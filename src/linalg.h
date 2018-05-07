/**
@file
@author Kristopher Wehage, Roger Wehage
@brief Utilities to perform linear algebra operations
@date 2018
@copyright Kristopher Wehage 2018

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

#ifndef _KSL_LINALG_H_
#define _KSL_LINALG_H_

#include "matrix.h"
#include "vector.h"

void ksl_linalg_gramSchmidt(double* A, int m, int n);

void ksl_linalg_pca(ksl_mat3x3_t* A, ksl_mat3x3_t* v);

void ksl_swapArray(const int n, double* a, const int a_stride, double* b,
                   const int b_stride);

int ksl_maxIndex(const int n, const double* a);

void ksl_linalg_lu(const int rank, const int colDim, double* A);

void ksl_linalg_lu_backwardSubstitution(const double* L, const double* y,
                                        double* x, const int n);

void ksl_linalg_lu_forwardSubstitution(const double* U, const double* y,
                                       double* x, const int n);

void ksl_linalg_lu_solve(const int rowDim, const int colDim, const double* A,
                         int* pr, int* pc, const double* x, double* y,
                         const int n);

int ksl_linalg_lu_full(const int rowDim, const int colDim, double* A,
                       const double eps, int* pr, int* pc);

int ksl_linalg_lu_full_specified(const int rowDim, const int colDim, double* A,
                                 const double eps, int* pr, int* pc,
                                 const int specifiedIndex);

void ksl_linalg_lu_backwardSubstitution(const double* L, const double* y,
                                        double* x, const int n);

void ksl_linalg_lu_forwardSubstitution(const double* U, const double* y,
                                       double* x, const int n);

void ksl_linalg_lu_full_backwardSubstitution(const double* L, const double* y,
                                             double* x, const int n);

void ksl_linalg_lu_full_forwardSubstitution(const double* U, const double* y,
                                            double* x, const int n);

void ksl_linalg_lu_full_solve(const int rowDim, const int colDim, double* A,
                              int* pr, int* pc, double* x, double* y);

void ksl_linalg_lu_setBMatrix(const int rank, const int colDim, double* A);

void ksl_linalg_lu_setCMatrix(const int rowDim, const int colDim, int rank,
                              double* A);

int ksl_linalg_ldlt(double* D, const int n);

void ksl_linalg_ldlt_backwardSubstitution(const double* L, const double* y,
                                          double* x, const int n);

void ksl_linalg_ldlt_forwardSubstitution(const double* L, const double* b,
                                         double* y, const int n);

void ksl_linalg_ldlt_solve(const double* A, const double* x, double* y,
                           const int n);

int ksl_linalg_cholesky(double* D, const int n);

void ksl_linalg_cholesky_forwardSubstitution(const double* L, const double* b,
                                             double* y, const int n);

void ksl_linalg_cholesky_backwardSubstitution(const double* L, const double* y,
                                              double* x, const int n);

void ksl_linalg_cholesky_solve(const double* A, const double* x, double* y,
                               const int n);

int ksl_linalg_symmetricMatrixInverse(double* A, const int n);

#endif
