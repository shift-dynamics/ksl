*Kinematics Subroutine Library*
===============================

A sparse math library for kinematics and dynamics.

short notation
--------------
* d = SE3 (rigid body transformation consisting of SO3 rotation and translation)
* r = SO3 (3x3 orthonormal rotation matrix)
* rx, ry, rz = SO3 rotation matrix about x,y, or z axis
* qx, qy, qz = quaternion rotation about x,y, or z axis
* s = screw
* c = coscrew
* q = quaternion with unit norm
* qn = quaternion with non-unit norm
* a = scalar
* v = vector
* Ad = Adjoint matrix for transforming screws
* CoAd = CoAdjoint matrix for transforming coscrews


examples
--------
* :code:`ksl_product_Ads`

.. math::

  \frac{1}{2}
