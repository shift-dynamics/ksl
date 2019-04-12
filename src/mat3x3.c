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

inline ksl_mat3x3_t ksl_mat3x3(const double m00, const double m01,
                               const double m02, const double m10,
                               const double m11, const double m12,
                               const double m20, const double m21,
                               const double m22) {
  ksl_mat3x3_t r;
  r.m00 = m00;
  r.m01 = m01;
  r.m02 = m02;
  r.m10 = m10;
  r.m11 = m11;
  r.m12 = m12;
  r.m20 = m20;
  r.m21 = m21;
  r.m22 = m22;
  return r;
}

inline ksl_mat3x3_t ksl_mat3x3_cmo(const double m00, const double m10,
                                   const double m20, const double m01,
                                   const double m11, const double m21,
                                   const double m02, const double m12,
                                   const double m22) {
  ksl_mat3x3_t r;
  r.m00 = m00;
  r.m10 = m10;
  r.m20 = m20;
  r.m01 = m01;
  r.m11 = m11;
  r.m21 = m21;
  r.m02 = m02;
  r.m12 = m12;
  r.m22 = m22;
  return r;
}

inline ksl_mat3x3f_t ksl_mat3x3f(const float m00, const float m01,
                                 const float m02, const float m10,
                                 const float m11, const float m12,
                                 const float m20, const float m21,
                                 const float m22) {
  ksl_mat3x3f_t r;
  r.m00 = m00;
  r.m01 = m01;
  r.m02 = m02;
  r.m10 = m10;
  r.m11 = m11;
  r.m12 = m12;
  r.m20 = m20;
  r.m21 = m21;
  r.m22 = m22;
  return r;
}

inline ksl_mat3x3f_t ksl_mat3x3f_cmo(const float m00, const float m10,
                                     const float m20, const float m01,
                                     const float m11, const float m21,
                                     const float m02, const float m12,
                                     const float m22) {
  ksl_mat3x3f_t r;
  r.m00 = m00;
  r.m10 = m10;
  r.m20 = m20;
  r.m01 = m01;
  r.m11 = m11;
  r.m21 = m21;
  r.m02 = m02;
  r.m12 = m12;
  r.m22 = m22;
  return r;
}

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

inline void ksl_mat3x3_setIdentity(ksl_mat3x3_t* restrict r) {
  memset(r, 0, sizeof(ksl_mat3x3_t));
  for(int i = 0; i < 3; i++) {
    r->at[i][i] = 1.0;
  }
}

inline void ksl_mat3x3f_setIdentity(ksl_mat3x3f_t* restrict r) {
  memset(r, 0, sizeof(ksl_mat3x3f_t));
  for(int i = 0; i < 3; i++) {
    r->at[i][i] = 1.0;
  }
}

inline void ksl_mat3x3_set(ksl_mat3x3_t* restrict R, const int row,
                           const int column, const double value) {
  assert(row < 3 && column < 3);
  R->at[column][row] = value;
}

inline void ksl_mat3x3f_set(ksl_mat3x3f_t* restrict R, int row, int column,
                            float value) {
  assert(row < 3 && column < 3);
  R->at[column][row] = value;
}

inline void ksl_mat3x3_normalize(ksl_mat3x3_t* restrict R) {
  ksl_linalg_gramSchmidt(&(R->as_array), 3, 3);
}

inline void ksl_mat3x3_normalized(const ksl_mat3x3_t* restrict Ri,
                                  ksl_mat3x3_t* restrict Ro) {
  ksl_mat3x3_copy(Ri, Ro);
  ksl_linalg_gramSchmidt(&(Ro->as_array), 3, 3);
}

inline void ksl_mat3x3f_normalize(ksl_mat3x3f_t* restrict R) {
  ksl_linalg_gramSchmidtf(&(R->as_array), 3, 3);
}

inline void ksl_mat3x3f_normalized(const ksl_mat3x3f_t* restrict Ri,
                                   ksl_mat3x3f_t* restrict Ro) {
  ksl_mat3x3f_copy(Ri, Ro);
  ksl_linalg_gramSchmidtf(&(Ro->as_array), 3, 3);
}

inline void ksl_mat3x3_setFromVectors(ksl_mat3x3_t* restrict R,
                                      const ksl_vec3_t* x, const ksl_vec3_t* y,
                                      const ksl_vec3_t* z) {
  memcpy(&R->v0, x, sizeof(ksl_vec3_t));
  memcpy(&R->v1, y, sizeof(ksl_vec3_t));
  memcpy(&R->v2, z, sizeof(ksl_vec3_t));
}

inline void ksl_mat3x3f_setFromVectors(ksl_mat3x3f_t* restrict R,
                                       const ksl_vec3f_t* x,
                                       const ksl_vec3f_t* y,
                                       const ksl_vec3f_t* z) {
  memcpy(&R->v0, x, sizeof(ksl_vec3f_t));
  memcpy(&R->v1, y, sizeof(ksl_vec3f_t));
  memcpy(&R->v2, z, sizeof(ksl_vec3f_t));
}

inline double ksl_mat3x3_get(const ksl_mat3x3_t* restrict R, const int row,
                             const int column) {
  assert(row < 3 && column < 3);
  return R->at[column][row];
}

inline float ksl_mat3x3f_get(const ksl_mat3x3f_t* restrict R, const int row,
                             const int column) {
  assert(row < 3 && column < 3);
  return R->at[column][row];
}

inline void ksl_mat3x3_copy(const ksl_mat3x3_t* restrict ri,
                            ksl_mat3x3_t* restrict ro) {
  memcpy(ro, ri, sizeof(ksl_mat3x3_t));
}

inline void ksl_mat3x3f_copy(const ksl_mat3x3f_t* restrict ri,
                             ksl_mat3x3f_t* restrict ro) {
  memcpy(ro, ri, sizeof(ksl_mat3x3f_t));
}

/*!@brief Performs the general matrix inverse for a ksl_mat3x3_t matrix in-place
with no pivoting. If the matrix is an orthonormal rotation matrix with a
determinant of one, (i.e. it is \in SO3), then the less expensive matrix
transpose function can be used for performing the inverse */
inline int ksl_mat3x3_invert(ksl_mat3x3_t* restrict R) {
  ksl_mat3x3_t a;
  ksl_mat3x3_copy(R, &a);

  /* Major loop to factor the matrix.
    Generate factors column by column */
  for(int row = 0; row < 3; row++) {
    /* i iterates over rows of a */
    for(int i = row + 1; i < 3; i++) {
      /* Evaluate the current entry in the L matrix.*/
      a.at[row][i] /= a.at[row][row];
      /* Compute U matrix */
      for(int j = row + 1; j < 3; j++) {
        a.at[j][i] -= a.at[row][i] * a.at[j][row];
      }
    }
  }

  ksl_vec3_t b;

  /* Major loop operates on columns of an identity matrix */
  for(int k = 0; k < 3; k++) {
    ksl_vec3_t y;
    memset(&y, 0, sizeof(ksl_vec3_t));
    y.at[k] = 1.0;
    /* perform forward substitution L^-1 y -> b
    where L is unit lower triangular */
    for(int i = 0; i < 3; i++) {
      b.at[i] = y.at[i];
      for(int j = 0; j < i; j++) {
        b.at[i] -= a.at[j][i] * b.at[j];
      }
    }

    /* perform backward substitution U^-1 b -> x
    where U is non-unit upper triangular */
    if(fabs(a.at[2][2]) < 1e-12) {
      return -3;
    }
    R->at[k][2] = b.at[2] / a.at[2][2];
    for(int i = 1; i > -1; i--) {
      double t = b.at[i];
      for(int j = i + 1; j < 3; j++) {
        t -= a.at[j][i] * R->at[k][j];
      }
      if(fabs(a.at[i][i]) < 1e-12) {
        return -(i + 1);
      }
      R->at[k][i] = t / a.at[i][i];
    }
  }

  return 0;
}

/*!@brief Performs the general matrix inverse for a ksl_mat3x3f_t matrix
in-place with no pivoting. If the matrix is an orthonormal rotation matrix with
a determinant of one, (i.e. it is \in SO3), then the less expensive matrix
transpose function can be used for performing the inverse */
inline int ksl_mat3x3f_invert(ksl_mat3x3f_t* restrict R) {
  ksl_mat3x3f_t a;
  ksl_mat3x3f_copy(R, &a);

  /* Major loop to factor the matrix.
    Generate factors column by column */
  for(int row = 0; row < 3; row++) {
    /* i iterates over rows of a */
    for(int i = row + 1; i < 3; i++) {
      /* Evaluate the current entry in the L matrix.*/
      a.at[row][i] /= a.at[row][row];
      /* Compute U matrix */
      for(int j = row + 1; j < 3; j++) {
        a.at[j][i] -= a.at[row][i] * a.at[j][row];
      }
    }
  }

  ksl_vec3_t b;

  /* Major loop operates on columns of an identity matrix */
  for(int k = 0; k < 3; k++) {
    ksl_vec3f_t y;
    memset(&y, 0, sizeof(ksl_vec3f_t));
    y.at[k] = 1.0;
    /* perform forward substitution L^-1 y -> b
    where L is unit lower triangular */
    for(int i = 0; i < 3; i++) {
      b.at[i] = y.at[i];
      for(int j = 0; j < i; j++) {
        b.at[i] -= a.at[j][i] * b.at[j];
      }
    }

    /* perform backward substitution U^-1 b -> x
    where U is non-unit upper triangular */
    if(fabs(a.at[2][2]) < 1e-12) {
      return -3;
    }
    R->at[k][2] = b.at[2] / a.at[2][2];
    for(int i = 1; i > -1; i--) {
      double t = b.at[i];
      for(int j = i + 1; j < 3; j++) {
        t -= a.at[j][i] * R->at[k][j];
      }
      if(fabs(a.at[i][i]) < 1e-12) {
        return -(i + 1);
      }
      R->at[k][i] = t / a.at[i][i];
    }
  }
  return 0;
}

/*!@brief Performs the general matrix inverse for a ksl_mat3x3_t matrix
with no pivoting. If the matrix is an orthonormal rotation matrix with a
determinant of one, (i.e. it is \in SO3), then the less expensive matrix
transpose function can be used for performing the inverse */
inline int ksl_mat3x3_inverted(const ksl_mat3x3_t* restrict ri,
                               ksl_mat3x3_t* restrict ro) {
  ksl_mat3x3_t a;
  ksl_mat3x3_copy(ri, &a);

  /* Major loop to factor the matrix.
    Generate factors column by column */
  for(int row = 0; row < 3; row++) {
    /* i iterates over rows of a */
    for(int i = row + 1; i < 3; i++) {
      /* Evaluate the current entry in the L matrix.*/
      a.at[row][i] /= a.at[row][row];
      /* Compute U matrix */
      for(int j = row + 1; j < 3; j++) {
        a.at[j][i] -= a.at[row][i] * a.at[j][row];
      }
    }
  }

  ksl_vec3_t b;

  /* Major loop operates on columns of an identity matrix */
  for(int k = 0; k < 3; k++) {
    ksl_vec3_t y;
    memset(&y, 0, sizeof(ksl_vec3_t));
    y.at[k] = 1.0;
    /* perform forward substitution L^-1 y -> b
    where L is unit lower triangular */
    for(int i = 0; i < 3; i++) {
      b.at[i] = y.at[i];
      for(int j = 0; j < i; j++) {
        b.at[i] -= a.at[j][i] * b.at[j];
      }
    }

    /* perform backward substitution U^-1 b -> x
    where U is non-unit upper triangular */
    if(fabs(a.at[2][2]) < 1e-12) {
      return -3;
    }
    ro->at[k][2] = b.at[2] / a.at[2][2];
    for(int i = 1; i > -1; i--) {
      double t = b.at[i];
      for(int j = i + 1; j < 3; j++) {
        t -= a.at[j][i] * ro->at[k][j];
      }
      if(fabs(a.at[i][i]) < 1e-12) {
        return -(i + 1);
      }
      ro->at[k][i] = t / a.at[i][i];
    }
  }
  return 0;
}

/*!@brief Performs the general matrix inverse for a ksl_mat3x3f_t matrix
with no pivoting. If the matrix is an orthonormal rotation matrix with a
determinant of one, (i.e. it is \in SO3), then the less expensive matrix
transpose function can be used for performing the inverse */
inline int ksl_mat3x3f_inverted(const ksl_mat3x3f_t* restrict ri,
                                ksl_mat3x3f_t* restrict ro) {
  ksl_mat3x3f_t a;
  ksl_mat3x3f_copy(ri, &a);

  /* Major loop to factor the matrix.
    Generate factors column by column */
  for(int row = 0; row < 3; row++) {
    /* i iterates over rows of a */
    for(int i = row + 1; i < 3; i++) {
      /* Evaluate the current entry in the L matrix.*/
      a.at[row][i] /= a.at[row][row];
      /* Compute U matrix */
      for(int j = row + 1; j < 3; j++) {
        a.at[j][i] -= a.at[row][i] * a.at[j][row];
      }
    }
  }

  ksl_vec3f_t b;

  /* Major loop operates on columns of an identity matrix */
  for(int k = 0; k < 3; k++) {
    ksl_vec3f_t y;
    memset(&y, 0, sizeof(ksl_vec3f_t));
    y.at[k] = 1.0;
    /* perform forward substitution L^-1 y -> b
    where L is unit lower triangular */
    for(int i = 0; i < 3; i++) {
      b.at[i] = y.at[i];
      for(int j = 0; j < i; j++) {
        b.at[i] -= a.at[j][i] * b.at[j];
      }
    }

    /* perform backward substitution U^-1 b -> x
    where U is non-unit upper triangular */
    if(fabs(a.at[2][2]) < 1e-12) {
      return -3;
    }
    ro->at[k][2] = b.at[2] / a.at[2][2];
    for(int i = 1; i > -1; i--) {
      double t = b.at[i];
      for(int j = i + 1; j < 3; j++) {
        t -= a.at[j][i] * ro->at[k][j];
      }
      if(fabs(a.at[i][i]) < 1e-12) {
        return -(i + 1);
      }
      ro->at[k][i] = t / a.at[i][i];
    }
  }
  return 0;
}

inline void ksl_mat3x3_transpose(ksl_mat3x3_t* restrict R) {
  ksl_swap(&R->at[0][1], &R->at[1][0]);
  ksl_swap(&R->at[0][2], &R->at[2][0]);
  ksl_swap(&R->at[1][2], &R->at[2][1]);
}

inline void ksl_mat3x3f_transpose(ksl_mat3x3f_t* restrict R) {
  ksl_swapf(&R->at[0][1], &R->at[1][0]);
  ksl_swapf(&R->at[0][2], &R->at[2][0]);
  ksl_swapf(&R->at[1][2], &R->at[2][1]);
}

inline void ksl_mat3x3_transposed(const ksl_mat3x3_t* restrict ri,
                                  ksl_mat3x3_t* restrict ro) {
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      ro->at[i][j] = ri->at[j][i];
    }
  }
}

inline void ksl_mat3x3f_transposed(const ksl_mat3x3f_t* restrict ri,
                                   ksl_mat3x3f_t* restrict ro) {
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      ro->at[i][j] = ri->at[j][i];
    }
  }
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
      // angle[2] = catan1pi(-Ri[i][j], Ri[i][i], angle[2]);
      // angle[0] = catan2pi(Ri[k][j]*c + Ri[k][i]*s, Ri[j][j]*c +
      // Ri[j][i] * s,
      // angle[0]); angle[1] = catan2pi(Ri[i][k], Ri[i][i]*c - Ri[i][j]*s,
      // angle[1]);
      angles->at[2] = catan1pi(-r->at[1][0], r->at[0][0], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        catan2pi(r->at[1][2] * c + r->at[0][2] * s,
                 r->at[1][1] * c + r->at[0][1] * s, reference->at[0]);
      angles->at[1] = catan2pi(r->at[2][0], r->at[0][0] * c - r->at[1][0] * s,
                               reference->at[1]);
      break;
    case KSL_AXIS_YZX:
      // i = 1, j = 2, k = 0
      // angle[2] = catan1pi(-Ri[i][j], Ri[i][i], angle[2]);
      // angle[0] = catan2pi(Ri[k][j]*c + Ri[k][i]*s, Ri[j][j]*c +
      // Ri[j][i] * s,
      // angle[0]); angle[1] = catan2pi(Ri[i][k], Ri[i][i]*c - Ri[i][j]*s,
      // angle[1]);
      angles->at[2] = catan1pi(-r->at[2][1], r->at[1][1], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        catan2pi(r->at[2][0] * c + r->at[1][0] * s,
                 r->at[2][2] * c + r->at[1][2] * s, reference->at[0]);
      angles->at[1] = catan2pi(r->at[0][1], r->at[1][1] * c - r->at[2][1] * s,
                               reference->at[1]);
      break;
    case KSL_AXIS_ZXY:
      // i = 2, j = 0, k = 1
      // angle[2] = catan1pi(-Ri[i][j], Ri[i][i], angle[2]);
      // angle[0] = catan2pi(Ri[k][j]*c + Ri[k][i]*s, Ri[j][j]*c +
      // Ri[j][i] * s,
      // angle[0]); angle[1] = catan2pi(Ri[i][k], Ri[i][i]*c - Ri[i][j]*s,
      // angle[1]);
      angles->at[2] = catan1pi(-r->at[0][2], r->at[2][2], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        catan2pi(r->at[0][1] * c + r->at[2][1] * s,
                 r->at[0][0] * c + r->at[2][0] * s, reference->at[0]);
      angles->at[1] = catan2pi(r->at[1][2], r->at[2][2] * c - r->at[0][2] * s,
                               reference->at[1]);
      break;
    case KSL_AXIS_XYX:
      // i = 0, j = 1, k = 0
      // Set k = 2 for correct index into direction cosine matrix.
      // angle[2] = catan1pi(Ri[i][j], Ri[i][k], angle[2]);
      // angle[0] = catan2pi(Ri[k][j]*c - Ri[k][k]*s, Ri[j][j]*c -
      // Ri[j][k] * s,
      // angle[0]); angle[1] = catan2pi(Ri[i][k]*c + Ri[i][j]*s, Ri[i][i],
      // angle[1]);		k = f[j];
      angles->at[2] = catan1pi(r->at[1][0], r->at[2][0], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        catan2pi(r->at[1][2] * c - r->at[2][2] * s,
                 r->at[1][1] * c - r->at[2][1] * s, reference->at[0]);
      angles->at[1] = catan2pi(r->at[2][0] * c + r->at[1][0] * s, r->at[0][0],
                               reference->at[1]);
      break;
    case KSL_AXIS_YZY:
      // i = 1, j = 2, k = 1
      // Set k = 0 for correct index into direction cosine matrix.
      // angle[2] = catan1pi(Ri[i][j], Ri[i][k], angle[2]);
      // angle[0] = catan2pi(Ri[k][j]*c - Ri[k][k]*s, Ri[j][j]*c -
      // Ri[j][k] * s,
      // angle[0]); angle[1] = catan2pi(Ri[i][k]*c + Ri[i][j]*s, Ri[i][i],
      // angle[1]);
      angles->at[2] = catan1pi(r->at[2][1], r->at[0][1], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        catan2pi(r->at[2][0] * c - r->at[0][0] * s,
                 r->at[2][2] * c - r->at[0][2] * s, reference->at[0]);
      angles->at[1] = catan2pi(r->at[0][1] * c + r->at[2][1] * s, r->at[1][1],
                               reference->at[1]);
      break;
    case KSL_AXIS_ZXZ:
      // i = 2, j = 0, k = 2
      // Set k = 1 for correct index into direction cosine matrix.
      // angle[2] = catan1pi(Ri[i][j], Ri[i][k], angle[2]);
      // angle[0] = catan2pi(Ri[k][j]*c - Ri[k][k]*s, Ri[j][j]*c -
      // Ri[j][k] * s,
      // angle[0]);
      // angle[1] = catan2pi(Ri[i][k]*c + Ri[i][j]*s, Ri[i][i],
      // angle[1]);
      angles->at[2] = catan1pi(r->at[0][2], r->at[1][2], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        catan2pi(r->at[0][1] * c - r->at[1][1] * s,
                 r->at[0][0] * c - r->at[1][0] * s, reference->at[0]);
      angles->at[1] = catan2pi(r->at[1][2] * c + r->at[0][2] * s, r->at[2][2],
                               reference->at[1]);
      break;
    case KSL_AXIS_XZY:
      // i = 0, j = 2, k = 1
      // angle[2] = catan1pi(Ri[i][j], Ri[i][i], angle[2]);
      // angle[0] = catan2pi(-(Ri[k][j]*c - Ri[k][i]*s), Ri[j][j]*c -
      // Ri[j][i]*s, angle[0]);  angle[1] = catan2pi(-Ri[i][k], Ri[i][i]*c +
      // Ri[i][j]*s, angle[1]);
      angles->at[2] = catan1pi(r->at[2][0], r->at[0][0], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        catan2pi(-(r->at[2][1] * c - r->at[0][1] * s),
                 r->at[2][2] * c - r->at[0][2] * s, reference->at[0]);
      angles->at[1] = catan2pi(-r->at[1][0], r->at[0][0] * c + r->at[2][0] * s,
                               reference->at[1]);
      break;
    case KSL_AXIS_YXZ:
      // i = 1, j = 0, k = 2
      // angle[2] = catan1pi(Ri[i][j], Ri[i][i], angle[2]);
      // angle[0] = catan2pi(-(Ri[k][j]*c - Ri[k][i]*s), Ri[j][j]*c -
      // Ri[j][i]*s, angle[0]);  angle[1] = catan2pi(-Ri[i][k], Ri[i][i]*c +
      // Ri[i][j]*s, angle[1]);
      angles->at[2] = catan1pi(r->at[0][1], r->at[1][1], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        catan2pi(-(r->at[0][2] * c - r->at[1][2] * s),
                 r->at[0][0] * c - r->at[1][0] * s, reference->at[0]);
      angles->at[1] = catan2pi(-r->at[2][1], r->at[1][1] * c + r->at[0][1] * s,
                               reference->at[1]);
      break;
    case KSL_AXIS_ZYX:
      // i = 2, j = 1, k = 0
      // angle[2] = catan1pi(Ri[i][j], Ri[i][i], angle[2]);
      // angle[0] = catan2pi(-(Ri[k][j]*c - Ri[k][i]*s), Ri[j][j]*c -
      // Ri[j][i]*s, angle[0]);  angle[1] = catan2pi(-Ri[i][k], Ri[i][i]*c +
      // Ri[i][j]*s, angle[1]);
      angles->at[2] = catan1pi(r->at[1][2], r->at[2][2], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        catan2pi(-(r->at[1][0] * c - r->at[2][0] * s),
                 r->at[1][1] * c - r->at[2][1] * s, reference->at[0]);
      angles->at[1] = catan2pi(-r->at[0][2], r->at[2][2] * c + r->at[1][2] * s,
                               reference->at[1]);
      break;
    case KSL_AXIS_XZX:
      // i = 0, j = 2, k = 0
      // Set k = 1 for correct index into direction cosine matrix.
      // angle[2] = catan1pi(-Ri[i][j], Ri[i][k], angle[2]);
      // angle[0] = catan2pi(-(Ri[k][j]*c + Ri[k][k]*s), Ri[j][j]*c +
      // Ri[j][k]*s, angle[0]);  angle[1] = catan2pi(-(Ri[i][k]*c -
      // Ri[i][j]*s),
      // Ri[i][i], angle[1]);
      angles->at[2] = catan1pi(-r->at[2][0], r->at[1][0], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        catan2pi(-(r->at[2][1] * c + r->at[1][1] * s),
                 r->at[2][2] * c + r->at[1][2] * s, reference->at[0]);
      angles->at[1] = catan2pi(-(r->at[1][0] * c - r->at[2][0] * s),
                               r->at[0][0], reference->at[1]);
      break;
    case KSL_AXIS_YXY:
      // i = 1, j = 0, k = 1
      // Set k = 2 for correct index into direction cosine matrix.
      // angle[2] = catan1pi(-Ri[i][j], Ri[i][k], angle[2]);
      // angle[0] = catan2pi(-(Ri[k][j]*c + Ri[k][k]*s), Ri[j][j]*c +
      // Ri[j][k]*s, angle[0]);  angle[1] = catan2pi(-(Ri[i][k]*c -
      // Ri[i][j]*s),
      // Ri[i][i], angle[1]);
      angles->at[2] = catan1pi(-r->at[0][1], r->at[2][1], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        catan2pi(-(r->at[0][2] * c + r->at[2][2] * s),
                 r->at[0][0] * c + r->at[2][0] * s, reference->at[0]);
      angles->at[1] = catan2pi(-(r->at[2][1] * c - r->at[0][1] * s),
                               r->at[1][1], reference->at[1]);
      break;
    case KSL_AXIS_ZYZ:
      // i = 2, j = 1, k = 2
      // Set k = 0 for correct index into direction cosine matrix.
      // angle[2] = catan1pi(-Ri[i][j], Ri[i][k], angle[2]);
      // angle[0] = catan2pi(-(Ri[k][j]*c + Ri[k][k]*s), Ri[j][j]*c +
      // Ri[j][k]*s, angle[0]);  angle[1] = catan2pi(-(Ri[i][k]*c -
      // Ri[i][j]*s),
      // Ri[i][i], angle[1]);
      angles->at[2] = catan1pi(-r->at[1][2], r->at[0][2], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        catan2pi(-(r->at[1][0] * c + r->at[0][0] * s),
                 r->at[1][1] * c + r->at[0][1] * s, reference->at[0]);
      angles->at[1] = catan2pi(-(r->at[0][2] * c - r->at[1][2] * s),
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
  //     angles->y = catan1pi(-r->at [j][i], r->at [i][i],
  //     reference->y); c = cos(angles->y); s = sin(angles->y); angles->x =
  //       catan2pi(r->at [j][k] * c + r->at [i][k] * s,
  //                r->at [j][j] * c + r->at [i][j] * s,
  //                reference->x);
  //     angles->y =
  //       catan2pi(r->at [k][i],
  //                r->at [i][i] * c - r->at [j][i] * s,
  //                reference->y);
  //   } else { // k == i; reverse cycle j --> i
  //     // Case 3: 0 --> 1 --> 0; 1 --> 2 --> 1; 2 --> 0 --> 2
  //     // Reset k for correct index into direction cosine matrix.
  //     k = f[j];
  //     angles->z = catan1pi(r->at [j][i], r->at [k][i],
  //     reference->z); c = cos(angles->z); s = sin(angles->z); angles->x =
  //       catan2pi(r->at [j][k] * c - r->at [k][k] * s,
  //                r->at [j][j] * c - r->at [k][j] * s,
  //                reference->x);
  //     angles->y = catan2pi(r->at [k][i] * c + r->at [j][i] * s,
  //                          r->at [i][i], reference->y);
  //   }
  // } else {       // Cases 2 and 4: reverse cycle i --> j
  //   if(k != i) { // reverse cycle j --> k
  //     // Case 2: 0 --> 2 --> 1; 1 --> 0 --> 2; 2 --> 1 --> 0
  //     angles->z = catan1pi(r->at [j][i], r->at [i][i],
  //     reference->z); c = cos(angles->z); s = sin(angles->z); angles->x =
  //       catan2pi(-(r->at [j][k] * c - r->at [i][k] * s),
  //                r->at [j][j] * c - r->at [i][j] * s,
  //                reference->x);
  //     angles->y =
  //       catan2pi(-r->at [k][i],
  //                r->at [i][i] * c + r->at [j][i] * s,
  //                reference->y);
  //   } else { // k == i; forward cycle j --> i
  //     // Case 4: 0 --> 2 --> 0; 1 --> 0 --> 1; 2 --> 1 --> 2
  //     // Reset k for correct index into direction cosine matrix.
  //     k = f[i];
  //     angles->z = catan1pi(-r->at [j][i], r->at [k][i],
  //     reference->z); c = cos(angles->z); s = sin(angles->z); angles->x =
  //       catan2pi(-(r->at [j][k] * c + r->at [k][k] * s),
  //                r->at [j][j] * c + r->at [k][j] * s,
  //                reference->x);
  //     angles->y = catan2pi(-(r->at [k][i] * c - r->at [j][i] * s),
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
      // angle[2] = catan1pi(-Ri[i][j], Ri[i][i], angle[2]);
      // angle[0] = catan2pi(Ri[k][j]*c + Ri[k][i]*s, Ri[j][j]*c +
      // Ri[j][i] * s,
      // angle[0]); angle[1] = catan2pi(Ri[i][k], Ri[i][i]*c - Ri[i][j]*s,
      // angle[1]);
      angles->at[2] = catan1pi(-r->at[1][0], r->at[0][0], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        catan2pi(r->at[1][2] * c + r->at[0][2] * s,
                 r->at[1][1] * c + r->at[0][1] * s, reference->at[0]);
      angles->at[1] = catan2pi(r->at[2][0], r->at[0][0] * c - r->at[1][0] * s,
                               reference->at[1]);
      break;
    case KSL_AXIS_YZX:
      // i = 1, j = 2, k = 0
      // angle[2] = catan1pi(-Ri[i][j], Ri[i][i], angle[2]);
      // angle[0] = catan2pi(Ri[k][j]*c + Ri[k][i]*s, Ri[j][j]*c +
      // Ri[j][i] * s,
      // angle[0]); angle[1] = catan2pi(Ri[i][k], Ri[i][i]*c - Ri[i][j]*s,
      // angle[1]);
      angles->at[2] = catan1pi(-r->at[2][1], r->at[1][1], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        catan2pi(r->at[2][0] * c + r->at[1][0] * s,
                 r->at[2][2] * c + r->at[1][2] * s, reference->at[0]);
      angles->at[1] = catan2pi(r->at[0][1], r->at[1][1] * c - r->at[2][1] * s,
                               reference->at[1]);
      break;
    case KSL_AXIS_ZXY:
      // i = 2, j = 0, k = 1
      // angle[2] = catan1pi(-Ri[i][j], Ri[i][i], angle[2]);
      // angle[0] = catan2pi(Ri[k][j]*c + Ri[k][i]*s, Ri[j][j]*c +
      // Ri[j][i] * s,
      // angle[0]); angle[1] = catan2pi(Ri[i][k], Ri[i][i]*c - Ri[i][j]*s,
      // angle[1]);
      angles->at[2] = catan1pi(-r->at[0][2], r->at[2][2], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        catan2pi(r->at[0][1] * c + r->at[2][1] * s,
                 r->at[0][0] * c + r->at[2][0] * s, reference->at[0]);
      angles->at[1] = catan2pi(r->at[1][2], r->at[2][2] * c - r->at[0][2] * s,
                               reference->at[1]);
      break;
    case KSL_AXIS_XYX:
      // i = 0, j = 1, k = 0
      // Set k = 2 for correct index into direction cosine matrix.
      // angle[2] = catan1pi(Ri[i][j], Ri[i][k], angle[2]);
      // angle[0] = catan2pi(Ri[k][j]*c - Ri[k][k]*s, Ri[j][j]*c -
      // Ri[j][k] * s,
      // angle[0]); angle[1] = catan2pi(Ri[i][k]*c + Ri[i][j]*s, Ri[i][i],
      // angle[1]);		k = f[j];
      angles->at[2] = catan1pi(r->at[1][0], r->at[2][0], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        catan2pi(r->at[1][2] * c - r->at[2][2] * s,
                 r->at[1][1] * c - r->at[2][1] * s, reference->at[0]);
      angles->at[1] = catan2pi(r->at[2][0] * c + r->at[1][0] * s, r->at[0][0],
                               reference->at[1]);
      break;
    case KSL_AXIS_YZY:
      // i = 1, j = 2, k = 1
      // Set k = 0 for correct index into direction cosine matrix.
      // angle[2] = catan1pi(Ri[i][j], Ri[i][k], angle[2]);
      // angle[0] = catan2pi(Ri[k][j]*c - Ri[k][k]*s, Ri[j][j]*c -
      // Ri[j][k] * s,
      // angle[0]); angle[1] = catan2pi(Ri[i][k]*c + Ri[i][j]*s, Ri[i][i],
      // angle[1]);
      angles->at[2] = catan1pi(r->at[2][1], r->at[0][1], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        catan2pi(r->at[2][0] * c - r->at[0][0] * s,
                 r->at[2][2] * c - r->at[0][2] * s, reference->at[0]);
      angles->at[1] = catan2pi(r->at[0][1] * c + r->at[2][1] * s, r->at[1][1],
                               reference->at[1]);
      break;
    case KSL_AXIS_ZXZ:
      // i = 2, j = 0, k = 2
      // Set k = 1 for correct index into direction cosine matrix.
      // angle[2] = catan1pi(Ri[i][j], Ri[i][k], angle[2]);
      // angle[0] = catan2pi(Ri[k][j]*c - Ri[k][k]*s, Ri[j][j]*c -
      // Ri[j][k] * s,
      // angle[0]);
      // angle[1] = catan2pi(Ri[i][k]*c + Ri[i][j]*s, Ri[i][i],
      // angle[1]);
      angles->at[2] = catan1pi(r->at[0][2], r->at[1][2], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        catan2pi(r->at[0][1] * c - r->at[1][1] * s,
                 r->at[0][0] * c - r->at[1][0] * s, reference->at[0]);
      angles->at[1] = catan2pi(r->at[1][2] * c + r->at[0][2] * s, r->at[2][2],
                               reference->at[1]);
      break;
    case KSL_AXIS_XZY:
      // i = 0, j = 2, k = 1
      // angle[2] = catan1pi(Ri[i][j], Ri[i][i], angle[2]);
      // angle[0] = catan2pi(-(Ri[k][j]*c - Ri[k][i]*s), Ri[j][j]*c -
      // Ri[j][i]*s, angle[0]);  angle[1] = catan2pi(-Ri[i][k], Ri[i][i]*c +
      // Ri[i][j]*s, angle[1]);
      angles->at[2] = catan1pi(r->at[2][0], r->at[0][0], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        catan2pi(-(r->at[2][1] * c - r->at[0][1] * s),
                 r->at[2][2] * c - r->at[0][2] * s, reference->at[0]);
      angles->at[1] = catan2pi(-r->at[1][0], r->at[0][0] * c + r->at[2][0] * s,
                               reference->at[1]);
      break;
    case KSL_AXIS_YXZ:
      // i = 1, j = 0, k = 2
      // angle[2] = catan1pi(Ri[i][j], Ri[i][i], angle[2]);
      // angle[0] = catan2pi(-(Ri[k][j]*c - Ri[k][i]*s), Ri[j][j]*c -
      // Ri[j][i]*s, angle[0]);  angle[1] = catan2pi(-Ri[i][k], Ri[i][i]*c +
      // Ri[i][j]*s, angle[1]);
      angles->at[2] = catan1pi(r->at[0][1], r->at[1][1], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        catan2pi(-(r->at[0][2] * c - r->at[1][2] * s),
                 r->at[0][0] * c - r->at[1][0] * s, reference->at[0]);
      angles->at[1] = catan2pi(-r->at[2][1], r->at[1][1] * c + r->at[0][1] * s,
                               reference->at[1]);
      break;
    case KSL_AXIS_ZYX:
      // i = 2, j = 1, k = 0
      // angle[2] = catan1pi(Ri[i][j], Ri[i][i], angle[2]);
      // angle[0] = catan2pi(-(Ri[k][j]*c - Ri[k][i]*s), Ri[j][j]*c -
      // Ri[j][i]*s, angle[0]);  angle[1] = catan2pi(-Ri[i][k], Ri[i][i]*c +
      // Ri[i][j]*s, angle[1]);
      angles->at[2] = catan1pi(r->at[1][2], r->at[2][2], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        catan2pi(-(r->at[1][0] * c - r->at[2][0] * s),
                 r->at[1][1] * c - r->at[2][1] * s, reference->at[0]);
      angles->at[1] = catan2pi(-r->at[0][2], r->at[2][2] * c + r->at[1][2] * s,
                               reference->at[1]);
      break;
    case KSL_AXIS_XZX:
      // i = 0, j = 2, k = 0
      // Set k = 1 for correct index into direction cosine matrix.
      // angle[2] = catan1pi(-Ri[i][j], Ri[i][k], angle[2]);
      // angle[0] = catan2pi(-(Ri[k][j]*c + Ri[k][k]*s), Ri[j][j]*c +
      // Ri[j][k]*s, angle[0]);  angle[1] = catan2pi(-(Ri[i][k]*c -
      // Ri[i][j]*s),
      // Ri[i][i], angle[1]);
      angles->at[2] = catan1pi(-r->at[2][0], r->at[1][0], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        catan2pi(-(r->at[2][1] * c + r->at[1][1] * s),
                 r->at[2][2] * c + r->at[1][2] * s, reference->at[0]);
      angles->at[1] = catan2pi(-(r->at[1][0] * c - r->at[2][0] * s),
                               r->at[0][0], reference->at[1]);
      break;
    case KSL_AXIS_YXY:
      // i = 1, j = 0, k = 1
      // Set k = 2 for correct index into direction cosine matrix.
      // angle[2] = catan1pi(-Ri[i][j], Ri[i][k], angle[2]);
      // angle[0] = catan2pi(-(Ri[k][j]*c + Ri[k][k]*s), Ri[j][j]*c +
      // Ri[j][k]*s, angle[0]);  angle[1] = catan2pi(-(Ri[i][k]*c -
      // Ri[i][j]*s),
      // Ri[i][i], angle[1]);
      angles->at[2] = catan1pi(-r->at[0][1], r->at[2][1], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        catan2pi(-(r->at[0][2] * c + r->at[2][2] * s),
                 r->at[0][0] * c + r->at[2][0] * s, reference->at[0]);
      angles->at[1] = catan2pi(-(r->at[2][1] * c - r->at[0][1] * s),
                               r->at[1][1], reference->at[1]);
      break;
    case KSL_AXIS_ZYZ:
      // i = 2, j = 1, k = 2
      // Set k = 0 for correct index into direction cosine matrix.
      // angle[2] = catan1pi(-Ri[i][j], Ri[i][k], angle[2]);
      // angle[0] = catan2pi(-(Ri[k][j]*c + Ri[k][k]*s), Ri[j][j]*c +
      // Ri[j][k]*s, angle[0]);  angle[1] = catan2pi(-(Ri[i][k]*c -
      // Ri[i][j]*s),
      // Ri[i][i], angle[1]);
      angles->at[2] = catan1pi(-r->at[1][2], r->at[0][2], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] =
        catan2pi(-(r->at[1][0] * c + r->at[0][0] * s),
                 r->at[1][1] * c + r->at[0][1] * s, reference->at[0]);
      angles->at[1] = catan2pi(-(r->at[0][2] * c - r->at[1][2] * s),
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
  //     angles->y = catan1pi(-r->at [j][i], r->at [i][i],
  //     reference->y); c = cos(angles->y); s = sin(angles->y); angles->x =
  //       catan2pi(r->at [j][k] * c + r->at [i][k] * s,
  //                r->at [j][j] * c + r->at [i][j] * s,
  //                reference->x);
  //     angles->y =
  //       catan2pi(r->at [k][i],
  //                r->at [i][i] * c - r->at [j][i] * s,
  //                reference->y);
  //   } else { // k == i; reverse cycle j --> i
  //     // Case 3: 0 --> 1 --> 0; 1 --> 2 --> 1; 2 --> 0 --> 2
  //     // Reset k for correct index into direction cosine matrix.
  //     k = f[j];
  //     angles->z = catan1pi(r->at [j][i], r->at [k][i],
  //     reference->z); c = cos(angles->z); s = sin(angles->z); angles->x =
  //       catan2pi(r->at [j][k] * c - r->at [k][k] * s,
  //                r->at [j][j] * c - r->at [k][j] * s,
  //                reference->x);
  //     angles->y = catan2pi(r->at [k][i] * c + r->at [j][i] * s,
  //                          r->at [i][i], reference->y);
  //   }
  // } else {       // Cases 2 and 4: reverse cycle i --> j
  //   if(k != i) { // reverse cycle j --> k
  //     // Case 2: 0 --> 2 --> 1; 1 --> 0 --> 2; 2 --> 1 --> 0
  //     angles->z = catan1pi(r->at [j][i], r->at [i][i],
  //     reference->z); c = cos(angles->z); s = sin(angles->z); angles->x =
  //       catan2pi(-(r->at [j][k] * c - r->at [i][k] * s),
  //                r->at [j][j] * c - r->at [i][j] * s,
  //                reference->x);
  //     angles->y =
  //       catan2pi(-r->at [k][i],
  //                r->at [i][i] * c + r->at [j][i] * s,
  //                reference->y);
  //   } else { // k == i; forward cycle j --> i
  //     // Case 4: 0 --> 2 --> 0; 1 --> 0 --> 1; 2 --> 1 --> 2
  //     // Reset k for correct index into direction cosine matrix.
  //     k = f[i];
  //     angles->z = catan1pi(-r->at [j][i], r->at [k][i],
  //     reference->z); c = cos(angles->z); s = sin(angles->z); angles->x =
  //       catan2pi(-(r->at [j][k] * c + r->at [k][k] * s),
  //                r->at [j][j] * c + r->at [k][j] * s,
  //                reference->x);
  //     angles->y = catan2pi(-(r->at [k][i] * c - r->at [j][i] * s),
  //                          r->at [i][i], reference->y);
  //   }
  // }
}

inline void ksl_mat3x3_setFromEulerAngles(ksl_mat3x3_t* r,
                                          const ksl_axis_enum_t axisType,
                                          const ksl_vec3_t* angles) {

  ksl_vec3i_t axes = ksl_axis_getVector(axisType);
  ksl_mat3x3_setIdentity(r);
  ksl_mat3x3_t temp;
  double dc[3][2];
  for(int i = 0; i < 3; i++) {
    ksl_dc(angles->at[i], dc[i]);
  }
  for(int i = 0; i < 3; i++) {
    switch(axes.at[i]) {
      case 0: {
        ksl_product_drdrx(r, dc[i], &temp);
        break;
      }
      case 1: {
        ksl_product_drdry(r, dc[i], &temp);
        break;
      }
      case 2: {
        ksl_product_drdrz(r, dc[i], &temp);
        break;
      }
    }
    ksl_mat3x3_copy(&temp, r);
  }
  return;
}

inline void ksl_mat3x3f_setFromEulerAngles(ksl_mat3x3f_t* r,
                                           const ksl_axis_enum_t axisType,
                                           const ksl_vec3f_t* angles) {

  ksl_vec3i_t axes = ksl_axis_getVector(axisType);
  ksl_mat3x3f_setIdentity(r);
  ksl_mat3x3f_t temp;
  float dc[3][2];
  for(int i = 0; i < 3; i++) {
    ksl_dcf(angles->at[i], dc[i]);
  }
  for(int i = 0; i < 3; i++) {
    switch(axes.at[i]) {
      case 0: {
        ksl_product_drdrxf(r, dc[i], &temp);
        break;
      }
      case 1: {
        ksl_product_drdryf(r, dc[i], &temp);
        break;
      }
      case 2: {
        ksl_product_drdrzf(r, dc[i], &temp);
        break;
      }
    }
    ksl_mat3x3f_copy(&temp, r);
  }
  return;
}

inline double ksl_mat3x3_determinant(const ksl_mat3x3_t* restrict R) {
  return (R->m00 * (R->m11 * R->m22 - R->m21 * R->m12) -
          R->m10 * (R->m01 * R->m22 - R->m21 * R->m02) +
          R->m20 * (R->m01 * R->m12 - R->m11 * R->m02));
}

inline float ksl_mat3x3f_determinant(const ksl_mat3x3f_t* restrict R) {
  return (R->m00 * (R->m11 * R->m22 - R->m21 * R->m12) -
          R->m10 * (R->m01 * R->m22 - R->m21 * R->m02) +
          R->m20 * (R->m01 * R->m12 - R->m11 * R->m02));
}

inline void ksl_mat3x3_getAxisAngle(const ksl_mat3x3_t* restrict r,
                                    ksl_vec3_t* restrict axis,
                                    double* restrict angle) {

  *angle = acos(0.5 * (r->m00 + r->m11 + r->m22 - 1.0));
  if(fabs(sin(*angle)) < 1e-9) {
    /* if m22 == -1, return {1, 0, 0} */
    if(fabs(r->m22 + 1) < 1e-9) {
      axis->x = 1.0;
      axis->y = 0.0;
      axis->z = 0.0;
      return;
    } else {
      axis->x = 0.0;
      axis->y = 0.0;
      axis->z = 1.0;
      return;
    }
  }
  /* u_tilde = (1 / 2 sin \theta) * (r - r^T) */
  axis->x = r->m21 - r->m12;
  axis->y = r->m02 - r->m20;
  axis->z = r->m10 - r->m01;
  ksl_vec3_scale(axis, 1 / (2 * sin(*angle)));
}

inline void ksl_mat3x3_setFromAxisAngle(ksl_mat3x3_t* restrict r,
                                        const ksl_vec3_t* restrict axis,
                                        const double angle) {
  ksl_vec3_t axis_n; /* normalized rotation axis */
  ksl_vec3_normalized(axis, &axis_n);
  double sc[2];
  ksl_dc(angle, sc);
  double t = 1.0 - sc[1];

  r->m00 = sc[1] + axis_n.x * axis_n.x * t;
  r->m11 = sc[1] + axis_n.y * axis_n.y * t;
  r->m22 = sc[1] + axis_n.z * axis_n.z * t;

  double tmp1 = axis_n.x * axis_n.y * t;
  double tmp2 = axis_n.z * sc[0];
  r->m10 = tmp1 + tmp2;
  r->m01 = tmp1 - tmp2;
  tmp1 = axis_n.x * axis_n.z * t;
  tmp2 = axis_n.y * sc[0];
  r->m20 = tmp1 - tmp2;
  r->m02 = tmp1 + tmp2;
  tmp1 = axis_n.y * axis_n.z * t;
  tmp2 = axis_n.x * sc[0];
  r->m21 = tmp1 + tmp2;
  r->m12 = tmp1 - tmp2;
}


inline void ksl_mat3x3_setFromAxisDC(ksl_mat3x3_t* restrict r,
                                     const ksl_vec3_t* restrict axis,
                                     const double* dc) {
  double t = 1.0 - dc[1];

  r->m00 = dc[1] + axis->x * axis->x * t;
  r->m11 = dc[1] + axis->y * axis->y * t;
  r->m22 = dc[1] + axis->z * axis->z * t;

  double tmp1 = axis->x * axis->y * t;
  double tmp2 = axis->z * dc[0];
  r->m10 = tmp1 + tmp2;
  r->m01 = tmp1 - tmp2;
  tmp1 = axis->x * axis->z * t;
  tmp2 = axis->y * dc[0];
  r->m20 = tmp1 - tmp2;
  r->m02 = tmp1 + tmp2;
  tmp1 = axis->y * axis->z * t;
  tmp2 = axis->x * dc[0];
  r->m21 = tmp1 + tmp2;
  r->m12 = tmp1 - tmp2;
}


inline void ksl_mat3x3f_getAxisAngle(const ksl_mat3x3f_t* restrict r,
                                     ksl_vec3f_t* restrict axis,
                                     float* restrict angle) {
  *angle = acos(0.5 * (r->m00 + r->m11 + r->m22 - 1.0));
  if(fabs(sin(*angle)) < 1e-9) {
    /* if m22 == -1, return {1, 0, 0} */
    if(fabs(r->m22 + 1) < 1e-9) {
      axis->x = 1.0;
      axis->y = 0.0;
      axis->z = 0.0;
      return;
    } else {
      axis->x = 0.0;
      axis->y = 0.0;
      axis->z = 1.0;
      return;
    }
  }
  /* u_tilde = (1 / 2 sin \theta) * (r - r^T) */
  axis->x = r->m21 - r->m12;
  axis->y = r->m02 - r->m20;
  axis->z = r->m10 - r->m01;
  ksl_vec3f_scale(axis, 1 / (2 * sin(*angle)));
}


inline void ksl_mat3x3f_setFromAxisAngle(ksl_mat3x3f_t* restrict r,
                                         const ksl_vec3f_t* restrict axis,
                                         const float angle) {
  ksl_vec3f_t axis_n; /* normalized rotation axis */
  ksl_vec3f_normalized(axis, &axis_n);
  double sc[2];
  ksl_dc(angle, sc);
  double t = 1.0 - sc[1];

  r->m00 = sc[1] + axis_n.x * axis_n.x * t;
  r->m11 = sc[1] + axis_n.y * axis_n.y * t;
  r->m22 = sc[1] + axis_n.z * axis_n.z * t;

  double tmp1 = axis_n.x * axis_n.y * t;
  double tmp2 = axis_n.z * sc[0];
  r->m10 = tmp1 + tmp2;
  r->m01 = tmp1 - tmp2;
  tmp1 = axis_n.x * axis_n.z * t;
  tmp2 = axis_n.y * sc[0];
  r->m20 = tmp1 - tmp2;
  r->m02 = tmp1 + tmp2;
  tmp1 = axis_n.y * axis_n.z * t;
  tmp2 = axis_n.x * sc[0];
  r->m21 = tmp1 + tmp2;
  r->m12 = tmp1 - tmp2;
}
