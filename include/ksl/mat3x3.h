/**
@file
@author Kristopher Wehage, Roger Wehage
@brief Utilities to initialize and operate on mat3x3 and ma4x4 matrices
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

#ifndef _KSL_MAT3X3_H_
#define _KSL_MAT3X3_H_

#include <stdarg.h>

#include "axis.h"
#include "pub_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! @brief A general 3x3 double precision matrix

This union allows accessing double precision mat3x3 quantities by field name, as
a singly dimensioned array, as a doubly dimensioned array, or by accessing a
specific column.  If using the `at` or `as_array` operators, quantities are
accessed in column major order.

The following examples illustrate how to access row 2, column 1 (using 0 based
indexing) of matrix `R`. The following access methods are equivalent.

\verbatim embed:rst
.. code-block:: c

  R.as_array[2 + 1 * 3];
  R.at[1][2];
  R.m21;
  R.v1.z;
  R.v1.at[2];
  R.v[1].z;
  R.v[1].at[2];

\endverbatim

See also the `ksl_mat3x3_get` and `ksl_mat3x3_set` functions. */
typedef union ksl_mat3x3_t {
  struct {
    double as_array[9];
  }; /*!< anonymous union allows accessing quantities at specified index in
          linear array, where entities are specified in column
          major order */
  struct {
    double at[3][3];
  }; /*!< anonymous union allows accessing quantities at specified index
        in a doubly dimensioned array, where entities are specified in column
        major order */
  struct {
    double m00, m10, m20;
    double m01, m11, m21;
    double m02, m12, m22;
  }; /*!< anonymous union allows accessing rotation matrix quantities by field
        name */
  struct {
    ksl_vec3_t v0, v1, v2;
  }; /*!< anonymous union allows accessing columns of rotation matrix quantities
        by field name */
  struct {
    ksl_vec3_t v[3];
  }; /*!< anonymous union allows accessing columns of rotation
          matrix quantities at specified index */
} ksl_mat3x3_t;

/*!
@brief A general 3x3 single precision matrix.

This union allows accessing single precision mat3x3 quantities by field name, as
a singly dimensioned array, as a doubly dimensioned array, or by accessing a
specific column.  If using the `at` or `as_array` operators, quantities are
accessed in column major order.

The following examples illustrate how to access row 2, column 1 (using 0 based
indexing) of matrix `R`. The following access methods are equivalent.

\verbatim embed:rst
.. code-block:: c

  R.as_array[2 + 1 * 3];
  R.at[1][2];
  R.m21;
  R.v1.z;
  R.v1.at[2];
  R.v[1].z;
  R.v[1].at[2];

\endverbatim

See also the `ksl_mat3x3f_get` and `ksl_mat3x3f_set` functions.
*/
typedef union ksl_mat3x3f_t {
  struct {
    float as_array[9];
  }; /*!< anonymous union allows accessing quantities at specified index in
                           linear array, where entities are specified in column
                           major order */
  struct {
    float at[3][3];
  }; /*!< anonymous union allows accessing mat3x3 quantities at specified index
       in a doubly dimensioned array, where entities are specified in column
       major order */
  struct {
    float m00, m10, m20;
    float m01, m11, m21;
    float m02, m12, m22;
  }; /*!< anonymous union allows accessing rotation matrix quantities by field
        name */
  struct {
    ksl_vec3f_t v0, v1, v2;
  }; /*!< anonymous union allows accessing columns of rotation matrix quantities
        by field name */
  struct {
    ksl_vec3f_t v[3];
  }; /*!< anonymous union allows accessing columns of rotation by index
          matrix quantities at specified index */
} ksl_mat3x3f_t;

/*!
@brief ksl_mat3x3_t constructor.

Note that in the constructor, fields are specified in row major order.
Internally, ksl_mat3x3_t datastructures are stored in column major order.
*/
ksl_mat3x3_t ksl_mat3x3(const double m00, const double m01, const double m02,
                        const double m10, const double m11, const double m12,
                        const double m20, const double m21, const double m22);

/*!
@brief alternative ksl_mat3x3_t constructor.

In this alternate constructor, fields are specified in column major order to
match the internal layout of ksl_mat3x3_t datastructures.
*/
ksl_mat3x3_t ksl_mat3x3_cmo(const double m00, const double m10,
                            const double m20, const double m01,
                            const double m11, const double m21,
                            const double m02, const double m12,
                            const double m22);

/*!
@brief ksl_mat3x3f_t constructor.

Note that in the constructor, fields are specified in row major order.
Internally, ksl_mat3x3f_t datastructures are stored in column major order.
*/
ksl_mat3x3f_t ksl_mat3x3f(const float m00, const float m01, const float m02,
                          const float m10, const float m11, const float m12,
                          const float m20, const float m21, const float m22);

/*!
@brief alternative ksl_mat3x3f_t constructor.

In this alternate constructor, fields are specified in column major order to
match the internal layout of ksl_mat3x3f_t datastructures.
*/
ksl_mat3x3f_t ksl_mat3x3f_cmo(const float m00, const float m10, const float m20,
                              const float m01, const float m11, const float m21,
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
void ksl_mat3x3_setIdentity(ksl_mat3x3_t* r);

/*!
@brief Set a single precision 3x3 matrix to identity.

\f$ I \rightarrow R \f$

@param r [in/out] input 3x3 matrix
*/
void ksl_mat3x3f_setIdentity(ksl_mat3x3f_t* r);

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
void ksl_mat3x3_set(ksl_mat3x3_t* R, const int row, const int column,
                    const double value);

/*!
@brief Set a double precision 3x3 matrix from 3 column vectors

\f$ \begin{bmatrix} \underline{v}_x & \underline{v}_y & \underline{v}_z
\end{bmatrix} \rightarrow R \f$

@param R [in/out] 3x3 rotation matrix
@param x [in] first column to set
@param y [in] second column to set
@param z [in] third column to set
*/
void ksl_mat3x3_setFromVectors(ksl_mat3x3_t* R, const ksl_vec3_t* x,
                               const ksl_vec3_t* y, const ksl_vec3_t* z);

/*!
@brief Set a single precision 3x3 matrix from 3 column vectors

\f$ \begin{bmatrix} \underline{v}_x & \underline{v}_y & \underline{v}_z
\end{bmatrix} \rightarrow R \f$

@param R [in/out] 3x3 rotation matrix
@param x [in] first column to set
@param y [in] second column to set
@param z [in] third column to set
*/
void ksl_mat3x3f_setFromVectors(ksl_mat3x3f_t* R, const ksl_vec3f_t* x,
                                const ksl_vec3f_t* y, const ksl_vec3f_t* z);

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
void ksl_mat3x3f_set(ksl_mat3x3f_t* R, int row, int column, float value);

void ksl_mat3x3_normalize(ksl_mat3x3_t* R);

void ksl_mat3x3_normalized(const ksl_mat3x3_t* Ri, ksl_mat3x3_t* Ro);

void ksl_mat3x3f_normalize(ksl_mat3x3f_t* R);

void ksl_mat3x3f_normalized(const ksl_mat3x3f_t* Ri, ksl_mat3x3f_t* Ro);

/*!
@brief TODO document this function
*/
double ksl_mat3x3_get(const ksl_mat3x3_t* R, const int row, const int column);

/*!
@brief TODO document this function
*/
float ksl_mat3x3f_get(const ksl_mat3x3f_t* R, const int row, const int column);

/*!
@brief TODO document this function
*/
void ksl_mat3x3_copy(const ksl_mat3x3_t* ri, ksl_mat3x3_t* ro);

/*!
@brief TODO document this function
*/
void ksl_mat3x3f_copy(const ksl_mat3x3f_t* ri, ksl_mat3x3f_t* ro);

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
void ksl_mat3x3_transpose(ksl_mat3x3_t* R);

/*!
@brief TODO document this function
*/
void ksl_mat3x3f_transpose(ksl_mat3x3f_t* R);

/*!
@brief TODO document this function
*/
void ksl_mat3x3_transposed(const ksl_mat3x3_t* ri, ksl_mat3x3_t* ro);

/*!
@brief TODO document this function
*/
void ksl_mat3x3f_transposed(const ksl_mat3x3f_t* ri, ksl_mat3x3f_t* ro);

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
void ksl_mat3x3_setFromEulerAngles(ksl_mat3x3_t*,
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
void ksl_mat3x3f_setFromEulerAngles(ksl_mat3x3f_t*,
                                    const ksl_axis_enum_t axisType,
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
void ksl_mat3x3_getAxisAngle(const ksl_mat3x3_t* r, ksl_vec3_t* axis,
                             double* angle);

/*!
@brief Set double precision rotation matrix from axis and angle representation.

@param r [out] rotation matrix will be set here
@param axis [in] axis of rotation
@param angle [in] angle of rotation in radians
*/
void ksl_mat3x3_setFromAxisAngle(ksl_mat3x3_t*, const ksl_vec3_t*,
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
void ksl_mat3x3f_getAxisAngle(const ksl_mat3x3f_t* r, ksl_vec3f_t* axis,
                              float* angle);

/*!
@brief Set a single precision rotation matrix from axis and angle
representation.

@param r [out] rotation matrix to set
@param axis [in] axis of rotation
@param angle [in] angle of rotation in radians
*/
void ksl_mat3x3f_setFromAxisAngle(ksl_mat3x3f_t* r, const ksl_vec3f_t* axis,
                                  const float angle);

/*!
@brief Compute the determinant of a 3x3 double precision matrix
@param ri [in] input 3x3 matrix
@param determinant
*/
double ksl_mat3x3_determinant(const ksl_mat3x3_t* r_i);

/*!
@brief Compute the determinant of a 3x3 single precision matrix
@param ri [in] input 3x3 matrix
@param determinant
*/
float ksl_mat3x3f_determinant(const ksl_mat3x3f_t*);

void ksl_mat3x3_pca(ksl_mat3x3_t* A, ksl_mat3x3_t* v);

#ifdef __cplusplus
}
#endif

#endif
