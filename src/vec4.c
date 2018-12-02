#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "ksl/vec4.h"

/*!
@brief vec4 constructor
*/
ksl_vec4_t ksl_vec4(const double x, const double y, const double z,
                    const double w) {
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
ksl_vec4f_t ksl_vec4f(const float x, const float y, const float z,
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
ksl_vec4i_t ksl_vec4i(const int x, const int y, const int z, const int w) {
  ksl_vec4i_t v;
  v.x = x;
  v.y = y;
  v.z = z;
  v.w = w;
  return v;
}

/*!
@brief initialize n ksl_vec4_t double precision vectors datastructures on the
heap
*/
inline ksl_vec4_t* ksl_vec4_alloc(int n) {
  return calloc(n, sizeof(ksl_vec4_t));
}

/*!
@brief initialize n ksl_vec4f_t single precision vectors datastructures on the
heap
*/
inline ksl_vec4f_t* ksl_vec4f_alloc(int n) {
  return calloc(n, sizeof(ksl_vec4f_t));
}

/*!
@brief initialize n ksl_vec4i_t vectors of integers on the heap
*/
inline ksl_vec4i_t* ksl_vec4i_alloc(int n) {
  return calloc(n, sizeof(ksl_vec4i_t));
}

/*!
@brief compute the norm of a double precision vector
*/
inline double ksl_vec4_l2norm(const ksl_vec4_t* restrict v) {
  return sqrt(v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w);
}

/*!
@brief compute the norm of a single precision vector
*/
float ksl_vec4f_l2norm(const ksl_vec4f_t* restrict v) {
  return sqrt(v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w);
}

/*!
@brief Normalize a double precision vector.

@param v [in/out] vector to normalize
*/
inline void ksl_vec4_normalize(ksl_vec4_t* restrict v) {
  double norm = ksl_vec4_l2norm(v);
  ksl_vec4_scale(v, 1.0 / norm);
}

/*!
@brief Normalize a single precision vector

@param v [in/out] vector to normalize
*/
inline void ksl_vec4f_normalize(ksl_vec4f_t* restrict v) {
  float norm = ksl_vec4f_l2norm(v);
  ksl_vec4f_scale(v, 1.0 / norm);
}

/*!
@brief Normalize a double precision vector leaving original datastructure
unmodified; results are returned in second datastructure.

@param v [in/out] vector to normalize
*/
inline void ksl_vec4_normalized(const ksl_vec4_t* restrict v,
                                ksl_vec4_t* restrict vo) {
  ksl_vec4_copy(v, vo);
  ksl_vec4_normalize(vo);
}

/*!
@brief Normalize a single precision vector leaving original datastructure
unmodified; results are returned in second datastructure.

@param v [in/out] vector to normalize
*/
inline void ksl_vec4f_normalized(const ksl_vec4f_t* restrict v,
                                 ksl_vec4f_t* restrict vo) {
  ksl_vec4f_copy(v, vo);
  ksl_vec4f_normalize(vo);
}

/*!
@brief Scale a double precision vector

@param v [in/out] vector to scale
*/
void ksl_vec4_scale(ksl_vec4_t* restrict v, const double k) {
  v->x *= k;
  v->y *= k;
  v->z *= k;
  v->w *= k;
}

/*!
@brief Scale a single precision vector

@param v [in/out] vector to scale
*/
void ksl_vec4f_scale(ksl_vec4f_t* restrict v, const float k) {
  v->x *= k;
  v->y *= k;
  v->z *= k;
  v->w *= k;
}

/*!
@brief Scale a double precision vector, returning results in second vector.

@param v [in/out] vector to scale
*/
void ksl_vec4_scaled(const ksl_vec4_t* restrict v, const double k,
                     ksl_vec4_t* restrict vo) {
  vo->x = v->x * k;
  vo->y = v->y * k;
  vo->z = v->z * k;
  vo->w = v->w * k;
}

/*!
@brief Scale a single precision vector, returning results in second vector.

@param v [in/out] vector to scale
*/
void ksl_vec4f_scaled(const ksl_vec4f_t* restrict v, const float k,
                      ksl_vec4f_t* restrict vo) {
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
inline void ksl_vec4_copy(const ksl_vec4_t* restrict vi,
                          ksl_vec4_t* restrict vo) {
  memcpy(vo, vi, sizeof(ksl_vec4_t));
}

/*!
@brief Copy a single precision ksl_vec3f_t vi into ksl_vec3f_t vo.

\f$V_i \rightarrow V_o\f$

@param vi input vector \f$V_i\f$
@param vo output vector \f$V_o\f$
*/
inline void ksl_vec4f_copy(const ksl_vec4f_t* restrict vi,
                           ksl_vec4f_t* restrict vo) {
  memcpy(vo, vi, sizeof(ksl_vec4f_t));
}

/*!
@brief Swap double precision vectors vio1 and vio2.

\f$V_io1 \rightarrow V_io2\f$
\f$V_io2 \rightarrow V_io1\f$

@param vio1 input/output vector \f$V_io1\f$
@param vio2 input/output vector \f$V_io2\f$
*/
inline void ksl_vec4_swap(ksl_vec4_t* restrict vio1,
                          ksl_vec4_t* restrict vio2) {
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
inline void ksl_vec4f_swap(ksl_vec4f_t* restrict vio1,
                           ksl_vec4f_t* restrict vio2) {
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
inline void ksl_vec4_inverted(const ksl_vec4_t* restrict vi,
                              ksl_vec4_t* restrict vo) {
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
inline void ksl_vec4_invert(ksl_vec4_t* restrict vi) {
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
inline void ksl_vec4f_inverted(const ksl_vec4f_t* restrict vi,
                               ksl_vec4f_t* restrict vo) {
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
inline void ksl_vec4f_invert(ksl_vec4f_t* restrict vi) {
  vi->x = -vi->x;
  vi->y = -vi->y;
  vi->z = -vi->z;
  vi->w = -vi->w;
}
