/**
@file
@author Kristopher Wehage, Roger Wehage
@brief Utilities to initialize and operate on mat3x3 and ma4x4 matrices
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

@param r_oi [in] input 3x3 matrix
@param v_i [in] input vector
@param v_o [out] result returned in v_o
*/
static inline void ksl_product_drvinv(const ksl_mat3x3_t* ri,
                                      const ksl_vec3_t* vi, ksl_vec3_t* vo);

/*!
@brief TODO document this function
*/
static inline void ksl_product_drvinvf(const ksl_mat3x3f_t* ri,
                                       const ksl_vec3f_t* vi, ksl_vec3f_t* vo);

/*!
@brief TODO document this function
*/
static inline void ksl_product_drinvv(const ksl_mat3x3_t* ri,
                                      const ksl_vec3_t* vi, ksl_vec3_t* vo);

/*!
@brief TODO document this function
*/
static inline void ksl_product_drinvvf(const ksl_mat3x3f_t* ri,
                                       const ksl_vec3f_t* vi, ksl_vec3f_t* vo);

/*!
@brief TODO document this function
*/
static inline void ksl_product_drinvvinv(const ksl_mat3x3_t* ri,
                                         const ksl_vec3_t* vi, ksl_vec3_t* vo);

/*!
@brief TODO document this function
*/
static inline void ksl_product_drinvvinvf(const ksl_mat3x3f_t* ri,
                                          const ksl_vec3f_t* vi,
                                          ksl_vec3f_t* vo);

/*!
@brief TODO document this function
*/
static inline void ksl_product_drvtx(const ksl_mat3x3_t* ri, const double ti,
                                     ksl_vec3_t* vo);

/*!
@brief TODO document this function
*/
static inline void ksl_product_drvtxf(const ksl_mat3x3f_t* ri, const float ti,
                                      ksl_vec3f_t* vo);

/*!
@brief TODO document this function
*/
static inline void ksl_product_drvtxinv(const ksl_mat3x3_t* ri, const double ti,
                                        ksl_vec3_t* vo);

/*!
@brief TODO document this function
*/
static inline void ksl_product_drvtxinvf(const ksl_mat3x3f_t* ri,
                                         const float ti, ksl_vec3f_t* vo);

/*!
@brief TODO document this function
*/
static inline void ksl_product_drvty(const ksl_mat3x3_t* ri, const double ti,
                                     ksl_vec3_t* vo);

/*!
@brief TODO document this function
*/
static inline void ksl_product_drvtyf(const ksl_mat3x3f_t* ri, const float ti,
                                      ksl_vec3f_t* vo);

/*!
@brief TODO document this function
*/
static inline void ksl_product_drvtyinv(const ksl_mat3x3_t* ri, const double ti,
                                        ksl_vec3_t* vo);

/*!
@brief TODO document this function
*/
static inline void ksl_product_drvtyinvf(const ksl_mat3x3f_t* ri,
                                         const float ti, ksl_vec3f_t* vo);

/*!
@brief TODO document this function
*/
static inline void ksl_product_drvtz(const ksl_mat3x3_t* ri, const double ti,
                                     ksl_vec3_t* vo);

/*!
@brief TODO document this function
*/
static inline void ksl_product_drvtzf(const ksl_mat3x3f_t* ri, const float ti,
                                      ksl_vec3f_t* vo);

/*!
@brief TODO document this function
*/
static inline void ksl_product_drvtzinv(const ksl_mat3x3_t* ri, const double ti,
                                        ksl_vec3_t* vo);

/*!
@brief TODO document this function
*/
static inline void ksl_product_drvtzinvf(const ksl_mat3x3f_t* ri,
                                         const float ti, ksl_vec3f_t* vo);

/* matrix-matrix operations */

/*!
@brief TODO document this function
*/
static inline void ksl_product_drdrx(const ksl_mat3x3_t* ri, const double dc[2],
                                     ksl_mat3x3_t* ro);

/*!
@brief TODO document this function
*/
static inline void ksl_product_drdrxf(const ksl_mat3x3f_t* ri,
                                      const float dc[2], ksl_mat3x3f_t* ro);

/*!
@brief TODO document this function
*/
static inline void ksl_product_drdrxinv(const ksl_mat3x3_t* ri,
                                        const double dc[2], ksl_mat3x3_t* ro);

/*!
@brief TODO document this function
*/
static inline void ksl_product_drdrxinvf(const ksl_mat3x3f_t* ri,
                                         const float dc[2], ksl_mat3x3f_t* ro);

/*!
@brief TODO document this function
*/
static inline void ksl_product_drdry(const ksl_mat3x3_t* ri, const double dc[2],
                                     ksl_mat3x3_t* ro);

/*!
@brief TODO document this function
*/
static inline void ksl_product_drdryf(const ksl_mat3x3f_t* ri,
                                      const float dc[2], ksl_mat3x3f_t* ro);

/*!
@brief TODO document this function
*/
static inline void ksl_product_drdryinv(const ksl_mat3x3_t* ri,
                                        const double dc[2], ksl_mat3x3_t* ro);

/*!
@brief TODO document this function
*/
static inline void ksl_product_drdryinvf(const ksl_mat3x3f_t* ri,
                                         const float dc[2], ksl_mat3x3f_t* ro);

/*!
@brief TODO document this function
*/
static inline void ksl_product_drdrz(const ksl_mat3x3_t* ri, const double dc[2],
                                     ksl_mat3x3_t* ro);

/*!
@brief TODO document this function
*/
static inline void ksl_product_drdrzf(const ksl_mat3x3f_t* ri,
                                      const float dc[2], ksl_mat3x3f_t* ro);

/*!
@brief TODO document this function
*/
static inline void ksl_product_drdrzinv(const ksl_mat3x3_t* ri,
                                        const double dc[2], ksl_mat3x3_t* ro);

/*!
@brief TODO document this function
*/
static inline void ksl_product_drdrzinvf(const ksl_mat3x3f_t* ri,
                                         const float dc[2], ksl_mat3x3f_t* ro);

/*!
@brief TODO document this function
*/
static inline void ksl_product_drdr(const ksl_mat3x3_t* r1i,
                                    const ksl_mat3x3_t* r2i, ksl_mat3x3_t* ro);

/*!
@brief TODO document this function
*/
static inline void ksl_product_drdrf(const ksl_mat3x3f_t* r1i,
                                     const ksl_mat3x3f_t* r2i,
                                     ksl_mat3x3f_t* ro);

/*!
@brief TODO document this function
*/
static inline void ksl_product_drdrinv(const ksl_mat3x3_t* r1i,
                                       const ksl_mat3x3_t* r2i,
                                       ksl_mat3x3_t* ro);

/*!
@brief TODO document this function
*/
static inline void ksl_product_drdrinvf(const ksl_mat3x3f_t* r1i,
                                        const ksl_mat3x3f_t* r2i,
                                        ksl_mat3x3f_t* ro);

/*!
@brief TODO document this function
*/
static inline void ksl_product_drinvdr(const ksl_mat3x3_t* r1i,
                                       const ksl_mat3x3_t* r2i,
                                       ksl_mat3x3_t* ro);

/*!
@brief TODO document this function
*/
static inline void ksl_product_drinvdrf(const ksl_mat3x3f_t* r1i,
                                        const ksl_mat3x3f_t* r2i,
                                        ksl_mat3x3f_t* ro);

/*!
@brief TODO document this function
*/
static inline void ksl_product_dv(const ksl_SE3_t* Di, const ksl_vec3_t* vi,
                                  ksl_vec3_t* vo);

/*!
@brief TODO document this function
*/
static inline void ksl_product_dvf(const ksl_SE3f_t* Di, const ksl_vec3f_t* vi,
                                   ksl_vec3f_t* vo);

/*!
@brief TODO document this function
*/
static inline void ksl_product_dinvv(const ksl_SE3_t* Di, const ksl_vec3_t* vi,
                                     ksl_vec3_t* vo);

/*!
@brief TODO document this function
*/
static inline void ksl_product_dinvvf(const ksl_SE3f_t* Di,
                                      const ksl_vec3f_t* vi, ksl_vec3f_t* vo);

/*!
@brief TODO document this function
*/
static inline void ksl_product_ddrx(const ksl_SE3_t* Di, const double dc[2],
                                    ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_product_ddrxf(const ksl_SE3f_t* Di, const float dc[2],
                                     ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_product_ddrxinv(const ksl_SE3_t* Di, const double dc[2],
                                       ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_product_ddrxinvf(const ksl_SE3f_t* Di, const float dc[2],
                                        ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_product_ddry(const ksl_SE3_t* Di, const double dc[2],
                                    ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_product_ddryf(const ksl_SE3f_t* Di, const float dc[2],
                                     ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_product_ddryinv(const ksl_SE3_t* Di, const double dc[2],
                                       ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_product_ddryinvf(const ksl_SE3f_t* Di, const float dc[2],
                                        ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_product_ddrz(const ksl_SE3_t* Di, const double dc[2],
                                    ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_product_ddrzf(const ksl_SE3f_t* Di, const float dc[2],
                                     ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_product_ddrzinv(const ksl_SE3_t* Di, const double dc[2],
                                       ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_product_ddrzinvf(const ksl_SE3f_t* Di, const float dc[2],
                                        ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_product_ddt(const ksl_SE3_t* Di, const ksl_vec3_t* t,
                                   ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_product_ddtinv(const ksl_SE3_t* Di, const ksl_vec3_t* vi,
                                      ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_product_ddtinvf(const ksl_SE3f_t* Di,
                                       const ksl_vec3f_t* vi, ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_product_ddtf(const ksl_SE3f_t* Di, const ksl_vec3f_t* vi,
                                    ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_product_dinvdt(const ksl_SE3_t* Di, const ksl_vec3_t* vi,
                                      ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_product_dinvdtf(const ksl_SE3f_t* Di,
                                       const ksl_vec3f_t* vi, ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_product_ddtx(const ksl_SE3_t* Di, const double ti,
                                    ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_product_ddtxf(const ksl_SE3f_t* Di, const float ti,
                                     ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_product_ddtxinv(const ksl_SE3_t* Di, const double ti,
                                       ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_product_ddtxinvf(const ksl_SE3f_t* Di, const float ti,
                                        ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_product_ddty(const ksl_SE3_t* Di, const double ti,
                                    ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_product_ddtyf(const ksl_SE3f_t* Di, const float ti,
                                     ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_product_ddtyinv(const ksl_SE3_t* Di, const double ti,
                                       ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_product_ddtyinvf(const ksl_SE3f_t* Di, const float ti,
                                        ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_product_ddtz(const ksl_SE3_t* Di, const double ti,
                                    ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_product_ddtzf(const ksl_SE3f_t* Di, const float ti,
                                     ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_product_ddtzinv(const ksl_SE3_t* Di, const double ti,
                                       ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_product_ddtzinvf(const ksl_SE3f_t* Di, const float ti,
                                        ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_product_ddr(const ksl_SE3_t* Di, const ksl_mat3x3_t* Ri,
                                   ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_product_ddrf(const ksl_SE3f_t* Di,
                                    const ksl_mat3x3f_t* Ri, ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_product_ddrinv(const ksl_SE3_t* Di,
                                      const ksl_mat3x3_t* Ri, ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_product_ddrinvf(const ksl_SE3f_t* Di,
                                       const ksl_mat3x3f_t* Ri, ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_product_dd(const ksl_SE3_t* D1i, const ksl_SE3_t* D2i,
                                  ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_product_ddf(const ksl_SE3f_t* D1i, const ksl_SE3f_t* D2i,
                                   ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_product_ddinv(const ksl_SE3_t* D1i, const ksl_SE3_t* D2i,
                                     ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_product_ddinvf(const ksl_SE3f_t* D1i,
                                      const ksl_SE3f_t* D2i, ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_product_dinvd(const ksl_SE3_t* D1i, const ksl_SE3_t* D2i,
                                     ksl_SE3_t* Do);

/*!
@brief TODO document this function
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
  const ksl_mat3x3_t r = *ri;
  ro->v1.x = dc[1] * r.v1.x + r.v2.x * dc[0];
  ro->v1.y = dc[1] * r.v1.y + r.v2.y * dc[0];
  ro->v1.z = dc[1] * r.v1.z + r.v2.z * dc[0];
  ro->v2.x = -dc[0] * r.v1.x + r.v2.x * dc[1];
  ro->v2.y = -dc[0] * r.v1.y + r.v2.y * dc[1];
  ro->v2.z = -dc[0] * r.v1.z + r.v2.z * dc[1];
  ro->v0 = r.v0;
}

static inline void ksl_product_drdrxf(const ksl_mat3x3f_t* KSL_RESTRICT ri,
                                      const float dc[2],
                                      ksl_mat3x3f_t* KSL_RESTRICT ro) {
  const ksl_mat3x3f_t r = *ri;
  ro->v1.x = dc[1] * r.v1.x + r.v2.x * dc[0];
  ro->v1.y = dc[1] * r.v1.y + r.v2.y * dc[0];
  ro->v1.z = dc[1] * r.v1.z + r.v2.z * dc[0];
  ro->v2.x = -dc[0] * r.v1.x + r.v2.x * dc[1];
  ro->v2.y = -dc[0] * r.v1.y + r.v2.y * dc[1];
  ro->v2.z = -dc[0] * r.v1.z + r.v2.z * dc[1];
  ro->v0 = r.v0;
}

static inline void ksl_product_drdrxinv(const ksl_mat3x3_t* KSL_RESTRICT ri,
                                        const double dc[2],
                                        ksl_mat3x3_t* KSL_RESTRICT ro) {
  const ksl_mat3x3_t r = *ri;
  ro->v1.x = dc[1] * r.v1.x + r.v2.x * -dc[0];
  ro->v1.y = dc[1] * r.v1.y + r.v2.y * -dc[0];
  ro->v1.z = dc[1] * r.v1.z + r.v2.z * -dc[0];
  ro->v2.x = dc[0] * r.v1.x + r.v2.x * dc[1];
  ro->v2.y = dc[0] * r.v1.y + r.v2.y * dc[1];
  ro->v2.z = dc[0] * r.v1.z + r.v2.z * dc[1];
  ro->v0 = r.v0;
}

static inline void ksl_product_drdrxinvf(const ksl_mat3x3f_t* KSL_RESTRICT ri,
                                         const float dc[2],
                                         ksl_mat3x3f_t* KSL_RESTRICT ro) {
  const ksl_mat3x3f_t r = *ri;
  ro->v1.x = dc[1] * r.v1.x + r.v2.x * -dc[0];
  ro->v1.y = dc[1] * r.v1.y + r.v2.y * -dc[0];
  ro->v1.z = dc[1] * r.v1.z + r.v2.z * -dc[0];
  ro->v2.x = dc[0] * r.v1.x + r.v2.x * dc[1];
  ro->v2.y = dc[0] * r.v1.y + r.v2.y * dc[1];
  ro->v2.z = dc[0] * r.v1.z + r.v2.z * dc[1];
  ro->v0 = r.v0;
}

static inline void ksl_product_drdry(const ksl_mat3x3_t* KSL_RESTRICT ri,
                                     const double dc[2],
                                     ksl_mat3x3_t* KSL_RESTRICT ro) {
  const ksl_mat3x3_t r = *ri;
  ro->v0.x = dc[1] * r.v0.x + r.v2.x * -dc[0];
  ro->v0.y = dc[1] * r.v0.y + r.v2.y * -dc[0];
  ro->v0.z = dc[1] * r.v0.z + r.v2.z * -dc[0];
  ro->v2.x = dc[0] * r.v0.x + r.v2.x * dc[1];
  ro->v2.y = dc[0] * r.v0.y + r.v2.y * dc[1];
  ro->v2.z = dc[0] * r.v0.z + r.v2.z * dc[1];
  ro->v1 = r.v1;
}

static inline void ksl_product_drdryf(const ksl_mat3x3f_t* KSL_RESTRICT ri,
                                      const float dc[2],
                                      ksl_mat3x3f_t* KSL_RESTRICT ro) {
  const ksl_mat3x3f_t r = *ri;
  ro->v0.x = dc[1] * r.v0.x + r.v2.x * -dc[0];
  ro->v0.y = dc[1] * r.v0.y + r.v2.y * -dc[0];
  ro->v0.z = dc[1] * r.v0.z + r.v2.z * -dc[0];
  ro->v2.x = dc[0] * r.v0.x + r.v2.x * dc[1];
  ro->v2.y = dc[0] * r.v0.y + r.v2.y * dc[1];
  ro->v2.z = dc[0] * r.v0.z + r.v2.z * dc[1];
  ro->v1 = r.v1;
}

static inline void ksl_product_drdryinv(const ksl_mat3x3_t* KSL_RESTRICT ri,
                                        const double dc[2],
                                        ksl_mat3x3_t* KSL_RESTRICT ro) {
  const ksl_mat3x3_t r = *ri;
  ro->v0.x = dc[1] * r.v0.x + r.v2.x * dc[0];
  ro->v0.y = dc[1] * r.v0.y + r.v2.y * dc[0];
  ro->v0.z = dc[1] * r.v0.z + r.v2.z * dc[0];
  ro->v2.x = -dc[0] * r.v0.x + r.v2.x * dc[1];
  ro->v2.y = -dc[0] * r.v0.y + r.v2.y * dc[1];
  ro->v2.z = -dc[0] * r.v0.z + r.v2.z * dc[1];
  ro->v1 = r.v1;
}

static inline void ksl_product_drdryinvf(const ksl_mat3x3f_t* KSL_RESTRICT ri,
                                         const float dc[2],
                                         ksl_mat3x3f_t* KSL_RESTRICT ro) {
  const ksl_mat3x3f_t r = *ri;
  ro->v0.x = dc[1] * r.v0.x + r.v2.x * dc[0];
  ro->v0.y = dc[1] * r.v0.y + r.v2.y * dc[0];
  ro->v0.z = dc[1] * r.v0.z + r.v2.z * dc[0];
  ro->v2.x = -dc[0] * r.v0.x + r.v2.x * dc[1];
  ro->v2.y = -dc[0] * r.v0.y + r.v2.y * dc[1];
  ro->v2.z = -dc[0] * r.v0.z + r.v2.z * dc[1];
  ro->v1 = r.v1;
}

static inline void ksl_product_drdrz(const ksl_mat3x3_t* KSL_RESTRICT ri,
                                     const double dc[2],
                                     ksl_mat3x3_t* KSL_RESTRICT ro) {
  const ksl_mat3x3_t r = *ri;
  ro->v0.x = dc[1] * r.v0.x + r.v1.x * dc[0];
  ro->v0.y = dc[1] * r.v0.y + r.v1.y * dc[0];
  ro->v0.z = dc[1] * r.v0.z + r.v1.z * dc[0];
  ro->v1.x = -dc[0] * r.v0.x + r.v1.x * dc[1];
  ro->v1.y = -dc[0] * r.v0.y + r.v1.y * dc[1];
  ro->v1.z = -dc[0] * r.v0.z + r.v1.z * dc[1];
  ro->v2 = r.v2;
}

static inline void ksl_product_drdrzf(const ksl_mat3x3f_t* KSL_RESTRICT ri,
                                      const float dc[2],
                                      ksl_mat3x3f_t* KSL_RESTRICT ro) {
  const ksl_mat3x3f_t r = *ri;
  ro->v0.x = dc[1] * r.v0.x + r.v1.x * dc[0];
  ro->v0.y = dc[1] * r.v0.y + r.v1.y * dc[0];
  ro->v0.z = dc[1] * r.v0.z + r.v1.z * dc[0];
  ro->v1.x = -dc[0] * r.v0.x + r.v1.x * dc[1];
  ro->v1.y = -dc[0] * r.v0.y + r.v1.y * dc[1];
  ro->v1.z = -dc[0] * r.v0.z + r.v1.z * dc[1];
  ro->v2 = r.v2;
}

static inline void ksl_product_drdrzinv(const ksl_mat3x3_t* KSL_RESTRICT ri,
                                        const double dc[2],
                                        ksl_mat3x3_t* KSL_RESTRICT ro) {
  const ksl_mat3x3_t r = *ri;
  ro->v0.x = dc[1] * r.v0.x + r.v1.x * -dc[0];
  ro->v0.y = dc[1] * r.v0.y + r.v1.y * -dc[0];
  ro->v0.z = dc[1] * r.v0.z + r.v1.z * -dc[0];
  ro->v1.x = dc[0] * r.v0.x + r.v1.x * dc[1];
  ro->v1.y = dc[0] * r.v0.y + r.v1.y * dc[1];
  ro->v1.z = dc[0] * r.v0.z + r.v1.z * dc[1];
  ro->v2 = r.v2;
}

static inline void ksl_product_drdrzinvf(const ksl_mat3x3f_t* KSL_RESTRICT ri,
                                         const float dc[2],
                                         ksl_mat3x3f_t* KSL_RESTRICT ro) {
  const ksl_mat3x3f_t r = *ri;
  ro->v0.x = dc[1] * r.v0.x + r.v1.x * -dc[0];
  ro->v0.y = dc[1] * r.v0.y + r.v1.y * -dc[0];
  ro->v0.z = dc[1] * r.v0.z + r.v1.z * -dc[0];
  ro->v1.x = dc[0] * r.v0.x + r.v1.x * dc[1];
  ro->v1.y = dc[0] * r.v0.y + r.v1.y * dc[1];
  ro->v1.z = dc[0] * r.v0.z + r.v1.z * dc[1];
  ro->v2 = r.v2;
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
