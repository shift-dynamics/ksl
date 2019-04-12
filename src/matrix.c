#include <assert.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include "ksl/SE3.h"
#include "ksl/mat3x3.h"
#include "ksl/mat4x4.h"
#include "ksl/matrix.h"
#include "ksl/vec3.h"
#include "ksl/vec4.h"

/* matrix vector operations */
inline void ksl_product_drv(const ksl_mat3x3_t* restrict ri,
                            const ksl_vec3_t* restrict vi,
                            ksl_vec3_t* restrict vo) {
  ksl_product_av(vi->x, &ri->v0, vo);
  ksl_axpy_vv(vi->y, &ri->v1, vo);
  ksl_axpy_vv(vi->z, &ri->v2, vo);
}

inline void ksl_product_drvf(const ksl_mat3x3f_t* restrict ri,
                             const ksl_vec3f_t* restrict vi,
                             ksl_vec3f_t* restrict vo) {
  ksl_product_avf(vi->x, &ri->v0, vo);
  ksl_axpy_vvf(vi->y, &ri->v1, vo);
  ksl_axpy_vvf(vi->z, &ri->v2, vo);
}

inline void ksl_product_drvinv(const ksl_mat3x3_t* restrict ri,
                               const ksl_vec3_t* restrict vi,
                               ksl_vec3_t* restrict vo) {
  ksl_product_av(-vi->x, &ri->v0, vo);
  ksl_axpy_vv(-vi->y, &ri->v1, vo);
  ksl_axpy_vv(-vi->z, &ri->v2, vo);
}

inline void ksl_product_drvinvf(const ksl_mat3x3f_t* restrict ri,
                                const ksl_vec3f_t* restrict vi,
                                ksl_vec3f_t* restrict vo) {
  ksl_product_avf(-vi->x, &ri->v0, vo);
  ksl_axpy_vvf(-vi->y, &ri->v1, vo);
  ksl_axpy_vvf(-vi->z, &ri->v2, vo);
}

inline void ksl_product_drinvv(const ksl_mat3x3_t* restrict ri,
                               const ksl_vec3_t* restrict vi,
                               ksl_vec3_t* restrict vo) {
  vo->x = ksl_dot_vv(&ri->v0, vi);
  vo->y = ksl_dot_vv(&ri->v1, vi);
  vo->z = ksl_dot_vv(&ri->v2, vi);
}

inline void ksl_product_drinvvf(const ksl_mat3x3f_t* restrict ri,
                                const ksl_vec3f_t* restrict vi,
                                ksl_vec3f_t* restrict vo) {
  vo->x = ksl_dot_vvf(&ri->v0, vi);
  vo->y = ksl_dot_vvf(&ri->v1, vi);
  vo->z = ksl_dot_vvf(&ri->v2, vi);
}

inline void ksl_product_drinvvinv(const ksl_mat3x3_t* restrict ri,
                                  const ksl_vec3_t* restrict vi,
                                  ksl_vec3_t* restrict vo) {
  vo->x = -ksl_dot_vv(&ri->v0, vi);
  vo->y = -ksl_dot_vv(&ri->v1, vi);
  vo->z = -ksl_dot_vv(&ri->v2, vi);
}

inline void ksl_product_drinvvinvf(const ksl_mat3x3f_t* restrict ri,
                                   const ksl_vec3f_t* restrict vi,
                                   ksl_vec3f_t* restrict vo) {
  vo->x = -ksl_dot_vvf(&ri->v0, vi);
  vo->y = -ksl_dot_vvf(&ri->v1, vi);
  vo->z = -ksl_dot_vvf(&ri->v2, vi);
}

inline void ksl_product_drvtx(const ksl_mat3x3_t* restrict ri, const double tx,
                              ksl_vec3_t* restrict vo) {
  ksl_product_av(tx, &ri->v0, vo);
}

inline void ksl_product_drvtxf(const ksl_mat3x3f_t* restrict ri, const float tx,
                               ksl_vec3f_t* restrict vo) {
  ksl_product_avf(tx, &ri->v0, vo);
}

inline void ksl_product_drvtxinv(const ksl_mat3x3_t* restrict ri,
                                 const double tx, ksl_vec3_t* restrict vo) {
  ksl_product_av(-tx, &ri->v0, vo);
}

inline void ksl_product_drvtxinvf(const ksl_mat3x3f_t* restrict ri,
                                  const float tx, ksl_vec3f_t* restrict vo) {
  ksl_product_avf(-tx, &ri->v0, vo);
}

inline void ksl_product_drvty(const ksl_mat3x3_t* restrict ri, const double ty,
                              ksl_vec3_t* restrict vo) {
  ksl_product_av(ty, &ri->v1, vo);
}

inline void ksl_product_drvtyf(const ksl_mat3x3f_t* restrict ri, const float ty,
                               ksl_vec3f_t* restrict vo) {
  ksl_product_avf(ty, &ri->v1, vo);
}

inline void ksl_product_drvtyinv(const ksl_mat3x3_t* restrict ri,
                                 const double ty, ksl_vec3_t* restrict vo) {
  ksl_product_av(-ty, &ri->v1, vo);
}

inline void ksl_product_drvtyinvf(const ksl_mat3x3f_t* restrict ri,
                                  const float ty, ksl_vec3f_t* restrict vo) {
  ksl_product_avf(-ty, &ri->v1, vo);
}

inline void ksl_product_drvtz(const ksl_mat3x3_t* restrict ri, const double tz,
                              ksl_vec3_t* restrict vo) {
  ksl_product_av(tz, &ri->v2, vo);
}

inline void ksl_product_drvtzf(const ksl_mat3x3f_t* restrict ri, const float tz,
                               ksl_vec3f_t* restrict vo) {
  ksl_product_avf(tz, &ri->v2, vo);
}

inline void ksl_product_drvtzinv(const ksl_mat3x3_t* restrict ri,
                                 const double tz, ksl_vec3_t* restrict vo) {
  ksl_product_av(-tz, &ri->v2, vo);
}

inline void ksl_product_drvtzinvf(const ksl_mat3x3f_t* restrict ri,
                                  const float tz, ksl_vec3f_t* restrict vo) {
  ksl_product_avf(-tz, &ri->v2, vo);
}

/* matrix-matrix operations */
inline void ksl_product_drdrx(const ksl_mat3x3_t* restrict ri,
                              const double dc[2], ksl_mat3x3_t* restrict ro) {
  ksl_vec3_copy(&ri->v0, &ro->v0);
  ksl_product_av(dc[1], &ri->v1, &ro->v1);
  ksl_axpy_vv(dc[0], &ri->v2, &ro->v1);
  ksl_product_av(-dc[0], &ri->v1, &ro->v2);
  ksl_axpy_vv(dc[1], &ri->v2, &ro->v2);
}

inline void ksl_product_drdrxf(const ksl_mat3x3f_t* restrict ri,
                               const float dc[2], ksl_mat3x3f_t* restrict ro) {
  ksl_vec3f_copy(&ri->v0, &ro->v0);
  ksl_product_avf(dc[1], &ri->v1, &ro->v1);
  ksl_axpy_vvf(dc[0], &ri->v2, &ro->v1);
  ksl_product_avf(-dc[0], &ri->v1, &ro->v2);
  ksl_axpy_vvf(dc[1], &ri->v2, &ro->v2);
}

inline void ksl_product_drdrxinv(const ksl_mat3x3_t* restrict ri,
                                 const double dc[2],
                                 ksl_mat3x3_t* restrict ro) {
  ksl_vec3_copy(&ri->v0, &ro->v0);

  ksl_product_av(dc[1], &ri->v1, &ro->v1);
  ksl_axpy_vv(-dc[0], &ri->v2, &ro->v1);

  ksl_product_av(dc[0], &ri->v1, &ro->v2);
  ksl_axpy_vv(dc[1], &ri->v2, &ro->v2);
}

inline void ksl_product_drdrxinvf(const ksl_mat3x3f_t* restrict ri,
                                  const float dc[2],
                                  ksl_mat3x3f_t* restrict ro) {
  ksl_vec3f_copy(&ri->v0, &ro->v0);

  ksl_product_avf(dc[1], &ri->v1, &ro->v1);
  ksl_axpy_vvf(-dc[0], &ri->v2, &ro->v1);

  ksl_product_avf(dc[0], &ri->v1, &ro->v2);
  ksl_axpy_vvf(dc[1], &ri->v2, &ro->v2);
}

inline void ksl_product_drdry(const ksl_mat3x3_t* restrict ri,
                              const double dc[2], ksl_mat3x3_t* restrict ro) {

  ksl_product_av(dc[1], &ri->v0, &ro->v0);
  ksl_axpy_vv(-dc[0], &ri->v2, &ro->v0);

  ksl_vec3_copy(&ri->v1, &ro->v1);

  ksl_product_av(dc[0], &ri->v0, &ro->v2);
  ksl_axpy_vv(dc[1], &ri->v2, &ro->v2);
}

inline void ksl_product_drdryf(const ksl_mat3x3f_t* restrict ri,
                               const float dc[2], ksl_mat3x3f_t* restrict ro) {
  ksl_product_avf(dc[1], &ri->v0, &ro->v0);
  ksl_axpy_vvf(-dc[0], &ri->v2, &ro->v0);

  ksl_vec3f_copy(&ri->v1, &ro->v1);

  ksl_product_avf(dc[0], &ri->v0, &ro->v2);
  ksl_axpy_vvf(dc[1], &ri->v2, &ro->v2);
}

inline void ksl_product_drdryinv(const ksl_mat3x3_t* restrict ri,
                                 const double dc[2],
                                 ksl_mat3x3_t* restrict ro) {
  ksl_product_av(dc[1], &ri->v0, &ro->v0);
  ksl_axpy_vv(dc[0], &ri->v2, &ro->v0);

  ksl_vec3_copy(&ri->v1, &ro->v1);

  ksl_product_av(-dc[0], &ri->v0, &ro->v2);
  ksl_axpy_vv(dc[1], &ri->v2, &ro->v2);
}

inline void ksl_product_drdryinvf(const ksl_mat3x3f_t* restrict ri,
                                  const float dc[2],
                                  ksl_mat3x3f_t* restrict ro) {
  ksl_product_avf(dc[1], &ri->v0, &ro->v0);
  ksl_axpy_vvf(dc[0], &ri->v2, &ro->v0);

  ksl_vec3f_copy(&ri->v1, &ro->v1);

  ksl_product_avf(-dc[0], &ri->v0, &ro->v2);
  ksl_axpy_vvf(dc[1], &ri->v2, &ro->v2);
}

inline void ksl_product_drdrz(const ksl_mat3x3_t* restrict ri,
                              const double dc[2], ksl_mat3x3_t* restrict ro) {
  ksl_product_av(dc[1], &ri->v0, &ro->v0);
  ksl_axpy_vv(dc[0], &ri->v1, &ro->v0);

  ksl_product_av(-dc[0], &ri->v0, &ro->v1);
  ksl_axpy_vv(dc[1], &ri->v1, &ro->v1);

  ksl_vec3_copy(&ri->v2, &ro->v2);
}

inline void ksl_product_drdrzf(const ksl_mat3x3f_t* restrict ri,
                               const float dc[2], ksl_mat3x3f_t* restrict ro) {
  ksl_product_avf(dc[1], &ri->v0, &ro->v0);
  ksl_axpy_vvf(dc[0], &ri->v1, &ro->v0);
  ksl_product_avf(-dc[0], &ri->v0, &ro->v1);
  ksl_axpy_vvf(dc[1], &ri->v1, &ro->v1);
  ksl_vec3f_copy(&ri->v2, &ro->v2);
}

inline void ksl_product_drdrzinv(const ksl_mat3x3_t* restrict ri,
                                 const double dc[2],
                                 ksl_mat3x3_t* restrict ro) {
  ksl_product_av(dc[1], &ri->v0, &ro->v0);
  ksl_axpy_vv(-dc[0], &ri->v1, &ro->v0);
  ksl_product_av(dc[0], &ri->v0, &ro->v1);
  ksl_axpy_vv(dc[1], &ri->v1, &ro->v1);
  ksl_vec3_copy(&ri->v2, &ro->v2);
}

inline void ksl_product_drdrzinvf(const ksl_mat3x3f_t* restrict ri,
                                  const float dc[2],
                                  ksl_mat3x3f_t* restrict ro) {
  ksl_product_avf(dc[1], &ri->v0, &ro->v0);
  ksl_axpy_vvf(-dc[0], &ri->v1, &ro->v0);
  ksl_product_avf(dc[0], &ri->v0, &ro->v1);
  ksl_axpy_vvf(dc[1], &ri->v1, &ro->v1);
  ksl_vec3f_copy(&ri->v2, &ro->v2);
}

inline void ksl_product_drdr(const ksl_mat3x3_t* restrict r1i,
                             const ksl_mat3x3_t* restrict r2i,
                             ksl_mat3x3_t* restrict ro) {
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

inline void ksl_product_drdrf(const ksl_mat3x3f_t* restrict r1i,
                              const ksl_mat3x3f_t* restrict r2i,
                              ksl_mat3x3f_t* restrict ro) {
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

inline void ksl_product_drdrinv(const ksl_mat3x3_t* restrict r1i,
                                const ksl_mat3x3_t* restrict r2i,
                                ksl_mat3x3_t* restrict ro) {
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

inline void ksl_product_drdrinvf(const ksl_mat3x3f_t* restrict r1i,
                                 const ksl_mat3x3f_t* restrict r2i,
                                 ksl_mat3x3f_t* restrict ro) {
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

inline void ksl_product_drinvdr(const ksl_mat3x3_t* restrict r1i,
                                const ksl_mat3x3_t* restrict r2i,
                                ksl_mat3x3_t* restrict ro) {
  ro->m00 = r1i->m00 * r2i->m00 + r1i->m10 * r2i->m10 + r1i->m20 * r2i->m20;
  ro->m01 = r1i->m00 * r2i->m01 + r1i->m10 * r2i->m11 + r1i->m20 * r2i->m21;
  ro->m02 = r1i->m00 * r2i->m02 + r1i->m10 * r2i->m12 + r1i->m20 * r2i->m22;
  ro->m10 = r1i->m01 * r2i->m00 + r1i->m11 * r2i->m10 + r1i->m21 * r2i->m20;
  ro->m11 = r1i->m01 * r2i->m01 + r1i->m11 * r2i->m11 + r1i->m21 * r2i->m21;
  ro->m12 = r1i->m01 * r2i->m02 + r1i->m11 * r2i->m12 + r1i->m21 * r2i->m22;
  ro->m20 = r1i->m02 * r2i->m00 + r1i->m12 * r2i->m10 + r1i->m22 * r2i->m20;
  ro->m21 = r1i->m02 * r2i->m01 + r1i->m12 * r2i->m11 + r1i->m22 * r2i->m21;
  ro->m22 = r1i->m02 * r2i->m02 + r1i->m12 * r2i->m12 + r1i->m22 * r2i->m22;
}

inline void ksl_product_drinvdrf(const ksl_mat3x3f_t* restrict r1i,
                                 const ksl_mat3x3f_t* restrict r2i,
                                 ksl_mat3x3f_t* restrict ro) {
  ro->m00 = r1i->m00 * r2i->m00 + r1i->m10 * r2i->m10 + r1i->m20 * r2i->m20;
  ro->m01 = r1i->m00 * r2i->m01 + r1i->m10 * r2i->m11 + r1i->m20 * r2i->m21;
  ro->m02 = r1i->m00 * r2i->m02 + r1i->m10 * r2i->m12 + r1i->m20 * r2i->m22;
  ro->m10 = r1i->m01 * r2i->m00 + r1i->m11 * r2i->m10 + r1i->m21 * r2i->m20;
  ro->m11 = r1i->m01 * r2i->m01 + r1i->m11 * r2i->m11 + r1i->m21 * r2i->m21;
  ro->m12 = r1i->m01 * r2i->m02 + r1i->m11 * r2i->m12 + r1i->m21 * r2i->m22;
  ro->m20 = r1i->m02 * r2i->m00 + r1i->m12 * r2i->m10 + r1i->m22 * r2i->m20;
  ro->m21 = r1i->m02 * r2i->m01 + r1i->m12 * r2i->m11 + r1i->m22 * r2i->m21;
  ro->m22 = r1i->m02 * r2i->m02 + r1i->m12 * r2i->m12 + r1i->m22 * r2i->m22;
}

inline void ksl_product_dv(const ksl_SE3_t* restrict Di,
                           const ksl_vec3_t* restrict vi,
                           ksl_vec3_t* restrict vo) {
  ksl_product_drv(&(Di->R), vi, vo);
  ksl_xpy_vv(&Di->t, vo);
}

inline void ksl_product_dvf(const ksl_SE3f_t* restrict Di,
                            const ksl_vec3f_t* restrict vi,
                            ksl_vec3f_t* restrict vo) {
  ksl_product_drvf(&(Di->R), vi, vo);
  ksl_xpy_vvf(&Di->t, vo);
}

inline void ksl_product_dinvv(const ksl_SE3_t* restrict Di,
                              const ksl_vec3_t* restrict vi,
                              ksl_vec3_t* restrict vo) {
  ksl_vec3_t temp;
  ksl_product_drinvv(&Di->R, &Di->t, &temp); /* R^-1 * t -> temp*/
  ksl_product_drinvv(&Di->R, vi, vo);        /* R^-1 * vi -> vo */
  ksl_nxpy_vv(&temp, vo);                    /* vo -= temp */
}

inline void ksl_product_dinvvf(const ksl_SE3f_t* restrict Di,
                               const ksl_vec3f_t* restrict vi,
                               ksl_vec3f_t* restrict vo) {
  ksl_vec3f_t temp;
  ksl_product_drinvvf(&Di->R, &Di->t, &temp); /* R^-1 * t -> temp*/
  ksl_product_drinvvf(&Di->R, vi, vo);        /* R^-1 * vi -> vo */
  ksl_nxpy_vvf(&temp, vo);                    /* vo -= temp */
}

inline void ksl_product_ddrx(const ksl_SE3_t* restrict Di, const double dc[2],
                             ksl_SE3_t* restrict Do) {
  ksl_product_drdrx(&Di->R, dc, &Do->R);
  ksl_vec3_copy(&Di->t, &Do->t);
}

inline void ksl_product_ddrxf(const ksl_SE3f_t* restrict Di, const float dc[2],
                              ksl_SE3f_t* restrict Do) {
  ksl_product_drdrxf(&Di->R, dc, &Do->R);
  ksl_vec3f_copy(&Di->t, &Do->t);
}

inline void ksl_product_ddrxinv(const ksl_SE3_t* restrict Di,
                                const double dc[2], ksl_SE3_t* restrict Do) {
  ksl_product_drdrxinv(&Di->R, dc, &Do->R);
  ksl_vec3_copy(&Di->t, &Do->t);
}

inline void ksl_product_ddrxinvf(const ksl_SE3f_t* restrict Di,
                                 const float dc[2], ksl_SE3f_t* restrict Do) {
  ksl_product_drdrxinvf(&Di->R, dc, &Do->R);
  ksl_vec3f_copy(&Di->t, &Do->t);
}

inline void ksl_product_ddry(const ksl_SE3_t* restrict Di, const double dc[2],
                             ksl_SE3_t* restrict Do) {
  ksl_product_drdry(&Di->R, dc, &Do->R);
  ksl_vec3_copy(&Di->t, &Do->t);
}

inline void ksl_product_ddryf(const ksl_SE3f_t* restrict Di, const float dc[2],
                              ksl_SE3f_t* restrict Do) {
  ksl_product_drdryf(&Di->R, dc, &Do->R);
  ksl_vec3f_copy(&Di->t, &Do->t);
}

inline void ksl_product_ddryinv(const ksl_SE3_t* restrict Di,
                                const double dc[2], ksl_SE3_t* restrict Do) {
  ksl_product_drdryinv(&Di->R, dc, &Do->R);
  ksl_vec3_copy(&Di->t, &Do->t);
}

inline void ksl_product_ddryinvf(const ksl_SE3f_t* restrict Di,
                                 const float dc[2], ksl_SE3f_t* restrict Do) {
  ksl_product_drdryinvf(&Di->R, dc, &Do->R);
  ksl_vec3f_copy(&Di->t, &Do->t);
}

inline void ksl_product_ddrz(const ksl_SE3_t* restrict Di, const double dc[2],
                             ksl_SE3_t* restrict Do) {
  ksl_product_drdrz(&Di->R, dc, &Do->R);
  ksl_vec3_copy(&Di->t, &Do->t);
}

inline void ksl_product_ddrzf(const ksl_SE3f_t* restrict Di, const float dc[2],
                              ksl_SE3f_t* restrict Do) {
  ksl_product_drdrzf(&Di->R, dc, &Do->R);
  ksl_vec3f_copy(&Di->t, &Do->t);
}

inline void ksl_product_ddrzinv(const ksl_SE3_t* restrict Di,
                                const double dc[2], ksl_SE3_t* restrict Do) {
  ksl_product_drdrzinv(&Di->R, dc, &Do->R);
  ksl_vec3_copy(&Di->t, &Do->t);
}

inline void ksl_product_ddrzinvf(const ksl_SE3f_t* restrict Di,
                                 const float dc[2], ksl_SE3f_t* restrict Do) {
  ksl_product_drdrzinvf(&Di->R, dc, &Do->R);
  ksl_vec3f_copy(&Di->t, &Do->t);
}

inline void ksl_product_ddt(const ksl_SE3_t* restrict Di,
                            const ksl_vec3_t* restrict t,
                            ksl_SE3_t* restrict Do) {
  ksl_mat3x3_copy(&Di->R, &Do->R);
  ksl_product_drv(&Di->R, t, &Do->t);
  ksl_xpy_vv(&Di->t, &Do->t);
}

inline void ksl_product_ddtf(const ksl_SE3f_t* restrict Di,
                             const ksl_vec3f_t* restrict t,
                             ksl_SE3f_t* restrict Do) {
  ksl_mat3x3f_copy(&Di->R, &Do->R);
  ksl_product_drvf(&Di->R, t, &Do->t);
  ksl_xpy_vvf(&Di->t, &Do->t);
}

inline void ksl_product_ddtinv(const ksl_SE3_t* restrict Di,
                               const ksl_vec3_t* restrict t,
                               ksl_SE3_t* restrict Do) {
  ksl_mat3x3_copy(&Di->R, &Do->R);
  ksl_product_drvinv(&Di->R, t, &Do->t);
  ksl_xpy_vv(&Di->t, &Do->t);
}

inline void ksl_product_ddtinvf(const ksl_SE3f_t* restrict Di,
                                const ksl_vec3f_t* restrict t,
                                ksl_SE3f_t* restrict Do) {
  ksl_mat3x3f_copy(&Di->R, &Do->R);
  ksl_product_drvinvf(&Di->R, t, &Do->t);
  ksl_xpy_vvf(&Di->t, &Do->t);
}

inline void ksl_product_dinvdt(const ksl_SE3_t* restrict Di,
                               const ksl_vec3_t* restrict t,
                               ksl_SE3_t* restrict Do) {
  ksl_vec3_t temp;
  ksl_subtract_vv(t, &Di->t, &temp);
  ksl_mat3x3_transposed(&Di->R, &Do->R);
  ksl_product_drinvv(&Di->R, &temp, &Do->t);
}

inline void ksl_product_dinvdtf(const ksl_SE3f_t* restrict Di,
                                const ksl_vec3f_t* restrict t,
                                ksl_SE3f_t* restrict Do) {
  ksl_vec3f_t temp;
  ksl_subtract_vvf(t, &Di->t, &temp);
  ksl_mat3x3f_transposed(&Di->R, &Do->R);
  ksl_product_drinvvf(&Di->R, &temp, &Do->t);
}

inline void ksl_product_ddtx(const ksl_SE3_t* restrict Di, const double ti,
                             ksl_SE3_t* restrict Do) {
  ksl_mat3x3_copy(&Di->R, &Do->R);
  ksl_product_drvtx(&Di->R, ti, &Do->t);
  ksl_xpy_vv(&Di->t, &Do->t);
}

inline void ksl_product_ddtxf(const ksl_SE3f_t* restrict Di, const float ti,
                              ksl_SE3f_t* restrict Do) {
  ksl_mat3x3f_copy(&Di->R, &Do->R);
  ksl_product_drvtxf(&Di->R, ti, &Do->t);
  ksl_xpy_vvf(&Di->t, &Do->t);
}

inline void ksl_product_ddtxinv(const ksl_SE3_t* restrict Di, const double ti,
                                ksl_SE3_t* restrict Do) {
  ksl_mat3x3_copy(&Di->R, &Do->R);
  ksl_product_drvtxinv(&Di->R, ti, &Do->t);
  ksl_xpy_vv(&Di->t, &Do->t);
}

inline void ksl_product_ddtxinvf(const ksl_SE3f_t* restrict Di, const float ti,
                                 ksl_SE3f_t* restrict Do) {
  ksl_mat3x3f_copy(&Di->R, &Do->R);
  ksl_product_drvtxinvf(&Di->R, ti, &Do->t);
  ksl_xpy_vvf(&Di->t, &Do->t);
}

inline void ksl_product_ddty(const ksl_SE3_t* restrict Di, const double ti,
                             ksl_SE3_t* restrict Do) {
  ksl_mat3x3_copy(&Di->R, &Do->R);
  ksl_product_drvty(&Di->R, ti, &Do->t);
  ksl_xpy_vv(&Di->t, &Do->t);
}

inline void ksl_product_ddtyf(const ksl_SE3f_t* restrict Di, const float ti,
                              ksl_SE3f_t* restrict Do) {
  ksl_mat3x3f_copy(&Di->R, &Do->R);
  ksl_product_drvtyf(&Di->R, ti, &Do->t);
  ksl_xpy_vvf(&Di->t, &Do->t);
}

inline void ksl_product_ddtyinv(const ksl_SE3_t* restrict Di, const double ti,
                                ksl_SE3_t* restrict Do) {
  ksl_mat3x3_copy(&Di->R, &Do->R);
  ksl_product_drvtyinv(&Di->R, ti, &Do->t);
  ksl_xpy_vv(&Di->t, &Do->t);
}

inline void ksl_product_ddtyinvf(const ksl_SE3f_t* restrict Di, const float ti,
                                 ksl_SE3f_t* restrict Do) {
  ksl_mat3x3f_copy(&Di->R, &Do->R);
  ksl_product_drvtyinvf(&Di->R, ti, &Do->t);
  ksl_xpy_vvf(&Di->t, &Do->t);
}

inline void ksl_product_ddtz(const ksl_SE3_t* restrict Di, const double ti,
                             ksl_SE3_t* restrict Do) {
  ksl_mat3x3_copy(&Di->R, &Do->R);
  ksl_product_drvtz(&Di->R, ti, &Do->t);
  ksl_xpy_vv(&Di->t, &Do->t);
}

inline void ksl_product_ddtzf(const ksl_SE3f_t* restrict Di, const float ti,
                              ksl_SE3f_t* restrict Do) {
  ksl_mat3x3f_copy(&Di->R, &Do->R);
  ksl_product_drvtzf(&Di->R, ti, &Do->t);
  ksl_xpy_vvf(&Di->t, &Do->t);
}

inline void ksl_product_ddtzinv(const ksl_SE3_t* restrict Di, const double ti,
                                ksl_SE3_t* restrict Do) {
  ksl_mat3x3_copy(&Di->R, &Do->R);
  ksl_product_drvtzinv(&Di->R, ti, &Do->t);
  ksl_xpy_vv(&Di->t, &Do->t);
}

inline void ksl_product_ddtzinvf(const ksl_SE3f_t* restrict Di, const float ti,
                                 ksl_SE3f_t* restrict Do) {
  ksl_mat3x3f_copy(&Di->R, &Do->R);
  ksl_product_drvtzinvf(&Di->R, ti, &Do->t);
  ksl_xpy_vvf(&Di->t, &Do->t);
}

inline void ksl_product_ddr(const ksl_SE3_t* restrict Di,
                            const ksl_mat3x3_t* restrict Ri,
                            ksl_SE3_t* restrict Do) {
  ksl_product_drdr(&Di->R, Ri, &Do->R);
  ksl_vec3_copy(&Di->t, &Do->t);
}

inline void ksl_product_ddrf(const ksl_SE3f_t* restrict Di,
                             const ksl_mat3x3f_t* restrict Ri,
                             ksl_SE3f_t* restrict Do) {
  ksl_product_drdrf(&Di->R, Ri, &Do->R);
  ksl_vec3f_copy(&Di->t, &Do->t);
}

inline void ksl_product_ddrinv(const ksl_SE3_t* restrict Di,
                               const ksl_mat3x3_t* restrict Ri,
                               ksl_SE3_t* restrict Do) {
  ksl_product_drdrinv(&Di->R, Ri, &Do->R);
  ksl_vec3_copy(&Di->t, &Do->t);
}

inline void ksl_product_ddrinvf(const ksl_SE3f_t* restrict Di,
                                const ksl_mat3x3f_t* restrict Ri,
                                ksl_SE3f_t* restrict Do) {
  ksl_product_drdrinvf(&Di->R, Ri, &Do->R);
  ksl_vec3f_copy(&Di->t, &Do->t);
}

inline void ksl_product_dd(const ksl_SE3_t* restrict D1i,
                           const ksl_SE3_t* restrict D2i,
                           ksl_SE3_t* restrict Do) {
  ksl_product_drdr(&D1i->R, &D2i->R, &Do->R);
  ksl_product_drv(&D1i->R, &D2i->t, &Do->t);
  ksl_xpy_vv(&D1i->t, &Do->t);
}

inline void ksl_product_ddf(const ksl_SE3f_t* restrict D1i,
                            const ksl_SE3f_t* restrict D2i,
                            ksl_SE3f_t* restrict Do) {
  ksl_product_drdrf(&D1i->R, &D2i->R, &Do->R);
  ksl_product_drvf(&D1i->R, &D2i->t, &Do->t);
  ksl_xpy_vvf(&D1i->t, &Do->t);
}

inline void ksl_product_ddinv(const ksl_SE3_t* restrict D1i,
                              const ksl_SE3_t* restrict D2i,
                              ksl_SE3_t* restrict Do) {
  ksl_product_drdrinv(&D1i->R, &D2i->R, &Do->R);
  ksl_product_drvinv(&Do->R, &D2i->t, &Do->t);
  ksl_xpy_vv(&D1i->t, &Do->t);
}

inline void ksl_product_ddinvf(const ksl_SE3f_t* D1i, const ksl_SE3f_t* D2i,
                               ksl_SE3f_t* Do) {
  ksl_product_drdrinvf(&D1i->R, &D2i->R, &Do->R);
  ksl_product_drvinvf(&Do->R, &D2i->t, &Do->t);
  ksl_xpy_vvf(&D1i->t, &Do->t);
}

inline void ksl_product_dinvd(const ksl_SE3_t* restrict D1i,
                              const ksl_SE3_t* restrict D2i,
                              ksl_SE3_t* restrict Do) {
  ksl_product_drinvdr(&D1i->R, &D2i->R, &Do->R);
  ksl_vec3_t temp;
  ksl_product_drinvv(&D1i->R, &D1i->t, &temp);
  ksl_product_drv(&D1i->R, &D2i->t, &Do->t);
  ksl_nxpy_vv(&temp, &Do->t);
}

inline void ksl_product_dinvdf(const ksl_SE3f_t* D1i, const ksl_SE3f_t* D2i,
                               ksl_SE3f_t* Do) {
  ksl_product_drinvdrf(&D1i->R, &D2i->R, &Do->R);
  ksl_vec3f_t temp;
  ksl_product_drinvvf(&D1i->R, &D1i->t, &temp);
  ksl_product_drvf(&D1i->R, &D2i->t, &Do->t);
  ksl_nxpy_vvf(&temp, &Do->t);
}

