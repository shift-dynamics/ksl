#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "ksl/vec3.h"

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
@brief Computes the single precision product of a vector and 1/scalar

Note: this function does not check for divide by zero.

\f$V_i * 1 / k_i \rightarrow V_o\f$

@param vi [in] A 3x1 input vector
@param ki [in] a double precision scalar
@param vo [out] the results are returned in vo
*/
void ksl_product_ainvvf(const ksl_vec3f_t* restrict vi, const float ki,
                        ksl_vec3f_t* restrict vo) {
  register float inv = 1.0 / ki;
  vo->x = inv * vi->x;
  vo->y = inv * vi->y;
  vo->z = inv * vi->z;
}

