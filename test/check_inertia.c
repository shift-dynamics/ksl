#include <config.h>

#include <check.h>
#include <stdlib.h>

#include "ksl_inertia.h"

START_TEST(test_inertia_create) {
  ksl_inertia_t inertia =
    ksl_inertia(1.0, ksl_vec3(2.0, 3.0, 4.0), 5.0, 6.0, 7.0, 8.0, 9.0, 10.0);
  ck_assert(inertia.m == inertia.at[0]);
  ck_assert(inertia.mt.x == inertia.at[1]);
  ck_assert(inertia.mt.y == inertia.at[2]);
  ck_assert(inertia.mt.z == inertia.at[3]);
  ck_assert(inertia.Ixx == inertia.at[4]);
  ck_assert(inertia.Iyy == inertia.at[5]);
  ck_assert(inertia.Izz == inertia.at[6]);
  ck_assert(inertia.Ixy == inertia.at[7]);
  ck_assert(inertia.Iyz == inertia.at[8]);
  ck_assert(inertia.Izx == inertia.at[9]);
}
END_TEST

Suite* inertia_suite(void) {
  Suite* s = suite_create("inertia");
  TCase* tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_inertia_create);
  suite_add_tcase(s, tc_core);
  return s;
}

int main(void) {
  int number_failed;
  Suite* s = inertia_suite();
  SRunner* sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
