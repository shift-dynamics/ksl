#include <config.h>

#include <check.h>
#include <stdlib.h>

#include "ksl_axis.h"

START_TEST(test_axis_create) {
  ksl_vec3i_t axis = ksl_axis_getVector(KSL_AXIS_XYZ);
  ck_assert(axis.x == 0);
  ck_assert(axis.y == 1);
  ck_assert(axis.z == 2);
}
END_TEST

Suite* axis_suite(void) {
  Suite* s = suite_create("axis");
  TCase* tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_axis_create);
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
