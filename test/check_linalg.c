#include <config.h>

#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "linalg.h"
#include "util.h"

static FILE* dbg;

START_TEST(test_swap_unit_stride) {
  double a[20] = {1,  2,  3,  4,  5,  6,  7,  8,  9,  10,
                  11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  double b[20] = {11, 12, 13, 14, 15, 6,  7,  8,  9,  10,
                  1,  2,  3,  4,  5,  16, 17, 18, 19, 20};
  ksl_swapArray(5, a, 1, a + 10, 1);
  ck_assert(ksl_allclose(20, a, b));
}
END_TEST

START_TEST(test_swap_nonunit_stride) {
  double a[20] = {1,  2,  3,  4,  5,  6,  7,  8,  9,  10,
                  11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  double b[20] = {4,  2,  3,  1,  5,  9,  7,  8,  6,  10,
                  14, 12, 13, 11, 15, 19, 17, 18, 16, 20};
  ksl_swapArray(4, a, 5, a + 3, 5);
  ck_assert(ksl_allclose(20, a, b));
}
END_TEST

START_TEST(test_maxIndex) {
  double a[10] = {-21, 45, -622, 431, 622, 0, -1, -633, 1, -99};
  ck_assert(ksl_maxIndex(10, a) == 7);
}
END_TEST

START_TEST(test_linalg_lu_full_rmo) {
  double AO[30] = {3,  1, -3, 3, 0,  2,  2, 2, -6, 3, 1, 7, -4, 0,  0,
                   -3, 1, 3,  8, -4, 12, 0, 4, 4,  6, 1, 3, -3, -2, -2};
  double AB[30] = {3,  1, -3, 3, 0,  2,  2, 2, -6, 3, 1, 7, -4, 0,  0,
                   -3, 1, 3,  8, -4, 12, 0, 4, 4,  6, 1, 3, -3, -2, -2};
  double LU[30] = {12,    4,         8,    0,          4,  -4,        -0.5, 9,
                   6,     3,         3,    0,          0,  1.0 / 3.0, -6,   -4,
                   0,     0,         0.25, -1.0 / 3.0, -1, -6,        -2,   2,
                   -0.25, 1.0 / 3.0, -0.5, 0,          0,  0};

  int pr[5];
  int prB[5] = {3, 1, 2, 4, 0};
  int pc[6];
  int pcB[6] = {2, 5, 0, 3, 4, 1};
  double eps = 1e-12;

  // fprintf(dbg, "In test_linalg_lu_full_rmo\n");
  //
  // fprintf(dbg, "\nAO:\n");
  // for(int i = 0; i < 5; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 5; j++) {
  //     fprintf(dbg, "%g, ", AO[i * 6 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", AO[i * 6 + 5]);
  // }

  ksl_linalg_lu_full_rmo(5, 6, AO, eps, pr, pc);

  // fprintf(dbg, "\nAO:\n");
  // for(int i = 0; i < 5; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 5; j++) {
  //     fprintf(dbg, "%g, ", AO[i * 6 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", AO[i * 6 + 5]);
  // }
  //
  // fprintf(dbg, "\npr = [");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "%d, ", pr[i]);
  // }
  // fprintf(dbg, "%d]\n", pr[4]);
  //
  // fprintf(dbg, "\npc = [");
  // for(int i = 0; i < 5; i++) {
  //   fprintf(dbg, "%d, ", pc[i]);
  // }
  // fprintf(dbg, "%d\n", pc[5]);
  //
  // fprintf(dbg, "\nAP:\n");
  // for(int i = 0; i < 5; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 5; j++) {
  //     fprintf(dbg, "%g, ", AB[pr[i] * 6 + pc[j]]);
  //   }
  //   fprintf(dbg, "%g|\n", AB[pr[i] * 6 + pc[5]]);
  // }

  ck_assert(ksl_allclose(30, AO, LU));
  ck_assert(ksl_allclosei(5, pr, prB));
  ck_assert(ksl_allclosei(6, pc, pcB));
}
END_TEST

START_TEST(test_linalg_lu_full_specified_rmo) {
  double AO[30] = {3,  1, -3, 3, 0,  2,  2, 2, -6, 3, 1, 7, -4, 0,  0,
                   -3, 1, 3,  8, -4, 12, 0, 4, 4,  6, 1, 3, -3, -2, -2};
  double LU[30] = {12,    4,         8,    0,          -4, 4,         -0.5, 9,
                   6,     3,         0,    3,          0,  1.0 / 3.0, -6,   -4,
                   0,     0,         0.25, -1.0 / 3.0, -1, -6,        2,    -2,
                   -0.25, 1.0 / 3.0, -0.5, -0,         0,  0};
  int pr[5];
  int prB[5] = {3, 1, 2, 4, 0};
  int pc[6];
  int pcB[6] = {2, 5, 0, 3, 1, 4};
  double eps = 1e-12;

  // fprintf(dbg, "In test_linalg_lu_full_specified_rmo\n");
  //
  // fprintf(dbg, "\nAO:\n");
  // for(int i = 0; i < 5; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 5; j++) {
  //     fprintf(dbg, "%g, ", AO[i * 6 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", AO[i * 6 + 5]);
  // }

  ksl_linalg_lu_full_specified_rmo(5, 6, AO, eps, pr, pc, 4);

  // fprintf(dbg, "\nAO:\n");
  // for(int i = 0; i < 5; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 5; j++) {
  //     fprintf(dbg, "%g, ", AO[i * 6 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", AO[i * 6 + 5]);
  // }
  //
  // fprintf(dbg, "\npr = [");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "%d, ", pr[i]);
  // }
  // fprintf(dbg, "%d]\n", pr[4]);
  //
  // fprintf(dbg, "\npc = [");
  // for(int i = 0; i < 5; i++) {
  //   fprintf(dbg, "%d, ", pc[i]);
  // }
  // fprintf(dbg, "%d\n", pc[5]);

  ck_assert(ksl_allclose(30, AO, LU));
  ck_assert(ksl_allclosei(5, pr, prB));
  ck_assert(ksl_allclosei(6, pc, pcB));
}
END_TEST

START_TEST(test_linalg_lu_rmo) {
  double AO[24] = {12, 4, 8,  0,  4, -4, -6, 7,  2, 3,  1,  2,
                   0,  3, -4, -3, 1, 0,  3,  -2, 6, -3, -2, 1};
  double LU[24] = {12, 4, 8,    0,          4,  -4,        -0.5, 9,
                   6,  3, 3,    0,          0,  1.0 / 3.0, -6,   -4,
                   0,  0, 0.25, -1.0 / 3.0, -1, -6,        -2,   2};

  // fprintf(dbg, "In test_linalg_lu_rmo\n");
  //
  // fprintf(dbg, "\nAO:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 5; j++) {
  //     fprintf(dbg, "%g, ", AO[i * 6 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", AO[i * 6 + 5]);
  // }

  ksl_linalg_lu_rmo(4, 6, AO);

  // fprintf(dbg, "\nAO:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 5; j++) {
  //     fprintf(dbg, "%g, ", AO[i * 6 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", AO[i * 6 + 5]);
  // }

  ck_assert(ksl_allclose(24, AO, LU));
}
END_TEST

START_TEST(test_linalg_lu_setBMatrix_rmo) {
  double LU[30] = {12,    4,         8,    0,          4,  -4,        -0.5, 9,
                   6,     3,         3,    0,          0,  1.0 / 3.0, -6,   -4,
                   0,     0,         0.25, -1.0 / 3.0, -1, -6,        -2,   2,
                   -0.25, 1.0 / 3.0, -0.5, 0,          0,  0};
  double LUB[30] = {12,    4,          8,    0,  29.0 / 81.0, -38.0 / 81.0,
                    -0.5,  9,          6,    3,  10.0 / 27.0, -1.0 / 27.0,
                    0,     1.0 / 3.0,  -6,   -4, -2.0 / 9.0,  2.0 / 9.0,
                    0.25,  -1.0 / 3.0, -1,   -6, 1.0 / 3.0,   -1.0 / 3.0,
                    -0.25, 1.0 / 3.0,  -0.5, 0,  0,           0};

  // fprintf(dbg, "test_linalg_lu_setBMatrix_rmo\n");

  // fprintf(dbg, "\nLU:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 5; j++) {
  //     fprintf(dbg, "%g, ", LU[i * 6 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", LU[i * 6 + 5]);
  // }

  ksl_linalg_lu_setBMatrix_rmo(5, 6, 4, LU);

  // fprintf(dbg, "\nLU:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 5; j++) {
  //     fprintf(dbg, "%g, ", LU[i * 6 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", LU[i * 6 + 5]);
  // }

  ck_assert(ksl_allclose(30, LU, LUB));
}
END_TEST

START_TEST(test_linalg_lu_setCMatrix_rmo) {
  double LU[30] = {12,    4,         8,    0,          4,  -4,        -0.5, 9,
                   6,     3,         3,    0,          0,  1.0 / 3.0, -6,   -4,
                   0,     0,         0.25, -1.0 / 3.0, -1, -6,        -2,   2,
                   -0.25, 1.0 / 3.0, -0.5, 0,          0,  0};
  double LUC[30] = {12, 4,  8,  0,         4,  -4,  -0.5, 9, 6,    3,
                    3,  0,  0,  1.0 / 3.0, -6, -4,  0,    0, 0.25, -1.0 / 3.0,
                    -1, -6, -2, 2,         0,  0.5, -0.5, 0, 0,    0};

  // fprintf(dbg, "test_linalg_lu_setCMatrix_rmo\n");
  //
  // fprintf(dbg, "\nLUC:\n");
  // for(int i = 0; i < 5; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 5; j++) {
  //     fprintf(dbg, "%g, ", LUC[i * 6 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", LUC[i * 6 + 5]);
  // }

  ksl_linalg_lu_setCMatrix_rmo(5, 6, 4, LU);

  // fprintf(dbg, "\nLU:\n");
  // for(int i = 0; i < 5; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 5; j++) {
  //     fprintf(dbg, "%g, ", LU[i * 6 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", LU[i * 6 + 5]);
  // }

  ck_assert(ksl_allclose(30, LU, LUC));
}
END_TEST

START_TEST(test_linalg_ldlt_rmo) {
  double A[16] = {4, 3,          2,          1,
                  3, 21.0 / 4.0, 7.0 / 2.0,  7.0 / 4.0,
                  2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                  1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};
  double AB[16] = {4, 3,          2,          1,
                   3, 26.0 / 5.0, 7.0 / 2.0,  7.0 / 4.0,
                   2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                   1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};
  double LDLT[16] = {4,         0.75,      0.5, 0.25,      0.75, 3,
                     2.0 / 3.0, 1.0 / 3.0, 0.5, 2.0 / 3.0, 2,    0.5,
                     0.25,      1.0 / 3.0, 0.5, 1};
  double AI[16] = {7.0 / 16.0, -0.25, 0,    0,          -0.25,     5.0 / 9.0,
                   -1.0 / 3.0, 0,     0,    -1.0 / 3.0, 3.0 / 4.0, -0.5,
                   0,          0,     -0.5, 1};
  // fprintf(dbg, "test_linalg_ldlt_rmo\n");
  //
  // fprintf(dbg, "\nA:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", A[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", A[i * 4 + 3]);
  // }
  //
  // fprintf(dbg, "\nLDLT:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", LDLT[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", LDLT[i * 4 + 3]);
  // }

  ksl_linalg_ldlt_rmo(A, 4);

  // fprintf(dbg, "\nA:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", A[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", A[i * 4 + 3]);
  // }

  ck_assert(ksl_allclose(16, A, LDLT));
}
END_TEST

START_TEST(test_linalg_cholesky_rmo) {
  double A[16] = {4, 3,          2,          1,
                  3, 21.0 / 4.0, 7.0 / 2.0,  7.0 / 4.0,
                  2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                  1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};
  double AB[16] = {4, 3,          2,          1,
                   3, 26.0 / 5.0, 7.0 / 2.0,  7.0 / 4.0,
                   2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                   1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};
  double UTU[16] = {2,
                    1.5,
                    1,
                    0.5,
                    1.5,
                    sqrt(3),
                    2.0 * sqrt(3) / 3.0,
                    sqrt(3) / 3.0,
                    1,
                    2.0 * sqrt(3) / 3.0,
                    sqrt(2),
                    sqrt(2) / 2.0,
                    0.5,
                    sqrt(3) / 3.0,
                    sqrt(2) / 2.0,
                    1};
  double AI[16] = {7.0 / 16.0, -0.25, 0,    0,          -0.25,     5.0 / 9.0,
                   -1.0 / 3.0, 0,     0,    -1.0 / 3.0, 3.0 / 4.0, -0.5,
                   0,          0,     -0.5, 1};
  // fprintf(dbg, "test_linalg_cholesky_rmo\n");
  //
  // fprintf(dbg, "\nA:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", A[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", A[i * 4 + 3]);
  // }
  //
  // fprintf(dbg, "\nUTU:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", UTU[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", UTU[i * 4 + 3]);
  // }

  ksl_linalg_cholesky_rmo(A, 4);

  // fprintf(dbg, "\nA:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", A[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", A[i * 4 + 3]);
  // }

  ck_assert(ksl_allclose(16, A, UTU));
}
END_TEST

START_TEST(test_linalg_ldlt_forwardElimination_rmo) {
  double A[16] = {4, 3,          2,          1,
                  3, 21.0 / 4.0, 7.0 / 2.0,  7.0 / 4.0,
                  2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                  1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};
  double AB[16] = {4, 3,          2,          1,
                   3, 26.0 / 5.0, 7.0 / 2.0,  7.0 / 4.0,
                   2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                   1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};
  double LDLT[16] = {4,         0.75,      0.5, 0.25,      0.75, 3,
                     2.0 / 3.0, 1.0 / 3.0, 0.5, 2.0 / 3.0, 2,    0.5,
                     0.25,      1.0 / 3.0, 0.5, 1};
  double AI[16] = {7.0 / 16.0, -0.25, 0,    0,          -0.25,     5.0 / 9.0,
                   -1.0 / 3.0, 0,     0,    -1.0 / 3.0, 3.0 / 4.0, -0.5,
                   0,          0,     -0.5, 1};
  double b[4] = {8, 18, 12, 2};
  double y[4];
  double yB[4] = {8, 12, 0, -4};
  double x[4];
  double xB[4] = {-1, 4, 2, -4};

  // fprintf(dbg, "test_linalg_ldlt_rmo\n");
  //
  // fprintf(dbg, "\nA:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", A[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", A[i * 4 + 3]);
  // }
  //
  // fprintf(dbg, "\nLDLT:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", LDLT[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", LDLT[i * 4 + 3]);
  // }

  ksl_linalg_ldlt_forwardElimination_rmo(LDLT, b, y, 4);

  // fprintf(dbg, "\nA:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", A[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", A[i * 4 + 3]);
  // }

  ck_assert(ksl_allclose(4, y, yB));
}

END_TEST

START_TEST(test_linalg_ldlt_backwardSubstitution_rmo) {
  double A[16] = {4, 3,          2,          1,
                  3, 21.0 / 4.0, 7.0 / 2.0,  7.0 / 4.0,
                  2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                  1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};
  double AB[16] = {4, 3,          2,          1,
                   3, 26.0 / 5.0, 7.0 / 2.0,  7.0 / 4.0,
                   2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                   1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};
  double LDLT[16] = {4,         0.75,      0.5, 0.25,      0.75, 3,
                     2.0 / 3.0, 1.0 / 3.0, 0.5, 2.0 / 3.0, 2,    0.5,
                     0.25,      1.0 / 3.0, 0.5, 1};
  double AI[16] = {7.0 / 16.0, -0.25, 0,    0,          -0.25,     5.0 / 9.0,
                   -1.0 / 3.0, 0,     0,    -1.0 / 3.0, 3.0 / 4.0, -0.5,
                   0,          0,     -0.5, 1};
  double b[4] = {8, 18, 12, 2};
  double y[4] = {2, 4, 0, -4};
  double x[4];
  double xB[4] = {-1, 4, 2, -4};
  // fprintf(dbg, "test_linalg_ldlt_rmo\n");
  //
  // fprintf(dbg, "\nA:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", A[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", A[i * 4 + 3]);
  // }
  //
  // fprintf(dbg, "\nLDLT:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", LDLT[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", LDLT[i * 4 + 3]);
  // }

  ksl_linalg_ldlt_backwardSubstitution_rmo(LDLT, y, x, 4);

  // fprintf(dbg, "\nA:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", A[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", A[i * 4 + 3]);
  // }

  ck_assert(ksl_allclose(4, x, xB));
}
END_TEST

START_TEST(test_linalg_cholesky_forwardElimination_rmo) {
  double A[16] = {4, 3,          2,          1,
                  3, 21.0 / 4.0, 7.0 / 2.0,  7.0 / 4.0,
                  2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                  1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};
  double AB[16] = {4, 3,          2,          1,
                   3, 26.0 / 5.0, 7.0 / 2.0,  7.0 / 4.0,
                   2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                   1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};
  double UTU[16] = {2,
                    1.5,
                    1,
                    0.5,
                    1.5,
                    sqrt(3),
                    2.0 * sqrt(3) / 3.0,
                    sqrt(3) / 3.0,
                    1,
                    2.0 * sqrt(3) / 3.0,
                    sqrt(2),
                    sqrt(2) / 2.0,
                    0.5,
                    sqrt(3) / 3.0,
                    sqrt(2) / 2.0,
                    1};
  double AI[16] = {7.0 / 16.0, -0.25, 0,    0,          -0.25,     5.0 / 9.0,
                   -1.0 / 3.0, 0,     0,    -1.0 / 3.0, 3.0 / 4.0, -0.5,
                   0,          0,     -0.5, 1};
  double b[4] = {8, 18, 12, 2};
  double y[4];
  double yB[4] = {4, 4 * sqrt(3), 0, -4};
  double x[4];
  double xB[4] = {-1, 4, 2, -4};

  // fprintf(dbg, "test_linalg_ldlt_rmo\n");
  //
  // fprintf(dbg, "\nA:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", A[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", A[i * 4 + 3]);
  // }
  //
  // fprintf(dbg, "\nLDLT:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", LDLT[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", LDLT[i * 4 + 3]);
  // }

  ksl_linalg_cholesky_forwardElimination_rmo(UTU, b, y, 4);

  // fprintf(dbg, "\nA:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", A[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", A[i * 4 + 3]);
  // }

  ck_assert(ksl_allclose(4, y, yB));
}
END_TEST

START_TEST(test_linalg_cholesky_backwardSubstitution_rmo) {
  double A[16] = {4, 3,          2,          1,
                  3, 21.0 / 4.0, 7.0 / 2.0,  7.0 / 4.0,
                  2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                  1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};
  double AB[16] = {4, 3,          2,          1,
                   3, 26.0 / 5.0, 7.0 / 2.0,  7.0 / 4.0,
                   2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                   1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};
  double UTU[16] = {2,
                    1.5,
                    1,
                    0.5,
                    1.5,
                    sqrt(3),
                    2.0 * sqrt(3) / 3.0,
                    sqrt(3) / 3.0,
                    1,
                    2.0 * sqrt(3) / 3.0,
                    sqrt(2),
                    sqrt(2) / 2.0,
                    0.5,
                    sqrt(3) / 3.0,
                    sqrt(2) / 2.0,
                    1};
  double AI[16] = {7.0 / 16.0, -0.25, 0,    0,          -0.25,     5.0 / 9.0,
                   -1.0 / 3.0, 0,     0,    -1.0 / 3.0, 3.0 / 4.0, -0.5,
                   0,          0,     -0.5, 1};
  double b[4] = {8, 18, 12, 2};
  double y[4] = {4, 4 * sqrt(3), 0, -4};
  double x[4];
  double xB[4] = {-1, 4, 2, -4};

  // fprintf(dbg, "test_linalg_ldlt_rmo\n");
  //
  // fprintf(dbg, "\nA:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", A[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", A[i * 4 + 3]);
  // }
  //
  // fprintf(dbg, "\nLDLT:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", LDLT[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", LDLT[i * 4 + 3]);
  // }

  ksl_linalg_cholesky_backwardSubstitution_rmo(UTU, y, x, 4);

  // fprintf(dbg, "\nA:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", A[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", A[i * 4 + 3]);
  // }

  ck_assert(ksl_allclose(4, x, xB));
}
END_TEST

START_TEST(test_linalg_ldlt_solve_rmo) {
  double A[16] = {4, 3,          2,          1,
                  3, 21.0 / 4.0, 7.0 / 2.0,  7.0 / 4.0,
                  2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                  1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};
  double AB[16] = {4, 3,          2,          1,
                   3, 26.0 / 5.0, 7.0 / 2.0,  7.0 / 4.0,
                   2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                   1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};
  double LDLT[16] = {4,         0.75,      0.5, 0.25,      0.75, 3,
                     2.0 / 3.0, 1.0 / 3.0, 0.5, 2.0 / 3.0, 2,    0.5,
                     0.25,      1.0 / 3.0, 0.5, 1};
  double AI[16] = {7.0 / 16.0, -0.25, 0,    0,          -0.25,     5.0 / 9.0,
                   -1.0 / 3.0, 0,     0,    -1.0 / 3.0, 3.0 / 4.0, -0.5,
                   0,          0,     -0.5, 1};
  double b[4] = {8, 18, 12, 2};
  double y[4];
  double yB[4] = {8, 12, 0, -4};
  double x[4];
  double xB[4] = {-1, 4, 2, -4};

  // fprintf(dbg, "test_linalg_ldlt_rmo\n");
  //
  // fprintf(dbg, "\nA:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", A[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", A[i * 4 + 3]);
  // }
  //
  // fprintf(dbg, "\nLDLT:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", LDLT[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", LDLT[i * 4 + 3]);
  // }

  ksl_linalg_ldlt_solve_rmo(LDLT, b, x, 4);

  // fprintf(dbg, "\nA:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", A[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", A[i * 4 + 3]);
  // }

  ck_assert(ksl_allclose(4, x, xB));
}
END_TEST

START_TEST(test_linalg_cholesky_solve_rmo) {
  double A[16] = {4, 3,          2,          1,
                  3, 21.0 / 4.0, 7.0 / 2.0,  7.0 / 4.0,
                  2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                  1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};
  double AB[16] = {4, 3,          2,          1,
                   3, 26.0 / 5.0, 7.0 / 2.0,  7.0 / 4.0,
                   2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                   1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};
  double UTU[16] = {2,
                    1.5,
                    1,
                    0.5,
                    1.5,
                    sqrt(3),
                    2.0 * sqrt(3) / 3.0,
                    sqrt(3) / 3.0,
                    1,
                    2.0 * sqrt(3) / 3.0,
                    sqrt(2),
                    sqrt(2) / 2.0,
                    0.5,
                    sqrt(3) / 3.0,
                    sqrt(2) / 2.0,
                    1};
  double AI[16] = {7.0 / 16.0, -0.25, 0,    0,          -0.25,     5.0 / 9.0,
                   -1.0 / 3.0, 0,     0,    -1.0 / 3.0, 3.0 / 4.0, -0.5,
                   0,          0,     -0.5, 1};
  double b[4] = {8, 18, 12, 2};
  double y[4];
  double yB[4] = {4, 4 * sqrt(3), 0, -4};
  double x[4];
  double xB[4] = {-1, 4, 2, -4};
  // fprintf(dbg, "test_linalg_ldlt_rmo\n");
  //
  // fprintf(dbg, "\nA:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", A[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", A[i * 4 + 3]);
  // }
  //
  // fprintf(dbg, "\nLDLT:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", LDLT[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", LDLT[i * 4 + 3]);
  // }

  ksl_linalg_cholesky_solve_rmo(UTU, b, x, 4);

  // fprintf(dbg, "\nA:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", A[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", A[i * 4 + 3]);
  // }

  ck_assert(ksl_allclose(4, x, xB));
}
END_TEST

START_TEST(test_linalg_symmetricMatrixInverse_rmo) {
  double A[16] = {4, 3,          2,          1,
                  3, 21.0 / 4.0, 7.0 / 2.0,  7.0 / 4.0,
                  2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                  1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};
  double AB[16] = {4, 3,          2,          1,
                   3, 26.0 / 5.0, 7.0 / 2.0,  7.0 / 4.0,
                   2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                   1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};
  double LDLT[16] = {4,         0.75,      0.5, 0.25,      0.75, 3,
                     2.0 / 3.0, 1.0 / 3.0, 0.5, 2.0 / 3.0, 2,    0.5,
                     0.25,      1.0 / 3.0, 0.5, 1};
  double AI[16] = {7.0 / 16.0, -0.25, 0,    0,          -0.25,     5.0 / 9.0,
                   -1.0 / 3.0, 0,     0,    -1.0 / 3.0, 3.0 / 4.0, -0.5,
                   0,          0,     -0.5, 1};

  // fprintf(dbg, "test_linalg_ldlt_rmo\n");
  //
  // fprintf(dbg, "\nA:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", A[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", A[i * 4 + 3]);
  // }
  //
  // fprintf(dbg, "\nLDLT:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", LDLT[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", LDLT[i * 4 + 3]);
  // }

  ksl_linalg_symmetricMatrixInverse_rmo(A, 4);

  // fprintf(dbg, "\nA:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", A[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", A[i * 4 + 3]);
  // }

  ck_assert(ksl_allclose(16, A, AI));
}
END_TEST

START_TEST(test_linalg_lu_full_cmo) {
  double AO[30] = {3, 2, -4, 8, 6,  1, 2, 0, -4, 1,  -3, -6, 0, 12, 3,
                   3, 3, -3, 0, -3, 0, 1, 1, 4,  -2, 2,  7,  3, 4,  -2};
  //  3,  1, -3, 3, 0,  2,
  //  2,  2, -6, 3, 1,  7,
  // -4,  0,  0,-3, 1,  3,
  //  8, -4, 12, 0, 4,  4,
  //  6, 1, 3, -3, -2, -2};
  double AB[30] = {3, 2, -4, 8, 6,  1, 2, 0, -4, 1,  -3, -6, 0, 12, 3,
                   3, 3, -3, 0, -3, 0, 1, 1, 4,  -2, 2,  7,  3, 4,  -2};
  double LU[30] = {12,         -0.5,      0,  0.25, -0.25, 4,  9,    1.0 / 3.0,
                   -1.0 / 3.0, 1.0 / 3.0, 8,  6,    -6,    -1, -0.5, 0,
                   3,          -4,        -6, 0,    4,     3,  0,    -2,
                   0,          -4,        0,  0,    2,     0};
  //   12,          4,    8,  0,  4, -4,
  // -0.5,          9,    6,  3,  3,  0,
  //    0,  1.0 / 3.0,   -6, -4,  0,  0,
  // 0.25, -1.0 / 3.0,   -1, -6, -2,  2,
  //-0.25,  1.0 / 3.0, -0.5,  0,  0,  0

  int pr[5];
  int prB[5] = {3, 1, 2, 4, 0};
  int pc[6];
  int pcB[6] = {2, 5, 0, 3, 4, 1};
  double eps = 1e-12;

  // fprintf(dbg, "In test_linalg_lu_full_cmo\n");
  //
  // fprintf(dbg, "\nAO:\n");
  // for(int i = 0; i < 5; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 5; j++) {
  //     fprintf(dbg, "%g, ", AO[j * 5 + i]);
  //   }
  //   fprintf(dbg, "%g|\n", AO[5 * 5 + i]);
  // }

  ksl_linalg_lu_full_cmo(5, 6, AO, eps, pr, pc);

  // fprintf(dbg, "\nAO:\n");
  // for(int i = 0; i < 5; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 5; j++) {
  //     fprintf(dbg, "%g, ", AO[j * 5 + i]);
  //   }
  //   fprintf(dbg, "%g|\n", AO[5 * 5 + i]);
  // }
  //
  // fprintf(dbg, "\npr = [");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "%d, ", pr[i]);
  // }
  // fprintf(dbg, "%d]\n", pr[4]);
  //
  // fprintf(dbg, "\npc = [");
  // for(int i = 0; i < 5; i++) {
  //   fprintf(dbg, "%d, ", pc[i]);
  // }
  // fprintf(dbg, "%d\n", pc[5]);
  //
  // fprintf(dbg, "\nAP:\n");
  // for(int i = 0; i < 5; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 5; j++) {
  //     fprintf(dbg, "%g, ", AB[pr[i] * 6 + pc[j]]);
  //   }
  //   fprintf(dbg, "%g|\n", AB[pr[i] * 6 + pc[5]]);
  // }

  ck_assert(ksl_allclose(30, AO, LU));
  ck_assert(ksl_allclosei(5, pr, prB));
  ck_assert(ksl_allclosei(6, pc, pcB));
}
END_TEST

START_TEST(test_linalg_lu_full_specified_cmo) {
  double AO[30] = {3, 2, -4, 8, 6,  1, 2, 0, -4, 1,  -3, -6, 0, 12, 3,
                   3, 3, -3, 0, -3, 0, 1, 1, 4,  -2, 2,  7,  3, 4,  -2};
  //  3,  1, -3, 3, 0,  2,
  //  2,  2, -6, 3, 1,  7,
  // -4,  0,  0,-3, 1,  3,
  //  8, -4, 12, 0, 4,  4,
  //  6, 1, 3, -3, -2, -2};
  double AB[30] = {3, 2, -4, 8, 6,  1, 2, 0, -4, 1,  -3, -6, 0, 12, 3,
                   3, 3, -3, 0, -3, 0, 1, 1, 4,  -2, 2,  7,  3, 4,  -2};
  double LU[30] = {12,         -0.5,      0,  0.25, -0.25, 4,  9,    1.0 / 3.0,
                   -1.0 / 3.0, 1.0 / 3.0, 8,  6,    -6,    -1, -0.5, 0,
                   3,          -4,        -6, 0,    -4,    0,  0,    2,
                   0,          4,         3,  0,    -2,    0};
  //   12,          4,    8,  0, -4,  4,
  // -0.5,          9,    6,  3,  0,  3,
  //    0,  1.0 / 3.0,   -6, -4,  0,  0,
  // 0.25, -1.0 / 3.0,   -1, -6,  2, -2,
  //-0.25,  1.0 / 3.0, -0.5,  0,  0,  0
  int pr[5];
  int prB[5] = {3, 1, 2, 4, 0};
  int pc[6];
  int pcB[6] = {2, 5, 0, 3, 1, 4};
  double eps = 1e-12;

  // fprintf(dbg, "In test_linalg_lu_full_specified_cmo\n");
  //
  // fprintf(dbg, "\nAO:\n");
  // for(int i = 0; i < 5; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 5; j++) {
  //     fprintf(dbg, "%g, ", AO[j * 5 + i]);
  //   }
  //   fprintf(dbg, "%g|\n", AO[5 * 5 + i]);
  // }

  ksl_linalg_lu_full_specified_cmo(5, 6, AO, eps, pr, pc, 4);

  // fprintf(dbg, "\nAO:\n");
  // for(int i = 0; i < 5; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 5; j++) {
  //     fprintf(dbg, "%g, ", AO[j * 5 + i]);
  //   }
  //   fprintf(dbg, "%g|\n", AO[5 * 5 + i]);
  // }
  //
  // fprintf(dbg, "\npr = [");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "%d, ", pr[i]);
  // }
  // fprintf(dbg, "%d]\n", pr[4]);
  //
  // fprintf(dbg, "\npc = [");
  // for(int i = 0; i < 5; i++) {
  //   fprintf(dbg, "%d, ", pc[i]);
  // }
  // fprintf(dbg, "%d\n", pc[5]);
  //
  // fprintf(dbg, "\nAP:\n");
  // for(int i = 0; i < 5; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 5; j++) {
  //     fprintf(dbg, "%g, ", AB[pr[i] * 6 + pc[j]]);
  //   }
  //   fprintf(dbg, "%g|\n", AB[pr[i] * 6 + pc[5]]);
  // }

  ck_assert(ksl_allclose(30, AO, LU));
  ck_assert(ksl_allclosei(5, pr, prB));
  ck_assert(ksl_allclosei(6, pc, pcB));
}

END_TEST

START_TEST(test_linalg_lu_cmo) {
  double AO[24] = {12, -6, 0,  3,  4, 7, 3, -2, 8,  2, -4, 6,
                   0,  3,  -3, -3, 4, 1, 1, -2, -4, 2, 0,  1};
  // 12,  4,  8,  0,  4, -4,
  // -6,  7,  2,  3,  1,  2,
  //  0,  3, -4, -3,  1,  0,
  //  3, -2,  6, -3, -2,  1
  double LU[24] = {12, -0.5, 0,  0.25, 4,  9, 1.0 / 3.0, -1.0 / 3.0,
                   8,  6,    -6, -1,   0,  3, -4,        -6,
                   4,  3,    0,  -2,   -4, 0, 0,         2};
  //   12,          4,  8,  0,  4, -4,
  // -0.5,          9,  6,  3,  3,  0,
  //    0,  1.0 / 3.0, -6, -4,  0,  0,
  // 0.25, -1.0 / 3.0, -1, -6, -2,  2

  // fprintf(dbg, "In test_linalg_lu_cmo\n");
  //
  // fprintf(dbg, "\nAO:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 5; j++) {
  //     fprintf(dbg, "%g, ", AO[j * 4 + i]);
  //   }
  //   fprintf(dbg, "%g|\n", AO[5 * 4 + i]);
  // }

  ksl_linalg_lu_cmo(4, 6, AO);

  // fprintf(dbg, "\nAO:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 5; j++) {
  //     fprintf(dbg, "%g, ", AO[j * 4 + i]);
  //   }
  //   fprintf(dbg, "%g|\n", AO[5 * 4 + i]);
  // }

  ck_assert(ksl_allclose(24, AO, LU));
}
END_TEST

START_TEST(test_linalg_lu_setBMatrix_cmo) {
  double LU[30] = {12,         -0.5,      0,  0.25, -0.25, 4,  9,    1.0 / 3.0,
                   -1.0 / 3.0, 1.0 / 3.0, 8,  6,    -6,    -1, -0.5, 0,
                   3,          -4,        -6, 0,    4,     3,  0,    -2,
                   0,          -4,        0,  0,    2,     0};
  //   12,          4,    8,  0,  4, -4,
  // -0.5,          9,    6,  3,  3,  0,
  //    0,  1.0 / 3.0,   -6, -4,  0,  0,
  // 0.25, -1.0 / 3.0,   -1, -6, -2,  2,
  //-0.25,  1.0 / 3.0, -0.5,  0,  0,  0
  double LUB[30] = {12,          -0.5,
                    0,           0.25,
                    -0.25,       4,
                    9,           1.0 / 3.0,
                    -1.0 / 3.0,  1.0 / 3.0,
                    8,           6,
                    -6,          -1,
                    -0.5,        0,
                    3,           -4,
                    -6,          0,
                    29.0 / 81.0, 10.0 / 27.0,
                    -2.0 / 9.0,  1.0 / 3.0,
                    0,           -38.0 / 81.0,
                    -1.0 / 27.0, 2.0 / 9.0,
                    -1.0 / 3.0,  0};
  //    12,          4,    8,  0, 29.0 / 81.0, -38.0 / 81.0,
  //  -0.5,          9,    6,  3,  0.0 / 27.0,  -1.0 / 27.0,
  //     0,  1.0 / 3.0,   -6, -4,  -2.0 / 9.0,    2.0 / 9.0,
  //  0.25, -1.0 / 3.0,   -1, -6,   1.0 / 3.0,   -1.0 / 3.0,
  // -0.25,  1.0 / 3.0, -0.5,  0,           0,            0

  // fprintf(dbg, "test_linalg_lu_setBMatrix_cmo\n");
  //
  // fprintf(dbg, "\nLU:\n");
  // for(int i = 0; i < 5; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 5; j++) {
  //     fprintf(dbg, "%g, ", LU[j * 5 + i]);
  //   }
  //   fprintf(dbg, "%g|\n", LU[5 * 5 + i]);
  // }
  //
  // fprintf(dbg, "\nLUB:\n");
  // for(int i = 0; i < 5; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 5; j++) {
  //     fprintf(dbg, "%g, ", LUB[j * 5 + i]);
  //   }
  //   fprintf(dbg, "%g|\n", LUB[5 * 5 + i]);
  // }

  ksl_linalg_lu_setBMatrix_cmo(5, 6, 4, LU);

  // fprintf(dbg, "\nLU:\n");
  // for(int i = 0; i < 5; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 5; j++) {
  //     fprintf(dbg, "%g, ", LU[j * 5 + i]);
  //   }
  //   fprintf(dbg, "%g|\n", LU[5 * 5 + i]);
  // }

  ck_assert(ksl_allclose(30, LU, LUB));
}
END_TEST

START_TEST(test_linalg_lu_setCMatrix_cmo) {

  double LU[30] = {12,         -0.5,      0,  0.25, -0.25, 4,  9,    1.0 / 3.0,
                   -1.0 / 3.0, 1.0 / 3.0, 8,  6,    -6,    -1, -0.5, 0,
                   3,          -4,        -6, 0,    4,     3,  0,    -2,
                   0,          -4,        0,  0,    2,     0};
  //   12,          4,    8,  0,  4, -4,
  // -0.5,          9,    6,  3,  3,  0,
  //    0,  1.0 / 3.0,   -6, -4,  0,  0,
  // 0.25, -1.0 / 3.0,   -1, -6, -2,  2,
  //-0.25,  1.0 / 3.0, -0.5,  0,  0,  0
  double LUC[30] = {12, -0.5, 0,  0.25, 0,    4,  9, 1.0 / 3.0, -1.0 / 3.0, 0.5,
                    8,  6,    -6, -1,   -0.5, 0,  3, -4,        -6,         0,
                    4,  3,    0,  -2,   0,    -4, 0, 0,         2,          0};

  // fprintf(dbg, "test_linalg_lu_setCMatrix_cmo\n");
  //
  // fprintf(dbg, "\nLU:\n");
  // for(int i = 0; i < 5; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 5; j++) {
  //     fprintf(dbg, "%g, ", LU[j * 5 + i]);
  //   }
  //   fprintf(dbg, "%g|\n", LU[5 * 5 + i]);
  // }
  //
  // fprintf(dbg, "\nLUC:\n");
  // for(int i = 0; i < 5; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 5; j++) {
  //     fprintf(dbg, "%g, ", LUC[j * 5 + i]);
  //   }
  //   fprintf(dbg, "%g|\n", LUC[5 * 5 + i]);
  // }

  ksl_linalg_lu_setCMatrix_cmo(5, 6, 4, LU);

  // fprintf(dbg, "\nLU:\n");
  // for(int i = 0; i < 5; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 5; j++) {
  //     fprintf(dbg, "%g, ", LU[j * 5 + i]);
  //   }
  //   fprintf(dbg, "%g|\n", LU[5 * 5 + i]);
  // }

  ck_assert(ksl_allclose(30, LU, LUC));
}
END_TEST

START_TEST(test_linalg_ldlt_cmo) {
  double A[16] = {4, 3,          2,          1,
                  3, 21.0 / 4.0, 7.0 / 2.0,  7.0 / 4.0,
                  2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                  1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};
  double AB[16] = {4, 3,          2,          1,
                   3, 26.0 / 5.0, 7.0 / 2.0,  7.0 / 4.0,
                   2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                   1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};
  double LDLT[16] = {4,         0.75,      0.5, 0.25,      0.75, 3,
                     2.0 / 3.0, 1.0 / 3.0, 0.5, 2.0 / 3.0, 2,    0.5,
                     0.25,      1.0 / 3.0, 0.5, 1};
  double AI[16] = {7.0 / 16.0, -0.25, 0,    0,          -0.25,     5.0 / 9.0,
                   -1.0 / 3.0, 0,     0,    -1.0 / 3.0, 3.0 / 4.0, -0.5,
                   0,          0,     -0.5, 1};

  // fprintf(dbg, "test_linalg_ldlt_cmo\n");
  //
  // fprintf(dbg, "\nA:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", A[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", A[i * 4 + 3]);
  // }
  //
  // fprintf(dbg, "\nLDLT:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", LDLT[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", LDLT[i * 4 + 3]);
  // }

  ksl_linalg_ldlt_cmo(A, 4);

  //   fprintf(dbg, "\nA:\n");
  //   for(int i = 0; i < 4; i++) {
  //     fprintf(dbg, "|");
  //     for(int j = 0; j < 3; j++) {
  //       fprintf(dbg, "%g, ", A[i * 4 + j]);
  //     }
  //     fprintf(dbg, "%g|\n", A[i * 4 + 3]);
  //   }

  ck_assert(ksl_allclose(16, A, LDLT));
}
END_TEST

START_TEST(test_linalg_cholesky_cmo) {
  double A[16] = {4, 3,          2,          1,
                  3, 21.0 / 4.0, 7.0 / 2.0,  7.0 / 4.0,
                  2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                  1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};
  double AB[16] = {4, 3,          2,          1,
                   3, 26.0 / 5.0, 7.0 / 2.0,  7.0 / 4.0,
                   2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                   1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};
  double UTU[16] = {2,
                    1.5,
                    1,
                    0.5,
                    1.5,
                    sqrt(3),
                    2.0 * sqrt(3) / 3.0,
                    sqrt(3) / 3.0,
                    1,
                    2.0 * sqrt(3) / 3.0,
                    sqrt(2),
                    sqrt(2) / 2.0,
                    0.5,
                    sqrt(3) / 3.0,
                    sqrt(2) / 2.0,
                    1};
  double AI[16] = {7.0 / 16.0, -0.25, 0,    0,          -0.25,     5.0 / 9.0,
                   -1.0 / 3.0, 0,     0,    -1.0 / 3.0, 3.0 / 4.0, -0.5,
                   0,          0,     -0.5, 1};

  // fprintf(dbg, "test_linalg_cholesky_cmo\n");
  //
  // fprintf(dbg, "\nA:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", A[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", A[i * 4 + 3]);
  // }
  //
  // fprintf(dbg, "\nUTU:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", UTU[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", UTU[i * 4 + 3]);
  // }

  ksl_linalg_cholesky_cmo(A, 4);

  // fprintf(dbg, "\nA:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", A[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", A[i * 4 + 3]);
  // }

  ck_assert(ksl_allclose(16, A, UTU));
}
END_TEST

START_TEST(test_linalg_ldlt_forwardElimination_cmo) {
  double A[16] = {4, 3,          2,          1,
                  3, 21.0 / 4.0, 7.0 / 2.0,  7.0 / 4.0,
                  2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                  1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};
  double AB[16] = {4, 3,          2,          1,
                   3, 26.0 / 5.0, 7.0 / 2.0,  7.0 / 4.0,
                   2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                   1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};
  double LDLT[16] = {4,         0.75,      0.5, 0.25,      0.75, 3,
                     2.0 / 3.0, 1.0 / 3.0, 0.5, 2.0 / 3.0, 2,    0.5,
                     0.25,      1.0 / 3.0, 0.5, 1};
  double AI[16] = {7.0 / 16.0, -0.25, 0,    0,          -0.25,     5.0 / 9.0,
                   -1.0 / 3.0, 0,     0,    -1.0 / 3.0, 3.0 / 4.0, -0.5,
                   0,          0,     -0.5, 1};
  double b[4] = {8, 18, 12, 2};
  double y[4];
  double yB[4] = {8, 12, 0, -4};
  double x[4];
  double xB[4] = {-1, 4, 2, -4};

  // fprintf(dbg, "test_linalg_ldlt_forwardElimination\n");
  //
  // fprintf(dbg, "\nA:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", A[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", A[i * 4 + 3]);
  // }
  //
  // fprintf(dbg, "\nLDLT:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", LDLT[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", LDLT[i * 4 + 3]);
  // }

  ksl_linalg_ldlt_forwardElimination_cmo(LDLT, b, y, 4);

  // fprintf(dbg, "\nA:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", A[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", A[i * 4 + 3]);
  // }
  //
  // fprintf(dbg, "\nyB: |\n");
  // for(int i = 0; i < 3; i++) {
  //   fprintf(dbg, "%g, ", yB[i]);
  // }
  // fprintf(dbg, "%g|\n", yB[3]);
  //
  // fprintf(dbg, "\ny: |\n");
  // for(int i = 0; i < 3; i++) {
  //   fprintf(dbg, "%g, ", y[i]);
  // }
  // fprintf(dbg, "%g|\n", y[3]);

  ck_assert(ksl_allclose(4, y, yB));
}
END_TEST

START_TEST(test_linalg_ldlt_backwardSubstitution_cmo) {
  double A[16] = {4, 3,          2,          1,
                  3, 21.0 / 4.0, 7.0 / 2.0,  7.0 / 4.0,
                  2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                  1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};
  double AB[16] = {4, 3,          2,          1,
                   3, 26.0 / 5.0, 7.0 / 2.0,  7.0 / 4.0,
                   2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                   1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};
  double LDLT[16] = {4,         0.75,      0.5, 0.25,      0.75, 3,
                     2.0 / 3.0, 1.0 / 3.0, 0.5, 2.0 / 3.0, 2,    0.5,
                     0.25,      1.0 / 3.0, 0.5, 1};
  double AI[16] = {7.0 / 16.0, -0.25, 0,    0,          -0.25,     5.0 / 9.0,
                   -1.0 / 3.0, 0,     0,    -1.0 / 3.0, 3.0 / 4.0, -0.5,
                   0,          0,     -0.5, 1};
  double b[4] = {8, 18, 12, 2};
  double y[4] = {2, 4, 0, -4};
  double x[4];
  double xB[4] = {-1, 4, 2, -4};
  //
  // fprintf(dbg, "test_linalg_ldlt_backwardSubstitution_cmo\n");
  //
  // fprintf(dbg, "\nA:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", A[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", A[i * 4 + 3]);
  // }
  //
  // fprintf(dbg, "\nLDLT:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", LDLT[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", LDLT[i * 4 + 3]);
  // }

  ksl_linalg_ldlt_backwardSubstitution_cmo(LDLT, y, x, 4);

  // fprintf(dbg, "\nA:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", A[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", A[i * 4 + 3]);
  // }
  //
  // fprintf(dbg, "\nxB: |\n");
  // for(int i = 0; i < 3; i++) {
  //   fprintf(dbg, "%g, ", xB[i]);
  // }
  // fprintf(dbg, "%g|\n", xB[3]);
  //
  // fprintf(dbg, "\nx: |\n");
  // for(int i = 0; i < 3; i++) {
  //   fprintf(dbg, "%g, ", x[i]);
  // }
  // fprintf(dbg, "%g|\n", x[3]);

  ck_assert(ksl_allclose(4, x, xB));
}
END_TEST

START_TEST(test_linalg_cholesky_forwardElimination_cmo) {
  double A[16] = {4, 3,          2,          1,
                  3, 21.0 / 4.0, 7.0 / 2.0,  7.0 / 4.0,
                  2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                  1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};
  double AB[16] = {4, 3,          2,          1,
                   3, 26.0 / 5.0, 7.0 / 2.0,  7.0 / 4.0,
                   2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                   1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};
  double UTU[16] = {2,
                    1.5,
                    1,
                    0.5,
                    1.5,
                    sqrt(3),
                    2.0 * sqrt(3) / 3.0,
                    sqrt(3) / 3.0,
                    1,
                    2.0 * sqrt(3) / 3.0,
                    sqrt(2),
                    sqrt(2) / 2.0,
                    0.5,
                    sqrt(3) / 3.0,
                    sqrt(2) / 2.0,
                    1};
  double AI[16] = {7.0 / 16.0, -0.25, 0,    0,          -0.25,     5.0 / 9.0,
                   -1.0 / 3.0, 0,     0,    -1.0 / 3.0, 3.0 / 4.0, -0.5,
                   0,          0,     -0.5, 1};
  double b[4] = {8, 18, 12, 2};
  double y[4];
  double yB[4] = {4, 4 * sqrt(3), 0, -4};
  double x[4];
  double xB[4] = {-1, 4, 2, -4};

  // fprintf(dbg, "test_linalg_cholesky_forwardElimination_cmo\n");
  //
  // fprintf(dbg, "\nA:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", A[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", A[i * 4 + 3]);
  // }
  //
  // fprintf(dbg, "\nUTU:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", UTU[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", UTU[i * 4 + 3]);
  // }

  ksl_linalg_cholesky_forwardElimination_cmo(UTU, b, y, 4);

  // fprintf(dbg, "\nA:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", A[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", A[i * 4 + 3]);
  // }
  //
  // fprintf(dbg, "\nyB: |\n");
  // for(int i = 0; i < 3; i++) {
  //   fprintf(dbg, "%g, ", yB[i]);
  // }
  // fprintf(dbg, "%g|\n", yB[3]);
  //
  // fprintf(dbg, "\ny: |\n");
  // for(int i = 0; i < 3; i++) {
  //   fprintf(dbg, "%g, ", y[i]);
  // }
  // fprintf(dbg, "%g|\n", y[3]);

  ck_assert(ksl_allclose(4, y, yB));
}
END_TEST

START_TEST(test_linalg_cholesky_backwardSubstitution_cmo) {
  double A[16] = {4, 3,          2,          1,
                  3, 21.0 / 4.0, 7.0 / 2.0,  7.0 / 4.0,
                  2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                  1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};
  double AB[16] = {4, 3,          2,          1,
                   3, 26.0 / 5.0, 7.0 / 2.0,  7.0 / 4.0,
                   2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                   1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};
  double UTU[16] = {2,
                    1.5,
                    1,
                    0.5,
                    1.5,
                    sqrt(3),
                    2.0 * sqrt(3) / 3.0,
                    sqrt(3) / 3.0,
                    1,
                    2.0 * sqrt(3) / 3.0,
                    sqrt(2),
                    sqrt(2) / 2.0,
                    0.5,
                    sqrt(3) / 3.0,
                    sqrt(2) / 2.0,
                    1};
  double AI[16] = {7.0 / 16.0, -0.25, 0,    0,          -0.25,     5.0 / 9.0,
                   -1.0 / 3.0, 0,     0,    -1.0 / 3.0, 3.0 / 4.0, -0.5,
                   0,          0,     -0.5, 1};
  double b[4] = {8, 18, 12, 2};
  double y[4] = {4, 4 * sqrt(3), 0, -4};
  double x[4];
  double xB[4] = {-1, 4, 2, -4};

  // fprintf(dbg, "test_linalg_cholesky_backwardSubstitution_cmo\n");
  //
  // fprintf(dbg, "\nA:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", A[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", A[i * 4 + 3]);
  // }
  //
  // fprintf(dbg, "\nUTU:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", UTU[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", UTU[i * 4 + 3]);
  // }

  ksl_linalg_cholesky_backwardSubstitution_cmo(UTU, y, x, 4);

  // fprintf(dbg, "\nA:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", A[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", A[i * 4 + 3]);
  // }
  //
  // fprintf(dbg, "\nxB: |\n");
  // for(int i = 0; i < 3; i++) {
  //   fprintf(dbg, "%g, ", xB[i]);
  // }
  // fprintf(dbg, "%g|\n", xB[3]);
  //
  // fprintf(dbg, "\nx: |\n");
  // for(int i = 0; i < 3; i++) {
  //   fprintf(dbg, "%g, ", x[i]);
  // }
  // fprintf(dbg, "%g|\n", x[3]);

  ck_assert(ksl_allclose(4, x, xB));
}
END_TEST

START_TEST(test_linalg_ldlt_solve_cmo) {
  double A[16] = {4, 3,          2,          1,
                  3, 21.0 / 4.0, 7.0 / 2.0,  7.0 / 4.0,
                  2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                  1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};
  double AB[16] = {4, 3,          2,          1,
                   3, 26.0 / 5.0, 7.0 / 2.0,  7.0 / 4.0,
                   2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                   1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};
  double LDLT[16] = {4,         0.75,      0.5, 0.25,      0.75, 3,
                     2.0 / 3.0, 1.0 / 3.0, 0.5, 2.0 / 3.0, 2,    0.5,
                     0.25,      1.0 / 3.0, 0.5, 1};
  double AI[16] = {7.0 / 16.0, -0.25, 0,    0,          -0.25,     5.0 / 9.0,
                   -1.0 / 3.0, 0,     0,    -1.0 / 3.0, 3.0 / 4.0, -0.5,
                   0,          0,     -0.5, 1};
  double b[4] = {8, 18, 12, 2};
  double y[4];
  double yB[4] = {8, 12, 0, -4};
  double x[4];
  double xB[4] = {-1, 4, 2, -4};

  // fprintf(dbg, "test_linalg_ldlt_cmo\n");
  //
  // fprintf(dbg, "\nA:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", A[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", A[i * 4 + 3]);
  // }
  //
  // fprintf(dbg, "\nLDLT:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", LDLT[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", LDLT[i * 4 + 3]);
  // }

  ksl_linalg_ldlt_solve_cmo(LDLT, b, x, 4);

  // fprintf(dbg, "\nA:\n");
  // for(int i = 0; i < 4; i++) {
  //   fprintf(dbg, "|");
  //   for(int j = 0; j < 3; j++) {
  //     fprintf(dbg, "%g, ", A[i * 4 + j]);
  //   }
  //   fprintf(dbg, "%g|\n", A[i * 4 + 3]);
  // }

  ck_assert(ksl_allclose(4, x, xB));
}
END_TEST

START_TEST(test_linalg_cholesky_solve_cmo) {
  double A[16] = {4, 3,          2,          1,
                  3, 21.0 / 4.0, 7.0 / 2.0,  7.0 / 4.0,
                  2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                  1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};
  double AB[16] = {4, 3,          2,          1,
                   3, 26.0 / 5.0, 7.0 / 2.0,  7.0 / 4.0,
                   2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                   1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};
  double UTU[16] = {2,
                    1.5,
                    1,
                    0.5,
                    1.5,
                    sqrt(3),
                    2.0 * sqrt(3) / 3.0,
                    sqrt(3) / 3.0,
                    1,
                    2.0 * sqrt(3) / 3.0,
                    sqrt(2),
                    sqrt(2) / 2.0,
                    0.5,
                    sqrt(3) / 3.0,
                    sqrt(2) / 2.0,
                    1};
  double AI[16] = {7.0 / 16.0, -0.25, 0,    0,          -0.25,     5.0 / 9.0,
                   -1.0 / 3.0, 0,     0,    -1.0 / 3.0, 3.0 / 4.0, -0.5,
                   0,          0,     -0.5, 1};
  double b[4] = {8, 18, 12, 2};
  double y[4];
  double yB[4] = {4, 4 * sqrt(3), 0, -4};
  double x[4];
  double xB[4] = {-1, 4, 2, -4};

  fprintf(dbg, "linalg_cholesky_solve_cmo\n");

  fprintf(dbg, "\nA:\n");
  for(int i = 0; i < 4; i++) {
    fprintf(dbg, "|");
    for(int j = 0; j < 3; j++) {
      fprintf(dbg, "%g, ", A[i * 4 + j]);
    }
    fprintf(dbg, "%g|\n", A[i * 4 + 3]);
  }

  fprintf(dbg, "\nUTU:\n");
  for(int i = 0; i < 4; i++) {
    fprintf(dbg, "|");
    for(int j = 0; j < 3; j++) {
      fprintf(dbg, "%g, ", UTU[i * 4 + j]);
    }
    fprintf(dbg, "%g|\n", UTU[i * 4 + 3]);
  }

  ksl_linalg_cholesky_solve_cmo(UTU, b, x, 4);

  fprintf(dbg, "\nA:\n");
  for(int i = 0; i < 4; i++) {
    fprintf(dbg, "|");
    for(int j = 0; j < 3; j++) {
      fprintf(dbg, "%g, ", A[i * 4 + j]);
    }
    fprintf(dbg, "%g|\n", A[i * 4 + 3]);
  }

  fprintf(dbg, "\nxB: |\n");
  for(int i = 0; i < 3; i++) {
    fprintf(dbg, "%g, ", xB[i]);
  }
  fprintf(dbg, "%g|\n", xB[3]);

  fprintf(dbg, "\nx: |\n");
  for(int i = 0; i < 3; i++) {
    fprintf(dbg, "%g, ", x[i]);
  }
  fprintf(dbg, "%g|\n", x[3]);

  // ck_assert(ksl_allclose(4, x, xB));
}
END_TEST

Suite* linalg_suite(void) {
  Suite* s = suite_create("linalg");
  TCase* tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_swap_unit_stride);
  tcase_add_test(tc_core, test_swap_nonunit_stride);
  tcase_add_test(tc_core, test_maxIndex);
  tcase_add_test(tc_core, test_linalg_lu_full_rmo);
  tcase_add_test(tc_core, test_linalg_lu_full_specified_rmo);
  tcase_add_test(tc_core, test_linalg_lu_rmo);
  tcase_add_test(tc_core, test_linalg_lu_setBMatrix_rmo);
  tcase_add_test(tc_core, test_linalg_lu_setCMatrix_rmo);
  tcase_add_test(tc_core, test_linalg_ldlt_rmo);
  tcase_add_test(tc_core, test_linalg_cholesky_rmo);
  tcase_add_test(tc_core, test_linalg_ldlt_forwardElimination_rmo);
  tcase_add_test(tc_core, test_linalg_ldlt_backwardSubstitution_rmo);
  tcase_add_test(tc_core, test_linalg_cholesky_forwardElimination_rmo);
  tcase_add_test(tc_core, test_linalg_cholesky_backwardSubstitution_rmo);
  tcase_add_test(tc_core, test_linalg_ldlt_solve_rmo);
  tcase_add_test(tc_core, test_linalg_cholesky_solve_rmo);
  tcase_add_test(tc_core, test_linalg_symmetricMatrixInverse_rmo);
  tcase_add_test(tc_core, test_linalg_lu_full_cmo);
  tcase_add_test(tc_core, test_linalg_lu_full_specified_cmo);
  tcase_add_test(tc_core, test_linalg_lu_cmo);
  tcase_add_test(tc_core, test_linalg_lu_setBMatrix_cmo);
  tcase_add_test(tc_core, test_linalg_lu_setCMatrix_cmo);
  tcase_add_test(tc_core, test_linalg_ldlt_cmo);
  tcase_add_test(tc_core, test_linalg_cholesky_cmo);
  tcase_add_test(tc_core, test_linalg_ldlt_forwardElimination_cmo);
  tcase_add_test(tc_core, test_linalg_ldlt_backwardSubstitution_cmo);
  tcase_add_test(tc_core, test_linalg_cholesky_forwardElimination_cmo);
  tcase_add_test(tc_core, test_linalg_cholesky_backwardSubstitution_cmo);
  tcase_add_test(tc_core, test_linalg_ldlt_solve_cmo);
  tcase_add_test(tc_core, test_linalg_cholesky_solve_cmo);
  suite_add_tcase(s, tc_core);
  return s;
}

int main(void) {
  dbg = fopen("test_debug.txt", "wa");
  int number_failed;
  Suite* s = linalg_suite();
  SRunner* sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  fclose(dbg);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
