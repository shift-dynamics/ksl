#include <print.h>

/*!
@}
@name Printing utilities
Utilities to print vectors, screws, rotation matrices and SE3 transformations
@{
*/

/*!
@brief Utility to print a 3x1 column vector

prints a 3x1 column vector as a row vector

@param ti 3x1 column vector
*/
void ksl_vec3_print(FILE* f, const ksl_vec3_t* restrict vi) {

  fprintf(f, "%g %g %g\n", vi->x, vi->y, vi->z);
}

/*!
@brief Utility to print a 3x1 column vector

prints a 3x1 column vector as a row vector

@param ti 3x1 column vector
*/
void ksl_vec3f_print(FILE* f, const ksl_vec3f_t* restrict vi) {

  fprintf(f, "%g %g %g\n", vi->x, vi->y, vi->z);
}

void ksl_quaternion_print(FILE* f, const ksl_quaternion_t* restrict qi) {
  fprintf(f, "%g %g %g %g\n", qi->x, qi->y, qi->z, qi->w);
}

void ksl_quaternionf_print(FILE* f, const ksl_quaternionf_t* restrict qi) {
  fprintf(f, "%g %g %g %g\n", qi->x, qi->y, qi->z, qi->w);
}

/*!
@brief Utility to print a 6x1 screw vector

prints a 6x1 column vector as a row vector

@param si 6x1 column vector
*/
void ksl_screw_print(FILE* f, ksl_screw_t* restrict si) {

  fprintf(f, "%g %g %g %g %g %g\n", si[0], si[1], si[2], si[3], si[4], si[5]);
}

/*!
@brief Utility to print a 3x3 rotation matrix

prints a rotation matrix

@param ri 3x3 rotation matrix
*/
void ksl_mat3x3_print(FILE* f, ksl_mat3x3_t* __restrict__ ri) {

  fprintf(f, "%g %g %g\n", ri->m00, ri->m01, ri->m02);
  fprintf(f, "%g %g %g\n", ri->m10, ri->m11, ri->m12);
  fprintf(f, "%g %g %g\n", ri->m20, ri->m21, ri->m22);
}

/*!
@brief Utility to print a 3x3 rotation matrix

prints a rotation matrix

@param ri 3x3 rotation matrix
*/
void ksl_mat3x3f_print(FILE* f, ksl_mat3x3f_t* __restrict__ ri) {

  fprintf(f, "%g %g %g\n", ri->m00, ri->m01, ri->m02);
  fprintf(f, "%g %g %g\n", ri->m10, ri->m11, ri->m12);
  fprintf(f, "%g %g %g\n", ri->m20, ri->m21, ri->m22);
}

/*!
@brief Utility to print a general displacement, \f$D_i\f$

prints a general displacement as a 4x4 matrix for transforming
homogeneous coordinates. Note that the displacement is stored in
memory as a 12 x 1 contiguous array with terms of the rotation matrix
in the first 9 entries of the array (in row major order), followed by
translation terms in the last 3 entries of the array.

@param Di A general displacement, \f$D_i\f$
*/
void ksl_displacement_print(FILE* f, ksl_displacement_t* __restrict__ Di) {

  fprintf(f, "  % 9.9f % 9.9f % 9.9f % 9.9f\n", Di->R.m00, Di->R.m01, Di->R.m02,
          Di->t.x);
  fprintf(f, "  % 9.9f % 9.9f % 9.9f % 9.9f\n", Di->R.m10, Di->R.m11, Di->R.m12,
          Di->t.y);
  fprintf(f, "  % 9.9f % 9.9f % 9.9f % 9.9f\n", Di->R.m20, Di->R.m21, Di->R.m22,
          Di->t.z);
  fprintf(f, "  ");
  for(int i = 0; i < 3; i++) {
    fprintf(f, " 0.000000000 ");
  }
  fprintf(f, " 1.000000000\n");
}

/*!
@brief Utility to print an SE3 mat4 matrix

prints a ksl_Mat4f as a 4x4 matrix for transforming
homogeneous coordinates. Note that the displacement is stored in
memory as a 12 x 1 contiguous array with terms of the rotation matrix
in the first 9 entries of the array (in row major order), followed by
translation terms in the last 3 entries of the array.

@param Di A general displacement, \f$D_i\f$
*/
void ksl_mat4x4_print(FILE* f, ksl_mat4x4_t* __restrict__ Di) {

  fprintf(f, "%0.4f %0.4f %0.4f %0.4f\n", Di->m00, Di->m01, Di->m02, Di->m03);
  fprintf(f, "%0.4f %0.4f %0.4f %0.4f\n", Di->m10, Di->m11, Di->m12, Di->m13);
  fprintf(f, "%0.4f %0.4f %0.4f %0.4f\n", Di->m20, Di->m21, Di->m22, Di->m23);
  fprintf(f, "%0.4f %0.4f %0.4f %0.4f\n", Di->m30, Di->m31, Di->m32, Di->m33);
}

/*!
@brief Utility to print a SE3 mat4 matrix

prints a ksl_Mat4f as a 4x4 matrix for transforming
homogeneous coordinates. Note that the displacement is stored in
memory as a 12 x 1 contiguous array with terms of the rotation matrix
in the first 9 entries of the array (in row major order), followed by
translation terms in the last 3 entries of the array.

@param Di A general displacement, \f$D_i\f$
*/
void ksl_mat4x4f_print(FILE* f, ksl_mat4x4f_t* __restrict__ Di) {

  fprintf(f, "%0.4f %0.4f %0.4f %0.4f\n", Di->m00, Di->m01, Di->m02, Di->m03);
  fprintf(f, "%0.4f %0.4f %0.4f %0.4f\n", Di->m10, Di->m11, Di->m12, Di->m13);
  fprintf(f, "%0.4f %0.4f %0.4f %0.4f\n", Di->m20, Di->m21, Di->m22, Di->m23);
  fprintf(f, "%0.4f %0.4f %0.4f %0.4f\n", Di->m30, Di->m31, Di->m32, Di->m33);
}

/*!
@brief utility to print a general array of double of length n on one line
*/
void ksl_array_print(FILE* f, const uint32_t n, double* __restrict__ a) {

  for(uint32_t i = 0; i < n; i++) {
    fprintf(f, "%0.6g ", a[i]);
  }
  fprintf(f, "\n");
}

/*!
@brief utility to print a 2D array stored in a single pointer
with dimension rowDim * colDim
*/
void ksl_array2D_print(FILE* f, const uint32_t rowDim, const uint32_t colDim,
                       ksl_matrix_enum_t matrixType, double* __restrict__ A) {

  switch(matrixType) {

    case KSL_ROWMAJOR: {
      for(uint32_t i = 0; i < rowDim; i++) {
        fprintf(f, "  [");
        for(int j = 0; j < colDim; j++) {
          fprintf(f, "% 0.10f", A[i * colDim + j]);
          if(j != colDim - 1) {
            fprintf(f, ", ");
          }
        }
        fprintf(f, "]\n");
      }
    } break;

    case KSL_COLMAJOR: {
      for(int i = 0; i < rowDim; i++) {
        fprintf(f, "  ");
        for(int j = 0; j < colDim; j++) {
          fprintf(f, "% 0.10f ", A[i + j * rowDim]);
        }
        fprintf(f, "\n");
      }
    } break;
  }
}

/*!
@brief utility to print a general array of uint32_ts of length n on one line
*/
void ksl_arrayi_print(FILE* f, const uint32_t n, int* __restrict__ a) {

  for(uint32_t i = 0; i < n; i++) {
    fprintf(f, "%d ", a[i]);
  }
  fprintf(f, "\n");
}

/*!
@brief utility to print a lower triangular matrix of doubles stored in a
linear array
*/
void ksl_triang_print(FILE* f, const uint32_t n, double* __restrict__ A) {

  for(uint32_t i = 0; i < n; i++) {
    uint32_t i_s = (i * (i + 1) / 2);
    for(uint32_t j = 0; j < i + 1; j++) {
      fprintf(f, "% 9.4f ", A[i_s + j]);
    }
    fprintf(f, "\n");
  }
}

/*!
@brief utility to print a lower triangular matrix of uint32_tegers stored in a
linear array
*/
void ksl_triangi_print(FILE* f, const uint32_t n, int* __restrict__ A) {

  for(uint32_t i = 0; i < n; i++) {
    uint32_t i_s = (i * (i + 1) / 2);
    for(uint32_t j = 0; j < i + 1; j++) {
      fprintf(f, "% d ", A[i_s + j]);
    }
    fprintf(f, "\n");
  }
}

/*!
@brief utility to print a lower triangular matrix of uint32_tegers stored in a
linear array
*/
void ksl_triangb_print(FILE* f, const uint32_t n, bool* __restrict__ A) {

  for(int i = 0; i < n; i++) {
    uint32_t i_s = (i * (i + 1) / 2);
    for(int j = 0; j < i + 1; j++) {
      fprintf(f, "%s ", A[i_s + j] ? "1" : "0");
    }
    fprintf(f, "\n");
  }
}
