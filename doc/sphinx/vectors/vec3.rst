.. _vec3:
.. title:: 3D Vectors

3D Vectors
==========

Overview
--------

A three-dimensional vector is an ordered set of three numbers, written as a
column matrix

.. math::

   \underline{v} = \begin{Bmatrix} v_x \\ v_y \\ v_z \end{Bmatrix}

In kinematics and dynamics, vectors describe the positions of points,
displacements, linear and angular velocities, forces and moments. The
components of a vector are always measured in some reference frame: the same
physical vector has different components in different frames, and the
components in two frames are related by a rotation matrix (see
:ref:`mat3x3`). A superscript names the frame, so :math:`\underline{v}^a` is
the vector :math:`\underline{v}` with its components expressed in frame
:math:`a`.

The operations used most often are the dot product, which gives the length of
a vector and the angle between two vectors, and the cross product, which
appears in moments (:math:`\underline{r} \times \underline{f}`) and in the
velocity of a point on a rotating body
(:math:`\underline{\omega} \times \underline{r}`). The cross product can also
be written as a product with the skew-symmetric matrix
:math:`\tilde{a}` (see :ref:`notation`):

.. math::

   \underline{a} \times \underline{b} = \tilde{a}\,\underline{b} =
   \begin{bmatrix} 0 & -a_z & a_y \\ a_z & 0 & -a_x \\ -a_y & a_x & 0
   \end{bmatrix} \begin{Bmatrix} b_x \\ b_y \\ b_z \end{Bmatrix}

**Storage.** ``ksl_vec3_t`` holds three ``double`` values with no padding, 24
bytes in all (``ksl_vec3f_t``: three ``float`` values, 12 bytes;
``ksl_vec3i_t``: three ``int`` values). An array of ``n`` vectors is therefore
one contiguous block of ``3n`` numbers. The components can be read by name or
by index:

.. code-block:: c

   ksl_vec3_t v = ksl_vec3(1.0, 2.0, 3.0);
   double y = v.y;       /* by name */
   double z = v.at[2];   /* by index, 0 to 2 */

**Function names.** Functions are named after the operation and the operand
types, for example ``ksl_add_vv`` (vector plus vector), ``ksl_cross_vv`` and
``ksl_dot_vv``. ``ksl_product_av`` multiplies a scalar ``a`` by a vector.
``axpy`` stands for "a times x plus y" (:math:`\underline{y} \leftarrow a
\underline{x} + \underline{y}`), a name borrowed from standard linear algebra
libraries; ``xpy`` and ``nxpy`` are the cases :math:`a = 1` and
:math:`a = -1`. An ``inv`` suffix on a vector means its negative, so
``ksl_cross_vvinv`` computes :math:`\underline{v}_1 \times
(-\underline{v}_2)`.

Double precision
----------------

.. doxygenunion:: ksl_vec3_t


.. doxygenfunction:: ksl_vec3


.. doxygenfunction:: ksl_vec3_alloc


.. doxygenfunction:: ksl_vec3_l2norm


.. doxygenfunction:: ksl_vec3_normalize


.. doxygenfunction:: ksl_vec3_normalized


.. doxygenfunction:: ksl_vec3_scale


.. doxygenfunction:: ksl_vec3_scaled


.. doxygenfunction:: ksl_vec3_copy


.. doxygenfunction:: ksl_vec3_swap


.. doxygenfunction:: ksl_vec3_inverted


.. doxygenfunction:: ksl_vec3_invert


.. doxygenfunction:: ksl_dot_vv


.. doxygenfunction:: ksl_product_av


.. doxygenfunction:: ksl_product_avinv


.. doxygenfunction:: ksl_product_ainvv


.. doxygenfunction:: ksl_add_vv


.. doxygenfunction:: ksl_subtract_vv


.. doxygenfunction:: ksl_axpy_vv


.. doxygenfunction:: ksl_nxpy_vv


.. doxygenfunction:: ksl_xpy_vv


.. doxygenfunction:: ksl_cross_vv


.. doxygenfunction:: ksl_cross_vvinv


.. doxygenfunction:: ksl_add_vvx


.. doxygenfunction:: ksl_add_vvxinv


.. doxygenfunction:: ksl_add_vvy


.. doxygenfunction:: ksl_add_vvyinv


.. doxygenfunction:: ksl_add_vvz


.. doxygenfunction:: ksl_add_vvzinv




Single precision
----------------

.. doxygenunion:: ksl_vec3f_t


.. doxygenfunction:: ksl_vec3f


.. doxygenfunction:: ksl_vec3f_alloc


.. doxygenfunction:: ksl_vec3f_l2norm


.. doxygenfunction:: ksl_vec3f_normalize


.. doxygenfunction:: ksl_vec3f_normalized


.. doxygenfunction:: ksl_vec3f_scale


.. doxygenfunction:: ksl_vec3f_scaled


.. doxygenfunction:: ksl_vec3f_copy


.. doxygenfunction:: ksl_vec3f_swap


.. doxygenfunction:: ksl_vec3f_inverted


.. doxygenfunction:: ksl_vec3f_invert


.. doxygenfunction:: ksl_dot_vvf


.. doxygenfunction:: ksl_product_avinvf


.. doxygenfunction:: ksl_product_avf


.. doxygenfunction:: ksl_add_vvf


.. doxygenfunction:: ksl_subtract_vvf


.. doxygenfunction:: ksl_axpy_vvf


.. doxygenfunction:: ksl_nxpy_vvf


.. doxygenfunction:: ksl_xpy_vvf


.. doxygenfunction:: ksl_cross_vvf


.. doxygenfunction:: ksl_cross_vvinvf


.. doxygenfunction:: ksl_add_vvxf


.. doxygenfunction:: ksl_add_vvxinvf


.. doxygenfunction:: ksl_add_vvyf


.. doxygenfunction:: ksl_add_vvyinvf


.. doxygenfunction:: ksl_add_vvzf


.. doxygenfunction:: ksl_add_vvzinvf



Integer
-------

.. doxygenunion:: ksl_vec3i_t


.. doxygenfunction:: ksl_vec3i


.. doxygenfunction:: ksl_vec3i_alloc


.. doxygenfunction:: ksl_vec3i_isEqual
