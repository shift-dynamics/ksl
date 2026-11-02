/**
@file
@author Kristopher Wehage, Roger Wehage
@brief Utilities to initialize and operate on quaternions
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
#ifndef _KSL_QUATERNION_H_
#define _KSL_QUATERNION_H_

#include "ksl/types.h"

#include "mat3x3.h"
#include "vec3.h"

/* The general quaternion products use SSE when the target supports it: SSE2
for double precision (with SSE3's addsub when available) and SSE for single
precision. Define KSL_NO_SIMD to use the portable scalar code instead. */
#if !defined(KSL_NO_SIMD) && defined(__SSE2__)
#define KSL_QUATERNION_SSE 1
#include <emmintrin.h>

#include "ksl/simd.h"
#ifdef __SSE3__
#include <pmmintrin.h>
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*!
@brief Construct a double precision quaternion from its components.
@param x [in] first vector component
@param y [in] second vector component
@param z [in] third vector component
@param w [in] scalar component
@return the quaternion {x, y, z, w}
*/
static inline ksl_quaternion_t ksl_quaternion(double x, double y, double z,
                                              double w);

/*!
@brief Single precision version of ksl_quaternion().
*/
static inline ksl_quaternionf_t ksl_quaternionf(float, float, float, float);

ksl_quaternion_t* ksl_quaternion_alloc(int);

ksl_quaternionf_t* ksl_quaternionf_alloc(int);

static inline double ksl_dot_qq(const ksl_quaternion_t*,
                                const ksl_quaternion_t*);

static inline float ksl_dot_qqf(const ksl_quaternionf_t*,
                                const ksl_quaternionf_t*);

static inline void ksl_quaternion_normalize(ksl_quaternion_t* qi);

static inline void ksl_quaternionf_normalize(ksl_quaternionf_t* qi);

static inline void ksl_axpy_qq(double, const ksl_quaternion_t*,
                               ksl_quaternion_t*);

static inline void ksl_axpy_qqf(float, const ksl_quaternionf_t*,
                                ksl_quaternionf_t*);

void ksl_mat3x3_toQuaternion(const ksl_mat3x3_t* ri, ksl_quaternion_t* qo);

void ksl_mat3x3f_toQuaternion(const ksl_mat3x3f_t* ri, ksl_quaternionf_t* qo);

static inline void ksl_quaternion_toMat3x3(ksl_quaternion_t* qi,
                                           ksl_mat3x3_t* ro);

static inline void ksl_quaternionf_toMat3x3f(ksl_quaternionf_t* qi,
                                             ksl_mat3x3f_t* ro);

static inline void ksl_quaternion_slerp(const ksl_quaternion_t* q1i,
                                        const ksl_quaternion_t* q2i, double* t,
                                        ksl_quaternion_t* qo);

static inline void ksl_quaternionf_slerp(const ksl_quaternionf_t* q1i,
                                         const ksl_quaternionf_t* q2i, float* t,
                                         ksl_quaternionf_t* qo);

static inline void ksl_quaternion_nlerp(const ksl_quaternion_t* q1i,
                                        const ksl_quaternion_t* q2i,
                                        const double* t, ksl_quaternion_t* qo);

static inline void ksl_quaternionf_nlerp(const ksl_quaternionf_t* q1i,
                                         const ksl_quaternionf_t* q2i,
                                         const float* t, ksl_quaternionf_t* qo);

static inline void ksl_add_dpiToq(const ksl_vec3_t* dpi, ksl_quaternion_t* qi);

static inline void ksl_subtract_dpiFromq(const ksl_vec3_t* dpi,
                                         ksl_quaternion_t* qi);

static inline void ksl_omega_to_dquaternion(const ksl_vec3_t* w,
                                            const ksl_quaternion_t* qi,
                                            ksl_quaternion_t* dqo);

static inline void ksl_product_qq(const ksl_quaternion_t* q1i,
                                  const ksl_quaternion_t* q2i,
                                  ksl_quaternion_t* qo);

static inline void ksl_product_qqf(const ksl_quaternionf_t* q1i,
                                   const ksl_quaternionf_t* q2i,
                                   ksl_quaternionf_t* qo);

static inline void ksl_product_qconjq(const ksl_quaternion_t* q1i,
                                      const ksl_quaternion_t* q2i,
                                      ksl_quaternion_t* qo);

static inline void ksl_product_qconjqf(const ksl_quaternionf_t* q1i,
                                       const ksl_quaternionf_t* q2i,
                                       ksl_quaternionf_t* qo);

static inline void ksl_product_qqconj(const ksl_quaternion_t* q1i,
                                      const ksl_quaternion_t* q2i,
                                      ksl_quaternion_t* qo);

static inline void ksl_product_qqconjf(const ksl_quaternionf_t* q1i,
                                       const ksl_quaternionf_t* q2i,
                                       ksl_quaternionf_t* qo);

static inline void ksl_product_qconjqconj(const ksl_quaternion_t* q1i,
                                          const ksl_quaternion_t* q2i,
                                          ksl_quaternion_t* qo);

static inline void ksl_product_qconjqconjf(const ksl_quaternionf_t* q1i,
                                           const ksl_quaternionf_t* q2i,
                                           ksl_quaternionf_t* qo);

/*!
@brief Double precision quaternion product qo = qx * qi, where qx is the
rotation about the x axis qx = {dci[0], 0, 0, dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qxq(const double dci[2],
                                   const ksl_quaternion_t* qi,
                                   ksl_quaternion_t* qo);

/*!
@brief Single precision quaternion product qo = qx * qi, where qx is the
rotation about the x axis qx = {dci[0], 0, 0, dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qxqf(const float dci[2],
                                    const ksl_quaternionf_t* qi,
                                    ksl_quaternionf_t* qo);

/*!
@brief Double precision quaternion product qo = qi * qx, where qx is the
rotation about the x axis qx = {dci[0], 0, 0, dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qqx(const ksl_quaternion_t* qi,
                                   const double dci[2], ksl_quaternion_t* qo);

/*!
@brief Single precision quaternion product qo = qi * qx, where qx is the
rotation about the x axis qx = {dci[0], 0, 0, dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qqxf(const ksl_quaternionf_t* qi,
                                    const float dci[2], ksl_quaternionf_t* qo);

/*!
@brief Double precision quaternion product qo = conj(qx) * qi, where qx is the
rotation about the x axis qx = {dci[0], 0, 0, dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qxconjq(const double dci[2],
                                       const ksl_quaternion_t* qi,
                                       ksl_quaternion_t* qo);

/*!
@brief Single precision quaternion product qo = conj(qx) * qi, where qx is the
rotation about the x axis qx = {dci[0], 0, 0, dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qxconjqf(const float dci[2],
                                        const ksl_quaternionf_t* qi,
                                        ksl_quaternionf_t* qo);

/*!
@brief Double precision quaternion product qo = qi * conj(qx), where qx is the
rotation about the x axis qx = {dci[0], 0, 0, dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qqxconj(const ksl_quaternion_t* qi,
                                       const double dci[2],
                                       ksl_quaternion_t* qo);

/*!
@brief Single precision quaternion product qo = qi * conj(qx), where qx is the
rotation about the x axis qx = {dci[0], 0, 0, dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qqxconjf(const ksl_quaternionf_t* qi,
                                        const float dci[2],
                                        ksl_quaternionf_t* qo);

/*!
@brief Double precision quaternion product qo = qx * conj(qi), where qx is the
rotation about the x axis qx = {dci[0], 0, 0, dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qxqconj(const double dci[2],
                                       const ksl_quaternion_t* qi,
                                       ksl_quaternion_t* qo);

/*!
@brief Single precision quaternion product qo = qx * conj(qi), where qx is the
rotation about the x axis qx = {dci[0], 0, 0, dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qxqconjf(const float dci[2],
                                        const ksl_quaternionf_t* qi,
                                        ksl_quaternionf_t* qo);

/*!
@brief Double precision quaternion product qo = conj(qi) * qx, where qx is the
rotation about the x axis qx = {dci[0], 0, 0, dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qconjqx(const ksl_quaternion_t* qi,
                                       const double dci[2],
                                       ksl_quaternion_t* qo);

/*!
@brief Single precision quaternion product qo = conj(qi) * qx, where qx is the
rotation about the x axis qx = {dci[0], 0, 0, dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qconjqxf(const ksl_quaternionf_t* qi,
                                        const float dci[2],
                                        ksl_quaternionf_t* qo);

/*!
@brief Double precision quaternion product qo = conj(qx) * conj(qi), where qx is
the rotation about the x axis qx = {dci[0], 0, 0, dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qxconjqconj(const double dci[2],
                                           const ksl_quaternion_t* qi,
                                           ksl_quaternion_t* qo);

/*!
@brief Single precision quaternion product qo = conj(qx) * conj(qi), where qx is
the rotation about the x axis qx = {dci[0], 0, 0, dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qxconjqconjf(const float dci[2],
                                            const ksl_quaternionf_t* qi,
                                            ksl_quaternionf_t* qo);

/*!
@brief Double precision quaternion product qo = conj(qi) * conj(qx), where qx is
the rotation about the x axis qx = {dci[0], 0, 0, dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qconjqxconj(const ksl_quaternion_t* qi,
                                           const double dci[2],
                                           ksl_quaternion_t* qo);

/*!
@brief Single precision quaternion product qo = conj(qi) * conj(qx), where qx is
the rotation about the x axis qx = {dci[0], 0, 0, dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qconjqxconjf(const ksl_quaternionf_t* qi,
                                            const float dci[2],
                                            ksl_quaternionf_t* qo);

/*!
@brief Double precision quaternion product qo = qy * qi, where qy is the
rotation about the y axis qy = {0, dci[0], 0, dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qyq(const double dci[2],
                                   const ksl_quaternion_t* qi,
                                   ksl_quaternion_t* qo);

/*!
@brief Single precision quaternion product qo = qy * qi, where qy is the
rotation about the y axis qy = {0, dci[0], 0, dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qyqf(const float dci[2],
                                    const ksl_quaternionf_t* qi,
                                    ksl_quaternionf_t* qo);

/*!
@brief Double precision quaternion product qo = qi * qy, where qy is the
rotation about the y axis qy = {0, dci[0], 0, dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qqy(const ksl_quaternion_t* qi,
                                   const double dci[2], ksl_quaternion_t* qo);

/*!
@brief Single precision quaternion product qo = qi * qy, where qy is the
rotation about the y axis qy = {0, dci[0], 0, dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qqyf(const ksl_quaternionf_t* qi,
                                    const float dci[2], ksl_quaternionf_t* qo);

/*!
@brief Double precision quaternion product qo = conj(qy) * qi, where qy is the
rotation about the y axis qy = {0, dci[0], 0, dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qyconjq(const double dci[2],
                                       const ksl_quaternion_t* qi,
                                       ksl_quaternion_t* qo);

/*!
@brief Single precision quaternion product qo = conj(qy) * qi, where qy is the
rotation about the y axis qy = {0, dci[0], 0, dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qyconjqf(const float dci[2],
                                        const ksl_quaternionf_t* qi,
                                        ksl_quaternionf_t* qo);

/*!
@brief Double precision quaternion product qo = qi * conj(qy), where qy is the
rotation about the y axis qy = {0, dci[0], 0, dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qqyconj(const ksl_quaternion_t* qi,
                                       const double dci[2],
                                       ksl_quaternion_t* qo);

/*!
@brief Single precision quaternion product qo = qi * conj(qy), where qy is the
rotation about the y axis qy = {0, dci[0], 0, dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qqyconjf(const ksl_quaternionf_t* qi,
                                        const float dci[2],
                                        ksl_quaternionf_t* qo);

/*!
@brief Double precision quaternion product qo = qy * conj(qi), where qy is the
rotation about the y axis qy = {0, dci[0], 0, dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qyqconj(const double dci[2],
                                       const ksl_quaternion_t* qi,
                                       ksl_quaternion_t* qo);

/*!
@brief Single precision quaternion product qo = qy * conj(qi), where qy is the
rotation about the y axis qy = {0, dci[0], 0, dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qyqconjf(const float dci[2],
                                        const ksl_quaternionf_t* qi,
                                        ksl_quaternionf_t* qo);

/*!
@brief Double precision quaternion product qo = conj(qi) * qy, where qy is the
rotation about the y axis qy = {0, dci[0], 0, dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qconjqy(const ksl_quaternion_t* qi,
                                       const double dci[2],
                                       ksl_quaternion_t* qo);

/*!
@brief Single precision quaternion product qo = conj(qi) * qy, where qy is the
rotation about the y axis qy = {0, dci[0], 0, dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qconjqyf(const ksl_quaternionf_t* qi,
                                        const float dci[2],
                                        ksl_quaternionf_t* qo);

/*!
@brief Double precision quaternion product qo = conj(qy) * conj(qi), where qy is
the rotation about the y axis qy = {0, dci[0], 0, dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qyconjqconj(const double dci[2],
                                           const ksl_quaternion_t* qi,
                                           ksl_quaternion_t* qo);

/*!
@brief Single precision quaternion product qo = conj(qy) * conj(qi), where qy is
the rotation about the y axis qy = {0, dci[0], 0, dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qyconjqconjf(const float dci[2],
                                            const ksl_quaternionf_t* qi,
                                            ksl_quaternionf_t* qo);

/*!
@brief Double precision quaternion product qo = conj(qi) * conj(qy), where qy is
the rotation about the y axis qy = {0, dci[0], 0, dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qconjqyconj(const ksl_quaternion_t* qi,
                                           const double dci[2],
                                           ksl_quaternion_t* qo);

/*!
@brief Single precision quaternion product qo = conj(qi) * conj(qy), where qy is
the rotation about the y axis qy = {0, dci[0], 0, dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qconjqyconjf(const ksl_quaternionf_t* qi,
                                            const float dci[2],
                                            ksl_quaternionf_t* qo);

/*!
@brief Double precision quaternion product qo = qz * qi, where qz is the
rotation about the z axis qz = {0, 0, dci[0], dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qzq(const double dci[2],
                                   const ksl_quaternion_t* qi,
                                   ksl_quaternion_t* qo);

/*!
@brief Single precision quaternion product qo = qz * qi, where qz is the
rotation about the z axis qz = {0, 0, dci[0], dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qzqf(const float dci[2],
                                    const ksl_quaternionf_t* qi,
                                    ksl_quaternionf_t* qo);

/*!
@brief Double precision quaternion product qo = qi * qz, where qz is the
rotation about the z axis qz = {0, 0, dci[0], dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qqz(const ksl_quaternion_t* qi,
                                   const double dci[2], ksl_quaternion_t* qo);

/*!
@brief Single precision quaternion product qo = qi * qz, where qz is the
rotation about the z axis qz = {0, 0, dci[0], dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qqzf(const ksl_quaternionf_t* qi,
                                    const float dci[2], ksl_quaternionf_t* qo);

/*!
@brief Double precision quaternion product qo = conj(qz) * qi, where qz is the
rotation about the z axis qz = {0, 0, dci[0], dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qzconjq(const double dci[2],
                                       const ksl_quaternion_t* qi,
                                       ksl_quaternion_t* qo);

/*!
@brief Single precision quaternion product qo = conj(qz) * qi, where qz is the
rotation about the z axis qz = {0, 0, dci[0], dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qzconjqf(const float dci[2],
                                        const ksl_quaternionf_t* qi,
                                        ksl_quaternionf_t* qo);

/*!
@brief Double precision quaternion product qo = qi * conj(qz), where qz is the
rotation about the z axis qz = {0, 0, dci[0], dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qqzconj(const ksl_quaternion_t* qi,
                                       const double dci[2],
                                       ksl_quaternion_t* qo);

/*!
@brief Single precision quaternion product qo = qi * conj(qz), where qz is the
rotation about the z axis qz = {0, 0, dci[0], dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qqzconjf(const ksl_quaternionf_t* qi,
                                        const float dci[2],
                                        ksl_quaternionf_t* qo);

/*!
@brief Double precision quaternion product qo = qz * conj(qi), where qz is the
rotation about the z axis qz = {0, 0, dci[0], dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qzqconj(const double dci[2],
                                       const ksl_quaternion_t* qi,
                                       ksl_quaternion_t* qo);

/*!
@brief Single precision quaternion product qo = qz * conj(qi), where qz is the
rotation about the z axis qz = {0, 0, dci[0], dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qzqconjf(const float dci[2],
                                        const ksl_quaternionf_t* qi,
                                        ksl_quaternionf_t* qo);

/*!
@brief Double precision quaternion product qo = conj(qi) * qz, where qz is the
rotation about the z axis qz = {0, 0, dci[0], dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qconjqz(const ksl_quaternion_t* qi,
                                       const double dci[2],
                                       ksl_quaternion_t* qo);

/*!
@brief Single precision quaternion product qo = conj(qi) * qz, where qz is the
rotation about the z axis qz = {0, 0, dci[0], dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qconjqzf(const ksl_quaternionf_t* qi,
                                        const float dci[2],
                                        ksl_quaternionf_t* qo);

/*!
@brief Double precision quaternion product qo = conj(qz) * conj(qi), where qz is
the rotation about the z axis qz = {0, 0, dci[0], dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qzconjqconj(const double dci[2],
                                           const ksl_quaternion_t* qi,
                                           ksl_quaternion_t* qo);

/*!
@brief Single precision quaternion product qo = conj(qz) * conj(qi), where qz is
the rotation about the z axis qz = {0, 0, dci[0], dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qzconjqconjf(const float dci[2],
                                            const ksl_quaternionf_t* qi,
                                            ksl_quaternionf_t* qo);

/*!
@brief Double precision quaternion product qo = conj(qi) * conj(qz), where qz is
the rotation about the z axis qz = {0, 0, dci[0], dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qconjqzconj(const ksl_quaternion_t* qi,
                                           const double dci[2],
                                           ksl_quaternion_t* qo);

/*!
@brief Single precision quaternion product qo = conj(qi) * conj(qz), where qz is
the rotation about the z axis qz = {0, 0, dci[0], dci[1]} given by dci =
{sin(theta/2), cos(theta/2)}.
*/
static inline void ksl_product_qconjqzconjf(const ksl_quaternionf_t* qi,
                                            const float dci[2],
                                            ksl_quaternionf_t* qo);

static inline void ksl_product_qv(const ksl_quaternion_t* qi,
                                  const ksl_vec3_t* vi, ksl_quaternion_t* qo);

static inline void ksl_product_qvf(const ksl_quaternionf_t* qi,
                                   const ksl_vec3f_t* vi,
                                   ksl_quaternionf_t* qo);

static inline void ksl_product_qconjv(const ksl_quaternion_t* qi,
                                      const ksl_vec3_t* vi,
                                      ksl_quaternion_t* qo);

static inline void ksl_product_qconjvf(const ksl_quaternionf_t* qi,
                                       const ksl_vec3f_t* vi,
                                       ksl_quaternionf_t* qo);

static inline void ksl_product_vq(const ksl_vec3_t* vi,
                                  const ksl_quaternion_t* qi,
                                  ksl_quaternion_t* qo);

static inline void ksl_product_vqf(const ksl_vec3f_t* vi,
                                   const ksl_quaternionf_t* qi,
                                   ksl_quaternionf_t* qo);

static inline void ksl_product_vqconj(const ksl_vec3_t* vi,
                                      const ksl_quaternion_t* qi,
                                      ksl_quaternion_t* qo);

static inline void ksl_product_vqconjf(const ksl_vec3f_t* vi,
                                       const ksl_quaternionf_t* qi,
                                       ksl_quaternionf_t* qo);

#ifdef __cplusplus
}
#endif

/* -------- inline definitions -------- */

#ifdef KSL_QUATERNION_SSE
/*! @cond KSL_INTERNAL */
/* {a0 - b0, a1 + b1} */
static inline __m128d ksl_addsub_pd_(const __m128d a, const __m128d b) {
#ifdef __SSE3__
  return _mm_addsub_pd(a, b);
#else
  return _mm_add_pd(a, _mm_xor_pd(b, _mm_set_pd(0.0, -0.0)));
#endif
}

/* qo = a * b for a = {ax, ay, az, aw} and b = {b_xy, b_zw}, two components per
register. Callers apply conjugates by negating a's vector part or flipping the
signs of b's. */
static inline void ksl_product_qq_sse2_(const double ax, const double ay,
                                        const double az, const double aw,
                                        const __m128d b_xy, const __m128d b_zw,
                                        double* KSL_RESTRICT qo) {
  const __m128d xx = _mm_set1_pd(ax), yy = _mm_set1_pd(ay);
  const __m128d zz = _mm_set1_pd(az), ww = _mm_set1_pd(aw);
  /* xy = t1 + {-t2.y, t2.x} with t1 = ww*xy + yy*zw, t2 = zz*xy - xx*zw */
  __m128d t1 = _mm_add_pd(_mm_mul_pd(ww, b_xy), _mm_mul_pd(yy, b_zw));
  __m128d t2 = _mm_sub_pd(_mm_mul_pd(zz, b_xy), _mm_mul_pd(xx, b_zw));
  ksl_storeu_pd_(qo, ksl_addsub_pd_(t1, _mm_shuffle_pd(t2, t2, 1)));
  /* zw = {t1.z + t2.w, t1.w - t2.z} with t1 = ww*zw - yy*xy,
     t2 = zz*zw + xx*xy */
  t1 = _mm_sub_pd(_mm_mul_pd(ww, b_zw), _mm_mul_pd(yy, b_xy));
  t2 = _mm_add_pd(_mm_mul_pd(zz, b_zw), _mm_mul_pd(xx, b_xy));
  const __m128d r = ksl_addsub_pd_(_mm_shuffle_pd(t1, t1, 1), t2);
  ksl_storeu_pd_(qo + 2, _mm_shuffle_pd(r, r, 1));
}

/* single precision qo = a * b with the whole quaternion b in one register:
qo = aw*b + ax*{bw,-bz,by,-bx} + ay*{bz,bw,-bx,-by} + az*{-by,bx,bw,-bz} */
static inline void ksl_product_qqf_sse_(const float ax, const float ay,
                                        const float az, const float aw,
                                        const __m128 b,
                                        float* KSL_RESTRICT qo) {
  __m128 r = _mm_mul_ps(_mm_set1_ps(aw), b);
  __m128 p = _mm_shuffle_ps(b, b, _MM_SHUFFLE(0, 1, 2, 3));
  p = _mm_xor_ps(p, _mm_set_ps(-0.0f, 0.0f, -0.0f, 0.0f));
  r = _mm_add_ps(r, _mm_mul_ps(_mm_set1_ps(ax), p));
  p = _mm_shuffle_ps(b, b, _MM_SHUFFLE(1, 0, 3, 2));
  p = _mm_xor_ps(p, _mm_set_ps(-0.0f, -0.0f, 0.0f, 0.0f));
  r = _mm_add_ps(r, _mm_mul_ps(_mm_set1_ps(ay), p));
  p = _mm_shuffle_ps(b, b, _MM_SHUFFLE(2, 3, 0, 1));
  p = _mm_xor_ps(p, _mm_set_ps(-0.0f, 0.0f, 0.0f, -0.0f));
  r = _mm_add_ps(r, _mm_mul_ps(_mm_set1_ps(az), p));
  ksl_storeu_ps_(qo, r);
}
/*! @endcond */
#endif

#include <assert.h>
#include <math.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

static inline ksl_quaternion_t ksl_quaternion(double x, double y, double z,
                                              double w) {
  ksl_quaternion_t quaternion;
  quaternion.x = x;
  quaternion.y = y;
  quaternion.z = z;
  quaternion.w = w;
  return quaternion;
}

static inline ksl_quaternionf_t ksl_quaternionf(float x, float y, float z,
                                                float w) {
  ksl_quaternionf_t quaternion;
  quaternion.x = x;
  quaternion.y = y;
  quaternion.z = z;
  quaternion.w = w;
  return quaternion;
}

/*!
@brief Dot product of two quaternions, x1 x2 + y1 y2 + z1 z2 + w1 w2.

@param q1i [in] first quaternion
@param q2i [in] second quaternion
@return the dot product of q1i and q2i
*/
static inline double ksl_dot_qq(const ksl_quaternion_t* KSL_RESTRICT q1i,
                                const ksl_quaternion_t* KSL_RESTRICT q2i) {
  return q1i->x * q2i->x + q1i->y * q2i->y + q1i->z * q2i->z + q1i->w * q2i->w;
}

/*!
@brief Single precision version of ksl_dot_qq().
*/
static inline float ksl_dot_qqf(const ksl_quaternionf_t* KSL_RESTRICT q1i,
                                const ksl_quaternionf_t* KSL_RESTRICT q2i) {
  return q1i->x * q2i->x + q1i->y * q2i->y + q1i->z * q2i->z + q1i->w * q2i->w;
}

/*!
@brief Normalize a quaternion to unit length, in place.

qi must not be zero.

@param qi [in,out] quaternion to normalize
*/
static inline void ksl_quaternion_normalize(ksl_quaternion_t* KSL_RESTRICT qi) {
  double norm = sqrt(ksl_dot_qq(qi, qi));
  for(int i = 0; i < 4; i++) {
    qi->at[i] /= norm;
  }
}

/*!
@brief Single precision version of ksl_quaternion_normalize().
*/
static inline void
ksl_quaternionf_normalize(ksl_quaternionf_t* KSL_RESTRICT qi) {
  float norm = sqrt(ksl_dot_qqf(qi, qi));
  for(int i = 0; i < 4; i++) {
    qi->at[i] /= norm;
  }
}

/*!
@brief Scale quaternion x by a and add it to quaternion y: y += a * x.

@param a [in] scale factor
@param x [in] quaternion to scale and add
@param y [in,out] quaternion that a * x is added to
*/
static inline void ksl_axpy_qq(const double a,
                               const ksl_quaternion_t* KSL_RESTRICT x,
                               ksl_quaternion_t* KSL_RESTRICT y) {
  for(int i = 0; i < 4; i++) {
    y->at[i] += a * x->at[i];
  }
}

/*!
@brief Single precision version of ksl_axpy_qq().
*/
static inline void ksl_axpy_qqf(const float a,
                                const ksl_quaternionf_t* KSL_RESTRICT x,
                                ksl_quaternionf_t* KSL_RESTRICT y) {
  for(int i = 0; i < 4; i++) {
    y->at[i] += a * x->at[i];
  }
}

/*!
@brief Convert a quaternion to a rotation matrix.

qi is first normalized in place. For \f$q = \{x, y, z, w\}\f$,
\f[
R = \begin{bmatrix}
w^2 + x^2 - y^2 - z^2 & 2(xy - wz) & 2(xz + wy) \\
2(xy + wz) & w^2 - x^2 + y^2 - z^2 & 2(yz - wx) \\
2(xz - wy) & 2(yz + wx) & w^2 - x^2 - y^2 + z^2
\end{bmatrix}
\f]

@param qi [in,out] quaternion, normalized on return
@param ro [out] rotation matrix
*/
static inline void ksl_quaternion_toMat3x3(ksl_quaternion_t* KSL_RESTRICT qi,
                                           ksl_mat3x3_t* KSL_RESTRICT ro) {

  ksl_quaternion_normalize(qi);

  double w2 = qi->w * qi->w;
  double x2 = qi->x * qi->x;
  double y2 = qi->y * qi->y;
  double z2 = qi->z * qi->z;

  ro->m00 = (x2 - y2 - z2 + w2);
  ro->m11 = (-x2 + y2 - z2 + w2);
  ro->m22 = (-x2 - y2 + z2 + w2);

  double tmp1 = qi->x * qi->y;
  double tmp2 = qi->z * qi->w;
  ro->m10 = 2.0 * (tmp1 + tmp2);
  ro->m01 = 2.0 * (tmp1 - tmp2);

  tmp1 = qi->x * qi->z;
  tmp2 = qi->y * qi->w;
  ro->m20 = 2.0 * (tmp1 - tmp2);
  ro->m02 = 2.0 * (tmp1 + tmp2);

  tmp1 = qi->y * qi->z;
  tmp2 = qi->x * qi->w;
  ro->m21 = 2.0 * (tmp1 + tmp2);
  ro->m12 = 2.0 * (tmp1 - tmp2);
}

/*!
@brief Single precision version of ksl_quaternion_toMat3x3().
*/
static inline void ksl_quaternionf_toMat3x3f(ksl_quaternionf_t* KSL_RESTRICT qi,
                                             ksl_mat3x3f_t* KSL_RESTRICT ro) {
  ksl_quaternionf_normalize(qi);

  float w2 = qi->w * qi->w;
  float x2 = qi->x * qi->x;
  float y2 = qi->y * qi->y;
  float z2 = qi->z * qi->z;

  ro->m00 = (x2 - y2 - z2 + w2);
  ro->m11 = (-x2 + y2 - z2 + w2);
  ro->m22 = (-x2 - y2 + z2 + w2);

  float tmp1 = qi->x * qi->y;
  float tmp2 = qi->z * qi->y;
  ro->m10 = 2.0 * (tmp1 + tmp2);
  ro->m01 = 2.0 * (tmp1 - tmp2);

  tmp1 = qi->x * qi->z;
  tmp2 = qi->y * qi->w;
  ro->m20 = 2.0 * (tmp1 - tmp2);
  ro->m02 = 2.0 * (tmp1 + tmp2);

  tmp1 = qi->y * qi->z;
  tmp2 = qi->x * qi->w;
  ro->m21 = 2.0 * (tmp1 + tmp2);
  ro->m12 = 2.0 * (tmp1 - tmp2);
}

/*!
@brief Spherical linear interpolation (slerp) between two quaternions.

Interpolates along the great circle from q1i to q2i at constant angular
velocity (Shoemake, 1985; see the References). Since q2i and -q2i are the same
rotation, the one closer to q1i is used, so the interpolation takes the
shorter path; at t = 1 the result may therefore be -q2i.

@param q1i [in] quaternion at t = 0
@param q2i [in] quaternion at t = 1
@param t [in] interpolation parameter, from 0 to 1
@param qo [out] interpolated quaternion
*/
static inline void
ksl_quaternion_slerp(const ksl_quaternion_t* KSL_RESTRICT q1i,
                     const ksl_quaternion_t* KSL_RESTRICT q2i,
                     double* KSL_RESTRICT t,
                     ksl_quaternion_t* KSL_RESTRICT qo) {

  /* q2i and -q2i are the same rotation: use the one closer to q1i, so that
  the interpolation takes the shorter path */
  double cosHalfTheta = ksl_dot_qq(q1i, q2i);
  double sign = 1.0;
  if(cosHalfTheta < 0.0) {
    sign = -1.0;
    cosHalfTheta = -cosHalfTheta;
  }

  memset(qo, 0, sizeof(ksl_quaternion_t));
  if(cosHalfTheta > 0.9995) {
    /* nearly the same rotation: sin(halfTheta) is close to zero, so
    interpolate linearly and normalize */
    ksl_axpy_qq(1.0 - *t, q1i, qo);
    ksl_axpy_qq(sign * *t, q2i, qo);
    ksl_quaternion_normalize(qo);
    return;
  }

  const double halfTheta = acos(cosHalfTheta);
  const double sinHalfTheta = sqrt(1.0 - cosHalfTheta * cosHalfTheta);
  ksl_axpy_qq(sin((1.0 - *t) * halfTheta) / sinHalfTheta, q1i, qo);
  ksl_axpy_qq(sign * sin(*t * halfTheta) / sinHalfTheta, q2i, qo);
}

/*!
@brief Single precision version of ksl_quaternion_slerp().
*/
static inline void
ksl_quaternionf_slerp(const ksl_quaternionf_t* KSL_RESTRICT q1i,
                      const ksl_quaternionf_t* KSL_RESTRICT q2i,
                      float* KSL_RESTRICT t,
                      ksl_quaternionf_t* KSL_RESTRICT qo) {

  /* q2i and -q2i are the same rotation: use the one closer to q1i, so that
  the interpolation takes the shorter path */
  float cosHalfTheta = ksl_dot_qqf(q1i, q2i);
  float sign = 1.0f;
  if(cosHalfTheta < 0.0f) {
    sign = -1.0f;
    cosHalfTheta = -cosHalfTheta;
  }

  memset(qo, 0, sizeof(ksl_quaternionf_t));
  if(cosHalfTheta > 0.9995f) {
    /* nearly the same rotation: sin(halfTheta) is close to zero, so
    interpolate linearly and normalize */
    ksl_axpy_qqf(1.0f - *t, q1i, qo);
    ksl_axpy_qqf(sign * *t, q2i, qo);
    ksl_quaternionf_normalize(qo);
    return;
  }

  const float halfTheta = acosf(cosHalfTheta);
  const float sinHalfTheta = sqrtf(1.0f - cosHalfTheta * cosHalfTheta);
  ksl_axpy_qqf(sinf((1.0f - *t) * halfTheta) / sinHalfTheta, q1i, qo);
  ksl_axpy_qqf(sign * sinf(*t * halfTheta) / sinHalfTheta, q2i, qo);
}

/*!
@brief Normalized linear interpolation (nlerp) between two quaternions.

Interpolates linearly between q1i and q2i and normalizes the result. It
follows the same path as ksl_quaternion_slerp() at lower cost, but not at
constant angular velocity. If the dot product of q1i and q2i is negative, q2i
is negated so that the interpolation takes the shorter path.

@param q1i [in] quaternion at t = 0
@param q2i [in] quaternion at t = 1
@param t [in] interpolation parameter, from 0 to 1
@param qo [out] interpolated quaternion
*/
static inline void
ksl_quaternion_nlerp(const ksl_quaternion_t* KSL_RESTRICT q1i,
                     const ksl_quaternion_t* KSL_RESTRICT q2i,
                     const double* KSL_RESTRICT t,
                     ksl_quaternion_t* KSL_RESTRICT qo) {

  if((*t) < 1e-9) {
    memcpy(qo, q1i, sizeof(ksl_quaternion_t));
    return;
  }
  if((*t) >= 1.0) {
    memcpy(qo, q2i, sizeof(ksl_quaternion_t));
    return;
  }
  double alpha = 1.0f - *t;
  double omega = *t;

  double dot = ksl_dot_qq(q1i, q2i);
  if(dot < 0) {
    omega = -omega;
  }

  memset(qo, 0, sizeof(ksl_quaternion_t));
  ksl_axpy_qq(alpha, q1i, qo);
  ksl_axpy_qq(omega, q2i, qo);

  /* linear interpolation doesn't yield quaternions with unit norm,
  so normalize before returning to user */
  ksl_quaternion_normalize(qo);
}

/*!
@brief Single precision version of ksl_quaternion_nlerp().
*/
static inline void
ksl_quaternionf_nlerp(const ksl_quaternionf_t* KSL_RESTRICT q1i,
                      const ksl_quaternionf_t* KSL_RESTRICT q2i,
                      const float* KSL_RESTRICT t,
                      ksl_quaternionf_t* KSL_RESTRICT qo) {

  if((*t) < 1e-9) {
    memcpy(qo, q1i, sizeof(ksl_quaternionf_t));
    return;
  }
  if((*t) >= 1.0) {
    memcpy(qo, q2i, sizeof(ksl_quaternionf_t));
    return;
  }
  float alpha = 1.0f - *t;
  float omega = *t;

  float dot = ksl_dot_qqf(q1i, q2i);
  if(dot < 0) {
    omega = -omega;
  }

  memset(qo, 0, sizeof(ksl_quaternionf_t));
  ksl_axpy_qqf(alpha, q1i, qo);
  ksl_axpy_qqf(omega, q2i, qo);

  /* linear interpolation doesn't yield quaternions with unit norm,
  so normalize before returning to user */
  ksl_quaternionf_normalize(qo);
}

/*!
@brief Apply a small rotation to a quaternion, to first order.

Adds the change in q produced by a small rotation vector
\f$\Delta\underline{\pi}\f$ whose coordinates are expressed in the rotated
(body) frame:
\f[
q \leftarrow q + \tfrac{1}{2}\, q
\begin{Bmatrix} \Delta\underline{\pi} \\ 0 \end{Bmatrix}
\f]
The result is not normalized.

@param dpi [in] small rotation vector, body frame coordinates
@param qi [in,out] quaternion to update
*/
static inline void ksl_add_dpiToq(const ksl_vec3_t* KSL_RESTRICT dpi,
                                  ksl_quaternion_t* KSL_RESTRICT qi) {
  ksl_quaternion_t dq;
  dq.x = qi->w * dpi->x - qi->z * dpi->y + qi->y * dpi->z;
  dq.y = qi->z * dpi->x + qi->w * dpi->y - qi->x * dpi->z;
  dq.z = -qi->y * dpi->x + qi->x * dpi->y + qi->w * dpi->z;
  dq.w = -qi->x * dpi->x - qi->y * dpi->y - qi->z * dpi->z;
  qi->x += 0.5 * dq.x;
  qi->y += 0.5 * dq.y;
  qi->z += 0.5 * dq.z;
  qi->w += 0.5 * dq.w;
}

/*!
@brief Remove a small rotation from a quaternion, to first order.

The reverse of ksl_add_dpiToq():
\f[
q \leftarrow q - \tfrac{1}{2}\, q
\begin{Bmatrix} \Delta\underline{\pi} \\ 0 \end{Bmatrix}
\f]
The result is not normalized.

@param dpi [in] small rotation vector, body frame coordinates
@param qi [in,out] quaternion to update
*/
static inline void ksl_subtract_dpiFromq(const ksl_vec3_t* KSL_RESTRICT dpi,
                                         ksl_quaternion_t* KSL_RESTRICT qi) {

  /*
  q^{ij} -= 1/2 * L_c(q^{ij}) d\underline{\pi}_{ij}^j)

         | qw -qz  qy : qx|                    | qw  qz -qy : qx|
  L(q) = | qz  qw -qx : qy| = |Lc(q):q| R(q) = |-qz  qw  qx : qy| = |Rc(q):q|
         |-qy  qx  qw : qz|                    | qy -qx  qw : qz|
         |-qx -qy -qz : qw|                    |-qx -qy -qz : qw|

                            | qw -qz  qy| |dpijx|
  qij -= 1/2*Lc(qij)*dpij = | qz  qw -qx| |dpijy|
                            |-qy  qx  qw| |dpijz|
                            |-qx -qy -qz|

  */

  /* dq \leftarrow L_c(e^{ij} d\underline{\pi}_{ij}^j) */
  ksl_quaternion_t dq;
  dq.x = qi->w * dpi->x - qi->z * dpi->y + qi->y * dpi->z;
  dq.y = qi->z * dpi->x + qi->w * dpi->y - qi->x * dpi->z;
  dq.z = -qi->y * dpi->x + qi->x * dpi->y + qi->w * dpi->z;
  dq.w = -qi->x * dpi->x - qi->y * dpi->y - qi->z * dpi->z;

  /* qi -= 1/2 * dq */
  qi->x -= 0.5 * dq.x;
  qi->y -= 0.5 * dq.y;
  qi->z -= 0.5 * dq.z;
  qi->w -= 0.5 * dq.w;
}

/*!
@brief Time derivative of a quaternion from the angular velocity.

\f[
\dot{q} = \tfrac{1}{2}
\begin{Bmatrix} \underline{\omega} \\ 0 \end{Bmatrix} q
+ \frac{1}{2\tau}\left(1 - q^T q\right) q, \qquad \tau = 0.5
\f]
where the coordinates of the angular velocity \f$\underline{\omega}\f$ are
expressed in the fixed frame. The second term keeps q at unit length during
numerical integration: it is zero when q has unit length and pulls the
length back toward 1 otherwise.

@param w [in] angular velocity, fixed frame coordinates
@param qi [in] quaternion
@param dqo [out] time derivative of the quaternion
*/
static inline void
ksl_omega_to_dquaternion(const ksl_vec3_t* KSL_RESTRICT w,
                         const ksl_quaternion_t* KSL_RESTRICT qi,
                         ksl_quaternion_t* KSL_RESTRICT dqo) {

  /*
          | qw  qz -qy : qx|
   R(q) = |-qz  qw  qx : qy| = |Rc(q):q|
          | qy -qx  qw : qz|
          |-qx -qy -qz : qw|
    1/2 * [ qi->w  qi->z -qi->y] * {w->x}
          [-qi->z  qi->w  qi->x]   {w->y}
          [ qi->y -qi->x  qi->w]   {w->z}
          [-qi->x -qi->y -qi->z]
  */
  dqo->x = qi->w * w->x + qi->z * w->y - qi->y * w->z;
  dqo->y = -qi->z * w->x + qi->w * w->y + qi->x * w->z;
  dqo->z = qi->y * w->x - qi->x * w->y + qi->w * w->z;
  dqo->w = -qi->x * w->x - qi->y * w->y - qi->z * w->z;

  dqo->x *= 0.5;
  dqo->y *= 0.5;
  dqo->z *= 0.5;
  dqo->w *= 0.5;

  /* add feedback term to normalize quaternion */

  /* if tau is 0.5 */
  double alpha = 1.0 - ksl_dot_qq(qi, qi);

  /*
    if tau is not 0.5, then
    let coeff = 0.5 / tau
  */
  // double alpha = coeff * (1 - ksl_dot_qq(qi, qi));

  ksl_axpy_qq(alpha, qi, dqo);
}

/*!
@brief Quaternion product qo = q1i * q2i.

The Hamilton product of two quaternions. For a quaternion
\f$q = \{x, y, z, w\}\f$ it can be written as a matrix product,
\f$q_1 q_2 = L(q_1)\, q_2 = R(q_2)\, q_1\f$, with
\f[
L(q) = \begin{bmatrix}
 w & -z &  y & x \\
 z &  w & -x & y \\
-y &  x &  w & z \\
-x & -y & -z & w
\end{bmatrix}, \qquad
R(q) = \begin{bmatrix}
 w &  z & -y & x \\
-z &  w &  x & y \\
 y & -x &  w & z \\
-x & -y & -z & w
\end{bmatrix}
\f]

@param q1i [in] first quaternion
@param q2i [in] second quaternion
@param qo [out] product
*/
static inline void ksl_product_qq(const ksl_quaternion_t* KSL_RESTRICT q1i,
                                  const ksl_quaternion_t* KSL_RESTRICT q2i,
                                  ksl_quaternion_t* KSL_RESTRICT qo) {
#ifdef KSL_QUATERNION_SSE
  ksl_product_qq_sse2_(q1i->x, q1i->y, q1i->z, q1i->w, _mm_loadu_pd(q2i->at),
                       _mm_loadu_pd(q2i->at + 2), qo->at);
#else
  /*
                    | q1iw -q1iz  q1iy  q1ix| |q2ix|
  qo = L(q1i)*q2i = | q1iz  q1iw -q1ix  q1iy| |q2iy| = R(q2i)*q1i
                    |-q1iy  q1ix  q1iw  q1iz| |q2iz|
                    |-q1ix -q1iy -q1iz  q1iw| |q2iw|
  */
  qo->x = q1i->w * q2i->x - q1i->z * q2i->y + q1i->y * q2i->z + q1i->x * q2i->w;
  qo->y = q1i->z * q2i->x + q1i->w * q2i->y - q1i->x * q2i->z + q1i->y * q2i->w;
  qo->z =
    -q1i->y * q2i->x + q1i->x * q2i->y + q1i->w * q2i->z + q1i->z * q2i->w;
  qo->w =
    -q1i->x * q2i->x - q1i->y * q2i->y - q1i->z * q2i->z + q1i->w * q2i->w;
#endif
}

/*!
@brief Single precision version of ksl_product_qq().
*/
static inline void ksl_product_qqf(const ksl_quaternionf_t* KSL_RESTRICT q1i,
                                   const ksl_quaternionf_t* KSL_RESTRICT q2i,
                                   ksl_quaternionf_t* KSL_RESTRICT qo) {
#ifdef KSL_QUATERNION_SSE
  ksl_product_qqf_sse_(q1i->x, q1i->y, q1i->z, q1i->w, _mm_loadu_ps(q2i->at),
                       qo->at);
#else
  /*
                    | q1iw -q1iz  q1iy  q1ix| |q2ix|
  qo = L(q1i)*q2i = | q1iz  q1iw -q1ix  q1iy| |q2iy| = R(q2i)*q1i
                    |-q1iy  q1ix  q1iw  q1iz| |q2iz|
                    |-q1ix -q1iy -q1iz  q1iw| |q2iw|
  */

  qo->x = q1i->w * q2i->x - q1i->z * q2i->y + q1i->y * q2i->z + q1i->x * q2i->w;
  qo->y = q1i->z * q2i->x + q1i->w * q2i->y - q1i->x * q2i->z + q1i->y * q2i->w;
  qo->z =
    -q1i->y * q2i->x + q1i->x * q2i->y + q1i->w * q2i->z + q1i->z * q2i->w;
  qo->w =
    -q1i->x * q2i->x - q1i->y * q2i->y - q1i->z * q2i->z + q1i->w * q2i->w;
#endif
}

/*!
@brief Quaternion product qo = conj(q1i) * q2i.

Computes \f$q_o = q_1^* q_2\f$. See ksl_product_qq() for the matrix form of the product.

@param q1i [in] first quaternion
@param q2i [in] second quaternion
@param qo [out] product
*/
static inline void ksl_product_qconjq(const ksl_quaternion_t* KSL_RESTRICT q1i,
                                      const ksl_quaternion_t* KSL_RESTRICT q2i,
                                      ksl_quaternion_t* KSL_RESTRICT qo) {
#ifdef KSL_QUATERNION_SSE
  ksl_product_qq_sse2_(-q1i->x, -q1i->y, -q1i->z, q1i->w, _mm_loadu_pd(q2i->at),
                       _mm_loadu_pd(q2i->at + 2), qo->at);
#else
  /*
                      | q1iw  q1iz -q1iy -q1ix| |q2ix|
  qo = L(q1i)^T*q2i = |-q1iz  q1iw  q1ix -q1iy| |q2iy|
                      | q1iy -q1ix  q1iw -q1iz| |q2iz|
                      | q1ix  q1iy  q1iz  q1iw| |q2iw|
  */

  qo->x = q1i->w * q2i->x + q1i->z * q2i->y - q1i->y * q2i->z - q1i->x * q2i->w;
  qo->y =
    -q1i->z * q2i->x + q1i->w * q2i->y + q1i->x * q2i->z - q1i->y * q2i->w;
  qo->z = q1i->y * q2i->x - q1i->x * q2i->y + q1i->w * q2i->z - q1i->z * q2i->w;
  qo->w = q1i->x * q2i->x + q1i->y * q2i->y + q1i->z * q2i->z + q1i->w * q2i->w;
#endif
}

/*!
@brief Single precision version of ksl_product_qconjq().
*/
static inline void
ksl_product_qconjqf(const ksl_quaternionf_t* KSL_RESTRICT q1i,
                    const ksl_quaternionf_t* KSL_RESTRICT q2i,
                    ksl_quaternionf_t* KSL_RESTRICT qo) {
#ifdef KSL_QUATERNION_SSE
  ksl_product_qqf_sse_(-q1i->x, -q1i->y, -q1i->z, q1i->w, _mm_loadu_ps(q2i->at),
                       qo->at);
#else
  /*
                      | q1iw  q1iz -q1iy -q1ix| |q2ix|
  qo = L(q1i)^T*q2i = |-q1iz  q1iw  q1ix -q1iy| |q2iy|
                      | q1iy -q1ix  q1iw -q1iz| |q2iz|
                      | q1ix  q1iy  q1iz  q1iw| |q2iw|
  */

  qo->x = q1i->w * q2i->x + q1i->z * q2i->y - q1i->y * q2i->z - q1i->x * q2i->w;
  qo->y =
    -q1i->z * q2i->x + q1i->w * q2i->y + q1i->x * q2i->z - q1i->y * q2i->w;
  qo->z = q1i->y * q2i->x - q1i->x * q2i->y + q1i->w * q2i->z - q1i->z * q2i->w;
  qo->w = q1i->x * q2i->x + q1i->y * q2i->y + q1i->z * q2i->z + q1i->w * q2i->w;
#endif
}

/*!
@brief Quaternion product qo = q1i * conj(q2i).

Computes \f$q_o = q_1 q_2^*\f$. See ksl_product_qq() for the matrix form of the product.

@param q1i [in] first quaternion
@param q2i [in] second quaternion
@param qo [out] product
*/
static inline void ksl_product_qqconj(const ksl_quaternion_t* KSL_RESTRICT q1i,
                                      const ksl_quaternion_t* KSL_RESTRICT q2i,
                                      ksl_quaternion_t* KSL_RESTRICT qo) {
#ifdef KSL_QUATERNION_SSE
  ksl_product_qq_sse2_(
    q1i->x, q1i->y, q1i->z, q1i->w,
    _mm_xor_pd(_mm_loadu_pd(q2i->at), _mm_set1_pd(-0.0)),
    _mm_xor_pd(_mm_loadu_pd(q2i->at + 2), _mm_set_pd(0.0, -0.0)), qo->at);
#else
  /*
                      | q2iw -q2iz  q2iy -q2ix| |q1ix|
  qo = R(q2i)^T*q1i = | q2iz  q2iw -q2ix -q2iy| |q1iy|
                      |-q2iy  q2ix  q2iw -q2iz| |q1iz|
                      | q2ix  q2iy  q2iz  q2iw| |q1iw|
  */

  qo->x = q2i->w * q1i->x - q2i->z * q1i->y + q2i->y * q1i->z - q2i->x * q1i->w;
  qo->y = q2i->z * q1i->x + q2i->w * q1i->y - q2i->x * q1i->z - q2i->y * q1i->w;
  qo->z =
    -q2i->y * q1i->x + q2i->x * q1i->y + q2i->w * q1i->z - q2i->z * q1i->w;
  qo->w = q2i->x * q1i->x + q2i->y * q1i->y + q2i->z * q1i->z + q2i->w * q1i->w;
#endif
}

/*!
@brief Single precision version of ksl_product_qqconj().
*/
static inline void
ksl_product_qqconjf(const ksl_quaternionf_t* KSL_RESTRICT q1i,
                    const ksl_quaternionf_t* KSL_RESTRICT q2i,
                    ksl_quaternionf_t* KSL_RESTRICT qo) {
#ifdef KSL_QUATERNION_SSE
  ksl_product_qqf_sse_(
    q1i->x, q1i->y, q1i->z, q1i->w,
    _mm_xor_ps(_mm_loadu_ps(q2i->at), _mm_set_ps(0.0f, -0.0f, -0.0f, -0.0f)),
    qo->at);
#else
  /*
                      | q2iw -q2iz  q2iy -q2ix| |q1ix|
  qo = R(q2i)^T*q1i = | q2iz  q2iw -q2ix -q2iy| |q1iy|
                      |-q2iy  q2ix  q2iw -q2iz| |q1iz|
                      | q2ix  q2iy  q2iz  q2iw| |q1iw|
  */

  qo->x = q2i->w * q1i->x - q2i->z * q1i->y + q2i->y * q1i->z - q2i->x * q1i->w;
  qo->y = q2i->z * q1i->x + q2i->w * q1i->y - q2i->x * q1i->z - q2i->y * q1i->w;
  qo->z =
    -q2i->y * q1i->x + q2i->x * q1i->y + q2i->w * q1i->z - q2i->z * q1i->w;
  qo->w = q2i->x * q1i->x + q2i->y * q1i->y + q2i->z * q1i->z + q2i->w * q1i->w;
#endif
}

/*!
@brief Quaternion product qo = conj(q1i) * conj(q2i).

Computes \f$q_o = q_1^* q_2^*\f$. See ksl_product_qq() for the matrix form of the product.

@param q1i [in] first quaternion
@param q2i [in] second quaternion
@param qo [out] product
*/
static inline void
ksl_product_qconjqconj(const ksl_quaternion_t* KSL_RESTRICT q1i,
                       const ksl_quaternion_t* KSL_RESTRICT q2i,
                       ksl_quaternion_t* KSL_RESTRICT qo) {
#ifdef KSL_QUATERNION_SSE
  ksl_product_qq_sse2_(
    -q1i->x, -q1i->y, -q1i->z, q1i->w,
    _mm_xor_pd(_mm_loadu_pd(q2i->at), _mm_set1_pd(-0.0)),
    _mm_xor_pd(_mm_loadu_pd(q2i->at + 2), _mm_set_pd(0.0, -0.0)), qo->at);
#else
  /*
                          | q1iw  q1iz -q1iy -q1ix| |-q2ix|
  qo = L(q1i)^T*q2iconj = |-q1iz  q1iw  q1ix -q1iy| |-q2iy|
                          | q1iy -q1ix  q1iw -q1iz| |-q2iz|
                          | q1ix  q1iy  q1iz  q1iw| | q2iw|

                          |-q1iw -q1iz  q1iy -q1ix| |q2ix|
                        = | q1iz -q1iw -q1ix -q1iy| |q2iy|
                          |-q1iy  q1ix -q1iw -q1iz| |q2iz|
                          |-q1ix -q1iy -q1iz  q1iw| |q2iw|
  */
  qo->x =
    -q1i->w * q2i->x - q1i->z * q2i->y + q1i->y * q2i->z - q1i->x * q2i->w;
  qo->y = q1i->z * q2i->x - q1i->w * q2i->y - q1i->x * q2i->z - q1i->y * q2i->w;
  qo->z =
    -q1i->y * q2i->x + q1i->x * q2i->y - q1i->w * q2i->z - q1i->z * q2i->w;
  qo->w =
    -q1i->x * q2i->x - q1i->y * q2i->y - q1i->z * q2i->z + q1i->w * q2i->w;
#endif
}

/*!
@brief Single precision version of ksl_product_qconjqconj().
*/
static inline void
ksl_product_qconjqconjf(const ksl_quaternionf_t* KSL_RESTRICT q1i,
                        const ksl_quaternionf_t* KSL_RESTRICT q2i,
                        ksl_quaternionf_t* KSL_RESTRICT qo) {
#ifdef KSL_QUATERNION_SSE
  ksl_product_qqf_sse_(
    -q1i->x, -q1i->y, -q1i->z, q1i->w,
    _mm_xor_ps(_mm_loadu_ps(q2i->at), _mm_set_ps(0.0f, -0.0f, -0.0f, -0.0f)),
    qo->at);
#else
  /*
                          | q1iw  q1iz -q1iy -q1ix| |-q2ix|
  qo = L(q1i)^T*q2iconj = |-q1iz  q1iw  q1ix -q1iy| |-q2iy|
                          | q1iy -q1ix  q1iw -q1iz| |-q2iz|
                          | q1ix  q1iy  q1iz  q1iw| | q2iw|

                          |-q1iw -q1iz  q1iy -q1ix| |q2ix|
                        = | q1iz -q1iw -q1ix -q1iy| |q2iy|
                          |-q1iy  q1ix -q1iw -q1iz| |q2iz|
                          |-q1ix -q1iy -q1iz  q1iw| |q2iw|
  */
  qo->x =
    -q1i->w * q2i->x - q1i->z * q2i->y + q1i->y * q2i->z - q1i->x * q2i->w;
  qo->y = q1i->z * q2i->x - q1i->w * q2i->y - q1i->x * q2i->z - q1i->y * q2i->w;
  qo->z =
    -q1i->y * q2i->x + q1i->x * q2i->y - q1i->w * q2i->z - q1i->z * q2i->w;
  qo->w =
    -q1i->x * q2i->x - q1i->y * q2i->y - q1i->z * q2i->z + q1i->w * q2i->w;
#endif
}

static inline void ksl_product_qxq(const double dci[2],
                                   const ksl_quaternion_t* KSL_RESTRICT qi,
                                   ksl_quaternion_t* KSL_RESTRICT qo) {
  /*
       | qiw  qiz -qiy  qix| |dci[0]|
  qo = |-qiz  qiw  qix  qiy| |  0   |
       | qiy -qix  qiw  qiz| |  0   |
       |-qix -qiy -qiz  qiw| |dci[1]|
  */
  qo->x = qi->x * dci[1] + qi->w * dci[0];
  qo->y = qi->y * dci[1] - qi->z * dci[0];
  qo->z = qi->z * dci[1] + qi->y * dci[0];
  qo->w = qi->w * dci[1] - qi->x * dci[0];
}

static inline void ksl_product_qxqf(const float dci[2],
                                    const ksl_quaternionf_t* KSL_RESTRICT qi,
                                    ksl_quaternionf_t* KSL_RESTRICT qo) {
  /*
                 | dci[1]    0       0     dci[0]| |qix|
qo = L(dci) qi = |   0     dci[1] -dci[0]    0   | |qiy|
                 |   0     dci[0]  dci[1]    0   | |qiz|
                 |-dci[0]    0       0     dci[1]| |qiw|
  */
  qo->x = dci[1] * qi->x + dci[0] * qi->w;
  qo->y = dci[1] * qi->y - dci[0] * qi->z;
  qo->z = dci[1] * qi->z + dci[0] * qi->y;
  qo->w = dci[1] * qi->w - dci[0] * qi->x;
}

static inline void ksl_product_qqx(const ksl_quaternion_t* KSL_RESTRICT qi,
                                   const double dci[2],
                                   ksl_quaternion_t* KSL_RESTRICT qo) {
  qo->x = qi->x * dci[1] + qi->w * dci[0];
  qo->y = qi->y * dci[1] + qi->z * dci[0];
  qo->z = qi->z * dci[1] - qi->y * dci[0];
  qo->w = qi->w * dci[1] - qi->x * dci[0];
}

static inline void ksl_product_qqxf(const ksl_quaternionf_t* KSL_RESTRICT qi,
                                    const float dci[2],
                                    ksl_quaternionf_t* KSL_RESTRICT qo) {
  qo->x = qi->x * dci[1] + qi->w * dci[0];
  qo->y = qi->y * dci[1] + qi->z * dci[0];
  qo->z = qi->z * dci[1] - qi->y * dci[0];
  qo->w = qi->w * dci[1] - qi->x * dci[0];
}

static inline void ksl_product_qxconjq(const double dci[2],
                                       const ksl_quaternion_t* KSL_RESTRICT qi,
                                       ksl_quaternion_t* KSL_RESTRICT qo) {
  qo->x = qi->x * dci[1] - qi->w * dci[0];
  qo->y = qi->y * dci[1] + qi->z * dci[0];
  qo->z = qi->z * dci[1] - qi->y * dci[0];
  qo->w = qi->w * dci[1] + qi->x * dci[0];
}

static inline void
ksl_product_qxconjqf(const float dci[2],
                     const ksl_quaternionf_t* KSL_RESTRICT qi,
                     ksl_quaternionf_t* KSL_RESTRICT qo) {
  qo->x = qi->x * dci[1] - qi->w * dci[0];
  qo->y = qi->y * dci[1] + qi->z * dci[0];
  qo->z = qi->z * dci[1] - qi->y * dci[0];
  qo->w = qi->w * dci[1] + qi->x * dci[0];
}

static inline void ksl_product_qqxconj(const ksl_quaternion_t* KSL_RESTRICT qi,
                                       const double dci[2],
                                       ksl_quaternion_t* KSL_RESTRICT qo) {
  qo->x = qi->x * dci[1] - qi->w * dci[0];
  qo->y = qi->y * dci[1] - qi->z * dci[0];
  qo->z = qi->z * dci[1] + qi->y * dci[0];
  qo->w = qi->w * dci[1] + qi->x * dci[0];
}

static inline void
ksl_product_qqxconjf(const ksl_quaternionf_t* KSL_RESTRICT qi,
                     const float dci[2], ksl_quaternionf_t* KSL_RESTRICT qo) {
  qo->x = qi->x * dci[1] - qi->w * dci[0];
  qo->y = qi->y * dci[1] - qi->z * dci[0];
  qo->z = qi->z * dci[1] + qi->y * dci[0];
  qo->w = qi->w * dci[1] + qi->x * dci[0];
}

static inline void ksl_product_qxqconj(const double dci[2],
                                       const ksl_quaternion_t* KSL_RESTRICT qi,
                                       ksl_quaternion_t* KSL_RESTRICT qo) {
  qo->x = -qi->x * dci[1] + qi->w * dci[0];
  qo->y = -qi->y * dci[1] + qi->z * dci[0];
  qo->z = -qi->z * dci[1] - qi->y * dci[0];
  qo->w = qi->w * dci[1] + qi->x * dci[0];
}

static inline void
ksl_product_qxqconjf(const float dci[2],
                     const ksl_quaternionf_t* KSL_RESTRICT qi,
                     ksl_quaternionf_t* KSL_RESTRICT qo) {
  qo->x = -qi->x * dci[1] + qi->w * dci[0];
  qo->y = -qi->y * dci[1] + qi->z * dci[0];
  qo->z = -qi->z * dci[1] - qi->y * dci[0];
  qo->w = qi->w * dci[1] + qi->x * dci[0];
}

static inline void ksl_product_qconjqx(const ksl_quaternion_t* KSL_RESTRICT qi,
                                       const double dci[2],
                                       ksl_quaternion_t* KSL_RESTRICT qo) {
  qo->x = -qi->x * dci[1] + qi->w * dci[0];
  qo->y = -qi->y * dci[1] - qi->z * dci[0];
  qo->z = -qi->z * dci[1] + qi->y * dci[0];
  qo->w = qi->w * dci[1] + qi->x * dci[0];
}

static inline void
ksl_product_qconjqxf(const ksl_quaternionf_t* KSL_RESTRICT qi,
                     const float dci[2], ksl_quaternionf_t* KSL_RESTRICT qo) {
  qo->x = -qi->x * dci[1] + qi->w * dci[0];
  qo->y = -qi->y * dci[1] - qi->z * dci[0];
  qo->z = -qi->z * dci[1] + qi->y * dci[0];
  qo->w = qi->w * dci[1] + qi->x * dci[0];
}

static inline void
ksl_product_qxconjqconj(const double dci[2],
                        const ksl_quaternion_t* KSL_RESTRICT qi,
                        ksl_quaternion_t* KSL_RESTRICT qo) {
  qo->x = -qi->x * dci[1] - qi->w * dci[0];
  qo->y = -qi->y * dci[1] - qi->z * dci[0];
  qo->z = -qi->z * dci[1] + qi->y * dci[0];
  qo->w = qi->w * dci[1] - qi->x * dci[0];
}

static inline void
ksl_product_qxconjqconjf(const float dci[2],
                         const ksl_quaternionf_t* KSL_RESTRICT qi,
                         ksl_quaternionf_t* KSL_RESTRICT qo) {
  qo->x = -qi->x * dci[1] - qi->w * dci[0];
  qo->y = -qi->y * dci[1] - qi->z * dci[0];
  qo->z = -qi->z * dci[1] + qi->y * dci[0];
  qo->w = qi->w * dci[1] - qi->x * dci[0];
}

static inline void
ksl_product_qconjqxconj(const ksl_quaternion_t* KSL_RESTRICT qi,
                        const double dci[2],
                        ksl_quaternion_t* KSL_RESTRICT qo) {
  qo->x = -qi->x * dci[1] - qi->w * dci[0];
  qo->y = -qi->y * dci[1] + qi->z * dci[0];
  qo->z = -qi->z * dci[1] - qi->y * dci[0];
  qo->w = qi->w * dci[1] - qi->x * dci[0];
}

static inline void
ksl_product_qconjqxconjf(const ksl_quaternionf_t* KSL_RESTRICT qi,
                         const float dci[2],
                         ksl_quaternionf_t* KSL_RESTRICT qo) {
  qo->x = -qi->x * dci[1] - qi->w * dci[0];
  qo->y = -qi->y * dci[1] + qi->z * dci[0];
  qo->z = -qi->z * dci[1] - qi->y * dci[0];
  qo->w = qi->w * dci[1] - qi->x * dci[0];
}

static inline void ksl_product_qyq(const double dci[2],
                                   const ksl_quaternion_t* KSL_RESTRICT qi,
                                   ksl_quaternion_t* KSL_RESTRICT qo) {
  qo->x = qi->x * dci[1] + qi->z * dci[0];
  qo->y = qi->y * dci[1] + qi->w * dci[0];
  qo->z = qi->z * dci[1] - qi->x * dci[0];
  qo->w = qi->w * dci[1] - qi->y * dci[0];
}

static inline void ksl_product_qyqf(const float dci[2],
                                    const ksl_quaternionf_t* KSL_RESTRICT qi,
                                    ksl_quaternionf_t* KSL_RESTRICT qo) {
  qo->x = qi->x * dci[1] + qi->z * dci[0];
  qo->y = qi->y * dci[1] + qi->w * dci[0];
  qo->z = qi->z * dci[1] - qi->x * dci[0];
  qo->w = qi->w * dci[1] - qi->y * dci[0];
}

static inline void ksl_product_qqy(const ksl_quaternion_t* KSL_RESTRICT qi,
                                   const double dci[2],
                                   ksl_quaternion_t* KSL_RESTRICT qo) {
  qo->x = qi->x * dci[1] - qi->z * dci[0];
  qo->y = qi->y * dci[1] + qi->w * dci[0];
  qo->z = qi->z * dci[1] + qi->x * dci[0];
  qo->w = qi->w * dci[1] - qi->y * dci[0];
}

static inline void ksl_product_qqyf(const ksl_quaternionf_t* KSL_RESTRICT qi,
                                    const float dci[2],
                                    ksl_quaternionf_t* KSL_RESTRICT qo) {
  qo->x = qi->x * dci[1] - qi->z * dci[0];
  qo->y = qi->y * dci[1] + qi->w * dci[0];
  qo->z = qi->z * dci[1] + qi->x * dci[0];
  qo->w = qi->w * dci[1] - qi->y * dci[0];
}

static inline void ksl_product_qyconjq(const double dci[2],
                                       const ksl_quaternion_t* KSL_RESTRICT qi,
                                       ksl_quaternion_t* KSL_RESTRICT qo) {
  qo->x = qi->x * dci[1] - qi->z * dci[0];
  qo->y = qi->y * dci[1] - qi->w * dci[0];
  qo->z = qi->z * dci[1] + qi->x * dci[0];
  qo->w = qi->w * dci[1] + qi->y * dci[0];
}

static inline void
ksl_product_qyconjqf(const float dci[2],
                     const ksl_quaternionf_t* KSL_RESTRICT qi,
                     ksl_quaternionf_t* KSL_RESTRICT qo) {
  qo->x = qi->x * dci[1] - qi->z * dci[0];
  qo->y = qi->y * dci[1] - qi->w * dci[0];
  qo->z = qi->z * dci[1] + qi->x * dci[0];
  qo->w = qi->w * dci[1] + qi->y * dci[0];
}

static inline void ksl_product_qqyconj(const ksl_quaternion_t* KSL_RESTRICT qi,
                                       const double dci[2],
                                       ksl_quaternion_t* KSL_RESTRICT qo) {
  qo->x = qi->x * dci[1] + qi->z * dci[0];
  qo->y = qi->y * dci[1] - qi->w * dci[0];
  qo->z = qi->z * dci[1] - qi->x * dci[0];
  qo->w = qi->w * dci[1] + qi->y * dci[0];
}

static inline void
ksl_product_qqyconjf(const ksl_quaternionf_t* KSL_RESTRICT qi,
                     const float dci[2], ksl_quaternionf_t* KSL_RESTRICT qo) {
  qo->x = qi->x * dci[1] + qi->z * dci[0];
  qo->y = qi->y * dci[1] - qi->w * dci[0];
  qo->z = qi->z * dci[1] - qi->x * dci[0];
  qo->w = qi->w * dci[1] + qi->y * dci[0];
}

static inline void ksl_product_qyqconj(const double dci[2],
                                       const ksl_quaternion_t* KSL_RESTRICT qi,
                                       ksl_quaternion_t* KSL_RESTRICT qo) {
  qo->x = -qi->x * dci[1] - qi->z * dci[0];
  qo->y = -qi->y * dci[1] + qi->w * dci[0];
  qo->z = -qi->z * dci[1] + qi->x * dci[0];
  qo->w = qi->w * dci[1] + qi->y * dci[0];
}

static inline void
ksl_product_qyqconjf(const float dci[2],
                     const ksl_quaternionf_t* KSL_RESTRICT qi,
                     ksl_quaternionf_t* KSL_RESTRICT qo) {
  qo->x = -qi->x * dci[1] - qi->z * dci[0];
  qo->y = -qi->y * dci[1] + qi->w * dci[0];
  qo->z = -qi->z * dci[1] + qi->x * dci[0];
  qo->w = qi->w * dci[1] + qi->y * dci[0];
}

static inline void ksl_product_qconjqy(const ksl_quaternion_t* KSL_RESTRICT qi,
                                       const double dci[2],
                                       ksl_quaternion_t* KSL_RESTRICT qo) {
  qo->x = -qi->x * dci[1] + qi->z * dci[0];
  qo->y = -qi->y * dci[1] + qi->w * dci[0];
  qo->z = -qi->z * dci[1] - qi->x * dci[0];
  qo->w = qi->w * dci[1] + qi->y * dci[0];
}

static inline void
ksl_product_qconjqyf(const ksl_quaternionf_t* KSL_RESTRICT qi,
                     const float dci[2], ksl_quaternionf_t* KSL_RESTRICT qo) {
  qo->x = -qi->x * dci[1] + qi->z * dci[0];
  qo->y = -qi->y * dci[1] + qi->w * dci[0];
  qo->z = -qi->z * dci[1] - qi->x * dci[0];
  qo->w = qi->w * dci[1] + qi->y * dci[0];
}

static inline void
ksl_product_qyconjqconj(const double dci[2],
                        const ksl_quaternion_t* KSL_RESTRICT qi,
                        ksl_quaternion_t* KSL_RESTRICT qo) {
  qo->x = -qi->x * dci[1] + qi->z * dci[0];
  qo->y = -qi->y * dci[1] - qi->w * dci[0];
  qo->z = -qi->z * dci[1] - qi->x * dci[0];
  qo->w = qi->w * dci[1] - qi->y * dci[0];
}

static inline void
ksl_product_qyconjqconjf(const float dci[2],
                         const ksl_quaternionf_t* KSL_RESTRICT qi,
                         ksl_quaternionf_t* KSL_RESTRICT qo) {
  qo->x = -qi->x * dci[1] + qi->z * dci[0];
  qo->y = -qi->y * dci[1] - qi->w * dci[0];
  qo->z = -qi->z * dci[1] - qi->x * dci[0];
  qo->w = qi->w * dci[1] - qi->y * dci[0];
}

static inline void
ksl_product_qconjqyconj(const ksl_quaternion_t* KSL_RESTRICT qi,
                        const double dci[2],
                        ksl_quaternion_t* KSL_RESTRICT qo) {
  qo->x = -qi->x * dci[1] - qi->z * dci[0];
  qo->y = -qi->y * dci[1] - qi->w * dci[0];
  qo->z = -qi->z * dci[1] + qi->x * dci[0];
  qo->w = qi->w * dci[1] - qi->y * dci[0];
}

static inline void
ksl_product_qconjqyconjf(const ksl_quaternionf_t* KSL_RESTRICT qi,
                         const float dci[2],
                         ksl_quaternionf_t* KSL_RESTRICT qo) {
  qo->x = -qi->x * dci[1] - qi->z * dci[0];
  qo->y = -qi->y * dci[1] - qi->w * dci[0];
  qo->z = -qi->z * dci[1] + qi->x * dci[0];
  qo->w = qi->w * dci[1] - qi->y * dci[0];
}

static inline void ksl_product_qzq(const double dci[2],
                                   const ksl_quaternion_t* KSL_RESTRICT qi,
                                   ksl_quaternion_t* KSL_RESTRICT qo) {
  qo->x = qi->x * dci[1] - qi->y * dci[0];
  qo->y = qi->y * dci[1] + qi->x * dci[0];
  qo->z = qi->z * dci[1] + qi->w * dci[0];
  qo->w = qi->w * dci[1] - qi->z * dci[0];
}

static inline void ksl_product_qzqf(const float dci[2],
                                    const ksl_quaternionf_t* KSL_RESTRICT qi,
                                    ksl_quaternionf_t* KSL_RESTRICT qo) {
  qo->x = qi->x * dci[1] - qi->y * dci[0];
  qo->y = qi->y * dci[1] + qi->x * dci[0];
  qo->z = qi->z * dci[1] + qi->w * dci[0];
  qo->w = qi->w * dci[1] - qi->z * dci[0];
}

static inline void ksl_product_qqz(const ksl_quaternion_t* KSL_RESTRICT qi,
                                   const double dci[2],
                                   ksl_quaternion_t* KSL_RESTRICT qo) {
  qo->x = qi->x * dci[1] + qi->y * dci[0];
  qo->y = qi->y * dci[1] - qi->x * dci[0];
  qo->z = qi->z * dci[1] + qi->w * dci[0];
  qo->w = qi->w * dci[1] - qi->z * dci[0];
}

static inline void ksl_product_qqzf(const ksl_quaternionf_t* KSL_RESTRICT qi,
                                    const float dci[2],
                                    ksl_quaternionf_t* KSL_RESTRICT qo) {
  qo->x = qi->x * dci[1] + qi->y * dci[0];
  qo->y = qi->y * dci[1] - qi->x * dci[0];
  qo->z = qi->z * dci[1] + qi->w * dci[0];
  qo->w = qi->w * dci[1] - qi->z * dci[0];
}

static inline void ksl_product_qzconjq(const double dci[2],
                                       const ksl_quaternion_t* KSL_RESTRICT qi,
                                       ksl_quaternion_t* KSL_RESTRICT qo) {
  qo->x = qi->x * dci[1] + qi->y * dci[0];
  qo->y = qi->y * dci[1] - qi->x * dci[0];
  qo->z = qi->z * dci[1] - qi->w * dci[0];
  qo->w = qi->w * dci[1] + qi->z * dci[0];
}

static inline void
ksl_product_qzconjqf(const float dci[2],
                     const ksl_quaternionf_t* KSL_RESTRICT qi,
                     ksl_quaternionf_t* KSL_RESTRICT qo) {
  qo->x = qi->x * dci[1] + qi->y * dci[0];
  qo->y = qi->y * dci[1] - qi->x * dci[0];
  qo->z = qi->z * dci[1] - qi->w * dci[0];
  qo->w = qi->w * dci[1] + qi->z * dci[0];
}

static inline void ksl_product_qqzconj(const ksl_quaternion_t* KSL_RESTRICT qi,
                                       const double dci[2],
                                       ksl_quaternion_t* KSL_RESTRICT qo) {
  qo->x = qi->x * dci[1] - qi->y * dci[0];
  qo->y = qi->y * dci[1] + qi->x * dci[0];
  qo->z = qi->z * dci[1] - qi->w * dci[0];
  qo->w = qi->w * dci[1] + qi->z * dci[0];
}

static inline void
ksl_product_qqzconjf(const ksl_quaternionf_t* KSL_RESTRICT qi,
                     const float dci[2], ksl_quaternionf_t* KSL_RESTRICT qo) {
  qo->x = qi->x * dci[1] - qi->y * dci[0];
  qo->y = qi->y * dci[1] + qi->x * dci[0];
  qo->z = qi->z * dci[1] - qi->w * dci[0];
  qo->w = qi->w * dci[1] + qi->z * dci[0];
}

static inline void ksl_product_qzqconj(const double dci[2],
                                       const ksl_quaternion_t* KSL_RESTRICT qi,
                                       ksl_quaternion_t* KSL_RESTRICT qo) {
  qo->x = -qi->x * dci[1] + qi->y * dci[0];
  qo->y = -qi->y * dci[1] - qi->x * dci[0];
  qo->z = -qi->z * dci[1] + qi->w * dci[0];
  qo->w = qi->w * dci[1] + qi->z * dci[0];
}

static inline void
ksl_product_qzqconjf(const float dci[2],
                     const ksl_quaternionf_t* KSL_RESTRICT qi,
                     ksl_quaternionf_t* KSL_RESTRICT qo) {
  qo->x = -qi->x * dci[1] + qi->y * dci[0];
  qo->y = -qi->y * dci[1] - qi->x * dci[0];
  qo->z = -qi->z * dci[1] + qi->w * dci[0];
  qo->w = qi->w * dci[1] + qi->z * dci[0];
}

static inline void ksl_product_qconjqz(const ksl_quaternion_t* KSL_RESTRICT qi,
                                       const double dci[2],
                                       ksl_quaternion_t* KSL_RESTRICT qo) {
  qo->x = -qi->x * dci[1] - qi->y * dci[0];
  qo->y = -qi->y * dci[1] + qi->x * dci[0];
  qo->z = -qi->z * dci[1] + qi->w * dci[0];
  qo->w = qi->w * dci[1] + qi->z * dci[0];
}

static inline void
ksl_product_qconjqzf(const ksl_quaternionf_t* KSL_RESTRICT qi,
                     const float dci[2], ksl_quaternionf_t* KSL_RESTRICT qo) {
  qo->x = -qi->x * dci[1] - qi->y * dci[0];
  qo->y = -qi->y * dci[1] + qi->x * dci[0];
  qo->z = -qi->z * dci[1] + qi->w * dci[0];
  qo->w = qi->w * dci[1] + qi->z * dci[0];
}

static inline void
ksl_product_qzconjqconj(const double dci[2],
                        const ksl_quaternion_t* KSL_RESTRICT qi,
                        ksl_quaternion_t* KSL_RESTRICT qo) {
  qo->x = -qi->x * dci[1] - qi->y * dci[0];
  qo->y = -qi->y * dci[1] + qi->x * dci[0];
  qo->z = -qi->z * dci[1] - qi->w * dci[0];
  qo->w = qi->w * dci[1] - qi->z * dci[0];
}

static inline void
ksl_product_qzconjqconjf(const float dci[2],
                         const ksl_quaternionf_t* KSL_RESTRICT qi,
                         ksl_quaternionf_t* KSL_RESTRICT qo) {
  qo->x = -qi->x * dci[1] - qi->y * dci[0];
  qo->y = -qi->y * dci[1] + qi->x * dci[0];
  qo->z = -qi->z * dci[1] - qi->w * dci[0];
  qo->w = qi->w * dci[1] - qi->z * dci[0];
}

static inline void
ksl_product_qconjqzconj(const ksl_quaternion_t* KSL_RESTRICT qi,
                        const double dci[2],
                        ksl_quaternion_t* KSL_RESTRICT qo) {
  qo->x = -qi->x * dci[1] + qi->y * dci[0];
  qo->y = -qi->y * dci[1] - qi->x * dci[0];
  qo->z = -qi->z * dci[1] - qi->w * dci[0];
  qo->w = qi->w * dci[1] - qi->z * dci[0];
}

static inline void
ksl_product_qconjqzconjf(const ksl_quaternionf_t* KSL_RESTRICT qi,
                         const float dci[2],
                         ksl_quaternionf_t* KSL_RESTRICT qo) {
  qo->x = -qi->x * dci[1] + qi->y * dci[0];
  qo->y = -qi->y * dci[1] - qi->x * dci[0];
  qo->z = -qi->z * dci[1] - qi->w * dci[0];
  qo->w = qi->w * dci[1] - qi->z * dci[0];
}

/*!
@brief Product of a quaternion and a vector, qo = qi * {vi, 0}.

The vector is treated as a quaternion with zero scalar part:
\f[
q_o = q \begin{Bmatrix} \underline{v} \\ 0 \end{Bmatrix}
\f]

@param qi [in] quaternion
@param vi [in] vector
@param qo [out] product
*/
static inline void ksl_product_qv(const ksl_quaternion_t* KSL_RESTRICT qi,
                                  const ksl_vec3_t* KSL_RESTRICT vi,
                                  ksl_quaternion_t* KSL_RESTRICT qo) {
  /*
                  | qiw -qiz  qiy  qix| |vix|
  qo = L(qi)*vi = | qiz  qiw -qix  qiy| |viy|
                  |-qiy  qix  qiw  qiz| |viz|
                  |-qix -qiy -qiz  qiw| | 0 |
*/

  qo->x = qi->w * vi->x - qi->z * vi->y + qi->y * vi->z;
  qo->y = qi->z * vi->x + qi->w * vi->y - qi->x * vi->z;
  qo->z = -qi->y * vi->x + qi->x * vi->y + qi->w * vi->z;
  qo->w = -qi->x * vi->x - qi->y * vi->y - qi->z * vi->z;
}

/*!
@brief Single precision version of ksl_product_qv().
*/
static inline void ksl_product_qvf(const ksl_quaternionf_t* KSL_RESTRICT qi,
                                   const ksl_vec3f_t* KSL_RESTRICT vi,
                                   ksl_quaternionf_t* KSL_RESTRICT qo) {
  /*
                  | qiw -qiz  qiy  qix| |vix|
  qo = L(qi)*vi = | qiz  qiw -qix  qiy| |viy|
                  |-qiy  qix  qiw  qiz| |viz|
                  |-qix -qiy -qiz  qiw| | 0 |
*/

  qo->x = qi->w * vi->x - qi->z * vi->y + qi->y * vi->z;
  qo->y = qi->z * vi->x + qi->w * vi->y - qi->x * vi->z;
  qo->z = -qi->y * vi->x + qi->x * vi->y + qi->w * vi->z;
  qo->w = -qi->x * vi->x - qi->y * vi->y - qi->z * vi->z;
}

/*!
@brief Product of a quaternion and a vector, qo = conj(qi) * {vi, 0}.

The vector is treated as a quaternion with zero scalar part:
\f[
q_o = q^* \begin{Bmatrix} \underline{v} \\ 0 \end{Bmatrix}
\f]

@param qi [in] quaternion
@param vi [in] vector
@param qo [out] product
*/
static inline void ksl_product_qconjv(const ksl_quaternion_t* KSL_RESTRICT qi,
                                      const ksl_vec3_t* KSL_RESTRICT vi,
                                      ksl_quaternion_t* KSL_RESTRICT qo) {
  /*
                    | qiw  qiz -qiy -qix| |vix|
  qo = L(qi)^T*vi = |-qiz  qiw  qix -qiy| |viy|
                    | qiy -qix  qiw -qiz| |viz|
                    | qix  qiy  qiz  qiw| | 0 |
  */

  qo->x = qi->w * vi->x + qi->z * vi->y - qi->y * vi->z;
  qo->y = -qi->z * vi->x + qi->w * vi->y + qi->x * vi->z;
  qo->z = qi->y * vi->x - qi->x * vi->y + qi->w * vi->z;
  qo->w = qi->x * vi->x + qi->y * vi->y + qi->z * vi->z;
}

/*!
@brief Single precision version of ksl_product_qconjv().
*/
static inline void ksl_product_qconjvf(const ksl_quaternionf_t* KSL_RESTRICT qi,
                                       const ksl_vec3f_t* KSL_RESTRICT vi,
                                       ksl_quaternionf_t* KSL_RESTRICT qo) {
  /*
                    | qiw  qiz -qiy -qix| |vix|
  qo = L(qi)^T*vi = |-qiz  qiw  qix -qiy| |viy|
                    | qiy -qix  qiw -qiz| |viz|
                    | qix  qiy  qiz  qiw| | 0 |
  */
  qo->x = qi->w * vi->x + qi->z * vi->y - qi->y * vi->z;
  qo->y = -qi->z * vi->x + qi->w * vi->y + qi->x * vi->z;
  qo->z = qi->y * vi->x - qi->x * vi->y + qi->w * vi->z;
  qo->w = qi->x * vi->x + qi->y * vi->y + qi->z * vi->z;
}

/*!
@brief Product of a quaternion and a vector, qo = {vi, 0} * qi.

The vector is treated as a quaternion with zero scalar part:
\f[
q_o = \begin{Bmatrix} \underline{v} \\ 0 \end{Bmatrix} q
\f]

@param vi [in] vector
@param qi [in] quaternion
@param qo [out] product
*/
static inline void ksl_product_vq(const ksl_vec3_t* KSL_RESTRICT vi,
                                  const ksl_quaternion_t* KSL_RESTRICT qi,
                                  ksl_quaternion_t* KSL_RESTRICT qo) {
  /*
                 | qiw  qiz -qiy  qix| |vix|
  qo =R(qi)*vi = |-qiz  qiw  qix  qiy| |viy|
                 | qiy -qix  qiw  qiz| |viz|
                 |-qix -qiy -qiz  qiw| | 0 |
  */
  qo->x = qi->w * vi->x + qi->z * vi->y - qi->y * vi->z;
  qo->y = -qi->z * vi->x + qi->w * vi->y + qi->x * vi->z;
  qo->z = qi->y * vi->x - qi->x * vi->y + qi->w * vi->z;
  qo->w = -qi->x * vi->x - qi->y * vi->y - qi->z * vi->z;
}

/*!
@brief Single precision version of ksl_product_vq().
*/
static inline void ksl_product_vqf(const ksl_vec3f_t* KSL_RESTRICT vi,
                                   const ksl_quaternionf_t* KSL_RESTRICT qi,
                                   ksl_quaternionf_t* KSL_RESTRICT qo) {
  /*
                 | qiw  qiz -qiy  qix| |vix|
  qo =R(qi)*vi = |-qiz  qiw  qix  qiy| |viy|
                 | qiy -qix  qiw  qiz| |viz|
                 |-qix -qiy -qiz  qiw| | 0 |
  */
  qo->x = qi->w * vi->x + qi->z * vi->y - qi->y * vi->z;
  qo->y = -qi->z * vi->x + qi->w * vi->y + qi->x * vi->z;
  qo->z = qi->y * vi->x - qi->x * vi->y + qi->w * vi->z;
  qo->w = -qi->x * vi->x - qi->y * vi->y - qi->z * vi->z;
}

/*!
@brief Product of a quaternion and a vector, qo = {vi, 0} * conj(qi).

The vector is treated as a quaternion with zero scalar part:
\f[
q_o = \begin{Bmatrix} \underline{v} \\ 0 \end{Bmatrix} q^*
\f]

@param vi [in] vector
@param qi [in] quaternion
@param qo [out] product
*/
static inline void ksl_product_vqconj(const ksl_vec3_t* KSL_RESTRICT vi,
                                      const ksl_quaternion_t* KSL_RESTRICT qi,
                                      ksl_quaternion_t* KSL_RESTRICT qo) {
  /*
                    | qiw -qiz  qiy -qix| |vix|
  qo = R(qi)^T*vi = | qiz  qiw -qix -qiy| |viy|
                    |-qiy  qix  qiw -qiz| |viz|
                    | qix  qiy  qiz  qiw| | 0 |
  */

  qo->x = qi->w * vi->x - qi->z * vi->y + qi->y * vi->z;
  qo->y = qi->z * vi->x + qi->w * vi->y - qi->x * vi->z;
  qo->z = -qi->y * vi->x + qi->x * vi->y + qi->w * vi->z;
  qo->w = qi->x * vi->x + qi->y * vi->y + qi->z * vi->z;
}

/*!
@brief Single precision version of ksl_product_vqconj().
*/
static inline void ksl_product_vqconjf(const ksl_vec3f_t* KSL_RESTRICT vi,
                                       const ksl_quaternionf_t* KSL_RESTRICT qi,
                                       ksl_quaternionf_t* KSL_RESTRICT qo) {
  /*
                    | qiw -qiz  qiy -qix| |vix|
  qo = R(qi)^T*vi = | qiz  qiw -qix -qiy| |viy|
                    |-qiy  qix  qiw -qiz| |viz|
                    | qix  qiy  qiz  qiw| | 0 |
  */

  qo->x = qi->w * vi->x - qi->z * vi->y + qi->y * vi->z;
  qo->y = qi->z * vi->x + qi->w * vi->y - qi->x * vi->z;
  qo->z = -qi->y * vi->x + qi->x * vi->y + qi->w * vi->z;
  qo->w = qi->x * vi->x + qi->y * vi->y + qi->z * vi->z;
}

#ifdef __cplusplus
}
#endif

#endif
