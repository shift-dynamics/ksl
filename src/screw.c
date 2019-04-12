#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "ksl/SE3.h"
#include "ksl/coscrew.h"
#include "ksl/matrix.h"
#include "ksl/screw.h"
#include "ksl/vec3.h"

ksl_screw_t ksl_screw(const double m0, const double m1, const double m2,
                      const double m3, const double m4, const double m5) {
  ksl_screw_t s;
  s.m0 = m0;
  s.m1 = m1;
  s.m2 = m2;
  s.m3 = m3;
  s.m4 = m4;
  s.m5 = m5;
  return s;
}

ksl_screwf_t ksl_screwf(const float m0, const float m1, const float m2,
                        const float m3, const float m4, const float m5) {
  ksl_screwf_t s;
  s.m0 = m0;
  s.m1 = m1;
  s.m2 = m2;
  s.m3 = m3;
  s.m4 = m4;
  s.m5 = m5;
  return s;
}

ksl_screw_t* ksl_screw_alloc(const int n) {
  return calloc(n, sizeof(ksl_screw_t));
}

ksl_screwf_t* ksl_screwf_alloc(const int n) {
  return calloc(n, sizeof(ksl_screwf_t));
}

inline double ksl_screw_norm(const ksl_screw_t* restrict s) {
  const double eps = 1e-9;
  if((fabs(s->ang.x) < eps) && (fabs(s->ang.y) < eps) &&
     (fabs(s->ang.z) < eps)) {
    return (ksl_vec3_l2norm(&s->lin));
  } else {
    return (ksl_vec3_l2norm(&s->ang));
  }
}

inline float ksl_screwf_norm(const ksl_screwf_t* restrict s) {
  const float eps = 1e-6;
  if((fabs(s->ang.x) < eps) && (fabs(s->ang.y) < eps) &&
     (fabs(s->ang.z) < eps)) {
    return (ksl_vec3f_l2norm(&s->lin));
  } else {
    return (ksl_vec3f_l2norm(&s->ang));
  }
}

inline void ksl_screw_normalize(ksl_screw_t* s) {
  const double eps = 1e-9;
  if((fabs(s->ang.x) < eps) && (fabs(s->ang.y) < eps) &&
     (fabs(s->ang.z) < eps)) {
    ksl_vec3_normalize(&s->lin);
  } else {
    double ang_inv_norm = 1.0 / ksl_vec3_l2norm(&s->ang);
    ksl_product_av(ang_inv_norm, &s->lin, &s->lin);
    ksl_product_av(ang_inv_norm, &s->ang, &s->ang);
  }
}

inline void ksl_screwf_normalize(ksl_screwf_t* s) {
  const float eps = 1e-6;
  if((fabs(s->ang.x) < eps) && (fabs(s->ang.y) < eps) &&
     (fabs(s->ang.z) < eps)) {
    ksl_vec3f_normalize(&s->lin);
  } else {
    float ang_inv_norm = 1.0 / ksl_vec3f_l2norm(&s->ang);
    ksl_product_avf(ang_inv_norm, &s->lin, &s->lin);
    ksl_product_avf(ang_inv_norm, &s->ang, &s->ang);
  }
}

inline double ksl_dot_cs(const ksl_coscrew_t* restrict ci,
                         const ksl_screw_t* restrict si) {
  register double sum = 0;
  for(int i = 0; i < 6; i++) {
    sum += ci->at[i] * si->at[i];
  }
  return sum;
}

inline float ksl_dot_csf(const ksl_coscrewf_t* restrict ci,
                         const ksl_screwf_t* restrict si) {
  register float sum = 0;
  for(int i = 0; i < 6; i++) {
    sum += ci->at[i] * si->at[i];
  }
  return sum;
}

void ksl_screw_scale(ksl_screw_t* restrict s, const double k) {
  for(int i = 0; i < 6; i++) {
    s->at[i] *= k;
  }
}

void ksl_screwf_scale(ksl_screwf_t* restrict s, const float k) {
  for(int i = 0; i < 6; i++) {
    s->at[i] *= k;
  }
}

inline void ksl_screw_copy(const ksl_screw_t* restrict si,
                           ksl_screw_t* restrict so) {
  memcpy(so, si, sizeof(ksl_screw_t));
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

void ksl_screw_copy_cmo(const ksl_screw_t* si, double* A, int row, int column,
                        int stride) {
  memcpy(A + (column * stride) + row, si, sizeof(ksl_screw_t));
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

inline void ksl_screwf_copy(const ksl_screwf_t* restrict si,
                            ksl_screwf_t* restrict so) {
  memcpy(so, si, sizeof(ksl_screwf_t));
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

void ksl_screwf_copy_cmo(const ksl_screwf_t* si, float* A, int row, int column,
                         int stride) {
  memcpy(A + (column * stride) + row, si, sizeof(ksl_screwf_t));
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

inline void ksl_screw_invert(ksl_screw_t* restrict s) {
  for(int i = 0; i < 6; i++) {
    s->at[i] = -s->at[i];
  }
}

inline void ksl_screwf_invert(ksl_screwf_t* restrict s) {
  for(int i = 0; i < 6; i++) {
    s->at[i] = -s->at[i];
  }
}

inline void ksl_screw_inverted(const ksl_screw_t* restrict si,
                               ksl_screw_t* restrict so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] = -si->at[i];
  }
}

inline void ksl_screwf_inverted(const ksl_screwf_t* restrict si,
                                ksl_screwf_t* restrict so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] = -si->at[i];
  }
}

inline void ksl_axpy_ss(const double a, const ksl_screw_t* restrict x,
                        ksl_screw_t* restrict y) {
  for(int i = 0; i < 6; i++) {
    y->at[i] += a * x->at[i];
  }
}

inline void ksl_axpy_ssf(const float a, const ksl_screwf_t* restrict x,
                         ksl_screwf_t* restrict y) {
  for(int i = 0; i < 6; i++) {
    y->at[i] += a * x->at[i];
  }
}

inline void ksl_xpy_ss(const ksl_screw_t* restrict s1i,
                       ksl_screw_t* restrict so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] += s1i->at[i];
  }
}

inline void ksl_xpy_ssf(const ksl_screwf_t* restrict s1i,
                        ksl_screwf_t* restrict so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] += s1i->at[i];
  }
}

inline void ksl_nxpy_ss(const ksl_screw_t* restrict s1i,
                        ksl_screw_t* restrict so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] -= s1i->at[i];
  }
}

inline void ksl_nxpy_ssf(const ksl_screwf_t* restrict s1i,
                         ksl_screwf_t* restrict so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] -= s1i->at[i];
  }
}

inline void ksl_product_as(const double k, const ksl_screw_t* restrict si,
                           ksl_screw_t* restrict so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] = k * si->at[i];
  }
}

inline void ksl_product_asf(const float k, const ksl_screwf_t* restrict si,
                            ksl_screwf_t* restrict so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] = k * si->at[i];
  }
}

inline void ksl_add_ss(const ksl_screw_t* restrict s1i,
                       const ksl_screw_t* restrict s2i,
                       ksl_screw_t* restrict so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] = s1i->at[i] + s2i->at[i];
  }
}

inline void ksl_add_ssf(const ksl_screwf_t* restrict s1i,
                        const ksl_screwf_t* restrict s2i,
                        ksl_screwf_t* restrict so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] = s1i->at[i] + s2i->at[i];
  }
}

inline void ksl_subtract_ss(const ksl_screw_t* restrict s1i,
                            const ksl_screw_t* restrict s2i,
                            ksl_screw_t* restrict so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] = s1i->at[i] - s2i->at[i];
  }
}

inline void ksl_subtract_ssf(const ksl_screwf_t* restrict s1i,
                             const ksl_screwf_t* restrict s2i,
                             ksl_screwf_t* restrict so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] = s1i->at[i] - s2i->at[i];
  }
}

inline void ksl_add_sst(const ksl_screw_t* restrict si1,
                        const ksl_screw_t* restrict si2,
                        ksl_screw_t* restrict so) {
  ksl_screw_t s;
  ksl_screw_copy(si1, &s);
  s.at[0] += si2->at[0];
  s.at[1] += si2->at[1];
  s.at[2] += si2->at[2];
  ksl_screw_copy(&s, so);
}

inline void ksl_add_sstf(const ksl_screwf_t* restrict si1,
                         const ksl_screwf_t* restrict si2,
                         ksl_screwf_t* restrict so) {
  ksl_screwf_t s;
  ksl_screwf_copy(si1, &s);
  s.at[0] += si2->at[0];
  s.at[1] += si2->at[1];
  s.at[2] += si2->at[2];
  ksl_screwf_copy(&s, so);
}

inline void ksl_hstx(const ksl_SE3_t* restrict Di, ksl_screw_t* restrict hso) {
  ksl_vec3_copy(&Di->R.v0, &hso->lin);
  memset(&hso->ang, 0, 3 * sizeof(double));
}

inline void ksl_hstxf(const ksl_SE3f_t* restrict Di,
                      ksl_screwf_t* restrict hso) {
  ksl_vec3f_copy(&Di->R.v0, &hso->lin);
  memset(&hso->ang, 0, 3 * sizeof(float));
}

inline void ksl_hsty(const ksl_SE3_t* restrict Di, ksl_screw_t* restrict hso) {
  ksl_vec3_copy(&Di->R.v1, &hso->lin);
  memset(&hso->ang, 0, 3 * sizeof(double));
}

inline void ksl_hstyf(const ksl_SE3f_t* restrict Di,
                      ksl_screwf_t* restrict hso) {
  ksl_vec3f_copy(&Di->R.v1, &hso->lin);
  memset(&hso->ang, 0, 3 * sizeof(float));
}

inline void ksl_hstz(const ksl_SE3_t* restrict Di, ksl_screw_t* restrict hso) {
  ksl_vec3_copy(&Di->R.v2, &hso->lin);
  memset(&hso->ang, 0, 3 * sizeof(double));
}

inline void ksl_hstzf(const ksl_SE3f_t* restrict Di,
                      ksl_screwf_t* restrict hso) {
  ksl_vec3f_copy(&Di->R.v2, &hso->lin);
  memset(&hso->ang, 0, 3 * sizeof(float));
}

inline void ksl_hsrx(const ksl_SE3_t* restrict Di, ksl_screw_t* restrict hso) {
  ksl_vec3_copy(&Di->R.v0, &hso->ang);
  ksl_cross_vv(&Di->t, &hso->ang, &hso->lin);
}

inline void ksl_hsrxf(const ksl_SE3f_t* restrict Di,
                      ksl_screwf_t* restrict hso) {
  ksl_vec3f_copy(&Di->R.v0, &hso->ang);
  ksl_cross_vvf(&Di->t, &hso->ang, &hso->lin);
}

inline void ksl_hsry(const ksl_SE3_t* restrict Di, ksl_screw_t* restrict hso) {
  ksl_vec3_copy(&Di->R.v1, &hso->ang);
  ksl_cross_vv(&Di->t, &hso->ang, &hso->lin);
}

inline void ksl_hsryf(const ksl_SE3f_t* restrict Di,
                      ksl_screwf_t* restrict hso) {
  ksl_vec3f_copy(&Di->R.v1, &hso->ang);
  ksl_cross_vvf(&Di->t, &hso->ang, &hso->lin);
}

inline void ksl_hsrz(const ksl_SE3_t* restrict Di, ksl_screw_t* restrict hso) {
  ksl_vec3_copy(&Di->R.v2, &hso->ang);
  ksl_cross_vv(&Di->t, &hso->ang, &hso->lin);
}

inline void ksl_hsrzf(const ksl_SE3f_t* restrict Di,
                      ksl_screwf_t* restrict hso) {
  ksl_vec3f_copy(&Di->R.v2, &hso->ang);
  ksl_cross_vvf(&Di->t, &hso->ang, &hso->lin);
}

inline void ksl_hstxinv(const ksl_SE3_t* restrict Di,
                        ksl_screw_t* restrict hso) {
  ksl_vec3_inverted(&Di->R.v0, &hso->lin);
  memset(&hso->ang, 0, 3 * sizeof(double));
}

inline void ksl_hstxinvf(const ksl_SE3f_t* restrict Di,
                         ksl_screwf_t* restrict hso) {
  ksl_vec3f_inverted(&Di->R.v0, &hso->lin);
  memset(&hso->ang, 0, 3 * sizeof(float));
}

inline void ksl_hstyinv(const ksl_SE3_t* restrict Di,
                        ksl_screw_t* restrict hso) {
  ksl_vec3_inverted(&Di->R.v1, &hso->lin);
  memset(&hso->ang, 0, 3 * sizeof(double));
}

inline void ksl_hstyinvf(const ksl_SE3f_t* restrict Di,
                         ksl_screwf_t* restrict hso) {
  ksl_vec3f_inverted(&Di->R.v1, &hso->lin);
  memset(&hso->ang, 0, 3 * sizeof(float));
}

inline void ksl_hstzinv(const ksl_SE3_t* restrict Di,
                        ksl_screw_t* restrict hso) {
  ksl_vec3_inverted(&Di->R.v2, &hso->lin);
  memset(&hso->ang, 0, 3 * sizeof(double));
}

inline void ksl_hstzinvf(const ksl_SE3f_t* restrict Di,
                         ksl_screwf_t* restrict hso) {
  ksl_vec3f_inverted(&Di->R.v2, &hso->lin);
  memset(&hso->ang, 0, 3 * sizeof(float));
}

inline void ksl_hsrxinv(const ksl_SE3_t* restrict Di,
                        ksl_screw_t* restrict hso) {
  ksl_vec3_inverted(&Di->R.v0, &hso->ang);
  ksl_cross_vv(&Di->t, &hso->ang, &hso->lin);
}

inline void ksl_hsrxinvf(const ksl_SE3f_t* restrict Di,
                         ksl_screwf_t* restrict hso) {
  ksl_vec3f_inverted(&Di->R.v0, &hso->ang);
  ksl_cross_vvf(&Di->t, &hso->ang, &hso->lin);
}

inline void ksl_hsryinv(const ksl_SE3_t* restrict Di,
                        ksl_screw_t* restrict hso) {
  ksl_vec3_inverted(&Di->R.v1, &hso->ang);
  ksl_cross_vv(&Di->t, &hso->ang, &hso->lin);
}

inline void ksl_hsryinvf(const ksl_SE3f_t* restrict Di,
                         ksl_screwf_t* restrict hso) {
  ksl_vec3f_inverted(&Di->R.v1, &hso->ang);
  ksl_cross_vvf(&Di->t, &hso->ang, &hso->lin);
}

inline void ksl_hsrzinv(const ksl_SE3_t* restrict Di,
                        ksl_screw_t* restrict hso) {
  ksl_vec3_inverted(&Di->R.v2, &hso->ang);
  ksl_cross_vv(&Di->t, &hso->ang, &hso->lin);
}

inline void ksl_hsrzinvf(const ksl_SE3f_t* restrict Di,
                         ksl_screwf_t* restrict hso) {
  ksl_vec3f_inverted(&Di->R.v2, &hso->ang);
  ksl_cross_vvf(&Di->t, &hso->ang, &hso->lin);
}

inline void ksl_hsra(const ksl_SE3_t* restrict Di, const ksl_vec3_t* axis,
                     ksl_screw_t* restrict hso) {
  ksl_product_drv(&Di->R, axis, &hso->ang);
  ksl_cross_vv(&Di->t, &hso->ang, &hso->lin);
}

inline void ksl_hsrainv(const ksl_SE3_t* restrict Di, const ksl_vec3_t* axis,
                        ksl_screw_t* restrict hso) {
  ksl_product_drvinv(&Di->R, axis, &hso->ang);
  ksl_cross_vv(&Di->t, &hso->ang, &hso->lin);
}

inline void ksl_hsraf(const ksl_SE3f_t* restrict Di, const ksl_vec3f_t* axis,
                      ksl_screwf_t* restrict hso) {
  ksl_product_drvf(&Di->R, axis, &hso->ang);
  ksl_cross_vvf(&Di->t, &hso->ang, &hso->lin);
}

inline void ksl_hsrainvf(const ksl_SE3f_t* restrict Di, const ksl_vec3f_t* axis,
                         ksl_screwf_t* restrict hso) {
  ksl_product_drvinvf(&Di->R, axis, &hso->ang);
  ksl_cross_vvf(&Di->t, &hso->ang, &hso->lin);
}

inline void ksl_hsta(const ksl_SE3_t* restrict Di, const ksl_vec3_t* axis,
                     ksl_screw_t* restrict hso) {
  ksl_product_drv(&Di->R, axis, &hso->lin);
  memset(&hso->ang, 0, 3 * sizeof(double));
}

inline void ksl_hstainv(const ksl_SE3_t* restrict Di, const ksl_vec3_t* axis,
                        ksl_screw_t* restrict hso) {
  ksl_product_drvinv(&Di->R, axis, &hso->lin);
  memset(&hso->ang, 0, 3 * sizeof(double));
}

inline void ksl_hstaf(const ksl_SE3f_t* restrict Di, const ksl_vec3f_t* axis,
                      ksl_screwf_t* restrict hso) {
  ksl_product_drvf(&Di->R, axis, &hso->lin);
  memset(&hso->ang, 0, 3 * sizeof(float));
}

inline void ksl_hstainvf(const ksl_SE3f_t* restrict Di, const ksl_vec3f_t* axis,
                         ksl_screwf_t* restrict hso) {
  ksl_product_drvinvf(&Di->R, axis, &hso->lin);
  memset(&hso->ang, 0, 3 * sizeof(float));
}

inline void ksl_cross_ss(const ksl_screw_t* restrict s1i,
                         const ksl_screw_t* restrict s2i,
                         ksl_screw_t* restrict so) {

  ksl_screw_t s;

  /* s.lin <- s1i->ang x s2i->lin */
  ksl_cross_vv(&s1i->ang, &s2i->lin, &s.lin);

  /* s.ang <- s1i->ang x s2i->ang */
  ksl_cross_vv(&s1i->ang, &s2i->ang, &s.ang);

  /* s.lin += s1i->lin x s2i->ang */
  s.m0 += s1i->m1 * s2i->m5 - s1i->m2 * s2i->m4;
  s.m1 += s1i->m2 * s2i->m3 - s1i->m0 * s2i->m5;
  s.m2 += s1i->m0 * s2i->m4 - s1i->m1 * s2i->m3;

  ksl_screw_copy(&s, so);
}

inline void ksl_cross_ssf(const ksl_screwf_t* restrict s1i,
                          const ksl_screwf_t* restrict s2i,
                          ksl_screwf_t* restrict so) {

  ksl_screwf_t s;

  /* s.lin <- s1i->ang x s2i->lin */
  ksl_cross_vvf(&s1i->ang, &s2i->lin, &s.lin);

  /* s.ang <- s1i->ang x s2i->ang */
  ksl_cross_vvf(&s1i->ang, &s2i->ang, &s.ang);

  /* s.lin += s1i->lin x s2i->ang */
  s.m0 += s1i->m1 * s2i->m5 - s1i->m2 * s2i->m4;
  s.m1 += s1i->m2 * s2i->m3 - s1i->m0 * s2i->m5;
  s.m2 += s1i->m0 * s2i->m4 - s1i->m1 * s2i->m3;

  ksl_screwf_copy(&s, so);
}

inline void ksl_cross_sst(const ksl_screw_t* restrict s1i,
                          const ksl_screw_t* restrict s2i,
                          ksl_screw_t* restrict so) {
  ksl_cross_vv(&s1i->ang, &s2i->lin, &so->lin);
  memset(&so->ang, 0, sizeof(ksl_vec3_t));
}

inline void ksl_cross_sstf(const ksl_screwf_t* restrict s1i,
                           const ksl_screwf_t* restrict s2i,
                           ksl_screwf_t* restrict so) {
  ksl_cross_vvf(&s1i->ang, &s2i->lin, &so->lin);
  memset(&so->ang, 0, sizeof(ksl_vec3f_t));
}

inline void ksl_product_Adrs(const ksl_mat3x3_t* restrict ri,
                             const ksl_screw_t* restrict si,
                             ksl_screw_t* restrict so) {

  ksl_product_drv(ri, &si->lin, &so->lin);
  ksl_product_drv(ri, &si->ang, &so->ang);
}

inline void ksl_product_Adrsf(const ksl_mat3x3f_t* restrict ri,
                              const ksl_screwf_t* restrict si,
                              ksl_screwf_t* restrict so) {

  ksl_product_drvf(ri, &si->lin, &so->lin);
  ksl_product_drvf(ri, &si->ang, &so->ang);
}

void ksl_product_Adrsinv(const ksl_mat3x3_t* restrict ri,
                         const ksl_screw_t* restrict si,
                         ksl_screw_t* restrict so) {

  ksl_product_drvinv(ri, &si->lin, &so->lin);
  ksl_product_drvinv(ri, &si->ang, &so->ang);
}

void ksl_product_Adrsinvf(const ksl_mat3x3f_t* restrict ri,
                          const ksl_screwf_t* restrict si,
                          ksl_screwf_t* restrict so) {
  ksl_product_drvinvf(ri, &si->lin, &so->lin);
  ksl_product_drvinvf(ri, &si->ang, &so->ang);
}

void ksl_product_Adrinvs(const ksl_mat3x3_t* restrict ri,
                         const ksl_screw_t* restrict si,
                         ksl_screw_t* restrict so) {
  ksl_product_drinvv(ri, &si->lin, &so->lin);
  ksl_product_drinvv(ri, &si->ang, &so->ang);
}

void ksl_product_Adrinvsf(const ksl_mat3x3f_t* restrict ri,
                          const ksl_screwf_t* restrict si,
                          ksl_screwf_t* restrict so) {
  ksl_product_drinvvf(ri, &si->lin, &so->lin);
  ksl_product_drinvvf(ri, &si->ang, &so->ang);
}

inline void ksl_product_Adts(const ksl_vec3_t* restrict ti,
                             const ksl_screw_t* restrict si,
                             ksl_screw_t* restrict so) {
  ksl_screw_copy(si, so);

  /* vo += ti x w2i */
  so->m0 += ti->y * si->m5 - ti->z * si->m4;
  so->m1 += ti->z * si->m3 - ti->x * si->m5;
  so->m2 += ti->x * si->m4 - ti->y * si->m3;
}

inline void ksl_product_Adtsf(const ksl_vec3f_t* restrict ti,
                              const ksl_screwf_t* restrict si,
                              ksl_screwf_t* restrict so) {
  ksl_screwf_copy(si, so);

  /* vo += ti x w2i */
  so->m0 += ti->y * si->m5 - ti->z * si->m4;
  so->m1 += ti->z * si->m3 - ti->x * si->m5;
  so->m2 += ti->x * si->m4 - ti->y * si->m3;
}

inline void ksl_product_Adtinvs(const ksl_vec3_t* restrict ti,
                                const ksl_screw_t* restrict si,
                                ksl_screw_t* restrict so) {
  ksl_screw_copy(si, so);

  /* vo -= ti x w2i */
  so->m0 -= ti->y * si->m5 - ti->z * si->m4;
  so->m1 -= ti->z * si->m3 - ti->x * si->m5;
  so->m2 -= ti->x * si->m4 - ti->y * si->m3;
}

inline void ksl_product_Adtinvsf(const ksl_vec3f_t* restrict ti,
                                 const ksl_screwf_t* restrict si,
                                 ksl_screwf_t* restrict so) {
  ksl_screwf_copy(si, so);

  /* vo -= ti x w2i */
  so->m0 -= ti->y * si->m5 - ti->z * si->m4;
  so->m1 -= ti->z * si->m3 - ti->x * si->m5;
  so->m2 -= ti->x * si->m4 - ti->y * si->m3;
}

inline void ksl_product_Adtsinv(const ksl_vec3_t* restrict ti,
                                const ksl_screw_t* restrict si,
                                ksl_screw_t* restrict so) {
  ksl_screw_inverted(si, so);

  /* vo += ti x w2i */
  so->m0 += ti->y * so->m5 - ti->z * so->m4;
  so->m1 += ti->z * so->m3 - ti->x * so->m5;
  so->m2 += ti->x * so->m4 - ti->y * so->m3;
}

inline void ksl_product_Adtsinvf(const ksl_vec3f_t* restrict ti,
                                 const ksl_screwf_t* restrict si,
                                 ksl_screwf_t* restrict so) {
  ksl_screwf_inverted(si, so);

  /* vo += ti x w2i */
  so->m0 += ti->y * so->m5 - ti->z * so->m4;
  so->m1 += ti->z * so->m3 - ti->x * so->m5;
  so->m2 += ti->x * so->m4 - ti->y * so->m3;
}

inline void ksl_product_Ads(const ksl_SE3_t* restrict Di,
                            const ksl_screw_t* restrict si,
                            ksl_screw_t* restrict so) {

  ksl_product_Adrs(&Di->R, si, so);

  so->m0 += Di->t.y * so->m5 - Di->t.z * so->m4;
  so->m1 += Di->t.z * so->m3 - Di->t.x * so->m5;
  so->m2 += Di->t.x * so->m4 - Di->t.y * so->m3;
}

inline void ksl_product_Adsf(const ksl_SE3f_t* restrict Di,
                             const ksl_screwf_t* restrict si,
                             ksl_screwf_t* restrict so) {

  ksl_product_Adrsf(&Di->R, si, so);

  so->m0 += Di->t.y * so->m5 - Di->t.z * so->m4;
  so->m1 += Di->t.z * so->m3 - Di->t.x * so->m5;
  so->m2 += Di->t.x * so->m4 - Di->t.y * so->m3;
}

inline void ksl_product_Adsinv(const ksl_SE3_t* restrict Di,
                               const ksl_screw_t* restrict si,
                               ksl_screw_t* restrict so) {
  ksl_product_Adrsinv(&(Di->R), si, so);
  so->m0 += Di->t.y * so->m5 - Di->t.z * so->m4;
  so->m1 += Di->t.z * so->m3 - Di->t.x * so->m5;
  so->m2 += Di->t.x * so->m4 - Di->t.y * so->m3;
}

inline void ksl_product_Adsinvf(const ksl_SE3f_t* restrict Di,
                                const ksl_screwf_t* restrict si,
                                ksl_screwf_t* restrict so) {
  ksl_product_Adrsinvf(&(Di->R), si, so);
  so->m0 += Di->t.y * so->m5 - Di->t.z * so->m4;
  so->m1 += Di->t.z * so->m3 - Di->t.x * so->m5;
  so->m2 += Di->t.x * so->m4 - Di->t.y * so->m3;
}

inline void ksl_product_Adinvs(const ksl_SE3_t* restrict Di,
                               const ksl_screw_t* restrict si,
                               ksl_screw_t* restrict so) {
  ksl_screw_t temp;
  ksl_screw_copy(si, &temp);

  temp.m0 -= Di->t.y * temp.m5 - Di->t.z * temp.m4;
  temp.m1 -= Di->t.z * temp.m3 - Di->t.x * temp.m5;
  temp.m2 -= Di->t.x * temp.m4 - Di->t.y * temp.m3;

  ksl_product_Adrinvs(&Di->R, &temp, so);
}

inline void ksl_product_Adinvsf(const ksl_SE3f_t* restrict Di,
                                const ksl_screwf_t* restrict si,
                                ksl_screwf_t* restrict so) {
  ksl_screwf_t temp;
  ksl_screwf_copy(si, &temp);

  temp.m0 -= Di->t.y * temp.m5 - Di->t.z * temp.m4;
  temp.m1 -= Di->t.z * temp.m3 - Di->t.x * temp.m5;
  temp.m2 -= Di->t.x * temp.m4 - Di->t.y * temp.m3;

  ksl_product_Adrinvsf(&Di->R, &temp, so);
}
