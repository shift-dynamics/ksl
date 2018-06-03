/**
@file
@brief Utilities to perform vectorized LU and LDU decomposition with complete
row and column pivoting, based on nonvectorized version of LU decomposition
with complete row and column pivoting written by Roger Wehage.
@author Kristopher Wehage
@date 2016
@version 1.1
@remark
THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
SUCH DAMAGE.
*/
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifdef KSL_WITH_BLAS_
#ifdef __APPLE__
#include <Accelerate/Accelerate.h>
#else
#include <cblas.h>
#endif
#endif

#include "linalg.h"
#include "util.h"

/*
n: Number of entries in two arrays to swap.
a: First array to swap.
a_stride: Stride in array a for swap.
b: Second array to swap.
b_stride: Stride in array b for swap.
*/

inline void ksl_swapArray(const int n, double* restrict a, const int a_stride,
                          double* restrict b, const int b_stride) {
  for(int i = 0; i < n; i++) {
    ksl_swap(a + i * a_stride, b + i * b_stride);
  }
}

/*
n: Number of entries in array a.
a: Array in which to locate index of absolutely largest entry.
Return index of absolutely largest entry in a.
*/
inline int ksl_maxIndex(const int n, const double* restrict a) {
  register double max = fabs(a[0]);
  int max_index = 0;
  for(int i = 1; i < n; i++) {
    double a_abs = fabs(a[i]);
    if(a_abs > max) {
      max_index = i;
      max = a_abs;
    }
  }
  return max_index;
}

/*!
@brief Row Major Order LU Decomposition with complete row and column pivoting

ksl_linalg_lu_full_rmo factors a double precision matrix, A[rowDim * colDim],
stored in Row Major Order using full row and column pivoting. Matrix A need
not have full row or column rank. The integer variable 'rank' represents the
matrix rank and internally is always one less than the true rank to be
consistent with C's indexing from zero. Upon return from the function,
rank will be set to the correct value.

The lower triangular (rank+1) by (rank+1) Lr matrix, except its unity
diagonal, is stored below the diagonal in A[0:rank][0:rank]. The upper
triangular (rank+1) by (rank+1) Ur matrix is stored on and above the
diagonal in A[0:rank][0:rank].

Following the first major matrix decomposition step, A[0:rank][rank+1:colDim]
stores the residual matrix UR and A[rank+1:rowDim][0:rank] stores the residual
matrix LR.

The following operations on this matrix are optionally performed after
ksl_linalg_lu_full_rmo() has factored A.

ksl_linalg_lu_setBMatrix_rmo() computes and stores B = inverse(Ur)*UR and stores
it back in A[0:rank][rank+1:colDim].
ksl_linalg_lu_setCMatrix_rmo() computes and stores C = LR*inverse(Lr) and stores
it back in A[rank+1:rowDim][0:rank].

The remaining A[rank+1:rowDim][rank+1:colDim] submatrix contains numbers whose
absolute values are all smaller than eps times the absolutely largest
entry in the original matrix. This part of the matrix is not used.

@param rowDim [in] row dimension of matrix A.
@param colDim [in] column dimension of matrix A.
@param *A [in/out] matrix to be factored with dimensions
A[0:rowDim-1][0:colDim-1], LU factors are overwritten in original matrix
@param eps [in] input tolerance on the order of machine roundoff.
@param pr [out] output row permutation array with dimensions pr[0:rowDim-1]
@param pc [out] output column permutation array with dimensions pc[0:colDim-1]
@return rank of matrix A
*/
int ksl_linalg_lu_full_rmo(const int rowDim, const int colDim,
                           double* restrict A, const double eps,
                           int* restrict pr, int* restrict pc) {

  // printf("Jacobian matrix in fullFactor_LU\n");
  // for(int i = 0; i < rowDim; i++) {
  //   for(int j = 0; j < colDim; j++)
  //     printf("% 2.4f ", A[i * colDim + j]);
  //   printf("\n");
  // }

  int rank;     /* (rank+1) is the matrix rank */
  int pivotRow; /*  row with current pivotal element */
  int pivotCol; /* column with current pivotal element */
  double pivot = 0.0;
  /* current pivotal element, holds the current pivotal element
     value */
  double tol;                    /* tolerance for checking residual matrix
                                               infinity norm against */
  double save;                   /* variable for holding intermediate results*/
  double size = rowDim * colDim; /*overall size of matrix */

  /*
    Return failure if a bad row or column dimension was found.
  */
  if((rowDim <= 0) || (colDim <= 0)) {
    return (-1);
  }

  /*
    Consistent with C-indexing, rank always has a value of
    one less than the true value. rank+1 is returned.
  */
  rank = -1; /* initialize for indexing */

  /*
    Search through the entire A matrix to find the
    absolutely largest element for assigning to pivot.
    Save that row and column number in pivotRow and
    pivotCol. Also intialize the row permutation array pr.
  */
#ifdef KSL_WITH_BLAS_
  int index = cblas_idamax(size, A, 1);
#else
  int index = ksl_maxIndex(size, A);
#endif
  // div_t result = div(index, colDim);
  // pivotRow = result.quot;
  // pivotCol = result.rem;
  pivotRow = index / colDim;
  pivotCol = index - pivotRow * colDim;
  pivot = A[index];
  // printf("pivotRow: %d, pivotCol: %d\n", pivotRow, pivotCol);

  /* Initialize the column permutation array. */
  for(int col = 0; col < colDim; col++) {
    pc[col] = col;
  }
  for(int row = 0; row < rowDim; row++) {
    pr[row] = row;
  }

  /* Set tolerance to check all zero-elements against.
  pivot = infinity norm of A.
  */
  tol = fabs(eps * pivot);

  /*
    Major loop to permute and factor the matrix.
    Generate factors column by column, so outer loop
    sweeps over columns.
  */
  for(int col = 0; col < colDim; col++) {
    /*
      If the current pivotal element is <= tol, the
      remaining submatrix is zero and factorization
      is complete. The else statement for the following if test
      breaks out of this loop so not to waste time
      going through the remaining columns.
    */
    if(fabs(pivot) > tol) {
      /* Increase rank for the current column. */
      ++rank;

      /*
        pivotRow can never be less than rank.
        If pivotRow==rank, then no permutation is needed.
        If pivotRow>rank, then need to swap rows.
      */
      if(pivotRow > rank) {
        /*
          Swap entire rows A[rank][:] and A[pivotRow][:].
          This also swaps rows in the LR matrix to this point.

          swap rows:
            N = colDim
            stride = 1
          Start of replaced row is A + colDim * rank & stride is 1
          Start of pivot row is A + colDim * pivotRow & stride is 1
        */
#ifdef KSL_WITH_BLAS_
        cblas_dswap(colDim, A + colDim * rank, 1, A + colDim * pivotRow, 1);
#else
        ksl_swapArray(colDim, A + colDim * rank, 1, A + colDim * pivotRow, 1);
#endif
        /*
          Swap row permutation entries pr[rank] and
          pr[pivotRow] to reflect row swaps in A.
        */
        ksl_swapi(pr + rank, pr + pivotRow);
      }

      /* pivotCol can never be less than rank.
      If pivotCol==rank, then no permutation is needed.
      If pivotCol>rank, then need to swap columns. */
      if(pivotCol > rank) {
        // printf("rank: %d, pivotCol: %d\n", rank, pivotCol);
        // printf("colDim %d\n", colDim);
        /*
        Swap entire columns A[:][rank] and A[:][pivotCol].
        This also swaps columns in the UR matrix to this point.
        swap columns:
          N = rowDim
          stride = colDim
          Start of replaced column is A + rank & stride is colDim
          Start of pivot column is A + pivotCol & stride is colDim
            */
#ifdef KSL_WITH_BLAS_
        cblas_dswap(rowDim, A + rank, colDim, A + pivotCol, colDim);
#else
        ksl_swapArray(rowDim, A + rank, colDim, A + pivotCol, colDim);
#endif
        /*
          Swap column permutation entries pc[rank] and
          pr[pivotCol] to reflect column swaps.
        */
        ksl_swapi(pc + rank, pc + pivotCol);
      }

      /*
        rank cannot be > rowDim-1. If rank < rowDim-1
        there is still some processing left to do. If
        rank == rowDim-1, there is only a 1 on the
        diagonal of this column of Lr. This loop factors
        the matrix and searches for a new pivotal element
        for the next factorization step.
      */
      if(rank < rowDim - 1) {

        /*
          Copy the current pivotal element into save so new
          pivotal element can be stored back in pivot.
        */
        save = pivot;
        pivot = 0;

        /* Need only process the rows from rank+1 to rowDim. */
        for(int i = rank + 1; i < rowDim; i++) {

          /* Evaluate the current entry in the L matrix.*/
          A[i * colDim + rank] /= save;

          /*
            rank cannot be >= colDim. If rank < colDim
            there is still some processing left to do. If
            rank == colDim-1, only a pivot remains on the
            diagonal.
          */
          if(rank < colDim) {

            /*
              This next loop computes the remaining U matrix,
              searches for the largest pivotal element, and
              remembers the new pivotal element row and colum.
            */
            for(int j = rank + 1; j < colDim; j++) {
              A[i * colDim + j] -= A[i * colDim + rank] * A[rank * colDim + j];
              if(fabs(A[i * colDim + j]) > fabs(pivot)) {
                pivot = A[i * colDim + j];
                pivotRow = i;
                pivotCol = j;
              } /*End if*/
            }   /*End for j*/
          }     /*End if rank*/
        }       /*Endfor i = rank+1*/
      }         /*Endif (rank<rowDim-1)*/
      else {
        break; /*No more rows to process.*/
      }
    } /*End if*/
    else {
      break; /*Done if remainder of matrix is at noise level.*/
    }
  } /*End for col*/

  return (rank + 1);
}

/*!
@brief Row Major Order LU Decomposition with complete row and column pivoting
with one specified coordinate

ksl_linalg_lu_full_specified_rmo factors a double precision matrix, A[rowDim *
colDim], stored in Row Major Order using full row and column pivoting. Matrix A
need not have full row or column rank. The integer variable 'rank' represents
the matrix rank and internally is always one less than the true rank to be
consistent with C's indexing from zero. Upon return from the function,
rank will be set to the correct value.

The lower triangular (rank+1) by (rank+1) Lr matrix, except its unity
diagonal, is stored below the diagonal in A[0:rank][0:rank]. The upper
triangular (rank+1) by (rank+1) Ur matrix is stored on and above the
diagonal in A[0:rank][0:rank].

Following the first major matrix decomposition step, A[0:rank][rank+1:colDim]
stores the residual matrix UR and A[rank+1:rowDim][0:rank] stores the residual
matrix LR.

ksl_linalg_lu_setBMatrix_rmo() computes and stores B = inverse(Ur)*UR and stores
it back in A[0:rank][rank+1:colDim].
ksl_linalg_lu_setCMatrix_rmo() computes and stores C = LR*inverse(Lr) and stores
it back in A[rank+1:rowDim][0:rank].

The remaining A[rank+1:rowDim][rank+1:colDim-1] submatrix contains numbers whose
absolute values are all smaller than eps times the absolutely largest
entry in the original matrix. This part of the matrix is not used.
The remainig A[rank+1:rowDim][colDim] submatrix could contain numbers whose
absolute values are greater than eps times the absolutely largest
entry in the original matrix. Adding a check here would be one way to
assert that the specified variable has sufficient mobility.

@param rowDim input row dimension of matrix A.
@param colDim input column dimension of matrix A.
@param **A input/output matrix to be factored with dimensions
A[0:rowDim-1][0:colDim-1]:
@param eps input tolerance on the order of machine roundoff.
@param pr output row permutation array with dimensions pr[0:rowDim-1]
@param pc output column permutation array with dimensions pc[0:colDim-1]
@return rank of matrix A
*/
int ksl_linalg_lu_full_specified_rmo(const int rowDim, const int colDim,
                                     double* restrict A, double eps,
                                     int* restrict pr, int* restrict pc,
                                     const int specifiedIndex) {

  // printf("Jacobian matrix in fullFactor_LU\n");
  // for(int i = 0; i < rowDim; i++) {
  //   for(int j = 0; j < colDim; j++)
  //     printf("% 2.4f ", A[i * colDim + j]);
  //   printf("\n");
  // }

  int rank;     /* (rank+1) is the matrix rank */
  int pivotRow; /* row with current pivotal element */
  int pivotCol; /* column with current pivotal element */
  double pivot = 0.0;
  /* current pivotal element, holds the current pivotal element */
  double tol;                    /* tolerance for checking residual matrix
                                               infinity norm against */
  double save;                   /* variable for holding intermediate results*/
  double size = rowDim * colDim; /*overall size of matrix */

  /*
    Return failure if a bad row or column dimension was found.
  */
  if((rowDim <= 0) || (colDim <= 1)) {
    return (-1);
  }

  /*
    Consistent with C-indexing, rank always has a value of
    one less than the true value. rank+1 is returned.
  */
  rank = -1; /* initialize for indexing */

  /*
    Initialize permutation arrays
  */
  for(int row = 0; row < rowDim; row++) {
    pr[row] = row;
  }
  for(int col = 0; col < colDim; col++) {
    pc[col] = col;
  }

  /*
    Swap the specified column to the last position in the input
    matrix
    Swap entire columns A[:][specifiedIndex] and A[:][colDim - 1].
    swap columns:
      N = rowDim
      stride = colDim
      Start of specefied column is A + specifiedIndex & stride is colDim
      Start of last column is A + colDim - 1 & stride is colDim

  */
  if(specifiedIndex != colDim - 1) {
#ifdef KSL_WITH_BLAS
    cblas_dswap(rowDim, A + specifiedIndex, colDim, A + colDim - 1, colDim);
#else
    ksl_swapArray(rowDim, A + specifiedIndex, colDim, A + colDim - 1, colDim);
#endif
    /*
      Swap column permutation entries pc[] and
      pc[pivotRow] to reflect row swaps in A.
    */
    ksl_swapi(pc + specifiedIndex, pc + colDim - 1);
  }

  /*
    Search through matrix A except the last column to find the
    absolutely largest element for assigning to pivot.
    Save that row and column number in pivotRow and
    pivotCol. This could cause numerical problems if the last
    column contains one or more entries substantially absolutely
    larger than all other entries in A.
  */
  pivot = A[0];
  pivotRow = 0;
  pivotCol = 0;
  for(int row = 0; row < rowDim; row++) {
    for(int col = 0; col < colDim - 1; col++) {
      if(fabs(A[row * colDim + col]) > fabs(pivot)) {
        pivot = A[row * colDim + col];
        pivotRow = row;
        pivotCol = col;
      }
    }
  }
  // printf("pivotRow: %d, pivotCol: %d\n", pivotRow, pivotCol);

  /* Set tolerance to check all zero-elements against.
  pivot = infinity norm of A.
 */
  tol = fabs(eps * pivot);

  /*
    Major loop to permute and factor the matrix.
    Generate factors column by column, so outer loop
    sweeps over columns.
  */
  for(int col = 0; col < colDim; col++) {
    /*
    If the current pivotal element is <= tol, the
    remaining submatrix is zero and factorization
    is complete. The else statement for the following if test
    breaks out of this loop so not to waste time
    going through the remaining columns.
    */
    if(fabs(pivot) > tol) {
      /* Increase rank for the current column. */
      ++rank;

      /*
        pivotRow can never be less than rank.
        If pivotRow==rank, then no permutation is needed.
        If pivotRow>rank, then need to swap rows.
      */
      if(pivotRow > rank) {
        /*
          Need to swap entire row A[rank][:] and A[pivotRow][:].
          This also swaps rows in the Lr matrix to this point.
          swap rows:
            N = colDim
            stride = 1
          Start of replaced row is A + colDim * rank & stride is 1
          Start of pivot row is A + colDim * pivotRow & stride is 1
        */
#ifdef KSL_WITH_BLAS_
        cblas_dswap(colDim, A + colDim * rank, 1, A + colDim * pivotRow, 1);
#else
        ksl_swapArray(colDim, A + colDim * rank, 1, A + colDim * pivotRow, 1);
#endif
        /*
          Swap row permutation entries pr[rank] and
          pr[pivotRow] to reflect row swaps in A.
        */
        ksl_swapi(pr + rank, pr + pivotRow);
      }

      /*
        pivotCol can never be less than rank.
        If pivotCol==rank, then no permutation is needed.
        If pivotCol>rank, then need to swap columns.
      */
      if(pivotCol > rank) {
        // printf("rank: %d, pivotCol: %d\n", rank, pivotCol);
        // printf("colDim %d\n", colDim);
        /*
        Swap entire columns A[:][rank] and A[:][pivotCol].
        This also swaps columns in the UR matrix to this point.
        swap columns:
          N = rowDim
          stride = colDim
          Start of replaced column is A + rank & stride is colDim
          Start of pivot column is A + pivotCol & stride is colDim
        */
#ifdef KSL_WITH_BLAS_
        cblas_dswap(rowDim, A + rank, colDim, A + pivotCol, colDim);
#else
        ksl_swapArray(rowDim, A + rank, colDim, A + pivotCol, colDim);
#endif
        /*
          Swap column permutation entries pc[rank] and
          pr[pivotCol] to reflect column swaps.
        */
        ksl_swapi(pc + rank, pc + pivotCol);
      }

      /*
        rank cannot be > rowDim-1. If rank < rowDim-1
        there is still some processing left to do. If
        rank == rowDim-1, there is only a 1 on the
        diagonal of this column of Lr. This loop factors
        the matrix and searches for a new pivotal element
        for the next factorization step.
      */
      if(rank < rowDim - 1) {

        /*
          Copy the current pivotal element into save so new
          pivotal element can be stored back in pivot.
        */
        save = pivot;
        pivot = 0;

        /* Need only process the rows from rank+1 to rowDim. */
        for(int i = rank + 1; i < rowDim; i++) {

          /* Evaluate the current entry in the L matrix.*/
          A[i * colDim + rank] /= save;

          /*
            rank cannot be >= colDim. If rank < colDim
            there is still some processing left to do. If
            rank == colDim-1, only a pivot remains on the
            diagonal.
          */
          if(rank < colDim) {

            /*
              This next loop computes the remaining U matrix,
              searches for the largest pivotal element, and
              remembers the new pivotal element row and colum.
            */
            for(int j = rank + 1; j < colDim; j++) {
              A[i * colDim + j] -= A[i * colDim + rank] * A[rank * colDim + j];
            }
            for(int j = rank + 1; j < colDim - 1; j++) {
              if(fabs(A[i * colDim + j]) > fabs(pivot)) {
                pivot = A[i * colDim + j];
                pivotRow = i;
                pivotCol = j;
              } /*End if*/
            }   /*End for j*/
          }     /*End if rank*/
        }       /*Endfor i = rank+1*/
      }         /*Endif (rank<rowDim-1)*/
      else {
        break; /*No more rows to process.*/
      }
    } /*End if*/
    else {
      break; /*Done if remainder of matrix is at noise level.*/
    }
  } /*End for col*/
  return (rank + 1);
}

/*!
@brief *Fast* Row Major Order LU Decomposition with no row or column pivoting
for a rectangular matrix

This function LU factors a double precision matrix, A[rank][colDim],
using no row or column pivoting. This function should be used only if the
left rank by rank submatrix is known to be nonsingular.

rank <= colDim or error.

The lower triangular rank by rank Lr matrix, except the unity
diagonal, is stored below the diagonal in A[0:rank-1][0:rank-1]. The upper
triangular rank by rank Ur matrix is stored on and above the
diagonal in A[0:rank-1][0:rank-1].

Note that this minimal algorithm variation does not compute the product
B = inverse(Ur)*UR

@param rank [in] row dimension of matrix A.
@param colDim [in] column dimension of matrix A.
@param *A [in/out] matrix to be factored with dimensions
A[0:rank-1][0:colDim-1]:
*/
inline void ksl_linalg_lu_rmo(const int rank, const int colDim,
                              double* restrict A) {

  if(rank > colDim) {
    // Error message & exit
  }

  /*
    Major loop to factor the matrix.
    Generate factors column by column
  */
  for(int row = 0; row < rank; row++) {

    /* i iterates over rows of A, up to rank-1 */
    for(int i = row + 1; i < rank; i++) {

      /* Evaluate the current entry in the L matrix.*/
      A[i * colDim + row] /= A[row * colDim + row];

      /* Compute U matrix */
      for(int j = row + 1; j < colDim; j++) {
        A[i * colDim + j] -= A[i * colDim + row] * A[row * colDim + j];
      }
    }
  }
}

/*!
@brief compute Row Major Order B matrix (inverse(Ur) * UR)

This block overwrites UR with inverse(Ur) * UR
If rank == 0 or rank == colDim nothing to process, so exit with message.
This loop computes A[0:rank-1][rank:colDim-1] = inverse(Ur)*UR
where UR is stored in A[0:rank-1][rank:colDim-1]
and Ur is stored in upper part of A[0:rank-1][0:rank-1].
i is the row number in Ur.
j is the column number in Ur & row number in UR.
k is the column number in UR.

@param rowDim [in] row dimension of matrix A.
@param colDim [in] column dimension of matrix A.
@param rank [in] rank of matrix A.
@param *A [in/out] matrix with dimensions A[0:rowDim-1][0:colDim-1]:

*/
inline void ksl_linalg_lu_setBMatrix_rmo(const int rowDim, const int colDim,
                                         const int rank, double* restrict A) {

  if(rank > 0 && rank < colDim) {
    for(int i = rank - 1; i > -1; i--) {   /* rows of B */
      for(int k = rank; k < colDim; k++) { /* columns of B */
        double save = 0;
        for(int j = rank - 1; j > i; j--) { /* columns of Ur */
          save += A[i * colDim + j] * A[j * colDim + k];
        }
        A[i * colDim + k] = (A[i * colDim + k] - save) / A[i * colDim + i];
      }
    }
  } else {
    // Error & do something.
  }
}

/*!
@brief compute Row Major Order C matrix

This block overwrites LR with LR*inverse(Lr)
If rank==1, the Lr matrix is a 1 by 1 identity
matrix, so there is nothing to do here. This loop
computes A[rank:rowDim-1][0:rank-1]=LR*inverse(Lr)
where LR is stored in A[rank:rowDim-1][0:rank-1]
and Lr is stored in A[0:rank-1][0:rank-1].
j is the column number in LR. It ends at 1
because the diagonal entry in row 0 of Lr is 1.
i is the row number in LR.
k is the column number in Lr

@param rowDim [in] row dimension of matrix A.
@param colDim [in] column dimension of matrix A.
@param rank [in] rank of matrix A.
@param *A [in/out] matrix with dimensions A[0:rowDim-1][0:colDim-1]:

*/
void ksl_linalg_lu_setCMatrix_rmo(int rowDim, int colDim, int rank, double* A) {

  if(rank > 1) {
    for(int j = rank - 1; j > 0; j--) {
      for(int i = rowDim - 1; i > rank - 1; i--) {
        for(int k = 0; k < j; k++)
          A[i * colDim + k] -= A[i * colDim + j] * A[j * colDim + k];
      }
    }
  } else {
    // Error & do something.
  }
}

/*!
@brief computes the Row Major Order L D L^T decomposition of a symmetric
positive definite matrix without pivoting

returns the matrix L D L^T in the original matrix A

@param *A [in/out] matrix with dimensions A[0:n-1][0:n-1]:
@param n row and column dimension of matrix A.

*/
int ksl_linalg_ldlt_rmo(double* restrict A, const int n) {
  for(int k = 0; k < n; k++) {
    double pivot_inv = A[k * n + k];
    if(pivot_inv > 0.0) {
      pivot_inv = 1.0 / A[k * n + k];
    } else {
      return k + 1;
    }
    for(int j = k + 1; j < n; j++) {
      A[k * n + j] = A[j * n + k];
      A[j * n + k] *= pivot_inv;
    }
    for(int j = k + 1; j < n; j++) {
      for(int i = k + 1; i < j + 1; i++) {
        A[j * n + i] -= A[j * n + k] * A[k * n + i];
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      A[i * n + j] = A[j * n + i];
    }
  }
  return 0;
}

/*!
@brief perform Row Major Order Cholesky (L * L^T) decomposition of a symmetric
matrix without pivoting

returns the matrix factor L in the lower triangular portion of matrix A

@param *A [in/out] matrix with dimensions A[0:n-1][0:n-1]:
@param n row and column dimension of matrix A.

*/
int ksl_linalg_cholesky_rmo(double* restrict A, const int n) {
  for(int k = 0; k < n; k++) {
    if(A[k * n + k] > 0.0) {
      A[k * n + k] = sqrt(A[k * n + k]);
    } else {
      return k + 1;
    }
    double pivot_inv = 1.0 / A[k * n + k];
    for(int j = k + 1; j < n; j++) {
      A[j * n + k] *= pivot_inv;
    }
    for(int j = k + 1; j < n; j++) {
      for(int i = k + 1; i < j + 1; i++) {
        A[j * n + i] -= A[j * n + k] * A[i * n + k];
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      A[i * n + j] = A[j * n + i];
    }
  }
  return 0;
}

/*!
@brief used to solve a system of equations

L * y = b

for y using forward elimination where L IS Row Major Order unit lower triangular

y = L^-1 * b

@param *L [in] n by n matrix L[0:n-1][0:n-1]:
@param *b [in] n by 1 column of right-hand side y[0:n-1].
@param *y [out] n by 1 column of unknowns.
@param n [in] dimension of L[][], b[], y[]:

*/
inline void ksl_linalg_ldlt_forwardElimination_rmo(const double* restrict L,
                                                   const double* restrict b,
                                                   double* restrict y,
                                                   const int n) {
  for(int i = 0; i < n; i++) {
    y[i] = b[i];
    for(int j = 0; j < i; j++) {
      y[i] -= L[i * n + j] * y[j];
    }
  }
}

/*!
@brief used to solve a system of equations

L^T * x = y

using backward substitution where L IS Row Major Order unit lower triangular

x = L^-T * y

@param *L [in] n by n matrix L[0:n-1][0:n-1]:
@param *y [in] n by 1 column of right-hand side b[0:n-1].
@param *x [out] n by 1 column of unknowns.
@param n [in] dimension of L[][], y[], x[]:

*/
inline void ksl_linalg_ldlt_backwardSubstitution_rmo(const double* restrict L,
                                                     const double* restrict y,
                                                     double* restrict x,
                                                     const int n) {
  x[n - 1] = y[n - 1];
  for(int i = n - 2; i > -1; i--) {
    x[i] = y[i];
    for(int j = i + 1; j < n; j++) {
      x[i] -= L[j * n + i] * x[j];
    }
  }
}

/*!
@brief used to solve a system of equations

L * y = b

for y using forward elimination where L is Row Major Order and IS NOT unit lower
triangular

y = L^-1 * b

@param *L [in] n by n matrix L[0:n-1][0:n-1]:
@param *b [in] n by 1 column of right-hand side y[0:n-1].
@param *y [out] n by 1 column of unknowns.
@param n [in] dimension of L[][], b[], y[]:

*/
inline void ksl_linalg_cholesky_forwardElimination_rmo(const double* restrict L,
                                                       const double* restrict b,
                                                       double* restrict y,
                                                       const int n) {
  for(int i = 0; i < n; i++) {
    double t = b[i];
    for(int j = 0; j < i; j++) {
      t -= L[i * n + j] * y[j];
    }
    y[i] = t / L[i * n + i];
  }
}

/*!
@brief used to solve a system of equations

L^T * x = y

using backward substitution where L is Row Major Order and IS NOT unit lower
triangular

x = L^-T * y

@param *L [in] n by n matrix L[0:n-1][0:n-1]:
@param *y [in] n by 1 column of right-hand side y[0:n-1].
@param *x [out] n by 1 column of unknowns.
@param n [in] dimension of L[][], y[], x[]:

*/
inline void
ksl_linalg_cholesky_backwardSubstitution_rmo(const double* restrict L,
                                             const double* restrict y,
                                             double* restrict x, const int n) {
  x[n - 1] = y[n - 1] / L[(n - 1) * n + (n - 1)];
  for(int i = n - 2; i > -1; i--) {
    double t = y[i];
    for(int j = i + 1; j < n; j++) {
      t -= L[j * n + i] * x[j];
    }
    x[i] = t / L[i * n + i];
  }
}

/*!
@brief solve the system of equations A * x = b where A is Row Major Order and
a symmetric positive definite matrix A

ksl_linalg_ldlt must be called on A prior to calling this function

@param *A [in] n by n matrix A[0:n-1][0:n-1] containing Choleski-factored
matrix:
@param *b [in] n by 1 column of right-hand side y[0:n-1].
@param *x [out] n by 1 column of unknowns.
@param n [in] dimension of L[][], b[], y[]:

*/
inline void ksl_linalg_ldlt_solve_rmo(const double* restrict A,
                                      const double* restrict b,
                                      double* restrict x, const int n) {
  double y[n];
  ksl_linalg_ldlt_forwardElimination_rmo(A, b, y, n);
  for(int i = 0; i < n; i++) {
    y[i] /= A[i * n + i];
  }
  ksl_linalg_ldlt_backwardSubstitution_rmo(A, y, x, n);
}

/*!
@brief solve the system of equations A * x = b where A is Row Major Order and
a symmetric positive definite matrix A

ksl_linalg_cholesky must be called on A prior to calling this function

@param *L [in] n by n matrix L[0:n-1][0:n-1]:
@param *b [in] n by 1 column of right-hand side y[0:n-1].
@param *y [out] n by 1 column of unknowns.
@param n [in] dimension of L[][], b[], y[]:

*/
inline void ksl_linalg_cholesky_solve_rmo(const double* restrict A,
                                          const double* restrict b,
                                          double* restrict x, const int n) {
  double y[n];
  ksl_linalg_cholesky_forwardElimination_rmo(A, b, y, n);
  ksl_linalg_cholesky_backwardSubstitution_rmo(A, y, x, n);
}

/*!
@brief compute inverse of a symmetric positive definite matrix A
where A and A_inverse are in Row Major Order.
*/

inline int ksl_linalg_symmetricMatrixInverse_rmo(double* restrict A,
                                                 const int n) {
  int status = ksl_linalg_ldlt_rmo(A, n);
  if(status > 0) {
    return status;
  }
  for(int i = 0; i < n - 1; i++) {
    for(int j = i + 1; j < n; j++) {
      A[i * n + j] = 0.0;
    }
  }
  for(int i = 0; i < n; i++) {
    A[i * n + i] = 1.0 / A[i * n + i];
  }
  for(int i = n - 2; i >= 0; i--) {  // i = n-1:-1:1
    for(int j = n - 1; j > i; j--) { // j = n:-1:i+1
      for(int k = j; k > i; k--) {   // k = j:-1:i+1
        A[i * n + j] -=
          A[k * n + i] * A[k * n + j]; // A(i,j) = A(i,j) - A(k,i)*A(k,j);
      }
    }
  }
  for(int i = n - 2; i >= 0; i--) {    // i = n-1:-1:1
    for(int j = 0; j <= i; j++) {      // j = 1:1:i
      for(int k = i + 1; k < n; k++) { // k = i+1:1:n
        A[j * n + i] -=
          A[j * n + k] * A[k * n + i]; // A(j,i) = A(j,i) - A(j,k)*A(k,i);
      }
    }
  }
  for(int i = 0; i < n - 1; i++) {
    for(int j = i + 1; j < n; j++) {
      A[j * n + i] = A[i * n + j];
    }
  }
  return 0;
}

// inline int ksl_linalg_symmetricMatrixInverse_rmo(double* restrict A, const
// int n) {
//   double A_inverse[n * n];
//   double a[n];
//
//   int status = ksl_linalg_ldlt_rmo(A, n);
//   if(status > 0) {
//     return status;
//   }
//   for(int i = 0; i < n; i++) {
//     memset(a, 0, n * sizeof(double));
//     a[i] = 1.0;
//     ksl_linalg_ldlt_solve_rmo(A, a, &A_inverse[i * n + 0], n);
//   }
//   memcpy(A, A_inverse, n * n * sizeof(double));
//   return 0;
// }

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/*!
@brief Column Major Order LU Decomposition with complete row and column pivoting

ksl_linalg_lu_full_cmo factors a double precision matrix, A[rowDim * colDim],
stored in Column Major Order using full row and column pivoting. Matrix A need
not have full row or column rank. The integer variable 'rank' represents the
matrix rank and internally is always one less than the true rank to be
consistent with C's indexing from zero. Upon return from the function,
rank will be set to the correct value.

The lower triangular (rank+1) by (rank+1) Lr matrix, except its unity
diagonal, is stored below the diagonal in A[0:rank][0:rank]. The upper
triangular (rank+1) by (rank+1) Ur matrix is stored on and above the
diagonal in A[0:rank][0:rank].

Following the first major matrix decomposition step, A[0:rank][rank+1:colDim]
stores the residual matrix UR and A[rank+1:rowDim][0:rank] stores the residual
matrix LR.

The following operations on this matrix are optionally performed after
ksl_linalg_lu_full_cmo() has factored A.

ksl_linalg_lu_setBMatrix_cmo() computes and stores B = inverse(Ur)*UR and stores
it back in A[0:rank][rank+1:colDim].
ksl_linalg_lu_setCMatrix_cmo() computes and stores C = LR*inverse(Lr) and stores
it back in A[rank+1:rowDim][0:rank].

The remaining A[rank+1:rowDim][rank+1:colDim] submatrix contains numbers whose
absolute values are all smaller than eps times the absolutely largest
entry in the original matrix. This part of the matrix is not used.

@param rowDim [in] row dimension of matrix A.
@param colDim [in] column dimension of matrix A.
@param *A [in/out] matrix to be factored with dimensions
A[0:rowDim-1][0:colDim-1], LU factors are overwritten in original matrix
@param eps [in] input tolerance on the order of machine roundoff.
@param pr [out] output row permutation array with dimensions pr[0:rowDim-1]
@param pc [out] output column permutation array with dimensions pc[0:colDim-1]
@return rank of matrix A
*/
int ksl_linalg_lu_full_cmo(const int rowDim, const int colDim,
                           double* restrict A, const double eps,
                           int* restrict pr, int* restrict pc) {

  // printf("Jacobian matrix in fullFactor_LU\n");
  // for(int i = 0; i < rowDim; i++) {
  //   for(int j = 0; j < colDim; j++)
  //     printf("% 2.4f ", A[j * rowDim + i]);
  //   printf("\n");
  // }

  int rank;     /* (rank+1) is the matrix rank */
  int pivotRow; /*  row with current pivotal element */
  int pivotCol; /* column with current pivotal element */
  double pivot = 0.0;
  /* current pivotal element, holds the current pivotal element
     value */
  double tol;                    /* tolerance for checking residual matrix
                                               infinity norm against */
  double save;                   /* variable for holding intermediate results*/
  double size = rowDim * colDim; /*overall size of matrix */

  /*
    Return failure if a bad row or column dimension was found.
  */
  if((rowDim <= 0) || (colDim <= 0)) {
    return (-1);
  }

  /*
    Consistent with C-indexing, rank always has a value of
    one less than the true value. rank+1 is returned.
  */
  rank = -1; /* initialize for indexing */

  /*
    Search through the entire A matrix to find the
    absolutely largest element for assigning to pivot.
    Save that row and column number in pivotRow and
    pivotCol. Also intialize the row permutation array pr.
  */
#ifdef KSL_WITH_BLAS_
  int index = cblas_idamax(size, A, 1);
#else
  int index = ksl_maxIndex(size, A);
#endif
  // div_t result = div(index, colDim);
  // pivotRow = result.quot;
  // pivotCol = result.rem;
  pivotCol = index / rowDim;
  pivotRow = index - pivotCol * rowDim;
  pivot = A[index];
  // printf("pivotRow: %d, pivotCol: %d\n", pivotRow, pivotCol);

  /* Initialize the column permutation array. */
  for(int col = 0; col < colDim; col++) {
    pc[col] = col;
  }
  for(int row = 0; row < rowDim; row++) {
    pr[row] = row;
  }

  /* Set tolerance to check all zero-elements against.
  pivot = infinity norm of A.
  */
  tol = fabs(eps * pivot);

  /*
    Major loop to permute and factor the matrix.
    Generate factors column by column, so outer loop
    sweeps over columns.
  */
  for(int col = 0; col < colDim; col++) {
    /*
      If the current pivotal element is <= tol, the
      remaining submatrix is zero and factorization
      is complete. The else statement for the following if test
      breaks out of this loop so not to waste time
      going through the remaining columns.
    */
    if(fabs(pivot) > tol) {
      /* Increase rank for the current column. */
      ++rank;

      /*
        pivotRow can never be less than rank.
        If pivotRow==rank, then no permutation is needed.
        If pivotRow>rank, then need to swap rows.
      */
      if(pivotRow > rank) {
        /*
          Swap entire rows A[rank][:] and A[pivotRow][:].
          This also swaps rows in the LR matrix to this point.

          swap rows:
            N = colDim
            stride = rowDim
          Start of replaced row is A + rank & stride is rowDim
          Start of pivot row is A + pivotRow & stride is rowDim
        */
#ifdef KSL_WITH_BLAS_
        cblas_dswap(colDim, A + rank, rowDim, A + pivotRow, rowDim);
#else
        ksl_swapArray(colDim, A + rank, rowDim, A + pivotRow, rowDim);
#endif
        /*
          Swap row permutation entries pr[rank] and
          pr[pivotRow] to reflect row swaps in A.
        */
        ksl_swapi(pr + rank, pr + pivotRow);
      }

      /* pivotCol can never be less than rank.
      If pivotCol==rank, then no permutation is needed.
      If pivotCol>rank, then need to swap columns. */
      if(pivotCol > rank) {
        // printf("rank: %d, pivotCol: %d\n", rank, pivotCol);
        // printf("colDim %d\n", colDim);
        /*
        Swap entire columns A[:][rank] and A[:][pivotCol].
        This also swaps columns in the UR matrix to this point.
        swap columns:
          N = rowDim
          stride = 1
          Start of replaced column is A + rowDim * rank & stride is 1
          Start of pivot column is A + rowDim * pivotCol & stride is 1
            */
#ifdef KSL_WITH_BLAS_
        cblas_dswap(rowDim, A + rowDim * rank, 1, A + rowDim * pivotCol, 1);
#else
        ksl_swapArray(rowDim, A + rowDim * rank, 1, A + rowDim * pivotCol, 1);
#endif
        /*
          Swap column permutation entries pc[rank] and
          pr[pivotCol] to reflect column swaps.
        */
        ksl_swapi(pc + rank, pc + pivotCol);
      }

      /*
        rank cannot be > rowDim-1. If rank < rowDim-1
        there is still some processing left to do. If
        rank == rowDim-1, there is only a 1 on the
        diagonal of this column of Lr. This loop factors
        the matrix and searches for a new pivotal element
        for the next factorization step.
      */
      if(rank < rowDim - 1) {

        /*
          Copy the current pivotal element into save so new
          pivotal element can be stored back in pivot.
        */
        save = pivot;
        pivot = 0;

        /* Need only process the rows from rank+1 to rowDim. */
        for(int i = rank + 1; i < rowDim; i++) {

          /*
            Evaluate the current entry in the L matrix.
            (rank is always one less than the true rank.)
            The first rank columns of the A matrix are complete.
            Now working in column rank of the A matrix, so the offset
            to the start of the working column is rank * rowDim.
          */
          A[rank * rowDim + i] /= save;

          /*
            rank cannot be >= colDim. If rank < colDim
            there is still some processing left to do. If
            rank == colDim-1, only a pivot remains on the
            diagonal.
          */
          if(rank < colDim) {

            /*
              This next loop computes the remaining U matrix,
              searches for the largest pivotal element, and
              remembers the new pivotal element row and colum.
            */
            for(int j = rank + 1; j < colDim; j++) {
              A[j * rowDim + i] -= A[rank * rowDim + i] * A[j * rowDim + rank];
              if(fabs(A[j * rowDim + i]) > fabs(pivot)) {
                pivot = A[j * rowDim + i];
                pivotRow = i;
                pivotCol = j;
              } /*End if*/
            }   /*End for j*/
          }     /*End if rank*/
        }       /*Endfor i = rank+1*/
      }         /*Endif (rank<rowDim-1)*/
      else {
        break; /*No more rows to process.*/
      }
    } /*End if*/
    else {
      break; /*Done if remainder of matrix is at noise level.*/
    }
  } /*End for col*/

  return (rank + 1);
}

/*!
@brief Column Major Order LU Decomposition with complete row and column pivoting
with one specified coordinate

ksl_linalg_lu_full_specified_cmo factors a double precision matrix, A[rowDim *
colDim], stored in Column Major Order using full row and column pivoting. Matrix
A need not have full row or column rank. The integer variable 'rank' represents
the matrix rank and internally is always one less than the true rank to be
consistent with C's indexing from zero. Upon return from the function,
rank will be set to the correct value.

The lower triangular (rank+1) by (rank+1) Lr matrix, except its unity
diagonal, is stored below the diagonal in A[0:rank][0:rank]. The upper
triangular (rank+1) by (rank+1) Ur matrix is stored on and above the
diagonal in A[0:rank][0:rank].

Following the first major matrix decomposition step, A[0:rank][rank+1:colDim]
stores the residual matrix UR and A[rank+1:rowDim][0:rank] stores the residual
matrix LR.

ksl_linalg_lu_setBMatrix_cmo() computes and stores B = inverse(Ur)*UR and stores
it back in A[0:rank][rank+1:colDim].
ksl_linalg_lu_setCMatrix_cmo() computes and stores C = LR*inverse(Lr) and stores
it back in A[rank+1:rowDim][0:rank].

The remaining A[rank+1:rowDim][rank+1:colDim-1] submatrix contains numbers whose
absolute values are all smaller than eps times the absolutely largest
entry in the original matrix. This part of the matrix is not used.
The remainig A[rank+1:rowDim][colDim] submatrix could contain numbers whose
absolute values are greater than eps times the absolutely largest
entry in the original matrix. Adding a check here would be one way to
assert that the specified variable has sufficient mobility.

@param rowDim input row dimension of matrix A.
@param colDim input column dimension of matrix A.
@param **A input/output matrix to be factored with dimensions
A[0:rowDim-1][0:colDim-1]:
@param eps input tolerance on the order of machine roundoff.
@param pr output row permutation array with dimensions pr[0:rowDim-1]
@param pc output column permutation array with dimensions pc[0:colDim-1]
@return rank of matrix A
*/
int ksl_linalg_lu_full_specified_cmo(const int rowDim, const int colDim,
                                     double* restrict A, double eps,
                                     int* restrict pr, int* restrict pc,
                                     const int specifiedIndex) {

  // printf("Jacobian matrix in fullFactor_LU\n");
  // for(int i = 0; i < rowDim; i++) {
  //   for(int j = 0; j < colDim; j++)
  //     printf("% 2.4f ", A[j * rowDim + i]);
  //   printf("\n");
  // }

  int rank;     /* (rank+1) is the matrix rank */
  int pivotRow; /* row with current pivotal element */
  int pivotCol; /* column with current pivotal element */
  double pivot = 0.0;
  /* current pivotal element, holds the current pivotal element */
  double tol;                    /* tolerance for checking residual matrix
                                               infinity norm against */
  double save;                   /* variable for holding intermediate results*/
  double size = rowDim * colDim; /*overall size of matrix */

  /*
    Return failure if a bad row or column dimension was found.
  */
  if((rowDim <= 0) || (colDim <= 1)) {
    return (-1);
  }

  /*
    Consistent with C-indexing, rank always has a value of
    one less than the true value. rank+1 is returned.
  */
  rank = -1; /* initialize for indexing */

  /*
    Initialize permutation arrays
  */
  for(int row = 0; row < rowDim; row++) {
    pr[row] = row;
  }
  for(int col = 0; col < colDim; col++) {
    pc[col] = col;
  }

  /*
    Swap the specified column to the last position in the input
    matrix
    Swap entire columns A[:][specifiedIndex] and A[:][colDim - 1].
    swap columns:
      N = rowDim
      stride = 1
      Start of specefied column is A + rowDim * specifiedIndex & stride 1
      Start of last column is A + rowDim * (colDim - 1) & stride is 1
  */
  if(specifiedIndex != colDim - 1) {
#ifdef KSL_WITH_BLAS
    cblas_dswap(rowDim, A + rowDim * specifiedIndex, 1,
                A + rowDim * (colDim - 1), 1);
#else
    ksl_swapArray(rowDim, A + rowDim * specifiedIndex, 1,
                  A + rowDim * (colDim - 1), 1);
#endif
    /*
      Swap column permutation entries pc[] and
      pc[pivotRow] to reflect row swaps in A.
    */
    ksl_swapi(pc + specifiedIndex, pc + colDim - 1);
  }

  /*
    Search through matrix A except the last column to find the
    absolutely largest element for assigning to pivot.
    Save that row and column number in pivotRow and
    pivotCol. This could cause numerical problems if the last
    column contains one or more entries substantially absolutely
    larger than all other entries in A.
  */
  pivot = A[0];
  pivotRow = 0;
  pivotCol = 0;
  for(int col = 0; col < colDim - 1; col++) {
    for(int row = 0; row < rowDim; row++) {
      if(fabs(A[col * rowDim + row]) > fabs(pivot)) {
        pivot = A[col * rowDim + row];
        pivotRow = row;
        pivotCol = col;
      }
    }
  }
  // printf("pivotRow: %d, pivotCol: %d\n", pivotRow, pivotCol);

  /* Set tolerance to check all zero-elements against.
  pivot = infinity norm of A.
 */
  tol = fabs(eps * pivot);

  /*
    Major loop to permute and factor the matrix.
    Generate factors column by column, so outer loop
    sweeps over columns.
  */
  for(int col = 0; col < colDim; col++) {
    /*
    If the current pivotal element is <= tol, the
    remaining submatrix is zero and factorization
    is complete. The else statement for the following if test
    breaks out of this loop so not to waste time
    going through the remaining columns.
    */
    if(fabs(pivot) > tol) {
      /* Increase rank for the current column. */
      ++rank;

      /*
        pivotRow can never be less than rank.
        If pivotRow==rank, then no permutation is needed.
        If pivotRow>rank, then need to swap rows.
      */
      if(pivotRow > rank) {
        /*
          Need to swap entire row A[rank][:] and A[pivotRow][:].
          This also swaps rows in the Lr matrix to this point.
          swap rows:
            N = colDim
            stride = rowDim
          Start of replaced row is A + rank & stride is rowDim
          Start of pivot row is A + pivotRow & stride is rowDim
        */
#ifdef KSL_WITH_BLAS_
        cblas_dswap(colDim, A + rank, rowDim, A + pivotRow, rowDim);
#else
        ksl_swapArray(colDim, A + rank, rowDim, A + pivotRow, rowDim);
#endif
        /*
          Swap row permutation entries pr[rank] and
          pr[pivotRow] to reflect row swaps in A.
        */
        ksl_swapi(pr + rank, pr + pivotRow);
      }

      /*
        pivotCol can never be less than rank.
        If pivotCol==rank, then no permutation is needed.
        If pivotCol>rank, then need to swap columns.
      */
      if(pivotCol > rank) {
        // printf("rank: %d, pivotCol: %d\n", rank, pivotCol);
        // printf("colDim %d\n", colDim);
        /*
        Swap entire columns A[:][rank] and A[:][pivotCol].
        This also swaps columns in the UR matrix to this point.
        swap columns:
          N = rowDim
          stride = 1
          Start of replaced column is A + rowDim * rank & stride is 1
          Start of pivot column is A + rowDim * pivotCol & stride is 1
        */
#ifdef KSL_WITH_BLAS_
        cblas_dswap(rowDim, A + rowDim * rank, 1, A + rowDim * pivotCol, 1);
#else
        ksl_swapArray(rowDim, A + rowDim * rank, 1, A + rowDim * pivotCol, 1);
#endif
        /*
          Swap column permutation entries pc[rank] and
          pr[pivotCol] to reflect column swaps.
        */
        ksl_swapi(pc + rank, pc + pivotCol);
      }

      /*
        rank cannot be > rowDim-1. If rank < rowDim-1
        there is still some processing left to do. If
        rank == rowDim-1, there is only a 1 on the
        diagonal of this column of Lr. This loop factors
        the matrix and searches for a new pivotal element
        for the next factorization step.
      */
      if(rank < rowDim - 1) {

        /*
          Copy the current pivotal element into save so new
          pivotal element can be stored back in pivot.
        */
        save = pivot;
        pivot = 0;

        /* Need only process the rows from rank+1 to rowDim. */
        for(int i = rank + 1; i < rowDim; i++) {

          /* Evaluate the current entry in the L matrix.*/
          A[rank * rowDim + i] /= save;

          /*
            rank cannot be >= colDim. If rank < colDim
            there is still some processing left to do. If
            rank == colDim-1, only a pivot remains on the
            diagonal.
          */
          if(rank < colDim) {

            /*
              This next loop computes the remaining U matrix,
              searches for the largest pivotal element, and
              remembers the new pivotal element row and colum.
            */
            for(int j = rank + 1; j < colDim; j++) {
              A[j * rowDim + i] -= A[rank * rowDim + i] * A[j * rowDim + rank];
            }
            for(int j = rank + 1; j < colDim - 1; j++) {
              if(fabs(A[j * rowDim + i]) > fabs(pivot)) {
                pivot = A[j * rowDim + i];
                pivotRow = i;
                pivotCol = j;
              } /*End if*/
            }   /*End for j*/
          }     /*End if rank*/
        }       /*Endfor i = rank+1*/
      }         /*Endif (rank<rowDim-1)*/
      else {
        break; /*No more rows to process.*/
      }
    } /*End if*/
    else {
      break; /*Done if remainder of matrix is at noise level.*/
    }
  } /*End for col*/
  return (rank + 1);
}

/*!
@brief *Fast* Column Major Order LU Decomposition with no row or column pivoting
for a rectangular matrix

This function LU factors a double precision matrix, A[rank][colDim],
using no row or column pivoting. This function should be used only if the
left rank by rank submatrix is known to be nonsingular.

rank <= colDim or error.

The lower triangular rank by rank Lr matrix, except the unity
diagonal, is stored below the diagonal in A[0:rank-1][0:rank-1]. The upper
triangular rank by rank Ur matrix is stored on and above the
diagonal in A[0:rank-1][0:rank-1].

Note that this minimal algorithm variation does not compute the product
B = inverse(Ur)*UR

@param rank [in] row dimension of matrix A.
@param colDim [in] column dimension of matrix A.
@param *A [in/out] matrix to be factored with dimensions
A[0:rank-1][0:colDim-1]:
*/
inline void ksl_linalg_lu_cmo(const int rank, const int colDim,
                              double* restrict A) {

  if(rank > colDim) {
    // Error message & exit
  }

  /*
    Major loop to factor the matrix.
    Generate factors column by column
  */
  for(int row = 0; row < rank; row++) {

    /* i iterates over rows of A, up to rank-1 */
    for(int i = row + 1; i < rank; i++) {

      /* Evaluate the current entry in the L matrix.*/
      A[row * rank + i] /= A[row * rank + row];

      /* Compute U matrix */
      for(int j = row + 1; j < colDim; j++) {
        A[j * rank + i] -= A[row * rank + i] * A[j * rank + row];
      }
    }
  }
}

/*!
@brief compute Column Major Order B matrix (inverse(Ur) * UR)


This block overwrites UR with inverse(Ur) * UR
If rank == 0 or rank == colDim nothing to process, so exit with message.
This loop computes A[0:rank-1][rank:colDim-1] = inverse(Ur)*UR
where UR is stored in A[0:rank-1][rank:colDim-1]
and Ur is stored in upper part of A[0:rank-1][0:rank-1].
i is the row number in Ur.
j is the column number in Ur & row number in UR.
k is the column number in UR.

@param rowDim [in] row dimension of matrix A.
@param colDim [in] column dimension of matrix A.
@param rank [in] rank of matrix A.
@param *A [in/out] matrix with dimensions A[0:rowDim-1][0:colDim-1]:

*/
inline void ksl_linalg_lu_setBMatrix_cmo(const int rowDim, const int colDim,
                                         const int rank, double* restrict A) {

  if(rank > 0 && rank < colDim) {
    for(int i = rank - 1; i > -1; i--) {   /* rows of B */
      for(int k = rank; k < colDim; k++) { /* columns of B */
        double save = 0;
        for(int j = rank - 1; j > i; j--) { /* columns of Ur */
          save += A[j * rowDim + i] * A[k * rowDim + j];
        }
        A[k * rowDim + i] = (A[k * rowDim + i] - save) / A[i * rowDim + i];
      }
    }
  } else {
    // Error & do something.
  }
}

/*!
@brief compute Column Major Order C matrix

This block overwrites LR with LR*inverse(Lr)
If rank==1, the Lr matrix is a 1 by 1 identity
matrix, so there is nothing to do here. This loop
computes A[rank:rowDim-1][0:rank-1]=LR*inverse(Lr)
where LR is stored in A[rank:rowDim-1][0:rank-1]
and Lr is stored in A[0:rank-1][0:rank-1].
j is the column number in LR. It ends at 1
because the diagonal entry in row 0 of Lr is 1.
i is the row number in LR.
k is the column number in Lr

@param rowDim [in] row dimension of matrix A.
@param colDim [in] column dimension of matrix A.
@param rank [in] rank of matrix A.
@param *A [in/out] matrix with dimensions A[0:rowDim-1][0:colDim-1]:
*/
void ksl_linalg_lu_setCMatrix_cmo(int rowDim, int colDim, int rank, double* A) {

  if(rank > 1) {
    for(int j = rank - 1; j > 0; j--) {
      for(int i = rowDim - 1; i > rank - 1; i--) {
        for(int k = 0; k < j; k++)
          A[k * rowDim + i] -= A[j * rowDim + i] * A[k * rowDim + j];
      }
    }
  } else {
    // Error & do something.
  }
}

/*!
@brief computes the Column Major Order L D L^T decomposition of a symmetric
matrix without pivoting

returns the matrix L D L^T in the original matrix A

@param *A [in/out] matrix with dimensions A[0:n-1][0:n-1]:
@param n row and column dimension of matrix A.

*/
int ksl_linalg_ldlt_cmo(double* restrict A, const int n) {
  for(int k = 0; k < n; k++) {
    double pivot_inv = A[k * n + k];
    if(pivot_inv > 0.0) {
      pivot_inv = 1.0 / A[k * n + k];
    } else {
      return k + 1;
    }
    for(int j = k + 1; j < n; j++) {
      A[j * n + k] = A[k * n + j];
      A[k * n + j] *= pivot_inv;
    }
    for(int j = k + 1; j < n; j++) {
      for(int i = k + 1; i < j + 1; i++) {
        A[i * n + j] -= A[k * n + j] * A[i * n + k];
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      A[j * n + i] = A[i * n + j];
    }
  }
  return 0;
}

/*!
@brief perform Column Major Order Cholesky (L * L^T) decomposition of a
symmetric matrix without pivoting

returns the matrix factor L in the lower triangular portion of matrix A

@param *A [in/out] matrix with dimensions A[0:n-1][0:n-1]:
@param n row and column dimension of matrix A.

*/
int ksl_linalg_cholesky_cmo(double* restrict A, const int n) {
  for(int k = 0; k < n; k++) {
    if(A[k * n + k] > 0.0) {
      A[k * n + k] = sqrt(A[k * n + k]);
    } else {
      return k + 1;
    }
    double pivot_inv = 1.0 / A[k * n + k];
    for(int j = k + 1; j < n; j++) {
      A[k * n + j] *= pivot_inv;
    }
    for(int j = k + 1; j < n; j++) {
      for(int i = k + 1; i < j + 1; i++) {
        A[i * n + j] -= A[k * n + j] * A[k * n + i];
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      A[j * n + i] = A[i * n + j];
    }
  }
  return 0;
}

/*!
@brief used to solve a system of equations

L * y = b

for y using forward elimination where L IS Column Major Order unit lower
triangular

y = L^-1 * b

@param *L [in] n by n matrix L[0:n-1][0:n-1]:
@param *b [in] n by 1 column of right-hand side y[0:n-1].
@param *y [out] n by 1 column of unknowns.
@param n [in] dimension of L[][], b[], y[]:

*/
inline void ksl_linalg_ldlt_forwardElimination_cmo(const double* restrict L,
                                                   const double* restrict b,
                                                   double* restrict y,
                                                   const int n) {
  for(int i = 0; i < n; i++) {
    y[i] = b[i];
  }
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      y[j] -= L[i * n + j] * y[i];
    }
  }
}

/*!
@brief used to solve a system of equations

L^T * x = y

using backward substitution where L IS Column Major Order unit lower triangular

x = L^-T * y

@param *L [in] n by n matrix L[0:n-1][0:n-1]:
@param *y [in] n by 1 column of right-hand side y[0:n-1].
@param *x [out] n by 1 column of unknowns.
@param n [in] dimension of L[][], y[], x[]:

*/
inline void ksl_linalg_ldlt_backwardSubstitution_cmo(const double* restrict L,
                                                     const double* restrict y,
                                                     double* restrict x,
                                                     const int n) {
  for(int i = n - 1; i > -1; i--) {
    x[i] = y[i];
  }
  for(int i = n - 2; i > -1; i--) {
    for(int j = n - 1; j > i; j--) {
      x[i] -= L[i * n + j] * x[j];
    }
  }
}

/*!
@brief used to solve a system of equations

L * y = b

for y using forward elimination where L is Column Major Order and IS NOT unit
lower triangular

y = L^-1 * b

@param *L [in] n by n matrix L[0:n-1][0:n-1]:
@param *b [in] n by 1 column of right-hand side y[0:n-1].
@param *y [out] n by 1 column of unknowns.
@param n [in] dimension of L[][], b[], y[]:

*/
inline void ksl_linalg_cholesky_forwardElimination_cmo(const double* restrict L,
                                                       const double* restrict b,
                                                       double* restrict y,
                                                       const int n) {
  for(int i = 0; i < n; i++) {
    y[i] = b[i];
  }
  for(int i = 0; i < n; i++) {
    y[i] /= L[i * n + i];
    for(int j = i + 1; j < n; j++) {
      y[j] -= L[j * n + i] * y[i];
    }
  }
}

/*!
@brief used to solve a system of equations

L^T * x = y

using backward substitution where L is Column Major Order and IS NOT unit lower
triangular

x = L^-T * y

@param *L [in] n by n matrix L[0:n-1][0:n-1]:
@param *y [in] n by 1 column of right-hand side y[0:n-1].
@param *x [out] n by 1 column of unknowns.
@param n [in] dimension of L[][], y[], x[]:

*/
inline void
ksl_linalg_cholesky_backwardSubstitution_cmo(const double* restrict L,
                                             const double* restrict y,
                                             double* restrict x, const int n) {
  for(int i = 0; i < n; i++) {
    x[i] = y[i];
  }
  x[n - 1] /= L[(n - 1) * n + (n - 1)];
  for(int i = n - 2; i > -1; i--) {
    for(int j = i + 1; j < n; j++) {
      x[i] -= L[i * n + j] * x[j];
    }
    x[i] /= L[i * n + i];
  }
}

/*!
@brief solve the system of equations A * x = b where A is Column Major Order and
a symmetric positive definite matrix A

ksl_linalg_ldlt_cmo must be called on A prior to calling this function

@param *A [in] n by n matrix A[0:n-1][0:n-1] containing Choleski-factored
matrix:
@param *b [in] n by 1 column of right-hand side y[0:n-1].
@param *x [out] n by 1 column of unknowns.
@param n [in] dimension of L[][], b[], y[]:

*/
inline void ksl_linalg_ldlt_solve_cmo(const double* restrict A,
                                      double* const restrict b,
                                      double* restrict x, const int n) {
  double y[n];
  ksl_linalg_ldlt_forwardElimination_cmo(A, b, y, n);
  for(int i = 0; i < n; i++) {
    y[i] /= A[i * n + i];
  }
  ksl_linalg_ldlt_backwardSubstitution_cmo(A, y, x, n);
}

/*!
@brief solve the system of equations A * x = b where A is Column Major Order and
a symmetric positive definite matrix A

@param *A [in] n by n matrix A[0:n-1][0:n-1] containing Choleski-factored
matrix:
@param *b [in] n by 1 column of right-hand side y[0:n-1].
@param *x [out] n by 1 column of unknowns.
@param n [in] dimension of L[][], b[], y[]:

ksl_linalg_cholesky must be called on A prior to calling this function
*/
inline void ksl_linalg_cholesky_solve_cmo(const double* restrict A,
                                          const double* restrict b,
                                          double* restrict x, const int n) {
  double y[n];
  ksl_linalg_cholesky_forwardElimination_cmo(A, b, y, n);
  ksl_linalg_cholesky_backwardSubstitution_cmo(A, y, x, n);
}

/*!
@brief compute inverse of a symmetric positive definite matrix A
where A and A_inverse are in Column Major Order.
*/

inline int ksl_linalg_symmetricMatrixInverse_cmo(double* restrict A,
                                                 const int n) {
  int status = ksl_linalg_ldlt_cmo(A, n);
  if(status > 0) {
    return status;
  }
  for(int i = 0; i < n - 1; i++) {
    for(int j = i + 1; j < n; j++) {
      A[j * n + i] = 0.0;
    }
  }
  for(int i = 0; i < n; i++) {
    A[i * n + i] = 1.0 / A[i * n + i];
  }
  for(int i = n - 2; i >= 0; i--) {  // i = n-1:-1:1
    for(int j = n - 1; j > i; j--) { // j = n:-1:i+1
      for(int k = j; k > i; k--) {   // k = j:-1:i+1
        A[j * n + i] -=
          A[i * n + k] * A[j * n + k]; // A(j,i) = A(j,i) - A(i,k)*A(j,k);
      }
    }
  }
  for(int i = n - 2; i >= 0; i--) {    // i = n-1:-1:1
    for(int j = 0; j <= i; j++) {      // j = 1:1:i
      for(int k = i + 1; k < n; k++) { // k = i+1:1:n
        A[i * n + j] -=
          A[k * n + j] * A[i * n + k]; // A(i,j) = A(i,j) - A(k,j)*A(k,i);
      }
    }
  }
  for(int i = 0; i < n - 1; i++) {
    for(int j = i + 1; j < n; j++) {
      A[i * n + j] = A[j * n + i];
    }
  }
  return 0;
}

// inline int ksl_linalg_symmetricMatrixInverse_cmo(double* restrict A, const
// int n) {
//   double A_inverse[n * n];
//   double a[n];
//
//   int status = ksl_linalg_ldlt_cmo(A, n);
//   if(status > 0) {
//     return status;
//   }
//   for(int i = 0; i < n; i++) {
//     memset(a, 0, n * sizeof(double));
//     a[i] = 1.0;
//     ksl_linalg_ldlt_solve_cmo(A, a, &A_inverse[i * n + 0], n);
//   }
//   memcpy(A, A_inverse, n * n * sizeof(double));
//   return 0;
// }
