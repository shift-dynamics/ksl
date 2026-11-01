.. _axis:
.. title:: Axes and Euler Angles

Axes and Euler Angles
=====================

``ksl/axis.h`` names the twelve Euler angle rotation sequences, such as
``KSL_AXIS_ZYX``. The functions that convert between rotation matrices and
Euler angles, ``ksl_mat3x3_getEulerAngles()`` and
``ksl_mat3x3_setFromEulerAngles()``, are described with the
:ref:`3x3 matrices <mat3x3>`.

.. doxygenenum:: ksl_axis_enum_t


.. doxygenfunction:: ksl_axis_getVector


.. doxygenfunction:: ksl_axis_getEulerAngles


Euler angle types
-----------------

These types are in ``ksl/eulerangles.h``, which must be included separately.

.. doxygenstruct:: ksl_eulerangles_t


.. doxygenstruct:: ksl_euleranglesf_t
