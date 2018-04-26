/**
@file
@author Kristopher Wehage, Roger Wehage
@brief Utilities to initialize and operate on quaternions
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

#ifndef _KSL_SCREW_H_
#define _KSL_SCREW_H_

#include "matrix.h"
#include "vector.h"

/*!
@brief double precision screw consisting of a linear and angular vector pair in
configuration space
*/
typedef union ksl_screw_t {
  double at[6];
  struct {
    ksl_vec3_t lin; /*!< bound linear vector, e.g. linear velocity or
                            acceleration */
    ksl_vec3_t ang; /*!< free angular vector, e.g. angular velocity or
                             angular acceleration (\omega, or \dot{\omega}) */
  };
} ksl_screw_t;

/*!
@brief single precision screw consisting of a linear and angular vector
pair in configuration space
*/
typedef union ksl_screwf_t {
  float at[6];
  struct {
    ksl_vec3f_t lin; /*!< bound linear vector, e.g. linear velocity or
                            acceleration */
    ksl_vec3f_t ang; /*!< free angular vector, e.g. angular velocity or
                             angular acceleration (\omega, or \dot{\omega}) */
  };
} ksl_screwf_t;

/*!
@brief double precision coscrew (i.e. a linear operator on a screw), consisting
of a linear and angular vector pair in function space.
*/
typedef union ksl_coscrew_t {
  double at[6];
  struct {
    ksl_vec3_t lin; /*!< free linear vector, e.g. force or linear
                         momentum */
    ksl_vec3_t ang; /*!< bound angular vector, e.g. moment/torque
                         or angular momentum*/
  };
} ksl_coscrew_t;

/*!
@brief single precision coscrew (i.e. a linear operator on a screw), consisting
of a linear and angular vector pair in function space.
*/
typedef union ksl_coscrewf_t {
  float at[6];
  struct {
    ksl_vec3f_t lin; /*!< free linear vector, e.g. force or linear
                         momentum */
    ksl_vec3f_t ang; /*!< bound angular vector, e.g. moment/torque
                         or angular momentum*/
  };
} ksl_coscrewf_t;

ksl_screw_t* ksl_screw_alloc(int);

ksl_screwf_t* ksl_screwf_alloc(int);

double ksl_screw_l2norm(ksl_screw_t* v);

float ksl_screwf_l2norm(ksl_screwf_t* v);

double ksl_dot_cs(ksl_coscrew_t* vi0, ksl_screw_t* vi1);

float ksl_dot_csf(ksl_coscrewf_t* vi0, ksl_screwf_t* vi1);

void ksl_axpy_ss(double scalar, ksl_screw_t* v1x, ksl_screw_t* v2y);

void ksl_axpy_ssf(float scalar, ksl_screwf_t* v1x, ksl_screwf_t* v2y);

void ksl_screw_copy(ksl_screw_t* si, ksl_screw_t* so);

void ksl_screwf_copy(ksl_screwf_t* si, ksl_screwf_t* so);

void ksl_screw_invert(ksl_screw_t* si, ksl_screw_t* so);

void ksl_screwf_invert(ksl_screwf_t* si, ksl_screwf_t* so);

void ksl_product_sk(ksl_screw_t* si, const double* ki, ksl_screw_t* so);

void ksl_product_skf(ksl_screwf_t* si, const float* ki, ksl_screwf_t* so);

void ksl_add_ss(ksl_screw_t* s1i, ksl_screw_t* s2i, ksl_screw_t* so);

void ksl_add_ssf(ksl_screwf_t* s1i, ksl_screwf_t* s2i, ksl_screwf_t* so);

void ksl_addequal_ss(ksl_screw_t* s1i, ksl_screw_t* s2i);

void ksl_addequal_ssf(ksl_screwf_t* s1i, ksl_screwf_t* s2i);

void ksl_subtract_ss(ksl_screw_t* s1i, ksl_screw_t* s2i, ksl_screw_t* so);

void ksl_subtract_ssf(ksl_screwf_t* s1i, ksl_screwf_t* s2i, ksl_screwf_t* so);

void ksl_subtractequal_ss(ksl_screw_t* s1i, ksl_screw_t* s2i);

void ksl_subtractequal_ssf(ksl_screwf_t* s1i, ksl_screwf_t* s2i);

void ksl_add_sst(ksl_screw_t* si1, ksl_screw_t* si2, ksl_screw_t* so);

void ksl_add_sstf(ksl_screwf_t* si1, ksl_screwf_t* si2, ksl_screwf_t* so);

void ksl_htx(ksl_SE3_t* Di, ksl_screw_t* ho);

void ksl_htxf(ksl_SE3f_t* Di, ksl_screwf_t* ho);

void ksl_hty(ksl_SE3_t* Di, ksl_screw_t* ho);

void ksl_htyf(ksl_SE3f_t* Di, ksl_screwf_t* ho);

void ksl_htz(ksl_SE3_t* ri, ksl_screw_t* ho);

void ksl_htzf(ksl_SE3f_t* ri, ksl_screwf_t* ho);

void ksl_hrx(ksl_SE3_t* Di, ksl_screw_t* ho);

void ksl_hrxf(ksl_SE3f_t* Di, ksl_screwf_t* ho);

void ksl_hry(ksl_SE3_t* Di, ksl_screw_t* ho);

void ksl_hrz(ksl_SE3_t* Di, ksl_screw_t* ho);

void ksl_hrzf(ksl_SE3f_t* Di, ksl_screwf_t* ho);

void ksl_htxinv(ksl_SE3_t* Di, ksl_screw_t* ho);

void ksl_htxinvf(ksl_SE3f_t* Di, ksl_screwf_t* ho);

void ksl_htyinv(ksl_SE3_t* Di, ksl_screw_t* ho);

void ksl_htyinvf(ksl_SE3f_t* Di, ksl_screwf_t* ho);

void ksl_htzinv(ksl_SE3_t* Di, ksl_screw_t* ho);

void ksl_htzinvf(ksl_SE3f_t* Di, ksl_screwf_t* ho);

void ksl_hrxinv(ksl_SE3_t* Di, ksl_screw_t* ho);

void ksl_hrxinvf(ksl_SE3f_t* Di, ksl_screwf_t* ho);

void ksl_hryinv(ksl_SE3_t* Di, ksl_screw_t* ho);

void ksl_hryinvf(ksl_SE3f_t* Di, ksl_screwf_t* ho);

void ksl_hrzinv(ksl_SE3_t* Di, ksl_screw_t* ho);

void ksl_hrzinvf(ksl_SE3f_t* Di, ksl_screwf_t* ho);

void ksl_cross_ss(ksl_screw_t* s1i, ksl_screw_t* s2i, ksl_screw_t* so);

void ksl_cross_ssf(ksl_screwf_t* s1i, ksl_screwf_t* s2i, ksl_screwf_t* so);

void ksl_cross_sst(ksl_screw_t* s1i, ksl_screw_t* s2i, ksl_screw_t* so);

void ksl_cross_sstf(ksl_screwf_t* s1i, ksl_screwf_t* s2i, ksl_screwf_t* so);

void ksl_product_Adrs(ksl_mat3x3_t* ri, ksl_screw_t* si, ksl_screw_t* so);

void ksl_product_Adrsinv(ksl_mat3x3_t* ri, ksl_screw_t* si, ksl_screw_t* so);

void ksl_product_Adrsf(ksl_mat3x3f_t* ri, ksl_screwf_t* si, ksl_screwf_t* so);

void ksl_product_Adrsinvf(ksl_mat3x3f_t* ri, ksl_screwf_t* si,
                          ksl_screwf_t* so);

void ksl_product_Adrinvs(ksl_mat3x3_t* ri, ksl_screw_t* si, ksl_screw_t* so);

void ksl_product_Adrinvsf(ksl_mat3x3f_t* ri, ksl_screwf_t* si,
                          ksl_screwf_t* so);

void ksl_product_Adts(ksl_vec3_t* ti, ksl_screw_t* si, ksl_screw_t* so);

void ksl_product_Adtsf(ksl_vec3f_t* ti, ksl_screwf_t* si, ksl_screwf_t* so);

void ksl_product_Adtinvs(ksl_vec3_t* ti, ksl_screw_t* si, ksl_screw_t* so);

void ksl_product_Adtinvsf(ksl_vec3f_t* ti, ksl_screwf_t* si, ksl_screwf_t* so);

void ksl_product_Adtsinv(ksl_vec3_t* ti, ksl_screw_t* si, ksl_screw_t* so);

void ksl_product_Adtsinvf(ksl_vec3f_t* ti, ksl_screwf_t* si, ksl_screwf_t* so);

void ksl_product_Ads(ksl_SE3_t* Di, ksl_screw_t* si, ksl_screw_t* so);

void ksl_product_Adsinv(ksl_SE3_t* Di, ksl_screw_t* si, ksl_screw_t* so);

void ksl_product_Adsf(ksl_SE3f_t* Di, ksl_screwf_t* si, ksl_screwf_t* so);

void ksl_product_Adinvs(ksl_SE3_t* Di, ksl_screw_t* si, ksl_screw_t* so);

void ksl_product_Adinvsf(ksl_SE3f_t* Di, ksl_screwf_t* si, ksl_screwf_t* so);

void ksl_cross_cc(ksl_coscrew_t* s1i, ksl_coscrew_t* s2i, ksl_coscrew_t* so);

void ksl_cross_ccf(ksl_coscrewf_t* s1i, ksl_coscrewf_t* s2i,
                   ksl_coscrewf_t* so);

void ksl_product_CoAdtc(ksl_vec3_t* ti, ksl_coscrew_t* si, ksl_coscrew_t* so);

void ksl_product_CoAdtcf(ksl_vec3f_t* ti, ksl_coscrewf_t* si,
                         ksl_coscrewf_t* so);

void ksl_product_CoAdtcinv(ksl_vec3_t* ti, ksl_coscrew_t* si,
                           ksl_coscrew_t* so);

void ksl_product_CoAdtcinvf(ksl_vec3f_t* ti, ksl_coscrewf_t* si,
                            ksl_coscrewf_t* so);

void ksl_product_CoAdc(ksl_SE3_t* Di, ksl_coscrew_t* si, ksl_coscrew_t* so);

void ksl_product_CoAdcf(ksl_SE3f_t* Di, ksl_coscrewf_t* si, ksl_coscrewf_t* so);

void ksl_product_CoAdinvc(ksl_SE3_t* Di, ksl_coscrew_t* si, ksl_screw_t* so);

void ksl_product_CoAdinvcf(ksl_SE3f_t* Di, ksl_coscrewf_t* si,
                           ksl_coscrewf_t* so);

#endif
