#include <config.h>

#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "ksl/SE3.h"
#include "ksl/coscrew.h"
#include "ksl/mat3x3.h"
#include "ksl/screw.h"
#include "ksl/trig.h"

START_TEST(test_coscrew_create) {
  ksl_coscrew_t c = ksl_coscrew(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  int i;
  double v;
  for(i = 0, v = 1.0; i < 6; i++, v += 1.0) {
    ck_assert(c.at[i] == v);
  }
  ck_assert((c.lin.x == 1.0) && (c.m0 == 1.0));
  ck_assert((c.lin.y == 2.0) && (c.m1 == 2.0));
  ck_assert((c.lin.z == 3.0) && (c.m2 == 3.0));
  ck_assert((c.ang.x == 4.0) && (c.m3 == 4.0));
  ck_assert((c.ang.y == 5.0) && (c.m4 == 5.0));
  ck_assert((c.ang.z == 6.0) && (c.m5 == 6.0));
}
END_TEST

START_TEST(test_coscrewf_create) {
  ksl_coscrewf_t c = ksl_coscrewf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  float v;
  int i;
  for(i = 0, v = 1.0; i < 6; i++, v += 1.0) {
    ck_assert(c.at[i] == v);
  }
  ck_assert((c.lin.x == 1.0) && (c.m0 == 1.0));
  ck_assert((c.lin.y == 2.0) && (c.m1 == 2.0));
  ck_assert((c.lin.z == 3.0) && (c.m2 == 3.0));
  ck_assert((c.ang.x == 4.0) && (c.m3 == 4.0));
  ck_assert((c.ang.y == 5.0) && (c.m4 == 5.0));
  ck_assert((c.ang.z == 6.0) && (c.m5 == 6.0));
}
END_TEST

START_TEST(test_coscrew_alloc) {
  ksl_coscrew_t c = ksl_coscrew(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_coscrew_t* c3 = ksl_coscrew_alloc(3);
  for(int i = 0; i < 3; i++) {
    ksl_coscrew_copy(&c, &c3[i]);
    int j;
    double v;
    for(j = 0, v = 1.0; j < 6; j++, v += 1.0) {
      ck_assert(c3[i].at[j] == v);
    }
  }
}
END_TEST

START_TEST(test_coscrewf_alloc) {
  ksl_coscrewf_t c = ksl_coscrewf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_coscrewf_t* c3 = ksl_coscrewf_alloc(3);
  for(int i = 0; i < 3; i++) {
    ksl_coscrewf_copy(&c, &c3[i]);
    int j;
    float v;
    for(j = 0, v = 1.0; j < 6; j++, v += 1.0) {
      ck_assert(c3[i].at[j] == v);
    }
  }
}
END_TEST

START_TEST(test_coscrew_norm) {
  ksl_coscrew_t c1 = ksl_coscrew(2.0, 1.0, -2.0, 7.0, 8.0, -3.0);
  ck_assert_double_eq_tol(ksl_coscrew_norm(&c1), 3.0, 1.e-9);
  ksl_coscrew_t c2 = ksl_coscrew(0.0, 0.0, 0.0, 2.0, 1.0, -2.0);
  ck_assert_double_eq_tol(ksl_coscrew_norm(&c2), 3.0, 1.e-9);
}
END_TEST

START_TEST(test_coscrewf_norm) {
  ksl_coscrewf_t c1 = ksl_coscrewf(2.0, 1.0, -2.0, 7.0, 8.0, -3.0);
  ck_assert_float_eq_tol(ksl_coscrewf_norm(&c1), 3.0, 1.e-5);
  ksl_coscrewf_t c2 = ksl_coscrewf(0.0, 0.0, 0.0, 2.0, 1.0, -2.0);
  ck_assert_float_eq_tol(ksl_coscrewf_norm(&c2), 3.0, 1.e-5);
}
END_TEST

START_TEST(test_coscrew_normalize) {
  ksl_coscrewf_t c1 = ksl_coscrewf(2.0, 1.0, -2.0, 7.0, 8.0, -3.0);
  ksl_coscrewf_normalize(&c1);
  ck_assert_float_eq_tol(c1.m0, 2.0 / 3.0, 1.e-5);
  ck_assert_float_eq_tol(c1.m1, 1.0 / 3.0, 1.e-5);
  ck_assert_float_eq_tol(c1.m2, -2.0 / 3.0, 1.e-5);
  ck_assert_float_eq_tol(c1.m3, 7.0 / 3.0, 1.e-5);
  ck_assert_float_eq_tol(c1.m4, 8.0 / 3.0, 1.e-5);
  ck_assert_float_eq_tol(c1.m5, -3.0 / 3.0, 1.e-5);
  ksl_coscrewf_t c2 = ksl_coscrewf(0.0, 0.0, 0.0, 2.0, 1.0, -2.0);
  ksl_coscrewf_normalize(&c2);
  ck_assert_float_eq_tol(c2.m0, 0.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m1, 0.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m2, 0.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m3, 2.0 / 3.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m4, 1.0 / 3.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m5, -2.0 / 3.0, 1.e-5);
}
END_TEST

START_TEST(test_coscrewf_normalize) {
  ksl_coscrew_t c1 = ksl_coscrew(2.0, 1.0, -2.0, 7.0, 8.0, -3.0);
  ksl_coscrew_normalize(&c1);
  ck_assert_double_eq_tol(c1.m0, 2.0 / 3.0, 1.e-9);
  ck_assert_double_eq_tol(c1.m1, 1.0 / 3.0, 1.e-9);
  ck_assert_double_eq_tol(c1.m2, -2.0 / 3.0, 1.e-9);
  ck_assert_double_eq_tol(c1.m3, 7.0 / 3.0, 1.e-9);
  ck_assert_double_eq_tol(c1.m4, 8.0 / 3.0, 1.e-9);
  ck_assert_double_eq_tol(c1.m5, -3.0 / 3.0, 1.e-9);
  ksl_coscrew_t c2 = ksl_coscrew(0.0, 0.0, 0.0, 2.0, 1.0, -2.0);
  ksl_coscrew_normalize(&c2);
  ck_assert_double_eq_tol(c2.m0, 0.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m1, 0.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m2, 0.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m3, 2.0 / 3.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m4, 1.0 / 3.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m5, -2.0 / 3.0, 1.e-9);
}
END_TEST

START_TEST(test_coscrew_normalize_scale) {
  /* the amplitude and unit coscrew do not depend on the size of the coscrew: a
  coscrew scaled by 1e-12 or 1e12 has the same unit coscrew (a fixed cutoff
  would take the small one's force as zero) */
  const ksl_coscrew_t s = ksl_coscrew(2.0, 1.0, -2.0, 7.0, 8.0, -3.0);
  ksl_coscrew_t u = s;
  ksl_coscrew_normalize(&u);
  /* the pitch is unchanged */
  double h = ksl_dot_vv(&s.lin, &s.ang) / ksl_dot_vv(&s.lin, &s.lin);
  double hn = ksl_dot_vv(&u.lin, &u.ang) / ksl_dot_vv(&u.lin, &u.lin);
  ck_assert_double_eq_tol(hn, h, 1e-12);
  ck_assert_double_eq_tol(ksl_vec3_l2norm(&u.lin), 1.0, 1e-15);
  const double scales[2] = {1e-12, 1e12};
  for(int j = 0; j < 2; j++) {
    ksl_coscrew_t t = s;
    ksl_coscrew_scale(&t, scales[j]);
    ck_assert_double_eq_tol(ksl_coscrew_norm(&t), 3.0 * scales[j],
                            1e-15 * scales[j]);
    ksl_coscrew_normalize(&t);
    for(int i = 0; i < 6; i++) {
      ck_assert_double_eq_tol(t.at[i], u.at[i], 1e-14);
    }
  }
  ksl_coscrewf_t sf = ksl_coscrewf(2.0, 1.0, -2.0, 7.0, 8.0, -3.0);
  ksl_coscrewf_scale(&sf, 1e-12f);
  ksl_coscrewf_normalize(&sf);
  for(int i = 0; i < 6; i++) {
    ck_assert_float_eq_tol(sf.at[i], u.at[i], 1e-6);
  }
}
END_TEST

START_TEST(test_coscrew_normalize_degenerate) {
  /* a force at round-off level relative to the moment: treated as
  zero, so the moment is normalized */
  ksl_coscrew_t s = ksl_coscrew(1e-16, 0.0, 0.0, 3.0, 0.0, 4.0);
  ck_assert_double_eq_tol(ksl_coscrew_norm(&s), 5.0, 1e-15);
  ksl_coscrew_normalize(&s);
  const double expected[6] = {1e-16 / 5.0, 0.0, 0.0, 0.6, 0.0, 0.8};
  for(int i = 0; i < 6; i++) {
    ck_assert_double_eq_tol(s.at[i], expected[i], 1e-15);
  }
  ksl_coscrewf_t sf = ksl_coscrewf(1e-9, 0.0, 0.0, 3.0, 0.0, 4.0);
  ck_assert_float_eq_tol(ksl_coscrewf_norm(&sf), 5.0f, 1e-6);

  /* a zero coscrew has amplitude zero and is left unchanged, not NaN */
  ksl_coscrew_t z = ksl_coscrew(0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
  ck_assert(ksl_coscrew_norm(&z) == 0.0);
  ksl_coscrew_normalize(&z);
  ksl_coscrewf_t zf = ksl_coscrewf(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  ck_assert(ksl_coscrewf_norm(&zf) == 0.0f);
  ksl_coscrewf_normalize(&zf);
  for(int i = 0; i < 6; i++) {
    ck_assert(z.at[i] == 0.0);
    ck_assert(zf.at[i] == 0.0f);
  }
}
END_TEST

START_TEST(test_coscrew_scale) {
  ksl_coscrew_t c = ksl_coscrew(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_coscrew_scale(&c, 2.0);
  int i;
  double v;
  for(i = 0, v = 2.0; i < 6; i++, v += 2.0) {
    ck_assert(c.at[i] == v);
  }
}
END_TEST

START_TEST(test_coscrewf_scale) {
  ksl_coscrewf_t c = ksl_coscrewf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_coscrewf_scale(&c, 2.0);
  int i;
  double v;
  for(i = 0, v = 2.0; i < 6; i++, v += 2.0) {
    ck_assert(c.at[i] == v);
  }
}
END_TEST

START_TEST(test_coscrew_copy) {
  ksl_coscrew_t c1 = ksl_coscrew(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_coscrew_t c2 = ksl_coscrew(-1.0, -2.0, -3.0, -4.0, -5.0, -6.0);
  ksl_coscrew_copy(&c1, &c2);
  ck_assert_double_eq_tol(c2.m0, 1.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m1, 2.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m2, 3.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m3, 4.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m4, 5.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m5, 6.0, 1.e-9);
}
END_TEST

START_TEST(test_coscrewf_copy) {
  ksl_coscrewf_t c1 = ksl_coscrewf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_coscrewf_t c2 = ksl_coscrewf(-1.0, -2.0, -3.0, -4.0, -5.0, -6.0);
  ksl_coscrewf_copy(&c1, &c2);
  ck_assert_float_eq_tol(c2.m0, 1.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m1, 2.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m2, 3.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m3, 4.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m4, 5.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m5, 6.0, 1.e-5);
}
END_TEST

START_TEST(test_coscrew_invert) {
  ksl_coscrew_t c1 = ksl_coscrew(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_coscrew_invert(&c1);
  ck_assert_double_eq_tol(c1.m0, -1.0, 1.e-9);
  ck_assert_double_eq_tol(c1.m1, -2.0, 1.e-9);
  ck_assert_double_eq_tol(c1.m2, -3.0, 1.e-9);
  ck_assert_double_eq_tol(c1.m3, -4.0, 1.e-9);
  ck_assert_double_eq_tol(c1.m4, -5.0, 1.e-9);
  ck_assert_double_eq_tol(c1.m5, -6.0, 1.e-9);
}
END_TEST

START_TEST(test_coscrewf_invert) {
  ksl_coscrewf_t c1 = ksl_coscrewf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_coscrewf_invert(&c1);
  ck_assert_float_eq_tol(c1.m0, -1.0, 1.e-5);
  ck_assert_float_eq_tol(c1.m1, -2.0, 1.e-5);
  ck_assert_float_eq_tol(c1.m2, -3.0, 1.e-5);
  ck_assert_float_eq_tol(c1.m3, -4.0, 1.e-5);
  ck_assert_float_eq_tol(c1.m4, -5.0, 1.e-5);
  ck_assert_float_eq_tol(c1.m5, -6.0, 1.e-5);
}
END_TEST

START_TEST(test_coscrew_inverted) {
  ksl_coscrew_t c1 = ksl_coscrew(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_coscrew_t c2 = ksl_coscrew(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_coscrew_inverted(&c1, &c2);
  ck_assert_double_eq_tol(c2.m0, -1.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m1, -2.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m2, -3.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m3, -4.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m4, -5.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m5, -6.0, 1.e-9);
}
END_TEST

START_TEST(test_coscrewf_inverted) {
  ksl_coscrewf_t c1 = ksl_coscrewf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_coscrewf_t c2 = ksl_coscrewf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_coscrewf_inverted(&c1, &c2);
  ck_assert_float_eq_tol(c2.m0, -1.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m1, -2.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m2, -3.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m3, -4.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m4, -5.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m5, -6.0, 1.e-5);
}
END_TEST

START_TEST(test_axpy_cc) {
  ksl_coscrew_t c1 = ksl_coscrew(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_coscrew_t c2 = ksl_coscrew(-2.0, -4.0, -6.0, -8.0, -10.0, -12.0);
  ksl_axpy_cc(5.0, &c1, &c2);
  ck_assert_double_eq_tol(c2.m0, 3.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m1, 6.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m2, 9.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m3, 12.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m4, 15.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m5, 18.0, 1.e-9);
}
END_TEST

START_TEST(test_axpy_ccf) {
  ksl_coscrewf_t c1 = ksl_coscrewf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_coscrewf_t c2 = ksl_coscrewf(-2.0, -4.0, -6.0, -8.0, -10.0, -12.0);
  ksl_axpy_ccf(5.0, &c1, &c2);
  ck_assert_float_eq_tol(c2.m0, 3.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m1, 6.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m2, 9.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m3, 12.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m4, 15.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m5, 18.0, 1.e-5);
}
END_TEST

START_TEST(test_xpy_cc) {
  ksl_coscrew_t c1 = ksl_coscrew(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_coscrew_t c2 = ksl_coscrew(10.0, 20.0, 30.0, 40.0, 50.0, 60.0);
  ksl_xpy_cc(&c1, &c2);
  ck_assert_double_eq_tol(c2.m0, 11.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m1, 22.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m2, 33.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m3, 44.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m4, 55.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m5, 66.0, 1.e-9);
}
END_TEST

START_TEST(test_xpy_ccf) {
  ksl_coscrewf_t c1 = ksl_coscrewf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_coscrewf_t c2 = ksl_coscrewf(10.0, 20.0, 30.0, 40.0, 50.0, 60.0);
  ksl_xpy_ccf(&c1, &c2);
  ck_assert_float_eq_tol(c2.m0, 11.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m1, 22.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m2, 33.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m3, 44.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m4, 55.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m5, 66.0, 1.e-5);
}
END_TEST

START_TEST(test_nxpy_cc) {
  ksl_coscrew_t c1 = ksl_coscrew(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_coscrew_t c2 = ksl_coscrew(10.0, 20.0, 30.0, 40.0, 50.0, 60.0);
  ksl_nxpy_cc(&c1, &c2);
  ck_assert_double_eq_tol(c2.m0, 9.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m1, 18.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m2, 27.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m3, 36.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m4, 45.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m5, 54.0, 1.e-9);
}
END_TEST

START_TEST(test_nxpy_ccf) {
  ksl_coscrewf_t c1 = ksl_coscrewf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_coscrewf_t c2 = ksl_coscrewf(10.0, 20.0, 30.0, 40.0, 50.0, 60.0);
  ksl_nxpy_ccf(&c1, &c2);
  ck_assert_float_eq_tol(c2.m0, 9.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m1, 18.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m2, 27.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m3, 36.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m4, 45.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m5, 54.0, 1.e-5);
}
END_TEST

START_TEST(test_product_ac) {
  ksl_coscrew_t c1 = ksl_coscrew(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_coscrew_t c2 = ksl_coscrew(-1.0, -2.0, -3.0, -4.0, -5.0, -6.0);
  ksl_product_ac(2.0, &c1, &c2);
  ck_assert_double_eq_tol(c2.m0, 2.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m1, 4.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m2, 6.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m3, 8.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m4, 10.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m5, 12.0, 1.e-9);
}
END_TEST

START_TEST(test_product_acf) {
  ksl_coscrewf_t c1 = ksl_coscrewf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_coscrewf_t c2 = ksl_coscrewf(-1.0, -2.0, -3.0, -4.0, -5.0, -6.0);
  ksl_product_acf(2.0, &c1, &c2);
  ck_assert_float_eq_tol(c2.m0, 2.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m1, 4.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m2, 6.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m3, 8.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m4, 10.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m5, 12.0, 1.e-5);
}
END_TEST

START_TEST(test_add_cc) {
  ksl_coscrew_t c1 = ksl_coscrew(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_coscrew_t c2 = ksl_coscrew(10.0, 20.0, 30.0, 40.0, 50.0, 60.0);
  ksl_coscrew_t c3;
  ksl_add_cc(&c1, &c2, &c3);
  ck_assert_double_eq_tol(c3.m0, 11.0, 1.e-9);
  ck_assert_double_eq_tol(c3.m1, 22.0, 1.e-9);
  ck_assert_double_eq_tol(c3.m2, 33.0, 1.e-9);
  ck_assert_double_eq_tol(c3.m3, 44.0, 1.e-9);
  ck_assert_double_eq_tol(c3.m4, 55.0, 1.e-9);
  ck_assert_double_eq_tol(c3.m5, 66.0, 1.e-9);
}
END_TEST

START_TEST(test_add_ccf) {
  ksl_coscrewf_t c1 = ksl_coscrewf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_coscrewf_t c2 = ksl_coscrewf(10.0, 20.0, 30.0, 40.0, 50.0, 60.0);
  ksl_coscrewf_t c3;
  ksl_add_ccf(&c1, &c2, &c3);
  ck_assert_float_eq_tol(c3.m0, 11.0, 1.e-5);
  ck_assert_float_eq_tol(c3.m1, 22.0, 1.e-5);
  ck_assert_float_eq_tol(c3.m2, 33.0, 1.e-5);
  ck_assert_float_eq_tol(c3.m3, 44.0, 1.e-5);
  ck_assert_float_eq_tol(c3.m4, 55.0, 1.e-5);
  ck_assert_float_eq_tol(c3.m5, 66.0, 1.e-5);
}
END_TEST

START_TEST(test_subtract_cc) {
  ksl_coscrew_t c1 = ksl_coscrew(10.0, 20.0, 30.0, 40.0, 50.0, 60.0);
  ksl_coscrew_t c2 = ksl_coscrew(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_coscrew_t c3;
  ksl_subtract_cc(&c1, &c2, &c3);
  ck_assert_double_eq_tol(c3.m0, 9.0, 1.e-9);
  ck_assert_double_eq_tol(c3.m1, 18.0, 1.e-9);
  ck_assert_double_eq_tol(c3.m2, 27.0, 1.e-9);
  ck_assert_double_eq_tol(c3.m3, 36.0, 1.e-9);
  ck_assert_double_eq_tol(c3.m4, 45.0, 1.e-9);
  ck_assert_double_eq_tol(c3.m5, 54.0, 1.e-9);
}
END_TEST

START_TEST(test_subtract_ccf) {
  ksl_coscrewf_t c1 = ksl_coscrewf(10.0, 20.0, 30.0, 40.0, 50.0, 60.0);
  ksl_coscrewf_t c2 = ksl_coscrewf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_coscrewf_t c3;
  ksl_subtract_ccf(&c1, &c2, &c3);
  ck_assert_float_eq_tol(c3.m0, 9.0, 1.e-5);
  ck_assert_float_eq_tol(c3.m1, 18.0, 1.e-5);
  ck_assert_float_eq_tol(c3.m2, 27.0, 1.e-5);
  ck_assert_float_eq_tol(c3.m3, 36.0, 1.e-5);
  ck_assert_float_eq_tol(c3.m4, 45.0, 1.e-5);
  ck_assert_float_eq_tol(c3.m5, 54.0, 1.e-5);
}
END_TEST

START_TEST(test_add_cct) {
  ksl_coscrew_t c1 = ksl_coscrew(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_coscrew_t c2 = ksl_coscrew(10.0, 20.0, 30.0, 0.0, 0.0, 0.0);
  ksl_coscrew_t c3;
  ksl_add_cct(&c1, &c2, &c3);
  ck_assert_double_eq_tol(c3.m0, 11.0, 1.e-9);
  ck_assert_double_eq_tol(c3.m1, 22.0, 1.e-9);
  ck_assert_double_eq_tol(c3.m2, 33.0, 1.e-9);
  ck_assert_double_eq_tol(c3.m3, 4.0, 1.e-9);
  ck_assert_double_eq_tol(c3.m4, 5.0, 1.e-9);
  ck_assert_double_eq_tol(c3.m5, 6.0, 1.e-9);
}
END_TEST

START_TEST(test_add_cctf) {
  ksl_coscrewf_t c1 = ksl_coscrewf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_coscrewf_t c2 = ksl_coscrewf(10.0, 20.0, 30.0, 0.0, 0.0, 0.0);
  ksl_coscrewf_t c3;
  ksl_add_cctf(&c1, &c2, &c3);
  ck_assert_float_eq_tol(c3.m0, 11.0, 1.e-5);
  ck_assert_float_eq_tol(c3.m1, 22.0, 1.e-5);
  ck_assert_float_eq_tol(c3.m2, 33.0, 1.e-5);
  ck_assert_float_eq_tol(c3.m3, 4.0, 1.e-5);
  ck_assert_float_eq_tol(c3.m4, 5.0, 1.e-5);
  ck_assert_float_eq_tol(c3.m5, 6.0, 1.e-5);
}
END_TEST

START_TEST(test_hctx) {
  ksl_SE3_t D =
    ksl_SE3(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
            7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
            2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_coscrew_t c = ksl_coscrew(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hctx(&D, &c);
  ck_assert_double_eq_tol(c.m0, 5.72061402818e-01, 1.e-9);
  ck_assert_double_eq_tol(c.m1, 7.89312333511e-01, 1.e-9);
  ck_assert_double_eq_tol(c.m2, 2.23006259046e-01, 1.e-9);
  ck_assert_double_eq_tol(c.m3, -1.92192448244e+00, 1.e-9);
  ck_assert_double_eq_tol(c.m4, 1.49317794941e+00, 1.e-9);
  ck_assert_double_eq_tol(c.m5, -3.54810472124e-01, 1.e-9);
}
END_TEST

START_TEST(test_hctxf) {
  ksl_SE3f_t D =
    ksl_SE3f(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
             7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
             2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_coscrewf_t c = ksl_coscrewf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hctxf(&D, &c);
  ck_assert_float_eq_tol(c.m0, 5.72061402818e-01, 1.e-5);
  ck_assert_float_eq_tol(c.m1, 7.89312333511e-01, 1.e-5);
  ck_assert_float_eq_tol(c.m2, 2.23006259046e-01, 1.e-5);
  ck_assert_float_eq_tol(c.m3, -1.92192448244e+00, 1.e-5);
  ck_assert_float_eq_tol(c.m4, 1.49317794941e+00, 1.e-5);
  ck_assert_float_eq_tol(c.m5, -3.54810472124e-01, 1.e-5);
}
END_TEST

START_TEST(test_hcty) {
  ksl_SE3_t D =
    ksl_SE3(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
            7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
            2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_coscrew_t c = ksl_coscrew(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hcty(&D, &c);
  ck_assert_double_eq_tol(c.m0, -4.15626937777e-01, 1.e-9);
  ck_assert_double_eq_tol(c.m1, 4.45650105751e-02, 1.e-9);
  ck_assert_double_eq_tol(c.m2, 9.08442738111e-01, 1.e-9);
  ck_assert_double_eq_tol(c.m3, 1.68319044450e+00, 1.e-9);
  ck_assert_double_eq_tol(c.m4, -2.15532355144e+00, 1.e-9);
  ck_assert_double_eq_tol(c.m5, 8.75818886130e-01, 1.e-9);
}
END_TEST

START_TEST(test_hctyf) {
  ksl_SE3f_t D =
    ksl_SE3f(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
             7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
             2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_coscrewf_t c = ksl_coscrewf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hctyf(&D, &c);
  ck_assert_float_eq_tol(c.m0, -4.15626937777e-01, 1.e-5);
  ck_assert_float_eq_tol(c.m1, 4.45650105751e-02, 1.e-5);
  ck_assert_float_eq_tol(c.m2, 9.08442738111e-01, 1.e-5);
  ck_assert_float_eq_tol(c.m3, 1.68319044450e+00, 1.e-5);
  ck_assert_float_eq_tol(c.m4, -2.15532355144e+00, 1.e-5);
  ck_assert_float_eq_tol(c.m5, 8.75818886130e-01, 1.e-5);
}
END_TEST

START_TEST(test_hctz) {
  ksl_SE3_t D =
    ksl_SE3(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
            7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
            2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_coscrew_t c = ksl_coscrew(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hctz(&D, &c);
  ck_assert_double_eq_tol(c.m0, 7.07106781187e-01, 1.e-9);
  ck_assert_double_eq_tol(c.m1, -6.12372435696e-01, 1.e-9);
  ck_assert_double_eq_tol(c.m2, 3.53553390593e-01, 1.e-9);
  ck_assert_double_eq_tol(c.m3, 2.54422408827e+00, 1.e-9);
  ck_assert_double_eq_tol(c.m4, 1.76776695297e+00, 1.e-9);
  ck_assert_double_eq_tol(c.m5, -2.02658599807e+00, 1.e-9);
}
END_TEST

START_TEST(test_hctzf) {
  ksl_SE3f_t D =
    ksl_SE3f(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
             7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
             2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_coscrewf_t c = ksl_coscrewf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hctzf(&D, &c);
  ck_assert_float_eq_tol(c.m0, 7.07106781187e-01, 1.e-5);
  ck_assert_float_eq_tol(c.m1, -6.12372435696e-01, 1.e-5);
  ck_assert_float_eq_tol(c.m2, 3.53553390593e-01, 1.e-5);
  ck_assert_float_eq_tol(c.m3, 2.54422408827e+00, 1.e-5);
  ck_assert_float_eq_tol(c.m4, 1.76776695297e+00, 1.e-5);
  ck_assert_float_eq_tol(c.m5, -2.02658599807e+00, 1.e-5);
}
END_TEST

START_TEST(test_hcrx) {
  ksl_SE3_t D =
    ksl_SE3(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
            7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
            2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_coscrew_t c = ksl_coscrew(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hcrx(&D, &c);
  ck_assert_double_eq_tol(c.m0, 0.00000000000e+00, 1.e-9);
  ck_assert_double_eq_tol(c.m1, 0.00000000000e+00, 1.e-9);
  ck_assert_double_eq_tol(c.m2, 0.00000000000e+00, 1.e-9);
  ck_assert_double_eq_tol(c.m3, 5.72061402818e-01, 1.e-9);
  ck_assert_double_eq_tol(c.m4, 7.89312333511e-01, 1.e-9);
  ck_assert_double_eq_tol(c.m5, 2.23006259046e-01, 1.e-9);
}
END_TEST

START_TEST(test_hcrxf) {
  ksl_SE3f_t D =
    ksl_SE3f(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
             7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
             2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_coscrewf_t c = ksl_coscrewf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hcrxf(&D, &c);
  ck_assert_float_eq_tol(c.m0, 0.00000000000e+00, 1.e-5);
  ck_assert_float_eq_tol(c.m1, 0.00000000000e+00, 1.e-5);
  ck_assert_float_eq_tol(c.m2, 0.00000000000e+00, 1.e-5);
  ck_assert_float_eq_tol(c.m3, 5.72061402818e-01, 1.e-5);
  ck_assert_float_eq_tol(c.m4, 7.89312333511e-01, 1.e-5);
  ck_assert_float_eq_tol(c.m5, 2.23006259046e-01, 1.e-5);
}
END_TEST

START_TEST(test_hcry) {
  ksl_SE3_t D =
    ksl_SE3(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
            7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
            2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_coscrew_t c = ksl_coscrew(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hcry(&D, &c);
  ck_assert_double_eq_tol(c.m0, 0.00000000000e+00, 1.e-9);
  ck_assert_double_eq_tol(c.m1, 0.00000000000e+00, 1.e-9);
  ck_assert_double_eq_tol(c.m2, 0.00000000000e+00, 1.e-9);
  ck_assert_double_eq_tol(c.m3, -4.15626937777e-01, 1.e-9);
  ck_assert_double_eq_tol(c.m4, 4.45650105751e-02, 1.e-9);
  ck_assert_double_eq_tol(c.m5, 9.08442738111e-01, 1.e-9);
}
END_TEST

START_TEST(test_hcryf) {
  ksl_SE3f_t D =
    ksl_SE3f(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
             7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
             2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_coscrewf_t c = ksl_coscrewf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hcryf(&D, &c);
  ck_assert_float_eq_tol(c.m0, 0.00000000000e+00, 1.e-5);
  ck_assert_float_eq_tol(c.m1, 0.00000000000e+00, 1.e-5);
  ck_assert_float_eq_tol(c.m2, 0.00000000000e+00, 1.e-5);
  ck_assert_float_eq_tol(c.m3, -4.15626937777e-01, 1.e-5);
  ck_assert_float_eq_tol(c.m4, 4.45650105751e-02, 1.e-5);
  ck_assert_float_eq_tol(c.m5, 9.08442738111e-01, 1.e-5);
}
END_TEST

START_TEST(test_hcrz) {
  ksl_SE3_t D =
    ksl_SE3(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
            7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
            2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_coscrew_t c = ksl_coscrew(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hcrz(&D, &c);
  ck_assert_double_eq_tol(c.m0, 0.00000000000e+00, 1.e-9);
  ck_assert_double_eq_tol(c.m1, 0.00000000000e+00, 1.e-9);
  ck_assert_double_eq_tol(c.m2, 0.00000000000e+00, 1.e-9);
  ck_assert_double_eq_tol(c.m3, 7.07106781187e-01, 1.e-9);
  ck_assert_double_eq_tol(c.m4, -6.12372435696e-01, 1.e-9);
  ck_assert_double_eq_tol(c.m5, 3.53553390593e-01, 1.e-9);
}
END_TEST

START_TEST(test_hcrzf) {
  ksl_SE3f_t D =
    ksl_SE3f(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
             7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
             2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_coscrewf_t c = ksl_coscrewf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hcrzf(&D, &c);
  ck_assert_float_eq_tol(c.m0, 0.00000000000e+00, 1.e-5);
  ck_assert_float_eq_tol(c.m1, 0.00000000000e+00, 1.e-5);
  ck_assert_float_eq_tol(c.m2, 0.00000000000e+00, 1.e-5);
  ck_assert_float_eq_tol(c.m3, 7.07106781187e-01, 1.e-5);
  ck_assert_float_eq_tol(c.m4, -6.12372435696e-01, 1.e-5);
  ck_assert_float_eq_tol(c.m5, 3.53553390593e-01, 1.e-5);
}
END_TEST

START_TEST(test_hctxinv) {
  ksl_SE3_t D =
    ksl_SE3(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
            7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
            2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_coscrew_t c = ksl_coscrew(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hctxinv(&D, &c);
  ck_assert_double_eq_tol(c.m0, -5.72061402818e-01, 1.e-9);
  ck_assert_double_eq_tol(c.m1, -7.89312333511e-01, 1.e-9);
  ck_assert_double_eq_tol(c.m2, -2.23006259046e-01, 1.e-9);
  ck_assert_double_eq_tol(c.m3, 1.92192448244e+00, 1.e-9);
  ck_assert_double_eq_tol(c.m4, -1.49317794941e+00, 1.e-9);
  ck_assert_double_eq_tol(c.m5, 3.54810472124e-01, 1.e-9);
}
END_TEST

START_TEST(test_hctxinvf) {
  ksl_SE3f_t D =
    ksl_SE3f(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
             7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
             2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_coscrewf_t c = ksl_coscrewf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hctxinvf(&D, &c);
  ck_assert_float_eq_tol(c.m0, -5.72061402818e-01, 1.e-5);
  ck_assert_float_eq_tol(c.m1, -7.89312333511e-01, 1.e-5);
  ck_assert_float_eq_tol(c.m2, -2.23006259046e-01, 1.e-5);
  ck_assert_float_eq_tol(c.m3, 1.92192448244e+00, 1.e-5);
  ck_assert_float_eq_tol(c.m4, -1.49317794941e+00, 1.e-5);
  ck_assert_float_eq_tol(c.m5, 3.54810472124e-01, 1.e-5);
}
END_TEST

START_TEST(test_hctyinv) {
  ksl_SE3_t D =
    ksl_SE3(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
            7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
            2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_coscrew_t c = ksl_coscrew(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hctyinv(&D, &c);
  ck_assert_double_eq_tol(c.m0, 4.15626937777e-01, 1.e-9);
  ck_assert_double_eq_tol(c.m1, -4.45650105751e-02, 1.e-9);
  ck_assert_double_eq_tol(c.m2, -9.08442738111e-01, 1.e-9);
  ck_assert_double_eq_tol(c.m3, -1.68319044450e+00, 1.e-9);
  ck_assert_double_eq_tol(c.m4, 2.15532355144e+00, 1.e-9);
  ck_assert_double_eq_tol(c.m5, -8.75818886130e-01, 1.e-9);
}
END_TEST

START_TEST(test_hctyinvf) {
  ksl_SE3f_t D =
    ksl_SE3f(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
             7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
             2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_coscrewf_t c = ksl_coscrewf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hctyinvf(&D, &c);
  ck_assert_float_eq_tol(c.m0, 4.15626937777e-01, 1.e-5);
  ck_assert_float_eq_tol(c.m1, -4.45650105751e-02, 1.e-5);
  ck_assert_float_eq_tol(c.m2, -9.08442738111e-01, 1.e-5);
  ck_assert_float_eq_tol(c.m3, -1.68319044450e+00, 1.e-5);
  ck_assert_float_eq_tol(c.m4, 2.15532355144e+00, 1.e-5);
  ck_assert_float_eq_tol(c.m5, -8.75818886130e-01, 1.e-5);
}
END_TEST

START_TEST(test_hctzinv) {
  ksl_SE3_t D =
    ksl_SE3(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
            7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
            2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_coscrew_t c = ksl_coscrew(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hctzinv(&D, &c);
  ck_assert_double_eq_tol(c.m0, -7.07106781187e-01, 1.e-9);
  ck_assert_double_eq_tol(c.m1, 6.12372435696e-01, 1.e-9);
  ck_assert_double_eq_tol(c.m2, -3.53553390593e-01, 1.e-9);
  ck_assert_double_eq_tol(c.m3, -2.54422408827e+00, 1.e-9);
  ck_assert_double_eq_tol(c.m4, -1.76776695297e+00, 1.e-9);
  ck_assert_double_eq_tol(c.m5, 2.02658599807e+00, 1.e-9);
}
END_TEST

START_TEST(test_hctzinvf) {
  ksl_SE3f_t D =
    ksl_SE3f(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
             7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
             2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_coscrewf_t c = ksl_coscrewf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hctzinvf(&D, &c);
  ck_assert_float_eq_tol(c.m0, -7.07106781187e-01, 1.e-5);
  ck_assert_float_eq_tol(c.m1, 6.12372435696e-01, 1.e-5);
  ck_assert_float_eq_tol(c.m2, -3.53553390593e-01, 1.e-5);
  ck_assert_float_eq_tol(c.m3, -2.54422408827e+00, 1.e-5);
  ck_assert_float_eq_tol(c.m4, -1.76776695297e+00, 1.e-5);
  ck_assert_float_eq_tol(c.m5, 2.02658599807e+00, 1.e-5);
}
END_TEST

START_TEST(test_hcrxinv) {
  ksl_SE3_t D =
    ksl_SE3(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
            7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
            2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_coscrew_t c = ksl_coscrew(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hcrxinv(&D, &c);
  ck_assert_double_eq_tol(c.m0, 0.00000000000e+00, 1.e-9);
  ck_assert_double_eq_tol(c.m1, 0.00000000000e+00, 1.e-9);
  ck_assert_double_eq_tol(c.m2, 0.00000000000e+00, 1.e-9);
  ck_assert_double_eq_tol(c.m3, -5.72061402818e-01, 1.e-9);
  ck_assert_double_eq_tol(c.m4, -7.89312333511e-01, 1.e-9);
  ck_assert_double_eq_tol(c.m5, -2.23006259046e-01, 1.e-9);
}
END_TEST

START_TEST(test_hcrxinvf) {
  ksl_SE3f_t D =
    ksl_SE3f(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
             7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
             2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_coscrewf_t c = ksl_coscrewf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hcrxinvf(&D, &c);
  ck_assert_float_eq_tol(c.m0, 0.00000000000e+00, 1.e-5);
  ck_assert_float_eq_tol(c.m1, 0.00000000000e+00, 1.e-5);
  ck_assert_float_eq_tol(c.m2, 0.00000000000e+00, 1.e-5);
  ck_assert_float_eq_tol(c.m3, -5.72061402818e-01, 1.e-5);
  ck_assert_float_eq_tol(c.m4, -7.89312333511e-01, 1.e-5);
  ck_assert_float_eq_tol(c.m5, -2.23006259046e-01, 1.e-5);
}
END_TEST

START_TEST(test_hcryinv) {
  ksl_SE3_t D =
    ksl_SE3(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
            7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
            2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_coscrew_t c = ksl_coscrew(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hcryinv(&D, &c);
  ck_assert_double_eq_tol(c.m0, 0.00000000000e+00, 1.e-9);
  ck_assert_double_eq_tol(c.m1, 0.00000000000e+00, 1.e-9);
  ck_assert_double_eq_tol(c.m2, 0.00000000000e+00, 1.e-9);
  ck_assert_double_eq_tol(c.m3, 4.15626937777e-01, 1.e-9);
  ck_assert_double_eq_tol(c.m4, -4.45650105751e-02, 1.e-9);
  ck_assert_double_eq_tol(c.m5, -9.08442738111e-01, 1.e-9);
}
END_TEST

START_TEST(test_hcryinvf) {
  ksl_SE3f_t D =
    ksl_SE3f(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
             7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
             2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_coscrewf_t c = ksl_coscrewf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hcryinvf(&D, &c);
  ck_assert_float_eq_tol(c.m0, 0.00000000000e+00, 1.e-5);
  ck_assert_float_eq_tol(c.m1, 0.00000000000e+00, 1.e-5);
  ck_assert_float_eq_tol(c.m2, 0.00000000000e+00, 1.e-5);
  ck_assert_float_eq_tol(c.m3, 4.15626937777e-01, 1.e-5);
  ck_assert_float_eq_tol(c.m4, -4.45650105751e-02, 1.e-5);
  ck_assert_float_eq_tol(c.m5, -9.08442738111e-01, 1.e-5);
}
END_TEST

START_TEST(test_hcrzinv) {
  ksl_SE3_t D =
    ksl_SE3(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
            7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
            2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_coscrew_t c = ksl_coscrew(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hcrzinv(&D, &c);
  ck_assert_double_eq_tol(c.m0, 0.00000000000e+00, 1.e-9);
  ck_assert_double_eq_tol(c.m1, 0.00000000000e+00, 1.e-9);
  ck_assert_double_eq_tol(c.m2, 0.00000000000e+00, 1.e-9);
  ck_assert_double_eq_tol(c.m3, -7.07106781187e-01, 1.e-9);
  ck_assert_double_eq_tol(c.m4, 6.12372435696e-01, 1.e-9);
  ck_assert_double_eq_tol(c.m5, -3.53553390593e-01, 1.e-9);
}
END_TEST

START_TEST(test_hcrzinvf) {
  ksl_SE3f_t D =
    ksl_SE3f(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
             7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
             2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);

  ksl_coscrewf_t c = ksl_coscrewf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_hcrzinvf(&D, &c);
  ck_assert_float_eq_tol(c.m0, 0.00000000000e+00, 1.e-5);
  ck_assert_float_eq_tol(c.m1, 0.00000000000e+00, 1.e-5);
  ck_assert_float_eq_tol(c.m2, 0.00000000000e+00, 1.e-5);
  ck_assert_float_eq_tol(c.m3, -7.07106781187e-01, 1.e-5);
  ck_assert_float_eq_tol(c.m4, 6.12372435696e-01, 1.e-5);
  ck_assert_float_eq_tol(c.m5, -3.53553390593e-01, 1.e-5);
}
END_TEST

START_TEST(test_cross_sc) {
  ksl_screw_t s1 = ksl_screw(4.0, 5.0, 6.0, 1.0, 2.0, 3.0);
  ksl_coscrew_t c2 = ksl_coscrew(3.0, 2.0, 1.0, 6.0, 5.0, 4.0);
  ksl_coscrew_t c3;
  ksl_cross_sc(&s1, &c2, &c3);
  ck_assert_double_eq_tol(c3.m0, -4.0, 1.e-9);
  ck_assert_double_eq_tol(c3.m1, 8.0, 1.e-9);
  ck_assert_double_eq_tol(c3.m2, -4.0, 1.e-9);
  ck_assert_double_eq_tol(c3.m3, -14.0, 1.e-9);
  ck_assert_double_eq_tol(c3.m4, 28.0, 1.e-9);
  ck_assert_double_eq_tol(c3.m5, -14.0, 1.e-9);
}
END_TEST

START_TEST(test_cross_scf) {
  ksl_screwf_t s1 = ksl_screwf(4.0, 5.0, 6.0, 1.0, 2.0, 3.0);
  ksl_coscrewf_t c2 = ksl_coscrewf(3.0, 2.0, 1.0, 6.0, 5.0, 4.0);
  ksl_coscrewf_t c3;
  ksl_cross_scf(&s1, &c2, &c3);
  ck_assert_float_eq_tol(c3.m0, -4.0, 1.e-5);
  ck_assert_float_eq_tol(c3.m1, 8.0, 1.e-5);
  ck_assert_float_eq_tol(c3.m2, -4.0, 1.e-5);
  ck_assert_float_eq_tol(c3.m3, -14.0, 1.e-5);
  ck_assert_float_eq_tol(c3.m4, 28.0, 1.e-5);
  ck_assert_float_eq_tol(c3.m5, -14.0, 1.e-5);
}
END_TEST

START_TEST(test_cross_sca) {
  ksl_screw_t s1 = ksl_screw(4.0, 5.0, 6.0, 1.0, 2.0, 3.0);
  ksl_coscrew_t c2 = ksl_coscrew(0.0, 0.0, 0.0, 6.0, 5.0, 4.0);
  ksl_coscrew_t c3;
  ksl_cross_sca(&s1, &c2, &c3);
  ck_assert_double_eq_tol(c3.m0, 0.0, 1.e-9);
  ck_assert_double_eq_tol(c3.m1, 0.0, 1.e-9);
  ck_assert_double_eq_tol(c3.m2, 0.0, 1.e-9);
  ck_assert_double_eq_tol(c3.m3, -7.0, 1.e-9);
  ck_assert_double_eq_tol(c3.m4, 14.0, 1.e-9);
  ck_assert_double_eq_tol(c3.m5, -7.0, 1.e-9);
}
END_TEST

START_TEST(test_cross_scaf) {
  ksl_screwf_t s1 = ksl_screwf(4.0, 5.0, 6.0, 1.0, 2.0, 3.0);
  ksl_coscrewf_t c2 = ksl_coscrewf(0.0, 0.0, 0.0, 6.0, 5.0, 4.0);
  ksl_coscrewf_t c3;
  ksl_cross_scaf(&s1, &c2, &c3);
  ck_assert_float_eq_tol(c3.m0, 0.0, 1.e-5);
  ck_assert_float_eq_tol(c3.m1, 0.0, 1.e-5);
  ck_assert_float_eq_tol(c3.m2, 0.0, 1.e-5);
  ck_assert_float_eq_tol(c3.m3, -7.0, 1.e-5);
  ck_assert_float_eq_tol(c3.m4, 14.0, 1.e-5);
  ck_assert_float_eq_tol(c3.m5, -7.0, 1.e-5);
}
END_TEST

START_TEST(test_product_CoAdrc) {
  ksl_mat3x3_t R =
    ksl_mat3x3(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01,
               7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01,
               2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01);
  ksl_coscrew_t c1 = ksl_coscrew(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_coscrew_t c2;
  ksl_product_CoAdrc(&R, &c1, &c2);
  ck_assert_double_eq_tol(c2.m0, 1.86212787082e+00, 1.e-9);
  ck_assert_double_eq_tol(c2.m1, -9.58674952426e-01, 1.e-9);
  ck_assert_double_eq_tol(c2.m2, 3.10055190705e+00, 1.e-9);
  ck_assert_double_eq_tol(c2.m3, 4.45275160950e+00, 1.e-9);
  ck_assert_double_eq_tol(c2.m4, -2.94160227256e-01, 1.e-9);
  ck_assert_double_eq_tol(c2.m5, 7.55555907030e+00, 1.e-9);
}
END_TEST

START_TEST(test_product_CoAdrcf) {
  ksl_mat3x3f_t R =
    ksl_mat3x3f(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01,
                7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01,
                2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01);
  ;
  ksl_coscrewf_t c1 = ksl_coscrewf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_coscrewf_t c2;
  ksl_product_CoAdrcf(&R, &c1, &c2);
  ck_assert_float_eq_tol(c2.m0, 1.86212787082e+00, 1.e-5);
  ck_assert_float_eq_tol(c2.m1, -9.58674952426e-01, 1.e-5);
  ck_assert_float_eq_tol(c2.m2, 3.10055190705e+00, 1.e-5);
  ck_assert_float_eq_tol(c2.m3, 4.45275160950e+00, 1.e-5);
  ck_assert_float_eq_tol(c2.m4, -2.94160227256e-01, 1.e-5);
  ck_assert_float_eq_tol(c2.m5, 7.55555907030e+00, 1.e-5);
}
END_TEST

START_TEST(test_product_CoAdrcinv) {
  ksl_mat3x3_t R =
    ksl_mat3x3(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01,
               7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01,
               2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01);
  ksl_coscrew_t c1 = ksl_coscrew(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_coscrew_t c2;
  ksl_product_CoAdrcinv(&R, &c1, &c2);
  ck_assert_double_eq_tol(c2.m0, -1.86212787082e+00, 1.e-9);
  ck_assert_double_eq_tol(c2.m1, 9.58674952426e-01, 1.e-9);
  ck_assert_double_eq_tol(c2.m2, -3.10055190705e+00, 1.e-9);
  ck_assert_double_eq_tol(c2.m3, -4.45275160950e+00, 1.e-9);
  ck_assert_double_eq_tol(c2.m4, 2.94160227256e-01, 1.e-9);
  ck_assert_double_eq_tol(c2.m5, -7.55555907030e+00, 1.e-9);
}
END_TEST

START_TEST(test_product_CoAdrcinvf) {
  ksl_mat3x3f_t R =
    ksl_mat3x3f(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01,
                7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01,
                2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01);
  ksl_coscrewf_t c1 = ksl_coscrewf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_coscrewf_t c2;
  ksl_product_CoAdrcinvf(&R, &c1, &c2);
  ck_assert_float_eq_tol(c2.m0, -1.86212787082e+00, 1.e-5);
  ck_assert_float_eq_tol(c2.m1, 9.58674952426e-01, 1.e-5);
  ck_assert_float_eq_tol(c2.m2, -3.10055190705e+00, 1.e-5);
  ck_assert_float_eq_tol(c2.m3, -4.45275160950e+00, 1.e-5);
  ck_assert_float_eq_tol(c2.m4, 2.94160227256e-01, 1.e-5);
  ck_assert_float_eq_tol(c2.m5, -7.55555907030e+00, 1.e-5);
}
END_TEST

START_TEST(test_product_CoAdrinvc) {
  ksl_mat3x3_t R =
    ksl_mat3x3(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01,
               7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01,
               2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01);
  ksl_coscrew_t c1 = ksl_coscrew(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_coscrew_t c2;
  ksl_product_CoAdrinvc(&R, &c1, &c2);
  ck_assert_double_eq_tol(c2.m0, 2.81970484698e+00, 1.e-9);
  ck_assert_double_eq_tol(c2.m1, 2.39883129770e+00, 1.e-9);
  ck_assert_double_eq_tol(c2.m2, 5.43022081575e-01, 1.e-9);
  ck_assert_double_eq_tol(c2.m3, 7.57284483310e+00, 1.e-9);
  ck_assert_double_eq_tol(c2.m4, 4.01097373043e+00, 1.e-9);
  ck_assert_double_eq_tol(c2.m5, 1.88788528983e+00, 1.e-9);
}
END_TEST

START_TEST(test_product_CoAdrinvcf) {
  ksl_mat3x3f_t R =
    ksl_mat3x3f(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01,
                7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01,
                2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01);
  ksl_coscrewf_t c1 = ksl_coscrewf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_coscrewf_t c2;
  ksl_product_CoAdrinvcf(&R, &c1, &c2);
  ck_assert_float_eq_tol(c2.m0, 2.81970484698e+00, 1.e-5);
  ck_assert_float_eq_tol(c2.m1, 2.39883129770e+00, 1.e-5);
  ck_assert_float_eq_tol(c2.m2, 5.43022081575e-01, 1.e-5);
  ck_assert_float_eq_tol(c2.m3, 7.57284483310e+00, 1.e-5);
  ck_assert_float_eq_tol(c2.m4, 4.01097373043e+00, 1.e-5);
  ck_assert_float_eq_tol(c2.m5, 1.88788528983e+00, 1.e-5);
}
END_TEST

START_TEST(test_product_CoAdtc) {
  ksl_vec3_t t = ksl_vec3(1.0, 2.0, 3.0);
  ksl_coscrew_t c1 = ksl_coscrew(4.0, 5.0, 6.0, 1.0, 2.0, 3.0);
  ksl_coscrew_t c2;
  ksl_product_CoAdtc(&t, &c1, &c2);
  ck_assert_double_eq_tol(c2.m0, 4.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m1, 5.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m2, 6.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m3, -2.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m4, 8.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m5, 0.0, 1.e-9);
}
END_TEST

START_TEST(test_product_CoAdtcf) {
  ksl_vec3f_t t = ksl_vec3f(1.0, 2.0, 3.0);
  ksl_coscrewf_t c1 = ksl_coscrewf(4.0, 5.0, 6.0, 1.0, 2.0, 3.0);
  ksl_coscrewf_t c2;
  ksl_product_CoAdtcf(&t, &c1, &c2);
  ck_assert_float_eq_tol(c2.m0, 4.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m1, 5.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m2, 6.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m3, -2.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m4, 8.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m5, 0.0, 1.e-5);
}
END_TEST

START_TEST(test_product_CoAdtinvc) {
  ksl_vec3_t t = ksl_vec3(1.0, 2.0, 3.0);
  ksl_coscrew_t c1 = ksl_coscrew(4.0, 5.0, 6.0, 1.0, 2.0, 3.0);
  ksl_coscrew_t c2;
  ksl_product_CoAdtinvc(&t, &c1, &c2);
  ck_assert_double_eq_tol(c2.m0, 4.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m1, 5.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m2, 6.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m3, 4.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m4, -4.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m5, 6.0, 1.e-9);
}
END_TEST

START_TEST(test_product_CoAdtinvcf) {
  ksl_vec3f_t t = ksl_vec3f(1.0, 2.0, 3.0);
  ksl_coscrewf_t c1 = ksl_coscrewf(4.0, 5.0, 6.0, 1.0, 2.0, 3.0);
  ksl_coscrewf_t c2;
  ksl_product_CoAdtinvcf(&t, &c1, &c2);
  ck_assert_float_eq_tol(c2.m0, 4.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m1, 5.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m2, 6.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m3, 4.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m4, -4.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m5, 6.0, 1.e-5);
}
END_TEST

START_TEST(test_product_CoAdtcinv) {
  ksl_vec3_t t = ksl_vec3(1.0, 2.0, 3.0);
  ksl_coscrew_t c1 = ksl_coscrew(4.0, 5.0, 6.0, 1.0, 2.0, 3.0);
  ksl_coscrew_t c2;
  ksl_product_CoAdtcinv(&t, &c1, &c2);
  ck_assert_double_eq_tol(c2.m0, -4.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m1, -5.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m2, -6.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m3, 2.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m4, -8.0, 1.e-9);
  ck_assert_double_eq_tol(c2.m5, 0.0, 1.e-9);
}
END_TEST

START_TEST(test_product_CoAdtcinvf) {
  ksl_vec3f_t t = ksl_vec3f(1.0, 2.0, 3.0);
  ksl_coscrewf_t c1 = ksl_coscrewf(4.0, 5.0, 6.0, 1.0, 2.0, 3.0);
  ksl_coscrewf_t c2;
  ksl_product_CoAdtcinvf(&t, &c1, &c2);
  ck_assert_float_eq_tol(c2.m0, -4.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m1, -5.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m2, -6.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m3, 2.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m4, -8.0, 1.e-5);
  ck_assert_float_eq_tol(c2.m5, 0.0, 1.e-5);
}
END_TEST

START_TEST(test_product_CoAdc) {
  ksl_SE3_t D =
    ksl_SE3(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
            7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
            2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);
  ksl_coscrew_t c1 = ksl_coscrew(4.0, 5.0, 6.0, 1.0, 2.0, 3.0);
  ksl_coscrew_t c2;
  ksl_product_CoAdc(&D, &c1, &c2);
  ck_assert_double_eq_tol(c2.m0, 4.45275160950e+00, 1.e-9);
  ck_assert_double_eq_tol(c2.m1, -2.94160227256e-01, 1.e-9);
  ck_assert_double_eq_tol(c2.m2, 7.55555907030e+00, 1.e-9);
  ck_assert_double_eq_tol(c2.m3, 1.78557266932e+01, 1.e-9);
  ck_assert_double_eq_tol(c2.m4, 4.84402080578e+00, 1.e-9);
  ck_assert_double_eq_tol(c2.m5, -6.09911153921e+00, 1.e-9);
}
END_TEST

START_TEST(test_product_CoAdcf) {
  ksl_SE3f_t D =
    ksl_SE3f(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
             7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
             2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);
  ksl_coscrewf_t c1 = ksl_coscrewf(4.0, 5.0, 6.0, 1.0, 2.0, 3.0);
  ksl_coscrewf_t c2;
  ksl_product_CoAdcf(&D, &c1, &c2);
  ck_assert_float_eq_tol(c2.m0, 4.45275160950e+00, 1.e-5);
  ck_assert_float_eq_tol(c2.m1, -2.94160227256e-01, 1.e-5);
  ck_assert_float_eq_tol(c2.m2, 7.55555907030e+00, 1.e-5);
  ck_assert_float_eq_tol(c2.m3, 1.78557266932e+01, 1.e-5);
  ck_assert_float_eq_tol(c2.m4, 4.84402080578e+00, 1.e-5);
  ck_assert_float_eq_tol(c2.m5, -6.09911153921e+00, 1.e-5);
}
END_TEST

START_TEST(test_product_CoAdcinv) {
  ksl_SE3_t D =
    ksl_SE3(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
            7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
            2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);
  ksl_coscrew_t c1 = ksl_coscrew(4.0, 5.0, 6.0, 1.0, 2.0, 3.0);
  ksl_coscrew_t c2;
  ksl_product_CoAdcinv(&D, &c1, &c2);
  ck_assert_double_eq_tol(c2.m0, -4.45275160950e+00, 1.e-9);
  ck_assert_double_eq_tol(c2.m1, 2.94160227256e-01, 1.e-9);
  ck_assert_double_eq_tol(c2.m2, -7.55555907030e+00, 1.e-9);
  ck_assert_double_eq_tol(c2.m3, -1.78557266932e+01, 1.e-9);
  ck_assert_double_eq_tol(c2.m4, -4.84402080578e+00, 1.e-9);
  ck_assert_double_eq_tol(c2.m5, 6.09911153921e+00, 1.e-9);
}
END_TEST

START_TEST(test_product_CoAdcinvf) {
  ksl_SE3f_t D =
    ksl_SE3f(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
             7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
             2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);
  ksl_coscrewf_t c1 = ksl_coscrewf(4.0, 5.0, 6.0, 1.0, 2.0, 3.0);
  ksl_coscrewf_t c2;
  ksl_product_CoAdcinvf(&D, &c1, &c2);
  ck_assert_float_eq_tol(c2.m0, -4.45275160950e+00, 1.e-5);
  ck_assert_float_eq_tol(c2.m1, 2.94160227256e-01, 1.e-5);
  ck_assert_float_eq_tol(c2.m2, -7.55555907030e+00, 1.e-5);
  ck_assert_float_eq_tol(c2.m3, -1.78557266932e+01, 1.e-5);
  ck_assert_float_eq_tol(c2.m4, -4.84402080578e+00, 1.e-5);
  ck_assert_float_eq_tol(c2.m5, 6.09911153921e+00, 1.e-5);
}
END_TEST

START_TEST(test_product_CoAdinvc) {
  ksl_SE3_t D =
    ksl_SE3(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
            7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
            2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);
  ksl_coscrew_t c1 = ksl_coscrew(4.0, 5.0, 6.0, 1.0, 2.0, 3.0);
  ksl_coscrew_t c2;
  ksl_product_CoAdinvc(&D, &c1, &c2);
  ck_assert_double_eq_tol(c2.m0, 7.57284483310e+00, 1.e-9);
  ck_assert_double_eq_tol(c2.m1, 4.01097373043e+00, 1.e-9);
  ck_assert_double_eq_tol(c2.m2, 1.88788528983e+00, 1.e-9);
  ck_assert_double_eq_tol(c2.m3, 4.69033831505e-01, 1.e-9);
  ck_assert_double_eq_tol(c2.m4, 3.60988863525e+00, 1.e-9);
  ck_assert_double_eq_tol(c2.m5, 7.39923721109e+00, 1.e-9);
}
END_TEST

START_TEST(test_product_CoAdinvcf) {
  ksl_SE3f_t D =
    ksl_SE3f(5.72061402818e-01, -4.15626937777e-01, 7.07106781187e-01, 1.0,
             7.89312333511e-01, 4.45650105751e-02, -6.12372435696e-01, 2.0,
             2.23006259046e-01, 9.08442738111e-01, 3.53553390593e-01, 3.0);
  ksl_coscrewf_t c1 = ksl_coscrewf(4.0, 5.0, 6.0, 1.0, 2.0, 3.0);
  ksl_coscrewf_t c2;
  ksl_product_CoAdinvcf(&D, &c1, &c2);
  ck_assert_float_eq_tol(c2.m0, 7.57284483310e+00, 1.e-5);
  ck_assert_float_eq_tol(c2.m1, 4.01097373043e+00, 1.e-5);
  ck_assert_float_eq_tol(c2.m2, 1.88788528983e+00, 1.e-5);
  ck_assert_float_eq_tol(c2.m3, 4.69033831505e-01, 1.e-5);
  ck_assert_float_eq_tol(c2.m4, 3.60988863525e+00, 1.e-5);
  ck_assert_float_eq_tol(c2.m5, 7.39923721109e+00, 1.e-5);
}
END_TEST

/* Duality between screws and coscrews: transforming both with the same
displacement leaves their power product unchanged, and the coscrew cross
product is the negative adjoint of the screw cross product. */

START_TEST(test_product_CoAdc_Ads_duality) {
  ksl_SE3_t D;
  ksl_vec3_t angles = ksl_vec3(0.2, -0.6, 1.1);
  ksl_mat3x3_setFromEulerAngles(&D.R, KSL_AXIS_XYZ, &angles);
  D.t = ksl_vec3(0.4, -0.7, 1.3);
  ksl_screw_t s = ksl_screw(1.0, -2.0, 0.5, 0.3, 0.8, -1.2);
  ksl_coscrew_t c = ksl_coscrew(-0.4, 1.5, 2.0, 0.7, -0.9, 0.25);

  ksl_screw_t s2;
  ksl_coscrew_t c2;
  ksl_product_Ads(&D, &s, &s2);
  ksl_product_CoAdc(&D, &c, &c2);
  ck_assert_double_eq_tol(ksl_dot_cs(&c2, &s2), ksl_dot_cs(&c, &s), 1e-12);

  ksl_product_Adinvs(&D, &s, &s2);
  ksl_product_CoAdinvc(&D, &c, &c2);
  ck_assert_double_eq_tol(ksl_dot_cs(&c2, &s2), ksl_dot_cs(&c, &s), 1e-12);

  /* Ad^-1 * Ad = I */
  ksl_screw_t s3;
  ksl_product_Ads(&D, &s, &s2);
  ksl_product_Adinvs(&D, &s2, &s3);
  for(int i = 0; i < 6; i++) {
    ck_assert_double_eq_tol(s3.at[i], s.at[i], 1e-12);
  }

  /* CoAd^-1 * CoAd = I */
  ksl_coscrew_t c3;
  ksl_product_CoAdc(&D, &c, &c2);
  ksl_product_CoAdinvc(&D, &c2, &c3);
  for(int i = 0; i < 6; i++) {
    ck_assert_double_eq_tol(c3.at[i], c.at[i], 1e-12);
  }
}
END_TEST

START_TEST(test_cross_sc_duality) {
  /* (s1 x* c) . s2 == -c . (s1 x s2) */
  ksl_screw_t s1 = ksl_screw(1.0, -2.0, 0.5, 0.3, 0.8, -1.2);
  ksl_screw_t s2 = ksl_screw(0.6, 0.1, -0.9, -1.4, 0.2, 0.75);
  ksl_coscrew_t c = ksl_coscrew(-0.4, 1.5, 2.0, 0.7, -0.9, 0.25);

  ksl_coscrew_t s1xc;
  ksl_cross_sc(&s1, &c, &s1xc);
  ksl_screw_t s1xs2;
  ksl_cross_ss(&s1, &s2, &s1xs2);
  ck_assert_double_eq_tol(ksl_dot_cs(&s1xc, &s2), -ksl_dot_cs(&c, &s1xs2),
                          1e-12);
}
END_TEST

Suite* coscrew_suite(void) {
  Suite* s = suite_create("coscrew");
  TCase* tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_coscrew_create);
  tcase_add_test(tc_core, test_coscrewf_create);
  tcase_add_test(tc_core, test_coscrew_alloc);
  tcase_add_test(tc_core, test_coscrewf_alloc);
  tcase_add_test(tc_core, test_coscrew_norm);
  tcase_add_test(tc_core, test_coscrewf_norm);
  tcase_add_test(tc_core, test_coscrew_normalize);
  tcase_add_test(tc_core, test_coscrewf_normalize);
  tcase_add_test(tc_core, test_coscrew_normalize_scale);
  tcase_add_test(tc_core, test_coscrew_normalize_degenerate);
  tcase_add_test(tc_core, test_coscrew_scale);
  tcase_add_test(tc_core, test_coscrewf_scale);
  tcase_add_test(tc_core, test_coscrew_copy);
  tcase_add_test(tc_core, test_coscrewf_copy);
  tcase_add_test(tc_core, test_coscrew_invert);
  tcase_add_test(tc_core, test_coscrewf_invert);
  tcase_add_test(tc_core, test_coscrew_inverted);
  tcase_add_test(tc_core, test_coscrewf_inverted);
  tcase_add_test(tc_core, test_axpy_cc);
  tcase_add_test(tc_core, test_axpy_ccf);
  tcase_add_test(tc_core, test_xpy_cc);
  tcase_add_test(tc_core, test_xpy_ccf);
  tcase_add_test(tc_core, test_nxpy_cc);
  tcase_add_test(tc_core, test_nxpy_ccf);
  tcase_add_test(tc_core, test_product_ac);
  tcase_add_test(tc_core, test_product_acf);
  tcase_add_test(tc_core, test_add_cc);
  tcase_add_test(tc_core, test_add_ccf);
  tcase_add_test(tc_core, test_subtract_cc);
  tcase_add_test(tc_core, test_subtract_ccf);
  tcase_add_test(tc_core, test_add_cct);
  tcase_add_test(tc_core, test_add_cctf);
  tcase_add_test(tc_core, test_hctx);
  tcase_add_test(tc_core, test_hctxf);
  tcase_add_test(tc_core, test_hcty);
  tcase_add_test(tc_core, test_hctyf);
  tcase_add_test(tc_core, test_hctz);
  tcase_add_test(tc_core, test_hctzf);
  tcase_add_test(tc_core, test_hcrx);
  tcase_add_test(tc_core, test_hcrxf);
  tcase_add_test(tc_core, test_hcry);
  tcase_add_test(tc_core, test_hcryf);
  tcase_add_test(tc_core, test_hcrz);
  tcase_add_test(tc_core, test_hcrzf);
  tcase_add_test(tc_core, test_hctxinv);
  tcase_add_test(tc_core, test_hctxinvf);
  tcase_add_test(tc_core, test_hctyinv);
  tcase_add_test(tc_core, test_hctyinvf);
  tcase_add_test(tc_core, test_hctzinv);
  tcase_add_test(tc_core, test_hctzinvf);
  tcase_add_test(tc_core, test_hcrxinv);
  tcase_add_test(tc_core, test_hcrxinvf);
  tcase_add_test(tc_core, test_hcryinv);
  tcase_add_test(tc_core, test_hcryinvf);
  tcase_add_test(tc_core, test_hcrzinv);
  tcase_add_test(tc_core, test_hcrzinvf);
  tcase_add_test(tc_core, test_cross_sc);
  tcase_add_test(tc_core, test_cross_scf);
  tcase_add_test(tc_core, test_cross_sca);
  tcase_add_test(tc_core, test_cross_scaf);
  tcase_add_test(tc_core, test_product_CoAdrc);
  tcase_add_test(tc_core, test_product_CoAdrcf);
  tcase_add_test(tc_core, test_product_CoAdrcinv);
  tcase_add_test(tc_core, test_product_CoAdrcinvf);
  tcase_add_test(tc_core, test_product_CoAdrinvc);
  tcase_add_test(tc_core, test_product_CoAdrinvcf);
  tcase_add_test(tc_core, test_product_CoAdtc);
  tcase_add_test(tc_core, test_product_CoAdtcf);
  tcase_add_test(tc_core, test_product_CoAdtinvc);
  tcase_add_test(tc_core, test_product_CoAdtinvcf);
  tcase_add_test(tc_core, test_product_CoAdtcinv);
  tcase_add_test(tc_core, test_product_CoAdtcinvf);
  tcase_add_test(tc_core, test_product_CoAdc);
  tcase_add_test(tc_core, test_product_CoAdcf);
  tcase_add_test(tc_core, test_product_CoAdcinv);
  tcase_add_test(tc_core, test_product_CoAdcinvf);
  tcase_add_test(tc_core, test_product_CoAdinvc);
  tcase_add_test(tc_core, test_product_CoAdinvcf);
  tcase_add_test(tc_core, test_product_CoAdc_Ads_duality);
  tcase_add_test(tc_core, test_cross_sc_duality);

  suite_add_tcase(s, tc_core);
  return s;
}

int main(void) {
  int number_failed;
  Suite* s = coscrew_suite();
  SRunner* sr = srunner_create(s);
  srunner_set_log(sr, "check_coscrew.log");
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
