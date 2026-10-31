#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "ksl/SE3.h"
#include "ksl/coscrew.h"
#include "ksl/matrix.h"
#include "ksl/screw.h"
#include "ksl/vec3.h"

ksl_coscrew_t* ksl_coscrew_alloc(const int n) {
  return calloc(n, sizeof(ksl_coscrew_t));
}

ksl_coscrewf_t* ksl_coscrewf_alloc(const int n) {
  return calloc(n, sizeof(ksl_coscrewf_t));
}

