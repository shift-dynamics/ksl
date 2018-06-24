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
  struct {
    ksl_vec3_t v0, v1, v2;
  };
  ksl_vec3_t v[3];
} ksl_mat3x3_t;

/*!
@brief general 3x3 double precision matrix

allow accessing mat3x3 quantities by field name or by
using at / as_array operators.  if using the at or as_array operators, then
quantities are accessed in column major order
*/
typedef union ksl_mat3x3f_t {
  float at[9];
  float as_array[3][3];
  struct {
    float m00, m10, m20;
    float m01, m11, m21;
    float m02, m12, m22;
  };
  struct {
    ksl_vec3f_t v0, v1, v2;
  };
  ksl_vec3f_t v[3];
} ksl_mat3x3f_t;

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
  struct {
    ksl_vec4_t v0, v1, v2, v3;
  };
} ksl_mat4x4_t;

/*!
@brief general 4x4 double precision matrix

allow accessing mat4x4 quantities by field name or
using at / as_array operators.  if using the at / as_array operators,
quantities are accessed in column major order
*/
typedef union ksl_mat4x4f_t {
  float at[16];
  float as_array[4][4];
  struct {
    float m00, m10, m20, m30;
    float m01, m11, m21, m31;
    float m02, m12, m22, m32;
    float m03, m13, m23, m33;
  };
  struct {
    ksl_vec4f_t v0, v1, v2, v3;
  };
} ksl_mat4x4f_t;

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
  struct {
    double m00, m10, m20;
    double m01, m11, m21;
    double m02, m12, m22;
    double m03, m13, m23;
  };
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
  float at[12];
  float as_array[4][3];
  struct {
    ksl_mat3x3f_t R;
    ksl_vec3f_t t;
  };
  struct {
    float m00, m10, m20;
    float m01, m11, m21;
    float m02, m12, m22;
    float m03, m13, m23;
  };
} ksl_SE3f_t;

ksl_SE3_t ksl_SE3(const double m00, const double m01, const double m02,
                  const double m03, const double m10, const double m11,
                  const double m12, const double m13, const double m20,
                  const double m21, const double m22, const double m23);

ksl_SE3_t ksl_SE3_cmo(const double m00, const double m10, const double m20,
                      const double m01, const double m11, const double m21,
                      const double m02, const double m12, const double m22,
                      const double m03, const double m13, const double m23);

ksl_SE3_t ksl_SE3_fromRt(const ksl_mat3x3_t R, const ksl_vec3_t t);

ksl_SE3f_t ksl_SE3f(const float m00, const float m01, const float m02,
                    const float m03, const float m10, const float m11,
                    const float m12, const float m13, const float m20,
                    const float m21, const float m22, const float m23);

ksl_SE3f_t ksl_SE3f_cmo(const float m00, const float m10, const float m20,
                        const float m01, const float m11, const float m21,
                        const float m02, const float m12, const float m22,
                        const float m03, const float m13, const float m23);

ksl_SE3f_t ksl_SE3f_fromRt(const ksl_mat3x3f_t R, const ksl_vec3f_t t);

ksl_mat3x3_t ksl_mat3x3(const double m00, const double m01, const double m02,
                        const double m10, const double m11, const double m12,
                        const double m20, const double m21, const double m22);

ksl_mat3x3_t ksl_mat3x3_cmo(const double m00, const double m10,
                            const double m20, const double m01,
                            const double m11, const double m21,
                            const double m02, const double m12,
                            const double m22);

ksl_mat3x3f_t ksl_mat3x3f(const float m00, const float m01, const float m02,
                          const float m10, const float m11, const float m12,
                          const float m20, const float m21, const float m22);

ksl_mat3x3f_t ksl_mat3x3f_cmo(const float m00, const float m10, const float m20,
                              const float m01, const float m11, const float m21,
                              const float m02, const float m12,
                              const float m22);

ksl_mat4x4_t ksl_mat4x4(const double m00, const double m01, const double m02,
                        const double m03, const double m10, const double m11,
                        const double m12, const double m13, const double m20,
                        const double m21, const double m22, const double m23,
                        const double m30, const double m31, const double m32,
                        const double m33);

ksl_mat4x4_t ksl_mat4x4_cmo(
  const double m00, const double m10, const double m20, const double m30,
  const double m01, const double m11, const double m21, const double m31,
  const double m02, const double m12, const double m22, const double m32,
  const double m03, const double m13, const double m23, const double m33);

ksl_mat4x4_t ksl_mat4x4_fromSE3(const ksl_SE3_t D);

ksl_mat4x4_t ksl_mat4x4_fromRt(const ksl_mat3x3_t R, const ksl_vec3_t t);

ksl_mat4x4f_t ksl_mat4x4f(const float m00, const float m01, const float m02,
                          const float m03, const float m10, const float m11,
                          const float m12, const float m13, const float m20,
                          const float m21, const float m22, const float m23,
                          const float m30, const float m31, const float m32,
                          const float m33);

ksl_mat4x4f_t ksl_mat4x4f_cmo(const float m00, const float m10, const float m20,
                              const float m30, const float m01, const float m11,
                              const float m21, const float m31, const float m02,
                              const float m12, const float m22, const float m32,
                              const float m03, const float m13, const float m23,
                              const float m33);

ksl_mat4x4f_t ksl_mat4x4f_fromSE3f(const ksl_SE3f_t D);

ksl_mat4x4f_t ksl_mat4x4f_fromRt(const ksl_mat3x3f_t R, const ksl_vec3f_t t);

ksl_SE3_t* ksl_SE3_alloc(int);

ksl_SE3f_t* ksl_SE3f_alloc(int);

ksl_mat3x3_t* ksl_mat3x3_alloc(int);

ksl_mat3x3f_t* ksl_mat3x3f_alloc(int);

ksl_mat4x4_t* ksl_mat4x4_alloc(int);

ksl_mat4x4f_t* ksl_mat4x4f_alloc(int);

void ksl_SE3_toMat4x4(const ksl_SE3_t* d, ksl_mat4x4_t* m);

void ksl_SE3f_toMat4x4f(const ksl_SE3f_t* d, ksl_mat4x4f_t* m);

void ksl_SE3_toMat4x4f(const ksl_SE3_t* d, ksl_mat4x4f_t* m);

void ksl_dc(double thetai, double dc[2]);

void ksl_dcf(float thetai, float dc[2]);

void ksl_SE3_setIdentity(ksl_SE3_t* d);

void ksl_SE3f_setIdentity(ksl_SE3f_t* d);

void ksl_mat3x3_setIdentity(ksl_mat3x3_t* r);

void ksl_mat3x3f_setIdentity(ksl_mat3x3f_t* r);

void ksl_mat3x3_set(ksl_mat3x3_t* R, const int row, const int column,
                    const double value);

void ksl_mat4x4_set(ksl_mat4x4_t* R, const int row, const int column,
                    const double value);

void ksl_SE3_set(ksl_SE3_t* D, const int row, const int column,
                 const double value);

void ksl_SE3f_set(ksl_SE3f_t* D, const int row, const int column,
                  const float value);

void ksl_mat3x3_setFromVectors(ksl_mat3x3_t* R, const ksl_vec3_t* x,
                               const ksl_vec3_t* y, const ksl_vec3_t* z);

void ksl_mat3x3f_setFromVectors(ksl_mat3x3f_t* R, const ksl_vec3f_t* x,
                                const ksl_vec3f_t* y, const ksl_vec3f_t* z);

void ksl_mat3x3f_set(ksl_mat3x3f_t* R, int row, int column, float value);

void ksl_mat4x4f_set(ksl_mat4x4f_t* D, int row, int column, float value);

void ksl_mat4x4_setIdentity(ksl_mat4x4_t* M);

void ksl_mat4x4f_setIdentity(ksl_mat4x4f_t* M);

double ksl_SE3_get(const ksl_SE3_t* D, const int row, const int column);

double ksl_mat3x3_get(const ksl_mat3x3_t* R, const int row, const int column);

float ksl_mat3x3f_get(const ksl_mat3x3f_t* R, const int row, const int column);

float ksl_SE3f_get(const ksl_SE3f_t* D, const int row, const int column);

void ksl_SE3_getTranslation(const ksl_SE3_t* D, ksl_vec3_t* t);

void ksl_SE3f_getTranslation(const ksl_SE3f_t* D, ksl_vec3f_t* t);

void ksl_mat3x3_copy(const ksl_mat3x3_t* ri, ksl_mat3x3_t* ro);

void ksl_mat3x3f_copy(const ksl_mat3x3f_t* ri, ksl_mat3x3f_t* ro);

int ksl_mat3x3_invert(ksl_mat3x3_t* R);

int ksl_mat3x3f_invert(ksl_mat3x3f_t* R);

int ksl_mat3x3_inverted(const ksl_mat3x3_t* ri, ksl_mat3x3_t* ro);

int ksl_mat3x3f_inverted(const ksl_mat3x3f_t* ri, ksl_mat3x3f_t* ro);

void ksl_mat3x3_transpose(ksl_mat3x3_t* R);

void ksl_mat3x3f_transpose(ksl_mat3x3f_t* R);

void ksl_mat3x3_transposed(const ksl_mat3x3_t* ri, ksl_mat3x3_t* ro);

void ksl_mat3x3f_transposed(const ksl_mat3x3f_t* ri, ksl_mat3x3f_t* ro);

void ksl_SE3_invert(ksl_SE3_t* D);

void ksl_SE3f_invert(ksl_SE3f_t* D);

void ksl_SE3_inverted(const ksl_SE3_t* Di, ksl_SE3_t* Do);

void ksl_SE3f_inverted(const ksl_SE3f_t* Di, ksl_SE3f_t* Do);

void ksl_SE3_copy(const ksl_SE3_t* Di, ksl_SE3_t* Do);

void ksl_SE3f_copy(const ksl_SE3f_t* Di, ksl_SE3f_t* Do);

/*!
@brief macro used obtain Euler angles, allows optionally passing in reference
angles from a previous nearby pose to ensure continuity in angles between
adjacent poses

@param r [in] rotation matrix
@param axisType [in] a ksl_axis_enum_t type specifying Euler angle axis
sequence.
@param angles [out] euler angles returned in angles
@param reference_angles [optional] euler angles from a previous nearby pose
*/
#define ksl_mat3x3_getEulerAngles(r, angles, axisType, ...)                    \
  {                                                                            \
    ksl_mat3x3_getEulerAnglesWithReference(r, angles, axisType, ##__VA_ARGS__, \
                                           NULL);                              \
  }

void ksl_mat3x3_getEulerAnglesWithReference(const ksl_mat3x3_t* r,
                                            const ksl_axis_enum_t axisType,
                                            ksl_vec3_t* angles, ...);

/*!
@brief macro used obtain Euler angles from a single precision rotation matrix,
allows optionally passing in reference angles from a previous nearby pose to
ensure continuity in angles between adjacent poses

@param r [in] rotation matrix
@param axisType [in] a ksl_axis_enum_t type specifying Euler angle axis
sequence.
@param angles [out] euler angles returned in angles
@param reference_angles [optional] euler angles from a previous nearby pose
*/
#define ksl_mat3x3f_getEulerAngles(r, angles, axisType, ...)                   \
  {                                                                            \
    ksl_mat3x3f_getEulerAnglesWithReference(r, angles, axisType,               \
                                            ##__VA_ARGS__, NULL);              \
  }

void ksl_mat3x3f_getEulerAnglesWithReference(const ksl_mat3x3f_t* r,
                                             const ksl_axis_enum_t axisType,
                                             ksl_vec3f_t* angles, ...);

void ksl_mat3x3_setFromEulerAngles(ksl_mat3x3_t*,
                                   const ksl_axis_enum_t axisType,
                                   const ksl_vec3_t*);

void ksl_mat3x3f_setFromEulerAngles(ksl_mat3x3f_t*,
                                    const ksl_axis_enum_t axisType,
                                    const ksl_vec3f_t*);

void ksl_mat3x3_getAxisAngle(const ksl_mat3x3_t*, ksl_vec3_t*, double*);

void ksl_mat3x3_setFromAxisAngle(ksl_mat3x3_t*, const ksl_vec3_t*,
                                 const double);

void ksl_mat3x3f_getAxisAngle(const ksl_mat3x3f_t*, ksl_vec3f_t*, float*);

void ksl_mat3x3f_setFromAxisAngle(ksl_mat3x3f_t*, const ksl_vec3f_t*,
                                  const float);

void ksl_mat4x4_getTranslation(const ksl_mat4x4_t* Mi, ksl_vec3_t* to);

void ksl_mat4x4f_getTranslation(const ksl_mat4x4f_t* Mi, ksl_vec3f_t* to);

double ksl_mat4x4_get(const ksl_mat4x4_t* Mi, const int row, const int column);

float ksl_mat4x4f_get(const ksl_mat4x4f_t* Mi, const int row, const int column);

double ksl_mat3x3_determinant(const ksl_mat3x3_t*);

float ksl_mat3x3f_determinant(const ksl_mat3x3f_t*);

/* matrix vector operations */
void ksl_product_drv(const ksl_mat3x3_t* ri, const ksl_vec3_t* vi,
                     ksl_vec3_t* vo);

void ksl_product_drvf(const ksl_mat3x3f_t* ri, const ksl_vec3f_t* vi,
                      ksl_vec3f_t* vo);

void ksl_product_drvinv(const ksl_mat3x3_t* ri, const ksl_vec3_t* vi,
                        ksl_vec3_t* vo);

void ksl_product_drvinvf(const ksl_mat3x3f_t* ri, const ksl_vec3f_t* vi,
                         ksl_vec3f_t* vo);

void ksl_product_drinvv(const ksl_mat3x3_t* ri, const ksl_vec3_t* vi,
                        ksl_vec3_t* vo);

void ksl_product_drinvvf(const ksl_mat3x3f_t* ri, const ksl_vec3f_t* vi,
                         ksl_vec3f_t* vo);

void ksl_product_drinvvinv(const ksl_mat3x3_t* ri, const ksl_vec3_t* vi,
                           ksl_vec3_t* vo);

void ksl_product_drinvvinvf(const ksl_mat3x3f_t* ri, const ksl_vec3f_t* vi,
                            ksl_vec3f_t* vo);

void ksl_product_drvtx(const ksl_mat3x3_t* ri, const double ti, ksl_vec3_t* vo);

void ksl_product_drvtxf(const ksl_mat3x3f_t* ri, const float ti,
                        ksl_vec3f_t* vo);

void ksl_product_drvtxinv(const ksl_mat3x3_t* ri, const double ti,
                          ksl_vec3_t* vo);

void ksl_product_drvtxinvf(const ksl_mat3x3f_t* ri, const float ti,
                           ksl_vec3f_t* vo);

void ksl_product_drvty(const ksl_mat3x3_t* ri, const double ti, ksl_vec3_t* vo);

void ksl_product_drvtyf(const ksl_mat3x3f_t* ri, const float ti,
                        ksl_vec3f_t* vo);

void ksl_product_drvtyinv(const ksl_mat3x3_t* ri, const double ti,
                          ksl_vec3_t* vo);

void ksl_product_drvtyinvf(const ksl_mat3x3f_t* ri, const float ti,
                           ksl_vec3f_t* vo);

void ksl_product_drvtz(const ksl_mat3x3_t* ri, const double ti, ksl_vec3_t* vo);

void ksl_product_drvtzf(const ksl_mat3x3f_t* ri, const float ti,
                        ksl_vec3f_t* vo);

void ksl_product_drvtzinv(const ksl_mat3x3_t* ri, const double ti,
                          ksl_vec3_t* vo);

void ksl_product_drvtzinvf(const ksl_mat3x3f_t* ri, const float ti,
                           ksl_vec3f_t* vo);

/* matrix-matrix operations */
void ksl_product_drdrx(const ksl_mat3x3_t* ri, const double dc[2],
                       ksl_mat3x3_t* ro);

void ksl_product_drdrxf(const ksl_mat3x3f_t* ri, const float dc[2],
                        ksl_mat3x3f_t* ro);

void ksl_product_drdrxinv(const ksl_mat3x3_t* ri, const double dc[2],
                          ksl_mat3x3_t* ro);

void ksl_product_drdrxinvf(const ksl_mat3x3f_t* ri, const float dc[2],
                           ksl_mat3x3f_t* ro);

void ksl_product_drdry(const ksl_mat3x3_t* ri, const double dc[2],
                       ksl_mat3x3_t* ro);

void ksl_product_drdryf(const ksl_mat3x3f_t* ri, const float dc[2],
                        ksl_mat3x3f_t* ro);

void ksl_product_drdryinv(const ksl_mat3x3_t* ri, const double dc[2],
                          ksl_mat3x3_t* ro);

void ksl_product_drdryinvf(const ksl_mat3x3f_t* ri, const float dc[2],
                           ksl_mat3x3f_t* ro);

void ksl_product_drdrz(const ksl_mat3x3_t* ri, const double dc[2],
                       ksl_mat3x3_t* ro);

void ksl_product_drdrzf(const ksl_mat3x3f_t* ri, const float dc[2],
                        ksl_mat3x3f_t* ro);

void ksl_product_drdrzinv(const ksl_mat3x3_t* ri, const double dc[2],
                          ksl_mat3x3_t* ro);

void ksl_product_drdrzinvf(const ksl_mat3x3f_t* ri, const float dc[2],
                           ksl_mat3x3f_t* ro);

void ksl_product_drdr(const ksl_mat3x3_t* r1i, const ksl_mat3x3_t* r2i,
                      ksl_mat3x3_t* ro);

void ksl_product_drdrf(const ksl_mat3x3f_t* r1i, const ksl_mat3x3f_t* r2i,
                       ksl_mat3x3f_t* ro);

void ksl_product_drdrinv(const ksl_mat3x3_t* r1i, const ksl_mat3x3_t* r2i,
                         ksl_mat3x3_t* ro);

void ksl_product_drdrinvf(const ksl_mat3x3f_t* r1i, const ksl_mat3x3f_t* r2i,
                          ksl_mat3x3f_t* ro);

void ksl_product_drinvdr(const ksl_mat3x3_t* r1i, const ksl_mat3x3_t* r2i,
                         ksl_mat3x3_t* ro);

void ksl_product_drinvdrf(const ksl_mat3x3f_t* r1i, const ksl_mat3x3f_t* r2i,
                          ksl_mat3x3f_t* ro);
void ksl_product_dv(const ksl_SE3_t* Di, const ksl_vec3_t* vi, ksl_vec3_t* vo);

void ksl_product_dinvv(const ksl_SE3_t* Di, const ksl_vec3_t* vi,
                       ksl_vec3_t* vo);

void ksl_product_ddrx(const ksl_SE3_t* Di, const double dc[2], ksl_SE3_t* Do);

void ksl_product_ddrxf(const ksl_SE3f_t* Di, const float dc[2], ksl_SE3f_t* Do);

void ksl_product_ddrxinv(const ksl_SE3_t* Di, const double dc[2],
                         ksl_SE3_t* Do);

void ksl_product_ddrxinvf(const ksl_SE3f_t* Di, const float dc[2],
                          ksl_SE3f_t* Do);

void ksl_product_ddry(const ksl_SE3_t* Di, const double dc[2], ksl_SE3_t* Do);

void ksl_product_ddryf(const ksl_SE3f_t* Di, const float dc[2], ksl_SE3f_t* Do);

void ksl_product_ddryinv(const ksl_SE3_t* Di, const double dc[2],
                         ksl_SE3_t* Do);

void ksl_product_ddryinvf(const ksl_SE3f_t* Di, const float dc[2],
                          ksl_SE3f_t* Do);

void ksl_product_ddrz(const ksl_SE3_t* Di, const double dc[2], ksl_SE3_t* Do);

void ksl_product_ddrzf(const ksl_SE3f_t* Di, const float dc[2], ksl_SE3f_t* Do);

void ksl_product_ddrzinv(const ksl_SE3_t* Di, const double dc[2],
                         ksl_SE3_t* Do);

void ksl_product_ddrzinvf(const ksl_SE3f_t* Di, const float dc[2],
                          ksl_SE3f_t* Do);

void ksl_product_ddt(const ksl_SE3_t* Di, const ksl_vec3_t* t, ksl_SE3_t* Do);

void ksl_product_ddtinv(const ksl_SE3_t* Di, const ksl_vec3_t* vi,
                        ksl_SE3_t* Do);

void ksl_product_ddtf(const ksl_SE3f_t* Di, const ksl_vec3f_t* vi,
                      ksl_SE3f_t* Do);

void ksl_product_dinvdt(const ksl_SE3_t* Di, const ksl_vec3_t* vi,
                        ksl_SE3_t* Do);

void ksl_product_dinvdtf(const ksl_SE3f_t* Di, const ksl_vec3f_t* vi,
                         ksl_SE3f_t* Do);

void ksl_product_ddtx(const ksl_SE3_t* Di, const double ti, ksl_SE3_t* Do);

void ksl_product_ddtxinv(const ksl_SE3_t* Di, const double ti, ksl_SE3_t* Do);

void ksl_product_ddtxinvf(const ksl_SE3f_t* Di, const float ti, ksl_SE3f_t* Do);

void ksl_product_ddty(const ksl_SE3_t* Di, const double ti, ksl_SE3_t* Do);

void ksl_product_ddtyf(const ksl_SE3f_t* Di, const float ti, ksl_SE3f_t* Do);

void ksl_product_ddtyinv(const ksl_SE3_t* Di, const double ti, ksl_SE3_t* Do);

void ksl_product_ddtyinvf(const ksl_SE3f_t* Di, const float ti, ksl_SE3f_t* Do);

void ksl_product_ddtz(const ksl_SE3_t* Di, const double ti, ksl_SE3_t* Do);

void ksl_product_ddtzf(const ksl_SE3f_t* Di, const float ti, ksl_SE3f_t* Do);

void ksl_product_ddtzinv(const ksl_SE3_t* Di, const double ti, ksl_SE3_t* Do);

void ksl_product_ddr(const ksl_SE3_t* Di, const ksl_mat3x3_t* Ri,
                     ksl_SE3_t* Do);

void ksl_product_ddrf(const ksl_SE3f_t* Di, const ksl_mat3x3f_t* Ri,
                      ksl_SE3f_t* Do);

void ksl_product_ddrinv(const ksl_SE3_t* Di, const ksl_mat3x3_t* Ri,
                        ksl_SE3_t* Do);

void ksl_product_ddrinvf(const ksl_SE3f_t* Di, const ksl_mat3x3f_t* Ri,
                         ksl_SE3f_t* Do);

void ksl_product_dd(const ksl_SE3_t* D1i, const ksl_SE3_t* D2i, ksl_SE3_t* Do);

void ksl_product_ddf(const ksl_SE3f_t* D1i, const ksl_SE3f_t* D2i,
                     ksl_SE3f_t* Do);

void ksl_product_ddinv(const ksl_SE3_t* D1i, const ksl_SE3_t* D2i,
                       ksl_SE3_t* Do);

void ksl_product_ddinvf(const ksl_SE3f_t* D1i, const ksl_SE3f_t* D2i,
                        ksl_SE3f_t* Do);

#endif
