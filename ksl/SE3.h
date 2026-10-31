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
@brief TODO document this function
*/
static inline double ksl_SE3_get(const ksl_SE3_t* D, const int row,
                                 const int column);

/*!
@brief TODO document this function
*/
static inline float ksl_SE3f_get(const ksl_SE3f_t* D, const int row,
                                 const int column);

/*!
@brief TODO document this function
*/
static inline void ksl_SE3_getTranslation(const ksl_SE3_t* D, ksl_vec3_t* t);

/*!
@brief TODO document this function
*/
static inline void ksl_SE3f_getTranslation(const ksl_SE3f_t* D, ksl_vec3f_t* t);

/*!
@brief TODO document this function
*/
static inline void ksl_SE3_invert(ksl_SE3_t* D);

/*!
@brief TODO document this function
*/
static inline void ksl_SE3f_invert(ksl_SE3f_t* D);

/*!
@brief TODO document this function
*/
static inline void ksl_SE3_inverted(const ksl_SE3_t* Di, ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_SE3f_inverted(const ksl_SE3f_t* Di, ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_SE3_copy(const ksl_SE3_t* Di, ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
static inline void ksl_SE3f_copy(const ksl_SE3f_t* Di, ksl_SE3f_t* Do);

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
