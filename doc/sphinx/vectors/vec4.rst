.. _vec4:
.. title:: 4D Vectors

4D Vectors
==========

Overview
--------

A 4D vector in *KSL* is a 3D vector with a fourth component :math:`w`
appended, called the *homogeneous coordinate*:

.. math::

   \begin{Bmatrix} x \\ y \\ z \\ w \end{Bmatrix}

**Points and directions.** In homogeneous coordinates a point
:math:`\underline{p}` is written :math:`\{\underline{p}, 1\}` and a direction
(a free vector such as a velocity or a force) is written
:math:`\{\underline{d}, 0\}`. A rigid body transformation then becomes a single
4x4 matrix product (see :ref:`SE3`):

.. math::

   \begin{bmatrix} R & \underline{t} \\ 0 & 1 \end{bmatrix}
   \begin{Bmatrix} \underline{p} \\ 1 \end{Bmatrix} =
   \begin{Bmatrix} R \underline{p} + \underline{t} \\ 1 \end{Bmatrix}, \qquad
   \begin{bmatrix} R & \underline{t} \\ 0 & 1 \end{bmatrix}
   \begin{Bmatrix} \underline{d} \\ 0 \end{Bmatrix} =
   \begin{Bmatrix} R \underline{d} \\ 0 \end{Bmatrix}

so a point is rotated and translated, while a direction is only rotated, as it
should be.

**Camera projection.** The homogeneous coordinate is what makes perspective
projection possible with matrices. A pinhole camera maps a point with
coordinates :math:`\{x, y, z\}` in the camera frame to the image point

.. math::

   u = f \frac{x}{z} + c_u, \qquad v = f \frac{y}{z} + c_v

where :math:`f` is the focal length in pixels and :math:`(c_u, c_v)` is the
image center. The division by the depth :math:`z` cannot be written as a
matrix product on 3D vectors. In homogeneous coordinates it can: the product

.. math::

   \begin{Bmatrix} w u \\ w v \\ w \end{Bmatrix} =
   \begin{bmatrix} f & 0 & c_u \\ 0 & f & c_v \\ 0 & 0 & 1 \end{bmatrix}
   \begin{bmatrix} R & \underline{t} \end{bmatrix}
   \begin{Bmatrix} \underline{p} \\ 1 \end{Bmatrix}

is linear, and the image point is recovered by dividing by the last
component :math:`w` (the *perspective divide*). Any nonzero multiple of a
homogeneous vector represents the same point. Graphics interfaces such as
OpenGL and Vulkan use the same idea with 4x4 projection matrices acting on 4D
vectors. :cite:`hartley2004multiple` covers camera models and projective
geometry in depth.

**In KSL.** Rigid body transformations do not need the homogeneous
coordinate: the ``ksl_SE3_t`` functions compute
:math:`R \underline{p} + \underline{t}` directly, without storing or
multiplying the extra row. ``ksl_vec4_t`` is provided for data that has a
:math:`w` component, for example when exchanging data with graphics or vision
code.

**Storage.** ``ksl_vec4_t`` holds four ``double`` values, 32 bytes
(``ksl_vec4f_t``: 16 bytes). The components can be read as ``x``, ``y``,
``z``, ``w``, as ``at[0]`` to ``at[3]``, or the first three together as a
``ksl_vec3_t`` named ``r``:

.. code-block:: c

   ksl_vec4_t p = ksl_vec4(1.0, 2.0, 3.0, 1.0);
   double w = p.w;
   ksl_vec3_t r = p.r;   /* {1, 2, 3} */

Double precision
----------------

.. doxygenunion:: ksl_vec4_t


.. doxygenfunction:: ksl_vec4


.. doxygenfunction:: ksl_vec4_alloc


.. doxygenfunction:: ksl_vec4_l2norm


.. doxygenfunction:: ksl_vec4_normalize


.. doxygenfunction:: ksl_vec4_normalized


.. doxygenfunction:: ksl_vec4_scale


.. doxygenfunction:: ksl_vec4_scaled


.. doxygenfunction:: ksl_vec4_copy


.. doxygenfunction:: ksl_vec4_swap


.. doxygenfunction:: ksl_vec4_inverted


.. doxygenfunction:: ksl_vec4_invert


Single precision
----------------

.. doxygenunion:: ksl_vec4f_t


.. doxygenfunction:: ksl_vec4f


.. doxygenfunction:: ksl_vec4f_alloc


.. doxygenfunction:: ksl_vec4f_l2norm


.. doxygenfunction:: ksl_vec4f_normalize


.. doxygenfunction:: ksl_vec4f_normalized


.. doxygenfunction:: ksl_vec4f_scale


.. doxygenfunction:: ksl_vec4f_scaled


.. doxygenfunction:: ksl_vec4f_copy


.. doxygenfunction:: ksl_vec4f_swap


.. doxygenfunction:: ksl_vec4f_inverted


.. doxygenfunction:: ksl_vec4f_invert


Integer
-------

.. doxygenunion:: ksl_vec4i_t


.. doxygenfunction:: ksl_vec4i


.. doxygenfunction:: ksl_vec4i_alloc
