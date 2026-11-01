/**
@file
@author Kristopher Wehage, Roger Wehage
@brief Utilities to initialize and operate on mat3x3 and ma4x4 matrices
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

#ifndef _KSL_MATRIX_H_
#define _KSL_MATRIX_H_

#include "ksl/types.h"

#include <stdarg.h>

#include "axis.h"
#include "pub_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* matrix vector operations */

/*!
@brief Compute the double precision matrix product of a 3x3 matrix \f$R^{oi}\f$
and a 3x1 vector \f$\underline{v}^i_{oi}\f$.

\f$R^{oi} \underline{v}^i_{oi} \rightarrow \underline{v}^o_{oi} \f$

@param r_oi [in] input 3x3 matrix
@param v_i [in] input vector
@param v_o [out] result returned in v_o
*/
static inline void ksl_product_drv(const ksl_mat3x3_t* r_oi,
                                   const ksl_vec3_t* v_i, ksl_vec3_t* v_o);

/*!
@brief Compute the single precision matrix product of a 3x3 matrix \f$R^{oi}\f$
and a 3x1 vector \f$\underline{v}^i_{oi}\f$.

\f$R^{oi} \underline{v}^i_{oi} \rightarrow \underline{v}^o_{oi} \f$

@param r_oi [in] input 3x3 matrix
@param v_i [in] input vector
@param v_o [out] result returned in v_o
*/
static inline void ksl_product_drvf(const ksl_mat3x3f_t* r_oi,
                                    const ksl_vec3f_t* v_i, ksl_vec3f_t* v_o);

/*!
@brief Compute the double precision matrix product of a 3x3 matrix \f$R^{oi}\f$
and the inverse of a 3x1 input vector \f$\underline{v}^i_{oi}\f$.

\f$R^{oi} (-\underline{v}^i_{oi}) \rightarrow \underline{v}^o_{io} \f$

\f$-R^{oi} \underline{v}^i_{oi} \rightarrow \underline{v}^o_{io} \f$

\f$R^{oi} \underline{v}^i_{io} \rightarrow \underline{v}^o_{io} \f$

@param ri [in] input 3x3 matrix
@param vi [in] input vector
@param vo [out] result, -ri * vi
*/
static inline void ksl_product_drvinv(const ksl_mat3x3_t* ri,
                                      const ksl_vec3_t* vi, ksl_vec3_t* vo);

/*!
@brief Single precision version of ksl_product_drvinv().
*/
static inline void ksl_product_drvinvf(const ksl_mat3x3f_t* ri,
                                       const ksl_vec3f_t* vi, ksl_vec3f_t* vo);

/*!
@brief Rotate a vector by an inverse rotation: vo = ri^T * vi.

@param ri [in] rotation matrix
@param vi [in] vector
@param vo [out] product ri^T * vi
*/
static inline void ksl_product_drinvv(const ksl_mat3x3_t* ri,
                                      const ksl_vec3_t* vi, ksl_vec3_t* vo);

/*!
@brief Single precision version of ksl_product_drinvv().
*/
static inline void ksl_product_drinvvf(const ksl_mat3x3f_t* ri,
                                       const ksl_vec3f_t* vi, ksl_vec3f_t* vo);

/*!
@brief Rotate a negated vector by an inverse rotation: vo = -ri^T * vi.

@param ri [in] rotation matrix
@param vi [in] vector
@param vo [out] product -ri^T * vi
*/
static inline void ksl_product_drinvvinv(const ksl_mat3x3_t* ri,
                                         const ksl_vec3_t* vi, ksl_vec3_t* vo);

/*!
@brief Single precision version of ksl_product_drinvvinv().
*/
static inline void ksl_product_drinvvinvf(const ksl_mat3x3f_t* ri,
                                          const ksl_vec3f_t* vi,
                                          ksl_vec3f_t* vo);

/*!
@brief Rotate a vector along the x axis: vo = ri * (ti * ex).

@param ri [in] rotation matrix
@param ti [in] length of the vector along the x axis
@param vo [out] ti times the x column of ri
*/
static inline void ksl_product_drvtx(const ksl_mat3x3_t* ri, const double ti,
                                     ksl_vec3_t* vo);

/*!
@brief Single precision version of ksl_product_drvtx().
*/
static inline void ksl_product_drvtxf(const ksl_mat3x3f_t* ri, const float ti,
                                      ksl_vec3f_t* vo);

/*!
@brief Rotate a negated vector along the x axis: vo = ri * (-ti * ex).

@param ri [in] rotation matrix
@param ti [in] length of the vector along the x axis
@param vo [out] -ti times the x column of ri
*/
static inline void ksl_product_drvtxinv(const ksl_mat3x3_t* ri, const double ti,
                                        ksl_vec3_t* vo);

/*!
@brief Single precision version of ksl_product_drvtxinv().
*/
static inline void ksl_product_drvtxinvf(const ksl_mat3x3f_t* ri,
                                         const float ti, ksl_vec3f_t* vo);

/*!
@brief Rotate a vector along the y axis: vo = ri * (ti * ey).

@param ri [in] rotation matrix
@param ti [in] length of the vector along the y axis
@param vo [out] ti times the y column of ri
*/
static inline void ksl_product_drvty(const ksl_mat3x3_t* ri, const double ti,
                                     ksl_vec3_t* vo);

/*!
@brief Single precision version of ksl_product_drvty().
*/
static inline void ksl_product_drvtyf(const ksl_mat3x3f_t* ri, const float ti,
                                      ksl_vec3f_t* vo);

/*!
@brief Rotate a negated vector along the y axis: vo = ri * (-ti * ey).

@param ri [in] rotation matrix
@param ti [in] length of the vector along the y axis
@param vo [out] -ti times the y column of ri
*/
static inline void ksl_product_drvtyinv(const ksl_mat3x3_t* ri, const double ti,
                                        ksl_vec3_t* vo);

/*!
@brief Single precision version of ksl_product_drvtyinv().
*/
static inline void ksl_product_drvtyinvf(const ksl_mat3x3f_t* ri,
                                         const float ti, ksl_vec3f_t* vo);

/*!
@brief Rotate a vector along the z axis: vo = ri * (ti * ez).

@param ri [in] rotation matrix
@param ti [in] length of the vector along the z axis
@param vo [out] ti times the z column of ri
*/
static inline void ksl_product_drvtz(const ksl_mat3x3_t* ri, const double ti,
                                     ksl_vec3_t* vo);

/*!
@brief Single precision version of ksl_product_drvtz().
*/
static inline void ksl_product_drvtzf(const ksl_mat3x3f_t* ri, const float ti,
                                      ksl_vec3f_t* vo);

/*!
@brief Rotate a negated vector along the z axis: vo = ri * (-ti * ez).

@param ri [in] rotation matrix
@param ti [in] length of the vector along the z axis
@param vo [out] -ti times the z column of ri
*/
static inline void ksl_product_drvtzinv(const ksl_mat3x3_t* ri, const double ti,
                                        ksl_vec3_t* vo);

/*!
@brief Single precision version of ksl_product_drvtzinv().
*/
static inline void ksl_product_drvtzinvf(const ksl_mat3x3f_t* ri,
                                         const float ti, ksl_vec3f_t* vo);

/* matrix-matrix operations */

/*!
@brief Compose a rotation with a rotation about the x axis: ro = ri * Rx(theta).

Only the two columns that change are computed; the x column is copied.

@param ri [in] rotation matrix
@param dc [in] the rotation angle as {sin(theta), cos(theta)}, see ksl_dc()
@param ro [out] product ri * Rx(theta)
*/
static inline void ksl_product_drdrx(const ksl_mat3x3_t* ri, const double dc[2],
                                     ksl_mat3x3_t* ro);

/*!
@brief Single precision version of ksl_product_drdrx().
*/
static inline void ksl_product_drdrxf(const ksl_mat3x3f_t* ri,
                                      const float dc[2], ksl_mat3x3f_t* ro);

/*!
@brief Compose a rotation with an inverse rotation about the x axis: ro = ri *
Rx(theta)^-1.

Only the two columns that change are computed; the x column is copied.

@param ri [in] rotation matrix
@param dc [in] the rotation angle as {sin(theta), cos(theta)}, see ksl_dc()
@param ro [out] product ri * Rx(-theta)
*/
static inline void ksl_product_drdrxinv(const ksl_mat3x3_t* ri,
                                        const double dc[2], ksl_mat3x3_t* ro);

/*!
@brief Single precision version of ksl_product_drdrxinv().
*/
static inline void ksl_product_drdrxinvf(const ksl_mat3x3f_t* ri,
                                         const float dc[2], ksl_mat3x3f_t* ro);

/*!
@brief Compose a rotation with a rotation about the y axis: ro = ri * Ry(theta).

Only the two columns that change are computed; the y column is copied.

@param ri [in] rotation matrix
@param dc [in] the rotation angle as {sin(theta), cos(theta)}, see ksl_dc()
@param ro [out] product ri * Ry(theta)
*/
static inline void ksl_product_drdry(const ksl_mat3x3_t* ri, const double dc[2],
                                     ksl_mat3x3_t* ro);

/*!
@brief Single precision version of ksl_product_drdry().
*/
static inline void ksl_product_drdryf(const ksl_mat3x3f_t* ri,
                                      const float dc[2], ksl_mat3x3f_t* ro);

/*!
@brief Compose a rotation with an inverse rotation about the y axis: ro = ri *
Ry(theta)^-1.

Only the two columns that change are computed; the y column is copied.

@param ri [in] rotation matrix
@param dc [in] the rotation angle as {sin(theta), cos(theta)}, see ksl_dc()
@param ro [out] product ri * Ry(-theta)
*/
static inline void ksl_product_drdryinv(const ksl_mat3x3_t* ri,
                                        const double dc[2], ksl_mat3x3_t* ro);

/*!
@brief Single precision version of ksl_product_drdryinv().
*/
static inline void ksl_product_drdryinvf(const ksl_mat3x3f_t* ri,
                                         const float dc[2], ksl_mat3x3f_t* ro);

/*!
@brief Compose a rotation with a rotation about the z axis: ro = ri * Rz(theta).

Only the two columns that change are computed; the z column is copied.

@param ri [in] rotation matrix
@param dc [in] the rotation angle as {sin(theta), cos(theta)}, see ksl_dc()
@param ro [out] product ri * Rz(theta)
*/
static inline void ksl_product_drdrz(const ksl_mat3x3_t* ri, const double dc[2],
                                     ksl_mat3x3_t* ro);

/*!
@brief Single precision version of ksl_product_drdrz().
*/
static inline void ksl_product_drdrzf(const ksl_mat3x3f_t* ri,
                                      const float dc[2], ksl_mat3x3f_t* ro);

/*!
@brief Compose a rotation with an inverse rotation about the z axis: ro = ri *
Rz(theta)^-1.

Only the two columns that change are computed; the z column is copied.

@param ri [in] rotation matrix
@param dc [in] the rotation angle as {sin(theta), cos(theta)}, see ksl_dc()
@param ro [out] product ri * Rz(-theta)
*/
static inline void ksl_product_drdrzinv(const ksl_mat3x3_t* ri,
                                        const double dc[2], ksl_mat3x3_t* ro);

/*!
@brief Single precision version of ksl_product_drdrzinv().
*/
static inline void ksl_product_drdrzinvf(const ksl_mat3x3f_t* ri,
                                         const float dc[2], ksl_mat3x3f_t* ro);

/*!
@brief Multiply two rotation matrices: ro = r1i * r2i.

@param r1i [in] first rotation
@param r2i [in] second rotation
@param ro [out] product r1i * r2i
*/
static inline void ksl_product_drdr(const ksl_mat3x3_t* r1i,
                                    const ksl_mat3x3_t* r2i, ksl_mat3x3_t* ro);

/*!
@brief Single precision version of ksl_product_drdr().
*/
static inline void ksl_product_drdrf(const ksl_mat3x3f_t* r1i,
                                     const ksl_mat3x3f_t* r2i,
                                     ksl_mat3x3f_t* ro);

/*!
@brief Multiply a rotation by an inverse rotation: ro = r1i * r2i^T.

@param r1i [in] first rotation
@param r2i [in] rotation to invert
@param ro [out] product r1i * r2i^T
*/
static inline void ksl_product_drdrinv(const ksl_mat3x3_t* r1i,
                                       const ksl_mat3x3_t* r2i,
                                       ksl_mat3x3_t* ro);

/*!
@brief Single precision version of ksl_product_drdrinv().
*/
static inline void ksl_product_drdrinvf(const ksl_mat3x3f_t* r1i,
                                        const ksl_mat3x3f_t* r2i,
                                        ksl_mat3x3f_t* ro);

/*!
@brief Multiply an inverse rotation by a rotation: ro = r1i^T * r2i.

@param r1i [in] rotation to invert
@param r2i [in] second rotation
@param ro [out] product r1i^T * r2i
*/
static inline void ksl_product_drinvdr(const ksl_mat3x3_t* r1i,
                                       const ksl_mat3x3_t* r2i,
                                       ksl_mat3x3_t* ro);

/*!
@brief Single precision version of ksl_product_drinvdr().
*/
static inline void ksl_product_drinvdrf(const ksl_mat3x3f_t* r1i,
                                        const ksl_mat3x3f_t* r2i,
                                        ksl_mat3x3f_t* ro);

/*!
@brief Transform a point by an SE3 transformation: vo = Di * vi = R * vi + t.

@param Di [in] SE3 transformation
@param vi [in] point
@param vo [out] transformed point
*/
static inline void ksl_product_dv(const ksl_SE3_t* Di, const ksl_vec3_t* vi,
                                  ksl_vec3_t* vo);

/*!
@brief Single precision version of ksl_product_dv().
*/
static inline void ksl_product_dvf(const ksl_SE3f_t* Di, const ksl_vec3f_t* vi,
                                   ksl_vec3f_t* vo);

/*!
@brief Transform a point by an inverse SE3 transformation: vo = Di^-1 * vi = R^T
* (vi - t).

Expresses a point given in the reference frame in the frame of Di.

@param Di [in] SE3 transformation to invert
@param vi [in] point
@param vo [out] transformed point
*/
static inline void ksl_product_dinvv(const ksl_SE3_t* Di, const ksl_vec3_t* vi,
                                     ksl_vec3_t* vo);

/*!
@brief Single precision version of ksl_product_dinvv().
*/
static inline void ksl_product_dinvvf(const ksl_SE3f_t* Di,
                                      const ksl_vec3f_t* vi, ksl_vec3f_t* vo);

/*!
@brief Compose an SE3 transformation with a rotation about the x axis: Do = Di *
Rx(theta).

Only the two columns of the rotation that change are computed; the x column and
the translation are copied.

@param Di [in] SE3 transformation
@param dc [in] the rotation angle as {sin(theta), cos(theta)}, see ksl_dc()
@param Do [out] product Di * Rx(theta)
*/
static inline void ksl_product_ddrx(const ksl_SE3_t* Di, const double dc[2],
                                    ksl_SE3_t* Do);

/*!
@brief Single precision version of ksl_product_ddrx().
*/
static inline void ksl_product_ddrxf(const ksl_SE3f_t* Di, const float dc[2],
                                     ksl_SE3f_t* Do);

/*!
@brief Compose an SE3 transformation with an inverse rotation about the x axis:
Do = Di * Rx(theta)^-1.

Only the two columns of the rotation that change are computed; the x column and
the translation are copied.

@param Di [in] SE3 transformation
@param dc [in] the rotation angle as {sin(theta), cos(theta)}, see ksl_dc()
@param Do [out] product Di * Rx(-theta)
*/
static inline void ksl_product_ddrxinv(const ksl_SE3_t* Di, const double dc[2],
                                       ksl_SE3_t* Do);

/*!
@brief Single precision version of ksl_product_ddrxinv().
*/
static inline void ksl_product_ddrxinvf(const ksl_SE3f_t* Di, const float dc[2],
                                        ksl_SE3f_t* Do);

/*!
@brief Compose an SE3 transformation with a rotation about the y axis: Do = Di *
Ry(theta).

Only the two columns of the rotation that change are computed; the y column and
the translation are copied.

@param Di [in] SE3 transformation
@param dc [in] the rotation angle as {sin(theta), cos(theta)}, see ksl_dc()
@param Do [out] product Di * Ry(theta)
*/
static inline void ksl_product_ddry(const ksl_SE3_t* Di, const double dc[2],
                                    ksl_SE3_t* Do);

/*!
@brief Single precision version of ksl_product_ddry().
*/
static inline void ksl_product_ddryf(const ksl_SE3f_t* Di, const float dc[2],
                                     ksl_SE3f_t* Do);

/*!
@brief Compose an SE3 transformation with an inverse rotation about the y axis:
Do = Di * Ry(theta)^-1.

Only the two columns of the rotation that change are computed; the y column and
the translation are copied.

@param Di [in] SE3 transformation
@param dc [in] the rotation angle as {sin(theta), cos(theta)}, see ksl_dc()
@param Do [out] product Di * Ry(-theta)
*/
static inline void ksl_product_ddryinv(const ksl_SE3_t* Di, const double dc[2],
                                       ksl_SE3_t* Do);

/*!
@brief Single precision version of ksl_product_ddryinv().
*/
static inline void ksl_product_ddryinvf(const ksl_SE3f_t* Di, const float dc[2],
                                        ksl_SE3f_t* Do);

/*!
@brief Compose an SE3 transformation with a rotation about the z axis: Do = Di *
Rz(theta).

Only the two columns of the rotation that change are computed; the z column and
the translation are copied.

@param Di [in] SE3 transformation
@param dc [in] the rotation angle as {sin(theta), cos(theta)}, see ksl_dc()
@param Do [out] product Di * Rz(theta)
*/
static inline void ksl_product_ddrz(const ksl_SE3_t* Di, const double dc[2],
                                    ksl_SE3_t* Do);

/*!
@brief Single precision version of ksl_product_ddrz().
*/
static inline void ksl_product_ddrzf(const ksl_SE3f_t* Di, const float dc[2],
                                     ksl_SE3f_t* Do);

/*!
@brief Compose an SE3 transformation with an inverse rotation about the z axis:
Do = Di * Rz(theta)^-1.

Only the two columns of the rotation that change are computed; the z column and
the translation are copied.

@param Di [in] SE3 transformation
@param dc [in] the rotation angle as {sin(theta), cos(theta)}, see ksl_dc()
@param Do [out] product Di * Rz(-theta)
*/
static inline void ksl_product_ddrzinv(const ksl_SE3_t* Di, const double dc[2],
                                       ksl_SE3_t* Do);

/*!
@brief Single precision version of ksl_product_ddrzinv().
*/
static inline void ksl_product_ddrzinvf(const ksl_SE3f_t* Di, const float dc[2],
                                        ksl_SE3f_t* Do);

/*!
@brief Compose an SE3 transformation with a translation: Do = Di * T(t).

The rotation is unchanged and the translation becomes R * t + t_Di.

@param Di [in] SE3 transformation
@param t [in] translation, expressed in the frame of Di
@param Do [out] product Di * T(t)
*/
static inline void ksl_product_ddt(const ksl_SE3_t* Di, const ksl_vec3_t* t,
                                   ksl_SE3_t* Do);

/*!
@brief Compose an SE3 transformation with an inverse translation: Do = Di *
T(vi)^-1.

@param Di [in] SE3 transformation
@param vi [in] translation, expressed in the frame of Di
@param Do [out] product Di * T(-vi)
*/
static inline void ksl_product_ddtinv(const ksl_SE3_t* Di, const ksl_vec3_t* vi,
                                      ksl_SE3_t* Do);

/*!
@brief Single precision version of ksl_product_ddtinv().
*/
static inline void ksl_product_ddtinvf(const ksl_SE3f_t* Di,
                                       const ksl_vec3f_t* vi, ksl_SE3f_t* Do);

/*!
@brief Single precision version of ksl_product_ddt().
*/
static inline void ksl_product_ddtf(const ksl_SE3f_t* Di, const ksl_vec3f_t* vi,
                                    ksl_SE3f_t* Do);

/*!
@brief Compose an inverse SE3 transformation with a translation: Do = Di^-1 *
T(vi).

Gives the pose of a frame located at vi, with the reference orientation,
relative to Di.

@param Di [in] SE3 transformation to invert
@param vi [in] translation
@param Do [out] product Di^-1 * T(vi)
*/
static inline void ksl_product_dinvdt(const ksl_SE3_t* Di, const ksl_vec3_t* vi,
                                      ksl_SE3_t* Do);

/*!
@brief Single precision version of ksl_product_dinvdt().
*/
static inline void ksl_product_dinvdtf(const ksl_SE3f_t* Di,
                                       const ksl_vec3f_t* vi, ksl_SE3f_t* Do);

/*!
@brief Compose an SE3 transformation with a translation along the x axis: Do =
Di * Tx(ti).

The rotation is unchanged and the translation becomes t + ti * (the x column of
R).

@param Di [in] SE3 transformation
@param ti [in] distance along the x axis of Di
@param Do [out] product Di * Tx(ti)
*/
static inline void ksl_product_ddtx(const ksl_SE3_t* Di, const double ti,
                                    ksl_SE3_t* Do);

/*!
@brief Single precision version of ksl_product_ddtx().
*/
static inline void ksl_product_ddtxf(const ksl_SE3f_t* Di, const float ti,
                                     ksl_SE3f_t* Do);

/*!
@brief Compose an SE3 transformation with an inverse translation along the x
axis: Do = Di * Tx(-ti).

The rotation is unchanged and the translation becomes t - ti * (the x column of
R).

@param Di [in] SE3 transformation
@param ti [in] distance along the x axis of Di
@param Do [out] product Di * Tx(-ti)
*/
static inline void ksl_product_ddtxinv(const ksl_SE3_t* Di, const double ti,
                                       ksl_SE3_t* Do);

/*!
@brief Single precision version of ksl_product_ddtxinv().
*/
static inline void ksl_product_ddtxinvf(const ksl_SE3f_t* Di, const float ti,
                                        ksl_SE3f_t* Do);

/*!
@brief Compose an SE3 transformation with a translation along the y axis: Do =
Di * Ty(ti).

The rotation is unchanged and the translation becomes t + ti * (the y column of
R).

@param Di [in] SE3 transformation
@param ti [in] distance along the y axis of Di
@param Do [out] product Di * Ty(ti)
*/
static inline void ksl_product_ddty(const ksl_SE3_t* Di, const double ti,
                                    ksl_SE3_t* Do);

/*!
@brief Single precision version of ksl_product_ddty().
*/
static inline void ksl_product_ddtyf(const ksl_SE3f_t* Di, const float ti,
                                     ksl_SE3f_t* Do);

/*!
@brief Compose an SE3 transformation with an inverse translation along the y
axis: Do = Di * Ty(-ti).

The rotation is unchanged and the translation becomes t - ti * (the y column of
R).

@param Di [in] SE3 transformation
@param ti [in] distance along the y axis of Di
@param Do [out] product Di * Ty(-ti)
*/
static inline void ksl_product_ddtyinv(const ksl_SE3_t* Di, const double ti,
                                       ksl_SE3_t* Do);

/*!
@brief Single precision version of ksl_product_ddtyinv().
*/
static inline void ksl_product_ddtyinvf(const ksl_SE3f_t* Di, const float ti,
                                        ksl_SE3f_t* Do);

/*!
@brief Compose an SE3 transformation with a translation along the z axis: Do =
Di * Tz(ti).

The rotation is unchanged and the translation becomes t + ti * (the z column of
R).

@param Di [in] SE3 transformation
@param ti [in] distance along the z axis of Di
@param Do [out] product Di * Tz(ti)
*/
static inline void ksl_product_ddtz(const ksl_SE3_t* Di, const double ti,
                                    ksl_SE3_t* Do);

/*!
@brief Single precision version of ksl_product_ddtz().
*/
static inline void ksl_product_ddtzf(const ksl_SE3f_t* Di, const float ti,
                                     ksl_SE3f_t* Do);

/*!
@brief Compose an SE3 transformation with an inverse translation along the z
axis: Do = Di * Tz(-ti).

The rotation is unchanged and the translation becomes t - ti * (the z column of
R).

@param Di [in] SE3 transformation
@param ti [in] distance along the z axis of Di
@param Do [out] product Di * Tz(-ti)
*/
static inline void ksl_product_ddtzinv(const ksl_SE3_t* Di, const double ti,
                                       ksl_SE3_t* Do);

/*!
@brief Single precision version of ksl_product_ddtzinv().
*/
static inline void ksl_product_ddtzinvf(const ksl_SE3f_t* Di, const float ti,
                                        ksl_SE3f_t* Do);

/*!
@brief Compose an SE3 transformation with a rotation: Do = Di * Ri.

The translation of Di is unchanged.

@param Di [in] SE3 transformation
@param Ri [in] rotation matrix
@param Do [out] product Di * Ri
*/
static inline void ksl_product_ddr(const ksl_SE3_t* Di, const ksl_mat3x3_t* Ri,
                                   ksl_SE3_t* Do);

/*!
@brief Single precision version of ksl_product_ddr().
*/
static inline void ksl_product_ddrf(const ksl_SE3f_t* Di,
                                    const ksl_mat3x3f_t* Ri, ksl_SE3f_t* Do);

/*!
@brief Compose an SE3 transformation with an inverse rotation: Do = Di * Ri^T.

The translation of Di is unchanged.

@param Di [in] SE3 transformation
@param Ri [in] rotation matrix
@param Do [out] product Di * Ri^T
*/
static inline void ksl_product_ddrinv(const ksl_SE3_t* Di,
                                      const ksl_mat3x3_t* Ri, ksl_SE3_t* Do);

/*!
@brief Single precision version of ksl_product_ddrinv().
*/
static inline void ksl_product_ddrinvf(const ksl_SE3f_t* Di,
                                       const ksl_mat3x3f_t* Ri, ksl_SE3f_t* Do);

/*!
@brief Compose two SE3 transformations: Do = D1i * D2i.

Do maps a point p to D1i * (D2i * p).

@param D1i [in] first transformation
@param D2i [in] second transformation
@param Do [out] product D1i * D2i
*/
static inline void ksl_product_dd(const ksl_SE3_t* D1i, const ksl_SE3_t* D2i,
                                  ksl_SE3_t* Do);

/*!
@brief Single precision version of ksl_product_dd().
*/
static inline void ksl_product_ddf(const ksl_SE3f_t* D1i, const ksl_SE3f_t* D2i,
                                   ksl_SE3f_t* Do);

/*!
@brief Compose an SE3 transformation with an inverse: Do = D1i * D2i^-1.

The inverse of D2i is applied without being computed separately.

@param D1i [in] first transformation
@param D2i [in] transformation to invert
@param Do [out] product D1i * D2i^-1
*/
static inline void ksl_product_ddinv(const ksl_SE3_t* D1i, const ksl_SE3_t* D2i,
                                     ksl_SE3_t* Do);

/*!
@brief Single precision version of ksl_product_ddinv().
*/
static inline void ksl_product_ddinvf(const ksl_SE3f_t* D1i,
                                      const ksl_SE3f_t* D2i, ksl_SE3f_t* Do);

/*!
@brief Compose an inverse SE3 transformation with another: Do = D1i^-1 * D2i.

Gives the pose of D2i relative to D1i. The inverse of D1i is applied without
being computed separately.

@param D1i [in] transformation to invert
@param D2i [in] second transformation
@param Do [out] product D1i^-1 * D2i
*/
static inline void ksl_product_dinvd(const ksl_SE3_t* D1i, const ksl_SE3_t* D2i,
                                     ksl_SE3_t* Do);

/*!
@brief Single precision version of ksl_product_dinvd().
*/
static inline void ksl_product_dinvdf(const ksl_SE3f_t* D1i,
                                      const ksl_SE3f_t* D2i, ksl_SE3f_t* Do);

#ifdef __cplusplus
}
#endif

/* -------- inline definitions -------- */

#include <assert.h>
#include <math.h>
#include <string.h>

#include "ksl/mat3x3.h"
#include "ksl/vec3.h"

#ifdef __cplusplus
extern "C" {
#endif

/* matrix vector operations */
static inline void ksl_product_drv(const ksl_mat3x3_t* KSL_RESTRICT ri,
                                   const ksl_vec3_t* KSL_RESTRICT vi,
                                   ksl_vec3_t* KSL_RESTRICT vo) {
  const double x = vi->x, y = vi->y, z = vi->z;
  vo->x = x * ri->v0.x + y * ri->v1.x + z * ri->v2.x;
  vo->y = x * ri->v0.y + y * ri->v1.y + z * ri->v2.y;
  vo->z = x * ri->v0.z + y * ri->v1.z + z * ri->v2.z;
}

static inline void ksl_product_drvf(const ksl_mat3x3f_t* KSL_RESTRICT ri,
                                    const ksl_vec3f_t* KSL_RESTRICT vi,
                                    ksl_vec3f_t* KSL_RESTRICT vo) {
  const float x = vi->x, y = vi->y, z = vi->z;
  vo->x = x * ri->v0.x + y * ri->v1.x + z * ri->v2.x;
  vo->y = x * ri->v0.y + y * ri->v1.y + z * ri->v2.y;
  vo->z = x * ri->v0.z + y * ri->v1.z + z * ri->v2.z;
}

static inline void ksl_product_drvinv(const ksl_mat3x3_t* KSL_RESTRICT ri,
                                      const ksl_vec3_t* KSL_RESTRICT vi,
                                      ksl_vec3_t* KSL_RESTRICT vo) {
  const double x = -vi->x, y = -vi->y, z = -vi->z;
  vo->x = x * ri->v0.x + y * ri->v1.x + z * ri->v2.x;
  vo->y = x * ri->v0.y + y * ri->v1.y + z * ri->v2.y;
  vo->z = x * ri->v0.z + y * ri->v1.z + z * ri->v2.z;
}

static inline void ksl_product_drvinvf(const ksl_mat3x3f_t* KSL_RESTRICT ri,
                                       const ksl_vec3f_t* KSL_RESTRICT vi,
                                       ksl_vec3f_t* KSL_RESTRICT vo) {
  const float x = -vi->x, y = -vi->y, z = -vi->z;
  vo->x = x * ri->v0.x + y * ri->v1.x + z * ri->v2.x;
  vo->y = x * ri->v0.y + y * ri->v1.y + z * ri->v2.y;
  vo->z = x * ri->v0.z + y * ri->v1.z + z * ri->v2.z;
}

static inline void ksl_product_drinvv(const ksl_mat3x3_t* KSL_RESTRICT ri,
                                      const ksl_vec3_t* KSL_RESTRICT vi,
                                      ksl_vec3_t* KSL_RESTRICT vo) {
  vo->x = ksl_dot_vv(&ri->v0, vi);
  vo->y = ksl_dot_vv(&ri->v1, vi);
  vo->z = ksl_dot_vv(&ri->v2, vi);
}

static inline void ksl_product_drinvvf(const ksl_mat3x3f_t* KSL_RESTRICT ri,
                                       const ksl_vec3f_t* KSL_RESTRICT vi,
                                       ksl_vec3f_t* KSL_RESTRICT vo) {
  vo->x = ksl_dot_vvf(&ri->v0, vi);
  vo->y = ksl_dot_vvf(&ri->v1, vi);
  vo->z = ksl_dot_vvf(&ri->v2, vi);
}

static inline void ksl_product_drinvvinv(const ksl_mat3x3_t* KSL_RESTRICT ri,
                                         const ksl_vec3_t* KSL_RESTRICT vi,
                                         ksl_vec3_t* KSL_RESTRICT vo) {
  vo->x = -ksl_dot_vv(&ri->v0, vi);
  vo->y = -ksl_dot_vv(&ri->v1, vi);
  vo->z = -ksl_dot_vv(&ri->v2, vi);
}

static inline void ksl_product_drinvvinvf(const ksl_mat3x3f_t* KSL_RESTRICT ri,
                                          const ksl_vec3f_t* KSL_RESTRICT vi,
                                          ksl_vec3f_t* KSL_RESTRICT vo) {
  vo->x = -ksl_dot_vvf(&ri->v0, vi);
  vo->y = -ksl_dot_vvf(&ri->v1, vi);
  vo->z = -ksl_dot_vvf(&ri->v2, vi);
}

static inline void ksl_product_drvtx(const ksl_mat3x3_t* KSL_RESTRICT ri,
                                     const double tx,
                                     ksl_vec3_t* KSL_RESTRICT vo) {
  ksl_product_av(tx, &ri->v0, vo);
}

static inline void ksl_product_drvtxf(const ksl_mat3x3f_t* KSL_RESTRICT ri,
                                      const float tx,
                                      ksl_vec3f_t* KSL_RESTRICT vo) {
  ksl_product_avf(tx, &ri->v0, vo);
}

static inline void ksl_product_drvtxinv(const ksl_mat3x3_t* KSL_RESTRICT ri,
                                        const double tx,
                                        ksl_vec3_t* KSL_RESTRICT vo) {
  ksl_product_av(-tx, &ri->v0, vo);
}

static inline void ksl_product_drvtxinvf(const ksl_mat3x3f_t* KSL_RESTRICT ri,
                                         const float tx,
                                         ksl_vec3f_t* KSL_RESTRICT vo) {
  ksl_product_avf(-tx, &ri->v0, vo);
}

static inline void ksl_product_drvty(const ksl_mat3x3_t* KSL_RESTRICT ri,
                                     const double ty,
                                     ksl_vec3_t* KSL_RESTRICT vo) {
  ksl_product_av(ty, &ri->v1, vo);
}

static inline void ksl_product_drvtyf(const ksl_mat3x3f_t* KSL_RESTRICT ri,
                                      const float ty,
                                      ksl_vec3f_t* KSL_RESTRICT vo) {
  ksl_product_avf(ty, &ri->v1, vo);
}

static inline void ksl_product_drvtyinv(const ksl_mat3x3_t* KSL_RESTRICT ri,
                                        const double ty,
                                        ksl_vec3_t* KSL_RESTRICT vo) {
  ksl_product_av(-ty, &ri->v1, vo);
}

static inline void ksl_product_drvtyinvf(const ksl_mat3x3f_t* KSL_RESTRICT ri,
                                         const float ty,
                                         ksl_vec3f_t* KSL_RESTRICT vo) {
  ksl_product_avf(-ty, &ri->v1, vo);
}

static inline void ksl_product_drvtz(const ksl_mat3x3_t* KSL_RESTRICT ri,
                                     const double tz,
                                     ksl_vec3_t* KSL_RESTRICT vo) {
  ksl_product_av(tz, &ri->v2, vo);
}

static inline void ksl_product_drvtzf(const ksl_mat3x3f_t* KSL_RESTRICT ri,
                                      const float tz,
                                      ksl_vec3f_t* KSL_RESTRICT vo) {
  ksl_product_avf(tz, &ri->v2, vo);
}

static inline void ksl_product_drvtzinv(const ksl_mat3x3_t* KSL_RESTRICT ri,
                                        const double tz,
                                        ksl_vec3_t* KSL_RESTRICT vo) {
  ksl_product_av(-tz, &ri->v2, vo);
}

static inline void ksl_product_drvtzinvf(const ksl_mat3x3f_t* KSL_RESTRICT ri,
                                         const float tz,
                                         ksl_vec3f_t* KSL_RESTRICT vo) {
  ksl_product_avf(-tz, &ri->v2, vo);
}

/* matrix-matrix operations */
static inline void ksl_product_drdrx(const ksl_mat3x3_t* KSL_RESTRICT ri,
                                     const double dc[2],
                                     ksl_mat3x3_t* KSL_RESTRICT ro) {
  const ksl_vec3_t v1 = ri->v1, v2 = ri->v2;
  ro->v1.x = dc[1] * v1.x + v2.x * dc[0];
  ro->v1.y = dc[1] * v1.y + v2.y * dc[0];
  ro->v1.z = dc[1] * v1.z + v2.z * dc[0];
  ro->v2.x = -dc[0] * v1.x + v2.x * dc[1];
  ro->v2.y = -dc[0] * v1.y + v2.y * dc[1];
  ro->v2.z = -dc[0] * v1.z + v2.z * dc[1];
  ro->v0 = ri->v0;
}

static inline void ksl_product_drdrxf(const ksl_mat3x3f_t* KSL_RESTRICT ri,
                                      const float dc[2],
                                      ksl_mat3x3f_t* KSL_RESTRICT ro) {
  const ksl_vec3f_t v1 = ri->v1, v2 = ri->v2;
  ro->v1.x = dc[1] * v1.x + v2.x * dc[0];
  ro->v1.y = dc[1] * v1.y + v2.y * dc[0];
  ro->v1.z = dc[1] * v1.z + v2.z * dc[0];
  ro->v2.x = -dc[0] * v1.x + v2.x * dc[1];
  ro->v2.y = -dc[0] * v1.y + v2.y * dc[1];
  ro->v2.z = -dc[0] * v1.z + v2.z * dc[1];
  ro->v0 = ri->v0;
}

static inline void ksl_product_drdrxinv(const ksl_mat3x3_t* KSL_RESTRICT ri,
                                        const double dc[2],
                                        ksl_mat3x3_t* KSL_RESTRICT ro) {
  const ksl_vec3_t v1 = ri->v1, v2 = ri->v2;
  ro->v1.x = dc[1] * v1.x + v2.x * -dc[0];
  ro->v1.y = dc[1] * v1.y + v2.y * -dc[0];
  ro->v1.z = dc[1] * v1.z + v2.z * -dc[0];
  ro->v2.x = dc[0] * v1.x + v2.x * dc[1];
  ro->v2.y = dc[0] * v1.y + v2.y * dc[1];
  ro->v2.z = dc[0] * v1.z + v2.z * dc[1];
  ro->v0 = ri->v0;
}

static inline void ksl_product_drdrxinvf(const ksl_mat3x3f_t* KSL_RESTRICT ri,
                                         const float dc[2],
                                         ksl_mat3x3f_t* KSL_RESTRICT ro) {
  const ksl_vec3f_t v1 = ri->v1, v2 = ri->v2;
  ro->v1.x = dc[1] * v1.x + v2.x * -dc[0];
  ro->v1.y = dc[1] * v1.y + v2.y * -dc[0];
  ro->v1.z = dc[1] * v1.z + v2.z * -dc[0];
  ro->v2.x = dc[0] * v1.x + v2.x * dc[1];
  ro->v2.y = dc[0] * v1.y + v2.y * dc[1];
  ro->v2.z = dc[0] * v1.z + v2.z * dc[1];
  ro->v0 = ri->v0;
}

static inline void ksl_product_drdry(const ksl_mat3x3_t* KSL_RESTRICT ri,
                                     const double dc[2],
                                     ksl_mat3x3_t* KSL_RESTRICT ro) {
  const ksl_vec3_t v0 = ri->v0, v2 = ri->v2;
  ro->v0.x = dc[1] * v0.x + v2.x * -dc[0];
  ro->v0.y = dc[1] * v0.y + v2.y * -dc[0];
  ro->v0.z = dc[1] * v0.z + v2.z * -dc[0];
  ro->v2.x = dc[0] * v0.x + v2.x * dc[1];
  ro->v2.y = dc[0] * v0.y + v2.y * dc[1];
  ro->v2.z = dc[0] * v0.z + v2.z * dc[1];
  ro->v1 = ri->v1;
}

static inline void ksl_product_drdryf(const ksl_mat3x3f_t* KSL_RESTRICT ri,
                                      const float dc[2],
                                      ksl_mat3x3f_t* KSL_RESTRICT ro) {
  const ksl_vec3f_t v0 = ri->v0, v2 = ri->v2;
  ro->v0.x = dc[1] * v0.x + v2.x * -dc[0];
  ro->v0.y = dc[1] * v0.y + v2.y * -dc[0];
  ro->v0.z = dc[1] * v0.z + v2.z * -dc[0];
  ro->v2.x = dc[0] * v0.x + v2.x * dc[1];
  ro->v2.y = dc[0] * v0.y + v2.y * dc[1];
  ro->v2.z = dc[0] * v0.z + v2.z * dc[1];
  ro->v1 = ri->v1;
}

static inline void ksl_product_drdryinv(const ksl_mat3x3_t* KSL_RESTRICT ri,
                                        const double dc[2],
                                        ksl_mat3x3_t* KSL_RESTRICT ro) {
  const ksl_vec3_t v0 = ri->v0, v2 = ri->v2;
  ro->v0.x = dc[1] * v0.x + v2.x * dc[0];
  ro->v0.y = dc[1] * v0.y + v2.y * dc[0];
  ro->v0.z = dc[1] * v0.z + v2.z * dc[0];
  ro->v2.x = -dc[0] * v0.x + v2.x * dc[1];
  ro->v2.y = -dc[0] * v0.y + v2.y * dc[1];
  ro->v2.z = -dc[0] * v0.z + v2.z * dc[1];
  ro->v1 = ri->v1;
}

static inline void ksl_product_drdryinvf(const ksl_mat3x3f_t* KSL_RESTRICT ri,
                                         const float dc[2],
                                         ksl_mat3x3f_t* KSL_RESTRICT ro) {
  const ksl_vec3f_t v0 = ri->v0, v2 = ri->v2;
  ro->v0.x = dc[1] * v0.x + v2.x * dc[0];
  ro->v0.y = dc[1] * v0.y + v2.y * dc[0];
  ro->v0.z = dc[1] * v0.z + v2.z * dc[0];
  ro->v2.x = -dc[0] * v0.x + v2.x * dc[1];
  ro->v2.y = -dc[0] * v0.y + v2.y * dc[1];
  ro->v2.z = -dc[0] * v0.z + v2.z * dc[1];
  ro->v1 = ri->v1;
}

static inline void ksl_product_drdrz(const ksl_mat3x3_t* KSL_RESTRICT ri,
                                     const double dc[2],
                                     ksl_mat3x3_t* KSL_RESTRICT ro) {
  const ksl_vec3_t v0 = ri->v0, v1 = ri->v1;
  ro->v0.x = dc[1] * v0.x + v1.x * dc[0];
  ro->v0.y = dc[1] * v0.y + v1.y * dc[0];
  ro->v0.z = dc[1] * v0.z + v1.z * dc[0];
  ro->v1.x = -dc[0] * v0.x + v1.x * dc[1];
  ro->v1.y = -dc[0] * v0.y + v1.y * dc[1];
  ro->v1.z = -dc[0] * v0.z + v1.z * dc[1];
  ro->v2 = ri->v2;
}

static inline void ksl_product_drdrzf(const ksl_mat3x3f_t* KSL_RESTRICT ri,
                                      const float dc[2],
                                      ksl_mat3x3f_t* KSL_RESTRICT ro) {
  const ksl_vec3f_t v0 = ri->v0, v1 = ri->v1;
  ro->v0.x = dc[1] * v0.x + v1.x * dc[0];
  ro->v0.y = dc[1] * v0.y + v1.y * dc[0];
  ro->v0.z = dc[1] * v0.z + v1.z * dc[0];
  ro->v1.x = -dc[0] * v0.x + v1.x * dc[1];
  ro->v1.y = -dc[0] * v0.y + v1.y * dc[1];
  ro->v1.z = -dc[0] * v0.z + v1.z * dc[1];
  ro->v2 = ri->v2;
}

static inline void ksl_product_drdrzinv(const ksl_mat3x3_t* KSL_RESTRICT ri,
                                        const double dc[2],
                                        ksl_mat3x3_t* KSL_RESTRICT ro) {
  const ksl_vec3_t v0 = ri->v0, v1 = ri->v1;
  ro->v0.x = dc[1] * v0.x + v1.x * -dc[0];
  ro->v0.y = dc[1] * v0.y + v1.y * -dc[0];
  ro->v0.z = dc[1] * v0.z + v1.z * -dc[0];
  ro->v1.x = dc[0] * v0.x + v1.x * dc[1];
  ro->v1.y = dc[0] * v0.y + v1.y * dc[1];
  ro->v1.z = dc[0] * v0.z + v1.z * dc[1];
  ro->v2 = ri->v2;
}

static inline void ksl_product_drdrzinvf(const ksl_mat3x3f_t* KSL_RESTRICT ri,
                                         const float dc[2],
                                         ksl_mat3x3f_t* KSL_RESTRICT ro) {
  const ksl_vec3f_t v0 = ri->v0, v1 = ri->v1;
  ro->v0.x = dc[1] * v0.x + v1.x * -dc[0];
  ro->v0.y = dc[1] * v0.y + v1.y * -dc[0];
  ro->v0.z = dc[1] * v0.z + v1.z * -dc[0];
  ro->v1.x = dc[0] * v0.x + v1.x * dc[1];
  ro->v1.y = dc[0] * v0.y + v1.y * dc[1];
  ro->v1.z = dc[0] * v0.z + v1.z * dc[1];
  ro->v2 = ri->v2;
}

static inline void ksl_product_drdr(const ksl_mat3x3_t* KSL_RESTRICT r1i,
                                    const ksl_mat3x3_t* KSL_RESTRICT r2i,
                                    ksl_mat3x3_t* KSL_RESTRICT ro) {
  ro->m00 = r1i->m00 * r2i->m00 + r1i->m01 * r2i->m10 + r1i->m02 * r2i->m20;
  ro->m01 = r1i->m00 * r2i->m01 + r1i->m01 * r2i->m11 + r1i->m02 * r2i->m21;
  ro->m02 = r1i->m00 * r2i->m02 + r1i->m01 * r2i->m12 + r1i->m02 * r2i->m22;
  ro->m10 = r1i->m10 * r2i->m00 + r1i->m11 * r2i->m10 + r1i->m12 * r2i->m20;
  ro->m11 = r1i->m10 * r2i->m01 + r1i->m11 * r2i->m11 + r1i->m12 * r2i->m21;
  ro->m12 = r1i->m10 * r2i->m02 + r1i->m11 * r2i->m12 + r1i->m12 * r2i->m22;
  ro->m20 = r1i->m20 * r2i->m00 + r1i->m21 * r2i->m10 + r1i->m22 * r2i->m20;
  ro->m21 = r1i->m20 * r2i->m01 + r1i->m21 * r2i->m11 + r1i->m22 * r2i->m21;
  ro->m22 = r1i->m20 * r2i->m02 + r1i->m21 * r2i->m12 + r1i->m22 * r2i->m22;
}

static inline void ksl_product_drdrf(const ksl_mat3x3f_t* KSL_RESTRICT r1i,
                                     const ksl_mat3x3f_t* KSL_RESTRICT r2i,
                                     ksl_mat3x3f_t* KSL_RESTRICT ro) {
  ro->m00 = r1i->m00 * r2i->m00 + r1i->m01 * r2i->m10 + r1i->m02 * r2i->m20;
  ro->m01 = r1i->m00 * r2i->m01 + r1i->m01 * r2i->m11 + r1i->m02 * r2i->m21;
  ro->m02 = r1i->m00 * r2i->m02 + r1i->m01 * r2i->m12 + r1i->m02 * r2i->m22;
  ro->m10 = r1i->m10 * r2i->m00 + r1i->m11 * r2i->m10 + r1i->m12 * r2i->m20;
  ro->m11 = r1i->m10 * r2i->m01 + r1i->m11 * r2i->m11 + r1i->m12 * r2i->m21;
  ro->m12 = r1i->m10 * r2i->m02 + r1i->m11 * r2i->m12 + r1i->m12 * r2i->m22;
  ro->m20 = r1i->m20 * r2i->m00 + r1i->m21 * r2i->m10 + r1i->m22 * r2i->m20;
  ro->m21 = r1i->m20 * r2i->m01 + r1i->m21 * r2i->m11 + r1i->m22 * r2i->m21;
  ro->m22 = r1i->m20 * r2i->m02 + r1i->m21 * r2i->m12 + r1i->m22 * r2i->m22;
}

static inline void ksl_product_drdrinv(const ksl_mat3x3_t* KSL_RESTRICT r1i,
                                       const ksl_mat3x3_t* KSL_RESTRICT r2i,
                                       ksl_mat3x3_t* KSL_RESTRICT ro) {
  /* ro[i][j] = sum_k r1i[i][k] * r2i[j][k] */
  ro->m00 = r1i->m00 * r2i->m00 + r1i->m01 * r2i->m01 + r1i->m02 * r2i->m02;
  ro->m01 = r1i->m00 * r2i->m10 + r1i->m01 * r2i->m11 + r1i->m02 * r2i->m12;
  ro->m02 = r1i->m00 * r2i->m20 + r1i->m01 * r2i->m21 + r1i->m02 * r2i->m22;
  ro->m10 = r1i->m10 * r2i->m00 + r1i->m11 * r2i->m01 + r1i->m12 * r2i->m02;
  ro->m11 = r1i->m10 * r2i->m10 + r1i->m11 * r2i->m11 + r1i->m12 * r2i->m12;
  ro->m12 = r1i->m10 * r2i->m20 + r1i->m11 * r2i->m21 + r1i->m12 * r2i->m22;
  ro->m20 = r1i->m20 * r2i->m00 + r1i->m21 * r2i->m01 + r1i->m22 * r2i->m02;
  ro->m21 = r1i->m20 * r2i->m10 + r1i->m21 * r2i->m11 + r1i->m22 * r2i->m12;
  ro->m22 = r1i->m20 * r2i->m20 + r1i->m21 * r2i->m21 + r1i->m22 * r2i->m22;
}

static inline void ksl_product_drdrinvf(const ksl_mat3x3f_t* KSL_RESTRICT r1i,
                                        const ksl_mat3x3f_t* KSL_RESTRICT r2i,
                                        ksl_mat3x3f_t* KSL_RESTRICT ro) {
  /* ro[i][j] = sum_k r1i[i][k] * r2i[j][k] */
  ro->m00 = r1i->m00 * r2i->m00 + r1i->m01 * r2i->m01 + r1i->m02 * r2i->m02;
  ro->m01 = r1i->m00 * r2i->m10 + r1i->m01 * r2i->m11 + r1i->m02 * r2i->m12;
  ro->m02 = r1i->m00 * r2i->m20 + r1i->m01 * r2i->m21 + r1i->m02 * r2i->m22;
  ro->m10 = r1i->m10 * r2i->m00 + r1i->m11 * r2i->m01 + r1i->m12 * r2i->m02;
  ro->m11 = r1i->m10 * r2i->m10 + r1i->m11 * r2i->m11 + r1i->m12 * r2i->m12;
  ro->m12 = r1i->m10 * r2i->m20 + r1i->m11 * r2i->m21 + r1i->m12 * r2i->m22;
  ro->m20 = r1i->m20 * r2i->m00 + r1i->m21 * r2i->m01 + r1i->m22 * r2i->m02;
  ro->m21 = r1i->m20 * r2i->m10 + r1i->m21 * r2i->m11 + r1i->m22 * r2i->m12;
  ro->m22 = r1i->m20 * r2i->m20 + r1i->m21 * r2i->m21 + r1i->m22 * r2i->m22;
}

static inline void ksl_product_drinvdr(const ksl_mat3x3_t* KSL_RESTRICT r1i,
                                       const ksl_mat3x3_t* KSL_RESTRICT r2i,
                                       ksl_mat3x3_t* KSL_RESTRICT ro) {
  ro->m00 = ksl_dot_vv(&r1i->v0, &r2i->v0);
  ro->m01 = ksl_dot_vv(&r1i->v0, &r2i->v1);
  ro->m02 = ksl_dot_vv(&r1i->v0, &r2i->v2);
  ro->m10 = ksl_dot_vv(&r1i->v1, &r2i->v0);
  ro->m11 = ksl_dot_vv(&r1i->v1, &r2i->v1);
  ro->m12 = ksl_dot_vv(&r1i->v1, &r2i->v2);
  ro->m20 = ksl_dot_vv(&r1i->v2, &r2i->v0);
  ro->m21 = ksl_dot_vv(&r1i->v2, &r2i->v1);
  ro->m22 = ksl_dot_vv(&r1i->v2, &r2i->v2);
}

static inline void ksl_product_drinvdrf(const ksl_mat3x3f_t* KSL_RESTRICT r1i,
                                        const ksl_mat3x3f_t* KSL_RESTRICT r2i,
                                        ksl_mat3x3f_t* KSL_RESTRICT ro) {
  ro->m00 = ksl_dot_vvf(&r1i->v0, &r2i->v0);
  ro->m01 = ksl_dot_vvf(&r1i->v0, &r2i->v1);
  ro->m02 = ksl_dot_vvf(&r1i->v0, &r2i->v2);
  ro->m10 = ksl_dot_vvf(&r1i->v1, &r2i->v0);
  ro->m11 = ksl_dot_vvf(&r1i->v1, &r2i->v1);
  ro->m12 = ksl_dot_vvf(&r1i->v1, &r2i->v2);
  ro->m20 = ksl_dot_vvf(&r1i->v2, &r2i->v0);
  ro->m21 = ksl_dot_vvf(&r1i->v2, &r2i->v1);
  ro->m22 = ksl_dot_vvf(&r1i->v2, &r2i->v2);
}

static inline void ksl_product_dv(const ksl_SE3_t* KSL_RESTRICT Di,
                                  const ksl_vec3_t* KSL_RESTRICT vi,
                                  ksl_vec3_t* KSL_RESTRICT vo) {
  const double x = vi->x, y = vi->y, z = vi->z;
  const ksl_mat3x3_t* r = &Di->R;
  vo->x = x * r->v0.x + y * r->v1.x + z * r->v2.x + Di->t.x;
  vo->y = x * r->v0.y + y * r->v1.y + z * r->v2.y + Di->t.y;
  vo->z = x * r->v0.z + y * r->v1.z + z * r->v2.z + Di->t.z;
}

static inline void ksl_product_dvf(const ksl_SE3f_t* KSL_RESTRICT Di,
                                   const ksl_vec3f_t* KSL_RESTRICT vi,
                                   ksl_vec3f_t* KSL_RESTRICT vo) {
  const float x = vi->x, y = vi->y, z = vi->z;
  const ksl_mat3x3f_t* r = &Di->R;
  vo->x = x * r->v0.x + y * r->v1.x + z * r->v2.x + Di->t.x;
  vo->y = x * r->v0.y + y * r->v1.y + z * r->v2.y + Di->t.y;
  vo->z = x * r->v0.z + y * r->v1.z + z * r->v2.z + Di->t.z;
}

static inline void ksl_product_dinvv(const ksl_SE3_t* KSL_RESTRICT Di,
                                     const ksl_vec3_t* KSL_RESTRICT vi,
                                     ksl_vec3_t* KSL_RESTRICT vo) {
  const double x = vi->x - Di->t.x, y = vi->y - Di->t.y, z = vi->z - Di->t.z;
  const ksl_mat3x3_t* r = &Di->R;
  vo->x = r->v0.x * x + r->v0.y * y + r->v0.z * z;
  vo->y = r->v1.x * x + r->v1.y * y + r->v1.z * z;
  vo->z = r->v2.x * x + r->v2.y * y + r->v2.z * z;
}

static inline void ksl_product_dinvvf(const ksl_SE3f_t* KSL_RESTRICT Di,
                                      const ksl_vec3f_t* KSL_RESTRICT vi,
                                      ksl_vec3f_t* KSL_RESTRICT vo) {
  const float x = vi->x - Di->t.x, y = vi->y - Di->t.y, z = vi->z - Di->t.z;
  const ksl_mat3x3f_t* r = &Di->R;
  vo->x = r->v0.x * x + r->v0.y * y + r->v0.z * z;
  vo->y = r->v1.x * x + r->v1.y * y + r->v1.z * z;
  vo->z = r->v2.x * x + r->v2.y * y + r->v2.z * z;
}

static inline void ksl_product_ddrx(const ksl_SE3_t* KSL_RESTRICT Di,
                                    const double dc[2],
                                    ksl_SE3_t* KSL_RESTRICT Do) {
  ksl_product_drdrx(&Di->R, dc, &Do->R);
  ksl_vec3_copy(&Di->t, &Do->t);
}

static inline void ksl_product_ddrxf(const ksl_SE3f_t* KSL_RESTRICT Di,
                                     const float dc[2],
                                     ksl_SE3f_t* KSL_RESTRICT Do) {
  ksl_product_drdrxf(&Di->R, dc, &Do->R);
  ksl_vec3f_copy(&Di->t, &Do->t);
}

static inline void ksl_product_ddrxinv(const ksl_SE3_t* KSL_RESTRICT Di,
                                       const double dc[2],
                                       ksl_SE3_t* KSL_RESTRICT Do) {
  ksl_product_drdrxinv(&Di->R, dc, &Do->R);
  ksl_vec3_copy(&Di->t, &Do->t);
}

static inline void ksl_product_ddrxinvf(const ksl_SE3f_t* KSL_RESTRICT Di,
                                        const float dc[2],
                                        ksl_SE3f_t* KSL_RESTRICT Do) {
  ksl_product_drdrxinvf(&Di->R, dc, &Do->R);
  ksl_vec3f_copy(&Di->t, &Do->t);
}

static inline void ksl_product_ddry(const ksl_SE3_t* KSL_RESTRICT Di,
                                    const double dc[2],
                                    ksl_SE3_t* KSL_RESTRICT Do) {
  ksl_product_drdry(&Di->R, dc, &Do->R);
  ksl_vec3_copy(&Di->t, &Do->t);
}

static inline void ksl_product_ddryf(const ksl_SE3f_t* KSL_RESTRICT Di,
                                     const float dc[2],
                                     ksl_SE3f_t* KSL_RESTRICT Do) {
  ksl_product_drdryf(&Di->R, dc, &Do->R);
  ksl_vec3f_copy(&Di->t, &Do->t);
}

static inline void ksl_product_ddryinv(const ksl_SE3_t* KSL_RESTRICT Di,
                                       const double dc[2],
                                       ksl_SE3_t* KSL_RESTRICT Do) {
  ksl_product_drdryinv(&Di->R, dc, &Do->R);
  ksl_vec3_copy(&Di->t, &Do->t);
}

static inline void ksl_product_ddryinvf(const ksl_SE3f_t* KSL_RESTRICT Di,
                                        const float dc[2],
                                        ksl_SE3f_t* KSL_RESTRICT Do) {
  ksl_product_drdryinvf(&Di->R, dc, &Do->R);
  ksl_vec3f_copy(&Di->t, &Do->t);
}

static inline void ksl_product_ddrz(const ksl_SE3_t* KSL_RESTRICT Di,
                                    const double dc[2],
                                    ksl_SE3_t* KSL_RESTRICT Do) {
  ksl_product_drdrz(&Di->R, dc, &Do->R);
  ksl_vec3_copy(&Di->t, &Do->t);
}

static inline void ksl_product_ddrzf(const ksl_SE3f_t* KSL_RESTRICT Di,
                                     const float dc[2],
                                     ksl_SE3f_t* KSL_RESTRICT Do) {
  ksl_product_drdrzf(&Di->R, dc, &Do->R);
  ksl_vec3f_copy(&Di->t, &Do->t);
}

static inline void ksl_product_ddrzinv(const ksl_SE3_t* KSL_RESTRICT Di,
                                       const double dc[2],
                                       ksl_SE3_t* KSL_RESTRICT Do) {
  ksl_product_drdrzinv(&Di->R, dc, &Do->R);
  ksl_vec3_copy(&Di->t, &Do->t);
}

static inline void ksl_product_ddrzinvf(const ksl_SE3f_t* KSL_RESTRICT Di,
                                        const float dc[2],
                                        ksl_SE3f_t* KSL_RESTRICT Do) {
  ksl_product_drdrzinvf(&Di->R, dc, &Do->R);
  ksl_vec3f_copy(&Di->t, &Do->t);
}

static inline void ksl_product_ddt(const ksl_SE3_t* KSL_RESTRICT Di,
                                   const ksl_vec3_t* KSL_RESTRICT t,
                                   ksl_SE3_t* KSL_RESTRICT Do) {
  const double x = t->x, y = t->y, z = t->z;
  const ksl_mat3x3_t r = Di->R;
  ksl_vec3_t to;
  to.x = x * r.v0.x + y * r.v1.x + z * r.v2.x + Di->t.x;
  to.y = x * r.v0.y + y * r.v1.y + z * r.v2.y + Di->t.y;
  to.z = x * r.v0.z + y * r.v1.z + z * r.v2.z + Di->t.z;
  Do->R = r;
  Do->t = to;
}

static inline void ksl_product_ddtf(const ksl_SE3f_t* KSL_RESTRICT Di,
                                    const ksl_vec3f_t* KSL_RESTRICT t,
                                    ksl_SE3f_t* KSL_RESTRICT Do) {
  const float x = t->x, y = t->y, z = t->z;
  const ksl_mat3x3f_t r = Di->R;
  ksl_vec3f_t to;
  to.x = x * r.v0.x + y * r.v1.x + z * r.v2.x + Di->t.x;
  to.y = x * r.v0.y + y * r.v1.y + z * r.v2.y + Di->t.y;
  to.z = x * r.v0.z + y * r.v1.z + z * r.v2.z + Di->t.z;
  Do->R = r;
  Do->t = to;
}

static inline void ksl_product_ddtinv(const ksl_SE3_t* KSL_RESTRICT Di,
                                      const ksl_vec3_t* KSL_RESTRICT t,
                                      ksl_SE3_t* KSL_RESTRICT Do) {
  const double x = -t->x, y = -t->y, z = -t->z;
  const ksl_mat3x3_t r = Di->R;
  ksl_vec3_t to;
  to.x = x * r.v0.x + y * r.v1.x + z * r.v2.x + Di->t.x;
  to.y = x * r.v0.y + y * r.v1.y + z * r.v2.y + Di->t.y;
  to.z = x * r.v0.z + y * r.v1.z + z * r.v2.z + Di->t.z;
  Do->R = r;
  Do->t = to;
}

static inline void ksl_product_ddtinvf(const ksl_SE3f_t* KSL_RESTRICT Di,
                                       const ksl_vec3f_t* KSL_RESTRICT t,
                                       ksl_SE3f_t* KSL_RESTRICT Do) {
  const float x = -t->x, y = -t->y, z = -t->z;
  const ksl_mat3x3f_t r = Di->R;
  ksl_vec3f_t to;
  to.x = x * r.v0.x + y * r.v1.x + z * r.v2.x + Di->t.x;
  to.y = x * r.v0.y + y * r.v1.y + z * r.v2.y + Di->t.y;
  to.z = x * r.v0.z + y * r.v1.z + z * r.v2.z + Di->t.z;
  Do->R = r;
  Do->t = to;
}

static inline void ksl_product_dinvdt(const ksl_SE3_t* KSL_RESTRICT Di,
                                      const ksl_vec3_t* KSL_RESTRICT t,
                                      ksl_SE3_t* KSL_RESTRICT Do) {
  ksl_vec3_t temp;
  ksl_subtract_vv(t, &Di->t, &temp);
  ksl_mat3x3_transposed(&Di->R, &Do->R);
  ksl_product_drinvv(&Di->R, &temp, &Do->t);
}

static inline void ksl_product_dinvdtf(const ksl_SE3f_t* KSL_RESTRICT Di,
                                       const ksl_vec3f_t* KSL_RESTRICT t,
                                       ksl_SE3f_t* KSL_RESTRICT Do) {
  ksl_vec3f_t temp;
  ksl_subtract_vvf(t, &Di->t, &temp);
  ksl_mat3x3f_transposed(&Di->R, &Do->R);
  ksl_product_drinvvf(&Di->R, &temp, &Do->t);
}

static inline void ksl_product_ddtx(const ksl_SE3_t* KSL_RESTRICT Di,
                                    const double ti,
                                    ksl_SE3_t* KSL_RESTRICT Do) {
  const double a = ti;
  const ksl_mat3x3_t r = Di->R;
  ksl_vec3_t to;
  to.x = a * r.v0.x + Di->t.x;
  to.y = a * r.v0.y + Di->t.y;
  to.z = a * r.v0.z + Di->t.z;
  Do->R = r;
  Do->t = to;
}

static inline void ksl_product_ddtxf(const ksl_SE3f_t* KSL_RESTRICT Di,
                                     const float ti,
                                     ksl_SE3f_t* KSL_RESTRICT Do) {
  const float a = ti;
  const ksl_mat3x3f_t r = Di->R;
  ksl_vec3f_t to;
  to.x = a * r.v0.x + Di->t.x;
  to.y = a * r.v0.y + Di->t.y;
  to.z = a * r.v0.z + Di->t.z;
  Do->R = r;
  Do->t = to;
}

static inline void ksl_product_ddtxinv(const ksl_SE3_t* KSL_RESTRICT Di,
                                       const double ti,
                                       ksl_SE3_t* KSL_RESTRICT Do) {
  const double a = -ti;
  const ksl_mat3x3_t r = Di->R;
  ksl_vec3_t to;
  to.x = a * r.v0.x + Di->t.x;
  to.y = a * r.v0.y + Di->t.y;
  to.z = a * r.v0.z + Di->t.z;
  Do->R = r;
  Do->t = to;
}

static inline void ksl_product_ddtxinvf(const ksl_SE3f_t* KSL_RESTRICT Di,
                                        const float ti,
                                        ksl_SE3f_t* KSL_RESTRICT Do) {
  const float a = -ti;
  const ksl_mat3x3f_t r = Di->R;
  ksl_vec3f_t to;
  to.x = a * r.v0.x + Di->t.x;
  to.y = a * r.v0.y + Di->t.y;
  to.z = a * r.v0.z + Di->t.z;
  Do->R = r;
  Do->t = to;
}

static inline void ksl_product_ddty(const ksl_SE3_t* KSL_RESTRICT Di,
                                    const double ti,
                                    ksl_SE3_t* KSL_RESTRICT Do) {
  const double a = ti;
  const ksl_mat3x3_t r = Di->R;
  ksl_vec3_t to;
  to.x = a * r.v1.x + Di->t.x;
  to.y = a * r.v1.y + Di->t.y;
  to.z = a * r.v1.z + Di->t.z;
  Do->R = r;
  Do->t = to;
}

static inline void ksl_product_ddtyf(const ksl_SE3f_t* KSL_RESTRICT Di,
                                     const float ti,
                                     ksl_SE3f_t* KSL_RESTRICT Do) {
  const float a = ti;
  const ksl_mat3x3f_t r = Di->R;
  ksl_vec3f_t to;
  to.x = a * r.v1.x + Di->t.x;
  to.y = a * r.v1.y + Di->t.y;
  to.z = a * r.v1.z + Di->t.z;
  Do->R = r;
  Do->t = to;
}

static inline void ksl_product_ddtyinv(const ksl_SE3_t* KSL_RESTRICT Di,
                                       const double ti,
                                       ksl_SE3_t* KSL_RESTRICT Do) {
  const double a = -ti;
  const ksl_mat3x3_t r = Di->R;
  ksl_vec3_t to;
  to.x = a * r.v1.x + Di->t.x;
  to.y = a * r.v1.y + Di->t.y;
  to.z = a * r.v1.z + Di->t.z;
  Do->R = r;
  Do->t = to;
}

static inline void ksl_product_ddtyinvf(const ksl_SE3f_t* KSL_RESTRICT Di,
                                        const float ti,
                                        ksl_SE3f_t* KSL_RESTRICT Do) {
  const float a = -ti;
  const ksl_mat3x3f_t r = Di->R;
  ksl_vec3f_t to;
  to.x = a * r.v1.x + Di->t.x;
  to.y = a * r.v1.y + Di->t.y;
  to.z = a * r.v1.z + Di->t.z;
  Do->R = r;
  Do->t = to;
}

static inline void ksl_product_ddtz(const ksl_SE3_t* KSL_RESTRICT Di,
                                    const double ti,
                                    ksl_SE3_t* KSL_RESTRICT Do) {
  const double a = ti;
  const ksl_mat3x3_t r = Di->R;
  ksl_vec3_t to;
  to.x = a * r.v2.x + Di->t.x;
  to.y = a * r.v2.y + Di->t.y;
  to.z = a * r.v2.z + Di->t.z;
  Do->R = r;
  Do->t = to;
}

static inline void ksl_product_ddtzf(const ksl_SE3f_t* KSL_RESTRICT Di,
                                     const float ti,
                                     ksl_SE3f_t* KSL_RESTRICT Do) {
  const float a = ti;
  const ksl_mat3x3f_t r = Di->R;
  ksl_vec3f_t to;
  to.x = a * r.v2.x + Di->t.x;
  to.y = a * r.v2.y + Di->t.y;
  to.z = a * r.v2.z + Di->t.z;
  Do->R = r;
  Do->t = to;
}

static inline void ksl_product_ddtzinv(const ksl_SE3_t* KSL_RESTRICT Di,
                                       const double ti,
                                       ksl_SE3_t* KSL_RESTRICT Do) {
  const double a = -ti;
  const ksl_mat3x3_t r = Di->R;
  ksl_vec3_t to;
  to.x = a * r.v2.x + Di->t.x;
  to.y = a * r.v2.y + Di->t.y;
  to.z = a * r.v2.z + Di->t.z;
  Do->R = r;
  Do->t = to;
}

static inline void ksl_product_ddtzinvf(const ksl_SE3f_t* KSL_RESTRICT Di,
                                        const float ti,
                                        ksl_SE3f_t* KSL_RESTRICT Do) {
  const float a = -ti;
  const ksl_mat3x3f_t r = Di->R;
  ksl_vec3f_t to;
  to.x = a * r.v2.x + Di->t.x;
  to.y = a * r.v2.y + Di->t.y;
  to.z = a * r.v2.z + Di->t.z;
  Do->R = r;
  Do->t = to;
}

static inline void ksl_product_ddr(const ksl_SE3_t* KSL_RESTRICT Di,
                                   const ksl_mat3x3_t* KSL_RESTRICT Ri,
                                   ksl_SE3_t* KSL_RESTRICT Do) {
  ksl_product_drdr(&Di->R, Ri, &Do->R);
  ksl_vec3_copy(&Di->t, &Do->t);
}

static inline void ksl_product_ddrf(const ksl_SE3f_t* KSL_RESTRICT Di,
                                    const ksl_mat3x3f_t* KSL_RESTRICT Ri,
                                    ksl_SE3f_t* KSL_RESTRICT Do) {
  ksl_product_drdrf(&Di->R, Ri, &Do->R);
  ksl_vec3f_copy(&Di->t, &Do->t);
}

static inline void ksl_product_ddrinv(const ksl_SE3_t* KSL_RESTRICT Di,
                                      const ksl_mat3x3_t* KSL_RESTRICT Ri,
                                      ksl_SE3_t* KSL_RESTRICT Do) {
  ksl_product_drdrinv(&Di->R, Ri, &Do->R);
  ksl_vec3_copy(&Di->t, &Do->t);
}

static inline void ksl_product_ddrinvf(const ksl_SE3f_t* KSL_RESTRICT Di,
                                       const ksl_mat3x3f_t* KSL_RESTRICT Ri,
                                       ksl_SE3f_t* KSL_RESTRICT Do) {
  ksl_product_drdrinvf(&Di->R, Ri, &Do->R);
  ksl_vec3f_copy(&Di->t, &Do->t);
}

static inline void ksl_product_dd(const ksl_SE3_t* KSL_RESTRICT D1i,
                                  const ksl_SE3_t* KSL_RESTRICT D2i,
                                  ksl_SE3_t* KSL_RESTRICT Do) {
  const double x = D2i->t.x, y = D2i->t.y, z = D2i->t.z;
  const ksl_mat3x3_t* r = &D1i->R;
  ksl_vec3_t to;
  to.x = x * r->v0.x + y * r->v1.x + z * r->v2.x + D1i->t.x;
  to.y = x * r->v0.y + y * r->v1.y + z * r->v2.y + D1i->t.y;
  to.z = x * r->v0.z + y * r->v1.z + z * r->v2.z + D1i->t.z;
  ksl_mat3x3_t ro;
  ksl_product_drdr(&D1i->R, &D2i->R, &ro);
  Do->R = ro;
  Do->t = to;
}

static inline void ksl_product_ddf(const ksl_SE3f_t* KSL_RESTRICT D1i,
                                   const ksl_SE3f_t* KSL_RESTRICT D2i,
                                   ksl_SE3f_t* KSL_RESTRICT Do) {
  const float x = D2i->t.x, y = D2i->t.y, z = D2i->t.z;
  const ksl_mat3x3f_t* r = &D1i->R;
  ksl_vec3f_t to;
  to.x = x * r->v0.x + y * r->v1.x + z * r->v2.x + D1i->t.x;
  to.y = x * r->v0.y + y * r->v1.y + z * r->v2.y + D1i->t.y;
  to.z = x * r->v0.z + y * r->v1.z + z * r->v2.z + D1i->t.z;
  ksl_mat3x3f_t ro;
  ksl_product_drdrf(&D1i->R, &D2i->R, &ro);
  Do->R = ro;
  Do->t = to;
}

static inline void ksl_product_ddinv(const ksl_SE3_t* KSL_RESTRICT D1i,
                                     const ksl_SE3_t* KSL_RESTRICT D2i,
                                     ksl_SE3_t* KSL_RESTRICT Do) {
  ksl_mat3x3_t r;
  ksl_product_drdrinv(&D1i->R, &D2i->R, &r);
  const double x = -D2i->t.x, y = -D2i->t.y, z = -D2i->t.z;
  ksl_vec3_t to;
  to.x = x * r.v0.x + y * r.v1.x + z * r.v2.x + D1i->t.x;
  to.y = x * r.v0.y + y * r.v1.y + z * r.v2.y + D1i->t.y;
  to.z = x * r.v0.z + y * r.v1.z + z * r.v2.z + D1i->t.z;
  Do->R = r;
  Do->t = to;
}

static inline void ksl_product_ddinvf(const ksl_SE3f_t* D1i,
                                      const ksl_SE3f_t* D2i, ksl_SE3f_t* Do) {
  ksl_mat3x3f_t r;
  ksl_product_drdrinvf(&D1i->R, &D2i->R, &r);
  const float x = -D2i->t.x, y = -D2i->t.y, z = -D2i->t.z;
  ksl_vec3f_t to;
  to.x = x * r.v0.x + y * r.v1.x + z * r.v2.x + D1i->t.x;
  to.y = x * r.v0.y + y * r.v1.y + z * r.v2.y + D1i->t.y;
  to.z = x * r.v0.z + y * r.v1.z + z * r.v2.z + D1i->t.z;
  Do->R = r;
  Do->t = to;
}

static inline void ksl_product_dinvd(const ksl_SE3_t* KSL_RESTRICT D1i,
                                     const ksl_SE3_t* KSL_RESTRICT D2i,
                                     ksl_SE3_t* KSL_RESTRICT Do) {
  const ksl_mat3x3_t* r = &D1i->R;
  const double x = D2i->t.x - D1i->t.x, y = D2i->t.y - D1i->t.y,
               z = D2i->t.z - D1i->t.z;
  ksl_vec3_t to;
  to.x = r->v0.x * x + r->v0.y * y + r->v0.z * z;
  to.y = r->v1.x * x + r->v1.y * y + r->v1.z * z;
  to.z = r->v2.x * x + r->v2.y * y + r->v2.z * z;
  ksl_mat3x3_t ro;
  ksl_product_drinvdr(&D1i->R, &D2i->R, &ro);
  Do->R = ro;
  Do->t = to;
}

static inline void ksl_product_dinvdf(const ksl_SE3f_t* KSL_RESTRICT D1i,
                                      const ksl_SE3f_t* KSL_RESTRICT D2i,
                                      ksl_SE3f_t* KSL_RESTRICT Do) {
  const ksl_mat3x3f_t* r = &D1i->R;
  const float x = D2i->t.x - D1i->t.x, y = D2i->t.y - D1i->t.y,
              z = D2i->t.z - D1i->t.z;
  ksl_vec3f_t to;
  to.x = r->v0.x * x + r->v0.y * y + r->v0.z * z;
  to.y = r->v1.x * x + r->v1.y * y + r->v1.z * z;
  to.z = r->v2.x * x + r->v2.y * y + r->v2.z * z;
  ksl_mat3x3f_t ro;
  ksl_product_drinvdrf(&D1i->R, &D2i->R, &ro);
  Do->R = ro;
  Do->t = to;
}

#ifdef __cplusplus
}
#endif

#endif
