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

#ifndef _KSL_MATRIX_H_
#define _KSL_MATRIX_H_

#include <stdarg.h>

#include "axis.h"

typedef union ksl_screw_t ksl_screw_t;
typedef union ksl_screwf_t ksl_screwf_t;

typedef enum ksl_matrix_enum_t {
  KSL_ROW_MAJOR,
  KSL_COLUMN_MAJOR
} ksl_matrix_enum_t;

/*!
@brief general 3x3 double precision matrix

allow accessing mat3x3 quantities by field name or by
using at / as_array operators.  if using the at or as_array operators,
quantities are accessed in column major order
*/
typedef union ksl_mat3x3_t {
  double as_array[9]; /*!< allows accessing quantities at specified index in
                         linear array, where entities are specified in column
                         major order */
  double at[3][3]; /*!< allows accessing mat3x3 quantities at specified index in
                      a doubly dimensioned array, where entities are specified
                      in column major order */
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
  ksl_vec3_t v[3]; /*!< anonymous union allows accessing columns of rotation
        matrix quantities at specified index */
} ksl_mat3x3_t;

/*!
@brief general 3x3 double precision matrix

allow accessing mat3x3 quantities by field name or by
using at / as_array operators.  if using the at or as_array operators,
quantities are accessed in column major order
*/
typedef union ksl_mat3x3f_t {
  float as_array[9]; /*!< allows accessing quantities at specified index in
                         linear array, where entities are specified in column
                         major order */
  float at[3][3]; /*!< allows accessing mat3x3 quantities at specified index in
                      a doubly dimensioned array, where entities are specified
                      in column major order */
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
  ksl_vec3f_t v[3]; /*!< anonymous union allows accessing columns of rotation
        matrix quantities at specified index */
} ksl_mat3x3f_t;

/*!
@brief general 4x4 double precision matrix

allow accessing mat4x4 quantities by field name or
using at / as_array operators.  if using the at / as_array operators,
quantities are accessed in column major order
*/
typedef union ksl_mat4x4_t {
  double as_array[16]; /*!< allows accessing quantities at specified index in
                         linear array, where entities are specified in column
                         major order */
  double at[4][4]; /*!< allows accessing mat3x3 quantities at specified index in
                      a doubly dimensioned array, where entities are specified
                      in column major order */
  struct {
    double m00, m10, m20, m30;
    double m01, m11, m21, m31;
    double m02, m12, m22, m32;
    double m03, m13, m23, m33;
  }; /*!< anonymous union allows accessing rotation matrix quantities by field
        name */
  struct {
    ksl_vec4_t v0, v1, v2, v3;
  }; /*!< anonymous union allows accessing columns of rotation matrix quantities
        by field name */
  ksl_vec4_t v[4]; /*!< anonymous union allows accessing columns of rotation
        matrix quantities at specified index */
} ksl_mat4x4_t;

/*!
@brief general 4x4 double precision matrix

allow accessing mat4x4 quantities by field name or
using at / as_array operators.  if using the at / as_array operators,
quantities are accessed in column major order
*/
typedef union ksl_mat4x4f_t {
  float as_array[16]; /*!< allows accessing quantities at specified index in
                         linear array, where entities are specified in column
                         major order */
  float at[4][4]; /*!< allows accessing mat3x3 quantities at specified index in
                      a doubly dimensioned array, where entities are specified
                      in column major order */
  struct {
    float m00, m10, m20, m30;
    float m01, m11, m21, m31;
    float m02, m12, m22, m32;
    float m03, m13, m23, m33;
  }; /*!< anonymous union allows accessing rotation matrix quantities by field
        name */
  struct {
    ksl_vec4f_t v0, v1, v2, v3;
  }; /*!< anonymous union allows accessing columns of rotation matrix quantities
        by field name */
  ksl_vec4f_t v[4]; /*!< anonymous union allows accessing columns of rotation
        matrix quantities at specified index */
} ksl_mat4x4f_t;

/*!
@brief SE3 (3 Dimensional Special Euclidian group) consists of a
SO3 (othonormalized 3x3 rotation matrix) and translation vector pair

if using the at/as_array operators,
quantities are accessed in column major order with Rotation matrix
quantities coming first, followed by translation vector
*/
typedef union ksl_SE3_t {
  double as_array[12]; /*!< allows accessing quantities at specified index in
                        linear array, where entities are specified in column
                        major order */
  double at[4][3]; /*!< allows accessing SE3 quantities at specified index in
                      a doubly dimensioned array, where entities are specified
                      in column major order */
  struct {
    ksl_mat3x3_t R; /*!< rotation component of SE3 transformation */
    ksl_vec3_t t;   /*!< translation component of SE3 transformation */
  }; /*!< anonymous union allows accessing rotation matrix and translation
       vector quantities by field name */
  struct {
    double m00, m10, m20;
    double m01, m11, m21;
    double m02, m12, m22;
    double m03, m13, m23;
  }; /*!< anonymous union allows accessing rotation matrix quantities by field
       name */
  struct {
    ksl_vec3_t v0, v1, v2, v3;
  }; /*!< anonymous union allows accessing columns of rotation matrix quantities
        by field name */
  ksl_vec3_t v[4]; /*!< anonymous union allows accessing columns of rotation
        matrix quantities at specified index */
} ksl_SE3_t;

/*!
@brief Single precision member of 3 Dimensional Special Euclidian group (SE3)
consisting of a single precision SO3 (othonormalized 3x3 rotation matrix) and
single precision translation vector pair

if using the at/as_array operators,
quantities are accessed in column major order with Rotation matrix
quantities coming first, followed by translation vector
*/
typedef union ksl_SE3f_t {
  float as_array[12]; /*!< allows accessing quantities at specified index in
                        linear array, with entities specified in column
                        major order */
  float at[4][3];     /*!< allows accessing SE3 quantities at specified index in
                          a doubly dimensioned array, with entities specified
                          in column major order */
  struct {
    ksl_mat3x3f_t R; /*!< rotation component of SE3 transformation */
    ksl_vec3f_t t;   /*!< translation component of SE3 transformation */
  }; /*!< anonymous union allows accessing rotation matrix and translation
       vector quantities by field name */
  struct {
    float m00, m10, m20;
    float m01, m11, m21;
    float m02, m12, m22;
    float m03, m13, m23;
  }; /*!< anonymous union allows accessing rotation matrix quantities by field
       name */
  struct {
    ksl_vec3f_t v0, v1, v2, v3;
  }; /*!< anonymous union allows accessing columns of rotation matrix quantities
        by field name */
  ksl_vec3f_t v[4]; /*!< anonymous union allows accessing columns of rotation
        matrix quantities at specified index */
} ksl_SE3f_t;

/*!
@brief ksl_SE3_t constructor.

Note that in the constructor, fields are specified in row major order.
Internally, ksl_SE3_t datastructures are stored in column major order.
*/
ksl_SE3_t ksl_SE3(const double m00, const double m01, const double m02,
                  const double m03, const double m10, const double m11,
                  const double m12, const double m13, const double m20,
                  const double m21, const double m22, const double m23);

/*!
@brief alternative ksl_SE3_t constructor.

In this alternate constructor, fields are specified in column major order to
match the internal layout of ksl_SE3_t datastructures.
*/
ksl_SE3_t ksl_SE3_cmo(const double m00, const double m10, const double m20,
                      const double m01, const double m11, const double m21,
                      const double m02, const double m12, const double m22,
                      const double m03, const double m13, const double m23);

/*!
@brief alternative ksl_SE3_t constructor that allows creating a ksl_SE3_t
datastructure from a rotation matrix and translation vector.
*/
ksl_SE3_t ksl_SE3_fromRt(const ksl_mat3x3_t R, const ksl_vec3_t t);

/*!
@brief ksl_SE3f_t constructor.

Note that in the constructor, fields are specified in row major order.
Internally, ksl_SE3f_t datastructures are stored in column major order.
*/
ksl_SE3f_t ksl_SE3f(const float m00, const float m01, const float m02,
                    const float m03, const float m10, const float m11,
                    const float m12, const float m13, const float m20,
                    const float m21, const float m22, const float m23);

/*!
@brief alternative ksl_SE3f_t constructor.

In this alternate constructor, fields are specified in column major order to
match the internal layout of ksl_SE3f_t datastructures.
*/
ksl_SE3f_t ksl_SE3f_cmo(const float m00, const float m10, const float m20,
                        const float m01, const float m11, const float m21,
                        const float m02, const float m12, const float m22,
                        const float m03, const float m13, const float m23);

/*!
@brief alternative ksl_SE3f_t constructor that allows creating a ksl_SE3_t
datastructure from a rotation matrix and translation vector.
*/
ksl_SE3f_t ksl_SE3f_fromRt(const ksl_mat3x3f_t R, const ksl_vec3f_t t);

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
@brief ksl_mat4x4_t constructor.

Note that in the constructor, fields are specified in row major order.
Internally, ksl_mat4x4_t datastructures are stored in column major order.
*/
ksl_mat4x4_t ksl_mat4x4(const double m00, const double m01, const double m02,
                        const double m03, const double m10, const double m11,
                        const double m12, const double m13, const double m20,
                        const double m21, const double m22, const double m23,
                        const double m30, const double m31, const double m32,
                        const double m33);

/*!
@brief alternative ksl_mat4x4_t constructor.

In this alternate constructor, fields are specified in column major order to
match the internal layout of ksl_mat4x4_t datastructures.
*/
ksl_mat4x4_t ksl_mat4x4_cmo(
  const double m00, const double m10, const double m20, const double m30,
  const double m01, const double m11, const double m21, const double m31,
  const double m02, const double m12, const double m22, const double m32,
  const double m03, const double m13, const double m23, const double m33);

/*!
@brief alternative ksl_mat4x4_t constructor that allows creating a ksl_mat4x4_t
datastructure from a ksl_SE3_t datastructure.
*/
ksl_mat4x4_t ksl_mat4x4_fromSE3(const ksl_SE3_t D);

/*!
@brief alternative ksl_mat4x4_t constructor that allows creating a ksl_mat4x4_t
datastructure from ksl_mat3x3_t and ksl_vec3_t datastructures.
*/
ksl_mat4x4_t ksl_mat4x4_fromRt(const ksl_mat3x3_t R, const ksl_vec3_t t);

/*!
@brief ksl_mat4x4f_t constructor.

Note that in the constructor, fields are specified in row major order.
Internally, ksl_mat4x4f_t datastructures are stored in column major order.
*/
ksl_mat4x4f_t ksl_mat4x4f(const float m00, const float m01, const float m02,
                          const float m03, const float m10, const float m11,
                          const float m12, const float m13, const float m20,
                          const float m21, const float m22, const float m23,
                          const float m30, const float m31, const float m32,
                          const float m33);

/*!
@brief alternative ksl_mat4x4f_t constructor.

In this alternate constructor, fields are specified in column major order to
match the internal layout of ksl_mat4x4f_t datastructures.
*/
ksl_mat4x4f_t ksl_mat4x4f_cmo(const float m00, const float m10, const float m20,
                              const float m30, const float m01, const float m11,
                              const float m21, const float m31, const float m02,
                              const float m12, const float m22, const float m32,
                              const float m03, const float m13, const float m23,
                              const float m33);

/*!
@brief alternative ksl_mat4x4f_t constructor that allows creating a
ksl_mat4x4f_t datastructure from a ksl_SE3f_t datastructure.
*/
ksl_mat4x4f_t ksl_mat4x4f_fromSE3f(const ksl_SE3f_t D);

/*!
@brief alternative ksl_mat4x4f_t constructor that allows creating a
ksl_mat4x4f_t datastructure from ksl_mat3x3f_t and ksl_vec3f_t datastructures.
*/
ksl_mat4x4f_t ksl_mat4x4f_fromRt(const ksl_mat3x3f_t R, const ksl_vec3f_t t);

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
@brief allocates n ksl_mat3x3_t datastructures on the heap. Must be freed by the
user.
*/
ksl_mat3x3_t* ksl_mat3x3_alloc(int n);

/*!
@brief allocates n ksl_mat3x3f_t datastructures on the heap. Must be freed by
the user.
*/
ksl_mat3x3f_t* ksl_mat3x3f_alloc(int n);

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
@brief convert a `ksl_SE3_t` datastructure to a `ksl_mat4x4_t` datastructure

@param d [in] input SE3 datastructure
@param m [out] output mat4x4 matrix
*/
void ksl_SE3_toMat4x4(const ksl_SE3_t* d, ksl_mat4x4_t* m);

/*!
@brief convert a `ksl_SE3f_t` datastructure to a `ksl_mat4x4f_t` datastructure

@param d [in] input SE3f datastructure
@param m [out] output mat4x4f matrix
*/
void ksl_SE3f_toMat4x4f(const ksl_SE3f_t* d, ksl_mat4x4f_t* m);

/*!
@brief convert a `ksl_SE3_t` datastructure to a `ksl_mat4x4f_t` datastructure

@param d [in] input SE3 datastructure
@param m [out] output mat4x4f matrix
*/
void ksl_SE3_toMat4x4f(const ksl_SE3_t* d, ksl_mat4x4f_t* m);

/*!
@brief compute double precision direction cosines from an angle specified in
radians

@param thetai [in] input angle
@param dc [out] direction cosines, with sine stored in dc[0] and cosine is
stored in dc[1]
*/
void ksl_dc(const double thetai, double dc[2]);

/*!
@brief compute single precision direction cosines from an angle specified in
radians

@param thetai [in] input angle
@param dc [out] direction cosines, with sine stored in dc[0] and cosine is
stored in dc[1]
*/
void ksl_dcf(const float thetai, float dc[2]);

/*!
@brief Set a double precision SE3 matrix to identity.

\f$\begin{bmatrix}I & 0\\0 & 1\end{bmatrix} \rightarrow \Phi \f$

@param d [in/out] input SE3 matrix
*/
void ksl_SE3_setIdentity(ksl_SE3_t* d);

/*!
@brief Set a single precision SE3 matrix to identity.

\f$\begin{bmatrix}I & 0\\0 & 1\end{bmatrix} \rightarrow \Phi \f$

@param d [in/out] input SE3 matrix
*/
void ksl_SE3f_setIdentity(ksl_SE3f_t* d);

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
@brief Set a value in a double precision 4x4 matrix at specified row and
column index.

Bounds checking are performed in debug mode. Bounds checking can be disabled by
compiling in release mode using the compiler flag -DNDEBUG.

@param M [in/out]
@param row [in] row index, \f$0 \le row \lt 4\f$
@param column [in] column index, \f$0 \le column \lt 4\f$
@param value [in] value to set
*/
void ksl_mat4x4_set(ksl_mat4x4_t* M, const int row, const int column,
                    const double value);

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
void ksl_SE3_set(ksl_SE3_t* D, const int row, const int column,
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
void ksl_SE3f_set(ksl_SE3f_t* D, const int row, const int column,
                  const float value);

/*!
@brief Set a double precision 3x3 matrix from a 3 column vectors

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
@brief Set a single precision 3x3 matrix from a 3 column vectors

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

/*!
@brief Set a value in a single precision 4x4 matrix at specified row and
column index.

Bounds checking are performed in debug mode. Bounds checking can be disabled by
compiling in release mode using the compiler flag -DNDEBUG.

@param M [in/out]
@param row [in] row index, \f$0 \le row \lt 4\f$
@param column [in] column index, \f$0 \le column \lt 4\f$
@param value [in] value to set
*/
void ksl_mat4x4f_set(ksl_mat4x4f_t* D, int row, int column, float value);

/*!
@brief Set a double precision 4x4 matrix to identity.

\f$ I \rightarrow M \f$

@param M [in/out] input 4x4 matrix
*/
void ksl_mat4x4_setIdentity(ksl_mat4x4_t* M);

/*!
@brief Set a single precision 4x4 matrix to identity.

\f$ I \rightarrow M \f$

@param M [in/out] input 4x4 matrix
*/
void ksl_mat4x4f_setIdentity(ksl_mat4x4f_t* M);

/*!
@brief TODO document this function
*/
double ksl_SE3_get(const ksl_SE3_t* D, const int row, const int column);

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
float ksl_SE3f_get(const ksl_SE3f_t* D, const int row, const int column);

/*!
@brief TODO document this function
*/
void ksl_SE3_getTranslation(const ksl_SE3_t* D, ksl_vec3_t* t);

/*!
@brief TODO document this function
*/
void ksl_SE3f_getTranslation(const ksl_SE3f_t* D, ksl_vec3f_t* t);

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
@brief TODO document this function
*/
void ksl_SE3_invert(ksl_SE3_t* D);

/*!
@brief TODO document this function
*/
void ksl_SE3f_invert(ksl_SE3f_t* D);

/*!
@brief TODO document this function
*/
void ksl_SE3_inverted(const ksl_SE3_t* Di, ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_SE3f_inverted(const ksl_SE3f_t* Di, ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
void ksl_SE3_copy(const ksl_SE3_t* Di, ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_SE3f_copy(const ksl_SE3f_t* Di, ksl_SE3f_t* Do);

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
@brief Obtain the 3D translation component of a double precision 4x4 matrix
@param Mi [in] input 4x4 matrix
@param to [out] translation vector returned in to
*/
void ksl_mat4x4_getTranslation(const ksl_mat4x4_t* Mi, ksl_vec3_t* to);

/*!
@brief Obtain the 3D translation component of a single precision 4x4 matrix
@param Mi [in] input 4x4 matrix
@param to [out] translation vector returned in to
*/
void ksl_mat4x4f_getTranslation(const ksl_mat4x4f_t* Mi, ksl_vec3f_t* to);

/*!
@brief Basic get function for a double precision 4x4 matrix

Bounds checking are performed in debug mode. Bounds checking can be disabled by
compiling in release mode using the compiler flag -DNDEBUG.

@param Mi [in] input 4x4 matrix
@param row [in] row index
@param column [in] column index
@return value at specified row and column index
*/
double ksl_mat4x4_get(const ksl_mat4x4_t* Mi, const int row, const int column);

/*!
@brief Basic get function for a single precision 4x4 matrix

Bounds checking are performed in debug mode. Bounds checking can be disabled by
compiling in release mode using the compiler flag -DNDEBUG.

@param Mi [in] input 4x4 matrix
@param row [in] row index
@param column [in] column index
@return value at specified row and column index
*/
float ksl_mat4x4f_get(const ksl_mat4x4f_t* Mi, const int row, const int column);

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

/* matrix vector operations */

/*!
@brief Compute the double precision matrix product of a 3x3 matrix \f$R^{oi}\f$
and a 3x1 vector \f$\underline{v}^i_{oi}\f$.

\f$R^{oi} \underline{v}^i_{oi} \rightarrow \underline{v}^o_{oi} \f$

@param r_oi [in] input 3x3 matrix
@param v_i [in] input vector
@param v_o [out] result returned in v_o
*/
void ksl_product_drv(const ksl_mat3x3_t* r_oi, const ksl_vec3_t* v_i,
                     ksl_vec3_t* v_o);

/*!
@brief Compute the single precision matrix product of a 3x3 matrix \f$R^{oi}\f$
and a 3x1 vector \f$\underline{v}^i_{oi}\f$.

\f$R^{oi} \underline{v}^i_{oi} \rightarrow \underline{v}^o_{oi} \f$

@param r_oi [in] input 3x3 matrix
@param v_i [in] input vector
@param v_o [out] result returned in v_o
*/
void ksl_product_drvf(const ksl_mat3x3f_t* r_oi, const ksl_vec3f_t* v_i,
                      ksl_vec3f_t* v_o);

/*!
@brief Compute the double precision matrix product of a 3x3 matrix \f$R^{oi}\f$
and the inverse of a 3x1 input vector \f$\underline{v}^i_{oi}\f$.

\f$R^{oi} (-\underline{v}^i_{oi}) \rightarrow \underline{v}^o_{io} \f$

\f$-R^{oi} \underline{v}^i_{oi} \rightarrow \underline{v}^o_{io} \f$

\f$R^{oi} \underline{v}^i_{io} \rightarrow \underline{v}^o_{io} \f$

@param r_oi [in] input 3x3 matrix
@param v_i [in] input vector
@param v_o [out] result returned in v_o
*/
void ksl_product_drvinv(const ksl_mat3x3_t* ri, const ksl_vec3_t* vi,
                        ksl_vec3_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_drvinvf(const ksl_mat3x3f_t* ri, const ksl_vec3f_t* vi,
                         ksl_vec3f_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_drinvv(const ksl_mat3x3_t* ri, const ksl_vec3_t* vi,
                        ksl_vec3_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_drinvvf(const ksl_mat3x3f_t* ri, const ksl_vec3f_t* vi,
                         ksl_vec3f_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_drinvvinv(const ksl_mat3x3_t* ri, const ksl_vec3_t* vi,
                           ksl_vec3_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_drinvvinvf(const ksl_mat3x3f_t* ri, const ksl_vec3f_t* vi,
                            ksl_vec3f_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_drvtx(const ksl_mat3x3_t* ri, const double ti, ksl_vec3_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_drvtxf(const ksl_mat3x3f_t* ri, const float ti,
                        ksl_vec3f_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_drvtxinv(const ksl_mat3x3_t* ri, const double ti,
                          ksl_vec3_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_drvtxinvf(const ksl_mat3x3f_t* ri, const float ti,
                           ksl_vec3f_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_drvty(const ksl_mat3x3_t* ri, const double ti, ksl_vec3_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_drvtyf(const ksl_mat3x3f_t* ri, const float ti,
                        ksl_vec3f_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_drvtyinv(const ksl_mat3x3_t* ri, const double ti,
                          ksl_vec3_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_drvtyinvf(const ksl_mat3x3f_t* ri, const float ti,
                           ksl_vec3f_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_drvtz(const ksl_mat3x3_t* ri, const double ti, ksl_vec3_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_drvtzf(const ksl_mat3x3f_t* ri, const float ti,
                        ksl_vec3f_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_drvtzinv(const ksl_mat3x3_t* ri, const double ti,
                          ksl_vec3_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_drvtzinvf(const ksl_mat3x3f_t* ri, const float ti,
                           ksl_vec3f_t* vo);

/* matrix-matrix operations */

/*!
@brief TODO document this function
*/
void ksl_product_drdrx(const ksl_mat3x3_t* ri, const double dc[2],
                       ksl_mat3x3_t* ro);

/*!
@brief TODO document this function
*/
void ksl_product_drdrxf(const ksl_mat3x3f_t* ri, const float dc[2],
                        ksl_mat3x3f_t* ro);

/*!
@brief TODO document this function
*/
void ksl_product_drdrxinv(const ksl_mat3x3_t* ri, const double dc[2],
                          ksl_mat3x3_t* ro);

/*!
@brief TODO document this function
*/
void ksl_product_drdrxinvf(const ksl_mat3x3f_t* ri, const float dc[2],
                           ksl_mat3x3f_t* ro);

/*!
@brief TODO document this function
*/
void ksl_product_drdry(const ksl_mat3x3_t* ri, const double dc[2],
                       ksl_mat3x3_t* ro);

/*!
@brief TODO document this function
*/
void ksl_product_drdryf(const ksl_mat3x3f_t* ri, const float dc[2],
                        ksl_mat3x3f_t* ro);

/*!
@brief TODO document this function
*/
void ksl_product_drdryinv(const ksl_mat3x3_t* ri, const double dc[2],
                          ksl_mat3x3_t* ro);

/*!
@brief TODO document this function
*/
void ksl_product_drdryinvf(const ksl_mat3x3f_t* ri, const float dc[2],
                           ksl_mat3x3f_t* ro);

/*!
@brief TODO document this function
*/
void ksl_product_drdrz(const ksl_mat3x3_t* ri, const double dc[2],
                       ksl_mat3x3_t* ro);

/*!
@brief TODO document this function
*/
void ksl_product_drdrzf(const ksl_mat3x3f_t* ri, const float dc[2],
                        ksl_mat3x3f_t* ro);

/*!
@brief TODO document this function
*/
void ksl_product_drdrzinv(const ksl_mat3x3_t* ri, const double dc[2],
                          ksl_mat3x3_t* ro);

/*!
@brief TODO document this function
*/
void ksl_product_drdrzinvf(const ksl_mat3x3f_t* ri, const float dc[2],
                           ksl_mat3x3f_t* ro);

/*!
@brief TODO document this function
*/
void ksl_product_drdr(const ksl_mat3x3_t* r1i, const ksl_mat3x3_t* r2i,
                      ksl_mat3x3_t* ro);

/*!
@brief TODO document this function
*/
void ksl_product_drdrf(const ksl_mat3x3f_t* r1i, const ksl_mat3x3f_t* r2i,
                       ksl_mat3x3f_t* ro);

/*!
@brief TODO document this function
*/
void ksl_product_drdrinv(const ksl_mat3x3_t* r1i, const ksl_mat3x3_t* r2i,
                         ksl_mat3x3_t* ro);

/*!
@brief TODO document this function
*/
void ksl_product_drdrinvf(const ksl_mat3x3f_t* r1i, const ksl_mat3x3f_t* r2i,
                          ksl_mat3x3f_t* ro);

/*!
@brief TODO document this function
*/
void ksl_product_drinvdr(const ksl_mat3x3_t* r1i, const ksl_mat3x3_t* r2i,
                         ksl_mat3x3_t* ro);

/*!
@brief TODO document this function
*/
void ksl_product_drinvdrf(const ksl_mat3x3f_t* r1i, const ksl_mat3x3f_t* r2i,
                          ksl_mat3x3f_t* ro);

/*!
@brief TODO document this function
*/
void ksl_product_dv(const ksl_SE3_t* Di, const ksl_vec3_t* vi, ksl_vec3_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_dvf(const ksl_SE3f_t* Di, const ksl_vec3f_t* vi,
                     ksl_vec3f_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_dinvv(const ksl_SE3_t* Di, const ksl_vec3_t* vi,
                       ksl_vec3_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_dinvvf(const ksl_SE3f_t* Di, const ksl_vec3f_t* vi,
                        ksl_vec3f_t* vo);

/*!
@brief TODO document this function
*/
void ksl_product_ddrx(const ksl_SE3_t* Di, const double dc[2], ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddrxf(const ksl_SE3f_t* Di, const float dc[2], ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddrxinv(const ksl_SE3_t* Di, const double dc[2],
                         ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddrxinvf(const ksl_SE3f_t* Di, const float dc[2],
                          ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddry(const ksl_SE3_t* Di, const double dc[2], ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddryf(const ksl_SE3f_t* Di, const float dc[2], ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddryinv(const ksl_SE3_t* Di, const double dc[2],
                         ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddryinvf(const ksl_SE3f_t* Di, const float dc[2],
                          ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddrz(const ksl_SE3_t* Di, const double dc[2], ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddrzf(const ksl_SE3f_t* Di, const float dc[2], ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddrzinv(const ksl_SE3_t* Di, const double dc[2],
                         ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddrzinvf(const ksl_SE3f_t* Di, const float dc[2],
                          ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddt(const ksl_SE3_t* Di, const ksl_vec3_t* t, ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddtinv(const ksl_SE3_t* Di, const ksl_vec3_t* vi,
                        ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddtinvf(const ksl_SE3f_t* Di, const ksl_vec3f_t* vi,
                         ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddtf(const ksl_SE3f_t* Di, const ksl_vec3f_t* vi,
                      ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_dinvdt(const ksl_SE3_t* Di, const ksl_vec3_t* vi,
                        ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_dinvdtf(const ksl_SE3f_t* Di, const ksl_vec3f_t* vi,
                         ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddtx(const ksl_SE3_t* Di, const double ti, ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddtxf(const ksl_SE3f_t* Di, const float ti, ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddtxinv(const ksl_SE3_t* Di, const double ti, ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddtxinvf(const ksl_SE3f_t* Di, const float ti, ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddty(const ksl_SE3_t* Di, const double ti, ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddtyf(const ksl_SE3f_t* Di, const float ti, ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddtyinv(const ksl_SE3_t* Di, const double ti, ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddtyinvf(const ksl_SE3f_t* Di, const float ti, ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddtz(const ksl_SE3_t* Di, const double ti, ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddtzf(const ksl_SE3f_t* Di, const float ti, ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddtzinv(const ksl_SE3_t* Di, const double ti, ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddtzinvf(const ksl_SE3f_t* Di, const float ti, ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddr(const ksl_SE3_t* Di, const ksl_mat3x3_t* Ri,
                     ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddrf(const ksl_SE3f_t* Di, const ksl_mat3x3f_t* Ri,
                      ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddrinv(const ksl_SE3_t* Di, const ksl_mat3x3_t* Ri,
                        ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddrinvf(const ksl_SE3f_t* Di, const ksl_mat3x3f_t* Ri,
                         ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_dd(const ksl_SE3_t* D1i, const ksl_SE3_t* D2i, ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddf(const ksl_SE3f_t* D1i, const ksl_SE3f_t* D2i,
                     ksl_SE3f_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddinv(const ksl_SE3_t* D1i, const ksl_SE3_t* D2i,
                       ksl_SE3_t* Do);

/*!
@brief TODO document this function
*/
void ksl_product_ddinvf(const ksl_SE3f_t* D1i, const ksl_SE3f_t* D2i,
                        ksl_SE3f_t* Do);

#endif
