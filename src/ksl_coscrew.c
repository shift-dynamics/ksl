#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "ksl_coscrew.h"
#include "ksl_matrix.h"
#include "ksl_screw.h"
#include "ksl_vector.h"

ksl_coscrew_t ksl_coscrew(const double m0, const double m1, const double m2,
                          const double m3, const double m4, const double m5) {
  ksl_coscrew_t s;
  s.m0 = m0;
  s.m1 = m1;
  s.m2 = m2;
  s.m3 = m3;
  s.m4 = m4;
  s.m5 = m5;
  return s;
}

ksl_coscrewf_t ksl_coscrewf(const float m0, const float m1, const float m2,
                            const float m3, const float m4, const float m5) {
  ksl_coscrewf_t s;
  s.m0 = m0;
  s.m1 = m1;
  s.m2 = m2;
  s.m3 = m3;
  s.m4 = m4;
  s.m5 = m5;
  return s;
}

ksl_coscrew_t* ksl_coscrew_alloc(const int n) {
  return calloc(n, sizeof(ksl_coscrew_t));
}

ksl_coscrewf_t* ksl_coscrewf_alloc(const int n) {
  return calloc(n, sizeof(ksl_coscrewf_t));
}

inline double ksl_coscrew_norm(const ksl_coscrew_t* restrict v) {
  const double eps = 1e-9;
  if((fabs(v->lin.x) < eps) && (fabs(v->lin.y) < eps) &&
     (fabs(v->lin.z) < eps)) {
    return (ksl_vec3_l2norm(&v->ang));
  } else {
    return (ksl_vec3_l2norm(&v->lin));
  }
}

inline float ksl_coscrewf_norm(const ksl_coscrewf_t* restrict v) {
  const float eps = 1e-6;
  if((fabs(v->lin.x) < eps) && (fabs(v->lin.y) < eps) &&
     (fabs(v->lin.z) < eps)) {
    return (ksl_vec3f_l2norm(&v->ang));
  } else {
    return (ksl_vec3f_l2norm(&v->lin));
  }
}

inline void ksl_coscrew_normalize(ksl_coscrew_t* v) {
  const double eps = 1e-9;
  if((fabs(v->lin.x) < eps) && (fabs(v->lin.y) < eps) &&
     (fabs(v->lin.z) < eps)) {
    ksl_vec3_normalize(&v->ang);
  } else {
    double lin_inv_norm = 1.0 / ksl_vec3_l2norm(&v->lin);
    ksl_product_av(lin_inv_norm, &v->ang, &v->ang);
    ksl_product_av(lin_inv_norm, &v->lin, &v->lin);
  }
}

inline void ksl_coscrewf_normalize(ksl_coscrewf_t* v) {
  const float eps = 1e-6;
  if((fabs(v->lin.x) < eps) && (fabs(v->lin.y) < eps) &&
     (fabs(v->lin.z) < eps)) {
    ksl_vec3f_normalize(&v->ang);
  } else {
    float lin_inv_norm = 1.0 / ksl_vec3f_l2norm(&v->lin);
    ksl_product_avf(lin_inv_norm, &v->ang, &v->ang);
    ksl_product_avf(lin_inv_norm, &v->lin, &v->lin);
  }
}

void ksl_coscrew_scale(ksl_coscrew_t* restrict c, const double k) {
  for(int i = 0; i < 6; i++) {
    c->at[i] *= k;
  }
}

void ksl_coscrewf_scale(ksl_coscrewf_t* restrict c, const float k) {
  for(int i = 0; i < 6; i++) {
    c->at[i] *= k;
  }
}

inline void ksl_coscrew_copy(const ksl_coscrew_t* restrict ci,
                             ksl_coscrew_t* restrict co) {
  memcpy(co, ci, sizeof(ksl_coscrew_t));
}

inline void ksl_coscrewf_copy(const ksl_coscrewf_t* restrict ci,
                              ksl_coscrewf_t* restrict co) {
  memcpy(co, ci, sizeof(ksl_coscrewf_t));
}

inline void ksl_coscrew_invert(ksl_coscrew_t* restrict c) {
  for(int i = 0; i < 6; i++) {
    c->at[i] = -c->at[i];
  }
}

inline void ksl_coscrewf_invert(ksl_coscrewf_t* restrict c) {
  for(int i = 0; i < 6; i++) {
    c->at[i] = -c->at[i];
  }
}

inline void ksl_coscrew_inverted(const ksl_coscrew_t* restrict ci,
                                 ksl_coscrew_t* restrict co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] = -ci->at[i];
  }
}

inline void ksl_coscrewf_inverted(const ksl_coscrewf_t* restrict ci,
                                  ksl_coscrewf_t* restrict co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] = -ci->at[i];
  }
}

inline void ksl_axpy_cc(const double a, const ksl_coscrew_t* restrict x,
                        ksl_coscrew_t* restrict y) {
  for(int i = 0; i < 6; i++) {
    y->at[i] += a * x->at[i];
  }
}

inline void ksl_axpy_ccf(const float a, const ksl_coscrewf_t* restrict x,
                         ksl_coscrewf_t* restrict y) {
  for(int i = 0; i < 6; i++) {
    y->at[i] += a * x->at[i];
  }
}

inline void ksl_xpy_cc(const ksl_coscrew_t* restrict c1i,
                       ksl_coscrew_t* restrict co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] += c1i->at[i];
  }
}

inline void ksl_xpy_ccf(const ksl_coscrewf_t* restrict c1i,
                        ksl_coscrewf_t* restrict co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] += c1i->at[i];
  }
}

inline void ksl_nxpy_cc(const ksl_coscrew_t* restrict c1i,
                        ksl_coscrew_t* restrict co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] -= c1i->at[i];
  }
}

inline void ksl_nxpy_ccf(const ksl_coscrewf_t* restrict c1i,
                         ksl_coscrewf_t* restrict co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] -= c1i->at[i];
  }
}

inline void ksl_product_ac(const double k, const ksl_coscrew_t* restrict ci,
                           ksl_coscrew_t* restrict co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] = k * ci->at[i];
  }
}

inline void ksl_product_acf(const float k, const ksl_coscrewf_t* restrict ci,
                            ksl_coscrewf_t* restrict co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] = k * ci->at[i];
  }
}

inline void ksl_add_cc(const ksl_coscrew_t* restrict c1i,
                       const ksl_coscrew_t* restrict c2i,
                       ksl_coscrew_t* restrict co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] = c1i->at[i] + c2i->at[i];
  }
}

inline void ksl_add_ccf(const ksl_coscrewf_t* restrict c1i,
                        const ksl_coscrewf_t* restrict c2i,
                        ksl_coscrewf_t* restrict co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] = c1i->at[i] + c2i->at[i];
  }
}

inline void ksl_subtract_cc(const ksl_coscrew_t* restrict c1i,
                            const ksl_coscrew_t* restrict c2i,
                            ksl_coscrew_t* restrict co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] = c1i->at[i] - c2i->at[i];
  }
}

inline void ksl_subtract_ccf(const ksl_coscrewf_t* restrict c1i,
                             const ksl_coscrewf_t* restrict c2i,
                             ksl_coscrewf_t* restrict co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] = c1i->at[i] - c2i->at[i];
  }
}

inline void ksl_add_cct(const ksl_coscrew_t* restrict ci1,
                        const ksl_coscrew_t* restrict ci2,
                        ksl_coscrew_t* restrict co) {
  ksl_coscrew_t c;
  ksl_coscrew_copy(ci1, &c);
  c.at[0] += ci2->at[0];
  c.at[1] += ci2->at[1];
  c.at[2] += ci2->at[2];
  ksl_coscrew_copy(&c, co);
}

inline void ksl_add_cctf(const ksl_coscrewf_t* restrict ci1,
                         const ksl_coscrewf_t* restrict ci2,
                         ksl_coscrewf_t* restrict co) {
  ksl_coscrewf_t c;
  ksl_coscrewf_copy(ci1, &c);
  c.at[0] += ci2->at[0];
  c.at[1] += ci2->at[1];
  c.at[2] += ci2->at[2];
  ksl_coscrewf_copy(&c, co);
}

inline void ksl_hctx(const ksl_SE3_t* restrict Di,
                     ksl_coscrew_t* restrict hco) {
  ksl_vec3_copy(&Di->R.v0, &hco->lin);
  ksl_cross_vv(&Di->t, &hco->lin, &hco->ang);
  // memset(&hco->ang, 0, 3 * sizeof(double));
}

inline void ksl_hctxf(const ksl_SE3f_t* restrict Di,
                      ksl_coscrewf_t* restrict hco) {
  ksl_vec3f_copy(&Di->R.v0, &hco->lin);
  ksl_cross_vvf(&Di->t, &hco->lin, &hco->ang);
  // memset(&hco->ang, 0, 3 * sizeof(float));
}

inline void ksl_hcty(const ksl_SE3_t* restrict Di,
                     ksl_coscrew_t* restrict hco) {
  ksl_vec3_copy(&Di->R.v1, &hco->lin);
  ksl_cross_vv(&Di->t, &hco->lin, &hco->ang);
  // memset(&hco->ang, 0, 3 * sizeof(double));
}

inline void ksl_hctyf(const ksl_SE3f_t* restrict Di,
                      ksl_coscrewf_t* restrict hco) {
  ksl_vec3f_copy(&Di->R.v1, &hco->lin);
  ksl_cross_vvf(&Di->t, &hco->lin, &hco->ang);
  // memset(&hco->ang, 0, 3 * sizeof(float));
}

inline void ksl_hctz(const ksl_SE3_t* restrict Di,
                     ksl_coscrew_t* restrict hco) {
  ksl_vec3_copy(&Di->R.v2, &hco->lin);
  ksl_cross_vv(&Di->t, &hco->lin, &hco->ang);
  // memset(&hco->ang, 0, 3 * sizeof(double));
}

inline void ksl_hctzf(const ksl_SE3f_t* restrict Di,
                      ksl_coscrewf_t* restrict hco) {
  ksl_vec3f_copy(&Di->R.v2, &hco->lin);
  ksl_cross_vvf(&Di->t, &hco->lin, &hco->ang);
  // memset(&hco->ang, 0, 3 * sizeof(float));
}

inline void ksl_hcrx(const ksl_SE3_t* restrict Di,
                     ksl_coscrew_t* restrict hco) {
  memset(&hco->lin, 0, 3 * sizeof(double));
  ksl_vec3_copy(&Di->R.v0, &hco->ang);
  // ksl_cross_vv(&Di->t, &hco->ang, &hco->lin);
}

inline void ksl_hcrxf(const ksl_SE3f_t* restrict Di,
                      ksl_coscrewf_t* restrict hco) {
  memset(&hco->lin, 0, 3 * sizeof(float));
  ksl_vec3f_copy(&Di->R.v0, &hco->ang);
  // ksl_cross_vvf(&Di->t, &hco->ang, &hco->lin);
}

inline void ksl_hcry(const ksl_SE3_t* restrict Di,
                     ksl_coscrew_t* restrict hco) {
  memset(&hco->lin, 0, 3 * sizeof(double));
  ksl_vec3_copy(&Di->R.v1, &hco->ang);
  // ksl_cross_vv(&Di->t, &hco->ang, &hco->lin);
}

inline void ksl_hcryf(const ksl_SE3f_t* restrict Di,
                      ksl_coscrewf_t* restrict hco) {
  memset(&hco->lin, 0, 3 * sizeof(float));
  ksl_vec3f_copy(&Di->R.v1, &hco->ang);
  // ksl_cross_vvf(&Di->t, &hco->ang, &hco->lin);
}

inline void ksl_hcrz(const ksl_SE3_t* restrict Di,
                     ksl_coscrew_t* restrict hco) {
  memset(&hco->lin, 0, 3 * sizeof(double));
  ksl_vec3_copy(&Di->R.v2, &hco->ang);
  // ksl_cross_vv(&Di->t, &hco->ang, &hco->lin);
}

inline void ksl_hcrzf(const ksl_SE3f_t* restrict Di,
                      ksl_coscrewf_t* restrict hco) {
  memset(&hco->lin, 0, 3 * sizeof(float));
  ksl_vec3f_copy(&Di->R.v2, &hco->ang);
  // ksl_cross_vvf(&Di->t, &hco->ang, &hco->lin);
}

inline void ksl_hctxinv(const ksl_SE3_t* restrict Di,
                        ksl_coscrew_t* restrict hco) {
  ksl_vec3_inverted(&Di->R.v0, &hco->lin);
  ksl_cross_vv(&Di->t, &hco->lin, &hco->ang);
  // memset(&hco->ang, 0, 3 * sizeof(double));
}

inline void ksl_hctxinvf(const ksl_SE3f_t* restrict Di,
                         ksl_coscrewf_t* restrict hco) {
  ksl_vec3f_inverted(&Di->R.v0, &hco->lin);
  ksl_cross_vvf(&Di->t, &hco->lin, &hco->ang);
  // memset(&hco->ang, 0, 3 * sizeof(float));
}

inline void ksl_hctyinv(const ksl_SE3_t* restrict Di,
                        ksl_coscrew_t* restrict hco) {
  ksl_vec3_inverted(&Di->R.v1, &hco->lin);
  ksl_cross_vv(&Di->t, &hco->lin, &hco->ang);
  // memset(&hco->ang, 0, 3 * sizeof(double));
}

inline void ksl_hctyinvf(const ksl_SE3f_t* restrict Di,
                         ksl_coscrewf_t* restrict hco) {
  ksl_vec3f_inverted(&Di->R.v1, &hco->lin);
  ksl_cross_vvf(&Di->t, &hco->lin, &hco->ang);
  // memset(&hco->ang, 0, 3 * sizeof(float));
}

inline void ksl_hctzinv(const ksl_SE3_t* restrict Di,
                        ksl_coscrew_t* restrict hco) {
  ksl_vec3_inverted(&Di->R.v2, &hco->lin);
  ksl_cross_vv(&Di->t, &hco->lin, &hco->ang);
  // memset(&hco->ang, 0, 3 * sizeof(double));
}

inline void ksl_hctzinvf(const ksl_SE3f_t* restrict Di,
                         ksl_coscrewf_t* restrict hco) {
  ksl_vec3f_inverted(&Di->R.v2, &hco->lin);
  ksl_cross_vvf(&Di->t, &hco->lin, &hco->ang);
  // memset(&hco->ang, 0, 3 * sizeof(float));
}

inline void ksl_hcrxinv(const ksl_SE3_t* restrict Di,
                        ksl_coscrew_t* restrict hco) {
  memset(&hco->lin, 0, 3 * sizeof(double));
  ksl_vec3_inverted(&Di->R.v0, &hco->ang);
  // ksl_cross_vv(&Di->t, &hco->ang, &hco->lin);
}

inline void ksl_hcrxinvf(const ksl_SE3f_t* restrict Di,
                         ksl_coscrewf_t* restrict hco) {
  memset(&hco->lin, 0, 3 * sizeof(float));
  ksl_vec3f_inverted(&Di->R.v0, &hco->ang);
  // ksl_cross_vvf(&Di->t, &hco->ang, &hco->lin);
}

inline void ksl_hcryinv(const ksl_SE3_t* restrict Di,
                        ksl_coscrew_t* restrict hco) {
  memset(&hco->lin, 0, 3 * sizeof(double));
  ksl_vec3_inverted(&Di->R.v1, &hco->ang);
  // ksl_cross_vv(&Di->t, &hco->ang, &hco->lin);
}

inline void ksl_hcryinvf(const ksl_SE3f_t* restrict Di,
                         ksl_coscrewf_t* restrict hco) {
  memset(&hco->lin, 0, 3 * sizeof(float));
  ksl_vec3f_inverted(&Di->R.v1, &hco->ang);
  // ksl_cross_vvf(&Di->t, &hco->ang, &hco->lin);
}

inline void ksl_hcrzinv(const ksl_SE3_t* restrict Di,
                        ksl_coscrew_t* restrict hco) {
  memset(&hco->lin, 0, 3 * sizeof(double));
  ksl_vec3_inverted(&Di->R.v2, &hco->ang);
  // ksl_cross_vv(&Di->t, &hco->ang, &hco->lin);
}

inline void ksl_hcrzinvf(const ksl_SE3f_t* restrict Di,
                         ksl_coscrewf_t* restrict hco) {
  memset(&hco->lin, 0, 3 * sizeof(float));
  ksl_vec3f_inverted(&Di->R.v2, &hco->ang);
  // ksl_cross_vvf(&Di->t, &hco->ang, &hco->lin);
}

inline void ksl_cross_sc(const ksl_screw_t* restrict s1i,
                         const ksl_coscrew_t* restrict c2i,
                         ksl_coscrew_t* restrict co) {

  ksl_coscrew_t c;

  /* c.lin <- s1i->ang x c2i->lin */
  ksl_cross_vv(&s1i->ang, &c2i->lin, &c.lin);

  /* c.ang <- s1i->ang x c2i->ang */
  ksl_cross_vv(&s1i->ang, &c2i->ang, &c.ang);

  /* c.ang += s1i->lin x c2i->lin */
  c.m3 += s1i->m1 * c2i->m2 - s1i->m2 * c2i->m1;
  c.m4 += s1i->m2 * c2i->m0 - s1i->m0 * c2i->m2;
  c.m5 += s1i->m0 * c2i->m1 - s1i->m1 * c2i->m0;

  ksl_coscrew_copy(&c, co);
}

inline void ksl_cross_scf(const ksl_screwf_t* restrict s1i,
                          const ksl_coscrewf_t* restrict c2i,
                          ksl_coscrewf_t* restrict co) {

  ksl_coscrewf_t c;

  /* c.lin <- s1i->ang x c2i->lin */
  ksl_cross_vvf(&s1i->ang, &c2i->lin, &c.lin);

  /* c.ang <- s1i->ang x c2i->ang */
  ksl_cross_vvf(&s1i->ang, &c2i->ang, &c.ang);

  /* c.ang += s1i->lin x c2i->lin */
  c.m3 += s1i->m1 * c2i->m2 - s1i->m2 * c2i->m1;
  c.m4 += s1i->m2 * c2i->m0 - s1i->m0 * c2i->m2;
  c.m5 += s1i->m0 * c2i->m1 - s1i->m1 * c2i->m0;

  ksl_coscrewf_copy(&c, co);
}

inline void ksl_cross_sca(const ksl_screw_t* restrict s1i,
                          const ksl_coscrew_t* restrict c2i,
                          ksl_coscrew_t* restrict co) {
  memset(&co->lin, 0, sizeof(ksl_vec3_t));
  ksl_cross_vv(&s1i->ang, &c2i->ang, &co->ang);
}

inline void ksl_cross_scaf(const ksl_screwf_t* restrict s1i,
                           const ksl_coscrewf_t* restrict c2i,
                           ksl_coscrewf_t* restrict co) {
  memset(&co->lin, 0, sizeof(ksl_vec3f_t));
  ksl_cross_vvf(&s1i->ang, &c2i->ang, &co->ang);
}

inline void ksl_product_CoAdrc(const ksl_mat3x3_t* restrict ri,
                               const ksl_coscrew_t* restrict ci,
                               ksl_coscrew_t* restrict co) {

  ksl_product_drv(ri, &ci->lin, &co->lin);
  ksl_product_drv(ri, &ci->ang, &co->ang);
}

inline void ksl_product_CoAdrcf(const ksl_mat3x3f_t* restrict ri,
                                const ksl_coscrewf_t* restrict ci,
                                ksl_coscrewf_t* restrict co) {

  ksl_product_drvf(ri, &ci->lin, &co->lin);
  ksl_product_drvf(ri, &ci->ang, &co->ang);
}

void ksl_product_CoAdrcinv(const ksl_mat3x3_t* restrict ri,
                           const ksl_coscrew_t* restrict ci,
                           ksl_coscrew_t* restrict co) {

  ksl_product_drvinv(ri, &ci->lin, &co->lin);
  ksl_product_drvinv(ri, &ci->ang, &co->ang);
}

void ksl_product_CoAdrcinvf(const ksl_mat3x3f_t* restrict ri,
                            const ksl_coscrewf_t* restrict ci,
                            ksl_coscrewf_t* restrict co) {
  ksl_product_drvinvf(ri, &ci->lin, &co->lin);
  ksl_product_drvinvf(ri, &ci->ang, &co->ang);
}

void ksl_product_CoAdrinvc(const ksl_mat3x3_t* restrict ri,
                           const ksl_coscrew_t* restrict ci,
                           ksl_coscrew_t* restrict co) {
  ksl_product_drinvv(ri, &ci->lin, &co->lin);
  ksl_product_drinvv(ri, &ci->ang, &co->ang);
}

void ksl_product_CoAdrinvcf(const ksl_mat3x3f_t* restrict ri,
                            const ksl_coscrewf_t* restrict ci,
                            ksl_coscrewf_t* restrict co) {
  ksl_product_drinvvf(ri, &ci->lin, &co->lin);
  ksl_product_drinvvf(ri, &ci->ang, &co->ang);
}

inline void ksl_product_CoAdtc(const ksl_vec3_t* restrict ti,
                               const ksl_coscrew_t* restrict ci,
                               ksl_coscrew_t* restrict co) {
  ksl_coscrew_copy(ci, co);

  /* \tauo += ti x f2i */
  co->m3 += ti->y * ci->m2 - ti->z * ci->m1;
  co->m4 += ti->z * ci->m0 - ti->x * ci->m2;
  co->m5 += ti->x * ci->m1 - ti->y * ci->m0;
}

inline void ksl_product_CoAdtcf(const ksl_vec3f_t* restrict ti,
                                const ksl_coscrewf_t* restrict ci,
                                ksl_coscrewf_t* restrict co) {
  ksl_coscrewf_copy(ci, co);

  /* \tauo += ti x f2i */
  co->m3 += ti->y * ci->m2 - ti->z * ci->m1;
  co->m4 += ti->z * ci->m0 - ti->x * ci->m2;
  co->m5 += ti->x * ci->m1 - ti->y * ci->m0;
}

inline void ksl_product_CoAdtinvc(const ksl_vec3_t* restrict ti,
                                  const ksl_coscrew_t* restrict ci,
                                  ksl_coscrew_t* restrict co) {
  ksl_coscrew_copy(ci, co);

  /* \tauo -= ti x f2i */
  co->m3 -= ti->y * ci->m2 - ti->z * ci->m1;
  co->m4 -= ti->z * ci->m0 - ti->x * ci->m2;
  co->m5 -= ti->x * ci->m1 - ti->y * ci->m0;
}

inline void ksl_product_CoAdtinvcf(const ksl_vec3f_t* restrict ti,
                                   const ksl_coscrewf_t* restrict ci,
                                   ksl_coscrewf_t* restrict co) {
  ksl_coscrewf_copy(ci, co);

  /* \tauo -= ti x f2i */
  co->m3 -= ti->y * ci->m2 - ti->z * ci->m1;
  co->m4 -= ti->z * ci->m0 - ti->x * ci->m2;
  co->m5 -= ti->x * ci->m1 - ti->y * ci->m0;
}

inline void ksl_product_CoAdtcinv(const ksl_vec3_t* restrict ti,
                                  const ksl_coscrew_t* restrict ci,
                                  ksl_coscrew_t* restrict co) {
  ksl_coscrew_inverted(ci, co);

  /* \tauo += ti x f2i */
  co->m3 += ti->y * co->m2 - ti->z * co->m1;
  co->m4 += ti->z * co->m0 - ti->x * co->m2;
  co->m5 += ti->x * co->m1 - ti->y * co->m0;
}

inline void ksl_product_CoAdtcinvf(const ksl_vec3f_t* restrict ti,
                                   const ksl_coscrewf_t* restrict ci,
                                   ksl_coscrewf_t* restrict co) {
  ksl_coscrewf_inverted(ci, co);

  /* \tauo += ti x f2i */
  co->m3 += ti->y * co->m2 - ti->z * co->m1;
  co->m4 += ti->z * co->m0 - ti->x * co->m2;
  co->m5 += ti->x * co->m1 - ti->y * co->m0;
}

inline void ksl_product_CoAdc(const ksl_SE3_t* restrict Di,
                              const ksl_coscrew_t* restrict ci,
                              ksl_coscrew_t* restrict co) {

  ksl_product_CoAdrc(&Di->R, ci, co);

  co->m3 += Di->t.y * co->m2 - Di->t.z * co->m1;
  co->m4 += Di->t.z * co->m0 - Di->t.x * co->m2;
  co->m5 += Di->t.x * co->m1 - Di->t.y * co->m0;
}

inline void ksl_product_CoAdcf(const ksl_SE3f_t* restrict Di,
                               const ksl_coscrewf_t* restrict ci,
                               ksl_coscrewf_t* restrict co) {

  ksl_product_CoAdrcf(&Di->R, ci, co);

  co->m3 += Di->t.y * co->m2 - Di->t.z * co->m1;
  co->m4 += Di->t.z * co->m0 - Di->t.x * co->m2;
  co->m5 += Di->t.x * co->m1 - Di->t.y * co->m0;
}

inline void ksl_product_CoAdcinv(const ksl_SE3_t* restrict Di,
                                 const ksl_coscrew_t* restrict ci,
                                 ksl_coscrew_t* restrict co) {
  ksl_product_CoAdrcinv(&(Di->R), ci, co);
  /* \tauo += ti x f2i */
  co->m3 += Di->t.y * co->m2 - Di->t.z * co->m1;
  co->m4 += Di->t.z * co->m0 - Di->t.x * co->m2;
  co->m5 += Di->t.x * co->m1 - Di->t.y * co->m0;
}

inline void ksl_product_CoAdcinvf(const ksl_SE3f_t* restrict Di,
                                  const ksl_coscrewf_t* restrict ci,
                                  ksl_coscrewf_t* restrict co) {
  ksl_product_CoAdrcinvf(&(Di->R), ci, co);
  /* \tauo += ti x f2i */
  co->m3 += Di->t.y * co->m2 - Di->t.z * co->m1;
  co->m4 += Di->t.z * co->m0 - Di->t.x * co->m2;
  co->m5 += Di->t.x * co->m1 - Di->t.y * co->m0;
}

inline void ksl_product_CoAdinvc(const ksl_SE3_t* restrict Di,
                                 const ksl_coscrew_t* restrict ci,
                                 ksl_coscrew_t* restrict co) {
  ksl_coscrew_t temp;
  ksl_coscrew_copy(ci, &temp);

  temp.m3 -= Di->t.y * temp.m2 - Di->t.z * temp.m1;
  temp.m4 -= Di->t.z * temp.m0 - Di->t.x * temp.m2;
  temp.m5 -= Di->t.x * temp.m1 - Di->t.y * temp.m0;

  ksl_product_CoAdrinvc(&Di->R, &temp, co);
}

inline void ksl_product_CoAdinvcf(const ksl_SE3f_t* restrict Di,
                                  const ksl_coscrewf_t* restrict ci,
                                  ksl_coscrewf_t* restrict co) {
  ksl_coscrewf_t temp;
  ksl_coscrewf_copy(ci, &temp);

  temp.m3 -= Di->t.y * temp.m2 - Di->t.z * temp.m1;
  temp.m4 -= Di->t.z * temp.m0 - Di->t.x * temp.m2;
  temp.m5 -= Di->t.x * temp.m1 - Di->t.y * temp.m0;

  ksl_product_CoAdrinvcf(&Di->R, &temp, co);
}
