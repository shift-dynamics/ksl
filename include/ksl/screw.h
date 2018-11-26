/**
@file
@author Kristopher Wehage, Roger Wehage
@brief Utilities to initialize and operate on screws
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
#ifndef _KSL_SCREW_H_
#define _KSL_SCREW_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "matrix.h"

typedef union ksl_coscrew_t ksl_coscrew_t;
typedef union ksl_coscrewf_t ksl_coscrewf_t;

/*!
@brief double precision screw consisting of a linear and angular vector pair in
configuration space
*/
typedef union ksl_screw_t {
  struct {
    double at[6];
  }; /*!< anonymous union allows accessing screw quantities at specified index
      */
  struct {
    ksl_vec3_t lin; /*!< free linear vector, e.g. linear velocity or
                            acceleration */
    ksl_vec3_t ang; /*!< bound angular vector, e.g. angular velocity or
                             angular acceleration */
  }; /*!< anonymous union allows accessing screw quantities by linear or angular
        vector components */
  struct {
    double m0, m1, m2, m3, m4, m5;
  }; /*!< anonymous union allows accessing screw quantities by field name  */
} ksl_screw_t;

/*!
@brief single precision screw consisting of a linear and angular vector
pair in configuration space
*/
typedef union ksl_screwf_t {
  struct {
    float at[6]; /*!< allows accessing screw quantities at specified index */
  }; /*!< anonymous union allows accessing screw quantities at specified index
      */
  struct {
    ksl_vec3f_t lin; /*!< free linear vector, e.g. linear velocity or
                            acceleration */
    ksl_vec3f_t ang; /*!< bound angular vector, e.g. angular velocity or
                             angular acceleration (\omega, or \dot{\omega}) */
  }; /*!< anonymous union allows accessing screw quantities by linear or angular
        vector components */
  struct {
    float m0, m1, m2, m3, m4, m5;
  }; /*!< anonymous union allows accessing screw quantities by field name */
} ksl_screwf_t;

/*!
@brief double precision screw constructor
*/
ksl_screw_t ksl_screw(const double m0, const double m1, const double m2,
                      const double m3, const double m4, const double m5);

/*!
@brief single precision screw constructor
*/
ksl_screwf_t ksl_screwf(const float m0, const float m1, const float m2,
                        const float m3, const float m4, const float m5);

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
double ksl_screw_norm(const ksl_screw_t* s);

/*!
@brief Compute the screw norm of a single precision spatial screw.

@param s [in] input screw
@return screw norm
*/
float ksl_screwf_norm(const ksl_screwf_t* s);

/*!
@brief TODO document this function
*/
void ksl_screw_normalize(ksl_screw_t* s);

/*!
@brief TODO document this function
*/
void ksl_screwf_normalize(ksl_screwf_t* s);

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
double ksl_dot_cs(const ksl_coscrew_t* ci, const ksl_screw_t* si);

/*!
@brief compute single precision dot product between a coscrew and screw
*/
float ksl_dot_csf(const ksl_coscrewf_t* ci, const ksl_screwf_t* si);

/*!
@brief TODO document this function
*/
void ksl_screw_scale(ksl_screw_t* s, const double a);

/*!
@brief TODO document this function
*/
void ksl_screwf_scale(ksl_screwf_t* s, const float a);

/*!
@brief Copy double precision ksl_screw_t si to so.

\f$S_i \rightarrow S_o\f$

@param si [in] screw to copy
@param so [out] si is copied to so
*/
void ksl_screw_copy(const ksl_screw_t* si, ksl_screw_t* so);

/*!
@brief Copy single precision ksl_screwf_t si to so.

\f$S_i \rightarrow S_o\f$

@param si [in] screw to copy
@param so [out] si is copied to so
*/
void ksl_screwf_copy(const ksl_screwf_t* si, ksl_screwf_t* so);

/*!
@brief Invert (i.e. negate) a ksl_screw_t in place.

\f$\mathbf{\underline{s}}^{-1} \rightarrow \mathbf{\underline{s}}\f$

\f$-\mathbf{\underline{s}} \rightarrow \mathbf{\underline{s}}\f$

@param si [in/out] screw to invert
*/
void ksl_screw_invert(ksl_screw_t* si);

/*!
@brief Invert (i.e. negate) a ksl_screwf_t in place.

\f$\mathbf{\underline{s}}^{-1} \rightarrow \mathbf{\underline{s}}\f$

\f$-\mathbf{\underline{s}} \rightarrow \mathbf{\underline{s}}\f$

@param si [in/out] screw to invert
*/
void ksl_screwf_invert(ksl_screwf_t* si);

/*!
@brief Returns the inverse of a ksl_screw_t.

\f$\mathbf{\underline{s}}_i^{-1} \rightarrow \mathbf{\underline{s}}_o\f$

@param si [in] screw to invert
@param so [out] inverse of si
*/
void ksl_screw_inverted(const ksl_screw_t* si, ksl_screw_t* so);

/*!
@brief Returns the inverse of a ksl_screwf_t.

\f$\mathbf{\underline{s}}_i^{-1} \rightarrow \mathbf{\underline{s}}_o\f$

@param si [in] screw to invert
@param so [out] inverse of si
*/
void ksl_screwf_inverted(const ksl_screwf_t* si, ksl_screwf_t* so);

/*!
@brief TODO document this function
*/
void ksl_product_as(const double k, const ksl_screw_t* si, ksl_screw_t* so);

/*!
@brief TODO document this function
*/
void ksl_product_asf(const float k, const ksl_screwf_t* si, ksl_screwf_t* so);

/*!
@brief compute axpy (a * x + y \rightarrow y) operation for double precision
screws
*/
void ksl_axpy_ss(const double, const ksl_screw_t*, ksl_screw_t*);

/*!
@brief compute axpy (a * x + y \rightarrow y) operation for single precision
screws
*/
void ksl_axpy_ssf(const float, const ksl_screwf_t*, ksl_screwf_t*);

/*!
@brief TODO document this function
*/
void ksl_xpy_ss(const ksl_screw_t*, ksl_screw_t*);

/*!
@brief TODO document this function
*/
void ksl_xpy_ssf(const ksl_screwf_t*, ksl_screwf_t*);

/*!
@brief TODO document this function
*/
void ksl_nxpy_ss(const ksl_screw_t*, ksl_screw_t*);

/*!
@brief TODO document this function
*/
void ksl_nxpy_ssf(const ksl_screwf_t*, ksl_screwf_t*);

/*!
@brief TODO document this function
*/
void ksl_add_ss(const ksl_screw_t* s1i, const ksl_screw_t* s2i,
                ksl_screw_t* so);

/*!
@brief TODO document this function
*/
void ksl_add_ssf(const ksl_screwf_t* s1i, const ksl_screwf_t* s2i,
                 ksl_screwf_t* so);

/*!
@brief TODO document this function
*/
void ksl_subtract_ss(const ksl_screw_t* s1i, const ksl_screw_t* s2i,
                     ksl_screw_t* so);

/*!
@brief TODO document this function
*/
void ksl_subtract_ssf(const ksl_screwf_t* s1i, const ksl_screwf_t* s2i,
                      ksl_screwf_t* so);

/*!
@brief TODO document this function
*/
void ksl_add_sst(const ksl_screw_t* si1, const ksl_screw_t* si2,
                 ksl_screw_t* so);

/*!
@brief TODO document this function
*/
void ksl_add_sstf(const ksl_screwf_t* si1, const ksl_screwf_t* si2,
                  ksl_screwf_t* so);

/*!
@brief TODO document this function
*/
void ksl_hstx(const ksl_SE3_t* Di, ksl_screw_t* ho);

/*!
@brief TODO document this function
*/
void ksl_hstxf(const ksl_SE3f_t* Di, ksl_screwf_t* ho);

/*!
@brief TODO document this function
*/
void ksl_hsty(const ksl_SE3_t* Di, ksl_screw_t* ho);

/*!
@brief TODO document this function
*/
void ksl_hstyf(const ksl_SE3f_t* Di, ksl_screwf_t* ho);

/*!
@brief TODO document this function
*/
void ksl_hstz(const ksl_SE3_t* ri, ksl_screw_t* ho);

/*!
@brief TODO document this function
*/
void ksl_hstzf(const ksl_SE3f_t* ri, ksl_screwf_t* ho);

/*!
@brief TODO document this function
*/
void ksl_hsrx(const ksl_SE3_t* Di, ksl_screw_t* ho);

/*!
@brief TODO document this function
*/
void ksl_hsrxf(const ksl_SE3f_t* Di, ksl_screwf_t* ho);

/*!
@brief TODO document this function
*/
void ksl_hsrxinv(const ksl_SE3_t* Di, ksl_screw_t* ho);

/*!
@brief TODO document this function
*/
void ksl_hsrxinvf(const ksl_SE3f_t* Di, ksl_screwf_t* ho);

/*!
@brief TODO document this function
*/
void ksl_hsry(const ksl_SE3_t* Di, ksl_screw_t* ho);

/*!
@brief TODO document this function
*/
void ksl_hsryf(const ksl_SE3f_t* Di, ksl_screwf_t* ho);

/*!
@brief TODO document this function
*/
void ksl_hsryinv(const ksl_SE3_t* Di, ksl_screw_t* ho);

/*!
@brief TODO document this function
*/
void ksl_hsryinvf(const ksl_SE3f_t* Di, ksl_screwf_t* ho);
/*!
@brief TODO document this function
*/
void ksl_hsrz(const ksl_SE3_t* Di, ksl_screw_t* ho);

/*!
@brief TODO document this function
*/
void ksl_hsrzf(const ksl_SE3f_t* Di, ksl_screwf_t* ho);

/*!
@brief TODO document this function
*/
void ksl_hsrzinv(const ksl_SE3_t* Di, ksl_screw_t* ho);

/*!
@brief TODO document this function
*/
void ksl_hsrzinvf(const ksl_SE3f_t* Di, ksl_screwf_t* ho);

/*!
@brief TODO document this function
*/
void ksl_hstxinv(const ksl_SE3_t* Di, ksl_screw_t* ho);

/*!
@brief TODO document this function
*/
void ksl_hstxinvf(const ksl_SE3f_t* Di, ksl_screwf_t* ho);

/*!
@brief TODO document this function
*/
void ksl_hstyinv(const ksl_SE3_t* Di, ksl_screw_t* ho);

/*!
@brief TODO document this function
*/
void ksl_hstyinvf(const ksl_SE3f_t* Di, ksl_screwf_t* ho);

/*!
@brief TODO document this function
*/
void ksl_hstzinv(const ksl_SE3_t* Di, ksl_screw_t* ho);

/*!
@brief TODO document this function
*/
void ksl_hstzinvf(const ksl_SE3f_t* Di, ksl_screwf_t* ho);

/*!
@brief TODO document this function
*/
void ksl_hsrxinv(const ksl_SE3_t* Di, ksl_screw_t* ho);

/*!
@brief TODO document this function
*/
void ksl_hrxinvf(const ksl_SE3f_t* Di, ksl_screwf_t* ho);

/*!
@brief TODO document this function
*/
void ksl_hsryinv(const ksl_SE3_t* Di, ksl_screw_t* ho);

/*!
@brief TODO document this function
*/
void ksl_hsryinvf(const ksl_SE3f_t* Di, ksl_screwf_t* ho);

/*!
@brief TODO document this function
*/
void ksl_hsrzinv(const ksl_SE3_t* Di, ksl_screw_t* ho);

/*!
@brief TODO document this function
*/
void ksl_hsrzinvf(const ksl_SE3f_t* Di, ksl_screwf_t* ho);

/*!
@brief double precision screw cross product

*/
void ksl_cross_ss(const ksl_screw_t* s1i, const ksl_screw_t* s2i,
                  ksl_screw_t* so);

/*!
@brief single precision screw cross product

*/
void ksl_cross_ssf(const ksl_screwf_t* s1i, const ksl_screwf_t* s2i,
                   ksl_screwf_t* so);

/*!
@brief TODO document this function
*/
void ksl_cross_sst(const ksl_screw_t* s1i, const ksl_screw_t* s2i,
                   ksl_screw_t* so);

/*!
@brief TODO document this function
*/
void ksl_cross_sstf(const ksl_screwf_t* s1i, const ksl_screwf_t* s2i,
                    ksl_screwf_t* so);

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
void ksl_product_Adrs(const ksl_mat3x3_t* r_oi, const ksl_screw_t* s_i,
                      ksl_screw_t* s_o);

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
void ksl_product_Adrsinv(const ksl_mat3x3_t* r_oi, const ksl_screw_t* s_i,
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
void ksl_product_Adrsf(const ksl_mat3x3f_t* r_oi, const ksl_screwf_t* s_i,
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
void ksl_product_Adrsinvf(const ksl_mat3x3f_t* r_oi, const ksl_screwf_t* s_i,
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
void ksl_product_Adrinvs(const ksl_mat3x3_t* r_io, const ksl_screw_t* s_i,
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
void ksl_product_Adrinvsf(const ksl_mat3x3f_t* r_io, const ksl_screwf_t* s_i,
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
void ksl_product_Adts(const ksl_vec3_t* t_oi, const ksl_screw_t* s_i,
                      ksl_screw_t* s_o);

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
void ksl_product_Adtsf(const ksl_vec3f_t* ti, const ksl_screwf_t* si,
                       ksl_screwf_t* so);

/*!
@brief TODO document this function
*/
void ksl_product_Adtinvs(const ksl_vec3_t* ti, const ksl_screw_t* si,
                         ksl_screw_t* so);

/*!
@brief TODO document this function
*/
void ksl_product_Adtinvsf(const ksl_vec3f_t* ti, const ksl_screwf_t* si,
                          ksl_screwf_t* so);

/*!
@brief TODO document this function
*/
void ksl_product_Adtsinv(const ksl_vec3_t* ti, const ksl_screw_t* si,
                         ksl_screw_t* so);

/*!
@brief TODO document this function
*/
void ksl_product_Adtsinvf(const ksl_vec3f_t* ti, const ksl_screwf_t* si,
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
void ksl_product_Ads(const ksl_SE3_t* Di, const ksl_screw_t* si,
                     ksl_screw_t* so);

/*!
@brief TODO document this function
*/
void ksl_product_Adsinv(const ksl_SE3_t* Di, const ksl_screw_t* si,
                        ksl_screw_t* so);

/*!
@brief TODO document this function
*/
void ksl_product_Adsinvf(const ksl_SE3f_t* Di, const ksl_screwf_t* si,
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
void ksl_product_Adsf(const ksl_SE3f_t* Di, const ksl_screwf_t* si,
                      ksl_screwf_t* so);

/*!
@brief TODO document this function
*/
void ksl_product_Adinvs(const ksl_SE3_t* Di, const ksl_screw_t* si,
                        ksl_screw_t* so);

/*!
@brief TODO document this function
*/
void ksl_product_Adinvsf(const ksl_SE3f_t* Di, const ksl_screwf_t* si,
                         ksl_screwf_t* so);

#ifdef __cplusplus
}
#endif

#endif
