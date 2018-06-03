#include <config.h>
#include <stdlib.h>

#include <assert.h>
#include <check.h>
#include <float.h>
#include <stdio.h>
#include <time.h>

#include "util.h"
#include "vector.h"

START_TEST(test_vec3_create) {
  ksl_vec3_t v = {{1.0, 2.0, 3.0}};
  ck_assert((v.x == 1.0) && (v.at[0] == 1.0));
  ck_assert((v.y == 2.0) && (v.at[1] == 2.0));
  ck_assert((v.z == 3.0) && (v.at[2] == 3.0));
}
END_TEST

START_TEST(test_vec3f_create) {
  ksl_vec3f_t v = {{1.0, 2.0, 3.0}};
  ck_assert((v.x == 1.0) && (v.at[0] == 1.0));
  ck_assert((v.y == 2.0) && (v.at[1] == 2.0));
  ck_assert((v.z == 3.0) && (v.at[2] == 3.0));
}
END_TEST

START_TEST(test_vec3i_create) {
  ksl_vec3f_t v = {{1, 2, 3}};
  ck_assert((v.x == 1) && (v.at[0] == 1));
  ck_assert((v.y == 2) && (v.at[1] == 2));
  ck_assert((v.z == 3) && (v.at[2] == 3));
}
END_TEST

START_TEST(test_vec4_create) {
  ksl_vec4_t v = {{1.0, 2.0, 3.0, 4.0}};
  ck_assert((v.x == 1.0) && (v.at[0] == 1.0) && (v.r.x == 1.0));
  ck_assert((v.y == 2.0) && (v.at[1] == 2.0) && (v.r.y == 2.0));
  ck_assert((v.z == 3.0) && (v.at[2] == 3.0) && (v.r.z == 3.0));
  ck_assert((v.w == 4.0) && (v.at[3] == 4.0));
}
END_TEST

START_TEST(test_vec4f_create) {
  ksl_vec4_t v = {{1.0, 2.0, 3.0, 4.0}};
  ck_assert((v.x == 1.0) && (v.at[0] == 1.0) && (v.r.x == 1.0));
  ck_assert((v.y == 2.0) && (v.at[1] == 2.0) && (v.r.y == 2.0));
  ck_assert((v.z == 3.0) && (v.at[2] == 3.0) && (v.r.z == 3.0));
  ck_assert((v.w == 4.0) && (v.at[3] == 4.0));
}
END_TEST

START_TEST(test_vec4i_create) {
  ksl_vec4i_t v = {{1, 2, 3, 4}};
  ck_assert((v.x == 1) && (v.at[0] == 1) && (v.r.x == 1));
  ck_assert((v.y == 2) && (v.at[1] == 2) && (v.r.y == 2));
  ck_assert((v.z == 3) && (v.at[2] == 3) && (v.r.z == 3));
  ck_assert((v.w == 4) && (v.at[3] == 4));
}
END_TEST

START_TEST(test_vec3_alloc) {
  ksl_vec3_t* v = ksl_vec3_alloc(3);
  for(int i = 0; i < 3; i++) {
    v[i].x = 1.0;
    v[i].y = 2.0;
    v[i].z = 3.0;
    ck_assert((v[i].x == 1.0) && (v[i].y == 2.0) && (v[i].z == 3.0));
  }
}
END_TEST

START_TEST(test_vec3f_alloc) {
  ksl_vec3f_t* v = ksl_vec3f_alloc(3);
  for(int i = 0; i < 3; i++) {
    v[i].x = 1.0;
    v[i].y = 2.0;
    v[i].z = 3.0;
    ck_assert((v[i].x == 1.0) && (v[i].y == 2.0) && (v[i].z == 3.0));
  }
}
END_TEST

START_TEST(test_vec3i_alloc) {
  ksl_vec3i_t* v = ksl_vec3i_alloc(3);
  for(int i = 0; i < 3; i++) {
    v[i].x = 1;
    v[i].y = 2;
    v[i].z = 3;
    ck_assert((v[i].x == 1) && (v[i].y == 2) && (v[i].z == 3));
  }
}
END_TEST

START_TEST(test_vec4_alloc) {
  ksl_vec4_t* v = ksl_vec4_alloc(3);
  for(int i = 0; i < 3; i++) {
    v[i].x = 1.0;
    v[i].y = 2.0;
    v[i].z = 3.0;
    v[i].w = 4.0;
    ck_assert((v[i].x == 1.0) && (v[i].y == 2.0) && (v[i].z == 3.0) &&
              (v[i].w == 4.0));
  }
}
END_TEST

START_TEST(test_vec4f_alloc) {
  ksl_vec4f_t* v = ksl_vec4f_alloc(3);
  for(int i = 0; i < 3; i++) {
    v[i].x = 1.0;
    v[i].y = 2.0;
    v[i].z = 3.0;
    v[i].w = 4.0;
    ck_assert((v[i].x == 1.0) && (v[i].y == 2.0) && (v[i].z == 3.0) &&
              (v[i].w == 4.0));
  }
}
END_TEST

START_TEST(test_vec4i_alloc) {
  ksl_vec4_t* v = ksl_vec4_alloc(3);
  for(int i = 0; i < 3; i++) {
    v[i].x = 1;
    v[i].y = 2;
    v[i].z = 3;
    v[i].w = 4;
    ck_assert((v[i].x == 1) && (v[i].y == 2) && (v[i].z == 3) && (v[i].w == 4));
  }
}
END_TEST

START_TEST(test_vec3_l2norm) {
  ksl_vec3_t v = {{2.0, 1.0, -2.0}};
  ck_assert_double_eq_tol(ksl_vec3_l2norm(&v), 3.0, 1.e-9);
}
END_TEST

START_TEST(test_vec3f_l2norm) {
  ksl_vec3f_t v = {{2.0, 1.0, -2.0}};
  ck_assert_float_eq_tol(ksl_vec3f_l2norm(&v), 3.0, 1.e-6);
}
END_TEST

START_TEST(test_vec4_l2norm) {
  ksl_vec4_t v = {{-2.0, 1.0, -4.0, 2.0}};
  ck_assert_double_eq_tol(ksl_vec4_l2norm(&v), 5.0, 1.e-9);
}
END_TEST

START_TEST(test_vec4f_l2norm) {
  ksl_vec4f_t v = {{-2.0, 1.0, -4.0, 2.0}};
  ck_assert_float_eq_tol(ksl_vec4f_l2norm(&v), 5.0, 1.e-6);
}
END_TEST

START_TEST(test_vec3_normalize) {
  ksl_vec3_t v1 = {{2.0, 1.0, -2.0}};
  double v2[3] = {2.0, 1.0, -2.0};
  ksl_vec3_normalize(&v1);
  double nv2 = sqrt(v2[0] * v2[0] + v2[1] * v2[1] + v2[2] * v2[2]);
  for(int i = 0; i < 3; i++) {
    v2[i] /= nv2;
  }
  ck_assert_double_eq_tol(v1.x, v2[0], 1.e-9);
  ck_assert_double_eq_tol(v1.y, v2[1], 1.e-9);
  ck_assert_double_eq_tol(v1.z, v2[2], 1.e-9);
}
END_TEST

START_TEST(test_vec3f_normalize) {
  ksl_vec3f_t v1 = {{2.0, 1.0, -2.0}};
  float v2[3] = {2.0, 1.0, -2.0};
  ksl_vec3f_normalize(&v1);
  float nv2 = sqrt(v2[0] * v2[0] + v2[1] * v2[1] + v2[2] * v2[2]);
  for(int i = 0; i < 3; i++) {
    v2[i] /= nv2;
  }
  ck_assert_float_eq_tol(v1.x, v2[0], 1.e-6);
  ck_assert_float_eq_tol(v1.y, v2[1], 1.e-6);
  ck_assert_float_eq_tol(v1.z, v2[2], 1.e-6);
}
END_TEST

START_TEST(test_vec4_normalize) {
  ksl_vec4_t v1 = {{2.0, 1.0, -2.0, -4.0}};
  double v2[4] = {2.0, 1.0, -2.0, -4.0};
  ksl_vec4_normalize(&v1);
  double nv2 =
    sqrt(v2[0] * v2[0] + v2[1] * v2[1] + v2[2] * v2[2] + v2[3] * v2[3]);
  for(int i = 0; i < 4; i++) {
    v2[i] /= nv2;
  }
  ck_assert_double_eq_tol(v1.x, v2[0], 1.e-9);
  ck_assert_double_eq_tol(v1.y, v2[1], 1.e-9);
  ck_assert_double_eq_tol(v1.z, v2[2], 1.e-9);
  ck_assert_double_eq_tol(v1.w, v2[3], 1.e-9);
}
END_TEST

START_TEST(test_vec4f_normalize) {
  ksl_vec4f_t v1 = {{2.0, 1.0, -2.0, -4.0}};
  float v2[4] = {2.0, 1.0, -2.0, -4.0};
  ksl_vec4f_normalize(&v1);
  float nv2 =
    sqrt(v2[0] * v2[0] + v2[1] * v2[1] + v2[2] * v2[2] + v2[3] * v2[3]);
  for(int i = 0; i < 4; i++) {
    v2[i] /= nv2;
  }
  ck_assert_float_eq_tol(v1.x, v2[0], 1.e-6);
  ck_assert_float_eq_tol(v1.y, v2[1], 1.e-6);
  ck_assert_float_eq_tol(v1.z, v2[2], 1.e-6);
  ck_assert_float_eq_tol(v1.w, v2[3], 1.e-6);
}
END_TEST

START_TEST(test_vec3_scale) {
  ksl_vec3_t v1 = {{1.0, 2.0, -3.0}};
  double v2[3] = {2.0, 4.0, -6.0};
  ksl_vec3_scale(&v1, 2.0);
  ck_assert_double_eq_tol(v1.x, v2[0], 1.e-9);
  ck_assert_double_eq_tol(v1.y, v2[1], 1.e-9);
  ck_assert_double_eq_tol(v1.z, v2[2], 1.e-9);
}
END_TEST

START_TEST(test_vec3f_scale) {
  ksl_vec3f_t v1 = {{1.0, 2.0, -3.0}};
  float v2[3] = {2.0, 4.0, -6.0};
  ksl_vec3f_scale(&v1, 2.0);
  ck_assert_float_eq_tol(v1.x, v2[0], 1.e-6);
  ck_assert_float_eq_tol(v1.y, v2[1], 1.e-6);
  ck_assert_float_eq_tol(v1.z, v2[2], 1.e-6);
}
END_TEST

START_TEST(test_vec4_scale) {
  ksl_vec4_t v1 = {{1.0, 2.0, -3.0, 4.0}};
  double v2[4] = {2.0, 4.0, -6.0, 8.0};
  ksl_vec4_scale(&v1, 2.0);
  ck_assert_double_eq_tol(v1.x, v2[0], 1.e-9);
  ck_assert_double_eq_tol(v1.y, v2[1], 1.e-9);
  ck_assert_double_eq_tol(v1.z, v2[2], 1.e-9);
  ck_assert_double_eq_tol(v1.w, v2[3], 1.e-9);
}
END_TEST

START_TEST(test_vec4f_scale) {
  ksl_vec4f_t v1 = {{1.0, 2.0, -3.0, 4.0}};
  float v2[4] = {2.0, 4.0, -6.0, 8.0};
  ksl_vec4f_scale(&v1, 2.0);
  ck_assert_float_eq_tol(v1.x, v2[0], 1.e-6);
  ck_assert_float_eq_tol(v1.y, v2[1], 1.e-6);
  ck_assert_float_eq_tol(v1.z, v2[2], 1.e-6);
  ck_assert_float_eq_tol(v1.w, v2[3], 1.e-6);
}
END_TEST

START_TEST(test_vec3_copy) {
  ksl_vec3_t v1 = {{1.0, 2.0, -3.0}};
  ksl_vec3_t v2;
  ksl_vec3_copy(&v1, &v2);
  ck_assert((v1.x == v2.x) && (v1.y == v2.y) && (v1.z == v2.z));
}
END_TEST

START_TEST(test_vec3f_copy) {
  ksl_vec3f_t v1 = {{1.0, 2.0, -3.0}};
  ksl_vec3f_t v2;
  ksl_vec3f_copy(&v1, &v2);
  ck_assert((v1.x == v2.x) && (v1.y == v2.y) && (v1.z == v2.z));
}
END_TEST

START_TEST(test_vec4_copy) {
  ksl_vec4_t v1 = {{1.0, 2.0, -3.0, 4.0}};
  ksl_vec4_t v2;
  ksl_vec4_copy(&v1, &v2);
  ck_assert((v1.x == v2.x) && (v1.y == v2.y) && (v1.z == v2.z) &&
            (v1.w == v2.w));
}
END_TEST

START_TEST(test_vec4f_copy) {
  ksl_vec4f_t v1 = {{1.0, 2.0, -3.0, 4.0}};
  ksl_vec4f_t v2;
  ksl_vec4f_copy(&v1, &v2);
  ck_assert((v1.x == v2.x) && (v1.y == v2.y) && (v1.z == v2.z) &&
            (v1.w == v2.w));
}
END_TEST

START_TEST(test_vec3_swap) {
  ksl_vec3_t v1 = {{1.0, 2.0, 3.0}};
  ksl_vec3_t v2 = {{5.0, 6.0, 7.0}};
  ksl_vec3_swap(&v1, &v2);
  ck_assert((v1.x == 5.0) && (v1.y == 6.0) && (v1.z == 7.0));
  ck_assert((v2.x == 1.0) && (v2.y == 2.0) && (v2.z == 3.0));
}
END_TEST

START_TEST(test_vec3f_swap) {
  ksl_vec3f_t v1 = {{1.0, 2.0, 3.0}};
  ksl_vec3f_t v2 = {{5.0, 6.0, 7.0}};
  ksl_vec3f_swap(&v1, &v2);
  ck_assert((v1.x == 5.0) && (v1.y == 6.0) && (v1.z == 7.0));
  ck_assert((v2.x == 1.0) && (v2.y == 2.0) && (v2.z == 3.0));
}
END_TEST

START_TEST(test_vec4_swap) {
  ksl_vec4_t v1 = {{1.0, 2.0, 3.0, 4.0}};
  ksl_vec4_t v2 = {{5.0, 6.0, 7.0, 8.0}};
  ksl_vec4_swap(&v1, &v2);
  ck_assert((v1.x == 5.0) && (v1.y == 6.0) && (v1.z == 7.0) && (v1.w == 8.0));
  ck_assert((v2.x == 1.0) && (v2.y == 2.0) && (v2.z == 3.0) && (v2.w == 4.0));
}
END_TEST

START_TEST(test_vec4f_swap) {
  ksl_vec4f_t v1 = {{1.0, 2.0, 3.0, 4.0}};
  ksl_vec4f_t v2 = {{5.0, 6.0, 7.0, 8.0}};
  ksl_vec4f_swap(&v1, &v2);
  ck_assert((v1.x == 5.0) && (v1.y == 6.0) && (v1.z == 7.0) && (v1.w == 8.0));
  ck_assert((v2.x == 1.0) && (v2.y == 2.0) && (v2.z == 3.0) && (v2.w == 4.0));
}
END_TEST

START_TEST(test_vec3_inverted) {
  ksl_vec3_t v1 = {{1.0, -2.0, 3.0}};
  ksl_vec3_t v2;
  ksl_vec3_inverted(&v1, &v2);
  ck_assert((v2.x == -1.0) && (v2.y == 2.0) && (v2.z == -3.0));
}
END_TEST

START_TEST(test_vec3_invert) {
  ksl_vec3_t v1 = {{1.0, -2.0, 3.0}};
  ksl_vec3_invert(&v1);
  ck_assert((v1.x == -1.0) && (v1.y == 2.0) && (v1.z == -3.0));
}
END_TEST

START_TEST(test_vec3f_inverted) {
  ksl_vec3f_t v1 = {{1.0, -2.0, 3.0}};
  ksl_vec3f_t v2;
  ksl_vec3f_inverted(&v1, &v2);
  ck_assert((v2.x == -1.0) && (v2.y == 2.0) && (v2.z == -3.0));
}
END_TEST

START_TEST(test_vec3f_invert) {
  ksl_vec3f_t v1 = {{1.0, -2.0, 3.0}};
  ksl_vec3f_invert(&v1);
  ck_assert((v1.x == -1.0) && (v1.y == 2.0) && (v1.z == -3.0));
}
END_TEST

START_TEST(test_vec4_inverted) {
  ksl_vec4_t v1 = {{1.0, -2.0, 3.0, -4.0}};
  ksl_vec4_t v2;
  ksl_vec4_inverted(&v1, &v2);
  ck_assert((v2.x == -1.0) && (v2.y == 2.0) && (v2.z == -3.0) && (v2.w == 4.0));
}
END_TEST

START_TEST(test_vec4_invert) {
  ksl_vec4_t v1 = {{1.0, -2.0, 3.0, -4.0}};
  ksl_vec4_invert(&v1);
  ck_assert((v1.x == -1.0) && (v1.y == 2.0) && (v1.z == -3.0) && (v1.w == 4.0));
}
END_TEST

START_TEST(test_vec4f_inverted) {
  ksl_vec4f_t v1 = {{1.0, -2.0, 3.0, -4.0}};
  ksl_vec4f_t v2;
  ksl_vec4f_inverted(&v1, &v2);
  ck_assert((v2.x == -1.0) && (v2.y == 2.0) && (v2.z == -3.0) && (v2.w == 4.0));
}
END_TEST

START_TEST(test_vec4f_invert) {
  ksl_vec4f_t v1 = {{1.0, -2.0, 3.0, -4.0}};
  ksl_vec4f_invert(&v1);
  ck_assert((v1.x == -1.0) && (v1.y == 2.0) && (v1.z == -3.0) && (v1.w == 4.0));
}
END_TEST

START_TEST(test_dot_vv) {
  ksl_vec3_t v1 = {{1.0, 2.0, 3.0}};
  ksl_vec3_t v2 = {{4.0, 5.0, 6.0}};
  ck_assert_double_eq_tol(ksl_dot_vv(&v1, &v2), 32.0, 1e-9);
}
END_TEST

START_TEST(test_dot_vvf) {
  ksl_vec3f_t v1 = {{1.0, 2.0, 3.0}};
  ksl_vec3f_t v2 = {{4.0, 5.0, 6.0}};
  ck_assert_float_eq_tol(ksl_dot_vvf(&v1, &v2), 32.0, 1e-6);
}
END_TEST

START_TEST(test_product_av) {
  ksl_vec3_t v1 = {{1.0, 2.0, 3.0}};
  ksl_vec3_t v2;
  ksl_product_av(4.0, &v1, &v2);
  ck_assert_double_eq_tol(v2.x, 4.0, 1e-9);
  ck_assert_double_eq_tol(v2.y, 8.0, 1e-9);
  ck_assert_double_eq_tol(v2.z, 12.0, 1e-9);
}
END_TEST

START_TEST(test_product_avinv) {
  ksl_vec3_t v1 = {{1.0, 2.0, 3.0}};
  ksl_vec3_t v2;
  ksl_product_avinv(4.0, &v1, &v2);
  ck_assert_double_eq_tol(v2.x, -4.0, 1e-9);
  ck_assert_double_eq_tol(v2.y, -8.0, 1e-9);
  ck_assert_double_eq_tol(v2.z, -12.0, 1e-9);
}
END_TEST

START_TEST(test_product_ainvv) {
  ksl_vec3_t v1 = {{2.0, 4.0, 8.0}};
  ksl_vec3_t v2;
  ksl_product_ainvv(4.0, &v1, &v2);
  ck_assert_double_eq_tol(v2.x, 0.5, 1e-9);
  ck_assert_double_eq_tol(v2.y, 1.0, 1e-9);
  ck_assert_double_eq_tol(v2.z, 2.0, 1e-9);
}
END_TEST

START_TEST(test_product_avinvf) {
  ksl_vec3f_t v1 = {{1.0, 2.0, 3.0}};
  ksl_vec3f_t v2;
  ksl_product_avinvf(4.0, &v1, &v2);
  ck_assert_float_eq_tol(v2.x, -4.0, 1e-6);
  ck_assert_float_eq_tol(v2.y, -8.0, 1e-6);
  ck_assert_float_eq_tol(v2.z, -12.0, 1e-6);
}
END_TEST

START_TEST(test_product_avf) {
  ksl_vec3f_t v1 = {{1.0, 2.0, 3.0}};
  ksl_vec3f_t v2;
  ksl_product_avf(4.0, &v1, &v2);
  ck_assert_float_eq_tol(v2.x, 4.0, 1e-6);
  ck_assert_float_eq_tol(v2.y, 8.0, 1e-6);
  ck_assert_float_eq_tol(v2.z, 12.0, 1e-6);
}
END_TEST

START_TEST(test_add_vv) {
  ksl_vec3_t v1 = {{1.0, 2.0, 3.0}};
  ksl_vec3_t v2 = {{10.0, 11.0, 12.0}};
  ksl_vec3_t v3;
  ksl_add_vv(&v1, &v2, &v3);
  ck_assert_double_eq_tol(v3.x, 11.0, 1e-9);
  ck_assert_double_eq_tol(v3.y, 13.0, 1e-9);
  ck_assert_double_eq_tol(v3.z, 15.0, 1e-9);
}
END_TEST

START_TEST(test_add_vvf) {
  ksl_vec3f_t v1 = {{1.0, 2.0, 3.0}};
  ksl_vec3f_t v2 = {{10.0, 11.0, 12.0}};
  ksl_vec3f_t v3;
  ksl_add_vvf(&v1, &v2, &v3);
  ck_assert_float_eq_tol(v3.x, 11.0, 1e-6);
  ck_assert_float_eq_tol(v3.y, 13.0, 1e-6);
  ck_assert_float_eq_tol(v3.z, 15.0, 1e-6);
}
END_TEST

START_TEST(test_subtract_vv) {
  ksl_vec3_t v1 = {{10.0, 11.0, 12.0}};
  ksl_vec3_t v2 = {{1.0, 2.0, 3.0}};
  ksl_vec3_t v3;
  ksl_subtract_vv(&v1, &v2, &v3);
  ck_assert_double_eq_tol(v3.x, 9.0, 1e-9);
  ck_assert_double_eq_tol(v3.y, 9.0, 1e-9);
  ck_assert_double_eq_tol(v3.z, 9.0, 1e-9);
}
END_TEST

START_TEST(test_subtract_vvf) {
  ksl_vec3f_t v1 = {{10.0, 11.0, 12.0}};
  ksl_vec3f_t v2 = {{1.0, 2.0, 3.0}};
  ksl_vec3f_t v3;
  ksl_subtract_vvf(&v1, &v2, &v3);
  ck_assert_float_eq_tol(v3.x, 9.0, 1e-6);
  ck_assert_float_eq_tol(v3.y, 9.0, 1e-6);
  ck_assert_float_eq_tol(v3.z, 9.0, 1e-6);
}
END_TEST

START_TEST(test_xpy_vv) {
  ksl_vec3_t v1 = {{1.0, 2.0, 3.0}};
  ksl_vec3_t v2 = {{10.0, 11.0, 12.0}};
  ksl_xpy_vv(&v1, &v2);
  ck_assert_double_eq_tol(v2.x, 11.0, 1e-9);
  ck_assert_double_eq_tol(v2.y, 13.0, 1e-9);
  ck_assert_double_eq_tol(v2.z, 15.0, 1e-9);
}
END_TEST

START_TEST(test_xpy_vvf) {
  ksl_vec3f_t v1 = {{1.0, 2.0, 3.0}};
  ksl_vec3f_t v2 = {{10.0, 11.0, 12.0}};
  ksl_xpy_vvf(&v1, &v2);
  ck_assert_float_eq_tol(v2.x, 11.0, 1e-6);
  ck_assert_float_eq_tol(v2.y, 13.0, 1e-6);
  ck_assert_float_eq_tol(v2.z, 15.0, 1e-6);
}
END_TEST

START_TEST(test_nxpy_vv) {
  ksl_vec3_t v1 = {{1.0, 2.0, 3.0}};
  ksl_vec3_t v2 = {{10.0, 11.0, 12.0}};
  ksl_nxpy_vv(&v1, &v2);
  ck_assert_double_eq_tol(v2.x, 9.0, 1e-9);
  ck_assert_double_eq_tol(v2.y, 9.0, 1e-9);
  ck_assert_double_eq_tol(v2.z, 9.0, 1e-9);
}
END_TEST

START_TEST(test_nxpy_vvf) {
  ksl_vec3f_t v1 = {{1.0, 2.0, 3.0}};
  ksl_vec3f_t v2 = {{10.0, 11.0, 12.0}};
  ksl_nxpy_vvf(&v1, &v2);
  ck_assert_float_eq_tol(v2.x, 9.0, 1e-6);
  ck_assert_float_eq_tol(v2.y, 9.0, 1e-6);
  ck_assert_float_eq_tol(v2.z, 9.0, 1e-6);
}
END_TEST

START_TEST(test_axpy_vv) {
  double a = 2.0;
  ksl_vec3_t v1 = {{1.0, 2.0, 3.0}};
  ksl_vec3_t v2 = {{10.0, 11.0, 12.0}};
  ksl_axpy_vv(a, &v1, &v2);
  ck_assert_double_eq_tol(v2.x, 12.0, 1e-9);
  ck_assert_double_eq_tol(v2.y, 15.0, 1e-9);
  ck_assert_double_eq_tol(v2.z, 18.0, 1e-9);
}
END_TEST

START_TEST(test_axpy_vvf) {
  float a = 2.0;
  ksl_vec3f_t v1 = {{1.0, 2.0, 3.0}};
  ksl_vec3f_t v2 = {{10.0, 11.0, 12.0}};
  ksl_axpy_vvf(a, &v1, &v2);
  ck_assert_float_eq_tol(v2.x, 12.0, 1e-6);
  ck_assert_float_eq_tol(v2.y, 15.0, 1e-6);
  ck_assert_float_eq_tol(v2.z, 18.0, 1e-6);
}
END_TEST

START_TEST(test_cross_vv) {
  ksl_vec3_t v1 = {{2.0, 3.0, 4.0}};
  ksl_vec3_t v2 = {{5.0, 6.0, 7.0}};
  ksl_vec3_t v3;
  ksl_cross_vv(&v1, &v2, &v3);
  ck_assert_double_eq_tol(v3.x, -3.0, 1e-9);
  ck_assert_double_eq_tol(v3.y, 6.0, 1e-9);
  ck_assert_double_eq_tol(v3.z, -3.0, 1e-9);
}
END_TEST

START_TEST(test_cross_vvinv) {
  ksl_vec3_t v1 = {{2.0, 3.0, 4.0}};
  ksl_vec3_t v2 = {{5.0, 6.0, 7.0}};
  ksl_vec3_t v3;
  ksl_cross_vvinv(&v1, &v2, &v3);
  ck_assert_double_eq_tol(v3.x, 3.0, 1e-9);
  ck_assert_double_eq_tol(v3.y, -6.0, 1e-9);
  ck_assert_double_eq_tol(v3.z, 3.0, 1e-9);
}
END_TEST

START_TEST(test_cross_vvf) {
  ksl_vec3f_t v1 = {{2.0, 3.0, 4.0}};
  ksl_vec3f_t v2 = {{5.0, 6.0, 7.0}};
  ksl_vec3f_t v3;
  ksl_cross_vvf(&v1, &v2, &v3);
  ck_assert_float_eq_tol(v3.x, -3.0, 1e-6);
  ck_assert_float_eq_tol(v3.y, 6.0, 1e-6);
  ck_assert_float_eq_tol(v3.z, -3.0, 1e-6);
}
END_TEST

START_TEST(test_cross_vvinvf) {
  ksl_vec3f_t v1 = {{2.0, 3.0, 4.0}};
  ksl_vec3f_t v2 = {{5.0, 6.0, 7.0}};
  ksl_vec3f_t v3;
  ksl_cross_vvinvf(&v1, &v2, &v3);
  ck_assert_float_eq_tol(v3.x, 3.0, 1e-6);
  ck_assert_float_eq_tol(v3.y, -6.0, 1e-6);
  ck_assert_float_eq_tol(v3.z, 3.0, 1e-6);
}
END_TEST

START_TEST(test_add_vvx) {
  double x = 2.0;
  ksl_vec3_t v1 = {{1.0, 4.0, 5.0}};
  ksl_vec3_t v2;
  ksl_add_vvx(&v1, x, &v2);
  ck_assert_double_eq_tol(v2.x, 3.0, 1e-9);
  ck_assert_double_eq_tol(v2.y, 4.0, 1e-9);
  ck_assert_double_eq_tol(v2.z, 5.0, 1e-9);
}
END_TEST

START_TEST(test_add_vvxf) {
  float x = 2.0;
  ksl_vec3f_t v1 = {{1.0, 4.0, 5.0}};
  ksl_vec3f_t v2;
  ksl_add_vvxf(&v1, x, &v2);
  ck_assert_float_eq_tol(v2.x, 3.0, 1e-6);
  ck_assert_float_eq_tol(v2.y, 4.0, 1e-6);
  ck_assert_float_eq_tol(v2.z, 5.0, 1e-6);
}
END_TEST

START_TEST(test_add_vvxinv) {
  double x = 2.0;
  ksl_vec3_t v1 = {{1.0, 4.0, 5.0}};
  ksl_vec3_t v2;
  ksl_add_vvxinv(&v1, x, &v2);
  ck_assert_double_eq_tol(v2.x, -1.0, 1e-9);
  ck_assert_double_eq_tol(v2.y, 4.0, 1e-9);
  ck_assert_double_eq_tol(v2.z, 5.0, 1e-9);
}
END_TEST

START_TEST(test_add_vvxinvf) {
  float x = 2.0;
  ksl_vec3f_t v1 = {{1.0, 4.0, 5.0}};
  ksl_vec3f_t v2;
  ksl_add_vvxinvf(&v1, x, &v2);
  ck_assert_float_eq_tol(v2.x, -1.0, 1e-6);
  ck_assert_float_eq_tol(v2.y, 4.0, 1e-6);
  ck_assert_float_eq_tol(v2.z, 5.0, 1e-6);
}
END_TEST

START_TEST(test_add_vvy) {
  double y = 2.0;
  ksl_vec3_t v1 = {{1.0, 4.0, 5.0}};
  ksl_vec3_t v2;
  ksl_add_vvy(&v1, y, &v2);
  ck_assert_double_eq_tol(v2.x, 1.0, 1e-9);
  ck_assert_double_eq_tol(v2.y, 6.0, 1e-9);
  ck_assert_double_eq_tol(v2.z, 5.0, 1e-9);
}
END_TEST

START_TEST(test_add_vvyf) {
  float y = 2.0;
  ksl_vec3f_t v1 = {{1.0, 4.0, 5.0}};
  ksl_vec3f_t v2;
  ksl_add_vvyf(&v1, y, &v2);
  ck_assert_float_eq_tol(v2.x, 1.0, 1e-6);
  ck_assert_float_eq_tol(v2.y, 6.0, 1e-6);
  ck_assert_float_eq_tol(v2.z, 5.0, 1e-6);
}
END_TEST

START_TEST(test_add_vvyinv) {
  double y = 2.0;
  ksl_vec3_t v1 = {{1.0, 4.0, 5.0}};
  ksl_vec3_t v2;
  ksl_add_vvyinv(&v1, y, &v2);
  ck_assert_double_eq_tol(v2.x, 1.0, 1e-9);
  ck_assert_double_eq_tol(v2.y, 2.0, 1e-9);
  ck_assert_double_eq_tol(v2.z, 5.0, 1e-9);
}
END_TEST

START_TEST(test_add_vvyinvf) {
  float y = 2.0;
  ksl_vec3f_t v1 = {{1.0, 4.0, 5.0}};
  ksl_vec3f_t v2;
  ksl_add_vvyinvf(&v1, y, &v2);
  ck_assert_float_eq_tol(v2.x, 1.0, 1e-6);
  ck_assert_float_eq_tol(v2.y, 2.0, 1e-6);
  ck_assert_float_eq_tol(v2.z, 5.0, 1e-6);
}
END_TEST

START_TEST(test_add_vvz) {
  double z = 2.0;
  ksl_vec3_t v1 = {{1.0, 4.0, 5.0}};
  ksl_vec3_t v2;
  ksl_add_vvz(&v1, z, &v2);
  ck_assert_double_eq_tol(v2.x, 1.0, 1e-9);
  ck_assert_double_eq_tol(v2.y, 4.0, 1e-9);
  ck_assert_double_eq_tol(v2.z, 7.0, 1e-9);
}
END_TEST

START_TEST(test_add_vvzf) {
  float z = 2.0;
  ksl_vec3f_t v1 = {{1.0, 4.0, 5.0}};
  ksl_vec3f_t v2;
  ksl_add_vvzf(&v1, z, &v2);
  ck_assert_float_eq_tol(v2.x, 1.0, 1e-6);
  ck_assert_float_eq_tol(v2.y, 4.0, 1e-6);
  ck_assert_float_eq_tol(v2.z, 7.0, 1e-6);
}
END_TEST

START_TEST(test_add_vvzinv) {
  double z = 2.0;
  ksl_vec3_t v1 = {{1.0, 4.0, 5.0}};
  ksl_vec3_t v2;
  ksl_add_vvzinv(&v1, z, &v2);
  ck_assert_double_eq_tol(v2.x, 1.0, 1e-9);
  ck_assert_double_eq_tol(v2.y, 4.0, 1e-9);
  ck_assert_double_eq_tol(v2.z, 3.0, 1e-9);
}
END_TEST

START_TEST(test_add_vvzinvf) {
  float z = 2.0;
  ksl_vec3f_t v1 = {{1.0, 4.0, 5.0}};
  ksl_vec3f_t v2;
  ksl_add_vvzinvf(&v1, z, &v2);
  ck_assert_float_eq_tol(v2.x, 1.0, 1e-6);
  ck_assert_float_eq_tol(v2.y, 4.0, 1e-6);
  ck_assert_float_eq_tol(v2.z, 3.0, 1e-6);
}
END_TEST

Suite* vector_suite(void) {
  Suite* s = suite_create("vector");

  /* Core test case */
  TCase* tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_vec3_create);
  tcase_add_test(tc_core, test_vec3f_create);
  tcase_add_test(tc_core, test_vec3i_create);
  tcase_add_test(tc_core, test_vec4_create);
  tcase_add_test(tc_core, test_vec4f_create);
  tcase_add_test(tc_core, test_vec4i_create);
  tcase_add_test(tc_core, test_vec3_alloc);
  tcase_add_test(tc_core, test_vec3f_alloc);
  tcase_add_test(tc_core, test_vec3i_alloc);
  tcase_add_test(tc_core, test_vec4_alloc);
  tcase_add_test(tc_core, test_vec4f_alloc);
  tcase_add_test(tc_core, test_vec4i_alloc);
  tcase_add_test(tc_core, test_vec3_l2norm);
  tcase_add_test(tc_core, test_vec3f_l2norm);
  tcase_add_test(tc_core, test_vec4_l2norm);
  tcase_add_test(tc_core, test_vec4f_l2norm);
  tcase_add_test(tc_core, test_vec3_normalize);
  tcase_add_test(tc_core, test_vec3f_normalize);
  tcase_add_test(tc_core, test_vec4_normalize);
  tcase_add_test(tc_core, test_vec4f_normalize);
  tcase_add_test(tc_core, test_vec3_scale);
  tcase_add_test(tc_core, test_vec3f_scale);
  tcase_add_test(tc_core, test_vec4_scale);
  tcase_add_test(tc_core, test_vec4f_scale);
  tcase_add_test(tc_core, test_vec3_copy);
  tcase_add_test(tc_core, test_vec3f_copy);
  tcase_add_test(tc_core, test_vec4_copy);
  tcase_add_test(tc_core, test_vec4f_copy);
  tcase_add_test(tc_core, test_vec3_swap);
  tcase_add_test(tc_core, test_vec3f_swap);
  tcase_add_test(tc_core, test_vec4_swap);
  tcase_add_test(tc_core, test_vec4f_swap);
  tcase_add_test(tc_core, test_vec3_inverted);
  tcase_add_test(tc_core, test_vec3_invert);
  tcase_add_test(tc_core, test_vec3f_inverted);
  tcase_add_test(tc_core, test_vec3f_invert);
  tcase_add_test(tc_core, test_vec4_inverted);
  tcase_add_test(tc_core, test_vec4_invert);
  tcase_add_test(tc_core, test_vec4f_inverted);
  tcase_add_test(tc_core, test_vec4f_invert);
  tcase_add_test(tc_core, test_dot_vv);
  tcase_add_test(tc_core, test_dot_vvf);
  tcase_add_test(tc_core, test_product_av);
  tcase_add_test(tc_core, test_product_avinv);
  tcase_add_test(tc_core, test_product_ainvv);
  tcase_add_test(tc_core, test_product_avinvf);
  tcase_add_test(tc_core, test_product_avf);
  tcase_add_test(tc_core, test_add_vv);
  tcase_add_test(tc_core, test_add_vvf);
  tcase_add_test(tc_core, test_subtract_vv);
  tcase_add_test(tc_core, test_subtract_vvf);
  tcase_add_test(tc_core, test_xpy_vv);
  tcase_add_test(tc_core, test_xpy_vvf);
  tcase_add_test(tc_core, test_nxpy_vv);
  tcase_add_test(tc_core, test_nxpy_vvf);
  tcase_add_test(tc_core, test_axpy_vv);
  tcase_add_test(tc_core, test_axpy_vvf);
  tcase_add_test(tc_core, test_cross_vv);
  tcase_add_test(tc_core, test_cross_vvinv);
  tcase_add_test(tc_core, test_cross_vvf);
  tcase_add_test(tc_core, test_cross_vvinvf);
  tcase_add_test(tc_core, test_add_vvx);
  tcase_add_test(tc_core, test_add_vvxf);
  tcase_add_test(tc_core, test_add_vvxinv);
  tcase_add_test(tc_core, test_add_vvxinvf);
  tcase_add_test(tc_core, test_add_vvy);
  tcase_add_test(tc_core, test_add_vvyf);
  tcase_add_test(tc_core, test_add_vvyinv);
  tcase_add_test(tc_core, test_add_vvyinvf);
  tcase_add_test(tc_core, test_add_vvz);
  tcase_add_test(tc_core, test_add_vvzf);
  tcase_add_test(tc_core, test_add_vvzinv);
  tcase_add_test(tc_core, test_add_vvzinvf);

  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
  int number_failed;
  Suite* s = vector_suite();
  SRunner* sr = srunner_create(s);
  srunner_set_log(sr, "check_vector.log");
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
