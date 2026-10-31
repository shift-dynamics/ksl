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
#ifdef KSL_WITH_BLAS_
  cblas_dcopy(6, (double*)(si), 1, A + (row * stride + column), stride);
#else
  for(unsigned int i = 0; i < 6; i++) {
    A[(row + i) * stride + column] = si->at[i];
  }
#endif
}

inline void ksl_screw_ncopy_rmo(const ksl_screw_t* si, double* A, int row,
                                int column, int stride) {
#ifdef KSL_WITH_BLAS_
  cblas_daxpy(6, -1.0, (double*)(si), 1, A + (row * stride + column), stride);
#else
  for(unsigned int i = 0; i < 6; i++) {
    A[(row + i) * stride + column] = -si->at[i];
  }
#endif
}

void ksl_screw_ncopy_cmo(const ksl_screw_t* si, double* A, int row, int column,
                         int stride) {
#ifdef KSL_WITH_BLAS_
  cblas_daxpy(6, -1.0, (double*)(si), 1, A + (column * stride + row), 1);
#else
  for(unsigned int i = 0; i < 6; i++) {
    A[column * stride + row + i] = -si->at[i];
  }
#endif
}

void ksl_screwf_copy_rmo(const ksl_screwf_t* si, float* A, int row, int column,
                         int stride) {
#ifdef KSL_WITH_BLAS_
  cblas_scopy(6, (float*)(si), 1, A + (row * stride + column), stride);
#else
  for(unsigned int i = 0; i < 6; i++) {
    A[(row + i) * stride + column] = si->at[i];
  }
#endif
}

void ksl_screwf_ncopy_rmo(const ksl_screwf_t* si, float* A, int row, int column,
                          int stride) {
#ifdef KSL_WITH_BLAS_
  cblas_saxpy(6, -1.0, (float*)(si), 1, A + (row * stride + column), stride);
#else
  for(unsigned int i = 0; i < 6; i++) {
    A[(row + i) * stride + column] = -si->at[i];
  }
#endif
}

void ksl_screwf_ncopy_cmo(const ksl_screwf_t* si, float* A, int row, int column,
                          int stride) {
#ifdef KSL_WITH_BLAS_
  cblas_saxpy(6, -1.0, (float*)(si), 1, A + (column * stride + row), 1);
#else
  for(unsigned int i = 0; i < 6; i++) {
    A[column * stride + row + i] = -si->at[i];
  }
#endif
}

