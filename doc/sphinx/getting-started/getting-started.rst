.. _getting-started:
.. title:: Getting Started

Getting Started
===============

This page shows how to add *KSL* to a program and explains the conventions
used in its data structures and function names. :ref:`installation` covers
building the library itself.

Using KSL in your project
-------------------------

Include ``ksl/ksl.h`` to get the data types and nearly all of the functions.
A few headers are not included by ``ksl/ksl.h`` and must be included
separately when they are needed:

* ``ksl/trig.h``: ``ksl_dc()`` (the ``{sin, cos}`` pair of an angle) and angle
  normalization
* ``ksl/eulerangles.h``: Euler angle types
* ``ksl/memory.h``: allocation of two-dimensional arrays

Most functions are ``static inline`` functions defined in the headers. The
rest (LU factorization, matrix inversion, printing, trigonometry utilities)
are in a small static library, so a program also needs to link against
``libksl`` and the math library ``-lm``.

**With meson**, add *KSL* as a subproject by placing a wrap file in
``subprojects/ksl.wrap``:

.. code::

   [wrap-git]
   url = https://github.com/shift-dynamics/ksl.git
   revision = master

   [provide]
   dependency_names = ksl

and use it as a dependency:

.. code::

   ksl_dep = dependency('ksl')
   executable('myprogram', 'main.c', dependencies: ksl_dep)

**Without meson**, build *KSL* as described in :ref:`installation`, then add
the repository root to the include path and link the static library:

.. code::

   cc -std=c11 -O2 -I path/to/ksl main.c path/to/ksl/build/libksl.a -lm

*KSL* is written in C11 and can also be included from C++.

Data layout
-----------

All types are unions, so the same data can be read as named fields or as
an array.

* ``ksl_vec3_t``: ``x``, ``y``, ``z``, or ``at[3]``.
* ``ksl_mat3x3_t``: a 3x3 matrix stored in **column major** order.
  ``at[j][i]`` is row ``i`` of column ``j``, ``m01`` is row 0 of column 1, and
  ``v[j]`` (or ``v0``, ``v1``, ``v2``) is column ``j`` as a ``ksl_vec3_t``.
* ``ksl_SE3_t``: a rigid body transformation (displacement) :math:`D = (R, t)`,
  stored as a rotation matrix ``R`` followed by a translation ``t``, 12 values
  in all. The same data is ``at[4][3]`` in column major order, so the
  translation is ``at[3]`` (or ``v3``). It acts on a point as
  :math:`D p = R p + t`.
* ``ksl_screw_t``: a 6 element screw, such as a velocity, with a linear part
  ``lin`` followed by an angular part ``ang``. For a velocity screw,
  ``lin`` is the velocity of the body point that is momentarily at the origin
  of the frame the screw is expressed in, and ``ang`` is the angular velocity.
* ``ksl_coscrew_t``: a 6 element coscrew, such as a force, with a linear
  part ``lin`` (the force) followed by an angular part ``ang`` (the moment
  about the origin).
* ``ksl_quaternion_t``: ``x``, ``y``, ``z``, ``w``, with the scalar part
  ``w`` last.
* ``ksl_inertia_t``: the mass, the first moment of mass and the 6 unique
  terms of the inertia matrix, 10 values in all.

Every type has a single precision version with an ``f`` suffix, for example
``ksl_SE3f_t``.

Naming conventions
------------------

Function names describe the operation and the operands. For example,
``ksl_product_dv`` is the product of a displacement ``d`` and a vector ``v``,
and ``ksl_product_Adsinv`` applies the adjoint ``Ad`` to a negated screw
``sinv``. The operand abbreviations are:

.. list-table::
   :header-rows: 1
   :widths: 20 25 55

   * - Abbreviation
     - Argument type
     - Meaning
   * - ``d``
     - ``ksl_SE3_t``
     - rigid body transformation (displacement), :math:`D = (R, t)`
   * - ``dr``
     - ``ksl_mat3x3_t``
     - rotation only, :math:`(R, 0)`
   * - ``drx``, ``dry``, ``drz``
     - ``double dc[2]``
     - rotation about the x, y or z axis, given as ``{sin, cos}`` of the angle
   * - ``dtx``, ``dty``, ``dtz``
     - ``double``
     - translation along the x, y or z axis
   * - ``qx``, ``qy``, ``qz``
     - ``double dc[2]``
     - quaternion for a rotation about the x, y or z axis, given as
       ``{sin, cos}``
   * - ``v``
     - ``ksl_vec3_t``
     - vector
   * - ``s``
     - ``ksl_screw_t``
     - screw
   * - ``c``
     - ``ksl_coscrew_t``
     - coscrew
   * - ``q``
     - ``ksl_quaternion_t``
     - quaternion
   * - ``a``
     - ``double``
     - scalar
   * - ``Ad``, ``CoAd``
     - ``ksl_SE3_t``
     - adjoint (for screws) and coadjoint (for coscrews) of a
       transformation, applied without forming a 6x6 matrix
   * - ``Adr``, ``CoAdr``
     - ``ksl_mat3x3_t``
     - adjoint and coadjoint of a rotation only
   * - ``Adt``, ``CoAdt``
     - ``ksl_vec3_t``
     - adjoint and coadjoint of a translation only
   * - ``hs``, ``hc``
     - ``ksl_SE3_t``
     - the screw of a joint axis, or the coscrew of a force or moment along
       an axis, of a frame given by a transformation (see below)

The suffix ``inv`` changes the meaning of an operand:

* after a transformation (``dinv``, ``drinv``, ``Adinv``) it means the
  **inverse** transformation. The inverse is applied directly; it is never
  computed and stored.
* after a vector, screw or coscrew (``vinv``, ``sinv``, ``cinv``) it means the
  **negative** of that quantity.

Functions that end in ``ed`` (``ksl_SE3_inverted``, ``ksl_vec3_normalized``)
write the result to a separate output. The same name without ``ed``
(``ksl_SE3_invert``) works in place.

The ``hs`` and ``hc`` functions return the axis quantities of a frame
:math:`D`: ``ksl_hsrz(D)`` is the screw of a revolute joint about the frame's
z axis, :math:`\mathrm{Ad}(D) \{0, e_z\}`; ``ksl_hstz(D)`` is the screw of a
prismatic joint along it, :math:`\mathrm{Ad}(D) \{e_z, 0\}`. Likewise
``ksl_hctz(D)`` is a unit force along the z axis and ``ksl_hcrz(D)`` a unit
moment about it.

Axis rotations take ``{sin, cos}``
**********************************

Functions for rotations about a coordinate axis take the angle as a two
element array ``dc = {sin(theta), cos(theta)}`` rather than the angle itself.
A program often needs the same rotation several times, and this way the sine
and cosine are computed only once. Use ``ksl_dc()`` from ``ksl/trig.h`` to
fill the array:

.. code-block:: c

   double dc[2];
   ksl_dc(theta, dc);           /* dc = {sin(theta), cos(theta)} */
   ksl_product_ddrz(&D, dc, &Do); /* Do = D * Rz(theta) */

The order is always sine first, then cosine.

Inputs and outputs
******************

Inputs come first and outputs last. Function arguments are pointers; outputs
are written into memory provided by the caller and the library never
allocates memory, except for the functions in ``ksl/memory.h``. Inputs and
outputs of a function must not overlap unless the documentation says
otherwise, because the functions are declared with ``restrict`` pointers. Use
the in-place version of a function, where one exists, to overwrite an input.

Example
-------

This program computes the tip position and tip velocity of a planar arm with
two revolute joints, and compares them with the closed-form result. It is
built and run as part of the *KSL* test suite.

.. literalinclude:: two_link.c
   :language: c

Its output is:

.. code::

   tip position  ksl:  0.689983  0.001444  0.000000
           closed form:  0.689983  0.001444  0.000000
   tip velocity  ksl:  0.288887  0.827167  0.000000
           closed form:  0.288887  0.827167  0.000000
