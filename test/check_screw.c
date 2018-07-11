#include <config.h>

#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "coscrew.h"
#include "screw.h"

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
  ksl_add_ss(&s1, &s2, &s2);
  ck_assert_double_eq_tol(s2.m0, 11.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m1, 22.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m2, 33.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m3, 44.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m4, 55.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m5, 66.0, 1.e-9);
}
END_TEST

START_TEST(test_add_ssf) {
  ksl_screwf_t s1 = ksl_screwf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screwf_t s2 = ksl_screwf(10.0, 20.0, 30.0, 40.0, 50.0, 60.0);
  ksl_add_ssf(&s1, &s2, &s2);
  ck_assert_float_eq_tol(s2.m0, 11.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m1, 22.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m2, 33.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m3, 44.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m4, 55.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m5, 66.0, 1.e-5);
}
END_TEST

START_TEST(test_subtract_ss) {
  ksl_screw_t s1 = ksl_screw(10.0, 20.0, 30.0, 40.0, 50.0, 60.0);
  ksl_screw_t s2 = ksl_screw(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_subtract_ss(&s1, &s2, &s2);
  ck_assert_double_eq_tol(s2.m0, 9.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m1, 18.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m2, 27.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m3, 36.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m4, 45.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m5, 54.0, 1.e-9);
}
END_TEST

START_TEST(test_subtract_ssf) {
  ksl_screwf_t s1 = ksl_screwf(10.0, 20.0, 30.0, 40.0, 50.0, 60.0);
  ksl_screwf_t s2 = ksl_screwf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_subtract_ssf(&s1, &s2, &s2);
  ck_assert_float_eq_tol(s2.m0, 9.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m1, 18.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m2, 27.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m3, 36.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m4, 45.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m5, 54.0, 1.e-5);
}
END_TEST

START_TEST(test_add_sst) {
  ksl_screw_t s1 = ksl_screw(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screw_t s2 = ksl_screw(10.0, 20.0, 30.0, 0.0, 0.0, 0.0);
  ksl_add_sst(&s1, &s2, &s2);
  ck_assert_double_eq_tol(s2.m0, 11.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m1, 22.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m2, 33.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m3, 4.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m4, 5.0, 1.e-9);
  ck_assert_double_eq_tol(s2.m5, 6.0, 1.e-9);
}
END_TEST

START_TEST(test_add_sstf) {
  ksl_screwf_t s1 = ksl_screwf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  ksl_screwf_t s2 = ksl_screwf(10.0, 20.0, 30.0, 0.0, 0.0, 0.0);
  ksl_add_sstf(&s1, &s2, &s2);
  ck_assert_float_eq_tol(s2.m0, 11.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m1, 22.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m2, 33.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m3, 4.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m4, 5.0, 1.e-5);
  ck_assert_float_eq_tol(s2.m5, 6.0, 1.e-5);
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
