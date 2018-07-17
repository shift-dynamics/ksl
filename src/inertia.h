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
  struct {
    double at[10];
  }; /*!< anonymous union allows accessing by index */
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
  };               /*!< anonymous union allows accessing by field names */
  struct {
    double mass;   /*!< mass */
    ksl_vec3_t mr; /*!< mass times a vector, r, from reference
                        frame to body centroid */
    double _Ixx;   /*!< Ixx centroidal inertia term, expressed in reference
                       frame coordinates */
    double _Iyy;   /*!< Ixy centroidal inertia term, expressed in reference
                       frame coordinates */
    double _Izz;   /*!< Izz centroidal inertia term, expressed in reference
                       frame coordinates */
    double Iyx;    /*!< Ixy centroidal inertia term, expressed in reference
                        frame coordinates */
    double Izy;    /*!< Iyz centroidal inertia term, expressed in reference
                        frame coordinates */
    double Ixz;    /*!< Izx centroidal inertia term, expressed in reference
                        frame coordinates */
  }; /*!< anonymous union allows accessing by alternative field names
      */
} ksl_inertia_t;

/*!
@brief single precision mass and inertia properties
*/
typedef union ksl_inertiaf_t {
  struct {
    float at[10];
  }; /*!< anonymous union allows accessing by index */
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
  }; /*!< anonymous union allows accessing inertial quantities by field name */
  struct {
    float mass;     /*!< mass */
    ksl_vec3f_t mr; /*!< mass times a vector, r, from reference
                        frame to body centroid */
    float _Ixx;     /*!< Ixx centroidal inertia term, expressed in reference
                         frame coordinates */
    float _Iyy;     /*!< Ixy centroidal inertia term, expressed in reference
                         frame coordinates */
    float _Izz;     /*!< Izz centroidal inertia term, expressed in reference
                         frame coordinates */
    float Iyx;      /*!< Ixy centroidal inertia term, expressed in reference
                          frame coordinates */
    float Izy;      /*!< Iyz centroidal inertia term, expressed in reference
                          frame coordinates */
    float Ixz;      /*!< Izx centroidal inertia term, expressed in reference
                          frame coordinates */
  }; /*!< anonymous union allows accessing inertial quantities by alternative
        field name */
} ksl_inertiaf_t;

/*!
@brief double precision spatial inertia matrix constructor
@param m [in] mass
@param t [in] vector from reference frame to body centroid
@param Ixx [in] centroidal inertia term, expressed in reference frame
coordinates
@param Iyy [in] centroidal inertia term, expressed in reference frame
coordinates
@param Izz [in] centroidal inertia term, expressed in reference frame
coordinates
@param Ixy [in] centroidal inertia term, expressed in reference frame
coordinates
@param Iyz [in] centroidal inertia term, expressed in reference frame
coordinates
@param Izx [in] centroidal inertia term, expressed in reference frame
coordinates
*/
ksl_inertia_t ksl_inertia(const double m, const ksl_vec3_t t, const double Ixx,
                          const double Iyy, const double Izz, const double Ixy,
                          const double Iyz, const double Izx);

/*!
@brief single precision spatial inertia matrix constructor
@param m [in] mass
@param t [in] vector from reference frame to body centroid
@param Ixx [in] centroidal inertia term, expressed in reference frame
coordinates
@param Iyy [in] centroidal inertia term, expressed in reference frame
coordinates
@param Izz [in] centroidal inertia term, expressed in reference frame
coordinates
@param Ixy [in] centroidal inertia term, expressed in reference frame
coordinates
@param Iyz [in] centroidal inertia term, expressed in reference frame
coordinates
@param Izx [in] centroidal inertia term, expressed in reference frame
coordinates
*/
ksl_inertiaf_t ksl_inertiaf(const float m, const ksl_vec3f_t t, const float Ixx,
                            const float Iyy, const float Izz, const float Ixy,
                            const float Iyz, const float Izx);

/*!
@brief Allocate n ksl_inertia_t datastructures on the heap
*/
ksl_inertia_t* ksl_inertia_alloc(int n);

/*!
@brief Allocate n ksl_inertiaf_t datastructures on the heap
*/
ksl_inertiaf_t* ksl_inertiaf_alloc(int n);

/*!
@brief Rotate a double precision centroidal inertia matrix

  \f$ [Ad]^*_{(\Phi(R^{fc}))} M_{cc} [Ad]_{(\Phi((R^{fc})^{-1}))} \rightarrow
M_{ff}\f$

@param inertia_i [in] input inertia matrix
@param r [in] orthonormal rotation matrix
@param inertia_o [out] output inertia matrix
*/
void ksl_inertia_rotated(const ksl_inertia_t* inertia_i, const ksl_mat3x3_t* r,
                         ksl_inertia_t* inertia_o);

/*!
@brief Rotate a single precision centroidal inertia matrix

\f$ [Ad]^*_{(\Phi(R^{fc}))} M_{cc} [Ad]_{(\Phi((R^{fc})^{-1}))} \rightarrow
M_{ff}\f$

@param inertia_i [in] input inertia matrix
@param r [in] orthonormal rotation matrix
@param inertia_o [out] output inertia matrix
*/
void ksl_inertiaf_rotated(const ksl_inertiaf_t* inertia_i,
                          const ksl_mat3x3f_t* r, ksl_inertiaf_t* inertia_o);

/*!
@brief Rotate a double precision centroidal inertia matrix in place

\f$ [Ad]^*_{(\Phi(R^{fc}))} M_{cc} [Ad]_{(\Phi((R^{fc})^{-1}))} \rightarrow
M_{ff}\f$

@param inertia_i [in/out] input inertia matrix
@param r [in] orthonormal rotation matrix
*/
void ksl_inertia_rotate(ksl_inertia_t* inertia_i, const ksl_mat3x3_t* r);

/*!
@brief Rotate a single precision centroidal inertia matrix in place

\f$ [Ad]^*_{(\Phi(R^{fc}))} M_{cc} [Ad]_{(\Phi((R^{fc})^{-1}))} \rightarrow
M_{ff}\f$

@param inertia_i [in/out] input inertia matrix
@param r [in] orthonormal rotation matrix
*/
void ksl_inertiaf_rotate(ksl_inertiaf_t* inertia_i, const ksl_mat3x3f_t* r);

/*!
@brief translate a double precision centroidal inertia matrix

  \f$ [Ad]^*_{(\Phi(\underline{t}_{fc}^f))} M_{cc}
[Ad]_{(\Phi((\underline{t}_{fc}^f)^{-1}))} \rightarrow M_{ff}\f$

@param inertia_i [in] input inertia matrix
@param t [in] translation vector
@param inertia_o [out] output inertia matrix
*/
void ksl_inertia_translated(const ksl_inertia_t* inertia_i, const ksl_vec3_t* t,
                            ksl_inertia_t* inertia_o);

/*!
@brief translate a single precision centroidal inertia matrix

\f$ [Ad]^*_{(\Phi(\underline{t}_{fc}^f))} M_{cc}
[Ad]_{(\Phi((\underline{t}_{fc}^f)^{-1}))} \rightarrow M_{ff}\f$

@param inertia_i [in] input inertia matrix
@param t [in] translation vector
@param inertia_o [out] output inertia matrix
*/
void ksl_inertiaf_translated(const ksl_inertiaf_t* inertia_i,
                             const ksl_vec3f_t* t, ksl_inertiaf_t* inertia_o);

/*!
@brief translate a double precision centroidal inertia matrix in place

\f$ [Ad]^*_{(\Phi(\underline{t}_{fc}^f))} M_{cc}
[Ad]_{(\Phi((\underline{t}_{fc}^f)^{-1}))} \rightarrow M_{ff}\f$

@param inertia_i [in/out] input inertia matrix
@param t [in] translation vector
*/
void ksl_inertia_translate(ksl_inertia_t* inertia_i, const ksl_vec3_t* t);

/*!
@brief translate a single precision centroidal inertia matrix in place

\f$ [Ad]^*_{(\Phi(\underline{t}_{fc}^f))} M_{cc}
[Ad]_{(\Phi((\underline{t}_{fc}^f)^{-1}))} \rightarrow M_{ff}\f$

@param inertia_i [in/out] input inertia matrix
@param t [in] translation vector
*/
void ksl_inertiaf_translate(ksl_inertiaf_t* inertia_i, const ksl_vec3f_t* t);

/*!
@brief spatial transform a double precision centroidal inertia matrix

  \f$ [Ad]_{(\Phi_{fc})}^* M_{cc} [Ad]_{(\Phi_{fc}^{-1})} \rightarrow M_{ff}\f$

@param inertia_i [in] input inertia matrix
@param d [in] SE3 transformation matrix
@param inertia_o [out] output inertia matrix
*/
void ksl_inertia_transformed(const ksl_inertia_t* inertia_i, const ksl_SE3_t* d,
                             ksl_inertia_t* inertia_o);

/*!
@brief spatial transform a single precision centroidal inertia matrix

  \f$ [Ad]_{(\Phi_{fc})}^* M_{cc} [Ad]_{(\Phi_{fc}^{-1})} \rightarrow M_{ff}\f$

@param inertia_i [in] input inertia matrix
@param d [in] SE3 transformation matrix
@param inertia_o [out] output inertia matrix
*/
void ksl_inertiaf_transformed(const ksl_inertiaf_t* inertia_i,
                              const ksl_SE3f_t* d, ksl_inertiaf_t* inertia_o);

/*!
@brief Perform a spatial transformation of a double precision centroidal inertia
matrix in place.

  \f$ [Ad]_{(\Phi_{fc})}^* M_{cc} [Ad]_{(\Phi_{fc}^{-1})} \rightarrow M_{ff}\f$

@param inertia_i [in/out] inertia matrix to transform
@param d [in] SE3 transformation
*/
void ksl_inertia_transform(ksl_inertia_t* inertia_i, const ksl_SE3_t* d);

/*!
@brief Perform a spatial transformation of a single precision centroidal inertia
matrix in place.

  \f$ [Ad]_{(\Phi_{fc})}^* M_{cc} [Ad]_{(\Phi_{fc}^{-1})} \rightarrow M_{ff}\f$

@param inertia_i [in/out] inertia matrix to transform
@param d [in] SE3 transformation
*/
void ksl_inertiaf_transform(ksl_inertiaf_t* inertia_i, const ksl_SE3f_t* d);

/*!
@brief merge double precision child inertia (j) with parent inertia (i)
@param parent inertia [in/out] parent inertia to be merged
@param t_ic_i [in/out] vector from parent body reference frame i to body center
of mass frame c, expressed in body frame i
@param child inertia [in]
@param t_jc_j [in] vector from child body reference frame j to body center of
mass frame c, expressed in body frame j
@param D_ij [in] transformation from parent reference frame i to child reference
frame j
*/
void ksl_inertia_merge(ksl_inertia_t* inertia_i, ksl_vec3_t* t_ic_i,
                       ksl_inertia_t* inertia_j, const ksl_vec3_t* t_jc_j,
                       const ksl_SE3_t* D_ij);

/*!
@brief merge single precision child inertia (j) with parent inertia (i)
@param parent inertia [in/out] parent inertia to be merged
@param t_ic_i [in/out] vector from parent body reference frame i to body center
of mass frame c, expressed in body frame i
@param child inertia [in]
@param t_jc_j [in] vector from child body reference frame j to body center of
mass frame c, expressed in body frame j
@param D_ij [in] transformation from parent reference frame i to child reference
frame j
*/
void ksl_inertiaf_merge(ksl_inertiaf_t* inertia_i, ksl_vec3f_t* t_ic_i,
                        ksl_inertiaf_t* inertia_j, const ksl_vec3f_t* t_jc_j,
                        const ksl_SE3f_t* D_ij);

/*!
@brief factor double precision inertia matrix

@todo finish this

inertia matrix is overwritten with its factors

4 cases:
  * rank 2+, full rank, positive definite, or rank 2, positive semidefinite
  * rank 1, positive semidefinite
  * rank 0, do nothing

  @return rank of inertia matrix
*/
int ksl_inertia_factor(ksl_inertia_t*);

/*!
@brief factor single precision inertia matrix

@todo finish this

inertia matrix is overwritten with its factors

4 cases:
  * rank 2+, full rank, positive definite, or rank 2, positive semidefinite
  * rank 1, positive semidefinite
  * rank 0, do nothing

  @return rank of inertia matrix
*/
int ksl_inertiaf_factor(ksl_inertiaf_t*);
#endif
