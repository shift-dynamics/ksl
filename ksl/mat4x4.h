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

#ifndef _KSL_MAT4X4_H_
#define _KSL_MAT4X4_H_

#include "ksl/types.h"

#include <stdarg.h>

#include "axis.h"
#include "pub_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "vec3.h"
#include "vec4.h"

/*!
@brief ksl_mat4x4_t constructor.

Note that in the constructor, fields are specified in row major order.
Internally, ksl_mat4x4_t datastructures are stored in column major order.
*/
static inline ksl_mat4x4_t ksl_mat4x4(
  const double m00, const double m01, const double m02, const double m03,
  const double m10, const double m11, const double m12, const double m13,
  const double m20, const double m21, const double m22, const double m23,
  const double m30, const double m31, const double m32, const double m33);

/*!
@brief alternative ksl_mat4x4_t constructor.

In this alternate constructor, fields are specified in column major order to
match the internal layout of ksl_mat4x4_t datastructures.
*/
static inline ksl_mat4x4_t ksl_mat4x4_cmo(
  const double m00, const double m10, const double m20, const double m30,
  const double m01, const double m11, const double m21, const double m31,
  const double m02, const double m12, const double m22, const double m32,
  const double m03, const double m13, const double m23, const double m33);

/*!
@brief alternative ksl_mat4x4_t constructor that allows creating a ksl_mat4x4_t
datastructure from a ksl_SE3_t datastructure.
*/
static inline ksl_mat4x4_t ksl_mat4x4_fromSE3(const ksl_SE3_t D);

/*!
@brief Convert a 4x4 homogeneous transformation matrix to an SE3 transformation.

Copies the rotation and translation (the top three rows); the bottom row of M is
ignored.

@param M [in] 4x4 homogeneous transformation matrix
@param D [out] the same transformation as an SE3
*/
static inline void ksl_mat4x4_toSE3(const ksl_mat4x4_t* M, ksl_SE3_t* D);

/*!
@brief Single precision version of ksl_mat4x4_toSE3().
*/
static inline void ksl_mat4x4f_toSE3f(const ksl_mat4x4f_t* M, ksl_SE3f_t* D);
/*!
@brief alternative ksl_mat4x4_t constructor that allows creating a ksl_mat4x4_t
datastructure from ksl_mat3x3_t and ksl_vec3_t datastructures.
*/
static inline ksl_mat4x4_t ksl_mat4x4_fromRt(const ksl_mat3x3_t R,
                                             const ksl_vec3_t t);

/*!
@brief ksl_mat4x4f_t constructor.

Note that in the constructor, fields are specified in row major order.
Internally, ksl_mat4x4f_t datastructures are stored in column major order.
*/
static inline ksl_mat4x4f_t
ksl_mat4x4f(const float m00, const float m01, const float m02, const float m03,
            const float m10, const float m11, const float m12, const float m13,
            const float m20, const float m21, const float m22, const float m23,
            const float m30, const float m31, const float m32, const float m33);

/*!
@brief alternative ksl_mat4x4f_t constructor.

In this alternate constructor, fields are specified in column major order to
match the internal layout of ksl_mat4x4f_t datastructures.
*/
static inline ksl_mat4x4f_t ksl_mat4x4f_cmo(
  const float m00, const float m10, const float m20, const float m30,
  const float m01, const float m11, const float m21, const float m31,
  const float m02, const float m12, const float m22, const float m32,
  const float m03, const float m13, const float m23, const float m33);

/*!
@brief alternative ksl_mat4x4f_t constructor that allows creating a
ksl_mat4x4f_t datastructure from a ksl_SE3f_t datastructure.
*/
static inline ksl_mat4x4f_t ksl_mat4x4f_fromSE3f(const ksl_SE3f_t D);

/*!
@brief alternative ksl_mat4x4f_t constructor that allows creating a
ksl_mat4x4f_t datastructure from ksl_mat3x3f_t and ksl_vec3f_t datastructures.
*/
static inline ksl_mat4x4f_t ksl_mat4x4f_fromRt(const ksl_mat3x3f_t R,
                                               const ksl_vec3f_t t);

/*!
@brief allocates n ksl_mat4x4_t datastructures on the heap. Must be freed by the
user.
*/
ksl_mat4x4_t* ksl_mat4x4_alloc(int n);

/*!
@brief allocates n ksl_mat4x4f_t datastructures on the heap. Must be freed by
the user.
*/
ksl_mat4x4f_t* ksl_mat4x4f_alloc(int n);

/*!
@brief Set a value in a double precision 4x4 matrix at specified row and
column index.

Bounds checking are performed in debug mode. Bounds checking can be disabled by
compiling in release mode using the compiler flag -DNDEBUG.

@param M [in/out]
@param row [in] row index, \f$0 \le row \lt 4\f$
@param column [in] column index, \f$0 \le column \lt 4\f$
@param value [in] value to set
*/
static inline void ksl_mat4x4_set(ksl_mat4x4_t* M, const int row,
                                  const int column, const double value);

/*!
@brief Set a value in a single precision 4x4 matrix at specified row and
column index.

Bounds checking are performed in debug mode. Bounds checking can be disabled by
compiling in release mode using the compiler flag -DNDEBUG.

@param D [in,out] matrix to modify
@param row [in] row index, \f$0 \le row \lt 4\f$
@param column [in] column index, \f$0 \le column \lt 4\f$
@param value [in] value to set
*/
static inline void ksl_mat4x4f_set(ksl_mat4x4f_t* D, int row, int column,
                                   float value);

/*!
@brief Set a double precision 4x4 matrix to identity.

\f$ I \rightarrow M \f$

@param M [in/out] input 4x4 matrix
*/
static inline void ksl_mat4x4_setIdentity(ksl_mat4x4_t* M);

/*!
@brief Set a single precision 4x4 matrix to identity.

\f$ I \rightarrow M \f$

@param M [in/out] input 4x4 matrix
*/
static inline void ksl_mat4x4f_setIdentity(ksl_mat4x4f_t* M);

/*!
@brief Obtain the 3D translation component of a double precision 4x4 matrix
@param Mi [in] input 4x4 matrix
@param to [out] translation vector returned in to
*/
static inline void ksl_mat4x4_getTranslation(const ksl_mat4x4_t* Mi,
                                             ksl_vec3_t* to);

/*!
@brief Obtain the 3D translation component of a single precision 4x4 matrix
@param Mi [in] input 4x4 matrix
@param to [out] translation vector returned in to
*/
static inline void ksl_mat4x4f_getTranslation(const ksl_mat4x4f_t* Mi,
                                              ksl_vec3f_t* to);

/*!
@brief Basic get function for a double precision 4x4 matrix

Bounds checking are performed in debug mode. Bounds checking can be disabled by
compiling in release mode using the compiler flag -DNDEBUG.

@param Mi [in] input 4x4 matrix
@param row [in] row index
@param column [in] column index
@return value at specified row and column index
*/
static inline double ksl_mat4x4_get(const ksl_mat4x4_t* Mi, const int row,
                                    const int column);

/*!
@brief Basic get function for a single precision 4x4 matrix

Bounds checking are performed in debug mode. Bounds checking can be disabled by
compiling in release mode using the compiler flag -DNDEBUG.

@param Mi [in] input 4x4 matrix
@param row [in] row index
@param column [in] column index
@return value at specified row and column index
*/
static inline float ksl_mat4x4f_get(const ksl_mat4x4f_t* Mi, const int row,
                                    const int column);

#ifdef __cplusplus
}
#endif

/* -------- inline definitions -------- */

#include <assert.h>
#include <math.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

static inline ksl_mat4x4_t ksl_mat4x4(
  const double m00, const double m01, const double m02, const double m03,
  const double m10, const double m11, const double m12, const double m13,
  const double m20, const double m21, const double m22, const double m23,
  const double m30, const double m31, const double m32, const double m33) {
  ksl_mat4x4_t m;
  m.m00 = m00;
  m.m01 = m01;
  m.m02 = m02;
  m.m03 = m03;
  m.m10 = m10;
  m.m11 = m11;
  m.m12 = m12;
  m.m13 = m13;
  m.m20 = m20;
  m.m21 = m21;
  m.m22 = m22;
  m.m23 = m23;
  m.m30 = m30;
  m.m31 = m31;
  m.m32 = m32;
  m.m33 = m33;
  return m;
}

static inline ksl_mat4x4_t ksl_mat4x4_cmo(
  const double m00, const double m10, const double m20, const double m30,
  const double m01, const double m11, const double m21, const double m31,
  const double m02, const double m12, const double m22, const double m32,
  const double m03, const double m13, const double m23, const double m33) {
  ksl_mat4x4_t m;
  m.m00 = m00;
  m.m10 = m10;
  m.m20 = m20;
  m.m30 = m30;
  m.m01 = m01;
  m.m11 = m11;
  m.m21 = m21;
  m.m31 = m31;
  m.m02 = m02;
  m.m12 = m12;
  m.m22 = m22;
  m.m32 = m32;
  m.m03 = m03;
  m.m13 = m13;
  m.m23 = m23;
  m.m33 = m33;
  return m;
}

static inline ksl_mat4x4_t ksl_mat4x4_fromSE3(const ksl_SE3_t D) {
  ksl_mat4x4_t m;
  m.m00 = D.m00;
  m.m10 = D.m10;
  m.m20 = D.m20;
  m.m30 = 0.0;
  m.m01 = D.m01;
  m.m11 = D.m11;
  m.m21 = D.m21;
  m.m31 = 0.0;
  m.m02 = D.m02;
  m.m12 = D.m12;
  m.m22 = D.m22;
  m.m32 = 0.0;
  m.m03 = D.m03;
  m.m13 = D.m13;
  m.m23 = D.m23;
  m.m33 = 1.0;
  return m;
}

static inline ksl_mat4x4_t ksl_mat4x4_fromRt(const ksl_mat3x3_t R,
                                             const ksl_vec3_t t) {
  ksl_mat4x4_t m;
  m.m00 = R.m00;
  m.m01 = R.m01;
  m.m02 = R.m02;
  m.m03 = t.x;
  m.m10 = R.m10;
  m.m11 = R.m11;
  m.m12 = R.m12;
  m.m13 = t.y;
  m.m20 = R.m20;
  m.m21 = R.m21;
  m.m22 = R.m22;
  m.m23 = t.z;
  m.m30 = 0.0;
  m.m31 = 0.0;
  m.m32 = 0.0;
  m.m33 = 1.0;
  return m;
}

static inline ksl_mat4x4f_t
ksl_mat4x4f(const float m00, const float m01, const float m02, const float m03,
            const float m10, const float m11, const float m12, const float m13,
            const float m20, const float m21, const float m22, const float m23,
            const float m30, const float m31, const float m32,
            const float m33) {
  ksl_mat4x4f_t m;
  m.m00 = m00;
  m.m01 = m01;
  m.m02 = m02;
  m.m03 = m03;
  m.m10 = m10;
  m.m11 = m11;
  m.m12 = m12;
  m.m13 = m13;
  m.m20 = m20;
  m.m21 = m21;
  m.m22 = m22;
  m.m23 = m23;
  m.m30 = m30;
  m.m31 = m31;
  m.m32 = m32;
  m.m33 = m33;
  return m;
}

static inline ksl_mat4x4f_t ksl_mat4x4f_cmo(
  const float m00, const float m10, const float m20, const float m30,
  const float m01, const float m11, const float m21, const float m31,
  const float m02, const float m12, const float m22, const float m32,
  const float m03, const float m13, const float m23, const float m33) {
  ksl_mat4x4f_t m;
  m.m00 = m00;
  m.m10 = m10;
  m.m20 = m20;
  m.m30 = m30;
  m.m01 = m01;
  m.m11 = m11;
  m.m21 = m21;
  m.m31 = m31;
  m.m02 = m02;
  m.m12 = m12;
  m.m22 = m22;
  m.m32 = m32;
  m.m03 = m03;
  m.m13 = m13;
  m.m23 = m23;
  m.m33 = m33;
  return m;
}

static inline ksl_mat4x4f_t ksl_mat4x4f_fromSE3f(const ksl_SE3f_t D) {
  ksl_mat4x4f_t m;
  m.m00 = D.m00;
  m.m01 = D.m01;
  m.m02 = D.m02;
  m.m03 = D.m03;
  m.m10 = D.m10;
  m.m11 = D.m11;
  m.m12 = D.m12;
  m.m13 = D.m13;
  m.m20 = D.m20;
  m.m21 = D.m21;
  m.m22 = D.m22;
  m.m23 = D.m23;
  m.m30 = 0.0;
  m.m31 = 0.0;
  m.m32 = 0.0;
  m.m33 = 1.0;
  return m;
}

static inline void ksl_mat4x4_toSE3(const ksl_mat4x4_t* KSL_RESTRICT M,
                                    ksl_SE3_t* KSL_RESTRICT D) {
  D->m00 = M->m00;
  D->m01 = M->m01;
  D->m02 = M->m02;
  D->m03 = M->m03;
  D->m10 = M->m10;
  D->m11 = M->m11;
  D->m12 = M->m12;
  D->m13 = M->m13;
  D->m20 = M->m20;
  D->m21 = M->m21;
  D->m22 = M->m22;
  D->m23 = M->m23;
}

static inline void ksl_mat4x4f_toSE3f(const ksl_mat4x4f_t* KSL_RESTRICT M,
                                      ksl_SE3f_t* KSL_RESTRICT D) {
  D->m00 = M->m00;
  D->m01 = M->m01;
  D->m02 = M->m02;
  D->m03 = M->m03;
  D->m10 = M->m10;
  D->m11 = M->m11;
  D->m12 = M->m12;
  D->m13 = M->m13;
  D->m20 = M->m20;
  D->m21 = M->m21;
  D->m22 = M->m22;
  D->m23 = M->m23;
}

static inline ksl_mat4x4f_t ksl_mat4x4f_fromRt(const ksl_mat3x3f_t R,
                                               const ksl_vec3f_t t) {
  ksl_mat4x4f_t m;
  m.m00 = R.m00;
  m.m01 = R.m01;
  m.m02 = R.m02;
  m.m03 = t.x;
  m.m10 = R.m10;
  m.m11 = R.m11;
  m.m12 = R.m12;
  m.m13 = t.y;
  m.m20 = R.m20;
  m.m21 = R.m21;
  m.m22 = R.m22;
  m.m23 = t.z;
  m.m30 = 0.0;
  m.m31 = 0.0;
  m.m32 = 0.0;
  m.m33 = 1.0;
  return m;
}

static inline void ksl_mat4x4_setIdentity(ksl_mat4x4_t* M) {
  memset(M, 0, sizeof(ksl_mat4x4_t));
  for(int i = 0; i < 4; i++) {
    M->at[i][i] = 1.0;
  }
}

static inline void ksl_mat4x4f_setIdentity(ksl_mat4x4f_t* M) {
  memset(M, 0, sizeof(ksl_mat4x4f_t));
  for(int i = 0; i < 4; i++) {
    M->at[i][i] = 1.0;
  }
}

static inline void ksl_mat4x4_set(ksl_mat4x4_t* KSL_RESTRICT M, const int row,
                                  const int column, const double value) {
  assert(row < 4 && column < 4);
  M->at[column][row] = value;
}

static inline void ksl_mat4x4f_set(ksl_mat4x4f_t* KSL_RESTRICT M, int row,
                                   int column, float value) {
  assert(row < 4 && column < 4);
  M->at[column][row] = value;
}

static inline double ksl_mat4x4_get(const ksl_mat4x4_t* KSL_RESTRICT R,
                                    const int row, const int column) {
  assert(row < 4 && column < 4);
  return R->at[column][row];
}

static inline float ksl_mat4x4f_get(const ksl_mat4x4f_t* KSL_RESTRICT R,
                                    const int row, const int column) {
  assert(row < 4 && column < 4);
  return R->at[column][row];
}

static inline void
ksl_mat4x4_getTranslation(const ksl_mat4x4_t* KSL_RESTRICT Mi,
                          ksl_vec3_t* KSL_RESTRICT to) {
  memcpy(to, &Mi->v3, sizeof(ksl_vec3_t));
}

static inline void
ksl_mat4x4f_getTranslation(const ksl_mat4x4f_t* KSL_RESTRICT Mi,
                           ksl_vec3f_t* to) {
  memcpy(to, &Mi->v3, sizeof(ksl_vec3f_t));
}

#ifdef __cplusplus
}
#endif

#endif
