#include <assert.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include "matrix.h"
#include "util.h"

inline ksl_SE3_t ksl_SE3(const double m00, const double m01, const double m02,
                         const double m03, const double m10, const double m11,
                         const double m12, const double m13, const double m20,
                         const double m21, const double m22, const double m23) {
  ksl_SE3_t d;
  d.R.m00 = m00;
  d.R.m01 = m01;
  d.R.m02 = m02;
  d.R.m10 = m10;
  d.R.m11 = m11;
  d.R.m12 = m12;
  d.R.m20 = m20;
  d.R.m21 = m21;
  d.R.m22 = m22;
  d.t.x = m03;
  d.t.y = m13;
  d.t.z = m23;
  return d;
}

inline ksl_SE3_t ksl_SE3_cmo(const double m00, const double m10,
                             const double m20, const double m01,
                             const double m11, const double m21,
                             const double m02, const double m12,
                             const double m22, const double m03,
                             const double m13, const double m23) {
  ksl_SE3_t d;
  d.R.m00 = m00;
  d.R.m10 = m10;
  d.R.m20 = m20;
  d.R.m01 = m01;
  d.R.m11 = m11;
  d.R.m21 = m21;
  d.R.m02 = m02;
  d.R.m12 = m12;
  d.R.m22 = m22;
  d.t.x = m03;
  d.t.y = m13;
  d.t.z = m23;
  return d;
}

inline ksl_SE3_t ksl_SE3_fromRt(const ksl_mat3x3_t R, const ksl_vec3_t t) {
  ksl_SE3_t d;
  d.R = R;
  d.t = t;
  return d;
}

inline ksl_SE3f_t ksl_SE3f(const float m00, const float m01, const float m02,
                           const float m03, const float m10, const float m11,
                           const float m12, const float m13, const float m20,
                           const float m21, const float m22, const float m23) {
  ksl_SE3f_t d;
  d.R.m00 = m00;
  d.R.m01 = m01;
  d.R.m02 = m02;
  d.R.m10 = m10;
  d.R.m11 = m11;
  d.R.m12 = m12;
  d.R.m20 = m20;
  d.R.m21 = m21;
  d.R.m22 = m22;
  d.t.x = m03;
  d.t.y = m13;
  d.t.z = m23;
  return d;
}

inline ksl_SE3f_t ksl_SE3f_cmo(const float m00, const float m10,
                               const float m20, const float m01,
                               const float m11, const float m21,
                               const float m02, const float m12,
                               const float m22, const float m03,
                               const float m13, const float m23) {
  ksl_SE3f_t d;
  d.R.m00 = m00;
  d.R.m10 = m10;
  d.R.m20 = m20;
  d.R.m01 = m01;
  d.R.m11 = m11;
  d.R.m21 = m21;
  d.R.m02 = m02;
  d.R.m12 = m12;
  d.R.m22 = m22;
  d.t.x = m03;
  d.t.y = m13;
  d.t.z = m23;
  return d;
}

inline ksl_SE3f_t ksl_SE3f_fromRt(const ksl_mat3x3f_t R, const ksl_vec3f_t t) {
  ksl_SE3f_t d;
  d.R = R;
  d.t = t;
  return d;
}

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

inline ksl_mat4x4_t ksl_mat4x4(
  const double m00, const double m01, const double m02, const double m03,
  const double m10, const double m11, const double m12, const double m13,
  const double m20, const double m21, const double m22, const double m23,
  const double m30, const double m31, const double m32, const double m33) {
  ksl_mat4x4_t m;
  m.m00 = m00;
  m.m01 = m01;
  m.m02 = m02;
  m.m03 = m03;
  m.m10 = m10;
  m.m11 = m11;
  m.m12 = m12;
  m.m13 = m13;
  m.m20 = m20;
  m.m21 = m21;
  m.m22 = m22;
  m.m23 = m23;
  m.m30 = m30;
  m.m31 = m31;
  m.m32 = m32;
  m.m33 = m33;
  return m;
}

inline ksl_mat4x4_t ksl_mat4x4_cmo(
  const double m00, const double m10, const double m20, const double m30,
  const double m01, const double m11, const double m21, const double m31,
  const double m02, const double m12, const double m22, const double m32,
  const double m03, const double m13, const double m23, const double m33) {
  ksl_mat4x4_t m;
  m.m00 = m00;
  m.m10 = m10;
  m.m20 = m20;
  m.m30 = m30;
  m.m01 = m01;
  m.m11 = m11;
  m.m21 = m21;
  m.m31 = m31;
  m.m02 = m02;
  m.m12 = m12;
  m.m22 = m22;
  m.m32 = m32;
  m.m03 = m03;
  m.m13 = m13;
  m.m23 = m23;
  m.m33 = m33;
  return m;
}

inline ksl_mat4x4_t ksl_mat4x4_fromSE3(const ksl_SE3_t D) {
  ksl_mat4x4_t m;
  m.m00 = D.m00;
  m.m10 = D.m10;
  m.m20 = D.m20;
  m.m30 = 0.0;
  m.m01 = D.m01;
  m.m11 = D.m11;
  m.m21 = D.m21;
  m.m31 = 0.0;
  m.m02 = D.m02;
  m.m12 = D.m12;
  m.m22 = D.m22;
  m.m32 = 0.0;
  m.m03 = D.m03;
  m.m13 = D.m13;
  m.m23 = D.m23;
  m.m33 = 1.0;
  return m;
}

inline ksl_mat4x4_t ksl_mat4x4_fromRt(const ksl_mat3x3_t R,
                                      const ksl_vec3_t t) {
  ksl_mat4x4_t m;
  m.m00 = R.m00;
  m.m01 = R.m01;
  m.m02 = R.m02;
  m.m03 = t.x;
  m.m10 = R.m10;
  m.m11 = R.m11;
  m.m12 = R.m12;
  m.m13 = t.y;
  m.m20 = R.m20;
  m.m21 = R.m21;
  m.m22 = R.m22;
  m.m23 = t.z;
  m.m30 = 0.0;
  m.m31 = 0.0;
  m.m32 = 0.0;
  m.m33 = 1.0;
  return m;
}

inline ksl_mat4x4f_t
ksl_mat4x4f(const float m00, const float m01, const float m02, const float m03,
            const float m10, const float m11, const float m12, const float m13,
            const float m20, const float m21, const float m22, const float m23,
            const float m30, const float m31, const float m32,
            const float m33) {
  ksl_mat4x4f_t m;
  m.m00 = m00;
  m.m01 = m01;
  m.m02 = m02;
  m.m03 = m03;
  m.m10 = m10;
  m.m11 = m11;
  m.m12 = m12;
  m.m13 = m13;
  m.m20 = m20;
  m.m21 = m21;
  m.m22 = m22;
  m.m23 = m23;
  m.m30 = m30;
  m.m31 = m31;
  m.m32 = m32;
  m.m33 = m33;
  return m;
}

inline ksl_mat4x4f_t ksl_mat4x4f_cmo(
  const float m00, const float m10, const float m20, const float m30,
  const float m01, const float m11, const float m21, const float m31,
  const float m02, const float m12, const float m22, const float m32,
  const float m03, const float m13, const float m23, const float m33) {
  ksl_mat4x4f_t m;
  m.m00 = m00;
  m.m10 = m10;
  m.m20 = m20;
  m.m30 = m30;
  m.m01 = m01;
  m.m11 = m11;
  m.m21 = m21;
  m.m31 = m31;
  m.m02 = m02;
  m.m12 = m12;
  m.m22 = m22;
  m.m32 = m32;
  m.m03 = m03;
  m.m13 = m13;
  m.m23 = m23;
  m.m33 = m33;
  return m;
}

inline ksl_mat4x4f_t ksl_mat4x4f_fromSE3f(const ksl_SE3f_t D) {
  ksl_mat4x4f_t m;
  m.m00 = D.m00;
  m.m01 = D.m01;
  m.m02 = D.m02;
  m.m03 = D.m03;
  m.m10 = D.m10;
  m.m11 = D.m11;
  m.m12 = D.m12;
  m.m13 = D.m13;
  m.m20 = D.m20;
  m.m21 = D.m21;
  m.m22 = D.m22;
  m.m23 = D.m23;
  m.m30 = 0.0;
  m.m31 = 0.0;
  m.m32 = 0.0;
  m.m33 = 1.0;
  return m;
}

inline ksl_mat4x4f_t ksl_mat4x4f_fromRt(const ksl_mat3x3f_t R,
                                        const ksl_vec3f_t t) {
  ksl_mat4x4f_t m;
  m.m00 = R.m00;
  m.m01 = R.m01;
  m.m02 = R.m02;
  m.m03 = t.x;
  m.m10 = R.m10;
  m.m11 = R.m11;
  m.m12 = R.m12;
  m.m13 = t.y;
  m.m20 = R.m20;
  m.m21 = R.m21;
  m.m22 = R.m22;
  m.m23 = t.z;
  m.m30 = 0.0;
  m.m31 = 0.0;
  m.m32 = 0.0;
  m.m33 = 1.0;
  return m;
}

ksl_SE3_t* ksl_SE3_alloc(const int n) {
  ksl_SE3_t* D = calloc(n, sizeof(ksl_SE3_t));
  for(int i = 0; i < n; i++) {
    ksl_SE3_setIdentity(&D[i]);
  }
  return D;
}

ksl_SE3f_t* ksl_SE3f_alloc(const int n) {
  ksl_SE3f_t* D = calloc(n, sizeof(ksl_SE3f_t));
  for(int i = 0; i < n; i++) {
    ksl_SE3f_setIdentity(&D[i]);
  }
  return D;
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

inline void ksl_SE3_toMat4x4(const ksl_SE3_t* restrict d,
                             ksl_mat4x4_t* restrict m) {
  memset(m, 0, sizeof(ksl_mat4x4_t));
  for(int i = 0; i < 4; i++) {   /* column index */
    for(int j = 0; j < 3; j++) { /* row index */
      m->as_array[i][j] = d->as_array[i][j];
    }
  }
  m->as_array[3][3] = 1.0;
}

inline void ksl_SE3f_toMat4x4f(const ksl_SE3f_t* restrict d,
                               ksl_mat4x4f_t* restrict m) {
  memset(m, 0, sizeof(ksl_mat4x4f_t));
  for(int i = 0; i < 4; i++) {   /* column index */
    for(int j = 0; j < 3; j++) { /* row index */
      m->as_array[i][j] = d->as_array[i][j];
    }
  }
  m->as_array[3][3] = 1.0;
}

inline void ksl_SE3_toMat4x4f(const ksl_SE3_t* d, ksl_mat4x4f_t* restrict m) {
  memset(m, 0, sizeof(ksl_mat4x4f_t));
  for(int i = 0; i < 4; i++) {   /* column index */
    for(int j = 0; j < 3; j++) { /* row index */
      m->as_array[i][j] = d->as_array[i][j];
    }
  }
  m->as_array[3][3] = 1.f;
}

inline void ksl_dc(const double thetai, double dc[2]) {
  sincos(thetai, &dc[0], &dc[1]);
}

inline void ksl_SE3_setIdentity(ksl_SE3_t* restrict d) {
  memset(d, 0, sizeof(ksl_SE3_t));
  for(int i = 0; i < 3; i++) {
    d->as_array[i][i] = 1.0;
  }
}

inline void ksl_SE3f_setIdentity(ksl_SE3f_t* restrict d) {
  memset(d, 0, sizeof(ksl_SE3f_t));
  for(int i = 0; i < 3; i++) {
    d->as_array[i][i] = 1.f;
  }
}

inline void ksl_mat3x3_setIdentity(ksl_mat3x3_t* restrict r) {
  memset(r, 0, sizeof(ksl_mat3x3_t));
  for(int i = 0; i < 3; i++) {
    r->as_array[i][i] = 1.0;
  }
}

inline void ksl_mat3x3f_setIdentity(ksl_mat3x3f_t* restrict r) {
  memset(r, 0, sizeof(ksl_mat3x3f_t));
  for(int i = 0; i < 3; i++) {
    r->as_array[i][i] = 1.0;
  }
}

inline void ksl_mat4x4_setIdentity(ksl_mat4x4_t* M) {
  memset(M, 0, sizeof(ksl_mat4x4_t));
  for(int i = 0; i < 4; i++) {
    M->as_array[i][i] = 1.0;
  }
}

inline void ksl_mat4x4f_setIdentity(ksl_mat4x4f_t* M) {
  memset(M, 0, sizeof(ksl_mat4x4f_t));
  for(int i = 0; i < 4; i++) {
    M->as_array[i][i] = 1.0;
  }
}

inline void ksl_mat3x3_set(ksl_mat3x3_t* restrict R, const int row,
                           const int column, const double value) {
  assert(row < 3 && column < 3);
  R->as_array[column][row] = value;
}

inline void ksl_mat3x3f_set(ksl_mat3x3f_t* restrict R, int row, int column,
                            float value) {
  assert(row < 3 && column < 3);
  R->as_array[column][row] = value;
}

inline void ksl_mat4x4_set(ksl_mat4x4_t* restrict M, const int row,
                           const int column, const double value) {
  assert(row < 4 && column < 4);
  M->as_array[column][row] = value;
}

inline void ksl_mat4x4f_set(ksl_mat4x4f_t* restrict M, int row, int column,
                            float value) {
  assert(row < 4 && column < 4);
  M->as_array[column][row] = value;
}

inline void ksl_SE3_set(ksl_SE3_t* restrict D, const int row, const int column,
                        const double value) {
  assert(row < 3 && column < 4);
  D->as_array[column][row] = value;
}

inline void ksl_SE3f_set(ksl_SE3f_t* D, int row, int column, float value) {
  assert(row < 3 && column < 4);
  D->as_array[column][row] = value;
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

inline double ksl_SE3_get(const ksl_SE3_t* restrict D, const int row,
                          const int column) {
  assert(row < 3 && column < 4);
  return D->as_array[column][row];
}

inline float ksl_SE3f_get(const ksl_SE3f_t* restrict D, const int row,
                          const int column) {
  assert(row < 3 && column < 4);
  return D->as_array[column][row];
}

inline double ksl_mat3x3_get(const ksl_mat3x3_t* restrict R, const int row,
                             const int column) {
  assert(row < 3 && column < 3);
  return R->as_array[column][row];
}

inline float ksl_mat3x3f_get(const ksl_mat3x3f_t* restrict R, const int row,
                             const int column) {
  assert(row < 3 && column < 3);
  return R->as_array[column][row];
}

inline double ksl_mat4x4_get(const ksl_mat4x4_t* restrict R, const int row,
                             const int column) {
  assert(row < 4 && column < 4);
  return R->as_array[column][row];
}

inline float ksl_mat4x4f_get(const ksl_mat4x4f_t* restrict R, const int row,
                             const int column) {
  assert(row < 4 && column < 4);
  return R->as_array[column][row];
}

inline void ksl_SE3_getTranslation(const ksl_SE3_t* restrict D,
                                   ksl_vec3_t* restrict t) {
  memcpy(t, &D->t, sizeof(ksl_vec3_t));
}

inline void ksl_SE3f_getTranslation(const ksl_SE3f_t* restrict D,
                                    ksl_vec3f_t* restrict t) {
  memcpy(t, &D->t, sizeof(ksl_vec3f_t));
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
      a.as_array[row][i] /= a.as_array[row][row];
      /* Compute U matrix */
      for(int j = row + 1; j < 3; j++) {
        a.as_array[j][i] -= a.as_array[row][i] * a.as_array[j][row];
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
        b.at[i] -= a.as_array[j][i] * b.at[j];
      }
    }

    /* perform backward substitution U^-1 b -> x
    where U is non-unit upper triangular */
    if(fabs(a.as_array[2][2]) < 1e-12) {
      return -3;
    }
    R->as_array[k][2] = b.at[2] / a.as_array[2][2];
    for(int i = 1; i > -1; i--) {
      double t = b.at[i];
      for(int j = i + 1; j < 3; j++) {
        t -= a.as_array[j][i] * R->as_array[k][j];
      }
      if(fabs(a.as_array[i][i]) < 1e-12) {
        return -(i + 1);
      }
      R->as_array[k][i] = t / a.as_array[i][i];
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
      a.as_array[row][i] /= a.as_array[row][row];
      /* Compute U matrix */
      for(int j = row + 1; j < 3; j++) {
        a.as_array[j][i] -= a.as_array[row][i] * a.as_array[j][row];
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
        b.at[i] -= a.as_array[j][i] * b.at[j];
      }
    }

    /* perform backward substitution U^-1 b -> x
    where U is non-unit upper triangular */
    if(fabs(a.as_array[2][2]) < 1e-12) {
      return -3;
    }
    R->as_array[k][2] = b.at[2] / a.as_array[2][2];
    for(int i = 1; i > -1; i--) {
      double t = b.at[i];
      for(int j = i + 1; j < 3; j++) {
        t -= a.as_array[j][i] * R->as_array[k][j];
      }
      if(fabs(a.as_array[i][i]) < 1e-12) {
        return -(i + 1);
      }
      R->as_array[k][i] = t / a.as_array[i][i];
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
      a.as_array[row][i] /= a.as_array[row][row];
      /* Compute U matrix */
      for(int j = row + 1; j < 3; j++) {
        a.as_array[j][i] -= a.as_array[row][i] * a.as_array[j][row];
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
        b.at[i] -= a.as_array[j][i] * b.at[j];
      }
    }

    /* perform backward substitution U^-1 b -> x
    where U is non-unit upper triangular */
    if(fabs(a.as_array[2][2]) < 1e-12) {
      return -3;
    }
    ro->as_array[k][2] = b.at[2] / a.as_array[2][2];
    for(int i = 1; i > -1; i--) {
      double t = b.at[i];
      for(int j = i + 1; j < 3; j++) {
        t -= a.as_array[j][i] * ro->as_array[k][j];
      }
      if(fabs(a.as_array[i][i]) < 1e-12) {
        return -(i + 1);
      }
      ro->as_array[k][i] = t / a.as_array[i][i];
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
      a.as_array[row][i] /= a.as_array[row][row];
      /* Compute U matrix */
      for(int j = row + 1; j < 3; j++) {
        a.as_array[j][i] -= a.as_array[row][i] * a.as_array[j][row];
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
        b.at[i] -= a.as_array[j][i] * b.at[j];
      }
    }

    /* perform backward substitution U^-1 b -> x
    where U is non-unit upper triangular */
    if(fabs(a.as_array[2][2]) < 1e-12) {
      return -3;
    }
    ro->as_array[k][2] = b.at[2] / a.as_array[2][2];
    for(int i = 1; i > -1; i--) {
      double t = b.at[i];
      for(int j = i + 1; j < 3; j++) {
        t -= a.as_array[j][i] * ro->as_array[k][j];
      }
      if(fabs(a.as_array[i][i]) < 1e-12) {
        return -(i + 1);
      }
      ro->as_array[k][i] = t / a.as_array[i][i];
    }
  }
  return 0;
}

inline void ksl_mat3x3_transpose(ksl_mat3x3_t* restrict R) {
  ksl_swap(&R->as_array[0][1], &R->as_array[1][0]);
  ksl_swap(&R->as_array[0][2], &R->as_array[2][0]);
  ksl_swap(&R->as_array[1][2], &R->as_array[2][1]);
}

inline void ksl_mat3x3f_transpose(ksl_mat3x3f_t* restrict R) {
  ksl_swapf(&R->as_array[0][1], &R->as_array[1][0]);
  ksl_swapf(&R->as_array[0][2], &R->as_array[2][0]);
  ksl_swapf(&R->as_array[1][2], &R->as_array[2][1]);
}

inline void ksl_mat3x3_transposed(const ksl_mat3x3_t* restrict ri,
                                  ksl_mat3x3_t* restrict ro) {
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      ro->as_array[i][j] = ri->as_array[j][i];
    }
  }
}

inline void ksl_mat3x3f_transposed(const ksl_mat3x3f_t* restrict ri,
                                   ksl_mat3x3f_t* restrict ro) {
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      ro->as_array[i][j] = ri->as_array[j][i];
    }
  }
}

inline void ksl_SE3_copy(const ksl_SE3_t* Di, ksl_SE3_t* Do) {
  memcpy(Do, Di, sizeof(ksl_SE3_t));
}

inline void ksl_SE3f_copy(const ksl_SE3f_t* Di, ksl_SE3f_t* Do) {
  memcpy(Do, Di, sizeof(ksl_SE3f_t));
}

inline void ksl_SE3_inverted(const ksl_SE3_t* Di, ksl_SE3_t* Do) {
  ksl_mat3x3_transposed(&Di->R, &Do->R);
  ksl_product_drinvvinv(&Di->R, &Di->t, &Do->t);
}

inline void ksl_SE3f_inverted(const ksl_SE3f_t* Di, ksl_SE3f_t* Do) {
  ksl_mat3x3f_transposed(&Di->R, &Do->R);
  ksl_product_drinvvinvf(&Di->R, &Di->t, &Do->t);
}

inline void ksl_SE3_invert(ksl_SE3_t* D) {
  ksl_vec3_t temp;
  ksl_product_drinvvinv(&D->R, &D->t, &temp);
  ksl_mat3x3_transpose(&D->R);
  ksl_vec3_copy(&temp, &D->t);
}

inline void ksl_SE3f_invert(ksl_SE3f_t* D) {
  ksl_vec3f_t temp;
  ksl_product_drinvvinvf(&D->R, &D->t, &temp);
  ksl_mat3x3f_transpose(&D->R);
  ksl_vec3f_copy(&temp, &D->t);
}

/*!
@brief obtain sequence of Euler angles using specified axis sequence convention

This function decomposes a general direction cosine matrix into three
      primitive direction cosine matrices, whose axes are determined by the
      integers passed in through axisSequence. The direction cosine matrix
      is passed in through Ri, and the three computed angles are updated
and returned in angle. The previous values assigned to angle are passed in
      to RtoA in angle. RtoA calls catan2, which uses the values stored in
angle to maintain continuity if at all possible. This function does not
check for bad axis indices. These checks could be added but would reduce
      efficiency. For actual reporting purposes, especially when a large
number of user output requests are to be processed.
*/
inline void
ksl_mat3x3_getEulerAnglesWithReference(const ksl_mat3x3_t* r,
                                       const ksl_axis_enum_t axisType,
                                       ksl_vec3_t* angles, ...) {

  va_list arguments;
  va_start(arguments, angles);
  ksl_vec3_t* reference = va_arg(arguments, ksl_vec3_t*);
  va_end(arguments);
  ksl_vec3_t reference_angles = {{0.0, 0.0, 0.0}};
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
      angles->at[2] =
        catan1pi(-r->as_array[1][0], r->as_array[0][0], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] = catan2pi(r->as_array[1][2] * c + r->as_array[0][2] * s,
                               r->as_array[1][1] * c + r->as_array[0][1] * s,
                               reference->at[0]);
      angles->at[1] = catan2pi(r->as_array[2][0],
                               r->as_array[0][0] * c - r->as_array[1][0] * s,
                               reference->at[1]);
      break;
    case KSL_AXIS_YZX:
      // i = 1, j = 2, k = 0
      // angle[2] = catan1pi(-Ri[i][j], Ri[i][i], angle[2]);
      // angle[0] = catan2pi(Ri[k][j]*c + Ri[k][i]*s, Ri[j][j]*c +
      // Ri[j][i] * s,
      // angle[0]); angle[1] = catan2pi(Ri[i][k], Ri[i][i]*c - Ri[i][j]*s,
      // angle[1]);
      angles->at[2] =
        catan1pi(-r->as_array[2][1], r->as_array[1][1], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] = catan2pi(r->as_array[2][0] * c + r->as_array[1][0] * s,
                               r->as_array[2][2] * c + r->as_array[1][2] * s,
                               reference->at[0]);
      angles->at[1] = catan2pi(r->as_array[0][1],
                               r->as_array[1][1] * c - r->as_array[2][1] * s,
                               reference->at[1]);
      break;
    case KSL_AXIS_ZXY:
      // i = 2, j = 0, k = 1
      // angle[2] = catan1pi(-Ri[i][j], Ri[i][i], angle[2]);
      // angle[0] = catan2pi(Ri[k][j]*c + Ri[k][i]*s, Ri[j][j]*c +
      // Ri[j][i] * s,
      // angle[0]); angle[1] = catan2pi(Ri[i][k], Ri[i][i]*c - Ri[i][j]*s,
      // angle[1]);
      angles->at[2] =
        catan1pi(-r->as_array[0][2], r->as_array[2][2], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] = catan2pi(r->as_array[0][1] * c + r->as_array[2][1] * s,
                               r->as_array[0][0] * c + r->as_array[2][0] * s,
                               reference->at[0]);
      angles->at[1] = catan2pi(r->as_array[1][2],
                               r->as_array[2][2] * c - r->as_array[0][2] * s,
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
      angles->at[2] =
        catan1pi(r->as_array[1][0], r->as_array[2][0], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] = catan2pi(r->as_array[1][2] * c - r->as_array[2][2] * s,
                               r->as_array[1][1] * c - r->as_array[2][1] * s,
                               reference->at[0]);
      angles->at[1] = catan2pi(r->as_array[2][0] * c + r->as_array[1][0] * s,
                               r->as_array[0][0], reference->at[1]);
      break;
    case KSL_AXIS_YZY:
      // i = 1, j = 2, k = 1
      // Set k = 0 for correct index into direction cosine matrix.
      // angle[2] = catan1pi(Ri[i][j], Ri[i][k], angle[2]);
      // angle[0] = catan2pi(Ri[k][j]*c - Ri[k][k]*s, Ri[j][j]*c -
      // Ri[j][k] * s,
      // angle[0]); angle[1] = catan2pi(Ri[i][k]*c + Ri[i][j]*s, Ri[i][i],
      // angle[1]);
      angles->at[2] =
        catan1pi(r->as_array[2][1], r->as_array[0][1], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] = catan2pi(r->as_array[2][0] * c - r->as_array[0][0] * s,
                               r->as_array[2][2] * c - r->as_array[0][2] * s,
                               reference->at[0]);
      angles->at[1] = catan2pi(r->as_array[0][1] * c + r->as_array[2][1] * s,
                               r->as_array[1][1], reference->at[1]);
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
      angles->at[2] =
        catan1pi(r->as_array[0][2], r->as_array[1][2], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] = catan2pi(r->as_array[0][1] * c - r->as_array[1][1] * s,
                               r->as_array[0][0] * c - r->as_array[1][0] * s,
                               reference->at[0]);
      angles->at[1] = catan2pi(r->as_array[1][2] * c + r->as_array[0][2] * s,
                               r->as_array[2][2], reference->at[1]);
      break;
    case KSL_AXIS_XZY:
      // i = 0, j = 2, k = 1
      // angle[2] = catan1pi(Ri[i][j], Ri[i][i], angle[2]);
      // angle[0] = catan2pi(-(Ri[k][j]*c - Ri[k][i]*s), Ri[j][j]*c -
      // Ri[j][i]*s, angle[0]);  angle[1] = catan2pi(-Ri[i][k], Ri[i][i]*c +
      // Ri[i][j]*s, angle[1]);
      angles->at[2] =
        catan1pi(r->as_array[2][0], r->as_array[0][0], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] = catan2pi(-(r->as_array[2][1] * c - r->as_array[0][1] * s),
                               r->as_array[2][2] * c - r->as_array[0][2] * s,
                               reference->at[0]);
      angles->at[1] = catan2pi(-r->as_array[1][0],
                               r->as_array[0][0] * c + r->as_array[2][0] * s,
                               reference->at[1]);
      break;
    case KSL_AXIS_YXZ:
      // i = 1, j = 0, k = 2
      // angle[2] = catan1pi(Ri[i][j], Ri[i][i], angle[2]);
      // angle[0] = catan2pi(-(Ri[k][j]*c - Ri[k][i]*s), Ri[j][j]*c -
      // Ri[j][i]*s, angle[0]);  angle[1] = catan2pi(-Ri[i][k], Ri[i][i]*c +
      // Ri[i][j]*s, angle[1]);
      angles->at[2] =
        catan1pi(r->as_array[0][1], r->as_array[1][1], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] = catan2pi(-(r->as_array[0][2] * c - r->as_array[1][2] * s),
                               r->as_array[0][0] * c - r->as_array[1][0] * s,
                               reference->at[0]);
      angles->at[1] = catan2pi(-r->as_array[2][1],
                               r->as_array[1][1] * c + r->as_array[0][1] * s,
                               reference->at[1]);
      break;
    case KSL_AXIS_ZYX:
      // i = 2, j = 1, k = 0
      // angle[2] = catan1pi(Ri[i][j], Ri[i][i], angle[2]);
      // angle[0] = catan2pi(-(Ri[k][j]*c - Ri[k][i]*s), Ri[j][j]*c -
      // Ri[j][i]*s, angle[0]);  angle[1] = catan2pi(-Ri[i][k], Ri[i][i]*c +
      // Ri[i][j]*s, angle[1]);
      angles->at[2] =
        catan1pi(r->as_array[1][2], r->as_array[2][2], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] = catan2pi(-(r->as_array[1][0] * c - r->as_array[2][0] * s),
                               r->as_array[1][1] * c - r->as_array[2][1] * s,
                               reference->at[0]);
      angles->at[1] = catan2pi(-r->as_array[0][2],
                               r->as_array[2][2] * c + r->as_array[1][2] * s,
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
      angles->at[2] =
        catan1pi(-r->as_array[2][0], r->as_array[1][0], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] = catan2pi(-(r->as_array[2][1] * c + r->as_array[1][1] * s),
                               r->as_array[2][2] * c + r->as_array[1][2] * s,
                               reference->at[0]);
      angles->at[1] = catan2pi(-(r->as_array[1][0] * c - r->as_array[2][0] * s),
                               r->as_array[0][0], reference->at[1]);
      break;
    case KSL_AXIS_YXY:
      // i = 1, j = 0, k = 1
      // Set k = 2 for correct index into direction cosine matrix.
      // angle[2] = catan1pi(-Ri[i][j], Ri[i][k], angle[2]);
      // angle[0] = catan2pi(-(Ri[k][j]*c + Ri[k][k]*s), Ri[j][j]*c +
      // Ri[j][k]*s, angle[0]);  angle[1] = catan2pi(-(Ri[i][k]*c -
      // Ri[i][j]*s),
      // Ri[i][i], angle[1]);
      angles->at[2] =
        catan1pi(-r->as_array[0][1], r->as_array[2][1], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] = catan2pi(-(r->as_array[0][2] * c + r->as_array[2][2] * s),
                               r->as_array[0][0] * c + r->as_array[2][0] * s,
                               reference->at[0]);
      angles->at[1] = catan2pi(-(r->as_array[2][1] * c - r->as_array[0][1] * s),
                               r->as_array[1][1], reference->at[1]);
      break;
    case KSL_AXIS_ZYZ:
      // i = 2, j = 1, k = 2
      // Set k = 0 for correct index into direction cosine matrix.
      // angle[2] = catan1pi(-Ri[i][j], Ri[i][k], angle[2]);
      // angle[0] = catan2pi(-(Ri[k][j]*c + Ri[k][k]*s), Ri[j][j]*c +
      // Ri[j][k]*s, angle[0]);  angle[1] = catan2pi(-(Ri[i][k]*c -
      // Ri[i][j]*s),
      // Ri[i][i], angle[1]);
      angles->at[2] =
        catan1pi(-r->as_array[1][2], r->as_array[0][2], reference->at[2]);
      c = cos(angles->at[2]);
      s = sin(angles->at[2]);
      angles->at[0] = catan2pi(-(r->as_array[1][0] * c + r->as_array[0][0] * s),
                               r->as_array[1][1] * c + r->as_array[0][1] * s,
                               reference->at[0]);
      angles->at[1] = catan2pi(-(r->as_array[0][2] * c - r->as_array[1][2] * s),
                               r->as_array[2][2], reference->at[1]);
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
  //     angles->y = catan1pi(-r->as_array[j][i], r->as_array[i][i],
  //     reference->y); c = cos(angles->y); s = sin(angles->y); angles->x =
  //       catan2pi(r->as_array[j][k] * c + r->as_array[i][k] * s,
  //                r->as_array[j][j] * c + r->as_array[i][j] * s,
  //                reference->x);
  //     angles->y =
  //       catan2pi(r->as_array[k][i],
  //                r->as_array[i][i] * c - r->as_array[j][i] * s,
  //                reference->y);
  //   } else { // k == i; reverse cycle j --> i
  //     // Case 3: 0 --> 1 --> 0; 1 --> 2 --> 1; 2 --> 0 --> 2
  //     // Reset k for correct index into direction cosine matrix.
  //     k = f[j];
  //     angles->z = catan1pi(r->as_array[j][i], r->as_array[k][i],
  //     reference->z); c = cos(angles->z); s = sin(angles->z); angles->x =
  //       catan2pi(r->as_array[j][k] * c - r->as_array[k][k] * s,
  //                r->as_array[j][j] * c - r->as_array[k][j] * s,
  //                reference->x);
  //     angles->y = catan2pi(r->as_array[k][i] * c + r->as_array[j][i] * s,
  //                          r->as_array[i][i], reference->y);
  //   }
  // } else {       // Cases 2 and 4: reverse cycle i --> j
  //   if(k != i) { // reverse cycle j --> k
  //     // Case 2: 0 --> 2 --> 1; 1 --> 0 --> 2; 2 --> 1 --> 0
  //     angles->z = catan1pi(r->as_array[j][i], r->as_array[i][i],
  //     reference->z); c = cos(angles->z); s = sin(angles->z); angles->x =
  //       catan2pi(-(r->as_array[j][k] * c - r->as_array[i][k] * s),
  //                r->as_array[j][j] * c - r->as_array[i][j] * s,
  //                reference->x);
  //     angles->y =
  //       catan2pi(-r->as_array[k][i],
  //                r->as_array[i][i] * c + r->as_array[j][i] * s,
  //                reference->y);
  //   } else { // k == i; forward cycle j --> i
  //     // Case 4: 0 --> 2 --> 0; 1 --> 0 --> 1; 2 --> 1 --> 2
  //     // Reset k for correct index into direction cosine matrix.
  //     k = f[i];
  //     angles->z = catan1pi(-r->as_array[j][i], r->as_array[k][i],
  //     reference->z); c = cos(angles->z); s = sin(angles->z); angles->x =
  //       catan2pi(-(r->as_array[j][k] * c + r->as_array[k][k] * s),
  //                r->as_array[j][j] * c + r->as_array[k][j] * s,
  //                reference->x);
  //     angles->y = catan2pi(-(r->as_array[k][i] * c - r->as_array[j][i] * s),
  //                          r->as_array[i][i], reference->y);
  //   }
  // }
}

/*!
@brief set mat3x3 matrix from a sequence of Euler angles

This function takes three Euler angles in one of twelve rotation orders
   and outputs a direction cosine matrix. The axis sequence is input through
         axis. Rotations about successive axes x=0, y=1, and z=2 are as
   follows: xyx = 010; xyz = 012; xzx = 020; xzy = 021 yxy = 101; yxz = 102;
   yzx = 120; yzy = 121 zxy = 201; zxz = 202; zyx = 210; zyz = 212

        |1      |       | c     s|       |c -s   |
   Rx = |   c -s|  Ry = |    1   |  Rz = |s  c   |
        |   s  c|       |-s     c|       |      1|

*/
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

inline void ksl_mat4x4_getTranslation(const ksl_mat4x4_t* restrict Mi,
                                      ksl_vec3_t* restrict to) {
  memcpy(to, &Mi->v3, sizeof(ksl_vec3_t));
}

inline void ksl_mat4x4f_getTranslation(const ksl_mat4x4f_t* restrict Mi,
                                       ksl_vec3f_t* to) {
  memcpy(to, &Mi->v3, sizeof(ksl_vec3f_t));
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

/*!
@brief get axis and angle from a rotation matrix

if sin is close to 0, the axis of rotation is not well defined.
*/
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

/*!
@brief set rotation matrix from axis and angle representation

@param r [out] rotation matrix will be set here
@param axis [in] axis of rotation
@param angle [in] angle of rotation in radians
*/
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

/* matrix vector operations */
inline void ksl_product_drv(const ksl_mat3x3_t* restrict ri,
                            const ksl_vec3_t* restrict vi,
                            ksl_vec3_t* restrict vo) {
  ksl_product_av(vi->x, &ri->v0, vo);
  ksl_axpy_vv(vi->y, &ri->v1, vo);
  ksl_axpy_vv(vi->z, &ri->v2, vo);
}

inline void ksl_product_drvf(const ksl_mat3x3f_t* restrict ri,
                             const ksl_vec3f_t* restrict vi,
                             ksl_vec3f_t* restrict vo) {
  ksl_product_avf(vi->x, &ri->v0, vo);
  ksl_axpy_vvf(vi->y, &ri->v1, vo);
  ksl_axpy_vvf(vi->z, &ri->v2, vo);
}

inline void ksl_product_drvinv(const ksl_mat3x3_t* restrict ri,
                               const ksl_vec3_t* restrict vi,
                               ksl_vec3_t* restrict vo) {
  ksl_product_av(-vi->x, &ri->v0, vo);
  ksl_axpy_vv(-vi->y, &ri->v1, vo);
  ksl_axpy_vv(-vi->z, &ri->v2, vo);
}

inline void ksl_product_drvinvf(const ksl_mat3x3f_t* restrict ri,
                                const ksl_vec3f_t* restrict vi,
                                ksl_vec3f_t* restrict vo) {
  ksl_product_avf(-vi->x, &ri->v0, vo);
  ksl_axpy_vvf(-vi->y, &ri->v1, vo);
  ksl_axpy_vvf(-vi->z, &ri->v2, vo);
}

inline void ksl_product_drinvv(const ksl_mat3x3_t* restrict ri,
                               const ksl_vec3_t* restrict vi,
                               ksl_vec3_t* restrict vo) {
  vo->x = ksl_dot_vv(&ri->v0, vi);
  vo->y = ksl_dot_vv(&ri->v1, vi);
  vo->z = ksl_dot_vv(&ri->v2, vi);
}

inline void ksl_product_drinvvf(const ksl_mat3x3f_t* restrict ri,
                                const ksl_vec3f_t* restrict vi,
                                ksl_vec3f_t* restrict vo) {
  vo->x = ksl_dot_vvf(&ri->v0, vi);
  vo->y = ksl_dot_vvf(&ri->v1, vi);
  vo->z = ksl_dot_vvf(&ri->v2, vi);
}

inline void ksl_product_drinvvinv(const ksl_mat3x3_t* restrict ri,
                                  const ksl_vec3_t* restrict vi,
                                  ksl_vec3_t* restrict vo) {
  vo->x = -ksl_dot_vv(&ri->v0, vi);
  vo->y = -ksl_dot_vv(&ri->v1, vi);
  vo->z = -ksl_dot_vv(&ri->v2, vi);
}

inline void ksl_product_drinvvinvf(const ksl_mat3x3f_t* restrict ri,
                                   const ksl_vec3f_t* restrict vi,
                                   ksl_vec3f_t* restrict vo) {
  vo->x = -ksl_dot_vvf(&ri->v0, vi);
  vo->y = -ksl_dot_vvf(&ri->v1, vi);
  vo->z = -ksl_dot_vvf(&ri->v2, vi);
}

inline void ksl_product_drvtx(const ksl_mat3x3_t* restrict ri, const double tx,
                              ksl_vec3_t* restrict vo) {
  ksl_product_av(tx, &ri->v0, vo);
}

inline void ksl_product_drvtxf(const ksl_mat3x3f_t* restrict ri, const float tx,
                               ksl_vec3f_t* restrict vo) {
  ksl_product_avf(tx, &ri->v0, vo);
}

inline void ksl_product_drvtxinv(const ksl_mat3x3_t* restrict ri,
                                 const double tx, ksl_vec3_t* restrict vo) {
  ksl_product_av(-tx, &ri->v0, vo);
}

inline void ksl_product_drvtxinvf(const ksl_mat3x3f_t* restrict ri,
                                  const float tx, ksl_vec3f_t* restrict vo) {
  ksl_product_avf(-tx, &ri->v0, vo);
}

inline void ksl_product_drvty(const ksl_mat3x3_t* restrict ri, const double ty,
                              ksl_vec3_t* restrict vo) {
  ksl_product_av(ty, &ri->v1, vo);
}

inline void ksl_product_drvtyf(const ksl_mat3x3f_t* restrict ri, const float ty,
                               ksl_vec3f_t* restrict vo) {
  ksl_product_avf(ty, &ri->v1, vo);
}

inline void ksl_product_drvtyinv(const ksl_mat3x3_t* restrict ri,
                                 const double ty, ksl_vec3_t* restrict vo) {
  ksl_product_av(-ty, &ri->v1, vo);
}

inline void ksl_product_drvtyinvf(const ksl_mat3x3f_t* restrict ri,
                                  const float ty, ksl_vec3f_t* restrict vo) {
  ksl_product_avf(-ty, &ri->v1, vo);
}

inline void ksl_product_drvtz(const ksl_mat3x3_t* restrict ri, const double tz,
                              ksl_vec3_t* restrict vo) {
  ksl_product_av(tz, &ri->v2, vo);
}

inline void ksl_product_drvtzf(const ksl_mat3x3f_t* restrict ri, const float tz,
                               ksl_vec3f_t* restrict vo) {
  ksl_product_avf(tz, &ri->v2, vo);
}

inline void ksl_product_drvtzinv(const ksl_mat3x3_t* restrict ri,
                                 const double tz, ksl_vec3_t* restrict vo) {
  ksl_product_av(-tz, &ri->v2, vo);
}

inline void ksl_product_drvtzinvf(const ksl_mat3x3f_t* restrict ri,
                                  const float tz, ksl_vec3f_t* restrict vo) {
  ksl_product_avf(-tz, &ri->v2, vo);
}

/* matrix-matrix operations */
inline void ksl_product_drdrx(const ksl_mat3x3_t* restrict ri,
                              const double dc[2], ksl_mat3x3_t* restrict ro) {
  ksl_vec3_copy(&ri->v0, &ro->v0);
  ksl_product_av(dc[1], &ri->v1, &ro->v1);
  ksl_axpy_vv(dc[0], &ri->v2, &ro->v1);
  ksl_product_av(-dc[0], &ri->v1, &ro->v2);
  ksl_axpy_vv(dc[1], &ri->v2, &ro->v2);
}

inline void ksl_product_drdrxf(const ksl_mat3x3f_t* restrict ri,
                               const float dc[2], ksl_mat3x3f_t* restrict ro) {
  ksl_vec3f_copy(&ri->v0, &ro->v0);
  ksl_product_avf(dc[1], &ri->v1, &ro->v1);
  ksl_axpy_vvf(dc[0], &ri->v2, &ro->v1);
  ksl_product_avf(-dc[0], &ri->v1, &ro->v2);
  ksl_axpy_vvf(dc[1], &ri->v2, &ro->v2);
}

inline void ksl_product_drdrxinv(const ksl_mat3x3_t* restrict ri,
                                 const double dc[2],
                                 ksl_mat3x3_t* restrict ro) {
  ksl_vec3_copy(&ri->v0, &ro->v0);
  ksl_product_av(dc[1], &ri->v1, &ro->v1);
  ksl_axpy_vv(-dc[0], &ri->v2, &ro->v1);
  ksl_product_av(dc[0], &ri->v1, &ro->v2);
  ksl_axpy_vv(dc[1], &ri->v2, &ro->v2);
}

inline void ksl_product_drdrxinvf(const ksl_mat3x3f_t* restrict ri,
                                  const float dc[2],
                                  ksl_mat3x3f_t* restrict ro) {
  ksl_vec3f_copy(&ri->v0, &ro->v0);
  ksl_product_avf(dc[1], &ri->v1, &ro->v1);
  ksl_axpy_vvf(-dc[0], &ri->v2, &ro->v1);
  ksl_product_avf(dc[0], &ri->v1, &ro->v2);
  ksl_axpy_vvf(dc[1], &ri->v2, &ro->v2);
}

inline void ksl_product_drdry(const ksl_mat3x3_t* restrict ri,
                              const double dc[2], ksl_mat3x3_t* restrict ro) {
  ksl_product_av(dc[1], &ri->v0, &ro->v0);
  ksl_axpy_vv(-dc[0], &ri->v2, &ro->v0);
  ksl_product_av(dc[1], &ri->v2, &ro->v2);
  ksl_axpy_vv(dc[0], &ri->v0, &ro->v2);
  ksl_vec3_copy(&ri->v1, &ro->v1);
}

inline void ksl_product_drdryf(const ksl_mat3x3f_t* restrict ri,
                               const float dc[2], ksl_mat3x3f_t* restrict ro) {
  ksl_product_avf(dc[1], &ri->v0, &ro->v0);
  ksl_axpy_vvf(-dc[0], &ri->v2, &ro->v0);
  ksl_product_avf(dc[1], &ri->v2, &ro->v2);
  ksl_axpy_vvf(dc[0], &ri->v0, &ro->v2);
  ksl_vec3f_copy(&ri->v1, &ro->v1);
}

inline void ksl_product_drdryinv(const ksl_mat3x3_t* restrict ri,
                                 const double dc[2],
                                 ksl_mat3x3_t* restrict ro) {
  ksl_product_av(dc[1], &ri->v0, &ro->v0);
  ksl_axpy_vv(dc[0], &ri->v2, &ro->v0);
  ksl_product_av(dc[1], &ri->v2, &ro->v2);
  ksl_axpy_vv(-dc[0], &ri->v0, &ro->v2);
  ksl_vec3_copy(&ri->v1, &ro->v1);
}

inline void ksl_product_drdryinvf(const ksl_mat3x3f_t* restrict ri,
                                  const float dc[2],
                                  ksl_mat3x3f_t* restrict ro) {
  ksl_product_avf(dc[1], &ri->v0, &ro->v0);
  ksl_axpy_vvf(dc[0], &ri->v2, &ro->v0);
  ksl_product_avf(dc[1], &ri->v2, &ro->v2);
  ksl_axpy_vvf(-dc[0], &ri->v0, &ro->v2);
  ksl_vec3f_copy(&ri->v1, &ro->v1);
}

inline void ksl_product_drdrz(const ksl_mat3x3_t* restrict ri,
                              const double dc[2], ksl_mat3x3_t* restrict ro) {
  ksl_product_av(dc[1], &ri->v0, &ro->v0);
  ksl_axpy_vv(dc[0], &ri->v1, &ro->v0);
  ksl_product_av(-dc[0], &ri->v0, &ro->v1);
  ksl_axpy_vv(dc[1], &ri->v1, &ro->v1);
  ksl_vec3_copy(&ri->v2, &ro->v2);
}

inline void ksl_product_drdrzf(const ksl_mat3x3f_t* restrict ri,
                               const float dc[2], ksl_mat3x3f_t* restrict ro) {
  ksl_product_avf(dc[1], &ri->v0, &ro->v0);
  ksl_axpy_vvf(dc[0], &ri->v1, &ro->v0);
  ksl_product_avf(-dc[0], &ri->v0, &ro->v1);
  ksl_axpy_vvf(dc[1], &ri->v1, &ro->v1);
  ksl_vec3f_copy(&ri->v2, &ro->v2);
}

inline void ksl_product_drdrzinv(const ksl_mat3x3_t* restrict ri,
                                 const double dc[2],
                                 ksl_mat3x3_t* restrict ro) {
  ksl_product_av(dc[1], &ri->v0, &ro->v0);
  ksl_axpy_vv(-dc[0], &ri->v1, &ro->v0);
  ksl_product_av(dc[0], &ri->v0, &ro->v1);
  ksl_axpy_vv(dc[1], &ri->v1, &ro->v1);
  ksl_vec3_copy(&ri->v2, &ro->v2);
}

inline void ksl_product_drdrzinvf(const ksl_mat3x3f_t* restrict ri,
                                  const float dc[2],
                                  ksl_mat3x3f_t* restrict ro) {
  ksl_product_avf(dc[1], &ri->v0, &ro->v0);
  ksl_axpy_vvf(-dc[0], &ri->v1, &ro->v0);
  ksl_product_avf(dc[0], &ri->v0, &ro->v1);
  ksl_axpy_vvf(dc[1], &ri->v1, &ro->v1);
  ksl_vec3f_copy(&ri->v2, &ro->v2);
}

inline void ksl_product_drdr(const ksl_mat3x3_t* restrict r1i,
                             const ksl_mat3x3_t* restrict r2i,
                             ksl_mat3x3_t* restrict ro) {
  ro->m00 = r1i->m00 * r2i->m00 + r1i->m01 * r2i->m10 + r1i->m02 * r2i->m20;
  ro->m01 = r1i->m00 * r2i->m01 + r1i->m01 * r2i->m11 + r1i->m02 * r2i->m21;
  ro->m02 = r1i->m00 * r2i->m02 + r1i->m01 * r2i->m12 + r1i->m02 * r2i->m22;
  ro->m10 = r1i->m10 * r2i->m00 + r1i->m11 * r2i->m10 + r1i->m12 * r2i->m20;
  ro->m11 = r1i->m10 * r2i->m01 + r1i->m11 * r2i->m11 + r1i->m12 * r2i->m21;
  ro->m12 = r1i->m10 * r2i->m02 + r1i->m11 * r2i->m12 + r1i->m12 * r2i->m22;
  ro->m20 = r1i->m20 * r2i->m00 + r1i->m21 * r2i->m10 + r1i->m22 * r2i->m20;
  ro->m21 = r1i->m20 * r2i->m01 + r1i->m21 * r2i->m11 + r1i->m22 * r2i->m21;
  ro->m22 = r1i->m20 * r2i->m02 + r1i->m21 * r2i->m12 + r1i->m22 * r2i->m22;
}

inline void ksl_product_drdrf(const ksl_mat3x3f_t* restrict r1i,
                              const ksl_mat3x3f_t* restrict r2i,
                              ksl_mat3x3f_t* restrict ro) {
  ro->m00 = r1i->m00 * r2i->m00 + r1i->m01 * r2i->m10 + r1i->m02 * r2i->m20;
  ro->m01 = r1i->m00 * r2i->m01 + r1i->m01 * r2i->m11 + r1i->m02 * r2i->m21;
  ro->m02 = r1i->m00 * r2i->m02 + r1i->m01 * r2i->m12 + r1i->m02 * r2i->m22;
  ro->m10 = r1i->m10 * r2i->m00 + r1i->m11 * r2i->m10 + r1i->m12 * r2i->m20;
  ro->m11 = r1i->m10 * r2i->m01 + r1i->m11 * r2i->m11 + r1i->m12 * r2i->m21;
  ro->m12 = r1i->m10 * r2i->m02 + r1i->m11 * r2i->m12 + r1i->m12 * r2i->m22;
  ro->m20 = r1i->m20 * r2i->m00 + r1i->m21 * r2i->m10 + r1i->m22 * r2i->m20;
  ro->m21 = r1i->m20 * r2i->m01 + r1i->m21 * r2i->m11 + r1i->m22 * r2i->m21;
  ro->m22 = r1i->m20 * r2i->m02 + r1i->m21 * r2i->m12 + r1i->m22 * r2i->m22;
}

inline void ksl_product_drdrinv(const ksl_mat3x3_t* restrict r1i,
                                const ksl_mat3x3_t* restrict r2i,
                                ksl_mat3x3_t* restrict ro) {
  ro->m00 = ksl_dot_vv(&r1i->v0, &r2i->v0);
  ro->m01 = ksl_dot_vv(&r1i->v0, &r2i->v1);
  ro->m02 = ksl_dot_vv(&r1i->v0, &r2i->v2);
  ro->m10 = ksl_dot_vv(&r1i->v1, &r2i->v0);
  ro->m11 = ksl_dot_vv(&r1i->v1, &r2i->v1);
  ro->m12 = ksl_dot_vv(&r1i->v1, &r2i->v2);
  ro->m20 = ksl_dot_vv(&r1i->v2, &r2i->v0);
  ro->m21 = ksl_dot_vv(&r1i->v2, &r2i->v1);
  ro->m22 = ksl_dot_vv(&r1i->v2, &r2i->v2);
}

inline void ksl_product_drdrinvf(const ksl_mat3x3f_t* restrict r1i,
                                 const ksl_mat3x3f_t* restrict r2i,
                                 ksl_mat3x3f_t* restrict ro) {
  ro->m00 = ksl_dot_vvf(&r1i->v0, &r2i->v0);
  ro->m01 = ksl_dot_vvf(&r1i->v0, &r2i->v1);
  ro->m02 = ksl_dot_vvf(&r1i->v0, &r2i->v2);
  ro->m10 = ksl_dot_vvf(&r1i->v1, &r2i->v0);
  ro->m11 = ksl_dot_vvf(&r1i->v1, &r2i->v1);
  ro->m12 = ksl_dot_vvf(&r1i->v1, &r2i->v2);
  ro->m20 = ksl_dot_vvf(&r1i->v2, &r2i->v0);
  ro->m21 = ksl_dot_vvf(&r1i->v2, &r2i->v1);
  ro->m22 = ksl_dot_vvf(&r1i->v2, &r2i->v2);
}

inline void ksl_product_drinvdr(const ksl_mat3x3_t* restrict r1i,
                                const ksl_mat3x3_t* restrict r2i,
                                ksl_mat3x3_t* restrict ro) {
  ro->m00 = r1i->m00 * r2i->m00 + r1i->m10 * r2i->m10 + r1i->m20 * r2i->m20;
  ro->m01 = r1i->m00 * r2i->m01 + r1i->m10 * r2i->m11 + r1i->m20 * r2i->m21;
  ro->m02 = r1i->m00 * r2i->m02 + r1i->m10 * r2i->m12 + r1i->m20 * r2i->m22;
  ro->m10 = r1i->m01 * r2i->m00 + r1i->m11 * r2i->m10 + r1i->m21 * r2i->m20;
  ro->m11 = r1i->m01 * r2i->m01 + r1i->m11 * r2i->m11 + r1i->m21 * r2i->m21;
  ro->m12 = r1i->m01 * r2i->m02 + r1i->m11 * r2i->m12 + r1i->m21 * r2i->m22;
  ro->m20 = r1i->m02 * r2i->m00 + r1i->m12 * r2i->m10 + r1i->m22 * r2i->m20;
  ro->m21 = r1i->m02 * r2i->m01 + r1i->m12 * r2i->m11 + r1i->m22 * r2i->m21;
  ro->m22 = r1i->m02 * r2i->m02 + r1i->m12 * r2i->m12 + r1i->m22 * r2i->m22;
}

inline void ksl_product_drinvdrf(const ksl_mat3x3f_t* restrict r1i,
                                 const ksl_mat3x3f_t* restrict r2i,
                                 ksl_mat3x3f_t* restrict ro) {
  ro->m00 = r1i->m00 * r2i->m00 + r1i->m10 * r2i->m10 + r1i->m20 * r2i->m20;
  ro->m01 = r1i->m00 * r2i->m01 + r1i->m10 * r2i->m11 + r1i->m20 * r2i->m21;
  ro->m02 = r1i->m00 * r2i->m02 + r1i->m10 * r2i->m12 + r1i->m20 * r2i->m22;
  ro->m10 = r1i->m01 * r2i->m00 + r1i->m11 * r2i->m10 + r1i->m21 * r2i->m20;
  ro->m11 = r1i->m01 * r2i->m01 + r1i->m11 * r2i->m11 + r1i->m21 * r2i->m21;
  ro->m12 = r1i->m01 * r2i->m02 + r1i->m11 * r2i->m12 + r1i->m21 * r2i->m22;
  ro->m20 = r1i->m02 * r2i->m00 + r1i->m12 * r2i->m10 + r1i->m22 * r2i->m20;
  ro->m21 = r1i->m02 * r2i->m01 + r1i->m12 * r2i->m11 + r1i->m22 * r2i->m21;
  ro->m22 = r1i->m02 * r2i->m02 + r1i->m12 * r2i->m12 + r1i->m22 * r2i->m22;
}

inline void ksl_product_dv(const ksl_SE3_t* restrict Di,
                           const ksl_vec3_t* restrict vi,
                           ksl_vec3_t* restrict vo) {
  ksl_product_drv(&(Di->R), vi, vo);
  ksl_xpy_vv(&Di->t, vo);
}

inline void ksl_product_dinvv(const ksl_SE3_t* restrict Di,
                              const ksl_vec3_t* restrict vi,
                              ksl_vec3_t* restrict vo) {
  ksl_vec3_t temp;
  ksl_product_drinvv(&Di->R, &Di->t, &temp); /* R^-1 * t -> temp*/
  ksl_product_drinvv(&Di->R, vi, vo);        /* R^-1 * vi -> vo */
  ksl_nxpy_vv(&temp, vo);                    /* vo -= temp */
}

inline void ksl_product_ddrx(const ksl_SE3_t* restrict Di, const double dc[2],
                             ksl_SE3_t* restrict Do) {
  ksl_product_drdrx(&Di->R, dc, &Do->R);
  ksl_vec3_copy(&Di->t, &Do->t);
}

inline void ksl_product_ddrxf(const ksl_SE3f_t* restrict Di, const float dc[2],
                              ksl_SE3f_t* restrict Do) {
  ksl_product_drdrxf(&Di->R, dc, &Do->R);
  ksl_vec3f_copy(&Di->t, &Do->t);
}

inline void ksl_product_ddrxinv(const ksl_SE3_t* restrict Di,
                                const double dc[2], ksl_SE3_t* restrict Do) {
  ksl_product_drdrxinv(&Di->R, dc, &Do->R);
  ksl_vec3_copy(&Di->t, &Do->t);
}

inline void ksl_product_ddrxinvf(const ksl_SE3f_t* restrict Di,
                                 const float dc[2], ksl_SE3f_t* restrict Do) {
  ksl_product_drdrxinvf(&Di->R, dc, &Do->R);
  ksl_vec3f_copy(&Di->t, &Do->t);
}

inline void ksl_product_ddry(const ksl_SE3_t* restrict Di, const double dc[2],
                             ksl_SE3_t* restrict Do) {
  ksl_product_drdry(&Di->R, dc, &Do->R);
  ksl_vec3_copy(&Di->t, &Do->t);
}

inline void ksl_product_ddryf(const ksl_SE3f_t* restrict Di, const float dc[2],
                              ksl_SE3f_t* restrict Do) {
  ksl_product_drdryf(&Di->R, dc, &Do->R);
  ksl_vec3f_copy(&Di->t, &Do->t);
}

inline void ksl_product_ddryinv(const ksl_SE3_t* restrict Di,
                                const double dc[2], ksl_SE3_t* restrict Do) {
  ksl_product_drdryinv(&Di->R, dc, &Do->R);
  ksl_vec3_copy(&Di->t, &Do->t);
}

inline void ksl_product_ddryinvf(const ksl_SE3f_t* restrict Di,
                                 const float dc[2], ksl_SE3f_t* restrict Do) {
  ksl_product_drdryinvf(&Di->R, dc, &Do->R);
  ksl_vec3f_copy(&Di->t, &Do->t);
}

inline void ksl_product_ddrz(const ksl_SE3_t* restrict Di, const double dc[2],
                             ksl_SE3_t* restrict Do) {
  ksl_product_drdrz(&Di->R, dc, &Do->R);
  ksl_vec3_copy(&Di->t, &Do->t);
}

inline void ksl_product_ddrzf(const ksl_SE3f_t* restrict Di, const float dc[2],
                              ksl_SE3f_t* restrict Do) {
  ksl_product_drdrzf(&Di->R, dc, &Do->R);
  ksl_vec3f_copy(&Di->t, &Do->t);
}

inline void ksl_product_ddrzinv(const ksl_SE3_t* restrict Di,
                                const double dc[2], ksl_SE3_t* restrict Do) {
  ksl_product_drdrzinv(&Di->R, dc, &Do->R);
  ksl_vec3_copy(&Di->t, &Do->t);
}

inline void ksl_product_ddrzinvf(const ksl_SE3f_t* restrict Di,
                                 const float dc[2], ksl_SE3f_t* restrict Do) {
  ksl_product_drdrzinvf(&Di->R, dc, &Do->R);
  ksl_vec3f_copy(&Di->t, &Do->t);
}

inline void ksl_product_ddt(const ksl_SE3_t* restrict Di,
                            const ksl_vec3_t* restrict t,
                            ksl_SE3_t* restrict Do) {
  ksl_mat3x3_copy(&Di->R, &Do->R);
  ksl_product_drv(&Di->R, t, &Do->t);
  ksl_xpy_vv(&Di->t, &Do->t);
}

inline void ksl_product_ddtf(const ksl_SE3f_t* restrict Di,
                             const ksl_vec3f_t* restrict t,
                             ksl_SE3f_t* restrict Do) {
  ksl_mat3x3f_copy(&Di->R, &Do->R);
  ksl_product_drvf(&Di->R, t, &Do->t);
  ksl_xpy_vvf(&Di->t, &Do->t);
}

inline void ksl_product_ddtinv(const ksl_SE3_t* restrict Di,
                               const ksl_vec3_t* restrict t,
                               ksl_SE3_t* restrict Do) {
  ksl_mat3x3_copy(&Di->R, &Do->R);
  ksl_product_drvinv(&Di->R, t, &Do->t);
  ksl_xpy_vv(&Di->t, &Do->t);
}

inline void ksl_product_ddtinvf(const ksl_SE3f_t* restrict Di,
                                const ksl_vec3f_t* restrict t,
                                ksl_SE3f_t* restrict Do) {
  ksl_mat3x3f_copy(&Di->R, &Do->R);
  ksl_product_drvinvf(&Di->R, t, &Do->t);
  ksl_xpy_vvf(&Di->t, &Do->t);
}

inline void ksl_product_dinvdt(const ksl_SE3_t* restrict Di,
                               const ksl_vec3_t* restrict t,
                               ksl_SE3_t* restrict Do) {
  ksl_subtract_vv(t, &Di->t, &Do->t);
  ksl_mat3x3_transposed(&Di->R, &Do->R);
  ksl_product_drinvv(&Di->R, &Do->t, &Do->t);
}

inline void ksl_product_dinvdtf(const ksl_SE3f_t* restrict Di,
                                const ksl_vec3f_t* restrict t,
                                ksl_SE3f_t* restrict Do) {
  ksl_subtract_vvf(t, &Di->t, &Do->t);
  ksl_mat3x3f_transposed(&Di->R, &Do->R);
  ksl_product_drinvvf(&Di->R, &Do->t, &Do->t);
}

inline void ksl_product_ddtx(const ksl_SE3_t* restrict Di, const double ti,
                             ksl_SE3_t* restrict Do) {
  ksl_mat3x3_copy(&Di->R, &Do->R);
  ksl_product_drvtx(&Di->R, ti, &Do->t);
  ksl_xpy_vv(&Di->t, &Do->t);
}

inline void ksl_product_ddtxf(const ksl_SE3f_t* restrict Di, const float ti,
                              ksl_SE3f_t* restrict Do) {
  ksl_mat3x3f_copy(&Di->R, &Do->R);
  ksl_product_drvtxf(&Di->R, ti, &Do->t);
  ksl_xpy_vvf(&Di->t, &Do->t);
}

inline void ksl_product_ddtxinv(const ksl_SE3_t* restrict Di, const double ti,
                                ksl_SE3_t* restrict Do) {
  ksl_mat3x3_copy(&Di->R, &Do->R);
  ksl_product_drvtxinv(&Di->R, ti, &Do->t);
  ksl_xpy_vv(&Di->t, &Do->t);
}

inline void ksl_product_ddtxinvf(const ksl_SE3f_t* restrict Di, const float ti,
                                 ksl_SE3f_t* restrict Do) {
  ksl_mat3x3f_copy(&Di->R, &Do->R);
  ksl_product_drvtxinvf(&Di->R, ti, &Do->t);
  ksl_xpy_vvf(&Di->t, &Do->t);
}

inline void ksl_product_ddty(const ksl_SE3_t* restrict Di, const double ti,
                             ksl_SE3_t* restrict Do) {
  ksl_mat3x3_copy(&Di->R, &Do->R);
  ksl_product_drvty(&Di->R, ti, &Do->t);
  ksl_xpy_vv(&Di->t, &Do->t);
}

inline void ksl_product_ddtyf(const ksl_SE3f_t* restrict Di, const float ti,
                              ksl_SE3f_t* restrict Do) {
  ksl_mat3x3f_copy(&Di->R, &Do->R);
  ksl_product_drvtyf(&Di->R, ti, &Do->t);
  ksl_xpy_vvf(&Di->t, &Do->t);
}

inline void ksl_product_ddtyinv(const ksl_SE3_t* restrict Di, const double ti,
                                ksl_SE3_t* restrict Do) {
  ksl_mat3x3_copy(&Di->R, &Do->R);
  ksl_product_drvtyinv(&Di->R, ti, &Do->t);
  ksl_xpy_vv(&Di->t, &Do->t);
}

inline void ksl_product_ddtyinvf(const ksl_SE3f_t* restrict Di, const float ti,
                                 ksl_SE3f_t* restrict Do) {
  ksl_mat3x3f_copy(&Di->R, &Do->R);
  ksl_product_drvtyinvf(&Di->R, ti, &Do->t);
  ksl_xpy_vvf(&Di->t, &Do->t);
}

inline void ksl_product_ddtz(const ksl_SE3_t* restrict Di, const double ti,
                             ksl_SE3_t* restrict Do) {
  ksl_mat3x3_copy(&Di->R, &Do->R);
  ksl_product_drvtz(&Di->R, ti, &Do->t);
  ksl_xpy_vv(&Di->t, &Do->t);
}

inline void ksl_product_ddtzf(const ksl_SE3f_t* restrict Di, const float ti,
                              ksl_SE3f_t* restrict Do) {
  ksl_mat3x3f_copy(&Di->R, &Do->R);
  ksl_product_drvtzf(&Di->R, ti, &Do->t);
  ksl_xpy_vvf(&Di->t, &Do->t);
}

inline void ksl_product_ddtzinv(const ksl_SE3_t* restrict Di, const double ti,
                                ksl_SE3_t* restrict Do) {
  ksl_mat3x3_copy(&Di->R, &Do->R);
  ksl_product_drvtzinv(&Di->R, ti, &Do->t);
  ksl_xpy_vv(&Di->t, &Do->t);
}

inline void ksl_product_ddtzinvf(const ksl_SE3f_t* restrict Di, const float ti,
                                 ksl_SE3f_t* restrict Do) {
  ksl_mat3x3f_copy(&Di->R, &Do->R);
  ksl_product_drvtzinvf(&Di->R, ti, &Do->t);
  ksl_xpy_vvf(&Di->t, &Do->t);
}

inline void ksl_product_ddr(const ksl_SE3_t* restrict Di,
                            const ksl_mat3x3_t* restrict Ri,
                            ksl_SE3_t* restrict Do) {
  ksl_product_drdr(&Di->R, Ri, &Do->R);
  ksl_vec3_copy(&Di->t, &Do->t);
}

inline void ksl_product_ddrf(const ksl_SE3f_t* restrict Di,
                             const ksl_mat3x3f_t* restrict Ri,
                             ksl_SE3f_t* restrict Do) {
  ksl_product_drdrf(&Di->R, Ri, &Do->R);
  ksl_vec3f_copy(&Di->t, &Do->t);
}

inline void ksl_product_ddrinv(const ksl_SE3_t* restrict Di,
                               const ksl_mat3x3_t* restrict Ri,
                               ksl_SE3_t* restrict Do) {
  ksl_product_drdrinv(&Di->R, Ri, &Do->R);
  ksl_xpy_vv(&Di->t, &Do->t);
}

inline void ksl_product_ddrinvf(const ksl_SE3f_t* restrict Di,
                                const ksl_mat3x3f_t* restrict Ri,
                                ksl_SE3f_t* restrict Do) {
  ksl_product_drdrinvf(&Di->R, Ri, &Do->R);
  ksl_xpy_vvf(&Di->t, &Do->t);
}

inline void ksl_product_dd(const ksl_SE3_t* restrict D1i,
                           const ksl_SE3_t* restrict D2i,
                           ksl_SE3_t* restrict Do) {
  ksl_product_drdr(&D1i->R, &D2i->R, &Do->R);
  ksl_product_drv(&D1i->R, &D2i->t, &Do->t);
  ksl_xpy_vv(&D1i->t, &Do->t);
}

inline void ksl_product_ddf(const ksl_SE3f_t* restrict D1i,
                            const ksl_SE3f_t* restrict D2i,
                            ksl_SE3f_t* restrict Do) {
  ksl_product_drdrf(&D1i->R, &D2i->R, &Do->R);
  ksl_product_drvf(&D1i->R, &D2i->t, &Do->t);
  ksl_xpy_vvf(&D1i->t, &Do->t);
}

inline void ksl_product_ddinv(const ksl_SE3_t* restrict D1i,
                              const ksl_SE3_t* restrict D2i,
                              ksl_SE3_t* restrict Do) {
  ksl_product_drdrinv(&D1i->R, &D2i->R, &Do->R);
  ksl_product_drvinv(&Do->R, &D2i->t, &Do->t);
  ksl_xpy_vv(&D1i->t, &Do->t);
}

inline void ksl_product_ddinvf(const ksl_SE3f_t* D1i, const ksl_SE3f_t* D2i,
                               ksl_SE3f_t* Do) {
  ksl_product_drdrinvf(&D1i->R, &D2i->R, &Do->R);
  ksl_product_drvinvf(&Do->R, &D2i->t, &Do->t);
  ksl_xpy_vvf(&D1i->t, &Do->t);
}
