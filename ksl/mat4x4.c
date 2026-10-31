#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "ksl/SE3.h"
#include "ksl/mat3x3.h"
#include "ksl/mat4x4.h"
#include "ksl/vec3.h"
#include "ksl/vec4.h"

ksl_mat4x4_t* ksl_mat4x4_alloc(const int n) {
  ksl_mat4x4_t* M = calloc(n, sizeof(ksl_mat4x4_t));
  for(int i = 0; i < n; i++) {
    ksl_mat4x4_setIdentity(&M[i]);
  }
  return M;
}

ksl_mat4x4f_t* ksl_mat4x4f_alloc(const int n) {
  ksl_mat4x4f_t* M = calloc(n, sizeof(ksl_mat4x4f_t));
  for(int i = 0; i < n; i++) {
    ksl_mat4x4f_setIdentity(&M[i]);
  }
  return M;
}

