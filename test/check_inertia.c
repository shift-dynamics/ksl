#include <config.h>

#include <check.h>
#include <stdlib.h>

#include "ksl/SE3.h"
#include "ksl/inertia.h"
#include "ksl/mat3x3.h"
#include "ksl/matrix.h"

/* dense 3x3 inertia tensor from the inertia_t fields */
static void inertia_to_mat3x3(const ksl_inertia_t* inertia, ksl_mat3x3_t* J) {
  *J = ksl_mat3x3(inertia->Ixx, inertia->Ixy, inertia->Izx, inertia->Ixy,
                  inertia->Iyy, inertia->Iyz, inertia->Izx, inertia->Iyz,
                  inertia->Izz);
}

/* J += m * (|d|^2 * I - d * d^T) */
static void add_parallel_axis(const double m, const ksl_vec3_t* d,
                              ksl_mat3x3_t* J) {
  double dd = ksl_dot_vv(d, d);
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      J->at[j][i] += m * ((i == j ? dd : 0.0) - d->at[i] * d->at[j]);
    }
  }
}

/* R * J * R^T */
static void rotate_mat3x3(const ksl_mat3x3_t* R, const ksl_mat3x3_t* J,
                          ksl_mat3x3_t* Jo) {
  ksl_mat3x3_t RJ, Rt;
  ksl_product_drdr(R, J, &RJ);
  ksl_mat3x3_transposed(R, &Rt);
  ksl_product_drdr(&RJ, &Rt, Jo);
}

static void check_inertia_eq(const ksl_inertia_t* inertia, const double m,
                             const ksl_vec3_t* mt, const ksl_mat3x3_t* J) {
  ck_assert_double_eq_tol(inertia->m, m, 1e-9);
  for(int i = 0; i < 3; i++) {
    ck_assert_double_eq_tol(inertia->mt.at[i], mt->at[i], 1e-9);
  }
  ksl_mat3x3_t J_test;
  inertia_to_mat3x3(inertia, &J_test);
  for(int i = 0; i < 9; i++) {
    ck_assert_double_eq_tol(J_test.as_array[i], J->as_array[i], 1e-9);
  }
}

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

START_TEST(test_inertia_rotated) {
  ksl_inertia_t inertia =
    ksl_inertia(2.0, ksl_vec3(0.0, 0.0, 0.0), 3.0, 4.0, 5.0, 0.1, 0.2, 0.3);
  ksl_mat3x3_t R;
  ksl_vec3_t angles = ksl_vec3(0.2, -0.6, 1.1);
  ksl_mat3x3_setFromEulerAngles(&R, KSL_AXIS_XYZ, &angles);

  ksl_mat3x3_t Jc, expected;
  inertia_to_mat3x3(&inertia, &Jc);
  rotate_mat3x3(&R, &Jc, &expected);
  ksl_vec3_t mt = ksl_vec3(0.0, 0.0, 0.0);

  ksl_inertia_t inertia_o;
  ksl_inertia_rotated(&inertia, &R, &inertia_o);
  check_inertia_eq(&inertia_o, 2.0, &mt, &expected);
}
END_TEST

START_TEST(test_inertia_translated) {
  /* centroidal inertia translated by t: parallel axis theorem */
  ksl_inertia_t inertia =
    ksl_inertia(2.0, ksl_vec3(0.0, 0.0, 0.0), 3.0, 4.0, 5.0, 0.1, 0.2, 0.3);
  ksl_vec3_t t = ksl_vec3(0.4, -0.7, 1.3);

  ksl_mat3x3_t expected;
  inertia_to_mat3x3(&inertia, &expected);
  add_parallel_axis(2.0, &t, &expected);
  ksl_vec3_t mt = ksl_vec3(2.0 * t.x, 2.0 * t.y, 2.0 * t.z);

  /* pre-fill the output with unrelated values; the result must not depend on
  them */
  ksl_inertia_t inertia_o =
    ksl_inertia(7.0, ksl_vec3(1.0, 1.0, 1.0), 9.0, 9.0, 9.0, 9.0, 9.0, 9.0);
  ksl_inertia_translated(&inertia, &t, &inertia_o);
  check_inertia_eq(&inertia_o, 2.0, &mt, &expected);
}
END_TEST

START_TEST(test_inertia_translate) {
  ksl_inertia_t inertia =
    ksl_inertia(2.0, ksl_vec3(0.0, 0.0, 0.0), 3.0, 4.0, 5.0, 0.1, 0.2, 0.3);
  ksl_vec3_t t = ksl_vec3(0.4, -0.7, 1.3);

  ksl_mat3x3_t expected;
  inertia_to_mat3x3(&inertia, &expected);
  add_parallel_axis(2.0, &t, &expected);
  ksl_vec3_t mt = ksl_vec3(2.0 * t.x, 2.0 * t.y, 2.0 * t.z);

  ksl_inertia_translate(&inertia, &t);
  check_inertia_eq(&inertia, 2.0, &mt, &expected);
}
END_TEST

START_TEST(test_inertia_transformed) {
  /* centroidal inertia transformed by D = {R, t}:
  J = R * Jc * R^T + m * (|t|^2 * I - t * t^T), mt = m * t */
  ksl_inertia_t inertia =
    ksl_inertia(2.0, ksl_vec3(0.0, 0.0, 0.0), 3.0, 4.0, 5.0, 0.1, 0.2, 0.3);
  ksl_SE3_t D;
  ksl_vec3_t angles = ksl_vec3(0.2, -0.6, 1.1);
  ksl_mat3x3_setFromEulerAngles(&D.R, KSL_AXIS_XYZ, &angles);
  D.t = ksl_vec3(0.4, -0.7, 1.3);

  ksl_mat3x3_t Jc, expected;
  inertia_to_mat3x3(&inertia, &Jc);
  rotate_mat3x3(&D.R, &Jc, &expected);
  add_parallel_axis(2.0, &D.t, &expected);
  ksl_vec3_t mt = ksl_vec3(2.0 * D.t.x, 2.0 * D.t.y, 2.0 * D.t.z);

  ksl_inertia_t inertia_o;
  ksl_inertia_transformed(&inertia, &D, &inertia_o);
  check_inertia_eq(&inertia_o, 2.0, &mt, &expected);
}
END_TEST

START_TEST(test_inertia_merge) {
  /* parent body i: centroidal inertia Ji (frame i axes), centroid c_i */
  const double m_i = 2.0;
  ksl_vec3_t c_i = ksl_vec3(0.1, 0.2, 0.3);
  ksl_inertia_t inertia_i = ksl_inertia(m_i, c_i, 3.0, 4.0, 5.0, 0.1, 0.2, 0.3);

  /* child body j: centroidal inertia Jj (frame j axes), centroid c_j */
  const double m_j = 3.0;
  ksl_vec3_t c_j = ksl_vec3(-0.2, 0.1, 0.4);
  ksl_inertia_t inertia_j =
    ksl_inertia(m_j, c_j, 1.0, 2.0, 1.5, -0.05, 0.1, 0.02);

  /* D_ij maps frame j coordinates into frame i */
  ksl_SE3_t D_ij;
  ksl_vec3_t angles = ksl_vec3(0.2, -0.6, 1.1);
  ksl_mat3x3_setFromEulerAngles(&D_ij.R, KSL_AXIS_XYZ, &angles);
  D_ij.t = ksl_vec3(0.5, -0.3, 0.8);

  /* expected combined centroid c, in frame i */
  ksl_vec3_t c_j_i;
  ksl_product_dv(&D_ij, &c_j, &c_j_i);
  const double m = m_i + m_j;
  ksl_vec3_t c = ksl_vec3((m_i * c_i.x + m_j * c_j_i.x) / m,
                          (m_i * c_i.y + m_j * c_j_i.y) / m,
                          (m_i * c_i.z + m_j * c_j_i.z) / m);
  ksl_vec3_t mt = ksl_vec3(m * c.x, m * c.y, m * c.z);

  /* expected combined inertia about c, in frame i axes */
  ksl_mat3x3_t expected, Jj, Jj_i;
  inertia_to_mat3x3(&inertia_i, &expected);
  ksl_vec3_t d;
  ksl_subtract_vv(&c_i, &c, &d);
  add_parallel_axis(m_i, &d, &expected);
  inertia_to_mat3x3(&inertia_j, &Jj);
  rotate_mat3x3(&D_ij.R, &Jj, &Jj_i);
  ksl_subtract_vv(&c_j_i, &c, &d);
  add_parallel_axis(m_j, &d, &Jj_i);
  for(int i = 0; i < 9; i++) {
    expected.as_array[i] += Jj_i.as_array[i];
  }

  ksl_inertia_merge(&inertia_i, &c_i, &inertia_j, &c_j, &D_ij);
  check_inertia_eq(&inertia_i, m, &mt, &expected);
}
END_TEST

Suite* inertia_suite(void) {
  Suite* s = suite_create("inertia");
  TCase* tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_inertia_create);
  tcase_add_test(tc_core, test_inertia_rotated);
  tcase_add_test(tc_core, test_inertia_translated);
  tcase_add_test(tc_core, test_inertia_translate);
  tcase_add_test(tc_core, test_inertia_transformed);
  tcase_add_test(tc_core, test_inertia_merge);
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
