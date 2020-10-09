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

#ifndef _KSL_SE3_H_
#define _KSL_SE3_H_

#include <stdarg.h>

#include "axis.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "ksl/mat3x3.h"

typedef union ksl_mat4x4_t ksl_mat4x4_t;
typedef union ksl_mat4x4f_t ksl_mat4x4f_t;
typedef union ksl_SE3_t ksl_SE3_t;
typedef union ksl_SE3f_t ksl_SE3f_t;

/*!
@brief Double precision member of 3 Dimensional Special Euclidian group (SE3)
consisting of a double precision SO3 (othonormalized 3x3 rotation matrix) and
double precision translation vector pair.

This union allows accessing double precision SE3 quantities by field name, as
a singly dimensioned array, as a doubly dimensioned array, or by accessing a
specific column.  If using the `at` or `as_array` operators, quantities are
accessed in column major order.

The following examples illustrate how to access row 2, column 1 (using 0 based
indexing) of SE3 matrix `D`. The following access methods are equivalent.

\verbatim embed:rst
.. code-block:: c

  D.as_array[2 + 1 * 3];
  D.at[1][2];
  D.m21;
  D.v1.z;
  D.v1.at[2];
  D.v[1].z;
  D.v[1].at[2];
  D.R.m21;
  D.R.v1.z;
  D.R.v1.at[2];
  D.R.v[1].z;
  D.R.v[1].at[2];

\endverbatim

The following examples illustrate how to access row 1, column 3 (using 0 based
indexing) of SE3 matrix `D`. The following access methods are equivalent.

\verbatim embed:rst
.. code-block:: c

  D.as_array[1 + 3 * 3];
  D.at[3][1];
  D.m13;
  D.v3.y;
  D.v3.at[1];
  D.v[3].y;
  D.v[3].at[1];
  D.t.y;
  D.t.at[1];

\endverbatim

See also the `ksl_SE3_get` and `ksl_SE3_set` functions.
*/
typedef union ksl_SE3_t {
  struct {
    double as_array[12];
  }; /*!< anonymous union allows accessing quantities at specified index in
          linear array, where entities are specified in column
          major order */
  struct {
    double at[4][3];
  }; /*!< anonymous union allows accessing SE3 quantities at specified index in
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
  struct {
    ksl_vec3_t v[4];
  }; /*!< anonymous union allows accessing columns of rotation
          matrix quantities at specified index */
} ksl_SE3_t;

/*!
@brief Single precision member of 3 Dimensional Special Euclidian group (SE3)
consisting of a single precision SO3 (othonormalized 3x3 rotation matrix) and
single precision translation vector pair.

This union allows accessing single precision SE3 quantities by field name, as
a singly dimensioned array, as a doubly dimensioned array, or by accessing a
specific column.  If using the `at` or `as_array` operators, quantities are
accessed in column major order.

The following examples illustrate how to access row 2, column 1 (using 0 based
indexing) of SE3 matrix `D`. The following access methods are equivalent.

\verbatim embed:rst
.. code-block:: c

  D.as_array[2 + 1 * 3];
  D.at[1][2];
  D.m21;
  D.v1.z;
  D.v1.at[2];
  D.v[1].z;
  D.v[1].at[2];
  D.R.m21;
  D.R.v1.z;
  D.R.v1.at[2];
  D.R.v[1].z;
  D.R.v[1].at[2];

\endverbatim

The following examples illustrate how to access row 1, column 3 (using 0 based
indexing) of SE3 matrix `D`. The following access methods are equivalent.

\verbatim embed:rst
.. code-block:: c

  D.as_array[1 + 3 * 3];
  D.at[3][1];
  D.m13;
  D.v3.y;
  D.v3.at[1];
  D.v[3].y;
  D.v[3].at[1];
  D.t.y;
  D.t.at[1];

\endverbatim

See also the `ksl_SE3f_get` and `ksl_SE3f_set` functions.
*/
typedef union ksl_SE3f_t {
  struct {
    float as_array[12];
  }; /*!< anonymous union allows accessing quantities at specified index in
          linear array, with entities specified in column major order */
  struct {
    float at[4][3];
  }; /*!< anonymous union allows accessing SE3 quantities at specified index in
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
  struct {
    ksl_vec3f_t v[4];
  }; /*!< anonymous union allows accessing columns of rotation
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
@brief TODO document this function
*/
double ksl_SE3_get(const ksl_SE3_t* D, const int row, const int column);

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

#ifdef __cplusplus
}
#endif

#endif
