.. title:: About

About
=====

*KSL* is a sparse math library written in the C programming language that is targeted to real-time kinematics, dynamics, contact detection, robotics and 3D visualization applications.

*KSL* contains a number of utility functions to transform vectors, screws, coscrews and spatial inertia matrices using the minimum number of operations as described in this documentation. Additionally, *KSL* contains routines for performing LU decomposition with complete row and column pivoting, an important component in the robust processing of kinematics and dynamics equations.

Purpose and design
------------------

Multibody dynamics, robotics and contact detection codes spend much of their
run time applying many small rigid-body transformations: composing joint
displacements down a kinematic chain, moving velocity screws and force
coscrews between frames, and transforming mass properties. General-purpose
linear algebra libraries express these operations as products of dense 4x4 or
6x6 matrices. That stores entries that are always zero or one and spends
floating point operations multiplying them.

*KSL* instead provides a kernel for each operation, written to use as little
data and as few floating point operations as possible:

* **Compact data structures.** A rigid-body displacement is stored as a 3x3
  rotation and a translation (12 values) rather than a 4x4 matrix, and mass
  properties as the mass, first moment and 6 unique inertia terms (10 values)
  rather than a 6x6 spatial inertia matrix. Screws, coscrews and quaternions
  are plain 6- and 4-element unions.
* **Specialized kernels instead of matrices.** Adjoint and coadjoint
  transformations of screws and coscrews work directly from the rotation and
  translation without forming a 6x6 matrix. Inverse transformations
  (``dinv``) are applied without computing an inverse. Rotations about a
  coordinate axis (``drx``, ``dry``, ``drz``, ``qx``, ``qy``, ``qz``) take the
  direction cosines ``[sin, cos]`` of the angle and update only the terms that
  change. Pure translations (``dtx``, ``dty``, ``dtz``, ``Adt``) and pure
  rotations (``dr``, ``Adr``) have their own kernels as well.
* **Inlined and allocation free.** The kernels are ``static inline``
  functions in the headers, so the compiler can inline them into the calling
  code and keep intermediate values in registers. They write into
  caller-provided outputs and never allocate memory.
* **Portable C.** *KSL* is written in C11, compiles as C++, and provides
  double precision functions alongside single precision versions with an
  ``f`` suffix.

:ref:`performance` compares these kernels with equivalent code written using
Eigen.

Availability
------------

The code is available open-source with minimal restrictions. If you find the code to be useful in your projects, we would love to hear from you.

This website is a work in progress. Please refer to the `GitHub issues <https://github.com/shift-dynamics/ksl/issues>`_ page for the latest development status.
