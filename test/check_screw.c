#include <config.h>

#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "ksl/SE3.h"
#include "ksl/coscrew.h"
#include "ksl/mat3x3.h"
#include "ksl/mat4x4.h"
#include "ksl/matrix.h"
#include "ksl/screw.h"
#include "ksl/vec3.h"

START_TEST(test_screw_create) {
  ksl_screw_t s = ksl_screw(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  int i;
  double v;
  for(i = 0, v = 1.0; i < 6; i++, v += 1.0) {
    ck_assert(s.at[i] == v);
  }
  ck_assert((s.lin.x == 1.0) && (s.m0 == 1.0));
  ck_assert((s.lin.y == 2.0) && (s.m1 == 2.0));
  ck_assert((s.lin.z == 3.0) && (s.m2 == 3.0));
  ck_assert((s.ang.x == 4.0) && (s.m3 == 4.0));
  ck_assert((s.ang.y == 5.0) && (s.m4 == 5.0));
  ck_assert((s.ang.z == 6.0) && (s.m5 == 6.0));
}
END_TEST

START_TEST(test_screwf_create) {
  ksl_screwf_t s = ksl_screwf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  float v;
  int i;
  for(i = 0, v = 1.0; i < 6; i++, v += 1.0) {
    ck_assert(s.at[i] == v);
  }
  ck_assert((s.lin.x == 1.0) && (s.m0 == 1.0));
  ck_assert((s.lin.y == 2.0) && (s.m1 == 2.0));
  ck_assert((s.lin.z == 3.0) && (s.m2 == 3.0));
  ck_assert((s.ang.x == 4.0) && (s.m3 == 4.0));
  ck_assert((s.ang.y == 5.0) && (s.m4 == 5.0));
  ck_assert((s.ang.z == 6.0) && (s.m5 == 6.0));
}
END_TEST

START_TEST(test_screw_alloc) {
  ksl_screw_t s = ksl_screw(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screw_t* s3 = ksl_screw_alloc(3);
  for(int i = 0; i < 3; i++) {
    ksl_screw_copy(&s, &s3[i]);
    int j;
    double v;
    for(j = 0, v = 1.0; j < 6; j++, v += 1.0) {
      ck_assert(s3[i].at[j] == v);
    }
  }
}
END_TEST

START_TEST(test_screwf_alloc) {
  ksl_screwf_t s = ksl_screwf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screwf_t* s3 = ksl_screwf_alloc(3);
  for(int i = 0; i < 3; i++) {
    ksl_screwf_copy(&s, &s3[i]);
    int j;
    float v;
    for(j = 0, v = 1.0; j < 6; j++, v += 1.0) {
      ck_assert(s3[i].at[j] == v);
    }
  }
}
END_TEST

START_TEST(test_screw_norm) {
  ksl_screw_t s1 = ksl_screw(7.0, 8.0, -3.0, 2.0, 1.0, -2.0);
  ck_assert_double_eq_tol(ksl_screw_norm(&s1), 3.0, 1.e-9);
  ksl_screw_t s2 = ksl_screw(2.0, 1.0, -2.0, 0.0, 0.0, 0.0);
  ck_assert_double_eq_tol(ksl_screw_norm(&s2), 3.0, 1.e-9);
}
END_TEST

START_TEST(test_screwf_norm) {
  ksl_screwf_t s1 = ksl_screwf(7.0, 8.0, -3.0, 2.0, 1.0, -2.0);
  ck_assert_float_eq_tol(ksl_screwf_norm(&s1), 3.0, 1.e-5);
  ksl_screwf_t s2 = ksl_screwf(2.0, 1.0, -2.0, 0.0, 0.0, 0.0);
  ck_assert_float_eq_tol(ksl_screwf_norm(&s2), 3.0, 1.e-5);
}
END_TEST

START_TEST(test_screw_normalize) {
  ksl_screw_t s1 = ksl_screw(7.0, 8.0, -3.0, 2.0, 1.0, -2.0);
  ksl_screw_normalize(&s1);
  ck_assert_double_eq_tol(s1.m0, 7.0 / 3.0, 1.e-9);
  ck_assert_double_eq_tol(s1.m1, 8.0 / 3.0, 1.e-9);
  ck_assert_double_eq_tol(s1.m2, -3.0 / 3.0, 1.e-9);
  ck_assert_double_eq_tol(s1.m3, 2.0 / 3.0, 1.e-9);
  ck_assert_double_eq_tol(s1.m4, 1.0 / 3.0, 1.e-9);
  ck_assert_double_eq_tol(s1.m5, -2.0 / 3.0, 1.e-9);
  ksl_screw_t s2 = ksl_screw(2.0, 1.0, -2.0, 0.0, 0.0, 0.0);
  ksl_screw_normalize(&s2);
  ck_assert_double_eq_tol(s2.m0, 2.0 / 3.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m1, 1.0 / 3.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m2, -2.0 / 3.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m3, 0.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m4, 0.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m5, 0.0, 1.e-9);
}
END_TEST

START_TEST(test_screwf_normalize) {
  ksl_screwf_t s1 = ksl_screwf(7.0, 8.0, -3.0, 2.0, 1.0, -2.0);
  ksl_screwf_normalize(&s1);
  ck_assert_float_eq_tol(s1.m0, 7.0 / 3.0, 1.e-5);
  ck_assert_float_eq_tol(s1.m1, 8.0 / 3.0, 1.e-5);
  ck_assert_float_eq_tol(s1.m2, -3.0 / 3.0, 1.e-5);
  ck_assert_float_eq_tol(s1.m3, 2.0 / 3.0, 1.e-5);
  ck_assert_float_eq_tol(s1.m4, 1.0 / 3.0, 1.e-5);
  ck_assert_float_eq_tol(s1.m5, -2.0 / 3.0, 1.e-5);
  ksl_screwf_t s2 = ksl_screwf(2.0, 1.0, -2.0, 0.0, 0.0, 0.0);
  ksl_screwf_normalize(&s2);
  ck_assert_float_eq_tol(s2.m0, 2.0 / 3.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m1, 1.0 / 3.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m2, -2.0 / 3.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m3, 0.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m4, 0.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m5, 0.0, 1.e-5);
}
END_TEST


/* Unit direction u, a point r0 on the axis (not the nearest one), pitch h and amplitude a. */
static const double kAxisU[3] = {1.0 / 3.0, 2.0 / 3.0, 2.0 / 3.0};
static const double kAxisR0[3] = {2.0, 0.0, 2.5};
static const double kPitch = 0.4;
static const double kAmplitude = 2.5;

/* r0 - u (u^T r0), the point of the axis nearest the reference point */
static ksl_vec3_t NearestAxisPoint(void) {
  ksl_vec3_t u = ksl_vec3(kAxisU[0], kAxisU[1], kAxisU[2]);
  ksl_vec3_t r0 = ksl_vec3(kAxisR0[0], kAxisR0[1], kAxisR0[2]);
  double d = ksl_dot_vv(&u, &r0);
  return ksl_vec3(r0.x - d * u.x, r0.y - d * u.y, r0.z - d * u.z);
}

/* A displacement for the invariance checks: rotation about {2; -1; 2}/3 by 0.7 and a
 * translation {0.3; -1.2; 2.0}. */
static ksl_SE3_t InvarianceDisplacement(void) {
  ksl_mat3x3_t R;
  ksl_vec3_t axis = ksl_vec3(2.0 / 3.0, -1.0 / 3.0, 2.0 / 3.0);
  ksl_mat3x3_setFromAxisAngle(&R, &axis, 0.7);
  return ksl_SE3_fromRt(R, ksl_vec3(0.3, -1.2, 2.0));
}

/* |(p - q) x w| and |p^T w| for a point p claimed to be the point of the line through q along w
 * nearest the origin */
static void CheckNearestPoint(const ksl_vec3_t* p, const ksl_vec3_t* q, const ksl_vec3_t* w) {
  ksl_vec3_t d = ksl_vec3(p->x - q->x, p->y - q->y, p->z - q->z);
  ksl_vec3_t c;
  ksl_cross_vv(&d, w, &c);
  ck_assert(ksl_vec3_l2norm(&c) < 1e-12);
  ck_assert(fabs(ksl_dot_vv(p, w)) < 1e-12);
}

START_TEST(test_screw_pitch_axisPoint) {
  /* omega = a u, v = r0 x omega + h omega */
  ksl_vec3_t u = ksl_vec3(kAxisU[0], kAxisU[1], kAxisU[2]);
  ksl_vec3_t r0 = ksl_vec3(kAxisR0[0], kAxisR0[1], kAxisR0[2]);
  ksl_screw_t s;
  s.ang = ksl_vec3(kAmplitude * u.x, kAmplitude * u.y, kAmplitude * u.z);
  ksl_cross_vv(&r0, &s.ang, &s.lin);
  s.lin.x += kPitch * s.ang.x;
  s.lin.y += kPitch * s.ang.y;
  s.lin.z += kPitch * s.ang.z;
  ck_assert_double_eq_tol(ksl_screw_pitch(&s), kPitch, 1e-12);
  ksl_vec3_t p, expected = NearestAxisPoint();
  ck_assert_int_eq(ksl_screw_axisPoint(&s, &p), 0);
  ck_assert_double_eq_tol(p.x, expected.x, 1e-12);
  ck_assert_double_eq_tol(p.y, expected.y, 1e-12);
  ck_assert_double_eq_tol(p.z, expected.z, 1e-12);

  /* the pitch does not depend on the frame; the axis point moves with the axis */
  ksl_SE3_t D = InvarianceDisplacement();
  ksl_screw_t sD;
  ksl_product_Ads(&D, &s, &sD);
  ck_assert_double_eq_tol(ksl_screw_pitch(&sD), kPitch, 1e-12);
  ksl_vec3_t pD, q;
  ck_assert_int_eq(ksl_screw_axisPoint(&sD, &pD), 0);
  ksl_product_dv(&D, &r0, &q);
  CheckNearestPoint(&pD, &q, &sD.ang);

  /* nor on the amplitude */
  ksl_screw_t s2;
  ksl_screw_normalized(&s, &s2);
  ck_assert_double_eq_tol(ksl_screw_pitch(&s2), kPitch, 1e-12);

  /* a pure translation has infinite pitch and no axis; a zero screw has pitch 0 */
  ksl_screw_t t = ksl_screw(1.0, -2.0, 0.5, 0.0, 0.0, 0.0);
  ck_assert(isinf(ksl_screw_pitch(&t)));
  ck_assert_int_eq(ksl_screw_axisPoint(&t, &p), 1);
  ksl_screw_t z = ksl_screw(0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
  ck_assert(ksl_screw_pitch(&z) == 0.0);
  ck_assert_int_eq(ksl_screw_axisPoint(&z, &p), 1);
}
END_TEST

/*
 * A body spins at 2 rad/s about the z axis through c = {1; 0; 0} while that axis
 * translates at u = {0; 3; 0}. At t = 0 the material point at x has acceleration
 * omega x (omega x (x - c)) = -4 (x - c) in the xy plane. The spatial velocity at
 * the origin is {u - omega x c, omega} = {0, 1, 0, 0, 0, 2} and the spatial
 * acceleration its derivative, {-omega x u, 0} = {6, 0, 0, 0, 0, 0}.
 */
START_TEST(test_screw_pointAcceleration) {
  const ksl_screw_t v = ksl_screw(0.0, 1.0, 0.0, 0.0, 0.0, 2.0);
  const ksl_screw_t a = ksl_screw(6.0, 0.0, 0.0, 0.0, 0.0, 0.0);
  ksl_SE3_t D;
  ksl_SE3_setIdentity(&D);
  ksl_vec3_t r_ddot;

  /* at the origin of f: {4; 0; 0}, not the linear part {6; 0; 0} */
  ksl_screw_pointAcceleration(&D, &v, &a, &r_ddot);
  ck_assert_double_eq_tol(r_ddot.x, 4.0, 1e-14);
  ck_assert_double_eq_tol(r_ddot.y, 0.0, 1e-14);
  ck_assert_double_eq_tol(r_ddot.z, 0.0, 1e-14);

  /* on the instantaneous screw axis, x = {-0.5; 0; z}: the linear part, {6; 0; 0} */
  D.t = ksl_vec3(-0.5, 0.0, 7.0);
  ksl_screw_pointAcceleration(&D, &v, &a, &r_ddot);
  ck_assert_double_eq_tol(r_ddot.x, 6.0, 1e-14);
  ck_assert_double_eq_tol(r_ddot.y, 0.0, 1e-14);
  ck_assert_double_eq_tol(r_ddot.z, 0.0, 1e-14);

  /*
   * at p = {1; 2; 0.5}, frame rotated 90 degrees about x: {0; -8; 0} in f, which is
   * {0; 0; 8} in coordinates of p
   */
  const ksl_vec3_t x_axis = ksl_vec3(1.0, 0.0, 0.0);
  ksl_mat3x3_setFromAxisAngle(&D.R, &x_axis, M_PI / 2.0);
  D.t = ksl_vec3(1.0, 2.0, 0.5);
  ksl_screw_pointAcceleration(&D, &v, &a, &r_ddot);
  ck_assert_double_eq_tol(r_ddot.x, 0.0, 1e-14);
  ck_assert_double_eq_tol(r_ddot.y, 0.0, 1e-14);
  ck_assert_double_eq_tol(r_ddot.z, 8.0, 1e-14);
}
END_TEST

START_TEST(test_screwf_pointAcceleration) {
  const ksl_screwf_t v = ksl_screwf(0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 2.0f);
  const ksl_screwf_t a = ksl_screwf(6.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  ksl_SE3f_t D;
  ksl_SE3f_setIdentity(&D);
  const ksl_vec3f_t x_axis = ksl_vec3f(1.0f, 0.0f, 0.0f);
  ksl_mat3x3f_setFromAxisAngle(&D.R, &x_axis, (float)(M_PI / 2.0));
  D.t = ksl_vec3f(1.0f, 2.0f, 0.5f);
  ksl_vec3f_t r_ddot;
  ksl_screwf_pointAcceleration(&D, &v, &a, &r_ddot);
  ck_assert_float_eq_tol(r_ddot.x, 0.0f, 1e-5f);
  ck_assert_float_eq_tol(r_ddot.y, 0.0f, 1e-5f);
  ck_assert_float_eq_tol(r_ddot.z, 8.0f, 1e-5f);
}
END_TEST

START_TEST(test_screwf_pitch_axisPoint) {
  /* pure rotation about the z axis through {1; 2; 0} plus 0.5 along it: v = r x w + h w */
  ksl_screwf_t s = ksl_screwf(4.0, -2.0, 1.0, 0.0, 0.0, 2.0);
  ck_assert_float_eq_tol(ksl_screwf_pitch(&s), 0.5f, 1e-6f);
  ksl_vec3f_t p;
  ck_assert_int_eq(ksl_screwf_axisPoint(&s, &p), 0);
  ck_assert_float_eq_tol(p.x, 1.0f, 1e-6f);
  ck_assert_float_eq_tol(p.y, 2.0f, 1e-6f);
  ck_assert_float_eq_tol(p.z, 0.0f, 1e-6f);
  ksl_screwf_t t = ksl_screwf(1.0, 0.0, 0.0, 0.0, 0.0, 0.0);
  ck_assert(isinf(ksl_screwf_pitch(&t)));
  ck_assert_int_eq(ksl_screwf_axisPoint(&t, &p), 1);
}
END_TEST

START_TEST(test_screw_normalize_scale) {
  /* the amplitude and unit screw do not depend on the size of the screw: a
  screw scaled by 1e-12 or 1e12 has the same unit screw (a fixed cutoff
  would take the small one's angular part as zero) */
  const ksl_screw_t s = ksl_screw(7.0, 8.0, -3.0, 2.0, 1.0, -2.0);
  ksl_screw_t u;
  ksl_screw_normalized(&s, &u);
  /* the pitch is unchanged */
  double h = ksl_dot_vv(&s.ang, &s.lin) / ksl_dot_vv(&s.ang, &s.ang);
  double hn = ksl_dot_vv(&u.ang, &u.lin) / ksl_dot_vv(&u.ang, &u.ang);
  ck_assert_double_eq_tol(hn, h, 1e-12);
  ck_assert_double_eq_tol(ksl_vec3_l2norm(&u.ang), 1.0, 1e-15);
  const double scales[2] = {1e-12, 1e12};
  for(int j = 0; j < 2; j++) {
    ksl_screw_t t = s;
    ksl_screw_scale(&t, scales[j]);
    ck_assert_double_eq_tol(ksl_screw_norm(&t), 3.0 * scales[j],
                            1e-15 * scales[j]);
    ksl_screw_normalize(&t);
    for(int i = 0; i < 6; i++) {
      ck_assert_double_eq_tol(t.at[i], u.at[i], 1e-14);
    }
  }
  ksl_screwf_t sf = ksl_screwf(7.0, 8.0, -3.0, 2.0, 1.0, -2.0);
  ksl_screwf_scale(&sf, 1e-12f);
  ksl_screwf_normalize(&sf);
  for(int i = 0; i < 6; i++) {
    ck_assert_float_eq_tol(sf.at[i], u.at[i], 1e-6);
  }
}
END_TEST

START_TEST(test_screw_normalize_degenerate) {
  /* a angular part at round-off level relative to the linear part: treated as
  zero, so the linear part is normalized */
  ksl_screw_t s = ksl_screw(3.0, 0.0, 4.0, 1e-16, 0.0, 0.0);
  ck_assert_double_eq_tol(ksl_screw_norm(&s), 5.0, 1e-15);
  ksl_screw_normalize(&s);
  const double expected[6] = {0.6, 0.0, 0.8, 1e-16 / 5.0, 0.0, 0.0};
  for(int i = 0; i < 6; i++) {
    ck_assert_double_eq_tol(s.at[i], expected[i], 1e-15);
  }
  ksl_screwf_t sf = ksl_screwf(3.0, 0.0, 4.0, 1e-9, 0.0, 0.0);
  ck_assert_float_eq_tol(ksl_screwf_norm(&sf), 5.0f, 1e-6);

  /* a zero screw has amplitude zero and is left unchanged, not NaN */
  ksl_screw_t z = ksl_screw(0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
  ck_assert(ksl_screw_norm(&z) == 0.0);
  ksl_screw_normalize(&z);
  ksl_screwf_t zf = ksl_screwf(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  ck_assert(ksl_screwf_norm(&zf) == 0.0f);
  ksl_screwf_normalize(&zf);
  for(int i = 0; i < 6; i++) {
    ck_assert(z.at[i] == 0.0);
    ck_assert(zf.at[i] == 0.0f);
  }
}
END_TEST

START_TEST(test_dot_cs) {
  ksl_screw_t s = ksl_screw(1.0, 2.0, 3.0, -3.0, -2.0, -1.0);
  ksl_coscrew_t c = ksl_coscrew(-1.0, -2.0, -3.0, 3.0, 2.0, 1.0);
  ck_assert_double_eq_tol(ksl_dot_cs(&c, &s), -28.0, 1.e-9);
}
END_TEST

START_TEST(test_dot_csf) {
  ksl_screwf_t s = ksl_screwf(1.0, 2.0, 3.0, -3.0, -2.0, -1.0);
  ksl_coscrewf_t c = ksl_coscrewf(-1.0, -2.0, -3.0, 3.0, 2.0, 1.0);
  ck_assert_float_eq_tol(ksl_dot_csf(&c, &s), -28.0, 1.e-5);
}
END_TEST

START_TEST(test_screw_scale) {
  ksl_screw_t s = ksl_screw(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screw_scale(&s, 2.0);
  int i;
  double v;
  for(i = 0, v = 2.0; i < 6; i++, v += 2.0) {
    ck_assert(s.at[i] == v);
  }
}
END_TEST

START_TEST(test_screwf_scale) {
  ksl_screwf_t s = ksl_screwf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screwf_scale(&s, 2.0);
  int i;
  double v;
  for(i = 0, v = 2.0; i < 6; i++, v += 2.0) {
    ck_assert(s.at[i] == v);
  }
}
END_TEST

START_TEST(test_screw_copy) {
  ksl_screw_t s1 = ksl_screw(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screw_t s2 = ksl_screw(-1.0, -2.0, -3.0, -4.0, -5.0, -6.0);
  ksl_screw_copy(&s1, &s2);
  ck_assert_double_eq_tol(s2.m0, 1.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m1, 2.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m2, 3.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m3, 4.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m4, 5.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m5, 6.0, 1.e-9);
}
END_TEST

START_TEST(test_screwf_copy) {
  ksl_screwf_t s1 = ksl_screwf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screwf_t s2 = ksl_screwf(-1.0, -2.0, -3.0, -4.0, -5.0, -6.0);
  ksl_screwf_copy(&s1, &s2);
  ck_assert_float_eq_tol(s2.m0, 1.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m1, 2.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m2, 3.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m3, 4.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m4, 5.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m5, 6.0, 1.e-5);
}
END_TEST

START_TEST(test_screw_invert) {
  ksl_screw_t s1 = ksl_screw(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screw_invert(&s1);
  ck_assert_double_eq_tol(s1.m0, -1.0, 1.e-9);
  ck_assert_double_eq_tol(s1.m1, -2.0, 1.e-9);
  ck_assert_double_eq_tol(s1.m2, -3.0, 1.e-9);
  ck_assert_double_eq_tol(s1.m3, -4.0, 1.e-9);
  ck_assert_double_eq_tol(s1.m4, -5.0, 1.e-9);
  ck_assert_double_eq_tol(s1.m5, -6.0, 1.e-9);
}
END_TEST

START_TEST(test_screwf_invert) {
  ksl_screwf_t s1 = ksl_screwf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screwf_invert(&s1);
  ck_assert_float_eq_tol(s1.m0, -1.0, 1.e-5);
  ck_assert_float_eq_tol(s1.m1, -2.0, 1.e-5);
  ck_assert_float_eq_tol(s1.m2, -3.0, 1.e-5);
  ck_assert_float_eq_tol(s1.m3, -4.0, 1.e-5);
  ck_assert_float_eq_tol(s1.m4, -5.0, 1.e-5);
  ck_assert_float_eq_tol(s1.m5, -6.0, 1.e-5);
}
END_TEST

START_TEST(test_screw_inverted) {
  ksl_screw_t s1 = ksl_screw(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screw_t s2 = ksl_screw(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screw_inverted(&s1, &s2);
  ck_assert_double_eq_tol(s2.m0, -1.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m1, -2.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m2, -3.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m3, -4.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m4, -5.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m5, -6.0, 1.e-9);
}
END_TEST

START_TEST(test_screwf_inverted) {
  ksl_screwf_t s1 = ksl_screwf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screwf_t s2 = ksl_screwf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screwf_inverted(&s1, &s2);
  ck_assert_float_eq_tol(s2.m0, -1.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m1, -2.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m2, -3.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m3, -4.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m4, -5.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m5, -6.0, 1.e-5);
}
END_TEST

START_TEST(test_axpy_ss) {
  ksl_screw_t s1 = ksl_screw(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screw_t s2 = ksl_screw(-2.0, -4.0, -6.0, -8.0, -10.0, -12.0);
  ksl_axpy_ss(5.0, &s1, &s2);
  ck_assert_double_eq_tol(s2.m0, 3.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m1, 6.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m2, 9.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m3, 12.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m4, 15.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m5, 18.0, 1.e-9);
}
END_TEST

START_TEST(test_axpy_ssf) {
  ksl_screwf_t s1 = ksl_screwf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screwf_t s2 = ksl_screwf(-2.0, -4.0, -6.0, -8.0, -10.0, -12.0);
  ksl_axpy_ssf(5.0, &s1, &s2);
  ck_assert_float_eq_tol(s2.m0, 3.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m1, 6.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m2, 9.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m3, 12.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m4, 15.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m5, 18.0, 1.e-5);
}
END_TEST

START_TEST(test_xpy_ss) {
  ksl_screw_t s1 = ksl_screw(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screw_t s2 = ksl_screw(10.0, 20.0, 30.0, 40.0, 50.0, 60.0);
  ksl_xpy_ss(&s1, &s2);
  ck_assert_double_eq_tol(s2.m0, 11.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m1, 22.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m2, 33.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m3, 44.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m4, 55.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m5, 66.0, 1.e-9);
}
END_TEST

START_TEST(test_xpy_ssf) {
  ksl_screwf_t s1 = ksl_screwf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screwf_t s2 = ksl_screwf(10.0, 20.0, 30.0, 40.0, 50.0, 60.0);
  ksl_xpy_ssf(&s1, &s2);
  ck_assert_float_eq_tol(s2.m0, 11.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m1, 22.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m2, 33.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m3, 44.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m4, 55.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m5, 66.0, 1.e-5);
}
END_TEST

START_TEST(test_nxpy_ss) {
  ksl_screw_t s1 = ksl_screw(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screw_t s2 = ksl_screw(10.0, 20.0, 30.0, 40.0, 50.0, 60.0);
  ksl_nxpy_ss(&s1, &s2);
  ck_assert_double_eq_tol(s2.m0, 9.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m1, 18.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m2, 27.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m3, 36.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m4, 45.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m5, 54.0, 1.e-9);
}
END_TEST

START_TEST(test_nxpy_ssf) {
  ksl_screwf_t s1 = ksl_screwf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screwf_t s2 = ksl_screwf(10.0, 20.0, 30.0, 40.0, 50.0, 60.0);
  ksl_nxpy_ssf(&s1, &s2);
  ck_assert_float_eq_tol(s2.m0, 9.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m1, 18.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m2, 27.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m3, 36.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m4, 45.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m5, 54.0, 1.e-5);
}
END_TEST

START_TEST(test_product_as) {
  ksl_screw_t s1 = ksl_screw(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screw_t s2 = ksl_screw(-1.0, -2.0, -3.0, -4.0, -5.0, -6.0);
  ksl_product_as(2.0, &s1, &s2);
  ck_assert_double_eq_tol(s2.m0, 2.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m1, 4.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m2, 6.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m3, 8.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m4, 10.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m5, 12.0, 1.e-9);
}
END_TEST

START_TEST(test_product_asf) {
  ksl_screwf_t s1 = ksl_screwf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screwf_t s2 = ksl_screwf(-1.0, -2.0, -3.0, -4.0, -5.0, -6.0);
  ksl_product_asf(2.0, &s1, &s2);
  ck_assert_float_eq_tol(s2.m0, 2.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m1, 4.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m2, 6.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m3, 8.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m4, 10.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m5, 12.0, 1.e-5);
}
END_TEST

START_TEST(test_add_ss) {
  ksl_screw_t s1 = ksl_screw(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screw_t s2 = ksl_screw(10.0, 20.0, 30.0, 40.0, 50.0, 60.0);
  ksl_screw_t s3;
  ksl_add_ss(&s1, &s2, &s3);
  ck_assert_double_eq_tol(s3.m0, 11.0, 1.e-9);
  ck_assert_double_eq_tol(s3.m1, 22.0, 1.e-9);
  ck_assert_double_eq_tol(s3.m2, 33.0, 1.e-9);
  ck_assert_double_eq_tol(s3.m3, 44.0, 1.e-9);
  ck_assert_double_eq_tol(s3.m4, 55.0, 1.e-9);
  ck_assert_double_eq_tol(s3.m5, 66.0, 1.e-9);
}
END_TEST

START_TEST(test_add_ssf) {
  ksl_screwf_t s1 = ksl_screwf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screwf_t s2 = ksl_screwf(10.0, 20.0, 30.0, 40.0, 50.0, 60.0);
  ksl_screwf_t s3;
  ksl_add_ssf(&s1, &s2, &s3);
  ck_assert_float_eq_tol(s3.m0, 11.0, 1.e-5);
  ck_assert_float_eq_tol(s3.m1, 22.0, 1.e-5);
  ck_assert_float_eq_tol(s3.m2, 33.0, 1.e-5);
  ck_assert_float_eq_tol(s3.m3, 44.0, 1.e-5);
  ck_assert_float_eq_tol(s3.m4, 55.0, 1.e-5);
  ck_assert_float_eq_tol(s3.m5, 66.0, 1.e-5);
}
END_TEST

START_TEST(test_subtract_ss) {
  ksl_screw_t s1 = ksl_screw(10.0, 20.0, 30.0, 40.0, 50.0, 60.0);
  ksl_screw_t s2 = ksl_screw(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screw_t s3;
  ksl_subtract_ss(&s1, &s2, &s3);
  ck_assert_double_eq_tol(s3.m0, 9.0, 1.e-9);
  ck_assert_double_eq_tol(s3.m1, 18.0, 1.e-9);
  ck_assert_double_eq_tol(s3.m2, 27.0, 1.e-9);
  ck_assert_double_eq_tol(s3.m3, 36.0, 1.e-9);
  ck_assert_double_eq_tol(s3.m4, 45.0, 1.e-9);
  ck_assert_double_eq_tol(s3.m5, 54.0, 1.e-9);
}
END_TEST

START_TEST(test_subtract_ssf) {
  ksl_screwf_t s1 = ksl_screwf(10.0, 20.0, 30.0, 40.0, 50.0, 60.0);
  ksl_screwf_t s2 = ksl_screwf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screwf_t s3;
  ksl_subtract_ssf(&s1, &s2, &s3);
  ck_assert_float_eq_tol(s3.m0, 9.0, 1.e-5);
  ck_assert_float_eq_tol(s3.m1, 18.0, 1.e-5);
  ck_assert_float_eq_tol(s3.m2, 27.0, 1.e-5);
  ck_assert_float_eq_tol(s3.m3, 36.0, 1.e-5);
  ck_assert_float_eq_tol(s3.m4, 45.0, 1.e-5);
  ck_assert_float_eq_tol(s3.m5, 54.0, 1.e-5);
}
END_TEST

START_TEST(test_add_sst) {
  ksl_screw_t s1 = ksl_screw(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screw_t s2 = ksl_screw(10.0, 20.0, 30.0, 0.0, 0.0, 0.0);
  ksl_screw_t s3;
  ksl_add_sst(&s1, &s2, &s3);
  ck_assert_double_eq_tol(s3.m0, 11.0, 1.e-9);
  ck_assert_double_eq_tol(s3.m1, 22.0, 1.e-9);
  ck_assert_double_eq_tol(s3.m2, 33.0, 1.e-9);
  ck_assert_double_eq_tol(s3.m3, 4.0, 1.e-9);
  ck_assert_double_eq_tol(s3.m4, 5.0, 1.e-9);
  ck_assert_double_eq_tol(s3.m5, 6.0, 1.e-9);
}
END_TEST

START_TEST(test_add_sstf) {
  ksl_screwf_t s1 = ksl_screwf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screwf_t s2 = ksl_screwf(10.0, 20.0, 30.0, 0.0, 0.0, 0.0);
  ksl_screwf_t s3;
  ksl_add_sstf(&s1, &s2, &s3);
  ck_assert_float_eq_tol(s3.m0, 11.0, 1.e-5);
  ck_assert_float_eq_tol(s3.m1, 22.0, 1.e-5);
  ck_assert_float_eq_tol(s3.m2, 33.0, 1.e-5);
  ck_assert_float_eq_tol(s3.m3, 4.0, 1.e-5);
  ck_assert_float_eq_tol(s3.m4, 5.0, 1.e-5);
  ck_assert_float_eq_tol(s3.m5, 6.0, 1.e-5);
}
END_TEST

START_TEST(test_hstx) {
  ksl_SE3_t D =
    ksl_SE3(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
            7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
            2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_screw_t s = ksl_screw(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hstx(&D, &s);
  ck_assert_double_eq_tol(s.m0, 5.72061402818e-01, 1.e-9);
  ck_assert_double_eq_tol(s.m1, 7.89312333511e-01, 1.e-9);
  ck_assert_double_eq_tol(s.m2, 2.23006259046e-01, 1.e-9);
  ck_assert_double_eq_tol(s.m3, 0.0, 1.e-9);
  ck_assert_double_eq_tol(s.m4, 0.0, 1.e-9);
  ck_assert_double_eq_tol(s.m5, 0.0, 1.e-9);
}
END_TEST

START_TEST(test_hstxf) {
  ksl_SE3f_t D =
    ksl_SE3f(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
             7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
             2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_screwf_t s = ksl_screwf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hstxf(&D, &s);
  ck_assert_float_eq_tol(s.m0, 5.72061402818e-01, 1.e-5);
  ck_assert_float_eq_tol(s.m1, 7.89312333511e-01, 1.e-5);
  ck_assert_float_eq_tol(s.m2, 2.23006259046e-01, 1.e-5);
  ck_assert_float_eq_tol(s.m3, 0.0, 1.e-5);
  ck_assert_float_eq_tol(s.m4, 0.0, 1.e-5);
  ck_assert_float_eq_tol(s.m5, 0.0, 1.e-5);
}
END_TEST

START_TEST(test_hsty) {
  ksl_SE3_t D =
    ksl_SE3(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
            7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
            2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_screw_t s = ksl_screw(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hsty(&D, &s);
  ck_assert_double_eq_tol(s.m0, -4.15626937777e-01, 1.e-9);
  ck_assert_double_eq_tol(s.m1, 4.45650105751e-02, 1.e-9);
  ck_assert_double_eq_tol(s.m2, 9.08442738111e-01, 1.e-9);
  ck_assert_double_eq_tol(s.m3, 0.0, 1.e-9);
  ck_assert_double_eq_tol(s.m4, 0.0, 1.e-9);
  ck_assert_double_eq_tol(s.m5, 0.0, 1.e-9);
}
END_TEST

START_TEST(test_hstyf) {
  ksl_SE3f_t D =
    ksl_SE3f(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
             7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
             2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_screwf_t s = ksl_screwf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hstyf(&D, &s);
  ck_assert_float_eq_tol(s.m0, -4.15626937777e-01, 1.e-5);
  ck_assert_float_eq_tol(s.m1, 4.45650105751e-02, 1.e-5);
  ck_assert_float_eq_tol(s.m2, 9.08442738111e-01, 1.e-5);
  ck_assert_float_eq_tol(s.m3, 0.0, 1.e-5);
  ck_assert_float_eq_tol(s.m4, 0.0, 1.e-5);
  ck_assert_float_eq_tol(s.m5, 0.0, 1.e-5);
}
END_TEST

START_TEST(test_hstz) {
  ksl_SE3_t D =
    ksl_SE3(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
            7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
            2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_screw_t s = ksl_screw(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hstz(&D, &s);
  ck_assert_double_eq_tol(s.m0, 7.07106781187e-01, 1.e-9);
  ck_assert_double_eq_tol(s.m1, -6.12372435696e-01, 1.e-9);
  ck_assert_double_eq_tol(s.m2, 3.53553390593e-01, 1.e-9);
  ck_assert_double_eq_tol(s.m3, 0.0, 1.e-9);
  ck_assert_double_eq_tol(s.m4, 0.0, 1.e-9);
  ck_assert_double_eq_tol(s.m5, 0.0, 1.e-9);
}
END_TEST

START_TEST(test_hstzf) {
  ksl_SE3f_t D =
    ksl_SE3f(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
             7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
             2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_screwf_t s = ksl_screwf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hstzf(&D, &s);
  ck_assert_float_eq_tol(s.m0, 7.07106781187e-01, 1.e-5);
  ck_assert_float_eq_tol(s.m1, -6.12372435696e-01, 1.e-5);
  ck_assert_float_eq_tol(s.m2, 3.53553390593e-01, 1.e-5);
  ck_assert_float_eq_tol(s.m3, 0.0, 1.e-5);
  ck_assert_float_eq_tol(s.m4, 0.0, 1.e-5);
  ck_assert_float_eq_tol(s.m5, 0.0, 1.e-5);
}
END_TEST

START_TEST(test_hsrx) {
  ksl_SE3_t D =
    ksl_SE3(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
            7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
            2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_screw_t s = ksl_screw(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hsrx(&D, &s);
  ck_assert_double_eq_tol(s.m0, -1.92192448244e+00, 1.e-9);
  ck_assert_double_eq_tol(s.m1, 1.49317794941e+00, 1.e-9);
  ck_assert_double_eq_tol(s.m2, -3.54810472124e-01, 1.e-9);
  ck_assert_double_eq_tol(s.m3, 5.72061402818e-01, 1.e-9);
  ck_assert_double_eq_tol(s.m4, 7.89312333511e-01, 1.e-9);
  ck_assert_double_eq_tol(s.m5, 2.23006259046e-01, 1.e-9);
}
END_TEST

START_TEST(test_hsrxf) {
  ksl_SE3f_t D =
    ksl_SE3f(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
             7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
             2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_screwf_t s = ksl_screwf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hsrxf(&D, &s);
  ck_assert_float_eq_tol(s.m0, -1.92192448244e+00, 1.e-5);
  ck_assert_float_eq_tol(s.m1, 1.49317794941e+00, 1.e-5);
  ck_assert_float_eq_tol(s.m2, -3.54810472124e-01, 1.e-5);
  ck_assert_float_eq_tol(s.m3, 5.72061402818e-01, 1.e-5);
  ck_assert_float_eq_tol(s.m4, 7.89312333511e-01, 1.e-5);
  ck_assert_float_eq_tol(s.m5, 2.23006259046e-01, 1.e-5);
}
END_TEST

START_TEST(test_hsry) {
  ksl_SE3_t D =
    ksl_SE3(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
            7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
            2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_screw_t s = ksl_screw(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hsry(&D, &s);
  ck_assert_double_eq_tol(s.m0, 1.68319044450e+00, 1.e-9);
  ck_assert_double_eq_tol(s.m1, -2.15532355144e+00, 1.e-9);
  ck_assert_double_eq_tol(s.m2, 8.75818886130e-01, 1.e-9);
  ck_assert_double_eq_tol(s.m3, -4.15626937777e-01, 1.e-9);
  ck_assert_double_eq_tol(s.m4, 4.45650105751e-02, 1.e-9);
  ck_assert_double_eq_tol(s.m5, 9.08442738111e-01, 1.e-9);
}
END_TEST

START_TEST(test_hsryf) {
  ksl_SE3f_t D =
    ksl_SE3f(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
             7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
             2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_screwf_t s = ksl_screwf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hsryf(&D, &s);
  ck_assert_float_eq_tol(s.m0, 1.68319044450e+00, 1.e-5);
  ck_assert_float_eq_tol(s.m1, -2.15532355144e+00, 1.e-5);
  ck_assert_float_eq_tol(s.m2, 8.75818886130e-01, 1.e-5);
  ck_assert_float_eq_tol(s.m3, -4.15626937777e-01, 1.e-5);
  ck_assert_float_eq_tol(s.m4, 4.45650105751e-02, 1.e-5);
  ck_assert_float_eq_tol(s.m5, 9.08442738111e-01, 1.e-5);
}
END_TEST

START_TEST(test_hsrz) {
  ksl_SE3_t D =
    ksl_SE3(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
            7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
            2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_screw_t s = ksl_screw(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hsrz(&D, &s);
  ck_assert_double_eq_tol(s.m0, 2.54422408827e+00, 1.e-9);
  ck_assert_double_eq_tol(s.m1, 1.76776695297e+00, 1.e-9);
  ck_assert_double_eq_tol(s.m2, -2.02658599807e+00, 1.e-9);
  ck_assert_double_eq_tol(s.m3, 7.07106781187e-01, 1.e-9);
  ck_assert_double_eq_tol(s.m4, -6.12372435696e-01, 1.e-9);
  ck_assert_double_eq_tol(s.m5, 3.53553390593e-01, 1.e-9);
}
END_TEST

START_TEST(test_hsrzf) {
  ksl_SE3f_t D =
    ksl_SE3f(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
             7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
             2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_screwf_t s = ksl_screwf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hsrzf(&D, &s);
  ck_assert_float_eq_tol(s.m0, 2.54422408827e+00, 1.e-5);
  ck_assert_float_eq_tol(s.m1, 1.76776695297e+00, 1.e-5);
  ck_assert_float_eq_tol(s.m2, -2.02658599807e+00, 1.e-5);
  ck_assert_float_eq_tol(s.m3, 7.07106781187e-01, 1.e-5);
  ck_assert_float_eq_tol(s.m4, -6.12372435696e-01, 1.e-5);
  ck_assert_float_eq_tol(s.m5, 3.53553390593e-01, 1.e-5);
}
END_TEST

START_TEST(test_hstxinv) {
  ksl_SE3_t D =
    ksl_SE3(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
            7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
            2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_screw_t s = ksl_screw(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hstxinv(&D, &s);
  ck_assert_double_eq_tol(s.m0, -5.72061402818e-01, 1.e-9);
  ck_assert_double_eq_tol(s.m1, -7.89312333511e-01, 1.e-9);
  ck_assert_double_eq_tol(s.m2, -2.23006259046e-01, 1.e-9);
  ck_assert_double_eq_tol(s.m3, 0.0, 1.e-9);
  ck_assert_double_eq_tol(s.m4, 0.0, 1.e-9);
  ck_assert_double_eq_tol(s.m5, 0.0, 1.e-9);
}
END_TEST

START_TEST(test_hstxinvf) {
  ksl_SE3f_t D =
    ksl_SE3f(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
             7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
             2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_screwf_t s = ksl_screwf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hstxinvf(&D, &s);
  ck_assert_float_eq_tol(s.m0, -5.72061402818e-01, 1.e-5);
  ck_assert_float_eq_tol(s.m1, -7.89312333511e-01, 1.e-5);
  ck_assert_float_eq_tol(s.m2, -2.23006259046e-01, 1.e-5);
  ck_assert_float_eq_tol(s.m3, 0.0, 1.e-5);
  ck_assert_float_eq_tol(s.m4, 0.0, 1.e-5);
  ck_assert_float_eq_tol(s.m5, 0.0, 1.e-5);
}
END_TEST

START_TEST(test_hstyinv) {
  ksl_SE3_t D =
    ksl_SE3(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
            7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
            2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_screw_t s = ksl_screw(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hstyinv(&D, &s);
  ck_assert_double_eq_tol(s.m0, 4.15626937777e-01, 1.e-9);
  ck_assert_double_eq_tol(s.m1, -4.45650105751e-02, 1.e-9);
  ck_assert_double_eq_tol(s.m2, -9.08442738111e-01, 1.e-9);
  ck_assert_double_eq_tol(s.m3, 0.0, 1.e-9);
  ck_assert_double_eq_tol(s.m4, 0.0, 1.e-9);
  ck_assert_double_eq_tol(s.m5, 0.0, 1.e-9);
}
END_TEST

START_TEST(test_hstyinvf) {
  ksl_SE3f_t D =
    ksl_SE3f(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
             7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
             2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_screwf_t s = ksl_screwf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hstyinvf(&D, &s);
  ck_assert_float_eq_tol(s.m0, 4.15626937777e-01, 1.e-5);
  ck_assert_float_eq_tol(s.m1, -4.45650105751e-02, 1.e-5);
  ck_assert_float_eq_tol(s.m2, -9.08442738111e-01, 1.e-5);
  ck_assert_float_eq_tol(s.m3, 0.0, 1.e-5);
  ck_assert_float_eq_tol(s.m4, 0.0, 1.e-5);
  ck_assert_float_eq_tol(s.m5, 0.0, 1.e-5);
}
END_TEST

START_TEST(test_hstzinv) {
  ksl_SE3_t D =
    ksl_SE3(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
            7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
            2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_screw_t s = ksl_screw(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hstzinv(&D, &s);
  ck_assert_double_eq_tol(s.m0, -7.07106781187e-01, 1.e-9);
  ck_assert_double_eq_tol(s.m1, 6.12372435696e-01, 1.e-9);
  ck_assert_double_eq_tol(s.m2, -3.53553390593e-01, 1.e-9);
  ck_assert_double_eq_tol(s.m3, 0.0, 1.e-9);
  ck_assert_double_eq_tol(s.m4, 0.0, 1.e-9);
  ck_assert_double_eq_tol(s.m5, 0.0, 1.e-9);
}
END_TEST

START_TEST(test_hstzinvf) {
  ksl_SE3f_t D =
    ksl_SE3f(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
             7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
             2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_screwf_t s = ksl_screwf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hstzinvf(&D, &s);
  ck_assert_float_eq_tol(s.m0, -7.07106781187e-01, 1.e-5);
  ck_assert_float_eq_tol(s.m1, 6.12372435696e-01, 1.e-5);
  ck_assert_float_eq_tol(s.m2, -3.53553390593e-01, 1.e-5);
  ck_assert_float_eq_tol(s.m3, 0.0, 1.e-5);
  ck_assert_float_eq_tol(s.m4, 0.0, 1.e-5);
  ck_assert_float_eq_tol(s.m5, 0.0, 1.e-5);
}
END_TEST

START_TEST(test_hsrxinv) {
  ksl_SE3_t D =
    ksl_SE3(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
            7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
            2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_screw_t s = ksl_screw(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hsrxinv(&D, &s);
  ck_assert_double_eq_tol(s.m0, 1.92192448244e+00, 1.e-9);
  ck_assert_double_eq_tol(s.m1, -1.49317794941e+00, 1.e-9);
  ck_assert_double_eq_tol(s.m2, 3.54810472124e-01, 1.e-9);
  ck_assert_double_eq_tol(s.m3, -5.72061402818e-01, 1.e-9);
  ck_assert_double_eq_tol(s.m4, -7.89312333511e-01, 1.e-9);
  ck_assert_double_eq_tol(s.m5, -2.23006259046e-01, 1.e-9);
}
END_TEST

START_TEST(test_hsrxinvf) {
  ksl_SE3f_t D =
    ksl_SE3f(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
             7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
             2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_screwf_t s = ksl_screwf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hsrxinvf(&D, &s);
  ck_assert_float_eq_tol(s.m0, 1.92192448244e+00, 1.e-5);
  ck_assert_float_eq_tol(s.m1, -1.49317794941e+00, 1.e-5);
  ck_assert_float_eq_tol(s.m2, 3.54810472124e-01, 1.e-5);
  ck_assert_float_eq_tol(s.m3, -5.72061402818e-01, 1.e-5);
  ck_assert_float_eq_tol(s.m4, -7.89312333511e-01, 1.e-5);
  ck_assert_float_eq_tol(s.m5, -2.23006259046e-01, 1.e-5);
}
END_TEST

START_TEST(test_hsryinv) {
  ksl_SE3_t D =
    ksl_SE3(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
            7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
            2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_screw_t s = ksl_screw(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hsryinv(&D, &s);
  ck_assert_double_eq_tol(s.m0, -1.68319044450e+00, 1.e-9);
  ck_assert_double_eq_tol(s.m1, 2.15532355144e+00, 1.e-9);
  ck_assert_double_eq_tol(s.m2, -8.75818886130e-01, 1.e-9);
  ck_assert_double_eq_tol(s.m3, 4.15626937777e-01, 1.e-9);
  ck_assert_double_eq_tol(s.m4, -4.45650105751e-02, 1.e-9);
  ck_assert_double_eq_tol(s.m5, -9.08442738111e-01, 1.e-9);
}
END_TEST

START_TEST(test_hsryinvf) {
  ksl_SE3f_t D =
    ksl_SE3f(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
             7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
             2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_screwf_t s = ksl_screwf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hsryinvf(&D, &s);
  ck_assert_float_eq_tol(s.m0, -1.68319044450e+00, 1.e-5);
  ck_assert_float_eq_tol(s.m1, 2.15532355144e+00, 1.e-5);
  ck_assert_float_eq_tol(s.m2, -8.75818886130e-01, 1.e-5);
  ck_assert_float_eq_tol(s.m3, 4.15626937777e-01, 1.e-5);
  ck_assert_float_eq_tol(s.m4, -4.45650105751e-02, 1.e-5);
  ck_assert_float_eq_tol(s.m5, -9.08442738111e-01, 1.e-5);
}
END_TEST

START_TEST(test_hsrzinv) {
  ksl_SE3_t D =
    ksl_SE3(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
            7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
            2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_screw_t s = ksl_screw(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hsrzinv(&D, &s);
  ck_assert_double_eq_tol(s.m0, -2.54422408827e+00, 1.e-9);
  ck_assert_double_eq_tol(s.m1, -1.76776695297e+00, 1.e-9);
  ck_assert_double_eq_tol(s.m2, 2.02658599807e+00, 1.e-9);
  ck_assert_double_eq_tol(s.m3, -7.07106781187e-01, 1.e-9);
  ck_assert_double_eq_tol(s.m4, 6.12372435696e-01, 1.e-9);
  ck_assert_double_eq_tol(s.m5, -3.53553390593e-01, 1.e-9);
}
END_TEST

START_TEST(test_hsrzinvf) {
  ksl_SE3f_t D =
    ksl_SE3f(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
             7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
             2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_screwf_t s = ksl_screwf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hsrzinvf(&D, &s);
  ck_assert_float_eq_tol(s.m0, -2.54422408827e+00, 1.e-5);
  ck_assert_float_eq_tol(s.m1, -1.76776695297e+00, 1.e-5);
  ck_assert_float_eq_tol(s.m2, 2.02658599807e+00, 1.e-5);
  ck_assert_float_eq_tol(s.m3, -7.07106781187e-01, 1.e-5);
  ck_assert_float_eq_tol(s.m4, 6.12372435696e-01, 1.e-5);
  ck_assert_float_eq_tol(s.m5, -3.53553390593e-01, 1.e-5);
}
END_TEST

START_TEST(test_cross_ss) {
  ksl_screw_t s1 = ksl_screw(4.0, 5.0, 6.0, 1.0, 2.0, 3.0);
  ksl_screw_t s2 = ksl_screw(6.0, 5.0, 4.0, 3.0, 2.0, 1.0);
  ksl_screw_t s3;
  ksl_cross_ss(&s1, &s2, &s3);
  ck_assert_double_eq_tol(s3.m0, -14.0, 1.e-9);
  ck_assert_double_eq_tol(s3.m1, 28.0, 1.e-9);
  ck_assert_double_eq_tol(s3.m2, -14.0, 1.e-9);
  ck_assert_double_eq_tol(s3.m3, -4.0, 1.e-9);
  ck_assert_double_eq_tol(s3.m4, 8.0, 1.e-9);
  ck_assert_double_eq_tol(s3.m5, -4.0, 1.e-9);
}
END_TEST

START_TEST(test_cross_ssf) {
  ksl_screwf_t s1 = ksl_screwf(4.0, 5.0, 6.0, 1.0, 2.0, 3.0);
  ksl_screwf_t s2 = ksl_screwf(6.0, 5.0, 4.0, 3.0, 2.0, 1.0);
  ksl_screwf_t s3;
  ksl_cross_ssf(&s1, &s2, &s3);
  ck_assert_float_eq_tol(s3.m0, -14.0, 1.e-5);
  ck_assert_float_eq_tol(s3.m1, 28.0, 1.e-5);
  ck_assert_float_eq_tol(s3.m2, -14.0, 1.e-5);
  ck_assert_float_eq_tol(s3.m3, -4.0, 1.e-5);
  ck_assert_float_eq_tol(s3.m4, 8.0, 1.e-5);
  ck_assert_float_eq_tol(s3.m5, -4.0, 1.e-5);
}
END_TEST

START_TEST(test_cross_sst) {
  ksl_screw_t s1 = ksl_screw(4.0, 5.0, 6.0, 1.0, 2.0, 3.0);
  ksl_screw_t s2 = ksl_screw(6.0, 5.0, 4.0, 0.0, 0.0, 0.0);
  ksl_screw_t s3;
  ksl_cross_sst(&s1, &s2, &s3);
  ck_assert_double_eq_tol(s3.m0, -7.0, 1.e-9);
  ck_assert_double_eq_tol(s3.m1, 14.0, 1.e-9);
  ck_assert_double_eq_tol(s3.m2, -7.0, 1.e-9);
  ck_assert_double_eq_tol(s3.m3, 0.0, 1.e-9);
  ck_assert_double_eq_tol(s3.m4, 0.0, 1.e-9);
  ck_assert_double_eq_tol(s3.m5, 0.0, 1.e-9);
}
END_TEST

START_TEST(test_cross_sstf) {
  ksl_screwf_t s1 = ksl_screwf(4.0, 5.0, 6.0, 1.0, 2.0, 3.0);
  ksl_screwf_t s2 = ksl_screwf(6.0, 5.0, 4.0, 0.0, 0.0, 0.0);
  ksl_screwf_t s3;
  ksl_cross_sstf(&s1, &s2, &s3);
  ck_assert_float_eq_tol(s3.m0, -7.0, 1.e-5);
  ck_assert_float_eq_tol(s3.m1, 14.0, 1.e-5);
  ck_assert_float_eq_tol(s3.m2, -7.0, 1.e-5);
  ck_assert_float_eq_tol(s3.m3, 0.0, 1.e-5);
  ck_assert_float_eq_tol(s3.m4, 0.0, 1.e-5);
  ck_assert_float_eq_tol(s3.m5, 0.0, 1.e-5);
}
END_TEST

START_TEST(test_product_Adrs) {
  ksl_mat3x3_t R =
    ksl_mat3x3(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01,
               7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01,
               2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01);
  ksl_screw_t s1 = ksl_screw(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screw_t s2;
  ksl_product_Adrs(&R, &s1, &s2);
  ck_assert_double_eq_tol(s2.m0, 1.86212787082e+00, 1.e-9);
  ck_assert_double_eq_tol(s2.m1, -9.58674952426e-01, 1.e-9);
  ck_assert_double_eq_tol(s2.m2, 3.10055190705e+00, 1.e-9);
  ck_assert_double_eq_tol(s2.m3, 4.45275160950e+00, 1.e-9);
  ck_assert_double_eq_tol(s2.m4, -2.94160227256e-01, 1.e-9);
  ck_assert_double_eq_tol(s2.m5, 7.55555907030e+00, 1.e-9);
}
END_TEST

START_TEST(test_product_Adrsf) {
  ksl_mat3x3f_t R =
    ksl_mat3x3f(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01,
                7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01,
                2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01);
  ;
  ksl_screwf_t s1 = ksl_screwf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screwf_t s2;
  ksl_product_Adrsf(&R, &s1, &s2);
  ck_assert_float_eq_tol(s2.m0, 1.86212787082e+00, 1.e-5);
  ck_assert_float_eq_tol(s2.m1, -9.58674952426e-01, 1.e-5);
  ck_assert_float_eq_tol(s2.m2, 3.10055190705e+00, 1.e-5);
  ck_assert_float_eq_tol(s2.m3, 4.45275160950e+00, 1.e-5);
  ck_assert_float_eq_tol(s2.m4, -2.94160227256e-01, 1.e-5);
  ck_assert_float_eq_tol(s2.m5, 7.55555907030e+00, 1.e-5);
}
END_TEST

START_TEST(test_product_Adrsinv) {
  ksl_mat3x3_t R =
    ksl_mat3x3(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01,
               7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01,
               2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01);
  ksl_screw_t s1 = ksl_screw(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screw_t s2;
  ksl_product_Adrsinv(&R, &s1, &s2);
  ck_assert_double_eq_tol(s2.m0, -1.86212787082e+00, 1.e-9);
  ck_assert_double_eq_tol(s2.m1, 9.58674952426e-01, 1.e-9);
  ck_assert_double_eq_tol(s2.m2, -3.10055190705e+00, 1.e-9);
  ck_assert_double_eq_tol(s2.m3, -4.45275160950e+00, 1.e-9);
  ck_assert_double_eq_tol(s2.m4, 2.94160227256e-01, 1.e-9);
  ck_assert_double_eq_tol(s2.m5, -7.55555907030e+00, 1.e-9);
}
END_TEST

START_TEST(test_product_Adrsinvf) {
  ksl_mat3x3f_t R =
    ksl_mat3x3f(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01,
                7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01,
                2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01);
  ksl_screwf_t s1 = ksl_screwf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screwf_t s2;
  ksl_product_Adrsinvf(&R, &s1, &s2);
  ck_assert_float_eq_tol(s2.m0, -1.86212787082e+00, 1.e-5);
  ck_assert_float_eq_tol(s2.m1, 9.58674952426e-01, 1.e-5);
  ck_assert_float_eq_tol(s2.m2, -3.10055190705e+00, 1.e-5);
  ck_assert_float_eq_tol(s2.m3, -4.45275160950e+00, 1.e-5);
  ck_assert_float_eq_tol(s2.m4, 2.94160227256e-01, 1.e-5);
  ck_assert_float_eq_tol(s2.m5, -7.55555907030e+00, 1.e-5);
}
END_TEST

START_TEST(test_product_Adrinvs) {
  ksl_mat3x3_t R =
    ksl_mat3x3(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01,
               7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01,
               2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01);
  ksl_screw_t s1 = ksl_screw(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screw_t s2;
  ksl_product_Adrinvs(&R, &s1, &s2);
  ck_assert_double_eq_tol(s2.m0, 2.81970484698e+00, 1.e-9);
  ck_assert_double_eq_tol(s2.m1, 2.39883129770e+00, 1.e-9);
  ck_assert_double_eq_tol(s2.m2, 5.43022081575e-01, 1.e-9);
  ck_assert_double_eq_tol(s2.m3, 7.57284483310e+00, 1.e-9);
  ck_assert_double_eq_tol(s2.m4, 4.01097373043e+00, 1.e-9);
  ck_assert_double_eq_tol(s2.m5, 1.88788528983e+00, 1.e-9);
}
END_TEST

START_TEST(test_product_Adrinvsf) {
  ksl_mat3x3f_t R =
    ksl_mat3x3f(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01,
                7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01,
                2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01);
  ksl_screwf_t s1 = ksl_screwf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screwf_t s2;
  ksl_product_Adrinvsf(&R, &s1, &s2);
  ck_assert_float_eq_tol(s2.m0, 2.81970484698e+00, 1.e-5);
  ck_assert_float_eq_tol(s2.m1, 2.39883129770e+00, 1.e-5);
  ck_assert_float_eq_tol(s2.m2, 5.43022081575e-01, 1.e-5);
  ck_assert_float_eq_tol(s2.m3, 7.57284483310e+00, 1.e-5);
  ck_assert_float_eq_tol(s2.m4, 4.01097373043e+00, 1.e-5);
  ck_assert_float_eq_tol(s2.m5, 1.88788528983e+00, 1.e-5);
}
END_TEST

START_TEST(test_product_Adts) {
  ksl_vec3_t t = ksl_vec3(1.0, 2.0, 3.0);
  ksl_screw_t s1 = ksl_screw(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screw_t s2;
  ksl_product_Adts(&t, &s1, &s2);
  ck_assert_double_eq_tol(s2.m0, -2.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m1, 8.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m2, 0.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m3, 4.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m4, 5.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m5, 6.0, 1.e-9);
}
END_TEST

START_TEST(test_product_Adtsf) {
  ksl_vec3f_t t = ksl_vec3f(1.0, 2.0, 3.0);
  ksl_screwf_t s1 = ksl_screwf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screwf_t s2;
  ksl_product_Adtsf(&t, &s1, &s2);
  ck_assert_float_eq_tol(s2.m0, -2.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m1, 8.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m2, 0.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m3, 4.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m4, 5.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m5, 6.0, 1.e-5);
}
END_TEST

START_TEST(test_product_Adtinvs) {
  ksl_vec3_t t = ksl_vec3(1.0, 2.0, 3.0);
  ksl_screw_t s1 = ksl_screw(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screw_t s2;
  ksl_product_Adtinvs(&t, &s1, &s2);
  ck_assert_double_eq_tol(s2.m0, 4.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m1, -4.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m2, 6.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m3, 4.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m4, 5.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m5, 6.0, 1.e-9);
}
END_TEST

START_TEST(test_product_Adtinvsf) {
  ksl_vec3f_t t = ksl_vec3f(1.0, 2.0, 3.0);
  ksl_screwf_t s1 = ksl_screwf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screwf_t s2;
  ksl_product_Adtinvsf(&t, &s1, &s2);
  ck_assert_float_eq_tol(s2.m0, 4.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m1, -4.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m2, 6.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m3, 4.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m4, 5.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m5, 6.0, 1.e-5);
}
END_TEST

START_TEST(test_product_Adtsinv) {
  ksl_vec3_t t = ksl_vec3(1.0, 2.0, 3.0);
  ksl_screw_t s1 = ksl_screw(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screw_t s2;
  ksl_product_Adtsinv(&t, &s1, &s2);
  ck_assert_double_eq_tol(s2.m0, 2.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m1, -8.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m2, 0.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m3, -4.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m4, -5.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m5, -6.0, 1.e-9);
}
END_TEST

START_TEST(test_product_Adtsinvf) {
  ksl_vec3f_t t = ksl_vec3f(1.0, 2.0, 3.0);
  ksl_screwf_t s1 = ksl_screwf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screwf_t s2;
  ksl_product_Adtsinvf(&t, &s1, &s2);
  ck_assert_float_eq_tol(s2.m0, 2.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m1, -8.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m2, 0.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m3, -4.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m4, -5.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m5, -6.0, 1.e-5);
}
END_TEST

START_TEST(test_product_Ads) {
  ksl_SE3_t D =
    ksl_SE3(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
            7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
            2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);
  ksl_screw_t s1 = ksl_screw(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screw_t s2;
  ksl_product_Ads(&D, &s1, &s2);
  ck_assert_double_eq_tol(s2.m0, 1.78557266932e+01, 1.e-9);
  ck_assert_double_eq_tol(s2.m1, 4.84402080578e+00, 1.e-9);
  ck_assert_double_eq_tol(s2.m2, -6.09911153921e+00, 1.e-9);
  ck_assert_double_eq_tol(s2.m3, 4.45275160950e+00, 1.e-9);
  ck_assert_double_eq_tol(s2.m4, -2.94160227256e-01, 1.e-9);
  ck_assert_double_eq_tol(s2.m5, 7.55555907030e+00, 1.e-9);
}
END_TEST

START_TEST(test_product_Adsf) {
  ksl_SE3f_t D =
    ksl_SE3f(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
             7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
             2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);
  ksl_screwf_t s1 = ksl_screwf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screwf_t s2;
  ksl_product_Adsf(&D, &s1, &s2);
  ck_assert_float_eq_tol(s2.m0, 1.78557266932e+01, 1.e-5);
  ck_assert_float_eq_tol(s2.m1, 4.84402080578e+00, 1.e-5);
  ck_assert_float_eq_tol(s2.m2, -6.09911153921e+00, 1.e-5);
  ck_assert_float_eq_tol(s2.m3, 4.45275160950e+00, 1.e-5);
  ck_assert_float_eq_tol(s2.m4, -2.94160227256e-01, 1.e-5);
  ck_assert_float_eq_tol(s2.m5, 7.55555907030e+00, 1.e-5);
}
END_TEST

START_TEST(test_product_Adsinv) {
  ksl_SE3_t D =
    ksl_SE3(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
            7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
            2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);
  ksl_screw_t s1 = ksl_screw(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screw_t s2;
  ksl_product_Adsinv(&D, &s1, &s2);
  ck_assert_double_eq_tol(s2.m0, -1.78557266932e+01, 1.e-9);
  ck_assert_double_eq_tol(s2.m1, -4.84402080578e+00, 1.e-9);
  ck_assert_double_eq_tol(s2.m2, 6.09911153921e+00, 1.e-9);
  ck_assert_double_eq_tol(s2.m3, -4.45275160950e+00, 1.e-9);
  ck_assert_double_eq_tol(s2.m4, 2.94160227256e-01, 1.e-9);
  ck_assert_double_eq_tol(s2.m5, -7.55555907030e+00, 1.e-9);
}
END_TEST

START_TEST(test_product_Adsinvf) {
  ksl_SE3f_t D =
    ksl_SE3f(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
             7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
             2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);
  ksl_screwf_t s1 = ksl_screwf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screwf_t s2;
  ksl_product_Adsinvf(&D, &s1, &s2);
  ck_assert_float_eq_tol(s2.m0, -1.78557266932e+01, 1.e-5);
  ck_assert_float_eq_tol(s2.m1, -4.84402080578e+00, 1.e-5);
  ck_assert_float_eq_tol(s2.m2, 6.09911153921e+00, 1.e-5);
  ck_assert_float_eq_tol(s2.m3, -4.45275160950e+00, 1.e-5);
  ck_assert_float_eq_tol(s2.m4, 2.94160227256e-01, 1.e-5);
  ck_assert_float_eq_tol(s2.m5, -7.55555907030e+00, 1.e-5);
}
END_TEST

START_TEST(test_product_Adinvs) {
  ksl_SE3_t D =
    ksl_SE3(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
            7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
            2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);
  ksl_screw_t s1 = ksl_screw(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screw_t s2;
  ksl_product_Adinvs(&D, &s1, &s2);
  ck_assert_double_eq_tol(s2.m0, 4.69033831505e-01, 1.e-9);
  ck_assert_double_eq_tol(s2.m1, 3.60988863525e+00, 1.e-9);
  ck_assert_double_eq_tol(s2.m2, 7.39923721109e+00, 1.e-9);
  ck_assert_double_eq_tol(s2.m3, 7.57284483310e+00, 1.e-9);
  ck_assert_double_eq_tol(s2.m4, 4.01097373043e+00, 1.e-9);
  ck_assert_double_eq_tol(s2.m5, 1.88788528983e+00, 1.e-9);
}
END_TEST

START_TEST(test_product_Adinvsf) {
  ksl_SE3f_t D =
    ksl_SE3f(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
             7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
             2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);
  ksl_screwf_t s1 = ksl_screwf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screwf_t s2;
  ksl_product_Adinvsf(&D, &s1, &s2);
  ck_assert_float_eq_tol(s2.m0, 4.69033831505e-01, 1.e-5);
  ck_assert_float_eq_tol(s2.m1, 3.60988863525e+00, 1.e-5);
  ck_assert_float_eq_tol(s2.m2, 7.39923721109e+00, 1.e-5);
  ck_assert_float_eq_tol(s2.m3, 7.57284483310e+00, 1.e-5);
  ck_assert_float_eq_tol(s2.m4, 4.01097373043e+00, 1.e-5);
  ck_assert_float_eq_tol(s2.m5, 1.88788528983e+00, 1.e-5);
}
END_TEST

/* -------- exponential, logarithm and interpolation -------- */

/* 4x4 matrix exponential of [w~ rho; 0 0] by its Taylor series */
static void exp_series(const ksl_screw_t* xi, ksl_SE3_t* D) {
  double a[16] = {0.0, -xi->ang.z, xi->ang.y, xi->lin.x,
                  xi->ang.z, 0.0, -xi->ang.x, xi->lin.y,
                  -xi->ang.y, xi->ang.x, 0.0, xi->lin.z,
                  0.0, 0.0, 0.0, 0.0};
  double term[16], sum[16], next[16];
  for(int i = 0; i < 16; i++) {
    term[i] = (i % 5 == 0) ? 1.0 : 0.0;
    sum[i] = term[i];
  }
  for(int n = 1; n < 40; n++) {
    for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 4; j++) {
        double v = 0.0;
        for(int k = 0; k < 4; k++) {
          v += term[4 * i + k] * a[4 * k + j];
        }
        next[4 * i + j] = v / n;
      }
    }
    for(int i = 0; i < 16; i++) {
      term[i] = next[i];
      sum[i] += term[i];
    }
  }
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      D->R.at[j][i] = sum[4 * i + j];
    }
    D->t.at[i] = sum[4 * i + 3];
  }
}

static double SE3_difference(const ksl_SE3_t* a, const ksl_SE3_t* b) {
  double d = 0.0;
  for(int i = 0; i < 12; i++) {
    d = fmax(d, fabs(a->as_array[i] - b->as_array[i]));
  }
  return d;
}

static ksl_screw_t test_screw(const double theta) {
  /* axis (2, -1, 2) / 3, angle theta, linear part (0.3, -0.7, 1.1) */
  return ksl_screw(0.3, -0.7, 1.1, theta * 2.0 / 3.0, -theta / 3.0,
                   theta * 2.0 / 3.0);
}

START_TEST(test_screw_exp) {
  /* exp against the Taylor series of the 4x4 matrix exponential; the
  single precision and ksl_SE3_exp versions agree */
  const double angles[] = {0.0, 1e-7, 1e-3, 0.5, 2.0, 3.0};
  for(int k = 0; k < 6; k++) {
    ksl_screw_t xi = test_screw(angles[k]);
    ksl_SE3_t D, Ds, De;
    ksl_screw_exp(&xi, &D);
    exp_series(&xi, &Ds);
    ck_assert_msg(SE3_difference(&D, &Ds) < 1e-13, "theta = %g", angles[k]);
    ksl_SE3_exp(&xi, &De);
    ck_assert(SE3_difference(&D, &De) == 0.0);
    ksl_screwf_t xif;
    for(int i = 0; i < 6; i++) {
      xif.at[i] = (float)xi.at[i];
    }
    ksl_SE3f_t Df;
    ksl_screwf_exp(&xif, &Df);
    for(int i = 0; i < 12; i++) {
      ck_assert_float_eq_tol(Df.as_array[i], D.as_array[i], 1e-5);
    }
  }
}
END_TEST

START_TEST(test_screw_log) {
  /* log(exp(xi)) = xi for 0 <= theta < pi, and exp(log(D)) = D up to pi */
  const double angles[] = {0.0, 1e-9, 1e-6, 1e-3, 0.5, 1.6, 3.0, M_PI - 1e-6};
  for(int k = 0; k < 8; k++) {
    ksl_screw_t xi = test_screw(angles[k]), lo, ls;
    ksl_SE3_t D, E;
    ksl_screw_exp(&xi, &D);
    ksl_screw_log(&D, &lo);
    for(int i = 0; i < 6; i++) {
      ck_assert_msg(fabs(lo.at[i] - xi.at[i]) < 1e-9 * (1.0 + 1e-3 / (M_PI - angles[k])),
                    "theta = %g, i = %d", angles[k], i);
    }
    ksl_screw_exp(&lo, &E);
    ck_assert_msg(SE3_difference(&D, &E) < 1e-12, "theta = %g", angles[k]);
    ksl_SE3_log(&D, &ls);
    for(int i = 0; i < 6; i++) {
      ck_assert(ls.at[i] == lo.at[i]);
    }
  }
  /* theta = pi: either axis direction is a logarithm; exp(log(D)) = D */
  ksl_screw_t xi = test_screw(M_PI), lo;
  ksl_SE3_t D, E;
  ksl_screw_exp(&xi, &D);
  ksl_screw_log(&D, &lo);
  ksl_screw_exp(&lo, &E);
  ck_assert(SE3_difference(&D, &E) < 1e-12);
  /* single precision */
  ksl_SE3f_t Df;
  ksl_screwf_t lf;
  xi = test_screw(1.2);
  ksl_screw_exp(&xi, &D);
  for(int i = 0; i < 12; i++) {
    Df.as_array[i] = (float)D.as_array[i];
  }
  ksl_screwf_log(&Df, &lf);
  for(int i = 0; i < 6; i++) {
    ck_assert_float_eq_tol(lf.at[i], xi.at[i], 1e-5);
  }
}
END_TEST

static ksl_SE3_t test_displacement(const double a, const double b,
                                   const double c) {
  ksl_screw_t xi = ksl_screw(a, -b, c, 0.4 * b, -0.9 * c, 0.6 * a);
  ksl_SE3_t D;
  ksl_screw_exp(&xi, &D);
  return D;
}

START_TEST(test_SE3_sclerp) {
  ksl_SE3_t D1 = test_displacement(0.5, 1.0, -0.7);
  ksl_SE3_t D2 = test_displacement(-1.2, 0.3, 1.9);
  ksl_SE3_t Do, Dh, Dhh;
  double t = 0.0;
  ksl_SE3_sclerp(&D1, &D2, &t, &Do);
  ck_assert(SE3_difference(&Do, &D1) < 1e-14);
  t = 1.0;
  ksl_SE3_sclerp(&D1, &D2, &t, &Do);
  ck_assert(SE3_difference(&Do, &D2) < 1e-13);
  /* the half-way step applied twice reaches D2 */
  t = 0.5;
  ksl_SE3_sclerp(&D1, &D2, &t, &Dh);
  ksl_SE3_sclerp(&D1, &Dh, &(double){2.0}, &Dhh);
  ck_assert(SE3_difference(&Dhh, &D2) < 1e-13);
  /* left and right invariance: sclerp(A D1 B, A D2 B) = A sclerp(D1, D2) B */
  ksl_SE3_t A = test_displacement(2.0, -0.4, 0.8);
  ksl_SE3_t B = test_displacement(-0.3, 1.1, 0.2);
  ksl_SE3_t AD1, AD2, AD1B, AD2B, Dl, ADl, ADlB;
  ksl_product_dd(&A, &D1, &AD1);
  ksl_product_dd(&AD1, &B, &AD1B);
  ksl_product_dd(&A, &D2, &AD2);
  ksl_product_dd(&AD2, &B, &AD2B);
  t = 0.3;
  ksl_SE3_sclerp(&AD1B, &AD2B, &t, &Dl);
  ksl_SE3_sclerp(&D1, &D2, &t, &Do);
  ksl_product_dd(&A, &Do, &ADl);
  ksl_product_dd(&ADl, &B, &ADlB);
  ck_assert(SE3_difference(&Dl, &ADlB) < 1e-13);
  /* single precision */
  ksl_SE3f_t D1f, D2f, Dof;
  for(int i = 0; i < 12; i++) {
    D1f.as_array[i] = (float)D1.as_array[i];
    D2f.as_array[i] = (float)D2.as_array[i];
  }
  float tf = 0.3f;
  ksl_SE3f_sclerp(&D1f, &D2f, &tf, &Dof);
  for(int i = 0; i < 12; i++) {
    ck_assert_float_eq_tol(Dof.as_array[i], Do.as_array[i], 1e-5);
  }
}
END_TEST

START_TEST(test_SE3_lerp) {
  ksl_SE3_t D1 = test_displacement(0.5, 1.0, -0.7);
  ksl_SE3_t D2 = test_displacement(-1.2, 0.3, 1.9);
  ksl_SE3_t Dl, Ds;
  for(int k = 0; k <= 4; k++) {
    double t = 0.25 * k;
    ksl_SE3_lerp(&D1, &D2, &t, &Dl);
    ksl_SE3_sclerp(&D1, &D2, &t, &Ds);
    /* the rotation is that of sclerp (slerp); the origin is on the line */
    for(int i = 0; i < 9; i++) ck_assert(fabs(Dl.R.as_array[i] - Ds.R.as_array[i]) < 1e-14);
    for(int i = 0; i < 3; i++) {
      ck_assert(fabs(Dl.t.at[i] - ((1 - t) * D1.t.at[i] + t * D2.t.at[i])) < 1e-15);
    }
    if(k == 4) ck_assert(SE3_difference(&Dl, &D2) < 1e-14);
  }
  ksl_SE3f_t D1f, D2f, Dof;
  for(int i = 0; i < 12; i++) {
    D1f.as_array[i] = (float)D1.as_array[i];
    D2f.as_array[i] = (float)D2.as_array[i];
  }
  float tf = 0.3f;
  double t = 0.3;
  ksl_SE3f_lerp(&D1f, &D2f, &tf, &Dof);
  ksl_SE3_lerp(&D1, &D2, &t, &Dl);
  for(int i = 0; i < 12; i++) ck_assert_float_eq_tol(Dof.as_array[i], Dl.as_array[i], 1e-5);
}
END_TEST

/* velocity screw of the squad path in the moving frame, by a central
difference of width 2 dt about t + side dt (side = -1 left, +1 right) */
static ksl_screw_t SE3_squad_rate(const int n, const ksl_SE3_t* keys,
                                  const double t, const double side) {
  const double dt = 1e-5;
  double t1 = t + side * dt - dt, t2 = t + side * dt + dt;
  ksl_SE3_t D1, D2;
  ksl_SE3_squad_keys(n, keys, &t1, &D1);
  ksl_SE3_squad_keys(n, keys, &t2, &D2);
  ksl_SE3_t rel;
  ksl_product_dinvd(&D1, &D2, &rel);
  ksl_screw_t xi;
  ksl_screw_log(&rel, &xi);
  for(int i = 0; i < 6; i++) {
    xi.at[i] /= 2.0 * dt;
  }
  return xi;
}

START_TEST(test_SE3_squad_keys) {
  ksl_SE3_t keys[4] = {test_displacement(0.0, 0.0, 0.0),
                       test_displacement(1.0, 0.5, -0.4),
                       test_displacement(1.5, 1.4, 0.3),
                       test_displacement(0.4, 2.0, 1.2)};
  /* passes through every key */
  for(int k = 0; k < 4; k++) {
    double t = k;
    ksl_SE3_t D;
    ksl_SE3_squad_keys(4, keys, &t, &D);
    ck_assert_msg(SE3_difference(&D, &keys[k]) < 1e-12, "k = %d", k);
  }
  /* continuous velocity screw at the interior keys: left and right rates,
  taken just off the key, differ by the change over 2 dt only */
  for(int k = 1; k < 3; k++) {
    ksl_screw_t l = SE3_squad_rate(4, keys, k, -1.0);
    ksl_screw_t r = SE3_squad_rate(4, keys, k, 1.0);
    for(int i = 0; i < 6; i++) {
      ck_assert_msg(fabs(l.at[i] - r.at[i]) < 1e-3, "k = %d, i = %d", k, i);
    }
  }
  /* single precision */
  ksl_SE3f_t keysf[4], Df;
  for(int k = 0; k < 4; k++) {
    for(int i = 0; i < 12; i++) {
      keysf[k].as_array[i] = (float)keys[k].as_array[i];
    }
  }
  double t = 1.7;
  float tf = 1.7f;
  ksl_SE3_t D;
  ksl_SE3_squad_keys(4, keys, &t, &D);
  ksl_SE3f_squad_keys(4, keysf, &tf, &Df);
  for(int i = 0; i < 12; i++) {
    ck_assert_float_eq_tol(Df.as_array[i], D.as_array[i], 1e-4);
  }
}
END_TEST

Suite* screw_suite(void) {
  Suite* s = suite_create("screw");
  TCase* tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_screw_create);
  tcase_add_test(tc_core, test_screwf_create);
  tcase_add_test(tc_core, test_screw_alloc);
  tcase_add_test(tc_core, test_screwf_alloc);
  tcase_add_test(tc_core, test_screw_norm);
  tcase_add_test(tc_core, test_screwf_norm);
  tcase_add_test(tc_core, test_screw_normalize);
  tcase_add_test(tc_core, test_screwf_normalize);
  tcase_add_test(tc_core, test_screw_pitch_axisPoint);
  tcase_add_test(tc_core, test_screwf_pitch_axisPoint);
  tcase_add_test(tc_core, test_screw_pointAcceleration);
  tcase_add_test(tc_core, test_screwf_pointAcceleration);
  tcase_add_test(tc_core, test_screw_normalize_scale);
  tcase_add_test(tc_core, test_screw_normalize_degenerate);
  tcase_add_test(tc_core, test_dot_cs);
  tcase_add_test(tc_core, test_dot_csf);
  tcase_add_test(tc_core, test_screw_scale);
  tcase_add_test(tc_core, test_screwf_scale);
  tcase_add_test(tc_core, test_screw_copy);
  tcase_add_test(tc_core, test_screwf_copy);
  tcase_add_test(tc_core, test_screw_invert);
  tcase_add_test(tc_core, test_screwf_invert);
  tcase_add_test(tc_core, test_screw_inverted);
  tcase_add_test(tc_core, test_screwf_inverted);
  tcase_add_test(tc_core, test_axpy_ss);
  tcase_add_test(tc_core, test_axpy_ssf);
  tcase_add_test(tc_core, test_xpy_ss);
  tcase_add_test(tc_core, test_xpy_ssf);
  tcase_add_test(tc_core, test_nxpy_ss);
  tcase_add_test(tc_core, test_nxpy_ssf);
  tcase_add_test(tc_core, test_product_as);
  tcase_add_test(tc_core, test_product_asf);
  tcase_add_test(tc_core, test_add_ss);
  tcase_add_test(tc_core, test_add_ssf);
  tcase_add_test(tc_core, test_subtract_ss);
  tcase_add_test(tc_core, test_subtract_ssf);
  tcase_add_test(tc_core, test_add_sst);
  tcase_add_test(tc_core, test_add_sstf);
  tcase_add_test(tc_core, test_hstx);
  tcase_add_test(tc_core, test_hstxf);
  tcase_add_test(tc_core, test_hsty);
  tcase_add_test(tc_core, test_hstyf);
  tcase_add_test(tc_core, test_hstz);
  tcase_add_test(tc_core, test_hstzf);
  tcase_add_test(tc_core, test_hsrx);
  tcase_add_test(tc_core, test_hsrxf);
  tcase_add_test(tc_core, test_hsry);
  tcase_add_test(tc_core, test_hsryf);
  tcase_add_test(tc_core, test_hsrz);
  tcase_add_test(tc_core, test_hsrzf);
  tcase_add_test(tc_core, test_hstxinv);
  tcase_add_test(tc_core, test_hstxinvf);
  tcase_add_test(tc_core, test_hstyinv);
  tcase_add_test(tc_core, test_hstyinvf);
  tcase_add_test(tc_core, test_hstzinv);
  tcase_add_test(tc_core, test_hstzinvf);
  tcase_add_test(tc_core, test_hsrxinv);
  tcase_add_test(tc_core, test_hsrxinvf);
  tcase_add_test(tc_core, test_hsryinv);
  tcase_add_test(tc_core, test_hsryinvf);
  tcase_add_test(tc_core, test_hsrzinv);
  tcase_add_test(tc_core, test_hsrzinvf);
  tcase_add_test(tc_core, test_cross_ss);
  tcase_add_test(tc_core, test_cross_ssf);
  tcase_add_test(tc_core, test_cross_sst);
  tcase_add_test(tc_core, test_cross_sstf);
  tcase_add_test(tc_core, test_product_Adrs);
  tcase_add_test(tc_core, test_product_Adrsf);
  tcase_add_test(tc_core, test_product_Adrsinv);
  tcase_add_test(tc_core, test_product_Adrsinvf);
  tcase_add_test(tc_core, test_product_Adrinvs);
  tcase_add_test(tc_core, test_product_Adrinvsf);
  tcase_add_test(tc_core, test_product_Adts);
  tcase_add_test(tc_core, test_product_Adtsf);
  tcase_add_test(tc_core, test_product_Adtinvs);
  tcase_add_test(tc_core, test_product_Adtinvsf);
  tcase_add_test(tc_core, test_product_Adtsinv);
  tcase_add_test(tc_core, test_product_Adtsinvf);
  tcase_add_test(tc_core, test_product_Ads);
  tcase_add_test(tc_core, test_product_Adsf);
  tcase_add_test(tc_core, test_product_Adsinv);
  tcase_add_test(tc_core, test_product_Adsinvf);
  tcase_add_test(tc_core, test_product_Adinvs);
  tcase_add_test(tc_core, test_product_Adinvsf);
  tcase_add_test(tc_core, test_screw_exp);
  tcase_add_test(tc_core, test_screw_log);
  tcase_add_test(tc_core, test_SE3_sclerp);
  tcase_add_test(tc_core, test_SE3_lerp);
  tcase_add_test(tc_core, test_SE3_squad_keys);

  suite_add_tcase(s, tc_core);
  return s;
}

int main(void) {
  int number_failed;
  Suite* s = screw_suite();
  SRunner* sr = srunner_create(s);
  srunner_set_log(sr, "check_screw.log");
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
