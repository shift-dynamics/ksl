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

#ifndef _KSL_MAT3X3_H_
#define _KSL_MAT3X3_H_

#include "ksl/types.h"

#include <stdarg.h>

#include "axis.h"
#include "pub_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
@brief ksl_mat3x3_t constructor.

Note that in the constructor, fields are specified in row major order.
Internally, ksl_mat3x3_t datastructures are stored in column major order.
*/
static inline ksl_mat3x3_t ksl_mat3x3(const double m00, const double m01,
                                      const double m02, const double m10,
                                      const double m11, const double m12,
                                      const double m20, const double m21,
                                      const double m22);

/*!
@brief alternative ksl_mat3x3_t constructor.

In this alternate constructor, fields are specified in column major order to
match the internal layout of ksl_mat3x3_t datastructures.
*/
static inline ksl_mat3x3_t ksl_mat3x3_cmo(const double m00, const double m10,
                                          const double m20, const double m01,
                                          const double m11, const double m21,
                                          const double m02, const double m12,
                                          const double m22);

/*!
@brief ksl_mat3x3f_t constructor.

Note that in the constructor, fields are specified in row major order.
Internally, ksl_mat3x3f_t datastructures are stored in column major order.
*/
static inline ksl_mat3x3f_t ksl_mat3x3f(const float m00, const float m01,
                                        const float m02, const float m10,
                                        const float m11, const float m12,
                                        const float m20, const float m21,
                                        const float m22);

/*!
@brief alternative ksl_mat3x3f_t constructor.

In this alternate constructor, fields are specified in column major order to
match the internal layout of ksl_mat3x3f_t datastructures.
*/
static inline ksl_mat3x3f_t ksl_mat3x3f_cmo(const float m00, const float m10,
                                            const float m20, const float m01,
                                            const float m11, const float m21,
                                            const float m02, const float m12,
                                            const float m22);

/*!
@brief allocates n ksl_mat3x3_t datastructures on the heap. Must be freed by the
user.
*/
ksl_mat3x3_t* ksl_mat3x3_alloc(const int n);

/*!
@brief allocates n ksl_mat3x3f_t datastructures on the heap. Must be freed by
the user.
*/
ksl_mat3x3f_t* ksl_mat3x3f_alloc(const int n);

/*!
@brief Set a double precision 3x3 matrix to identity.

\f$ I \rightarrow R \f$

@param r [in/out] input 3x3 matrix
*/
static inline void ksl_mat3x3_setIdentity(ksl_mat3x3_t* r);

/*!
@brief Set a single precision 3x3 matrix to identity.

\f$ I \rightarrow R \f$

@param r [in/out] input 3x3 matrix
*/
static inline void ksl_mat3x3f_setIdentity(ksl_mat3x3f_t* r);

/*!
@brief Set a value in a double precision 3x3 matrix at specified row and
column index.

Bounds checking are performed in debug mode. Bounds checking can be disabled by
compiling in release mode using the compiler flag -DNDEBUG.

@param R [in/out]
@param row [in] row index, \f$0 \le row \lt 3\f$
@param column [in] column index, \f$0 \le column \lt 3\f$
@param value [in] value to set
*/
static inline void ksl_mat3x3_set(ksl_mat3x3_t* R, const int row,
                                  const int column, const double value);

/*!
@brief Set a double precision 3x3 matrix from 3 column vectors

\f$ \begin{bmatrix} \underline{v}_x & \underline{v}_y & \underline{v}_z
\end{bmatrix} \rightarrow R \f$

@param R [in/out] 3x3 rotation matrix
@param x [in] first column to set
@param y [in] second column to set
@param z [in] third column to set
*/
static inline void ksl_mat3x3_setFromVectors(ksl_mat3x3_t* R,
                                             const ksl_vec3_t* x,
                                             const ksl_vec3_t* y,
                                             const ksl_vec3_t* z);

/*!
@brief Set a single precision 3x3 matrix from 3 column vectors

\f$ \begin{bmatrix} \underline{v}_x & \underline{v}_y & \underline{v}_z
\end{bmatrix} \rightarrow R \f$

@param R [in/out] 3x3 rotation matrix
@param x [in] first column to set
@param y [in] second column to set
@param z [in] third column to set
*/
static inline void ksl_mat3x3f_setFromVectors(ksl_mat3x3f_t* R,
                                              const ksl_vec3f_t* x,
                                              const ksl_vec3f_t* y,
                                              const ksl_vec3f_t* z);

/*!
@brief Set a value in a single precision 3x3 matrix at specified row and
column index.

Bounds checking are performed in debug mode. Bounds checking can be disabled by
compiling in release mode using the compiler flag -DNDEBUG.

@param R [in/out]
@param row [in] row index, \f$0 \le row \lt 3\f$
@param column [in] column index, \f$0 \le column \lt 3\f$
@param value [in] value to set
*/
static inline void ksl_mat3x3f_set(ksl_mat3x3f_t* R, int row, int column,
                                   float value);

static inline void ksl_mat3x3_normalize(ksl_mat3x3_t* R);

static inline void ksl_mat3x3_normalized(const ksl_mat3x3_t* Ri,
                                         ksl_mat3x3_t* Ro);

static inline void ksl_mat3x3f_normalize(ksl_mat3x3f_t* R);

static inline void ksl_mat3x3f_normalized(const ksl_mat3x3f_t* Ri,
                                          ksl_mat3x3f_t* Ro);

/*!
@brief TODO document this function
*/
static inline double ksl_mat3x3_get(const ksl_mat3x3_t* R, const int row,
                                    const int column);

/*!
@brief TODO document this function
*/
static inline float ksl_mat3x3f_get(const ksl_mat3x3f_t* R, const int row,
                                    const int column);

/*!
@brief TODO document this function
*/
static inline void ksl_mat3x3_copy(const ksl_mat3x3_t* ri, ksl_mat3x3_t* ro);

/*!
@brief TODO document this function
*/
static inline void ksl_mat3x3f_copy(const ksl_mat3x3f_t* ri, ksl_mat3x3f_t* ro);

/*!
@brief TODO document this function
*/
int ksl_mat3x3_invert(ksl_mat3x3_t* R);

/*!
@brief TODO document this function
*/
int ksl_mat3x3f_invert(ksl_mat3x3f_t* R);

/*!
@brief TODO document this function
*/
int ksl_mat3x3_inverted(const ksl_mat3x3_t* ri, ksl_mat3x3_t* ro);

/*!
@brief TODO document this function
*/
int ksl_mat3x3f_inverted(const ksl_mat3x3f_t* ri, ksl_mat3x3f_t* ro);

/*!
@brief TODO document this function
*/
static inline void ksl_mat3x3_transpose(ksl_mat3x3_t* R);

/*!
@brief TODO document this function
*/
static inline void ksl_mat3x3f_transpose(ksl_mat3x3f_t* R);

/*!
@brief TODO document this function
*/
static inline void ksl_mat3x3_transposed(const ksl_mat3x3_t* ri,
                                         ksl_mat3x3_t* ro);

/*!
@brief TODO document this function
*/
static inline void ksl_mat3x3f_transposed(const ksl_mat3x3f_t* ri,
                                          ksl_mat3x3f_t* ro);

/*!
@brief This macro is used to obtain a double precision sequence of Euler angles
from an orthonormal rotation matrix using a specified axis sequence convention.

Note that this function requires the input direction cosine matrix to be
orthonormal, i.e., a member of the SO3 group. For efficiency, no checks are
performed on the input direction cosine matrix to check whether it is
orthonormal.

This function decomposes a general direction cosine matrix into three
primitive direction cosine matrices, whose axes are determined by a
`ksl_axis_enum_t` data structure which is passed in through the `axisType`
parameter. The direction cosine matrix is passed in through `r`, and the three
computed angles are updated and returned in `angles`.

Optionally, reference angles from a previous nearby position can be passed in
the last argument.

@param r [in] direction cosine matrix
@param axisType [in] an enum specifying angle sequence
@param angles [out] sequence of euler angles
@param referenceAngles [in/optional] a sequence of reference angles from a
nearby pose, used to obtain continuity in angles between poses.
*/
#define ksl_mat3x3_getEulerAngles(r, angles, axisType, ...)                    \
  {                                                                            \
    ksl_mat3x3_getEulerAnglesWithReference(r, angles, axisType, ##__VA_ARGS__, \
                                           NULL);                              \
  }

/*!
@brief Obtain double precision sequence of Euler angles using
specified axis sequence convention.

This function requires the input direction cosine matrix to be
orthonormal, i.e., a member of the SO3 group. For efficiency, no checks are
performed on the input direction cosine matrix to verify that it is
orthonormal.

This function decomposes a general direction cosine matrix into three
primitive direction cosine matrices, whose axes are determined by a
`ksl_axis_enum_t` enum data structure passed in through the `axisType`
parameter. The direction cosine matrix is passed in through the `r`, and the
three computed angles are updated and returned in `angles`.

Optionally, reference angles from a previous nearby position can be passed in
the last argument.

@param r [in] direction cosine matrix
@param axisType [in] an enum specifying angle sequence
@param angles [out] sequence of euler angles
@param referenceAngles [in/optional] a sequence of reference angles from a
nearby pose, used to obtain continuity in angles between poses.
*/
void ksl_mat3x3_getEulerAnglesWithReference(const ksl_mat3x3_t* r,
                                            const ksl_axis_enum_t axisType,
                                            ksl_vec3_t* angles, ...);

/*!
@brief This macro is used to obtain a single precision sequence of Euler angles
from an orthonormal rotation matrix using a specified axis sequence convention.

Note that this function requires the input direction cosine matrix to be
orthonormal, i.e., a member of the SO3 group. For efficiency, no checks are
performed on the input direction cosine matrix to check whether it is
orthonormal.

This function decomposes a general direction cosine matrix into three
primitive direction cosine matrices, whose axes are determined by a
`ksl_axis_enum_t` data structure which is passed in through the `axisType`
parameter. The direction cosine matrix is passed in through `r`, and the three
computed angles are updated and returned in `angles`.

Optionally, reference angles from a previous nearby position can be passed in
the last argument.

@param r [in] direction cosine matrix
@param axisType [in] an enum specifying angle sequence
@param angles [out] sequence of euler angles
@param referenceAngles [in/optional] a sequence of reference angles from a
nearby pose, used to obtain continuity in angles between poses.
*/
#define ksl_mat3x3f_getEulerAngles(r, angles, axisType, ...)                   \
  {                                                                            \
    ksl_mat3x3f_getEulerAnglesWithReference(r, angles, axisType,               \
                                            ##__VA_ARGS__, NULL);              \
  }

/*!
@brief Obtain single precision sequence of Euler angles using
specified axis sequence convention.

This function requires the input direction cosine matrix to be
orthonormal, i.e., a member of the SO3 group. For efficiency, no checks are
performed on the input direction cosine matrix to verify that it is
orthonormal.

This function decomposes a general direction cosine matrix into three
primitive direction cosine matrices, whose axes are determined by a
`ksl_axis_enum_t` enum data structure passed in through the `axisType`
parameter. The direction cosine matrix is passed in through the `r`, and the
three computed angles are updated and returned in `angles`.

Optionally, reference angles from a previous nearby position can be passed in
the last argument.

@param r [in] direction cosine matrix
@param axisType [in] an enum specifying angle sequence
@param angles [out] sequence of euler angles
@param referenceAngles [in/optional] a sequence of reference angles from a
nearby pose, used to obtain continuity in angles between poses.
*/
void ksl_mat3x3f_getEulerAnglesWithReference(const ksl_mat3x3f_t* r,
                                             const ksl_axis_enum_t axisType,
                                             ksl_vec3f_t* angles, ...);

/*!
@brief Set a double precision mat3x3 matrix from a sequence of Euler angles.

This function takes three Euler angles in one of twelve rotation orders
and outputs a direction cosine matrix. The axis sequence is input
using a ksl_axis_enum_t datastructure.

\f$ R_x = \begin{bmatrix} 1 & 0 & 0\\ 0 & c & -s \\ 0 & s & c \end{bmatrix}\f$

\f$ R_y = \begin{bmatrix} c & 0 & s\\ 0 & 1 & 0 \\ -s & 0 & c \end{bmatrix}\f$

\f$ R_z = \begin{bmatrix} c & -s & 0\\ s & c & 0 \\ 0 & 0 & 1 \end{bmatrix}\f$

*/
static inline void ksl_mat3x3_setFromEulerAngles(ksl_mat3x3_t*,
                                                 const ksl_axis_enum_t axisType,
                                                 const ksl_vec3_t*);

/*!
@brief Set a single precision mat3x3f matrix from a sequence of Euler angles

This function takes three Euler angles in one of twelve rotation orders
and outputs a direction cosine matrix. The axis sequence is input
using a ksl_axis_enum_t datastructure.

\f$ R_x = \begin{bmatrix} 1 & 0 & 0\\ 0 & c & -s \\ 0 & s & c \end{bmatrix}\f$

\f$ R_y = \begin{bmatrix} c & 0 & s\\ 0 & 1 & 0 \\ -s & 0 & c \end{bmatrix}\f$

\f$ R_z = \begin{bmatrix} c & -s & 0\\ s & c & 0 \\ 0 & 0 & 1 \end{bmatrix}\f$

*/
static inline void
ksl_mat3x3f_setFromEulerAngles(ksl_mat3x3f_t*, const ksl_axis_enum_t axisType,
                               const ksl_vec3f_t*);

/*!
@brief Get axis and angle from a double precision rotation matrix.

This function requires the input direction cosine matrix to be
orthonormal, i.e., a member of the SO3 group. For efficiency, no checks are
performed on the input direction cosine matrix to verify that it is
orthonormal.

Note that if sin is close to 0, the axis of rotation is not well defined.

@param r [in] input rotation matrix
@param axis [out] axis of rotation
@param angle [out] angle of rotation in radians
*/
static inline void ksl_mat3x3_getAxisAngle(const ksl_mat3x3_t* r,
                                           ksl_vec3_t* axis, double* angle);

/*!
@brief Set double precision rotation matrix from axis and angle representation.

@param r [out] rotation matrix will be set here
@param axis [in] axis of rotation
@param angle [in] angle of rotation in radians
*/
static inline void ksl_mat3x3_setFromAxisAngle(ksl_mat3x3_t*, const ksl_vec3_t*,
                                               const double);

/*!
@brief Get axis and angle from a single precision rotation matrix.

This function requires the input direction cosine matrix to be
orthonormal, i.e., a member of the SO3 group. For efficiency, no checks are
performed on the input direction cosine matrix to verify that it is
orthonormal.

Note that if sin is close to 0, the axis of rotation is not well defined.

@param r [in] input rotation matrix
@param axis [out] axis of rotation
@param angle [out] angle of rotation in radians
*/
static inline void ksl_mat3x3f_getAxisAngle(const ksl_mat3x3f_t* r,
                                            ksl_vec3f_t* axis, float* angle);

/*!
@brief Set a single precision rotation matrix from axis and angle
representation.

@param r [out] rotation matrix to set
@param axis [in] axis of rotation
@param angle [in] angle of rotation in radians
*/
static inline void ksl_mat3x3f_setFromAxisAngle(ksl_mat3x3f_t* r,
                                                const ksl_vec3f_t* axis,
                                                const float angle);

/*!
@brief Set 3x3 rotation matrix from axis and direction cosines
*/
static inline void ksl_mat3x3_setFromAxisDC(ksl_mat3x3_t* r,
                                            const ksl_vec3_t* axis,
                                            const double* dc);

/*!
@brief Compute the determinant of a 3x3 double precision matrix
@param ri [in] input 3x3 matrix
@param determinant
*/
static inline double ksl_mat3x3_determinant(const ksl_mat3x3_t* r_i);

/*!
@brief Compute the determinant of a 3x3 single precision matrix
@param ri [in] input 3x3 matrix
@param determinant
*/
static inline float ksl_mat3x3f_determinant(const ksl_mat3x3f_t*);

void ksl_mat3x3_pca(ksl_mat3x3_t* A, ksl_mat3x3_t* v);

#ifdef __cplusplus
}
#endif

/* -------- inline definitions -------- */

#include <assert.h>
#include <math.h>
#include <string.h>

#include "ksl/array.h"
#include "ksl/axis.h"
#include "ksl/linalg.h"
#include "ksl/matrix.h"
#include "ksl/trig.h"
#include "ksl/vec3.h"

#ifdef __cplusplus
extern "C" {
#endif

static inline ksl_mat3x3_t ksl_mat3x3(const double m00, const double m01,
                                      const double m02, const double m10,
                                      const double m11, const double m12,
                                      const double m20, const double m21,
                                      const double m22) {
  ksl_mat3x3_t r;
  r.m00 = m00;
  r.m01 = m01;
  r.m02 = m02;
  r.m10 = m10;
  r.m11 = m11;
  r.m12 = m12;
  r.m20 = m20;
  r.m21 = m21;
  r.m22 = m22;
  return r;
}

static inline ksl_mat3x3_t ksl_mat3x3_cmo(const double m00, const double m10,
                                          const double m20, const double m01,
                                          const double m11, const double m21,
                                          const double m02, const double m12,
                                          const double m22) {
  ksl_mat3x3_t r;
  r.m00 = m00;
  r.m10 = m10;
  r.m20 = m20;
  r.m01 = m01;
  r.m11 = m11;
  r.m21 = m21;
  r.m02 = m02;
  r.m12 = m12;
  r.m22 = m22;
  return r;
}

static inline ksl_mat3x3f_t ksl_mat3x3f(const float m00, const float m01,
                                        const float m02, const float m10,
                                        const float m11, const float m12,
                                        const float m20, const float m21,
                                        const float m22) {
  ksl_mat3x3f_t r;
  r.m00 = m00;
  r.m01 = m01;
  r.m02 = m02;
  r.m10 = m10;
  r.m11 = m11;
  r.m12 = m12;
  r.m20 = m20;
  r.m21 = m21;
  r.m22 = m22;
  return r;
}

static inline ksl_mat3x3f_t ksl_mat3x3f_cmo(const float m00, const float m10,
                                            const float m20, const float m01,
                                            const float m11, const float m21,
                                            const float m02, const float m12,
                                            const float m22) {
  ksl_mat3x3f_t r;
  r.m00 = m00;
  r.m10 = m10;
  r.m20 = m20;
  r.m01 = m01;
  r.m11 = m11;
  r.m21 = m21;
  r.m02 = m02;
  r.m12 = m12;
  r.m22 = m22;
  return r;
}

static inline void ksl_mat3x3_setIdentity(ksl_mat3x3_t* KSL_RESTRICT r) {
  memset(r, 0, sizeof(ksl_mat3x3_t));
  for(int i = 0; i < 3; i++) {
    r->at[i][i] = 1.0;
  }
}

static inline void ksl_mat3x3f_setIdentity(ksl_mat3x3f_t* KSL_RESTRICT r) {
  memset(r, 0, sizeof(ksl_mat3x3f_t));
  for(int i = 0; i < 3; i++) {
    r->at[i][i] = 1.0;
  }
}

static inline void ksl_mat3x3_set(ksl_mat3x3_t* KSL_RESTRICT R, const int row,
                                  const int column, const double value) {
  assert(row < 3 && column < 3);
  R->at[column][row] = value;
}

static inline void ksl_mat3x3f_set(ksl_mat3x3f_t* KSL_RESTRICT R, int row,
                                   int column, float value) {
  assert(row < 3 && column < 3);
  R->at[column][row] = value;
}

static inline void ksl_mat3x3_normalize(ksl_mat3x3_t* KSL_RESTRICT R) {
  ksl_linalg_gramSchmidt((double*)&(R->as_array), 3, 3);
}

static inline void ksl_mat3x3_normalized(const ksl_mat3x3_t* KSL_RESTRICT Ri,
                                         ksl_mat3x3_t* KSL_RESTRICT Ro) {
  ksl_mat3x3_copy(Ri, Ro);
  ksl_linalg_gramSchmidt((double*)&(Ro->as_array), 3, 3);
}

static inline void ksl_mat3x3f_normalize(ksl_mat3x3f_t* KSL_RESTRICT R) {
  ksl_linalg_gramSchmidtf((float*)&(R->as_array), 3, 3);
}

static inline void ksl_mat3x3f_normalized(const ksl_mat3x3f_t* KSL_RESTRICT Ri,
                                          ksl_mat3x3f_t* KSL_RESTRICT Ro) {
  ksl_mat3x3f_copy(Ri, Ro);
  ksl_linalg_gramSchmidtf((float*)&(Ro->as_array), 3, 3);
}

static inline void ksl_mat3x3_setFromVectors(ksl_mat3x3_t* KSL_RESTRICT R,
                                             const ksl_vec3_t* x,
                                             const ksl_vec3_t* y,
                                             const ksl_vec3_t* z) {
  memcpy(&R->v0, x, sizeof(ksl_vec3_t));
  memcpy(&R->v1, y, sizeof(ksl_vec3_t));
  memcpy(&R->v2, z, sizeof(ksl_vec3_t));
}

static inline void ksl_mat3x3f_setFromVectors(ksl_mat3x3f_t* KSL_RESTRICT R,
                                              const ksl_vec3f_t* x,
                                              const ksl_vec3f_t* y,
                                              const ksl_vec3f_t* z) {
  memcpy(&R->v0, x, sizeof(ksl_vec3f_t));
  memcpy(&R->v1, y, sizeof(ksl_vec3f_t));
  memcpy(&R->v2, z, sizeof(ksl_vec3f_t));
}

static inline double ksl_mat3x3_get(const ksl_mat3x3_t* KSL_RESTRICT R,
                                    const int row, const int column) {
  assert(row < 3 && column < 3);
  return R->at[column][row];
}

static inline float ksl_mat3x3f_get(const ksl_mat3x3f_t* KSL_RESTRICT R,
                                    const int row, const int column) {
  assert(row < 3 && column < 3);
  return R->at[column][row];
}

static inline void ksl_mat3x3_copy(const ksl_mat3x3_t* KSL_RESTRICT ri,
                                   ksl_mat3x3_t* KSL_RESTRICT ro) {
  memcpy(ro, ri, sizeof(ksl_mat3x3_t));
}

static inline void ksl_mat3x3f_copy(const ksl_mat3x3f_t* KSL_RESTRICT ri,
                                    ksl_mat3x3f_t* KSL_RESTRICT ro) {
  memcpy(ro, ri, sizeof(ksl_mat3x3f_t));
}

static inline void ksl_mat3x3_transpose(ksl_mat3x3_t* KSL_RESTRICT R) {
  ksl_swap(&R->at[0][1], &R->at[1][0]);
  ksl_swap(&R->at[0][2], &R->at[2][0]);
  ksl_swap(&R->at[1][2], &R->at[2][1]);
}

static inline void ksl_mat3x3f_transpose(ksl_mat3x3f_t* KSL_RESTRICT R) {
  ksl_swapf(&R->at[0][1], &R->at[1][0]);
  ksl_swapf(&R->at[0][2], &R->at[2][0]);
  ksl_swapf(&R->at[1][2], &R->at[2][1]);
}

static inline void ksl_mat3x3_transposed(const ksl_mat3x3_t* KSL_RESTRICT ri,
                                         ksl_mat3x3_t* KSL_RESTRICT ro) {
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      ro->at[i][j] = ri->at[j][i];
    }
  }
}

static inline void ksl_mat3x3f_transposed(const ksl_mat3x3f_t* KSL_RESTRICT ri,
                                          ksl_mat3x3f_t* KSL_RESTRICT ro) {
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      ro->at[i][j] = ri->at[j][i];
    }
  }
}

static inline void ksl_mat3x3_setFromEulerAngles(ksl_mat3x3_t* r,
                                                 const ksl_axis_enum_t axisType,
                                                 const ksl_vec3_t* angles) {

  ksl_vec3i_t axes = ksl_axis_getVector(axisType);
  ksl_mat3x3_setIdentity(r);
  ksl_mat3x3_t temp;
  double dc[3][2];
  for(int i = 0; i < 3; i++) {
    ksl_dc(angles->at[i], dc[i]);
  }
  for(int i = 0; i < 3; i++) {
    switch(axes.at[i]) {
      case 0: {
        ksl_product_drdrx(r, dc[i], &temp);
        break;
      }
      case 1: {
        ksl_product_drdry(r, dc[i], &temp);
        break;
      }
      case 2: {
        ksl_product_drdrz(r, dc[i], &temp);
        break;
      }
      default: {
        temp = *r;
        break;
      }
    }
    ksl_mat3x3_copy(&temp, r);
  }
  return;
}

static inline void
ksl_mat3x3f_setFromEulerAngles(ksl_mat3x3f_t* r, const ksl_axis_enum_t axisType,
                               const ksl_vec3f_t* angles) {

  ksl_vec3i_t axes = ksl_axis_getVector(axisType);
  ksl_mat3x3f_setIdentity(r);
  ksl_mat3x3f_t temp;
  float dc[3][2];
  for(int i = 0; i < 3; i++) {
    ksl_dcf(angles->at[i], dc[i]);
  }
  for(int i = 0; i < 3; i++) {
    switch(axes.at[i]) {
      case 0: {
        ksl_product_drdrxf(r, dc[i], &temp);
        break;
      }
      case 1: {
        ksl_product_drdryf(r, dc[i], &temp);
        break;
      }
      case 2: {
        ksl_product_drdrzf(r, dc[i], &temp);
        break;
      }
      default: {
        temp = *r;
        break;
      }
    }
    ksl_mat3x3f_copy(&temp, r);
  }
  return;
}

static inline double
ksl_mat3x3_determinant(const ksl_mat3x3_t* KSL_RESTRICT R) {
  return (R->m00 * (R->m11 * R->m22 - R->m21 * R->m12) -
          R->m10 * (R->m01 * R->m22 - R->m21 * R->m02) +
          R->m20 * (R->m01 * R->m12 - R->m11 * R->m02));
}

static inline float
ksl_mat3x3f_determinant(const ksl_mat3x3f_t* KSL_RESTRICT R) {
  return (R->m00 * (R->m11 * R->m22 - R->m21 * R->m12) -
          R->m10 * (R->m01 * R->m22 - R->m21 * R->m02) +
          R->m20 * (R->m01 * R->m12 - R->m11 * R->m02));
}

static inline void ksl_mat3x3_getAxisAngle(const ksl_mat3x3_t* KSL_RESTRICT r,
                                           ksl_vec3_t* KSL_RESTRICT axis,
                                           double* KSL_RESTRICT angle) {
  /* c = cos(theta), v = sin(theta) * u, from r = c I + (1 - c) u u^T + s u~ */
  double c = 0.5 * (r->m00 + r->m11 + r->m22 - 1.0);
  ksl_vec3_t v = ksl_vec3(0.5 * (r->m21 - r->m12), 0.5 * (r->m02 - r->m20),
                          0.5 * (r->m10 - r->m01));
  double s = ksl_vec3_l2norm(&v);
  *angle = atan2(s, c);

  if(c >= 0.0) {
    if(s < 1e-9) {
      /* identity: the axis is arbitrary, return {0, 0, 1} */
      axis->x = 0.0;
      axis->y = 0.0;
      axis->z = 1.0;
      return;
    }
    /* u_tilde = (1 / 2 sin \theta) * (r - r^T) */
    ksl_product_av(1.0 / s, &v, axis);
    return;
  }

  /* theta > pi / 2: the skew-symmetric part vanishes as theta -> pi, so use
  the symmetric part, (r + r^T) / 2 - c I = (1 - c) u u^T, and take the
  column with the largest diagonal entry. */
  int k = 0;
  for(int i = 1; i < 3; i++) {
    if(r->at[i][i] > r->at[k][k]) {
      k = i;
    }
  }
  double scale = 1.0 / sqrt((r->at[k][k] - c) * (1.0 - c));
  for(int i = 0; i < 3; i++) {
    double sym = 0.5 * (r->at[k][i] + r->at[i][k]) - (i == k ? c : 0.0);
    axis->at[i] = sym * scale;
  }
  /* the symmetric part only determines u up to sign; match sin(theta) * u */
  if(ksl_dot_vv(axis, &v) < 0.0) {
    ksl_vec3_invert(axis);
  }
}

static inline void
ksl_mat3x3_setFromAxisAngle(ksl_mat3x3_t* KSL_RESTRICT r,
                            const ksl_vec3_t* KSL_RESTRICT axis,
                            const double angle) {
  ksl_vec3_t axis_n; /* normalized rotation axis */
  ksl_vec3_normalized(axis, &axis_n);
  double sc[2];
  ksl_dc(angle, sc);
  double t = 1.0 - sc[1];

  r->m00 = sc[1] + axis_n.x * axis_n.x * t;
  r->m11 = sc[1] + axis_n.y * axis_n.y * t;
  r->m22 = sc[1] + axis_n.z * axis_n.z * t;

  double tmp1 = axis_n.x * axis_n.y * t;
  double tmp2 = axis_n.z * sc[0];
  r->m10 = tmp1 + tmp2;
  r->m01 = tmp1 - tmp2;
  tmp1 = axis_n.x * axis_n.z * t;
  tmp2 = axis_n.y * sc[0];
  r->m20 = tmp1 - tmp2;
  r->m02 = tmp1 + tmp2;
  tmp1 = axis_n.y * axis_n.z * t;
  tmp2 = axis_n.x * sc[0];
  r->m21 = tmp1 + tmp2;
  r->m12 = tmp1 - tmp2;
}

static inline void ksl_mat3x3_setFromAxisDC(ksl_mat3x3_t* KSL_RESTRICT r,
                                            const ksl_vec3_t* KSL_RESTRICT axis,
                                            const double* dc) {
  double t = 1.0 - dc[1];

  r->m00 = dc[1] + axis->x * axis->x * t;
  r->m11 = dc[1] + axis->y * axis->y * t;
  r->m22 = dc[1] + axis->z * axis->z * t;

  double tmp1 = axis->x * axis->y * t;
  double tmp2 = axis->z * dc[0];
  r->m10 = tmp1 + tmp2;
  r->m01 = tmp1 - tmp2;
  tmp1 = axis->x * axis->z * t;
  tmp2 = axis->y * dc[0];
  r->m20 = tmp1 - tmp2;
  r->m02 = tmp1 + tmp2;
  tmp1 = axis->y * axis->z * t;
  tmp2 = axis->x * dc[0];
  r->m21 = tmp1 + tmp2;
  r->m12 = tmp1 - tmp2;
}

static inline void ksl_mat3x3f_getAxisAngle(const ksl_mat3x3f_t* KSL_RESTRICT r,
                                            ksl_vec3f_t* KSL_RESTRICT axis,
                                            float* KSL_RESTRICT angle) {
  /* c = cos(theta), v = sin(theta) * u, from r = c I + (1 - c) u u^T + s u~ */
  float c = 0.5f * (r->m00 + r->m11 + r->m22 - 1.0f);
  ksl_vec3f_t v = ksl_vec3f(0.5f * (r->m21 - r->m12), 0.5f * (r->m02 - r->m20),
                            0.5f * (r->m10 - r->m01));
  float s = ksl_vec3f_l2norm(&v);
  *angle = atan2f(s, c);

  if(c >= 0.0f) {
    if(s < 1e-6f) {
      /* identity: the axis is arbitrary, return {0, 0, 1} */
      axis->x = 0.0f;
      axis->y = 0.0f;
      axis->z = 1.0f;
      return;
    }
    /* u_tilde = (1 / 2 sin \theta) * (r - r^T) */
    ksl_product_avf(1.0f / s, &v, axis);
    return;
  }

  /* theta > pi / 2: the skew-symmetric part vanishes as theta -> pi, so use
  the symmetric part, (r + r^T) / 2 - c I = (1 - c) u u^T, and take the
  column with the largest diagonal entry. */
  int k = 0;
  for(int i = 1; i < 3; i++) {
    if(r->at[i][i] > r->at[k][k]) {
      k = i;
    }
  }
  float scale = 1.0f / sqrtf((r->at[k][k] - c) * (1.0f - c));
  for(int i = 0; i < 3; i++) {
    float sym = 0.5f * (r->at[k][i] + r->at[i][k]) - (i == k ? c : 0.0f);
    axis->at[i] = sym * scale;
  }
  /* the symmetric part only determines u up to sign; match sin(theta) * u */
  if(ksl_dot_vvf(axis, &v) < 0.0f) {
    ksl_vec3f_invert(axis);
  }
}

static inline void
ksl_mat3x3f_setFromAxisAngle(ksl_mat3x3f_t* KSL_RESTRICT r,
                             const ksl_vec3f_t* KSL_RESTRICT axis,
                             const float angle) {
  ksl_vec3f_t axis_n; /* normalized rotation axis */
  ksl_vec3f_normalized(axis, &axis_n);
  double sc[2];
  ksl_dc(angle, sc);
  double t = 1.0 - sc[1];

  r->m00 = sc[1] + axis_n.x * axis_n.x * t;
  r->m11 = sc[1] + axis_n.y * axis_n.y * t;
  r->m22 = sc[1] + axis_n.z * axis_n.z * t;

  double tmp1 = axis_n.x * axis_n.y * t;
  double tmp2 = axis_n.z * sc[0];
  r->m10 = tmp1 + tmp2;
  r->m01 = tmp1 - tmp2;
  tmp1 = axis_n.x * axis_n.z * t;
  tmp2 = axis_n.y * sc[0];
  r->m20 = tmp1 - tmp2;
  r->m02 = tmp1 + tmp2;
  tmp1 = axis_n.y * axis_n.z * t;
  tmp2 = axis_n.x * sc[0];
  r->m21 = tmp1 + tmp2;
  r->m12 = tmp1 - tmp2;
}

#ifdef __cplusplus
}
#endif

#endif
