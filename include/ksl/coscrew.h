/**
@file
@author Kristopher Wehage, Roger Wehage
@brief Utilities to initialize and operate on coscrews
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
#ifndef _KSL_COSCREW_H_
#define _KSL_COSCREW_H_

#include "matrix.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
@brief double precision coscrew (i.e. a linear operator on a screw), consisting
of a linear and angular vector pair in function space.
*/
typedef union ksl_coscrew_t {
  struct {
    double at[6];
  }; /*!< anyonymous union allows accessing coscrew quantities at specified
        index */
  struct {
    ksl_vec3_t lin; /*!< bound linear vector, e.g. force or linear
                         momentum */
    ksl_vec3_t ang; /*!< free angular vector, e.g. moment/torque
                         or angular momentum*/
  }; /*!< anyonymous union allows accessing coscrew quantities by its linear and
        angular vector components */
  struct {
    double m0, m1, m2, m3, m4, m5;
  }; /*!< anonymous union allows accessing coscrew quantities by field name */
} ksl_coscrew_t;

/*!
@brief single precision coscrew (i.e. a linear operator on a screw), consisting
of a linear and angular vector pair in function space.
*/
typedef union ksl_coscrewf_t {
  struct {
    float at[6];
  }; /*!< anonymous union allows accessing coscrew quantities at specified index
      */
  struct {
    ksl_vec3f_t lin; /*!< bound linear vector, e.g. force or linear
                         momentum */
    ksl_vec3f_t ang; /*!< free angular vector, e.g. moment/torque
                         or angular momentum*/
  }; /*!< anyonymous union allows accessing coscrew quantities by its linear and
        angular vector components */
  struct {
    float m0, m1, m2, m3, m4, m5;
  }; /*!< anonymous union allows accessing coscrew quantities by field name */
} ksl_coscrewf_t;

/*!
@brief double precision screw constructor
*/
ksl_coscrew_t ksl_coscrew(const double m0, const double m1, const double m2,
                          const double m3, const double m4, const double m5);

/*!
@brief single precision screwf constructor
*/
ksl_coscrewf_t ksl_coscrewf(const float m0, const float m1, const float m2,
                            const float m3, const float m4, const float m5);

/*!
@brief Allocates n double precision coscrew quantities on the heap. Must be
freed by the user.
*/
ksl_coscrew_t* ksl_coscrew_alloc(int n);

/*!
@brief Allocate n single precision coscrew quantities on the heap. Must be freed
by the user.
*/
ksl_coscrewf_t* ksl_coscrewf_alloc(int n);

/*!
@brief Copy double precision ksl_coscrew_t.

\f$\mathbf{\underline{c}}_{i}^* \rightarrow
\mathbf{\underline{c}}_o^*\f$

@param ci [in] screw to copy
@param co [out] input screw is copied to co
*/
void ksl_coscrew_copy(const ksl_coscrew_t* ci, ksl_coscrew_t* co);

/*!
@brief Copy single precision ksl_coscrewf_t ci to co.

\f$\mathbf{\underline{c}}_{i}^* \rightarrow
\mathbf{\underline{c}}_o^*\f$

@param self [in] screw to copy
@param co [out] ci is copied to co
*/
void ksl_coscrewf_copy(const ksl_coscrewf_t* self, ksl_coscrewf_t* co);

/*!
@brief Scale a double precision ksl_coscrew_t.

\f$\mathbf{\underline{c}}_{i}^* * a \rightarrow
\mathbf{\underline{c}}_i^*\f$

@param self [in] coscrew to invert
@param a [out] amount to scale the screw
*/
void ksl_coscrew_scale(ksl_coscrew_t* self, const double a);

/*!
@brief Scale a single precision ksl_coscrew_t.

\f$\mathbf{\underline{c}}_{i}^* * a \rightarrow
\mathbf{\underline{c}}_i^*\f$

@param self [in] coscrew to invert
@param a [out] inverse of ci
*/
void ksl_coscrewf_scale(ksl_coscrewf_t* self, const float a);

/*!
@brief Returns the inverse of a ksl_coscrew_t.

\f$-\mathbf{\underline{c}}_{i}^* \rightarrow
\mathbf{\underline{c}}_o^*\f$

@param ci [in] coscrew to invert
@param co [out] inverse of ci
*/
void ksl_coscrew_inverted(const ksl_coscrew_t* ci, ksl_coscrew_t* co);

/*!
@brief Returns the inverse of a ksl_coscrewf_t.

\f$-\mathbf{\underline{c}}_{i}^* \rightarrow
\mathbf{\underline{c}}_o^*\f$

@param self [in] coscrew to invert
@param co [out] inverse of ci
*/
void ksl_coscrewf_inverted(const ksl_coscrewf_t* self, ksl_coscrewf_t* co);

/*!
@brief Invert (i.e. negate) a ksl_coscrew_t in place.

\f$-\mathbf{\underline{c}}_{i}^* \rightarrow
\mathbf{\underline{c}}_i^*\f$

@param self [in/out] coscrew to invert
*/
void ksl_coscrew_invert(ksl_coscrew_t* self);

/*!
@brief Invert (i.e. negate) a ksl_coscrewf_t in place.

\f$-\mathbf{\underline{c}}_{i}^* \rightarrow
\mathbf{\underline{c}}_i^*\f$

@param self [in/out] coscrew to invert
*/
void ksl_coscrewf_invert(ksl_coscrewf_t* self);

double ksl_coscrew_norm(const ksl_coscrew_t* v);

float ksl_coscrewf_norm(const ksl_coscrewf_t* v);

void ksl_coscrew_normalize(ksl_coscrew_t* v);

void ksl_coscrewf_normalize(ksl_coscrewf_t* v);

/*!
@brief In-place add a double precision coscrew multiplied with a scalar to an
existing coscrew.

\f$a * \mathbf{\underline{c}}_{x}^* + \mathbf{\underline{c}}_y^* \rightarrow
\mathbf{\underline{c}}_y^*\f$

@param a [in]
@param x [in]
@param y [in/out] coscrew to add
*/
void ksl_axpy_cc(const double a, const ksl_coscrew_t* x, ksl_coscrew_t* y);

/*!
@brief In-place add a single precision coscrew multiplied with a scalar to an
existing coscrew.

\f$a * \mathbf{\underline{c}}_{x}^* + \mathbf{\underline{c}}_y^* \rightarrow
\mathbf{\underline{c}}_y^*\f$

@param a [in]
@param x [in]
@param y [in/out]
*/
void ksl_axpy_ccf(const float a, const ksl_coscrewf_t* x, ksl_coscrewf_t* y);

/*!
@brief In-place add a double precision coscrew to an existing coscrew. This is a
variant of axpy where the scalar term a is 1.

\f$ \mathbf{\underline{c}}_{x}^* + \mathbf{\underline{c}}_y^* \rightarrow
\mathbf{\underline{c}}_y^*\f$

@param c [in/out]
@param ci [in] coscrew to add
*/
void ksl_xpy_cc(const ksl_coscrew_t* x, ksl_coscrew_t* y);

/*!
@brief In-place add a single precision coscrew to an existing coscrew. This is a
variant of axpy where there the scalar term is 1.

\f$ \mathbf{\underline{c}}_{x}^* + \mathbf{\underline{c}}_y^* \rightarrow
\mathbf{\underline{c}}_y^*\f$

@param co [in/out] sum of c1i and co
@param c1i [in] first coscrew to add
*/
void ksl_xpy_ccf(const ksl_coscrewf_t* x, ksl_coscrewf_t* y);

/*!
@brief In-place subtract a double precision coscrew x from an  coscrew y. This
is a variant of axpy where the scalar term is -1.

\f$ -\mathbf{\underline{c}}_{x}^* + \mathbf{\underline{c}}_y^* \rightarrow
\mathbf{\underline{c}}_y^*\f$

@param self [in/out]
@param ci [in] first coscrew to subtract
*/
void ksl_nxpy_cc(const ksl_coscrew_t* x, ksl_coscrew_t* y);

/*!
@brief In-place subtract a single precision coscrew from an existing coscrew.
This is a variant of axpy where the scalar term is -1.

\f$ -\mathbf{\underline{c}}_{x}^* + \mathbf{\underline{c}}_y^* \rightarrow
\mathbf{\underline{c}}_y^*\f$

@param self [in/out]
@param ci [in] first coscrew to subtract
*/
void ksl_nxpy_ccf(const ksl_coscrewf_t* x, ksl_coscrewf_t* y);

/*!
@brief Scale a double precision coscrew.

\f$ \mathbf{\underline{c}}_i^* * a \rightarrow \mathbf{\underline{c}}_o^*\f$

@param co [in/out] coscrew to scale
*/
void ksl_product_ac(const double a, const ksl_coscrew_t* ci, ksl_coscrew_t* co);

/*!
@brief Scale a single precision coscrew.

\f$ \mathbf{\underline{c}}_i^* * a \rightarrow \mathbf{\underline{c}}_o^*\f$

@param co [in/out] coscrew to scale
*/
void ksl_product_acf(const float a, const ksl_coscrewf_t* ci,
                     ksl_coscrewf_t* co);

/*!
@brief Compute the sum of two double precision coscrews

\f$\mathbf{\underline{c}}_{1i}^* + \mathbf{\underline{c}}_{2i}^* \rightarrow
\mathbf{\underline{c}}_o^*\f$

@param c1i [in] first coscrew to add
@param c1i [in] second coscrew to add
@param co [out] sum of c1i and c2i
*/
void ksl_add_cc(const ksl_coscrew_t* c1i, const ksl_coscrew_t* c2i,
                ksl_coscrew_t* co);

/*!
@brief Compute the sum of two single precision coscrews

\f$\mathbf{\underline{c}}_{1i}^* + \mathbf{\underline{c}}_{2i}^* \rightarrow
\mathbf{\underline{c}}_o^*\f$

@param c1i [in] first coscrew to add
@param c2i [in] second coscrew to add
@param co [out] sum of c1i and c2i
*/
void ksl_add_ccf(const ksl_coscrewf_t* c1i, const ksl_coscrewf_t* c2i,
                 ksl_coscrewf_t* co);

/*!
@brief Compute the difference between two double precision coscrews

\f$\mathbf{\underline{c}}_{1i}^* - \mathbf{\underline{c}}_{2i}^* \rightarrow
\mathbf{\underline{c}}_o^*\f$

@param c1i [in] first coscrew
@param c2i [in] second coscrew
@param co [out] c1i minus c2i
*/
void ksl_subtract_cc(const ksl_coscrew_t* c1i, const ksl_coscrew_t* c2i,
                     ksl_coscrew_t* co);

/*!
@brief Compute the difference between two double precision coscrews

\f$\mathbf{\underline{c}}_{1i}^* - \mathbf{\underline{c}}_{2i}^* \rightarrow
\mathbf{\underline{c}}_o^*\f$

@param c1i [in] first coscrew
@param c2i [in] second coscrew
@param co [out] result of c1i minus c2i
*/
void ksl_subtract_ccf(const ksl_coscrewf_t* c1i, const ksl_coscrewf_t* c2i,
                      ksl_coscrewf_t* co);

void ksl_add_cct(const ksl_coscrew_t* ci1, const ksl_coscrew_t* ci2,
                 ksl_coscrew_t* co);

void ksl_add_cctf(const ksl_coscrewf_t* ci1, const ksl_coscrewf_t* ci2,
                  ksl_coscrewf_t* co);

void ksl_hctx(const ksl_SE3_t* Di, ksl_coscrew_t* co);

void ksl_hctxf(const ksl_SE3f_t* Di, ksl_coscrewf_t* co);

void ksl_hcty(const ksl_SE3_t* Di, ksl_coscrew_t* co);

void ksl_hctyf(const ksl_SE3f_t* Di, ksl_coscrewf_t* co);

void ksl_hctz(const ksl_SE3_t* ri, ksl_coscrew_t* co);

void ksl_hctzf(const ksl_SE3f_t* ri, ksl_coscrewf_t* co);

void ksl_hcrx(const ksl_SE3_t* Di, ksl_coscrew_t* co);

void ksl_hcrxf(const ksl_SE3f_t* Di, ksl_coscrewf_t* co);

void ksl_hcry(const ksl_SE3_t* Di, ksl_coscrew_t* co);

void ksl_hcryf(const ksl_SE3f_t* Di, ksl_coscrewf_t* co);

void ksl_hcrz(const ksl_SE3_t* Di, ksl_coscrew_t* co);

void ksl_hcrzf(const ksl_SE3f_t* Di, ksl_coscrewf_t* co);

void ksl_hctxinv(const ksl_SE3_t* Di, ksl_coscrew_t* co);

void ksl_hctxinvf(const ksl_SE3f_t* Di, ksl_coscrewf_t* co);

void ksl_hctyinv(const ksl_SE3_t* Di, ksl_coscrew_t* co);

void ksl_hctyinvf(const ksl_SE3f_t* Di, ksl_coscrewf_t* co);

void ksl_hctzinv(const ksl_SE3_t* Di, ksl_coscrew_t* co);

void ksl_hctzinvf(const ksl_SE3f_t* Di, ksl_coscrewf_t* co);

void ksl_hcrxinv(const ksl_SE3_t* Di, ksl_coscrew_t* co);

void ksl_hcrxinvf(const ksl_SE3f_t* Di, ksl_coscrewf_t* co);

void ksl_hcryinv(const ksl_SE3_t* Di, ksl_coscrew_t* co);

void ksl_hcryinvf(const ksl_SE3f_t* Di, ksl_coscrewf_t* co);

void ksl_hcrzinv(const ksl_SE3_t* Di, ksl_coscrew_t* co);

void ksl_hcrzinvf(const ksl_SE3f_t* Di, ksl_coscrewf_t* co);

void ksl_cross_sc(const ksl_screw_t* s1i, const ksl_coscrew_t* c2i,
                  ksl_coscrew_t* co);

void ksl_cross_scf(const ksl_screwf_t* s1i, const ksl_coscrewf_t* c2i,
                   ksl_coscrewf_t* co);

void ksl_cross_sca(const ksl_screw_t* s1i, const ksl_coscrew_t* c2i,
                   ksl_coscrew_t* co);

void ksl_cross_scaf(const ksl_screwf_t* s1i, const ksl_coscrewf_t* c2i,
                    ksl_coscrewf_t* co);

/*!
@brief Performs a double precision spatial translation of a coscrew. Performs a
Coadjoint transformation of a coscrew, where CoAdjoint transformation matrix
consists of only a translation component.

\f$ [Ad]^*(\underline{t}_i) \mathbf{\underline{c}}_{i}^* \rightarrow
\mathbf{\underline{c}}_o^*\f$

\f$\ \begin{bmatrix} I & 0\\ \underline{\tilde{t}}_i & I \end{bmatrix}
\mathbf{\underline{c}}_{i}^* \rightarrow \mathbf{\underline{c}}_o^*\f$


@param ti [in] translation vector
@param ci [in] input coscrew
@param co [out] output coscrew
*/
void ksl_product_CoAdtc(const ksl_vec3_t* ti, const ksl_coscrew_t* ci,
                        ksl_coscrew_t* co);

/*!
@brief Performs a single precision spatial translation of a coscrew. Performs a
Coadjoint transformation of a coscrew, where CoAdjoint transformation matrix
consists of only a translation component.

\f$ [Ad]^*(\underline{t}_i) \mathbf{\underline{c}}_{i}^* \rightarrow
\mathbf{\underline{c}}_o^*\f$

\f$\ \begin{bmatrix} I & 0\\ \underline{\tilde{t}}_i & I \end{bmatrix}
\mathbf{\underline{c}}_{i}^* \rightarrow \mathbf{\underline{c}}_o^*\f$


@param ti [in] translation vector
@param ci [in] input coscrew
@param co [out] output coscrew
*/
void ksl_product_CoAdtcf(const ksl_vec3f_t* ti, const ksl_coscrewf_t* ci,
                         ksl_coscrewf_t* co);

/*!
@brief Performs a double precision spatial translation of the inverse of a
coscrew. Performs a Coadjoint transformation of the inverse of a coscrew, where
CoAdjoint transformation matrix consists of only a translation component.

\f$ [Ad]^*(\underline{t}_i) * -\mathbf{\underline{c}}_{i}^* \rightarrow
\mathbf{\underline{c}}_o^*\f$

\f$ -[Ad]^*(\underline{t}_i) \mathbf{\underline{c}}_{i}^* \rightarrow
\mathbf{\underline{c}}_o^*\f$

\f$\ -\begin{bmatrix} I & 0\\ \underline{\tilde{t}}_i & I \end{bmatrix}
\mathbf{\underline{c}}_{i}^* \rightarrow \mathbf{\underline{c}}_o^*\f$

@param ti [in] translation vector
@param ci [in] input coscrew
@param co [out] output coscrew
*/
void ksl_product_CoAdtcinv(const ksl_vec3_t* ti, const ksl_coscrew_t* ci,
                           ksl_coscrew_t* co);

/*!
@brief Performs a single precision spatial translation of the inverse of a
coscrew. Performs a Coadjoint transformation of the inverse of a coscrew, where
CoAdjoint transformation matrix consists of only a translation component.

\f$ [Ad]^*(\underline{t}_i) * -\mathbf{\underline{c}}_{i}^* \rightarrow
\mathbf{\underline{c}}_o^*\f$

\f$ -[Ad]^*(\underline{t}_i) \mathbf{\underline{c}}_{i}^* \rightarrow
\mathbf{\underline{c}}_o^*\f$

\f$\ -\begin{bmatrix} I & 0\\ \underline{\tilde{t}}_i & I \end{bmatrix}
\mathbf{\underline{c}}_{i}^* \rightarrow \mathbf{\underline{c}}_o^*\f$

@param ti [in] translation vector
@param ci [in] input coscrew
@param co [out] output coscrew
*/
void ksl_product_CoAdtcinvf(const ksl_vec3f_t* ti, const ksl_coscrewf_t* ci,
                            ksl_coscrewf_t* co);

/*!
@brief Performs a double precision spatial rotation of a coscrew. Performs a
Coadjoint transformation of a coscrew, where CoAdjoint transformation matrix
consists of only a rotation component.

\f$ [Ad]^*(R_i) \mathbf{\underline{c}}_{i}^* \rightarrow
\mathbf{\underline{c}}_o^*\f$

\f$\ \begin{bmatrix} R_i & 0\\ 0 & R_i \end{bmatrix}
\mathbf{\underline{c}}_{i}^* \rightarrow \mathbf{\underline{c}}_o^*\f$

@param Ri [in] input rotation matrix
@param ci [in] input coscrew
@param co [out] output coscrew
*/
void ksl_product_CoAdrc(const ksl_mat3x3_t* Ri, const ksl_coscrew_t* ci,
                        ksl_coscrew_t* co);

/*!
@brief Performs a single precision spatial rotation of a coscrew. Performs a
Coadjoint transformation of a coscrew, where CoAdjoint transformation matrix
consists of only a rotation component.

\f$ [Ad]^*(R_i) \mathbf{\underline{c}}_{i}^* \rightarrow
\mathbf{\underline{c}}_o^*\f$

\f$\ \begin{bmatrix} R_i & 0\\ 0 & R_i \end{bmatrix}
\mathbf{\underline{c}}_{i}^* \rightarrow \mathbf{\underline{c}}_o^*\f$

@param Ri [in] input rotation matrix
@param ci [in] input coscrew
@param co [out] output coscrew
*/
void ksl_product_CoAdrcf(const ksl_mat3x3f_t* Ri, const ksl_coscrewf_t* ci,
                         ksl_coscrewf_t* co);

/*!
@brief Performs a double precision spatial rotation of a coscrew, using the
transpose of the input rotation matrix. Performs a Coadjoint transformation of a
coscrew, where CoAdjoint transformation matrix consists of only a rotation
component transposed.

\f$ [Ad]^*(R_i^T) \mathbf{\underline{c}}_{i}^* \rightarrow
\mathbf{\underline{c}}_o^*\f$

\f$ \left([Ad]^*(R_i) \right)^{-1} \mathbf{\underline{c}}_{i}^* \rightarrow
\mathbf{\underline{c}}_o^*\f$

\f$\ \begin{bmatrix} R_i^T & 0\\ 0 & R_i^T \end{bmatrix}
\mathbf{\underline{c}}_{i}^* \rightarrow \mathbf{\underline{c}}_o^*\f$

@param Ri [in] input rotation matrix
@param ci [in] input coscrew
@param co [out] output coscrew
*/
void ksl_product_CoAdrinvc(const ksl_mat3x3_t* Ri, const ksl_coscrew_t* ci,
                           ksl_coscrew_t* co);

/*!
@brief Performs a single precision spatial rotation of a coscrew, using the
transpose of the input rotation matrix. Performs a Coadjoint transformation of a
coscrew, where CoAdjoint transformation matrix consists of only a rotation
component transposed.

\f$ [Ad]^*(R_i^T) \mathbf{\underline{c}}_{i}^* \rightarrow
\mathbf{\underline{c}}_o^*\f$

\f$ \left([Ad]^*(R_i) \right)^{-1} \mathbf{\underline{c}}_{i}^* \rightarrow
\mathbf{\underline{c}}_o^*\f$

\f$\ \begin{bmatrix} R_i^T & 0\\ 0 & R_i^T \end{bmatrix}
\mathbf{\underline{c}}_{i}^* \rightarrow \mathbf{\underline{c}}_o^*\f$

@param Ri [in] input rotation matrix
@param ci [in] input coscrew
@param co [out] output coscrew
*/
void ksl_product_CoAdrinvcf(const ksl_mat3x3f_t* Ri, const ksl_coscrewf_t* ci,
                            ksl_coscrewf_t* co);

/*!
@brief Performs a double precision spatial transformation of a coscrew. Performs
a Coadjoint transformation of a coscrew, where CoAdjoint transformation matrix
consists of a rotation and translation component.

\f$ [Ad]^*(\Phi_{Di}) \mathbf{\underline{c}}_{i}^* \rightarrow
\mathbf{\underline{c}}_o^*\f$

\f$ [Ad]^*(R_i, \underline{t}_i) \mathbf{\underline{c}}_{i}^* \rightarrow
\mathbf{\underline{c}}_o^*\f$

\f$\ \begin{bmatrix} R_i & 0\\ \tilde{\underline{t}}_i R_i & R_i \end{bmatrix}
\mathbf{\underline{c}}_{i}^* \rightarrow \mathbf{\underline{c}}_o^*\f$

@param Ri [in] input rotation matrix
@param ci [in] input coscrew
@param co [out] output coscrew
*/
void ksl_product_CoAdc(const ksl_SE3_t* Di, const ksl_coscrew_t* ci,
                       ksl_coscrew_t* co);

/*!
@brief Performs a single precision spatial transformation of a coscrew. Performs
a Coadjoint transformation of a coscrew, where CoAdjoint transformation matrix
consists of a rotation and translation component.

\f$ [Ad]^*(\Phi_{Di}) \mathbf{\underline{c}}_{i}^* \rightarrow
\mathbf{\underline{c}}_o^*\f$

\f$ [Ad]^*(R_i, \underline{t}_i) \mathbf{\underline{c}}_{i}^* \rightarrow
\mathbf{\underline{c}}_o^*\f$

\f$\ \begin{bmatrix} R_i & 0\\ \tilde{\underline{t}}_i R_i & R_i \end{bmatrix}
\mathbf{\underline{c}}_{i}^* \rightarrow \mathbf{\underline{c}}_o^*\f$

@param Di [in] input SE3 matrix
@param ci [in] input coscrew
@param co [out] output coscrew
*/
void ksl_product_CoAdcf(const ksl_SE3f_t* Di, const ksl_coscrewf_t* ci,
                        ksl_coscrewf_t* co);

/*!
@brief Performs the inverse single precision spatial transformation of a
coscrew. Performs the inverse of a Coadjoint transformation of a coscrew, where
the CoAdjoint transformation matrix consists of a rotation and translation
component.

\f$ [Ad]^*(\Phi_{Di}^{-1}) \mathbf{\underline{c}}_{i}^* \rightarrow
\mathbf{\underline{c}}_o^*\f$

\f$ \left( [Ad]^*(\Phi_{Di}) \right)^{-1} \mathbf{\underline{c}}_{i}^*
\rightarrow \mathbf{\underline{c}}_o^*\f$

\f$ [Ad]^*(R_i^T, -\underline{t}_i) \mathbf{\underline{c}}_{i}^* \rightarrow
\mathbf{\underline{c}}_o^*\f$

\f$\ \begin{bmatrix} R_i^T & 0\\ -\tilde{\underline{t}}_i R_i^T & R_i^T
\end{bmatrix} \mathbf{\underline{c}}_{i}^* \rightarrow
\mathbf{\underline{c}}_o^*\f$

@param Di [in] input SE3 matrix
@param ci [in] input coscrew
@param co [out] output coscrew
*/
void ksl_product_CoAdinvc(const ksl_SE3_t* Di, const ksl_coscrew_t* ci,
                          ksl_coscrew_t* co);

/*!
@brief Performs the inverse single precision spatial transformation of a
coscrew. Performs the inverse of a Coadjoint transformation of a coscrew, where
the CoAdjoint transformation matrix consists of a rotation and translation
component.

\f$ [Ad]^*(\Phi_{Di}^{-1}) \mathbf{\underline{c}}_{i}^* \rightarrow
\mathbf{\underline{c}}_o^*\f$

\f$ \left( [Ad]^*(\Phi_{Di}) \right)^{-1} \mathbf{\underline{c}}_{i}^*
\rightarrow \mathbf{\underline{c}}_o^*\f$

\f$ [Ad]^*(R_i^T, -\underline{t}_i) \mathbf{\underline{c}}_{i}^* \rightarrow
\mathbf{\underline{c}}_o^*\f$

\f$\ \begin{bmatrix} R_i^T & 0\\ -\tilde{\underline{t}}_i R_i^T & R_i^T
\end{bmatrix} \mathbf{\underline{c}}_{i}^* \rightarrow
\mathbf{\underline{c}}_o^*\f$

@param Di [in] input SE3 matrix
@param ci [in] input coscrew
@param co [out] output coscrew
*/
void ksl_product_CoAdinvcf(const ksl_SE3f_t* Di, const ksl_coscrewf_t* ci,
                           ksl_coscrewf_t* co);

void ksl_product_CoAdrc(const ksl_mat3x3_t* ri, const ksl_coscrew_t* ci,
                        ksl_coscrew_t* co);

void ksl_product_CoAdrcf(const ksl_mat3x3f_t* ri, const ksl_coscrewf_t* ci,
                         ksl_coscrewf_t* co);

void ksl_product_CoAdrcinv(const ksl_mat3x3_t* ri, const ksl_coscrew_t* ci,
                           ksl_coscrew_t* co);

void ksl_product_CoAdrcinvf(const ksl_mat3x3f_t* ri, const ksl_coscrewf_t* ci,
                            ksl_coscrewf_t* co);

void ksl_product_CoAdtinvc(const ksl_vec3_t* ti, const ksl_coscrew_t* ci,
                           ksl_coscrew_t* co);

void ksl_product_CoAdtinvcf(const ksl_vec3f_t* ti, const ksl_coscrewf_t* ci,
                            ksl_coscrewf_t* co);

void ksl_product_CoAdcinv(const ksl_SE3_t* Di, const ksl_coscrew_t* ci,
                          ksl_coscrew_t* co);

void ksl_product_CoAdcinvf(const ksl_SE3f_t* Di, const ksl_coscrewf_t* ci,
                           ksl_coscrewf_t* co);

#ifdef __cplusplus
}
#endif

#endif
