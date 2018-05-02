#include <stdlib.h>
#include <string.h>

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
@brief allocate n double precision coscrew quantities
*/
ksl_coscrew_t* ksl_coscrew_alloc(const int n) {
  return calloc(n, sizeof(ksl_coscrew_t));
}

/*!
@brief allocate n single precision coscrew quantities
*/
ksl_coscrewf_t* ksl_coscrewf_alloc(const int n) {
  return calloc(n, sizeof(ksl_coscrewf_t));
}


inline double ksl_screw_norm(const ksl_screw_t* restrict v);

inline float ksl_screwf_norm(const ksl_screwf_t* restrict v);

/*!
@brief compute double precision dot product between a coscrew and screw
*/
inline double ksl_dot_cs(const ksl_coscrew_t* restrict ci, const ksl_screw_t* restrict si) {
  register double sum = 0;
  for(int i = 0; i < 6; i++) {
    sum += ci->at[i] * si->at[i];
  }
  return sum;
}

/*!
@brief compute single precision dot product between a coscrew and screw
*/
inline float ksl_dot_csf(const ksl_coscrewf_t* restrict ci, const ksl_screwf_t* restrict si) {
  register float sum = 0;
  for(int i = 0; i < 6; i++) {
    sum += ci->at[i] * si->at[i];
  }
  return sum;
}

/*!
@brief compute axpy (a * x + y \rightarrow y) operation for double precision screws
*/
inline void ksl_axpy_ss(const double a, const ksl_screw_t* restrict x, ksl_screw_t* restrict y) {
  for(int i = 0; i < 6; i++) {
    y->at[i] += a * x->at[i];
  }
}

/*!
@brief compute axpy (a * x + y \rightarrow y) operation for single precision screws
*/
inline void ksl_axpy_ssf(const float a, const ksl_screwf_t* restrict x, ksl_screwf_t* restrict y) {
  for(int i = 0; i < 6; i++) {
    y->at[i] += a * x->at[i];
  }
}

inline void ksl_screw_copy(const ksl_screw_t* restrict si, ksl_screw_t* restrict so) {
  memcpy(so, si, sizeof(ksl_screw_t));
}

inline void ksl_screwf_copy(const ksl_screwf_t* restrict si, ksl_screwf_t* restrict so) {
  memcpy(so, si, sizeof(ksl_screwf_t));
}

inline void ksl_coscrew_copy(const ksl_coscrew_t* restrict ci, ksl_coscrew_t* restrict co) {
  memcpy(co, ci, sizeof(ksl_coscrew_t));
}

inline void ksl_coscrewf_copy(const ksl_coscrewf_t* restrict ci, ksl_coscrewf_t* restrict co) {
  memcpy(co, ci, sizeof(ksl_coscrewf_t));
}

inline void ksl_screw_invert(const ksl_screw_t* restrict si, ksl_screw_t* restrict so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] = -si->at[i];
  }
}

inline void ksl_screwf_invert(const ksl_screwf_t* restrict si, ksl_screwf_t* restrict so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] = -si->at[i];
  }
}

inline void ksl_coscrew_invert(const ksl_coscrew_t* restrict ci, ksl_coscrew_t* restrict co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] = -ci->at[i];
  }
}

inline void ksl_coscrewf_invert(const ksl_coscrewf_t* restrict ci, ksl_coscrewf_t* restrict co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] = -ci->at[i];
  }
}

inline void ksl_product_sk(const ksl_screw_t* restrict si, const double k, ksl_screw_t* restrict so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] = si->at[i] * k;
  }
}

void ksl_product_skf(const ksl_screwf_t* restrict si, const float k, ksl_screwf_t* restrict so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] = si->at[i] * k;
  }
}

void ksl_add_ss(const ksl_screw_t* restrict s1i, const ksl_screw_t* restrict s2i, ksl_screw_t* restrict so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] = s1i->at[i] + s2i->at[i];
  }
}

void ksl_add_ssf(const ksl_screwf_t* restrict s1i, const ksl_screwf_t* restrict s2i, ksl_screwf_t* restrict so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] = s1i->at[i] + s2i->at[i];
  }
}

void ksl_addequal_ss(const ksl_screw_t* restrict s1i, ksl_screw_t* restrict so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] += s1i->at[i];
  }
}

void ksl_addequal_ssf(const ksl_screwf_t* restrict s1i, ksl_screwf_t* restrict so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] += s1i->at[i];
  }
}

void ksl_subtract_ss(const ksl_screw_t* restrict s1i, const ksl_screw_t* restrict s2i, ksl_screw_t* so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] = s1i->at[i] - s2i->at[i];
  }
}

void ksl_subtract_ssf(const ksl_screwf_t* restrict s1i, const ksl_screwf_t* restrict s2i, ksl_screwf_t* restrict so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] = s1i->at[i] - s2i->at[i];
  }
}

void ksl_subtractequal_ss(const ksl_screw_t* restrict s1i, ksl_screw_t* restrict so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] -= s1i->at[i] ;
  }
}

void ksl_subtractequal_ssf(const ksl_screwf_t* restrict s1i, ksl_screwf_t* restrict so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] -= s1i->at[i] ;
  }
}

void ksl_add_sst(ksl_screw_t* si1, ksl_screw_t* si2, ksl_screw_t* so);

void ksl_add_sstf(ksl_screwf_t* si1, ksl_screwf_t* si2, ksl_screwf_t* so);

void ksl_htx(ksl_SE3_t* Di, ksl_screw_t* ho);

void ksl_htxf(ksl_SE3f_t* Di, ksl_screwf_t* ho);

void ksl_hty(ksl_SE3_t* Di, ksl_screw_t* ho);

void ksl_htyf(ksl_SE3f_t* Di, ksl_screwf_t* ho);

void ksl_htz(ksl_SE3_t* ri, ksl_screw_t* ho);

void ksl_htzf(ksl_SE3f_t* ri, ksl_screwf_t* ho);

void ksl_hrx(ksl_SE3_t* Di, ksl_screw_t* ho);

void ksl_hrxf(ksl_SE3f_t* Di, ksl_screwf_t* ho);

void ksl_hry(ksl_SE3_t* Di, ksl_screw_t* ho);

void ksl_hrz(ksl_SE3_t* Di, ksl_screw_t* ho);

void ksl_hrzf(ksl_SE3f_t* Di, ksl_screwf_t* ho);

void ksl_htxinv(ksl_SE3_t* Di, ksl_screw_t* ho);

void ksl_htxinvf(ksl_SE3f_t* Di, ksl_screwf_t* ho);

void ksl_htyinv(ksl_SE3_t* Di, ksl_screw_t* ho);

void ksl_htyinvf(ksl_SE3f_t* Di, ksl_screwf_t* ho);

void ksl_htzinv(ksl_SE3_t* Di, ksl_screw_t* ho);

void ksl_htzinvf(ksl_SE3f_t* Di, ksl_screwf_t* ho);

void ksl_hrxinv(ksl_SE3_t* Di, ksl_screw_t* ho);

void ksl_hrxinvf(ksl_SE3f_t* Di, ksl_screwf_t* ho);

void ksl_hryinv(ksl_SE3_t* Di, ksl_screw_t* ho);

void ksl_hryinvf(ksl_SE3f_t* Di, ksl_screwf_t* ho);

void ksl_hrzinv(ksl_SE3_t* Di, ksl_screw_t* ho);

void ksl_hrzinvf(ksl_SE3f_t* Di, ksl_screwf_t* ho);

void ksl_cross_ss(ksl_screw_t* s1i, ksl_screw_t* s2i, ksl_screw_t* so);

void ksl_cross_ssf(ksl_screwf_t* s1i, ksl_screwf_t* s2i, ksl_screwf_t* so);

void ksl_cross_sst(ksl_screw_t* s1i, ksl_screw_t* s2i, ksl_screw_t* so);

void ksl_cross_sstf(ksl_screwf_t* s1i, ksl_screwf_t* s2i, ksl_screwf_t* so);

void ksl_product_Adrs(ksl_mat3x3_t* ri, ksl_screw_t* si, ksl_screw_t* so);

void ksl_product_Adrsinv(ksl_mat3x3_t* ri, ksl_screw_t* si, ksl_screw_t* so);

void ksl_product_Adrsf(ksl_mat3x3f_t* ri, ksl_screwf_t* si, ksl_screwf_t* so);

void ksl_product_Adrsinvf(ksl_mat3x3f_t* ri, ksl_screwf_t* si,
                          ksl_screwf_t* so);

void ksl_product_Adrinvs(ksl_mat3x3_t* ri, ksl_screw_t* si, ksl_screw_t* so);

void ksl_product_Adrinvsf(ksl_mat3x3f_t* ri, ksl_screwf_t* si,
                          ksl_screwf_t* so);

void ksl_product_Adts(ksl_vec3_t* ti, ksl_screw_t* si, ksl_screw_t* so);

void ksl_product_Adtsf(ksl_vec3f_t* ti, ksl_screwf_t* si, ksl_screwf_t* so);

void ksl_product_Adtinvs(ksl_vec3_t* ti, ksl_screw_t* si, ksl_screw_t* so);

void ksl_product_Adtinvsf(ksl_vec3f_t* ti, ksl_screwf_t* si, ksl_screwf_t* so);

void ksl_product_Adtsinv(ksl_vec3_t* ti, ksl_screw_t* si, ksl_screw_t* so);

void ksl_product_Adtsinvf(ksl_vec3f_t* ti, ksl_screwf_t* si, ksl_screwf_t* so);

void ksl_product_Ads(ksl_SE3_t* Di, ksl_screw_t* si, ksl_screw_t* so);

void ksl_product_Adsinv(ksl_SE3_t* Di, ksl_screw_t* si, ksl_screw_t* so);

void ksl_product_Adsf(ksl_SE3f_t* Di, ksl_screwf_t* si, ksl_screwf_t* so);

void ksl_product_Adinvs(ksl_SE3_t* Di, ksl_screw_t* si, ksl_screw_t* so);

void ksl_product_Adinvsf(ksl_SE3f_t* Di, ksl_screwf_t* si, ksl_screwf_t* so);

void ksl_cross_cc(ksl_coscrew_t* s1i, ksl_coscrew_t* s2i, ksl_coscrew_t* so);

void ksl_cross_ccf(ksl_coscrewf_t* s1i, ksl_coscrewf_t* s2i,
                   ksl_coscrewf_t* so);

void ksl_product_CoAdtc(ksl_vec3_t* ti, ksl_coscrew_t* si, ksl_coscrew_t* so);

void ksl_product_CoAdtcf(ksl_vec3f_t* ti, ksl_coscrewf_t* si,
                         ksl_coscrewf_t* so);

void ksl_product_CoAdtcinv(ksl_vec3_t* ti, ksl_coscrew_t* si,
                           ksl_coscrew_t* so);

void ksl_product_CoAdtcinvf(ksl_vec3f_t* ti, ksl_coscrewf_t* si,
                            ksl_coscrewf_t* so);

void ksl_product_CoAdc(ksl_SE3_t* Di, ksl_coscrew_t* si, ksl_coscrew_t* so);

void ksl_product_CoAdcf(ksl_SE3f_t* Di, ksl_coscrewf_t* si, ksl_coscrewf_t* so);

void ksl_product_CoAdinvc(ksl_SE3_t* Di, ksl_coscrew_t* si, ksl_screw_t* so);

void ksl_product_CoAdinvcf(ksl_SE3f_t* Di, ksl_coscrewf_t* si,
                           ksl_coscrewf_t* so);
