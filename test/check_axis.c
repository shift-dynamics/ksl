#include <config.h>

#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "ksl/axis.h"
#include "ksl/mat3x3.h"

START_TEST(test_axis_create) {
  ksl_vec3i_t axis = ksl_axis_getVector(KSL_AXIS_XYZ);
  ck_assert(axis.x == 0);
  ck_assert(axis.y == 1);
  ck_assert(axis.z == 2);
}
END_TEST

START_TEST(test_axis_euler_rates) {
  /* for all 12 sequences: E theta-dot = w, with w~ = R-dot R^T by central
  differences of ksl_mat3x3_setFromEulerAngles; and the inverse */
  const ksl_vec3_t angles = ksl_vec3(0.4, -0.7, 1.1);
  const ksl_vec3_t rates = ksl_vec3(0.3, -1.2, 0.8);
  const double h = 1e-6;
  for(int a = 0; a < 12; a++) {
    ksl_axis_enum_t type = (ksl_axis_enum_t)a;
    ksl_vec3_t ap, am, w, back;
    for(int i = 0; i < 3; i++) {
      ap.at[i] = angles.at[i] + h * rates.at[i];
      am.at[i] = angles.at[i] - h * rates.at[i];
    }
    ksl_mat3x3_t r, rp, rm;
    ksl_mat3x3_setFromEulerAngles(&r, type, &angles);
    ksl_mat3x3_setFromEulerAngles(&rp, type, &ap);
    ksl_mat3x3_setFromEulerAngles(&rm, type, &am);
    /* W = R-dot R^T, column major at[column][row] */
    double W[3][3];
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
        double v = 0.0;
        for(int k = 0; k < 3; k++) {
          v += (rp.at[k][i] - rm.at[k][i]) / (2 * h) * r.at[k][j];
        }
        W[i][j] = v;
      }
    }
    ksl_vec3_t wd = ksl_vec3(W[2][1], W[0][2], W[1][0]);
    ksl_axis_eulerRatesToOmega(type, &angles, &rates, &w);
    for(int i = 0; i < 3; i++) ck_assert_msg(fabs(w.at[i] - wd.at[i]) < 1e-8, "sequence %d", a);
    ck_assert(ksl_axis_omegaToEulerRates(type, &angles, &w, &back) == 0);
    for(int i = 0; i < 3; i++) ck_assert(fabs(back.at[i] - rates.at[i]) < 1e-12);
  }
  /* gimbal lock: x-y-z at theta_1 = pi/2, x-y-x at theta_1 = 0 */
  ksl_vec3_t lock1 = ksl_vec3(0.3, M_PI / 2, 0.2), lock2 = ksl_vec3(0.3, 0.0, 0.2);
  ksl_vec3_t w = ksl_vec3(1, 0, 0), out;
  ck_assert(ksl_axis_omegaToEulerRates(KSL_AXIS_XYZ, &lock1, &w, &out) != 0);
  ck_assert(ksl_axis_omegaToEulerRates(KSL_AXIS_XYX, &lock2, &w, &out) != 0);
}
END_TEST

Suite* axis_suite(void) {
  Suite* s = suite_create("axis");
  TCase* tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_axis_create);
  tcase_add_test(tc_core, test_axis_euler_rates);
  suite_add_tcase(s, tc_core);
  return s;
}

int main(void) {
  int number_failed;
  Suite* s = axis_suite();
  SRunner* sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
