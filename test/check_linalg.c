#include <config.h>

#include <check.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "ksl/array.h"
#include "ksl/linalg.h"

static FILE* dbg;

START_TEST(test_swap_unit_stride) {

  /* Swap rows 0 and 2 of a[] to match b[] */

  /*
   1,  2,  3,  4,  5,
   6,  7,  8,  9, 10,
  11, 12, 13, 14, 15,
  16, 17, 18, 19, 20
  */
  double a[20] = {1,  2,  3,  4,  5,  6,  7,  8,  9,  10,
                  11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

  /*
  11, 12, 13, 14, 15,
   6,  7,  8,  9, 10,
   1,  2,  3,  4,  5,
  16, 17, 18, 19, 20
  */
  double b[20] = {11, 12, 13, 14, 15, 6,  7,  8,  9,  10,
                  1,  2,  3,  4,  5,  16, 17, 18, 19, 20};

  ksl_swapArray(5, a, 1, a + 10, 1);

  ck_assert(ksl_allclose(20, a, b));
}
END_TEST

START_TEST(test_swap_nonunit_stride) {

  /*swap columns 0 and 3 of a[] to match b[] */

  /*
   1,  2,  3,  4,  5,
   6,  7,  8,  9, 10,
  11, 12, 13, 14, 15,
  16, 17, 18, 19, 20
  */
  double a[20] = {1,  2,  3,  4,  5,  6,  7,  8,  9,  10,
                  11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

  /*
   4,  2,  3,  1,  5,
   9,  7,  8,  6, 10,
  14, 12, 13, 11, 15,
  19, 17, 18, 16, 20
  */
  double b[20] = {4,  2,  3,  1,  5,  9,  7,  8,  6,  10,
                  14, 12, 13, 11, 15, 19, 17, 18, 16, 20};

  ksl_swapArray(4, a, 5, a + 3, 5);

  ck_assert(ksl_allclose(20, a, b));
}
END_TEST

START_TEST(test_maxIndex) {

  /* Return index of absolutely largest entry in a[] */

  double a[10] = {-21, 45, -622, 431, 622, 0, -1, -633, 1, -99};

  ck_assert(ksl_maxIndex(10, a) == 7);
}
END_TEST

START_TEST(test_linalg_lu_full_rmo) {

  /*
  Entries in array A[] were selected to allow exact values for all computed
  quantities.The matrix has five rows and six columns and requires row and
  column pivoting for optimal numerical accuracy and stability. The row and
  column permutations are recorded in the pr[] and pc[] arrays. Entries in array
  LU[] are exactly what must be returned from ksl_linalg_lu_full_rmo().
  Developers of the original IBM version of DMFGR recommended setting eps on the
  order of double precision unit roundoff, which is roughly 2e-16. A
  conservative 1e-12 was used here.

  The matrix represented by array LU[] contains exactly what is returned in
  array A[] from function ksl_linalg_lu_rmo(). The symbol L_r||U_r is equivalent
  to L_r union U_r. Single vertical bars indicate matrix partitioning.
  */

  /*
  5 by 6 matrix has rank 4
   3,  1, -3,  3,  0,  2,
   2,  2, -6,  3,  1,  7,
  -4,  0,  0, -3,  1,  3,
   8, -4, 12,  0,  4,  4,
   6,  1,  3, -3, -2, -2
  */
  double A[30] = {3,  1, -3, 3, 0,  2,  2, 2, -6, 3, 1, 7, -4, 0,  0,
                  -3, 1, 3,  8, -4, 12, 0, 4, 4,  6, 1, 3, -3, -2, -2};

  /*
  5 by 6 matrix contains 4 by 4 L_r union U_r, 4 by 2 U_R, 1 by 4 L_R matrices
     12,        4,    8,  0, |  4, -4,
   -0.5,        9,    6,  3, |  3,  0,
      0,  1.0/3.0,   -6, -4, |  0,  0,
   0.25, -1.0/3.0,   -1, -6, | -2,  2,  L_r||U_r | U_R
  ———————————————————————————————————   ————————————
  -0.25,  1.0/3.0, -0.5,  0, |  0,  0      L_R   |  0
  */
  double LU[30] = {12,    4,         8,    0,          4,  -4,        -0.5, 9,
                   6,     3,         3,    0,          0,  1.0 / 3.0, -6,   -4,
                   0,     0,         0.25, -1.0 / 3.0, -1, -6,        -2,   2,
                   -0.25, 1.0 / 3.0, -0.5, 0,          0,  0};

  /* Row permutation array */
  int pr[5];

  /* Column permutation array */
  int pc[6];

  /* tol = eps*|A|_infinity */
  double eps = 1e-12;

  ksl_linalg_lu_full_rmo(5, 6, A, eps, pr, pc);

  ck_assert(ksl_allclose(30, A, LU));
}
END_TEST

START_TEST(test_linalg_lu_full_specified_rmo) {

  /*
  Function ksl_linalg_lu_full_specified_rmo() allows the user to specify one
  variable as independent, identified by the column index of the supplied
  matrix. The function does not verify that the specified column index is less
  than colDim and greater than -1, nor does it verify that the specified
  variable has sufficient mobility to qualify as an independent variable. If the
  specified column is not the last column in the original array A[] the function
  will swap columns to move the specified column to the last column in A[].
  Column 4 was specified as independent, so columns 4 and 5 are swapped in this
  test.

  Entries in array A[] were selected to allow exact values for all computed
  quantities.The matrix has five rows and six columns and requires row and
  column pivoting for optimal numerical accuracy and stability. The row and
  column permutations are recorded in the pr[] and pc[] arrays. Entries in array
  LU[] are exactly what must be returned from
  ksl_linalg_lu_full_specified_rmo(). Developers of the original IBM version of
  DMFGR recommended setting eps on the order of double precision unit roundoff,
  which is roughly 2e-16. A conservative 1e-12 was used here.

  The matrix represented by array LU[] contains exactly what is returned in
  array A[] from function ksl_linalg_lu_rmo(). The symbol L_r||U_r is equivalent
  to L_r union U_r. Single vertical bars indicate matrix partitioning.
*/

  /*
  5 by 6 matrix has rank 4
   3,  1, -3,  3,  0,  2,
   2,  2, -6,  3,  1,  7,
  -4,  0,  0, -3,  1,  3,
   8, -4, 12,  0,  4,  4,
   6,  1,  3, -3, -2, -2
  */
  double A[30] = {3,  1, -3, 3, 0,  2,  2, 2, -6, 3, 1, 7, -4, 0,  0,
                  -3, 1, 3,  8, -4, 12, 0, 4, 4,  6, 1, 3, -3, -2, -2};

  /*
  5 by 6 matrix contains 4 by 4 L_r union U_r, 4 by 2 U_R, 1 by 4 L_R matrices
     12,        4,    8,  0, | -4,  4,
   -0.5,        9,    6,  3, |  0,  3,
      0,  1.0/3.0,   -6, -4, |  0,  0,
   0.25, -1.0/3.0,   -1, -6, |  2, -2,  L_r||U_r | U_R
  ———————————————————————————————————   ————————————
  -0.25,  1.0/3.0, -0.5,  0, |  0,  0      L_R   |  0
  */
  double LU[30] = {12,    4,         8,    0,          -4, 4,         -0.5, 9,
                   6,     3,         0,    3,          0,  1.0 / 3.0, -6,   -4,
                   0,     0,         0.25, -1.0 / 3.0, -1, -6,        2,    -2,
                   -0.25, 1.0 / 3.0, -0.5, -0,         0,  0};

  /* Row permutation array */
  int pr[5];

  /* Column permutation array */
  int pc[6];

  /* tol = eps*|A|_infinity */
  double eps = 1e-12;

  ksl_linalg_lu_full_specified_rmo(5, 6, A, eps, pr, pc, 4);

  ck_assert(ksl_allclose(30, A, LU));
}
END_TEST

START_TEST(test_linalg_lu_full_multiSpecified_rmo) {

  /*
  Function ksl_linalg_lu_full_multiSpecified_rmo() allows the user to specify
  a set of variables as independent. The specified columns are moved, in the
  order given, to the last columns of A[] and are never chosen as pivots.

  The 5 by 6 rank 4 matrix of test_linalg_lu_full_specified_rmo is factored
  with columns 4 and 1 specified. The factors must reproduce the permuted
  matrix, A[pr[i]][pc[j]] = sum_k L[i][k] U[k][j], with the rank by rank Lr
  (unit diagonal) and the rank rows of U stored in the returned array.
  */
  const double A0[30] = {3,  1, -3, 3, 0,  2,  2, 2, -6, 3, 1, 7, -4, 0,  0,
                         -3, 1, 3,  8, -4, 12, 0, 4, 4,  6, 1, 3, -3, -2, -2};
  double A[30];
  memcpy(A, A0, sizeof(A));
  int pr[5];
  int pc[6];
  const int specified[2] = {4, 1};
  double eps = 1e-12;

  int rank = ksl_linalg_lu_full_multiSpecified_rmo(5, 6, A, eps, pr, pc, 2,
                                                   specified);
  ck_assert_int_eq(rank, 4);
  ck_assert_int_eq(pc[4], 4);
  ck_assert_int_eq(pc[5], 1);

  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 6; j++) {
      double sum = 0.0;
      /* U is upper triangular in its first rank columns */
      for(int k = 0; k < rank && k <= i && k <= j; k++) {
        const double l = k == i ? 1.0 : A[i * 6 + k];
        sum += l * A[k * 6 + j];
      }
      ck_assert(fabs(sum - A0[pr[i] * 6 + pc[j]]) < 1e-12);
    }
  }

  /* the single specified wrapper matches the original function */
  double B[30];
  double C[30];
  int pr_b[5], pc_b[6], pr_c[5], pc_c[6];
  memcpy(B, A0, sizeof(B));
  memcpy(C, A0, sizeof(C));
  const int one[1] = {4};
  ksl_linalg_lu_full_specified_rmo(5, 6, B, eps, pr_b, pc_b, 4);
  ksl_linalg_lu_full_multiSpecified_rmo(5, 6, C, eps, pr_c, pc_c, 1, one);
  ck_assert(ksl_allclose(30, B, C));

  /* duplicate or out of range specified indices are rejected */
  const int duplicate[2] = {4, 4};
  const int out_of_range[2] = {4, 6};
  memcpy(A, A0, sizeof(A));
  ck_assert_int_eq(ksl_linalg_lu_full_multiSpecified_rmo(5, 6, A, eps, pr, pc,
                                                         2, duplicate),
                   -1);
  memcpy(A, A0, sizeof(A));
  ck_assert_int_eq(ksl_linalg_lu_full_multiSpecified_rmo(5, 6, A, eps, pr, pc,
                                                         2, out_of_range),
                   -1);
}
END_TEST

START_TEST(test_linalg_lu_rmo) {

  /*
  Entries in array A[] were selected to allow exact values for all computed
  quantities.The full row-rank matrix has four rows and six columns and requires
  no row or column pivoting. The matrix represented by array LU[] represents
  exactly what is returned in array A[] from function ksl_linalg_lu_rmo().

  The matrix represented by array LU[] contains exactly what is returned in
  array A[] from function ksl_linalg_lu_rmo(). The symbol L_r||U_r is
  equivalent to L_r union U_r. Single vertical bars indicate matrix
  partitioning.
  */

  /*
  4 by 6 matrix has rank 4
  12,  4,  8,  0,  4, -4,
  -6,  7,  2,  3,  1,  2,
   0,  3, -4, -3,  1,  0,
   3, -2,  6, -3, -2,  1
  */
  double A[24] = {12, 4, 8,  0,  4, -4, -6, 7,  2, 3,  1,  2,
                  0,  3, -4, -3, 1, 0,  3,  -2, 6, -3, -2, 1};

  /*
  4 by 6 matrix contains 4 by 4 L_r union U_r, and 4 by 2 U_R matrices
    12,        4,  8,  0, |  4, -4,
  -0.5,        9,  6,  3, |  3,  0,
     0,  1.0/3.0, -6, -4, |  0,  0,   L_r||U_r | U_R
  0.25, -1.0/3.0, -1, -6, | -2,  2
  */
  double LU[24] = {12, 4, 8,    0,          4,  -4,        -0.5, 9,
                   6,  3, 3,    0,          0,  1.0 / 3.0, -6,   -4,
                   0,  0, 0.25, -1.0 / 3.0, -1, -6,        -2,   2};

  ksl_linalg_lu_rmo(4, 6, A);

  ck_assert(ksl_allclose(24, A, LU));
}
END_TEST

START_TEST(test_linalg_lu_setBMatrix_rmo) {

  /*
  5 by 6 matrix contains 4 by 4 L_r union U_r, 4 by 2 U_R, 1 by 4 L_R matrices
     12,        4,    8,  0, |  4, -4,
   -0.5,        9,    6,  3, |  3,  0,
      0,  1.0/3.0,   -6, -4, |  0,  0,
   0.25, -1.0/3.0,   -1, -6, | -2,  2,  L_r||U_r | U_R
  ———————————————————————————————————   ————————————
  -0.25,  1.0/3.0, -0.5,  0, |  0,  0    L_R   |  0
  */
  double LU[30] = {12,    4,         8,    0,          4,  -4,        -0.5, 9,
                   6,     3,         3,    0,          0,  1.0 / 3.0, -6,   -4,
                   0,     0,         0.25, -1.0 / 3.0, -1, -6,        -2,   2,
                   -0.25, 1.0 / 3.0, -0.5, 0,          0,  0};

  /*
  5 by 6 matrix contains 4 by 4 L_r union U_r, 4 by 2 B, 1 by 4 L_R matrices
     12,        4,    8,  0, | 29.0/81.0, -38.0/81.0,
   -0.5,        9,    6,  3, | 10.0/27.0,  -1.0/27.0,
      0,  1.0/3.0,   -6, -4, |  -2.0/9.0,    2.0/9.0,
   0.25, -1.0/3.0,   -1, -6, |   1.0/3.0,   -1.0/ .0,    L_r||U_r |  B
  ———————————————————————————————————————————————————    ————————————
  -0.25,  1.0/3.0, -0.5,  0, |         0,          0      L_R   |  0
  */
  double LUB[30] = {12,    4,          8,    0,  29.0 / 81.0, -38.0 / 81.0,
                    -0.5,  9,          6,    3,  10.0 / 27.0, -1.0 / 27.0,
                    0,     1.0 / 3.0,  -6,   -4, -2.0 / 9.0,  2.0 / 9.0,
                    0.25,  -1.0 / 3.0, -1,   -6, 1.0 / 3.0,   -1.0 / 3.0,
                    -0.25, 1.0 / 3.0,  -0.5, 0,  0,           0};

  ksl_linalg_lu_setBMatrix_rmo(4, 6, LU);

  ck_assert(ksl_allclose(30, LU, LUB));
}
END_TEST

START_TEST(test_linalg_lu_setCMatrix_rmo) {

  /*
  5 by 6 matrix contains 4 by 4 L_r union U_r, 4 by 2 U_R, 1 by 4 L_R matrices
     12,        4,    8,  0, |  4, -4,
   -0.5,        9,    6,  3, |  3,  0,
      0,  1.0/3.0,   -6, -4, |  0,  0,
   0.25, -1.0/3.0,   -1, -6, | -2,  2,  L_r||U_r | U_R
  ———————————————————————————————————   ————————————
  -0.25,  1.0/3.0, -0.5,  0, |  0,  0    L_R   |  0
  */
  double LU[30] = {12,    4,         8,    0,          4,  -4,        -0.5, 9,
                   6,     3,         3,    0,          0,  1.0 / 3.0, -6,   -4,
                   0,     0,         0.25, -1.0 / 3.0, -1, -6,        -2,   2,
                   -0.25, 1.0 / 3.0, -0.5, 0,          0,  0};

  /*
  5 by 6 matrix contains 4 by 4 L_r union U_r, 4 by 2 U_R, 1 by 4 C matrices
     12,        4,    8,  0, |  4, -4,
   -0.5,        9,    6,  3, |  3,  0,
      0,  1.0/3.0,   -6, -4, |  0,  0,
   0.25, -1.0/3.0,   -1, -6, | -2,  2,  L_r||U_r | U_R
  ———————————————————————————————————   ————————————
      0,      0.5, -0.5,  0, |  0,  0     C    |  0
  */
  double LUC[30] = {12, 4,  8,  0,         4,  -4,  -0.5, 9, 6,    3,
                    3,  0,  0,  1.0 / 3.0, -6, -4,  0,    0, 0.25, -1.0 / 3.0,
                    -1, -6, -2, 2,         0,  0.5, -0.5, 0, 0,    0};

  ksl_linalg_lu_setCMatrix_rmo(5, 6, 4, LU);

  ck_assert(ksl_allclose(30, LU, LUC));
}
END_TEST

START_TEST(test_linalg_ldlt_rmo) {

  /*
  4,        3,        2,         1,
  3, 21.0/4.0,  7.0/2.0,   7.0/4.0,
  2,  7.0/2.0, 13.0/3.0,  13.0/6.0,
  1,  7.0/4.0, 13.0/6.0, 25.0/12.0
  */
  double A[16] = {4, 3,          2,          1,
                  3, 21.0 / 4.0, 7.0 / 2.0,  7.0 / 4.0,
                  2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                  1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};

  /*
     4,     0.75,      0.5,     0.25,
  0.75,        3,  2.0/3.0,  1.0/3.0,
   0.5,  2.0/3.0,        2,      0.5,
  0.25,  1.0/3.0,      0.5,        1
  */
  double LDLT[16] = {4,         0.75,      0.5, 0.25,      0.75, 3,
                     2.0 / 3.0, 1.0 / 3.0, 0.5, 2.0 / 3.0, 2,    0.5,
                     0.25,      1.0 / 3.0, 0.5, 1};

  ksl_linalg_ldlt_rmo(A, 4);

  ck_assert(ksl_allclose(16, A, LDLT));
}
END_TEST

START_TEST(test_linalg_cholesky_rmo) {

  /*
  4,        3,        2,         1,
  3, 21.0/4.0,  7.0/2.0,   7.0/4.0,
  2,  7.0/2.0, 13.0/3.0,  13.0/6.0,
  1,  7.0/4.0, 13.0/6.0, 25.0/12.0
  */
  double A[16] = {4, 3,          2,          1,
                  3, 21.0 / 4.0, 7.0 / 2.0,  7.0 / 4.0,
                  2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                  1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};

  /*
    2,             1.5,               1,         0.5,
  1.5,         sqrt(3), 2.0*sqrt(3)/3.0, sqrt(3)/3.0,
    1, 2.0*sqrt(3)/3.0,         sqrt(2), sqrt(2)/2.0,
  0.5,     sqrt(3)/3.0,     sqrt(2)/2.0,           1
  */
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

  ksl_linalg_cholesky_rmo(A, 4);

  ck_assert(ksl_allclose(16, A, UTU));
}
END_TEST

START_TEST(test_linalg_ldlt_forwardElimination_rmo) {

  /*
     4,     0.75,      0.5,     0.25,
  0.75,        3,  2.0/3.0,  1.0/3.0,
   0.5,  2.0/3.0,        2,      0.5,
  0.25,  1.0/3.0,      0.5,        1
  */
  double LDLT[16] = {4,         0.75,      0.5, 0.25,      0.75, 3,
                     2.0 / 3.0, 1.0 / 3.0, 0.5, 2.0 / 3.0, 2,    0.5,
                     0.25,      1.0 / 3.0, 0.5, 1};

  double b[4] = {8, 18, 12, 2};
  double y[4];
  double yB[4] = {8, 12, 0, -4};

  ksl_linalg_ldlt_forwardElimination_rmo(LDLT, b, y, 4);

  ck_assert(ksl_allclose(4, y, yB));
}

END_TEST

START_TEST(test_linalg_ldlt_backwardSubstitution_rmo) {

  /*
     4,     0.75,      0.5,     0.25,
  0.75,        3,  2.0/3.0,  1.0/3.0,
   0.5,  2.0/3.0,        2,      0.5,
  0.25,  1.0/3.0,      0.5,        1
  */
  double LDLT[16] = {4,         0.75,      0.5, 0.25,      0.75, 3,
                     2.0 / 3.0, 1.0 / 3.0, 0.5, 2.0 / 3.0, 2,    0.5,
                     0.25,      1.0 / 3.0, 0.5, 1};
  double y[4] = {2, 4, 0, -4};
  double x[4];
  double xB[4] = {-1, 4, 2, -4};

  ksl_linalg_ldlt_backwardSubstitution_rmo(LDLT, y, x, 4);

  ck_assert(ksl_allclose(4, x, xB));
}
END_TEST

START_TEST(test_linalg_cholesky_forwardElimination_rmo) {

  /*
    2,             1.5,               1,         0.5,
  1.5,         sqrt(3), 2.0*sqrt(3)/3.0, sqrt(3)/3.0,
    1, 2.0*sqrt(3)/3.0,         sqrt(2), sqrt(2)/2.0,
  0.5,     sqrt(3)/3.0,     sqrt(2)/2.0,           1
  */
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

  double b[4] = {8, 18, 12, 2};
  double y[4];
  double yB[4] = {4, 4 * sqrt(3), 0, -4};

  ksl_linalg_cholesky_forwardElimination_rmo(UTU, b, y, 4);

  ck_assert(ksl_allclose(4, y, yB));
}
END_TEST

START_TEST(test_linalg_cholesky_backwardSubstitution_rmo) {

  /*
    2,             1.5,               1,         0.5,
  1.5,         sqrt(3), 2.0*sqrt(3)/3.0, sqrt(3)/3.0,
    1, 2.0*sqrt(3)/3.0,         sqrt(2), sqrt(2)/2.0,
  0.5,     sqrt(3)/3.0,     sqrt(2)/2.0,           1
  */
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

  double y[4] = {4, 4 * sqrt(3), 0, -4};
  double x[4];
  double xB[4] = {-1, 4, 2, -4};

  ksl_linalg_cholesky_backwardSubstitution_rmo(UTU, y, x, 4);

  ck_assert(ksl_allclose(4, x, xB));
}
END_TEST

START_TEST(test_linalg_ldlt_solve_rmo) {

  /*
     4,     0.75,      0.5,     0.25,
  0.75,        3,  2.0/3.0,  1.0/3.0,
   0.5,  2.0/3.0,        2,      0.5,
  0.25,  1.0/3.0,      0.5,        1
  */
  double LDLT[16] = {4,         0.75,      0.5, 0.25,      0.75, 3,
                     2.0 / 3.0, 1.0 / 3.0, 0.5, 2.0 / 3.0, 2,    0.5,
                     0.25,      1.0 / 3.0, 0.5, 1};

  double b[4] = {8, 18, 12, 2};
  double x[4];
  double xB[4] = {-1, 4, 2, -4};

  ksl_linalg_ldlt_solve_rmo(LDLT, b, x, 4);

  ck_assert(ksl_allclose(4, x, xB));
}
END_TEST

START_TEST(test_linalg_cholesky_solve_rmo) {

  /*
    2,             1.5,               1,         0.5,
  1.5,         sqrt(3), 2.0*sqrt(3)/3.0, sqrt(3)/3.0,
    1, 2.0*sqrt(3)/3.0,         sqrt(2), sqrt(2)/2.0,
  0.5,     sqrt(3)/3.0,     sqrt(2)/2.0,           1
  */
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
  double b[4] = {8, 18, 12, 2};
  double x[4];
  double xB[4] = {-1, 4, 2, -4};

  ksl_linalg_cholesky_solve_rmo(UTU, b, x, 4);

  ck_assert(ksl_allclose(4, x, xB));
}
END_TEST

START_TEST(test_linalg_symmetricMatrixInverse_rmo) {

  /*
  4,        3,        2,         1,
  3, 21.0/4.0,  7.0/2.0,   7.0/4.0,
  2,  7.0/2.0, 13.0/3.0,  13.0/6.0,
  1,  7.0/4.0, 13.0/6.0, 25.0/12.0
  */
  double A[16] = {4, 3,          2,          1,
                  3, 21.0 / 4.0, 7.0 / 2.0,  7.0 / 4.0,
                  2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                  1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};

  /*
  7.0/16.0,     -0.25,        0,    0,
     -0.25,   5.0/9.0, -1.0/3.0,    0,
         0,  -1.0/3.0,  3.0/4.0, -0.5,
         0,         0,     -0.5,    1
  */
  double AI[16] = {7.0 / 16.0, -0.25, 0,    0,          -0.25,     5.0 / 9.0,
                   -1.0 / 3.0, 0,     0,    -1.0 / 3.0, 3.0 / 4.0, -0.5,
                   0,          0,     -0.5, 1};

  ksl_linalg_symmetricMatrixInverse_rmo(A, 4);

  ck_assert(ksl_allclose(16, A, AI));
}
END_TEST

START_TEST(test_linalg_lu_full_cmo) {

  /*
  5 by 6 matrix has rank 4
   3,  1, -3,  3,  0,  2,
   2,  2, -6,  3,  1,  7,
  -4,  0,  0, -3,  1,  3,
   8, -4, 12,  0,  4,  4,
   6,  1,  3, -3, -2, -2
  */
  double A[30] = {3, 2, -4, 8, 6,  1, 2, 0, -4, 1,  -3, -6, 0, 12, 3,
                  3, 3, -3, 0, -3, 0, 1, 1, 4,  -2, 2,  7,  3, 4,  -2};

  /*
  5 by 6 matrix contains 4 by 4 L_r union U_r, 4 by 2 U_R, 1 by 4 L_R matrices
     12,        4,    8,  0, |  4, -4,
   -0.5,        9,    6,  3, |  3,  0,
      0,  1.0/3.0,   -6, -4, |  0,  0,
   0.25, -1.0/3.0,   -1, -6, | -2,  2,  L_r||U_r | U_R
  ———————————————————————————————————   ————————————
  -0.25,  1.0/3.0, -0.5,  0, |  0,  0    L_R   |  0
  */
  double LU[30] = {12,         -0.5,      0,  0.25, -0.25, 4,  9,    1.0 / 3.0,
                   -1.0 / 3.0, 1.0 / 3.0, 8,  6,    -6,    -1, -0.5, 0,
                   3,          -4,        -6, 0,    4,     3,  0,    -2,
                   0,          -4,        0,  0,    2,     0};

  /* Row permutation array */
  int pr[5];

  /* Column permutation array */
  int pc[6];

  /* tol = eps*|A|_infinity */
  double eps = 1e-12;

  ksl_linalg_lu_full_cmo(5, 6, A, eps, pr, pc);

  ck_assert(ksl_allclose(30, A, LU));
}
END_TEST

START_TEST(test_linalg_lu_full_specified_cmo) {

  /*
  5 by 6 matrix has rank 4
   3,  1, -3,  3,  0,  2,
   2,  2, -6,  3,  1,  7,
  -4,  0,  0, -3,  1,  3,
   8, -4, 12,  0,  4,  4,
   6,  1,  3, -3, -2, -2
  */
  double A[30] = {3, 2, -4, 8, 6,  1, 2, 0, -4, 1,  -3, -6, 0, 12, 3,
                  3, 3, -3, 0, -3, 0, 1, 1, 4,  -2, 2,  7,  3, 4,  -2};

  /*
  5 by 6 matrix contains 4 by 4 L_r union U_r, 4 by 2 U_R, 1 by 4 L_R matrices
     12,        4,    8,  0, | -4,  4,
   -0.5,        9,    6,  3, |  0,  3,
      0,  1.0/3.0,   -6, -4, |  0,  0,
   0.25, -1.0/3.0,   -1, -6, |  2, -2,  L_r||U_r | U_R
  ———————————————————————————————————   ————————————
  -0.25,  1.0/3.0, -0.5,  0, |  0,  0    L_R   |  0
  */
  double LU[30] = {12,         -0.5,      0,  0.25, -0.25, 4,  9,    1.0 / 3.0,
                   -1.0 / 3.0, 1.0 / 3.0, 8,  6,    -6,    -1, -0.5, 0,
                   3,          -4,        -6, 0,    -4,    0,  0,    2,
                   0,          4,         3,  0,    -2,    0};

  /* Row permutation array */
  int pr[5];

  /* Column permutation array */
  int pc[6];

  /* tol = eps*|A|_infinity */
  double eps = 1e-12;

  ksl_linalg_lu_full_specified_cmo(5, 6, A, eps, pr, pc, 4);

  ck_assert(ksl_allclose(30, A, LU));
}

END_TEST

START_TEST(test_linalg_lu_cmo) {

  /*
  4 by 6 matrix has rank 4
  12,  4,  8,  0,  4, -4,
  -6,  7,  2,  3,  1,  2,
   0,  3, -4, -3,  1,  0,
   3, -2,  6, -3, -2,  1
  */
  double A[24] = {12, -6, 0,  3,  4, 7, 3, -2, 8,  2, -4, 6,
                  0,  3,  -3, -3, 4, 1, 1, -2, -4, 2, 0,  1};

  /*
  4 by 6 matrix contains 4 by 4 L_r union U_r, 4 by 2 U_R matrices
    12,        4,  8,  0, |  4, -4,
  -0.5,        9,  6,  3, |  3,  0,
     0,  1.0/3.0, -6, -4, |  0,  0,   L_r||U_r | U_R
  0.25, -1.0/3.0, -1, -6, | -2,  2
  */
  double LU[24] = {12, -0.5, 0,  0.25, 4,  9, 1.0 / 3.0, -1.0 / 3.0,
                   8,  6,    -6, -1,   0,  3, -4,        -6,
                   4,  3,    0,  -2,   -4, 0, 0,         2};

  ksl_linalg_lu_cmo(4, 6, A);

  ck_assert(ksl_allclose(24, A, LU));
}
END_TEST

START_TEST(test_linalg_lu_setBMatrix_cmo) {

  /*
  5 by 6 matrix contains 4 by 4 L_r union U_r, 4 by 2 U_R, 1 by 4 L_R matrices
     12,        4,    8,  0, |  4, -4,
   -0.5,        9,    6,  3, |  3,  0,
      0,  1.0/3.0,   -6, -4, |  0,  0,
   0.25, -1.0/3.0,   -1, -6, | -2,  2,  L_r||U_r | U_R
  ———————————————————————————————————   ————————————
  -0.25,  1.0/3.0, -0.5,  0, |  0,  0    L_R   |  0
  */
  double LU[30] = {12,         -0.5,      0,  0.25, -0.25, 4,  9,    1.0 / 3.0,
                   -1.0 / 3.0, 1.0 / 3.0, 8,  6,    -6,    -1, -0.5, 0,
                   3,          -4,        -6, 0,    4,     3,  0,    -2,
                   0,          -4,        0,  0,    2,     0};

  /*
  5 by 6 matrix contains 4 by 4 L_r union U_r, 4 by 2 B, 1 by 4 L_R matrices
     12,        4,    8,  0, | 29.0/81.0, -38.0/81.0,
   -0.5,        9,    6,  3, | 10.0/27.0,  -1.0/27.0,
      0,  1.0/3.0,   -6, -4, |  -2.0/9.0,    2.0/9.0,
   0.25, -1.0/3.0,   -1, -6, |   1.0/3.0,   -1.0/ .0,    L_r||U_r | B
  ———————————————————————————————————————————————————    ——————————
  -0.25,  1.0/3.0, -0.5,  0, |         0,          0       L_R  | 0
  */
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

  ksl_linalg_lu_setBMatrix_cmo(5, 6, 4, LU);

  ck_assert(ksl_allclose(30, LU, LUB));
}
END_TEST

START_TEST(test_linalg_lu_setCMatrix_cmo) {

  /*
  5 by 6 matrix contains 4 by 4 L_r union U_r, 4 by 2 U_R, 1 by 4 L_R matrices
     12,        4,    8,  0, |  4, -4,
   -0.5,        9,    6,  3, |  3,  0,
      0,  1.0/3.0,   -6, -4, |  0,  0,
   0.25, -1.0/3.0,   -1, -6, | -2,  2,  L_r||U_r | U_R
  ———————————————————————————————————   ————————————
  -0.25,  1.0/3.0, -0.5,  0, |  0,  0    L_R   |  0
  */
  double LU[30] = {12,         -0.5,      0,  0.25, -0.25, 4,  9,    1.0 / 3.0,
                   -1.0 / 3.0, 1.0 / 3.0, 8,  6,    -6,    -1, -0.5, 0,
                   3,          -4,        -6, 0,    4,     3,  0,    -2,
                   0,          -4,        0,  0,    2,     0};

  /*
  5 by 6 matrix contains 4 by 4 L_r union U_r, 4 by 2 U_R, 1 by 4 L_R matrices
     12,        4,    8,  0, |  4, -4,
   -0.5,        9,    6,  3, |  3,  0,
      0,  1.0/3.0,   -6, -4, |  0,  0,
   0.25, -1.0/3.0,   -1, -6, | -2,  2,  L_r||U_r | U_R
  ———————————————————————————————————   ————————————
      0,      0.5, -0.5,  0, |  0,  0     C    |  0
  */
  double LUC[30] = {12, -0.5, 0,  0.25, 0,    4,  9, 1.0 / 3.0, -1.0 / 3.0, 0.5,
                    8,  6,    -6, -1,   -0.5, 0,  3, -4,        -6,         0,
                    4,  3,    0,  -2,   0,    -4, 0, 0,         2,          0};

  ksl_linalg_lu_setCMatrix_cmo(5, 6, 4, LU);

  ck_assert(ksl_allclose(30, LU, LUC));
}
END_TEST

START_TEST(test_linalg_ldlt_cmo) {

  /*
  4,        3,        2,         1,
  3, 21.0/4.0,  7.0/2.0,   7.0/4.0,
  2,  7.0/2.0, 13.0/3.0,  13.0/6.0,
  1,  7.0/4.0, 13.0/6.0, 25.0/12.0
  */
  double A[16] = {4, 3,          2,          1,
                  3, 21.0 / 4.0, 7.0 / 2.0,  7.0 / 4.0,
                  2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                  1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};

  /*
     4,     0.75,      0.5,     0.25,
  0.75,        3,  2.0/3.0,  1.0/3.0,
   0.5,  2.0/3.0,        2,      0.5,
  0.25,  1.0/3.0,      0.5,        1
  */
  double LDLT[16] = {4,         0.75,      0.5, 0.25,      0.75, 3,
                     2.0 / 3.0, 1.0 / 3.0, 0.5, 2.0 / 3.0, 2,    0.5,
                     0.25,      1.0 / 3.0, 0.5, 1};

  ksl_linalg_ldlt_cmo(A, 4);

  ck_assert(ksl_allclose(16, A, LDLT));
}
END_TEST

START_TEST(test_linalg_cholesky_cmo) {

  /*
  4,        3,        2,         1,
  3, 21.0/4.0,  7.0/2.0,   7.0/4.0,
  2,  7.0/2.0, 13.0/3.0,  13.0/6.0,
  1,  7.0/4.0, 13.0/6.0, 25.0/12.0
  */
  double A[16] = {4, 3,          2,          1,
                  3, 21.0 / 4.0, 7.0 / 2.0,  7.0 / 4.0,
                  2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                  1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};

  /*
    2,             1.5,               1,         0.5,
  1.5,         sqrt(3), 2.0*sqrt(3)/3.0, sqrt(3)/3.0,
    1, 2.0*sqrt(3)/3.0,         sqrt(2), sqrt(2)/2.0,
  0.5,     sqrt(3)/3.0,     sqrt(2)/2.0,           1
  */
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

  ksl_linalg_cholesky_cmo(A, 4);

  ck_assert(ksl_allclose(16, A, UTU));
}
END_TEST

START_TEST(test_linalg_ldlt_forwardElimination_cmo) {

  /*
     4,     0.75,      0.5,     0.25,
  0.75,        3,  2.0/3.0,  1.0/3.0,
   0.5,  2.0/3.0,        2,      0.5,
  0.25,  1.0/3.0,      0.5,        1
  */
  double LDLT[16] = {4,         0.75,      0.5, 0.25,      0.75, 3,
                     2.0 / 3.0, 1.0 / 3.0, 0.5, 2.0 / 3.0, 2,    0.5,
                     0.25,      1.0 / 3.0, 0.5, 1};
  double b[4] = {8, 18, 12, 2};
  double y[4];
  double yB[4] = {8, 12, 0, -4};

  ksl_linalg_ldlt_forwardElimination_cmo(LDLT, b, y, 4);

  ck_assert(ksl_allclose(4, y, yB));
}
END_TEST

START_TEST(test_linalg_ldlt_backwardSubstitution_cmo) {

  /*
     4,     0.75,      0.5,     0.25,
  0.75,        3,  2.0/3.0,  1.0/3.0,
   0.5,  2.0/3.0,        2,      0.5,
  0.25,  1.0/3.0,      0.5,        1
  */
  double LDLT[16] = {4,         0.75,      0.5, 0.25,      0.75, 3,
                     2.0 / 3.0, 1.0 / 3.0, 0.5, 2.0 / 3.0, 2,    0.5,
                     0.25,      1.0 / 3.0, 0.5, 1};
  double y[4] = {2, 4, 0, -4};
  double x[4];
  double xB[4] = {-1, 4, 2, -4};

  ksl_linalg_ldlt_backwardSubstitution_cmo(LDLT, y, x, 4);

  ck_assert(ksl_allclose(4, x, xB));
}
END_TEST

START_TEST(test_linalg_cholesky_forwardElimination_cmo) {

  /*
    2,             1.5,               1,         0.5,
  1.5,         sqrt(3), 2.0*sqrt(3)/3.0, sqrt(3)/3.0,
    1, 2.0*sqrt(3)/3.0,         sqrt(2), sqrt(2)/2.0,
  0.5,     sqrt(3)/3.0,     sqrt(2)/2.0,           1
  */
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
  double b[4] = {8, 18, 12, 2};
  double y[4];
  double yB[4] = {4, 4 * sqrt(3), 0, -4};

  ksl_linalg_cholesky_forwardElimination_cmo(UTU, b, y, 4);

  ck_assert(ksl_allclose(4, y, yB));
}
END_TEST

START_TEST(test_linalg_cholesky_backwardSubstitution_cmo) {

  /*
    2,             1.5,               1,         0.5,
  1.5,         sqrt(3), 2.0*sqrt(3)/3.0, sqrt(3)/3.0,
    1, 2.0*sqrt(3)/3.0,         sqrt(2), sqrt(2)/2.0,
  0.5,     sqrt(3)/3.0,     sqrt(2)/2.0,           1
  */
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

  double y[4] = {4, 4 * sqrt(3), 0, -4};
  double x[4];
  double xB[4] = {-1, 4, 2, -4};

  ksl_linalg_cholesky_backwardSubstitution_cmo(UTU, y, x, 4);

  ck_assert(ksl_allclose(4, x, xB));
}
END_TEST

START_TEST(test_linalg_ldlt_solve_cmo) {

  /*
     4,     0.75,      0.5,     0.25,
  0.75,        3,  2.0/3.0,  1.0/3.0,
   0.5,  2.0/3.0,        2,      0.5,
  0.25,  1.0/3.0,      0.5,        1
  */
  double LDLT[16] = {4,         0.75,      0.5, 0.25,      0.75, 3,
                     2.0 / 3.0, 1.0 / 3.0, 0.5, 2.0 / 3.0, 2,    0.5,
                     0.25,      1.0 / 3.0, 0.5, 1};

  double b[4] = {8, 18, 12, 2};
  double x[4];
  double xB[4] = {-1, 4, 2, -4};

  ksl_linalg_ldlt_solve_cmo(LDLT, b, x, 4);

  ck_assert(ksl_allclose(4, x, xB));
}
END_TEST

START_TEST(test_linalg_cholesky_solve_cmo) {

  /*
    2,             1.5,               1,         0.5,
  1.5,         sqrt(3), 2.0*sqrt(3)/3.0, sqrt(3)/3.0,
    1, 2.0*sqrt(3)/3.0,         sqrt(2), sqrt(2)/2.0,
  0.5,     sqrt(3)/3.0,     sqrt(2)/2.0,           1
  */
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
  double b[4] = {8, 18, 12, 2};
  double x[4];
  double xB[4] = {-1, 4, 2, -4};

  ksl_linalg_cholesky_solve_cmo(UTU, b, x, 4);

  ck_assert(ksl_allclose(4, x, xB));
}
END_TEST

START_TEST(test_linalg_symmetricMatrixInverse_cmo) {

  /*
  4,        3,        2,         1,
  3, 21.0/4.0,  7.0/2.0,   7.0/4.0,
  2,  7.0/2.0, 13.0/3.0,  13.0/6.0,
  1,  7.0/4.0, 13.0/6.0, 25.0/12.0
  */
  double A[16] = {4, 3,          2,          1,
                  3, 21.0 / 4.0, 7.0 / 2.0,  7.0 / 4.0,
                  2, 7.0 / 2.0,  13.0 / 3.0, 13.0 / 6.0,
                  1, 7.0 / 4.0,  13.0 / 6.0, 25.0 / 12.0};

  /*
  7.0/16.0,     -0.25,        0,    0,
     -0.25,   5.0/9.0, -1.0/3.0,    0,
         0,  -1.0/3.0,  3.0/4.0, -0.5,
         0,         0,     -0.5,    1
  */
  double AI[16] = {7.0 / 16.0, -0.25, 0,    0,          -0.25,     5.0 / 9.0,
                   -1.0 / 3.0, 0,     0,    -1.0 / 3.0, 3.0 / 4.0, -0.5,
                   0,          0,     -0.5, 1};

  ksl_linalg_symmetricMatrixInverse_cmo(A, 4);

  ck_assert(ksl_allclose(16, A, AI));
}
END_TEST

/* -------- Householder QR, Jacobi SVD, null spaces, mobility numbers -------- */

static unsigned long long linalg_seed = 20261112ULL;
static double linalg_uniform(void) {
  linalg_seed = linalg_seed * 6364136223846793005ULL + 1442695040888963407ULL;
  return (double)(linalg_seed >> 11) / 9007199254740992.0 * 2.0 - 1.0;
}

/* row major m by n matrix of rank r, the product of m by r and r by n */
static void random_of_rank(int m, int n, int r, double* a) {
  double x[64], y[64];
  for(int i = 0; i < m * r; i++) x[i] = linalg_uniform();
  for(int i = 0; i < r * n; i++) y[i] = linalg_uniform();
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      double v = 0.0;
      for(int k = 0; k < r; k++) v += x[i * r + k] * y[k * n + j];
      a[i * n + j] = v;
    }
  }
}

static double max_abs_diff(int n, const double* a, const double* b) {
  double d = 0.0;
  for(int i = 0; i < n; i++) d = fmax(d, fabs(a[i] - b[i]));
  return d;
}

/* c = a b, row major, a m by k, b k by n */
static void mul(int m, int k, int n, const double* a, const double* b, double* c) {
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      double v = 0.0;
      for(int l = 0; l < k; l++) v += a[i * k + l] * b[l * n + j];
      c[i * n + j] = v;
    }
  }
}

static void transpose(int m, int n, const double* a, double* t) {
  for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++) t[j * m + i] = a[i * n + j];
}

START_TEST(test_linalg_qr_householder) {
  const int shapes[3][3] = {{5, 7, 3}, {6, 4, 4}, {4, 4, 2}};
  for(int c = 0; c < 3; c++) {
    const int m = shapes[c][0], n = shapes[c][1], r = shapes[c][2];
    double a[64], rr[64], q[64], qr[64], qt[64], qtq[64], id[64];
    random_of_rank(m, n, r, a);
    memcpy(rr, a, sizeof(double) * m * n);
    ksl_linalg_qr_householder_rmo(m, n, rr, q);
    mul(m, m, n, q, rr, qr);
    ck_assert(max_abs_diff(m * n, qr, a) < 1e-13);
    transpose(m, m, q, qt);
    mul(m, m, m, qt, q, qtq);
    for(int i = 0; i < m * m; i++) id[i] = (i % (m + 1) == 0) ? 1.0 : 0.0;
    ck_assert(max_abs_diff(m * m, qtq, id) < 1e-14);
    for(int i = 0; i < m; i++)
      for(int j = 0; j < i && j < n; j++) ck_assert(rr[i * n + j] == 0.0);
    /* column major: the same factors, transposed storage */
    double ac[64], qc[64];
    transpose(m, n, a, ac);
    ksl_linalg_qr_householder_cmo(m, n, ac, qc);
    double rt[64], qtt[64];
    transpose(n, m, ac, rt);
    transpose(m, m, qc, qtt);
    ck_assert(max_abs_diff(m * n, rt, rr) < 1e-14);
    ck_assert(max_abs_diff(m * m, qtt, q) < 1e-14);
  }
}
END_TEST

START_TEST(test_linalg_svd_jacobi) {
  const int shapes[3][3] = {{4, 5, 3}, {6, 4, 4}, {5, 5, 2}};
  for(int c = 0; c < 3; c++) {
    const int m = shapes[c][0], n = shapes[c][1], r = shapes[c][2];
    double a[64], w[64], v[64], sigma[8], vt[64], wvt[64], vtv[64], id[64];
    random_of_rank(m, n, r, a);
    memcpy(w, a, sizeof(double) * m * n);
    int sweeps = ksl_linalg_svd_jacobi_rmo(m, n, w, sigma, v);
    ck_assert(sweeps > 0);
    transpose(n, n, v, vt);
    mul(m, n, n, w, vt, wvt);
    ck_assert(max_abs_diff(m * n, wvt, a) < 1e-13);
    mul(n, n, n, vt, v, vtv);
    for(int i = 0; i < n * n; i++) id[i] = (i % (n + 1) == 0) ? 1.0 : 0.0;
    ck_assert(max_abs_diff(n * n, vtv, id) < 1e-14);
    for(int i = 0; i < n; i++) {
      if(i > 0) ck_assert(sigma[i] <= sigma[i - 1] + 1e-15);
      for(int j = i + 1; j < n; j++) {
        double d = 0.0;
        for(int l = 0; l < m; l++) d += w[l * n + i] * w[l * n + j];
        ck_assert(fabs(d) < 1e-13);
      }
    }
    /* rank r: sigma_r and beyond vanish; the last columns of V are a null space */
    for(int i = r; i < n; i++) ck_assert(sigma[i] < 1e-13);
    double av[64];
    mul(m, n, n, a, v, av);
    for(int i = 0; i < m; i++)
      for(int j = r; j < n; j++) ck_assert(fabs(av[i * n + j]) < 1e-13);
    /* column major gives the same singular values */
    double ac[64], vc[64], sc[8];
    transpose(m, n, a, ac);
    ck_assert(ksl_linalg_svd_jacobi_cmo(m, n, ac, sc, vc) > 0);
    ck_assert(max_abs_diff(n, sc, sigma) < 1e-13);
  }
}
END_TEST

START_TEST(test_linalg_lu_nullSpaces) {
  const int m = 4, n = 6, r = 3;
  double a[24], lu[24], z[18], y[4], az[12], ya[6];
  int pr[4], pc[6];
  random_of_rank(m, n, r, a);
  memcpy(lu, a, sizeof lu);
  int rank = ksl_linalg_lu_full_rmo(m, n, lu, 1e-12, pr, pc);
  ck_assert_int_eq(rank, r);
  ksl_linalg_lu_setBMatrix_rmo(rank, n, lu);
  ksl_linalg_lu_setCMatrix_rmo(m, n, rank, lu);
  ksl_linalg_lu_nullSpace_rmo(rank, n, lu, pc, z);
  mul(m, n, n - r, a, z, az);
  for(int i = 0; i < m * (n - r); i++) ck_assert(fabs(az[i]) < 1e-13);
  ksl_linalg_lu_leftNullSpace_rmo(m, n, rank, lu, pr, y);
  mul(m - r, m, n, y, a, ya);
  for(int i = 0; i < (m - r) * n; i++) ck_assert(fabs(ya[i]) < 1e-13);
  /* the unit rows and columns are where the permutations put them */
  for(int j = 0; j < n - r; j++) ck_assert(z[pc[r + j] * (n - r) + j] == 1.0);
  ck_assert(y[pr[r]] == 1.0);
}
END_TEST

START_TEST(test_linalg_lu_solve_rmo) {
  const int m = 4, n = 6, r = 3;
  double a[24], lu[24], ad[9], x[3], b[3], bx[3];
  int pr[4], pc[6];
  random_of_rank(m, n, r, a);
  memcpy(lu, a, sizeof lu);
  int rank = ksl_linalg_lu_full_rmo(m, n, lu, 1e-12, pr, pc);
  ck_assert_int_eq(rank, r);
  /* A^d: the primary rows and dependent columns of A, in pivoted order */
  for(int i = 0; i < r; i++)
    for(int j = 0; j < r; j++) ad[i * r + j] = a[pr[i] * n + pc[j]];
  const double x0[3] = {0.5, -1.25, 2.0};
  mul(r, r, 1, ad, x0, b);
  ksl_linalg_lu_solve_rmo(rank, n, lu, b, x);
  for(int i = 0; i < r; i++) ck_assert(fabs(x[i] - x0[i]) < 1e-12);
  /* in place, and after the B and C matrices have been formed */
  ksl_linalg_lu_setBMatrix_rmo(rank, n, lu);
  ksl_linalg_lu_setCMatrix_rmo(m, n, rank, lu);
  memcpy(bx, b, sizeof b);
  ksl_linalg_lu_solve_rmo(rank, n, lu, bx, bx);
  for(int i = 0; i < r; i++) ck_assert(fabs(bx[i] - x0[i]) < 1e-12);
  /* the independent columns of A give the columns of B */
  for(int k = 0; k < n - r; k++) {
    for(int i = 0; i < r; i++) b[i] = a[pr[i] * n + pc[r + k]];
    ksl_linalg_lu_solve_rmo(rank, n, lu, b, x);
    for(int i = 0; i < r; i++) ck_assert(fabs(x[i] - lu[i * n + r + k]) < 1e-12);
  }
}
END_TEST

START_TEST(test_linalg_mobilityNumbers) {
  const int m = 4, n = 6, r = 3, k = n - r;
  double a[24], lu[24], z[18], z0[18], mu[6];
  int pr[4], pc[6];
  random_of_rank(m, n, r, a);
  memcpy(lu, a, sizeof lu);
  ksl_linalg_lu_full_rmo(m, n, lu, 1e-12, pr, pc);
  ksl_linalg_lu_setBMatrix_rmo(r, n, lu);
  ksl_linalg_lu_nullSpace_rmo(r, n, lu, pc, z);
  memcpy(z0, z, sizeof z);
  ksl_linalg_mobilityNumbers_rmo(n, k, z, mu);
  /* against the diagonal of N (N^T N)^-1 N^T, with no orthonormalization */
  double nt[18], ntn[9], ntni[9], t[18], proj[36];
  transpose(n, k, z0, nt);
  mul(k, n, k, nt, z0, ntn);
  memcpy(ntni, ntn, sizeof ntn);
  ksl_linalg_symmetricMatrixInverse_rmo(ntni, k);
  mul(n, k, k, z0, ntni, t);
  mul(n, k, n, t, nt, proj);
  double sum = 0.0;
  for(int i = 0; i < n; i++) {
    ck_assert(fabs(mu[i] - proj[i * n + i]) < 1e-13);
    ck_assert(mu[i] >= -1e-15 && mu[i] <= 1.0 + 1e-15);
    sum += mu[i];
  }
  ck_assert(fabs(sum - k) < 1e-13);
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
  tcase_add_test(tc_core, test_linalg_lu_full_multiSpecified_rmo);
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
  tcase_add_test(tc_core, test_linalg_symmetricMatrixInverse_cmo);
  tcase_add_test(tc_core, test_linalg_qr_householder);
  tcase_add_test(tc_core, test_linalg_svd_jacobi);
  tcase_add_test(tc_core, test_linalg_lu_nullSpaces);
  tcase_add_test(tc_core, test_linalg_lu_solve_rmo);
  tcase_add_test(tc_core, test_linalg_mobilityNumbers);
  suite_add_tcase(s, tc_core);
  return s;
}

int main(void) {
  dbg = fopen("test_debug.txt", "wa");
  int number_failed;
  Suite* s = linalg_suite();
  SRunner* sr = srunner_create(s);
  srunner_set_log(sr, "check_linalg.log");
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  fclose(dbg);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
