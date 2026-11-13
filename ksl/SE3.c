#include <assert.h>
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include "ksl/SE3.h"
#include "ksl/mat4x4.h"
#include "ksl/matrix.h"
#include "ksl/screw.h"

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


/* -------- exponential, logarithm and interpolation of displacements -------- */

void ksl_SE3_exp(const ksl_screw_t* restrict si, ksl_SE3_t* restrict Do) {
  ksl_screw_exp(si, Do);
}

void ksl_SE3_log(const ksl_SE3_t* restrict Di, ksl_screw_t* restrict so) {
  ksl_screw_log(Di, so);
}

void ksl_SE3_lerp(const ksl_SE3_t* restrict D1i, const ksl_SE3_t* restrict D2i,
                  const double* restrict t, ksl_SE3_t* restrict Do) {
  ksl_mat3x3_t rel, step;
  ksl_product_drinvdr(&D1i->R, &D2i->R, &rel);
  ksl_vec3_t axis;
  double angle;
  ksl_mat3x3_getAxisAngle(&rel, &axis, &angle);
  ksl_mat3x3_setFromAxisAngle(&step, &axis, *t * angle);
  ksl_product_drdr(&D1i->R, &step, &Do->R);
  for(int i = 0; i < 3; i++) {
    Do->t.at[i] = (1.0 - *t) * D1i->t.at[i] + *t * D2i->t.at[i];
  }
}

void ksl_SE3_sclerp(const ksl_SE3_t* restrict D1i,
                    const ksl_SE3_t* restrict D2i, const double* restrict t,
                    ksl_SE3_t* restrict Do) {
  ksl_SE3_t rel, step;
  ksl_screw_t xi;
  ksl_product_dinvd(D1i, D2i, &rel);
  ksl_SE3_log(&rel, &xi);
  for(int i = 0; i < 6; i++) {
    xi.at[i] *= *t;
  }
  ksl_SE3_exp(&xi, &step);
  ksl_product_dd(D1i, &step, Do);
}

/* log(D1i^-1 D2i) */
static void ksl_SE3_log_difference(const ksl_SE3_t* D1i, const ksl_SE3_t* D2i,
                                   ksl_screw_t* so) {
  ksl_SE3_t rel;
  ksl_product_dinvd(D1i, D2i, &rel);
  ksl_SE3_log(&rel, so);
}

void ksl_SE3_squad_control(const ksl_SE3_t* restrict Dprevi,
                           const ksl_SE3_t* restrict Di,
                           const ksl_SE3_t* restrict Dnexti,
                           ksl_SE3_t* restrict So) {
  ksl_screw_t lnext, lprev, xi;
  ksl_SE3_log_difference(Di, Dnexti, &lnext);
  ksl_SE3_log_difference(Di, Dprevi, &lprev);
  for(int i = 0; i < 6; i++) {
    xi.at[i] = -0.25 * (lnext.at[i] + lprev.at[i]);
  }
  ksl_SE3_t e;
  ksl_SE3_exp(&xi, &e);
  ksl_product_dd(Di, &e, So);
}

void ksl_SE3_squad(const ksl_SE3_t* restrict D1i, const ksl_SE3_t* restrict D2i,
                   const ksl_SE3_t* restrict S1i, const ksl_SE3_t* restrict S2i,
                   const double* restrict t, ksl_SE3_t* restrict Do) {
  const double h = *t;
  const double u = 2.0 * h * (1.0 - h);
  ksl_SE3_t a, b;
  ksl_SE3_sclerp(D1i, D2i, &h, &a);
  ksl_SE3_sclerp(S1i, S2i, &h, &b);
  ksl_SE3_sclerp(&a, &b, &u, Do);
}

void ksl_SE3_squad_keys(const int n, const ksl_SE3_t* restrict keys,
                        const double* restrict t, ksl_SE3_t* restrict Do) {
  if(n < 2 || !(*t > 0.0)) {
    *Do = keys[0];
    return;
  }
  if(*t >= n - 1) {
    *Do = keys[n - 1];
    return;
  }
  const int k = (int)floor(*t);
  const double h = *t - k;
  ksl_SE3_t s1 = keys[k], s2 = keys[k + 1];
  if(k > 0) {
    ksl_SE3_squad_control(&keys[k - 1], &keys[k], &keys[k + 1], &s1);
  }
  if(k + 2 < n) {
    ksl_SE3_squad_control(&keys[k], &keys[k + 1], &keys[k + 2], &s2);
  }
  ksl_SE3_squad(&keys[k], &keys[k + 1], &s1, &s2, &h, Do);
}

/* single precision versions: convert to double, compute, convert back */

static ksl_SE3_t ksl_SE3_fromf(const ksl_SE3f_t* D) {
  ksl_SE3_t d;
  for(int i = 0; i < 12; i++) {
    d.as_array[i] = D->as_array[i];
  }
  return d;
}

static void ksl_SE3_tof(const ksl_SE3_t* d, ksl_SE3f_t* D) {
  for(int i = 0; i < 12; i++) {
    D->as_array[i] = (float)d->as_array[i];
  }
}

void ksl_SE3f_exp(const ksl_screwf_t* restrict si, ksl_SE3f_t* restrict Do) {
  ksl_screwf_exp(si, Do);
}

void ksl_SE3f_log(const ksl_SE3f_t* restrict Di, ksl_screwf_t* restrict so) {
  ksl_screwf_log(Di, so);
}

void ksl_SE3f_lerp(const ksl_SE3f_t* restrict D1i, const ksl_SE3f_t* restrict D2i,
                   const float* restrict t, ksl_SE3f_t* restrict Do) {
  ksl_SE3_t d1 = ksl_SE3_fromf(D1i), d2 = ksl_SE3_fromf(D2i), d;
  double h = *t;
  ksl_SE3_lerp(&d1, &d2, &h, &d);
  ksl_SE3_tof(&d, Do);
}

void ksl_SE3f_sclerp(const ksl_SE3f_t* restrict D1i,
                     const ksl_SE3f_t* restrict D2i, const float* restrict t,
                     ksl_SE3f_t* restrict Do) {
  ksl_SE3_t d1 = ksl_SE3_fromf(D1i), d2 = ksl_SE3_fromf(D2i), d;
  double h = *t;
  ksl_SE3_sclerp(&d1, &d2, &h, &d);
  ksl_SE3_tof(&d, Do);
}

void ksl_SE3f_squad_control(const ksl_SE3f_t* restrict Dprevi,
                            const ksl_SE3f_t* restrict Di,
                            const ksl_SE3f_t* restrict Dnexti,
                            ksl_SE3f_t* restrict So) {
  ksl_SE3_t dp = ksl_SE3_fromf(Dprevi), d = ksl_SE3_fromf(Di),
            dn = ksl_SE3_fromf(Dnexti), s;
  ksl_SE3_squad_control(&dp, &d, &dn, &s);
  ksl_SE3_tof(&s, So);
}

void ksl_SE3f_squad(const ksl_SE3f_t* restrict D1i,
                    const ksl_SE3f_t* restrict D2i,
                    const ksl_SE3f_t* restrict S1i,
                    const ksl_SE3f_t* restrict S2i, const float* restrict t,
                    ksl_SE3f_t* restrict Do) {
  ksl_SE3_t d1 = ksl_SE3_fromf(D1i), d2 = ksl_SE3_fromf(D2i),
            s1 = ksl_SE3_fromf(S1i), s2 = ksl_SE3_fromf(S2i), d;
  double h = *t;
  ksl_SE3_squad(&d1, &d2, &s1, &s2, &h, &d);
  ksl_SE3_tof(&d, Do);
}

void ksl_SE3f_squad_keys(const int n, const ksl_SE3f_t* restrict keys,
                         const float* restrict t, ksl_SE3f_t* restrict Do) {
  if(n < 2 || !(*t > 0.0f)) {
    *Do = keys[0];
    return;
  }
  if(*t >= n - 1) {
    *Do = keys[n - 1];
    return;
  }
  const int k = (int)floorf(*t);
  const double h = (double)*t - k;
  ksl_SE3_t d1 = ksl_SE3_fromf(&keys[k]), d2 = ksl_SE3_fromf(&keys[k + 1]);
  ksl_SE3_t s1 = d1, s2 = d2, d;
  if(k > 0) {
    ksl_SE3_t dp = ksl_SE3_fromf(&keys[k - 1]);
    ksl_SE3_squad_control(&dp, &d1, &d2, &s1);
  }
  if(k + 2 < n) {
    ksl_SE3_t dn = ksl_SE3_fromf(&keys[k + 2]);
    ksl_SE3_squad_control(&d1, &d2, &dn, &s2);
  }
  ksl_SE3_squad(&d1, &d2, &s1, &s2, &h, &d);
  ksl_SE3_tof(&d, Do);
}
