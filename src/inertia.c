#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "inertia.h"

inline ksl_inertia_t* ksl_inertia_alloc(int n) {
  return calloc(n, sizeof(ksl_inertia_t));
}

inline ksl_inertiaf_t* ksl_inertiaf_alloc(int n) {
  return calloc(n, sizeof(ksl_inertiaf_t));
}

inline void ksl_inertia_copy(const ksl_inertia_t* restrict inertia_i,
                             ksl_inertia_t* restrict inertia_o) {
  memcpy(inertia_o, inertia_i, sizeof(ksl_inertia_t));
}

inline void ksl_inertiaf_copy(const ksl_inertiaf_t* restrict inertia_i,
                              ksl_inertiaf_t* restrict inertia_o) {
  memcpy(inertia_o, inertia_i, sizeof(ksl_inertiaf_t));
}

/*!
@brief rotate a double precision centroidal inertia matrix

  I_ff = CoAd(D(R_{fc})) * Icc * Ad(D(R_{fc}^{-1}))

*/
inline void ksl_inertia_rotated(const ksl_inertia_t* restrict inertia_i,
                                const ksl_mat3x3_t* restrict r,
                                ksl_inertia_t* restrict inertia_o) {

  ksl_vec3_t temp;

  temp.at[0] = r->m00 * inertia_i->Ixx;
  temp.at[0] += r->m01 * inertia_i->Ixy;
  temp.at[0] += r->m02 * inertia_i->Izx;
  temp.at[1] = r->m00 * inertia_i->Ixy;
  temp.at[1] += r->m01 * inertia_i->Iyy;
  temp.at[1] += r->m02 * inertia_i->Iyz;
  temp.at[2] = r->m00 * inertia_i->Izx;
  temp.at[2] += r->m01 * inertia_i->Iyz;
  temp.at[2] += r->m02 * inertia_i->Izz;

  inertia_o->Ixx = temp.x * r->m00 + temp.y * r->m01 + temp.z * r->m02;
  inertia_o->Ixy = temp.x * r->m10 + temp.y * r->m11 + temp.z * r->m12;
  inertia_o->Izx = temp.x * r->m20 + temp.y * r->m21 + temp.z * r->m22;

  temp.at[0] = r->m10 * inertia_i->Ixx;
  temp.at[0] += r->m11 * inertia_i->Ixy;
  temp.at[0] += r->m12 * inertia_i->Izx;
  temp.at[1] = r->m10 * inertia_i->Ixy;
  temp.at[1] += r->m11 * inertia_i->Iyy;
  temp.at[1] += r->m12 * inertia_i->Iyz;
  temp.at[2] = r->m10 * inertia_i->Izx;
  temp.at[2] += r->m11 * inertia_i->Iyz;
  temp.at[2] += r->m12 * inertia_i->Izz;

  inertia_o->Iyy = temp.x * r->m10 + temp.y * r->m11 + temp.z * r->m12;
  inertia_o->Iyz = temp.x * r->m20 + temp.y * r->m21 + temp.z * r->m22;

  temp.at[0] = r->m20 * inertia_i->Ixx;
  temp.at[0] += r->m21 * inertia_i->Ixy;
  temp.at[0] += r->m22 * inertia_i->Izx;
  temp.at[1] = r->m20 * inertia_i->Ixy;
  temp.at[1] += r->m21 * inertia_i->Iyy;
  temp.at[1] += r->m22 * inertia_i->Iyz;
  temp.at[2] = r->m20 * inertia_i->Izx;
  temp.at[2] += r->m21 * inertia_i->Iyz;
  temp.at[2] += r->m22 * inertia_i->Izz;

  inertia_o->Izz = temp.x * r->m20 + temp.y * r->m21 + temp.z * r->m22;
  inertia_o->m = inertia_i->m;

  /* inertia_o->mt = Rfb * m_c * t_bc */
  ksl_product_drv(r, &inertia_i->mt, &inertia_o->mt);
}

/*!
@brief rotate a single precision centroidal inertia matrix

  I_ff = CoAd(D(R_{fc})) * Icc * Ad(D(R_{fc}^{-1}))

*/
inline void ksl_inertiaf_rotated(const ksl_inertiaf_t* restrict inertia_i,
                                 const ksl_mat3x3f_t* restrict r,
                                 ksl_inertiaf_t* restrict inertia_o) {

  ksl_vec3f_t temp;

  temp.at[0] = r->m00 * inertia_i->Ixx;
  temp.at[0] += r->m01 * inertia_i->Ixy;
  temp.at[0] += r->m02 * inertia_i->Izx;
  temp.at[1] = r->m00 * inertia_i->Ixy;
  temp.at[1] += r->m01 * inertia_i->Iyy;
  temp.at[1] += r->m02 * inertia_i->Iyz;
  temp.at[2] = r->m00 * inertia_i->Izx;
  temp.at[2] += r->m01 * inertia_i->Iyz;
  temp.at[2] += r->m02 * inertia_i->Izz;

  inertia_o->Ixx = temp.x * r->m00 + temp.y * r->m01 + temp.z * r->m02;
  inertia_o->Ixy = temp.x * r->m10 + temp.y * r->m11 + temp.z * r->m12;
  inertia_o->Izx = temp.x * r->m20 + temp.y * r->m21 + temp.z * r->m22;

  temp.at[0] = r->m10 * inertia_i->Ixx;
  temp.at[0] += r->m11 * inertia_i->Ixy;
  temp.at[0] += r->m12 * inertia_i->Izx;
  temp.at[1] = r->m10 * inertia_i->Ixy;
  temp.at[1] += r->m11 * inertia_i->Iyy;
  temp.at[1] += r->m12 * inertia_i->Iyz;
  temp.at[2] = r->m10 * inertia_i->Izx;
  temp.at[2] += r->m11 * inertia_i->Iyz;
  temp.at[2] += r->m12 * inertia_i->Izz;

  inertia_o->Iyy = temp.x * r->m10 + temp.y * r->m11 + temp.z * r->m12;
  inertia_o->Iyz = temp.x * r->m20 + temp.y * r->m21 + temp.z * r->m22;

  temp.at[0] = r->m20 * inertia_i->Ixx;
  temp.at[0] += r->m21 * inertia_i->Ixy;
  temp.at[0] += r->m22 * inertia_i->Izx;
  temp.at[1] = r->m20 * inertia_i->Ixy;
  temp.at[1] += r->m21 * inertia_i->Iyy;
  temp.at[1] += r->m22 * inertia_i->Iyz;
  temp.at[2] = r->m20 * inertia_i->Izx;
  temp.at[2] += r->m21 * inertia_i->Iyz;
  temp.at[2] += r->m22 * inertia_i->Izz;

  inertia_o->Izz = temp.x * r->m20 + temp.y * r->m21 + temp.z * r->m22;
  inertia_o->m = inertia_i->m;

  /* inertia_o->mt = Rfb * m_c * t_bc */
  ksl_product_drvf(r, &inertia_i->mt, &inertia_o->mt);
}

/*!
@brief rotate a double precision centroidal inertia matrix in place

  I_ff = CoAd(D(R_{fc})) * Icc * Ad(D(R_{fc}^{-1}))

*/
inline void ksl_inertia_rotate(ksl_inertia_t* restrict inertia_i,
                               const ksl_mat3x3_t* restrict r) {
  ksl_inertia_t inertia_o;
  ksl_inertia_rotated(inertia_i, r, &inertia_o);
  ksl_inertia_copy(&inertia_o, inertia_i);
}

/*!
@brief rotate a single precision centroidal inertia matrix in place

  I_ff = CoAd(D(R_{fc})) * Icc * Ad(D(R_{fc}^{-1}))

*/
inline void ksl_inertiaf_rotate(ksl_inertiaf_t* restrict inertia_i,
                                const ksl_mat3x3f_t* restrict r) {
  ksl_inertiaf_t inertia_o;
  ksl_inertiaf_rotated(inertia_i, r, &inertia_o);
  ksl_inertiaf_copy(&inertia_o, inertia_i);
}

/*!
@brief translate a double precision centroidal inertia matrix

  I_ff = CoAd(D(t_{fc})) * Icc * Ad(D(t_{fc}^{-1}))
*/
void ksl_inertia_translated(const ksl_inertia_t* restrict inertia_i,
                            const ksl_vec3_t* restrict t,
                            ksl_inertia_t* restrict inertia_o) {
  ksl_axpy_vv(inertia_i->m, t, &inertia_o->mt);

  ksl_vec3_t temp;
  memcpy(&temp, &inertia_o->mt, sizeof(ksl_vec3_t));
  assert(inertia_i->m > 0);
  ksl_vec3_scale(&temp, 1 / inertia_i->m);

  inertia_o->Ixy -= inertia_o->mt.x * temp.y;
  inertia_o->Iyz -= inertia_o->mt.y * temp.z;
  inertia_o->Izx -= inertia_o->mt.z * temp.x;

  ksl_vec3_t temp2;
  temp2.x = inertia_o->mt.x * temp.x;
  temp2.y = inertia_o->mt.y * temp.y;
  temp2.z = inertia_o->mt.z * temp.z;

  inertia_o->Ixx += temp2.y + temp2.z;
  inertia_o->Iyy += temp2.x + temp2.z;
  inertia_o->Izz += temp2.x + temp2.y;
}

/*!
@brief translate a single precision centroidal inertia matrix

  I_ff = CoAd(D(t_{fc})) * Icc * Ad(D(t_{fc}^{-1}))
*/
void ksl_inertiaf_translated(const ksl_inertiaf_t* restrict inertia_i,
                             const ksl_vec3f_t* restrict t,
                             ksl_inertiaf_t* restrict inertia_o) {
  ksl_axpy_vvf(inertia_i->m, t, &inertia_o->mt);

  ksl_vec3f_t temp;
  memcpy(&temp, &inertia_o->mt, sizeof(ksl_vec3_t));
  assert(inertia_i->m > 0);
  ksl_vec3f_scale(&temp, 1 / inertia_i->m);

  inertia_o->Ixy -= inertia_o->mt.x * temp.y;
  inertia_o->Iyz -= inertia_o->mt.y * temp.z;
  inertia_o->Izx -= inertia_o->mt.z * temp.x;

  ksl_vec3_t temp2;
  temp2.x = inertia_o->mt.x * temp.x;
  temp2.y = inertia_o->mt.y * temp.y;
  temp2.z = inertia_o->mt.z * temp.z;

  inertia_o->Ixx += temp2.y + temp2.z;
  inertia_o->Iyy += temp2.x + temp2.z;
  inertia_o->Izz += temp2.x + temp2.y;
}

/*!
@brief translate a double precision centroidal inertia matrix in place

  I_ff = CoAd(D(t_{fc})) * Icc * Ad(D(t_{fc}^{-1}))
*/
inline void ksl_inertia_translate(ksl_inertia_t* restrict inertia_i,
                                  const ksl_vec3_t* restrict t) {
  ksl_inertia_t inertia_o;
  ksl_inertia_translated(inertia_i, t, &inertia_o);
  ksl_inertia_copy(&inertia_o, inertia_i);
}

/*!
@brief translate a single precision centroidal inertia matrix in place

  I_ff = CoAd(D(t_{fc})) * Icc * Ad(D(t_{fc}^{-1}))
*/
inline void ksl_inertiaf_translate(ksl_inertiaf_t* restrict inertia_i,
                                   const ksl_vec3f_t* restrict t) {
  ksl_inertiaf_t inertia_o;
  ksl_inertiaf_translated(inertia_i, t, &inertia_o);
  ksl_inertiaf_copy(&inertia_o, inertia_i);
}

/*!
@brief spatial transform a double precision centroidal inertia matrix

  I_ff = CoAd(D_{fc}) * Icc * Ad(D_{fc}^{-1})
*/
inline void ksl_inertia_transformed(const ksl_inertia_t* restrict inertia_i,
                                    const ksl_SE3_t* restrict d,
                                    ksl_inertia_t* restrict inertia_o) {
  ksl_inertia_rotated(inertia_i, &d->R, inertia_o);
  ksl_axpy_vv(inertia_i->m, &d->t, &inertia_o->mt);

  ksl_vec3_t t;
  ksl_vec3_copy(&inertia_o->mt, &t);
  ksl_vec3_scale(&t, 1 / inertia_i->m);

  inertia_o->Ixy -= inertia_o->mt.x * t.y;
  inertia_o->Iyz -= inertia_o->mt.y * t.z;
  inertia_o->Izx -= inertia_o->mt.z * t.x;

  ksl_vec3_t temp2;
  temp2.x = inertia_o->mt.x * t.x;
  temp2.y = inertia_o->mt.y * t.y;
  temp2.z = inertia_o->mt.z * t.z;

  inertia_o->Ixx += temp2.y + temp2.z;
  inertia_o->Iyy += temp2.x + temp2.z;
  inertia_o->Izz += temp2.x + temp2.y;
}

/*!
@brief spatial transform a single precision centroidal inertia matrix

  I_ff = CoAd(D_{fc}) * Icc * Ad(D_{fc}^{-1})
*/
inline void ksl_inertiaf_transformed(const ksl_inertiaf_t* restrict inertia_i,
                                     const ksl_SE3f_t* restrict d,
                                     ksl_inertiaf_t* restrict inertia_o) {
  ksl_inertiaf_rotated(inertia_i, &d->R, inertia_o);
  ksl_axpy_vvf(inertia_i->m, &d->t, &inertia_o->mt);

  ksl_vec3f_t t;
  ksl_vec3f_copy(&inertia_o->mt, &t);
  ksl_vec3f_scale(&t, 1 / inertia_i->m);

  inertia_o->Ixy -= inertia_o->mt.x * t.y;
  inertia_o->Iyz -= inertia_o->mt.y * t.z;
  inertia_o->Izx -= inertia_o->mt.z * t.x;

  ksl_vec3_t temp2;
  temp2.x = inertia_o->mt.x * t.x;
  temp2.y = inertia_o->mt.y * t.y;
  temp2.z = inertia_o->mt.z * t.z;

  inertia_o->Ixx += temp2.y + temp2.z;
  inertia_o->Iyy += temp2.x + temp2.z;
  inertia_o->Izz += temp2.x + temp2.y;
}

/*!
@brief translate a double precision centroidal inertia matrix in place

  I_ff = CoAd(D(t_{fc})) * Icc * Ad(D(t_{fc}^{-1}))
*/
inline void ksl_inertia_transform(ksl_inertia_t* restrict inertia_i,
                                  const ksl_SE3_t* restrict d) {
  ksl_inertia_t inertia_o;
  ksl_inertia_transformed(inertia_i, d, &inertia_o);
  ksl_inertia_copy(&inertia_o, inertia_i);
}

/*!
@brief translate a single precision centroidal inertia matrix in place

  I_ff = CoAd(D(t_{fc})) * Icc * Ad(D(t_{fc}^{-1}))
*/
inline void ksl_inertiaf_transform(ksl_inertiaf_t* restrict inertia_i,
                                   const ksl_SE3f_t* restrict d) {
  ksl_inertiaf_t inertia_o;
  ksl_inertiaf_transformed(inertia_i, d, &inertia_o);
  ksl_inertiaf_copy(&inertia_o, inertia_i);
}
