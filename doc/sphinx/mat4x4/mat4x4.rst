.. _mat4x4:
.. title:: 4x4 Matrices

4x4 Matrices
============

Overview
--------

A 4x4 matrix acting on homogeneous coordinates (see :ref:`vec4`) can represent
a rigid body transformation,

.. math::

   \begin{bmatrix} R & \underline{t} \\ 0 & 1 \end{bmatrix}

as described in :ref:`SE3`, and also transformations that are not rigid, such
as the perspective projection of a camera or the scaling used in computer
graphics.

*KSL* does its rigid body arithmetic with ``ksl_SE3_t``, which stores only
:math:`R` and :math:`\underline{t}` (12 numbers instead of 16) and never
multiplies the constant bottom row. ``ksl_mat4x4_t`` is provided for exchanging
data with software that expects a full 4x4 matrix, such as graphics interfaces
and model file formats. ``ksl_SE3_toMat4x4()`` and ``ksl_mat4x4_toSE3()``
convert between the two. ``ksl_mat4x4_toSE3()`` copies the rotation and
translation and assumes the bottom row is :math:`[0\;0\;0\;1]`.

**Storage.** ``ksl_mat4x4_t`` holds sixteen ``double`` values, 128 bytes
(``ksl_mat4x4f_t``: 64 bytes), in column major order, the same convention as
:ref:`mat3x3`: ``at[column][row]``, ``m<row><column>``, columns ``v[0]`` to
``v[3]`` as ``ksl_vec4_t``, and ``as_array`` for the sixteen values in order.
Column major order is also what OpenGL expects, so the ``as_array`` member of
a ``ksl_mat4x4f_t`` can be passed directly to OpenGL functions such as
``glUniformMatrix4fv`` without transposing.

Double precision
----------------

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


.. doxygenfunction:: ksl_mat4x4_toSE3



Single precision
----------------

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


.. doxygenfunction:: ksl_mat4x4f_toSE3f
