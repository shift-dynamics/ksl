/**
@file
@author Kristopher Wehage, Roger Wehage
@brief Utilities to initialize and operate on vectors
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

#ifndef _KSL_VECTOR_H_
#define _KSL_VECTOR_H_

/*!
@brief 3 dimensional double precision vector
*/
typedef union ksl_vec3_t {
  double at[3];
  struct {
    double x;
    double y;
    double z;
  };
} ksl_vec3_t;

/*!
@brief 3 dimensional single precision vector
*/
typedef union ksl_vec3f_t {
  float at[3];
  struct {
    float x;
    float y;
    float z;
  };
} ksl_vec3f_t;

/*!
@brief 3 dimensional integer vector
*/
typedef union ksl_vec3i_t {
  int at[3];
  struct {
    int x;
    int y;
    int z;
  };
} ksl_vec3i_t;

/*!
@brief double precision 4x1 vector representing a 3x1 vector
with a homogeneous coordinate (w) appended.

Typically used for nonlinear transformations such as camera projections.
*/
typedef union ksl_vec4_t {
  double at[4];
  struct {
    union {
      ksl_vec3_t r;
      struct {
        double x;
        double y;
        double z;
      };
    };
    double w;
  };
} ksl_vec4_t;

/*!
@brief single precision 4x1 vector representing a 3x1 vector
with a homogeneous coordinate (w) appended.

Typically used for nonlinear transformations such as camera projections.
*/
typedef union ksl_vec4f_t {
  float at[4];
  struct {
    union {
      ksl_vec3f_t r;
      struct {
        float x;
        float y;
        float z;
      };
    };
    float w;
  };
} ksl_vec4f_t;

ksl_vec3_t* ksl_vec3_alloc(int);

ksl_vec3f_t* ksl_vec3f_alloc(int);

ksl_vec3i_t* ksl_vec3i_alloc(int);

double ksl_vec3_l2norm(const ksl_vec3_t* v);

float ksl_vec3f_l2norm(const ksl_vec3f_t* v);

void ksl_vec3_normalize(ksl_vec3_t* v);

void ksl_vec3f_normalize(ksl_vec3f_t* v);

void ksl_vec3_scale(double k, ksl_vec3_t* v);

void ksl_vec3f_scale(float k, ksl_vec3f_t* v);

void ksl_vec3_copy(const ksl_vec3_t* vi, ksl_vec3_t* vo);

void ksl_vec3f_copy(const ksl_vec3f_t* vi, ksl_vec3f_t* vo);

void ksl_vec3_swap(ksl_vec3_t* vi, ksl_vec3_t* vo);

void ksl_vec3f_swap(ksl_vec3f_t* vi, ksl_vec3f_t* vo);

void ksl_vec3_inverted(const ksl_vec3_t* vi, ksl_vec3_t* vo);

void ksl_vec3_invert(ksl_vec3_t* vi);

void ksl_vec3f_inverted(const ksl_vec3f_t* vi, ksl_vec3f_t* vo);

void ksl_vec3f_invert(ksl_vec3f_t* vi);

double ksl_dot_vv(const ksl_vec3_t* vi0, const ksl_vec3_t* vi1);

float ksl_dot_vvf(const ksl_vec3f_t* vi0, const ksl_vec3f_t* vi1);

void ksl_product_av(const double ki, const ksl_vec3_t* vi, ksl_vec3_t* vo);

void ksl_product_avinv(const double ki, const ksl_vec3_t* vi, ksl_vec3_t* vo);

void ksl_product_ainvv(const double ki, const ksl_vec3_t* vi, ksl_vec3_t* vo);

void ksl_product_avf(const float ki, const ksl_vec3f_t* vi, ksl_vec3f_t* vo);

void ksl_add_vv(const ksl_vec3_t* v1i, const ksl_vec3_t* v2i, ksl_vec3_t* vo);

void ksl_add_vvf(const ksl_vec3f_t* v1i, const ksl_vec3f_t* v2i,
                 ksl_vec3f_t* vo);

void ksl_subtract_vv(const ksl_vec3_t* v1i, const ksl_vec3_t* v2i,
                     ksl_vec3_t* vo);

void ksl_subtract_vvf(const ksl_vec3f_t* v1i, const ksl_vec3f_t* v2i,
                      ksl_vec3f_t* vo);

void ksl_axpy_vv(const double scalar, const ksl_vec3_t* v1x, ksl_vec3_t* v2y);

void ksl_axpy_vvf(const float scalar, const ksl_vec3f_t* v1x, ksl_vec3f_t* v2y);

void ksl_nxpy_vv(const ksl_vec3_t* v1x, ksl_vec3_t* v2y);

void ksl_nxpy_vvf(const ksl_vec3f_t* v1x, ksl_vec3f_t* v2y);

void ksl_xpy_vv(const ksl_vec3_t* v1x, ksl_vec3_t* v2y);

void ksl_xpy_vvf(const ksl_vec3f_t* v1x, ksl_vec3f_t* v2y);

void ksl_cross_vv(const ksl_vec3_t* v1i, const ksl_vec3_t* v2i, ksl_vec3_t* vo);

void ksl_cross_vvinv(const ksl_vec3_t* v1i, const ksl_vec3_t* v2i,
                     ksl_vec3_t* vo);

void ksl_cross_vvf(const ksl_vec3f_t* v1i, const ksl_vec3f_t* v2i,
                   ksl_vec3f_t* vo);

void ksl_cross_vvinvf(const ksl_vec3f_t* v1i, const ksl_vec3f_t* v2i,
                      ksl_vec3f_t* vo);

void ksl_add_vvx(const ksl_vec3_t* t1i, const double t2i, ksl_vec3_t* to);

void ksl_add_vvxf(const ksl_vec3f_t* t1i, const float t2i, ksl_vec3f_t* to);

void ksl_add_vvxinv(const ksl_vec3_t* t1i, const double t2i, ksl_vec3_t* to);

void ksl_add_vvxinvf(const ksl_vec3f_t* t1i, const float t2i, ksl_vec3f_t* to);

void ksl_add_vvy(const ksl_vec3_t* t1i, const double t2i, ksl_vec3_t* to);

void ksl_add_vvyf(const ksl_vec3f_t* t1i, const float t2i, ksl_vec3f_t* to);

void ksl_add_vvyinv(const ksl_vec3_t* t1i, const double t2i, ksl_vec3_t* to);

void ksl_add_vvyinvf(const ksl_vec3f_t* t1i, const float t2i, ksl_vec3f_t* to);

void ksl_add_vvz(const ksl_vec3_t* t1i, const double t2i, ksl_vec3_t* to);

void ksl_add_vvzf(const ksl_vec3f_t* t1i, const float t2i, ksl_vec3f_t* to);

void ksl_add_vvzinv(const ksl_vec3_t* t1i, const double t2i, ksl_vec3_t* to);

void ksl_add_vvzinvf(const ksl_vec3f_t* t1i, const float t2i, ksl_vec3f_t* to);

#endif
