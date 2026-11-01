.. _axis:
.. title:: Axes and Euler Angles

Axes and Euler Angles
=====================

Overview
--------

**Euler angles** describe an orientation as three successive rotations about
coordinate axes. ``ksl/axis.h`` names the twelve possible axis sequences. For
``KSL_AXIS_XYZ`` with angles :math:`(\alpha, \beta, \gamma)`, the rotation
matrix is

.. math::

   R = R_x(\alpha)\, R_y(\beta)\, R_z(\gamma)

that is, a rotation about x, then about the new y axis, then about the newest
z axis. Six sequences use three different axes (``XYZ``, ``ZYX``, ...; often
called Tait-Bryan or roll-pitch-yaw angles) and six repeat the first axis
(``ZXZ``, ``ZYZ``, ...; the classical Euler angles). The comment after each
value in ``ksl_axis_enum_t`` lists its axes as indices, 0 = x, 1 = y, 2 = z.

Euler angles are easy to read and to specify by hand, which makes them common
in input files and user interfaces. They have two drawbacks:

* **Singular orientations (gimbal lock).** When the middle rotation lines up
  the first and third axes (:math:`\beta = \pm 90^\circ` for the three-axis
  sequences, :math:`\beta = 0` or :math:`180^\circ` for the repeated-axis
  ones), only the sum or difference of the first and third angles is defined,
  and the angles change very quickly near that orientation.
* **Wrap-around.** Each angle is only defined up to a multiple of
  :math:`2\pi`.

``ksl_mat3x3_getEulerAngles()`` (see :ref:`mat3x3`) accepts the angles of a
nearby previous orientation as an optional last argument and returns the
solution closest to them, so a sequence of orientations gives continuous
angles. For computation, rotation matrices or quaternions (see
:ref:`quaternions`) avoid both problems. :cite:`kuipers1999quaternions`
discusses rotation sequences in detail.

The functions that convert between rotation matrices and Euler angles,
``ksl_mat3x3_getEulerAngles()`` and ``ksl_mat3x3_setFromEulerAngles()``, are
described with the :ref:`3x3 matrices <mat3x3>`. The Euler angle types are in
``ksl/eulerangles.h``, which must be included separately.

Axis sequences
--------------

.. doxygenenum:: ksl_axis_enum_t


.. doxygenfunction:: ksl_axis_getVector


.. doxygenfunction:: ksl_axis_getEulerAngles


Euler angle types
-----------------

These types are in ``ksl/eulerangles.h``, which must be included separately.

.. doxygenstruct:: ksl_eulerangles_t


.. doxygenstruct:: ksl_euleranglesf_t
