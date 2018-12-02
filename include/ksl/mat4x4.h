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

#ifndef _KSL_MAT4X4_H_
#define _KSL_MAT4X4_H_

#include <stdarg.h>

#include "axis.h"
#include "pub_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "vec3.h"
#include "vec4.h"

typedef union ksl_mat3x3_t ksl_mat3x3_t;
typedef union ksl_mat3x3f_t ksl_mat3x3f_t;

typedef union ksl_SE3_t ksl_SE3_t;
typedef union ksl_SE3f_t ksl_SE3f_t;

/*! @brief A general double precision 4x4 matrix.

This union allows accessing double precision mat4x4 quantities by field name, as
a singly dimensioned array, as a doubly dimensioned array, or by accessing a
specific column.  If using the `at` or `as_array` operators, quantities are
accessed in column major order.

The following examples illustrate how to access row 3, column 2 (using 0 based
indexing) of matrix `M`. The following access methods are equivalent.

\verbatim embed:rst
.. code-block:: c

  M.as_array[3 + 2 * 4];
  M.at[2][3];
  M.m32;
  M.v2.w;
  M.v2.at[3];
  M.v[2].w;
  M.v[2].at[3];

\endverbatim


See also the `ksl_mat4x4_get` and `ksl_mat4x4_set` functions.

*/
typedef union ksl_mat4x4_t {
  struct {
    double as_array[16];
  }; /*!< anonymous union allows accessing quantities at specified index in
          linear array, where entities are specified in column
          major order */
  struct {
    double at[4][4];
  }; /*!< anonymous union allows accessing mat3x3 quantities at specified index
        in a doubly dimensioned array, where entities are specified in column
        major order */
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
  struct {
    ksl_vec4_t v[4];
  }; /*!< anonymous union allows accessing columns of rotation
          matrix quantities at specified index */
} ksl_mat4x4_t;

/*!
@brief A general single precision 4x4 matrix.

This union allows accessing single precision mat4x4 quantities by field name, as
a singly dimensioned array, as a doubly dimensioned array, or by accessing a
specific column.  If using the `at` or `as_array` operators, quantities are
accessed in column major order.

The following examples illustrate how to access row 3, column 2 (using 0 based
indexing) of matrix `M`. The following access methods are equivalent.

\verbatim embed:rst
.. code-block:: c

  M.as_array[3 + 2 * 4];
  M.at[2][3];
  M.m32;
  M.v2.w;
  M.v2.at[3];
  M.v[2].w;
  M.v[2].at[3];

\endverbatim

See also the `ksl_mat4x4f_get` and `ksl_mat4x4f_set` functions.
*/
typedef union ksl_mat4x4f_t {
  struct {
    float as_array[16];
  }; /*!< allows accessing quantities at specified index in
          linear array, where entities are specified in column
          major order */
  struct {
    float at[4][4];
  }; /*!< allows accessing mat3x3 quantities at specified index in
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
  struct {
    ksl_vec4f_t v[4];
  }; /*!< anonymous union allows accessing columns of rotation
          matrix quantities at specified index */
} ksl_mat4x4f_t;

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
void ksl_mat4x4_set(ksl_mat4x4_t* M, const int row, const int column,
                    const double value);

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

#ifdef __cplusplus
}
#endif

#endif
