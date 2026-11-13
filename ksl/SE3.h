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

#ifndef _KSL_SE3_H_
#define _KSL_SE3_H_

#include "ksl/types.h"

#include <stdarg.h>

#include "axis.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "ksl/mat3x3.h"

/*!
@brief ksl_SE3_t constructor.

Note that in the constructor, fields are specified in row major order.
Internally, ksl_SE3_t datastructures are stored in column major order.
*/
static inline ksl_SE3_t
ksl_SE3(const double m00, const double m01, const double m02, const double m03,
        const double m10, const double m11, const double m12, const double m13,
        const double m20, const double m21, const double m22, const double m23);

/*!
@brief alternative ksl_SE3_t constructor.

In this alternate constructor, fields are specified in column major order to
match the internal layout of ksl_SE3_t datastructures.
*/
static inline ksl_SE3_t ksl_SE3_cmo(const double m00, const double m10,
                                    const double m20, const double m01,
                                    const double m11, const double m21,
                                    const double m02, const double m12,
                                    const double m22, const double m03,
                                    const double m13, const double m23);

/*!
@brief alternative ksl_SE3_t constructor that allows creating a ksl_SE3_t
datastructure from a rotation matrix and translation vector.
*/
static inline ksl_SE3_t ksl_SE3_fromRt(const ksl_mat3x3_t R,
                                       const ksl_vec3_t t);

/*!
@brief ksl_SE3f_t constructor.

Note that in the constructor, fields are specified in row major order.
Internally, ksl_SE3f_t datastructures are stored in column major order.
*/
static inline ksl_SE3f_t
ksl_SE3f(const float m00, const float m01, const float m02, const float m03,
         const float m10, const float m11, const float m12, const float m13,
         const float m20, const float m21, const float m22, const float m23);

/*!
@brief alternative ksl_SE3f_t constructor.

In this alternate constructor, fields are specified in column major order to
match the internal layout of ksl_SE3f_t datastructures.
*/
static inline ksl_SE3f_t ksl_SE3f_cmo(const float m00, const float m10,
                                      const float m20, const float m01,
                                      const float m11, const float m21,
                                      const float m02, const float m12,
                                      const float m22, const float m03,
                                      const float m13, const float m23);

/*!
@brief alternative ksl_SE3f_t constructor that allows creating a ksl_SE3_t
datastructure from a rotation matrix and translation vector.
*/
static inline ksl_SE3f_t ksl_SE3f_fromRt(const ksl_mat3x3f_t R,
                                         const ksl_vec3f_t t);

/*!
@brief allocates n ksl_SE3_t datastructures on the heap. Must be freed by the
user.
*/
ksl_SE3_t* ksl_SE3_alloc(int n);

/*!
@brief allocates n ksl_SE3f_t datastructures on the heap. Must be freed by the
user.
*/
ksl_SE3f_t* ksl_SE3f_alloc(int n);

/*!
@brief convert a `ksl_SE3_t` datastructure to a `ksl_mat4x4_t` datastructure

@param d [in] input SE3 datastructure
@param m [out] output mat4x4 matrix
*/
static inline void ksl_SE3_toMat4x4(const ksl_SE3_t* d, ksl_mat4x4_t* m);

/*!
@brief convert a `ksl_SE3f_t` datastructure to a `ksl_mat4x4f_t` datastructure

@param d [in] input SE3f datastructure
@param m [out] output mat4x4f matrix
*/
static inline void ksl_SE3f_toMat4x4f(const ksl_SE3f_t* d, ksl_mat4x4f_t* m);

/*!
@brief convert a `ksl_SE3_t` datastructure to a `ksl_mat4x4f_t` datastructure

@param d [in] input SE3 datastructure
@param m [out] output mat4x4f matrix
*/
static inline void ksl_SE3_toMat4x4f(const ksl_SE3_t* d, ksl_mat4x4f_t* m);

/*!
 * @brief return a `ksl_SE3_t` initialized to identity
 @return ksl_SE3_t initialized to identity
*/
static inline ksl_SE3_t ksl_SE3_identity();

/*!
@brief Set a double precision SE3 matrix to identity.

\f$\begin{bmatrix}I & 0\\0 & 1\end{bmatrix} \rightarrow \Phi \f$

@param d [in/out] input SE3 matrix
*/
static inline void ksl_SE3_setIdentity(ksl_SE3_t* d);

/*!
@brief Set a single precision SE3 matrix to identity.

\f$\begin{bmatrix}I & 0\\0 & 1\end{bmatrix} \rightarrow \Phi \f$

@param d [in/out] input SE3 matrix
*/
static inline void ksl_SE3f_setIdentity(ksl_SE3f_t* d);

/*!
@brief Set a value in a double precision SE3 matrix at specified row and
column index.

Bounds checking are performed in debug mode. Bounds checking can be disabled by
compiling in release mode using the compiler flag -DNDEBUG.

The `ksl_SE3_t` data structure is designed specifically for rigid body
transformations and is a subset of more general 4x4 matrices. As the fourth row
of an SE(3) matrix always contains 0s and 1s, no memory is allocated for these
quantities and it is not permitted to set values in these locations. If it is
desired to set quantities in the last row, it is recommended to use the more
general `ksl_mat4x4_t` data structure.

@param D [in/out]
@param row [in] row index, \f$0 \le row \lt 3\f$
@param column [in] column index, \f$0 \le column \lt 4\f$
@param value [in] value to set
*/
static inline void ksl_SE3_set(ksl_SE3_t* D, const int row, const int column,
                               const double value);

/*!
@brief Set a value in a single precision SE3 matrix at specified row and
column index.

Bounds checking are performed in debug mode. Bounds checking can be disabled by
compiling in release mode using the compiler flag -DNDEBUG.

The `ksl_SE3_t` data structure is designed specifically for rigid body
transformations and is a subset of more general 4x4 matrices. As the fourth row
of an SE(3) matrix always contains 0s and 1s, no memory is allocated for these
quantities and it is not permitted to set values in these locations. If it is
desired to set quantities in the last row, it is recommended to use the more
general `ksl_mat4x4_t` data structure.

@param D [in/out]
@param row [in] row index, \f$0 \le row \lt 3\f$
@param column [in] column index, \f$0 \le column \lt 4\f$
@param value [in] value to set
*/
static inline void ksl_SE3f_set(ksl_SE3f_t* D, const int row, const int column,
                                const float value);

/*!
@brief Return the entry of the 3x4 matrix [R t] of an SE3 transformation at
(row, column).

@param D [in] SE3 transformation
@param row [in] row index, 0 to 2
@param column [in] column index, 0 to 3; column 3 is the translation
@return the requested entry
*/
static inline double ksl_SE3_get(const ksl_SE3_t* D, const int row,
                                 const int column);

/*!
@brief Single precision version of ksl_SE3_get().
*/
static inline float ksl_SE3f_get(const ksl_SE3f_t* D, const int row,
                                 const int column);

/*!
@brief Copy the translation part of an SE3 transformation.

@param D [in] SE3 transformation
@param t [out] translation of D
*/
static inline void ksl_SE3_getTranslation(const ksl_SE3_t* D, ksl_vec3_t* t);

/*!
@brief Single precision version of ksl_SE3_getTranslation().
*/
static inline void ksl_SE3f_getTranslation(const ksl_SE3f_t* D, ksl_vec3f_t* t);

/*!
@brief Invert an SE3 transformation in place: D = D^-1.

For D = (R, t) the inverse is (R^T, -R^T t).

@param D [in,out] SE3 transformation, replaced by its inverse
*/
static inline void ksl_SE3_invert(ksl_SE3_t* D);

/*!
@brief Single precision version of ksl_SE3_invert().
*/
static inline void ksl_SE3f_invert(ksl_SE3f_t* D);

/*!
@brief Compute the inverse of an SE3 transformation: Do = Di^-1.

For Di = (R, t) the inverse is (R^T, -R^T t). Di and Do must not overlap.

@param Di [in] SE3 transformation
@param Do [out] inverse of Di
*/
static inline void ksl_SE3_inverted(const ksl_SE3_t* Di, ksl_SE3_t* Do);

/*!
@brief Single precision version of ksl_SE3_inverted().
*/
static inline void ksl_SE3f_inverted(const ksl_SE3f_t* Di, ksl_SE3f_t* Do);

/*!
@brief Copy an SE3 transformation: Do = Di.

@param Di [in] transformation to copy
@param Do [out] copy of Di
*/
static inline void ksl_SE3_copy(const ksl_SE3_t* Di, ksl_SE3_t* Do);

/*!
@brief Single precision version of ksl_SE3_copy().
*/
static inline void ksl_SE3f_copy(const ksl_SE3f_t* Di, ksl_SE3f_t* Do);

/*!
@brief Exponential of a screw, \f$\Phi = \exp\boldsymbol{\underline{\xi}}\f$: the same as
ksl_screw_exp().

@param si [in] screw \f$\boldsymbol{\underline{\xi}}\f$
@param Do [out] displacement \f$\exp\boldsymbol{\underline{\xi}}\f$
*/
void ksl_SE3_exp(const ksl_screw_t* si, ksl_SE3_t* Do);

/*!
@brief Single precision version of ksl_SE3_exp().
*/
void ksl_SE3f_exp(const ksl_screwf_t* si, ksl_SE3f_t* Do);

/*!
@brief Logarithm of a displacement, \f$\boldsymbol{\underline{\xi}} = \log\Phi\f$: the
same as ksl_screw_log().

@param Di [in] displacement \f$\Phi\f$
@param so [out] screw \f$\log\Phi\f$
*/
void ksl_SE3_log(const ksl_SE3_t* Di, ksl_screw_t* so);

/*!
@brief Single precision version of ksl_SE3_log().
*/
void ksl_SE3f_log(const ksl_SE3f_t* Di, ksl_screwf_t* so);

/*!
@brief Interpolation of a displacement with a straight path of the origin.

\f[
R(t) = R_1 R(\underline{u}, t\theta), \qquad \underline{r}(t) = (1 - t)\,\underline{r}_1 +
t\,\underline{r}_2, \qquad 0 \le t \le 1,
\f]

where \f$\underline{u}\f$ and \f$0 \le \theta \le \pi\f$ are the axis and angle of
\f$R_1^{T}R_2\f$ (ksl_mat3x3_getAxisAngle()): the rotation is the slerp of the rotations and the
origin of the moving frame moves along the straight line between the two origins. Unlike
ksl_SE3_sclerp(), the path depends on which point of the moving frame is taken as its origin.

@param D1i [in] displacement at t = 0
@param D2i [in] displacement at t = 1
@param t [in] interpolation parameter, from 0 to 1
@param Do [out] interpolated displacement
*/
void ksl_SE3_lerp(const ksl_SE3_t* D1i, const ksl_SE3_t* D2i, const double* t,
                  ksl_SE3_t* Do);

/*!
@brief Single precision version of ksl_SE3_lerp(), computed in double precision.
*/
void ksl_SE3f_lerp(const ksl_SE3f_t* D1i, const ksl_SE3f_t* D2i, const float* t,
                   ksl_SE3f_t* Do);

/*!
@brief Screw linear interpolation (sclerp) between two displacements.

\f[
\mathrm{sclerp}(\Phi_1, \Phi_2, t) = \Phi_1 \exp\bigl(t \log(\Phi_1^{-1}\Phi_2)\bigr),
\qquad 0 \le t \le 1,
\f]

moves the frame from \f$\Phi_1\f$ to \f$\Phi_2\f$ along the screw axis of the relative
displacement \f$\Phi_1^{-1}\Phi_2\f$, at a constant velocity screw. It is the counterpart for
displacements of ksl_quaternion_slerp(); the rotation part is the slerp of the rotations, and
the path does not depend on the choice of the fixed frame or of the point of the moving frame
taken as its origin. The relative rotation is taken the shorter way.

@param D1i [in] displacement at t = 0
@param D2i [in] displacement at t = 1
@param t [in] interpolation parameter, from 0 to 1
@param Do [out] interpolated displacement
*/
void ksl_SE3_sclerp(const ksl_SE3_t* D1i, const ksl_SE3_t* D2i, const double* t,
                    ksl_SE3_t* Do);

/*!
@brief Single precision version of ksl_SE3_sclerp(), computed in double precision.
*/
void ksl_SE3f_sclerp(const ksl_SE3f_t* D1i, const ksl_SE3f_t* D2i, const float* t,
                     ksl_SE3f_t* Do);

/*!
@brief Control displacement of a key displacement for ksl_SE3_squad().

Given the key \f$\Phi_k\f$ and its neighbors \f$\Phi_{k-1}\f$ and \f$\Phi_{k+1}\f$, computes

\f[
\Sigma_k = \Phi_k \exp\left(-\frac{\log(\Phi_k^{-1}\Phi_{k+1}) +
\log(\Phi_k^{-1}\Phi_{k-1})}{4}\right),
\f]

the counterpart for displacements of ksl_quaternion_squad_control(), which makes the
velocity screw of the path through the keys continuous at \f$\Phi_k\f$.

@param Dprevi [in] previous key, \f$\Phi_{k-1}\f$
@param Di [in] key, \f$\Phi_k\f$
@param Dnexti [in] next key, \f$\Phi_{k+1}\f$
@param So [out] control displacement, \f$\Sigma_k\f$
*/
void ksl_SE3_squad_control(const ksl_SE3_t* Dprevi, const ksl_SE3_t* Di,
                           const ksl_SE3_t* Dnexti, ksl_SE3_t* So);

/*!
@brief Single precision version of ksl_SE3_squad_control(), computed in double
precision.
*/
void ksl_SE3f_squad_control(const ksl_SE3f_t* Dprevi, const ksl_SE3f_t* Di,
                            const ksl_SE3f_t* Dnexti, ksl_SE3f_t* So);

/*!
@brief Screw quadrangle interpolation between two key displacements.

\f[
\mathrm{squad}(\Phi_1, \Phi_2, \Sigma_1, \Sigma_2, t) = \mathrm{sclerp}\big(
\mathrm{sclerp}(\Phi_1, \Phi_2, t), \mathrm{sclerp}(\Sigma_1, \Sigma_2, t), 2t(1 - t)\big),
\f]

with the control displacements \f$\Sigma_1\f$ and \f$\Sigma_2\f$ from ksl_SE3_squad_control():
the counterpart for displacements of ksl_quaternion_squad(). Joining the segments between
successive keys gives a path through all the keys whose velocity screw is continuous at the
keys; its acceleration in general is not.

@param D1i [in] key at t = 0
@param D2i [in] key at t = 1
@param S1i [in] control displacement of D1i
@param S2i [in] control displacement of D2i
@param t [in] interpolation parameter, from 0 to 1
@param Do [out] interpolated displacement
*/
void ksl_SE3_squad(const ksl_SE3_t* D1i, const ksl_SE3_t* D2i,
                   const ksl_SE3_t* S1i, const ksl_SE3_t* S2i, const double* t,
                   ksl_SE3_t* Do);

/*!
@brief Single precision version of ksl_SE3_squad(), computed in double precision.
*/
void ksl_SE3f_squad(const ksl_SE3f_t* D1i, const ksl_SE3f_t* D2i,
                    const ksl_SE3f_t* S1i, const ksl_SE3f_t* S2i, const float* t,
                    ksl_SE3f_t* Do);

/*!
@brief Interpolate an array of key displacements with ksl_SE3_squad().

Evaluates the path through the n keys at the parameter t, which runs from 0 at keys[0] to
n - 1 at keys[n - 1]: key k is reached at t = k. Between keys k and k + 1 it calls
ksl_SE3_squad() with t - k, computing the two control displacements with
ksl_SE3_squad_control(); the first and last keys are their own control displacements.
t outside [0, n - 1] is clamped. The counterpart for displacements of
ksl_quaternion_squad_keys().

@param n [in] number of keys, at least 1
@param keys [in] key displacements
@param t [in] key parameter, from 0 to n - 1
@param Do [out] interpolated displacement
*/
void ksl_SE3_squad_keys(int n, const ksl_SE3_t* keys, const double* t,
                        ksl_SE3_t* Do);

/*!
@brief Single precision version of ksl_SE3_squad_keys(), computed in double
precision.
*/
void ksl_SE3f_squad_keys(int n, const ksl_SE3f_t* keys, const float* t,
                         ksl_SE3f_t* Do);

#ifdef __cplusplus
}
#endif

/* -------- inline definitions -------- */

#include <assert.h>
#include <math.h>
#include <string.h>

#include "ksl/mat3x3.h"
#include "ksl/matrix.h"
#include "ksl/vec3.h"

#ifdef __cplusplus
extern "C" {
#endif

static inline ksl_SE3_t ksl_SE3(const double m00, const double m01,
                                const double m02, const double m03,
                                const double m10, const double m11,
                                const double m12, const double m13,
                                const double m20, const double m21,
                                const double m22, const double m23) {
  ksl_SE3_t d;
  d.R.m00 = m00;
  d.R.m01 = m01;
  d.R.m02 = m02;
  d.R.m10 = m10;
  d.R.m11 = m11;
  d.R.m12 = m12;
  d.R.m20 = m20;
  d.R.m21 = m21;
  d.R.m22 = m22;
  d.t.x = m03;
  d.t.y = m13;
  d.t.z = m23;
  return d;
}

static inline ksl_SE3_t ksl_SE3_cmo(const double m00, const double m10,
                                    const double m20, const double m01,
                                    const double m11, const double m21,
                                    const double m02, const double m12,
                                    const double m22, const double m03,
                                    const double m13, const double m23) {
  ksl_SE3_t d;
  d.R.m00 = m00;
  d.R.m10 = m10;
  d.R.m20 = m20;
  d.R.m01 = m01;
  d.R.m11 = m11;
  d.R.m21 = m21;
  d.R.m02 = m02;
  d.R.m12 = m12;
  d.R.m22 = m22;
  d.t.x = m03;
  d.t.y = m13;
  d.t.z = m23;
  return d;
}

static inline ksl_SE3_t ksl_SE3_fromRt(const ksl_mat3x3_t R,
                                       const ksl_vec3_t t) {
  ksl_SE3_t d;
  d.R = R;
  d.t = t;
  return d;
}

static inline ksl_SE3f_t
ksl_SE3f(const float m00, const float m01, const float m02, const float m03,
         const float m10, const float m11, const float m12, const float m13,
         const float m20, const float m21, const float m22, const float m23) {
  ksl_SE3f_t d;
  d.R.m00 = m00;
  d.R.m01 = m01;
  d.R.m02 = m02;
  d.R.m10 = m10;
  d.R.m11 = m11;
  d.R.m12 = m12;
  d.R.m20 = m20;
  d.R.m21 = m21;
  d.R.m22 = m22;
  d.t.x = m03;
  d.t.y = m13;
  d.t.z = m23;
  return d;
}

static inline ksl_SE3f_t ksl_SE3f_cmo(const float m00, const float m10,
                                      const float m20, const float m01,
                                      const float m11, const float m21,
                                      const float m02, const float m12,
                                      const float m22, const float m03,
                                      const float m13, const float m23) {
  ksl_SE3f_t d;
  d.R.m00 = m00;
  d.R.m10 = m10;
  d.R.m20 = m20;
  d.R.m01 = m01;
  d.R.m11 = m11;
  d.R.m21 = m21;
  d.R.m02 = m02;
  d.R.m12 = m12;
  d.R.m22 = m22;
  d.t.x = m03;
  d.t.y = m13;
  d.t.z = m23;
  return d;
}

static inline ksl_SE3f_t ksl_SE3f_fromRt(const ksl_mat3x3f_t R,
                                         const ksl_vec3f_t t) {
  ksl_SE3f_t d;
  d.R = R;
  d.t = t;
  return d;
}

static inline void ksl_SE3_toMat4x4(const ksl_SE3_t* KSL_RESTRICT d,
                                    ksl_mat4x4_t* KSL_RESTRICT m) {
  memset(m, 0, sizeof(ksl_mat4x4_t));
  for(int i = 0; i < 4; i++) {   /* column index */
    for(int j = 0; j < 3; j++) { /* row index */
      m->at[i][j] = d->at[i][j];
    }
  }
  m->at[3][3] = 1.0;
}

static inline void ksl_SE3f_toMat4x4f(const ksl_SE3f_t* KSL_RESTRICT d,
                                      ksl_mat4x4f_t* KSL_RESTRICT m) {
  memset(m, 0, sizeof(ksl_mat4x4f_t));
  for(int i = 0; i < 4; i++) {   /* column index */
    for(int j = 0; j < 3; j++) { /* row index */
      m->at[i][j] = d->at[i][j];
    }
  }
  m->at[3][3] = 1.0;
}

static inline void ksl_SE3_toMat4x4f(const ksl_SE3_t* d,
                                     ksl_mat4x4f_t* KSL_RESTRICT m) {
  memset(m, 0, sizeof(ksl_mat4x4f_t));
  for(int i = 0; i < 4; i++) {   /* column index */
    for(int j = 0; j < 3; j++) { /* row index */
      m->at[i][j] = d->at[i][j];
    }
  }
  m->at[3][3] = 1.f;
}

static inline ksl_SE3_t ksl_SE3_identity() {
  ksl_SE3_t d;
  ksl_SE3_setIdentity(&d);
  return d;
}

static inline void ksl_SE3_setIdentity(ksl_SE3_t* KSL_RESTRICT d) {
  memset(d, 0, sizeof(ksl_SE3_t));
  for(int i = 0; i < 3; i++) {
    d->at[i][i] = 1.0;
  }
}

static inline void ksl_SE3f_setIdentity(ksl_SE3f_t* KSL_RESTRICT d) {
  memset(d, 0, sizeof(ksl_SE3f_t));
  for(int i = 0; i < 3; i++) {
    d->at[i][i] = 1.f;
  }
}

static inline void ksl_SE3_set(ksl_SE3_t* KSL_RESTRICT D, const int row,
                               const int column, const double value) {
  assert(row < 3 && column < 4);
  D->at[column][row] = value;
}

static inline void ksl_SE3f_set(ksl_SE3f_t* D, int row, int column,
                                float value) {
  assert(row < 3 && column < 4);
  D->at[column][row] = value;
}

static inline double ksl_SE3_get(const ksl_SE3_t* KSL_RESTRICT D, const int row,
                                 const int column) {
  assert(row < 3 && column < 4);
  return D->at[column][row];
}

static inline float ksl_SE3f_get(const ksl_SE3f_t* KSL_RESTRICT D,
                                 const int row, const int column) {
  assert(row < 3 && column < 4);
  return D->at[column][row];
}

static inline void ksl_SE3_getTranslation(const ksl_SE3_t* KSL_RESTRICT D,
                                          ksl_vec3_t* KSL_RESTRICT t) {
  memcpy(t, &D->t, sizeof(ksl_vec3_t));
}

static inline void ksl_SE3f_getTranslation(const ksl_SE3f_t* KSL_RESTRICT D,
                                           ksl_vec3f_t* KSL_RESTRICT t) {
  memcpy(t, &D->t, sizeof(ksl_vec3f_t));
}

static inline void ksl_SE3_copy(const ksl_SE3_t* Di, ksl_SE3_t* Do) {
  memcpy(Do, Di, sizeof(ksl_SE3_t));
}

static inline void ksl_SE3f_copy(const ksl_SE3f_t* Di, ksl_SE3f_t* Do) {
  memcpy(Do, Di, sizeof(ksl_SE3f_t));
}

static inline void ksl_SE3_inverted(const ksl_SE3_t* Di, ksl_SE3_t* Do) {
  ksl_mat3x3_transposed(&Di->R, &Do->R);
  ksl_product_drinvvinv(&Di->R, &Di->t, &Do->t);
}

static inline void ksl_SE3f_inverted(const ksl_SE3f_t* Di, ksl_SE3f_t* Do) {
  ksl_mat3x3f_transposed(&Di->R, &Do->R);
  ksl_product_drinvvinvf(&Di->R, &Di->t, &Do->t);
}

static inline void ksl_SE3_invert(ksl_SE3_t* D) {
  ksl_vec3_t temp;
  ksl_product_drinvvinv(&D->R, &D->t, &temp);
  ksl_mat3x3_transpose(&D->R);
  ksl_vec3_copy(&temp, &D->t);
}

static inline void ksl_SE3f_invert(ksl_SE3f_t* D) {
  ksl_vec3f_t temp;
  ksl_product_drinvvinvf(&D->R, &D->t, &temp);
  ksl_mat3x3f_transpose(&D->R);
  ksl_vec3f_copy(&temp, &D->t);
}

#ifdef __cplusplus
}
#endif

#endif
