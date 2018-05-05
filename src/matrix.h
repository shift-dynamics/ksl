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

#include "axis.h"

typedef union ksl_screw_t ksl_screw_t;
typedef union ksl_screwf_t ksl_screwf_t;

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
} ksl_SE3f_t;

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

void ksl_SE3_setIdentity(ksl_SE3_t* d);

void ksl_mat3x3_setIdentity(ksl_mat3x3_t* r);

void ksl_mat3x3_set(ksl_mat3x3_t* R, const int row, const int column,
                    const double value);

void ksl_mat4x4_set(ksl_mat4x4_t* R, const int row, const int column,
                    const double value);

void ksl_SE3_set(ksl_SE3_t* D, const int row, const int column,
                 const double value);

void ksl_mat3x3_setFromVectors(ksl_mat3x3_t* R, const ksl_vec3_t* x,
                               const ksl_vec3_t* y, const ksl_vec3_t* z);

void ksl_mat3x3f_set(ksl_mat3x3f_t* R, int row, int column, float value);

void ksl_mat4x4f_set(ksl_mat4x4f_t* D, int row, int column, float value);

void ksl_mat4x4f_setIdentity(ksl_mat4x4f_t* M);

void ksl_SE3f_set(ksl_SE3f_t* D, int row, int column, float value);

double ksl_SE3_get(ksl_SE3_t* D, int row, int column);

float ksl_mat3x3f_get(ksl_mat3x3f_t* R, int row, int column);

float ksl_SE3f_get(ksl_SE3f_t* D, int row, int column);

void ksl_SE3_getTranslation(ksl_SE3_t* D, ksl_vec3_t* t);

void ksl_mat3x3_copy(ksl_mat3x3_t* ri, ksl_mat3x3_t* ro);

void ksl_mat3x3f_copy(ksl_mat3x3f_t* ri, ksl_mat3x3f_t* ro);

void ksl_mat3x3_invert(ksl_mat3x3_t* R);

void ksl_mat3x3_inverted(const ksl_mat3x3_t* ri, ksl_mat3x3_t* ro);

void ksl_mat3x3_transpose(ksl_mat3x3_t* R);

void ksl_mat3x3_transposed(const ksl_mat3x3_t* ri, ksl_mat3x3_t* ro);

void ksl_SE3_invert(ksl_SE3_t* D);

void ksl_SE3f_invert(ksl_SE3f_t* D);

void ksl_SE3_inverted(const ksl_SE3_t* Di, ksl_SE3_t* Do);

void ksl_SE3f_inverted(const ksl_SE3f_t* Di, ksl_SE3f_t* Do);

void ksl_SE3_copy(const ksl_SE3_t* Di, ksl_SE3_t* Do);

void ksl_SE3f_copy(const ksl_SE3f_t* Di, ksl_SE3f_t* Do);

void ksl_mat3x3_getEulerAngles(const ksl_mat3x3_t* rin, ksl_vec3_t* angles,
                               const ksl_axis_enum_t axisType);

void ksl_mat3x3_setFromEulerAngles(ksl_mat3x3_t*, const ksl_vec3_t*,
                                   const ksl_axis_enum_t axisType);

double ksl_mat3x3_getScalar(const ksl_mat3x3_t* ri);

float ksl_mat3x3f_getScalar(const ksl_mat3x3f_t* ri);

void ksl_mat4x4_getTranslation(const ksl_mat4x4_t* Mi, ksl_vec3_t* to);

void ksl_mat4x4f_getTranslation(const ksl_mat4x4f_t* Mi, ksl_vec3f_t* to);

void ksl_mat4x4f_get(const ksl_mat4x4f_t* Mi, int row, int column);

double ksl_mat3x3_determinant(const ksl_mat3x3_t*);

/* matrix vector operations */
void ksl_product_DrV(const ksl_mat3x3_t* ri, const ksl_vec3_t* vi,
                     ksl_vec3_t* vo);

void ksl_product_DrVf(const ksl_mat3x3f_t* ri, const ksl_vec3f_t* vi,
                      ksl_vec3f_t* vo);

void ksl_product_DrVinv(const ksl_mat3x3_t* ri, const ksl_vec3_t* vi,
                        ksl_vec3_t* vo);

void ksl_product_DrVinvf(const ksl_mat3x3f_t* ri, const ksl_vec3f_t* vi,
                         ksl_vec3f_t* vo);

void ksl_product_DrinvV(const ksl_mat3x3_t* ri, const ksl_vec3_t* vi,
                        ksl_vec3_t* vo);

void ksl_product_DrinvVf(const ksl_mat3x3f_t* ri, const ksl_vec3f_t* vi,
                         ksl_vec3f_t* vo);

void ksl_product_DrinvVinv(const ksl_mat3x3_t* ri, const ksl_vec3_t* vi,
                           ksl_vec3_t* vo);

void ksl_product_DrinvVinvf(const ksl_mat3x3f_t* ri, const ksl_vec3f_t* vi,
                            ksl_vec3f_t* vo);

void ksl_product_DrVtx(const ksl_mat3x3_t* ri, const double ti, ksl_vec3_t* vo);

void ksl_product_DrVtxf(const ksl_mat3x3f_t* ri, const float ti,
                        ksl_vec3f_t* vo);

void ksl_product_DrVtxinv(const ksl_mat3x3_t* ri, const double ti,
                          ksl_vec3_t* vo);

void ksl_product_DrVtxinvf(const ksl_mat3x3f_t* ri, const float ti,
                           ksl_vec3f_t* vo);

void ksl_product_DrVty(const ksl_mat3x3_t* ri, const double ti, ksl_vec3_t* vo);

void ksl_product_DrVtyf(const ksl_mat3x3f_t* ri, const float ti,
                        ksl_vec3f_t* vo);

void ksl_product_DrVtyinv(const ksl_mat3x3_t* ri, const double ti,
                          ksl_vec3_t* vo);

void ksl_product_DrVtyinvf(const ksl_mat3x3f_t* ri, const float ti,
                           ksl_vec3f_t* vo);

void ksl_product_DrVtz(const ksl_mat3x3_t* ri, const double ti, ksl_vec3_t* vo);

void ksl_product_DrVtzf(const ksl_mat3x3f_t* ri, const float ti,
                        ksl_vec3f_t* vo);

void ksl_product_DrVtzinv(const ksl_mat3x3_t* ri, const double ti,
                          ksl_vec3_t* vo);

void ksl_product_DrVtzinvf(const ksl_mat3x3f_t* ri, const float ti,
                           ksl_vec3f_t* vo);

/* matrix-matrix operations */
void ksl_product_DrDrx(const ksl_mat3x3_t* ri, const double dc[2],
                       ksl_mat3x3_t* ro);

void ksl_product_DrDrxf(const ksl_mat3x3f_t* ri, const float dc[2],
                        ksl_mat3x3f_t* ro);

void ksl_product_DrDrxinv(const ksl_mat3x3_t* ri, const double dc[2],
                          ksl_mat3x3_t* ro);

void ksl_product_DrDrxinvf(const ksl_mat3x3f_t* ri, const float dc[2],
                           ksl_mat3x3f_t* ro);

void ksl_product_DrDry(const ksl_mat3x3_t* ri, const double dc[2],
                       ksl_mat3x3_t* ro);

void ksl_product_DrDryf(const ksl_mat3x3f_t* ri, const float dc[2],
                        ksl_mat3x3f_t* ro);

void ksl_product_DrDryinv(const ksl_mat3x3_t* ri, const double dc[2],
                          ksl_mat3x3_t* ro);

void ksl_product_DrDryinvf(const ksl_mat3x3f_t* ri, const float dc[2],
                           ksl_mat3x3f_t* ro);

void ksl_product_DrDrz(const ksl_mat3x3_t* ri, const double dc[2],
                       ksl_mat3x3_t* ro);

void ksl_product_DrDrzf(const ksl_mat3x3f_t* ri, const float dc[2],
                        ksl_mat3x3f_t* ro);

void ksl_product_DrDrzinv(const ksl_mat3x3_t* ri, const double dc[2],
                          ksl_mat3x3_t* ro);

void ksl_product_DrDrzinvf(const ksl_mat3x3f_t* ri, const float dc[2],
                           ksl_mat3x3f_t* ro);

void ksl_product_DrDr(const ksl_mat3x3_t* r1i, const ksl_mat3x3_t* r2i,
                      ksl_mat3x3_t* ro);

void ksl_product_DrDrf(const ksl_mat3x3f_t* r1i, const ksl_mat3x3f_t* r2i,
                       ksl_mat3x3f_t* ro);

void ksl_product_DrDrinv(const ksl_mat3x3_t* r1i, const ksl_mat3x3_t* r2i,
                         ksl_mat3x3_t* ro);

void ksl_product_DrDrinvf(const ksl_mat3x3f_t* r1i, const ksl_mat3x3f_t* r2i,
                          ksl_mat3x3f_t* ro);

void ksl_product_DrinvDr(const ksl_mat3x3_t* r1i, const ksl_mat3x3_t* r2i,
                         ksl_mat3x3_t* ro);

void ksl_product_DrinvDrf(const ksl_mat3x3f_t* r1i, const ksl_mat3x3f_t* r2i,
                          ksl_mat3x3f_t* ro);
void ksl_product_DV(const ksl_SE3_t* Di, const ksl_vec3_t* vi, ksl_vec3_t* vo);

void ksl_product_DinvV(const ksl_SE3_t* Di, const ksl_vec3_t* vi,
                       ksl_vec3_t* vo);

void ksl_product_DDrx(const ksl_SE3_t* Di, const double dc[2], ksl_SE3_t* Do);

void ksl_product_DDrxf(const ksl_SE3f_t* Di, const float dc[2], ksl_SE3f_t* Do);

void ksl_product_DDrxinv(const ksl_SE3_t* Di, const double dc[2],
                         ksl_SE3_t* Do);

void ksl_product_DDrxinvf(const ksl_SE3f_t* Di, const float dc[2],
                          ksl_SE3f_t* Do);

void ksl_product_DDry(const ksl_SE3_t* Di, const double dc[2], ksl_SE3_t* Do);

void ksl_product_DDryf(const ksl_SE3f_t* Di, const float dc[2], ksl_SE3f_t* Do);

void ksl_product_DDryinv(const ksl_SE3_t* Di, const double dc[2],
                         ksl_SE3_t* Do);

void ksl_product_DDryinvf(const ksl_SE3f_t* Di, const float dc[2],
                          ksl_SE3f_t* Do);

void ksl_product_DDrz(const ksl_SE3_t* Di, const double dc[2], ksl_SE3_t* Do);

void ksl_product_DDrzf(const ksl_SE3f_t* Di, const float dc[2], ksl_SE3f_t* Do);

void ksl_product_DDrzinv(const ksl_SE3_t* Di, const double dc[2],
                         ksl_SE3_t* Do);

void ksl_product_DDrzinvf(const ksl_SE3f_t* Di, const float dc[2],
                          ksl_SE3f_t* Do);

void ksl_product_DDt(const ksl_SE3_t* Di, const ksl_vec3_t* t, ksl_SE3_t* Do);

void ksl_product_DDtinv(const ksl_SE3_t* Di, const ksl_vec3_t* vi,
                        ksl_SE3_t* Do);

void ksl_product_DDtf(const ksl_SE3f_t* Di, const ksl_vec3f_t* vi,
                      ksl_SE3f_t* Do);

void ksl_product_DinvDt(const ksl_SE3_t* Di, const ksl_vec3_t* vi,
                        ksl_SE3_t* Do);

void ksl_product_DinvDtf(const ksl_SE3f_t* Di, const ksl_vec3f_t* vi,
                         ksl_SE3f_t* Do);

void ksl_product_DDtx(const ksl_SE3_t* Di, const double ti, ksl_SE3_t* Do);

void ksl_product_DDtxinv(const ksl_SE3_t* Di, const double ti, ksl_SE3_t* Do);

void ksl_product_DDtxinvf(const ksl_SE3f_t* Di, const float ti, ksl_SE3f_t* Do);

void ksl_product_DDty(const ksl_SE3_t* Di, const double ti, ksl_SE3_t* Do);

void ksl_product_DDtyf(const ksl_SE3f_t* Di, const float ti, ksl_SE3f_t* Do);

void ksl_product_DDtyinv(const ksl_SE3_t* Di, const double ti, ksl_SE3_t* Do);

void ksl_product_DDtyinvf(const ksl_SE3f_t* Di, const float ti, ksl_SE3f_t* Do);

void ksl_product_DDtz(const ksl_SE3_t* Di, const double ti, ksl_SE3_t* Do);

void ksl_product_DDtzf(const ksl_SE3f_t* Di, const float ti, ksl_SE3f_t* Do);

void ksl_product_DDtzinv(const ksl_SE3_t* Di, const double ti, ksl_SE3_t* Do);

void ksl_product_DDr(const ksl_SE3_t* Di, const ksl_mat3x3_t* Ri,
                     ksl_SE3_t* Do);

void ksl_product_DDrf(const ksl_SE3f_t* Di, const ksl_mat3x3f_t* Ri,
                      ksl_SE3f_t* Do);

void ksl_product_DDrinv(const ksl_SE3_t* Di, const ksl_mat3x3_t* Ri,
                        ksl_SE3_t* Do);

void ksl_product_DDrinvf(const ksl_SE3f_t* Di, const ksl_mat3x3f_t* Ri,
                         ksl_SE3f_t* Do);

void ksl_product_DD(const ksl_SE3_t* D1i, const ksl_SE3_t* D2i, ksl_SE3_t* Do);

void ksl_product_DDf(const ksl_SE3f_t* D1i, const ksl_SE3f_t* D2i,
                     ksl_SE3f_t* Do);

void ksl_product_DDinv(const ksl_SE3_t* D1i, const ksl_SE3_t* D2i,
                       ksl_SE3_t* Do);

void ksl_product_DDinvf(const ksl_SE3f_t* D1i, const ksl_SE3f_t* D2i,
                        ksl_SE3f_t* Do);

#endif
