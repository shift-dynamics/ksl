.. _SE3:
.. title:: SO(3) and SE(3)


SO(3) and SE(3) Groups
======================

SO(3)
-----

The Special Orthogonal group, SO(3), consists of the set of 3x3 orthonormal matrices for rigid body rotations.

SE3 matrices have the property that:

.. math::

    R^{-1} = R^T


SE(3)
-----

4x4 matrices for transforming homogeneous coordinates are commonly used to describe general rigid body displacements :cite:`uicker2013`.

.. math::

    \Phi \in SE(3) = \begin{bmatrix}R & \underline{r}\\ 0 & 1 \end{bmatrix}

Here :math:`R` is an orthonormal rotation matrix :math:`\in SE(3)` and :math:`\underline{r}` is a translation vector. In group theory, these 4x4 matrices are identified as the Special Euclidian group, SE(3).

SE(3) matrices have the property that:

.. math::

    \Phi^{-1} = \begin{bmatrix}R^T & -R^T \underline{r} \\ 0 & 1 \end{bmatrix}


Consider how the 3 dimensional vector :math:`\underline{v}_a` is transformed to frame :math:`b` using 4x4 transformation matrices. To transform a vector using 4x4 transformation matrices, a homogeneous coordinate is appended to :math:`\underline{v}_a` and the transformation is performed as:

.. math::

    \begin{Bmatrix} \underline{v}_a \\ 1 \end{Bmatrix} =
    \begin{Bmatrix} R^{ab} \underline{v}_b + \underline{r}_{ab}^a \\ 1 \end{Bmatrix} =
    \begin{bmatrix} R^{ab} & \underline{r}_{ab}^a \\ 0 & 1 \end{bmatrix}
    \begin{Bmatrix} \underline{v}_b \\ 1 \end{Bmatrix}


The notation provided by the SE(3) group is convenient for its compact notation in that it encapsulates general rigid body rotation and translation in one symbol. However, this example demonstrates that when composing rigid body transformations, there is no need to perform the full 4x4 matrix multiplication or store the 0s and 1s. *KSL* has a special datastructure for rigid body transformations called *ksl_SE3_t* and a collection of functions that perform only the minimum number of operations for composing rigid body transformations and transforming vectors.

Rigid body rotations
--------------------

double precision
****************

.. doxygenunion:: ksl_mat3x3_t


.. doxygenfunction:: ksl_mat3x3


.. doxygenfunction:: ksl_mat3x3_cmo


.. doxygenfunction:: ksl_mat3x3_alloc


.. doxygenfunction:: ksl_mat3x3_setIdentity


.. doxygenfunction:: ksl_mat3x3_set


.. doxygenfunction:: ksl_mat3x3_setFromVectors


.. doxygenfunction:: ksl_mat3x3_get


.. doxygenfunction:: ksl_mat3x3_copy


.. doxygenfunction:: ksl_mat3x3_invert


.. doxygenfunction:: ksl_mat3x3_inverted


.. doxygenfunction:: ksl_mat3x3_transpose


.. doxygenfunction:: ksl_mat3x3_transposed


.. doxygenmacro:: ksl_mat3x3_getEulerAngles


.. doxygenfunction:: ksl_mat3x3_getEulerAnglesWithReference


.. doxygenfunction:: ksl_mat3x3_setFromEulerAngles


.. doxygenfunction:: ksl_mat3x3_getAxisAngle


.. doxygenfunction:: ksl_mat3x3_setFromAxisAngle


.. doxygenfunction:: ksl_mat3x3_determinant


single precision
****************

.. doxygenunion:: ksl_mat3x3f_t


.. doxygenfunction:: ksl_mat3x3f


.. doxygenfunction:: ksl_mat3x3f_cmo


.. doxygenfunction:: ksl_mat3x3f_alloc


.. doxygenfunction:: ksl_mat3x3f_setIdentity


.. doxygenfunction:: ksl_mat3x3f_set


.. doxygenfunction:: ksl_mat3x3f_setFromVectors


.. doxygenfunction:: ksl_mat3x3f_get


.. doxygenfunction:: ksl_mat3x3f_copy


.. doxygenfunction:: ksl_mat3x3f_invert


.. doxygenfunction:: ksl_mat3x3f_inverted


.. doxygenfunction:: ksl_mat3x3f_transpose


.. doxygenfunction:: ksl_mat3x3f_transposed


.. doxygenmacro:: ksl_mat3x3f_getEulerAngles


.. doxygenfunction:: ksl_mat3x3f_getEulerAnglesWithReference


.. doxygenfunction:: ksl_mat3x3f_setFromEulerAngles


.. doxygenfunction:: ksl_mat3x3f_getAxisAngle


.. doxygenfunction:: ksl_mat3x3f_setFromAxisAngle


.. doxygenfunction:: ksl_mat3x3f_determinant


Rigid body transformations
--------------------------

double precision
****************

.. doxygenunion:: ksl_SE3_t


.. doxygenfunction:: ksl_SE3


.. doxygenfunction:: ksl_SE3_cmo


.. doxygenfunction:: ksl_SE3_fromRt


.. doxygenfunction:: ksl_SE3_alloc


.. doxygenfunction:: ksl_SE3_toMat4x4


.. doxygenfunction:: ksl_SE3_toMat4x4f


.. doxygenfunction:: ksl_SE3_setIdentity


.. doxygenfunction:: ksl_SE3_set


.. doxygenfunction:: ksl_SE3_get


.. doxygenfunction:: ksl_SE3_getTranslation


.. doxygenfunction:: ksl_SE3_invert


.. doxygenfunction:: ksl_SE3_inverted


.. doxygenfunction:: ksl_SE3_copy


single precision
****************

.. doxygenunion:: ksl_SE3f_t


.. doxygenfunction:: ksl_SE3f


.. doxygenfunction:: ksl_SE3f_cmo


.. doxygenfunction:: ksl_SE3f_fromRt


.. doxygenfunction:: ksl_SE3f_alloc


.. doxygenfunction:: ksl_SE3f_toMat4x4f


.. doxygenfunction:: ksl_SE3f_setIdentity


.. doxygenfunction:: ksl_SE3f_set


.. doxygenfunction:: ksl_SE3f_get


.. doxygenfunction:: ksl_SE3f_getTranslation


.. doxygenfunction:: ksl_SE3f_invert


.. doxygenfunction:: ksl_SE3f_inverted


.. doxygenfunction:: ksl_SE3f_copy


4x4 matrices
-------------

double precision
****************

.. doxygenunion:: ksl_mat4x4_t


.. doxygenfunction:: ksl_mat4x4


.. doxygenfunction:: ksl_mat4x4_cmo


.. doxygenfunction:: ksl_mat4x4_fromSE3


.. doxygenfunction:: ksl_mat4x4_fromRt


.. doxygenfunction:: ksl_mat4x4_alloc


.. doxygenfunction:: ksl_mat4x4_set


.. doxygenfunction:: ksl_mat4x4_setIdentity


.. doxygenfunction:: ksl_mat4x4_getTranslation


.. doxygenfunction:: ksl_mat4x4_get


single precision
****************

.. doxygenunion:: ksl_mat4x4f_t


.. doxygenfunction:: ksl_mat4x4f


.. doxygenfunction:: ksl_mat4x4f_cmo


.. doxygenfunction:: ksl_mat4x4f_fromSE3f


.. doxygenfunction:: ksl_mat4x4f_fromRt


.. doxygenfunction:: ksl_mat4x4f_alloc


.. doxygenfunction:: ksl_mat4x4f_set


.. doxygenfunction:: ksl_mat4x4f_setIdentity


.. doxygenfunction:: ksl_mat4x4f_getTranslation


.. doxygenfunction:: ksl_mat4x4f_get


Matrix-vector operations
------------------------

double precision
****************

.. doxygenfunction:: ksl_product_drv


.. doxygenfunction:: ksl_product_drvinv


.. doxygenfunction:: ksl_product_drinvv


.. doxygenfunction:: ksl_product_drinvvinv


.. doxygenfunction:: ksl_product_drvtx


.. doxygenfunction:: ksl_product_drvtxinv


.. doxygenfunction:: ksl_product_drvty


.. doxygenfunction:: ksl_product_drvtyinv


.. doxygenfunction:: ksl_product_drvtz


.. doxygenfunction:: ksl_product_drvtzinv


single precision
****************

.. doxygenfunction:: ksl_product_drvf


.. doxygenfunction:: ksl_product_drvinvf


.. doxygenfunction:: ksl_product_drinvvf


.. doxygenfunction:: ksl_product_drinvvinvf


.. doxygenfunction:: ksl_product_drvtxf


.. doxygenfunction:: ksl_product_drvtxinvf


.. doxygenfunction:: ksl_product_drvtyf


.. doxygenfunction:: ksl_product_drvtyinvf


.. doxygenfunction:: ksl_product_drvtzf


.. doxygenfunction:: ksl_product_drvtzinvf


Matrix-matrix operations
---------------------------------------------

double precision
****************

.. doxygenfunction:: ksl_product_drdrx


.. doxygenfunction:: ksl_product_drdrxinv


.. doxygenfunction:: ksl_product_drdry


.. doxygenfunction:: ksl_product_drdryinv


.. doxygenfunction:: ksl_product_drdrz


.. doxygenfunction:: ksl_product_drdrzinv


.. doxygenfunction:: ksl_product_drdr


.. doxygenfunction:: ksl_product_drdrinv


.. doxygenfunction:: ksl_product_drinvdr


.. doxygenfunction:: ksl_product_dv


.. doxygenfunction:: ksl_product_dinvv


.. doxygenfunction:: ksl_product_ddrx


.. doxygenfunction:: ksl_product_ddrxinv


.. doxygenfunction:: ksl_product_ddry


.. doxygenfunction:: ksl_product_ddryinv


.. doxygenfunction:: ksl_product_ddrz


.. doxygenfunction:: ksl_product_ddrzinv


.. doxygenfunction:: ksl_product_ddt


.. doxygenfunction:: ksl_product_ddtinv


.. doxygenfunction:: ksl_product_dinvdt


.. doxygenfunction:: ksl_product_ddtx


.. doxygenfunction:: ksl_product_ddtxinv


.. doxygenfunction:: ksl_product_ddty


.. doxygenfunction:: ksl_product_ddtyinv


.. doxygenfunction:: ksl_product_ddtz


.. doxygenfunction:: ksl_product_ddtzinv


.. doxygenfunction:: ksl_product_ddr


.. doxygenfunction:: ksl_product_ddrinv


.. doxygenfunction:: ksl_product_dd


.. doxygenfunction:: ksl_product_ddinv


single precision
****************

.. doxygenfunction:: ksl_product_drdrxf


.. doxygenfunction:: ksl_product_drdrxinvf


.. doxygenfunction:: ksl_product_drdryf


.. doxygenfunction:: ksl_product_drdryinvf


.. doxygenfunction:: ksl_product_drdrzf


.. doxygenfunction:: ksl_product_drdrzinvf


.. doxygenfunction:: ksl_product_drdrf


.. doxygenfunction:: ksl_product_drdrinvf


.. doxygenfunction:: ksl_product_drinvdrf


.. doxygenfunction:: ksl_product_dvf


.. doxygenfunction:: ksl_product_dinvvf


.. doxygenfunction:: ksl_product_ddrxf


.. doxygenfunction:: ksl_product_ddrxinvf


.. doxygenfunction:: ksl_product_ddryf


.. doxygenfunction:: ksl_product_ddryinvf


.. doxygenfunction:: ksl_product_ddrzf


.. doxygenfunction:: ksl_product_ddrzinvf


.. doxygenfunction:: ksl_product_ddtf


.. doxygenfunction:: ksl_product_ddtinvf


.. doxygenfunction:: ksl_product_dinvdtf


.. doxygenfunction:: ksl_product_ddtxf


.. doxygenfunction:: ksl_product_ddtxinvf


.. doxygenfunction:: ksl_product_ddtyf


.. doxygenfunction:: ksl_product_ddtyinvf


.. doxygenfunction:: ksl_product_ddtzf


.. doxygenfunction:: ksl_product_ddtzinvf


.. doxygenfunction:: ksl_product_ddrf


.. doxygenfunction:: ksl_product_ddrinvf


.. doxygenfunction:: ksl_product_ddf


.. doxygenfunction:: ksl_product_ddinvf
