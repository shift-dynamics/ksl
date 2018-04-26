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
} s2_inertia_t;

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
} s2_inertiaf_t;

s2_inertia_t* s2_inertia_alloc(int);

s2_inertiaf_t* s2_inertiaf_alloc(int);

void ksl_inertia_rotate(s2_inertia_t* inertia_i, ksl_mat3x3_t* r,
                        s2_inertia_t* inertia_o);

void ksl_inertia_rotate2(s2_inertia_t* inertia_i, ksl_mat3x3_t* r,
                         s2_inertia_t* inertia_o);

void ksl_inertia_transform(s2_inertia_t* inertia_i, ksl_SE3_t* d,
                           s2_inertia_t* inertia_o);

void ksl_inertiaf_rotate(s2_inertiaf_t* inertia_i, ksl_mat3x3f_t* r,
                         s2_inertiaf_t* inertia_o);

void ksl_inertiaf_rotate2(s2_inertiaf_t* inertia_i, ksl_mat3x3f_t* r,
                          s2_inertiaf_t* inertia_o);

void ksl_inertiaf_transform(s2_inertiaf_t* inertia_i, ksl_SE3f_t* d,
                            s2_inertiaf_t* inertia_o);

#endif
