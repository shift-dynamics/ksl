.. _trig:
.. title:: Trigonometric Functions

Trigonometric Functions
=======================

Overview
--------

**Sine and cosine pairs.** *KSL* functions that rotate about a coordinate axis
take the angle as the two-element array ``{sin(theta), cos(theta)}`` rather
than the angle itself. Sine and cosine are among the most expensive
operations in a kinematics calculation, and the same joint angle is usually
needed by several functions in one time step. ``ksl_dc()`` computes the pair
once, and every function that uses it then needs only multiplications and
additions:

.. code-block:: c

   double dc[2];
   ksl_dc(theta, dc);              /* dc = {sin(theta), cos(theta)} */
   ksl_product_ddrz(&D, dc, &Do);  /* Do = D * Rz(theta) */

**Angle ranges.** ``ksl_normalizeRadians()`` and ``ksl_normalizeDegrees()``
wrap an angle into :math:`[0, 2\pi)` or :math:`[0, 360)`.

**Continuous angles.** The standard ``atan2(y, x)`` returns an angle in
:math:`(-\pi, \pi]`, so an angle that keeps increasing, such as a wheel or a
motor shaft, jumps by :math:`2\pi` every revolution. ``ksl_catan2pi()`` returns the
angle that matches ``atan2(y, x)`` and is closest to a previous value, so the
result stays continuous through any number of turns, as long as the angle
changes by less than :math:`\pi/4` between calls. ``ksl_catan1pi()`` is the
version for when the signs of ``x`` and ``y`` are not known and the angle is
only defined up to a multiple of :math:`\pi`. The Euler angle functions use
them to keep angles continuous (see :ref:`axis`).

These functions are declared in ``ksl/trig.h``, which must be included
separately from ``ksl/ksl.h``.

Functions
---------

.. doxygenfunction:: ksl_dc


.. doxygenfunction:: ksl_dcf


.. doxygenfunction:: ksl_normalizeDegrees


.. doxygenfunction:: ksl_normalizeDegreesf


.. doxygenfunction:: ksl_normalizeRadians


.. doxygenfunction:: ksl_normalizeRadiansf


.. doxygenfunction:: ksl_catan2pi


.. doxygenfunction:: ksl_catan2pif


.. doxygenfunction:: ksl_catan1pi


.. doxygenfunction:: ksl_catan1pif
