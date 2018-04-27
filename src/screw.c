#include <stdlib.h>

#include "screw.h"

/*!
@brief allocate n double precision screw quantities
*/
ksl_screw_t* ksl_screw_alloc(const int n) {
  return calloc(n, sizeof(ksl_screw_t));
}

/*!
@brief allocate n single precision screw quantities
*/
ksl_screwf_t* ksl_screwf_alloc(const int n) {
  return calloc(n, sizeof(ksl_screwf_t));
}

/*!
@brief allocate n double precision coscrew quantities
*/
ksl_coscrew_t* ksl_coscrew_alloc(const int n) {
  return calloc(n, sizeof(ksl_coscrew_t));
}

/*!
@brief allocate n single precision coscrew quantities
*/
ksl_coscrewf_t* ksl_coscrewf_alloc(const int n) {
  return calloc(n, sizeof(ksl_coscrewf_t));
}
