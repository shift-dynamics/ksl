#include <assert.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include "ksl/SE3.h"
#include "ksl/mat4x4.h"
#include "ksl/matrix.h"

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

inline void ksl_SE3_toMat4x4(const ksl_SE3_t* restrict d,
                             ksl_mat4x4_t* restrict m) {
  memset(m, 0, sizeof(ksl_mat4x4_t));
  for(int i = 0; i < 4; i++) {   /* column index */
    for(int j = 0; j < 3; j++) { /* row index */
      m->at[i][j] = d->at[i][j];
    }
  }
  m->at[3][3] = 1.0;
}

inline void ksl_SE3f_toMat4x4f(const ksl_SE3f_t* restrict d,
                               ksl_mat4x4f_t* restrict m) {
  memset(m, 0, sizeof(ksl_mat4x4f_t));
  for(int i = 0; i < 4; i++) {   /* column index */
    for(int j = 0; j < 3; j++) { /* row index */
      m->at[i][j] = d->at[i][j];
    }
  }
  m->at[3][3] = 1.0;
}

inline void ksl_SE3_toMat4x4f(const ksl_SE3_t* d, ksl_mat4x4f_t* restrict m) {
  memset(m, 0, sizeof(ksl_mat4x4f_t));
  for(int i = 0; i < 4; i++) {   /* column index */
    for(int j = 0; j < 3; j++) { /* row index */
      m->at[i][j] = d->at[i][j];
    }
  }
  m->at[3][3] = 1.f;
}

inline void ksl_SE3_setIdentity(ksl_SE3_t* restrict d) {
  memset(d, 0, sizeof(ksl_SE3_t));
  for(int i = 0; i < 3; i++) {
    d->at[i][i] = 1.0;
  }
}

inline void ksl_SE3f_setIdentity(ksl_SE3f_t* restrict d) {
  memset(d, 0, sizeof(ksl_SE3f_t));
  for(int i = 0; i < 3; i++) {
    d->at[i][i] = 1.f;
  }
}

inline void ksl_SE3_set(ksl_SE3_t* restrict D, const int row, const int column,
                        const double value) {
  assert(row < 3 && column < 4);
  D->at[column][row] = value;
}

inline void ksl_SE3f_set(ksl_SE3f_t* D, int row, int column, float value) {
  assert(row < 3 && column < 4);
  D->at[column][row] = value;
}

inline double ksl_SE3_get(const ksl_SE3_t* restrict D, const int row,
                          const int column) {
  assert(row < 3 && column < 4);
  return D->at[column][row];
}

inline float ksl_SE3f_get(const ksl_SE3f_t* restrict D, const int row,
                          const int column) {
  assert(row < 3 && column < 4);
  return D->at[column][row];
}

inline void ksl_SE3_getTranslation(const ksl_SE3_t* restrict D,
                                   ksl_vec3_t* restrict t) {
  memcpy(t, &D->t, sizeof(ksl_vec3_t));
}

inline void ksl_SE3f_getTranslation(const ksl_SE3f_t* restrict D,
                                    ksl_vec3f_t* restrict t) {
  memcpy(t, &D->t, sizeof(ksl_vec3f_t));
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
