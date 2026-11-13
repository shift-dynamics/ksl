#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "ksl/SE3.h"
#include "ksl/coscrew.h"
#include "ksl/mat3x3.h"
#include "ksl/matrix.h"
#include "ksl/screw.h"
#include "ksl/vec3.h"

ksl_screw_t* ksl_screw_alloc(const int n) {
  return calloc(n, sizeof(ksl_screw_t));
}

ksl_screwf_t* ksl_screwf_alloc(const int n) {
  return calloc(n, sizeof(ksl_screwf_t));
}

inline void ksl_screw_copy_rmo(const ksl_screw_t* si, double* A, int row,
                               int column, int stride) {
  for(unsigned int i = 0; i < 6; i++) {
    A[(row + i) * stride + column] = si->at[i];
  }
}

inline void ksl_screw_ncopy_rmo(const ksl_screw_t* si, double* A, int row,
                                int column, int stride) {
  for(unsigned int i = 0; i < 6; i++) {
    A[(row + i) * stride + column] = -si->at[i];
  }
}

void ksl_screw_ncopy_cmo(const ksl_screw_t* si, double* A, int row, int column,
                         int stride) {
  for(unsigned int i = 0; i < 6; i++) {
    A[column * stride + row + i] = -si->at[i];
  }
}

void ksl_screwf_copy_rmo(const ksl_screwf_t* si, float* A, int row, int column,
                         int stride) {
  for(unsigned int i = 0; i < 6; i++) {
    A[(row + i) * stride + column] = si->at[i];
  }
}

void ksl_screwf_ncopy_rmo(const ksl_screwf_t* si, float* A, int row, int column,
                          int stride) {
  for(unsigned int i = 0; i < 6; i++) {
    A[(row + i) * stride + column] = -si->at[i];
  }
}

void ksl_screwf_ncopy_cmo(const ksl_screwf_t* si, float* A, int row, int column,
                          int stride) {
  for(unsigned int i = 0; i < 6; i++) {
    A[column * stride + row + i] = -si->at[i];
  }
}


/* -------- exponential and logarithm: screw <-> displacement -------- */

/* w x a, written out */
static void ksl_screw_cross(const double* w, const double* a, double* c) {
  c[0] = w[1] * a[2] - w[2] * a[1];
  c[1] = w[2] * a[0] - w[0] * a[2];
  c[2] = w[0] * a[1] - w[1] * a[0];
}

void ksl_screw_exp(const ksl_screw_t* restrict si, ksl_SE3_t* restrict Do) {
  const double* rho = si->lin.at;
  const double* w = si->ang.at;
  const double th2 = w[0] * w[0] + w[1] * w[1] + w[2] * w[2];
  const double th = sqrt(th2);
  /* a = sin(th) / th, b = (1 - cos(th)) / th^2, c = (th - sin(th)) / th^3,
  with w = th u, so that R = I + a w~ + b w~ w~ and V = I + b w~ + c w~ w~ */
  double a, b, c;
  if(th < 1e-3) {
    /* to within th^6 / 5040 */
    a = 1.0 - th2 / 6.0 * (1.0 - th2 / 20.0);
    b = 0.5 - th2 / 24.0 * (1.0 - th2 / 30.0);
    c = 1.0 / 6.0 - th2 / 120.0 * (1.0 - th2 / 42.0);
  } else {
    const double s = sin(th), co = cos(th);
    a = s / th;
    b = (1.0 - co) / th2;
    c = (th - s) / (th2 * th);
  }
  /* R = I + a w~ + b (w w^T - th^2 I) */
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      Do->R.at[j][i] = b * w[i] * w[j] + (i == j ? 1.0 - b * th2 : 0.0);
    }
  }
  Do->R.m21 += a * w[0];
  Do->R.m12 -= a * w[0];
  Do->R.m02 += a * w[1];
  Do->R.m20 -= a * w[1];
  Do->R.m10 += a * w[2];
  Do->R.m01 -= a * w[2];
  /* r = V rho = rho + b w x rho + c w x (w x rho) */
  double wr[3], wwr[3];
  ksl_screw_cross(w, rho, wr);
  ksl_screw_cross(w, wr, wwr);
  for(int i = 0; i < 3; i++) {
    Do->t.at[i] = rho[i] + b * wr[i] + c * wwr[i];
  }
}

void ksl_screw_log(const ksl_SE3_t* restrict Di, ksl_screw_t* restrict so) {
  const ksl_mat3x3_t* R = &Di->R;
  /* cos(th) and sin(th) u from R = cos(th) I + (1 - cos(th)) u u^T + sin(th) u~ */
  const double co = 0.5 * (R->m00 + R->m11 + R->m22 - 1.0);
  const double v[3] = {0.5 * (R->m21 - R->m12), 0.5 * (R->m02 - R->m20),
                       0.5 * (R->m10 - R->m01)};
  const double s = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
  const double th = atan2(s, co);
  double* w = so->ang.at;
  if(co >= 0.0) {
    /* th <= pi / 2: w = (th / sin(th)) sin(th) u, to within s^4 / 8 near 0 */
    const double f = s < 1e-6 ? 1.0 + s * s / 6.0 : th / s;
    for(int i = 0; i < 3; i++) {
      w[i] = f * v[i];
    }
  } else {
    /* near pi the skew part vanishes; ksl_mat3x3_getAxisAngle uses the
    symmetric part */
    ksl_vec3_t u;
    double angle;
    ksl_mat3x3_getAxisAngle(R, &u, &angle);
    for(int i = 0; i < 3; i++) {
      w[i] = th * u.at[i];
    }
  }
  /* rho = V^-1 r = r - w x r / 2 + d w x (w x r), with
  d = (1 - (th / 2) cot(th / 2)) / th^2 */
  const double th2 = th * th;
  double d;
  if(th < 1e-3) {
    /* 1/12 + th^2/720 + th^4/30240 */
    d = 1.0 / 12.0 + th2 / 720.0 * (1.0 + th2 / 42.0);
  } else {
    const double h = 0.5 * th;
    d = (1.0 - h * cos(h) / sin(h)) / th2;
  }
  const double* r = Di->t.at;
  double wr[3], wwr[3];
  ksl_screw_cross(w, r, wr);
  ksl_screw_cross(w, wr, wwr);
  for(int i = 0; i < 3; i++) {
    so->lin.at[i] = r[i] - 0.5 * wr[i] + d * wwr[i];
  }
}

void ksl_screwf_exp(const ksl_screwf_t* restrict si, ksl_SE3f_t* restrict Do) {
  ksl_screw_t s;
  for(int i = 0; i < 6; i++) {
    s.at[i] = si->at[i];
  }
  ksl_SE3_t d;
  ksl_screw_exp(&s, &d);
  for(int i = 0; i < 12; i++) {
    Do->as_array[i] = (float)d.as_array[i];
  }
}

void ksl_screwf_log(const ksl_SE3f_t* restrict Di, ksl_screwf_t* restrict so) {
  ksl_SE3_t d;
  for(int i = 0; i < 12; i++) {
    d.as_array[i] = Di->as_array[i];
  }
  ksl_screw_t s;
  ksl_screw_log(&d, &s);
  for(int i = 0; i < 6; i++) {
    so->at[i] = (float)s.at[i];
  }
}
