/**
@file
@author Kristopher Wehage, Roger Wehage
@brief Utilities to initialize and operate on screws
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

typedef union ksl_coscrew_t ksl_coscrew_t;
typedef union ksl_coscrewf_t ksl_coscrewf_t;

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
  struct {
    double m0, m1, m2, m3, m4, m5, m6;
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
  struct {
    float m0, m1, m2, m3, m4, m5, m6;
  };
} ksl_screwf_t;

ksl_screw_t ksl_screw(const double m0, const double m1, const double m2,
                      const double m3, const double m4, const double m5);

ksl_screwf_t ksl_screwf(const float m0, const float m1, const float m2,
                        const float m3, const float m4, const float m5);

ksl_screw_t* ksl_screw_alloc(int);

ksl_screwf_t* ksl_screwf_alloc(int);

double ksl_screw_norm(const ksl_screw_t* v);

float ksl_screwf_norm(const ksl_screwf_t* v);

double ksl_dot_cs(const ksl_coscrew_t*, const ksl_screw_t*);

float ksl_dot_csf(const ksl_coscrewf_t*, const ksl_screwf_t*);

void ks_screw_scale(ksl_screw_t, const double);

void ksl_screw_copy(const ksl_screw_t* si, ksl_screw_t* so);

void ksl_screwf_copy(const ksl_screwf_t* si, ksl_screwf_t* so);

void ksl_screw_invert(ksl_screw_t* si);

void ksl_screwf_invert(ksl_screwf_t* si);

void ksl_screw_inverted(const ksl_screw_t* si, ksl_screw_t* so);

void ksl_screwf_inverted(const ksl_screwf_t* si, ksl_screwf_t* so);

void ksl_axpy_ss(const double, const ksl_screw_t*, ksl_screw_t*);

void ksl_axpy_ssf(const float, const ksl_screwf_t*, ksl_screwf_t*);

void ksl_xpy_ss(const ksl_screw_t*, ksl_screw_t*);

void ksl_xpy_ssf(const ksl_screwf_t*, ksl_screwf_t*);

void ksl_nxpy_ss(const ksl_screw_t*, ksl_screw_t*);

void ksl_nxpy_ssf(const ksl_screwf_t*, ksl_screwf_t*);

void ksl_product_sa(const ksl_screw_t* si, const double ki, ksl_screw_t* so);

void ksl_product_saf(const ksl_screwf_t* si, const float ki, ksl_screwf_t* so);

void ksl_add_ss(const ksl_screw_t* s1i, const ksl_screw_t* s2i,
                ksl_screw_t* so);

void ksl_add_ssf(const ksl_screwf_t* s1i, const ksl_screwf_t* s2i,
                 ksl_screwf_t* so);

void ksl_subtract_ss(const ksl_screw_t* s1i, const ksl_screw_t* s2i,
                     ksl_screw_t* so);

void ksl_subtract_ssf(const ksl_screwf_t* s1i, const ksl_screwf_t* s2i,
                      ksl_screwf_t* so);

void ksl_add_sst(const ksl_screw_t* si1, const ksl_screw_t* si2,
                 ksl_screw_t* so);

void ksl_add_sstf(const ksl_screwf_t* si1, const ksl_screwf_t* si2,
                  ksl_screwf_t* so);

void ksl_htx(const ksl_SE3_t* Di, ksl_screw_t* ho);

void ksl_htxf(const ksl_SE3f_t* Di, ksl_screwf_t* ho);

void ksl_hty(const ksl_SE3_t* Di, ksl_screw_t* ho);

void ksl_htyf(const ksl_SE3f_t* Di, ksl_screwf_t* ho);

void ksl_htz(const ksl_SE3_t* ri, ksl_screw_t* ho);

void ksl_htzf(const ksl_SE3f_t* ri, ksl_screwf_t* ho);

void ksl_hrx(const ksl_SE3_t* Di, ksl_screw_t* ho);

void ksl_hrxf(const ksl_SE3f_t* Di, ksl_screwf_t* ho);

void ksl_hry(const ksl_SE3_t* Di, ksl_screw_t* ho);

void ksl_hrz(const ksl_SE3_t* Di, ksl_screw_t* ho);

void ksl_hrzf(const ksl_SE3f_t* Di, ksl_screwf_t* ho);

void ksl_htxinv(const ksl_SE3_t* Di, ksl_screw_t* ho);

void ksl_htxinvf(const ksl_SE3f_t* Di, ksl_screwf_t* ho);

void ksl_htyinv(const ksl_SE3_t* Di, ksl_screw_t* ho);

void ksl_htyinvf(const ksl_SE3f_t* Di, ksl_screwf_t* ho);

void ksl_htzinv(const ksl_SE3_t* Di, ksl_screw_t* ho);

void ksl_htzinvf(const ksl_SE3f_t* Di, ksl_screwf_t* ho);

void ksl_hrxinv(const ksl_SE3_t* Di, ksl_screw_t* ho);

void ksl_hrxinvf(const ksl_SE3f_t* Di, ksl_screwf_t* ho);

void ksl_hryinv(const ksl_SE3_t* Di, ksl_screw_t* ho);

void ksl_hryinvf(const ksl_SE3f_t* Di, ksl_screwf_t* ho);

void ksl_hrzinv(const ksl_SE3_t* Di, ksl_screw_t* ho);

void ksl_hrzinvf(const ksl_SE3f_t* Di, ksl_screwf_t* ho);

void ksl_cross_ss(const ksl_screw_t* s1i, const ksl_screw_t* s2i,
                  ksl_screw_t* so);

void ksl_cross_ssf(const ksl_screwf_t* s1i, const ksl_screwf_t* s2i,
                   ksl_screwf_t* so);

void ksl_cross_sst(const ksl_screw_t* s1i, const ksl_screw_t* s2i,
                   ksl_screw_t* so);

void ksl_cross_sstf(const ksl_screwf_t* s1i, const ksl_screwf_t* s2i,
                    ksl_screwf_t* so);

void ksl_product_Adrs(const ksl_mat3x3_t* ri, const ksl_screw_t* si,
                      ksl_screw_t* so);

void ksl_product_Adrsinv(const ksl_mat3x3_t* ri, const ksl_screw_t* si,
                         ksl_screw_t* so);

void ksl_product_Adrsf(const ksl_mat3x3f_t* ri, const ksl_screwf_t* si,
                       ksl_screwf_t* so);

void ksl_product_Adrsinvf(const ksl_mat3x3f_t* ri, const ksl_screwf_t* si,
                          ksl_screwf_t* so);

void ksl_product_Adrinvs(const ksl_mat3x3_t* ri, const ksl_screw_t* si,
                         ksl_screw_t* so);

void ksl_product_Adrinvsf(const ksl_mat3x3f_t* ri, const ksl_screwf_t* si,
                          ksl_screwf_t* so);

void ksl_product_Adts(const ksl_vec3_t* ti, const ksl_screw_t* si,
                      ksl_screw_t* so);

void ksl_product_Adtsf(const ksl_vec3f_t* ti, const ksl_screwf_t* si,
                       ksl_screwf_t* so);

void ksl_product_Adtinvs(const ksl_vec3_t* ti, const ksl_screw_t* si,
                         ksl_screw_t* so);

void ksl_product_Adtinvsf(const ksl_vec3f_t* ti, const ksl_screwf_t* si,
                          ksl_screwf_t* so);

void ksl_product_Adtsinv(const ksl_vec3_t* ti, const ksl_screw_t* si,
                         ksl_screw_t* so);

void ksl_product_Adtsinvf(const ksl_vec3f_t* ti, const ksl_screwf_t* si,
                          ksl_screwf_t* so);

void ksl_product_Ads(const ksl_SE3_t* Di, const ksl_screw_t* si,
                     ksl_screw_t* so);

void ksl_product_Adsinv(const ksl_SE3_t* Di, const ksl_screw_t* si,
                        ksl_screw_t* so);

void ksl_product_Adsf(const ksl_SE3f_t* Di, const ksl_screwf_t* si,
                      ksl_screwf_t* so);

void ksl_product_Adinvs(const ksl_SE3_t* Di, const ksl_screw_t* si,
                        ksl_screw_t* so);

void ksl_product_Adinvsf(const ksl_SE3f_t* Di, const ksl_screwf_t* si,
                         ksl_screwf_t* so);

#endif
