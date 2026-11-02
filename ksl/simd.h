/**
@file
@author Kristopher Wehage, Roger Wehage
@brief Internal SSE2 helpers for the SE3, adjoint and coadjoint products
@date 2026
@copyright Kristopher Wehage 2026

@remark
THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
SUCH DAMAGE.
*/
#ifndef _KSL_SIMD_H_
#define _KSL_SIMD_H_

/* Internal helpers for the double precision SE3, adjoint and coadjoint
products. They are not part of the public interface.

When the target supports SSE2 (every 64-bit x86 processor does), these
functions are written with SSE2 instructions, which operate on two double
precision numbers at once. A 3-vector, such as a column of a rotation matrix,
is held as one pair {x, y} and one single value {z}. Results are written to
memory in the same pieces, 16 bytes then 8 bytes per column, so a following
function that reads them can take the values directly from the pending writes
instead of waiting for them to reach the cache.

Without this, the compiler groups neighbouring numbers into pairs on its own.
Because a column has three numbers, those pairs straddle columns, which costs
extra instructions to rearrange values and slows down a chain of dependent
products.

Define KSL_NO_SIMD to use the portable C code instead. */

#include "ksl/types.h"

#if !defined(KSL_NO_SIMD) && defined(__SSE2__)
#define KSL_SSE2 1
#include <emmintrin.h>

#ifdef __cplusplus
extern "C" {
#endif

/* a 3-vector as {x, y} and {z, unused} */
typedef struct ksl_sse2_vec3_t {
  __m128d xy;
  __m128d z;
} ksl_sse2_vec3_t;

/* Unaligned stores of two doubles or four floats.

The SSE store functions may write to memory of any type. After one, the
compiler has to assume that any pointer held in memory may have changed, so
in a loop such as

  for(i = 0; i < n; i++) ksl_product_qq(&a[i], &b[i], &c[i]);

where a, b and c are std::vector or are reached through a struct, it reloads
their data pointers on every iteration. GCC treats a store of a vector of
doubles as a store of doubles, which cannot change a pointer, so the loads stay
outside the loop. Clang treats it like the SSE store functions, so those are
used there. */
#if defined(__GNUC__) && !defined(__clang__)
typedef double ksl_v2d_u_ __attribute__((vector_size(16), aligned(8)));
typedef float ksl_v4f_u_ __attribute__((vector_size(16), aligned(4)));

static inline void ksl_storeu_pd_(double* p, __m128d v) {
  *(ksl_v2d_u_*)p = (ksl_v2d_u_)v;
}

static inline void ksl_storeu_ps_(float* p, __m128 v) {
  *(ksl_v4f_u_*)p = (ksl_v4f_u_)v;
}
#else
static inline void ksl_storeu_pd_(double* p, __m128d v) {
  _mm_storeu_pd(p, v);
}

static inline void ksl_storeu_ps_(float* p, __m128 v) { _mm_storeu_ps(p, v); }
#endif

static inline ksl_sse2_vec3_t ksl_sse2_load_(const ksl_vec3_t* v) {
  ksl_sse2_vec3_t r;
  r.xy = _mm_loadu_pd(&v->x);
  r.z = _mm_load_sd(&v->z);
  return r;
}

static inline void ksl_sse2_store_(ksl_vec3_t* v, ksl_sse2_vec3_t a) {
  ksl_storeu_pd_(&v->x, a.xy);
  _mm_store_sd(&v->z, a.z);
}

static inline ksl_sse2_vec3_t ksl_sse2_add_(ksl_sse2_vec3_t a,
                                            ksl_sse2_vec3_t b) {
  ksl_sse2_vec3_t r;
  r.xy = _mm_add_pd(a.xy, b.xy);
  r.z = _mm_add_sd(a.z, b.z);
  return r;
}

/* c0 * bx + c1 * by + c2 * bz, where bx, by and bz hold the same value in
both halves */
static inline ksl_sse2_vec3_t ksl_sse2_combine_(ksl_sse2_vec3_t c0,
                                                ksl_sse2_vec3_t c1,
                                                ksl_sse2_vec3_t c2, __m128d bx,
                                                __m128d by, __m128d bz) {
  ksl_sse2_vec3_t r;
  r.xy = _mm_add_pd(_mm_add_pd(_mm_mul_pd(c0.xy, bx), _mm_mul_pd(c1.xy, by)),
                    _mm_mul_pd(c2.xy, bz));
  r.z = _mm_add_sd(_mm_add_sd(_mm_mul_sd(c0.z, bx), _mm_mul_sd(c1.z, by)),
                   _mm_mul_sd(c2.z, bz));
  return r;
}

/* matrix with columns c0, c1, c2 times the vector b in memory */
static inline ksl_sse2_vec3_t ksl_sse2_product_mv_(ksl_sse2_vec3_t c0,
                                                   ksl_sse2_vec3_t c1,
                                                   ksl_sse2_vec3_t c2,
                                                   const ksl_vec3_t* b) {
  return ksl_sse2_combine_(c0, c1, c2, _mm_load1_pd(&b->x),
                           _mm_load1_pd(&b->y), _mm_load1_pd(&b->z));
}

/* matrix with columns c0, c1, c2 times the vector b in registers */
static inline ksl_sse2_vec3_t ksl_sse2_product_mb_(ksl_sse2_vec3_t c0,
                                                   ksl_sse2_vec3_t c1,
                                                   ksl_sse2_vec3_t c2,
                                                   ksl_sse2_vec3_t b) {
  return ksl_sse2_combine_(c0, c1, c2, _mm_unpacklo_pd(b.xy, b.xy),
                           _mm_unpackhi_pd(b.xy, b.xy),
                           _mm_unpacklo_pd(b.z, b.z));
}

/* transpose of the matrix with columns c0, c1, c2 */
static inline void ksl_sse2_transpose_(ksl_sse2_vec3_t c0, ksl_sse2_vec3_t c1,
                                       ksl_sse2_vec3_t c2, ksl_sse2_vec3_t* t0,
                                       ksl_sse2_vec3_t* t1,
                                       ksl_sse2_vec3_t* t2) {
  t0->xy = _mm_unpacklo_pd(c0.xy, c1.xy); /* {c0.x, c1.x} */
  t0->z = c2.xy;                          /* {c2.x, unused} */
  t1->xy = _mm_unpackhi_pd(c0.xy, c1.xy); /* {c0.y, c1.y} */
  t1->z = _mm_unpackhi_pd(c2.xy, c2.xy);  /* {c2.y, c2.y} */
  t2->xy = _mm_unpacklo_pd(c0.z, c1.z);   /* {c0.z, c1.z} */
  t2->z = c2.z;
}

/* cross product a x b, with a in memory and b in registers */
static inline ksl_sse2_vec3_t ksl_sse2_cross_(const ksl_vec3_t* a,
                                              ksl_sse2_vec3_t b) {
  const __m128d a_xy = _mm_loadu_pd(&a->x);
  const __m128d a_yz = _mm_loadu_pd(&a->y);
  const __m128d a_zx = _mm_unpacklo_pd(_mm_load_sd(&a->z), a_xy);
  const __m128d b_yz = _mm_shuffle_pd(b.xy, b.z, 1);
  const __m128d b_zx = _mm_unpacklo_pd(b.z, b.xy);
  ksl_sse2_vec3_t r;
  /* {ay bz - az by, az bx - ax bz} */
  r.xy = _mm_sub_pd(_mm_mul_pd(a_yz, b_zx), _mm_mul_pd(a_zx, b_yz));
  /* ax by - ay bx */
  r.z = _mm_sub_sd(_mm_mul_sd(a_xy, b_yz), _mm_mul_sd(a_yz, b.xy));
  return r;
}

#ifdef __cplusplus
}
#endif

#endif

#endif
