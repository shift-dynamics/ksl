/**
@file
@author Kristopher Wehage, Roger Wehage
@brief Utilities to perform linear algebra operations
@date 2018
@copyright Kristopher Wehage 2018-2026

@remark
THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS "AS IS" AND
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

#include "ksl/array.h"
#include "ksl/types.h"

#ifdef __cplusplus
extern "C" {
#endif

void ksl_linalg_gramSchmidt(double* A, const int m, const int n);

void ksl_linalg_gramSchmidtf(float* A, const int m, const int n);

int ksl_linalg_lu_full_rmo(const int rowDim, const int colDim, double* A,
                           const double eps, int* pr, int* pc);

int ksl_linalg_lu_full_specified_rmo(const int rowDim, const int colDim,
                                     double* A, double eps, int* pr, int* pc,
                                     const int specifiedIndex);

int ksl_linalg_lu_full_multiSpecified_rmo(const int rowDim, const int colDim,
                                          double* A, double eps, int* pr,
                                          int* pc, const int specifiedCount,
                                          const int* specifiedIndices);

void ksl_linalg_lu_rmo(const int rank, const int colDim, double* A);

void ksl_linalg_lu_setBMatrix_rmo(const int rank, const int colDim, double* A);

/*!
@brief Return the largest absolute value in the B matrix of a factored row major
matrix.

B is stored in A[0:rank-1][rank:colDim-1]. A large value indicates that the
partition into dependent and independent columns is poorly conditioned.

@param rank [in] rank of A, as returned by ksl_linalg_lu_full_rmo()
@param colDim [in] column dimension of A
@param A [in] matrix factored by ksl_linalg_lu_full_rmo(), after
ksl_linalg_lu_setBMatrix_rmo()
@return maximum absolute entry of B
*/
double ksl_linalg_lu_infinityNormB_rmo(int rank, int colDim, double* A);

void ksl_linalg_lu_setCMatrix_rmo(int rowDim, int colDim, int rank, double* A);

/*!
@brief Solve \f$L_r U_r \underline{x} = \underline{b}\f$ with the factors of
ksl_linalg_lu_full_rmo().

\f$L_r\f$ (unit diagonal, not stored) and \f$U_r\f$ are the rank by rank factors in
A[0:rank-1][0:rank-1], which ksl_linalg_lu_setBMatrix_rmo() and
ksl_linalg_lu_setCMatrix_rmo() leave unchanged. The solution is a forward substitution,

\f[
y_i = b_i - \sum_{j < i} l_{ij}\,y_j,
\f]

followed by a back substitution,

\f[
x_i = \frac{1}{u_{ii}}\Bigl(y_i - \sum_{j > i} u_{ij}\,x_j\Bigr).
\f]

The rows of the system are in pivoted order, so that b[i] is the entry of the original
right side in row pr[i], and x[i] is the value of the variable of column pc[i]. With
b[i] = A_orig[pr[i]][j], for instance, x is column j of
\f$\begin{bmatrix} I & B \end{bmatrix}\f$ in pivoted column order.

@param rank [in] rank r returned by ksl_linalg_lu_full_rmo()
@param colDim [in] column dimension of A
@param A [in] factored matrix
@param b [in] right side, r entries in pivoted row order
@param x [out] solution, r entries; may be the same array as b
*/
void ksl_linalg_lu_solve_rmo(const int rank, const int colDim, const double* A,
                             const double* b, double* x);

int ksl_linalg_ldlt_rmo(double* A, const int n);

int ksl_linalg_cholesky_rmo(double* A, const int n);

void ksl_linalg_ldlt_forwardElimination_rmo(const double* L, const double* b,
                                            double* y, const int n);

void ksl_linalg_ldlt_backwardSubstitution_rmo(const double* L, const double* b,
                                              double* x, const int n);

void ksl_linalg_cholesky_forwardElimination_rmo(const double* L,
                                                const double* b, double* y,
                                                const int n);

void ksl_linalg_cholesky_backwardSubstitution_rmo(const double* L,
                                                  const double* y, double* x,
                                                  const int n);

void ksl_linalg_ldlt_solve_rmo(const double* A, const double* b, double* x,
                               const int n);

void ksl_linalg_cholesky_solve_rmo(const double* A, const double* b, double* x,
                                   const int n);

int ksl_linalg_symmetricMatrixInverse_rmo(double* A, const int n);

int ksl_linalg_lu_full_cmo(const int rowDim, const int colDim, double* A,
                           const double eps, int* pr, int* pc);

int ksl_linalg_lu_full_specified_cmo(const int rowDim, const int colDim,
                                     double* A, double eps, int* pr, int* pc,
                                     const int specifiedIndex);

void ksl_linalg_lu_cmo(const int rank, const int colDim, double* A);

void ksl_linalg_lu_setBMatrix_cmo(const int rowDim, const int colDim,
                                  const int rank, double* A);

void ksl_linalg_lu_setCMatrix_cmo(int rowDim, int colDim, int rank, double* A);

int ksl_linalg_ldlt_cmo(double* A, const int n);

int ksl_linalg_cholesky_cmo(double* A, const int n);

void ksl_linalg_ldlt_forwardElimination_cmo(const double* L, const double* b,
                                            double* y, const int n);

void ksl_linalg_ldlt_backwardSubstitution_cmo(const double* L, const double* b,
                                              double* x, const int n);

void ksl_linalg_cholesky_forwardElimination_cmo(const double* L,
                                                const double* b, double* y,
                                                const int n);

void ksl_linalg_cholesky_backwardSubstitution_cmo(const double* L,
                                                  const double* y, double* x,
                                                  const int n);

void ksl_linalg_ldlt_solve_cmo(const double* A, double* const b, double* x,
                               const int n);

void ksl_linalg_cholesky_solve_cmo(const double* A, const double* b, double* x,
                                   const int n);

int ksl_linalg_symmetricMatrixInverse_cmo(double* A, const int n);

/*!
@brief Householder QR factorization of a row major m by n matrix.

Computes \f$A = QR\f$ with \f$Q\f$ an m by m orthogonal matrix and \f$R\f$ m by n and upper
triangular. Column k of A is reflected by \f$H_k = I - 2\underline{v}_k\underline{v}_k^{T}
/\underline{v}_k^{T}\underline{v}_k\f$, with \f$\underline{v}_k = \underline{a}_k + \mathrm{sign}
(a_{kk})\,\lVert\underline{a}_k\rVert\,\underline{e}_k\f$ over rows k to m - 1, so that
\f$R = H_{p-1}\cdots H_0 A\f$ and \f$Q = H_0\cdots H_{p-1}\f$, p = min(n, m - 1). A column that
is already zero below the diagonal is skipped.

@param m [in] row dimension
@param n [in] column dimension
@param A [in,out] m by n matrix, replaced by R
@param Q [out] m by m orthogonal factor
*/
void ksl_linalg_qr_householder_rmo(const int m, const int n, double* A, double* Q);

/*!
@brief Column major version of ksl_linalg_qr_householder_rmo().
*/
void ksl_linalg_qr_householder_cmo(const int m, const int n, double* A, double* Q);

/*!
@brief Singular value decomposition of a row major m by n matrix by one-sided (Hestenes)
Jacobi rotations.

Rotates pairs of columns of A until they are orthogonal: on return \f$W = AV\f$ has orthogonal
columns in nonincreasing order of length, the singular values
\f$\sigma_j = \lVert\underline{w}_j\rVert\f$, and V is n by n orthogonal, so that
\f$A = W V^{T}\f$ and \f$\underline{u}_j = \underline{w}_j/\sigma_j\f$ for \f$\sigma_j > 0\f$.
For columns i and j with \f$b_{ii} = \underline{w}_i^{T}\underline{w}_i \ge b_{jj}\f$ and
\f$b_{ij} = \underline{w}_i^{T}\underline{w}_j\f$, the rotation has
\f$\alpha = 2b_{ij}\f$, \f$\beta = b_{ii} - b_{jj}\f$, \f$\gamma = \mathrm{sign}(\beta)
\sqrt{\alpha^{2} + \beta^{2}}\f$, \f$c = \sqrt{(\beta + \gamma)/2\gamma}\f$ and
\f$s = \alpha/(2\gamma c)\f$. The columns of V for zero singular values span the null space of
A. Sweeps stop when every pair satisfies \f$|b_{ij}| \le \varepsilon\sqrt{b_{ii}b_{jj}}\f$ with
\f$\varepsilon = 10^{-15}\f$, or after 60 sweeps.

@param m [in] row dimension
@param n [in] column dimension
@param A [in,out] m by n matrix, replaced by W = A V
@param sigma [out] n singular values, nonincreasing
@param V [out] n by n orthogonal matrix
@return number of sweeps, or -1 if 60 sweeps did not converge
*/
int ksl_linalg_svd_jacobi_rmo(const int m, const int n, double* A, double* sigma,
                              double* V);

/*!
@brief Column major version of ksl_linalg_svd_jacobi_rmo().
*/
int ksl_linalg_svd_jacobi_cmo(const int m, const int n, double* A, double* sigma,
                              double* V);

/*!
@brief Null space basis of a row major matrix factored by ksl_linalg_lu_full_rmo().

With the rank r, the column permutation pc, and B in A[0:r-1][r:n-1] from
ksl_linalg_lu_setBMatrix_rmo(), the n by (n - r) basis is

\f[
Z = P_c^{T}\begin{bmatrix} -B \\ I \end{bmatrix},
\f]

row pc[i] of Z holding row i of \f$-B\f$ for i < r and row pc[r + j] the unit row
\f$\underline{e}_j^{T}\f$, so that \f$AZ = 0\f$ for the original A.

@param rank [in] rank r returned by ksl_linalg_lu_full_rmo()
@param colDim [in] column dimension n
@param A [in] factored matrix after ksl_linalg_lu_setBMatrix_rmo()
@param pc [in] column permutation from ksl_linalg_lu_full_rmo()
@param Z [out] n by (n - r) row major null space basis
*/
void ksl_linalg_lu_nullSpace_rmo(const int rank, const int colDim, const double* A,
                                 const int* pc, double* Z);

/*!
@brief Left null space basis of a row major matrix factored by ksl_linalg_lu_full_rmo().

With the rank r, the row permutation pr, and C in A[r:m-1][0:r-1] from
ksl_linalg_lu_setCMatrix_rmo(), the (m - r) by m basis is

\f[
Y = \begin{bmatrix} -C & I \end{bmatrix} P_r,
\f]

column pr[j] of Y holding column j of \f$-C\f$ for j < r and column pr[r + i] the unit
column \f$\underline{e}_i\f$, so that \f$YA = 0\f$ for the original A.

@param rowDim [in] row dimension m
@param colDim [in] column dimension n
@param rank [in] rank r returned by ksl_linalg_lu_full_rmo()
@param A [in] factored matrix after ksl_linalg_lu_setCMatrix_rmo()
@param pr [in] row permutation from ksl_linalg_lu_full_rmo()
@param Y [out] (m - r) by m row major left null space basis
*/
void ksl_linalg_lu_leftNullSpace_rmo(const int rowDim, const int colDim,
                                     const int rank, const double* A,
                                     const int* pr, double* Y);

/*!
@brief Mobility numbers of n coordinates from a null space basis.

Orthonormalizes the columns of the n by k basis Z in place with ksl_linalg_gramSchmidt()
and returns the diagonal of the projector onto the null space,

\f[
\mu_i = \bigl(ZZ^{T}\bigr)_{ii} = \sum_{j=0}^{k-1} z_{ij}^{2}, \qquad
0 \le \mu_i \le 1, \qquad \sum_{i} \mu_i = k,
\f]

which does not depend on the basis chosen. \f$\mu_i = 0\f$ for a coordinate that cannot move
and \f$\mu_i = 1\f$ for one that moves independently of all others.

@param n [in] number of coordinates (rows of Z)
@param k [in] dimension of the null space (columns of Z), full column rank
@param Z [in,out] n by k row major basis, orthonormalized in place
@param mu [out] n mobility numbers
*/
void ksl_linalg_mobilityNumbers_rmo(const int n, const int k, double* Z, double* mu);

#ifdef __cplusplus
}
#endif

#endif
