#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "ksl/SE3.h"
#include "ksl/mat3x3.h"
#include "ksl/mat4x4.h"
#include "ksl/vec3.h"
#include "ksl/vec4.h"

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

inline void ksl_mat4x4_setIdentity(ksl_mat4x4_t* M) {
  memset(M, 0, sizeof(ksl_mat4x4_t));
  for(int i = 0; i < 4; i++) {
    M->at[i][i] = 1.0;
  }
}

inline void ksl_mat4x4f_setIdentity(ksl_mat4x4f_t* M) {
  memset(M, 0, sizeof(ksl_mat4x4f_t));
  for(int i = 0; i < 4; i++) {
    M->at[i][i] = 1.0;
  }
}

inline void ksl_mat4x4_set(ksl_mat4x4_t* restrict M, const int row,
                           const int column, const double value) {
  assert(row < 4 && column < 4);
  M->at[column][row] = value;
}

inline void ksl_mat4x4f_set(ksl_mat4x4f_t* restrict M, int row, int column,
                            float value) {
  assert(row < 4 && column < 4);
  M->at[column][row] = value;
}

inline double ksl_mat4x4_get(const ksl_mat4x4_t* restrict R, const int row,
                             const int column) {
  assert(row < 4 && column < 4);
  return R->at[column][row];
}

inline float ksl_mat4x4f_get(const ksl_mat4x4f_t* restrict R, const int row,
                             const int column) {
  assert(row < 4 && column < 4);
  return R->at[column][row];
}

inline void ksl_mat4x4_getTranslation(const ksl_mat4x4_t* restrict Mi,
                                      ksl_vec3_t* restrict to) {
  memcpy(to, &Mi->v3, sizeof(ksl_vec3_t));
}

inline void ksl_mat4x4f_getTranslation(const ksl_mat4x4f_t* restrict Mi,
                                       ksl_vec3f_t* to) {
  memcpy(to, &Mi->v3, sizeof(ksl_vec3f_t));
}
