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

void ksl_SE3_toMat4x4(ksl_SE3_t* d, ksl_mat4x4_t* m);

void ksl_SE3f_toMat4x4f(ksl_SE3f_t* d, ksl_mat4x4f_t* m);

void ksl_SE3_toMat4x4f(ksl_SE3_t* d, ksl_mat4x4f_t* m);

void ksl_dc(double* thetai, double dc[2]);

void ksl_SE3_setIdentity(ksl_SE3_t* d);

void ksl_mat3x3_setIdentity(ksl_mat3x3_t* r);

void ksl_mat3x3_set(ksl_mat3x3_t* R, int row, int column, double value);

void ksl_mat4x4_set(ksl_mat4x4_t* R, int row, int column, double value);

void ksl_SE3_set(ksl_SE3_t* D, int row, int column, double value);

void ksl_mat3x3_setFromVectors(ksl_mat3x3_t* R, ksl_vec3_t* x, ksl_vec3_t* y,
                               ksl_vec3_t* z);

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

void ksl_mat3x3_transpose(ksl_mat3x3_t* ri, ksl_mat3x3_t* ro);

void ksl_mat3x3f_transpose(ksl_mat3x3f_t* ri, ksl_mat3x3f_t* ro);

void ksl_product_rv(const ksl_mat3x3_t* ri, const ksl_vec3_t* vi, ksl_vec3_t* vo);

void ksl_product_rvf(const ksl_mat3x3f_t* ri, const ksl_vec3f_t* vi, ksl_vec3f_t* vo);

void ksl_product_rvinv(const ksl_mat3x3_t* ri, const ksl_vec3_t* vi, ksl_vec3_t* vo);

void ksl_product_rvinvf(const ksl_mat3x3f_t* ri, const ksl_vec3f_t* vi, ksl_vec3f_t* vo);

void ksl_product_rinvv(const ksl_mat3x3_t* ri, const ksl_vec3_t* vi, ksl_vec3_t* vo);

void ksl_product_rinvvf(const ksl_mat3x3f_t* ri, const ksl_vec3f_t* vi, ksl_vec3f_t* vo);

void ksl_product_rinvvinv(const ksl_mat3x3_t* ri, const ksl_vec3_t* vi, ksl_vec3_t* vo);

void ksl_product_rinvvinvf(const ksl_mat3x3f_t* ri, const ksl_vec3f_t* vi, ksl_vec3f_t* vo);

void ksl_product_rrx(const ksl_mat3x3_t* ri, const double dc[2], ksl_mat3x3_t* ro);

void ksl_product_rrxf(const ksl_mat3x3f_t* ri, const float dc[2], ksl_mat3x3f_t* ro);

void ksl_product_rrxinv(const ksl_mat3x3_t* ri, const double dc[2], ksl_mat3x3_t* ro);

void ksl_product_rrxinvf(const ksl_mat3x3f_t* ri, const float dc[2], ksl_mat3x3f_t* ro);

void ksl_product_rry(const ksl_mat3x3_t* ri, const double dc[2], ksl_mat3x3_t* ro);

void ksl_product_rryf(const ksl_mat3x3f_t* ri, const float dc[2], ksl_mat3x3f_t* ro);

void ksl_product_rryinv(const ksl_mat3x3_t* ri, const double dc[2], ksl_mat3x3_t* ro);

void ksl_product_rryinvf(const ksl_mat3x3f_t* ri, const float dc[2], ksl_mat3x3f_t* ro);

void ksl_product_rrz(const ksl_mat3x3_t* ri, const double dc[2], ksl_mat3x3_t* ro);

void ksl_product_rrzf(const ksl_mat3x3f_t* ri, const float dc[2], ksl_mat3x3f_t* ro);

void ksl_product_rrzinv(const ksl_mat3x3_t* ri, const double dc[2], ksl_mat3x3_t* ro);

void ksl_product_rrzinvf(const ksl_mat3x3f_t* ri, const float dc[2], ksl_mat3x3f_t* ro);

void ksl_product_rr(const ksl_mat3x3_t* r1i, const ksl_mat3x3_t* r2i, ksl_mat3x3_t* ro);

void ksl_product_rrf(const ksl_mat3x3f_t* r1i, const ksl_mat3x3f_t* r2i, ksl_mat3x3f_t* ro);

void ksl_product_rrinv(const ksl_mat3x3_t* r1i, const ksl_mat3x3_t* r2i, ksl_mat3x3_t* ro);

void ksl_product_rrinvf(const ksl_mat3x3f_t* r1i, const ksl_mat3x3f_t* r2i,
                        ksl_mat3x3f_t* ro);

void ksl_product_rinvr(const ksl_mat3x3_t* r1i, const ksl_mat3x3_t* r2i, ksl_mat3x3_t* ro);

void ksl_product_rinvrf(const ksl_mat3x3f_t* r1i, const ksl_mat3x3f_t* r2i,
                        ksl_mat3x3f_t* ro);

void ksl_product_rtx(const ksl_mat3x3_t* ri, const double ti, ksl_vec3_t* to);

void ksl_product_rtxf(const ksl_mat3x3f_t* ri, const float ti, ksl_vec3f_t* to);

void ksl_product_rtxinv(const ksl_mat3x3_t* ri, const double ti, ksl_vec3_t* to);

void ksl_product_rtxinvf(const ksl_mat3x3f_t* ri, const float ti, ksl_vec3f_t* to);

void ksl_product_rty(const ksl_mat3x3_t* ri, const double ti, ksl_vec3_t* to);

void ksl_product_rtyf(const ksl_mat3x3f_t* ri, const float ti, ksl_vec3f_t* to);

void ksl_product_rtyinv(const ksl_mat3x3_t* ri, const double ti, ksl_vec3_t* to);

void ksl_product_rtyinvf(const ksl_mat3x3f_t* ri, const float ti, ksl_vec3f_t* to);

void ksl_product_rtz(const ksl_mat3x3_t* ri, const double ti, ksl_vec3_t* to);

void ksl_product_rtzf(const ksl_mat3x3f_t* ri, const float ti, ksl_vec3f_t* to);

void ksl_product_rtzinv(const ksl_mat3x3_t* ri, const double ti, ksl_vec3_t* to);

void ksl_product_rtzinvf(const ksl_mat3x3f_t* ri, const float ti, ksl_vec3f_t* to);

void ksl_SE3_inverted(const ksl_SE3_t* Di, ksl_SE3_t* Do);

void ksl_SE3f_inverted(const ksl_SE3f_t* Di, ksl_SE3f_t* Do);

void ksl_SE3_copy(const ksl_SE3_t* Di, ksl_SE3_t* Do);

void ksl_SE3f_copy(const ksl_SE3f_t* Di, ksl_SE3f_t* Do);

void ksl_product_drx(const ksl_SE3_t* Di, const double dc[2], ksl_SE3_t* Do);

void ksl_product_drxf(const ksl_SE3f_t* Di, const float dc[2], ksl_SE3f_t* Do);

void ksl_product_drxinv(const ksl_SE3_t* Di, const double dc[2], ksl_SE3_t* Do);

void ksl_product_drxinvf(const ksl_SE3f_t* Di, const float dc[2], ksl_SE3f_t* Do);

void ksl_product_dry(const ksl_SE3_t* Di, const double dc[2], ksl_SE3_t* Do);

void ksl_product_dryf(const ksl_SE3f_t* Di, const float dc[2], ksl_SE3f_t* Do);

void ksl_product_dryinv(const ksl_SE3_t* Di, const double dc[2], ksl_SE3_t* Do);

void ksl_product_dryinvf(const ksl_SE3f_t* Di, const float dc[2], ksl_SE3f_t* Do);

void ksl_product_drz(const ksl_SE3_t* Di, const double dc[2], ksl_SE3_t* Do);

void ksl_product_drzf(const ksl_SE3f_t* Di, const float dc[2], ksl_SE3f_t* Do);

void ksl_product_drzinv(const ksl_SE3_t* Di, const double dc[2], ksl_SE3_t* Do);

void ksl_product_drzinvf(const ksl_SE3f_t* Di, const float dc[2], ksl_SE3f_t* Do);

void ksl_product_dt(const ksl_SE3_t* Di, const ksl_vec3_t* vi, ksl_SE3_t* Do);

void ksl_product_dtinv(const ksl_SE3_t* Di, const ksl_vec3_t* vi, ksl_SE3_t* Do);

void ksl_product_dv(const ksl_SE3_t* Di, const ksl_vec3_t* vi, ksl_vec3_t* vo);

void ksl_product_dinvv(const ksl_SE3_t* Di, const ksl_vec3_t* vi, ksl_vec3_t* vo);

void ksl_product_dtf(const ksl_SE3f_t* Di, const ksl_vec3f_t* vi, ksl_SE3f_t* Do);

void ksl_product_dinvt(const ksl_SE3_t* Di, const ksl_vec3_t* vi, ksl_SE3_t* Do);

void ksl_product_dinvtf(const ksl_SE3f_t* Di, const ksl_vec3f_t* vi, ksl_SE3f_t* Do);

void ksl_product_dtx(const ksl_SE3_t* Di, const double ti, ksl_SE3_t* Do);

void ksl_product_dtxinv(const ksl_SE3_t* Di, const double ti, ksl_SE3_t* Do);

void ksl_product_dtxinvf(const ksl_SE3f_t* Di, const float ti, ksl_SE3f_t* Do);

void ksl_product_dty(const ksl_SE3_t* Di, const double ti, ksl_SE3_t* Do);

void ksl_product_dtyf(const ksl_SE3f_t* Di, const float ti, ksl_SE3f_t* Do);

void ksl_product_dtyinv(const ksl_SE3_t* Di, const double ti, ksl_SE3_t* Do);

void ksl_product_dtyinvf(const ksl_SE3f_t* Di, const float ti, ksl_SE3f_t* Do);

void ksl_product_dtz(const ksl_SE3_t* Di, const double ti, ksl_SE3_t* Do);

void ksl_product_dtzf(const ksl_SE3f_t* Di, const float ti, ksl_SE3f_t* Do);

void ksl_product_dtzinv(const ksl_SE3_t* Di, const double ti, ksl_SE3_t* Do);

void ksl_product_dr(const ksl_SE3_t* Di, const ksl_mat3x3_t* Ri, ksl_SE3_t* Do);

void ksl_product_drf(const ksl_SE3f_t* Di, const ksl_mat3x3f_t* Ri, ksl_SE3f_t* Do);

void ksl_product_drinv(const ksl_SE3_t* Di, const ksl_mat3x3_t* Ri, ksl_SE3_t* Do);

void ksl_product_drinvf(const ksl_SE3f_t* Di, const ksl_mat3x3f_t* Ri, ksl_SE3f_t* Do);

void ksl_product_dd(const ksl_SE3_t* D1i, const ksl_SE3_t* D2i, ksl_SE3_t* Do);

void ksl_product_ddf(const ksl_SE3f_t* D1i, const ksl_SE3f_t* D2i, ksl_SE3f_t* Do);

void ksl_product_ddinv(const ksl_SE3_t* D1i, const ksl_SE3_t* D2i, ksl_SE3_t* Do);

void ksl_product_ddinvf(const ksl_SE3f_t* D1i, const ksl_SE3f_t* D2i, ksl_SE3f_t* Do);

void ksl_mat3x3_getEulerAngles(const ksl_mat3x3_t* rin, ksl_vec3_t* angles,
                               const ksl_axis_enum_t axisType);

void ksl_mat3x3_setFromEulerAngles(ksl_mat3x3_t*, const ksl_vec3_t*, const ksl_axis_enum_t axisType);

double ksl_mat3x3_getScalar(const ksl_mat3x3_t* ri);

float ksl_mat3x3f_getScalar(const ksl_mat3x3f_t* ri);

void ksl_mat4x4_getTranslation(const ksl_mat4x4_t* Mi, ksl_vec3_t* to);

void ksl_mat4x4f_getTranslation(const ksl_mat4x4f_t* Mi, ksl_vec3f_t* to);

void ksl_mat4x4f_get(const ksl_mat4x4f_t* Mi, int row, int column);

double ksl_mat3x3_determinant(const ksl_mat3x3_t*);

#endif
