#include <config.h>
#include <stdlib.h>

#include <assert.h>
#include <check.h>
#include <float.h>
#include <stdio.h>
#include <time.h>

#include "ksl/quaternion.h"

START_TEST(test_quaternion_create) {
  ksl_quaternion_t q = {{1.0, 2.0, 3.0, 4.0}};
  ck_assert(q.x == q.at[0]);
  ck_assert(q.y == q.at[1]);
  ck_assert(q.z == q.at[2]);
  ck_assert(q.w == q.at[3]);
}
END_TEST

Suite* quaternion_suite(void) {
  Suite* s = suite_create("quaternion");

  /* Core test case */
  TCase* tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_quaternion_create);
  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
  int number_failed;
  Suite* s = quaternion_suite();
  SRunner* sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
