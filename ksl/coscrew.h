/**
@file
@author Kristopher Wehage, Roger Wehage
@brief Utilities to initialize and operate on coscrews
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
#ifndef _KSL_COSCREW_H_
#define _KSL_COSCREW_H_

#include "ksl/types.h"

#include "matrix.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
@brief double precision screw constructor
*/
static inline ksl_coscrew_t ksl_coscrew(const double m0, const double m1,
                                        const double m2, const double m3,
                                        const double m4, const double m5);

/*!
@brief single precision screwf constructor
*/
static inline ksl_coscrewf_t ksl_coscrewf(const float m0, const float m1,
                                          const float m2, const float m3,
                                          const float m4, const float m5);

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
static inline void ksl_coscrew_copy(const ksl_coscrew_t* ci, ksl_coscrew_t* co);

/*!
@brief Copy single precision ksl_coscrewf_t ci to co.

\f$\mathbf{\underline{c}}_{i}^* \rightarrow
\mathbf{\underline{c}}_o^*\f$

@param self [in] screw to copy
@param co [out] ci is copied to co
*/
static inline void ksl_coscrewf_copy(const ksl_coscrewf_t* self,
                                     ksl_coscrewf_t* co);

/*!
@brief Scale a double precision ksl_coscrew_t.

\f$\mathbf{\underline{c}}_{i}^* * a \rightarrow
\mathbf{\underline{c}}_i^*\f$

@param self [in] coscrew to invert
@param a [out] amount to scale the screw
*/
static inline void ksl_coscrew_scale(ksl_coscrew_t* self, const double a);

/*!
@brief Scale a single precision ksl_coscrew_t.

\f$\mathbf{\underline{c}}_{i}^* * a \rightarrow
\mathbf{\underline{c}}_i^*\f$

@param self [in] coscrew to invert
@param a [out] inverse of ci
*/
static inline void ksl_coscrewf_scale(ksl_coscrewf_t* self, const float a);

/*!
@brief Returns the inverse of a ksl_coscrew_t.

\f$-\mathbf{\underline{c}}_{i}^* \rightarrow
\mathbf{\underline{c}}_o^*\f$

@param ci [in] coscrew to invert
@param co [out] inverse of ci
*/
static inline void ksl_coscrew_inverted(const ksl_coscrew_t* ci,
                                        ksl_coscrew_t* co);

/*!
@brief Returns the inverse of a ksl_coscrewf_t.

\f$-\mathbf{\underline{c}}_{i}^* \rightarrow
\mathbf{\underline{c}}_o^*\f$

@param self [in] coscrew to invert
@param co [out] inverse of ci
*/
static inline void ksl_coscrewf_inverted(const ksl_coscrewf_t* self,
                                         ksl_coscrewf_t* co);

/*!
@brief Invert (i.e. negate) a ksl_coscrew_t in place.

\f$-\mathbf{\underline{c}}_{i}^* \rightarrow
\mathbf{\underline{c}}_i^*\f$

@param self [in/out] coscrew to invert
*/
static inline void ksl_coscrew_invert(ksl_coscrew_t* self);

/*!
@brief Invert (i.e. negate) a ksl_coscrewf_t in place.

\f$-\mathbf{\underline{c}}_{i}^* \rightarrow
\mathbf{\underline{c}}_i^*\f$

@param self [in/out] coscrew to invert
*/
static inline void ksl_coscrewf_invert(ksl_coscrewf_t* self);

/*!
@brief Return the magnitude of a coscrew.

@param v [in] coscrew
@return the length of the linear (force) part, or of the angular (moment) part
if the force is zero (below 1e-9)
*/
static inline double ksl_coscrew_norm(const ksl_coscrew_t* v);

/*!
@brief Single precision version of ksl_coscrew_norm().
*/
static inline float ksl_coscrewf_norm(const ksl_coscrewf_t* v);

/*!
@brief Normalize a coscrew in place.

Divides the coscrew by the length of its linear (force) part. If the force is
zero (below 1e-9), the coscrew is a pure moment and its angular part is
normalized instead.

@param v [in,out] coscrew
*/
static inline void ksl_coscrew_normalize(ksl_coscrew_t* v);

/*!
@brief Single precision version of ksl_coscrew_normalize().
*/
static inline void ksl_coscrewf_normalize(ksl_coscrewf_t* v);

/*!
@brief In-place add a double precision coscrew multiplied with a scalar to an
existing coscrew.

\f$a * \mathbf{\underline{c}}_{x}^* + \mathbf{\underline{c}}_y^* \rightarrow
\mathbf{\underline{c}}_y^*\f$

@param a [in]
@param x [in]
@param y [in/out] coscrew to add
*/
static inline void ksl_axpy_cc(const double a, const ksl_coscrew_t* x,
                               ksl_coscrew_t* y);

/*!
@brief In-place add a single precision coscrew multiplied with a scalar to an
existing coscrew.

\f$a * \mathbf{\underline{c}}_{x}^* + \mathbf{\underline{c}}_y^* \rightarrow
\mathbf{\underline{c}}_y^*\f$

@param a [in]
@param x [in]
@param y [in/out]
*/
static inline void ksl_axpy_ccf(const float a, const ksl_coscrewf_t* x,
                                ksl_coscrewf_t* y);

/*!
@brief In-place add a double precision coscrew to an existing coscrew. This is a
variant of axpy where the scalar term a is 1.

\f$ \mathbf{\underline{c}}_{x}^* + \mathbf{\underline{c}}_y^* \rightarrow
\mathbf{\underline{c}}_y^*\f$

@param x [in] coscrew to add
@param y [in,out] coscrew that x is added to
*/
static inline void ksl_xpy_cc(const ksl_coscrew_t* x, ksl_coscrew_t* y);

/*!
@brief In-place add a single precision coscrew to an existing coscrew. This is a
variant of axpy where there the scalar term is 1.

\f$ \mathbf{\underline{c}}_{x}^* + \mathbf{\underline{c}}_y^* \rightarrow
\mathbf{\underline{c}}_y^*\f$

@param x [in] coscrew to add
@param y [in,out] coscrew that x is added to
*/
static inline void ksl_xpy_ccf(const ksl_coscrewf_t* x, ksl_coscrewf_t* y);

/*!
@brief In-place subtract a double precision coscrew x from an  coscrew y. This
is a variant of axpy where the scalar term is -1.

\f$ -\mathbf{\underline{c}}_{x}^* + \mathbf{\underline{c}}_y^* \rightarrow
\mathbf{\underline{c}}_y^*\f$

@param x [in] coscrew to subtract
@param y [in,out] coscrew that x is subtracted from
*/
static inline void ksl_nxpy_cc(const ksl_coscrew_t* x, ksl_coscrew_t* y);

/*!
@brief In-place subtract a single precision coscrew from an existing coscrew.
This is a variant of axpy where the scalar term is -1.

\f$ -\mathbf{\underline{c}}_{x}^* + \mathbf{\underline{c}}_y^* \rightarrow
\mathbf{\underline{c}}_y^*\f$

@param x [in] coscrew to subtract
@param y [in,out] coscrew that x is subtracted from
*/
static inline void ksl_nxpy_ccf(const ksl_coscrewf_t* x, ksl_coscrewf_t* y);

/*!
@brief Scale a double precision coscrew.

\f$ \mathbf{\underline{c}}_i^* * a \rightarrow \mathbf{\underline{c}}_o^*\f$

@param a [in] scale factor
@param ci [in] coscrew to scale
@param co [out] scaled coscrew
*/
static inline void ksl_product_ac(const double a, const ksl_coscrew_t* ci,
                                  ksl_coscrew_t* co);

/*!
@brief Scale a single precision coscrew.

\f$ \mathbf{\underline{c}}_i^* * a \rightarrow \mathbf{\underline{c}}_o^*\f$

@param a [in] scale factor
@param ci [in] coscrew to scale
@param co [out] scaled coscrew
*/
static inline void ksl_product_acf(const float a, const ksl_coscrewf_t* ci,
                                   ksl_coscrewf_t* co);

/*!
@brief Compute the sum of two double precision coscrews

\f$\mathbf{\underline{c}}_{1i}^* + \mathbf{\underline{c}}_{2i}^* \rightarrow
\mathbf{\underline{c}}_o^*\f$

@param c1i [in] first coscrew to add
@param c2i [in] second coscrew to add
@param co [out] sum of c1i and c2i
*/
static inline void ksl_add_cc(const ksl_coscrew_t* c1i,
                              const ksl_coscrew_t* c2i, ksl_coscrew_t* co);

/*!
@brief Compute the sum of two single precision coscrews

\f$\mathbf{\underline{c}}_{1i}^* + \mathbf{\underline{c}}_{2i}^* \rightarrow
\mathbf{\underline{c}}_o^*\f$

@param c1i [in] first coscrew to add
@param c2i [in] second coscrew to add
@param co [out] sum of c1i and c2i
*/
static inline void ksl_add_ccf(const ksl_coscrewf_t* c1i,
                               const ksl_coscrewf_t* c2i, ksl_coscrewf_t* co);

/*!
@brief Compute the difference between two double precision coscrews

\f$\mathbf{\underline{c}}_{1i}^* - \mathbf{\underline{c}}_{2i}^* \rightarrow
\mathbf{\underline{c}}_o^*\f$

@param c1i [in] first coscrew
@param c2i [in] second coscrew
@param co [out] c1i minus c2i
*/
static inline void ksl_subtract_cc(const ksl_coscrew_t* c1i,
                                   const ksl_coscrew_t* c2i, ksl_coscrew_t* co);

/*!
@brief Compute the difference between two double precision coscrews

\f$\mathbf{\underline{c}}_{1i}^* - \mathbf{\underline{c}}_{2i}^* \rightarrow
\mathbf{\underline{c}}_o^*\f$

@param c1i [in] first coscrew
@param c2i [in] second coscrew
@param co [out] result of c1i minus c2i
*/
static inline void ksl_subtract_ccf(const ksl_coscrewf_t* c1i,
                                    const ksl_coscrewf_t* c2i,
                                    ksl_coscrewf_t* co);

/*!
@brief Add the linear part of a coscrew to a coscrew: co = ci1 + {ci2.lin, 0}.

@param ci1 [in] coscrew
@param ci2 [in] coscrew whose linear part is added; its angular part is ignored
@param co [out] sum
*/
static inline void ksl_add_cct(const ksl_coscrew_t* ci1,
                               const ksl_coscrew_t* ci2, ksl_coscrew_t* co);

/*!
@brief Single precision version of ksl_add_cct().
*/
static inline void ksl_add_cctf(const ksl_coscrewf_t* ci1,
                                const ksl_coscrewf_t* ci2, ksl_coscrewf_t* co);

/*!
@brief Compute the unit force coscrew along the x axis of a frame: co = CoAd(Di)
* {ex, 0}.

This is the constraint force direction of a joint that resists translation along
the axis.

@param Di [in] pose of the frame
@param co [out] {rx, t x rx}, where rx is the x column of the rotation
*/
static inline void ksl_hctx(const ksl_SE3_t* Di, ksl_coscrew_t* co);

/*!
@brief Single precision version of ksl_hctx().
*/
static inline void ksl_hctxf(const ksl_SE3f_t* Di, ksl_coscrewf_t* co);

/*!
@brief Compute the unit force coscrew along the y axis of a frame: co = CoAd(Di)
* {ey, 0}.

This is the constraint force direction of a joint that resists translation along
the axis.

@param Di [in] pose of the frame
@param co [out] {ry, t x ry}, where ry is the y column of the rotation
*/
static inline void ksl_hcty(const ksl_SE3_t* Di, ksl_coscrew_t* co);

/*!
@brief Single precision version of ksl_hcty().
*/
static inline void ksl_hctyf(const ksl_SE3f_t* Di, ksl_coscrewf_t* co);

/*!
@brief Compute the unit force coscrew along the z axis of a frame: co = CoAd(Di)
* {ez, 0}.

This is the constraint force direction of a joint that resists translation along
the axis.

@param Di [in] pose of the frame
@param co [out] {rz, t x rz}, where rz is the z column of the rotation
*/
static inline void ksl_hctz(const ksl_SE3_t* Di, ksl_coscrew_t* co);

/*!
@brief Single precision version of ksl_hctz().
*/
static inline void ksl_hctzf(const ksl_SE3f_t* Di, ksl_coscrewf_t* co);

/*!
@brief Compute the unit moment coscrew about the x axis of a frame: co =
CoAd(Di) * {0, ex}.

@param Di [in] pose of the frame
@param co [out] {0, rx}, where rx is the x column of the rotation
*/
static inline void ksl_hcrx(const ksl_SE3_t* Di, ksl_coscrew_t* co);

/*!
@brief Single precision version of ksl_hcrx().
*/
static inline void ksl_hcrxf(const ksl_SE3f_t* Di, ksl_coscrewf_t* co);

/*!
@brief Compute the unit moment coscrew about the y axis of a frame: co =
CoAd(Di) * {0, ey}.

@param Di [in] pose of the frame
@param co [out] {0, ry}, where ry is the y column of the rotation
*/
static inline void ksl_hcry(const ksl_SE3_t* Di, ksl_coscrew_t* co);

/*!
@brief Single precision version of ksl_hcry().
*/
static inline void ksl_hcryf(const ksl_SE3f_t* Di, ksl_coscrewf_t* co);

/*!
@brief Compute the unit moment coscrew about the z axis of a frame: co =
CoAd(Di) * {0, ez}.

@param Di [in] pose of the frame
@param co [out] {0, rz}, where rz is the z column of the rotation
*/
static inline void ksl_hcrz(const ksl_SE3_t* Di, ksl_coscrew_t* co);

/*!
@brief Single precision version of ksl_hcrz().
*/
static inline void ksl_hcrzf(const ksl_SE3f_t* Di, ksl_coscrewf_t* co);

/*!
@brief Compute the unit force coscrew along the negative x axis of a frame: co =
CoAd(Di) * {-ex, 0}.

@param Di [in] pose of the frame
@param co [out] {-rx, -t x rx}, where rx is the x column of the rotation
*/
static inline void ksl_hctxinv(const ksl_SE3_t* Di, ksl_coscrew_t* co);

/*!
@brief Single precision version of ksl_hctxinv().
*/
static inline void ksl_hctxinvf(const ksl_SE3f_t* Di, ksl_coscrewf_t* co);

/*!
@brief Compute the unit force coscrew along the negative y axis of a frame: co =
CoAd(Di) * {-ey, 0}.

@param Di [in] pose of the frame
@param co [out] {-ry, -t x ry}, where ry is the y column of the rotation
*/
static inline void ksl_hctyinv(const ksl_SE3_t* Di, ksl_coscrew_t* co);

/*!
@brief Single precision version of ksl_hctyinv().
*/
static inline void ksl_hctyinvf(const ksl_SE3f_t* Di, ksl_coscrewf_t* co);

/*!
@brief Compute the unit force coscrew along the negative z axis of a frame: co =
CoAd(Di) * {-ez, 0}.

@param Di [in] pose of the frame
@param co [out] {-rz, -t x rz}, where rz is the z column of the rotation
*/
static inline void ksl_hctzinv(const ksl_SE3_t* Di, ksl_coscrew_t* co);

/*!
@brief Single precision version of ksl_hctzinv().
*/
static inline void ksl_hctzinvf(const ksl_SE3f_t* Di, ksl_coscrewf_t* co);

/*!
@brief Compute the unit moment coscrew about the negative x axis of a frame: co
= CoAd(Di) * {0, -ex}.

@param Di [in] pose of the frame
@param co [out] {0, -rx}, where rx is the x column of the rotation
*/
static inline void ksl_hcrxinv(const ksl_SE3_t* Di, ksl_coscrew_t* co);

/*!
@brief Single precision version of ksl_hcrxinv().
*/
static inline void ksl_hcrxinvf(const ksl_SE3f_t* Di, ksl_coscrewf_t* co);

/*!
@brief Compute the unit moment coscrew about the negative y axis of a frame: co
= CoAd(Di) * {0, -ey}.

@param Di [in] pose of the frame
@param co [out] {0, -ry}, where ry is the y column of the rotation
*/
static inline void ksl_hcryinv(const ksl_SE3_t* Di, ksl_coscrew_t* co);

/*!
@brief Single precision version of ksl_hcryinv().
*/
static inline void ksl_hcryinvf(const ksl_SE3f_t* Di, ksl_coscrewf_t* co);

/*!
@brief Compute the unit moment coscrew about the negative z axis of a frame: co
= CoAd(Di) * {0, -ez}.

@param Di [in] pose of the frame
@param co [out] {0, -rz}, where rz is the z column of the rotation
*/
static inline void ksl_hcrzinv(const ksl_SE3_t* Di, ksl_coscrew_t* co);

/*!
@brief Single precision version of ksl_hcrzinv().
*/
static inline void ksl_hcrzinvf(const ksl_SE3f_t* Di, ksl_coscrewf_t* co);

/*!
@brief Cross product of a screw and a coscrew: co = si x* ci = {w x f, w x n + v
x f}.

This is the dual (force) cross product used to compute the rate of change of a
coscrew, such as momentum, in a moving frame.

@param s1i [in] screw {v, w}
@param c2i [in] coscrew {f, n}
@param co [out] cross product
*/
static inline void ksl_cross_sc(const ksl_screw_t* s1i,
                                const ksl_coscrew_t* c2i, ksl_coscrew_t* co);

/*!
@brief Single precision version of ksl_cross_sc().
*/
static inline void ksl_cross_scf(const ksl_screwf_t* s1i,
                                 const ksl_coscrewf_t* c2i, ksl_coscrewf_t* co);

/*!
@brief Cross product of a screw with the angular part of a coscrew: co = {0,
s1i.ang x c2i.ang}.

@param s1i [in] screw
@param c2i [in] coscrew whose angular part is used; its linear part is ignored
@param co [out] cross product
*/
static inline void ksl_cross_sca(const ksl_screw_t* s1i,
                                 const ksl_coscrew_t* c2i, ksl_coscrew_t* co);

/*!
@brief Single precision version of ksl_cross_sca().
*/
static inline void ksl_cross_scaf(const ksl_screwf_t* s1i,
                                  const ksl_coscrewf_t* c2i,
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
static inline void ksl_product_CoAdtc(const ksl_vec3_t* ti,
                                      const ksl_coscrew_t* ci,
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
static inline void ksl_product_CoAdtcf(const ksl_vec3f_t* ti,
                                       const ksl_coscrewf_t* ci,
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
static inline void ksl_product_CoAdtcinv(const ksl_vec3_t* ti,
                                         const ksl_coscrew_t* ci,
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
static inline void ksl_product_CoAdtcinvf(const ksl_vec3f_t* ti,
                                          const ksl_coscrewf_t* ci,
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
static inline void ksl_product_CoAdrc(const ksl_mat3x3_t* Ri,
                                      const ksl_coscrew_t* ci,
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
static inline void ksl_product_CoAdrcf(const ksl_mat3x3f_t* Ri,
                                       const ksl_coscrewf_t* ci,
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
static inline void ksl_product_CoAdrinvc(const ksl_mat3x3_t* Ri,
                                         const ksl_coscrew_t* ci,
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
static inline void ksl_product_CoAdrinvcf(const ksl_mat3x3f_t* Ri,
                                          const ksl_coscrewf_t* ci,
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

@param Di [in] SE3 transformation
@param ci [in] input coscrew
@param co [out] output coscrew
*/
static inline void ksl_product_CoAdc(const ksl_SE3_t* Di,
                                     const ksl_coscrew_t* ci,
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
static inline void ksl_product_CoAdcf(const ksl_SE3f_t* Di,
                                      const ksl_coscrewf_t* ci,
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
static inline void ksl_product_CoAdinvc(const ksl_SE3_t* Di,
                                        const ksl_coscrew_t* ci,
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
static inline void ksl_product_CoAdinvcf(const ksl_SE3f_t* Di,
                                         const ksl_coscrewf_t* ci,
                                         ksl_coscrewf_t* co);

static inline void ksl_product_CoAdrc(const ksl_mat3x3_t* ri,
                                      const ksl_coscrew_t* ci,
                                      ksl_coscrew_t* co);

static inline void ksl_product_CoAdrcf(const ksl_mat3x3f_t* ri,
                                       const ksl_coscrewf_t* ci,
                                       ksl_coscrewf_t* co);

/*!
@brief Rotate a negated coscrew: co = CoAd(ri) * (-ci) = {-ri * ci.lin, -ri *
ci.ang}.

@param ri [in] rotation matrix
@param ci [in] coscrew
@param co [out] rotated, negated coscrew
*/
static inline void ksl_product_CoAdrcinv(const ksl_mat3x3_t* ri,
                                         const ksl_coscrew_t* ci,
                                         ksl_coscrew_t* co);

/*!
@brief Single precision version of ksl_product_CoAdrcinv().
*/
static inline void ksl_product_CoAdrcinvf(const ksl_mat3x3f_t* ri,
                                          const ksl_coscrewf_t* ci,
                                          ksl_coscrewf_t* co);

/*!
@brief Transform a coscrew by the coadjoint of an inverse translation: co =
CoAd(T(ti)^-1) * ci.

Moves the reference point of a force from the origin to ti.

@param ti [in] translation
@param ci [in] coscrew
@param co [out] {ci.lin, ci.ang - ti x ci.lin}
*/
static inline void ksl_product_CoAdtinvc(const ksl_vec3_t* ti,
                                         const ksl_coscrew_t* ci,
                                         ksl_coscrew_t* co);

/*!
@brief Single precision version of ksl_product_CoAdtinvc().
*/
static inline void ksl_product_CoAdtinvcf(const ksl_vec3f_t* ti,
                                          const ksl_coscrewf_t* ci,
                                          ksl_coscrewf_t* co);

/*!
@brief Transform a negated coscrew by the coadjoint of an SE3 transformation: co
= CoAd(Di) * (-ci).

@param Di [in] SE3 transformation
@param ci [in] coscrew
@param co [out] transformed, negated coscrew
*/
static inline void ksl_product_CoAdcinv(const ksl_SE3_t* Di,
                                        const ksl_coscrew_t* ci,
                                        ksl_coscrew_t* co);

/*!
@brief Single precision version of ksl_product_CoAdcinv().
*/
static inline void ksl_product_CoAdcinvf(const ksl_SE3f_t* Di,
                                         const ksl_coscrewf_t* ci,
                                         ksl_coscrewf_t* co);

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

static inline ksl_coscrew_t ksl_coscrew(const double m0, const double m1,
                                        const double m2, const double m3,
                                        const double m4, const double m5) {
  ksl_coscrew_t s;
  s.m0 = m0;
  s.m1 = m1;
  s.m2 = m2;
  s.m3 = m3;
  s.m4 = m4;
  s.m5 = m5;
  return s;
}

static inline ksl_coscrewf_t ksl_coscrewf(const float m0, const float m1,
                                          const float m2, const float m3,
                                          const float m4, const float m5) {
  ksl_coscrewf_t s;
  s.m0 = m0;
  s.m1 = m1;
  s.m2 = m2;
  s.m3 = m3;
  s.m4 = m4;
  s.m5 = m5;
  return s;
}

static inline double ksl_coscrew_norm(const ksl_coscrew_t* KSL_RESTRICT v) {
  const double eps = 1e-9;
  if((fabs(v->lin.x) < eps) && (fabs(v->lin.y) < eps) &&
     (fabs(v->lin.z) < eps)) {
    return (ksl_vec3_l2norm(&v->ang));
  } else {
    return (ksl_vec3_l2norm(&v->lin));
  }
}

static inline float ksl_coscrewf_norm(const ksl_coscrewf_t* KSL_RESTRICT v) {
  const float eps = 1e-6;
  if((fabs(v->lin.x) < eps) && (fabs(v->lin.y) < eps) &&
     (fabs(v->lin.z) < eps)) {
    return (ksl_vec3f_l2norm(&v->ang));
  } else {
    return (ksl_vec3f_l2norm(&v->lin));
  }
}

static inline void ksl_coscrew_normalize(ksl_coscrew_t* v) {
  const double eps = 1e-9;
  if((fabs(v->lin.x) < eps) && (fabs(v->lin.y) < eps) &&
     (fabs(v->lin.z) < eps)) {
    ksl_vec3_normalize(&v->ang);
  } else {
    double lin_inv_norm = 1.0 / ksl_vec3_l2norm(&v->lin);
    ksl_vec3_scale(&v->ang, lin_inv_norm);
    ksl_vec3_scale(&v->lin, lin_inv_norm);
  }
}

static inline void ksl_coscrewf_normalize(ksl_coscrewf_t* v) {
  const float eps = 1e-6;
  if((fabs(v->lin.x) < eps) && (fabs(v->lin.y) < eps) &&
     (fabs(v->lin.z) < eps)) {
    ksl_vec3f_normalize(&v->ang);
  } else {
    float lin_inv_norm = 1.0 / ksl_vec3f_l2norm(&v->lin);
    ksl_vec3f_scale(&v->ang, lin_inv_norm);
    ksl_vec3f_scale(&v->lin, lin_inv_norm);
  }
}

static inline void ksl_coscrew_scale(ksl_coscrew_t* KSL_RESTRICT c,
                                     const double k) {
  for(int i = 0; i < 6; i++) {
    c->at[i] *= k;
  }
}

static inline void ksl_coscrewf_scale(ksl_coscrewf_t* KSL_RESTRICT c,
                                      const float k) {
  for(int i = 0; i < 6; i++) {
    c->at[i] *= k;
  }
}

static inline void ksl_coscrew_copy(const ksl_coscrew_t* KSL_RESTRICT ci,
                                    ksl_coscrew_t* KSL_RESTRICT co) {
  memcpy(co, ci, sizeof(ksl_coscrew_t));
}

static inline void ksl_coscrewf_copy(const ksl_coscrewf_t* KSL_RESTRICT ci,
                                     ksl_coscrewf_t* KSL_RESTRICT co) {
  memcpy(co, ci, sizeof(ksl_coscrewf_t));
}

static inline void ksl_coscrew_invert(ksl_coscrew_t* KSL_RESTRICT c) {
  for(int i = 0; i < 6; i++) {
    c->at[i] = -c->at[i];
  }
}

static inline void ksl_coscrewf_invert(ksl_coscrewf_t* KSL_RESTRICT c) {
  for(int i = 0; i < 6; i++) {
    c->at[i] = -c->at[i];
  }
}

static inline void ksl_coscrew_inverted(const ksl_coscrew_t* KSL_RESTRICT ci,
                                        ksl_coscrew_t* KSL_RESTRICT co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] = -ci->at[i];
  }
}

static inline void ksl_coscrewf_inverted(const ksl_coscrewf_t* KSL_RESTRICT ci,
                                         ksl_coscrewf_t* KSL_RESTRICT co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] = -ci->at[i];
  }
}

static inline void ksl_axpy_cc(const double a,
                               const ksl_coscrew_t* KSL_RESTRICT x,
                               ksl_coscrew_t* KSL_RESTRICT y) {
  for(int i = 0; i < 6; i++) {
    y->at[i] += a * x->at[i];
  }
}

static inline void ksl_axpy_ccf(const float a,
                                const ksl_coscrewf_t* KSL_RESTRICT x,
                                ksl_coscrewf_t* KSL_RESTRICT y) {
  for(int i = 0; i < 6; i++) {
    y->at[i] += a * x->at[i];
  }
}

static inline void ksl_xpy_cc(const ksl_coscrew_t* KSL_RESTRICT c1i,
                              ksl_coscrew_t* KSL_RESTRICT co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] += c1i->at[i];
  }
}

static inline void ksl_xpy_ccf(const ksl_coscrewf_t* KSL_RESTRICT c1i,
                               ksl_coscrewf_t* KSL_RESTRICT co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] += c1i->at[i];
  }
}

static inline void ksl_nxpy_cc(const ksl_coscrew_t* KSL_RESTRICT c1i,
                               ksl_coscrew_t* KSL_RESTRICT co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] -= c1i->at[i];
  }
}

static inline void ksl_nxpy_ccf(const ksl_coscrewf_t* KSL_RESTRICT c1i,
                                ksl_coscrewf_t* KSL_RESTRICT co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] -= c1i->at[i];
  }
}

static inline void ksl_product_ac(const double k,
                                  const ksl_coscrew_t* KSL_RESTRICT ci,
                                  ksl_coscrew_t* KSL_RESTRICT co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] = k * ci->at[i];
  }
}

static inline void ksl_product_acf(const float k,
                                   const ksl_coscrewf_t* KSL_RESTRICT ci,
                                   ksl_coscrewf_t* KSL_RESTRICT co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] = k * ci->at[i];
  }
}

static inline void ksl_add_cc(const ksl_coscrew_t* KSL_RESTRICT c1i,
                              const ksl_coscrew_t* KSL_RESTRICT c2i,
                              ksl_coscrew_t* KSL_RESTRICT co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] = c1i->at[i] + c2i->at[i];
  }
}

static inline void ksl_add_ccf(const ksl_coscrewf_t* KSL_RESTRICT c1i,
                               const ksl_coscrewf_t* KSL_RESTRICT c2i,
                               ksl_coscrewf_t* KSL_RESTRICT co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] = c1i->at[i] + c2i->at[i];
  }
}

static inline void ksl_subtract_cc(const ksl_coscrew_t* KSL_RESTRICT c1i,
                                   const ksl_coscrew_t* KSL_RESTRICT c2i,
                                   ksl_coscrew_t* KSL_RESTRICT co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] = c1i->at[i] - c2i->at[i];
  }
}

static inline void ksl_subtract_ccf(const ksl_coscrewf_t* KSL_RESTRICT c1i,
                                    const ksl_coscrewf_t* KSL_RESTRICT c2i,
                                    ksl_coscrewf_t* KSL_RESTRICT co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] = c1i->at[i] - c2i->at[i];
  }
}

static inline void ksl_add_cct(const ksl_coscrew_t* KSL_RESTRICT ci1,
                               const ksl_coscrew_t* KSL_RESTRICT ci2,
                               ksl_coscrew_t* KSL_RESTRICT co) {
  ksl_coscrew_t c;
  ksl_coscrew_copy(ci1, &c);
  c.at[0] += ci2->at[0];
  c.at[1] += ci2->at[1];
  c.at[2] += ci2->at[2];
  ksl_coscrew_copy(&c, co);
}

static inline void ksl_add_cctf(const ksl_coscrewf_t* KSL_RESTRICT ci1,
                                const ksl_coscrewf_t* KSL_RESTRICT ci2,
                                ksl_coscrewf_t* KSL_RESTRICT co) {
  ksl_coscrewf_t c;
  ksl_coscrewf_copy(ci1, &c);
  c.at[0] += ci2->at[0];
  c.at[1] += ci2->at[1];
  c.at[2] += ci2->at[2];
  ksl_coscrewf_copy(&c, co);
}

static inline void ksl_hctx(const ksl_SE3_t* KSL_RESTRICT Di,
                            ksl_coscrew_t* KSL_RESTRICT hco) {
  ksl_vec3_copy(&Di->R.v0, &hco->lin);
  ksl_cross_vv(&Di->t, &hco->lin, &hco->ang);
  // memset(&hco->ang, 0, 3 * sizeof(double));
}

static inline void ksl_hctxf(const ksl_SE3f_t* KSL_RESTRICT Di,
                             ksl_coscrewf_t* KSL_RESTRICT hco) {
  ksl_vec3f_copy(&Di->R.v0, &hco->lin);
  ksl_cross_vvf(&Di->t, &hco->lin, &hco->ang);
  // memset(&hco->ang, 0, 3 * sizeof(float));
}

static inline void ksl_hcty(const ksl_SE3_t* KSL_RESTRICT Di,
                            ksl_coscrew_t* KSL_RESTRICT hco) {
  ksl_vec3_copy(&Di->R.v1, &hco->lin);
  ksl_cross_vv(&Di->t, &hco->lin, &hco->ang);
  // memset(&hco->ang, 0, 3 * sizeof(double));
}

static inline void ksl_hctyf(const ksl_SE3f_t* KSL_RESTRICT Di,
                             ksl_coscrewf_t* KSL_RESTRICT hco) {
  ksl_vec3f_copy(&Di->R.v1, &hco->lin);
  ksl_cross_vvf(&Di->t, &hco->lin, &hco->ang);
  // memset(&hco->ang, 0, 3 * sizeof(float));
}

static inline void ksl_hctz(const ksl_SE3_t* KSL_RESTRICT Di,
                            ksl_coscrew_t* KSL_RESTRICT hco) {
  ksl_vec3_copy(&Di->R.v2, &hco->lin);
  ksl_cross_vv(&Di->t, &hco->lin, &hco->ang);
  // memset(&hco->ang, 0, 3 * sizeof(double));
}

static inline void ksl_hctzf(const ksl_SE3f_t* KSL_RESTRICT Di,
                             ksl_coscrewf_t* KSL_RESTRICT hco) {
  ksl_vec3f_copy(&Di->R.v2, &hco->lin);
  ksl_cross_vvf(&Di->t, &hco->lin, &hco->ang);
  // memset(&hco->ang, 0, 3 * sizeof(float));
}

static inline void ksl_hcrx(const ksl_SE3_t* KSL_RESTRICT Di,
                            ksl_coscrew_t* KSL_RESTRICT hco) {
  memset(&hco->lin, 0, 3 * sizeof(double));
  ksl_vec3_copy(&Di->R.v0, &hco->ang);
  // ksl_cross_vv(&Di->t, &hco->ang, &hco->lin);
}

static inline void ksl_hcrxf(const ksl_SE3f_t* KSL_RESTRICT Di,
                             ksl_coscrewf_t* KSL_RESTRICT hco) {
  memset(&hco->lin, 0, 3 * sizeof(float));
  ksl_vec3f_copy(&Di->R.v0, &hco->ang);
  // ksl_cross_vvf(&Di->t, &hco->ang, &hco->lin);
}

static inline void ksl_hcry(const ksl_SE3_t* KSL_RESTRICT Di,
                            ksl_coscrew_t* KSL_RESTRICT hco) {
  memset(&hco->lin, 0, 3 * sizeof(double));
  ksl_vec3_copy(&Di->R.v1, &hco->ang);
  // ksl_cross_vv(&Di->t, &hco->ang, &hco->lin);
}

static inline void ksl_hcryf(const ksl_SE3f_t* KSL_RESTRICT Di,
                             ksl_coscrewf_t* KSL_RESTRICT hco) {
  memset(&hco->lin, 0, 3 * sizeof(float));
  ksl_vec3f_copy(&Di->R.v1, &hco->ang);
  // ksl_cross_vvf(&Di->t, &hco->ang, &hco->lin);
}

static inline void ksl_hcrz(const ksl_SE3_t* KSL_RESTRICT Di,
                            ksl_coscrew_t* KSL_RESTRICT hco) {
  memset(&hco->lin, 0, 3 * sizeof(double));
  ksl_vec3_copy(&Di->R.v2, &hco->ang);
  // ksl_cross_vv(&Di->t, &hco->ang, &hco->lin);
}

static inline void ksl_hcrzf(const ksl_SE3f_t* KSL_RESTRICT Di,
                             ksl_coscrewf_t* KSL_RESTRICT hco) {
  memset(&hco->lin, 0, 3 * sizeof(float));
  ksl_vec3f_copy(&Di->R.v2, &hco->ang);
  // ksl_cross_vvf(&Di->t, &hco->ang, &hco->lin);
}

static inline void ksl_hctxinv(const ksl_SE3_t* KSL_RESTRICT Di,
                               ksl_coscrew_t* KSL_RESTRICT hco) {
  ksl_vec3_inverted(&Di->R.v0, &hco->lin);
  ksl_cross_vv(&Di->t, &hco->lin, &hco->ang);
  // memset(&hco->ang, 0, 3 * sizeof(double));
}

static inline void ksl_hctxinvf(const ksl_SE3f_t* KSL_RESTRICT Di,
                                ksl_coscrewf_t* KSL_RESTRICT hco) {
  ksl_vec3f_inverted(&Di->R.v0, &hco->lin);
  ksl_cross_vvf(&Di->t, &hco->lin, &hco->ang);
  // memset(&hco->ang, 0, 3 * sizeof(float));
}

static inline void ksl_hctyinv(const ksl_SE3_t* KSL_RESTRICT Di,
                               ksl_coscrew_t* KSL_RESTRICT hco) {
  ksl_vec3_inverted(&Di->R.v1, &hco->lin);
  ksl_cross_vv(&Di->t, &hco->lin, &hco->ang);
  // memset(&hco->ang, 0, 3 * sizeof(double));
}

static inline void ksl_hctyinvf(const ksl_SE3f_t* KSL_RESTRICT Di,
                                ksl_coscrewf_t* KSL_RESTRICT hco) {
  ksl_vec3f_inverted(&Di->R.v1, &hco->lin);
  ksl_cross_vvf(&Di->t, &hco->lin, &hco->ang);
  // memset(&hco->ang, 0, 3 * sizeof(float));
}

static inline void ksl_hctzinv(const ksl_SE3_t* KSL_RESTRICT Di,
                               ksl_coscrew_t* KSL_RESTRICT hco) {
  ksl_vec3_inverted(&Di->R.v2, &hco->lin);
  ksl_cross_vv(&Di->t, &hco->lin, &hco->ang);
  // memset(&hco->ang, 0, 3 * sizeof(double));
}

static inline void ksl_hctzinvf(const ksl_SE3f_t* KSL_RESTRICT Di,
                                ksl_coscrewf_t* KSL_RESTRICT hco) {
  ksl_vec3f_inverted(&Di->R.v2, &hco->lin);
  ksl_cross_vvf(&Di->t, &hco->lin, &hco->ang);
  // memset(&hco->ang, 0, 3 * sizeof(float));
}

static inline void ksl_hcrxinv(const ksl_SE3_t* KSL_RESTRICT Di,
                               ksl_coscrew_t* KSL_RESTRICT hco) {
  memset(&hco->lin, 0, 3 * sizeof(double));
  ksl_vec3_inverted(&Di->R.v0, &hco->ang);
  // ksl_cross_vv(&Di->t, &hco->ang, &hco->lin);
}

static inline void ksl_hcrxinvf(const ksl_SE3f_t* KSL_RESTRICT Di,
                                ksl_coscrewf_t* KSL_RESTRICT hco) {
  memset(&hco->lin, 0, 3 * sizeof(float));
  ksl_vec3f_inverted(&Di->R.v0, &hco->ang);
  // ksl_cross_vvf(&Di->t, &hco->ang, &hco->lin);
}

static inline void ksl_hcryinv(const ksl_SE3_t* KSL_RESTRICT Di,
                               ksl_coscrew_t* KSL_RESTRICT hco) {
  memset(&hco->lin, 0, 3 * sizeof(double));
  ksl_vec3_inverted(&Di->R.v1, &hco->ang);
  // ksl_cross_vv(&Di->t, &hco->ang, &hco->lin);
}

static inline void ksl_hcryinvf(const ksl_SE3f_t* KSL_RESTRICT Di,
                                ksl_coscrewf_t* KSL_RESTRICT hco) {
  memset(&hco->lin, 0, 3 * sizeof(float));
  ksl_vec3f_inverted(&Di->R.v1, &hco->ang);
  // ksl_cross_vvf(&Di->t, &hco->ang, &hco->lin);
}

static inline void ksl_hcrzinv(const ksl_SE3_t* KSL_RESTRICT Di,
                               ksl_coscrew_t* KSL_RESTRICT hco) {
  memset(&hco->lin, 0, 3 * sizeof(double));
  ksl_vec3_inverted(&Di->R.v2, &hco->ang);
  // ksl_cross_vv(&Di->t, &hco->ang, &hco->lin);
}

static inline void ksl_hcrzinvf(const ksl_SE3f_t* KSL_RESTRICT Di,
                                ksl_coscrewf_t* KSL_RESTRICT hco) {
  memset(&hco->lin, 0, 3 * sizeof(float));
  ksl_vec3f_inverted(&Di->R.v2, &hco->ang);
  // ksl_cross_vvf(&Di->t, &hco->ang, &hco->lin);
}

static inline void ksl_cross_sc(const ksl_screw_t* KSL_RESTRICT s1i,
                                const ksl_coscrew_t* KSL_RESTRICT c2i,
                                ksl_coscrew_t* KSL_RESTRICT co) {

  ksl_coscrew_t c;

  /* c.lin <- s1i->ang x c2i->lin */
  ksl_cross_vv(&s1i->ang, &c2i->lin, &c.lin);

  /* c.ang <- s1i->ang x c2i->ang */
  ksl_cross_vv(&s1i->ang, &c2i->ang, &c.ang);

  /* c.ang += s1i->lin x c2i->lin */
  c.m3 += s1i->m1 * c2i->m2 - s1i->m2 * c2i->m1;
  c.m4 += s1i->m2 * c2i->m0 - s1i->m0 * c2i->m2;
  c.m5 += s1i->m0 * c2i->m1 - s1i->m1 * c2i->m0;

  ksl_coscrew_copy(&c, co);
}

static inline void ksl_cross_scf(const ksl_screwf_t* KSL_RESTRICT s1i,
                                 const ksl_coscrewf_t* KSL_RESTRICT c2i,
                                 ksl_coscrewf_t* KSL_RESTRICT co) {

  ksl_coscrewf_t c;

  /* c.lin <- s1i->ang x c2i->lin */
  ksl_cross_vvf(&s1i->ang, &c2i->lin, &c.lin);

  /* c.ang <- s1i->ang x c2i->ang */
  ksl_cross_vvf(&s1i->ang, &c2i->ang, &c.ang);

  /* c.ang += s1i->lin x c2i->lin */
  c.m3 += s1i->m1 * c2i->m2 - s1i->m2 * c2i->m1;
  c.m4 += s1i->m2 * c2i->m0 - s1i->m0 * c2i->m2;
  c.m5 += s1i->m0 * c2i->m1 - s1i->m1 * c2i->m0;

  ksl_coscrewf_copy(&c, co);
}

static inline void ksl_cross_sca(const ksl_screw_t* KSL_RESTRICT s1i,
                                 const ksl_coscrew_t* KSL_RESTRICT c2i,
                                 ksl_coscrew_t* KSL_RESTRICT co) {
  memset(&co->lin, 0, sizeof(ksl_vec3_t));
  ksl_cross_vv(&s1i->ang, &c2i->ang, &co->ang);
}

static inline void ksl_cross_scaf(const ksl_screwf_t* KSL_RESTRICT s1i,
                                  const ksl_coscrewf_t* KSL_RESTRICT c2i,
                                  ksl_coscrewf_t* KSL_RESTRICT co) {
  memset(&co->lin, 0, sizeof(ksl_vec3f_t));
  ksl_cross_vvf(&s1i->ang, &c2i->ang, &co->ang);
}

static inline void ksl_product_CoAdrc(const ksl_mat3x3_t* KSL_RESTRICT ri,
                                      const ksl_coscrew_t* KSL_RESTRICT ci,
                                      ksl_coscrew_t* KSL_RESTRICT co) {

  ksl_product_drv(ri, &ci->lin, &co->lin);
  ksl_product_drv(ri, &ci->ang, &co->ang);
}

static inline void ksl_product_CoAdrcf(const ksl_mat3x3f_t* KSL_RESTRICT ri,
                                       const ksl_coscrewf_t* KSL_RESTRICT ci,
                                       ksl_coscrewf_t* KSL_RESTRICT co) {

  ksl_product_drvf(ri, &ci->lin, &co->lin);
  ksl_product_drvf(ri, &ci->ang, &co->ang);
}

static inline void ksl_product_CoAdrcinv(const ksl_mat3x3_t* KSL_RESTRICT ri,
                                         const ksl_coscrew_t* KSL_RESTRICT ci,
                                         ksl_coscrew_t* KSL_RESTRICT co) {

  ksl_product_drvinv(ri, &ci->lin, &co->lin);
  ksl_product_drvinv(ri, &ci->ang, &co->ang);
}

static inline void ksl_product_CoAdrcinvf(const ksl_mat3x3f_t* KSL_RESTRICT ri,
                                          const ksl_coscrewf_t* KSL_RESTRICT ci,
                                          ksl_coscrewf_t* KSL_RESTRICT co) {
  ksl_product_drvinvf(ri, &ci->lin, &co->lin);
  ksl_product_drvinvf(ri, &ci->ang, &co->ang);
}

static inline void ksl_product_CoAdrinvc(const ksl_mat3x3_t* KSL_RESTRICT ri,
                                         const ksl_coscrew_t* KSL_RESTRICT ci,
                                         ksl_coscrew_t* KSL_RESTRICT co) {
  ksl_product_drinvv(ri, &ci->lin, &co->lin);
  ksl_product_drinvv(ri, &ci->ang, &co->ang);
}

static inline void ksl_product_CoAdrinvcf(const ksl_mat3x3f_t* KSL_RESTRICT ri,
                                          const ksl_coscrewf_t* KSL_RESTRICT ci,
                                          ksl_coscrewf_t* KSL_RESTRICT co) {
  ksl_product_drinvvf(ri, &ci->lin, &co->lin);
  ksl_product_drinvvf(ri, &ci->ang, &co->ang);
}

static inline void ksl_product_CoAdtc(const ksl_vec3_t* KSL_RESTRICT ti,
                                      const ksl_coscrew_t* KSL_RESTRICT ci,
                                      ksl_coscrew_t* KSL_RESTRICT co) {
  const double c0 = ci->m0, c1 = ci->m1, c2 = ci->m2;
  const double c3 = ci->m3, c4 = ci->m4, c5 = ci->m5;
  co->m0 = c0;
  co->m1 = c1;
  co->m2 = c2;
  co->m3 = c3 + (ti->y * c2 - ti->z * c1);
  co->m4 = c4 + (ti->z * c0 - ti->x * c2);
  co->m5 = c5 + (ti->x * c1 - ti->y * c0);
}

static inline void ksl_product_CoAdtcf(const ksl_vec3f_t* KSL_RESTRICT ti,
                                       const ksl_coscrewf_t* KSL_RESTRICT ci,
                                       ksl_coscrewf_t* KSL_RESTRICT co) {
  const float c0 = ci->m0, c1 = ci->m1, c2 = ci->m2;
  const float c3 = ci->m3, c4 = ci->m4, c5 = ci->m5;
  co->m0 = c0;
  co->m1 = c1;
  co->m2 = c2;
  co->m3 = c3 + (ti->y * c2 - ti->z * c1);
  co->m4 = c4 + (ti->z * c0 - ti->x * c2);
  co->m5 = c5 + (ti->x * c1 - ti->y * c0);
}

static inline void ksl_product_CoAdtinvc(const ksl_vec3_t* KSL_RESTRICT ti,
                                         const ksl_coscrew_t* KSL_RESTRICT ci,
                                         ksl_coscrew_t* KSL_RESTRICT co) {
  const double c0 = ci->m0, c1 = ci->m1, c2 = ci->m2;
  const double c3 = ci->m3, c4 = ci->m4, c5 = ci->m5;
  co->m0 = c0;
  co->m1 = c1;
  co->m2 = c2;
  co->m3 = c3 - (ti->y * c2 - ti->z * c1);
  co->m4 = c4 - (ti->z * c0 - ti->x * c2);
  co->m5 = c5 - (ti->x * c1 - ti->y * c0);
}

static inline void ksl_product_CoAdtinvcf(const ksl_vec3f_t* KSL_RESTRICT ti,
                                          const ksl_coscrewf_t* KSL_RESTRICT ci,
                                          ksl_coscrewf_t* KSL_RESTRICT co) {
  const float c0 = ci->m0, c1 = ci->m1, c2 = ci->m2;
  const float c3 = ci->m3, c4 = ci->m4, c5 = ci->m5;
  co->m0 = c0;
  co->m1 = c1;
  co->m2 = c2;
  co->m3 = c3 - (ti->y * c2 - ti->z * c1);
  co->m4 = c4 - (ti->z * c0 - ti->x * c2);
  co->m5 = c5 - (ti->x * c1 - ti->y * c0);
}

static inline void ksl_product_CoAdtcinv(const ksl_vec3_t* KSL_RESTRICT ti,
                                         const ksl_coscrew_t* KSL_RESTRICT ci,
                                         ksl_coscrew_t* KSL_RESTRICT co) {
  const double c0 = -ci->m0, c1 = -ci->m1, c2 = -ci->m2;
  const double c3 = -ci->m3, c4 = -ci->m4, c5 = -ci->m5;
  co->m0 = c0;
  co->m1 = c1;
  co->m2 = c2;
  co->m3 = c3 + (ti->y * c2 - ti->z * c1);
  co->m4 = c4 + (ti->z * c0 - ti->x * c2);
  co->m5 = c5 + (ti->x * c1 - ti->y * c0);
}

static inline void ksl_product_CoAdtcinvf(const ksl_vec3f_t* KSL_RESTRICT ti,
                                          const ksl_coscrewf_t* KSL_RESTRICT ci,
                                          ksl_coscrewf_t* KSL_RESTRICT co) {
  const float c0 = -ci->m0, c1 = -ci->m1, c2 = -ci->m2;
  const float c3 = -ci->m3, c4 = -ci->m4, c5 = -ci->m5;
  co->m0 = c0;
  co->m1 = c1;
  co->m2 = c2;
  co->m3 = c3 + (ti->y * c2 - ti->z * c1);
  co->m4 = c4 + (ti->z * c0 - ti->x * c2);
  co->m5 = c5 + (ti->x * c1 - ti->y * c0);
}

static inline void ksl_product_CoAdc(const ksl_SE3_t* KSL_RESTRICT Di,
                                     const ksl_coscrew_t* KSL_RESTRICT ci,
                                     ksl_coscrew_t* KSL_RESTRICT co) {
  const ksl_mat3x3_t* r = &Di->R;
  const double c0 = ci->m0, c1 = ci->m1, c2 = ci->m2;
  const double c3 = ci->m3, c4 = ci->m4, c5 = ci->m5;
  const double fx = c0 * r->v0.x + c1 * r->v1.x + c2 * r->v2.x;
  const double fy = c0 * r->v0.y + c1 * r->v1.y + c2 * r->v2.y;
  const double fz = c0 * r->v0.z + c1 * r->v1.z + c2 * r->v2.z;
  const double nx = c3 * r->v0.x + c4 * r->v1.x + c5 * r->v2.x;
  const double ny = c3 * r->v0.y + c4 * r->v1.y + c5 * r->v2.y;
  const double nz = c3 * r->v0.z + c4 * r->v1.z + c5 * r->v2.z;
  co->m0 = fx;
  co->m1 = fy;
  co->m2 = fz;
  co->m3 = nx + (Di->t.y * fz - Di->t.z * fy);
  co->m4 = ny + (Di->t.z * fx - Di->t.x * fz);
  co->m5 = nz + (Di->t.x * fy - Di->t.y * fx);
}

static inline void ksl_product_CoAdcf(const ksl_SE3f_t* KSL_RESTRICT Di,
                                      const ksl_coscrewf_t* KSL_RESTRICT ci,
                                      ksl_coscrewf_t* KSL_RESTRICT co) {
  const ksl_mat3x3f_t* r = &Di->R;
  const float c0 = ci->m0, c1 = ci->m1, c2 = ci->m2;
  const float c3 = ci->m3, c4 = ci->m4, c5 = ci->m5;
  const float fx = c0 * r->v0.x + c1 * r->v1.x + c2 * r->v2.x;
  const float fy = c0 * r->v0.y + c1 * r->v1.y + c2 * r->v2.y;
  const float fz = c0 * r->v0.z + c1 * r->v1.z + c2 * r->v2.z;
  const float nx = c3 * r->v0.x + c4 * r->v1.x + c5 * r->v2.x;
  const float ny = c3 * r->v0.y + c4 * r->v1.y + c5 * r->v2.y;
  const float nz = c3 * r->v0.z + c4 * r->v1.z + c5 * r->v2.z;
  co->m0 = fx;
  co->m1 = fy;
  co->m2 = fz;
  co->m3 = nx + (Di->t.y * fz - Di->t.z * fy);
  co->m4 = ny + (Di->t.z * fx - Di->t.x * fz);
  co->m5 = nz + (Di->t.x * fy - Di->t.y * fx);
}

static inline void ksl_product_CoAdcinv(const ksl_SE3_t* KSL_RESTRICT Di,
                                        const ksl_coscrew_t* KSL_RESTRICT ci,
                                        ksl_coscrew_t* KSL_RESTRICT co) {
  const ksl_mat3x3_t* r = &Di->R;
  const double c0 = -ci->m0, c1 = -ci->m1, c2 = -ci->m2;
  const double c3 = -ci->m3, c4 = -ci->m4, c5 = -ci->m5;
  const double fx = c0 * r->v0.x + c1 * r->v1.x + c2 * r->v2.x;
  const double fy = c0 * r->v0.y + c1 * r->v1.y + c2 * r->v2.y;
  const double fz = c0 * r->v0.z + c1 * r->v1.z + c2 * r->v2.z;
  const double nx = c3 * r->v0.x + c4 * r->v1.x + c5 * r->v2.x;
  const double ny = c3 * r->v0.y + c4 * r->v1.y + c5 * r->v2.y;
  const double nz = c3 * r->v0.z + c4 * r->v1.z + c5 * r->v2.z;
  co->m0 = fx;
  co->m1 = fy;
  co->m2 = fz;
  co->m3 = nx + (Di->t.y * fz - Di->t.z * fy);
  co->m4 = ny + (Di->t.z * fx - Di->t.x * fz);
  co->m5 = nz + (Di->t.x * fy - Di->t.y * fx);
}

static inline void ksl_product_CoAdcinvf(const ksl_SE3f_t* KSL_RESTRICT Di,
                                         const ksl_coscrewf_t* KSL_RESTRICT ci,
                                         ksl_coscrewf_t* KSL_RESTRICT co) {
  const ksl_mat3x3f_t* r = &Di->R;
  const float c0 = -ci->m0, c1 = -ci->m1, c2 = -ci->m2;
  const float c3 = -ci->m3, c4 = -ci->m4, c5 = -ci->m5;
  const float fx = c0 * r->v0.x + c1 * r->v1.x + c2 * r->v2.x;
  const float fy = c0 * r->v0.y + c1 * r->v1.y + c2 * r->v2.y;
  const float fz = c0 * r->v0.z + c1 * r->v1.z + c2 * r->v2.z;
  const float nx = c3 * r->v0.x + c4 * r->v1.x + c5 * r->v2.x;
  const float ny = c3 * r->v0.y + c4 * r->v1.y + c5 * r->v2.y;
  const float nz = c3 * r->v0.z + c4 * r->v1.z + c5 * r->v2.z;
  co->m0 = fx;
  co->m1 = fy;
  co->m2 = fz;
  co->m3 = nx + (Di->t.y * fz - Di->t.z * fy);
  co->m4 = ny + (Di->t.z * fx - Di->t.x * fz);
  co->m5 = nz + (Di->t.x * fy - Di->t.y * fx);
}

static inline void ksl_product_CoAdinvc(const ksl_SE3_t* KSL_RESTRICT Di,
                                        const ksl_coscrew_t* KSL_RESTRICT ci,
                                        ksl_coscrew_t* KSL_RESTRICT co) {
  ksl_coscrew_t temp;
  ksl_coscrew_copy(ci, &temp);

  temp.m3 -= Di->t.y * temp.m2 - Di->t.z * temp.m1;
  temp.m4 -= Di->t.z * temp.m0 - Di->t.x * temp.m2;
  temp.m5 -= Di->t.x * temp.m1 - Di->t.y * temp.m0;

  ksl_product_CoAdrinvc(&Di->R, &temp, co);
}

static inline void ksl_product_CoAdinvcf(const ksl_SE3f_t* KSL_RESTRICT Di,
                                         const ksl_coscrewf_t* KSL_RESTRICT ci,
                                         ksl_coscrewf_t* KSL_RESTRICT co) {
  ksl_coscrewf_t temp;
  ksl_coscrewf_copy(ci, &temp);

  temp.m3 -= Di->t.y * temp.m2 - Di->t.z * temp.m1;
  temp.m4 -= Di->t.z * temp.m0 - Di->t.x * temp.m2;
  temp.m5 -= Di->t.x * temp.m1 - Di->t.y * temp.m0;

  ksl_product_CoAdrinvcf(&Di->R, &temp, co);
}

#ifdef __cplusplus
}
#endif

#endif
