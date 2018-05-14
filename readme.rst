*Kinematics Subroutine Library*
===============================


.. raw:: html

   <embed>
    <a href='http://104.35.187.125:8090/job/shift-dynamics/job/ksl/job/master/'><img src='http://104.35.187.125:8090/buildStatus/icon?job=shift-dynamics/ksl/master' alt="Build Status"></a>
   </embed>


A sparse math library for kinematics and dynamics.

double precision
-------------------------

short notation
**************

========================== ========================= =============
abbreviation               datastructure             description
-------------------------- ------------------------- -------------
**d**                      :code:`ksl_SE3_t`         SE3 general rigid body transformation (i.e. *displacement*) consisting of SO3 rotation and translation
**dinv**                   :code:`ksl_SE3_t`         inverse of an SE3 rigid body transformation
**dr**                     :code:`ksl_mat3x3_t`      SE3 transformation consisting of only a SO3 (3x3 orthonormal rotation matrix) and no translation
**drinv**                  :code:`ksl_mat3x3_t`      SE3 transformation consisting of only an inverse SO3 rotation matrix
**drx**, **dry**, **drz**  :code:`float dc[2]`       SE3 transformation consisting of only a rotation matrix about x,y, or z axis
**dtx**, **dty**, **dtz**  :code:`double`            SE3 transformation consisting of only a translation along x,y, or z axis
**qx**, **qy**, **qz**     :code:`double dc[2]`      quaternion rotation about x,y, or z axis, defined by direction cosines
**s**                      :code:`ksl_screw_t`       screw
**c**                      :code:`ksl_coscrew_t`     coscrew
**q**                      :code:`ksl_quaternion_t`  quaternion
**a**                      :code:`double`            scalar
**v**                      :code:`ksl_vec3_t`        vector
**Ad**                     :code:`ksl_SE3_t`         Adjoint matrix for transforming screws
**CoAd**                   :code:`ksl_SE3_t`         CoAdjoint matrix for transforming coscrews
**Adr**                    :code:`ksl_mat3x3_t`      Adjoint matrix for transforming screws consisting of only an SO3 rotation
**CoAdr**                  :code:`ksl_mat3x3_t`      CoAdjoint matrix for transforming coscrews consisting of only an SO3 rotation
**Adt**                    :code:`double`            Adjoint matrix for transforming screws consisting of only a translation
**CoAdt**                  :code:`double`            CoAdjoint matrix for transforming coscrews consisting of only a translation
========================== ========================= =============

example usage
*************

============================  ========= ========================================================
Function name                 operation description
----------------------------  --------- --------------------------------------------------------
:code:`ksl_product_dvf`       D * v     SE3 transformation (rigid body displacement) of vector v

:code:`ksl_product_Ads`       Ad * s    product of Adjoint matrix and screw

:code:`ksl_product_CoAdc`     CoAd * c  product of CoAdjoint matrix and coscrew

:code:`ksl_product_qq`        q * q     quaternion product of two normalized quaternions

:code:`ksl_dot_cs`            c^T * s   dot product between a coscrew and screw

:code:`ksl_product_va`        v * a     product between a vector and scalar
============================  ========= ========================================================


single precision
---------------------------------

short notation
**************

========================== ========================= =============
abbreviation               datastructure             description
-------------------------- ------------------------- -------------
**d**                      :code:`ksl_SE3f_t`        SE3 (rigid body transformation consisting of SO3 rotation and translation)
**dinv**                   :code:`ksl_SE3f_t`        inverse of an SE3 rigid body transformation
**dr**                     :code:`ksl_mat3x3f_t`     SE3 transformation consisting of only a SO3 (3x3 orthonormal rotation matrix) and no translation
**drinv**                  :code:`ksl_mat3x3f_t`     SE3 transformation consisting of only an inverse SO3 rotation matrix
**drx**, **dry**, **drz**  :code:`float dc[2]`       SE3 transformation consisting of only a rotation matrix about x,y, or z axis, defined by direction cosines
**dtx**, **dty**, **dtz**  :code:`float`             SE3 transformation consisting of only a translation along x,y, or z axis, defined by direction cosines
**qx**, **qy**, **qz**     :code:`float dc[2]`       quaternion rotation about x,y, or z axis, defined by direction cosines
**s**                      :code:`ksl_screwf_t`      screw
**c**                      :code:`ksl_coscrewf_t`    coscrew
**q**                      :code:`ksl_quaternionf_t` quaternion
**a**                      :code:`float`             scalar
**v**                      :code:`ksl_vec3f_t`       vector
**Ad**                     :code:`ksl_SE3f_t`        Adjoint matrix for transforming screws
**CoAd**                   :code:`ksl_SE3f_t`        CoAdjoint matrix for transforming coscrews
**Adr**                    :code:`ksl_mat3x3f_t`     Adjoint matrix for transforming screws consisting of only an SO3 rotation
**CoAdr**                  :code:`ksl_mat3x3f_t`     CoAdjoint matrix for transforming coscrews consisting of only an SO3 rotation
**Adt**                    :code:`float`             Adjoint matrix for transforming screws consisting of only a translation
**CoAdt**                  :code:`float`             CoAdjoint matrix for transforming coscrews consisting of only a translation
========================== ========================= =============


example usage
*************

============================  ========= ========================================================
Function name                 operation description
----------------------------  --------- --------------------------------------------------------
:code:`ksl_product_dvf`       D * v     SE3 transformation (rigid body displacement) of vector v
:code:`ksl_product_Adsf`      Ad * s    product of Adjoint matrix and screw

:code:`ksl_product_CoAdcf`    CoAd * c  product of CoAdjoint matrix and coscrew

:code:`ksl_product_qqf`       q * q     quaternion product of two normalized quaternions

:code:`ksl_dot_csf`           c^T * s   dot product between a coscrew and screw

:code:`ksl_product_avf`       a * v     product between a vector and scalar
============================  ========= ========================================================
