#include <stdlib.h>
#include <string.h>

#include "coscrew.h"
#include "matrix.h"

/*!
@brief allocate n double precision coscrew quantities
*/
ksl_coscrew_t* ksl_coscrew_alloc(const int n) {
  return calloc(n, sizeof(ksl_coscrew_t));
}

/*!
@brief allocate n single precision coscrew quantities
*/
ksl_coscrewf_t* ksl_coscrewf_alloc(const int n) {
  return calloc(n, sizeof(ksl_coscrewf_t));
}

/*!
@defgroup Coscrew *methods*

The following functions are methods of coscrews, that is, they operate on
a single screw and return a single result or combine the results of an
additional quantity to modify the coscrew in-place.
*/

/*!@{*/

/*!
@brief Copy double precision ksl_coscrew_t ci to co.

\f$C_i \rightarrow C_o\f$

@param ci [in] screw to copy
@param co [out] ci is copied to co
*/
inline void ksl_coscrew_copy(const ksl_coscrew_t* restrict self,
                             ksl_coscrew_t* restrict co) {
  memcpy(co, self, sizeof(ksl_coscrew_t));
}

/*!
@brief Copy single precision ksl_coscrewf_t ci to co.

\f$C_i \rightarrow C_o\f$

@param ci [in] screw to copy
@param co [out] ci is copied to co
*/
inline void ksl_coscrewf_copy(const ksl_coscrewf_t* restrict self,
                              ksl_coscrewf_t* restrict co) {
  memcpy(co, self, sizeof(ksl_coscrewf_t));
}

/*!
@brief Scale a double precision ksl_coscrew_t.

\f$\mathbf{\underline{c}} * a \rightarrow \mathbf{\underline{c}}\f$

@param ci [in] coscrew to invert
@param co [out] inverse of ci
*/
inline void ksl_coscrew_scale(ksl_coscrew_t* restrict self,
                              const double a) {
  for(int i = 0; i < 6; i++) {
    self->at[i] *= a;
  }
}

/*!
@brief Scale a single precision ksl_coscrew_t.

\f$\mathbf{\underline{c}} * a \rightarrow \mathbf{\underline{c}}\f$

@param ci [in] coscrew to invert
@param co [out] inverse of ci
*/
inline void ksl_coscrewf_scale(ksl_coscrewf_t* restrict self,
                                const double a) {
  for(int i = 0; i < 6; i++) {
    self->at[i] *= a;
  }
}

/*!
@brief Returns the inverse of a ksl_coscrew_t.

\f$\mathbf{\underline{s}}_i^{-1} \rightarrow \mathbf{\underline{s}}_o\f$

@param ci [in] coscrew to invert
@param co [out] inverse of ci
*/
inline void ksl_coscrew_inverted(const ksl_coscrew_t* restrict self,
                                 ksl_coscrew_t* restrict co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] = -self->at[i];
  }
}

/*!
@brief Returns the inverse of a ksl_coscrewf_t.

\f$\mathbf{\underline{s}}_i^{-1} \rightarrow \mathbf{\underline{s}}_o\f$

@param ci [in] coscrew to invert
@param co [out] inverse of ci
*/
inline void ksl_coscrewf_inverted(const ksl_coscrewf_t* restrict self,
                                  ksl_coscrewf_t* restrict co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] = -self->at[i];
  }
}

/*!
@brief Invert (i.e. negate) a ksl_coscrew_t in place.

\f$\mathbf{\underline{c}}^{-1} \rightarrow \mathbf{\underline{c}}\f$
\f$-\mathbf{\underline{c}} \rightarrow \mathbf{\underline{c}}\f$

@param self [in/out] coscrew to invert
*/
inline void ksl_coscrew_invert(ksl_coscrew_t* restrict self) {
  for(int i = 0; i < 6; i++) {
    self->at[i] = -self->at[i];
  }
}

/*!
@brief Invert (i.e. negate) a ksl_coscrewf_t in place.

\f$\mathbf{\underline{c}}^{-1} \rightarrow \mathbf{\underline{c}}\f$
\f$-\mathbf{\underline{c}} \rightarrow \mathbf{\underline{c}}\f$

@param self [in/out] coscrew to invert
*/
inline void ksl_coscrewf_invert(ksl_coscrewf_t* restrict self) {
  for(int i = 0; i < 6; i++) {
    self->at[i] = -self->at[i];
  }
}



/*!@}*/

/*!
@defgroup Coscrew *functions*

The following functions combine one or more coscrews with other quantities to generate another coscrew.
*/

/*!
@brief In-place add a double precision coscrew multiplied with a scalar to an existing coscrew.

\f$ a \mathbf{\underline{x}} + \mathbf{\underline{y}} \rightarrow
\mathbf{\underline{y}}\f$

@param a [in]
@param x [in]
@param y [in/out] coscrew to add
*/
void ksl_axpy_cc(const double a, const ksl_coscrew_t* restrict x,
  ksl_coscrew_t* restrict y) {
  for(int i = 0; i < 6; i++) {
    y->at[i] += a * x->at[i];
  }
}

/*!
@brief In-place add a single precision coscrew multiplied with a scalar to an existing coscrew.

\f$ a \mathbf{\underline{x}} + \mathbf{\underline{y}} \rightarrow
\mathbf{\underline{y}}\f$

@param a [in]
@param x [in]
@param y [in/out]
*/
void ksl_axpy_ccf(const float a, const ksl_coscrewf_t* restrict x,
  ksl_coscrewf_t* restrict y) {
  for(int i = 0; i < 6; i++) {
    y->at[i] += a * x->at[i];
  }
}

/*!
@brief In-place add a double precision coscrew to an existing coscrew. This is a variant of axpy where the scalar term a is 1.

\f$\mathbf{\underline{c}}_{1i} + \mathbf{\underline{c}}_{o} \rightarrow
\mathbf{\underline{c}}_o\f$

@param c [in/out]
@param ci [in] coscrew to add
*/
void ksl_xpy_cc(const ksl_coscrew_t* restrict x,
  ksl_coscrew_t* restrict y) {
  for(int i = 0; i < 6; i++) {
    y->at[i] += x->at[i];
  }
}

/*!
@brief In-place add a single precision coscrew to an existing coscrew. This is a variant of axpy where there the scalar term is 1.

\f$\mathbf{\underline{c}}_{1i} + \mathbf{\underline{c}}_{o} \rightarrow
\mathbf{\underline{c}}_o\f$

@param co [in/out] sum of c1i and co
@param c1i [in] first coscrew to add
*/
void ksl_xpy_ccf(const ksl_coscrewf_t* restrict x,
  ksl_coscrewf_t* restrict y) {
  for(int i = 0; i < 6; i++) {
    y->at[i] += x->at[i];
  }
}

/*!
@brief In-place subtract a double precision coscrew x from an  coscrew y. This is a variant of axpy where the scalar term is -1.

\f$\mathbf{\underline{c}} - \mathbf{\underline{c}}_{i} \rightarrow
\mathbf{\underline{c}}\f$

@param self [in/out]
@param ci [in] first coscrew to subtract
*/
void ksl_nxpy_cc(const ksl_coscrew_t* restrict x,
                ksl_coscrew_t* restrict y) {
  for(int i = 0; i < 6; i++) {
    y->at[i] -= x->at[i];
  }
}

/*!
@brief In-place subtract a single precision coscrew from an existing coscrew. This is a variant of axpy where the scalar term is -1.

\f$\mathbf{\underline{c}} - \mathbf{\underline{c}}_{i} \rightarrow
\mathbf{\underline{c}}\f$

@param self [in/out]
@param ci [in] first coscrew to subtract
*/
void ksl_nxpy_ccf(const ksl_coscrewf_t* restrict x,
                 ksl_coscrewf_t* restrict y) {
  for(int i = 0; i < 6; i++) {
    y->at[i] -= x->at[i];
  }
}

/*!
@brief Scale a double precision coscrew.

\f$-\mathbf{\underline{c}} * a \rightarrow \mathbf{\underline{c}}\f$

@param ci [in/out] coscrew to invert
*/
inline void ksl_product_ca(const ksl_coscrew_t* restrict ci, const double a,
                           ksl_coscrew_t* restrict co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] = ci->at[i] * a;
  }
}

/*!
@brief Scale a single precision coscrew.

\f$-\mathbf{\underline{c}} * a \rightarrow \mathbf{\underline{c}}\f$

@param ci [in/out] coscrew to invert
*/
void ksl_product_caf(const ksl_coscrewf_t* restrict ci, const float a,
                     ksl_coscrewf_t* restrict co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] = ci->at[i] * a;
  }
}

/*!
@brief Compute the sum of two double precision coscrews

\f$\mathbf{\underline{c}}_{1i} + \mathbf{\underline{c}}_{2i} \rightarrow
\mathbf{\underline{c}}_o\f$

@param c1i [in] first coscrew to add
@param c1i [in] second coscrew to add
@param co [out] sum of c1i and c2i
*/
void ksl_add_cc(const ksl_coscrew_t* restrict c1i,
                const ksl_coscrew_t* restrict c2i, ksl_coscrew_t* restrict co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] = c1i->at[i] + c2i->at[i];
  }
}

/*!
@brief Compute the sum of two single precision coscrews

\f$\mathbf{\underline{c}}_{1i} + \mathbf{\underline{c}}_{2i} \rightarrow
\mathbf{\underline{c}}_o\f$

@param c1i [in] first coscrew to add
@param c1i [in] second coscrew to add
@param co [out] sum of c1i and c2i
*/
void ksl_add_ccf(const ksl_coscrewf_t* restrict c1i,
                 const ksl_coscrewf_t* restrict c2i,
                 ksl_coscrewf_t* restrict co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] = c1i->at[i] + c2i->at[i];
  }
}

/*!
@brief Compute the difference between two double precision coscrews

\f$\mathbf{\underline{c}}_{1i} - \mathbf{\underline{c}}_{2i} \rightarrow
\mathbf{\underline{c}}_o\f$

@param c1i [in] first coscrew
@param c2i [in] second coscrew
@param co [out] c1i minus c2i
*/
void ksl_subtract_cc(const ksl_coscrew_t* restrict c1i,
                     const ksl_coscrew_t* restrict c2i,
                     ksl_coscrew_t* restrict co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] = c1i->at[i] - c2i->at[i];
  }
}

/*!
@brief Compute the difference between two double precision coscrews

\f$\mathbf{\underline{c}}_{1i} - \mathbf{\underline{c}}_{2i} \rightarrow
\mathbf{\underline{c}}_o\f$

@param c1i [in] first coscrew
@param c2i [in] second coscrew
@param co [out] result of c1i minus c2i
*/
void ksl_subtract_ccf(const ksl_coscrewf_t* restrict c1i,
                      const ksl_coscrewf_t* restrict c2i,
                      ksl_coscrewf_t* restrict co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] = c1i->at[i] - c2i->at[i];
  }
}

/*!
@brief Compute the double precision coscrew cross product

@param c1i [in] first coscrew
@param c2i [in] second coscrew
@param co [out] result of c1i x c2i
*/
inline void ksl_cross_cc(const ksl_coscrew_t* restrict c1i,
                         const ksl_coscrew_t* restrict c2i,
                         ksl_coscrew_t* restrict co) {
  /* vo <- w1 x v2 */
  ksl_cross_vv(&c1i->ang, &c2i->lin, &co->lin);

  /* wo <- v1 x v2 */
  ksl_cross_vv(&c1i->lin, &c2i->lin, &co->ang);

  /* wo += w1 x w2 */
  co->m3 += c1i->m4 * c2i->m5 - c1i->m5 * c2i->m4;
  co->m4 += c1i->m5 * c2i->m3 - c1i->m3 * c2i->m5;
  co->m5 += c1i->m3 * c2i->m4 - c1i->m4 * c2i->m3;
}

/*!
@brief Compute the single precision coscrew cross product

@param c1i [in] first coscrew
@param c2i [in] second coscrew
@param co [out] result of c1i x c2i
*/
void ksl_cross_ccf(const ksl_coscrewf_t* restrict c1i,
                   const ksl_coscrewf_t* restrict c2i,
                   ksl_coscrewf_t* restrict co) {
  /* vo <- w1 x v2 */
  ksl_cross_vvf(&c1i->ang, &c2i->lin, &co->lin);

  /* wo <- v1 x v2 */
  ksl_cross_vvf(&c1i->lin, &c2i->lin, &co->ang);

  /* wo += w1 x w2 */
  co->m3 += c1i->m4 * c2i->m5 - c1i->m5 * c2i->m4;
  co->m4 += c1i->m5 * c2i->m3 - c1i->m3 * c2i->m5;
  co->m5 += c1i->m3 * c2i->m4 - c1i->m4 * c2i->m3;
}

void ksl_product_CoAdtc(const ksl_vec3_t* restrict ti,
                        const ksl_coscrew_t* restrict ci,
                        ksl_coscrew_t* restrict co) {
  ksl_coscrew_copy(ci, co);

  /* wo += w1 x w2 */
  co->m3 += ti->y * ci->m2 - ti->z * ci->m1;
  co->m4 += ti->z * ci->m0 - ti->x * ci->m2;
  co->m5 += ti->x * ci->m1 - ti->y * ci->m0;
}

void ksl_product_CoAdtcf(const ksl_vec3f_t* restrict ti,
                         const ksl_coscrewf_t* restrict ci,
                         ksl_coscrewf_t* restrict co) {
  ksl_coscrewf_copy(ci, co);

  /* wo += w1 x w2 */
  co->m3 += ti->y * ci->m2 - ti->z * ci->m1;
  co->m4 += ti->z * ci->m0 - ti->x * ci->m2;
  co->m5 += ti->x * ci->m1 - ti->y * ci->m0;
}

void ksl_product_CoAdtcinv(const ksl_vec3_t* ti, const ksl_coscrew_t* ci,
                           ksl_coscrew_t* co) {
  ksl_coscrew_t temp;
  ksl_coscrew_inverted(ci, &temp);
  ksl_product_CoAdtc(ti, &temp, co);
}

void ksl_product_CoAdtcinvf(const ksl_vec3f_t* ti, const ksl_coscrewf_t* ci,
                            ksl_coscrewf_t* co) {

  ksl_coscrewf_t temp;
  ksl_coscrewf_inverted(ci, &temp);
  ksl_product_CoAdtcf(ti, &temp, co);
}

void ksl_product_CoAdrc(const ksl_mat3x3_t* Ri, const ksl_coscrew_t* ci,
                        ksl_coscrew_t* co) {
  ksl_product_rv(Ri, &ci->lin, &co->lin);
  ksl_product_rv(Ri, &ci->ang, &co->ang);
}

void ksl_product_CoAdrcf(const ksl_mat3x3f_t* Ri, const ksl_coscrewf_t* ci,
                         ksl_coscrewf_t* co) {
  ksl_product_rvf(Ri, &ci->lin, &co->lin);
  ksl_product_rvf(Ri, &ci->ang, &co->ang);
}

void ksl_product_CoAdrinvc(const ksl_mat3x3_t* Ri, const ksl_coscrew_t* ci,
                           ksl_coscrew_t* co) {
  ksl_product_rinvv(Ri, &ci->lin, &co->lin);
  ksl_product_rinvv(Ri, &ci->ang, &co->ang);
}

void ksl_product_CoAdrinvcf(const ksl_mat3x3f_t* Ri, const ksl_coscrewf_t* ci,
                            ksl_coscrewf_t* co) {
  ksl_product_rinvvf(Ri, &ci->lin, &co->lin);
  ksl_product_rinvvf(Ri, &ci->ang, &co->ang);
}

void ksl_product_CoAdc(const ksl_SE3_t* Di, const ksl_coscrew_t* ci,
                       ksl_coscrew_t* co) {
  ksl_product_CoAdrc(&(Di->R), ci, co);

  co->m3 += Di->t.y * co->m2 - Di->t.z * co->m1;
  co->m4 += Di->t.z * co->m0 - Di->t.x * co->m2;
  co->m5 += Di->t.x * co->m1 - Di->t.y * co->m0;
}

void ksl_product_CoAdcf(const ksl_SE3f_t* Di, const ksl_coscrewf_t* ci,
                        ksl_coscrewf_t* co) {

  ksl_product_CoAdrcf(&Di->R, ci, co);

  co->m3 += Di->t.y * co->m2 - Di->t.z * co->m1;
  co->m4 += Di->t.z * co->m0 - Di->t.x * co->m2;
  co->m5 += Di->t.x * co->m1 - Di->t.y * co->m0;
}

void ksl_product_CoAdinvc(const ksl_SE3_t* Di, const ksl_coscrew_t* ci,
                          ksl_coscrew_t* co) {
  ksl_coscrew_t temp;
  ksl_coscrew_copy(ci, &temp);

  temp.m3 -= Di->t.y * temp.m2 - Di->t.z * temp.m1;
  temp.m4 -= Di->t.z * temp.m0 - Di->t.x * temp.m2;
  temp.m5 -= Di->t.x * temp.m1 - Di->t.y * temp.m0;

  ksl_product_CoAdrinvc(&(Di->R), &temp, co);
}

void ksl_product_CoAdinvcf(const ksl_SE3f_t* Di, const ksl_coscrewf_t* ci,
                           ksl_coscrewf_t* co) {
  ksl_coscrewf_t temp;
  ksl_coscrewf_copy(ci, &temp);

  temp.m3 -= Di->t.y * temp.m2 - Di->t.z * temp.m1;
  temp.m4 -= Di->t.z * temp.m0 - Di->t.x * temp.m2;
  temp.m5 -= Di->t.x * temp.m1 - Di->t.y * temp.m0;

  ksl_product_CoAdrinvcf(&(Di->R), &temp, co);
}
