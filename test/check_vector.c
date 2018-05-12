#include <config.h>
#include <stdlib.h>

#include <assert.h>
#include <check.h>
#include <float.h>
#include <stdio.h>
#include <time.h>

#include "vector.h"

START_TEST(test_vector_create) {
  ksl_vec3_t v = {{1.0, 2.0, 3.0}};
  ck_assert(v.x == v.at[0]);
  ck_assert(v.y == v.at[1]);
  ck_assert(v.z == v.at[2]);
}
END_TEST

Suite* vector_suite(void) {
  Suite* s = suite_create("vector");

  /* Core test case */
  TCase* tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_vector_create);
  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
  int number_failed;
  Suite* s = vector_suite();
  SRunner* sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
