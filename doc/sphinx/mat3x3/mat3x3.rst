.. _mat3x3:
.. title:: 3x3 Matrices

3x3 Matrices
============

Overview
--------

The 3x3 matrices that appear most often in kinematics are **rotation
matrices**, which describe the orientation of one reference frame relative to
another. The rotation matrix :math:`R^{ab}` takes the components of a vector
in frame :math:`b` to its components in frame :math:`a`:

.. math::

   \underline{v}^a = R^{ab}\, \underline{v}^b

The columns of :math:`R^{ab}` are the unit vectors along the x, y and z axes
of frame :math:`b`, expressed in frame :math:`a`. Each entry is the cosine of
the angle between an axis of :math:`a` and an axis of :math:`b`, which is why
rotation matrices are also called *direction cosine matrices*. Because the
columns are orthonormal, a rotation matrix has determinant +1 and its inverse
is its transpose:

.. math::

   (R^{ab})^{-1} = (R^{ab})^T = R^{ba}

so ``ksl_mat3x3_transpose()`` inverts a rotation with no arithmetic at all,
while ``ksl_mat3x3_invert()`` is only needed for general matrices. Rotations
compose by multiplication, :math:`R^{ac} = R^{ab} R^{bc}`. The rotations about
a single coordinate axis are

.. math::

   R_x = \begin{bmatrix} 1 & 0 & 0 \\ 0 & c & -s \\ 0 & s & c \end{bmatrix},
   \quad
   R_y = \begin{bmatrix} c & 0 & s \\ 0 & 1 & 0 \\ -s & 0 & c \end{bmatrix},
   \quad
   R_z = \begin{bmatrix} c & -s & 0 \\ s & c & 0 \\ 0 & 0 & 1 \end{bmatrix}

with :math:`c = \cos\theta` and :math:`s = \sin\theta`. A rotation by angle
:math:`\theta` about a general unit axis :math:`\underline{e}` is given by
Rodrigues' formula,
:math:`R = I + \sin\theta\, \tilde{e} + (1 - \cos\theta)\, \tilde{e}^2`
(``ksl_mat3x3_setFromAxisAngle()``). Orientations can also be described by
three Euler angles (see :ref:`axis`) or by a unit quaternion (see
:ref:`quaternions`). :cite:`murray1994mathematical` and :cite:`uicker2013`
give a fuller introduction.

**Keeping a rotation orthonormal.** After many products, round-off error
slowly makes the columns of a rotation matrix lose their unit length and
orthogonality. ``ksl_mat3x3_normalize()`` restores them.

**Storage.** ``ksl_mat3x3_t`` holds nine ``double`` values, 72 bytes
(``ksl_mat3x3f_t``: 36 bytes), in **column major** order: the three values of
the first column come first. Column major order is used because the columns
of a rotation matrix are the rotated frame's axes, so they can be read
directly as vectors. Entries can be accessed several ways:

.. code-block:: c

   ksl_mat3x3_t R;
   ksl_mat3x3_setIdentity(&R);
   double r01 = R.m01;      /* row 0, column 1 */
   double r10 = R.at[0][1]; /* at[column][row]: row 1, column 0 */
   ksl_vec3_t z = R.v[2];   /* third column: the frame's z axis */

``as_array`` gives the nine values as a flat array.

Double precision
----------------

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


.. doxygendefine:: ksl_mat3x3_getEulerAngles


.. doxygenfunction:: ksl_mat3x3_getEulerAnglesWithReference


.. doxygenfunction:: ksl_mat3x3_setFromEulerAngles


.. doxygenfunction:: ksl_mat3x3_getAxisAngle


.. doxygenfunction:: ksl_mat3x3_setFromAxisAngle


.. doxygenfunction:: ksl_mat3x3_determinant


.. doxygenfunction:: ksl_mat3x3_normalize


.. doxygenfunction:: ksl_mat3x3_normalized


.. doxygenfunction:: ksl_mat3x3_setFromAxisDC



Single precision
----------------

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


.. doxygendefine:: ksl_mat3x3f_getEulerAngles


.. doxygenfunction:: ksl_mat3x3f_getEulerAnglesWithReference


.. doxygenfunction:: ksl_mat3x3f_setFromEulerAngles


.. doxygenfunction:: ksl_mat3x3f_getAxisAngle


.. doxygenfunction:: ksl_mat3x3f_setFromAxisAngle


.. doxygenfunction:: ksl_mat3x3f_determinant


.. doxygenfunction:: ksl_mat3x3f_normalize


.. doxygenfunction:: ksl_mat3x3f_normalized
