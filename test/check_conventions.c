#include <config.h>

#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "ksl/SE3.h"
#include "ksl/coscrew.h"
#include "ksl/matrix.h"
#include "ksl/screw.h"
#include "ksl/trig.h"

/* Checks the conventions stated in the documentation: what each specialized
function computes, written out with plain reference arithmetic that does not
use the library.

  - SE3 transformations D = (R, t) act on points as D*p = R*p + t.
  - "inv" after a transformation means its inverse (dinv = D^-1), after a
    vector, screw or coscrew it means its negative (vinv = -v).
  - drx, dry, drz are rotations about the x, y, z axis given by
    dc = {sin(theta), cos(theta)}; dtx, dty, dtz are translations along an
    axis.
  - Screws are {lin, ang}, Ad(D)*s = {R*lin + t x R*ang, R*ang}.
  - Coscrews are {lin, ang}, CoAd(D)*c = {R*lin, R*ang + t x R*lin}. */

static const double tol = 1e-12;

/* ---------- reference arithmetic, independent of the library ---------- */

typedef struct {
  double R[3][3]; /* R[row][col] */
  double t[3];
} ref_se3;

static ref_se3 ref_from(const ksl_SE3_t* D) {
  ref_se3 r;
  for(int c = 0; c < 3; c++)
    for(int i = 0; i < 3; i++)
      r.R[i][c] = D->at[c][i];
  for(int i = 0; i < 3; i++)
    r.t[i] = D->at[3][i];
  return r;
}

static ref_se3 ref_mul(const ref_se3* a, const ref_se3* b) {
  ref_se3 o;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      o.R[i][j] = 0;
      for(int k = 0; k < 3; k++)
        o.R[i][j] += a->R[i][k] * b->R[k][j];
    }
    o.t[i] = a->t[i];
    for(int k = 0; k < 3; k++)
      o.t[i] += a->R[i][k] * b->t[k];
  }
  return o;
}

static ref_se3 ref_inv(const ref_se3* a) {
  ref_se3 o;
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      o.R[i][j] = a->R[j][i];
  for(int i = 0; i < 3; i++) {
    o.t[i] = 0;
    for(int k = 0; k < 3; k++)
      o.t[i] -= a->R[k][i] * a->t[k];
  }
  return o;
}

static ref_se3 ref_identity(void) {
  ref_se3 o = {{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}, {0, 0, 0}};
  return o;
}

/* rotation by theta about axis (0, 1, 2), from s = sin, c = cos */
static ref_se3 ref_rot(int axis, double s, double c) {
  ref_se3 o = ref_identity();
  int i = (axis + 1) % 3, j = (axis + 2) % 3;
  o.R[i][i] = c;
  o.R[i][j] = -s;
  o.R[j][i] = s;
  o.R[j][j] = c;
  return o;
}

static ref_se3 ref_trans(const double t[3]) {
  ref_se3 o = ref_identity();
  for(int i = 0; i < 3; i++)
    o.t[i] = t[i];
  return o;
}

static void ref_mulv(const double R[3][3], const double v[3], double o[3]) {
  for(int i = 0; i < 3; i++)
    o[i] = R[i][0] * v[0] + R[i][1] * v[1] + R[i][2] * v[2];
}

static void ref_cross(const double a[3], const double b[3], double o[3]) {
  o[0] = a[1] * b[2] - a[2] * b[1];
  o[1] = a[2] * b[0] - a[0] * b[2];
  o[2] = a[0] * b[1] - a[1] * b[0];
}

/* Ad(D)*s for s = {lin, ang} */
static void ref_Ad(const ref_se3* D, const double s[6], double o[6]) {
  double Rv[3], Rw[3], txRw[3];
  ref_mulv(D->R, s, Rv);
  ref_mulv(D->R, s + 3, Rw);
  ref_cross(D->t, Rw, txRw);
  for(int i = 0; i < 3; i++) {
    o[i] = Rv[i] + txRw[i];
    o[3 + i] = Rw[i];
  }
}

/* CoAd(D)*c for c = {lin, ang} */
static void ref_CoAd(const ref_se3* D, const double c[6], double o[6]) {
  double Rf[3], Rn[3], txRf[3];
  ref_mulv(D->R, c, Rf);
  ref_mulv(D->R, c + 3, Rn);
  ref_cross(D->t, Rf, txRf);
  for(int i = 0; i < 3; i++) {
    o[i] = Rf[i];
    o[3 + i] = Rn[i] + txRf[i];
  }
}

static void neg6(const double a[6], double o[6]) {
  for(int i = 0; i < 6; i++)
    o[i] = -a[i];
}

/* ---------- test data ---------- */

static ksl_SE3_t D1, D2;
static ref_se3 r1, r2;
static double dc[2];
static const double theta = 0.7;

static ksl_SE3_t make_se3(double ax, double ay, double az, double angle,
                          double tx, double ty, double tz) {
  /* rotation from an axis-angle via Rodrigues' formula */
  double n = sqrt(ax * ax + ay * ay + az * az);
  ax /= n;
  ay /= n;
  az /= n;
  double c = cos(angle), s = sin(angle), C = 1 - c;
  double R[3][3] = {
    {c + ax * ax * C, ax * ay * C - az * s, ax * az * C + ay * s},
    {ay * ax * C + az * s, c + ay * ay * C, ay * az * C - ax * s},
    {az * ax * C - ay * s, az * ay * C + ax * s, c + az * az * C}};
  ksl_SE3_t D;
  for(int col = 0; col < 3; col++)
    for(int row = 0; row < 3; row++)
      D.at[col][row] = R[row][col];
  D.at[3][0] = tx;
  D.at[3][1] = ty;
  D.at[3][2] = tz;
  return D;
}

static void setup(void) {
  D1 = make_se3(1.0, 2.0, 3.0, 0.9, 0.4, -1.2, 2.5);
  D2 = make_se3(-0.5, 0.3, 0.9, 1.9, -0.7, 0.2, 1.1);
  r1 = ref_from(&D1);
  r2 = ref_from(&D2);
  ksl_dc(theta, dc);
}

static void check_se3(const ksl_SE3_t* got, const ref_se3* expected,
                      const char* what) {
  ref_se3 g = ref_from(got);
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++)
      ck_assert_msg(fabs(g.R[i][j] - expected->R[i][j]) < tol,
                    "%s: R[%d][%d] %g != %g", what, i, j, g.R[i][j],
                    expected->R[i][j]);
    ck_assert_msg(fabs(g.t[i] - expected->t[i]) < tol, "%s: t[%d] %g != %g",
                  what, i, g.t[i], expected->t[i]);
  }
}

static void check_mat3(const ksl_mat3x3_t* got, const ref_se3* expected,
                       const char* what) {
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      ck_assert_msg(fabs(got->at[j][i] - expected->R[i][j]) < tol,
                    "%s: R[%d][%d] %g != %g", what, i, j, got->at[j][i],
                    expected->R[i][j]);
}

static void check_n(const double* got, const double* expected, int n,
                    const char* what) {
  for(int i = 0; i < n; i++)
    ck_assert_msg(fabs(got[i] - expected[i]) < tol, "%s: [%d] %g != %g", what,
                  i, got[i], expected[i]);
}

/* ---------- tests ---------- */

START_TEST(test_dc_is_sin_cos) {
  ck_assert_double_eq_tol(dc[0], sin(theta), tol);
  ck_assert_double_eq_tol(dc[1], cos(theta), tol);
}
END_TEST

START_TEST(test_se3_products) {
  ksl_SE3_t Do;
  ref_se3 e, i1 = ref_inv(&r1), i2 = ref_inv(&r2);

  ksl_product_dd(&D1, &D2, &Do);
  e = ref_mul(&r1, &r2);
  check_se3(&Do, &e, "dd");

  ksl_product_ddinv(&D1, &D2, &Do);
  e = ref_mul(&r1, &i2);
  check_se3(&Do, &e, "ddinv");

  ksl_product_dinvd(&D1, &D2, &Do);
  e = ref_mul(&i1, &r2);
  check_se3(&Do, &e, "dinvd");

  ksl_product_ddr(&D1, &D2.R, &Do);
  ref_se3 rot2 = r2;
  rot2.t[0] = rot2.t[1] = rot2.t[2] = 0;
  e = ref_mul(&r1, &rot2);
  check_se3(&Do, &e, "ddr");

  ksl_product_ddrinv(&D1, &D2.R, &Do);
  ref_se3 rot2inv = ref_inv(&rot2);
  e = ref_mul(&r1, &rot2inv);
  check_se3(&Do, &e, "ddrinv");

  ksl_vec3_t t = ksl_vec3(0.3, -0.8, 1.7);
  ref_se3 T = ref_trans(t.at), Tinv = ref_inv(&T);
  ksl_product_ddt(&D1, &t, &Do);
  e = ref_mul(&r1, &T);
  check_se3(&Do, &e, "ddt");
  ksl_product_ddtinv(&D1, &t, &Do);
  e = ref_mul(&r1, &Tinv);
  check_se3(&Do, &e, "ddtinv");
  ksl_product_dinvdt(&D1, &t, &Do);
  e = ref_mul(&i1, &T);
  check_se3(&Do, &e, "dinvdt");

  ksl_SE3_inverted(&D1, &Do);
  check_se3(&Do, &i1, "SE3_inverted");
  Do = D1;
  ksl_SE3_invert(&Do);
  check_se3(&Do, &i1, "SE3_invert");
}
END_TEST

typedef void (*axis_rot_fn)(const ksl_SE3_t*, const double[2], ksl_SE3_t*);
typedef void (*axis_trans_fn)(const ksl_SE3_t*, const double, ksl_SE3_t*);
typedef void (*mat_rot_fn)(const ksl_mat3x3_t*, const double[2], ksl_mat3x3_t*);

START_TEST(test_axis_rotations_and_translations) {
  axis_rot_fn ddr[3] = {ksl_product_ddrx, ksl_product_ddry, ksl_product_ddrz};
  axis_rot_fn ddrinv[3] = {ksl_product_ddrxinv, ksl_product_ddryinv,
                           ksl_product_ddrzinv};
  mat_rot_fn drdr[3] = {ksl_product_drdrx, ksl_product_drdry,
                        ksl_product_drdrz};
  mat_rot_fn drdrinv[3] = {ksl_product_drdrxinv, ksl_product_drdryinv,
                           ksl_product_drdrzinv};
  axis_trans_fn ddt[3] = {ksl_product_ddtx, ksl_product_ddty, ksl_product_ddtz};
  axis_trans_fn ddtinv[3] = {ksl_product_ddtxinv, ksl_product_ddtyinv,
                             ksl_product_ddtzinv};
  for(int axis = 0; axis < 3; axis++) {
    ref_se3 Ra = ref_rot(axis, dc[0], dc[1]), Rainv = ref_inv(&Ra), e;
    ksl_SE3_t Do;
    ksl_mat3x3_t ro;

    ddr[axis](&D1, dc, &Do);
    e = ref_mul(&r1, &Ra);
    check_se3(&Do, &e, "ddr{x,y,z}");
    drdr[axis](&D1.R, dc, &ro);
    check_mat3(&ro, &e, "drdr{x,y,z}");

    ddrinv[axis](&D1, dc, &Do);
    e = ref_mul(&r1, &Rainv);
    check_se3(&Do, &e, "ddr{x,y,z}inv");
    drdrinv[axis](&D1.R, dc, &ro);
    check_mat3(&ro, &e, "drdr{x,y,z}inv");

    double tv[3] = {0, 0, 0};
    tv[axis] = 1.3;
    ref_se3 T = ref_trans(tv), Tinv = ref_inv(&T);
    ddt[axis](&D1, 1.3, &Do);
    e = ref_mul(&r1, &T);
    check_se3(&Do, &e, "ddt{x,y,z}");
    ddtinv[axis](&D1, 1.3, &Do);
    e = ref_mul(&r1, &Tinv);
    check_se3(&Do, &e, "ddt{x,y,z}inv");
  }
}
END_TEST

START_TEST(test_rotation_products) {
  ksl_mat3x3_t ro;
  ref_se3 a = r1, b = r2, e;
  a.t[0] = a.t[1] = a.t[2] = b.t[0] = b.t[1] = b.t[2] = 0;
  ref_se3 ainv = ref_inv(&a), binv = ref_inv(&b);

  ksl_product_drdr(&D1.R, &D2.R, &ro);
  e = ref_mul(&a, &b);
  check_mat3(&ro, &e, "drdr");
  ksl_product_drdrinv(&D1.R, &D2.R, &ro);
  e = ref_mul(&a, &binv);
  check_mat3(&ro, &e, "drdrinv");
  ksl_product_drinvdr(&D1.R, &D2.R, &ro);
  e = ref_mul(&ainv, &b);
  check_mat3(&ro, &e, "drinvdr");
}
END_TEST

START_TEST(test_vector_products) {
  ksl_vec3_t v = ksl_vec3(0.6, -1.1, 2.3), vo;
  double e[3], nv[3] = {-v.x, -v.y, -v.z};
  ref_se3 i1 = ref_inv(&r1);

  ksl_product_dv(&D1, &v, &vo);
  ref_mulv(r1.R, v.at, e);
  for(int i = 0; i < 3; i++)
    e[i] += r1.t[i];
  check_n(vo.at, e, 3, "dv");

  ksl_product_dinvv(&D1, &v, &vo);
  ref_mulv(i1.R, v.at, e);
  for(int i = 0; i < 3; i++)
    e[i] += i1.t[i];
  check_n(vo.at, e, 3, "dinvv");

  ksl_product_drv(&D1.R, &v, &vo);
  ref_mulv(r1.R, v.at, e);
  check_n(vo.at, e, 3, "drv");

  ksl_product_drvinv(&D1.R, &v, &vo);
  ref_mulv(r1.R, nv, e);
  check_n(vo.at, e, 3, "drvinv");

  ksl_product_drinvv(&D1.R, &v, &vo);
  ref_mulv(i1.R, v.at, e);
  check_n(vo.at, e, 3, "drinvv");

  ksl_product_drinvvinv(&D1.R, &v, &vo);
  ref_mulv(i1.R, nv, e);
  check_n(vo.at, e, 3, "drinvvinv");

  typedef void (*fn)(const ksl_mat3x3_t*, const double, ksl_vec3_t*);
  fn drvt[3] = {ksl_product_drvtx, ksl_product_drvty, ksl_product_drvtz};
  fn drvtinv[3] = {ksl_product_drvtxinv, ksl_product_drvtyinv,
                   ksl_product_drvtzinv};
  for(int axis = 0; axis < 3; axis++) {
    double tv[3] = {0, 0, 0};
    tv[axis] = 1.3;
    drvt[axis](&D1.R, 1.3, &vo);
    ref_mulv(r1.R, tv, e);
    check_n(vo.at, e, 3, "drvt{x,y,z}");
    tv[axis] = -1.3;
    drvtinv[axis](&D1.R, 1.3, &vo);
    ref_mulv(r1.R, tv, e);
    check_n(vo.at, e, 3, "drvt{x,y,z}inv");
  }
}
END_TEST

START_TEST(test_screw_transformations) {
  const double sv[6] = {0.3, -1.4, 0.8, 1.1, 0.25, -0.6};
  ksl_screw_t s = ksl_screw(sv[0], sv[1], sv[2], sv[3], sv[4], sv[5]), so;
  double e[6], ns[6];
  neg6(sv, ns);
  ref_se3 i1 = ref_inv(&r1), rot = r1, rotinv;
  rot.t[0] = rot.t[1] = rot.t[2] = 0;
  rotinv = ref_inv(&rot);
  ksl_vec3_t t = ksl_vec3(0.3, -0.8, 1.7);
  ref_se3 T = ref_trans(t.at), Tinv = ref_inv(&T);

  ksl_product_Ads(&D1, &s, &so);
  ref_Ad(&r1, sv, e);
  check_n(so.at, e, 6, "Ads");
  ksl_product_Adsinv(&D1, &s, &so);
  ref_Ad(&r1, ns, e);
  check_n(so.at, e, 6, "Adsinv");
  ksl_product_Adinvs(&D1, &s, &so);
  ref_Ad(&i1, sv, e);
  check_n(so.at, e, 6, "Adinvs");
  ksl_product_Adrs(&D1.R, &s, &so);
  ref_Ad(&rot, sv, e);
  check_n(so.at, e, 6, "Adrs");
  ksl_product_Adrinvs(&D1.R, &s, &so);
  ref_Ad(&rotinv, sv, e);
  check_n(so.at, e, 6, "Adrinvs");
  ksl_product_Adts(&t, &s, &so);
  ref_Ad(&T, sv, e);
  check_n(so.at, e, 6, "Adts");
  ksl_product_Adtinvs(&t, &s, &so);
  ref_Ad(&Tinv, sv, e);
  check_n(so.at, e, 6, "Adtinvs");
  ksl_product_Adtsinv(&t, &s, &so);
  ref_Ad(&T, ns, e);
  check_n(so.at, e, 6, "Adtsinv");
}
END_TEST

START_TEST(test_coscrew_transformations) {
  const double cv[6] = {0.3, -1.4, 0.8, 1.1, 0.25, -0.6};
  ksl_coscrew_t c = ksl_coscrew(cv[0], cv[1], cv[2], cv[3], cv[4], cv[5]), co;
  double e[6], nc[6];
  neg6(cv, nc);
  ref_se3 i1 = ref_inv(&r1), rot = r1, rotinv;
  rot.t[0] = rot.t[1] = rot.t[2] = 0;
  rotinv = ref_inv(&rot);
  ksl_vec3_t t = ksl_vec3(0.3, -0.8, 1.7);
  ref_se3 T = ref_trans(t.at), Tinv = ref_inv(&T);

  ksl_product_CoAdc(&D1, &c, &co);
  ref_CoAd(&r1, cv, e);
  check_n(co.at, e, 6, "CoAdc");
  ksl_product_CoAdcinv(&D1, &c, &co);
  ref_CoAd(&r1, nc, e);
  check_n(co.at, e, 6, "CoAdcinv");
  ksl_product_CoAdinvc(&D1, &c, &co);
  ref_CoAd(&i1, cv, e);
  check_n(co.at, e, 6, "CoAdinvc");
  ksl_product_CoAdrc(&D1.R, &c, &co);
  ref_CoAd(&rot, cv, e);
  check_n(co.at, e, 6, "CoAdrc");
  ksl_product_CoAdrcinv(&D1.R, &c, &co);
  ref_CoAd(&rot, nc, e);
  check_n(co.at, e, 6, "CoAdrcinv");
  ksl_product_CoAdrinvc(&D1.R, &c, &co);
  ref_CoAd(&rotinv, cv, e);
  check_n(co.at, e, 6, "CoAdrinvc");
  ksl_product_CoAdtc(&t, &c, &co);
  ref_CoAd(&T, cv, e);
  check_n(co.at, e, 6, "CoAdtc");
  ksl_product_CoAdtinvc(&t, &c, &co);
  ref_CoAd(&Tinv, cv, e);
  check_n(co.at, e, 6, "CoAdtinvc");
}
END_TEST

START_TEST(test_joint_axis_screws) {
  /* hs*: the screw of a joint axis of frame D, expressed in the reference
  frame: Ad(D) * {0, axis} for a revolute (r) joint and Ad(D) * {axis, 0} for a
  prismatic (t) joint; "inv" negates the axis. */
  typedef void (*fn)(const ksl_SE3_t*, ksl_screw_t*);
  fn hsr[3] = {ksl_hsrx, ksl_hsry, ksl_hsrz};
  fn hsrinv[3] = {ksl_hsrxinv, ksl_hsryinv, ksl_hsrzinv};
  fn hst[3] = {ksl_hstx, ksl_hsty, ksl_hstz};
  fn hstinv[3] = {ksl_hstxinv, ksl_hstyinv, ksl_hstzinv};
  ksl_screw_t so;
  double e[6];
  for(int axis = 0; axis < 3; axis++) {
    for(int sign = 1; sign >= -1; sign -= 2) {
      double rev[6] = {0, 0, 0, 0, 0, 0}, pri[6] = {0, 0, 0, 0, 0, 0};
      rev[3 + axis] = sign;
      pri[axis] = sign;
      (sign > 0 ? hsr : hsrinv)[axis](&D1, &so);
      ref_Ad(&r1, rev, e);
      check_n(so.at, e, 6, "hsr{x,y,z}[inv]");
      (sign > 0 ? hst : hstinv)[axis](&D1, &so);
      ref_Ad(&r1, pri, e);
      check_n(so.at, e, 6, "hst{x,y,z}[inv]");
    }
  }
  ksl_vec3_t a = ksl_vec3(0.2, -0.7, 0.4);
  double rev[6] = {0, 0, 0, a.x, a.y, a.z}, pri[6] = {a.x, a.y, a.z, 0, 0, 0};
  double nrev[6], npri[6];
  neg6(rev, nrev);
  neg6(pri, npri);
  ksl_hsra(&D1, &a, &so);
  ref_Ad(&r1, rev, e);
  check_n(so.at, e, 6, "hsra");
  ksl_hsrainv(&D1, &a, &so);
  ref_Ad(&r1, nrev, e);
  check_n(so.at, e, 6, "hsrainv");
  ksl_hsta(&D1, &a, &so);
  ref_Ad(&r1, pri, e);
  check_n(so.at, e, 6, "hsta");
  ksl_hstainv(&D1, &a, &so);
  ref_Ad(&r1, npri, e);
  check_n(so.at, e, 6, "hstainv");
}
END_TEST

START_TEST(test_joint_axis_coscrews) {
  /* hc*: CoAd(D) * {axis, 0} for a force along (t) an axis of frame D and
  CoAd(D) * {0, axis} for a moment about (r) it; "inv" negates the axis. */
  typedef void (*fn)(const ksl_SE3_t*, ksl_coscrew_t*);
  fn hcr[3] = {ksl_hcrx, ksl_hcry, ksl_hcrz};
  fn hcrinv[3] = {ksl_hcrxinv, ksl_hcryinv, ksl_hcrzinv};
  fn hct[3] = {ksl_hctx, ksl_hcty, ksl_hctz};
  fn hctinv[3] = {ksl_hctxinv, ksl_hctyinv, ksl_hctzinv};
  ksl_coscrew_t co;
  double e[6];
  for(int axis = 0; axis < 3; axis++) {
    for(int sign = 1; sign >= -1; sign -= 2) {
      double mom[6] = {0, 0, 0, 0, 0, 0}, frc[6] = {0, 0, 0, 0, 0, 0};
      mom[3 + axis] = sign;
      frc[axis] = sign;
      (sign > 0 ? hcr : hcrinv)[axis](&D1, &co);
      ref_CoAd(&r1, mom, e);
      check_n(co.at, e, 6, "hcr{x,y,z}[inv]");
      (sign > 0 ? hct : hctinv)[axis](&D1, &co);
      ref_CoAd(&r1, frc, e);
      check_n(co.at, e, 6, "hct{x,y,z}[inv]");
    }
  }
}
END_TEST

START_TEST(test_screw_algebra) {
  const double av[6] = {0.3, -1.4, 0.8, 1.1, 0.25, -0.6};
  const double bv[6] = {-0.9, 0.5, 1.6, -0.35, 0.7, 0.45};
  ksl_screw_t a = ksl_screw(av[0], av[1], av[2], av[3], av[4], av[5]);
  ksl_screw_t b = ksl_screw(bv[0], bv[1], bv[2], bv[3], bv[4], bv[5]), so;
  ksl_coscrew_t c = ksl_coscrew(bv[0], bv[1], bv[2], bv[3], bv[4], bv[5]), co;
  double e[6];

  /* screws whose angular part is zero (pure translations) */
  ksl_add_sst(&a, &b, &so);
  for(int i = 0; i < 6; i++)
    e[i] = av[i] + (i < 3 ? bv[i] : 0);
  check_n(so.at, e, 6, "add_sst");
  ksl_cross_sst(&a, &b, &so);
  ref_cross(av + 3, bv, e);
  e[3] = e[4] = e[5] = 0;
  check_n(so.at, e, 6, "cross_sst");

  /* coscrew cross product s x* c = {w x f, w x n + v x f} */
  ksl_cross_sc(&a, &c, &co);
  double wxf[3], wxn[3], vxf[3];
  ref_cross(av + 3, bv, wxf);
  ref_cross(av + 3, bv + 3, wxn);
  ref_cross(av, bv, vxf);
  for(int i = 0; i < 3; i++) {
    e[i] = wxf[i];
    e[3 + i] = wxn[i] + vxf[i];
  }
  check_n(co.at, e, 6, "cross_sc");
  /* only the angular parts: {0, w x n} */
  ksl_cross_sca(&a, &c, &co);
  for(int i = 0; i < 3; i++) {
    e[i] = 0;
    e[3 + i] = wxn[i];
  }
  check_n(co.at, e, 6, "cross_sca");
  ksl_coscrew_t c2 = ksl_coscrew(av[0], av[1], av[2], av[3], av[4], av[5]);
  ksl_add_cct(&c2, &c, &co);
  for(int i = 0; i < 6; i++)
    e[i] = av[i] + (i < 3 ? bv[i] : 0);
  check_n(co.at, e, 6, "add_cct");
}
END_TEST

Suite* conventions_suite(void) {
  Suite* s = suite_create("Conventions");
  TCase* tc = tcase_create("Core");
  tcase_add_checked_fixture(tc, setup, NULL);
  tcase_add_test(tc, test_dc_is_sin_cos);
  tcase_add_test(tc, test_se3_products);
  tcase_add_test(tc, test_axis_rotations_and_translations);
  tcase_add_test(tc, test_rotation_products);
  tcase_add_test(tc, test_vector_products);
  tcase_add_test(tc, test_screw_transformations);
  tcase_add_test(tc, test_coscrew_transformations);
  tcase_add_test(tc, test_joint_axis_screws);
  tcase_add_test(tc, test_joint_axis_coscrews);
  tcase_add_test(tc, test_screw_algebra);
  suite_add_tcase(s, tc);
  return s;
}

int main(void) {
  SRunner* sr = srunner_create(conventions_suite());
  srunner_run_all(sr, CK_NORMAL);
  int failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
