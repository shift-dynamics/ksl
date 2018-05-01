#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "vector.h"

/*!
@brief initialize n ksl_vec3_t double precision vectors datastructures on the
heap
*/
inline ksl_vec3_t* ksl_vec3_alloc(int n) {
  return calloc(n, sizeof(ksl_vec3_t));
}

/*!
@brief initialize n ksl_vec3f_t single precision vectors datastructures on the
heap
*/
inline ksl_vec3f_t* ksl_vec3f_alloc(int n) {
  return calloc(n, sizeof(ksl_vec3f_t));
}

/*!
@brief initialize n ksl_vec3i_t vectors of integers on the heap
*/
inline ksl_vec3i_t* ksl_vec3i_alloc(int n) {
  return calloc(n, sizeof(ksl_vec3i_t));
}

/*!
@brief compute the norm of a double precision vector
*/
inline double ksl_vec3_l2norm(const ksl_vec3_t* restrict v) {
  return sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
}

/*!
@brief compute the norm of a single precision vector
*/
float ksl_vec3f_l2norm(const ksl_vec3f_t* restrict v) {
  return sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
}

/*!
@brief Normalize a double precision vector

@param v [in/out] vector to normalize
*/
inline void ksl_vec3_normalize(ksl_vec3_t* restrict v) {
  double norm = ksl_vec3_l2norm(v);
  ksl_vec3_scale(1.0 / norm, v);
}

/*!
@brief Normalize a single precision vector

@param v [in/out] vector to normalize
*/
inline void ksl_vec3f_normalize(ksl_vec3f_t* restrict v) {
  float norm = ksl_vec3f_l2norm(v);
  ksl_vec3f_scale(1.0 / norm, v);
}

/*!
@brief Scale a double precision vector

@param v [in/out] vector to scale
*/
void ksl_vec3_scale(double k, ksl_vec3_t* v) {
  v->x *= k;
  v->y *= k;
  v->z *= k;
}

/*!
@brief Scale a single precision vector

@param v [in/out] vector to scale
*/
void ksl_vec3f_scale(float k, ksl_vec3f_t* v) {
  v->x *= k;
  v->y *= k;
  v->z *= k;
}

/*!
@brief Copy a double precision ksl_vec3_t vi into ksl_vec3_t vo.

\f$V_i \rightarrow V_o\f$

@param vi input vector \f$V_i\f$
@param vo output vector \f$V_o\f$
*/
inline void ksl_vec3_copy(const ksl_vec3_t* restrict vi,
                          ksl_vec3_t* restrict vo) {
  memcpy(vo, vi, sizeof(ksl_vec3_t));
}

/*!
@brief Copy a single precision ksl_vec3f_t vi into ksl_vec3f_t vo.

\f$V_i \rightarrow V_o\f$

@param vi input vector \f$V_i\f$
@param vo output vector \f$V_o\f$
*/
inline void ksl_vec3f_copy(const ksl_vec3f_t* restrict vi,
                           ksl_vec3f_t* restrict vo) {
  memcpy(vo, vi, sizeof(ksl_vec3_t));
}

/*!
@brief Swap double precision vectors vio1 and vio2.

\f$V_io1 \rightarrow V_io2\f$
\f$V_io2 \rightarrow V_io1\f$

@param vio1 input/output vector \f$V_io1\f$
@param vio2 input/output vector \f$V_io2\f$
*/
inline void ksl_vec3_swap(ksl_vec3_t* restrict vio1,
                          ksl_vec3_t* restrict vio2) {
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
inline void ksl_vec3f_swap(ksl_vec3f_t* restrict vio1,
                           ksl_vec3f_t* restrict vio2) {
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
inline void ksl_vec3_inverted(const ksl_vec3_t* restrict vi,
                              ksl_vec3_t* restrict vo) {
  vo->x = -vi->x;
  vo->y = -vi->y;
  vo->z = -vi->z;
}

/*!
@brief invert a double precision vector in place

\f$-V_i \rightarrow V_i\f$

@param vi [in/out] input vector \f$V_i\f$
*/
inline void ksl_vec3_invert(ksl_vec3_t* restrict vi) {
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
inline void ksl_vec3f_inverted(const ksl_vec3f_t* restrict vi,
                               ksl_vec3f_t* restrict vo) {
  vo->x = -vi->x;
  vo->y = -vi->y;
  vo->z = -vi->z;
}

/*!
@brief invert a single precision vector in place

\f$-V_i \rightarrow V_i\f$

@param vi [in/out] input vector \f$V_i\f$
*/
inline void ksl_vec3f_invert(ksl_vec3f_t* restrict vi) {
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
double ksl_dot_vv(const ksl_vec3_t* restrict vi0,
                  const ksl_vec3_t* restrict vi1) {
  register double sum = 0;
  sum += vi0->x * vi1->x;
  sum += vi0->y * vi1->y;
  sum += vi0->z * vi1->z;
  return sum;
}

/*!
@brief single precision dot product of two vectors

\f$ V_i0 \cdot V_i1 \rightarrow V_o\f$

@param vi0 first input vector
@param vi1 second input vector
*/
float ksl_dot_vvf(const ksl_vec3f_t* restrict vi0,
                  const ksl_vec3f_t* restrict vi1) {
  register float sum = 0;
  sum += vi0->x * vi1->x;
  sum += vi0->y * vi1->y;
  sum += vi0->z * vi1->z;
  return sum;
}

/*!
@brief Computes the double precision product of a vector and a scalar

\f$V_i * k_i \rightarrow V_o\f$

@param vi[3] A 3x1 input vector
@param *ki a pointer to a scalar
@param vo[3] the results are stored in vo[3]
*/
inline void ksl_product_vk(const ksl_vec3_t* restrict vi, const double ki,
                           ksl_vec3_t* restrict vo) {
  vo->x = vi->x * ki;
  vo->y = vi->y * ki;
  vo->z = vi->z * ki;
}

/*!
@brief Computes the double precision product of the inverse of a vector and a
scalar

\f$-V_i * k_i \rightarrow V_o\f$

@param vi [in] A 3x1 input vector
@param ki [in] double precision scalar
@param vo [out] the results are stored in vo
*/
void ksl_product_vinvk(const ksl_vec3_t* restrict vi, const double ki,
                       ksl_vec3_t* restrict vo) {
  vo->x = -vi->x * ki;
  vo->y = -vi->y * ki;
  vo->z = -vi->z * ki;
}

/*!
@brief Computes the double precision product of a vector and 1/scalar

Note: this function does not check for divide by zero.

\f$V_i * 1 / k_i \rightarrow V_o\f$

@param vi [in] A 3x1 input vector
@param ki [in] a double precision scalar
@param vo [out] the results are returned in vo
*/
void ksl_product_vkinv(const ksl_vec3_t* restrict vi, const double ki,
                       ksl_vec3_t* restrict vo) {
  register double inv = 1.0 / ki;
  vo->x = vi->x * inv;
  vo->y = vi->y * inv;
  vo->z = vi->z * inv;
}

/*!
@brief Computes the single precision product of the inverse of a vector and a
scalar

\f$-V_i * k_i \rightarrow V_o\f$

@param vi [in] A 3x1 input vector
@param ki [in] double precision scalar
@param vo [out] the results are stored in vo[3]
*/
void ksl_product_vinvkf(const ksl_vec3f_t* restrict vi, const float ki,
                        ksl_vec3f_t* restrict vo) {
  vo->x = -vi->x * ki;
  vo->y = -vi->y * ki;
  vo->z = -vi->z * ki;
}

/*!
@brief Computes the single precision product of a vector and 1/scalar

Note: this function does not check for divide by zero.

\f$V_i * 1 / k_i \rightarrow V_o\f$

@param vi [in] A 3x1 input vector
@param ki [in] a double precision scalar
@param vo [out] the results are returned in vo
*/
void ksl_product_vkinvf(const ksl_vec3f_t* restrict vi, const float ki,
                        ksl_vec3f_t* restrict vo) {
  register float inv = 1.0 / ki;
  vo->x = vi->x * inv;
  vo->y = vi->y * inv;
  vo->z = vi->z * inv;
}

/*!
@brief Computes the single precision product of a vector and a scalar

\f$V_i * k_i \rightarrow V_o\f$

@param vi[3] A 3x1 input vector
@param *ki a pointer to a scalar
@param vo[3] the results are stored in vo[3]
*/
void ksl_product_vkf(const ksl_vec3f_t* restrict vi, const float ki,
                     ksl_vec3f_t* restrict vo) {
  vo->x = vi->x * ki;
  vo->y = vi->y * ki;
  vo->z = vi->z * ki;
}

/*!
@brief Adds two double precision vectors

Add 3 by 1 column matrices v1i and v2i and store results in vo.

\f$V_{1i} + V_{2i} \rightarrow V_o\f$

@param v1i a first column vector input
@param v2i second column vector
@param vo the results of v1i + v2i are stored in vo
*/
inline void ksl_add_vv(const ksl_vec3_t* restrict v1i,
                       const ksl_vec3_t* restrict v2i,
                       ksl_vec3_t* restrict vo) {
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
inline void ksl_add_vvf(const ksl_vec3f_t* restrict v1i,
                        const ksl_vec3f_t* restrict v2i,
                        ksl_vec3f_t* restrict vo) {
  vo->x = v1i->x + v2i->x;
  vo->y = v1i->y + v2i->y;
  vo->z = v1i->z + v2i->z;
}

/*!
@brief Adds two double precision vectors

Add 3 by 1 column matrix v1i to v2i

\f$V_{2i} += V_{1i} \f$

@param v1i a first column vector input
@param v2i second column vector
*/
inline void ksl_addequal_vv(const ksl_vec3_t* restrict v1i,
                            ksl_vec3_t* restrict v2i) {
  v2i->x += v1i->x;
  v2i->y += v1i->y;
  v2i->z += v1i->z;
}

/*!
@brief Adds two single precision vectors

Add 3 by 1 column matrix v1i to v2i

\f$V_{2i} += V_{1i} \f$

@param v1i a first column vector input
@param v2i second column vector
*/
inline void ksl_addequal_vvf(const ksl_vec3f_t* restrict v1i,
                             ksl_vec3f_t* restrict v2i) {
  v2i->x += v1i->x;
  v2i->y += v1i->y;
  v2i->z += v1i->z;
}

/*!
@brief Subtract two double precision vectors

Add 3 by 1 column matrix v1i to v2i

\f$V_{2i} = V_{1i} - V_{2i}\f$

@param v1i [in]
@param v2i [in]
@param vo [out]
*/
inline void ksl_subtract_vv(const ksl_vec3_t* restrict v1i,
                            const ksl_vec3_t* restrict v2i,
                            ksl_vec3_t* restrict vo) {
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
inline void ksl_subtract_vvf(const ksl_vec3f_t* restrict v1i,
                             const ksl_vec3f_t* restrict v2i,
                             ksl_vec3f_t* restrict vo) {
  vo->x = v1i->x - v2i->x;
  vo->y = v1i->y - v2i->y;
  vo->z = v1i->z - v2i->z;
}

/*!
@brief double precision subtract v1i from v2i in place

\f$V_{2i} -= V_{1i} \f$

@param v1i [in]
@param v2i [in/out]
*/
inline void ksl_subtractequal_vv(const ksl_vec3_t* restrict v1i,
                                 ksl_vec3_t* restrict v2i) {
  v2i->x -= v1i->x;
  v2i->y -= v1i->y;
  v2i->z -= v1i->z;
}

/*!
@brief single precision subtract v1i from v2i in place

\f$V_{2i} -= V_{1i} \f$

@param v1i [in]
@param v2i [in/out]
*/
inline void ksl_subtractequal_vvf(const ksl_vec3f_t* restrict v1i,
                                  ksl_vec3f_t* restrict v2i) {
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
inline void ksl_axpy_vv(const double k, const ksl_vec3_t* restrict v1x,
                        ksl_vec3_t* restrict v2y) {
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
inline void ksl_axpy_vvf(const float k, const ksl_vec3f_t* restrict v1x,
                         ksl_vec3f_t* restrict v2y) {
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
inline void ksl_cross_vv(const ksl_vec3_t* restrict v1i,
                         const ksl_vec3_t* restrict v2i,
                         ksl_vec3_t* restrict vo) {
  vo->x = v1i->y * v2i->z - v1i->z * v2i->y;
  vo->y = v1i->z * v2i->x - v1i->x * v2i->z;
  vo->z = v1i->x * v2i->y - v1i->y * v2i->x;
}

void ksl_cross_vvinv(const ksl_vec3_t* restrict v1i,
                     const ksl_vec3_t* restrict v2i, ksl_vec3_t* vo);

/*!
@brief Compute single precision cross product of v1i with v2i

\f$V_{1i} \times V_{2i} \rightarrow V_o\f$

@param v1i a first 3x1 vector
@param v2i a second 3x1 vector
@param vo the results are stored in vo
*/
inline void ksl_cross_vvf(const ksl_vec3f_t* restrict v1i,
                          const ksl_vec3f_t* restrict v2i,
                          ksl_vec3f_t* restrict vo) {
  vo->x = v1i->y * v2i->z - v1i->z * v2i->y;
  vo->y = v1i->z * v2i->x - v1i->x * v2i->z;
  vo->z = v1i->x * v2i->y - v1i->y * v2i->x;
}

void ksl_cross_vvinvf(const ksl_vec3f_t* v1i, const ksl_vec3f_t* v2i,
                      ksl_vec3f_t* vo);

void ksl_add_ttx(const ksl_vec3_t* t1i, const double t2i, ksl_vec3_t* to);

void ksl_add_ttxf(const ksl_vec3f_t* t1i, const float t2i, ksl_vec3f_t* to);

void ksl_add_ttxinv(const ksl_vec3_t* t1i, const double t2i, ksl_vec3_t* to);

void ksl_add_ttxinvf(const ksl_vec3f_t* t1i, const float t2i, ksl_vec3f_t* to);

void ksl_add_tty(const ksl_vec3_t* t1i, const double t2i, ksl_vec3_t* to);

void ksl_add_ttyf(const ksl_vec3f_t* t1i, const float t2i, ksl_vec3f_t* to);

void ksl_add_ttyinv(const ksl_vec3_t* t1i, const double t2i, ksl_vec3_t* to);

void ksl_add_ttyinvf(const ksl_vec3f_t* t1i, const float t2i, ksl_vec3f_t* to);

void ksl_add_ttz(const ksl_vec3_t* t1i, const double t2i, ksl_vec3_t* to);

void ksl_add_ttzf(const ksl_vec3f_t* t1i, const float t2i, ksl_vec3f_t* to);

void ksl_add_ttzinv(const ksl_vec3_t* t1i, const double t2i, ksl_vec3_t* to);

void ksl_add_ttzinvf(const ksl_vec3f_t* t1i, const float t2i, ksl_vec3f_t* to);
