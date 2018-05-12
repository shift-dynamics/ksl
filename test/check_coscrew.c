#include <config.h>

#include <check.h>
#include <stdlib.h>

#include "coscrew.h"

START_TEST(test_coscrew_create) {
  ksl_coscrew_t s = {{1.0, 2.0, 3.0, 4.0, 5.0, 6.0}};
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

Suite* coscrew_suite(void) {
  Suite* s = suite_create("coscrew");
  TCase* tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_coscrew_create);
  suite_add_tcase(s, tc_core);
  return s;
}

int main(void) {
  int number_failed;
  Suite* s = coscrew_suite();
  SRunner* sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
