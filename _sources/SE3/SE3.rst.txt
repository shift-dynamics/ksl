.. _SE3:
.. title:: SE(3)

SE(3)
=====

Overview
--------

4x4 matrices for transforming homogeneous coordinates are commonly used to describe general rigid body displacements :cite:`uicker2013`.

.. math::

    \Phi \in SE(3) = \begin{bmatrix}R & \underline{r}\\ 0 & 1 \end{bmatrix}

Here :math:`R` is an orthonormal rotation matrix that is a member of the Special Orthogonal Group (:math:`\in SO(3)`) with the property:

.. math::

    R^{-1} = R^T


and :math:`\underline{r}` is a translation vector. In group theory, this set of 4x4 matrices is identified as the Special Euclidian group, SE(3).

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


Double precision
----------------

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


Single precision
----------------

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



Matrix-vector operations
------------------------

Double precision
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


Single precision
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

Double precision
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


Single precision
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
