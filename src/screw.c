#include <stdlib.h>
#include <string.h>

#include "coscrew.h"
#include "matrix.h"
#include "screw.h"

/*!
@brief allocate n double precision screw quantities
*/
ksl_screw_t* ksl_screw_alloc(const int n) {
  return calloc(n, sizeof(ksl_screw_t));
}

/*!
@brief allocate n single precision screw quantities
*/
ksl_screwf_t* ksl_screwf_alloc(const int n) {
  return calloc(n, sizeof(ksl_screwf_t));
}

/*!
@todo
*/
inline double ksl_screw_norm(const ksl_screw_t* restrict v);

/*!
@todo
*/
inline float ksl_screwf_norm(const ksl_screwf_t* restrict v);

/*!
@brief compute double precision dot product between a coscrew and screw
*/
inline double ksl_dot_cs(const ksl_coscrew_t* restrict ci,
                         const ksl_screw_t* restrict si) {
  register double sum = 0;
  for(int i = 0; i < 6; i++) {
    sum += ci->at[i] * si->at[i];
  }
  return sum;
}

/*!
@brief compute single precision dot product between a coscrew and screw
*/
inline float ksl_dot_csf(const ksl_coscrewf_t* restrict ci,
                         const ksl_screwf_t* restrict si) {
  register float sum = 0;
  for(int i = 0; i < 6; i++) {
    sum += ci->at[i] * si->at[i];
  }
  return sum;
}

/*!
@brief compute axpy (a * x + y \rightarrow y) operation for double precision
screws
*/
inline void ksl_axpy_ss(const double a, const ksl_screw_t* restrict x,
                        ksl_screw_t* restrict y) {
  for(int i = 0; i < 6; i++) {
    y->at[i] += a * x->at[i];
  }
}

/*!
@brief compute axpy (a * x + y \rightarrow y) operation for single precision
screws
*/
inline void ksl_axpy_ssf(const float a, const ksl_screwf_t* restrict x,
                         ksl_screwf_t* restrict y) {
  for(int i = 0; i < 6; i++) {
    y->at[i] += a * x->at[i];
  }
}

/*!
@brief Copy double precision ksl_screw_t si to so.

\f$S_i \rightarrow S_o\f$

@param si [in] screw to copy
@param so [out] si is copied to so
*/
inline void ksl_screw_copy(const ksl_screw_t* restrict si,
                           ksl_screw_t* restrict so) {
  memcpy(so, si, sizeof(ksl_screw_t));
}

/*!
@brief Copy single precision ksl_screwf_t si to so.

\f$S_i \rightarrow S_o\f$

@param si [in] screw to copy
@param so [out] si is copied to so
*/
inline void ksl_screwf_copy(const ksl_screwf_t* restrict si,
                            ksl_screwf_t* restrict so) {
  memcpy(so, si, sizeof(ksl_screwf_t));
}

/*!
@brief Returns the inverse of a ksl_screw_t.

\f$\mathbf{\underline{s}}_i^{-1} \rightarrow \mathbf{\underline{s}}_o\f$

@param si [in] screw to invert
@param so [out] inverse of si
*/
inline void ksl_screw_inverted(const ksl_screw_t* restrict si,
                               ksl_screw_t* restrict so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] = -si->at[i];
  }
}

/*!
@brief Returns the inverse of a ksl_screwf_t.

\f$\mathbf{\underline{s}}_i^{-1} \rightarrow \mathbf{\underline{s}}_o\f$

@param si [in] screw to invert
@param so [out] inverse of si
*/
inline void ksl_screwf_inverted(const ksl_screwf_t* restrict si,
                                ksl_screwf_t* restrict so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] = -si->at[i];
  }
}

/*!
@brief Invert (i.e. negate) a ksl_screw_t in place.

\f$\mathbf{\underline{s}}^{-1} \rightarrow \mathbf{\underline{s}}\f$
\f$-\mathbf{\underline{s}} \rightarrow \mathbf{\underline{s}}\f$

@param si [in/out] screw to invert
*/
inline void ksl_screw_invert(ksl_screw_t* restrict s) {
  for(int i = 0; i < 6; i++) {
    s->at[i] = -s->at[i];
  }
}

/*!
@brief Invert (i.e. negate) a ksl_screwf_t in place.

\f$\mathbf{\underline{s}}^{-1} \rightarrow \mathbf{\underline{s}}\f$
\f$-\mathbf{\underline{s}} \rightarrow \mathbf{\underline{s}}\f$

@param si [in/out] screw to invert
*/
inline void ksl_screwf_invert(ksl_screwf_t* restrict s) {
  for(int i = 0; i < 6; i++) {
    s->at[i] = -s->at[i];
  }
}

inline void ksl_product_as(const double k, const ksl_screw_t* restrict si,
                           ksl_screw_t* restrict so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] = k * si->at[i];
  }
}

void ksl_product_asf(const float k, const ksl_screwf_t* restrict si,
                     ksl_screwf_t* restrict so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] = k * si->at[i];
  }
}

void ksl_add_ss(const ksl_screw_t* restrict s1i,
                const ksl_screw_t* restrict s2i, ksl_screw_t* restrict so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] = s1i->at[i] + s2i->at[i];
  }
}

void ksl_add_ssf(const ksl_screwf_t* restrict s1i,
                 const ksl_screwf_t* restrict s2i, ksl_screwf_t* restrict so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] = s1i->at[i] + s2i->at[i];
  }
}

void ksl_xpy_ss(const ksl_screw_t* restrict s1i, ksl_screw_t* restrict so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] += s1i->at[i];
  }
}

void ksl_xpy_ssf(const ksl_screwf_t* restrict s1i, ksl_screwf_t* restrict so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] += s1i->at[i];
  }
}

void ksl_subtract_ss(const ksl_screw_t* restrict s1i,
                     const ksl_screw_t* restrict s2i, ksl_screw_t* so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] = s1i->at[i] - s2i->at[i];
  }
}

void ksl_subtract_ssf(const ksl_screwf_t* restrict s1i,
                      const ksl_screwf_t* restrict s2i,
                      ksl_screwf_t* restrict so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] = s1i->at[i] - s2i->at[i];
  }
}

void ksl_nxpy_ss(const ksl_screw_t* restrict s1i, ksl_screw_t* restrict so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] -= s1i->at[i];
  }
}

void ksl_nxpy_ssf(const ksl_screwf_t* restrict s1i, ksl_screwf_t* restrict so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] -= s1i->at[i];
  }
}

void ksl_add_sst(const ksl_screw_t* restrict si1,
                 const ksl_screw_t* restrict si2, ksl_screw_t* restrict so) {
  ksl_screw_copy(si1, so);
  so->at[0] += si2->at[0];
  so->at[1] += si2->at[1];
  so->at[2] += si2->at[2];
}

void ksl_add_sstf(const ksl_screwf_t* restrict si1,
                  const ksl_screwf_t* restrict si2, ksl_screwf_t* restrict so) {
  ksl_screwf_copy(si1, so);
  so->at[0] += si2->at[0];
  so->at[1] += si2->at[1];
  so->at[2] += si2->at[2];
}

inline void ksl_htx(const ksl_SE3_t* restrict Di, ksl_screw_t* restrict ho) {
  ksl_vec3_copy(&Di->R.v0, &ho->lin);
}

inline void ksl_htxf(const ksl_SE3f_t* restrict Di, ksl_screwf_t* restrict ho) {
  ksl_vec3f_copy(&Di->R.v0, &ho->lin);
}

inline void ksl_hty(const ksl_SE3_t* restrict Di, ksl_screw_t* restrict ho) {
  ksl_vec3_copy(&Di->R.v1, &ho->lin);
}

inline void ksl_htyf(const ksl_SE3f_t* restrict Di, ksl_screwf_t* restrict ho) {
  ksl_vec3f_copy(&Di->R.v1, &ho->lin);
}

inline void ksl_htz(const ksl_SE3_t* restrict Di, ksl_screw_t* restrict ho) {
  ksl_vec3_copy(&Di->R.v2, &ho->lin);
}

inline void ksl_htzf(const ksl_SE3f_t* restrict Di, ksl_screwf_t* restrict ho) {
  ksl_vec3f_copy(&Di->R.v2, &ho->lin);
}

inline void ksl_hrx(const ksl_SE3_t* restrict Di, ksl_screw_t* restrict ho) {
  ksl_vec3_copy(&Di->R.v0, &ho->ang);
  ksl_cross_vv(&Di->t, &ho->ang, &ho->lin);
}

inline void ksl_hrxf(const ksl_SE3f_t* restrict Di, ksl_screwf_t* restrict ho) {
  ksl_vec3f_copy(&Di->R.v0, &ho->ang);
  ksl_cross_vvf(&Di->t, &ho->ang, &ho->lin);
}

inline void ksl_hry(const ksl_SE3_t* restrict Di, ksl_screw_t* restrict ho) {
  ksl_vec3_copy(&Di->R.v1, &ho->ang);
  ksl_cross_vv(&Di->t, &ho->ang, &ho->lin);
}

inline void ksl_hryf(const ksl_SE3f_t* restrict Di, ksl_screwf_t* restrict ho) {
  ksl_vec3f_copy(&Di->R.v1, &ho->ang);
  ksl_cross_vvf(&Di->t, &ho->ang, &ho->lin);
}

inline void ksl_hrz(const ksl_SE3_t* restrict Di, ksl_screw_t* restrict ho) {
  ksl_vec3_copy(&Di->R.v2, &ho->ang);
  ksl_cross_vv(&Di->t, &ho->ang, &ho->lin);
}

inline void ksl_hrzf(const ksl_SE3f_t* restrict Di, ksl_screwf_t* restrict ho) {
  ksl_vec3f_copy(&Di->R.v2, &ho->ang);
  ksl_cross_vvf(&Di->t, &ho->ang, &ho->lin);
}

inline void ksl_htxinv(const ksl_SE3_t* restrict Di, ksl_screw_t* restrict ho) {
  ksl_vec3_inverted(&Di->R.v0, &ho->lin);
}

inline void ksl_htxinvf(const ksl_SE3f_t* restrict Di,
                        ksl_screwf_t* restrict ho) {
  ksl_vec3f_inverted(&Di->R.v0, &ho->lin);
}

inline void ksl_htyinv(const ksl_SE3_t* restrict Di, ksl_screw_t* restrict ho) {
  ksl_vec3_inverted(&Di->R.v1, &ho->lin);
}

inline void ksl_htyinvf(const ksl_SE3f_t* restrict Di,
                        ksl_screwf_t* restrict ho) {
  ksl_vec3f_inverted(&Di->R.v1, &ho->lin);
}

inline void ksl_htzinv(const ksl_SE3_t* restrict Di, ksl_screw_t* restrict ho) {
  ksl_vec3_inverted(&Di->R.v2, &ho->lin);
}

inline void ksl_htzinvf(const ksl_SE3f_t* restrict Di,
                        ksl_screwf_t* restrict ho) {
  ksl_vec3f_inverted(&Di->R.v2, &ho->lin);
}

inline void ksl_hrxinv(const ksl_SE3_t* restrict Di, ksl_screw_t* restrict ho) {
  ksl_vec3_inverted(&Di->R.v0, &ho->ang);
  ksl_cross_vv(&Di->t, &ho->ang, &ho->lin);
}

inline void ksl_hrxinvf(const ksl_SE3f_t* restrict Di,
                        ksl_screwf_t* restrict ho) {
  ksl_vec3f_inverted(&Di->R.v0, &ho->ang);
  ksl_cross_vvf(&Di->t, &ho->ang, &ho->lin);
}

inline void ksl_hryinv(const ksl_SE3_t* restrict Di, ksl_screw_t* restrict ho) {
  ksl_vec3_inverted(&Di->R.v1, &ho->ang);
  ksl_cross_vv(&Di->t, &ho->ang, &ho->lin);
}

inline void ksl_hryinvf(const ksl_SE3f_t* restrict Di,
                        ksl_screwf_t* restrict ho) {
  ksl_vec3f_inverted(&Di->R.v1, &ho->ang);
  ksl_cross_vvf(&Di->t, &ho->ang, &ho->lin);
}

inline void ksl_hrzinv(const ksl_SE3_t* restrict Di, ksl_screw_t* restrict ho) {
  ksl_vec3_inverted(&Di->R.v2, &ho->ang);
  ksl_cross_vv(&Di->t, &ho->ang, &ho->lin);
}

inline void ksl_hrzinvf(const ksl_SE3f_t* restrict Di,
                        ksl_screwf_t* restrict ho) {
  ksl_vec3f_inverted(&Di->R.v2, &ho->ang);
  ksl_cross_vvf(&Di->t, &ho->ang, &ho->lin);
}

inline void ksl_cross_ss(const ksl_screw_t* restrict s1i,
                         const ksl_screw_t* restrict s2i,
                         ksl_screw_t* restrict so) {

  /* so.v <- s1i.w x s2i.v */
  ksl_cross_vv(&s1i->ang, &s2i->lin, &so->lin);

  /* wo <- w1i x w2i */
  ksl_cross_vv(&s1i->ang, &s2i->ang, &so->ang);

  /* vo += v1i x w2i */
  so->m0 += s1i->m1 * s2i->m5 - s1i->m2 * s2i->m4;
  so->m1 += s1i->m2 * s2i->m3 - s1i->m0 * s2i->m5;
  so->m2 += s1i->m0 * s2i->m4 - s1i->m1 * s2i->m3;
}

inline void ksl_cross_ssf(const ksl_screwf_t* restrict s1i,
                          const ksl_screwf_t* restrict s2i,
                          ksl_screwf_t* restrict so) {
  /* so.v <- s1i.w x s2i.v */
  ksl_cross_vvf(&s1i->ang, &s2i->lin, &so->lin);

  /* wo <- w1i x w2i */
  ksl_cross_vvf(&s1i->ang, &s2i->ang, &so->ang);

  /* vo += v1i x w2i */
  so->m0 += s1i->m1 * s2i->m5 - s1i->m2 * s2i->m4;
  so->m1 += s1i->m2 * s2i->m3 - s1i->m0 * s2i->m5;
  so->m2 += s1i->m0 * s2i->m4 - s1i->m1 * s2i->m3;
}

inline void ksl_cross_sst(const ksl_screw_t* restrict s1i,
                          const ksl_screw_t* restrict s2i,
                          ksl_screw_t* restrict so) {
  ksl_cross_vv(&s1i->ang, &s2i->lin, &so->lin);
  memset(&so->ang, 0, sizeof(ksl_screw_t));
}

inline void ksl_cross_sstf(const ksl_screwf_t* restrict s1i,
                           const ksl_screwf_t* restrict s2i,
                           ksl_screwf_t* restrict so) {
  ksl_cross_vvf(&s1i->ang, &s2i->lin, &so->lin);
  memset(&so->ang, 0, sizeof(ksl_screwf_t));
}

/*!
@brief rotates a double precision screw

Store product of direction cosine matrix ri with spatial vector si in so.

\f$ R_i * S_i[0:2] \rightarrow S_o[0:2]\f$

\f$ R_i * S_i[3:5] \rightarrow S_o[3:5]\f$

@param ri a SO3 rotation matrix
@param si a 1x6 screw
@param so the output of ri * si is returned in so
*/
inline void ksl_product_Adrs(const ksl_mat3x3_t* restrict ri,
                             const ksl_screw_t* restrict si,
                             ksl_screw_t* restrict so) {

  ksl_product_drv(ri, &si->lin, &so->lin);
  ksl_product_drv(ri, &si->ang, &so->ang);
}

/*!
@brief rotates a single precision screw

Store product of direction cosine matrix ri with spatial vector si in so.

\f$ R_i * S_i[0:2] \rightarrow S_o[0:2]\f$

\f$ R_i * S_i[3:5] \rightarrow S_o[3:5]\f$

@param ri a SO3 rotation matrix
@param si a 1x6 screw
@param so the output of ri * si is returned in so
*/
inline void ksl_product_Adrsf(const ksl_mat3x3f_t* restrict ri,
                              const ksl_screwf_t* restrict si,
                              ksl_screwf_t* restrict so) {

  ksl_product_drvf(ri, &si->lin, &so->lin);
  ksl_product_drvf(ri, &si->ang, &so->ang);
}

/*!
@brief General spatial transformation a double precision screw

Store product of direction cosine matrix ri with spatial vector si in so.

\f$ R_i * S_i[0:2] \rightarrow S_o[0:2]\f$

\f$ R_i * S_i[3:5] \rightarrow S_o[3:5]\f$

@param ri a SO3 rotation matrix
@param si a 1x6 screw
@param so the output of ri * si is returned in so
*/
inline void ksl_product_Ads(const ksl_SE3_t* restrict Di,
                            const ksl_screw_t* restrict si,
                            ksl_screw_t* restrict so) {

  ksl_product_Adrs(&Di->R, si, so);

  so->m3 += Di->t.y * so->m2 - Di->t.z * so->m1;
  so->m4 += Di->t.z * so->m0 - Di->t.x * so->m2;
  so->m5 += Di->t.x * so->m1 - Di->t.y * so->m0;
}

/*!
@brief General spatial transformation a single precision screw

Store product of direction cosine matrix ri with spatial vector si in so.

\f$ R_i * S_i[0:2] \rightarrow S_o[0:2]\f$

\f$ R_i * S_i[3:5] \rightarrow S_o[3:5]\f$

@param ri a SO3 rotation matrix
@param si a 1x6 screw
@param so the output of ri * si is returned in so
*/
inline void ksl_product_Adsf(const ksl_SE3f_t* restrict Di,
                             const ksl_screwf_t* restrict si,
                             ksl_screwf_t* restrict so) {

  ksl_product_Adrsf(&Di->R, si, so);

  so->m3 += Di->t.y * so->m2 - Di->t.z * so->m1;
  so->m4 += Di->t.z * so->m0 - Di->t.x * so->m2;
  so->m5 += Di->t.x * so->m1 - Di->t.y * so->m0;
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

  /* vo -= ti x w2i */
  so->m0 -= ti->y * si->m5 - ti->z * si->m4;
  so->m1 -= ti->z * si->m3 - ti->x * si->m5;
  so->m2 -= ti->x * si->m4 - ti->y * si->m3;
}

inline void ksl_product_Adtsinvf(const ksl_vec3f_t* restrict ti,
                                 const ksl_screwf_t* restrict si,
                                 ksl_screwf_t* restrict so) {
  ksl_screwf_inverted(si, so);

  /* vo -= ti x w2i */
  so->m0 -= ti->y * si->m5 - ti->z * si->m4;
  so->m1 -= ti->z * si->m3 - ti->x * si->m5;
  so->m2 -= ti->x * si->m4 - ti->y * si->m3;
}

inline void ksl_product_Adsinv(const ksl_SE3_t* restrict Di,
                               const ksl_screw_t* restrict si,
                               ksl_screw_t* restrict so) {
  ksl_product_Adrsinv(&(Di->R), si, so);
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
