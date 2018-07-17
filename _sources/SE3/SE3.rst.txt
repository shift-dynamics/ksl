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


Consider how the vector :math:`\underline{v}_b` is transformed from frame :math:`b` to frame :math:`a` using 4x4 transformation matrices. To transform a 3D vector using 4x4 transformation matrices, a homogeneous coordinate is appended to :math:`\underline{v}_b` and the transformation is performed as:

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
