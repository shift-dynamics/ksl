#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "ksl/vec4.h"

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

