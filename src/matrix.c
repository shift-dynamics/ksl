#include <assert.h>
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

/*!@todo */
inline void ksl_mat3x3_invert(ksl_mat3x3_t* restrict R);

/*!@todo */
inline void ksl_mat3x3f_invert(ksl_mat3x3_t* restrict R);

/*!@todo */
inline void ksl_mat3x3_inverted(const ksl_mat3x3_t* restrict ri,
                                ksl_mat3x3_t* restrict ro);

/*!@todo */
inline void ksl_mat3x3f_inverted(const ksl_mat3x3_t* restrict ri,
                                 ksl_mat3x3_t* restrict ro);

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

/*! @todo */
inline void ksl_mat3x3_getEulerAngles(const ksl_mat3x3_t* rin,
                                      ksl_vec3_t* angles,
                                      const ksl_axis_enum_t axisType);

/*! @todo */
inline void ksl_mat3x3_setFromEulerAngles(ksl_mat3x3_t*, const ksl_vec3_t*,
                                          const ksl_axis_enum_t axisType);

/*! @todo */
double ksl_mat3x3_getScalar(const ksl_mat3x3_t* restrict ri);

/*! @todo */
float ksl_mat3x3f_getScalar(const ksl_mat3x3f_t* restrict ri);

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
