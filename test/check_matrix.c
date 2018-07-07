#include <config.h>

#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"
#include "print.h"

START_TEST(test_matrix_SE3) {
  ksl_SE3_t* D = ksl_SE3_alloc(3);
  ck_assert_ptr_nonnull(D);

  D[1] = ksl_SE3(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0);

  double k = 1;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 4; j++) {
      ck_assert_double_eq(D[1].at[j][i], k++);
    }
  }
  free(D);
}
END_TEST

START_TEST(test_matrix_SE3f) {
  ksl_SE3f_t* D = ksl_SE3f_alloc(3);
  ck_assert_ptr_nonnull(D);

  D[1] =
    ksl_SE3f(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0);

  float k = 1;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 4; j++) {
      ck_assert_float_eq(D[1].at[j][i], k++);
    }
  }
  free(D);
}
END_TEST

START_TEST(test_matrix_mat3x3) {
  ksl_mat3x3_t* D = ksl_mat3x3_alloc(3);
  ck_assert_ptr_nonnull(D);

  D[1] = ksl_mat3x3(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);

  double k = 1;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      ck_assert_double_eq(D[1].at[j][i], k++);
    }
  }
  free(D);
}
END_TEST

START_TEST(test_matrix_mat3x3f) {
  ksl_mat3x3f_t* D = ksl_mat3x3f_alloc(3);
  ck_assert_ptr_nonnull(D);

  D[1] = ksl_mat3x3f(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);

  float k = 1;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      ck_assert_float_eq(D[1].at[j][i], k++);
    }
  }
  free(D);
}
END_TEST

START_TEST(test_matrix_mat4x4) {
  ksl_mat4x4_t* D = ksl_mat4x4_alloc(3);
  ck_assert_ptr_nonnull(D);

  D[1] = ksl_mat4x4(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0,
                    12.0, 13.0, 14.0, 15.0, 16.0);

  double k = 1;
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      ck_assert_double_eq(D[1].at[j][i], k++);
    }
  }
  free(D);
}
END_TEST

START_TEST(test_matrix_mat4x4f) {
  ksl_mat4x4f_t* D = ksl_mat4x4f_alloc(3);
  ck_assert_ptr_nonnull(D);

  D[1] = ksl_mat4x4f(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0,
                     12.0, 13.0, 14.0, 15.0, 16.0);

  float k = 1;
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      ck_assert_float_eq(D[1].at[j][i], k++);
    }
  }
  free(D);
}
END_TEST

START_TEST(test_matrix_SE3_alloc) {
  ksl_SE3_t* D = ksl_SE3_alloc(1);
  ck_assert_ptr_nonnull(D);
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 4; j++) {
      if(i == j) {
        ck_assert_double_eq(D[0].at[j][i], 1.0);
      } else {
        ck_assert_double_eq(D[0].at[j][i], 0.0);
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
          ck_assert_double_eq(Df[k].at[j][i], 1.0);
        } else {
          ck_assert_double_eq(Df[k].at[j][i], 0.0);
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
          ck_assert_double_eq(R[k].at[j][i], 1.0);
        } else {
          ck_assert_double_eq(R[k].at[j][i], 0.0);
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
          ck_assert_double_eq(Rf[k].at[j][i], 1.0);
        } else {
          ck_assert_double_eq(Rf[k].at[j][i], 0.0);
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
          ck_assert_double_eq(M[k].at[j][i], 1.0);
        } else {
          ck_assert_double_eq(M[k].at[j][i], 0.0);
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
          ck_assert_double_eq(Mf[k].at[j][i], 1.0);
        } else {
          ck_assert_double_eq(Mf[k].at[j][i], 0.0);
        }
      }
    }
  }
  free(Mf);
}
END_TEST

START_TEST(test_matrix_SE3toMat4x4) {
  ksl_SE3_t d = {
    {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0}};
  ksl_mat4x4_t m;
  ksl_SE3_toMat4x4(&d, &m);
  for(int j = 0; j < 4; j++) {
    for(int i = 0; i < 3; i++) {
      ck_assert_double_eq(m.at[j][i], d.at[j][i]);
    }
    if(j != 3) {
      ck_assert_double_eq(m.at[j][3], 0.0);
    } else {
      ck_assert_double_eq(m.at[j][3], 1.0);
    }
  }
}
END_TEST

START_TEST(test_matrix_SE3ftoMat4x4f) {
  ksl_SE3f_t d = {
    {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0}};
  ksl_mat4x4f_t m;
  ksl_SE3f_toMat4x4f(&d, &m);
  for(int j = 0; j < 4; j++) {
    for(int i = 0; i < 3; i++) {
      ck_assert_float_eq(m.at[j][i], d.at[j][i]);
    }
    if(j != 3) {
      ck_assert_float_eq(m.at[j][3], 0.0);
    } else {
      ck_assert_float_eq(m.at[j][3], 1.0);
    }
  }
}
END_TEST

START_TEST(test_matrix_SE3toMat4x4f) {
  ksl_SE3_t d = {
    {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0}};
  ksl_mat4x4f_t m;
  ksl_SE3_toMat4x4f(&d, &m);
  for(int j = 0; j < 4; j++) {
    for(int i = 0; i < 3; i++) {
      ck_assert_float_eq(m.at[j][i], (float)d.at[j][i]);
    }
    if(j != 3) {
      ck_assert_float_eq(m.at[j][3], 0.0);
    } else {
      ck_assert_float_eq(m.at[j][3], 1.0);
    }
  }
}
END_TEST

START_TEST(test_matrix_dc) {
  double dc[2];
  ksl_dc(0.2, dc);
  ck_assert_double_eq(dc[0], 0.19866933079506122);
  ck_assert_double_eq(dc[1], 0.9800665778412416);
  ksl_dc(5.2, dc);
  ck_assert_double_eq(dc[0], -0.8834546557201531);
  ck_assert_double_eq(dc[1], 0.4685166713003771);
}
END_TEST

START_TEST(test_matrix_SE3_setIdentity) {
  ksl_SE3_t d = {
    {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0}};
  ksl_SE3_setIdentity(&d);
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 4; j++) {
      if(i == j) {
        ck_assert_double_eq(d.at[j][i], 1.0);
      } else {
        ck_assert_double_eq(d.at[j][i], 0.0);
      }
    }
  }
}
END_TEST

START_TEST(test_matrix_SE3f_setIdentity) {
  ksl_SE3f_t d = {
    {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0}};
  ksl_SE3f_setIdentity(&d);
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 4; j++) {
      if(i == j) {
        ck_assert_float_eq(d.at[j][i], 1.0);
      } else {
        ck_assert_float_eq(d.at[j][i], 0.0);
      }
    }
  }
}
END_TEST

START_TEST(test_matrix_mat3x3_setIdentity) {
  ksl_mat3x3_t r = {{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0}};
  ksl_mat3x3_setIdentity(&r);
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      if(i == j) {
        ck_assert_double_eq(r.at[j][i], 1.0);
      } else {
        ck_assert_double_eq(r.at[j][i], 0.0);
      }
    }
  }
}
END_TEST

START_TEST(test_matrix_mat3x3f_setIdentity) {
  ksl_mat3x3f_t rf = {{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0}};
  ksl_mat3x3f_setIdentity(&rf);
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      if(i == j) {
        ck_assert_float_eq(rf.at[j][i], 1.0);
      } else {
        ck_assert_float_eq(rf.at[j][i], 0.0);
      }
    }
  }
}
END_TEST

START_TEST(test_matrix_mat4x4_setIdentity) {
  ksl_mat4x4_t m = {{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0,
                     12.0, 13.0, 14.0, 15.0, 16.0}};
  ksl_mat4x4_setIdentity(&m);
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      if(i == j) {
        ck_assert_double_eq(m.at[j][i], 1.0);
      } else {
        ck_assert_double_eq(m.at[j][i], 0.0);
      }
    }
  }
}
END_TEST

START_TEST(test_matrix_mat4x4f_setIdentity) {
  ksl_mat4x4f_t m = {{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0,
                      12.0, 13.0, 14.0, 15.0, 16.0}};
  ksl_mat4x4f_setIdentity(&m);
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      if(i == j) {
        ck_assert_float_eq(m.at[j][i], 1.0);
      } else {
        ck_assert_float_eq(m.at[j][i], 0.0);
      }
    }
  }
}
END_TEST

START_TEST(test_matrix_mat3x3_setAndGet) {
  ksl_mat3x3_t m;
  double k = 0.0;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      ksl_mat3x3_set(&m, i, j, k);
      double result = ksl_mat3x3_get(&m, i, j);
      ck_assert_double_eq(result, k);
    }
  }
}
END_TEST

START_TEST(test_matrix_mat3x3f_setAndGet) {
  ksl_mat3x3f_t m;
  float k = 0.0;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      ksl_mat3x3f_set(&m, i, j, k);
      float result = ksl_mat3x3f_get(&m, i, j);
      ck_assert_float_eq(result, k);
    }
  }
}
END_TEST

START_TEST(test_matrix_mat4x4_setAndGet) {
  ksl_mat4x4_t m;
  double k = 0.0;
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      ksl_mat4x4_set(&m, i, j, k);
      double result = ksl_mat4x4_get(&m, i, j);
      ck_assert_double_eq(result, k);
    }
  }
}
END_TEST

START_TEST(test_matrix_mat4x4f_setAndGet) {
  ksl_mat4x4f_t m;
  float k = 0.0;
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      ksl_mat4x4f_set(&m, i, j, k);
      float result = ksl_mat4x4f_get(&m, i, j);
      ck_assert_float_eq(result, k);
    }
  }
}
END_TEST

START_TEST(test_matrix_SE3_setAndGet) {
  ksl_SE3_t m;
  double k = 0.0;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 4; j++) {
      ksl_SE3_set(&m, i, j, k);
      double result = ksl_SE3_get(&m, i, j);
      ck_assert_double_eq(result, k);
    }
  }
}
END_TEST

START_TEST(test_matrix_SE3f_setAndGet) {
  ksl_SE3f_t m;
  float k = 0.0;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 4; j++) {
      ksl_SE3f_set(&m, i, j, k);
      float result = ksl_SE3f_get(&m, i, j);
      ck_assert_float_eq(result, k);
    }
  }
}
END_TEST

START_TEST(test_matrix_mat3x3_setFromVectors) {
  ksl_mat3x3_t m;
  ksl_vec3_t v[3] = {{{1.0, 2.0, 3.0}}, {{4.0, 5.0, 6.0}}, {{7.0, 8.0, 9.0}}};
  ksl_mat3x3_setFromVectors(&m, &v[0], &v[1], &v[2]);

  for(int j = 0; j < 3; j++) {
    for(int i = 0; i < 3; i++) {
      ck_assert_double_eq(m.at[j][i], v[j].at[i]);
    }
  }
}
END_TEST

START_TEST(test_matrix_mat3x3f_setFromVectors) {
  ksl_mat3x3f_t m;
  ksl_vec3f_t v[3] = {{{1.0, 2.0, 3.0}}, {{4.0, 5.0, 6.0}}, {{7.0, 8.0, 9.0}}};
  ksl_mat3x3f_setFromVectors(&m, &v[0], &v[1], &v[2]);

  for(int j = 0; j < 3; j++) {
    for(int i = 0; i < 3; i++) {
      ck_assert_float_eq(m.at[j][i], v[j].at[i]);
    }
  }
}
END_TEST

START_TEST(test_matrix_SE3_getTranslation) {
  ksl_SE3_t d = {
    {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0}};
  ksl_vec3_t v;
  ksl_SE3_getTranslation(&d, &v);

  for(int i = 0; i < 3; i++) {
    ck_assert_double_eq(d.t.at[i], v.at[i]);
  }
}
END_TEST

START_TEST(test_matrix_SE3f_getTranslation) {
  ksl_SE3f_t d = {
    {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0}};
  ksl_vec3f_t v;
  ksl_SE3f_getTranslation(&d, &v);

  for(int i = 0; i < 3; i++) {
    ck_assert_float_eq(d.t.at[i], v.at[i]);
  }
}
END_TEST

START_TEST(test_matrix_mat3x3_copy) {
  ksl_mat3x3_t r1 = {{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0}};
  ksl_mat3x3_t r2;
  ksl_mat3x3_copy(&r1, &r2);

  for(int i = 0; i < 9; i++) {
    ck_assert_double_eq(r1.as_array[i], r2.as_array[i]);
  }
}
END_TEST

START_TEST(test_matrix_mat3x3f_copy) {
  ksl_mat3x3f_t r1 = {{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0}};
  ksl_mat3x3f_t r2;
  ksl_mat3x3f_copy(&r1, &r2);

  for(int i = 0; i < 9; i++) {
    ck_assert_float_eq(r1.as_array[i], r2.as_array[i]);
  }
}
END_TEST

START_TEST(test_matrix_mat3x3_invert) {
  ksl_mat3x3_t r1 = ksl_mat3x3(13.0, 8.0, 9.0, 3.0, 5.0, 1.0, 1.0, 0.5, 3.0);

  ksl_mat3x3_invert(&r1);

  ksl_mat3x3_t r2 =
    ksl_mat3x3(0.15591397849462368, -0.20967741935483872, -0.39784946236559143,
               -0.08602150537634409, 0.32258064516129037, 0.1505376344086022,
               -0.037634408602150546, 0.016129032258064523, 0.4408602150537635);

  for(int i = 0; i < 9; i++) {
    ck_assert_double_eq_tol(r1.as_array[i], r2.as_array[i], 1e-9);
  }
}
END_TEST

START_TEST(test_matrix_mat3x3f_invert) {
  ksl_mat3x3f_t r1 = ksl_mat3x3f(13.0, 8.0, 9.0, 3.0, 5.0, 1.0, 1.0, 0.5, 3.0);

  ksl_mat3x3f_invert(&r1);

  ksl_mat3x3f_t r2 = ksl_mat3x3f(
    0.15591397849462368, -0.20967741935483872, -0.39784946236559143,
    -0.08602150537634409, 0.32258064516129037, 0.1505376344086022,
    -0.037634408602150546, 0.016129032258064523, 0.4408602150537635);

  for(int i = 0; i < 9; i++) {
    ck_assert_float_eq_tol(r1.as_array[i], r2.as_array[i], 1e-6);
  }
}
END_TEST

START_TEST(test_matrix_mat3x3_inverted) {
  ksl_mat3x3_t r1 = ksl_mat3x3(13.0, 8.0, 9.0, 3.0, 5.0, 1.0, 1.0, 0.5, 3.0);
  ksl_mat3x3_t r2;
  ksl_mat3x3_inverted(&r1, &r2);
  ksl_mat3x3_invert(&r1);

  for(int i = 0; i < 9; i++) {
    ck_assert_double_eq(r1.as_array[i], r2.as_array[i]);
  }
}
END_TEST

START_TEST(test_matrix_mat3x3f_inverted) {
  ksl_mat3x3f_t r1 = ksl_mat3x3f(13.0, 8.0, 9.0, 3.0, 5.0, 1.0, 1.0, 0.5, 3.0);
  ksl_mat3x3f_t r2;
  ksl_mat3x3f_inverted(&r1, &r2);
  ksl_mat3x3f_invert(&r1);

  for(int i = 0; i < 9; i++) {
    ck_assert(fabs(r1.as_array[i] - r2.as_array[i]) < 1e-8);
  }
}
END_TEST

START_TEST(test_matrix_mat3x3_transpose) {
  ksl_mat3x3_t r1 = ksl_mat3x3(13.0, 8.0, 9.0, 3.0, 5.0, 1.0, 1.0, 0.5, 3.0);
  ksl_mat3x3_t r2;
  ksl_mat3x3_copy(&r1, &r2);
  ksl_mat3x3_transpose(&r1);
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      ck_assert_double_eq(r1.at[i][j], r2.at[j][i]);
    }
  }
}
END_TEST

START_TEST(test_matrix_mat3x3f_transpose) {
  ksl_mat3x3f_t r1 = ksl_mat3x3f(13.0, 8.0, 9.0, 3.0, 5.0, 1.0, 1.0, 0.5, 3.0);
  ksl_mat3x3f_t r2;
  ksl_mat3x3f_copy(&r1, &r2);
  ksl_mat3x3f_transpose(&r1);
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      ck_assert_float_eq(r1.at[i][j], r2.at[j][i]);
    }
  }
}
END_TEST

START_TEST(test_matrix_mat3x3_transposed) {
  ksl_mat3x3_t r1 = ksl_mat3x3(13.0, 8.0, 9.0, 3.0, 5.0, 1.0, 1.0, 0.5, 3.0);
  ksl_mat3x3_t r2;
  ksl_mat3x3_transposed(&r1, &r2);
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      ck_assert_double_eq(r1.at[i][j], r2.at[j][i]);
    }
  }
}
END_TEST

START_TEST(test_matrix_mat3x3f_transposed) {
  ksl_mat3x3f_t r1 = ksl_mat3x3f(13.0, 8.0, 9.0, 3.0, 5.0, 1.0, 1.0, 0.5, 3.0);
  ksl_mat3x3f_t r2;
  ksl_mat3x3f_transposed(&r1, &r2);
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      ck_assert_float_eq(r1.at[i][j], r2.at[j][i]);
    }
  }
}
END_TEST

START_TEST(test_matrix_SE3_copy) {
  ksl_SE3_t d1 =
    ksl_SE3(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0);
  ksl_SE3_t d2;
  ksl_SE3_copy(&d1, &d2);
  for(int i = 0; i < 12; i++) {
    ck_assert_double_eq(d1.as_array[i], d2.as_array[i]);
  }
}
END_TEST

START_TEST(test_matrix_SE3f_copy) {
  ksl_SE3f_t d1 =
    ksl_SE3f(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0);
  ksl_SE3f_t d2;
  ksl_SE3f_copy(&d1, &d2);
  for(int i = 0; i < 12; i++) {
    ck_assert_float_eq(d1.as_array[i], d2.as_array[i]);
  }
}
END_TEST

START_TEST(test_matrix_SE3_inverted) {
  ksl_SE3_t d1 =
    ksl_SE3(0.28953232855036204, 0.13809317325638165, 0.9471543201739556, 1.0,
            -0.9568081313741513, 0.014614837677269121, 0.29035255510494773, 2.0,
            0.026253199052874154, -0.99031140658868, 0.13636013904305067, 3.0);
  ksl_SE3_t d2;
  ksl_SE3_inverted(&d1, &d2);
  ksl_SE3_t d3;
  ksl_product_dd(&d1, &d2, &d3);

  /* verify that the result is identity */
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 4; j++) {
      if(i == j) {
        ck_assert_double_eq_tol(1.0, d3.at[j][i], 1e-9);
      } else {
        ck_assert_double_eq_tol(0.0, d3.at[j][i], 1e-9);
      }
    }
  }
}
END_TEST

START_TEST(test_matrix_SE3f_inverted) {
  ksl_SE3f_t d1 = ksl_SE3f(
    0.28953232855036204, 0.13809317325638165, 0.9471543201739556, 1.0,
    -0.9568081313741513, 0.014614837677269121, 0.29035255510494773, 2.0,
    0.026253199052874154, -0.99031140658868, 0.13636013904305067, 3.0);
  ksl_SE3f_t d2;
  ksl_SE3f_inverted(&d1, &d2);
  ksl_SE3f_t d3;
  ksl_product_ddf(&d1, &d2, &d3);

  /* verify that the result is identity */
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 4; j++) {
      if(i == j) {
        ck_assert_float_eq_tol(1.0, d3.at[j][i], 1e-6);
      } else {
        ck_assert_float_eq_tol(0.0, d3.at[j][i], 1e-6);
      }
    }
  }
}
END_TEST

START_TEST(test_matrix_SE3_invert) {
  ksl_SE3_t d1 =
    ksl_SE3(0.28953232855036204, 0.13809317325638165, 0.9471543201739556, 1.0,
            -0.9568081313741513, 0.014614837677269121, 0.29035255510494773, 2.0,
            0.026253199052874154, -0.99031140658868, 0.13636013904305067, 3.0);
  ksl_SE3_t d2;
  ksl_SE3_copy(&d1, &d2);
  ksl_SE3_invert(&d1);
  ksl_SE3_t d3;
  ksl_product_dd(&d1, &d2, &d3);

  /* verify that the result is identity */
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 4; j++) {
      if(i == j) {
        ck_assert_double_eq_tol(1.0, d3.at[j][i], 1e-9);
      } else {
        ck_assert_double_eq_tol(0.0, d3.at[j][i], 1e-9);
      }
    }
  }
}
END_TEST

START_TEST(test_matrix_SE3f_invert) {
  ksl_SE3f_t d1 = ksl_SE3f(
    0.28953232855036204, 0.13809317325638165, 0.9471543201739556, 1.0,
    -0.9568081313741513, 0.014614837677269121, 0.29035255510494773, 2.0,
    0.026253199052874154, -0.99031140658868, 0.13636013904305067, 3.0);
  ksl_SE3f_t d2;
  ksl_SE3f_copy(&d1, &d2);
  ksl_SE3f_invert(&d1);
  ksl_SE3f_t d3;
  ksl_product_ddf(&d1, &d2, &d3);

  /* verify that the result is identity */
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 4; j++) {
      if(i == j) {
        ck_assert(fabs(1.0 - d3.at[j][i]) < 1e-6);
      } else {
        ck_assert(fabs(d3.at[j][i]) < 1e-6);
      }
    }
  }
}
END_TEST

START_TEST(test_matrix_mat3x3_getEulerAngles) {
  ksl_mat3x3_t r1;
  ksl_mat3x3_t r2;

  for(int j = 0; j < 12; j++) {
    ksl_mat3x3_setIdentity(&r1);
    ksl_axis_enum_t axis = j;
    ksl_vec3i_t sequence = ksl_axis_getVector(axis);
    ksl_vec3_t angles_test = {{0.2, 0.3, 0.4}};
    double dc[2];
    for(int i = 0; i < 3; i++) {
      ksl_dc(angles_test.at[i], dc);
      switch(sequence.at[i]) {
        case 0: {
          ksl_product_drdrx(&r1, dc, &r2);
          break;
        }
        case 1: {
          ksl_product_drdry(&r1, dc, &r2);
          break;
        }
        case 2: {
          ksl_product_drdrz(&r1, dc, &r2);
          break;
        }
      }
      r1 = r2;
    }

    ksl_vec3_t angles;
    ksl_vec3_t angles_prev = {{0.21, 0.31, 0.41}};
    ksl_mat3x3_getEulerAngles(&r1, axis, &angles, &angles_prev);

    for(int i = 0; i < 3; i++) {
      ck_assert_msg(fabs(angles_test.at[i] - angles.at[i]) < 1e-9,
                    "failed for angle sequence: %d%d%d\n", sequence.x,
                    sequence.y, sequence.z);
    }

    ksl_mat3x3_getEulerAngles(&r1, axis, &angles);
    for(int i = 0; i < 3; i++) {
      ck_assert_msg(fabs(angles_test.at[i] - angles.at[i]) < 1e-9,
                    "failed for angle sequence with reference: %d%d%d\n",
                    sequence.x, sequence.y, sequence.z);
    }
  }
}
END_TEST

START_TEST(test_matrix_mat3x3_setFromEulerAngles) {
  ksl_mat3x3_t r1;
  ksl_mat3x3_t r2;

  for(int j = 0; j < 12; j++) {
    ksl_mat3x3_setIdentity(&r1);
    ksl_axis_enum_t axis = j;
    ksl_vec3i_t sequence = ksl_axis_getVector(axis);
    ksl_vec3_t angles = {{0.2, 0.3, 0.4}};
    double dc[2];
    for(int i = 0; i < 3; i++) {
      ksl_dc(angles.at[i], dc);
      switch(sequence.at[i]) {
        case 0: {
          ksl_product_drdrx(&r1, dc, &r2);
          break;
        }
        case 1: {
          ksl_product_drdry(&r1, dc, &r2);
          break;
        }
        case 2: {
          ksl_product_drdrz(&r1, dc, &r2);
          break;
        }
      }
      r1 = r2;
    }
    ksl_mat3x3_setFromEulerAngles(&r2, axis, &angles);
    for(int i = 0; i < 9; i++) {
      ck_assert_msg(fabs(r1.as_array[i] - r2.as_array[i]) < 1e-6,
                    "setFromEulerAngles failed for angle sequence: %d%d%d",
                    sequence.at[0], sequence.at[1], sequence.at[2]);
    }
  }
}
END_TEST

START_TEST(test_matrix_mat4x4_getTranslation) {
  ksl_mat4x4_t m = {{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0,
                     12.0, 13.0, 14.0, 15.0, 16.0}};
  ksl_vec3_t v;
  ksl_mat4x4_getTranslation(&m, &v);
  ck_assert_double_eq(v.x, m.m03);
  ck_assert_double_eq(v.y, m.m13);
  ck_assert_double_eq(v.z, m.m23);
}
END_TEST

START_TEST(test_matrix_mat4x4f_getTranslation) {
  ksl_mat4x4f_t m = {{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0,
                      12.0, 13.0, 14.0, 15.0, 16.0}};
  ksl_vec3f_t v;
  ksl_mat4x4f_getTranslation(&m, &v);
  ck_assert_float_eq(v.x, m.m03);
  ck_assert_float_eq(v.y, m.m13);
  ck_assert_float_eq(v.z, m.m23);
}
END_TEST

START_TEST(test_matrix_mat3x3_determinant) {
  ksl_mat3x3_t m = {{3.0, 2.0, 1.0, 4.0, 5.0, 6.0, 7.0, 9.0, 8.0}};
  double det = ksl_mat3x3_determinant(&m);
  ck_assert_double_eq_tol(det, -21, 1e-9);
}
END_TEST

START_TEST(test_matrix_mat3x3f_determinant) {
  ksl_mat3x3f_t m = {{3.0, 2.0, 1.0, 4.0, 5.0, 6.0, 7.0, 9.0, 8.0}};
  float det = ksl_mat3x3f_determinant(&m);
  ck_assert_float_eq_tol(det, -21, 1e-6);
}
END_TEST

START_TEST(test_matrix_mat3x3_getAxisAngle) {
  ksl_vec3_t axis = {{1.0, 2.0, 3.0}};
  double angle = 0.5;
  ksl_mat3x3_t m;
  ksl_mat3x3_setFromAxisAngle(&m, &axis, angle);

  ksl_vec3_t axis_test;
  double angle_test;
  ksl_mat3x3_getAxisAngle(&m, &axis_test, &angle_test);
  ksl_vec3_normalize(&axis);

  ck_assert_double_eq_tol(axis.x, axis_test.x, 1e-9);
  ck_assert_double_eq_tol(axis.y, axis_test.y, 1e-9);
  ck_assert_double_eq_tol(axis.z, axis_test.z, 1e-9);
  ck_assert_double_eq_tol(angle, angle_test, 1e-9);
}
END_TEST

START_TEST(test_matrix_mat3x3f_getAxisAngle) {
  ksl_vec3f_t axis = {{1.0, 2.0, 3.0}};
  float angle = 0.5;
  ksl_mat3x3f_t m;
  ksl_mat3x3f_setFromAxisAngle(&m, &axis, angle);

  ksl_vec3f_t axis_test;
  float angle_test;
  ksl_mat3x3f_getAxisAngle(&m, &axis_test, &angle_test);
  ksl_vec3f_normalize(&axis);

  ck_assert_float_eq_tol(axis.x, axis_test.x, 1e-6);
  ck_assert_float_eq_tol(axis.y, axis_test.y, 1e-6);
  ck_assert_float_eq_tol(axis.z, axis_test.z, 1e-6);
  ck_assert_float_eq_tol(angle, angle_test, 1e-6);
}
END_TEST

/* matrix vector operations */
START_TEST(test_matrix_product_drv) {

  ksl_mat3x3_t r;
  ksl_mat3x3_setIdentity(&r);
  ksl_vec3_t angles = {{0.2, 0.3, 0.4}};
  ksl_mat3x3_setFromEulerAngles(&r, KSL_AXIS_XYZ, &angles);

  ksl_vec3_t v1 = {{1.0, 2.0, 3.0}};
  ksl_vec3_t v2;
  ksl_product_drv(&r, &v1, &v2);

  ck_assert_double_eq_tol(v2.x, 1.0224326923807563, 1e-9);
  ck_assert_double_eq_tol(v2.y, 1.6260200151342845, 1e-9);
  ck_assert_double_eq_tol(v2.z, 3.2110263623853568, 1e-9);
}
END_TEST

START_TEST(test_matrix_product_drvf) {

  ksl_mat3x3f_t r;
  ksl_mat3x3f_setIdentity(&r);
  ksl_vec3f_t angles = {{0.2, 0.3, 0.4}};
  ksl_mat3x3f_setFromEulerAngles(&r, KSL_AXIS_XYZ, &angles);
  ksl_vec3f_t v1 = {{1.0, 2.0, 3.0}};

  ksl_vec3f_t v2;
  ksl_product_drvf(&r, &v1, &v2);
  ck_assert_float_eq_tol(v2.x, 1.0224326923807563, 1e-6);
  ck_assert_float_eq_tol(v2.y, 1.6260200151342845, 1e-6);
  ck_assert_float_eq_tol(v2.z, 3.2110263623853568, 1e-6);
}
END_TEST

START_TEST(test_matrix_product_drvinv) {

  ksl_mat3x3_t r;
  ksl_mat3x3_setIdentity(&r);
  ksl_vec3_t angles = {{0.2, 0.3, 0.4}};
  ksl_mat3x3_setFromEulerAngles(&r, KSL_AXIS_XYZ, &angles);
  ksl_vec3_t v1 = {{1.0, 2.0, 3.0}};
  ksl_vec3_t v2;
  ksl_product_drvinv(&r, &v1, &v2);
  ck_assert_double_eq_tol(v2.x, -1.0224326923807563, 1e-9);
  ck_assert_double_eq_tol(v2.y, -1.6260200151342845, 1e-9);
  ck_assert_double_eq_tol(v2.z, -3.2110263623853568, 1e-9);
}
END_TEST

START_TEST(test_matrix_product_drvinvf) {

  ksl_mat3x3f_t r;
  ksl_mat3x3f_setIdentity(&r);
  ksl_vec3f_t angles = {{0.2, 0.3, 0.4}};
  ksl_mat3x3f_setFromEulerAngles(&r, KSL_AXIS_XYZ, &angles);
  ksl_vec3f_t v1 = {{1.0, 2.0, 3.0}};

  ksl_vec3f_t v2;
  ksl_product_drvinvf(&r, &v1, &v2);
  ck_assert_float_eq_tol(v2.x, -1.0224326923807563, 1e-6);
  ck_assert_float_eq_tol(v2.y, -1.6260200151342845, 1e-6);
  ck_assert_float_eq_tol(v2.z, -3.2110263623853568, 1e-6);
}
END_TEST

START_TEST(test_matrix_product_drinvv) {

  ksl_mat3x3_t r;
  ksl_mat3x3_setIdentity(&r);
  ksl_vec3_t angles = {{0.2, 0.3, 0.4}};
  ksl_mat3x3_setFromEulerAngles(&r, KSL_AXIS_XYZ, &angles);
  ksl_vec3_t v1 = {{1.0, 2.0, 3.0}};
  ksl_vec3_t v2;
  ksl_product_drinvv(&r, &v1, &v2);
  ck_assert_double_eq_tol(v2.x, 1.1831846399394617, 1e-9);
  ck_assert_double_eq_tol(v2.y, 2.274971321748124, 1e-9);
  ck_assert_double_eq_tol(v2.z, 2.7248081754565625, 1e-9);
}
END_TEST

START_TEST(test_matrix_product_drinvvf) {

  ksl_mat3x3f_t r;
  ksl_mat3x3f_setIdentity(&r);
  ksl_vec3f_t angles = {{0.2, 0.3, 0.4}};
  ksl_mat3x3f_setFromEulerAngles(&r, KSL_AXIS_XYZ, &angles);
  ksl_vec3f_t v1 = {{1.0, 2.0, 3.0}};

  ksl_vec3f_t v2;
  ksl_product_drinvvf(&r, &v1, &v2);
  ck_assert_float_eq_tol(v2.x, 1.1831846399394617, 1e-6);
  ck_assert_float_eq_tol(v2.y, 2.274971321748124, 1e-6);
  ck_assert_float_eq_tol(v2.z, 2.7248081754565625, 1e-6);
}
END_TEST

START_TEST(test_matrix_product_drinvvinv) {

  ksl_mat3x3_t r;
  ksl_mat3x3_setIdentity(&r);
  ksl_vec3_t angles = {{0.2, 0.3, 0.4}};
  ksl_mat3x3_setFromEulerAngles(&r, KSL_AXIS_XYZ, &angles);
  ksl_vec3_t v1 = {{1.0, 2.0, 3.0}};
  ksl_vec3_t v2;
  ksl_product_drinvvinv(&r, &v1, &v2);
  ck_assert_double_eq_tol(v2.x, -1.1831846399394617, 1e-9);
  ck_assert_double_eq_tol(v2.y, -2.274971321748124, 1e-9);
  ck_assert_double_eq_tol(v2.z, -2.7248081754565625, 1e-9);
}
END_TEST

START_TEST(test_matrix_product_drinvvinvf) {

  ksl_mat3x3f_t r;
  ksl_mat3x3f_setIdentity(&r);
  ksl_vec3f_t angles = {{0.2, 0.3, 0.4}};
  ksl_mat3x3f_setFromEulerAngles(&r, KSL_AXIS_XYZ, &angles);
  ksl_vec3f_t v1 = {{1.0, 2.0, 3.0}};

  ksl_vec3f_t v2;
  ksl_product_drinvvinvf(&r, &v1, &v2);
  ck_assert_float_eq_tol(v2.x, -1.1831846399394617, 1e-6);
  ck_assert_float_eq_tol(v2.y, -2.274971321748124, 1e-6);
  ck_assert_float_eq_tol(v2.z, -2.7248081754565625, 1e-6);
}
END_TEST

START_TEST(test_matrix_product_drvtx) {
  ksl_mat3x3_t r;
  ksl_mat3x3_setIdentity(&r);
  ksl_vec3_t angles = {{0.2, 0.3, 0.4}};
  ksl_mat3x3_setFromEulerAngles(&r, KSL_AXIS_XYZ, &angles);
  ksl_vec3_t v2;
  ksl_product_drvtx(&r, 2.0, &v2);
  ck_assert_double_eq_tol(v2.x, 1.759846352562514, 1e-9);
  ck_assert_double_eq_tol(v2.y, 0.8714642629237408, 1e-9);
  ck_assert_double_eq_tol(v2.z, -0.3788018661770242, 1e-9);
}
END_TEST

START_TEST(test_matrix_product_drvtxf) {
  ksl_mat3x3f_t r;
  ksl_mat3x3f_setIdentity(&r);
  ksl_vec3f_t angles = {{0.2, 0.3, 0.4}};
  ksl_mat3x3f_setFromEulerAngles(&r, KSL_AXIS_XYZ, &angles);
  ksl_vec3f_t v2;
  ksl_product_drvtxf(&r, 2.0, &v2);
  ck_assert_float_eq_tol(v2.x, 1.759846352562514, 1e-6);
  ck_assert_float_eq_tol(v2.y, 0.8714642629237408, 1e-6);
  ck_assert_float_eq_tol(v2.z, -0.3788018661770242, 1e-6);
}
END_TEST

START_TEST(test_matrix_product_drvtxinv) {
  ksl_mat3x3_t r;
  ksl_mat3x3_setIdentity(&r);
  ksl_vec3_t angles = {{0.2, 0.3, 0.4}};
  ksl_mat3x3_setFromEulerAngles(&r, KSL_AXIS_XYZ, &angles);
  ksl_vec3_t v2;
  ksl_product_drvtxinv(&r, 2.0, &v2);
  ck_assert_double_eq_tol(v2.x, -1.759846352562514, 1e-9);
  ck_assert_double_eq_tol(v2.y, -0.8714642629237408, 1e-9);
  ck_assert_double_eq_tol(v2.z, 0.3788018661770242, 1e-9);
}
END_TEST

START_TEST(test_matrix_product_drvtxinvf) {
  ksl_mat3x3f_t r;
  ksl_mat3x3f_setIdentity(&r);
  ksl_vec3f_t angles = {{0.2, 0.3, 0.4}};
  ksl_mat3x3f_setFromEulerAngles(&r, KSL_AXIS_XYZ, &angles);
  ksl_vec3f_t v2;
  ksl_product_drvtxinvf(&r, 2.0, &v2);
  ck_assert_float_eq_tol(v2.x, -1.759846352562514, 1e-6);
  ck_assert_float_eq_tol(v2.y, -0.8714642629237408, 1e-6);
  ck_assert_float_eq_tol(v2.z, 0.3788018661770242, 1e-6);
}
END_TEST

START_TEST(test_matrix_product_drvty) {
  ksl_mat3x3_t r;
  ksl_mat3x3_setIdentity(&r);
  ksl_vec3_t angles = {{0.2, 0.3, 0.4}};
  ksl_mat3x3_setFromEulerAngles(&r, KSL_AXIS_XYZ, &angles);
  ksl_vec3_t v2;
  ksl_product_drvty(&r, 2.0, &v2);
  ck_assert_double_eq_tol(v2.x, -0.7440511038845192, 1e-9);
  ck_assert_double_eq_tol(v2.y, 1.7596760666084763, 1e-9);
  ck_assert_double_eq_tol(v2.z, 0.5915472047212714, 1e-9);
}
END_TEST

START_TEST(test_matrix_product_drvtyf) {
  ksl_mat3x3f_t r;
  ksl_mat3x3f_setIdentity(&r);
  ksl_vec3f_t angles = {{0.2, 0.3, 0.4}};
  ksl_mat3x3f_setFromEulerAngles(&r, KSL_AXIS_XYZ, &angles);
  ksl_vec3f_t v2;
  ksl_product_drvtyf(&r, 2.0, &v2);
  ck_assert_float_eq_tol(v2.x, -0.7440511038845192, 1e-6);
  ck_assert_float_eq_tol(v2.y, 1.7596760666084763, 1e-6);
  ck_assert_float_eq_tol(v2.z, 0.5915472047212714, 1e-6);
}
END_TEST

START_TEST(test_matrix_product_drvtyinv) {
  ksl_mat3x3_t r;
  ksl_mat3x3_setIdentity(&r);
  ksl_vec3_t angles = {{0.2, 0.3, 0.4}};
  ksl_mat3x3_setFromEulerAngles(&r, KSL_AXIS_XYZ, &angles);
  ksl_vec3_t v2;
  ksl_product_drvtyinv(&r, 2.0, &v2);
  ck_assert_double_eq_tol(v2.x, 0.7440511038845192, 1e-9);
  ck_assert_double_eq_tol(v2.y, -1.7596760666084763, 1e-9);
  ck_assert_double_eq_tol(v2.z, -0.5915472047212714, 1e-9);
}
END_TEST

START_TEST(test_matrix_product_drvtyinvf) {
  ksl_mat3x3f_t r;
  ksl_mat3x3f_setIdentity(&r);
  ksl_vec3f_t angles = {{0.2, 0.3, 0.4}};
  ksl_mat3x3f_setFromEulerAngles(&r, KSL_AXIS_XYZ, &angles);
  ksl_vec3f_t v2;
  ksl_product_drvtyinvf(&r, 2.0, &v2);
  ck_assert_float_eq_tol(v2.x, 0.7440511038845192, 1e-6);
  ck_assert_float_eq_tol(v2.y, -1.7596760666084763, 1e-6);
  ck_assert_float_eq_tol(v2.z, -0.5915472047212714, 1e-6);
}
END_TEST

START_TEST(test_matrix_product_drvtz) {
  ksl_mat3x3_t r;
  ksl_mat3x3_setIdentity(&r);
  ksl_vec3_t angles = {{0.2, 0.3, 0.4}};
  ksl_mat3x3_setFromEulerAngles(&r, KSL_AXIS_XYZ, &angles);
  ksl_vec3_t v2;
  ksl_product_drvtz(&r, 2.0, &v2);
  ck_assert_double_eq_tol(v2.x, 0.591040413322679, 1e-9);
  ck_assert_double_eq_tol(v2.y, -0.3795921219573748, 1e-9);
  ck_assert_double_eq_tol(v2.z, 1.8725867271683985, 1e-9);
}
END_TEST

START_TEST(test_matrix_product_drvtzf) {
  ksl_mat3x3f_t r;
  ksl_mat3x3f_setIdentity(&r);
  ksl_vec3f_t angles = {{0.2, 0.3, 0.4}};
  ksl_mat3x3f_setFromEulerAngles(&r, KSL_AXIS_XYZ, &angles);
  ksl_vec3f_t v2;
  ksl_product_drvtzf(&r, 2.0, &v2);
  ck_assert_float_eq_tol(v2.x, 0.591040413322679, 1e-6);
  ck_assert_float_eq_tol(v2.y, -0.3795921219573748, 1e-6);
  ck_assert_float_eq_tol(v2.z, 1.8725867271683985, 1e-6);
}
END_TEST

START_TEST(test_matrix_product_drvtzinv) {
  ksl_mat3x3_t r;
  ksl_mat3x3_setIdentity(&r);
  ksl_vec3_t angles = {{0.2, 0.3, 0.4}};
  ksl_mat3x3_setFromEulerAngles(&r, KSL_AXIS_XYZ, &angles);
  ksl_vec3_t v2;
  ksl_product_drvtzinv(&r, 2.0, &v2);
  ck_assert_double_eq_tol(v2.x, -0.591040413322679, 1e-9);
  ck_assert_double_eq_tol(v2.y, 0.3795921219573748, 1e-9);
  ck_assert_double_eq_tol(v2.z, -1.8725867271683985, 1e-9);
}
END_TEST

START_TEST(test_matrix_product_drvtzinvf) {
  ksl_mat3x3f_t r;
  ksl_mat3x3f_setIdentity(&r);
  ksl_vec3f_t angles = {{0.2, 0.3, 0.4}};
  ksl_mat3x3f_setFromEulerAngles(&r, KSL_AXIS_XYZ, &angles);
  ksl_vec3f_t v2;
  ksl_product_drvtzinvf(&r, 2.0, &v2);
  ck_assert_float_eq_tol(v2.x, -0.591040413322679, 1e-6);
  ck_assert_float_eq_tol(v2.y, 0.3795921219573748, 1e-6);
  ck_assert_float_eq_tol(v2.z, -1.8725867271683985, 1e-6);
}
END_TEST

/* matrix-matrix operations */
START_TEST(test_matrix_product_drdrx) {
  ksl_mat3x3_t r1;
  ksl_mat3x3_setIdentity(&r1);
  ksl_vec3_t angles = {{0.2, 0.3, 0.4}};
  ksl_mat3x3_setFromEulerAngles(&r1, KSL_AXIS_XYZ, &angles);
  ksl_mat3x3_t r2;
  double dc[2];
  ksl_dc(0.5, dc);
  ksl_product_drdrx(&r1, dc, &r2);

  ksl_mat3x3_t r3 =
    ksl_mat3x3(0.879923176281257, -0.1848032027151301, 0.4377019306666745,
               0.4357321314618704, 0.6811374365560571, -0.588378536431725,
               -0.1894009330885121, 0.7084487058270867, 0.6798733100785226);

  for(int i = 0; i < 9; i++) {
    ck_assert_double_eq_tol(r2.as_array[i], r3.as_array[i], 1e-9);
  }
}
END_TEST

START_TEST(test_matrix_product_drdrxf) {
  ksl_mat3x3f_t r1;
  ksl_mat3x3f_setIdentity(&r1);
  ksl_vec3f_t angles = {{0.2, 0.3, 0.4}};
  ksl_mat3x3f_setFromEulerAngles(&r1, KSL_AXIS_XYZ, &angles);
  ksl_mat3x3f_t r2;
  float dc[2];
  ksl_dcf(0.5, dc);
  ksl_product_drdrxf(&r1, dc, &r2);

  ksl_mat3x3f_t r3 =
    ksl_mat3x3f(0.879923176281257, -0.1848032027151301, 0.4377019306666745,
                0.4357321314618704, 0.6811374365560571, -0.588378536431725,
                -0.1894009330885121, 0.7084487058270867, 0.6798733100785226);

  for(int i = 0; i < 9; i++) {
    ck_assert_float_eq_tol(r2.as_array[i], r3.as_array[i], 1e-6);
  }
}
END_TEST

START_TEST(test_matrix_product_drdrxinv) {
  ksl_mat3x3_t r1;
  ksl_mat3x3_setIdentity(&r1);
  ksl_vec3_t angles = {{0.2, 0.3, 0.4}};
  ksl_mat3x3_setFromEulerAngles(&r1, KSL_AXIS_XYZ, &angles);
  ksl_mat3x3_t r2;
  double dc[2];
  ksl_dc(0.5, dc);
  ksl_product_drdrxinv(&r1, dc, &r2);

  ksl_mat3x3_t r3 =
    ksl_mat3x3(0.879923176281257, -0.4681630712092062, 0.080984829437787,
               0.4357321314618704, 0.8631235940753837, 0.2552551095709692,
               -0.1894009330885121, -0.1893171944287045, 0.963476147311829);

  for(int i = 0; i < 9; i++) {
    ck_assert_double_eq_tol(r2.as_array[i], r3.as_array[i], 1e-9);
  }
}
END_TEST

START_TEST(test_matrix_product_drdrxinvf) {
  ksl_mat3x3f_t r1;
  ksl_mat3x3f_setIdentity(&r1);
  ksl_vec3f_t angles = {{0.2, 0.3, 0.4}};
  ksl_mat3x3f_setFromEulerAngles(&r1, KSL_AXIS_XYZ, &angles);
  ksl_mat3x3f_t r2;
  float dc[2];
  ksl_dcf(0.5, dc);
  ksl_product_drdrxinvf(&r1, dc, &r2);

  ksl_mat3x3f_t r3 =
    ksl_mat3x3f(0.879923176281257, -0.4681630712092062, 0.080984829437787,
                0.4357321314618704, 0.8631235940753837, 0.2552551095709692,
                -0.1894009330885121, -0.1893171944287045, 0.963476147311829);

  for(int i = 0; i < 9; i++) {
    ck_assert_float_eq_tol(r2.as_array[i], r3.as_array[i], 1e-6);
  }
}
END_TEST

START_TEST(test_matrix_product_drdry) {
  ksl_mat3x3_t r1;
  ksl_mat3x3_setIdentity(&r1);
  ksl_vec3_t angles = {{0.2, 0.3, 0.4}};
  ksl_mat3x3_setFromEulerAngles(&r1, KSL_AXIS_XYZ, &angles);
  ksl_mat3x3_t r2;
  double dc[2];
  ksl_dc(0.5, dc);
  ksl_product_drdry(&r1, dc, &r2);

  ksl_mat3x3_t r3 =
    ksl_mat3x3(0.6305253010605816, -0.3720255519422596, 0.6812010227711935,
               0.4733839989859243, 0.8798380333042382, 0.0423393983828867,
               -0.6150979062121391, 0.2957736023606357, 0.7308710843370773);

  for(int i = 0; i < 9; i++) {
    ck_assert_double_eq_tol(r2.as_array[i], r3.as_array[i], 1e-9);
  }
}
END_TEST

START_TEST(test_matrix_product_drdryf) {
  ksl_mat3x3f_t r1;
  ksl_mat3x3f_setIdentity(&r1);
  ksl_vec3f_t angles = {{0.2, 0.3, 0.4}};
  ksl_mat3x3f_setFromEulerAngles(&r1, KSL_AXIS_XYZ, &angles);
  ksl_mat3x3f_t r2;
  float dc[2];
  ksl_dcf(0.5, dc);
  ksl_product_drdryf(&r1, dc, &r2);

  ksl_mat3x3f_t r3 =
    ksl_mat3x3f(0.6305253010605816, -0.3720255519422596, 0.6812010227711935,
                0.4733839989859243, 0.8798380333042382, 0.0423393983828867,
                -0.6150979062121391, 0.2957736023606357, 0.7308710843370773);

  for(int i = 0; i < 9; i++) {
    ck_assert_float_eq_tol(r2.as_array[i], r3.as_array[i], 1e-6);
  }
}
END_TEST

START_TEST(test_matrix_product_drdryinv) {
  ksl_mat3x3_t r1;
  ksl_mat3x3_setIdentity(&r1);
  ksl_vec3_t angles = {{0.2, 0.3, 0.4}};
  ksl_mat3x3_setFromEulerAngles(&r1, KSL_AXIS_XYZ, &angles);
  ksl_mat3x3_t r2;
  double dc[2];
  ksl_dc(0.5, dc);
  ksl_product_drdryinv(&r1, dc, &r2);

  ksl_mat3x3_t r3 =
    ksl_mat3x3(0.9138851695546577, -0.3720255519422596, -0.1625142626667319,
               0.2913978414665975, 0.8798380333042382, -0.3754628252436425,
               0.2826679940436521, 0.2957736023606357, 0.9124783730532743);

  for(int i = 0; i < 9; i++) {
    ck_assert_double_eq_tol(r2.as_array[i], r3.as_array[i], 1e-9);
  }
}
END_TEST

START_TEST(test_matrix_product_drdryinvf) {
  ksl_mat3x3f_t r1;
  ksl_mat3x3f_setIdentity(&r1);
  ksl_vec3f_t angles = {{0.2, 0.3, 0.4}};
  ksl_mat3x3f_setFromEulerAngles(&r1, KSL_AXIS_XYZ, &angles);
  ksl_mat3x3f_t r2;
  float dc[2];
  ksl_dcf(0.5, dc);
  ksl_product_drdryinvf(&r1, dc, &r2);

  ksl_mat3x3f_t r3 =
    ksl_mat3x3f(0.9138851695546577, -0.3720255519422596, -0.1625142626667319,
                0.2913978414665975, 0.8798380333042382, -0.3754628252436425,
                0.2826679940436521, 0.2957736023606357, 0.9124783730532743);

  for(int i = 0; i < 9; i++) {
    ck_assert_float_eq_tol(r2.as_array[i], r3.as_array[i], 1e-6);
  }
}
END_TEST

START_TEST(test_matrix_product_drdrz) {
  ksl_mat3x3_t r1;
  ksl_mat3x3_setIdentity(&r1);
  ksl_vec3_t angles = {{0.2, 0.3, 0.4}};
  ksl_mat3x3_setFromEulerAngles(&r1, KSL_AXIS_XYZ, &angles);
  ksl_mat3x3_t r2;
  double dc[2];
  ksl_dc(0.5, dc);
  ksl_product_drdrz(&r1, dc, &r2);

  ksl_mat3x3_t r3 =
    ksl_mat3x3(0.5938466846931759, -0.7483407796811308, 0.2955202066613395,
               0.804207743227608, 0.5632294035024559, -0.1897960609786874,
               -0.0244135374675904, 0.3503694000572896, 0.9362933635841992);

  for(int i = 0; i < 9; i++) {
    ck_assert_double_eq_tol(r2.as_array[i], r3.as_array[i], 1e-9);
  }
}
END_TEST

START_TEST(test_matrix_product_drdrzf) {
  ksl_mat3x3f_t r1;
  ksl_mat3x3f_setIdentity(&r1);
  ksl_vec3f_t angles = {{0.2, 0.3, 0.4}};
  ksl_mat3x3f_setFromEulerAngles(&r1, KSL_AXIS_XYZ, &angles);
  ksl_mat3x3f_t r2;
  float dc[2];
  ksl_dcf(0.5, dc);
  ksl_product_drdrzf(&r1, dc, &r2);

  ksl_mat3x3f_t r3 =
    ksl_mat3x3f(0.5938466846931759, -0.7483407796811308, 0.2955202066613395,
                0.804207743227608, 0.5632294035024559, -0.1897960609786874,
                -0.0244135374675904, 0.3503694000572896, 0.9362933635841992);

  for(int i = 0; i < 9; i++) {
    ck_assert_float_eq_tol(r2.as_array[i], r3.as_array[i], 1e-6);
  }
}
END_TEST

START_TEST(test_matrix_product_drdrzinv) {
  ksl_mat3x3_t r1;
  ksl_mat3x3_setIdentity(&r1);
  ksl_vec3_t angles = {{0.2, 0.3, 0.4}};
  ksl_mat3x3_setFromEulerAngles(&r1, KSL_AXIS_XYZ, &angles);
  ksl_mat3x3_t r2;
  double dc[2];
  ksl_dc(0.5, dc);
  ksl_product_drdrzinv(&r1, dc, &r2);

  ksl_mat3x3_t r3 =
    ksl_mat3x3(0.9505637859220634, 0.0953745057567946, 0.2955202066613395,
               -0.0394259027750862, 0.981031627128985, -0.1897960609786874,
               -0.3080163747008967, 0.1687621113410926, 0.9362933635841992);

  for(int i = 0; i < 9; i++) {
    ck_assert_double_eq_tol(r2.as_array[i], r3.as_array[i], 1e-9);
  }
}
END_TEST

START_TEST(test_matrix_product_drdrzinvf) {
  ksl_mat3x3f_t r1;
  ksl_mat3x3f_setIdentity(&r1);
  ksl_vec3f_t angles = {{0.2, 0.3, 0.4}};
  ksl_mat3x3f_setFromEulerAngles(&r1, KSL_AXIS_XYZ, &angles);
  ksl_mat3x3f_t r2;
  float dc[2];
  ksl_dcf(0.5, dc);
  ksl_product_drdrzinvf(&r1, dc, &r2);

  ksl_mat3x3f_t r3 =
    ksl_mat3x3f(0.9505637859220634, 0.0953745057567946, 0.2955202066613395,
                -0.0394259027750862, 0.981031627128985, -0.1897960609786874,
                -0.3080163747008967, 0.1687621113410926, 0.9362933635841992);

  for(int i = 0; i < 9; i++) {
    ck_assert_float_eq_tol(r2.as_array[i], r3.as_array[i], 1e-6);
  }
}
END_TEST

START_TEST(test_matrix_product_drdr) {
  ksl_mat3x3_t r1;
  ksl_mat3x3_setIdentity(&r1);
  ksl_vec3_t angles = {{0.2, 0.3, 0.4}};
  ksl_mat3x3_setFromEulerAngles(&r1, KSL_AXIS_XYZ, &angles);
  ksl_mat3x3_t r2;
  ksl_mat3x3_setFromEulerAngles(&r2, KSL_AXIS_XYZ, &angles);
  ksl_mat3x3_t r3;
  ksl_product_drdr(&r1, &r2, &r3);

  ksl_mat3x3_t r4 =
    ksl_mat3x3(0.556189506562649, -0.5672690591880383, 0.6073376715448456,
               0.8027320537624947, 0.5558748134730649, -0.2159269358105488,
               -0.2151150451545507, 0.6076257122885793, 0.7645367951341207);

  for(int i = 0; i < 9; i++) {
    ck_assert_double_eq_tol(r3.as_array[i], r4.as_array[i], 1e-9);
  }
}
END_TEST

START_TEST(test_matrix_product_drdrf) {
  ksl_mat3x3f_t r1;
  ksl_mat3x3f_setIdentity(&r1);
  ksl_vec3f_t angles = {{0.2, 0.3, 0.4}};
  ksl_mat3x3f_setFromEulerAngles(&r1, KSL_AXIS_XYZ, &angles);
  ksl_mat3x3f_t r2;
  ksl_mat3x3f_setFromEulerAngles(&r2, KSL_AXIS_XYZ, &angles);
  ksl_mat3x3f_t r3;
  ksl_product_drdrf(&r1, &r2, &r3);

  ksl_mat3x3f_t r4 =
    ksl_mat3x3f(0.556189506562649, -0.5672690591880383, 0.6073376715448456,
                0.8027320537624947, 0.5558748134730649, -0.2159269358105488,
                -0.2151150451545507, 0.6076257122885793, 0.7645367951341207);

  for(int i = 0; i < 9; i++) {
    ck_assert_float_eq_tol(r3.as_array[i], r4.as_array[i], 1e-6);
  }
}
END_TEST

START_TEST(test_matrix_product_drdrinv) {
  ksl_mat3x3_t r1;
  ksl_mat3x3_setIdentity(&r1);
  ksl_vec3_t angles = {{0.2, 0.3, 0.4}};
  ksl_mat3x3_setFromEulerAngles(&r1, KSL_AXIS_XYZ, &angles);
  ksl_mat3x3_t r2;
  ksl_mat3x3_setFromEulerAngles(&r2, KSL_AXIS_XYZ, &angles);
  ksl_mat3x3_t r3;
  ksl_product_drdrinv(&r1, &r2, &r3);

  ksl_mat3x3_t r4 = ksl_mat3x3(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);

  for(int i = 0; i < 9; i++) {
    ck_assert_double_eq_tol(r3.as_array[i], r4.as_array[i], 1e-9);
  }
}
END_TEST

START_TEST(test_matrix_product_drdrinvf) {
  ksl_mat3x3f_t r1;
  ksl_mat3x3f_setIdentity(&r1);
  ksl_vec3f_t angles = {{0.2, 0.3, 0.4}};
  ksl_mat3x3f_setFromEulerAngles(&r1, KSL_AXIS_XYZ, &angles);
  ksl_mat3x3f_t r2;
  ksl_mat3x3f_setFromEulerAngles(&r2, KSL_AXIS_XYZ, &angles);
  ksl_mat3x3f_t r3;
  ksl_product_drdrinvf(&r1, &r2, &r3);

  ksl_mat3x3f_t r4 = ksl_mat3x3f(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);

  for(int i = 0; i < 9; i++) {
    ck_assert_float_eq_tol(r3.as_array[i], r4.as_array[i], 1e-6);
  }
}
END_TEST

START_TEST(test_matrix_product_drinvdr) {
  ksl_mat3x3_t r1;
  ksl_mat3x3_setIdentity(&r1);
  ksl_vec3_t angles = {{0.2, 0.3, 0.4}};
  ksl_mat3x3_setFromEulerAngles(&r1, KSL_AXIS_XYZ, &angles);
  ksl_mat3x3_t r2;
  ksl_mat3x3_setFromEulerAngles(&r2, KSL_AXIS_XYZ, &angles);
  ksl_mat3x3_t r3;
  ksl_product_drinvdr(&r1, &r2, &r3);

  ksl_mat3x3_t r4 = ksl_mat3x3(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);

  for(int i = 0; i < 9; i++) {
    ck_assert_double_eq_tol(r3.as_array[i], r4.as_array[i], 1e-9);
  }
}
END_TEST

START_TEST(test_matrix_product_drinvdrf) {
  ksl_mat3x3f_t r1;
  ksl_mat3x3f_setIdentity(&r1);
  ksl_vec3f_t angles = {{0.2, 0.3, 0.4}};
  ksl_mat3x3f_setFromEulerAngles(&r1, KSL_AXIS_XYZ, &angles);
  ksl_mat3x3f_t r2;
  ksl_mat3x3f_setFromEulerAngles(&r2, KSL_AXIS_XYZ, &angles);
  ksl_mat3x3f_t r3;
  ksl_product_drinvdrf(&r1, &r2, &r3);

  ksl_mat3x3f_t r4 = ksl_mat3x3f(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);

  for(int i = 0; i < 9; i++) {
    ck_assert_float_eq_tol(r3.as_array[i], r4.as_array[i], 1e-6);
  }
}
END_TEST

START_TEST(test_matrix_product_dv) {
  ksl_SE3_t d =
    ksl_SE3(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
            0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
            -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  ksl_vec3_t v1 = ksl_vec3(1.0, 2.0, 3.0);
  ksl_vec3_t v2;
  ksl_vec3_t v3 =
    ksl_vec3(2.0224326923807565, 3.6260200151342845, 6.211026362385358);
  ksl_product_dv(&d, &v1, &v2);
  for(int i = 0; i < 3; i++) {
    ck_assert_double_eq_tol(v2.at[i], v3.at[i], 1e-9);
  }
}
END_TEST

START_TEST(test_matrix_product_dvf) {
  ksl_SE3f_t d =
    ksl_SE3f(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
             0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
             -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  ksl_vec3f_t v1 = ksl_vec3f(1.0, 2.0, 3.0);
  ksl_vec3f_t v2;
  ksl_vec3f_t v3 =
    ksl_vec3f(2.0224326923807565, 3.6260200151342845, 6.211026362385358);
  ksl_product_dvf(&d, &v1, &v2);
  for(int i = 0; i < 3; i++) {
    ck_assert_float_eq_tol(v2.at[i], v3.at[i], 1e-6);
  }
}
END_TEST

START_TEST(test_matrix_product_dinvv) {
  ksl_SE3_t d =
    ksl_SE3(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
            0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
            -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  ksl_vec3_t v1 = ksl_vec3(2.0, 3.0, 4.0);
  ksl_vec3_t v2;
  ksl_vec3_t v3 =
    ksl_vec3(1.1262543746546154, 0.8035860837226143, 1.0420175092668518);
  ksl_product_dinvv(&d, &v1, &v2);
  for(int i = 0; i < 3; i++) {
    ck_assert_double_eq_tol(v2.at[i], v3.at[i], 1e-9);
  }
}
END_TEST

START_TEST(test_matrix_product_dinvvf) {
  ksl_SE3f_t d =
    ksl_SE3f(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
             0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
             -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  ksl_vec3f_t v1 = ksl_vec3f(2.0, 3.0, 4.0);
  ksl_vec3f_t v2;
  ksl_vec3f_t v3 =
    ksl_vec3f(1.1262543746546154, 0.8035860837226143, 1.0420175092668518);
  ksl_product_dinvvf(&d, &v1, &v2);
  for(int i = 0; i < 3; i++) {
    ck_assert_float_eq_tol(v2.at[i], v3.at[i], 1e-6);
  }
}
END_TEST

START_TEST(test_matrix_product_ddrx) {
  ksl_SE3_t d =
    ksl_SE3(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
            0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
            -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  double dc[2];
  ksl_dc(0.5, dc);
  ksl_SE3_t d2;
  ksl_product_ddrx(&d, dc, &d2);
  ksl_SE3_t d3 =
    ksl_SE3(0.879923176281257, -0.1848032027151301, 0.4377019306666745, 1.,
            0.4357321314618704, 0.6811374365560571, -0.588378536431725, 2.,
            -0.1894009330885121, 0.7084487058270867, 0.6798733100785226, 3.);
  for(int i = 0; i < 12; i++) {
    ck_assert_double_eq_tol(d2.as_array[i], d3.as_array[i], 1e-9);
  }
}
END_TEST

START_TEST(test_matrix_product_ddrxf) {
  ksl_SE3f_t d =
    ksl_SE3f(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
             0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
             -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  float dc[2];
  ksl_dcf(0.5, dc);
  ksl_SE3f_t d2;
  ksl_product_ddrxf(&d, dc, &d2);
  ksl_SE3f_t d3 =
    ksl_SE3f(0.879923176281257, -0.1848032027151301, 0.4377019306666745, 1.,
             0.4357321314618704, 0.6811374365560571, -0.588378536431725, 2.,
             -0.1894009330885121, 0.7084487058270867, 0.6798733100785226, 3.);
  for(int i = 0; i < 12; i++) {
    ck_assert_float_eq_tol(d2.as_array[i], d3.as_array[i], 1e-6);
  }
}
END_TEST

START_TEST(test_matrix_product_ddrxinv) {
  ksl_SE3_t d =
    ksl_SE3(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
            0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
            -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  double dc[2];
  ksl_dc(0.5, dc);
  ksl_SE3_t d2;
  ksl_product_ddrxinv(&d, dc, &d2);
  ksl_SE3_t d3 =
    ksl_SE3(0.879923176281257, -0.4681630712092061, 0.080984829437787, 1.,
            0.4357321314618704, 0.8631235940753836, 0.2552551095709691, 2.,
            -0.1894009330885121, -0.1893171944287045, 0.963476147311829, 3.);
  for(int i = 0; i < 12; i++) {
    ck_assert_double_eq_tol(d2.as_array[i], d3.as_array[i], 1e-9);
  }
}
END_TEST

START_TEST(test_matrix_product_ddrxinvf) {
  ksl_SE3f_t d =
    ksl_SE3f(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
             0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
             -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  float dc[2];
  ksl_dcf(0.5, dc);
  ksl_SE3f_t d2;
  ksl_product_ddrxinvf(&d, dc, &d2);
  ksl_SE3f_t d3 =
    ksl_SE3f(0.879923176281257, -0.4681630712092061, 0.080984829437787, 1.,
             0.4357321314618704, 0.8631235940753836, 0.2552551095709691, 2.,
             -0.1894009330885121, -0.1893171944287045, 0.963476147311829, 3.);
  for(int i = 0; i < 12; i++) {
    ck_assert_float_eq_tol(d2.as_array[i], d3.as_array[i], 1e-6);
  }
}
END_TEST

START_TEST(test_matrix_product_ddry) {
  ksl_SE3_t d =
    ksl_SE3(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
            0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
            -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  double dc[2];
  ksl_dc(0.5, dc);
  ksl_SE3_t d2;
  ksl_product_ddry(&d, dc, &d2);
  ksl_SE3_t d3 =
    ksl_SE3(0.6305253010605816, -0.3720255519422596, 0.6812010227711934, 1.,
            0.4733839989859243, 0.8798380333042382, 0.0423393983828867, 2.,
            -0.6150979062121391, 0.2957736023606357, 0.7308710843370773, 3);
  for(int i = 0; i < 12; i++) {
    ck_assert_double_eq_tol(d2.as_array[i], d3.as_array[i], 1e-9);
  }
}
END_TEST

START_TEST(test_matrix_product_ddryf) {
  ksl_SE3f_t d =
    ksl_SE3f(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
             0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
             -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  float dc[2];
  ksl_dcf(0.5, dc);
  ksl_SE3f_t d2;
  ksl_product_ddryf(&d, dc, &d2);
  ksl_SE3f_t d3 =
    ksl_SE3f(0.6305253010605816, -0.3720255519422596, 0.6812010227711934, 1.,
             0.4733839989859243, 0.8798380333042382, 0.0423393983828867, 2.,
             -0.6150979062121391, 0.2957736023606357, 0.7308710843370773, 3);
  for(int i = 0; i < 12; i++) {
    ck_assert_float_eq_tol(d2.as_array[i], d3.as_array[i], 1e-6);
  }
}
END_TEST

START_TEST(test_matrix_product_ddryinv) {
  ksl_SE3_t d =
    ksl_SE3(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
            0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
            -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  double dc[2];
  ksl_dc(0.5, dc);
  ksl_SE3_t d2;
  ksl_product_ddryinv(&d, dc, &d2);
  ksl_SE3_t d3 =
    ksl_SE3(0.9138851695546576, -0.3720255519422596, -0.162514262666732, 1.,
            0.2913978414665975, 0.8798380333042382, -0.3754628252436425, 2.,
            0.2826679940436521, 0.2957736023606357, 0.9124783730532743, 3.);
  for(int i = 0; i < 12; i++) {
    ck_assert_double_eq_tol(d2.as_array[i], d3.as_array[i], 1e-9);
  }
}
END_TEST

START_TEST(test_matrix_product_ddryinvf) {
  ksl_SE3f_t d =
    ksl_SE3f(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
             0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
             -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  float dc[2];
  ksl_dcf(0.5, dc);
  ksl_SE3f_t d2;
  ksl_product_ddryinvf(&d, dc, &d2);
  ksl_SE3f_t d3 =
    ksl_SE3f(0.9138851695546576, -0.3720255519422596, -0.162514262666732, 1.,
             0.2913978414665975, 0.8798380333042382, -0.3754628252436425, 2.,
             0.2826679940436521, 0.2957736023606357, 0.9124783730532743, 3.);
  for(int i = 0; i < 12; i++) {
    ck_assert_float_eq_tol(d2.as_array[i], d3.as_array[i], 1e-6);
  }
}
END_TEST

START_TEST(test_matrix_product_ddrz) {
  ksl_SE3_t d =
    ksl_SE3(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
            0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
            -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  double dc[2];
  ksl_dc(0.5, dc);
  ksl_SE3_t d2;
  ksl_product_ddrz(&d, dc, &d2);
  ksl_SE3_t d3 =
    ksl_SE3(0.5938466846931759, -0.7483407796811308, 0.2955202066613395, 1.,
            0.804207743227608, 0.5632294035024559, -0.1897960609786874, 2.,
            -0.0244135374675904, 0.3503694000572896, 0.9362933635841992, 3.);
  for(int i = 0; i < 12; i++) {
    ck_assert_double_eq_tol(d2.as_array[i], d3.as_array[i], 1e-9);
  }
}
END_TEST

START_TEST(test_matrix_product_ddrzf) {
  ksl_SE3f_t d =
    ksl_SE3f(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
             0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
             -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  float dc[2];
  ksl_dcf(0.5, dc);
  ksl_SE3f_t d2;
  ksl_product_ddrzf(&d, dc, &d2);
  ksl_SE3f_t d3 =
    ksl_SE3f(0.5938466846931759, -0.7483407796811308, 0.2955202066613395, 1.,
             0.804207743227608, 0.5632294035024559, -0.1897960609786874, 2.,
             -0.0244135374675904, 0.3503694000572896, 0.9362933635841992, 3.);
  for(int i = 0; i < 12; i++) {
    ck_assert_float_eq_tol(d2.as_array[i], d3.as_array[i], 1e-6);
  }
}
END_TEST

START_TEST(test_matrix_product_ddrzinv) {
  ksl_SE3_t d =
    ksl_SE3(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
            0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
            -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  double dc[2];
  ksl_dc(0.5, dc);
  ksl_SE3_t d2;
  ksl_product_ddrzinv(&d, dc, &d2);
  ksl_SE3_t d3 =
    ksl_SE3(0.9505637859220633, 0.0953745057567946, 0.2955202066613395, 1.,
            -0.0394259027750862, 0.981031627128985, -0.1897960609786874, 2.,
            -0.3080163747008967, 0.1687621113410926, 0.9362933635841992, 3.);
  for(int i = 0; i < 12; i++) {
    ck_assert_double_eq_tol(d2.as_array[i], d3.as_array[i], 1e-9);
  }
}
END_TEST

START_TEST(test_matrix_product_ddrzinvf) {
  ksl_SE3f_t d =
    ksl_SE3f(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
             0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
             -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  float dc[2];
  ksl_dcf(0.5, dc);
  ksl_SE3f_t d2;
  ksl_product_ddrzinvf(&d, dc, &d2);
  ksl_SE3f_t d3 =
    ksl_SE3f(0.9505637859220633, 0.0953745057567946, 0.2955202066613395, 1.,
             -0.0394259027750862, 0.981031627128985, -0.1897960609786874, 2.,
             -0.3080163747008967, 0.1687621113410926, 0.9362933635841992, 3.);
  for(int i = 0; i < 12; i++) {
    ck_assert_float_eq_tol(d2.as_array[i], d3.as_array[i], 1e-6);
  }
}
END_TEST

START_TEST(test_matrix_product_ddt) {
  ksl_SE3_t d =
    ksl_SE3(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
            0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
            -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  ksl_vec3_t t = ksl_vec3(1.0, 2.0, 3.0);
  ksl_SE3_t d2;
  ksl_product_ddt(&d, &t, &d2);
  ksl_SE3_t d3 =
    ksl_SE3(0.879923176281257, -0.3720255519422596, 0.2955202066613395,
            2.0224326923807565, 0.4357321314618704, 0.8798380333042382,
            -0.1897960609786874, 3.6260200151342845, -0.1894009330885121,
            0.2957736023606357, 0.9362933635841992, 6.211026362385357);
  for(int i = 0; i < 12; i++) {
    ck_assert_double_eq_tol(d2.as_array[i], d3.as_array[i], 1e-9);
  }
}
END_TEST

START_TEST(test_matrix_product_ddtf) {
  ksl_SE3f_t d =
    ksl_SE3f(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
             0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
             -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  ksl_vec3f_t t = ksl_vec3f(1.0, 2.0, 3.0);
  ksl_SE3f_t d2;
  ksl_product_ddtf(&d, &t, &d2);
  ksl_SE3f_t d3 =
    ksl_SE3f(0.879923176281257, -0.3720255519422596, 0.2955202066613395,
             2.0224326923807565, 0.4357321314618704, 0.8798380333042382,
             -0.1897960609786874, 3.6260200151342845, -0.1894009330885121,
             0.2957736023606357, 0.9362933635841992, 6.211026362385357);
  for(int i = 0; i < 12; i++) {
    ck_assert_float_eq_tol(d2.as_array[i], d3.as_array[i], 1e-6);
  }
}
END_TEST

START_TEST(test_matrix_product_ddtinv) {
  ksl_SE3_t d =
    ksl_SE3(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
            0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
            -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  ksl_vec3_t t = ksl_vec3(1.0, 2.0, 3.0);
  ksl_SE3_t d2;
  ksl_product_ddtinv(&d, &t, &d2);
  ksl_SE3_t d3 =
    ksl_SE3(0.879923176281257, -0.3720255519422596, 0.2955202066613395,
            -0.0224326923807563, 0.4357321314618704, 0.8798380333042382,
            -0.1897960609786874, 0.3739799848657155, -0.1894009330885121,
            0.2957736023606357, 0.9362933635841992, -0.2110263623853568);
  for(int i = 0; i < 12; i++) {
    ck_assert_double_eq_tol(d2.as_array[i], d3.as_array[i], 1e-9);
  }
}
END_TEST

START_TEST(test_matrix_product_ddtinvf) {
  ksl_SE3f_t d =
    ksl_SE3f(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
             0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
             -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  ksl_vec3f_t t = ksl_vec3f(1.0, 2.0, 3.0);
  ksl_SE3f_t d2;
  ksl_product_ddtinvf(&d, &t, &d2);
  ksl_SE3f_t d3 =
    ksl_SE3f(0.879923176281257, -0.3720255519422596, 0.2955202066613395,
             -0.0224326923807563, 0.4357321314618704, 0.8798380333042382,
             -0.1897960609786874, 0.3739799848657155, -0.1894009330885121,
             0.2957736023606357, 0.9362933635841992, -0.2110263623853568);
  for(int i = 0; i < 12; i++) {
    ck_assert_float_eq_tol(d2.as_array[i], d3.as_array[i], 1e-6);
  }
}
END_TEST

START_TEST(test_matrix_product_ddtx) {
  ksl_SE3_t d =
    ksl_SE3(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
            0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
            -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  ksl_SE3_t d2;
  ksl_product_ddtx(&d, 2.0, &d2);
  ksl_SE3_t d3 =
    ksl_SE3(0.879923176281257, -0.3720255519422596, 0.2955202066613395,
            2.759846352562514, 0.4357321314618704, 0.8798380333042382,
            -0.1897960609786874, 2.871464262923741, -0.1894009330885121,
            0.2957736023606357, 0.9362933635841992, 2.621198133822976);
  for(int i = 0; i < 12; i++) {
    ck_assert_double_eq_tol(d2.as_array[i], d3.as_array[i], 1e-9);
  }
}
END_TEST

START_TEST(test_matrix_product_ddtxf) {
  ksl_SE3f_t d =
    ksl_SE3f(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
             0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
             -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  ksl_SE3f_t d2;
  ksl_product_ddtxf(&d, 2.0, &d2);
  ksl_SE3f_t d3 =
    ksl_SE3f(0.879923176281257, -0.3720255519422596, 0.2955202066613395,
             2.759846352562514, 0.4357321314618704, 0.8798380333042382,
             -0.1897960609786874, 2.871464262923741, -0.1894009330885121,
             0.2957736023606357, 0.9362933635841992, 2.621198133822976);
  for(int i = 0; i < 12; i++) {
    ck_assert_float_eq_tol(d2.as_array[i], d3.as_array[i], 1e-6);
  }
}
END_TEST

START_TEST(test_matrix_product_ddtxinv) {
  ksl_SE3_t d =
    ksl_SE3(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
            0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
            -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  ksl_SE3_t d2;
  ksl_product_ddtxinv(&d, 2.0, &d2);
  ksl_SE3_t d3 =
    ksl_SE3(0.879923176281257, -0.3720255519422596, 0.2955202066613395,
            -0.7598463525625141, 0.4357321314618704, 0.8798380333042382,
            -0.1897960609786874, 1.1285357370762592, -0.1894009330885121,
            0.2957736023606357, 0.9362933635841992, 3.378801866177024);
  for(int i = 0; i < 12; i++) {
    ck_assert_double_eq_tol(d2.as_array[i], d3.as_array[i], 1e-9);
  }
}
END_TEST

START_TEST(test_matrix_product_ddtxinvf) {
  ksl_SE3f_t d =
    ksl_SE3f(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
             0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
             -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  ksl_SE3f_t d2;
  ksl_product_ddtxinvf(&d, 2.0, &d2);
  ksl_SE3f_t d3 =
    ksl_SE3f(0.879923176281257, -0.3720255519422596, 0.2955202066613395,
             -0.7598463525625141, 0.4357321314618704, 0.8798380333042382,
             -0.1897960609786874, 1.1285357370762592, -0.1894009330885121,
             0.2957736023606357, 0.9362933635841992, 3.378801866177024);
  for(int i = 0; i < 12; i++) {
    ck_assert_float_eq_tol(d2.as_array[i], d3.as_array[i], 1e-6);
  }
}
END_TEST

START_TEST(test_matrix_product_ddty) {
  ksl_SE3_t d =
    ksl_SE3(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
            0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
            -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  ksl_SE3_t d2;
  ksl_product_ddty(&d, 2.0, &d2);
  ksl_SE3_t d3 =
    ksl_SE3(0.879923176281257, -0.3720255519422596, 0.2955202066613395,
            0.2559488961154808, 0.4357321314618704, 0.8798380333042382,
            -0.1897960609786874, 3.7596760666084763, -0.1894009330885121,
            0.2957736023606357, 0.9362933635841992, 3.5915472047212713);
  for(int i = 0; i < 12; i++) {
    ck_assert_double_eq_tol(d2.as_array[i], d3.as_array[i], 1e-9);
  }
}
END_TEST

START_TEST(test_matrix_product_ddtyf) {
  ksl_SE3f_t d =
    ksl_SE3f(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
             0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
             -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  ksl_SE3f_t d2;
  ksl_product_ddtyf(&d, 2.0, &d2);
  ksl_SE3f_t d3 =
    ksl_SE3f(0.879923176281257, -0.3720255519422596, 0.2955202066613395,
             0.2559488961154808, 0.4357321314618704, 0.8798380333042382,
             -0.1897960609786874, 3.7596760666084763, -0.1894009330885121,
             0.2957736023606357, 0.9362933635841992, 3.5915472047212713);
  for(int i = 0; i < 12; i++) {
    ck_assert_float_eq_tol(d2.as_array[i], d3.as_array[i], 1e-6);
  }
}
END_TEST

START_TEST(test_matrix_product_ddtyinv) {
  ksl_SE3_t d =
    ksl_SE3(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
            0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
            -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  ksl_SE3_t d2;
  ksl_product_ddtyinv(&d, 2.0, &d2);
  ksl_SE3_t d3 =
    ksl_SE3(0.879923176281257, -0.3720255519422596, 0.2955202066613395,
            1.7440511038845192, 0.4357321314618704, 0.8798380333042382,
            -0.1897960609786874, 0.2403239333915237, -0.1894009330885121,
            0.2957736023606357, 0.9362933635841992, 2.4084527952787287);
  for(int i = 0; i < 12; i++) {
    ck_assert_double_eq_tol(d2.as_array[i], d3.as_array[i], 1e-9);
  }
}
END_TEST

START_TEST(test_matrix_product_ddtyinvf) {
  ksl_SE3f_t d =
    ksl_SE3f(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
             0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
             -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  ksl_SE3f_t d2;
  ksl_product_ddtyinvf(&d, 2.0, &d2);
  ksl_SE3f_t d3 =
    ksl_SE3f(0.879923176281257, -0.3720255519422596, 0.2955202066613395,
             1.7440511038845192, 0.4357321314618704, 0.8798380333042382,
             -0.1897960609786874, 0.2403239333915237, -0.1894009330885121,
             0.2957736023606357, 0.9362933635841992, 2.4084527952787287);
  for(int i = 0; i < 12; i++) {
    ck_assert_float_eq_tol(d2.as_array[i], d3.as_array[i], 1e-6);
  }
}
END_TEST

START_TEST(test_matrix_product_ddtz) {
  ksl_SE3_t d =
    ksl_SE3(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
            0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
            -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  ksl_SE3_t d2;
  ksl_product_ddtz(&d, 2.0, &d2);
  ksl_SE3_t d3 =
    ksl_SE3(0.879923176281257, -0.3720255519422596, 0.2955202066613395,
            1.591040413322679, 0.4357321314618704, 0.8798380333042382,
            -0.1897960609786874, 1.6204078780426252, -0.1894009330885121,
            0.2957736023606357, 0.9362933635841992, 4.8725867271683985);
  for(int i = 0; i < 12; i++) {
    ck_assert_double_eq_tol(d2.as_array[i], d3.as_array[i], 1e-9);
  }
}
END_TEST

START_TEST(test_matrix_product_ddtzf) {
  ksl_SE3f_t d =
    ksl_SE3f(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
             0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
             -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  ksl_SE3f_t d2;
  ksl_product_ddtzf(&d, 2.0, &d2);
  ksl_SE3f_t d3 =
    ksl_SE3f(0.879923176281257, -0.3720255519422596, 0.2955202066613395,
             1.591040413322679, 0.4357321314618704, 0.8798380333042382,
             -0.1897960609786874, 1.6204078780426252, -0.1894009330885121,
             0.2957736023606357, 0.9362933635841992, 4.8725867271683985);
  for(int i = 0; i < 12; i++) {
    ck_assert_float_eq_tol(d2.as_array[i], d3.as_array[i], 1e-6);
  }
}
END_TEST

START_TEST(test_matrix_product_ddtzinv) {
  ksl_SE3_t d =
    ksl_SE3(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
            0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
            -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  ksl_SE3_t d2;
  ksl_product_ddtzinv(&d, 2.0, &d2);
  ksl_SE3_t d3 =
    ksl_SE3(0.879923176281257, -0.3720255519422596, 0.2955202066613395,
            0.408959586677321, 0.4357321314618704, 0.8798380333042382,
            -0.1897960609786874, 2.3795921219573746, -0.1894009330885121,
            0.2957736023606357, 0.9362933635841992, 1.1274132728316015);
  for(int i = 0; i < 12; i++) {
    ck_assert_double_eq_tol(d2.as_array[i], d3.as_array[i], 1e-9);
  }
}
END_TEST

START_TEST(test_matrix_product_ddtzinvf) {
  ksl_SE3f_t d =
    ksl_SE3f(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
             0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
             -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  ksl_SE3f_t d2;
  ksl_product_ddtzinvf(&d, 2.0, &d2);
  ksl_SE3f_t d3 =
    ksl_SE3f(0.879923176281257, -0.3720255519422596, 0.2955202066613395,
             0.408959586677321, 0.4357321314618704, 0.8798380333042382,
             -0.1897960609786874, 2.3795921219573746, -0.1894009330885121,
             0.2957736023606357, 0.9362933635841992, 1.1274132728316015);
  for(int i = 0; i < 12; i++) {
    ck_assert_float_eq_tol(d2.as_array[i], d3.as_array[i], 1e-6);
  }
}
END_TEST

START_TEST(test_matrix_product_ddr) {
  ksl_SE3_t d =
    ksl_SE3(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
            0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
            -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  ksl_mat3x3_t r = d.R;
  ksl_SE3_t d2;
  ksl_product_ddr(&d, &r, &d2);
  ksl_SE3_t d3 =
    ksl_SE3(0.556189506562649, -0.5672690591880384, 0.6073376715448455, 1.,
            0.8027320537624947, 0.5558748134730649, -0.2159269358105487, 2.,
            -0.2151150451545508, 0.6076257122885793, 0.7645367951341207, 3.);
  for(int i = 0; i < 12; i++) {
    ck_assert_double_eq_tol(d2.as_array[i], d3.as_array[i], 1e-9);
  }
}
END_TEST

START_TEST(test_matrix_product_ddrf) {
  ksl_SE3f_t d =
    ksl_SE3f(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
             0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
             -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  ksl_mat3x3f_t r = d.R;
  ksl_SE3f_t d2;
  ksl_product_ddrf(&d, &r, &d2);
  ksl_SE3f_t d3 =
    ksl_SE3f(0.556189506562649, -0.5672690591880384, 0.6073376715448455, 1.,
             0.8027320537624947, 0.5558748134730649, -0.2159269358105487, 2.,
             -0.2151150451545508, 0.6076257122885793, 0.7645367951341207, 3.);
  for(int i = 0; i < 12; i++) {
    ck_assert_float_eq_tol(d2.as_array[i], d3.as_array[i], 1e-6);
  }
}
END_TEST

START_TEST(test_matrix_product_ddrinv) {
  ksl_SE3_t d =
    ksl_SE3(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
            0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
            -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  ksl_mat3x3_t r = d.R;
  ksl_SE3_t d2;
  ksl_product_ddrinv(&d, &r, &d2);
  ksl_SE3_t d3 =
    ksl_SE3(1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 2.0, 0.0, 0.0, 1.0, 3.0);
  for(int i = 0; i < 12; i++) {
    ck_assert_double_eq_tol(d2.as_array[i], d3.as_array[i], 1e-9);
  }
}
END_TEST

START_TEST(test_matrix_product_ddrinvf) {
  ksl_SE3f_t d =
    ksl_SE3f(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
             0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
             -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  ksl_mat3x3f_t r = d.R;
  ksl_SE3f_t d2;
  ksl_product_ddrinvf(&d, &r, &d2);
  ksl_SE3f_t d3 =
    ksl_SE3f(1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 2.0, 0.0, 0.0, 1.0, 3.0);
  for(int i = 0; i < 12; i++) {
    ck_assert_float_eq_tol(d2.as_array[i], d3.as_array[i], 1e-6);
  }
}
END_TEST

START_TEST(test_matrix_product_dd) {
  ksl_SE3_t d1 =
    ksl_SE3(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
            0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
            -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  ksl_SE3_t d2 = d1;
  ksl_SE3_t d3;
  ksl_product_dd(&d1, &d2, &d3);
  ksl_SE3_t d4 =
    ksl_SE3(0.556189506562649, -0.5672690591880383, 0.6073376715448456,
            2.0224326923807565, 0.8027320537624947, 0.5558748134730649,
            -0.2159269358105488, 3.6260200151342845, -0.2151150451545507,
            0.6076257122885793, 0.7645367951341207, 6.211026362385358);

  for(int i = 0; i < 9; i++) {
    ck_assert_double_eq_tol(d3.as_array[i], d4.as_array[i], 1e-9);
  }
}
END_TEST

START_TEST(test_matrix_product_ddf) {
  ksl_SE3f_t d1 =
    ksl_SE3f(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
             0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
             -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  ksl_SE3f_t d2 = d1;
  ksl_SE3f_t d3;
  ksl_product_ddf(&d1, &d2, &d3);
  ksl_SE3f_t d4 =
    ksl_SE3f(0.556189506562649, -0.5672690591880383, 0.6073376715448456,
             2.0224326923807565, 0.8027320537624947, 0.5558748134730649,
             -0.2159269358105488, 3.6260200151342845, -0.2151150451545507,
             0.6076257122885793, 0.7645367951341207, 6.211026362385358);

  for(int i = 0; i < 9; i++) {
    ck_assert_float_eq_tol(d3.as_array[i], d4.as_array[i], 1e-6);
  }
}
END_TEST

START_TEST(test_matrix_product_ddinv) {
  ksl_SE3_t d1 =
    ksl_SE3(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
            0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
            -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  ksl_SE3_t d2 = d1;
  ksl_SE3_t d3;
  ksl_product_ddinv(&d1, &d2, &d3);
  ksl_SE3_t d4;
  ksl_SE3_setIdentity(&d4);

  for(int i = 0; i < 9; i++) {
    ck_assert_double_eq_tol(d3.as_array[i], d4.as_array[i], 1e-9);
  }
}
END_TEST

START_TEST(test_matrix_product_ddinvf) {
  ksl_SE3f_t d1 =
    ksl_SE3f(0.879923176281257, -0.3720255519422596, 0.2955202066613395, 1.,
             0.4357321314618704, 0.8798380333042382, -0.1897960609786874, 2.,
             -0.1894009330885121, 0.2957736023606357, 0.9362933635841992, 3.);
  ksl_SE3f_t d2 = d1;
  ksl_SE3f_t d3;
  ksl_product_ddinvf(&d1, &d2, &d3);
  ksl_SE3f_t d4;
  ksl_SE3f_setIdentity(&d4);
  for(int i = 0; i < 9; i++) {
    ck_assert_float_eq_tol(d3.as_array[i], d4.as_array[i], 1e-6);
  }
}
END_TEST

Suite* matrix_suite(void) {
  Suite* s = suite_create("matrix");
  TCase* tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_matrix_SE3);
  tcase_add_test(tc_core, test_matrix_SE3f);
  tcase_add_test(tc_core, test_matrix_mat3x3);
  tcase_add_test(tc_core, test_matrix_mat3x3f);
  tcase_add_test(tc_core, test_matrix_mat4x4);
  tcase_add_test(tc_core, test_matrix_mat4x4f);
  tcase_add_test(tc_core, test_matrix_SE3_alloc);
  tcase_add_test(tc_core, test_matrix_SE3f_alloc);
  tcase_add_test(tc_core, test_matrix_mat3x3_alloc);
  tcase_add_test(tc_core, test_matrix_mat3x3f_alloc);
  tcase_add_test(tc_core, test_matrix_mat4x4_alloc);
  tcase_add_test(tc_core, test_matrix_mat4x4f_alloc);
  tcase_add_test(tc_core, test_matrix_SE3toMat4x4);
  tcase_add_test(tc_core, test_matrix_SE3ftoMat4x4f);
  tcase_add_test(tc_core, test_matrix_SE3toMat4x4f);
  tcase_add_test(tc_core, test_matrix_dc);
  tcase_add_test(tc_core, test_matrix_SE3_setIdentity);
  tcase_add_test(tc_core, test_matrix_SE3f_setIdentity);
  tcase_add_test(tc_core, test_matrix_mat3x3_setIdentity);
  tcase_add_test(tc_core, test_matrix_mat3x3f_setIdentity);
  tcase_add_test(tc_core, test_matrix_mat4x4_setIdentity);
  tcase_add_test(tc_core, test_matrix_mat4x4f_setIdentity);
  tcase_add_test(tc_core, test_matrix_SE3_setAndGet);
  tcase_add_test(tc_core, test_matrix_SE3f_setAndGet);
  tcase_add_test(tc_core, test_matrix_mat3x3_setAndGet);
  tcase_add_test(tc_core, test_matrix_mat3x3f_setAndGet);
  tcase_add_test(tc_core, test_matrix_mat4x4_setAndGet);
  tcase_add_test(tc_core, test_matrix_mat4x4f_setAndGet);
  tcase_add_test(tc_core, test_matrix_mat3x3_setFromVectors);
  tcase_add_test(tc_core, test_matrix_mat3x3f_setFromVectors);
  tcase_add_test(tc_core, test_matrix_SE3_getTranslation);
  tcase_add_test(tc_core, test_matrix_SE3f_getTranslation);
  tcase_add_test(tc_core, test_matrix_mat3x3_copy);
  tcase_add_test(tc_core, test_matrix_mat3x3f_copy);
  tcase_add_test(tc_core, test_matrix_mat3x3_invert);
  tcase_add_test(tc_core, test_matrix_mat3x3f_invert);
  tcase_add_test(tc_core, test_matrix_mat3x3_inverted);
  tcase_add_test(tc_core, test_matrix_mat3x3f_inverted);
  tcase_add_test(tc_core, test_matrix_mat3x3_transpose);
  tcase_add_test(tc_core, test_matrix_mat3x3f_transpose);
  tcase_add_test(tc_core, test_matrix_mat3x3_transposed);
  tcase_add_test(tc_core, test_matrix_mat3x3f_transposed);
  tcase_add_test(tc_core, test_matrix_SE3_copy);
  tcase_add_test(tc_core, test_matrix_SE3f_copy);
  tcase_add_test(tc_core, test_matrix_SE3_inverted);
  tcase_add_test(tc_core, test_matrix_SE3f_inverted);
  tcase_add_test(tc_core, test_matrix_SE3_invert);
  tcase_add_test(tc_core, test_matrix_SE3f_invert);
  tcase_add_test(tc_core, test_matrix_mat3x3_getEulerAngles);
  tcase_add_test(tc_core, test_matrix_mat3x3_setFromEulerAngles);
  tcase_add_test(tc_core, test_matrix_mat4x4_getTranslation);
  tcase_add_test(tc_core, test_matrix_mat4x4f_getTranslation);
  tcase_add_test(tc_core, test_matrix_mat3x3_determinant);
  tcase_add_test(tc_core, test_matrix_mat3x3f_determinant);
  tcase_add_test(tc_core, test_matrix_mat3x3_getAxisAngle);
  tcase_add_test(tc_core, test_matrix_mat3x3f_getAxisAngle);
  tcase_add_test(tc_core, test_matrix_product_drv);
  tcase_add_test(tc_core, test_matrix_product_drvf);
  tcase_add_test(tc_core, test_matrix_product_drvinv);
  tcase_add_test(tc_core, test_matrix_product_drvinvf);
  tcase_add_test(tc_core, test_matrix_product_drinvv);
  tcase_add_test(tc_core, test_matrix_product_drinvvf);
  tcase_add_test(tc_core, test_matrix_product_drinvvinv);
  tcase_add_test(tc_core, test_matrix_product_drinvvinvf);
  tcase_add_test(tc_core, test_matrix_product_drvtx);
  tcase_add_test(tc_core, test_matrix_product_drvtxf);
  tcase_add_test(tc_core, test_matrix_product_drvtxinv);
  tcase_add_test(tc_core, test_matrix_product_drvtxinvf);
  tcase_add_test(tc_core, test_matrix_product_drvty);
  tcase_add_test(tc_core, test_matrix_product_drvtyf);
  tcase_add_test(tc_core, test_matrix_product_drvtyinv);
  tcase_add_test(tc_core, test_matrix_product_drvtyinvf);
  tcase_add_test(tc_core, test_matrix_product_drvtz);
  tcase_add_test(tc_core, test_matrix_product_drvtzf);
  tcase_add_test(tc_core, test_matrix_product_drvtzinv);
  tcase_add_test(tc_core, test_matrix_product_drvtzinvf);
  tcase_add_test(tc_core, test_matrix_product_drdrx);
  tcase_add_test(tc_core, test_matrix_product_drdrxf);
  tcase_add_test(tc_core, test_matrix_product_drdrxinv);
  tcase_add_test(tc_core, test_matrix_product_drdrxinvf);
  tcase_add_test(tc_core, test_matrix_product_drdry);
  tcase_add_test(tc_core, test_matrix_product_drdryf);
  tcase_add_test(tc_core, test_matrix_product_drdryinv);
  tcase_add_test(tc_core, test_matrix_product_drdryinvf);
  tcase_add_test(tc_core, test_matrix_product_drdrz);
  tcase_add_test(tc_core, test_matrix_product_drdrzf);
  tcase_add_test(tc_core, test_matrix_product_drdrzinv);
  tcase_add_test(tc_core, test_matrix_product_drdrzinvf);
  tcase_add_test(tc_core, test_matrix_product_drdr);
  tcase_add_test(tc_core, test_matrix_product_drdrf);
  tcase_add_test(tc_core, test_matrix_product_drdrinv);
  tcase_add_test(tc_core, test_matrix_product_drdrinvf);
  tcase_add_test(tc_core, test_matrix_product_drinvdr);
  tcase_add_test(tc_core, test_matrix_product_drinvdrf);
  tcase_add_test(tc_core, test_matrix_product_dv);
  tcase_add_test(tc_core, test_matrix_product_dvf);
  tcase_add_test(tc_core, test_matrix_product_dinvv);
  tcase_add_test(tc_core, test_matrix_product_dinvvf);

  tcase_add_test(tc_core, test_matrix_product_ddrx);
  tcase_add_test(tc_core, test_matrix_product_ddrxf);
  tcase_add_test(tc_core, test_matrix_product_ddrxinv);
  tcase_add_test(tc_core, test_matrix_product_ddrxinvf);

  tcase_add_test(tc_core, test_matrix_product_ddry);
  tcase_add_test(tc_core, test_matrix_product_ddryf);
  tcase_add_test(tc_core, test_matrix_product_ddryinv);
  tcase_add_test(tc_core, test_matrix_product_ddryinvf);

  tcase_add_test(tc_core, test_matrix_product_ddrz);
  tcase_add_test(tc_core, test_matrix_product_ddrzf);
  tcase_add_test(tc_core, test_matrix_product_ddrzinv);
  tcase_add_test(tc_core, test_matrix_product_ddrzinvf);

  tcase_add_test(tc_core, test_matrix_product_dd);
  tcase_add_test(tc_core, test_matrix_product_ddf);
  tcase_add_test(tc_core, test_matrix_product_ddinv);
  tcase_add_test(tc_core, test_matrix_product_ddinvf);

  tcase_add_test(tc_core, test_matrix_product_ddt);
  tcase_add_test(tc_core, test_matrix_product_ddtf);
  tcase_add_test(tc_core, test_matrix_product_ddtinv);
  tcase_add_test(tc_core, test_matrix_product_ddtinvf);

  tcase_add_test(tc_core, test_matrix_product_ddtx);
  tcase_add_test(tc_core, test_matrix_product_ddtxf);
  tcase_add_test(tc_core, test_matrix_product_ddtxinv);
  tcase_add_test(tc_core, test_matrix_product_ddtxinvf);

  tcase_add_test(tc_core, test_matrix_product_ddty);
  tcase_add_test(tc_core, test_matrix_product_ddtyf);
  tcase_add_test(tc_core, test_matrix_product_ddtyinv);
  tcase_add_test(tc_core, test_matrix_product_ddtyinvf);

  tcase_add_test(tc_core, test_matrix_product_ddtz);
  tcase_add_test(tc_core, test_matrix_product_ddtzf);
  tcase_add_test(tc_core, test_matrix_product_ddtzinv);
  tcase_add_test(tc_core, test_matrix_product_ddtzinvf);

  tcase_add_test(tc_core, test_matrix_product_ddr);
  tcase_add_test(tc_core, test_matrix_product_ddrf);
  tcase_add_test(tc_core, test_matrix_product_ddrinv);
  tcase_add_test(tc_core, test_matrix_product_ddrinvf);

  suite_add_tcase(s, tc_core);
  return s;
}

int main(void) {
  int number_failed;
  Suite* s = matrix_suite();
  SRunner* sr = srunner_create(s);
  srunner_set_log(sr, "matrix_test.log");
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
