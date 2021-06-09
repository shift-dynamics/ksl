# *Kinematics Subroutine Library*

<embed>
<a href='http://172.117.149.107:8090/job/shift-dynamics/job/ksl/job/master/'><img src='http://172.117.149.107:8090/buildStatus/icon?job=shift-dynamics/ksl/master' alt="Build Status"></a>
</embed>


## overview

*KSL* is a sparse math library written in the C programming language that is targeted to real-time kinematics, dynamics, contact detection, robotics and 3D visualization applications.

*KSL* contains a number of utility functions to transform vectors, screws, coscrews and spatial inertia matrices using the minimum number of operations as described in the *KSL* documentation at https://ksl.shift-dynamics.io.

Additionally, *KSL* contains routines for performing LU decomposition with complete row and column pivoting, an important component in the robust processing of kinematics and dynamics equations.

The code is available open-source with minimal restrictions. If you find the code to be useful in your projects, we would love to hear from you.


## quick introduction
The below tables contain examples of the naming conventions used for *KSL* datastructures and functions. For a complete list of functions, refer to the *KSL* website and source code.

## double precision

### notation

| abbreviation |              datastructure  |           description |
 --- | --- | --- 
| **d**                    | `ksl_SE3_t`        |  SE3 general rigid body transformation (i.e. *displacement*) consisting of SO3 rotation and translation |
| **dinv**                 | `ksl_SE3_t`        |  inverse of an SE3 rigid body transformation |
| **dr**                   | `ksl_mat3x3_t`     |  SE3 transformation consisting of only a SO3 (3x3 orthonormal rotation matrix) and no translation |
| **drinv**                | `ksl_mat3x3_t`     |  SE3 transformation consisting of only an inverse SO3 rotation matrix
| **drx**, **dry**, **drz** | `double dc[2]`     |  SE3 transformation consisting of only a rotation matrix about x,y, or z axis |
| **dtx**, **dty**, **dtz** | `double`          |  SE3 transformation consisting of only a translation along x,y, or z axis |
| **qx**, **qy**, **qz**   | `double dc[2]`     |  quaternion rotation about x,y, or z axis, defined by direction cosines |
| **s**                    | `ksl_screw_t`      |  screw |
| **c**                    | `ksl_coscrew_t`    |  coscrew |
| **q**                    | `ksl_quaternion_t` |  quaternion |
| **a**                    | `double`           |  scalar |
| **v**                    | `ksl_vec3_t`       |  vector |
| **Ad**                   | `ksl_SE3_t`        |  Adjoint matrix for transforming screws |
| **CoAd**                 | `ksl_SE3_t`        |  CoAdjoint matrix for transforming coscrews |
| **Adr**                  | `ksl_mat3x3_t`     |  Adjoint matrix for transforming screws consisting of only an SO3 rotation |
| **CoAdr**                | `ksl_mat3x3_t`     |  CoAdjoint matrix for transforming coscrews consisting of only an SO3 rotation |
| **Adt**                  | `double`           |  Adjoint matrix for transforming screws consisting of only a translation |
| **CoAdt**                | `double`           |  CoAdjoint matrix for transforming coscrews consisting of only a translation |

## example usage

| Function name        |         operation | description |
--- | --- | ---
| `ksl_product_dvf`    |   D * v     | SE3 transformation (rigid body displacement) of vector v |
| `ksl_product_Ads`    |   Ad * s    | product of Adjoint matrix and screw |
| `ksl_product_CoAdc`  |   CoAd * c  | product of CoAdjoint matrix and coscrew |
| `ksl_product_qq`     |   q * q     | quaternion product of two normalized quaternions |
| `ksl_dot_cs`         |   c^T * s   | dot product between a coscrew and screw |
| `ksl_product_va`     |   v * a     | product between a vector and scalar |

## single precision

### notation

| abbreviation               | datastructure       | description |
--- | --- | ---
| **d**                      | `ksl_SE3f_t`        | SE3 (rigid body transformation consisting of SO3 rotation and translation) |
| **dinv**                   | `ksl_SE3f_t`        | inverse of an SE3 rigid body transformation |
| **dr**                     | `ksl_mat3x3f_t`     | SE3 transformation consisting of only a SO3 (3x3 orthonormal rotation matrix) and no translation |
| **drinv**                  | `ksl_mat3x3f_t`     | SE3 transformation consisting of only an inverse SO3 rotation matrix |
| **drx**, **dry**, **drz**  | `float dc[2]`       | SE3 transformation consisting of only a rotation matrix about x,y, or z axis, defined by direction cosines |
| **dtx**, **dty**, **dtz**  | `float`             | SE3 transformation consisting of only a translation along x,y, or z axis, defined by direction cosines |
| **qx**, **qy**, **qz**     | `float dc[2]`       | quaternion rotation about x,y, or z axis, defined by direction cosines |
| **s**                      | `ksl_screwf_t`      | screw |
| **c**                      | `ksl_coscrewf_t`    | coscrew |
| **q**                      | `ksl_quaternionf_t` | quaternion |
| **a**                      | `float`             | scalar |
| **v**                      | `ksl_vec3f_t`       | vector |
| **Ad**                     | `ksl_SE3f_t`        | Adjoint matrix for transforming screws |
| **CoAd**                   | `ksl_SE3f_t`        | CoAdjoint matrix for transforming coscrews |
| **Adr**                    | `ksl_mat3x3f_t`     | Adjoint matrix for transforming screws consisting of only an SO3 rotation |
| **CoAdr**                  | `ksl_mat3x3f_t`     | CoAdjoint matrix for transforming coscrews consisting of only an SO3 rotation |
| **Adt**                    | `float`             | Adjoint matrix for transforming screws consisting of only a translation |
| **CoAdt**                  | `float`             | CoAdjoint matrix for transforming coscrews consisting of only a translation |


### example usage

| Function name        |              | operation description |
--- | --- | ---
| `ksl_product_dvf`    |    D * v     | SE3 transformation (rigid body displacement) of vector v |
| `ksl_product_Adsf`   |    Ad * s    | product of Adjoint matrix and screw |
| `ksl_product_CoAdcf` |    CoAd * c  | product of CoAdjoint matrix and coscrew |
| `ksl_product_qqf`    |    q * q     | quaternion product of two normalized quaternions |
| `ksl_dot_csf`        |    c^T * s   | dot product between a coscrew and screw |
| `ksl_product_avf`    |    a * v     | product between a vector and scalar |
