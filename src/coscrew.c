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

#include <stdlib.h>
#include <string.h>

#include "coscrew.h"
#include "matrix.h"

ksl_coscrew_t ksl_coscrew(const double m0, const double m1, const double m2,
                          const double m3, const double m4, const double m5) {
  ksl_coscrew_t s;
  s.m0 = m0;
  s.m1 = m1;
  s.m2 = m2;
  s.m3 = m3;
  s.m4 = m4;
  s.m5 = m5;
  return s;
}

ksl_coscrewf_t ksl_coscrewf(const float m0, const float m1, const float m2,
                            const float m3, const float m4, const float m5) {
  ksl_coscrewf_t s;
  s.m0 = m0;
  s.m1 = m1;
  s.m2 = m2;
  s.m3 = m3;
  s.m4 = m4;
  s.m5 = m5;
  return s;
}

ksl_coscrew_t* ksl_coscrew_alloc(const int n) {
  return calloc(n, sizeof(ksl_coscrew_t));
}

ksl_coscrewf_t* ksl_coscrewf_alloc(const int n) {
  return calloc(n, sizeof(ksl_coscrewf_t));
}

inline void ksl_coscrew_copy(const ksl_coscrew_t* restrict self,
                             ksl_coscrew_t* restrict co) {
  memcpy(co, self, sizeof(ksl_coscrew_t));
}

inline void ksl_coscrewf_copy(const ksl_coscrewf_t* restrict self,
                              ksl_coscrewf_t* restrict co) {
  memcpy(co, self, sizeof(ksl_coscrewf_t));
}

inline void ksl_coscrew_scale(ksl_coscrew_t* restrict self, const double a) {
  for(int i = 0; i < 6; i++) {
    self->at[i] *= a;
  }
}

inline void ksl_coscrewf_scale(ksl_coscrewf_t* restrict self, const float a) {
  for(int i = 0; i < 6; i++) {
    self->at[i] *= a;
  }
}

inline void ksl_coscrew_inverted(const ksl_coscrew_t* restrict self,
                                 ksl_coscrew_t* restrict co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] = -self->at[i];
  }
}

inline void ksl_coscrewf_inverted(const ksl_coscrewf_t* restrict self,
                                  ksl_coscrewf_t* restrict co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] = -self->at[i];
  }
}

inline void ksl_coscrew_invert(ksl_coscrew_t* restrict self) {
  for(int i = 0; i < 6; i++) {
    self->at[i] = -self->at[i];
  }
}

inline void ksl_coscrewf_invert(ksl_coscrewf_t* restrict self) {
  for(int i = 0; i < 6; i++) {
    self->at[i] = -self->at[i];
  }
}

void ksl_axpy_cc(const double a, const ksl_coscrew_t* restrict x,
                 ksl_coscrew_t* restrict y) {
  for(int i = 0; i < 6; i++) {
    y->at[i] += a * x->at[i];
  }
}

void ksl_axpy_ccf(const float a, const ksl_coscrewf_t* restrict x,
                  ksl_coscrewf_t* restrict y) {
  for(int i = 0; i < 6; i++) {
    y->at[i] += a * x->at[i];
  }
}

void ksl_xpy_cc(const ksl_coscrew_t* restrict x, ksl_coscrew_t* restrict y) {
  for(int i = 0; i < 6; i++) {
    y->at[i] += x->at[i];
  }
}

void ksl_xpy_ccf(const ksl_coscrewf_t* restrict x, ksl_coscrewf_t* restrict y) {
  for(int i = 0; i < 6; i++) {
    y->at[i] += x->at[i];
  }
}

void ksl_nxpy_cc(const ksl_coscrew_t* restrict x, ksl_coscrew_t* restrict y) {
  for(int i = 0; i < 6; i++) {
    y->at[i] -= x->at[i];
  }
}

void ksl_nxpy_ccf(const ksl_coscrewf_t* restrict x,
                  ksl_coscrewf_t* restrict y) {
  for(int i = 0; i < 6; i++) {
    y->at[i] -= x->at[i];
  }
}

inline void ksl_product_ca(const ksl_coscrew_t* restrict ci, const double a,
                           ksl_coscrew_t* restrict co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] = ci->at[i] * a;
  }
}

void ksl_product_caf(const ksl_coscrewf_t* restrict ci, const float a,
                     ksl_coscrewf_t* restrict co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] = ci->at[i] * a;
  }
}

void ksl_add_cc(const ksl_coscrew_t* restrict c1i,
                const ksl_coscrew_t* restrict c2i, ksl_coscrew_t* restrict co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] = c1i->at[i] + c2i->at[i];
  }
}

void ksl_add_ccf(const ksl_coscrewf_t* restrict c1i,
                 const ksl_coscrewf_t* restrict c2i,
                 ksl_coscrewf_t* restrict co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] = c1i->at[i] + c2i->at[i];
  }
}

void ksl_subtract_cc(const ksl_coscrew_t* restrict c1i,
                     const ksl_coscrew_t* restrict c2i,
                     ksl_coscrew_t* restrict co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] = c1i->at[i] - c2i->at[i];
  }
}

void ksl_subtract_ccf(const ksl_coscrewf_t* restrict c1i,
                      const ksl_coscrewf_t* restrict c2i,
                      ksl_coscrewf_t* restrict co) {
  for(int i = 0; i < 6; i++) {
    co->at[i] = c1i->at[i] - c2i->at[i];
  }
}

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

inline void ksl_cross_ccf(const ksl_coscrewf_t* restrict c1i,
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

inline void ksl_product_CoAdtc(const ksl_vec3_t* restrict ti,
                               const ksl_coscrew_t* restrict ci,
                               ksl_coscrew_t* restrict co) {
  ksl_coscrew_copy(ci, co);

  /* wo += w1 x w2 */
  co->m3 += ti->y * ci->m2 - ti->z * ci->m1;
  co->m4 += ti->z * ci->m0 - ti->x * ci->m2;
  co->m5 += ti->x * ci->m1 - ti->y * ci->m0;
}

inline void ksl_product_CoAdtcf(const ksl_vec3f_t* restrict ti,
                                const ksl_coscrewf_t* restrict ci,
                                ksl_coscrewf_t* restrict co) {
  ksl_coscrewf_copy(ci, co);

  /* wo += w1 x w2 */
  co->m3 += ti->y * ci->m2 - ti->z * ci->m1;
  co->m4 += ti->z * ci->m0 - ti->x * ci->m2;
  co->m5 += ti->x * ci->m1 - ti->y * ci->m0;
}

inline void ksl_product_CoAdtcinv(const ksl_vec3_t* restrict ti,
                                  const ksl_coscrew_t* restrict ci,
                                  ksl_coscrew_t* restrict co) {
  ksl_coscrew_t temp;
  ksl_coscrew_inverted(ci, &temp);
  ksl_product_CoAdtc(ti, &temp, co);
}

inline void ksl_product_CoAdtcinvf(const ksl_vec3f_t* restrict ti,
                                   const ksl_coscrewf_t* restrict ci,
                                   ksl_coscrewf_t* restrict co) {

  ksl_coscrewf_t temp;
  ksl_coscrewf_inverted(ci, &temp);
  ksl_product_CoAdtcf(ti, &temp, co);
}

inline void ksl_product_CoAdrc(const ksl_mat3x3_t* restrict Ri,
                               const ksl_coscrew_t* restrict ci,
                               ksl_coscrew_t* restrict co) {
  ksl_product_drv(Ri, &ci->lin, &co->lin);
  ksl_product_drv(Ri, &ci->ang, &co->ang);
}

inline void ksl_product_CoAdrcf(const ksl_mat3x3f_t* restrict Ri,
                                const ksl_coscrewf_t* restrict ci,
                                ksl_coscrewf_t* restrict co) {
  ksl_product_drvf(Ri, &ci->lin, &co->lin);
  ksl_product_drvf(Ri, &ci->ang, &co->ang);
}

inline void ksl_product_CoAdrinvc(const ksl_mat3x3_t* restrict Ri,
                                  const ksl_coscrew_t* restrict ci,
                                  ksl_coscrew_t* restrict co) {
  ksl_product_drinvv(Ri, &ci->lin, &co->lin);
  ksl_product_drinvv(Ri, &ci->ang, &co->ang);
}

inline void ksl_product_CoAdrinvcf(const ksl_mat3x3f_t* restrict Ri,
                                   const ksl_coscrewf_t* restrict ci,
                                   ksl_coscrewf_t* restrict co) {
  ksl_product_drinvvf(Ri, &ci->lin, &co->lin);
  ksl_product_drinvvf(Ri, &ci->ang, &co->ang);
}

inline void ksl_product_CoAdc(const ksl_SE3_t* restrict Di,
                              const ksl_coscrew_t* restrict ci,
                              ksl_coscrew_t* restrict co) {
  ksl_product_CoAdrc(&(Di->R), ci, co);

  co->m3 += Di->t.y * co->m2 - Di->t.z * co->m1;
  co->m4 += Di->t.z * co->m0 - Di->t.x * co->m2;
  co->m5 += Di->t.x * co->m1 - Di->t.y * co->m0;
}

inline void ksl_product_CoAdcf(const ksl_SE3f_t* restrict Di,
                               const ksl_coscrewf_t* restrict ci,
                               ksl_coscrewf_t* restrict co) {

  ksl_product_CoAdrcf(&Di->R, ci, co);

  co->m3 += Di->t.y * co->m2 - Di->t.z * co->m1;
  co->m4 += Di->t.z * co->m0 - Di->t.x * co->m2;
  co->m5 += Di->t.x * co->m1 - Di->t.y * co->m0;
}

inline void ksl_product_CoAdinvc(const ksl_SE3_t* restrict Di,
                                 const ksl_coscrew_t* restrict ci,
                                 ksl_coscrew_t* restrict co) {
  ksl_coscrew_t temp;
  ksl_coscrew_copy(ci, &temp);

  temp.m3 -= Di->t.y * temp.m2 - Di->t.z * temp.m1;
  temp.m4 -= Di->t.z * temp.m0 - Di->t.x * temp.m2;
  temp.m5 -= Di->t.x * temp.m1 - Di->t.y * temp.m0;

  ksl_product_CoAdrinvc(&(Di->R), &temp, co);
}

inline void ksl_product_CoAdinvcf(const ksl_SE3f_t* restrict Di,
                                  const ksl_coscrewf_t* restrict ci,
                                  ksl_coscrewf_t* restrict co) {
  ksl_coscrewf_t temp;
  ksl_coscrewf_copy(ci, &temp);

  temp.m3 -= Di->t.y * temp.m2 - Di->t.z * temp.m1;
  temp.m4 -= Di->t.z * temp.m0 - Di->t.x * temp.m2;
  temp.m5 -= Di->t.x * temp.m1 - Di->t.y * temp.m0;

  ksl_product_CoAdrinvcf(&(Di->R), &temp, co);
}
