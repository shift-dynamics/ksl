/**
@file
@author Kristopher Wehage, Roger Wehage
@brief Utilities to initialize and operate on vectors
@date 2018
@copyright Kristopher Wehage 2018-2026

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
#ifndef _KSL_VEC4_H_
#define _KSL_VEC4_H_

#include "ksl/types.h"

#include "vec3.h"

#ifdef __cplusplus
extern "C" {
#endif

static inline ksl_vec4i_t ksl_vec4i(const int x, const int y, const int z,
                                    const int w);

static inline ksl_vec4_t ksl_vec4(const double x, const double y,
                                  const double z, const double w);

static inline ksl_vec4f_t ksl_vec4f(const float x, const float y, const float z,
                                    const float w);

ksl_vec4_t* ksl_vec4_alloc(int);

ksl_vec4f_t* ksl_vec4f_alloc(int);

ksl_vec4i_t* ksl_vec4i_alloc(int);

static inline double ksl_vec4_l2norm(const ksl_vec4_t* v);

static inline float ksl_vec4f_l2norm(const ksl_vec4f_t* v);

static inline void ksl_vec4_normalize(ksl_vec4_t* v);

static inline void ksl_vec4f_normalize(ksl_vec4f_t* v);

static inline void ksl_vec4_normalized(const ksl_vec4_t* v, ksl_vec4_t* vo);

static inline void ksl_vec4f_normalized(const ksl_vec4f_t* v, ksl_vec4f_t* vo);

static inline void ksl_vec4_scale(ksl_vec4_t* v, const double);

static inline void ksl_vec4f_scale(ksl_vec4f_t* v, const float);

static inline void ksl_vec4_scaled(const ksl_vec4_t* v, const double,
                                   ksl_vec4_t* vo);

static inline void ksl_vec4f_scaled(const ksl_vec4f_t* v, const float,
                                    ksl_vec4f_t* vo);

static inline void ksl_vec4_copy(const ksl_vec4_t* vi, ksl_vec4_t* vo);

static inline void ksl_vec4f_copy(const ksl_vec4f_t* vi, ksl_vec4f_t* vo);

static inline void ksl_vec4_swap(ksl_vec4_t* v1, ksl_vec4_t* v2);

static inline void ksl_vec4f_swap(ksl_vec4f_t* v1, ksl_vec4f_t* v2);

static inline void ksl_vec4_inverted(const ksl_vec4_t* vi, ksl_vec4_t* vo);

static inline void ksl_vec4_invert(ksl_vec4_t* vi);

static inline void ksl_vec4f_inverted(const ksl_vec4f_t* vi, ksl_vec4f_t* vo);

static inline void ksl_vec4f_invert(ksl_vec4f_t* vi);

#ifdef __cplusplus
}
#endif

/* -------- inline definitions -------- */

#include <assert.h>
#include <math.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

/*!
@brief vec4 constructor
*/
static inline ksl_vec4_t ksl_vec4(const double x, const double y,
                                  const double z, const double w) {
  ksl_vec4_t v;
  v.x = x;
  v.y = y;
  v.z = z;
  v.w = w;
  return v;
}

/*!
@brief vec4f constructor
*/
static inline ksl_vec4f_t ksl_vec4f(const float x, const float y, const float z,
                                    const float w) {
  ksl_vec4f_t v;
  v.x = x;
  v.y = y;
  v.z = z;
  v.w = w;
  return v;
}

/*!
@brief vec4i constructor
*/
static inline ksl_vec4i_t ksl_vec4i(const int x, const int y, const int z,
                                    const int w) {
  ksl_vec4i_t v;
  v.x = x;
  v.y = y;
  v.z = z;
  v.w = w;
  return v;
}

/*!
@brief compute the norm of a double precision vector
*/
static inline double ksl_vec4_l2norm(const ksl_vec4_t* KSL_RESTRICT v) {
  return sqrt(v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w);
}

/*!
@brief compute the norm of a single precision vector
*/
static inline float ksl_vec4f_l2norm(const ksl_vec4f_t* KSL_RESTRICT v) {
  return sqrt(v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w);
}

/*!
@brief Normalize a double precision vector.

@param v [in/out] vector to normalize
*/
static inline void ksl_vec4_normalize(ksl_vec4_t* KSL_RESTRICT v) {
  double norm = ksl_vec4_l2norm(v);
  ksl_vec4_scale(v, 1.0 / norm);
}

/*!
@brief Normalize a single precision vector

@param v [in/out] vector to normalize
*/
static inline void ksl_vec4f_normalize(ksl_vec4f_t* KSL_RESTRICT v) {
  float norm = ksl_vec4f_l2norm(v);
  ksl_vec4f_scale(v, 1.0 / norm);
}

/*!
@brief Normalize a double precision vector leaving original datastructure
unmodified; results are returned in second datastructure.

@param v [in] vector to normalize
@param vo [out] unit vector in the direction of v
*/
static inline void ksl_vec4_normalized(const ksl_vec4_t* KSL_RESTRICT v,
                                       ksl_vec4_t* KSL_RESTRICT vo) {
  ksl_vec4_copy(v, vo);
  ksl_vec4_normalize(vo);
}

/*!
@brief Normalize a single precision vector leaving original datastructure
unmodified; results are returned in second datastructure.

@param v [in] vector to normalize
@param vo [out] unit vector in the direction of v
*/
static inline void ksl_vec4f_normalized(const ksl_vec4f_t* KSL_RESTRICT v,
                                        ksl_vec4f_t* KSL_RESTRICT vo) {
  ksl_vec4f_copy(v, vo);
  ksl_vec4f_normalize(vo);
}

/*!
@brief Scale a double precision vector

@param v [in,out] vector to scale in place
@param k [in] scale factor
*/
static inline void ksl_vec4_scale(ksl_vec4_t* KSL_RESTRICT v, const double k) {
  v->x *= k;
  v->y *= k;
  v->z *= k;
  v->w *= k;
}

/*!
@brief Scale a single precision vector

@param v [in,out] vector to scale in place
@param k [in] scale factor
*/
static inline void ksl_vec4f_scale(ksl_vec4f_t* KSL_RESTRICT v, const float k) {
  v->x *= k;
  v->y *= k;
  v->z *= k;
  v->w *= k;
}

/*!
@brief Scale a double precision vector, returning results in second vector.

@param v [in] vector to scale
@param k [in] scale factor
@param vo [out] scaled vector, k * v
*/
static inline void ksl_vec4_scaled(const ksl_vec4_t* KSL_RESTRICT v,
                                   const double k,
                                   ksl_vec4_t* KSL_RESTRICT vo) {
  vo->x = v->x * k;
  vo->y = v->y * k;
  vo->z = v->z * k;
  vo->w = v->w * k;
}

/*!
@brief Scale a single precision vector, returning results in second vector.

@param v [in] vector to scale
@param k [in] scale factor
@param vo [out] scaled vector, k * v
*/
static inline void ksl_vec4f_scaled(const ksl_vec4f_t* KSL_RESTRICT v,
                                    const float k,
                                    ksl_vec4f_t* KSL_RESTRICT vo) {
  vo->x = v->x * k;
  vo->y = v->y * k;
  vo->z = v->z * k;
  vo->w = v->w * k;
}

/*!
@brief Copy a double precision ksl_vec3_t vi into ksl_vec3_t vo.

\f$V_i \rightarrow V_o\f$

@param vi input vector \f$V_i\f$
@param vo output vector \f$V_o\f$
*/
static inline void ksl_vec4_copy(const ksl_vec4_t* KSL_RESTRICT vi,
                                 ksl_vec4_t* KSL_RESTRICT vo) {
  memcpy(vo, vi, sizeof(ksl_vec4_t));
}

/*!
@brief Copy a single precision ksl_vec3f_t vi into ksl_vec3f_t vo.

\f$V_i \rightarrow V_o\f$

@param vi input vector \f$V_i\f$
@param vo output vector \f$V_o\f$
*/
static inline void ksl_vec4f_copy(const ksl_vec4f_t* KSL_RESTRICT vi,
                                  ksl_vec4f_t* KSL_RESTRICT vo) {
  memcpy(vo, vi, sizeof(ksl_vec4f_t));
}

/*!
@brief Swap double precision vectors vio1 and vio2.

\f$V_io1 \rightarrow V_io2\f$
\f$V_io2 \rightarrow V_io1\f$

@param vio1 input/output vector \f$V_io1\f$
@param vio2 input/output vector \f$V_io2\f$
*/
static inline void ksl_vec4_swap(ksl_vec4_t* KSL_RESTRICT vio1,
                                 ksl_vec4_t* KSL_RESTRICT vio2) {
  ksl_vec4_t temp;
  ksl_vec4_copy(vio1, &temp);
  ksl_vec4_copy(vio2, vio1);
  ksl_vec4_copy(&temp, vio2);
}

/*!
@brief Swap single precision vectors vio1 and vio2.

\f$V_io1 \rightarrow V_io2\f$
\f$V_io2 \rightarrow V_io1\f$

@param vio1 input/output vector \f$V_io1\f$
@param vio2 input/output vector \f$V_io2\f$
*/
static inline void ksl_vec4f_swap(ksl_vec4f_t* KSL_RESTRICT vio1,
                                  ksl_vec4f_t* KSL_RESTRICT vio2) {
  ksl_vec4f_t temp;
  ksl_vec4f_copy(vio1, &temp);
  ksl_vec4f_copy(vio2, vio1);
  ksl_vec4f_copy(&temp, vio2);
}

/*!
@brief Copy inverse of double precision ksl_vec4_t vi into vo.

\f$-V_i \rightarrow V_o\f$

@param vi input vector \f$V_i\f$
@param vo output vector \f$V_o\f$
*/
static inline void ksl_vec4_inverted(const ksl_vec4_t* KSL_RESTRICT vi,
                                     ksl_vec4_t* KSL_RESTRICT vo) {
  vo->x = -vi->x;
  vo->y = -vi->y;
  vo->z = -vi->z;
  vo->w = -vi->w;
}

/*!
@brief invert a double precision vector in place

\f$-V_i \rightarrow V_i\f$

@param vi [in/out] input vector \f$V_i\f$
*/
static inline void ksl_vec4_invert(ksl_vec4_t* KSL_RESTRICT vi) {
  vi->x = -vi->x;
  vi->y = -vi->y;
  vi->z = -vi->z;
  vi->w = -vi->w;
}

/*!
@brief Copy inverse of single precision ksl_vec4f_t vi into vo.

\f$-V_i \rightarrow V_o\f$

@param vi [in] input vector \f$V_i\f$
@param vo [out] output vector \f$V_o\f$
*/
static inline void ksl_vec4f_inverted(const ksl_vec4f_t* KSL_RESTRICT vi,
                                      ksl_vec4f_t* KSL_RESTRICT vo) {
  vo->x = -vi->x;
  vo->y = -vi->y;
  vo->z = -vi->z;
  vo->w = -vi->w;
}

/*!
@brief invert a single precision vector in place

\f$-V_i \rightarrow V_i\f$

@param vi [in/out] input vector \f$V_i\f$
*/
static inline void ksl_vec4f_invert(ksl_vec4f_t* KSL_RESTRICT vi) {
  vi->x = -vi->x;
  vi->y = -vi->y;
  vi->z = -vi->z;
  vi->w = -vi->w;
}

#ifdef __cplusplus
}
#endif

#endif
