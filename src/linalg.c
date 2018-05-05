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

inline void ksl_swapArray(const int n, double* a, const int a_stride, double* b,
                          const int b_stride) {
  for(int i = 0; i < n; i++) {
    ksl_swap(a + i * a_stride, b + i * b_stride);
  }
}

/*!
@brief LU Decomposition with complete row and column pivoting

mbdl)factor_LU_full factors a double precision matrix, A[rowDim * colDim],
stored in row major order using full row and column pivoting. Matrix A need
not have full row or column rank. The integer variable 'rank' represents the
matrix rank and internally is always one less than the true rank to be
consistent with C's indexing from zero. Upon return from the function,
rank will be set to the correct value.

The lower triangular (rank+1) by (rank+1) Lr matrix, except the unity
diagonal, is stored below the diagonal in A[0:rank][0:rank]. The upper
triangular (rank+1) by (rank+1) Ur matrix is stored on and above the
diagonal in A[0:rank][0:rank].

Following the first major matrix decomposition step, A[0:rank][rank+1:colDim]
stores the residual matrix UR and A[rank+1:rowDim][0:rank] stores the residual
matrix LR. The product C=LR*inverse(Lr) is then computed and stored back in
A[rank+1:rowDim][0:rank] and the product B=-inverse(Ur)*UR is
computed and stored back in A[0:rank][rank+1:colDim].

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
int ksl_linalg_LU_full(const int rowDim, const int colDim, double* A,
                       double eps, int* pr, int* pc) {

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
  int index = cblas_idamax(size, A, 1);
  div_t result = div(index, colDim);
  pivotRow = result.quot;
  pivotCol = result.rem;
  pivot = A[index];
  // printf("pivotRow: %d, pivotCol: %d\n", pivotRow, pivotCol);

  /* Initialize the column permutation array. */
  for(int col = 0; col < colDim; col++) {
    pc[col] = col;
  }
  for(int row = 0; row < rowDim; row++) {
    pr[row] = row;
  }

  /* Set tolerance to check all zero-elements against. */
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
      is complete. Need to add an else statement to
      break out of this loop so not to waste time
      going through remaining columns?
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

          swapping row:
            N = colDim
            inc = 1

          number of entries for column swap: colDim
          stride =
        */

        cblas_dswap(colDim, A + colDim * rank, 1, A + colDim * pivotRow, 1);

        /* Swap row permutation entries pr[rank] and
        pr[pivotRow] to reflect row swaps in A. */
        ksl_iswap(pr + rank, pr + pivotRow);
      }

      /* pivotCol can never be less than rank.
      If pivotCol==rank, then no permutation is needed.
      If pivotCol>rank, then need to swap columns. */
      if(pivotCol > rank) {
        // printf("rank: %d, pivotCol: %d\n", rank, pivotCol);
        // printf("colDim %d\n", colDim);
        /* entire columns A[:][rank] and A[:][pivotCol].
          swapping column:
            N = rowDim
            stride = colDim */
        cblas_dswap(rowDim, A + rank, colDim, A + pivotCol, colDim);

        /* Swap column permutation entries pc[rank] and
        pr[pivotCol] to reflect column swaps. */
        ksl_iswap(pc + rank, pc + pivotCol);
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

  /*
    This block computes LR*inverse(Lr)
    Here rank>0 means true rank is greater than 1.
    If rank==0, the Lr matrix is a 1 by 1 identity
    matrix, so there is nothing to do here. This loop
    computes A[rank+1:rowDim-1][0:rank]=LR*inverse(Lr)
    where LR is stored in A[rank+1:rowDim-1][0:rank]
    and Lr is stored in A[0:rank][0:rank].
    j is the column number in LR. It ends at 1
    because the diagonal entry in row 0 of Lr is 1.
    i is the row number in LR.
    k is the column number in Lr
  */
  // if(rank > 0) {
  //   for(j = rank; j > 0; j--) {
  //     for(i = rowDim - 1; i > rank; i--) {
  //       for(k = 0; k < j; k++)
  //         A[i * colDim + k] -= A[i * colDim + j] *
  //           A[j * colDim + k];
  //     }
  //   }
  // }

  /*
    This block computes -inverse(Ur)*UR.
    Here rank > -1 means the true rank is greater than 0.
    If rank==0, nothing to process. This loop computes
    A[0:rank][rank+1:colDim-1]=-inverse(Ur)*UR
    where UR is stored in A[0:rank][rank+1:colDim-1]
    and Ur is stored in upper part of A[0:rank][0:rank].
    i is the row number in Ur.
    j is the column number in Ur & row number in UR.
    k is the column number in UR.
  */
  // if(rank > -1 && rank < colDim - 1) {
  //   for(i = rank; i >= 0; i--) {
  //     for(k = rank + 1; k < colDim; k++) {
  //       save = 0;
  //       for(j = rank; j > i; j--) {
  //         save -= A[i * colDim + j] * A[j * colDim + k];
  //       }
  //       A[i * colDim + k] = (save - A[i * colDim + k]) / A[i * colDim + i];
  //     }
  //   }
  // }

  return (rank + 1);
}

/*!
@brief LU Decomposition with complete row and column pivoting with one
specified coordinate

ksl_linalg_LU_full_specified factors a double precision matrix, A[rowDim *
colDim], stored in row major order using full row and column pivoting. Matrix A
need not have full row or column rank. The integer variable 'rank' represents
the matrix rank and internally is always one less than the true rank to be
consistent with C's indexing from zero. Upon return from the function,
rank will be set to the correct value.

The lower triangular (rank+1) by (rank+1) Lr matrix, except the unity
diagonal, is stored below the diagonal in A[0:rank][0:rank]. The upper
triangular (rank+1) by (rank+1) Ur matrix is stored on and above the
diagonal in A[0:rank][0:rank].

Following the first major matrix decomposition step, A[0:rank][rank+1:colDim]
stores the residual matrix UR and A[rank+1:rowDim][0:rank] stores the residual
matrix LR. The product C=LR*inverse(Lr) is then computed and stored back in
A[rank+1:rowDim][0:rank] and the product B=-inverse(Ur)*UR is
computed and stored back in A[0:rank][rank+1:colDim].

The remaining A[rank+1:rowDim][rank+1:colDim] submatrix contains numbers whose
absolute values are all smaller than eps times the absolutely largest
entry in the original matrix. This part of the matrix is not used.

@param rowDim input row dimension of matrix A.
@param colDim input column dimension of matrix A.
@param **A input/output matrix to be factored with dimensions
A[0:rowDim-1][0:colDim-1]:
@param eps input tolerance on the order of machine roundoff.
@param pr output row permutation array with dimensions pr[0:rowDim-1]
@param pc output column permutation array with dimensions pc[0:colDim-1]
@return rank of matrix A
*/
int ksl_linalg_LU_full_specified(int rowDim, int colDim, double* A, double eps,
                                 int* pr, int* pc, int specifiedIndex) {

  // printf("Jacobian matrix in fullFactor_LU\n");
  // for(int i = 0; i < rowDim; i++) {
  //   for(int j = 0; j < colDim; j++)
  //     printf("% 2.4f ", A[i * colDim + j]);
  //   printf("\n");
  // }

  int rank;     /* (rank+1) is the matrix rank */
  int col;      /* working column number */
  int pivotRow; /* row with current pivotal element */
  int pivotCol; /* column with current pivotal element */
  int i;        /* local row index */
  int j;        /* local column index */
  // int k;        /* local row/column index */
  double pivot = 0.0;
  /* current pivotal element, holds the current pivotal element */
  double tol;  /* tolerance for checking residual matrix
                             infinity norm against */
  double save; /* variable for holding intermediate results*/

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
  */
  if(specifiedIndex != colDim - 1) {
    cblas_dswap(rowDim, A + specifiedIndex, colDim, A + colDim - 1, colDim);

    /*
      Swap column permutation entries pc[] and
      pc[pivotRow] to reflect row swaps in A.
    */
    ksl_iswap(pc + specifiedIndex, pc + colDim - 1);
  }

  /*
    Search through the remaining A matrix to find the
    absolutely largest element for assigning to pivot.
    Save that row and column number in pivotRow and
    pivotCol. Also intialize the row permutation array pr.
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

  /* Set tolerance to check all zero-elements against. */
  tol = fabs(eps * pivot);

  /*
    Major loop to permute and factor the matrix.
    Generate factors column by column, so outer loop
    sweeps over columns.
  */
  for(col = 0; col < colDim; col++) {
    /*
      If the current pivotal element is <= tol, the
      remaining submatrix is zero and factorization
      is complete. Need to add an else statement to
      break out of this loop so not to waste time
      going through remaining columns?
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

          swapping row:
            N = colDim
            inc = 1

          number of entries for column swap: colDim
          stride = rowDim
        */

        cblas_dswap(colDim, A + colDim * rank, 1, A + colDim * pivotRow, 1);

        /*
          Swap row permutation entries pr[rank] and
          pr[pivotRow] to reflect row swaps in A.
        */
        ksl_iswap(pr + rank, pr + pivotRow);
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
          entire columns A[:][rank] and A[:][pivotCol].

          swapping column:
            N = rowDim
            stride = colDim
        */
        cblas_dswap(rowDim, A + rank, colDim, A + pivotCol, colDim);

        /*
          Swap column permutation entries pc[rank] and
          pr[pivotCol] to reflect column swaps.
        */
        ksl_iswap(pc + rank, pc + pivotCol);
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
        for(i = rank + 1; i < rowDim; i++) {

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
            for(j = rank + 1; j < colDim; j++) {
              A[i * colDim + j] -= A[i * colDim + rank] * A[rank * colDim + j];
            }
            for(j = rank + 1; j < colDim - 1; j++) {
              if(fabs(A[i * colDim + j]) > fabs(pivot)) {
                pivot = A[i * colDim + j];
                pivotRow = i;
                pivotCol = j;
              }
            }
          } /*End if rank*/
        }   /*Endfor i = rank+1*/
      }     /*Endif (rank<rowDim-1)*/
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
@brief LU Decomposition with no row or column pivoting

factor LU factors a double precision matrix, A[rowDim][colDim],
using no row or column pivoting. Only the square rank x colDim submatrix of
matrix A will be processed.

The lower triangular (rank+1) by (rank+1) Lr matrix, except the unity
diagonal, is stored below the diagonal in A[0:rank][0:rank]. The upper
triangular (rank+1) by (rank+1) Ur matrix is stored on and above the
diagonal in A[0:rank][0:rank].

Note that this minimal algorithm variation does not compute the product
C=LR*inverse(Lr)

@param rowDim [in] row dimension of matrix A.
@param colDim [in] column dimension of matrix A.
@param rank [in] only the square rank x colDim submatrix of A will be processed
@param *A [in/out] matrix to be factored with dimensions
A[0:rowDim-1][0:colDim-1]:
*/
void ksl_linalg_LU(int rank, int colDim, double* A) {

  /*
    Major loop to factor the matrix.
    Generate factors column by column
  */
  for(int row = 0; row < rank; row++) {

    /* i iterates over rows of A, up to rank,
    previously rank was rowDim */
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
@brief compute B matrix (inverse(Ur) * UR)

This block overwrites UR with inverse(Ur) * UR
If rank == 0, nothing to process. This loop computes
A[0:rank][rank+1:colDim-1] = inverse(Ur)*UR
where UR is stored in A[0:rank][rank+1:colDim-1]
and Ur is stored in upper part of A[0:rank][0:rank].
i is the row number in Ur.
j is the column number in Ur & row number in UR.
k is the column number in UR.

*/
void ksl_linalg_setBMatrix(int rank, int colDim, double* A) {

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
  }
}

/*!
@brief compute C matrix

This block overwrites LR with LR*inverse(Lr)
Here rank>0 means true rank is greater than 1.
If rank==0, the Lr matrix is a 1 by 1 identity
matrix, so there is nothing to do here. This loop
computes A[rank+1:rowDim-1][0:rank]=LR*inverse(Lr)
where LR is stored in A[rank+1:rowDim-1][0:rank]
and Lr is stored in A[0:rank][0:rank].
j is the column number in LR. It ends at 1
because the diagonal entry in row 0 of Lr is 1.
i is the row number in LR.
k is the column number in Lr
*/
void ksl_linalg_setCMatrix(int rowDim, int colDim, int rank, double* A) {

  if(rank > 1) {
    for(int j = rank - 1; j > 0; j--) {
      for(int i = rowDim - 1; i > rank - 1; i--) {
        for(int k = 0; k < j; k++)
          A[i * colDim + k] -= A[i * colDim + j] * A[j * colDim + k];
      }
    }
  }
}

/*!
computes the L D L^T decomposition of a symmetric matrix without pivoting

returns the matrix L D L^T in the original matrix A
*/
int ksl_linalg_ldlt(double* restrict D, const int n) {
  for(int k = 0; k < n; k++) {
    double pivot_inv = 1.0 / D[k * n + k];
    for(int j = k + 1; j < n; j++) {
      D[k * n + j] = D[j * n + k];
      D[j * n + k] *= pivot_inv;
    }
    for(int j = k + 1; j < n; j++) {
      for(int i = k + 1; i < j + 1; i++) {
        D[j * n + i] -= D[j * n + k] * D[k * n + i];
      }
    }
  }
  return 0;
}

int ksl_linalg_cholesky(double* restrict D, const int n) {
  for(int k = 0; k < n; k++) {
    D[k * 4 + k] = sqrt(D[k * 4 + k]);
    if(fabs(D[k * 4 + k]) < 1e-9) {
      return -1;
    }
    double pivot_inv = 1.0 / D[k * 4 + k];
    for(int j = k + 1; j < n; j++) {
      D[j * n + k] *= pivot_inv;
    }
    for(int j = k + 1; j < n; j++) {
      for(int i = k + 1; i < j + 1; i++) {
        D[j * n + i] -= D[j * n + k] * D[i * n + k];
      }
    }
  }
  return 0;
}

/*!
@brief used to solve a system of equations

L^T * x = y

using backward substitution where L IS unit lower triangular

x = L^-T * y

*/
inline void ksl_linalg_ldlt_backwardSubstitution(double* restrict L,
                                                 double* restrict y,
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

L^T * x = y

using backward substitution where L IS NOT unit lower triangular

x = L^-T * y

*/
inline void ksl_linalg_cholesky_backwardSubstitution(double* restrict L,
                                                     double* restrict y,
                                                     double* restrict x,
                                                     const int n) {
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
@brief used to solve a system of equations

L * y = b

for y using forward substitution where L IS unit lower triangular

y = L^-1 * b

*/
inline void ksl_linalg_ldlt_forwardSubstitution(double* restrict L,
                                                double* restrict b,
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

L * y = b

for y using forward substitution where L IS NOT unit lower triangular

y = L^-1 * b

*/
inline void ksl_linalg_cholesky_forwardSubstitution(double* restrict L,
                                                    double* restrict b,
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
@brief solve the system of equations A * x = y where A is a symmetric positive
definite matrix A

ksl_linalg_ldlt must be called on A prior to calling this function
*/
inline void ksl_linalg_ldlt_solve(double* restrict A, double* restrict x,
                                  double* restrict y, const int n) {
  double b[n];
  ksl_linalg_ldlt_forwardSubstitution(A, x, b, n);
  for(int i = 0; i < n; i++) {
    b[i] /= A[i * n + i];
  }
  ksl_linalg_ldlt_backwardSubstitution(A, b, y, n);
}

/*!
@brief solve the system of equations A * x = y where A is a symmetric positive
definite matrix A

ksl_linalg_cholesky must be called on A prior to calling this function
*/
inline void ksl_linalg_cholesky_solve(double* restrict A, double* restrict x,
                                      double* restrict y, const int n) {
  double b[n];
  ksl_linalg_ldlt_forwardSubstitution(A, x, b, n);
  ksl_linalg_ldlt_backwardSubstitution(A, b, y, n);
}

/*!
@brief compute matrix inverse of a symmetric positive definite matrix A
*/
inline int ksl_linalg_symmetricMatrixInverse(double* restrict A, const int n) {
  double A_inverse[n * n];
  double a[n];

  int status = ksl_linalg_ldlt(A, n);
  if(status) {
    return -1;
  }
  for(int i = 0; i < n; i++) {
    memset(a, 0, n * sizeof(double));
    a[i] = 1.0;
    ksl_linalg_ldlt_solve(A, a, &A_inverse[i * n + 0], n);
  }
  memcpy(A, A_inverse, n * n * sizeof(double));
  return 0;
}
