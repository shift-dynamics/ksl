#include <config.h>

#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "print.h"
#include "screw.h"

START_TEST(test_screw_create) {
  ksl_screw_t s = {{1.0, 2.0, 3.0, 4.0, 5.0, 6.0}};
  ck_assert(s.lin.x == s.at[0]);
  ck_assert(s.lin.y == s.at[1]);
  ck_assert(s.lin.z == s.at[2]);
  ck_assert(s.ang.x == s.at[3]);
  ck_assert(s.ang.y == s.at[4]);
  ck_assert(s.ang.z == s.at[5]);
  ck_assert(s.m0 == s.at[0]);
  ck_assert(s.m1 == s.at[1]);
  ck_assert(s.m2 == s.at[2]);
  ck_assert(s.m3 == s.at[3]);
  ck_assert(s.m4 == s.at[4]);
  ck_assert(s.m5 == s.at[5]);
}
END_TEST

START_TEST(test_screw_cross_ss) {
  ksl_screw_t s1 = {{4.0, 5.0, 6.0, 1.0, 2.0, 3.0}};
  ksl_screw_t s2 = {{6.0, 5.0, 4.0, 3.0, 2.0, 1.0}};
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

START_TEST(test_screw_cross_ssf) {
  ksl_screwf_t s1 = {{4.0, 5.0, 6.0, 1.0, 2.0, 3.0}};
  ksl_screwf_t s2 = {{6.0, 5.0, 4.0, 3.0, 2.0, 1.0}};
  ksl_screwf_t s3;

  ksl_cross_ssf(&s1, &s2, &s3);

  ck_assert_float_eq_tol(s3.m0, -14.0, 1.e-6);
  ck_assert_float_eq_tol(s3.m1, 28.0, 1.e-6);
  ck_assert_float_eq_tol(s3.m2, -14.0, 1.e-6);
  ck_assert_float_eq_tol(s3.m3, -4.0, 1.e-6);
  ck_assert_float_eq_tol(s3.m4, 8.0, 1.e-6);
  ck_assert_float_eq_tol(s3.m5, -4.0, 1.e-6);
}
END_TEST
Suite* screw_suite(void) {
  Suite* s = suite_create("screw");
  TCase* tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_screw_create);
  tcase_add_test(tc_core, test_screw_cross_ss);
  tcase_add_test(tc_core, test_screw_cross_ssf);
  suite_add_tcase(s, tc_core);
  return s;
}

int main(void) {
  int number_failed;
  Suite* s = screw_suite();
  SRunner* sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
