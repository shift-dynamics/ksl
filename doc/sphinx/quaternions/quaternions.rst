.. _quaternions:
.. title:: Quaternions

Quaternions
===========

Overview
--------

A unit quaternion is a compact, well-behaved way to represent a rotation. A
rotation by angle :math:`\theta` about the unit axis :math:`\underline{e}` is
the quaternion

.. math::

   q = \begin{Bmatrix} \underline{e} \sin(\theta/2) \\ \cos(\theta/2)
   \end{Bmatrix} = \begin{Bmatrix} x \\ y \\ z \\ w \end{Bmatrix},
   \qquad x^2 + y^2 + z^2 + w^2 = 1

The first three components form the vector part and :math:`w` is the scalar
part. Note the **half angle**: :math:`q` and :math:`-q` describe the same
rotation.

Compared with a rotation matrix, a quaternion uses 4 numbers instead of 9 and
is easily brought back to unit length after round-off
(``ksl_quaternion_normalize()``). Compared with Euler angles, it has no
singular orientations (no gimbal lock, see :ref:`axis`), and two orientations
can be interpolated smoothly along the shortest path with spherical linear
interpolation, *slerp* (``ksl_quaternion_slerp()``)
:cite:`shoemake1985animating`. The time derivative of a quaternion is linear
in the angular velocity, which makes quaternions convenient as orientation
coordinates for integrating the equations of motion
(``ksl_omega_to_dquaternion()``). :cite:`kuipers1999quaternions` is a readable
introduction.

**Products.** Quaternions are multiplied with the Hamilton product, in which
:math:`ij = k`. The product composes rotations in the same order as rotation
matrices: if :math:`q_1` and :math:`q_2` correspond to :math:`R_1` and
:math:`R_2`, then :math:`q_1 q_2` corresponds to :math:`R_1 R_2`. The
conjugate :math:`q^* = \{-\underline{e}\sin(\theta/2), \cos(\theta/2)\}` is
the inverse rotation; ``conj`` in a function name means the conjugate of that
operand, so ``ksl_product_qconjq`` computes :math:`q_1^* q_2`.
``ksl_mat3x3_toQuaternion()`` and ``ksl_quaternion_toMat3x3()`` convert to and
from rotation matrices.

**Axis quaternions take the half angle.** ``ksl_product_qxq`` and the other
``qx``, ``qy`` and ``qz`` functions multiply by a rotation about a coordinate
axis given as a ``{sin, cos}`` pair. For a quaternion that pair is
:math:`\{\sin(\theta/2), \cos(\theta/2)\}`, whereas the matrix functions
(``drx`` and so on) take :math:`\{\sin\theta, \cos\theta\}`:

.. code-block:: c

   double dc_half[2];
   ksl_dc(0.5 * theta, dc_half);       /* not ksl_dc(theta, ...) */
   ksl_product_qxq(dc_half, &q, &qo);  /* qo = qx(theta) * q */

**Storage.** ``ksl_quaternion_t`` holds four ``double`` values, 32 bytes
(``ksl_quaternionf_t``: 16 bytes), with the scalar part **last**: ``x``,
``y``, ``z``, ``w``, or ``at[0]`` to ``at[3]``, or the vector part as a
``ksl_vec3_t`` named ``r``. Some other libraries store the scalar first, so
check the order when exchanging data.

Double precision
----------------

.. doxygenunion:: ksl_quaternion_t


.. doxygenfunction:: ksl_quaternion_alloc


.. doxygenfunction:: ksl_dot_qq


.. doxygenfunction:: ksl_quaternion_normalize


.. doxygenfunction:: ksl_axpy_qq


.. doxygenfunction:: ksl_mat3x3_toQuaternion


.. doxygenfunction:: ksl_quaternion_toMat3x3


.. doxygenfunction:: ksl_quaternion_slerp


.. doxygenfunction:: ksl_quaternion_nlerp


.. doxygenfunction:: ksl_add_dpiToq


.. doxygenfunction:: ksl_subtract_dpiFromq


.. doxygenfunction:: ksl_omega_to_dquaternion


.. doxygenfunction:: ksl_product_qq


.. doxygenfunction:: ksl_product_qconjq


.. doxygenfunction:: ksl_product_qqconj


.. doxygenfunction:: ksl_product_qconjqconj


.. doxygenfunction:: ksl_product_qxq


.. doxygenfunction:: ksl_product_qqx


.. doxygenfunction:: ksl_product_qxconjq


.. doxygenfunction:: ksl_product_qconjqx


.. doxygenfunction:: ksl_product_qxqconj


.. doxygenfunction:: ksl_product_qqxconj


.. doxygenfunction:: ksl_product_qxconjqconj


.. doxygenfunction:: ksl_product_qconjqxconj


.. doxygenfunction:: ksl_product_qyq


.. doxygenfunction:: ksl_product_qqy


.. doxygenfunction:: ksl_product_qyconjq


.. doxygenfunction:: ksl_product_qconjqy


.. doxygenfunction:: ksl_product_qyqconj


.. doxygenfunction:: ksl_product_qqyconj


.. doxygenfunction:: ksl_product_qyconjqconj


.. doxygenfunction:: ksl_product_qconjqyconj


.. doxygenfunction:: ksl_product_qzq


.. doxygenfunction:: ksl_product_qqz


.. doxygenfunction:: ksl_product_qzconjq


.. doxygenfunction:: ksl_product_qconjqz


.. doxygenfunction:: ksl_product_qzqconj


.. doxygenfunction:: ksl_product_qqzconj


.. doxygenfunction:: ksl_product_qzconjqconj


.. doxygenfunction:: ksl_product_qconjqzconj


.. doxygenfunction:: ksl_product_qv


.. doxygenfunction:: ksl_product_qconjv


.. doxygenfunction:: ksl_product_vq


.. doxygenfunction:: ksl_product_vqconj


.. doxygenfunction:: ksl_quaternion



Single precision
----------------

.. doxygenunion:: ksl_quaternionf_t


.. doxygenfunction:: ksl_quaternionf_alloc


.. doxygenfunction:: ksl_quaternionf_normalize


.. doxygenfunction:: ksl_mat3x3f_toQuaternion


.. doxygenfunction:: ksl_dot_qqf


.. doxygenfunction:: ksl_axpy_qqf


.. doxygenfunction:: ksl_quaternionf_toMat3x3f


.. doxygenfunction:: ksl_quaternionf_slerp


.. doxygenfunction:: ksl_quaternionf_nlerp


.. doxygenfunction:: ksl_product_qqf


.. doxygenfunction:: ksl_product_qconjqf


.. doxygenfunction:: ksl_product_qqconjf


.. doxygenfunction:: ksl_product_qconjqconjf


.. doxygenfunction:: ksl_product_qxqf


.. doxygenfunction:: ksl_product_qqxf


.. doxygenfunction:: ksl_product_qxconjqf


.. doxygenfunction:: ksl_product_qconjqxf


.. doxygenfunction:: ksl_product_qxqconjf


.. doxygenfunction:: ksl_product_qqxconjf


.. doxygenfunction:: ksl_product_qxconjqconjf


.. doxygenfunction:: ksl_product_qconjqxconjf


.. doxygenfunction:: ksl_product_qyqf


.. doxygenfunction:: ksl_product_qqyf


.. doxygenfunction:: ksl_product_qyconjqf


.. doxygenfunction:: ksl_product_qconjqyf


.. doxygenfunction:: ksl_product_qyqconjf


.. doxygenfunction:: ksl_product_qqyconjf


.. doxygenfunction:: ksl_product_qyconjqconjf


.. doxygenfunction:: ksl_product_qconjqyconjf


.. doxygenfunction:: ksl_product_qzqf


.. doxygenfunction:: ksl_product_qqzf


.. doxygenfunction:: ksl_product_qzconjqf


.. doxygenfunction:: ksl_product_qconjqzf


.. doxygenfunction:: ksl_product_qzqconjf


.. doxygenfunction:: ksl_product_qqzconjf


.. doxygenfunction:: ksl_product_qzconjqconjf


.. doxygenfunction:: ksl_product_qconjqzconjf


.. doxygenfunction:: ksl_product_qvf


.. doxygenfunction:: ksl_product_qconjvf


.. doxygenfunction:: ksl_product_vqf


.. doxygenfunction:: ksl_product_vqconjf


.. doxygenfunction:: ksl_quaternionf
