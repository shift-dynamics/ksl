/**
@file
@author Kristopher Wehage, Roger Wehage
@brief Utilities to initialize and operate on coscrews
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

#ifndef _KSL_COSCREW_H_
#define _KSL_COSCREW_H_

#include "matrix.h"

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
  struct {
    double m0, m1, m2, m3, m4, m5, m6;
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
  struct {
    float m0, m1, m2, m3, m4, m5, m6;
  };
} ksl_coscrewf_t;

ksl_coscrew_t* ksl_coscrew_alloc(int);

ksl_coscrewf_t* ksl_coscrewf_alloc(int);

void ksl_cross_cc(const ksl_coscrew_t* s1i, const ksl_coscrew_t* s2i,
                  ksl_coscrew_t* so);

void ksl_cross_ccf(const ksl_coscrewf_t* s1i, const ksl_coscrewf_t* s2i,
                   ksl_coscrewf_t* so);

void ksl_product_CoAdtc(const ksl_vec3_t* ti, const ksl_coscrew_t* si,
                        ksl_coscrew_t* so);

void ksl_product_CoAdtcf(const ksl_vec3f_t* ti, const ksl_coscrewf_t* si,
                         ksl_coscrewf_t* so);

void ksl_product_CoAdtcinv(const ksl_vec3_t* ti, const ksl_coscrew_t* si,
                           ksl_coscrew_t* so);

void ksl_product_CoAdtcinvf(const ksl_vec3f_t* ti, const ksl_coscrewf_t* si,
                            ksl_coscrewf_t* so);

void ksl_product_CoAdc(const ksl_SE3_t* Di, const ksl_coscrew_t* si,
                       ksl_coscrew_t* so);

void ksl_product_CoAdcf(const ksl_SE3f_t* Di, const ksl_coscrewf_t* si,
                        ksl_coscrewf_t* so);

void ksl_product_CoAdinvc(const ksl_SE3_t* Di, const ksl_coscrew_t* si,
                          ksl_coscrew_t* co);

void ksl_product_CoAdinvcf(const ksl_SE3f_t* Di, const ksl_coscrewf_t* si,
                           ksl_coscrewf_t* so);

#endif
