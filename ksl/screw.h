/**
@file
@author Kristopher Wehage, Roger Wehage
@brief Utilities to initialize and operate on screws
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
#ifndef _KSL_SCREW_H_
#define _KSL_SCREW_H_

#include "ksl/types.h"

#include "matrix.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
@brief double precision screw constructor
*/
static inline ksl_screw_t ksl_screw(const double m0, const double m1,
                                    const double m2, const double m3,
                                    const double m4, const double m5);

/*!
@brief single precision screw constructor
*/
static inline ksl_screwf_t ksl_screwf(const float m0, const float m1,
                                      const float m2, const float m3,
                                      const float m4, const float m5);

/*!
@brief allocate n double precision screw quantities on the heap, must be freed
by the user.
*/
ksl_screw_t* ksl_screw_alloc(int n);

/*!
@brief allocate n single precision screw quantities on the heap, must be freed
by the user.
*/
ksl_screwf_t* ksl_screwf_alloc(int n);

/*!
@brief Compute the screw norm of a double precision spatial screw.

@param s [in] input screw
@return screw norm
*/
static inline double ksl_screw_norm(const ksl_screw_t* s);

/*!
@brief Compute the screw norm of a single precision spatial screw.

@param s [in] input screw
@return screw norm
*/
static inline float ksl_screwf_norm(const ksl_screwf_t* s);

/*!
@brief TODO document this function
*/
static inline void ksl_screw_normalize(ksl_screw_t* s);

/*!
@brief TODO document this function
*/
static inline void ksl_screwf_normalize(ksl_screwf_t* s);

/*!
@brief TODO document this function
*/
void ksl_screw_normalized(const ksl_screw_t* si, ksl_screw_t* so);

/*!
@brief TODO document this function
*/
void ksl_screwf_normalized(const ksl_screwf_t* si, ksl_screwf_t* so);

/*!
@brief compute double precision dot product between a coscrew and screw
*/
static inline double ksl_dot_cs(const ksl_coscrew_t* ci, const ksl_screw_t* si);

/*!
@brief compute single precision dot product between a coscrew and screw
*/
static inline float ksl_dot_csf(const ksl_coscrewf_t* ci,
                                const ksl_screwf_t* si);

/*!
@brief TODO document this function
*/
static inline void ksl_screw_scale(ksl_screw_t* s, const double a);

/*!
@brief TODO document this function
*/
static inline void ksl_screwf_scale(ksl_screwf_t* s, const float a);

/*!
@brief Copy double precision ksl_screw_t si to so.

\f$S_i \rightarrow S_o\f$

@param si [in] screw to copy
@param so [out] si is copied to so
*/
static inline void ksl_screw_copy(const ksl_screw_t* si, ksl_screw_t* so);

/*!
@brief Copy a double precision screw into a row-major ordered double precision
array at specified row and column index as a column vector
*/
void ksl_screw_copy_rmo(const ksl_screw_t* si, double* A, int rowIndex,
                        int columnIndex, int stride);

/*!
@brief Copy a double precision screw into a column-major ordered double
precision array at specified row and column index as a column vector
*/
static inline void ksl_screw_copy_cmo(const ksl_screw_t* si, double* A,
                                      int rowIndex, int columnIndex,
                                      int stride);

/*!
@brief Copy the negative (i.e. inverse) of a double precision screw into a
row-major ordered double precision array at specified row and column index as a
column vector
*/
void ksl_screw_ncopy_rmo(const ksl_screw_t* si, double* A, int rowIndex,
                         int columnIndex, int stride);

/*!
@brief Copy the negative (i..e inverse) of a double precision screw into a
column-major ordered double precision array at specified row and column index as
a column vector
*/
void ksl_screw_ncopy_cmo(const ksl_screw_t* si, double* A, int rowIndex,
                         int columnIndex, int stride);

/*!
@brief Copy single precision ksl_screwf_t si to so.

\f$S_i \rightarrow S_o\f$

@param si [in] screw to copy
@param so [out] si is copied to so
*/
static inline void ksl_screwf_copy(const ksl_screwf_t* si, ksl_screwf_t* so);

/*!
@brief Copy a single precision screw into a row-major ordered double precision
array at specified row and column index as a column vector
*/
void ksl_screwf_copy_rmo(const ksl_screwf_t* si, float* A, int rowIndex,
                         int columnIndex, int stride);

/*!
@brief Copy a single precision screw into a column-major ordered double
precision array at specified row and column index as a column vector
*/
static inline void ksl_screwf_copy_cmo(const ksl_screwf_t* si, float* A,
                                       int rowIndex, int columnIndex,
                                       int stride);

/*!
@brief Copy the negative (i.e. inverse) of a single precision screw into a
row-major ordered double precision array at specified row and column index as a
column vector
*/
void ksl_screwf_ncopy_rmo(const ksl_screwf_t* si, float* A, int rowIndex,
                          int columnIndex, int stride);

/*!
@brief Copy the negative (i.e. inverse) of a single precision screw into a
column-major ordered double precision array at specified row and column index as
a column vector
*/
void ksl_screwf_ncopy_cmo(const ksl_screwf_t* si, float* A, int rowIndex,
                          int columnIndex, int stride);
/*!
@brief Invert (i.e. negate) a ksl_screw_t in place.

\f$\mathbf{\underline{s}}^{-1} \rightarrow \mathbf{\underline{s}}\f$

\f$-\mathbf{\underline{s}} \rightarrow \mathbf{\underline{s}}\f$

@param si [in/out] screw to invert
*/
static inline void ksl_screw_invert(ksl_screw_t* si);

/*!
@brief Invert (i.e. negate) a ksl_screwf_t in place.

\f$\mathbf{\underline{s}}^{-1} \rightarrow \mathbf{\underline{s}}\f$

\f$-\mathbf{\underline{s}} \rightarrow \mathbf{\underline{s}}\f$

@param si [in/out] screw to invert
*/
static inline void ksl_screwf_invert(ksl_screwf_t* si);

/*!
@brief Returns the inverse of a ksl_screw_t.

\f$\mathbf{\underline{s}}_i^{-1} \rightarrow \mathbf{\underline{s}}_o\f$

@param si [in] screw to invert
@param so [out] inverse of si
*/
static inline void ksl_screw_inverted(const ksl_screw_t* si, ksl_screw_t* so);

/*!
@brief Returns the inverse of a ksl_screwf_t.

\f$\mathbf{\underline{s}}_i^{-1} \rightarrow \mathbf{\underline{s}}_o\f$

@param si [in] screw to invert
@param so [out] inverse of si
*/
static inline void ksl_screwf_inverted(const ksl_screwf_t* si,
                                       ksl_screwf_t* so);

/*!
@brief TODO document this function
*/
static inline void ksl_product_as(const double k, const ksl_screw_t* si,
                                  ksl_screw_t* so);

/*!
@brief TODO document this function
*/
static inline void ksl_product_asf(const float k, const ksl_screwf_t* si,
                                   ksl_screwf_t* so);

/*!
@brief compute axpy (a * x + y \rightarrow y) operation for double precision
screws
*/
static inline void ksl_axpy_ss(const double, const ksl_screw_t*, ksl_screw_t*);

/*!
@brief compute axpy (a * x + y \rightarrow y) operation for single precision
screws
*/
static inline void ksl_axpy_ssf(const float, const ksl_screwf_t*,
                                ksl_screwf_t*);

/*!
@brief TODO document this function
*/
static inline void ksl_xpy_ss(const ksl_screw_t*, ksl_screw_t*);

/*!
@brief TODO document this function
*/
static inline void ksl_xpy_ssf(const ksl_screwf_t*, ksl_screwf_t*);

/*!
@brief TODO document this function
*/
static inline void ksl_nxpy_ss(const ksl_screw_t*, ksl_screw_t*);

/*!
@brief TODO document this function
*/
static inline void ksl_nxpy_ssf(const ksl_screwf_t*, ksl_screwf_t*);

/*!
@brief TODO document this function
*/
static inline void ksl_add_ss(const ksl_screw_t* s1i, const ksl_screw_t* s2i,
                              ksl_screw_t* so);

/*!
@brief TODO document this function
*/
static inline void ksl_add_ssf(const ksl_screwf_t* s1i, const ksl_screwf_t* s2i,
                               ksl_screwf_t* so);

/*!
@brief TODO document this function
*/
static inline void ksl_subtract_ss(const ksl_screw_t* s1i,
                                   const ksl_screw_t* s2i, ksl_screw_t* so);

/*!
@brief TODO document this function
*/
static inline void ksl_subtract_ssf(const ksl_screwf_t* s1i,
                                    const ksl_screwf_t* s2i, ksl_screwf_t* so);

/*!
@brief TODO document this function
*/
static inline void ksl_add_sst(const ksl_screw_t* si1, const ksl_screw_t* si2,
                               ksl_screw_t* so);

/*!
@brief TODO document this function
*/
static inline void ksl_add_sstf(const ksl_screwf_t* si1,
                                const ksl_screwf_t* si2, ksl_screwf_t* so);

/*!
@brief TODO document this function
*/
static inline void ksl_hstx(const ksl_SE3_t* Di, ksl_screw_t* ho);

/*!
@brief TODO document this function
*/
static inline void ksl_hstxf(const ksl_SE3f_t* Di, ksl_screwf_t* ho);

/*!
@brief TODO document this function
*/
static inline void ksl_hsty(const ksl_SE3_t* Di, ksl_screw_t* ho);

/*!
@brief TODO document this function
*/
static inline void ksl_hstyf(const ksl_SE3f_t* Di, ksl_screwf_t* ho);

/*!
@brief TODO document this function
*/
static inline void ksl_hstz(const ksl_SE3_t* ri, ksl_screw_t* ho);

/*!
@brief TODO document this function
*/
static inline void ksl_hstzf(const ksl_SE3f_t* ri, ksl_screwf_t* ho);

/*!
@brief TODO document this function
*/
static inline void ksl_hsrx(const ksl_SE3_t* Di, ksl_screw_t* ho);

/*!
@brief TODO document this function
*/
static inline void ksl_hsrxf(const ksl_SE3f_t* Di, ksl_screwf_t* ho);

/*!
@brief TODO document this function
*/
static inline void ksl_hsrxinv(const ksl_SE3_t* Di, ksl_screw_t* ho);

/*!
@brief TODO document this function
*/
static inline void ksl_hsrxinvf(const ksl_SE3f_t* Di, ksl_screwf_t* ho);

/*!
@brief TODO document this function
*/
static inline void ksl_hsry(const ksl_SE3_t* Di, ksl_screw_t* ho);

/*!
@brief TODO document this function
*/
static inline void ksl_hsryf(const ksl_SE3f_t* Di, ksl_screwf_t* ho);

/*!
@brief TODO document this function
*/
static inline void ksl_hsryinv(const ksl_SE3_t* Di, ksl_screw_t* ho);

/*!
@brief TODO document this function
*/
static inline void ksl_hsryinvf(const ksl_SE3f_t* Di, ksl_screwf_t* ho);
/*!
@brief TODO document this function
*/
static inline void ksl_hsrz(const ksl_SE3_t* Di, ksl_screw_t* ho);

static inline void ksl_hsra(const ksl_SE3_t* Di, const ksl_vec3_t* axis,
                            ksl_screw_t* ho);
static inline void ksl_hsrainv(const ksl_SE3_t* Di, const ksl_vec3_t* axis,
                               ksl_screw_t* ho);
static inline void ksl_hsraf(const ksl_SE3f_t* Di, const ksl_vec3f_t* axis,
                             ksl_screwf_t* ho);
static inline void ksl_hsrainvf(const ksl_SE3f_t* Di, const ksl_vec3f_t* axis,
                                ksl_screwf_t* ho);
static inline void ksl_hsta(const ksl_SE3_t* Di, const ksl_vec3_t* axis,
                            ksl_screw_t* ho);
static inline void ksl_hstainv(const ksl_SE3_t* Di, const ksl_vec3_t* axis,
                               ksl_screw_t* ho);
static inline void ksl_hstaf(const ksl_SE3f_t* Di, const ksl_vec3f_t* axis,
                             ksl_screwf_t* ho);
static inline void ksl_hstainvf(const ksl_SE3f_t* Di, const ksl_vec3f_t* axis,
                                ksl_screwf_t* ho);

/*!
@brief TODO document this function
*/
static inline void ksl_hsrzf(const ksl_SE3f_t* Di, ksl_screwf_t* ho);

/*!
@brief TODO document this function
*/
static inline void ksl_hsrzinv(const ksl_SE3_t* Di, ksl_screw_t* ho);

/*!
@brief TODO document this function
*/
static inline void ksl_hsrzinvf(const ksl_SE3f_t* Di, ksl_screwf_t* ho);

/*!
@brief TODO document this function
*/
static inline void ksl_hstxinv(const ksl_SE3_t* Di, ksl_screw_t* ho);

/*!
@brief TODO document this function
*/
static inline void ksl_hstxinvf(const ksl_SE3f_t* Di, ksl_screwf_t* ho);

/*!
@brief TODO document this function
*/
static inline void ksl_hstyinv(const ksl_SE3_t* Di, ksl_screw_t* ho);

/*!
@brief TODO document this function
*/
static inline void ksl_hstyinvf(const ksl_SE3f_t* Di, ksl_screwf_t* ho);

/*!
@brief TODO document this function
*/
static inline void ksl_hstzinv(const ksl_SE3_t* Di, ksl_screw_t* ho);

/*!
@brief TODO document this function
*/
static inline void ksl_hstzinvf(const ksl_SE3f_t* Di, ksl_screwf_t* ho);

/*!
@brief TODO document this function
*/
static inline void ksl_hsrxinv(const ksl_SE3_t* Di, ksl_screw_t* ho);

/*!
@brief TODO document this function
*/
void ksl_hrxinvf(const ksl_SE3f_t* Di, ksl_screwf_t* ho);

/*!
@brief TODO document this function
*/
static inline void ksl_hsryinv(const ksl_SE3_t* Di, ksl_screw_t* ho);

/*!
@brief TODO document this function
*/
static inline void ksl_hsryinvf(const ksl_SE3f_t* Di, ksl_screwf_t* ho);

/*!
@brief TODO document this function
*/
static inline void ksl_hsrzinv(const ksl_SE3_t* Di, ksl_screw_t* ho);

/*!
@brief TODO document this function
*/
static inline void ksl_hsrzinvf(const ksl_SE3f_t* Di, ksl_screwf_t* ho);

/*!
@brief double precision screw cross product

*/
static inline void ksl_cross_ss(const ksl_screw_t* s1i, const ksl_screw_t* s2i,
                                ksl_screw_t* so);

/*!
@brief single precision screw cross product

*/
static inline void ksl_cross_ssf(const ksl_screwf_t* s1i,
                                 const ksl_screwf_t* s2i, ksl_screwf_t* so);

/*!
@brief TODO document this function
*/
static inline void ksl_cross_sst(const ksl_screw_t* s1i, const ksl_screw_t* s2i,
                                 ksl_screw_t* so);

/*!
@brief TODO document this function
*/
static inline void ksl_cross_sstf(const ksl_screwf_t* s1i,
                                  const ksl_screwf_t* s2i, ksl_screwf_t* so);

/*!
@brief Rotate a double precision screw

Store product of direction cosine matrix `r_oi` and screw `s_i` in `s_o`.

\f$ [Ad]_{(R^{oi})} \mathbf{\underline{s}}_{io,i}^i \rightarrow
\mathbf{\underline{s}}_{io,i}^o \f$

\f$ \begin{bmatrix} R^{oi} & 0\\0 & R^{oi} \end{bmatrix}
\begin{Bmatrix} \underline{v}_{io,i}^i \\ \underline{\omega}_{io}^i
\end{Bmatrix} \rightarrow \begin{Bmatrix} \underline{v}_{io,i}^o \\
\underline{\omega}_{io}^o \end{Bmatrix}\f$

\f$ R^{oi} \underline{v}_{io,i}^i \rightarrow \underline{v}_{io,i}^i,
R^{oi} \underline{\omega}_{io}^i \rightarrow \underline{\omega}_{io}^o \f$

@param r_oi [in] an SO3 rotation matrix
@param s_i [in] a 6x1 screw
@param s_o [out] the product of r_oi * s_i is returned in s_o
*/
static inline void ksl_product_Adrs(const ksl_mat3x3_t* r_oi,
                                    const ksl_screw_t* s_i, ksl_screw_t* s_o);

/*!
@brief Rotate the inverse of a double precision screw

Store product of direction cosine matrix `r_oi` and the inverse of screw `s_i`
in `s_o`.

\f$ [Ad]_{(R^{oi})} (-\mathbf{\underline{s}}_{io,i}^i) \rightarrow
\mathbf{\underline{s}}_{io,i}^o \f$

\f$ -[Ad]_{(R^{oi})} \mathbf{\underline{s}}_{io,i}^i \rightarrow
\mathbf{\underline{s}}_{io,i}^o \f$

\f$ \begin{bmatrix} R^{oi} & 0\\0 & R^{oi} \end{bmatrix}
\begin{Bmatrix} -\underline{v}_{io,i}^i \\ -\underline{\omega}_{io}^i
\end{Bmatrix} \rightarrow \begin{Bmatrix} \underline{v}_{io,i}^o \\
\underline{\omega}_{io}^o \end{Bmatrix}\f$

\f$ \begin{bmatrix} -R^{oi} & 0\\0 & -R^{oi} \end{bmatrix}
\begin{Bmatrix} \underline{v}_{io,i}^i \\ \underline{\omega}_{io}^i
\end{Bmatrix} \rightarrow \begin{Bmatrix} \underline{v}_{io,i}^o \\
\underline{\omega}_{io}^o \end{Bmatrix}\f$

\f$ -R^{oi} \underline{v}_{io,i}^i \rightarrow \underline{v}_{io,i}^i,
-R^{oi} \underline{\omega}_{io}^i \rightarrow \underline{\omega}_{io}^o \f$

@param r_oi [in] an SO3 rotation matrix
@param s_i [in] a 6x1 screw
@param s_o [out] the product of r_oi * s_i is returned in s_o
*/
static inline void ksl_product_Adrsinv(const ksl_mat3x3_t* r_oi,
                                       const ksl_screw_t* s_i,
                                       ksl_screw_t* s_o);

/*!
@brief Rotate a single precision screw

Store product of direction cosine matrix `r_oi` and screw `s_i` in `s_o`.

\f$ [Ad]_{(R^{oi})} \mathbf{\underline{s}}_{io,i}^i \rightarrow
\mathbf{\underline{s}}_{io,i}^o \f$

\f$ \begin{bmatrix} R^{oi} & 0\\0 & R^{oi} \end{bmatrix}
\begin{Bmatrix} \underline{v}_{io,i}^i \\ \underline{\omega}_{io}^i
\end{Bmatrix} \rightarrow \begin{Bmatrix} \underline{v}_{io,i}^o \\
\underline{\omega}_{io}^o \end{Bmatrix}\f$

\f$ R^{oi} \underline{v}_{io,i}^i \rightarrow \underline{v}_{io,i}^i,
R^{oi} \underline{\omega}_{io}^i \rightarrow \underline{\omega}_{io}^o \f$

@param r_oi [in] an SO3 rotation matrix
@param s_i [in] a 6x1 screw
@param s_o [out] the product of r_oi * s_i is returned in s_o
*/
static inline void ksl_product_Adrsf(const ksl_mat3x3f_t* r_oi,
                                     const ksl_screwf_t* s_i,
                                     ksl_screwf_t* s_o);

/*!
@brief Rotate the inverse of a single precision screw

Store product of direction cosine matrix `r_oi` and the inverse of screw `s_i`
in `s_o`.

\f$ [Ad]_{(R^{oi})} (-\mathbf{\underline{s}}_{io,i}^i) \rightarrow
\mathbf{\underline{s}}_{io,i}^o \f$

\f$ -[Ad]_{(R^{oi})} \mathbf{\underline{s}}_{io,i}^i \rightarrow
\mathbf{\underline{s}}_{io,i}^o \f$

\f$ \begin{bmatrix} R^{oi} & 0\\0 & R^{oi} \end{bmatrix}
\begin{Bmatrix} -\underline{v}_{io,i}^i \\ -\underline{\omega}_{io}^i
\end{Bmatrix} \rightarrow \begin{Bmatrix} \underline{v}_{io,i}^o \\
\underline{\omega}_{io}^o \end{Bmatrix}\f$

\f$ \begin{bmatrix} -R^{oi} & 0\\0 & -R^{oi} \end{bmatrix}
\begin{Bmatrix} \underline{v}_{io,i}^i \\ \underline{\omega}_{io}^i
\end{Bmatrix} \rightarrow \begin{Bmatrix} \underline{v}_{io,i}^o \\
\underline{\omega}_{io}^o \end{Bmatrix}\f$

\f$ -R^{oi} \underline{v}_{io,i}^i \rightarrow \underline{v}_{io,i}^i,
-R^{oi} \underline{\omega}_{io}^i \rightarrow \underline{\omega}_{io}^o \f$

@param r_oi [in] an SO3 rotation matrix
@param s_i [in] a 6x1 screw
@param s_o [out] the product of r_oi * s_i is returned in s_o
*/
static inline void ksl_product_Adrsinvf(const ksl_mat3x3f_t* r_oi,
                                        const ksl_screwf_t* s_i,
                                        ksl_screwf_t* s_o);

/*!
@brief Perform inverse rotation of a double precision screw

Store product of the inverse of direction cosine matrix `r_io` with screw `s_i`
in `s_o`, where `r_io` is a member of SO(3).

\f$ [Ad]_{(R^{io})^{-1}} \mathbf{\underline{s}}_{io,i}^i \rightarrow
\mathbf{\underline{s}}_{io,i}^o \f$

\f$ [Ad]_{(R^{oi})} \mathbf{\underline{s}}_{io,i}^i \rightarrow
\mathbf{\underline{s}}_{io,i}^o \f$

\f$ \begin{bmatrix} (R^{io})^{-1} & 0\\0 & (R^{io})^{-1} \end{bmatrix}
\begin{Bmatrix} \underline{v}_{io,i}^i \\ \underline{\omega}_{io}^i
\end{Bmatrix} \rightarrow \begin{Bmatrix} \underline{v}_{io,i}^o \\
\underline{\omega}_{io}^o \end{Bmatrix}\f$

\f$ \begin{bmatrix} R^{oi} & 0\\0 & R^{oi} \end{bmatrix}
\begin{Bmatrix} \underline{v}_{io,i}^i \\ \underline{\omega}_{io}^i
\end{Bmatrix} \rightarrow \begin{Bmatrix} \underline{v}_{io,i}^o \\
\underline{\omega}_{io}^o \end{Bmatrix}\f$

\f$ (R^{io})^{-1} \underline{v}_{io,i}^i \rightarrow \underline{v}_{io,i}^i,
(R^{io})^{-1} \underline{\omega}_{io}^i \rightarrow \underline{\omega}_{io}^o
\f$

\f$ R^{oi} \underline{v}_{io,i}^i \rightarrow \underline{v}_{io,i}^i,
R^{oi} \underline{\omega}_{io}^i \rightarrow \underline{\omega}_{io}^o \f$

@param r_io [in] an SO3 rotation matrix
@param s_i [in] a 6x1 screw
@param s_o [out] the product of r_oi * s_i is returned in s_o
*/
static inline void ksl_product_Adrinvs(const ksl_mat3x3_t* r_io,
                                       const ksl_screw_t* s_i,
                                       ksl_screw_t* s_o);

/*!
@brief Perform inverse rotation of a single precision screw

Store product of the inverse of direction cosine matrix `r_io` with screw `s_i`
in `s_o`, where `r_io` is a member of SO(3).

\f$ [Ad]_{(R^{io})^{-1}} \mathbf{\underline{s}}_{io,i}^i \rightarrow
\mathbf{\underline{s}}_{io,i}^o \f$

\f$ [Ad]_{(R^{oi})} \mathbf{\underline{s}}_{io,i}^i \rightarrow
\mathbf{\underline{s}}_{io,i}^o \f$

\f$ \begin{bmatrix} (R^{io})^{-1} & 0\\0 & (R^{io})^{-1} \end{bmatrix}
\begin{Bmatrix} \underline{v}_{io,i}^i \\ \underline{\omega}_{io}^i
\end{Bmatrix} \rightarrow \begin{Bmatrix} \underline{v}_{io,i}^o \\
\underline{\omega}_{io}^o \end{Bmatrix}\f$

\f$ \begin{bmatrix} R^{oi} & 0\\0 & R^{oi} \end{bmatrix}
\begin{Bmatrix} \underline{v}_{io,i}^i \\ \underline{\omega}_{io}^i
\end{Bmatrix} \rightarrow \begin{Bmatrix} \underline{v}_{io,i}^o \\
\underline{\omega}_{io}^o \end{Bmatrix}\f$

\f$ (R^{io})^{-1} \underline{v}_{io,i}^i \rightarrow \underline{v}_{io,i}^i,
(R^{io})^{-1} \underline{\omega}_{io}^i \rightarrow \underline{\omega}_{io}^o
\f$

\f$ R^{oi} \underline{v}_{io,i}^i \rightarrow \underline{v}_{io,i}^i,
R^{oi} \underline{\omega}_{io}^i \rightarrow \underline{\omega}_{io}^o \f$

@param r_io [in] an SO3 rotation matrix
@param s_i [in] a 6x1 screw
@param s_o [out] the product of r_oi * s_i is returned in s_o
*/
static inline void ksl_product_Adrinvsf(const ksl_mat3x3f_t* r_io,
                                        const ksl_screwf_t* s_i,
                                        ksl_screwf_t* s_o);

/*!
@brief Translate a double precision screw

Perform a spatial translation of screw `s_i` using the translation vector
`t_oi`, storing results in `s_o`.

\f$ [Ad]_{(\underline{t}_{oi}^i)} \mathbf{\underline{s}}_{io,i}^i \rightarrow
\mathbf{\underline{s}}_{io,o}^i \f$

\f$ \begin{bmatrix} I & \underline{\tilde{r}}_{oi}^i \\0 & I
\end{bmatrix}
\begin{Bmatrix}
  \underline{v}_{io,i}^i \\
  \underline{\omega}_{io}^i
\end{Bmatrix}
\rightarrow
\begin{Bmatrix}
  \underline{v}_{io,o}^i \\
  \underline{\omega}_{io}^i
\end{Bmatrix}\f$

\f$ \underline{v}_{io,i}^i + \underline{\tilde{r}}_{oi}^i
\underline{\omega}_{io}^i \rightarrow \underline{v}_{io,o}^i,
\underline{\omega}_{io}^i \rightarrow \underline{\omega}_{io}^i \f$
*/
static inline void ksl_product_Adts(const ksl_vec3_t* t_oi,
                                    const ksl_screw_t* s_i, ksl_screw_t* s_o);

/*!
@brief Translate a single precision screw

Perform a spatial translation of screw `s_i` using the translation vector
`t_oi`, storing results in `s_o`.

\f$ [Ad]_{(\underline{t}_{oi}^i)} \mathbf{\underline{s}}_{io,i}^i \rightarrow
\mathbf{\underline{s}}_{io,o}^i \f$

\f$ \begin{bmatrix} I & \underline{\tilde{r}}_{oi}^i \\0 & I
\end{bmatrix}
\begin{Bmatrix}
  \underline{v}_{io,i}^i \\
  \underline{\omega}_{io}^i
\end{Bmatrix}
\rightarrow
\begin{Bmatrix}
  \underline{v}_{io,o}^i \\
  \underline{\omega}_{io}^i
\end{Bmatrix}\f$

\f$ \underline{v}_{io,i}^i + \underline{\tilde{r}}_{oi}^i
\underline{\omega}_{io}^i \rightarrow \underline{v}_{io,o}^i,
\underline{\omega}_{io}^i \rightarrow \underline{\omega}_{io}^i \f$
*/
static inline void ksl_product_Adtsf(const ksl_vec3f_t* ti,
                                     const ksl_screwf_t* si, ksl_screwf_t* so);

/*!
@brief TODO document this function
*/
static inline void ksl_product_Adtinvs(const ksl_vec3_t* ti,
                                       const ksl_screw_t* si, ksl_screw_t* so);

/*!
@brief TODO document this function
*/
static inline void ksl_product_Adtinvsf(const ksl_vec3f_t* ti,
                                        const ksl_screwf_t* si,
                                        ksl_screwf_t* so);

/*!
@brief TODO document this function
*/
static inline void ksl_product_Adtsinv(const ksl_vec3_t* ti,
                                       const ksl_screw_t* si, ksl_screw_t* so);

/*!
@brief TODO document this function
*/
static inline void ksl_product_Adtsinvf(const ksl_vec3f_t* ti,
                                        const ksl_screwf_t* si,
                                        ksl_screwf_t* so);

/*!
@brief General spatial transformation a double precision screw

Store product of direction cosine matrix ri with spatial vector si in so.

\f$ R_i * S_i[0:2] \rightarrow S_o[0:2]\f$

\f$ R_i * S_i[3:5] \rightarrow S_o[3:5]\f$

@param ri a SO3 rotation matrix
@param si a 1x6 screw
@param so the output of ri * si is returned in so
*/
static inline void ksl_product_Ads(const ksl_SE3_t* Di, const ksl_screw_t* si,
                                   ksl_screw_t* so);

/*!
@brief TODO document this function
*/
static inline void ksl_product_Adsinv(const ksl_SE3_t* Di,
                                      const ksl_screw_t* si, ksl_screw_t* so);

/*!
@brief TODO document this function
*/
static inline void ksl_product_Adsinvf(const ksl_SE3f_t* Di,
                                       const ksl_screwf_t* si,
                                       ksl_screwf_t* so);

/*!
@brief General spatial transformation a single precision screw

Store product of direction cosine matrix ri with spatial vector si in so.

\f$ R_i * S_i[0:2] \rightarrow S_o[0:2]\f$

\f$ R_i * S_i[3:5] \rightarrow S_o[3:5]\f$

@param ri a SO3 rotation matrix
@param si a 1x6 screw
@param so the output of ri * si is returned in so
*/
static inline void ksl_product_Adsf(const ksl_SE3f_t* Di,
                                    const ksl_screwf_t* si, ksl_screwf_t* so);

/*!
@brief TODO document this function
*/
static inline void ksl_product_Adinvs(const ksl_SE3_t* Di,
                                      const ksl_screw_t* si, ksl_screw_t* so);

/*!
@brief TODO document this function
*/
static inline void ksl_product_Adinvsf(const ksl_SE3f_t* Di,
                                       const ksl_screwf_t* si,
                                       ksl_screwf_t* so);

#ifdef __cplusplus
}
#endif

/* -------- inline definitions -------- */

#include <assert.h>
#include <math.h>
#include <string.h>

#include "ksl/matrix.h"
#include "ksl/vec3.h"

#ifdef __cplusplus
extern "C" {
#endif

static inline ksl_screw_t ksl_screw(const double m0, const double m1,
                                    const double m2, const double m3,
                                    const double m4, const double m5) {
  ksl_screw_t s;
  s.m0 = m0;
  s.m1 = m1;
  s.m2 = m2;
  s.m3 = m3;
  s.m4 = m4;
  s.m5 = m5;
  return s;
}

static inline ksl_screwf_t ksl_screwf(const float m0, const float m1,
                                      const float m2, const float m3,
                                      const float m4, const float m5) {
  ksl_screwf_t s;
  s.m0 = m0;
  s.m1 = m1;
  s.m2 = m2;
  s.m3 = m3;
  s.m4 = m4;
  s.m5 = m5;
  return s;
}

static inline double ksl_screw_norm(const ksl_screw_t* KSL_RESTRICT s) {
  const double eps = 1e-9;
  if((fabs(s->ang.x) < eps) && (fabs(s->ang.y) < eps) &&
     (fabs(s->ang.z) < eps)) {
    return (ksl_vec3_l2norm(&s->lin));
  } else {
    return (ksl_vec3_l2norm(&s->ang));
  }
}

static inline float ksl_screwf_norm(const ksl_screwf_t* KSL_RESTRICT s) {
  const float eps = 1e-6;
  if((fabs(s->ang.x) < eps) && (fabs(s->ang.y) < eps) &&
     (fabs(s->ang.z) < eps)) {
    return (ksl_vec3f_l2norm(&s->lin));
  } else {
    return (ksl_vec3f_l2norm(&s->ang));
  }
}

static inline void ksl_screw_normalize(ksl_screw_t* s) {
  const double eps = 1e-9;
  if((fabs(s->ang.x) < eps) && (fabs(s->ang.y) < eps) &&
     (fabs(s->ang.z) < eps)) {
    ksl_vec3_normalize(&s->lin);
  } else {
    double ang_inv_norm = 1.0 / ksl_vec3_l2norm(&s->ang);
    ksl_vec3_scale(&s->lin, ang_inv_norm);
    ksl_vec3_scale(&s->ang, ang_inv_norm);
  }
}

static inline void ksl_screwf_normalize(ksl_screwf_t* s) {
  const float eps = 1e-6;
  if((fabs(s->ang.x) < eps) && (fabs(s->ang.y) < eps) &&
     (fabs(s->ang.z) < eps)) {
    ksl_vec3f_normalize(&s->lin);
  } else {
    float ang_inv_norm = 1.0 / ksl_vec3f_l2norm(&s->ang);
    ksl_vec3f_scale(&s->lin, ang_inv_norm);
    ksl_vec3f_scale(&s->ang, ang_inv_norm);
  }
}

static inline double ksl_dot_cs(const ksl_coscrew_t* KSL_RESTRICT ci,
                                const ksl_screw_t* KSL_RESTRICT si) {
  return ci->m0 * si->m0 + ci->m1 * si->m1 + ci->m2 * si->m2 + ci->m3 * si->m3 +
         ci->m4 * si->m4 + ci->m5 * si->m5;
}

static inline float ksl_dot_csf(const ksl_coscrewf_t* KSL_RESTRICT ci,
                                const ksl_screwf_t* KSL_RESTRICT si) {
  return ci->m0 * si->m0 + ci->m1 * si->m1 + ci->m2 * si->m2 + ci->m3 * si->m3 +
         ci->m4 * si->m4 + ci->m5 * si->m5;
}

static inline void ksl_screw_scale(ksl_screw_t* KSL_RESTRICT s,
                                   const double k) {
  for(int i = 0; i < 6; i++) {
    s->at[i] *= k;
  }
}

static inline void ksl_screwf_scale(ksl_screwf_t* KSL_RESTRICT s,
                                    const float k) {
  for(int i = 0; i < 6; i++) {
    s->at[i] *= k;
  }
}

static inline void ksl_screw_copy(const ksl_screw_t* KSL_RESTRICT si,
                                  ksl_screw_t* KSL_RESTRICT so) {
  memcpy(so, si, sizeof(ksl_screw_t));
}

static inline void ksl_screw_copy_cmo(const ksl_screw_t* si, double* A, int row,
                                      int column, int stride) {
  memcpy(A + (column * stride) + row, si, sizeof(ksl_screw_t));
}

static inline void ksl_screwf_copy(const ksl_screwf_t* KSL_RESTRICT si,
                                   ksl_screwf_t* KSL_RESTRICT so) {
  memcpy(so, si, sizeof(ksl_screwf_t));
}

static inline void ksl_screwf_copy_cmo(const ksl_screwf_t* si, float* A,
                                       int row, int column, int stride) {
  memcpy(A + (column * stride) + row, si, sizeof(ksl_screwf_t));
}

static inline void ksl_screw_invert(ksl_screw_t* KSL_RESTRICT s) {
  for(int i = 0; i < 6; i++) {
    s->at[i] = -s->at[i];
  }
}

static inline void ksl_screwf_invert(ksl_screwf_t* KSL_RESTRICT s) {
  for(int i = 0; i < 6; i++) {
    s->at[i] = -s->at[i];
  }
}

static inline void ksl_screw_inverted(const ksl_screw_t* KSL_RESTRICT si,
                                      ksl_screw_t* KSL_RESTRICT so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] = -si->at[i];
  }
}

static inline void ksl_screwf_inverted(const ksl_screwf_t* KSL_RESTRICT si,
                                       ksl_screwf_t* KSL_RESTRICT so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] = -si->at[i];
  }
}

static inline void ksl_axpy_ss(const double a,
                               const ksl_screw_t* KSL_RESTRICT x,
                               ksl_screw_t* KSL_RESTRICT y) {
  for(int i = 0; i < 6; i++) {
    y->at[i] += a * x->at[i];
  }
}

static inline void ksl_axpy_ssf(const float a,
                                const ksl_screwf_t* KSL_RESTRICT x,
                                ksl_screwf_t* KSL_RESTRICT y) {
  for(int i = 0; i < 6; i++) {
    y->at[i] += a * x->at[i];
  }
}

static inline void ksl_xpy_ss(const ksl_screw_t* KSL_RESTRICT s1i,
                              ksl_screw_t* KSL_RESTRICT so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] += s1i->at[i];
  }
}

static inline void ksl_xpy_ssf(const ksl_screwf_t* KSL_RESTRICT s1i,
                               ksl_screwf_t* KSL_RESTRICT so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] += s1i->at[i];
  }
}

static inline void ksl_nxpy_ss(const ksl_screw_t* KSL_RESTRICT s1i,
                               ksl_screw_t* KSL_RESTRICT so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] -= s1i->at[i];
  }
}

static inline void ksl_nxpy_ssf(const ksl_screwf_t* KSL_RESTRICT s1i,
                                ksl_screwf_t* KSL_RESTRICT so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] -= s1i->at[i];
  }
}

static inline void ksl_product_as(const double k,
                                  const ksl_screw_t* KSL_RESTRICT si,
                                  ksl_screw_t* KSL_RESTRICT so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] = k * si->at[i];
  }
}

static inline void ksl_product_asf(const float k,
                                   const ksl_screwf_t* KSL_RESTRICT si,
                                   ksl_screwf_t* KSL_RESTRICT so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] = k * si->at[i];
  }
}

static inline void ksl_add_ss(const ksl_screw_t* KSL_RESTRICT s1i,
                              const ksl_screw_t* KSL_RESTRICT s2i,
                              ksl_screw_t* KSL_RESTRICT so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] = s1i->at[i] + s2i->at[i];
  }
}

static inline void ksl_add_ssf(const ksl_screwf_t* KSL_RESTRICT s1i,
                               const ksl_screwf_t* KSL_RESTRICT s2i,
                               ksl_screwf_t* KSL_RESTRICT so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] = s1i->at[i] + s2i->at[i];
  }
}

static inline void ksl_subtract_ss(const ksl_screw_t* KSL_RESTRICT s1i,
                                   const ksl_screw_t* KSL_RESTRICT s2i,
                                   ksl_screw_t* KSL_RESTRICT so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] = s1i->at[i] - s2i->at[i];
  }
}

static inline void ksl_subtract_ssf(const ksl_screwf_t* KSL_RESTRICT s1i,
                                    const ksl_screwf_t* KSL_RESTRICT s2i,
                                    ksl_screwf_t* KSL_RESTRICT so) {
  for(int i = 0; i < 6; i++) {
    so->at[i] = s1i->at[i] - s2i->at[i];
  }
}

static inline void ksl_add_sst(const ksl_screw_t* KSL_RESTRICT si1,
                               const ksl_screw_t* KSL_RESTRICT si2,
                               ksl_screw_t* KSL_RESTRICT so) {
  ksl_screw_t s;
  ksl_screw_copy(si1, &s);
  s.at[0] += si2->at[0];
  s.at[1] += si2->at[1];
  s.at[2] += si2->at[2];
  ksl_screw_copy(&s, so);
}

static inline void ksl_add_sstf(const ksl_screwf_t* KSL_RESTRICT si1,
                                const ksl_screwf_t* KSL_RESTRICT si2,
                                ksl_screwf_t* KSL_RESTRICT so) {
  ksl_screwf_t s;
  ksl_screwf_copy(si1, &s);
  s.at[0] += si2->at[0];
  s.at[1] += si2->at[1];
  s.at[2] += si2->at[2];
  ksl_screwf_copy(&s, so);
}

static inline void ksl_hstx(const ksl_SE3_t* KSL_RESTRICT Di,
                            ksl_screw_t* KSL_RESTRICT hso) {
  ksl_vec3_copy(&Di->R.v0, &hso->lin);
  memset(&hso->ang, 0, 3 * sizeof(double));
}

static inline void ksl_hstxf(const ksl_SE3f_t* KSL_RESTRICT Di,
                             ksl_screwf_t* KSL_RESTRICT hso) {
  ksl_vec3f_copy(&Di->R.v0, &hso->lin);
  memset(&hso->ang, 0, 3 * sizeof(float));
}

static inline void ksl_hsty(const ksl_SE3_t* KSL_RESTRICT Di,
                            ksl_screw_t* KSL_RESTRICT hso) {
  ksl_vec3_copy(&Di->R.v1, &hso->lin);
  memset(&hso->ang, 0, 3 * sizeof(double));
}

static inline void ksl_hstyf(const ksl_SE3f_t* KSL_RESTRICT Di,
                             ksl_screwf_t* KSL_RESTRICT hso) {
  ksl_vec3f_copy(&Di->R.v1, &hso->lin);
  memset(&hso->ang, 0, 3 * sizeof(float));
}

static inline void ksl_hstz(const ksl_SE3_t* KSL_RESTRICT Di,
                            ksl_screw_t* KSL_RESTRICT hso) {
  ksl_vec3_copy(&Di->R.v2, &hso->lin);
  memset(&hso->ang, 0, 3 * sizeof(double));
}

static inline void ksl_hstzf(const ksl_SE3f_t* KSL_RESTRICT Di,
                             ksl_screwf_t* KSL_RESTRICT hso) {
  ksl_vec3f_copy(&Di->R.v2, &hso->lin);
  memset(&hso->ang, 0, 3 * sizeof(float));
}

static inline void ksl_hsrx(const ksl_SE3_t* KSL_RESTRICT Di,
                            ksl_screw_t* KSL_RESTRICT hso) {
  ksl_vec3_copy(&Di->R.v0, &hso->ang);
  ksl_cross_vv(&Di->t, &hso->ang, &hso->lin);
}

static inline void ksl_hsrxf(const ksl_SE3f_t* KSL_RESTRICT Di,
                             ksl_screwf_t* KSL_RESTRICT hso) {
  ksl_vec3f_copy(&Di->R.v0, &hso->ang);
  ksl_cross_vvf(&Di->t, &hso->ang, &hso->lin);
}

static inline void ksl_hsry(const ksl_SE3_t* KSL_RESTRICT Di,
                            ksl_screw_t* KSL_RESTRICT hso) {
  ksl_vec3_copy(&Di->R.v1, &hso->ang);
  ksl_cross_vv(&Di->t, &hso->ang, &hso->lin);
}

static inline void ksl_hsryf(const ksl_SE3f_t* KSL_RESTRICT Di,
                             ksl_screwf_t* KSL_RESTRICT hso) {
  ksl_vec3f_copy(&Di->R.v1, &hso->ang);
  ksl_cross_vvf(&Di->t, &hso->ang, &hso->lin);
}

static inline void ksl_hsrz(const ksl_SE3_t* KSL_RESTRICT Di,
                            ksl_screw_t* KSL_RESTRICT hso) {
  ksl_vec3_copy(&Di->R.v2, &hso->ang);
  ksl_cross_vv(&Di->t, &hso->ang, &hso->lin);
}

static inline void ksl_hsrzf(const ksl_SE3f_t* KSL_RESTRICT Di,
                             ksl_screwf_t* KSL_RESTRICT hso) {
  ksl_vec3f_copy(&Di->R.v2, &hso->ang);
  ksl_cross_vvf(&Di->t, &hso->ang, &hso->lin);
}

static inline void ksl_hstxinv(const ksl_SE3_t* KSL_RESTRICT Di,
                               ksl_screw_t* KSL_RESTRICT hso) {
  ksl_vec3_inverted(&Di->R.v0, &hso->lin);
  memset(&hso->ang, 0, 3 * sizeof(double));
}

static inline void ksl_hstxinvf(const ksl_SE3f_t* KSL_RESTRICT Di,
                                ksl_screwf_t* KSL_RESTRICT hso) {
  ksl_vec3f_inverted(&Di->R.v0, &hso->lin);
  memset(&hso->ang, 0, 3 * sizeof(float));
}

static inline void ksl_hstyinv(const ksl_SE3_t* KSL_RESTRICT Di,
                               ksl_screw_t* KSL_RESTRICT hso) {
  ksl_vec3_inverted(&Di->R.v1, &hso->lin);
  memset(&hso->ang, 0, 3 * sizeof(double));
}

static inline void ksl_hstyinvf(const ksl_SE3f_t* KSL_RESTRICT Di,
                                ksl_screwf_t* KSL_RESTRICT hso) {
  ksl_vec3f_inverted(&Di->R.v1, &hso->lin);
  memset(&hso->ang, 0, 3 * sizeof(float));
}

static inline void ksl_hstzinv(const ksl_SE3_t* KSL_RESTRICT Di,
                               ksl_screw_t* KSL_RESTRICT hso) {
  ksl_vec3_inverted(&Di->R.v2, &hso->lin);
  memset(&hso->ang, 0, 3 * sizeof(double));
}

static inline void ksl_hstzinvf(const ksl_SE3f_t* KSL_RESTRICT Di,
                                ksl_screwf_t* KSL_RESTRICT hso) {
  ksl_vec3f_inverted(&Di->R.v2, &hso->lin);
  memset(&hso->ang, 0, 3 * sizeof(float));
}

static inline void ksl_hsrxinv(const ksl_SE3_t* KSL_RESTRICT Di,
                               ksl_screw_t* KSL_RESTRICT hso) {
  ksl_vec3_inverted(&Di->R.v0, &hso->ang);
  ksl_cross_vv(&Di->t, &hso->ang, &hso->lin);
}

static inline void ksl_hsrxinvf(const ksl_SE3f_t* KSL_RESTRICT Di,
                                ksl_screwf_t* KSL_RESTRICT hso) {
  ksl_vec3f_inverted(&Di->R.v0, &hso->ang);
  ksl_cross_vvf(&Di->t, &hso->ang, &hso->lin);
}

static inline void ksl_hsryinv(const ksl_SE3_t* KSL_RESTRICT Di,
                               ksl_screw_t* KSL_RESTRICT hso) {
  ksl_vec3_inverted(&Di->R.v1, &hso->ang);
  ksl_cross_vv(&Di->t, &hso->ang, &hso->lin);
}

static inline void ksl_hsryinvf(const ksl_SE3f_t* KSL_RESTRICT Di,
                                ksl_screwf_t* KSL_RESTRICT hso) {
  ksl_vec3f_inverted(&Di->R.v1, &hso->ang);
  ksl_cross_vvf(&Di->t, &hso->ang, &hso->lin);
}

static inline void ksl_hsrzinv(const ksl_SE3_t* KSL_RESTRICT Di,
                               ksl_screw_t* KSL_RESTRICT hso) {
  ksl_vec3_inverted(&Di->R.v2, &hso->ang);
  ksl_cross_vv(&Di->t, &hso->ang, &hso->lin);
}

static inline void ksl_hsrzinvf(const ksl_SE3f_t* KSL_RESTRICT Di,
                                ksl_screwf_t* KSL_RESTRICT hso) {
  ksl_vec3f_inverted(&Di->R.v2, &hso->ang);
  ksl_cross_vvf(&Di->t, &hso->ang, &hso->lin);
}

static inline void ksl_hsra(const ksl_SE3_t* KSL_RESTRICT Di,
                            const ksl_vec3_t* axis,
                            ksl_screw_t* KSL_RESTRICT hso) {
  ksl_product_drv(&Di->R, axis, &hso->ang);
  ksl_cross_vv(&Di->t, &hso->ang, &hso->lin);
}

static inline void ksl_hsrainv(const ksl_SE3_t* KSL_RESTRICT Di,
                               const ksl_vec3_t* axis,
                               ksl_screw_t* KSL_RESTRICT hso) {
  ksl_product_drvinv(&Di->R, axis, &hso->ang);
  ksl_cross_vv(&Di->t, &hso->ang, &hso->lin);
}

static inline void ksl_hsraf(const ksl_SE3f_t* KSL_RESTRICT Di,
                             const ksl_vec3f_t* axis,
                             ksl_screwf_t* KSL_RESTRICT hso) {
  ksl_product_drvf(&Di->R, axis, &hso->ang);
  ksl_cross_vvf(&Di->t, &hso->ang, &hso->lin);
}

static inline void ksl_hsrainvf(const ksl_SE3f_t* KSL_RESTRICT Di,
                                const ksl_vec3f_t* axis,
                                ksl_screwf_t* KSL_RESTRICT hso) {
  ksl_product_drvinvf(&Di->R, axis, &hso->ang);
  ksl_cross_vvf(&Di->t, &hso->ang, &hso->lin);
}

static inline void ksl_hsta(const ksl_SE3_t* KSL_RESTRICT Di,
                            const ksl_vec3_t* axis,
                            ksl_screw_t* KSL_RESTRICT hso) {
  ksl_product_drv(&Di->R, axis, &hso->lin);
  memset(&hso->ang, 0, 3 * sizeof(double));
}

static inline void ksl_hstainv(const ksl_SE3_t* KSL_RESTRICT Di,
                               const ksl_vec3_t* axis,
                               ksl_screw_t* KSL_RESTRICT hso) {
  ksl_product_drvinv(&Di->R, axis, &hso->lin);
  memset(&hso->ang, 0, 3 * sizeof(double));
}

static inline void ksl_hstaf(const ksl_SE3f_t* KSL_RESTRICT Di,
                             const ksl_vec3f_t* axis,
                             ksl_screwf_t* KSL_RESTRICT hso) {
  ksl_product_drvf(&Di->R, axis, &hso->lin);
  memset(&hso->ang, 0, 3 * sizeof(float));
}

static inline void ksl_hstainvf(const ksl_SE3f_t* KSL_RESTRICT Di,
                                const ksl_vec3f_t* axis,
                                ksl_screwf_t* KSL_RESTRICT hso) {
  ksl_product_drvinvf(&Di->R, axis, &hso->lin);
  memset(&hso->ang, 0, 3 * sizeof(float));
}

static inline void ksl_cross_ss(const ksl_screw_t* KSL_RESTRICT s1i,
                                const ksl_screw_t* KSL_RESTRICT s2i,
                                ksl_screw_t* KSL_RESTRICT so) {

  ksl_screw_t s;

  /* s.lin <- s1i->ang x s2i->lin */
  ksl_cross_vv(&s1i->ang, &s2i->lin, &s.lin);

  /* s.ang <- s1i->ang x s2i->ang */
  ksl_cross_vv(&s1i->ang, &s2i->ang, &s.ang);

  /* s.lin += s1i->lin x s2i->ang */
  s.m0 += s1i->m1 * s2i->m5 - s1i->m2 * s2i->m4;
  s.m1 += s1i->m2 * s2i->m3 - s1i->m0 * s2i->m5;
  s.m2 += s1i->m0 * s2i->m4 - s1i->m1 * s2i->m3;

  ksl_screw_copy(&s, so);
}

static inline void ksl_cross_ssf(const ksl_screwf_t* KSL_RESTRICT s1i,
                                 const ksl_screwf_t* KSL_RESTRICT s2i,
                                 ksl_screwf_t* KSL_RESTRICT so) {

  ksl_screwf_t s;

  /* s.lin <- s1i->ang x s2i->lin */
  ksl_cross_vvf(&s1i->ang, &s2i->lin, &s.lin);

  /* s.ang <- s1i->ang x s2i->ang */
  ksl_cross_vvf(&s1i->ang, &s2i->ang, &s.ang);

  /* s.lin += s1i->lin x s2i->ang */
  s.m0 += s1i->m1 * s2i->m5 - s1i->m2 * s2i->m4;
  s.m1 += s1i->m2 * s2i->m3 - s1i->m0 * s2i->m5;
  s.m2 += s1i->m0 * s2i->m4 - s1i->m1 * s2i->m3;

  ksl_screwf_copy(&s, so);
}

static inline void ksl_cross_sst(const ksl_screw_t* KSL_RESTRICT s1i,
                                 const ksl_screw_t* KSL_RESTRICT s2i,
                                 ksl_screw_t* KSL_RESTRICT so) {
  ksl_cross_vv(&s1i->ang, &s2i->lin, &so->lin);
  memset(&so->ang, 0, sizeof(ksl_vec3_t));
}

static inline void ksl_cross_sstf(const ksl_screwf_t* KSL_RESTRICT s1i,
                                  const ksl_screwf_t* KSL_RESTRICT s2i,
                                  ksl_screwf_t* KSL_RESTRICT so) {
  ksl_cross_vvf(&s1i->ang, &s2i->lin, &so->lin);
  memset(&so->ang, 0, sizeof(ksl_vec3f_t));
}

static inline void ksl_product_Adrs(const ksl_mat3x3_t* KSL_RESTRICT ri,
                                    const ksl_screw_t* KSL_RESTRICT si,
                                    ksl_screw_t* KSL_RESTRICT so) {

  ksl_product_drv(ri, &si->lin, &so->lin);
  ksl_product_drv(ri, &si->ang, &so->ang);
}

static inline void ksl_product_Adrsf(const ksl_mat3x3f_t* KSL_RESTRICT ri,
                                     const ksl_screwf_t* KSL_RESTRICT si,
                                     ksl_screwf_t* KSL_RESTRICT so) {

  ksl_product_drvf(ri, &si->lin, &so->lin);
  ksl_product_drvf(ri, &si->ang, &so->ang);
}

static inline void ksl_product_Adrsinv(const ksl_mat3x3_t* KSL_RESTRICT ri,
                                       const ksl_screw_t* KSL_RESTRICT si,
                                       ksl_screw_t* KSL_RESTRICT so) {

  ksl_product_drvinv(ri, &si->lin, &so->lin);
  ksl_product_drvinv(ri, &si->ang, &so->ang);
}

static inline void ksl_product_Adrsinvf(const ksl_mat3x3f_t* KSL_RESTRICT ri,
                                        const ksl_screwf_t* KSL_RESTRICT si,
                                        ksl_screwf_t* KSL_RESTRICT so) {
  ksl_product_drvinvf(ri, &si->lin, &so->lin);
  ksl_product_drvinvf(ri, &si->ang, &so->ang);
}

static inline void ksl_product_Adrinvs(const ksl_mat3x3_t* KSL_RESTRICT ri,
                                       const ksl_screw_t* KSL_RESTRICT si,
                                       ksl_screw_t* KSL_RESTRICT so) {
  ksl_product_drinvv(ri, &si->lin, &so->lin);
  ksl_product_drinvv(ri, &si->ang, &so->ang);
}

static inline void ksl_product_Adrinvsf(const ksl_mat3x3f_t* KSL_RESTRICT ri,
                                        const ksl_screwf_t* KSL_RESTRICT si,
                                        ksl_screwf_t* KSL_RESTRICT so) {
  ksl_product_drinvvf(ri, &si->lin, &so->lin);
  ksl_product_drinvvf(ri, &si->ang, &so->ang);
}

static inline void ksl_product_Adts(const ksl_vec3_t* KSL_RESTRICT ti,
                                    const ksl_screw_t* KSL_RESTRICT si,
                                    ksl_screw_t* KSL_RESTRICT so) {
  const double s0 = si->m0, s1 = si->m1, s2 = si->m2;
  const double s3 = si->m3, s4 = si->m4, s5 = si->m5;
  so->m0 = s0 + (ti->y * s5 - ti->z * s4);
  so->m1 = s1 + (ti->z * s3 - ti->x * s5);
  so->m2 = s2 + (ti->x * s4 - ti->y * s3);
  so->m3 = s3;
  so->m4 = s4;
  so->m5 = s5;
}

static inline void ksl_product_Adtsf(const ksl_vec3f_t* KSL_RESTRICT ti,
                                     const ksl_screwf_t* KSL_RESTRICT si,
                                     ksl_screwf_t* KSL_RESTRICT so) {
  const float s0 = si->m0, s1 = si->m1, s2 = si->m2;
  const float s3 = si->m3, s4 = si->m4, s5 = si->m5;
  so->m0 = s0 + (ti->y * s5 - ti->z * s4);
  so->m1 = s1 + (ti->z * s3 - ti->x * s5);
  so->m2 = s2 + (ti->x * s4 - ti->y * s3);
  so->m3 = s3;
  so->m4 = s4;
  so->m5 = s5;
}

static inline void ksl_product_Adtinvs(const ksl_vec3_t* KSL_RESTRICT ti,
                                       const ksl_screw_t* KSL_RESTRICT si,
                                       ksl_screw_t* KSL_RESTRICT so) {
  const double s0 = si->m0, s1 = si->m1, s2 = si->m2;
  const double s3 = si->m3, s4 = si->m4, s5 = si->m5;
  so->m0 = s0 - (ti->y * s5 - ti->z * s4);
  so->m1 = s1 - (ti->z * s3 - ti->x * s5);
  so->m2 = s2 - (ti->x * s4 - ti->y * s3);
  so->m3 = s3;
  so->m4 = s4;
  so->m5 = s5;
}

static inline void ksl_product_Adtinvsf(const ksl_vec3f_t* KSL_RESTRICT ti,
                                        const ksl_screwf_t* KSL_RESTRICT si,
                                        ksl_screwf_t* KSL_RESTRICT so) {
  const float s0 = si->m0, s1 = si->m1, s2 = si->m2;
  const float s3 = si->m3, s4 = si->m4, s5 = si->m5;
  so->m0 = s0 - (ti->y * s5 - ti->z * s4);
  so->m1 = s1 - (ti->z * s3 - ti->x * s5);
  so->m2 = s2 - (ti->x * s4 - ti->y * s3);
  so->m3 = s3;
  so->m4 = s4;
  so->m5 = s5;
}

static inline void ksl_product_Adtsinv(const ksl_vec3_t* KSL_RESTRICT ti,
                                       const ksl_screw_t* KSL_RESTRICT si,
                                       ksl_screw_t* KSL_RESTRICT so) {
  const double s0 = -si->m0, s1 = -si->m1, s2 = -si->m2;
  const double s3 = -si->m3, s4 = -si->m4, s5 = -si->m5;
  so->m0 = s0 + (ti->y * s5 - ti->z * s4);
  so->m1 = s1 + (ti->z * s3 - ti->x * s5);
  so->m2 = s2 + (ti->x * s4 - ti->y * s3);
  so->m3 = s3;
  so->m4 = s4;
  so->m5 = s5;
}

static inline void ksl_product_Adtsinvf(const ksl_vec3f_t* KSL_RESTRICT ti,
                                        const ksl_screwf_t* KSL_RESTRICT si,
                                        ksl_screwf_t* KSL_RESTRICT so) {
  const float s0 = -si->m0, s1 = -si->m1, s2 = -si->m2;
  const float s3 = -si->m3, s4 = -si->m4, s5 = -si->m5;
  so->m0 = s0 + (ti->y * s5 - ti->z * s4);
  so->m1 = s1 + (ti->z * s3 - ti->x * s5);
  so->m2 = s2 + (ti->x * s4 - ti->y * s3);
  so->m3 = s3;
  so->m4 = s4;
  so->m5 = s5;
}

static inline void ksl_product_Ads(const ksl_SE3_t* KSL_RESTRICT Di,
                                   const ksl_screw_t* KSL_RESTRICT si,
                                   ksl_screw_t* KSL_RESTRICT so) {
  const ksl_mat3x3_t* r = &Di->R;
  const double s0 = si->m0, s1 = si->m1, s2 = si->m2;
  const double s3 = si->m3, s4 = si->m4, s5 = si->m5;
  const double wx = s3 * r->v0.x + s4 * r->v1.x + s5 * r->v2.x;
  const double wy = s3 * r->v0.y + s4 * r->v1.y + s5 * r->v2.y;
  const double wz = s3 * r->v0.z + s4 * r->v1.z + s5 * r->v2.z;
  const double vx = s0 * r->v0.x + s1 * r->v1.x + s2 * r->v2.x;
  const double vy = s0 * r->v0.y + s1 * r->v1.y + s2 * r->v2.y;
  const double vz = s0 * r->v0.z + s1 * r->v1.z + s2 * r->v2.z;
  so->m0 = vx + (Di->t.y * wz - Di->t.z * wy);
  so->m1 = vy + (Di->t.z * wx - Di->t.x * wz);
  so->m2 = vz + (Di->t.x * wy - Di->t.y * wx);
  so->m3 = wx;
  so->m4 = wy;
  so->m5 = wz;
}

static inline void ksl_product_Adsf(const ksl_SE3f_t* KSL_RESTRICT Di,
                                    const ksl_screwf_t* KSL_RESTRICT si,
                                    ksl_screwf_t* KSL_RESTRICT so) {
  const ksl_mat3x3f_t* r = &Di->R;
  const float s0 = si->m0, s1 = si->m1, s2 = si->m2;
  const float s3 = si->m3, s4 = si->m4, s5 = si->m5;
  const float wx = s3 * r->v0.x + s4 * r->v1.x + s5 * r->v2.x;
  const float wy = s3 * r->v0.y + s4 * r->v1.y + s5 * r->v2.y;
  const float wz = s3 * r->v0.z + s4 * r->v1.z + s5 * r->v2.z;
  const float vx = s0 * r->v0.x + s1 * r->v1.x + s2 * r->v2.x;
  const float vy = s0 * r->v0.y + s1 * r->v1.y + s2 * r->v2.y;
  const float vz = s0 * r->v0.z + s1 * r->v1.z + s2 * r->v2.z;
  so->m0 = vx + (Di->t.y * wz - Di->t.z * wy);
  so->m1 = vy + (Di->t.z * wx - Di->t.x * wz);
  so->m2 = vz + (Di->t.x * wy - Di->t.y * wx);
  so->m3 = wx;
  so->m4 = wy;
  so->m5 = wz;
}

static inline void ksl_product_Adsinv(const ksl_SE3_t* KSL_RESTRICT Di,
                                      const ksl_screw_t* KSL_RESTRICT si,
                                      ksl_screw_t* KSL_RESTRICT so) {
  const ksl_mat3x3_t* r = &Di->R;
  const double s0 = -si->m0, s1 = -si->m1, s2 = -si->m2;
  const double s3 = -si->m3, s4 = -si->m4, s5 = -si->m5;
  const double wx = s3 * r->v0.x + s4 * r->v1.x + s5 * r->v2.x;
  const double wy = s3 * r->v0.y + s4 * r->v1.y + s5 * r->v2.y;
  const double wz = s3 * r->v0.z + s4 * r->v1.z + s5 * r->v2.z;
  const double vx = s0 * r->v0.x + s1 * r->v1.x + s2 * r->v2.x;
  const double vy = s0 * r->v0.y + s1 * r->v1.y + s2 * r->v2.y;
  const double vz = s0 * r->v0.z + s1 * r->v1.z + s2 * r->v2.z;
  so->m0 = vx + (Di->t.y * wz - Di->t.z * wy);
  so->m1 = vy + (Di->t.z * wx - Di->t.x * wz);
  so->m2 = vz + (Di->t.x * wy - Di->t.y * wx);
  so->m3 = wx;
  so->m4 = wy;
  so->m5 = wz;
}

static inline void ksl_product_Adsinvf(const ksl_SE3f_t* KSL_RESTRICT Di,
                                       const ksl_screwf_t* KSL_RESTRICT si,
                                       ksl_screwf_t* KSL_RESTRICT so) {
  const ksl_mat3x3f_t* r = &Di->R;
  const float s0 = -si->m0, s1 = -si->m1, s2 = -si->m2;
  const float s3 = -si->m3, s4 = -si->m4, s5 = -si->m5;
  const float wx = s3 * r->v0.x + s4 * r->v1.x + s5 * r->v2.x;
  const float wy = s3 * r->v0.y + s4 * r->v1.y + s5 * r->v2.y;
  const float wz = s3 * r->v0.z + s4 * r->v1.z + s5 * r->v2.z;
  const float vx = s0 * r->v0.x + s1 * r->v1.x + s2 * r->v2.x;
  const float vy = s0 * r->v0.y + s1 * r->v1.y + s2 * r->v2.y;
  const float vz = s0 * r->v0.z + s1 * r->v1.z + s2 * r->v2.z;
  so->m0 = vx + (Di->t.y * wz - Di->t.z * wy);
  so->m1 = vy + (Di->t.z * wx - Di->t.x * wz);
  so->m2 = vz + (Di->t.x * wy - Di->t.y * wx);
  so->m3 = wx;
  so->m4 = wy;
  so->m5 = wz;
}

static inline void ksl_product_Adinvs(const ksl_SE3_t* KSL_RESTRICT Di,
                                      const ksl_screw_t* KSL_RESTRICT si,
                                      ksl_screw_t* KSL_RESTRICT so) {
  ksl_screw_t temp;
  ksl_screw_copy(si, &temp);

  temp.m0 -= Di->t.y * temp.m5 - Di->t.z * temp.m4;
  temp.m1 -= Di->t.z * temp.m3 - Di->t.x * temp.m5;
  temp.m2 -= Di->t.x * temp.m4 - Di->t.y * temp.m3;

  ksl_product_Adrinvs(&Di->R, &temp, so);
}

static inline void ksl_product_Adinvsf(const ksl_SE3f_t* KSL_RESTRICT Di,
                                       const ksl_screwf_t* KSL_RESTRICT si,
                                       ksl_screwf_t* KSL_RESTRICT so) {
  ksl_screwf_t temp;
  ksl_screwf_copy(si, &temp);

  temp.m0 -= Di->t.y * temp.m5 - Di->t.z * temp.m4;
  temp.m1 -= Di->t.z * temp.m3 - Di->t.x * temp.m5;
  temp.m2 -= Di->t.x * temp.m4 - Di->t.y * temp.m3;

  ksl_product_Adrinvsf(&Di->R, &temp, so);
}

#ifdef __cplusplus
}
#endif

#endif
