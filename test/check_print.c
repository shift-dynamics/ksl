#include <check.h>
#include <config.h>
#include <stdio.h>
#include <stdlib.h>

#include "ksl.h"

static FILE* f;

START_TEST(test_print_vec3) {
  fprintf(f, "\nvec3:\n");
  ksl_print_options_t* options = ksl_print_options();

  ksl_vec3_t v = {{1.0, 2.0, 3.0}};
  ksl_vec3_print(f, &v);

  ksl_print_setDelimiter(" ", options);

  ksl_vec3_print(f, &v, "with \" \" delimiter: ", options);

  ksl_vec3_print(f, &v, "with default delimiter: ");
  free(options);
  ck_assert(1);
}
END_TEST

START_TEST(test_print_vec3f) {
  fprintf(f, "\nvec3f:\n");
  ksl_print_options_t* options = ksl_print_options();

  ksl_vec3_t v = {{1.0, 2.0, 3.0}};
  ksl_vec3_print(f, &v);

  ksl_print_setDelimiter("\t", options);
  ksl_print_setInnerBrackets("{", "}", options);
  ksl_print_setOuterBrackets("{", "}", options);

  ksl_vec3_print(f, &v, "with \\t delimiter: ", options);

  ksl_vec3_print(f, &v, "with default delimiter: ");
  free(options);
  ck_assert(1);
}
END_TEST

START_TEST(test_print_mat3x3) {
  fprintf(f, "\nmat3x3:\n");
  ksl_print_options_t* options = ksl_print_options();
  ksl_mat3x3_t m = {{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0}};
  ksl_mat3x3_print(f, &m);

  ksl_print_setDelimiter(" ", options);
  ksl_print_setInnerBrackets("{", "}", options);
  ksl_print_setOuterBrackets("{", "}", options);
  ksl_print_setRealFormat("%0.6f");

  ksl_mat3x3_print(f, &m, "with \" \" delimiter: ", options);

  ksl_mat3x3_print(f, &m, "with default delimiter: ");
  free(options);
  ck_assert(1);
}
END_TEST

START_TEST(test_print_inertia) {
  fprintf(f, "\ninertia:\n");
  ksl_print_options_t* options = ksl_print_options();
  ksl_inertia_t m = {{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0}};
  ksl_inertia_print(f, &m);

  ksl_print_setDelimiter(" ", options);
  ksl_print_setInnerBrackets("{", "}", options);
  ksl_print_setOuterBrackets("{", "}", options);
  ksl_print_setRealFormat("% 0.3f");

  ksl_inertia_print(f, &m, "with \" \" delimiter: ", options);

  ksl_inertia_print(f, &m, "with default delimiter: ");
  free(options);
  ck_assert(1);
}
END_TEST

Suite* print_suite(void) {
  Suite* s = suite_create("print");
  TCase* tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_print_vec3);
  tcase_add_test(tc_core, test_print_vec3f);
  tcase_add_test(tc_core, test_print_mat3x3);
  tcase_add_test(tc_core, test_print_inertia);
  suite_add_tcase(s, tc_core);
  return s;
}

int main(void) {
  f = fopen("print_test.txt", "w");
  int number_failed;
  Suite* s = print_suite();
  SRunner* sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  fclose(f);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
