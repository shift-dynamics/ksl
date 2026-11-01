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

/* Hamilton product written out component by component, independent of the
library, as the reference for the SIMD and scalar implementations */
static void reference_qq(const double a[4], const double b[4], double o[4]) {
  o[0] = a[3] * b[0] + a[0] * b[3] + a[1] * b[2] - a[2] * b[1];
  o[1] = a[3] * b[1] - a[0] * b[2] + a[1] * b[3] + a[2] * b[0];
  o[2] = a[3] * b[2] + a[0] * b[1] - a[1] * b[0] + a[2] * b[3];
  o[3] = a[3] * b[3] - a[0] * b[0] - a[1] * b[1] - a[2] * b[2];
}

START_TEST(test_quaternion_product_reference) {
  /* non-unit quaternions with distinct components, so a wrong sign or lane
  in any of the products shows up */
  const double a[4] = {0.3, -1.7, 2.9, 0.45};
  const double b[4] = {-2.2, 0.8, 1.3, -0.6};
  for(int conj1 = 0; conj1 < 2; conj1++) {
    for(int conj2 = 0; conj2 < 2; conj2++) {
      double ac[4], bc[4], expected[4];
      for(int i = 0; i < 4; i++) {
        ac[i] = (conj1 && i < 3) ? -a[i] : a[i];
        bc[i] = (conj2 && i < 3) ? -b[i] : b[i];
      }
      reference_qq(ac, bc, expected);

      ksl_quaternion_t q1 = {{a[0], a[1], a[2], a[3]}};
      ksl_quaternion_t q2 = {{b[0], b[1], b[2], b[3]}};
      ksl_quaternionf_t q1f = {{a[0], a[1], a[2], a[3]}};
      ksl_quaternionf_t q2f = {{b[0], b[1], b[2], b[3]}};
      ksl_quaternion_t qo;
      ksl_quaternionf_t qof;
      if(!conj1 && !conj2) {
        ksl_product_qq(&q1, &q2, &qo);
        ksl_product_qqf(&q1f, &q2f, &qof);
      } else if(conj1 && !conj2) {
        ksl_product_qconjq(&q1, &q2, &qo);
        ksl_product_qconjqf(&q1f, &q2f, &qof);
      } else if(!conj1 && conj2) {
        ksl_product_qqconj(&q1, &q2, &qo);
        ksl_product_qqconjf(&q1f, &q2f, &qof);
      } else {
        ksl_product_qconjqconj(&q1, &q2, &qo);
        ksl_product_qconjqconjf(&q1f, &q2f, &qof);
      }
      for(int i = 0; i < 4; i++) {
        ck_assert_msg(fabs(qo.at[i] - expected[i]) < 1e-12,
                      "conj1 %d conj2 %d: component %d", conj1, conj2, i);
        ck_assert_msg(fabs(qof.at[i] - expected[i]) < 1e-5,
                      "float conj1 %d conj2 %d: component %d", conj1, conj2, i);
      }
    }
  }
}
END_TEST

START_TEST(test_quaternion_product_qxq) {
  /* dci = {sin(theta/2), cos(theta/2)} as computed by ksl_dc, i.e.
  qx = {dci[0], 0, 0, dci[1]} */
  double theta = 0.8;
  double dc[2];
  ksl_dc(0.5 * theta, dc);
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

/* every axial product ksl_product_q{x,y,z}... against the general product
with the axial quaternion written out, including the conjugate variants */
typedef void (*axial_first_fn)(const double[2], const ksl_quaternion_t*,
                               ksl_quaternion_t*);
typedef void (*axial_second_fn)(const ksl_quaternion_t*, const double[2],
                                ksl_quaternion_t*);
typedef void (*axial_first_fnf)(const float[2], const ksl_quaternionf_t*,
                                ksl_quaternionf_t*);
typedef void (*axial_second_fnf)(const ksl_quaternionf_t*, const float[2],
                                 ksl_quaternionf_t*);

static void check_axial(int axis, int axial_first, int axial_conj, int q_conj,
                        axial_first_fn f1, axial_second_fn f2,
                        axial_first_fnf f1f, axial_second_fnf f2f) {
  double theta = 0.8;
  double dc[2];
  ksl_dc(0.5 * theta, dc);
  float dcf[2];
  ksl_dcf(0.5f * (float)theta, dcf);
  ksl_quaternion_t qa = ksl_quaternion(0.0, 0.0, 0.0, dc[1]);
  qa.at[axis] = dc[0];
  ksl_quaternion_t q = make_test_quaternion(-0.5, 0.3, 0.9, 1.9);
  if(axial_conj)
    qa = quaternion_conj(&qa);
  ksl_quaternion_t qc = q_conj ? quaternion_conj(&q) : q;
  ksl_quaternion_t expected;
  if(axial_first) {
    ksl_product_qq(&qa, &qc, &expected);
  } else {
    ksl_product_qq(&qc, &qa, &expected);
  }

  ksl_quaternion_t out;
  ksl_quaternionf_t qf, outf;
  for(int i = 0; i < 4; i++)
    qf.at[i] = q.at[i];
  if(axial_first) {
    f1(dc, &q, &out);
    f1f(dcf, &qf, &outf);
  } else {
    f2(&q, dc, &out);
    f2f(&qf, dcf, &outf);
  }
  for(int i = 0; i < 4; i++) {
    ck_assert_msg(fabs(out.at[i] - expected.at[i]) < 1e-12,
                  "axis %d first %d aconj %d qconj %d: component %d", axis,
                  axial_first, axial_conj, q_conj, i);
    ck_assert_msg(fabs(outf.at[i] - expected.at[i]) < 1e-6,
                  "float axis %d first %d aconj %d qconj %d: component %d",
                  axis, axial_first, axial_conj, q_conj, i);
  }
}

#define AXIAL_FIRST(axis, ac, qc, name)                                        \
  check_axial(axis, 1, ac, qc, name, NULL, name##f, NULL)
#define AXIAL_SECOND(axis, ac, qc, name)                                       \
  check_axial(axis, 0, ac, qc, NULL, name, NULL, name##f)
#define AXIAL_ALL(axis, a)                                                     \
  AXIAL_FIRST(axis, 0, 0, ksl_product_q##a##q);                                \
  AXIAL_SECOND(axis, 0, 0, ksl_product_qq##a);                                 \
  AXIAL_FIRST(axis, 1, 0, ksl_product_q##a##conjq);                            \
  AXIAL_SECOND(axis, 1, 0, ksl_product_qq##a##conj);                           \
  AXIAL_FIRST(axis, 0, 1, ksl_product_q##a##qconj);                            \
  AXIAL_SECOND(axis, 0, 1, ksl_product_qconjq##a);                             \
  AXIAL_FIRST(axis, 1, 1, ksl_product_q##a##conjqconj);                        \
  AXIAL_SECOND(axis, 1, 1, ksl_product_qconjq##a##conj)

START_TEST(test_quaternion_product_axial) {
  AXIAL_ALL(0, x);
  AXIAL_ALL(1, y);
  AXIAL_ALL(2, z);
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
  tcase_add_test(tc_core, test_quaternion_product_reference);
  tcase_add_test(tc_core, test_quaternion_product_qxq);
  tcase_add_test(tc_core, test_quaternion_product_axial);
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
