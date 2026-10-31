#include <assert.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include "ksl/SE3.h"
#include "ksl/mat4x4.h"
#include "ksl/matrix.h"

ksl_SE3_t* ksl_SE3_alloc(const int n) {
  ksl_SE3_t* D = calloc(n, sizeof(ksl_SE3_t));
  for(int i = 0; i < n; i++) {
    ksl_SE3_setIdentity(D + i);
  }
  return D;
}

ksl_SE3f_t* ksl_SE3f_alloc(const int n) {
  ksl_SE3f_t* D = calloc(n, sizeof(ksl_SE3f_t));
  for(int i = 0; i < n; i++) {
    ksl_SE3f_setIdentity(D + i);
  }
  return D;
}

