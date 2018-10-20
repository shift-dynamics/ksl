#include <config.h>

#include <check.h>
#include <stdlib.h>

#include "ksl/util.h"

START_TEST(test_util_swap) {
  double a = 4.0;
  double a0 = a;
  double b = 6.0;
  double b0 = b;
  ksl_swap(&a, &b);
  ck_assert(b == a0);
  ck_assert(a == b0);
}
END_TEST

Suite* util_suite(void) {
  Suite* s = suite_create("util");
  TCase* tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_util_swap);
  suite_add_tcase(s, tc_core);
  return s;
}

int main(void) {
  int number_failed;
  Suite* s = util_suite();
  SRunner* sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
