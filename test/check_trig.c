#include <config.h>

#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "ksl/mat3x3.h"
#include "ksl/trig.h"

/* A true angle t is given to the functions as (sin t, cos t), or negated for
ksl_catan1pi; the result must be t whenever t is within pi (pi/2) of the
reference, whichever way it moved. */
START_TEST(test_catan2pi_both_directions) {
  const double refs[] = {0.0, 1.0, -2.5, 100.0, -1000.0, 1.0e6};
  const double steps[] = {-3.0, -1.6, -0.5, -0.1, 0.0, 0.1, 0.5, 1.6, 3.0};
  for(size_t r = 0; r < sizeof(refs) / sizeof(refs[0]); r++) {
    for(size_t s = 0; s < sizeof(steps) / sizeof(steps[0]); s++) {
      double t = refs[r] + steps[s];
      double got = ksl_catan2pi(sin(t), cos(t), refs[r]);
      ck_assert_double_eq_tol(got, t, 1e-9 * fmax(1.0, fabs(t)));
    }
  }
  /* a decrease of pi/2 from 0: -pi/2, not 3 pi/2 */
  ck_assert_double_eq_tol(ksl_catan2pi(-1.0, 0.0, 0.0), -M_PI_2, 1e-15);
}
END_TEST

START_TEST(test_catan1pi_both_directions) {
  const double refs[] = {0.0, 1.0, -2.5, 100.0, -1000.0, 1.0e6};
  const double steps[] = {-1.5, -1.0, -0.5, -0.1, 0.0, 0.1, 0.5, 1.0, 1.5};
  for(size_t r = 0; r < sizeof(refs) / sizeof(refs[0]); r++) {
    for(size_t s = 0; s < sizeof(steps) / sizeof(steps[0]); s++) {
      double t = refs[r] + steps[s];
      double sign = (s % 2 == 0) ? 1.0 : -1.0; /* signs known only jointly */
      double got = ksl_catan1pi(sign * sin(t), sign * cos(t), refs[r]);
      ck_assert_double_eq_tol(got, t, 1e-9 * fmax(1.0, fabs(t)));
    }
  }
  /* a decrease of 1 rad from 0: -1, not pi - 1 */
  ck_assert_double_eq_tol(ksl_catan1pi(-sin(1.0), cos(1.0), 0.0), -1.0, 1e-15);
}
END_TEST

START_TEST(test_catan_single_precision) {
  ck_assert_float_eq_tol(ksl_catan2pif(-1.0f, 0.0f, 0.0f), -(float)M_PI_2, 1e-6f);
  ck_assert_float_eq_tol(ksl_catan2pif(sinf(10.5f), cosf(10.5f), 9.0f), 10.5f,
                         1e-5f);
  ck_assert_float_eq_tol(ksl_catan1pif(-sinf(1.0f), cosf(1.0f), 0.0f), -1.0f,
                         1e-6f);
  ck_assert_float_eq_tol(ksl_catan1pif(sinf(7.2f), cosf(7.2f), 8.0f), 7.2f,
                         1e-5f);
}
END_TEST

/* Euler angles that decrease by more than pi/4 between calls are tracked
without jumps. */
START_TEST(test_euler_angles_decreasing) {
  ksl_vec3_t prev = ksl_vec3(0.0, 0.0, 0.0);
  for(int n = 1; n <= 40; n++) {
    ksl_vec3_t t = ksl_vec3(-1.0 * n, 0.3 * sin(0.2 * n), -0.9 * n);
    ksl_mat3x3_t r;
    ksl_mat3x3_setFromEulerAngles(&r, KSL_AXIS_XYZ, &t);
    ksl_vec3_t now;
    ksl_mat3x3_getEulerAnglesWithReference(&r, KSL_AXIS_XYZ, &now, &prev);
    for(int i = 0; i < 3; i++) {
      ck_assert_double_eq_tol(now.at[i], t.at[i], 1e-9);
    }
    prev = now;
  }
}
END_TEST

Suite* trig_suite(void) {
  Suite* s = suite_create("trig");
  TCase* tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_catan2pi_both_directions);
  tcase_add_test(tc_core, test_catan1pi_both_directions);
  tcase_add_test(tc_core, test_catan_single_precision);
  tcase_add_test(tc_core, test_euler_angles_decreasing);
  suite_add_tcase(s, tc_core);
  return s;
}

int main(void) {
  int number_failed;
  Suite* s = trig_suite();
  SRunner* sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
