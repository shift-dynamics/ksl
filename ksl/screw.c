#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "ksl/SE3.h"
#include "ksl/coscrew.h"
#include "ksl/matrix.h"
#include "ksl/screw.h"
#include "ksl/vec3.h"

ksl_screw_t* ksl_screw_alloc(const int n) {
  return calloc(n, sizeof(ksl_screw_t));
}

ksl_screwf_t* ksl_screwf_alloc(const int n) {
  return calloc(n, sizeof(ksl_screwf_t));
}

inline void ksl_screw_copy_rmo(const ksl_screw_t* si, double* A, int row,
                               int column, int stride) {
  for(unsigned int i = 0; i < 6; i++) {
    A[(row + i) * stride + column] = si->at[i];
  }
}

inline void ksl_screw_ncopy_rmo(const ksl_screw_t* si, double* A, int row,
                                int column, int stride) {
  for(unsigned int i = 0; i < 6; i++) {
    A[(row + i) * stride + column] = -si->at[i];
  }
}

void ksl_screw_ncopy_cmo(const ksl_screw_t* si, double* A, int row, int column,
                         int stride) {
  for(unsigned int i = 0; i < 6; i++) {
    A[column * stride + row + i] = -si->at[i];
  }
}

void ksl_screwf_copy_rmo(const ksl_screwf_t* si, float* A, int row, int column,
                         int stride) {
  for(unsigned int i = 0; i < 6; i++) {
    A[(row + i) * stride + column] = si->at[i];
  }
}

void ksl_screwf_ncopy_rmo(const ksl_screwf_t* si, float* A, int row, int column,
                          int stride) {
  for(unsigned int i = 0; i < 6; i++) {
    A[(row + i) * stride + column] = -si->at[i];
  }
}

void ksl_screwf_ncopy_cmo(const ksl_screwf_t* si, float* A, int row, int column,
                          int stride) {
  for(unsigned int i = 0; i < 6; i++) {
    A[column * stride + row + i] = -si->at[i];
  }
}

