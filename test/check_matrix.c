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
      ck_assert_double_eq(D[1].as_array[j][i], k++);
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
      ck_assert_float_eq(D[1].as_array[j][i], k++);
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
      ck_assert_double_eq(D[1].as_array[j][i], k++);
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
      ck_assert_float_eq(D[1].as_array[j][i], k++);
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
      ck_assert_double_eq(D[1].as_array[j][i], k++);
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
      ck_assert_float_eq(D[1].as_array[j][i], k++);
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

START_TEST(test_matrix_SE3toMat4x4) {
  ksl_SE3_t d = {
    {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0}};
  ksl_mat4x4_t m;
  ksl_SE3_toMat4x4(&d, &m);
  for(int j = 0; j < 4; j++) {
    for(int i = 0; i < 3; i++) {
      ck_assert_double_eq(m.as_array[j][i], d.as_array[j][i]);
    }
    if(j != 3) {
      ck_assert_double_eq(m.as_array[j][3], 0.0);
    } else {
      ck_assert_double_eq(m.as_array[j][3], 1.0);
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
      ck_assert_float_eq(m.as_array[j][i], d.as_array[j][i]);
    }
    if(j != 3) {
      ck_assert_float_eq(m.as_array[j][3], 0.0);
    } else {
      ck_assert_float_eq(m.as_array[j][3], 1.0);
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
      ck_assert_float_eq(m.as_array[j][i], (float)d.as_array[j][i]);
    }
    if(j != 3) {
      ck_assert_float_eq(m.as_array[j][3], 0.0);
    } else {
      ck_assert_float_eq(m.as_array[j][3], 1.0);
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
        ck_assert_double_eq(d.as_array[j][i], 1.0);
      } else {
        ck_assert_double_eq(d.as_array[j][i], 0.0);
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
        ck_assert_float_eq(d.as_array[j][i], 1.0);
      } else {
        ck_assert_float_eq(d.as_array[j][i], 0.0);
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
        ck_assert_double_eq(r.as_array[j][i], 1.0);
      } else {
        ck_assert_double_eq(r.as_array[j][i], 0.0);
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
        ck_assert_float_eq(rf.as_array[j][i], 1.0);
      } else {
        ck_assert_float_eq(rf.as_array[j][i], 0.0);
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
        ck_assert_double_eq(m.as_array[j][i], 1.0);
      } else {
        ck_assert_double_eq(m.as_array[j][i], 0.0);
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
        ck_assert_float_eq(m.as_array[j][i], 1.0);
      } else {
        ck_assert_float_eq(m.as_array[j][i], 0.0);
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
      ck_assert_double_eq(m.as_array[j][i], v[j].at[i]);
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
      ck_assert_float_eq(m.as_array[j][i], v[j].at[i]);
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
    ck_assert_double_eq(r1.at[i], r2.at[i]);
  }
}
END_TEST

START_TEST(test_matrix_mat3x3f_copy) {
  ksl_mat3x3f_t r1 = {{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0}};
  ksl_mat3x3f_t r2;
  ksl_mat3x3f_copy(&r1, &r2);

  for(int i = 0; i < 9; i++) {
    ck_assert_float_eq(r1.at[i], r2.at[i]);
  }
}
END_TEST

START_TEST(test_matrix_mat3x3_invert) {
  ksl_mat3x3_t r1 = ksl_mat3x3(13.0, 8.0, 9.0, 3.0, 5.0, 1.0, 1.0, 0.5, 3.0);

  // FILE* f = fopen("matrix_inv.txt", "w");
  ksl_mat3x3_invert(&r1);

  // ksl_mat3x3_print(f, &r1);
  // fclose(f);

  ksl_mat3x3_t r2 =
    ksl_mat3x3(0.15591397849462368, -0.20967741935483872, -0.39784946236559143,
               -0.08602150537634409, 0.32258064516129037, 0.1505376344086022,
               -0.037634408602150546, 0.016129032258064523, 0.4408602150537635);

  for(int i = 0; i < 9; i++) {
    ck_assert_double_eq_tol(r1.at[i], r2.at[i], 1e-9);
  }
}
END_TEST

START_TEST(test_matrix_mat3x3f_invert) {
  ksl_mat3x3f_t r1 = ksl_mat3x3f(13.0, 8.0, 9.0, 3.0, 5.0, 1.0, 1.0, 0.5, 3.0);

  // FILE* f = fopen("matrix_inv.txt", "w");
  ksl_mat3x3f_invert(&r1);

  // ksl_mat3x3_print(f, &r1);
  // fclose(f);

  ksl_mat3x3f_t r2 = ksl_mat3x3f(
    0.15591397849462368, -0.20967741935483872, -0.39784946236559143,
    -0.08602150537634409, 0.32258064516129037, 0.1505376344086022,
    -0.037634408602150546, 0.016129032258064523, 0.4408602150537635);

  for(int i = 0; i < 9; i++) {
    ck_assert_float_eq_tol(r1.at[i], r2.at[i], 1e-6);
  }
}
END_TEST

START_TEST(test_matrix_mat3x3_inverted) {
  ksl_mat3x3_t r1 = ksl_mat3x3(13.0, 8.0, 9.0, 3.0, 5.0, 1.0, 1.0, 0.5, 3.0);
  ksl_mat3x3_t r2;
  ksl_mat3x3_inverted(&r1, &r2);
  ksl_mat3x3_invert(&r1);

  for(int i = 0; i < 9; i++) {
    ck_assert_double_eq(r1.at[i], r2.at[i]);
  }
}
END_TEST

START_TEST(test_matrix_mat3x3f_inverted) {
  ksl_mat3x3f_t r1 = ksl_mat3x3f(13.0, 8.0, 9.0, 3.0, 5.0, 1.0, 1.0, 0.5, 3.0);
  ksl_mat3x3f_t r2;
  ksl_mat3x3f_inverted(&r1, &r2);
  ksl_mat3x3f_invert(&r1);

  for(int i = 0; i < 9; i++) {
    ck_assert(fabs(r1.at[i] - r2.at[i]) < 1e-8);
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
      ck_assert_double_eq(r1.as_array[i][j], r2.as_array[j][i]);
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
      ck_assert_float_eq(r1.as_array[i][j], r2.as_array[j][i]);
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
      ck_assert_double_eq(r1.as_array[i][j], r2.as_array[j][i]);
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
      ck_assert_float_eq(r1.as_array[i][j], r2.as_array[j][i]);
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
    ck_assert_double_eq(d1.at[i], d2.at[i]);
  }
}
END_TEST

START_TEST(test_matrix_SE3f_copy) {
  ksl_SE3f_t d1 =
    ksl_SE3f(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0);
  ksl_SE3f_t d2;
  ksl_SE3f_copy(&d1, &d2);
  for(int i = 0; i < 12; i++) {
    ck_assert_float_eq(d1.at[i], d2.at[i]);
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
        ck_assert_double_eq_tol(1.0, d3.as_array[j][i], 1e-9);
      } else {
        ck_assert_double_eq_tol(0.0, d3.as_array[j][i], 1e-9);
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
        ck_assert_float_eq_tol(1.0, d3.as_array[j][i], 1e-6);
      } else {
        ck_assert_float_eq_tol(0.0, d3.as_array[j][i], 1e-6);
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
        ck_assert_double_eq_tol(1.0, d3.as_array[j][i], 1e-9);
      } else {
        ck_assert_double_eq_tol(0.0, d3.as_array[j][i], 1e-9);
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
        ck_assert(fabs(1.0 - d3.as_array[j][i]) < 1e-6);
      } else {
        ck_assert(fabs(d3.as_array[j][i]) < 1e-6);
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

    ksl_vec3_t angles_prev = {{0.21, 0.31, 0.41}};
    ksl_mat3x3_getEulerAngles(&r1, &angles_prev, axis);

    for(int i = 0; i < 3; i++) {
      ck_assert_double_eq_tol(angles_prev.at[i], angles.at[i], 1e-9);
    }
  }
}
END_TEST

//
// /*! @todo */
// inline void ksl_mat3x3_setFromEulerAngles(ksl_mat3x3_t*, const ksl_vec3_t*,
//                                           const ksl_axis_enum_t axisType);
//

// inline void ksl_mat4x4_getTranslation(const ksl_mat4x4_t* restrict Mi,
//                                       ksl_vec3_t* restrict to) {
//   memcpy(to, &Mi->v3, sizeof(ksl_vec3_t));
// }
//
// inline void ksl_mat4x4f_getTranslation(const ksl_mat4x4f_t* restrict Mi,
//                                        ksl_vec3f_t* to) {
//   memcpy(to, &Mi->v3, sizeof(ksl_vec3f_t));
// }
//
// inline double ksl_mat3x3_determinant(const ksl_mat3x3_t* restrict R) {
//   return (R->m00 * (R->m11 * R->m22 - R->m21 * R->m12) -
//           R->m10 * (R->m01 * R->m22 - R->m21 * R->m02) +
//           R->m20 * (R->m01 * R->m12 - R->m11 * R->m02));
// }
//
// inline float ksl_mat3x3f_determinant(const ksl_mat3x3f_t* restrict R) {
//   return (R->m00 * (R->m11 * R->m22 - R->m21 * R->m12) -
//           R->m10 * (R->m01 * R->m22 - R->m21 * R->m02) +
//           R->m20 * (R->m01 * R->m12 - R->m11 * R->m02));
// }
//
// /*!
// @brief get axis and angle from a rotation matrix
//
// if sin is close to 0, the axis of rotation is not well defined.
// */
// inline void ksl_mat3x3_getAxisAngle(const ksl_mat3x3_t* restrict r,
//                                     ksl_vec3_t* restrict axis,
//                                     double* restrict angle) {
//
//   *angle = acos(0.5 * (r->m00 + r->m11 + r->m22 - 1.0));
//   if(fabs(sin(*angle)) < 1e-9) {
//     /* if m22 == -1, return {1, 0, 0} */
//     if(fabs(r->m22 + 1) < 1e-9) {
//       axis->x = 1.0;
//       axis->y = 0.0;
//       axis->z = 0.0;
//       return;
//     } else {
//       axis->x = 0.0;
//       axis->y = 0.0;
//       axis->z = 1.0;
//       return;
//     }
//   }
//   /* u_tilde = (1 / 2 sin \theta) * (r - r^T) */
//   axis->x = r->m21 - r->m12;
//   axis->y = r->m02 - r->m20;
//   axis->z = r->m10 - r->m01;
//   ksl_vec3_scale(axis, 1 / (2 * sin(*angle)));
// }
//
// /* matrix vector operations */
// inline void ksl_product_drv(const ksl_mat3x3_t* restrict ri,
//                             const ksl_vec3_t* restrict vi,
//                             ksl_vec3_t* restrict vo) {
//   ksl_product_av(vi->x, &ri->v0, vo);
//   ksl_axpy_vv(vi->y, &ri->v1, vo);
//   ksl_axpy_vv(vi->z, &ri->v2, vo);
// }
//
// inline void ksl_product_drvf(const ksl_mat3x3f_t* restrict ri,
//                              const ksl_vec3f_t* restrict vi,
//                              ksl_vec3f_t* restrict vo) {
//   ksl_product_avf(vi->x, &ri->v0, vo);
//   ksl_axpy_vvf(vi->y, &ri->v1, vo);
//   ksl_axpy_vvf(vi->z, &ri->v2, vo);
// }
//
// inline void ksl_product_drvinv(const ksl_mat3x3_t* restrict ri,
//                                const ksl_vec3_t* restrict vi,
//                                ksl_vec3_t* restrict vo) {
//   ksl_product_av(-vi->x, &ri->v0, vo);
//   ksl_axpy_vv(-vi->y, &ri->v1, vo);
//   ksl_axpy_vv(-vi->z, &ri->v2, vo);
// }
//
// inline void ksl_product_drvinvf(const ksl_mat3x3f_t* restrict ri,
//                                 const ksl_vec3f_t* restrict vi,
//                                 ksl_vec3f_t* restrict vo) {
//   ksl_product_avf(-vi->x, &ri->v0, vo);
//   ksl_axpy_vvf(-vi->y, &ri->v1, vo);
//   ksl_axpy_vvf(-vi->z, &ri->v2, vo);
// }
//
// inline void ksl_product_drinvv(const ksl_mat3x3_t* restrict ri,
//                                const ksl_vec3_t* restrict vi,
//                                ksl_vec3_t* restrict vo) {
//   vo->x = ksl_dot_vv(&ri->v0, vi);
//   vo->y = ksl_dot_vv(&ri->v1, vi);
//   vo->z = ksl_dot_vv(&ri->v2, vi);
// }
//
// inline void ksl_product_drinvvf(const ksl_mat3x3f_t* restrict ri,
//                                 const ksl_vec3f_t* restrict vi,
//                                 ksl_vec3f_t* restrict vo) {
//   vo->x = ksl_dot_vvf(&ri->v0, vi);
//   vo->y = ksl_dot_vvf(&ri->v1, vi);
//   vo->z = ksl_dot_vvf(&ri->v2, vi);
// }
//
// inline void ksl_product_drinvvinv(const ksl_mat3x3_t* restrict ri,
//                                   const ksl_vec3_t* restrict vi,
//                                   ksl_vec3_t* restrict vo) {
//   vo->x = -ksl_dot_vv(&ri->v0, vi);
//   vo->y = -ksl_dot_vv(&ri->v1, vi);
//   vo->z = -ksl_dot_vv(&ri->v2, vi);
// }
//
// inline void ksl_product_drinvvinvf(const ksl_mat3x3f_t* restrict ri,
//                                    const ksl_vec3f_t* restrict vi,
//                                    ksl_vec3f_t* restrict vo) {
//   vo->x = -ksl_dot_vvf(&ri->v0, vi);
//   vo->y = -ksl_dot_vvf(&ri->v1, vi);
//   vo->z = -ksl_dot_vvf(&ri->v2, vi);
// }
//
// inline void ksl_product_drvtx(const ksl_mat3x3_t* restrict ri, const double
// tx,
//                               ksl_vec3_t* restrict vo) {
//   ksl_product_av(tx, &ri->v0, vo);
// }
//
// inline void ksl_product_drvtxf(const ksl_mat3x3f_t* restrict ri, const float
// tx,
//                                ksl_vec3f_t* restrict vo) {
//   ksl_product_avf(tx, &ri->v0, vo);
// }
//
// inline void ksl_product_drvtxinv(const ksl_mat3x3_t* restrict ri,
//                                  const double tx, ksl_vec3_t* restrict vo) {
//   ksl_product_av(-tx, &ri->v0, vo);
// }
//
// inline void ksl_product_drvtxinvf(const ksl_mat3x3f_t* restrict ri,
//                                   const float tx, ksl_vec3f_t* restrict vo) {
//   ksl_product_avf(-tx, &ri->v0, vo);
// }
//
// inline void ksl_product_drvty(const ksl_mat3x3_t* restrict ri, const double
// ty,
//                               ksl_vec3_t* restrict vo) {
//   ksl_product_av(ty, &ri->v1, vo);
// }
//
// inline void ksl_product_drvtyf(const ksl_mat3x3f_t* restrict ri, const float
// ty,
//                                ksl_vec3f_t* restrict vo) {
//   ksl_product_avf(ty, &ri->v1, vo);
// }
//
// inline void ksl_product_drvtyinv(const ksl_mat3x3_t* restrict ri,
//                                  const double ty, ksl_vec3_t* restrict vo) {
//   ksl_product_av(-ty, &ri->v1, vo);
// }
//
// inline void ksl_product_drvtyinvf(const ksl_mat3x3f_t* restrict ri,
//                                   const float ty, ksl_vec3f_t* restrict vo) {
//   ksl_product_avf(-ty, &ri->v1, vo);
// }
//
// inline void ksl_product_drvtz(const ksl_mat3x3_t* restrict ri, const double
// tz,
//                               ksl_vec3_t* restrict vo) {
//   ksl_product_av(tz, &ri->v2, vo);
// }
//
// inline void ksl_product_drvtzf(const ksl_mat3x3f_t* restrict ri, const float
// tz,
//                                ksl_vec3f_t* restrict vo) {
//   ksl_product_avf(tz, &ri->v2, vo);
// }
//
// inline void ksl_product_drvtzinv(const ksl_mat3x3_t* restrict ri,
//                                  const double tz, ksl_vec3_t* restrict vo) {
//   ksl_product_av(-tz, &ri->v2, vo);
// }
//
// inline void ksl_product_drvtzinvf(const ksl_mat3x3f_t* restrict ri,
//                                   const float tz, ksl_vec3f_t* restrict vo) {
//   ksl_product_avf(-tz, &ri->v2, vo);
// }
//
// /* matrix-matrix operations */
// inline void ksl_product_drdrx(const ksl_mat3x3_t* restrict ri,
//                               const double dc[2], ksl_mat3x3_t* restrict ro)
//                               {
//   ksl_vec3_copy(&ri->v0, &ro->v0);
//   ksl_product_av(dc[1], &ri->v1, &ro->v1);
//   ksl_axpy_vv(dc[0], &ri->v2, &ro->v1);
//   ksl_product_av(-dc[0], &ri->v1, &ro->v2);
//   ksl_axpy_vv(dc[1], &ri->v2, &ro->v2);
// }
//
// inline void ksl_product_drdrxf(const ksl_mat3x3f_t* restrict ri,
//                                const float dc[2], ksl_mat3x3f_t* restrict ro)
//                                {
//   ksl_vec3f_copy(&ri->v0, &ro->v0);
//   ksl_product_avf(dc[1], &ri->v1, &ro->v1);
//   ksl_axpy_vvf(dc[0], &ri->v2, &ro->v1);
//   ksl_product_avf(-dc[0], &ri->v1, &ro->v2);
//   ksl_axpy_vvf(dc[1], &ri->v2, &ro->v2);
// }
//
// inline void ksl_product_drdrxinv(const ksl_mat3x3_t* restrict ri,
//                                  const double dc[2],
//                                  ksl_mat3x3_t* restrict ro) {
//   ksl_vec3_copy(&ri->v0, &ro->v0);
//   ksl_product_av(dc[1], &ri->v1, &ro->v1);
//   ksl_axpy_vv(-dc[0], &ri->v2, &ro->v1);
//   ksl_product_av(dc[0], &ri->v1, &ro->v2);
//   ksl_axpy_vv(dc[1], &ri->v2, &ro->v2);
// }
//
// inline void ksl_product_drdrxinvf(const ksl_mat3x3f_t* restrict ri,
//                                   const float dc[2],
//                                   ksl_mat3x3f_t* restrict ro) {
//   ksl_vec3f_copy(&ri->v0, &ro->v0);
//   ksl_product_avf(dc[1], &ri->v1, &ro->v1);
//   ksl_axpy_vvf(-dc[0], &ri->v2, &ro->v1);
//   ksl_product_avf(dc[0], &ri->v1, &ro->v2);
//   ksl_axpy_vvf(dc[1], &ri->v2, &ro->v2);
// }
//
// inline void ksl_product_drdry(const ksl_mat3x3_t* restrict ri,
//                               const double dc[2], ksl_mat3x3_t* restrict ro)
//                               {
//   ksl_product_av(dc[1], &ri->v0, &ro->v0);
//   ksl_axpy_vv(-dc[0], &ri->v2, &ro->v0);
//   ksl_product_av(dc[1], &ri->v2, &ro->v2);
//   ksl_axpy_vv(dc[0], &ri->v0, &ro->v2);
//   ksl_vec3_copy(&ri->v1, &ro->v1);
// }
//
// inline void ksl_product_drdryf(const ksl_mat3x3f_t* restrict ri,
//                                const float dc[2], ksl_mat3x3f_t* restrict ro)
//                                {
//   ksl_product_avf(dc[1], &ri->v0, &ro->v0);
//   ksl_axpy_vvf(-dc[0], &ri->v2, &ro->v0);
//   ksl_product_avf(dc[1], &ri->v2, &ro->v2);
//   ksl_axpy_vvf(dc[0], &ri->v0, &ro->v2);
//   ksl_vec3f_copy(&ri->v1, &ro->v1);
// }
//
// inline void ksl_product_drdryinv(const ksl_mat3x3_t* restrict ri,
//                                  const double dc[2],
//                                  ksl_mat3x3_t* restrict ro) {
//   ksl_product_av(dc[1], &ri->v0, &ro->v0);
//   ksl_axpy_vv(dc[0], &ri->v2, &ro->v0);
//   ksl_product_av(dc[1], &ri->v2, &ro->v2);
//   ksl_axpy_vv(-dc[0], &ri->v0, &ro->v2);
//   ksl_vec3_copy(&ri->v1, &ro->v1);
// }
//
// inline void ksl_product_drdryinvf(const ksl_mat3x3f_t* restrict ri,
//                                   const float dc[2],
//                                   ksl_mat3x3f_t* restrict ro) {
//   ksl_product_avf(dc[1], &ri->v0, &ro->v0);
//   ksl_axpy_vvf(dc[0], &ri->v2, &ro->v0);
//   ksl_product_avf(dc[1], &ri->v2, &ro->v2);
//   ksl_axpy_vvf(-dc[0], &ri->v0, &ro->v2);
//   ksl_vec3f_copy(&ri->v1, &ro->v1);
// }
//
// inline void ksl_product_drdrz(const ksl_mat3x3_t* restrict ri,
//                               const double dc[2], ksl_mat3x3_t* restrict ro)
//                               {
//   ksl_product_av(dc[1], &ri->v0, &ro->v0);
//   ksl_axpy_vv(dc[0], &ri->v1, &ro->v0);
//   ksl_product_av(-dc[0], &ri->v0, &ro->v1);
//   ksl_axpy_vv(dc[1], &ri->v1, &ro->v1);
//   ksl_vec3_copy(&ri->v2, &ro->v2);
// }
//
// inline void ksl_product_drdrzf(const ksl_mat3x3f_t* restrict ri,
//                                const float dc[2], ksl_mat3x3f_t* restrict ro)
//                                {
//   ksl_product_avf(dc[1], &ri->v0, &ro->v0);
//   ksl_axpy_vvf(dc[0], &ri->v1, &ro->v0);
//   ksl_product_avf(-dc[0], &ri->v0, &ro->v1);
//   ksl_axpy_vvf(dc[1], &ri->v1, &ro->v1);
//   ksl_vec3f_copy(&ri->v2, &ro->v2);
// }
//
// inline void ksl_product_drdrzinv(const ksl_mat3x3_t* restrict ri,
//                                  const double dc[2],
//                                  ksl_mat3x3_t* restrict ro) {
//   ksl_product_av(dc[1], &ri->v0, &ro->v0);
//   ksl_axpy_vv(-dc[0], &ri->v1, &ro->v0);
//   ksl_product_av(dc[0], &ri->v0, &ro->v1);
//   ksl_axpy_vv(dc[1], &ri->v1, &ro->v1);
//   ksl_vec3_copy(&ri->v2, &ro->v2);
// }
//
// inline void ksl_product_drdrzinvf(const ksl_mat3x3f_t* restrict ri,
//                                   const float dc[2],
//                                   ksl_mat3x3f_t* restrict ro) {
//   ksl_product_avf(dc[1], &ri->v0, &ro->v0);
//   ksl_axpy_vvf(-dc[0], &ri->v1, &ro->v0);
//   ksl_product_avf(dc[0], &ri->v0, &ro->v1);
//   ksl_axpy_vvf(dc[1], &ri->v1, &ro->v1);
//   ksl_vec3f_copy(&ri->v2, &ro->v2);
// }
//
// inline void ksl_product_drdr(const ksl_mat3x3_t* restrict r1i,
//                              const ksl_mat3x3_t* restrict r2i,
//                              ksl_mat3x3_t* restrict ro) {
//   ro->m00 = r1i->m00 * r2i->m00 + r1i->m01 * r2i->m10 + r1i->m02 * r2i->m20;
//   ro->m01 = r1i->m00 * r2i->m01 + r1i->m01 * r2i->m11 + r1i->m02 * r2i->m21;
//   ro->m02 = r1i->m00 * r2i->m02 + r1i->m01 * r2i->m12 + r1i->m02 * r2i->m22;
//   ro->m10 = r1i->m10 * r2i->m00 + r1i->m11 * r2i->m10 + r1i->m12 * r2i->m20;
//   ro->m11 = r1i->m10 * r2i->m01 + r1i->m11 * r2i->m11 + r1i->m12 * r2i->m21;
//   ro->m12 = r1i->m10 * r2i->m02 + r1i->m11 * r2i->m12 + r1i->m12 * r2i->m22;
//   ro->m20 = r1i->m20 * r2i->m00 + r1i->m21 * r2i->m10 + r1i->m22 * r2i->m20;
//   ro->m21 = r1i->m20 * r2i->m01 + r1i->m21 * r2i->m11 + r1i->m22 * r2i->m21;
//   ro->m22 = r1i->m20 * r2i->m02 + r1i->m21 * r2i->m12 + r1i->m22 * r2i->m22;
// }
//
// inline void ksl_product_drdrf(const ksl_mat3x3f_t* restrict r1i,
//                               const ksl_mat3x3f_t* restrict r2i,
//                               ksl_mat3x3f_t* restrict ro) {
//   ro->m00 = r1i->m00 * r2i->m00 + r1i->m01 * r2i->m10 + r1i->m02 * r2i->m20;
//   ro->m01 = r1i->m00 * r2i->m01 + r1i->m01 * r2i->m11 + r1i->m02 * r2i->m21;
//   ro->m02 = r1i->m00 * r2i->m02 + r1i->m01 * r2i->m12 + r1i->m02 * r2i->m22;
//   ro->m10 = r1i->m10 * r2i->m00 + r1i->m11 * r2i->m10 + r1i->m12 * r2i->m20;
//   ro->m11 = r1i->m10 * r2i->m01 + r1i->m11 * r2i->m11 + r1i->m12 * r2i->m21;
//   ro->m12 = r1i->m10 * r2i->m02 + r1i->m11 * r2i->m12 + r1i->m12 * r2i->m22;
//   ro->m20 = r1i->m20 * r2i->m00 + r1i->m21 * r2i->m10 + r1i->m22 * r2i->m20;
//   ro->m21 = r1i->m20 * r2i->m01 + r1i->m21 * r2i->m11 + r1i->m22 * r2i->m21;
//   ro->m22 = r1i->m20 * r2i->m02 + r1i->m21 * r2i->m12 + r1i->m22 * r2i->m22;
// }
//
// inline void ksl_product_drdrinv(const ksl_mat3x3_t* restrict r1i,
//                                 const ksl_mat3x3_t* restrict r2i,
//                                 ksl_mat3x3_t* restrict ro) {
//   ro->m00 = ksl_dot_vv(&r1i->v0, &r2i->v0);
//   ro->m01 = ksl_dot_vv(&r1i->v0, &r2i->v1);
//   ro->m02 = ksl_dot_vv(&r1i->v0, &r2i->v2);
//   ro->m10 = ksl_dot_vv(&r1i->v1, &r2i->v0);
//   ro->m11 = ksl_dot_vv(&r1i->v1, &r2i->v1);
//   ro->m12 = ksl_dot_vv(&r1i->v1, &r2i->v2);
//   ro->m20 = ksl_dot_vv(&r1i->v2, &r2i->v0);
//   ro->m21 = ksl_dot_vv(&r1i->v2, &r2i->v1);
//   ro->m22 = ksl_dot_vv(&r1i->v2, &r2i->v2);
// }
//
// inline void ksl_product_drdrinvf(const ksl_mat3x3f_t* restrict r1i,
//                                  const ksl_mat3x3f_t* restrict r2i,
//                                  ksl_mat3x3f_t* restrict ro) {
//   ro->m00 = ksl_dot_vvf(&r1i->v0, &r2i->v0);
//   ro->m01 = ksl_dot_vvf(&r1i->v0, &r2i->v1);
//   ro->m02 = ksl_dot_vvf(&r1i->v0, &r2i->v2);
//   ro->m10 = ksl_dot_vvf(&r1i->v1, &r2i->v0);
//   ro->m11 = ksl_dot_vvf(&r1i->v1, &r2i->v1);
//   ro->m12 = ksl_dot_vvf(&r1i->v1, &r2i->v2);
//   ro->m20 = ksl_dot_vvf(&r1i->v2, &r2i->v0);
//   ro->m21 = ksl_dot_vvf(&r1i->v2, &r2i->v1);
//   ro->m22 = ksl_dot_vvf(&r1i->v2, &r2i->v2);
// }
//
// inline void ksl_product_drinvdr(const ksl_mat3x3_t* restrict r1i,
//                                 const ksl_mat3x3_t* restrict r2i,
//                                 ksl_mat3x3_t* restrict ro) {
//   ro->m00 = r1i->m00 * r2i->m00 + r1i->m10 * r2i->m10 + r1i->m20 * r2i->m20;
//   ro->m01 = r1i->m00 * r2i->m01 + r1i->m10 * r2i->m11 + r1i->m20 * r2i->m21;
//   ro->m02 = r1i->m00 * r2i->m02 + r1i->m10 * r2i->m12 + r1i->m20 * r2i->m22;
//   ro->m10 = r1i->m01 * r2i->m00 + r1i->m11 * r2i->m10 + r1i->m21 * r2i->m20;
//   ro->m11 = r1i->m01 * r2i->m01 + r1i->m11 * r2i->m11 + r1i->m21 * r2i->m21;
//   ro->m12 = r1i->m01 * r2i->m02 + r1i->m11 * r2i->m12 + r1i->m21 * r2i->m22;
//   ro->m20 = r1i->m02 * r2i->m00 + r1i->m12 * r2i->m10 + r1i->m22 * r2i->m20;
//   ro->m21 = r1i->m02 * r2i->m01 + r1i->m12 * r2i->m11 + r1i->m22 * r2i->m21;
//   ro->m22 = r1i->m02 * r2i->m02 + r1i->m12 * r2i->m12 + r1i->m22 * r2i->m22;
// }
//
// inline void ksl_product_drinvdrf(const ksl_mat3x3f_t* restrict r1i,
//                                  const ksl_mat3x3f_t* restrict r2i,
//                                  ksl_mat3x3f_t* restrict ro) {
//   ro->m00 = r1i->m00 * r2i->m00 + r1i->m10 * r2i->m10 + r1i->m20 * r2i->m20;
//   ro->m01 = r1i->m00 * r2i->m01 + r1i->m10 * r2i->m11 + r1i->m20 * r2i->m21;
//   ro->m02 = r1i->m00 * r2i->m02 + r1i->m10 * r2i->m12 + r1i->m20 * r2i->m22;
//   ro->m10 = r1i->m01 * r2i->m00 + r1i->m11 * r2i->m10 + r1i->m21 * r2i->m20;
//   ro->m11 = r1i->m01 * r2i->m01 + r1i->m11 * r2i->m11 + r1i->m21 * r2i->m21;
//   ro->m12 = r1i->m01 * r2i->m02 + r1i->m11 * r2i->m12 + r1i->m21 * r2i->m22;
//   ro->m20 = r1i->m02 * r2i->m00 + r1i->m12 * r2i->m10 + r1i->m22 * r2i->m20;
//   ro->m21 = r1i->m02 * r2i->m01 + r1i->m12 * r2i->m11 + r1i->m22 * r2i->m21;
//   ro->m22 = r1i->m02 * r2i->m02 + r1i->m12 * r2i->m12 + r1i->m22 * r2i->m22;
// }
//
// inline void ksl_product_dv(const ksl_SE3_t* restrict Di,
//                            const ksl_vec3_t* restrict vi,
//                            ksl_vec3_t* restrict vo) {
//   ksl_product_drv(&(Di->R), vi, vo);
//   ksl_xpy_vv(&Di->t, vo);
// }
//
// inline void ksl_product_dinvv(const ksl_SE3_t* restrict Di,
//                               const ksl_vec3_t* restrict vi,
//                               ksl_vec3_t* restrict vo) {
//   ksl_vec3_t temp;
//   ksl_product_drinvv(&Di->R, &Di->t, &temp); /* R^-1 * t -> temp*/
//   ksl_product_drinvv(&Di->R, vi, vo);        /* R^-1 * vi -> vo */
//   ksl_nxpy_vv(&temp, vo);                    /* vo -= temp */
// }
//
// inline void ksl_product_ddrx(const ksl_SE3_t* restrict Di, const double
// dc[2],
//                              ksl_SE3_t* restrict Do) {
//   ksl_product_drdrx(&Di->R, dc, &Do->R);
//   ksl_vec3_copy(&Di->t, &Do->t);
// }
//
// inline void ksl_product_ddrxf(const ksl_SE3f_t* restrict Di, const float
// dc[2],
//                               ksl_SE3f_t* restrict Do) {
//   ksl_product_drdrxf(&Di->R, dc, &Do->R);
//   ksl_vec3f_copy(&Di->t, &Do->t);
// }
//
// inline void ksl_product_ddrxinv(const ksl_SE3_t* restrict Di,
//                                 const double dc[2], ksl_SE3_t* restrict Do) {
//   ksl_product_drdrxinv(&Di->R, dc, &Do->R);
//   ksl_vec3_copy(&Di->t, &Do->t);
// }
//
// inline void ksl_product_ddrxinvf(const ksl_SE3f_t* restrict Di,
//                                  const float dc[2], ksl_SE3f_t* restrict Do)
//                                  {
//   ksl_product_drdrxinvf(&Di->R, dc, &Do->R);
//   ksl_vec3f_copy(&Di->t, &Do->t);
// }
//
// inline void ksl_product_ddry(const ksl_SE3_t* restrict Di, const double
// dc[2],
//                              ksl_SE3_t* restrict Do) {
//   ksl_product_drdry(&Di->R, dc, &Do->R);
//   ksl_vec3_copy(&Di->t, &Do->t);
// }
//
// inline void ksl_product_ddryf(const ksl_SE3f_t* restrict Di, const float
// dc[2],
//                               ksl_SE3f_t* restrict Do) {
//   ksl_product_drdryf(&Di->R, dc, &Do->R);
//   ksl_vec3f_copy(&Di->t, &Do->t);
// }
//
// inline void ksl_product_ddryinv(const ksl_SE3_t* restrict Di,
//                                 const double dc[2], ksl_SE3_t* restrict Do) {
//   ksl_product_drdryinv(&Di->R, dc, &Do->R);
//   ksl_vec3_copy(&Di->t, &Do->t);
// }
//
// inline void ksl_product_ddryinvf(const ksl_SE3f_t* restrict Di,
//                                  const float dc[2], ksl_SE3f_t* restrict Do)
//                                  {
//   ksl_product_drdryinvf(&Di->R, dc, &Do->R);
//   ksl_vec3f_copy(&Di->t, &Do->t);
// }
//
// inline void ksl_product_ddrz(const ksl_SE3_t* restrict Di, const double
// dc[2],
//                              ksl_SE3_t* restrict Do) {
//   ksl_product_drdrz(&Di->R, dc, &Do->R);
//   ksl_vec3_copy(&Di->t, &Do->t);
// }
//
// inline void ksl_product_ddrzf(const ksl_SE3f_t* restrict Di, const float
// dc[2],
//                               ksl_SE3f_t* restrict Do) {
//   ksl_product_drdrzf(&Di->R, dc, &Do->R);
//   ksl_vec3f_copy(&Di->t, &Do->t);
// }
//
// inline void ksl_product_ddrzinv(const ksl_SE3_t* restrict Di,
//                                 const double dc[2], ksl_SE3_t* restrict Do) {
//   ksl_product_drdrzinv(&Di->R, dc, &Do->R);
//   ksl_vec3_copy(&Di->t, &Do->t);
// }
//
// inline void ksl_product_ddrzinvf(const ksl_SE3f_t* restrict Di,
//                                  const float dc[2], ksl_SE3f_t* restrict Do)
//                                  {
//   ksl_product_drdrzinvf(&Di->R, dc, &Do->R);
//   ksl_vec3f_copy(&Di->t, &Do->t);
// }
//
// inline void ksl_product_ddt(const ksl_SE3_t* restrict Di,
//                             const ksl_vec3_t* restrict t,
//                             ksl_SE3_t* restrict Do) {
//   ksl_mat3x3_copy(&Di->R, &Do->R);
//   ksl_product_drv(&Di->R, t, &Do->t);
//   ksl_xpy_vv(&Di->t, &Do->t);
// }
//
// inline void ksl_product_ddtf(const ksl_SE3f_t* restrict Di,
//                              const ksl_vec3f_t* restrict t,
//                              ksl_SE3f_t* restrict Do) {
//   ksl_mat3x3f_copy(&Di->R, &Do->R);
//   ksl_product_drvf(&Di->R, t, &Do->t);
//   ksl_xpy_vvf(&Di->t, &Do->t);
// }
//
// inline void ksl_product_ddtinv(const ksl_SE3_t* restrict Di,
//                                const ksl_vec3_t* restrict t,
//                                ksl_SE3_t* restrict Do) {
//   ksl_mat3x3_copy(&Di->R, &Do->R);
//   ksl_product_drvinv(&Di->R, t, &Do->t);
//   ksl_xpy_vv(&Di->t, &Do->t);
// }
//
// inline void ksl_product_ddtinvf(const ksl_SE3f_t* restrict Di,
//                                 const ksl_vec3f_t* restrict t,
//                                 ksl_SE3f_t* restrict Do) {
//   ksl_mat3x3f_copy(&Di->R, &Do->R);
//   ksl_product_drvinvf(&Di->R, t, &Do->t);
//   ksl_xpy_vvf(&Di->t, &Do->t);
// }
//
// inline void ksl_product_dinvdt(const ksl_SE3_t* restrict Di,
//                                const ksl_vec3_t* restrict t,
//                                ksl_SE3_t* restrict Do) {
//   ksl_subtract_vv(t, &Di->t, &Do->t);
//   ksl_mat3x3_transposed(&Di->R, &Do->R);
//   ksl_product_drinvv(&Di->R, &Do->t, &Do->t);
// }
//
// inline void ksl_product_dinvdtf(const ksl_SE3f_t* restrict Di,
//                                 const ksl_vec3f_t* restrict t,
//                                 ksl_SE3f_t* restrict Do) {
//   ksl_subtract_vvf(t, &Di->t, &Do->t);
//   ksl_mat3x3f_transposed(&Di->R, &Do->R);
//   ksl_product_drinvvf(&Di->R, &Do->t, &Do->t);
// }
//
// inline void ksl_product_ddtx(const ksl_SE3_t* restrict Di, const double ti,
//                              ksl_SE3_t* restrict Do) {
//   ksl_mat3x3_copy(&Di->R, &Do->R);
//   ksl_product_drvtx(&Di->R, ti, &Do->t);
//   ksl_xpy_vv(&Di->t, &Do->t);
// }
//
// inline void ksl_product_ddtxf(const ksl_SE3f_t* restrict Di, const float ti,
//                               ksl_SE3f_t* restrict Do) {
//   ksl_mat3x3f_copy(&Di->R, &Do->R);
//   ksl_product_drvtxf(&Di->R, ti, &Do->t);
//   ksl_xpy_vvf(&Di->t, &Do->t);
// }
//
// inline void ksl_product_ddtxinv(const ksl_SE3_t* restrict Di, const double
// ti,
//                                 ksl_SE3_t* restrict Do) {
//   ksl_mat3x3_copy(&Di->R, &Do->R);
//   ksl_product_drvtxinv(&Di->R, ti, &Do->t);
//   ksl_xpy_vv(&Di->t, &Do->t);
// }
//
// inline void ksl_product_ddtxinvf(const ksl_SE3f_t* restrict Di, const float
// ti,
//                                  ksl_SE3f_t* restrict Do) {
//   ksl_mat3x3f_copy(&Di->R, &Do->R);
//   ksl_product_drvtxinvf(&Di->R, ti, &Do->t);
//   ksl_xpy_vvf(&Di->t, &Do->t);
// }
//
// inline void ksl_product_ddty(const ksl_SE3_t* restrict Di, const double ti,
//                              ksl_SE3_t* restrict Do) {
//   ksl_mat3x3_copy(&Di->R, &Do->R);
//   ksl_product_drvty(&Di->R, ti, &Do->t);
//   ksl_xpy_vv(&Di->t, &Do->t);
// }
//
// inline void ksl_product_ddtyf(const ksl_SE3f_t* restrict Di, const float ti,
//                               ksl_SE3f_t* restrict Do) {
//   ksl_mat3x3f_copy(&Di->R, &Do->R);
//   ksl_product_drvtyf(&Di->R, ti, &Do->t);
//   ksl_xpy_vvf(&Di->t, &Do->t);
// }
//
// inline void ksl_product_ddtyinv(const ksl_SE3_t* restrict Di, const double
// ti,
//                                 ksl_SE3_t* restrict Do) {
//   ksl_mat3x3_copy(&Di->R, &Do->R);
//   ksl_product_drvtyinv(&Di->R, ti, &Do->t);
//   ksl_xpy_vv(&Di->t, &Do->t);
// }
//
// inline void ksl_product_ddtyinvf(const ksl_SE3f_t* restrict Di, const float
// ti,
//                                  ksl_SE3f_t* restrict Do) {
//   ksl_mat3x3f_copy(&Di->R, &Do->R);
//   ksl_product_drvtyinvf(&Di->R, ti, &Do->t);
//   ksl_xpy_vvf(&Di->t, &Do->t);
// }
//
// inline void ksl_product_ddtz(const ksl_SE3_t* restrict Di, const double ti,
//                              ksl_SE3_t* restrict Do) {
//   ksl_mat3x3_copy(&Di->R, &Do->R);
//   ksl_product_drvtz(&Di->R, ti, &Do->t);
//   ksl_xpy_vv(&Di->t, &Do->t);
// }
//
// inline void ksl_product_ddtzf(const ksl_SE3f_t* restrict Di, const float ti,
//                               ksl_SE3f_t* restrict Do) {
//   ksl_mat3x3f_copy(&Di->R, &Do->R);
//   ksl_product_drvtzf(&Di->R, ti, &Do->t);
//   ksl_xpy_vvf(&Di->t, &Do->t);
// }
//
// inline void ksl_product_ddtzinv(const ksl_SE3_t* restrict Di, const double
// ti,
//                                 ksl_SE3_t* restrict Do) {
//   ksl_mat3x3_copy(&Di->R, &Do->R);
//   ksl_product_drvtzinv(&Di->R, ti, &Do->t);
//   ksl_xpy_vv(&Di->t, &Do->t);
// }
//
// inline void ksl_product_ddtzinvf(const ksl_SE3f_t* restrict Di, const float
// ti,
//                                  ksl_SE3f_t* restrict Do) {
//   ksl_mat3x3f_copy(&Di->R, &Do->R);
//   ksl_product_drvtzinvf(&Di->R, ti, &Do->t);
//   ksl_xpy_vvf(&Di->t, &Do->t);
// }
//
// inline void ksl_product_ddr(const ksl_SE3_t* restrict Di,
//                             const ksl_mat3x3_t* restrict Ri,
//                             ksl_SE3_t* restrict Do) {
//   ksl_product_drdr(&Di->R, Ri, &Do->R);
//   ksl_vec3_copy(&Di->t, &Do->t);
// }
//
// inline void ksl_product_ddrf(const ksl_SE3f_t* restrict Di,
//                              const ksl_mat3x3f_t* restrict Ri,
//                              ksl_SE3f_t* restrict Do) {
//   ksl_product_drdrf(&Di->R, Ri, &Do->R);
//   ksl_vec3f_copy(&Di->t, &Do->t);
// }
//
// inline void ksl_product_ddrinv(const ksl_SE3_t* restrict Di,
//                                const ksl_mat3x3_t* restrict Ri,
//                                ksl_SE3_t* restrict Do) {
//   ksl_product_drdrinv(&Di->R, Ri, &Do->R);
//   ksl_xpy_vv(&Di->t, &Do->t);
// }
//
// inline void ksl_product_ddrinvf(const ksl_SE3f_t* restrict Di,
//                                 const ksl_mat3x3f_t* restrict Ri,
//                                 ksl_SE3f_t* restrict Do) {
//   ksl_product_drdrinvf(&Di->R, Ri, &Do->R);
//   ksl_xpy_vvf(&Di->t, &Do->t);
// }
//
// inline void ksl_product_dd(const ksl_SE3_t* restrict D1i,
//                            const ksl_SE3_t* restrict D2i,
//                            ksl_SE3_t* restrict Do) {
//   ksl_product_drdr(&D1i->R, &D2i->R, &Do->R);
//   ksl_product_drv(&D1i->R, &D2i->t, &Do->t);
//   ksl_xpy_vv(&D1i->t, &Do->t);
// }
//
// inline void ksl_product_ddf(const ksl_SE3f_t* restrict D1i,
//                             const ksl_SE3f_t* restrict D2i,
//                             ksl_SE3f_t* restrict Do) {
//   ksl_product_drdrf(&D1i->R, &D2i->R, &Do->R);
//   ksl_product_drvf(&D1i->R, &D2i->t, &Do->t);
//   ksl_xpy_vvf(&D1i->t, &Do->t);
// }
//
// inline void ksl_product_ddinv(const ksl_SE3_t* restrict D1i,
//                               const ksl_SE3_t* restrict D2i,
//                               ksl_SE3_t* restrict Do) {
//   ksl_product_drdrinv(&D1i->R, &D2i->R, &Do->R);
//   ksl_product_drvinv(&Do->R, &D2i->t, &Do->t);
//   ksl_xpy_vv(&D1i->t, &Do->t);
// }
//
// inline void ksl_product_ddinvf(const ksl_SE3f_t* D1i, const ksl_SE3f_t* D2i,
//                                ksl_SE3f_t* Do) {
//   ksl_product_drdrinvf(&D1i->R, &D2i->R, &Do->R);
//   ksl_product_drvinvf(&Do->R, &D2i->t, &Do->t);
//   ksl_xpy_vvf(&D1i->t, &Do->t);
// }

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
