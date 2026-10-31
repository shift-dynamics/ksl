/**
@file
@author Kristopher Wehage
@date 2016
@copyright Kristopher Wehage 2016
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
#ifndef _KSL_INERTIA_H_
#define _KSL_INERTIA_H_

#include "ksl/types.h"

#include "matrix.h"
#include "vec3.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
@brief double precision spatial inertia matrix constructor
@param m [in] mass
@param t [in] vector from reference frame to body centroid
@param Ixx [in] centroidal inertia term, expressed in reference frame
coordinates
@param Iyy [in] centroidal inertia term, expressed in reference frame
coordinates
@param Izz [in] centroidal inertia term, expressed in reference frame
coordinates
@param Ixy [in] centroidal inertia term, expressed in reference frame
coordinates
@param Iyz [in] centroidal inertia term, expressed in reference frame
coordinates
@param Izx [in] centroidal inertia term, expressed in reference frame
coordinates
*/
static inline ksl_inertia_t ksl_inertia(const double m, const ksl_vec3_t t,
                                        const double Ixx, const double Iyy,
                                        const double Izz, const double Ixy,
                                        const double Iyz, const double Izx);

/*!
@brief single precision spatial inertia matrix constructor
@param m [in] mass
@param t [in] vector from reference frame to body centroid
@param Ixx [in] centroidal inertia term, expressed in reference frame
coordinates
@param Iyy [in] centroidal inertia term, expressed in reference frame
coordinates
@param Izz [in] centroidal inertia term, expressed in reference frame
coordinates
@param Ixy [in] centroidal inertia term, expressed in reference frame
coordinates
@param Iyz [in] centroidal inertia term, expressed in reference frame
coordinates
@param Izx [in] centroidal inertia term, expressed in reference frame
coordinates
*/
static inline ksl_inertiaf_t ksl_inertiaf(const float m, const ksl_vec3f_t t,
                                          const float Ixx, const float Iyy,
                                          const float Izz, const float Ixy,
                                          const float Iyz, const float Izx);

/*!
@brief Allocate n ksl_inertia_t datastructures on the heap
*/
ksl_inertia_t* ksl_inertia_alloc(int n);

/*!
@brief Allocate n ksl_inertiaf_t datastructures on the heap
*/
ksl_inertiaf_t* ksl_inertiaf_alloc(int n);

/*!
@brief Rotate a double precision centroidal inertia matrix

  \f$ [Ad]^*_{(\Phi(R^{fc}))} M_{cc} [Ad]_{(\Phi((R^{fc})^{-1}))} \rightarrow
M_{ff}\f$

@param inertia_i [in] input inertia matrix
@param r [in] orthonormal rotation matrix
@param inertia_o [out] output inertia matrix
*/
static inline void ksl_inertia_rotated(const ksl_inertia_t* inertia_i,
                                       const ksl_mat3x3_t* r,
                                       ksl_inertia_t* inertia_o);

/*!
@brief Rotate a single precision centroidal inertia matrix

\f$ [Ad]^*_{(\Phi(R^{fc}))} M_{cc} [Ad]_{(\Phi((R^{fc})^{-1}))} \rightarrow
M_{ff}\f$

@param inertia_i [in] input inertia matrix
@param r [in] orthonormal rotation matrix
@param inertia_o [out] output inertia matrix
*/
static inline void ksl_inertiaf_rotated(const ksl_inertiaf_t* inertia_i,
                                        const ksl_mat3x3f_t* r,
                                        ksl_inertiaf_t* inertia_o);

/*!
@brief Rotate a double precision centroidal inertia matrix in place

\f$ [Ad]^*_{(\Phi(R^{fc}))} M_{cc} [Ad]_{(\Phi((R^{fc})^{-1}))} \rightarrow
M_{ff}\f$

@param inertia_i [in/out] input inertia matrix
@param r [in] orthonormal rotation matrix
*/
static inline void ksl_inertia_rotate(ksl_inertia_t* inertia_i,
                                      const ksl_mat3x3_t* r);

/*!
@brief Rotate a single precision centroidal inertia matrix in place

\f$ [Ad]^*_{(\Phi(R^{fc}))} M_{cc} [Ad]_{(\Phi((R^{fc})^{-1}))} \rightarrow
M_{ff}\f$

@param inertia_i [in/out] input inertia matrix
@param r [in] orthonormal rotation matrix
*/
static inline void ksl_inertiaf_rotate(ksl_inertiaf_t* inertia_i,
                                       const ksl_mat3x3f_t* r);

/*!
@brief translate a double precision centroidal inertia matrix

  \f$ [Ad]^*_{(\Phi(\underline{t}_{fc}^f))} M_{cc}
[Ad]_{(\Phi((\underline{t}_{fc}^f)^{-1}))} \rightarrow M_{ff}\f$

@param inertia_i [in] input inertia matrix
@param t [in] translation vector
@param inertia_o [out] output inertia matrix
*/
static inline void ksl_inertia_translated(const ksl_inertia_t* inertia_i,
                                          const ksl_vec3_t* t,
                                          ksl_inertia_t* inertia_o);

/*!
@brief translate a single precision centroidal inertia matrix

\f$ [Ad]^*_{(\Phi(\underline{t}_{fc}^f))} M_{cc}
[Ad]_{(\Phi((\underline{t}_{fc}^f)^{-1}))} \rightarrow M_{ff}\f$

@param inertia_i [in] input inertia matrix
@param t [in] translation vector
@param inertia_o [out] output inertia matrix
*/
static inline void ksl_inertiaf_translated(const ksl_inertiaf_t* inertia_i,
                                           const ksl_vec3f_t* t,
                                           ksl_inertiaf_t* inertia_o);

/*!
@brief translate a double precision centroidal inertia matrix in place

\f$ [Ad]^*_{(\Phi(\underline{t}_{fc}^f))} M_{cc}
[Ad]_{(\Phi((\underline{t}_{fc}^f)^{-1}))} \rightarrow M_{ff}\f$

@param inertia_i [in/out] input inertia matrix
@param t [in] translation vector
*/
static inline void ksl_inertia_translate(ksl_inertia_t* inertia_i,
                                         const ksl_vec3_t* t);

/*!
@brief translate a single precision centroidal inertia matrix in place

\f$ [Ad]^*_{(\Phi(\underline{t}_{fc}^f))} M_{cc}
[Ad]_{(\Phi((\underline{t}_{fc}^f)^{-1}))} \rightarrow M_{ff}\f$

@param inertia_i [in/out] input inertia matrix
@param t [in] translation vector
*/
static inline void ksl_inertiaf_translate(ksl_inertiaf_t* inertia_i,
                                          const ksl_vec3f_t* t);

/*!
@brief spatial transform a double precision centroidal inertia matrix

  \f$ [Ad]_{(\Phi_{fc})}^* M_{cc} [Ad]_{(\Phi_{fc}^{-1})} \rightarrow M_{ff}\f$

@param inertia_i [in] input inertia matrix
@param d [in] SE3 transformation matrix
@param inertia_o [out] output inertia matrix
*/
static inline void ksl_inertia_transformed(const ksl_inertia_t* inertia_i,
                                           const ksl_SE3_t* d,
                                           ksl_inertia_t* inertia_o);

/*!
@brief spatial transform a single precision centroidal inertia matrix

  \f$ [Ad]_{(\Phi_{fc})}^* M_{cc} [Ad]_{(\Phi_{fc}^{-1})} \rightarrow M_{ff}\f$

@param inertia_i [in] input inertia matrix
@param d [in] SE3 transformation matrix
@param inertia_o [out] output inertia matrix
*/
static inline void ksl_inertiaf_transformed(const ksl_inertiaf_t* inertia_i,
                                            const ksl_SE3f_t* d,
                                            ksl_inertiaf_t* inertia_o);

/*!
@brief Perform a spatial transformation of a double precision centroidal inertia
matrix in place.

  \f$ [Ad]_{(\Phi_{fc})}^* M_{cc} [Ad]_{(\Phi_{fc}^{-1})} \rightarrow M_{ff}\f$

@param inertia_i [in/out] inertia matrix to transform
@param d [in] SE3 transformation
*/
static inline void ksl_inertia_transform(ksl_inertia_t* inertia_i,
                                         const ksl_SE3_t* d);

/*!
@brief Perform a spatial transformation of a single precision centroidal inertia
matrix in place.

  \f$ [Ad]_{(\Phi_{fc})}^* M_{cc} [Ad]_{(\Phi_{fc}^{-1})} \rightarrow M_{ff}\f$

@param inertia_i [in/out] inertia matrix to transform
@param d [in] SE3 transformation
*/
static inline void ksl_inertiaf_transform(ksl_inertiaf_t* inertia_i,
                                          const ksl_SE3f_t* d);

/*!
@brief merge double precision child inertia (j) with parent inertia (i)
@param parent inertia [in/out] parent inertia to be merged
@param t_ic_i [in/out] vector from parent body reference frame i to body center
of mass frame c, expressed in body frame i
@param child inertia [in]
@param t_jc_j [in] vector from child body reference frame j to body center of
mass frame c, expressed in body frame j
@param D_ij [in] transformation from parent reference frame i to child reference
frame j
*/
void ksl_inertia_merge(ksl_inertia_t* inertia_i, const ksl_vec3_t* t_ic_i,
                       const ksl_inertia_t* inertia_j, const ksl_vec3_t* t_jc_j,
                       const ksl_SE3_t* D_ij);

/*!
@brief merge single precision child inertia (j) with parent inertia (i)
@param parent inertia [in/out] parent inertia to be merged
@param t_ic_i [in/out] vector from parent body reference frame i to body center
of mass frame c, expressed in body frame i
@param child inertia [in]
@param t_jc_j [in] vector from child body reference frame j to body center of
mass frame c, expressed in body frame j
@param D_ij [in] transformation from parent reference frame i to child reference
frame j
*/
void ksl_inertiaf_merge(ksl_inertiaf_t* inertia_i, const ksl_vec3f_t* t_ic_i,
                        const ksl_inertiaf_t* inertia_j,
                        const ksl_vec3f_t* t_jc_j, const ksl_SE3f_t* D_ij);

/*!
@brief factor double precision inertia matrix

@todo finish this

inertia matrix is overwritten with its factors

4 cases:
  * rank 2+, full rank, positive definite, or rank 2, positive semidefinite
  * rank 1, positive semidefinite
  * rank 0, do nothing

  @return rank of inertia matrix
*/
int ksl_inertia_factor(ksl_inertia_t*);

/*!
@brief factor single precision inertia matrix

@todo finish this

inertia matrix is overwritten with its factors

4 cases:
  * rank 2+, full rank, positive definite, or rank 2, positive semidefinite
  * rank 1, positive semidefinite
  * rank 0, do nothing

  @return rank of inertia matrix
*/
int ksl_inertiaf_factor(ksl_inertiaf_t*);

static inline void ksl_inertia_copy(const ksl_inertia_t* inertia_i,
                                    ksl_inertia_t* inertia_o);

static inline void ksl_inertiaf_copy(const ksl_inertiaf_t* inertia_i,
                                     ksl_inertiaf_t* inertia_o);

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

static inline ksl_inertia_t ksl_inertia(const double m, const ksl_vec3_t t,
                                        const double Ixx, const double Iyy,
                                        const double Izz, const double Ixy,
                                        const double Iyz, const double Izx) {
  ksl_inertia_t i;
  i.m = m;
  i.mt.x = m * t.x;
  i.mt.y = m * t.y;
  i.mt.z = m * t.z;
  i.Ixx = Ixx;
  i.Iyy = Iyy;
  i.Izz = Izz;
  i.Ixy = Ixy;
  i.Iyz = Iyz;
  i.Izx = Izx;
  return i;
}

static inline ksl_inertiaf_t ksl_inertiaf(const float m, const ksl_vec3f_t t,
                                          const float Ixx, const float Iyy,
                                          const float Izz, const float Ixy,
                                          const float Iyz, const float Izx) {
  ksl_inertiaf_t i;
  i.m = m;
  i.mt.x = m * t.x;
  i.mt.y = m * t.y;
  i.mt.z = m * t.z;
  i.Ixx = Ixx;
  i.Iyy = Iyy;
  i.Izz = Izz;
  i.Ixy = Ixy;
  i.Iyz = Iyz;
  i.Izx = Izx;
  return i;
}

static inline void ksl_inertia_copy(const ksl_inertia_t* KSL_RESTRICT inertia_i,
                                    ksl_inertia_t* KSL_RESTRICT inertia_o) {
  memcpy(inertia_o, inertia_i, sizeof(ksl_inertia_t));
}

static inline void
ksl_inertiaf_copy(const ksl_inertiaf_t* KSL_RESTRICT inertia_i,
                  ksl_inertiaf_t* KSL_RESTRICT inertia_o) {
  memcpy(inertia_o, inertia_i, sizeof(ksl_inertiaf_t));
}

static inline void
ksl_inertia_rotated(const ksl_inertia_t* KSL_RESTRICT inertia_i,
                    const ksl_mat3x3_t* KSL_RESTRICT r,
                    ksl_inertia_t* KSL_RESTRICT inertia_o) {

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

static inline void
ksl_inertiaf_rotated(const ksl_inertiaf_t* KSL_RESTRICT inertia_i,
                     const ksl_mat3x3f_t* KSL_RESTRICT r,
                     ksl_inertiaf_t* KSL_RESTRICT inertia_o) {

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

static inline void ksl_inertia_rotate(ksl_inertia_t* KSL_RESTRICT inertia_i,
                                      const ksl_mat3x3_t* KSL_RESTRICT r) {
  ksl_inertia_t inertia_o;
  ksl_inertia_rotated(inertia_i, r, &inertia_o);
  ksl_inertia_copy(&inertia_o, inertia_i);
}

static inline void ksl_inertiaf_rotate(ksl_inertiaf_t* KSL_RESTRICT inertia_i,
                                       const ksl_mat3x3f_t* KSL_RESTRICT r) {
  ksl_inertiaf_t inertia_o;
  ksl_inertiaf_rotated(inertia_i, r, &inertia_o);
  ksl_inertiaf_copy(&inertia_o, inertia_i);
}

static inline void
ksl_inertia_translated(const ksl_inertia_t* KSL_RESTRICT inertia_i,
                       const ksl_vec3_t* KSL_RESTRICT t,
                       ksl_inertia_t* KSL_RESTRICT inertia_o) {
  ksl_inertia_t o = *inertia_i;
  o.mt.x += t->x * inertia_i->m;
  o.mt.y += t->y * inertia_i->m;
  o.mt.z += t->z * inertia_i->m;
  assert(inertia_i->m > 0);
  const double minv = 1 / inertia_i->m;
  ksl_vec3_t c;
  c.x = o.mt.x * minv;
  c.y = o.mt.y * minv;
  c.z = o.mt.z * minv;

  o.Ixy -= o.mt.x * c.y;
  o.Iyz -= o.mt.y * c.z;
  o.Izx -= o.mt.z * c.x;

  const double px = o.mt.x * c.x, py = o.mt.y * c.y, pz = o.mt.z * c.z;
  o.Ixx += py + pz;
  o.Iyy += px + pz;
  o.Izz += px + py;
  *inertia_o = o;
}

static inline void
ksl_inertiaf_translated(const ksl_inertiaf_t* KSL_RESTRICT inertia_i,
                        const ksl_vec3f_t* KSL_RESTRICT t,
                        ksl_inertiaf_t* KSL_RESTRICT inertia_o) {
  ksl_inertiaf_t o = *inertia_i;
  o.mt.x += t->x * inertia_i->m;
  o.mt.y += t->y * inertia_i->m;
  o.mt.z += t->z * inertia_i->m;
  assert(inertia_i->m > 0);
  const float minv = 1 / inertia_i->m;
  ksl_vec3f_t c;
  c.x = o.mt.x * minv;
  c.y = o.mt.y * minv;
  c.z = o.mt.z * minv;

  o.Ixy -= o.mt.x * c.y;
  o.Iyz -= o.mt.y * c.z;
  o.Izx -= o.mt.z * c.x;

  const float px = o.mt.x * c.x, py = o.mt.y * c.y, pz = o.mt.z * c.z;
  o.Ixx += py + pz;
  o.Iyy += px + pz;
  o.Izz += px + py;
  *inertia_o = o;
}

static inline void ksl_inertia_translate(ksl_inertia_t* KSL_RESTRICT inertia_i,
                                         const ksl_vec3_t* KSL_RESTRICT t) {
  ksl_inertia_t inertia_o;
  ksl_inertia_translated(inertia_i, t, &inertia_o);
  ksl_inertia_copy(&inertia_o, inertia_i);
}

static inline void
ksl_inertiaf_translate(ksl_inertiaf_t* KSL_RESTRICT inertia_i,
                       const ksl_vec3f_t* KSL_RESTRICT t) {
  ksl_inertiaf_t inertia_o;
  ksl_inertiaf_translated(inertia_i, t, &inertia_o);
  ksl_inertiaf_copy(&inertia_o, inertia_i);
}

static inline void
ksl_inertia_transformed(const ksl_inertia_t* KSL_RESTRICT inertia_i,
                        const ksl_SE3_t* KSL_RESTRICT d,
                        ksl_inertia_t* KSL_RESTRICT inertia_o) {
  ksl_inertia_t o;
  ksl_inertia_rotated(inertia_i, &d->R, &o);
  o.mt.x += d->t.x * inertia_i->m;
  o.mt.y += d->t.y * inertia_i->m;
  o.mt.z += d->t.z * inertia_i->m;
  const double minv = 1 / inertia_i->m;
  ksl_vec3_t c;
  c.x = o.mt.x * minv;
  c.y = o.mt.y * minv;
  c.z = o.mt.z * minv;

  o.Ixy -= o.mt.x * c.y;
  o.Iyz -= o.mt.y * c.z;
  o.Izx -= o.mt.z * c.x;

  const double px = o.mt.x * c.x, py = o.mt.y * c.y, pz = o.mt.z * c.z;
  o.Ixx += py + pz;
  o.Iyy += px + pz;
  o.Izz += px + py;
  *inertia_o = o;
}

static inline void
ksl_inertiaf_transformed(const ksl_inertiaf_t* KSL_RESTRICT inertia_i,
                         const ksl_SE3f_t* KSL_RESTRICT d,
                         ksl_inertiaf_t* KSL_RESTRICT inertia_o) {
  ksl_inertiaf_t o;
  ksl_inertiaf_rotated(inertia_i, &d->R, &o);
  o.mt.x += d->t.x * inertia_i->m;
  o.mt.y += d->t.y * inertia_i->m;
  o.mt.z += d->t.z * inertia_i->m;
  const float minv = 1 / inertia_i->m;
  ksl_vec3f_t c;
  c.x = o.mt.x * minv;
  c.y = o.mt.y * minv;
  c.z = o.mt.z * minv;

  o.Ixy -= o.mt.x * c.y;
  o.Iyz -= o.mt.y * c.z;
  o.Izx -= o.mt.z * c.x;

  const float px = o.mt.x * c.x, py = o.mt.y * c.y, pz = o.mt.z * c.z;
  o.Ixx += py + pz;
  o.Iyy += px + pz;
  o.Izz += px + py;
  *inertia_o = o;
}

static inline void ksl_inertia_transform(ksl_inertia_t* KSL_RESTRICT inertia_i,
                                         const ksl_SE3_t* KSL_RESTRICT d) {
  ksl_inertia_t inertia_o;
  ksl_inertia_transformed(inertia_i, d, &inertia_o);
  ksl_inertia_copy(&inertia_o, inertia_i);
}

static inline void
ksl_inertiaf_transform(ksl_inertiaf_t* KSL_RESTRICT inertia_i,
                       const ksl_SE3f_t* KSL_RESTRICT d) {
  ksl_inertiaf_t inertia_o;
  ksl_inertiaf_transformed(inertia_i, d, &inertia_o);
  ksl_inertiaf_copy(&inertia_o, inertia_i);
}

#ifdef __cplusplus
}
#endif

#endif
