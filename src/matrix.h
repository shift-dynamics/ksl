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

#include "vector.h"

/*!
@brief general 3x3 double precision matrix

allow accessing mat3x3 quantities by field name or by
using at / as_array operators.  if using the at or as_array operators, then
quantities are accessed in column major order
*/
typedef union ksl_mat3x3_t {
  double at[9];
  double as_array[3][3];
  struct {
    double m00, m10, m20;
    double m01, m11, m21;
    double m02, m12, m22;
  };
} ksl_mat3x3_t;

/*!
@brief general 4x4 double precision matrix

allow accessing mat4x4 quantities by field name or
using at / as_array operators.  if using the at / as_array operators,
quantities are accessed in column major order
*/
typedef union ksl_mat4x4_t {
  double at[16];
  double as_array[4][4];
  struct {
    double m00, m10, m20, m30;
    double m01, m11, m21, m31;
    double m02, m12, m22, m32;
    double m03, m13, m23, m33;
  };
} ksl_mat4x4_t;

/*!
@brief SE3 (3 Dimensional Special Euclidian group) consists of a
SO3 (othonormalized 3x3 rotation matrix) and translation vector pair

if using the at/as_array operators,
quantities are accessed in column major order with Rotation matrix
quantities coming first, followed by translation vector
*/
typedef union ksl_SE3_t {
  double at[12];
  double as_array[4][3];
  struct {
    ksl_mat3x3_t R;
    ksl_vec3_t t;
  };
} ksl_SE3_t;

#endif
