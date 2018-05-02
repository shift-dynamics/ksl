*Kinematics Subroutine Library*
===============================

A sparse math library for kinematics and dynamics.

double precision
-------------------------

short notation
**************

====================== ======================== =============
abbreviation           datastructure            description
---------------------- ------------------------ -------------
**d**                  :code:`ksl_SE3_t`        SE3 (rigid body transformation consisting of SO3 rotation and translation)
**dinv**               :code:`ksl_SE3_t`        inverse of an SE3 rigid body transformation
**r**                  :code:`ksl_mat3x3_t`     SO3 (3x3 orthonormal rotation matrix)
**rinv**               :code:`ksl_mat3x3_t`     inverse of an SO3 rotation matrix
**rx**, **ry**, **rz** :code:`double dc[2]`     SO3 rotation matrix about x,y, or z axis, defined by direction cosines
**qx**, **qy**, **qz** :code:`double dc[2]`     quaternion rotation about x,y, or z axis, defined by direction cosines
**s**                  :code:`ksl_screw_t`      screw
**c**                  :code:`ksl_coscrew_t`    coscrew
**q**                  :code:`ksl_quaternion_t` quaternion with unit norm
**qn**                 :code:`ksl_quaternion_t` quaternion with non-unit norm
**a**                  :code:`double`           scalar
**v**                  :code:`ksl_vec3_t`       vector
**Ad**                 :code:`ksl_SE3_t`        Adjoint matrix for transforming screws
**CoAd**               :code:`ksl_SE3_t`        CoAdjoint matrix for transforming coscrews
====================== ======================== =============

example usage
*************

============================  ========= ========================================================
Function name                 operation description
----------------------------  --------- --------------------------------------------------------
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

====================== ========================= =============
abbreviation           datastructure             description
---------------------- ------------------------- -------------
**d**                  :code:`ksl_SE3f_t`        SE3 (rigid body transformation consisting of SO3 rotation and translation)
**dinv**               :code:`ksl_SE3f_t`        inverse of an SE3 rigid body transformation
**r**                  :code:`ksl_mat3x3f_t`     SO3 (3x3 orthonormal rotation matrix)
**rinv**               :code:`ksl_mat3x3f_t`     inverse of an SO3 rotation matrix
**rx**, **ry**, **rz** :code:`float dc[2]`       SO3 rotation matrix about x,y, or z axis, defined by direction cosines
**qx**, **qy**, **qz** :code:`float dc[2]`       quaternion rotation about x,y, or z axis, defined by direction cosines
**s**                  :code:`ksl_screwf_t`      screw
**c**                  :code:`ksl_coscrewf_t`    coscrew
**q**                  :code:`ksl_quaternionf_t` quaternion with unit norm
**qn**                 :code:`ksl_quaternionf_t` quaternion with non-unit norm
**a**                  :code:`float`             scalar
**v**                  :code:`ksl_vec3f_t`       vector
**Ad**                 :code:`ksl_SE3f_t`        Adjoint matrix for transforming screws
**CoAd**               :code:`ksl_SE3f_t`        CoAdjoint matrix for transforming coscrews
====================== ========================= =============


example usage
*************

============================  ========= ========================================================
Function name                 operation description
----------------------------  --------- --------------------------------------------------------
:code:`ksl_product_Adsf`      Ad * s    product of Adjoint matrix and screw

:code:`ksl_product_CoAdcf`    CoAd * c  product of CoAdjoint matrix and coscrew

:code:`ksl_product_qqf`       q * q     quaternion product of two normalized quaternions

:code:`ksl_dot_csf`           c^T * s   dot product between a coscrew and screw

:code:`ksl_product_vaf`       v * a     product between a vector and scalar
============================  ========= ========================================================
