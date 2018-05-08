/**
@file
@author Kristopher Wehage
@date 2016
@copyright Kristopher Wehage 2016
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

#ifndef _KSL_INERTIA_H_
#define _KSL_INERTIA_H_

#include "matrix.h"
#include "vector.h"

/*!
@brief double precision mass and inertia properties
*/
typedef union ksl_inertia_t {
  double at[10];
  struct {
    double m;      /*!< mass */
    ksl_vec3_t mt; /*!< mass times a vector, t, from reference
                        frame to body centroid */
    double Ixx;    /*!< Ixx centroidal inertia term, expressed in reference
                        frame coordinates */
    double Iyy;    /*!< Ixy centroidal inertia term, expressed in reference
                        frame coordinates */
    double Izz;    /*!< Izz centroidal inertia term, expressed in reference
                        frame coordinates */
    double Ixy;    /*!< Ixy centroidal inertia term, expressed in reference
                        frame coordinates */
    double Iyz;    /*!< Iyz centroidal inertia term, expressed in reference
                        frame coordinates */
    double Izx;    /*!< Izx centroidal inertia term, expressed in reference
                        frame coordinates */
  };
} ksl_inertia_t;

/*!
@brief single precision mass and inertia properties
*/
typedef union ksl_inertiaf_t {
  float at[10];
  struct {
    float m;        /*!< mass */
    ksl_vec3f_t mt; /*!< mass times a vector, t, from reference
                        frame to body centroid */
    float Ixx;      /*!< Ixx centroidal inertia term, expressed in reference
                         frame coordinates */
    float Iyy;      /*!< Ixy centroidal inertia term, expressed in reference
                         frame coordinates */
    float Izz;      /*!< Izz centroidal inertia term, expressed in reference
                         frame coordinates */
    float Ixy;      /*!< Ixy centroidal inertia term, expressed in reference
                         frame coordinates */
    float Iyz;      /*!< Iyz centroidal inertia term, expressed in reference
                         frame coordinates */
    float Izx;      /*!< Izx centroidal inertia term, expressed in reference
                         frame coordinates */
  };
} ksl_inertiaf_t;

ksl_inertia_t* ksl_inertia_alloc(int);

ksl_inertiaf_t* ksl_inertiaf_alloc(int);

void ksl_inertia_rotated(const ksl_inertia_t* inertia_i, const ksl_mat3x3_t* r,
                         ksl_inertia_t* inertia_o);

void ksl_inertiaf_rotated(const ksl_inertiaf_t* inertia_i,
                          const ksl_mat3x3f_t* r, ksl_inertiaf_t* inertia_o);

void ksl_inertia_rotate(ksl_inertia_t* inertia_i, const ksl_mat3x3_t* r);

void ksl_inertiaf_rotate(ksl_inertiaf_t* inertia_i, const ksl_mat3x3f_t* r);

void ksl_inertia_translated(const ksl_inertia_t* inertia_i, const ksl_vec3_t* r,
                            ksl_inertia_t* inertia_o);

void ksl_inertiaf_translated(const ksl_inertiaf_t* inertia_i,
                             const ksl_vec3f_t* r, ksl_inertiaf_t* inertia_o);

void ksl_inertia_translate(ksl_inertia_t* inertia_i, const ksl_vec3_t* r);

void ksl_inertiaf_translate(ksl_inertiaf_t* inertia_i, const ksl_vec3f_t* r);

void ksl_inertia_transformed(const ksl_inertia_t* inertia_i, const ksl_SE3_t* d,
                             ksl_inertia_t* inertia_o);

void ksl_inertiaf_transformed(const ksl_inertiaf_t* inertia_i,
                              const ksl_SE3f_t* d, ksl_inertiaf_t* inertia_o);

void ksl_inertia_merge(ksl_inertia_t* inertia_i, ksl_vec3_t* t_ic_i,
                       ksl_inertia_t* inertia_j, const ksl_vec3_t* t_jc_j,
                       const ksl_SE3_t* D_ij);

void ksl_inertiaf_merge(ksl_inertiaf_t* inertia_i, ksl_vec3f_t* t_ic_i,
                        ksl_inertiaf_t* inertia_j, const ksl_vec3f_t* t_jc_j,
                        const ksl_SE3f_t* D_ij);

int ksl_inertia_factor(ksl_inertia_t*);

#endif
