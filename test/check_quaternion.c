#include <config.h>
#include <stdlib.h>

#include <assert.h>
#include <check.h>
#include <float.h>
#include <stdio.h>
#include <time.h>

#include <math.h>

#include "ksl/matrix.h"
#include "ksl/quaternion.h"

static ksl_quaternion_t make_test_quaternion(double ax, double ay, double az,
                                             double angle) {
  ksl_vec3_t axis = ksl_vec3(ax, ay, az);
  ksl_vec3_normalize(&axis);
  double s = sin(0.5 * angle);
  return ksl_quaternion(axis.x * s, axis.y * s, axis.z * s, cos(0.5 * angle));
}

static ksl_quaternion_t quaternion_conj(const ksl_quaternion_t* q) {
  return ksl_quaternion(-q->x, -q->y, -q->z, q->w);
}

START_TEST(test_quaternion_create) {
  ksl_quaternion_t q = {{1.0, 2.0, 3.0, 4.0}};
  ck_assert(q.x == q.at[0]);
  ck_assert(q.y == q.at[1]);
  ck_assert(q.z == q.at[2]);
  ck_assert(q.w == q.at[3]);
}
END_TEST

START_TEST(test_quaternion_product_qq) {
  /* R(q1 * q2) == R(q1) * R(q2) */
  ksl_quaternion_t q1 = make_test_quaternion(1.0, 2.0, 3.0, 0.7);
  ksl_quaternion_t q2 = make_test_quaternion(-0.5, 0.3, 0.9, 1.9);
  ksl_quaternion_t q3;
  ksl_product_qq(&q1, &q2, &q3);

  ksl_mat3x3_t r1, r2, r3, expected;
  ksl_quaternion_toMat3x3(&q1, &r1);
  ksl_quaternion_toMat3x3(&q2, &r2);
  ksl_quaternion_toMat3x3(&q3, &r3);
  ksl_product_drdr(&r1, &r2, &expected);

  for(int i = 0; i < 9; i++) {
    ck_assert_double_eq_tol(r3.as_array[i], expected.as_array[i], 1e-9);
  }
}
END_TEST

START_TEST(test_quaternion_product_qconjq) {
  ksl_quaternion_t q1 = make_test_quaternion(1.0, 2.0, 3.0, 0.7);
  ksl_quaternion_t q2 = make_test_quaternion(-0.5, 0.3, 0.9, 1.9);
  ksl_quaternion_t q1c = quaternion_conj(&q1);
  ksl_quaternion_t expected;
  ksl_product_qq(&q1c, &q2, &expected);

  ksl_quaternion_t q3;
  ksl_product_qconjq(&q1, &q2, &q3);

  for(int i = 0; i < 4; i++) {
    ck_assert_double_eq_tol(q3.at[i], expected.at[i], 1e-12);
  }
}
END_TEST

START_TEST(test_quaternion_product_qqconj) {
  ksl_quaternion_t q1 = make_test_quaternion(1.0, 2.0, 3.0, 0.7);
  ksl_quaternion_t q2 = make_test_quaternion(-0.5, 0.3, 0.9, 1.9);
  ksl_quaternion_t q2c = quaternion_conj(&q2);
  ksl_quaternion_t expected;
  ksl_product_qq(&q1, &q2c, &expected);

  ksl_quaternion_t q3;
  ksl_product_qqconj(&q1, &q2, &q3);

  for(int i = 0; i < 4; i++) {
    ck_assert_double_eq_tol(q3.at[i], expected.at[i], 1e-12);
  }
}
END_TEST

START_TEST(test_quaternion_product_qconjqconj) {
  ksl_quaternion_t q1 = make_test_quaternion(1.0, 2.0, 3.0, 0.7);
  ksl_quaternion_t q2 = make_test_quaternion(-0.5, 0.3, 0.9, 1.9);
  ksl_quaternion_t q1c = quaternion_conj(&q1);
  ksl_quaternion_t q2c = quaternion_conj(&q2);
  ksl_quaternion_t expected;
  ksl_product_qq(&q1c, &q2c, &expected);

  ksl_quaternion_t q3;
  ksl_product_qconjqconj(&q1, &q2, &q3);

  for(int i = 0; i < 4; i++) {
    ck_assert_double_eq_tol(q3.at[i], expected.at[i], 1e-12);
  }
}
END_TEST

START_TEST(test_quaternion_product_qxq) {
  /* per the documentation of ksl_product_qxq, dci = {cos(theta/2),
  sin(theta/2)}, i.e. qx = {dci[1], 0, 0, dci[0]} */
  double theta = 0.8;
  double dc[2] = {cos(0.5 * theta), sin(0.5 * theta)};
  ksl_quaternion_t qx = make_test_quaternion(1.0, 0.0, 0.0, theta);
  ksl_quaternion_t q = make_test_quaternion(-0.5, 0.3, 0.9, 1.9);
  ksl_quaternion_t expected;
  ksl_product_qq(&qx, &q, &expected);

  ksl_quaternion_t q3;
  ksl_product_qxq(dc, &q, &q3);

  for(int i = 0; i < 4; i++) {
    ck_assert_double_eq_tol(q3.at[i], expected.at[i], 1e-12);
  }
}
END_TEST

START_TEST(test_quaternion_mat3x3_toQuaternion) {
  /* round trip R -> q -> R, including rotations near pi which exercise each
  branch of the conversion */
  ksl_vec3_t axes[5] = {ksl_vec3(1.0, 2.0, 3.0), ksl_vec3(1.0, 0.0, 0.0),
                        ksl_vec3(0.0, 1.0, 0.0), ksl_vec3(0.0, 0.0, 1.0),
                        ksl_vec3(1.0, 1.0, 1.0)};
  double angles[4] = {0.3, 2.0, M_PI - 1e-3, M_PI};
  for(int k = 0; k < 5; k++) {
    for(int j = 0; j < 4; j++) {
      ksl_mat3x3_t r;
      ksl_mat3x3_setFromAxisAngle(&r, &axes[k], angles[j]);
      ksl_quaternion_t q;
      ksl_mat3x3_toQuaternion(&r, &q);
      ksl_mat3x3_t r_test;
      ksl_quaternion_toMat3x3(&q, &r_test);
      for(int i = 0; i < 9; i++) {
        ck_assert_msg(fabs(r.as_array[i] - r_test.as_array[i]) < 1e-9,
                      "failed for axis %d, angle %f\n", k, angles[j]);
      }
    }
  }
}
END_TEST

Suite* quaternion_suite(void) {
  Suite* s = suite_create("quaternion");

  /* Core test case */
  TCase* tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_quaternion_create);
  tcase_add_test(tc_core, test_quaternion_product_qq);
  tcase_add_test(tc_core, test_quaternion_product_qconjq);
  tcase_add_test(tc_core, test_quaternion_product_qqconj);
  tcase_add_test(tc_core, test_quaternion_product_qconjqconj);
  tcase_add_test(tc_core, test_quaternion_product_qxq);
  tcase_add_test(tc_core, test_quaternion_mat3x3_toQuaternion);
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
