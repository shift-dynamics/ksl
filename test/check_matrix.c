#include <config.h>

#include <check.h>
#include <stdlib.h>

#include "matrix.h"

START_TEST(test_matrix_SE3_alloc) {
  ksl_SE3_t* D = ksl_SE3_alloc(1);
  ck_assert_ptr_nonnull(D);
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 4; j++) {
      if(i == j) {
        ck_assert_double_eq(D[0].as_array[j][i], 1.0);
      } else {
        ck_assert_double_eq(D[0].as_array[j][i], 0.0);
      }
    }
  }
  free(D);
}
END_TEST

START_TEST(test_matrix_SE3f_alloc) {
  const int n = 2;
  ksl_SE3f_t* Df = ksl_SE3f_alloc(n);
  ck_assert_ptr_nonnull(Df);
  for(int k = 0; k < n; k++) {
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 4; j++) {
        if(i == j) {
          ck_assert_double_eq(Df[k].as_array[j][i], 1.0);
        } else {
          ck_assert_double_eq(Df[k].as_array[j][i], 0.0);
        }
      }
    }
  }
  free(Df);
}
END_TEST

START_TEST(test_matrix_mat3x3_alloc) {
  const int n = 3;
  ksl_mat3x3_t* R = ksl_mat3x3_alloc(n);
  ck_assert_ptr_nonnull(R);
  for(int k = 0; k < n; k++) {
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
        if(i == j) {
          ck_assert_double_eq(R[k].as_array[j][i], 1.0);
        } else {
          ck_assert_double_eq(R[k].as_array[j][i], 0.0);
        }
      }
    }
  }
  free(R);
}
END_TEST

START_TEST(test_matrix_mat3x3f_alloc) {
  const int n = 4;
  ksl_mat3x3f_t* Rf = ksl_mat3x3f_alloc(n);
  ck_assert_ptr_nonnull(Rf);
  for(int k = 0; k < n; k++) {
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
        if(i == j) {
          ck_assert_double_eq(Rf[k].as_array[j][i], 1.0);
        } else {
          ck_assert_double_eq(Rf[k].as_array[j][i], 0.0);
        }
      }
    }
  }
  free(Rf);
}
END_TEST

START_TEST(test_matrix_mat4x4_alloc) {
  const int n = 5;
  ksl_mat4x4_t* M = ksl_mat4x4_alloc(n);
  ck_assert_ptr_nonnull(M);
  for(int k = 0; k < n; k++) {
    for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 4; j++) {
        if(i == j) {
          ck_assert_double_eq(M[k].as_array[j][i], 1.0);
        } else {
          ck_assert_double_eq(M[k].as_array[j][i], 0.0);
        }
      }
    }
  }
  free(M);
}
END_TEST

START_TEST(test_matrix_mat4x4f_alloc) {
  const int n = 6;
  ksl_mat4x4f_t* Mf = ksl_mat4x4f_alloc(n);
  ck_assert_ptr_nonnull(Mf);
  for(int k = 0; k < n; k++) {
    for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 4; j++) {
        if(i == j) {
          ck_assert_double_eq(Mf[k].as_array[j][i], 1.0);
        } else {
          ck_assert_double_eq(Mf[k].as_array[j][i], 0.0);
        }
      }
    }
  }
  free(Mf);
}
END_TEST

Suite* matrix_suite(void) {
  Suite* s = suite_create("matrix");
  TCase* tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_matrix_SE3_alloc);
  tcase_add_test(tc_core, test_matrix_SE3f_alloc);
  tcase_add_test(tc_core, test_matrix_mat3x3_alloc);
  tcase_add_test(tc_core, test_matrix_mat3x3f_alloc);
  tcase_add_test(tc_core, test_matrix_mat4x4_alloc);
  tcase_add_test(tc_core, test_matrix_mat4x4f_alloc);
  suite_add_tcase(s, tc_core);
  return s;
}

int main(void) {
  int number_failed;
  Suite* s = matrix_suite();
  SRunner* sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
