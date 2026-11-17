#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ksl/array.h"
#include "ksl/linalg.h"
#include "ksl/mat3x3.h"
#include "ksl/matrix.h"
#include "ksl/trig.h"

ksl_mat3x3_t* ksl_mat3x3_alloc(const int n) {
  ksl_mat3x3_t* R = calloc(n, sizeof(ksl_mat3x3_t));
  for(int i = 0; i < n; i++) {
    ksl_mat3x3_setIdentity(&R[i]);
  }
  return R;
}

ksl_mat3x3f_t* ksl_mat3x3f_alloc(const int n) {
  ksl_mat3x3f_t* R = calloc(n, sizeof(ksl_mat3x3f_t));
  for(int i = 0; i < n; i++) {
    ksl_mat3x3f_setIdentity(&R[i]);
  }
  return R;
}

/* the inverse of a 3x3 matrix by Gauss-Jordan elimination with partial
pivoting: in each column, the row whose entry is largest in magnitude is
the pivot. Returns 0, or -(k + 1) if no entry of column k (after the
eliminations before it) is as large as 1e-12, the matrix being singular; ro
is then not written. ri and ro may be the same matrix. */
static int ksl_mat3x3_pivotedInverse(const ksl_mat3x3_t* ri,
                                     ksl_mat3x3_t* ro) {
  /* a and x row major: a[r][c] = ri->at[c][r], x the identity */
  double a[3][3], x[3][3];
  for(int r = 0; r < 3; r++) {
    for(int c = 0; c < 3; c++) {
      a[r][c] = ri->at[c][r];
      x[r][c] = r == c ? 1.0 : 0.0;
    }
  }
  for(int k = 0; k < 3; k++) {
    int p = k;
    for(int r = k + 1; r < 3; r++) {
      if(fabs(a[r][k]) > fabs(a[p][k])) {
        p = r;
      }
    }
    if(!(fabs(a[p][k]) >= 1e-12)) {
      return -(k + 1);
    }
    if(p != k) {
      for(int c = 0; c < 3; c++) {
        double t = a[k][c];
        a[k][c] = a[p][c];
        a[p][c] = t;
        t = x[k][c];
        x[k][c] = x[p][c];
        x[p][c] = t;
      }
    }
    const double pivot = a[k][k];
    for(int c = 0; c < 3; c++) {
      a[k][c] /= pivot;
      x[k][c] /= pivot;
    }
    for(int r = 0; r < 3; r++) {
      if(r == k) {
        continue;
      }
      const double f = a[r][k];
      for(int c = 0; c < 3; c++) {
        a[r][c] -= f * a[k][c];
        x[r][c] -= f * x[k][c];
      }
    }
  }
  for(int r = 0; r < 3; r++) {
    for(int c = 0; c < 3; c++) {
      ro->at[c][r] = x[r][c];
    }
  }
  return 0;
}

/* single precision ksl_mat3x3_pivotedInverse */
static int ksl_mat3x3f_pivotedInverse(const ksl_mat3x3f_t* ri,
                                      ksl_mat3x3f_t* ro) {
  float a[3][3], x[3][3];
  for(int r = 0; r < 3; r++) {
    for(int c = 0; c < 3; c++) {
      a[r][c] = ri->at[c][r];
      x[r][c] = r == c ? 1.0f : 0.0f;
    }
  }
  for(int k = 0; k < 3; k++) {
    int p = k;
    for(int r = k + 1; r < 3; r++) {
      if(fabsf(a[r][k]) > fabsf(a[p][k])) {
        p = r;
      }
    }
    if(!(fabsf(a[p][k]) >= 1e-12f)) {
      return -(k + 1);
    }
    if(p != k) {
      for(int c = 0; c < 3; c++) {
        float t = a[k][c];
        a[k][c] = a[p][c];
        a[p][c] = t;
        t = x[k][c];
        x[k][c] = x[p][c];
        x[p][c] = t;
      }
    }
    const float pivot = a[k][k];
    for(int c = 0; c < 3; c++) {
      a[k][c] /= pivot;
      x[k][c] /= pivot;
    }
    for(int r = 0; r < 3; r++) {
      if(r == k) {
        continue;
      }
      const float f = a[r][k];
      for(int c = 0; c < 3; c++) {
        a[r][c] -= f * a[k][c];
        x[r][c] -= f * x[k][c];
      }
    }
  }
  for(int r = 0; r < 3; r++) {
    for(int c = 0; c < 3; c++) {
      ro->at[c][r] = x[r][c];
    }
  }
  return 0;
}

/*!@brief Performs the general matrix inverse for a ksl_mat3x3_t matrix in-place
with partial pivoting. If the matrix is an orthonormal rotation matrix with a
determinant of one, (i.e. it is in SO3), then the less expensive matrix
transpose function can be used for performing the inverse */
inline int ksl_mat3x3_invert(ksl_mat3x3_t* restrict R) {
  return ksl_mat3x3_pivotedInverse(R, R);
}

/*!@brief Single precision version of ksl_mat3x3_invert() */
inline int ksl_mat3x3f_invert(ksl_mat3x3f_t* restrict R) {
  return ksl_mat3x3f_pivotedInverse(R, R);
}

/*!@brief Performs the general matrix inverse for a ksl_mat3x3_t matrix
with partial pivoting. If the matrix is an orthonormal rotation matrix with a
determinant of one, (i.e. it is in SO3), then the less expensive matrix
transpose function can be used for performing the inverse */
inline int ksl_mat3x3_inverted(const ksl_mat3x3_t* restrict ri,
                               ksl_mat3x3_t* restrict ro) {
  return ksl_mat3x3_pivotedInverse(ri, ro);
}

/*!@brief Single precision version of ksl_mat3x3_inverted() */
inline int ksl_mat3x3f_inverted(const ksl_mat3x3f_t* restrict ri,
                                ksl_mat3x3f_t* restrict ro) {
  return ksl_mat3x3f_pivotedInverse(ri, ro);
}

inline void
ksl_mat3x3_getEulerAnglesWithReference(const ksl_mat3x3_t* r,
                                       const ksl_axis_enum_t axisType,
                                       ksl_vec3_t* angles, ...) {

  va_list arguments;
  va_start(arguments, angles);
  ksl_vec3_t* reference = va_arg(arguments, ksl_vec3_t*);
  va_end(arguments);
  ksl_vec3_t reference_angles = ksl_vec3(0.0, 0.0, 0.0);
  if(!reference) {
    reference = &reference_angles;
  }

  // Temp variables to hold the true sin and cos values of third angle.
  double c;
  double s;

  switch(axisType) {
    case KSL_AXIS_XYZ:
      // i = 0, j = 1, k = 2
      // angle[2] = ksl_catan1pi(-Ri[i][j], Ri[i][i], angle[2]);
      // angle[0] = ksl_catan2pi(Ri[k][j]*c + Ri[k][i]*s, Ri[j][j]*c +
      // Ri[j][i] * s,
      // angle[0]); angle[1] = ksl_catan2pi(Ri[i][k], Ri[i][i]*c - Ri[i][j]*s,
      // angle[1]);
      angles->at[2] = ksl_catan1pi(-r->at[1][0], r->at[0][0], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        ksl_catan2pi(r->at[1][2] * c + r->at[0][2] * s,
                     r->at[1][1] * c + r->at[0][1] * s, reference->at[0]);
      angles->at[1] = ksl_catan2pi(
        r->at[2][0], r->at[0][0] * c - r->at[1][0] * s, reference->at[1]);
      break;
    case KSL_AXIS_YZX:
      // i = 1, j = 2, k = 0
      // angle[2] = ksl_catan1pi(-Ri[i][j], Ri[i][i], angle[2]);
      // angle[0] = ksl_catan2pi(Ri[k][j]*c + Ri[k][i]*s, Ri[j][j]*c +
      // Ri[j][i] * s,
      // angle[0]); angle[1] = ksl_catan2pi(Ri[i][k], Ri[i][i]*c - Ri[i][j]*s,
      // angle[1]);
      angles->at[2] = ksl_catan1pi(-r->at[2][1], r->at[1][1], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        ksl_catan2pi(r->at[2][0] * c + r->at[1][0] * s,
                     r->at[2][2] * c + r->at[1][2] * s, reference->at[0]);
      angles->at[1] = ksl_catan2pi(
        r->at[0][1], r->at[1][1] * c - r->at[2][1] * s, reference->at[1]);
      break;
    case KSL_AXIS_ZXY:
      // i = 2, j = 0, k = 1
      // angle[2] = ksl_catan1pi(-Ri[i][j], Ri[i][i], angle[2]);
      // angle[0] = ksl_catan2pi(Ri[k][j]*c + Ri[k][i]*s, Ri[j][j]*c +
      // Ri[j][i] * s,
      // angle[0]); angle[1] = ksl_catan2pi(Ri[i][k], Ri[i][i]*c - Ri[i][j]*s,
      // angle[1]);
      angles->at[2] = ksl_catan1pi(-r->at[0][2], r->at[2][2], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        ksl_catan2pi(r->at[0][1] * c + r->at[2][1] * s,
                     r->at[0][0] * c + r->at[2][0] * s, reference->at[0]);
      angles->at[1] = ksl_catan2pi(
        r->at[1][2], r->at[2][2] * c - r->at[0][2] * s, reference->at[1]);
      break;
    case KSL_AXIS_XYX:
      // i = 0, j = 1, k = 0
      // Set k = 2 for correct index into direction cosine matrix.
      // angle[2] = ksl_catan1pi(Ri[i][j], Ri[i][k], angle[2]);
      // angle[0] = ksl_catan2pi(Ri[k][j]*c - Ri[k][k]*s, Ri[j][j]*c -
      // Ri[j][k] * s,
      // angle[0]); angle[1] = ksl_catan2pi(Ri[i][k]*c + Ri[i][j]*s, Ri[i][i],
      // angle[1]);		k = f[j];
      angles->at[2] = ksl_catan1pi(r->at[1][0], r->at[2][0], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        ksl_catan2pi(r->at[1][2] * c - r->at[2][2] * s,
                     r->at[1][1] * c - r->at[2][1] * s, reference->at[0]);
      angles->at[1] = ksl_catan2pi(r->at[2][0] * c + r->at[1][0] * s,
                                   r->at[0][0], reference->at[1]);
      break;
    case KSL_AXIS_YZY:
      // i = 1, j = 2, k = 1
      // Set k = 0 for correct index into direction cosine matrix.
      // angle[2] = ksl_catan1pi(Ri[i][j], Ri[i][k], angle[2]);
      // angle[0] = ksl_catan2pi(Ri[k][j]*c - Ri[k][k]*s, Ri[j][j]*c -
      // Ri[j][k] * s,
      // angle[0]); angle[1] = ksl_catan2pi(Ri[i][k]*c + Ri[i][j]*s, Ri[i][i],
      // angle[1]);
      angles->at[2] = ksl_catan1pi(r->at[2][1], r->at[0][1], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        ksl_catan2pi(r->at[2][0] * c - r->at[0][0] * s,
                     r->at[2][2] * c - r->at[0][2] * s, reference->at[0]);
      angles->at[1] = ksl_catan2pi(r->at[0][1] * c + r->at[2][1] * s,
                                   r->at[1][1], reference->at[1]);
      break;
    case KSL_AXIS_ZXZ:
      // i = 2, j = 0, k = 2
      // Set k = 1 for correct index into direction cosine matrix.
      // angle[2] = ksl_catan1pi(Ri[i][j], Ri[i][k], angle[2]);
      // angle[0] = ksl_catan2pi(Ri[k][j]*c - Ri[k][k]*s, Ri[j][j]*c -
      // Ri[j][k] * s,
      // angle[0]);
      // angle[1] = ksl_catan2pi(Ri[i][k]*c + Ri[i][j]*s, Ri[i][i],
      // angle[1]);
      angles->at[2] = ksl_catan1pi(r->at[0][2], r->at[1][2], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        ksl_catan2pi(r->at[0][1] * c - r->at[1][1] * s,
                     r->at[0][0] * c - r->at[1][0] * s, reference->at[0]);
      angles->at[1] = ksl_catan2pi(r->at[1][2] * c + r->at[0][2] * s,
                                   r->at[2][2], reference->at[1]);
      break;
    case KSL_AXIS_XZY:
      // i = 0, j = 2, k = 1
      // angle[2] = ksl_catan1pi(Ri[i][j], Ri[i][i], angle[2]);
      // angle[0] = ksl_catan2pi(-(Ri[k][j]*c - Ri[k][i]*s), Ri[j][j]*c -
      // Ri[j][i]*s, angle[0]);  angle[1] = ksl_catan2pi(-Ri[i][k], Ri[i][i]*c +
      // Ri[i][j]*s, angle[1]);
      angles->at[2] = ksl_catan1pi(r->at[2][0], r->at[0][0], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        ksl_catan2pi(-(r->at[2][1] * c - r->at[0][1] * s),
                     r->at[2][2] * c - r->at[0][2] * s, reference->at[0]);
      angles->at[1] = ksl_catan2pi(
        -r->at[1][0], r->at[0][0] * c + r->at[2][0] * s, reference->at[1]);
      break;
    case KSL_AXIS_YXZ:
      // i = 1, j = 0, k = 2
      // angle[2] = ksl_catan1pi(Ri[i][j], Ri[i][i], angle[2]);
      // angle[0] = ksl_catan2pi(-(Ri[k][j]*c - Ri[k][i]*s), Ri[j][j]*c -
      // Ri[j][i]*s, angle[0]);  angle[1] = ksl_catan2pi(-Ri[i][k], Ri[i][i]*c +
      // Ri[i][j]*s, angle[1]);
      angles->at[2] = ksl_catan1pi(r->at[0][1], r->at[1][1], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        ksl_catan2pi(-(r->at[0][2] * c - r->at[1][2] * s),
                     r->at[0][0] * c - r->at[1][0] * s, reference->at[0]);
      angles->at[1] = ksl_catan2pi(
        -r->at[2][1], r->at[1][1] * c + r->at[0][1] * s, reference->at[1]);
      break;
    case KSL_AXIS_ZYX:
      // i = 2, j = 1, k = 0
      // angle[2] = ksl_catan1pi(Ri[i][j], Ri[i][i], angle[2]);
      // angle[0] = ksl_catan2pi(-(Ri[k][j]*c - Ri[k][i]*s), Ri[j][j]*c -
      // Ri[j][i]*s, angle[0]);  angle[1] = ksl_catan2pi(-Ri[i][k], Ri[i][i]*c +
      // Ri[i][j]*s, angle[1]);
      angles->at[2] = ksl_catan1pi(r->at[1][2], r->at[2][2], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        ksl_catan2pi(-(r->at[1][0] * c - r->at[2][0] * s),
                     r->at[1][1] * c - r->at[2][1] * s, reference->at[0]);
      angles->at[1] = ksl_catan2pi(
        -r->at[0][2], r->at[2][2] * c + r->at[1][2] * s, reference->at[1]);
      break;
    case KSL_AXIS_XZX:
      // i = 0, j = 2, k = 0
      // Set k = 1 for correct index into direction cosine matrix.
      // angle[2] = ksl_catan1pi(-Ri[i][j], Ri[i][k], angle[2]);
      // angle[0] = ksl_catan2pi(-(Ri[k][j]*c + Ri[k][k]*s), Ri[j][j]*c +
      // Ri[j][k]*s, angle[0]);  angle[1] = ksl_catan2pi(-(Ri[i][k]*c -
      // Ri[i][j]*s),
      // Ri[i][i], angle[1]);
      angles->at[2] = ksl_catan1pi(-r->at[2][0], r->at[1][0], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        ksl_catan2pi(-(r->at[2][1] * c + r->at[1][1] * s),
                     r->at[2][2] * c + r->at[1][2] * s, reference->at[0]);
      angles->at[1] = ksl_catan2pi(-(r->at[1][0] * c - r->at[2][0] * s),
                                   r->at[0][0], reference->at[1]);
      break;
    case KSL_AXIS_YXY:
      // i = 1, j = 0, k = 1
      // Set k = 2 for correct index into direction cosine matrix.
      // angle[2] = ksl_catan1pi(-Ri[i][j], Ri[i][k], angle[2]);
      // angle[0] = ksl_catan2pi(-(Ri[k][j]*c + Ri[k][k]*s), Ri[j][j]*c +
      // Ri[j][k]*s, angle[0]);  angle[1] = ksl_catan2pi(-(Ri[i][k]*c -
      // Ri[i][j]*s),
      // Ri[i][i], angle[1]);
      angles->at[2] = ksl_catan1pi(-r->at[0][1], r->at[2][1], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        ksl_catan2pi(-(r->at[0][2] * c + r->at[2][2] * s),
                     r->at[0][0] * c + r->at[2][0] * s, reference->at[0]);
      angles->at[1] = ksl_catan2pi(-(r->at[2][1] * c - r->at[0][1] * s),
                                   r->at[1][1], reference->at[1]);
      break;
    case KSL_AXIS_ZYZ:
      // i = 2, j = 1, k = 2
      // Set k = 0 for correct index into direction cosine matrix.
      // angle[2] = ksl_catan1pi(-Ri[i][j], Ri[i][k], angle[2]);
      // angle[0] = ksl_catan2pi(-(Ri[k][j]*c + Ri[k][k]*s), Ri[j][j]*c +
      // Ri[j][k]*s, angle[0]);  angle[1] = ksl_catan2pi(-(Ri[i][k]*c -
      // Ri[i][j]*s),
      // Ri[i][i], angle[1]);
      angles->at[2] = ksl_catan1pi(-r->at[1][2], r->at[0][2], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        ksl_catan2pi(-(r->at[1][0] * c + r->at[0][0] * s),
                     r->at[1][1] * c + r->at[0][1] * s, reference->at[0]);
      angles->at[1] = ksl_catan2pi(-(r->at[0][2] * c - r->at[1][2] * s),
                                   r->at[2][2], reference->at[1]);
      break;
    default:
      fprintf(
        stderr,
        "\nError:invalid axis sequence in function ksl_mat3x3_getEulerAngles"
        " -- Aborting.\n");
      exit(1);
  }

  // const int f[3] = {1, 2, 0};
  //
  // ksl_vec3i_t axes = ksl_axis_getVector(axisType);
  //
  // /* Short notation for the axis identifiers. */
  // int i = axes.x;
  // int j = axes.y;
  // int k = axes.z;
  //
  // /* The value of k will be changed in Cases 3 and 4.
  // Temp variables to hold true sin and cos values of third angle. */
  // double c;
  // double s;
  //
  // if(j == f[i]) { // Identifies Cases 1 and 3: forward cycle i --> j
  //   if(k != i) {  // forward cycle j --> k
  //     // Case 1: 0 --> 1 --> 2; 1 --> 2 --> 0; 2 --> 0 --> 1
  //     angles->y = ksl_catan1pi(-r->at [j][i], r->at [i][i],
  //     reference->y); c = cos(angles->y); s = sin(angles->y); angles->x =
  //       ksl_catan2pi(r->at [j][k] * c + r->at [i][k] * s,
  //                r->at [j][j] * c + r->at [i][j] * s,
  //                reference->x);
  //     angles->y =
  //       ksl_catan2pi(r->at [k][i],
  //                r->at [i][i] * c - r->at [j][i] * s,
  //                reference->y);
  //   } else { // k == i; reverse cycle j --> i
  //     // Case 3: 0 --> 1 --> 0; 1 --> 2 --> 1; 2 --> 0 --> 2
  //     // Reset k for correct index into direction cosine matrix.
  //     k = f[j];
  //     angles->z = ksl_catan1pi(r->at [j][i], r->at [k][i],
  //     reference->z); c = cos(angles->z); s = sin(angles->z); angles->x =
  //       ksl_catan2pi(r->at [j][k] * c - r->at [k][k] * s,
  //                r->at [j][j] * c - r->at [k][j] * s,
  //                reference->x);
  //     angles->y = ksl_catan2pi(r->at [k][i] * c + r->at [j][i] * s,
  //                          r->at [i][i], reference->y);
  //   }
  // } else {       // Cases 2 and 4: reverse cycle i --> j
  //   if(k != i) { // reverse cycle j --> k
  //     // Case 2: 0 --> 2 --> 1; 1 --> 0 --> 2; 2 --> 1 --> 0
  //     angles->z = ksl_catan1pi(r->at [j][i], r->at [i][i],
  //     reference->z); c = cos(angles->z); s = sin(angles->z); angles->x =
  //       ksl_catan2pi(-(r->at [j][k] * c - r->at [i][k] * s),
  //                r->at [j][j] * c - r->at [i][j] * s,
  //                reference->x);
  //     angles->y =
  //       ksl_catan2pi(-r->at [k][i],
  //                r->at [i][i] * c + r->at [j][i] * s,
  //                reference->y);
  //   } else { // k == i; forward cycle j --> i
  //     // Case 4: 0 --> 2 --> 0; 1 --> 0 --> 1; 2 --> 1 --> 2
  //     // Reset k for correct index into direction cosine matrix.
  //     k = f[i];
  //     angles->z = ksl_catan1pi(-r->at [j][i], r->at [k][i],
  //     reference->z); c = cos(angles->z); s = sin(angles->z); angles->x =
  //       ksl_catan2pi(-(r->at [j][k] * c + r->at [k][k] * s),
  //                r->at [j][j] * c + r->at [k][j] * s,
  //                reference->x);
  //     angles->y = ksl_catan2pi(-(r->at [k][i] * c - r->at [j][i] * s),
  //                          r->at [i][i], reference->y);
  //   }
  // }
}

inline void
ksl_mat3x3f_getEulerAnglesWithReference(const ksl_mat3x3f_t* r,
                                        const ksl_axis_enum_t axisType,
                                        ksl_vec3f_t* angles, ...) {

  va_list arguments;
  va_start(arguments, angles);
  ksl_vec3f_t* reference = va_arg(arguments, ksl_vec3f_t*);
  va_end(arguments);
  ksl_vec3f_t reference_angles = ksl_vec3f(0.0, 0.0, 0.0);
  if(!reference) {
    reference = &reference_angles;
  }

  // Temp variables to hold the true sin and cos values of third angle.
  double c;
  double s;

  switch(axisType) {
    case KSL_AXIS_XYZ:
      // i = 0, j = 1, k = 2
      // angle[2] = ksl_catan1pi(-Ri[i][j], Ri[i][i], angle[2]);
      // angle[0] = ksl_catan2pi(Ri[k][j]*c + Ri[k][i]*s, Ri[j][j]*c +
      // Ri[j][i] * s,
      // angle[0]); angle[1] = ksl_catan2pi(Ri[i][k], Ri[i][i]*c - Ri[i][j]*s,
      // angle[1]);
      angles->at[2] = ksl_catan1pi(-r->at[1][0], r->at[0][0], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        ksl_catan2pi(r->at[1][2] * c + r->at[0][2] * s,
                     r->at[1][1] * c + r->at[0][1] * s, reference->at[0]);
      angles->at[1] = ksl_catan2pi(
        r->at[2][0], r->at[0][0] * c - r->at[1][0] * s, reference->at[1]);
      break;
    case KSL_AXIS_YZX:
      // i = 1, j = 2, k = 0
      // angle[2] = ksl_catan1pi(-Ri[i][j], Ri[i][i], angle[2]);
      // angle[0] = ksl_catan2pi(Ri[k][j]*c + Ri[k][i]*s, Ri[j][j]*c +
      // Ri[j][i] * s,
      // angle[0]); angle[1] = ksl_catan2pi(Ri[i][k], Ri[i][i]*c - Ri[i][j]*s,
      // angle[1]);
      angles->at[2] = ksl_catan1pi(-r->at[2][1], r->at[1][1], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        ksl_catan2pi(r->at[2][0] * c + r->at[1][0] * s,
                     r->at[2][2] * c + r->at[1][2] * s, reference->at[0]);
      angles->at[1] = ksl_catan2pi(
        r->at[0][1], r->at[1][1] * c - r->at[2][1] * s, reference->at[1]);
      break;
    case KSL_AXIS_ZXY:
      // i = 2, j = 0, k = 1
      // angle[2] = ksl_catan1pi(-Ri[i][j], Ri[i][i], angle[2]);
      // angle[0] = ksl_catan2pi(Ri[k][j]*c + Ri[k][i]*s, Ri[j][j]*c +
      // Ri[j][i] * s,
      // angle[0]); angle[1] = ksl_catan2pi(Ri[i][k], Ri[i][i]*c - Ri[i][j]*s,
      // angle[1]);
      angles->at[2] = ksl_catan1pi(-r->at[0][2], r->at[2][2], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        ksl_catan2pi(r->at[0][1] * c + r->at[2][1] * s,
                     r->at[0][0] * c + r->at[2][0] * s, reference->at[0]);
      angles->at[1] = ksl_catan2pi(
        r->at[1][2], r->at[2][2] * c - r->at[0][2] * s, reference->at[1]);
      break;
    case KSL_AXIS_XYX:
      // i = 0, j = 1, k = 0
      // Set k = 2 for correct index into direction cosine matrix.
      // angle[2] = ksl_catan1pi(Ri[i][j], Ri[i][k], angle[2]);
      // angle[0] = ksl_catan2pi(Ri[k][j]*c - Ri[k][k]*s, Ri[j][j]*c -
      // Ri[j][k] * s,
      // angle[0]); angle[1] = ksl_catan2pi(Ri[i][k]*c + Ri[i][j]*s, Ri[i][i],
      // angle[1]);		k = f[j];
      angles->at[2] = ksl_catan1pi(r->at[1][0], r->at[2][0], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        ksl_catan2pi(r->at[1][2] * c - r->at[2][2] * s,
                     r->at[1][1] * c - r->at[2][1] * s, reference->at[0]);
      angles->at[1] = ksl_catan2pi(r->at[2][0] * c + r->at[1][0] * s,
                                   r->at[0][0], reference->at[1]);
      break;
    case KSL_AXIS_YZY:
      // i = 1, j = 2, k = 1
      // Set k = 0 for correct index into direction cosine matrix.
      // angle[2] = ksl_catan1pi(Ri[i][j], Ri[i][k], angle[2]);
      // angle[0] = ksl_catan2pi(Ri[k][j]*c - Ri[k][k]*s, Ri[j][j]*c -
      // Ri[j][k] * s,
      // angle[0]); angle[1] = ksl_catan2pi(Ri[i][k]*c + Ri[i][j]*s, Ri[i][i],
      // angle[1]);
      angles->at[2] = ksl_catan1pi(r->at[2][1], r->at[0][1], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        ksl_catan2pi(r->at[2][0] * c - r->at[0][0] * s,
                     r->at[2][2] * c - r->at[0][2] * s, reference->at[0]);
      angles->at[1] = ksl_catan2pi(r->at[0][1] * c + r->at[2][1] * s,
                                   r->at[1][1], reference->at[1]);
      break;
    case KSL_AXIS_ZXZ:
      // i = 2, j = 0, k = 2
      // Set k = 1 for correct index into direction cosine matrix.
      // angle[2] = ksl_catan1pi(Ri[i][j], Ri[i][k], angle[2]);
      // angle[0] = ksl_catan2pi(Ri[k][j]*c - Ri[k][k]*s, Ri[j][j]*c -
      // Ri[j][k] * s,
      // angle[0]);
      // angle[1] = ksl_catan2pi(Ri[i][k]*c + Ri[i][j]*s, Ri[i][i],
      // angle[1]);
      angles->at[2] = ksl_catan1pi(r->at[0][2], r->at[1][2], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        ksl_catan2pi(r->at[0][1] * c - r->at[1][1] * s,
                     r->at[0][0] * c - r->at[1][0] * s, reference->at[0]);
      angles->at[1] = ksl_catan2pi(r->at[1][2] * c + r->at[0][2] * s,
                                   r->at[2][2], reference->at[1]);
      break;
    case KSL_AXIS_XZY:
      // i = 0, j = 2, k = 1
      // angle[2] = ksl_catan1pi(Ri[i][j], Ri[i][i], angle[2]);
      // angle[0] = ksl_catan2pi(-(Ri[k][j]*c - Ri[k][i]*s), Ri[j][j]*c -
      // Ri[j][i]*s, angle[0]);  angle[1] = ksl_catan2pi(-Ri[i][k], Ri[i][i]*c +
      // Ri[i][j]*s, angle[1]);
      angles->at[2] = ksl_catan1pi(r->at[2][0], r->at[0][0], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        ksl_catan2pi(-(r->at[2][1] * c - r->at[0][1] * s),
                     r->at[2][2] * c - r->at[0][2] * s, reference->at[0]);
      angles->at[1] = ksl_catan2pi(
        -r->at[1][0], r->at[0][0] * c + r->at[2][0] * s, reference->at[1]);
      break;
    case KSL_AXIS_YXZ:
      // i = 1, j = 0, k = 2
      // angle[2] = ksl_catan1pi(Ri[i][j], Ri[i][i], angle[2]);
      // angle[0] = ksl_catan2pi(-(Ri[k][j]*c - Ri[k][i]*s), Ri[j][j]*c -
      // Ri[j][i]*s, angle[0]);  angle[1] = ksl_catan2pi(-Ri[i][k], Ri[i][i]*c +
      // Ri[i][j]*s, angle[1]);
      angles->at[2] = ksl_catan1pi(r->at[0][1], r->at[1][1], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        ksl_catan2pi(-(r->at[0][2] * c - r->at[1][2] * s),
                     r->at[0][0] * c - r->at[1][0] * s, reference->at[0]);
      angles->at[1] = ksl_catan2pi(
        -r->at[2][1], r->at[1][1] * c + r->at[0][1] * s, reference->at[1]);
      break;
    case KSL_AXIS_ZYX:
      // i = 2, j = 1, k = 0
      // angle[2] = ksl_catan1pi(Ri[i][j], Ri[i][i], angle[2]);
      // angle[0] = ksl_catan2pi(-(Ri[k][j]*c - Ri[k][i]*s), Ri[j][j]*c -
      // Ri[j][i]*s, angle[0]);  angle[1] = ksl_catan2pi(-Ri[i][k], Ri[i][i]*c +
      // Ri[i][j]*s, angle[1]);
      angles->at[2] = ksl_catan1pi(r->at[1][2], r->at[2][2], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        ksl_catan2pi(-(r->at[1][0] * c - r->at[2][0] * s),
                     r->at[1][1] * c - r->at[2][1] * s, reference->at[0]);
      angles->at[1] = ksl_catan2pi(
        -r->at[0][2], r->at[2][2] * c + r->at[1][2] * s, reference->at[1]);
      break;
    case KSL_AXIS_XZX:
      // i = 0, j = 2, k = 0
      // Set k = 1 for correct index into direction cosine matrix.
      // angle[2] = ksl_catan1pi(-Ri[i][j], Ri[i][k], angle[2]);
      // angle[0] = ksl_catan2pi(-(Ri[k][j]*c + Ri[k][k]*s), Ri[j][j]*c +
      // Ri[j][k]*s, angle[0]);  angle[1] = ksl_catan2pi(-(Ri[i][k]*c -
      // Ri[i][j]*s),
      // Ri[i][i], angle[1]);
      angles->at[2] = ksl_catan1pi(-r->at[2][0], r->at[1][0], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        ksl_catan2pi(-(r->at[2][1] * c + r->at[1][1] * s),
                     r->at[2][2] * c + r->at[1][2] * s, reference->at[0]);
      angles->at[1] = ksl_catan2pi(-(r->at[1][0] * c - r->at[2][0] * s),
                                   r->at[0][0], reference->at[1]);
      break;
    case KSL_AXIS_YXY:
      // i = 1, j = 0, k = 1
      // Set k = 2 for correct index into direction cosine matrix.
      // angle[2] = ksl_catan1pi(-Ri[i][j], Ri[i][k], angle[2]);
      // angle[0] = ksl_catan2pi(-(Ri[k][j]*c + Ri[k][k]*s), Ri[j][j]*c +
      // Ri[j][k]*s, angle[0]);  angle[1] = ksl_catan2pi(-(Ri[i][k]*c -
      // Ri[i][j]*s),
      // Ri[i][i], angle[1]);
      angles->at[2] = ksl_catan1pi(-r->at[0][1], r->at[2][1], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        ksl_catan2pi(-(r->at[0][2] * c + r->at[2][2] * s),
                     r->at[0][0] * c + r->at[2][0] * s, reference->at[0]);
      angles->at[1] = ksl_catan2pi(-(r->at[2][1] * c - r->at[0][1] * s),
                                   r->at[1][1], reference->at[1]);
      break;
    case KSL_AXIS_ZYZ:
      // i = 2, j = 1, k = 2
      // Set k = 0 for correct index into direction cosine matrix.
      // angle[2] = ksl_catan1pi(-Ri[i][j], Ri[i][k], angle[2]);
      // angle[0] = ksl_catan2pi(-(Ri[k][j]*c + Ri[k][k]*s), Ri[j][j]*c +
      // Ri[j][k]*s, angle[0]);  angle[1] = ksl_catan2pi(-(Ri[i][k]*c -
      // Ri[i][j]*s),
      // Ri[i][i], angle[1]);
      angles->at[2] = ksl_catan1pi(-r->at[1][2], r->at[0][2], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        ksl_catan2pi(-(r->at[1][0] * c + r->at[0][0] * s),
                     r->at[1][1] * c + r->at[0][1] * s, reference->at[0]);
      angles->at[1] = ksl_catan2pi(-(r->at[0][2] * c - r->at[1][2] * s),
                                   r->at[2][2], reference->at[1]);
      break;
    default:
      fprintf(
        stderr,
        "\nError:invalid axis sequence in function ksl_mat3x3_getEulerAngles"
        " -- Aborting.\n");
      exit(1);
  }

  // const int f[3] = {1, 2, 0};
  //
  // ksl_vec3i_t axes = ksl_axis_getVector(axisType);
  //
  // /* Short notation for the axis identifiers. */
  // int i = axes.x;
  // int j = axes.y;
  // int k = axes.z;
  //
  // /* The value of k will be changed in Cases 3 and 4.
  // Temp variables to hold true sin and cos values of third angle. */
  // double c;
  // double s;
  //
  // if(j == f[i]) { // Identifies Cases 1 and 3: forward cycle i --> j
  //   if(k != i) {  // forward cycle j --> k
  //     // Case 1: 0 --> 1 --> 2; 1 --> 2 --> 0; 2 --> 0 --> 1
  //     angles->y = ksl_catan1pi(-r->at [j][i], r->at [i][i],
  //     reference->y); c = cos(angles->y); s = sin(angles->y); angles->x =
  //       ksl_catan2pi(r->at [j][k] * c + r->at [i][k] * s,
  //                r->at [j][j] * c + r->at [i][j] * s,
  //                reference->x);
  //     angles->y =
  //       ksl_catan2pi(r->at [k][i],
  //                r->at [i][i] * c - r->at [j][i] * s,
  //                reference->y);
  //   } else { // k == i; reverse cycle j --> i
  //     // Case 3: 0 --> 1 --> 0; 1 --> 2 --> 1; 2 --> 0 --> 2
  //     // Reset k for correct index into direction cosine matrix.
  //     k = f[j];
  //     angles->z = ksl_catan1pi(r->at [j][i], r->at [k][i],
  //     reference->z); c = cos(angles->z); s = sin(angles->z); angles->x =
  //       ksl_catan2pi(r->at [j][k] * c - r->at [k][k] * s,
  //                r->at [j][j] * c - r->at [k][j] * s,
  //                reference->x);
  //     angles->y = ksl_catan2pi(r->at [k][i] * c + r->at [j][i] * s,
  //                          r->at [i][i], reference->y);
  //   }
  // } else {       // Cases 2 and 4: reverse cycle i --> j
  //   if(k != i) { // reverse cycle j --> k
  //     // Case 2: 0 --> 2 --> 1; 1 --> 0 --> 2; 2 --> 1 --> 0
  //     angles->z = ksl_catan1pi(r->at [j][i], r->at [i][i],
  //     reference->z); c = cos(angles->z); s = sin(angles->z); angles->x =
  //       ksl_catan2pi(-(r->at [j][k] * c - r->at [i][k] * s),
  //                r->at [j][j] * c - r->at [i][j] * s,
  //                reference->x);
  //     angles->y =
  //       ksl_catan2pi(-r->at [k][i],
  //                r->at [i][i] * c + r->at [j][i] * s,
  //                reference->y);
  //   } else { // k == i; forward cycle j --> i
  //     // Case 4: 0 --> 2 --> 0; 1 --> 0 --> 1; 2 --> 1 --> 2
  //     // Reset k for correct index into direction cosine matrix.
  //     k = f[i];
  //     angles->z = ksl_catan1pi(-r->at [j][i], r->at [k][i],
  //     reference->z); c = cos(angles->z); s = sin(angles->z); angles->x =
  //       ksl_catan2pi(-(r->at [j][k] * c + r->at [k][k] * s),
  //                r->at [j][j] * c + r->at [k][j] * s,
  //                reference->x);
  //     angles->y = ksl_catan2pi(-(r->at [k][i] * c - r->at [j][i] * s),
  //                          r->at [i][i], reference->y);
  //   }
  // }
}

