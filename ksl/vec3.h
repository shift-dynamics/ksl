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
#ifndef _KSL_VEC3_H_
#define _KSL_VEC3_H_

#include "ksl/types.h"

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

static inline ksl_vec3_t ksl_vec3(const double x, const double y,
                                  const double z);

static inline ksl_vec3f_t ksl_vec3f(const float x, const float y,
                                    const float z);

static inline ksl_vec3i_t ksl_vec3i(const int x, const int y, const int z);

ksl_vec3_t* ksl_vec3_alloc(int);

ksl_vec3f_t* ksl_vec3f_alloc(int);

ksl_vec3i_t* ksl_vec3i_alloc(int);

static inline bool ksl_vec3i_isEqual(const ksl_vec3i_t* v1,
                                     const ksl_vec3i_t* v2);

static inline double ksl_vec3_l2norm(const ksl_vec3_t* v);

static inline float ksl_vec3f_l2norm(const ksl_vec3f_t* v);

static inline void ksl_vec3_normalize(ksl_vec3_t* v);

static inline void ksl_vec3f_normalize(ksl_vec3f_t* v);

static inline void ksl_vec3_normalized(const ksl_vec3_t* v, ksl_vec3_t* vo);

static inline void ksl_vec3f_normalized(const ksl_vec3f_t* v, ksl_vec3f_t* vo);

static inline void ksl_vec3_scale(ksl_vec3_t* v, const double);

static inline void ksl_vec3f_scale(ksl_vec3f_t* v, const float);

static inline void ksl_vec3_scaled(const ksl_vec3_t* v, const double,
                                   ksl_vec3_t* vo);

static inline void ksl_vec3f_scaled(const ksl_vec3f_t* v, const float,
                                    ksl_vec3f_t* vo);

static inline void ksl_vec3_copy(const ksl_vec3_t* vi, ksl_vec3_t* vo);

static inline void ksl_vec3f_copy(const ksl_vec3f_t* vi, ksl_vec3f_t* vo);

static inline void ksl_vec3_swap(ksl_vec3_t* v1, ksl_vec3_t* v2);

static inline void ksl_vec3f_swap(ksl_vec3f_t* v1, ksl_vec3f_t* v2);

static inline void ksl_vec3_inverted(const ksl_vec3_t* vi, ksl_vec3_t* vo);

static inline void ksl_vec3_invert(ksl_vec3_t* vi);

static inline void ksl_vec3f_inverted(const ksl_vec3f_t* vi, ksl_vec3f_t* vo);

static inline void ksl_vec3f_invert(ksl_vec3f_t* vi);

static inline double ksl_dot_vv(const ksl_vec3_t* vi0, const ksl_vec3_t* vi1);

static inline float ksl_dot_vvf(const ksl_vec3f_t* vi0, const ksl_vec3f_t* vi1);

static inline void ksl_product_av(const double ki, const ksl_vec3_t* vi,
                                  ksl_vec3_t* vo);

static inline void ksl_product_avinv(const double ki, const ksl_vec3_t* vi,
                                     ksl_vec3_t* vo);

static inline void ksl_product_ainvv(const double ki, const ksl_vec3_t* vi,
                                     ksl_vec3_t* vo);

static inline void ksl_product_avinvf(const float ki, const ksl_vec3f_t* vi,
                                      ksl_vec3f_t* vo);

static inline void ksl_product_avf(const float ki, const ksl_vec3f_t* vi,
                                   ksl_vec3f_t* vo);

static inline void ksl_add_vv(const ksl_vec3_t* v1i, const ksl_vec3_t* v2i,
                              ksl_vec3_t* vo);

static inline void ksl_add_vvf(const ksl_vec3f_t* v1i, const ksl_vec3f_t* v2i,
                               ksl_vec3f_t* vo);

static inline void ksl_subtract_vv(const ksl_vec3_t* v1i, const ksl_vec3_t* v2i,
                                   ksl_vec3_t* vo);

static inline void ksl_subtract_vvf(const ksl_vec3f_t* v1i,
                                    const ksl_vec3f_t* v2i, ksl_vec3f_t* vo);

static inline void ksl_axpy_vv(const double scalar, const ksl_vec3_t* v1x,
                               ksl_vec3_t* v2y);

static inline void ksl_axpy_vvf(const float scalar, const ksl_vec3f_t* v1x,
                                ksl_vec3f_t* v2y);

static inline void ksl_nxpy_vv(const ksl_vec3_t* v1x, ksl_vec3_t* v2y);

static inline void ksl_nxpy_vvf(const ksl_vec3f_t* v1x, ksl_vec3f_t* v2y);

static inline void ksl_xpy_vv(const ksl_vec3_t* v1x, ksl_vec3_t* v2y);

static inline void ksl_xpy_vvf(const ksl_vec3f_t* v1x, ksl_vec3f_t* v2y);

static inline void ksl_cross_vv(const ksl_vec3_t* v1i, const ksl_vec3_t* v2i,
                                ksl_vec3_t* vo);

static inline void ksl_cross_vvinv(const ksl_vec3_t* v1i, const ksl_vec3_t* v2i,
                                   ksl_vec3_t* vo);

static inline void ksl_cross_vvf(const ksl_vec3f_t* v1i, const ksl_vec3f_t* v2i,
                                 ksl_vec3f_t* vo);

static inline void ksl_cross_vvinvf(const ksl_vec3f_t* v1i,
                                    const ksl_vec3f_t* v2i, ksl_vec3f_t* vo);

static inline void ksl_add_vvx(const ksl_vec3_t* t1i, const double t2i,
                               ksl_vec3_t* to);

static inline void ksl_add_vvxf(const ksl_vec3f_t* t1i, const float t2i,
                                ksl_vec3f_t* to);

static inline void ksl_add_vvxinv(const ksl_vec3_t* t1i, const double t2i,
                                  ksl_vec3_t* to);

static inline void ksl_add_vvxinvf(const ksl_vec3f_t* t1i, const float t2i,
                                   ksl_vec3f_t* to);

static inline void ksl_add_vvy(const ksl_vec3_t* t1i, const double t2i,
                               ksl_vec3_t* to);

static inline void ksl_add_vvyf(const ksl_vec3f_t* t1i, const float t2i,
                                ksl_vec3f_t* to);

static inline void ksl_add_vvyinv(const ksl_vec3_t* t1i, const double t2i,
                                  ksl_vec3_t* to);

static inline void ksl_add_vvyinvf(const ksl_vec3f_t* t1i, const float t2i,
                                   ksl_vec3f_t* to);

static inline void ksl_add_vvz(const ksl_vec3_t* t1i, const double t2i,
                               ksl_vec3_t* to);

static inline void ksl_add_vvzf(const ksl_vec3f_t* t1i, const float t2i,
                                ksl_vec3f_t* to);

static inline void ksl_add_vvzinv(const ksl_vec3_t* t1i, const double t2i,
                                  ksl_vec3_t* to);

static inline void ksl_add_vvzinvf(const ksl_vec3f_t* t1i, const float t2i,
                                   ksl_vec3f_t* to);

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
@brief vec3 constructor
*/
static inline ksl_vec3_t ksl_vec3(const double x, const double y,
                                  const double z) {
  ksl_vec3_t v;
  v.x = x;
  v.y = y;
  v.z = z;
  return v;
}

/*!
@brief vec3f constructor
*/
static inline ksl_vec3f_t ksl_vec3f(const float x, const float y,
                                    const float z) {
  ksl_vec3f_t v;
  v.x = x;
  v.y = y;
  v.z = z;
  return v;
}

/*!
@brief vec3i constructor
*/
static inline ksl_vec3i_t ksl_vec3i(const int x, const int y, const int z) {
  ksl_vec3i_t v;
  v.x = x;
  v.y = y;
  v.z = z;
  return v;
}

static inline bool ksl_vec3i_isEqual(const ksl_vec3i_t* v1,
                                     const ksl_vec3i_t* v2) {
  if(v1->x == v2->x && v1->y == v2->y && v1->z == v2->z) {
    return true;
  } else {
    return false;
  }
}

/*!
@brief compute the norm of a double precision vector
*/
static inline double ksl_vec3_l2norm(const ksl_vec3_t* KSL_RESTRICT v) {
  return sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
}

/*!
@brief compute the norm of a single precision vector
*/
static inline float ksl_vec3f_l2norm(const ksl_vec3f_t* KSL_RESTRICT v) {
  return sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
}

/*!
@brief Normalize a double precision vector

@param v [in/out] vector to normalize
*/
static inline void ksl_vec3_normalize(ksl_vec3_t* KSL_RESTRICT v) {
  double norm = ksl_vec3_l2norm(v);
  ksl_vec3_scale(v, 1.0 / norm);
}

/*!
@brief Normalize a single precision vector

@param v [in/out] vector to normalize
*/
static inline void ksl_vec3f_normalize(ksl_vec3f_t* KSL_RESTRICT v) {
  float norm = ksl_vec3f_l2norm(v);
  ksl_vec3f_scale(v, 1.0 / norm);
}

/*!
@brief Normalize a double precision vector leaving original datastructure
unmodified; results are returned in second datastructure.

@param v [in/out] vector to normalize
*/
static inline void ksl_vec3_normalized(const ksl_vec3_t* KSL_RESTRICT v,
                                       ksl_vec3_t* KSL_RESTRICT vo) {
  ksl_vec3_copy(v, vo);
  ksl_vec3_normalize(vo);
}

/*!
@brief Normalize a single precision vector leaving original datastructure
unmodified; results are returned in second datastructure.

@param v [in/out] vector to normalize
*/
static inline void ksl_vec3f_normalized(const ksl_vec3f_t* KSL_RESTRICT v,
                                        ksl_vec3f_t* KSL_RESTRICT vo) {
  ksl_vec3f_copy(v, vo);
  ksl_vec3f_normalize(vo);
}

/*!
@brief Scale a double precision vector

@param v [in/out] vector to scale
*/
static inline void ksl_vec3_scale(ksl_vec3_t* KSL_RESTRICT v, const double k) {
  v->x *= k;
  v->y *= k;
  v->z *= k;
}

/*!
@brief Scale a single precision vector

@param v [in/out] vector to scale
*/
static inline void ksl_vec3f_scale(ksl_vec3f_t* KSL_RESTRICT v, const float k) {
  v->x *= k;
  v->y *= k;
  v->z *= k;
}

/*!
@brief Scale a double precision vector, returning results in second vector.

@param v [in/out] vector to scale
*/
static inline void ksl_vec3_scaled(const ksl_vec3_t* KSL_RESTRICT v,
                                   const double k,
                                   ksl_vec3_t* KSL_RESTRICT vo) {
  ksl_product_av(k, v, vo);
}

/*!
@brief Scale a single precision vector, returning results in second vector.

@param v [in/out] vector to scale
*/
static inline void ksl_vec3f_scaled(const ksl_vec3f_t* KSL_RESTRICT v,
                                    const float k,
                                    ksl_vec3f_t* KSL_RESTRICT vo) {
  ksl_product_avf(k, v, vo);
}

/*!
@brief Copy a double precision ksl_vec3_t vi into ksl_vec3_t vo.

\f$V_i \rightarrow V_o\f$

@param vi input vector \f$V_i\f$
@param vo output vector \f$V_o\f$
*/
static inline void ksl_vec3_copy(const ksl_vec3_t* KSL_RESTRICT vi,
                                 ksl_vec3_t* KSL_RESTRICT vo) {
  memcpy(vo, vi, sizeof(ksl_vec3_t));
}

/*!
@brief Copy a single precision ksl_vec3f_t vi into ksl_vec3f_t vo.

\f$V_i \rightarrow V_o\f$

@param vi input vector \f$V_i\f$
@param vo output vector \f$V_o\f$
*/
static inline void ksl_vec3f_copy(const ksl_vec3f_t* KSL_RESTRICT vi,
                                  ksl_vec3f_t* KSL_RESTRICT vo) {
  memcpy(vo, vi, sizeof(ksl_vec3f_t));
}

/*!
@brief Swap double precision vectors vio1 and vio2.

\f$V_io1 \rightarrow V_io2\f$
\f$V_io2 \rightarrow V_io1\f$

@param vio1 input/output vector \f$V_io1\f$
@param vio2 input/output vector \f$V_io2\f$
*/
static inline void ksl_vec3_swap(ksl_vec3_t* KSL_RESTRICT vio1,
                                 ksl_vec3_t* KSL_RESTRICT vio2) {
  ksl_vec3_t temp;
  ksl_vec3_copy(vio1, &temp);
  ksl_vec3_copy(vio2, vio1);
  ksl_vec3_copy(&temp, vio2);
}

/*!
@brief Swap single precision vectors vio1 and vio2.

\f$V_io1 \rightarrow V_io2\f$
\f$V_io2 \rightarrow V_io1\f$

@param vio1 input/output vector \f$V_io1\f$
@param vio2 input/output vector \f$V_io2\f$
*/
static inline void ksl_vec3f_swap(ksl_vec3f_t* KSL_RESTRICT vio1,
                                  ksl_vec3f_t* KSL_RESTRICT vio2) {
  ksl_vec3f_t temp;
  ksl_vec3f_copy(vio1, &temp);
  ksl_vec3f_copy(vio2, vio1);
  ksl_vec3f_copy(&temp, vio2);
}

/*!
@brief Copy inverse of double precision ksl_vec3_t vi into vo.

\f$-V_i \rightarrow V_o\f$

@param vi input vector \f$V_i\f$
@param vo output vector \f$V_o\f$
*/
static inline void ksl_vec3_inverted(const ksl_vec3_t* KSL_RESTRICT vi,
                                     ksl_vec3_t* KSL_RESTRICT vo) {
  vo->x = -vi->x;
  vo->y = -vi->y;
  vo->z = -vi->z;
}

/*!
@brief invert a double precision vector in place

\f$-V_i \rightarrow V_i\f$

@param vi [in/out] input vector \f$V_i\f$
*/
static inline void ksl_vec3_invert(ksl_vec3_t* KSL_RESTRICT vi) {
  vi->x = -vi->x;
  vi->y = -vi->y;
  vi->z = -vi->z;
}

/*!
@brief Copy inverse of single precision ksl_vec3f_t vi into vo.

\f$-V_i \rightarrow V_o\f$

@param vi [in] input vector \f$V_i\f$
@param vo [out] output vector \f$V_o\f$
*/
static inline void ksl_vec3f_inverted(const ksl_vec3f_t* KSL_RESTRICT vi,
                                      ksl_vec3f_t* KSL_RESTRICT vo) {
  vo->x = -vi->x;
  vo->y = -vi->y;
  vo->z = -vi->z;
}

/*!
@brief invert a single precision vector in place

\f$-V_i \rightarrow V_i\f$

@param vi [in/out] input vector \f$V_i\f$
*/
static inline void ksl_vec3f_invert(ksl_vec3f_t* KSL_RESTRICT vi) {
  vi->x = -vi->x;
  vi->y = -vi->y;
  vi->z = -vi->z;
}

/*!
@brief double precision dot product of two vectors

\f$ V_i0 \cdot V_i1 \rightarrow V_o\f$

@param vi0 first input vector
@param vi1 second input vector
*/
static inline double ksl_dot_vv(const ksl_vec3_t* KSL_RESTRICT vi0,
                                const ksl_vec3_t* KSL_RESTRICT vi1) {
  return vi0->x * vi1->x + vi0->y * vi1->y + vi0->z * vi1->z;
}

/*!
@brief single precision dot product of two vectors

\f$ V_i0 \cdot V_i1 \rightarrow V_o\f$

@param vi0 first input vector
@param vi1 second input vector
*/
static inline float ksl_dot_vvf(const ksl_vec3f_t* KSL_RESTRICT vi0,
                                const ksl_vec3f_t* KSL_RESTRICT vi1) {
  return vi0->x * vi1->x + vi0->y * vi1->y + vi0->z * vi1->z;
}

/*!
@brief Computes the double precision product of a vector and a scalar

\f$V_i * k_i \rightarrow V_o\f$

@param vi[3] A 3x1 input vector
@param *ki a pointer to a scalar
@param vo[3] the results are stored in vo[3]
*/
static inline void ksl_product_av(const double ki,
                                  const ksl_vec3_t* KSL_RESTRICT vi,
                                  ksl_vec3_t* KSL_RESTRICT vo) {
  vo->x = ki * vi->x;
  vo->y = ki * vi->y;
  vo->z = ki * vi->z;
}

/*!
@brief Computes the double precision product of the inverse of a vector and a
scalar

\f$-V_i * k_i \rightarrow V_o\f$

@param vi [in] A 3x1 input vector
@param ki [in] double precision scalar
@param vo [out] the results are stored in vo
*/
static inline void ksl_product_avinv(const double ki,
                                     const ksl_vec3_t* KSL_RESTRICT vi,
                                     ksl_vec3_t* KSL_RESTRICT vo) {
  vo->x = -ki * vi->x;
  vo->y = -ki * vi->y;
  vo->z = -ki * vi->z;
}

/*!
@brief Computes the double precision product of a vector and 1/scalar

Note: this function does not check for divide by zero.

\f$V_i * 1 / k_i \rightarrow V_o\f$

@param vi [in] A 3x1 input vector
@param ki [in] a double precision scalar
@param vo [out] the results are returned in vo
*/
static inline void ksl_product_ainvv(const double ki,
                                     const ksl_vec3_t* KSL_RESTRICT vi,
                                     ksl_vec3_t* KSL_RESTRICT vo) {
  double inv = 1.0 / ki;
  vo->x = inv * vi->x;
  vo->y = inv * vi->y;
  vo->z = inv * vi->z;
}

/*!
@brief Computes the single precision product of the inverse of a vector and a
scalar

\f$-V_i * k_i \rightarrow V_o\f$

@param vi [in] A 3x1 input vector
@param ki [in] double precision scalar
@param vo [out] the results are stored in vo[3]
*/
static inline void ksl_product_avinvf(const float ki,
                                      const ksl_vec3f_t* KSL_RESTRICT vi,
                                      ksl_vec3f_t* KSL_RESTRICT vo) {
  vo->x = -ki * vi->x;
  vo->y = -ki * vi->y;
  vo->z = -ki * vi->z;
}

/*!
@brief Computes the single precision product of a vector and a scalar

\f$V_i * k_i \rightarrow V_o\f$

@param vi[3] A 3x1 input vector
@param *ki a pointer to a scalar
@param vo[3] the results are stored in vo[3]
*/
static inline void ksl_product_avf(const float ki,
                                   const ksl_vec3f_t* KSL_RESTRICT vi,
                                   ksl_vec3f_t* KSL_RESTRICT vo) {
  vo->x = ki * vi->x;
  vo->y = ki * vi->y;
  vo->z = ki * vi->z;
}

/*!
@brief Adds two double precision vectors

Add 3 by 1 column matrices v1i and v2i and store results in vo.

\f$V_{1i} + V_{2i} \rightarrow V_o\f$

@param v1i a first column vector input
@param v2i second column vector
@param vo the results of v1i + v2i are stored in vo
*/
static inline void ksl_add_vv(const ksl_vec3_t* KSL_RESTRICT v1i,
                              const ksl_vec3_t* KSL_RESTRICT v2i,
                              ksl_vec3_t* KSL_RESTRICT vo) {
  vo->x = v1i->x + v2i->x;
  vo->y = v1i->y + v2i->y;
  vo->z = v1i->z + v2i->z;
}

/*!
@brief Adds two single precision vectors

Add 3 by 1 column matrices v1i and v2i and store results in vo.

\f$V_{1i} + V_{2i} \rightarrow V_o\f$

@param v1i a first column vector input
@param v2i second column vector
@param vo the results of v1i + v2i are stored in vo
*/
static inline void ksl_add_vvf(const ksl_vec3f_t* KSL_RESTRICT v1i,
                               const ksl_vec3f_t* KSL_RESTRICT v2i,
                               ksl_vec3f_t* KSL_RESTRICT vo) {
  vo->x = v1i->x + v2i->x;
  vo->y = v1i->y + v2i->y;
  vo->z = v1i->z + v2i->z;
}

/*!
@brief Subtract two double precision vectors

Add 3 by 1 column matrix v1i to v2i

\f$V_{2i} = V_{1i} - V_{2i}\f$

@param v1i [in]
@param v2i [in]
@param vo [out]
*/
static inline void ksl_subtract_vv(const ksl_vec3_t* KSL_RESTRICT v1i,
                                   const ksl_vec3_t* KSL_RESTRICT v2i,
                                   ksl_vec3_t* KSL_RESTRICT vo) {
  vo->x = v1i->x - v2i->x;
  vo->y = v1i->y - v2i->y;
  vo->z = v1i->z - v2i->z;
}

/*!
@brief Subtract two single precision vectors

Add 3 by 1 column matrix v1i to v2i

\f$V_{2i} = V_{1i} - V_{2i}\f$

@param v1i [in]
@param v2i [in]
@param vo [out]
*/
static inline void ksl_subtract_vvf(const ksl_vec3f_t* KSL_RESTRICT v1i,
                                    const ksl_vec3f_t* KSL_RESTRICT v2i,
                                    ksl_vec3f_t* KSL_RESTRICT vo) {
  vo->x = v1i->x - v2i->x;
  vo->y = v1i->y - v2i->y;
  vo->z = v1i->z - v2i->z;
}

/*!
@brief Adds two double precision vectors. This is a variation of axpy where a =
1

Add 3 by 1 column matrix v1i to v2i

\f$V_{2i} += V_{1i} \f$

@param v1i a first column vector input
@param v2i second column vector
*/
static inline void ksl_xpy_vv(const ksl_vec3_t* KSL_RESTRICT v1i,
                              ksl_vec3_t* KSL_RESTRICT v2i) {
  v2i->x += v1i->x;
  v2i->y += v1i->y;
  v2i->z += v1i->z;
}

/*!
@brief Adds two single precision vectors. This is a variation of axpy where a =
1

Add 3 by 1 column matrix v1i to v2i

\f$V_{2i} += V_{1i} \f$

@param v1i a first column vector input
@param v2i second column vector
*/
static inline void ksl_xpy_vvf(const ksl_vec3f_t* KSL_RESTRICT v1i,
                               ksl_vec3f_t* KSL_RESTRICT v2i) {
  v2i->x += v1i->x;
  v2i->y += v1i->y;
  v2i->z += v1i->z;
}

/*!
@brief double precision subtract v1i from v2i in place. This is a variation
of axpy where a = -1

\f$V_{2i} -= V_{1i} \f$

@param v1i [in]
@param v2i [in/out]
*/
static inline void ksl_nxpy_vv(const ksl_vec3_t* KSL_RESTRICT v1i,
                               ksl_vec3_t* KSL_RESTRICT v2i) {
  v2i->x -= v1i->x;
  v2i->y -= v1i->y;
  v2i->z -= v1i->z;
}

/*!
@brief single precision subtract v1i from v2i in place. This is a variation of
axpy where a = -1

\f$V_{2i} -= V_{1i} \f$

@param v1i [in]
@param v2i [in/out]
*/
static inline void ksl_nxpy_vvf(const ksl_vec3f_t* KSL_RESTRICT v1i,
                                ksl_vec3f_t* KSL_RESTRICT v2i) {
  v2i->x -= v1i->x;
  v2i->y -= v1i->y;
  v2i->z -= v1i->z;
}

/*!
@brief axpy (ax plus y stored in y) for double precision vectors

add 3 by 1 column matrix v1i scaled by k to v2i

\f$V_{2i} += k * V_{1i} \f$

@param v1i a first column vector input
@param v2i second column vector
*/
static inline void ksl_axpy_vv(const double k,
                               const ksl_vec3_t* KSL_RESTRICT v1x,
                               ksl_vec3_t* KSL_RESTRICT v2y) {
  v2y->x += v1x->x * k;
  v2y->y += v1x->y * k;
  v2y->z += v1x->z * k;
}

/*!
@brief axpy (ax plus y stored in y) for single precision vectors

add 3 by 1 column matrix v1i scaled by k to v2i

\f$V_{2i} += k * V_{1i} \f$

@param v1i a first column vector input
@param v2i second column vector
*/
static inline void ksl_axpy_vvf(const float k,
                                const ksl_vec3f_t* KSL_RESTRICT v1x,
                                ksl_vec3f_t* KSL_RESTRICT v2y) {
  v2y->x += v1x->x * k;
  v2y->y += v1x->y * k;
  v2y->z += v1x->z * k;
}

/*!
@brief Compute double precision cross product of v1i with v2i

\f$V_{1i} \times V_{2i} \rightarrow V_o\f$

@param v1i a first 3x1 vector
@param v2i a second 3x1 vector
@param vo the results are stored in vo
*/
static inline void ksl_cross_vv(const ksl_vec3_t* KSL_RESTRICT v1i,
                                const ksl_vec3_t* KSL_RESTRICT v2i,
                                ksl_vec3_t* KSL_RESTRICT vo) {
  vo->x = v1i->y * v2i->z - v1i->z * v2i->y;
  vo->y = v1i->z * v2i->x - v1i->x * v2i->z;
  vo->z = v1i->x * v2i->y - v1i->y * v2i->x;
}

/*!
@brief Compute double precision cross product of v1i with v2i^-1

\f$V_{1i} \times V_{2i} \rightarrow V_o\f$

@param v1i [in] a first 3x1 vector
@param v2i [in] a second 3x1 vector
@param vo [out] results are stored in vo
*/
static inline void ksl_cross_vvinv(const ksl_vec3_t* KSL_RESTRICT v1i,
                                   const ksl_vec3_t* KSL_RESTRICT v2i,
                                   ksl_vec3_t* vo) {
  vo->x = v1i->z * v2i->y - v1i->y * v2i->z;
  vo->y = v1i->x * v2i->z - v1i->z * v2i->x;
  vo->z = v1i->y * v2i->x - v1i->x * v2i->y;
}

/*!
@brief Compute single precision cross product of v1i with v2i

\f$V_{1i} \times V_{2i} \rightarrow V_o\f$

@param v1i a first 3x1 vector
@param v2i a second 3x1 vector
@param vo the results are stored in vo
*/
static inline void ksl_cross_vvf(const ksl_vec3f_t* KSL_RESTRICT v1i,
                                 const ksl_vec3f_t* KSL_RESTRICT v2i,
                                 ksl_vec3f_t* KSL_RESTRICT vo) {
  vo->x = v1i->y * v2i->z - v1i->z * v2i->y;
  vo->y = v1i->z * v2i->x - v1i->x * v2i->z;
  vo->z = v1i->x * v2i->y - v1i->y * v2i->x;
}

/*!
@brief Compute single precision cross product of v1i with v2i^-1

\f$V_{1i} \times V_{2i} \rightarrow V_o\f$

@param v1i [in] a first 3x1 vector
@param v2i [in] a second 3x1 vector
@param vo [out] results are stored in vo
*/
static inline void ksl_cross_vvinvf(const ksl_vec3f_t* KSL_RESTRICT v1i,
                                    const ksl_vec3f_t* KSL_RESTRICT v2i,
                                    ksl_vec3f_t* KSL_RESTRICT vo) {
  vo->x = v1i->z * v2i->y - v1i->y * v2i->z;
  vo->y = v1i->x * v2i->z - v1i->z * v2i->x;
  vo->z = v1i->y * v2i->x - v1i->x * v2i->y;
}

/*!
@brief Add a double precision Vector with a primitive translation along x-axis

Computes the result of a general 3-d translation, followed by a translation
along the x axis using sparse algebra.

\f$t_{i} + t_{x} \rightarrow t_o\f$

is equivalent to:

\f$t_{i} \rightarrow t_o\f$

\f$t_o[0] + t_x \rightarrow t_o[0]\f$

@param t1i a pointer to a general 3-d translation
@param t2i a pointer to a double
@param to a pointer to a general 3-d translation where the result is stored.
*/
static inline void ksl_add_vvx(const ksl_vec3_t* KSL_RESTRICT t1i,
                               const double t2i, ksl_vec3_t* KSL_RESTRICT to) {
  ksl_vec3_copy(t1i, to);
  to->x += t2i;
}

/*!
@brief Add a single precision Vector with a primitive translation along x-axis

Computes the result of a general 3-d translation, followed by a translation
along the x axis using sparse algebra.

\f$t_{i} + t_{x} \rightarrow t_o\f$

is equivalent to:

\f$t_{i} \rightarrow t_o\f$

\f$t_o[0] + t_x \rightarrow t_o[0]\f$

@param t1i a pointer to a general 3-d translation
@param t2i a pointer to a double
@param to a pointer to a general 3-d translation where the result is stored.
*/
static inline void ksl_add_vvxf(const ksl_vec3f_t* KSL_RESTRICT t1i,
                                const float t2i, ksl_vec3f_t* KSL_RESTRICT to) {
  ksl_vec3f_copy(t1i, to);
  to->x += t2i;
}

/*!
@brief Add a double precision Vector with the inverse of a translation
along the x-axis

Computes the result of a general 3-d transformation, followed by a tranformation
along the x axis using sparse algebra.

\f$t_{i} + t_{x} \rightarrow t_o\f$

is equivalent to:

\f$t_{i} \rightarrow t_o\f$

\f$t_o[0] + t_x \rightarrow t_o[0]\f$

@param t1i a pointer to a general 3-d translation
@param t2i a pointer to a double
@param to a pointer to a general 3-d translation where the result is stored.
*/
static inline void ksl_add_vvxinv(const ksl_vec3_t* KSL_RESTRICT t1i,
                                  const double t2i,
                                  ksl_vec3_t* KSL_RESTRICT to) {
  ksl_vec3_copy(t1i, to);
  to->x -= t2i;
}

/*!
@brief Add a single precision Vector with the inverse of a translation
along the x-axis

Computes the result of a general 3-d transformation, followed by a tranformation
along the x axis using sparse algebra.

\f$t_{i} + t_{x} \rightarrow t_o\f$

is equivalent to:

\f$t_{i} \rightarrow t_o\f$

\f$t_o[0] + t_x \rightarrow t_o[0]\f$

@param t1i a pointer to a general 3-d translation
@param t2i a pointer to a double
@param to a pointer to a general 3-d translation where the result is stored.
*/
static inline void ksl_add_vvxinvf(const ksl_vec3f_t* KSL_RESTRICT t1i,
                                   const float t2i,
                                   ksl_vec3f_t* KSL_RESTRICT to) {
  ksl_vec3f_copy(t1i, to);
  to->x -= t2i;
}

/*!
@brief Add a double precision Vector with a translation
along the y-axis

Computes the result of a general 3-d transformation, followed by a tranformation
along the y axis using sparse algebra.

\f$t_{i} + t_{y} \rightarrow t_o\f$

is equivalent to:

\f$t_{i}[0:2] \rightarrow t_o[0:2]\f$

\f$t_o[1] + t_y \rightarrow t_o[1]\f$

@param t1i a pointer to a general 3-d translation
@param t2i a pointer to a double
@param to a pointer to a general 3-d translation where the result is stored.
*/
static inline void ksl_add_vvy(const ksl_vec3_t* KSL_RESTRICT t1i,
                               const double t2i, ksl_vec3_t* KSL_RESTRICT to) {
  ksl_vec3_copy(t1i, to);
  to->y += t2i;
}

/*!
@brief Add a single precision Vector with a translation
along the y-axis

Computes the result of a general 3-d transformation, followed by a tranformation
along the y axis using sparse algebra.

\f$t_{i} + t_{y} \rightarrow t_o\f$

is equivalent to:

\f$t_{i}[0:2] \rightarrow t_o[0:2]\f$

\f$t_o[1] + t_y \rightarrow t_o[1]\f$

@param t1i a pointer to a general 3-d translation
@param t2i a pointer to a double
@param to a pointer to a general 3-d translation where the result is stored.
*/
static inline void ksl_add_vvyf(const ksl_vec3f_t* KSL_RESTRICT t1i,
                                const float t2i, ksl_vec3f_t* KSL_RESTRICT to) {
  ksl_vec3f_copy(t1i, to);
  to->y += t2i;
}

/*!
@brief Add a double precision Vector with the inverse of a translation
along the y-axis

Computes the result of a general 3-d transformation, followed by a tranformation
along the y axis using sparse algebra.

\f$t_{i} + t_{y} \rightarrow t_o\f$

is equivalent to:

\f$t_{i}[0:2] \rightarrow t_o[0:2]\f$

\f$t_o[1] - t_y \rightarrow t_o[1]\f$

@param t1i a pointer to a general 3-d translation
@param t2i a pointer to a double
@param to a pointer to a general 3-d translation where the result is stored.
*/
static inline void ksl_add_vvyinv(const ksl_vec3_t* KSL_RESTRICT t1i,
                                  const double t2i,
                                  ksl_vec3_t* KSL_RESTRICT to) {
  ksl_vec3_copy(t1i, to);
  to->y -= t2i;
}

/*!
@brief Add a single precision Vector with the inverse of a translation along the
y-axis

Computes the result of a general 3-d transformation, followed by a tranformation
along the y axis using sparse algebra.

\f$t_{i} + t_{y} \rightarrow t_o\f$

is equivalent to:

\f$t_{i}[0:2] \rightarrow t_o[0:2]\f$

\f$t_o[1] - t_y \rightarrow t_o[1]\f$

@param t1i a pointer to a general 3-d translation
@param t2i a pointer to a double
@param to a pointer to a general 3-d translation where the result is stored.
*/
static inline void ksl_add_vvyinvf(const ksl_vec3f_t* KSL_RESTRICT t1i,
                                   const float t2i,
                                   ksl_vec3f_t* KSL_RESTRICT to) {
  ksl_vec3f_copy(t1i, to);
  to->y -= t2i;
}

/*!
@brief Add a double precision Vector with a translation
along the z-axis

Computes the result of a general 3-d transformation, followed by a tranformation
along the z axis using sparse algebra.

\f$t_{i} + t_{z} \rightarrow t_o\f$

is equivalent to:

\f$t_{i}[0:2] \rightarrow t_o[0:2]\f$

\f$t_o[2] + t_z \rightarrow t_o[2]\f$

@param t1i a pointer to a general 3-d translation
@param t2i a pointer to a double
@param to a pointer to a general 3-d translation where the result is stored.
*/
static inline void ksl_add_vvz(const ksl_vec3_t* KSL_RESTRICT t1i,
                               const double t2i, ksl_vec3_t* KSL_RESTRICT to) {
  ksl_vec3_copy(t1i, to);
  to->z += t2i;
}

/*!
@brief Add a single precision Vector with a translation
along the z-axis

Computes the result of a general 3-d transformation, followed by a tranformation
along the z axis using sparse algebra.

\f$t_{i} + t_{z} \rightarrow t_o\f$

is equivalent to:

\f$t_{i}[0:2] \rightarrow t_o[0:2]\f$

\f$t_o[2] + t_z \rightarrow t_o[2]\f$

@param t1i a pointer to a general 3-d translation
@param t2i a pointer to a double
@param to a pointer to a general 3-d translation where the result is stored.
*/
static inline void ksl_add_vvzf(const ksl_vec3f_t* KSL_RESTRICT t1i,
                                const float t2i, ksl_vec3f_t* KSL_RESTRICT to) {
  ksl_vec3f_copy(t1i, to);
  to->z += t2i;
}

/*!
@brief Add a double precision Vector with the inverse of a translation along the
z-axis

Computes the result of a general 3-d transformation, followed by a tranformation
along the z axis using sparse algebra.

\f$t_{i} + t_{z} \rightarrow t_o\f$

is equivalent to:

\f$t_{i}[0:2] \rightarrow t_o[0:2]\f$

\f$t_o[2] - t_z \rightarrow t_o[2]\f$

@param t1i [in] a pointer to a general 3-d translation
@param t2i [in] translation along z-axis
@param to [out] a pointer to a general 3-d translation where the result is
stored.
*/
static inline void ksl_add_vvzinv(const ksl_vec3_t* KSL_RESTRICT t1i,
                                  const double t2i,
                                  ksl_vec3_t* KSL_RESTRICT to) {
  ksl_vec3_copy(t1i, to);
  to->z -= t2i;
}

/*!
@brief Add a single precision vector with the inverse of a translation along the
z-axis

Computes the result of a general 3-d transformation, followed by a tranformation
along the z axis using sparse algebra.

\f$t_{i} + t_{z} \rightarrow t_o\f$

is equivalent to:

\f$t_{i}[0:2] \rightarrow t_o[0:2]\f$

\f$t_o[2] - t_z \rightarrow t_o[2]\f$

@param t1i [in] a pointer to a general 3-d translation
@param t2i [in] translation along z-axis
@param to [out] a pointer to a general 3-d translation where the result is
stored.
*/
static inline void ksl_add_vvzinvf(const ksl_vec3f_t* KSL_RESTRICT t1i,
                                   const float t2i,
                                   ksl_vec3f_t* KSL_RESTRICT to) {
  ksl_vec3f_copy(t1i, to);
  to->z -= t2i;
}

#ifdef __cplusplus
}
#endif

#endif
