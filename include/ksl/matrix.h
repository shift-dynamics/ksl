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

#include <stdarg.h>

#include "axis.h"
#include "pub_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef union ksl_mat3x3_t ksl_mat3x3_t;
typedef union ksl_mat3x3f_t ksl_mat3x3f_t;
typedef union ksl_mat4x4_t ksl_mat4x4_t;
typedef union ksl_mat4x4f_t ksl_mat4x4f_t;
typedef union ksl_vec3_t ksl_vec3_t;
typedef union ksl_vec3f_t ksl_vec3f_t;
typedef union ksl_vec4_t ksl_vec4_t;
typedef union ksl_vec4f_t ksl_vec4f_t;
typedef union ksl_SE3_t ksl_SE3_t;
typedef union ksl_SE3f_t ksl_SE3f_t;

/* matrix vector operations */

/*!
@brief Compute the double precision matrix product of a 3x3 matrix \f$R^{oi}\f$
and a 3x1 vector \f$\underline{v}^i_{oi}\f$.

\f$R^{oi} \underline{v}^i_{oi} \rightarrow \underline{v}^o_{oi} \f$

@param r_oi [in] input 3x3 matrix
@param v_i [in] input vector
@param v_o [out] result returned in v_o
*/
void ksl_product_drv(const ksl_mat3x3_t* r_oi, const ksl_vec3_t* v_i,
                     ksl_vec3_t* v_o);

/*!
@brief Compute the single precision matrix product of a 3x3 matrix \f$R^{oi}\f$
and a 3x1 vector \f$\underline{v}^i_{oi}\f$.

\f$R^{oi} \underline{v}^i_{oi} \rightarrow \underline{v}^o_{oi} \f$

@param r_oi [in] input 3x3 matrix
@param v_i [in] input vector
@param v_o [out] result returned in v_o
*/
void ksl_product_drvf(const ksl_mat3x3f_t* r_oi, const ksl_vec3f_t* v_i,
                      ksl_vec3f_t* v_o);

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
void ksl_product_drvinv(const ksl_mat3x3_t* ri, const ksl_vec3_t* vi,
                        ksl_vec3_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_drvinvf(const ksl_mat3x3f_t* ri, const ksl_vec3f_t* vi,
                         ksl_vec3f_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_drinvv(const ksl_mat3x3_t* ri, const ksl_vec3_t* vi,
                        ksl_vec3_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_drinvvf(const ksl_mat3x3f_t* ri, const ksl_vec3f_t* vi,
                         ksl_vec3f_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_drinvvinv(const ksl_mat3x3_t* ri, const ksl_vec3_t* vi,
                           ksl_vec3_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_drinvvinvf(const ksl_mat3x3f_t* ri, const ksl_vec3f_t* vi,
                            ksl_vec3f_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_drvtx(const ksl_mat3x3_t* ri, const double ti, ksl_vec3_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_drvtxf(const ksl_mat3x3f_t* ri, const float ti,
                        ksl_vec3f_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_drvtxinv(const ksl_mat3x3_t* ri, const double ti,
                          ksl_vec3_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_drvtxinvf(const ksl_mat3x3f_t* ri, const float ti,
                           ksl_vec3f_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_drvty(const ksl_mat3x3_t* ri, const double ti, ksl_vec3_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_drvtyf(const ksl_mat3x3f_t* ri, const float ti,
                        ksl_vec3f_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_drvtyinv(const ksl_mat3x3_t* ri, const double ti,
                          ksl_vec3_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_drvtyinvf(const ksl_mat3x3f_t* ri, const float ti,
                           ksl_vec3f_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_drvtz(const ksl_mat3x3_t* ri, const double ti, ksl_vec3_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_drvtzf(const ksl_mat3x3f_t* ri, const float ti,
                        ksl_vec3f_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_drvtzinv(const ksl_mat3x3_t* ri, const double ti,
                          ksl_vec3_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_drvtzinvf(const ksl_mat3x3f_t* ri, const float ti,
                           ksl_vec3f_t* vo);

/* matrix-matrix operations */

/*!
@brief TODO document this function
*/
void ksl_product_drdrx(const ksl_mat3x3_t* ri, const double dc[2],
                       ksl_mat3x3_t* ro);

/*!
@brief TODO document this function
*/
void ksl_product_drdrxf(const ksl_mat3x3f_t* ri, const float dc[2],
                        ksl_mat3x3f_t* ro);

/*!
@brief TODO document this function
*/
void ksl_product_drdrxinv(const ksl_mat3x3_t* ri, const double dc[2],
                          ksl_mat3x3_t* ro);

/*!
@brief TODO document this function
*/
void ksl_product_drdrxinvf(const ksl_mat3x3f_t* ri, const float dc[2],
                           ksl_mat3x3f_t* ro);

/*!
@brief TODO document this function
*/
void ksl_product_drdry(const ksl_mat3x3_t* ri, const double dc[2],
                       ksl_mat3x3_t* ro);

/*!
@brief TODO document this function
*/
void ksl_product_drdryf(const ksl_mat3x3f_t* ri, const float dc[2],
                        ksl_mat3x3f_t* ro);

/*!
@brief TODO document this function
*/
void ksl_product_drdryinv(const ksl_mat3x3_t* ri, const double dc[2],
                          ksl_mat3x3_t* ro);

/*!
@brief TODO document this function
*/
void ksl_product_drdryinvf(const ksl_mat3x3f_t* ri, const float dc[2],
                           ksl_mat3x3f_t* ro);

/*!
@brief TODO document this function
*/
void ksl_product_drdrz(const ksl_mat3x3_t* ri, const double dc[2],
                       ksl_mat3x3_t* ro);

/*!
@brief TODO document this function
*/
void ksl_product_drdrzf(const ksl_mat3x3f_t* ri, const float dc[2],
                        ksl_mat3x3f_t* ro);

/*!
@brief TODO document this function
*/
void ksl_product_drdrzinv(const ksl_mat3x3_t* ri, const double dc[2],
                          ksl_mat3x3_t* ro);

/*!
@brief TODO document this function
*/
void ksl_product_drdrzinvf(const ksl_mat3x3f_t* ri, const float dc[2],
                           ksl_mat3x3f_t* ro);

/*!
@brief TODO document this function
*/
void ksl_product_drdr(const ksl_mat3x3_t* r1i, const ksl_mat3x3_t* r2i,
                      ksl_mat3x3_t* ro);

/*!
@brief TODO document this function
*/
void ksl_product_drdrf(const ksl_mat3x3f_t* r1i, const ksl_mat3x3f_t* r2i,
                       ksl_mat3x3f_t* ro);

/*!
@brief TODO document this function
*/
void ksl_product_drdrinv(const ksl_mat3x3_t* r1i, const ksl_mat3x3_t* r2i,
                         ksl_mat3x3_t* ro);

/*!
@brief TODO document this function
*/
void ksl_product_drdrinvf(const ksl_mat3x3f_t* r1i, const ksl_mat3x3f_t* r2i,
                          ksl_mat3x3f_t* ro);

/*!
@brief TODO document this function
*/
void ksl_product_drinvdr(const ksl_mat3x3_t* r1i, const ksl_mat3x3_t* r2i,
                         ksl_mat3x3_t* ro);

/*!
@brief TODO document this function
*/
void ksl_product_drinvdrf(const ksl_mat3x3f_t* r1i, const ksl_mat3x3f_t* r2i,
                          ksl_mat3x3f_t* ro);

/*!
@brief TODO document this function
*/
void ksl_product_dv(const ksl_SE3_t* Di, const ksl_vec3_t* vi, ksl_vec3_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_dvf(const ksl_SE3f_t* Di, const ksl_vec3f_t* vi,
                     ksl_vec3f_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_dinvv(const ksl_SE3_t* Di, const ksl_vec3_t* vi,
                       ksl_vec3_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_dinvvf(const ksl_SE3f_t* Di, const ksl_vec3f_t* vi,
                        ksl_vec3f_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_ddrx(const ksl_SE3_t* Di, const double dc[2], ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddrxf(const ksl_SE3f_t* Di, const float dc[2], ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddrxinv(const ksl_SE3_t* Di, const double dc[2],
                         ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddrxinvf(const ksl_SE3f_t* Di, const float dc[2],
                          ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddry(const ksl_SE3_t* Di, const double dc[2], ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddryf(const ksl_SE3f_t* Di, const float dc[2], ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddryinv(const ksl_SE3_t* Di, const double dc[2],
                         ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddryinvf(const ksl_SE3f_t* Di, const float dc[2],
                          ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddrz(const ksl_SE3_t* Di, const double dc[2], ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddrzf(const ksl_SE3f_t* Di, const float dc[2], ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddrzinv(const ksl_SE3_t* Di, const double dc[2],
                         ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddrzinvf(const ksl_SE3f_t* Di, const float dc[2],
                          ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddt(const ksl_SE3_t* Di, const ksl_vec3_t* t, ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddtinv(const ksl_SE3_t* Di, const ksl_vec3_t* vi,
                        ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddtinvf(const ksl_SE3f_t* Di, const ksl_vec3f_t* vi,
                         ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddtf(const ksl_SE3f_t* Di, const ksl_vec3f_t* vi,
                      ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_dinvdt(const ksl_SE3_t* Di, const ksl_vec3_t* vi,
                        ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_dinvdtf(const ksl_SE3f_t* Di, const ksl_vec3f_t* vi,
                         ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddtx(const ksl_SE3_t* Di, const double ti, ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddtxf(const ksl_SE3f_t* Di, const float ti, ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddtxinv(const ksl_SE3_t* Di, const double ti, ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddtxinvf(const ksl_SE3f_t* Di, const float ti, ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddty(const ksl_SE3_t* Di, const double ti, ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddtyf(const ksl_SE3f_t* Di, const float ti, ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddtyinv(const ksl_SE3_t* Di, const double ti, ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddtyinvf(const ksl_SE3f_t* Di, const float ti, ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddtz(const ksl_SE3_t* Di, const double ti, ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddtzf(const ksl_SE3f_t* Di, const float ti, ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddtzinv(const ksl_SE3_t* Di, const double ti, ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddtzinvf(const ksl_SE3f_t* Di, const float ti, ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddr(const ksl_SE3_t* Di, const ksl_mat3x3_t* Ri,
                     ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddrf(const ksl_SE3f_t* Di, const ksl_mat3x3f_t* Ri,
                      ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddrinv(const ksl_SE3_t* Di, const ksl_mat3x3_t* Ri,
                        ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddrinvf(const ksl_SE3f_t* Di, const ksl_mat3x3f_t* Ri,
                         ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_dd(const ksl_SE3_t* D1i, const ksl_SE3_t* D2i, ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddf(const ksl_SE3f_t* D1i, const ksl_SE3f_t* D2i,
                     ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddinv(const ksl_SE3_t* D1i, const ksl_SE3_t* D2i,
                       ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddinvf(const ksl_SE3f_t* D1i, const ksl_SE3f_t* D2i,
                        ksl_SE3f_t* Do);

inline void ksl_product_dinvd(const ksl_SE3_t* restrict D1i,
                              const ksl_SE3_t* restrict D2i,
                              ksl_SE3_t* restrict Do);

inline void ksl_product_dinvdf(const ksl_SE3f_t* D1i, const ksl_SE3f_t* D2i,
                               ksl_SE3f_t* Do);


#ifdef __cplusplus
}
#endif

#endif
