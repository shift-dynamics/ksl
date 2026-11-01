.. _performance:
.. title:: Performance

Performance compared to Eigen
=============================

`Eigen <https://eigen.tuxfamily.org>`_ is the most widely used C++ library for
small fixed-size linear algebra, and its ``Isometry3d``, ``Quaterniond`` and
fixed-size matrix types are a common way to write kinematics code. This page
compares *KSL* kernels with the equivalent Eigen code.

For each operation, Eigen is timed in up to two forms:

* **Eigen R, t**: hand-written code on a compact ``{Matrix3d R; Vector3d t;}``
  pair, which has the same 96-byte footprint as ``ksl_SE3_t``. This is the
  fastest way we found to express each operation in Eigen. For an inertia
  transform it computes :math:`R I R^T` plus the parallel-axis term with
  ``Matrix3d``.
* **Eigen generic**: the general-purpose type a typical program would reach
  for, such as ``Isometry3d`` (128 bytes, a full 4x4 matrix) or a 6x6 adjoint
  or spatial inertia matrix (288 bytes).

Results
-------

Times are nanoseconds per operation; lower is better. *Speedup* is the fastest
Eigen variant divided by *KSL*, so values above 1 mean *KSL* is faster.

Portable build (``-O3 -march=x86-64``)
**************************************

.. list-table::
   :header-rows: 1
   :widths: 30 25 10 10 15 10

   * - Operation
     - KSL function
     - KSL
     - Eigen R, t
     - Eigen generic
     - Speedup
   * - SE3 product
     - ``ksl_product_dd``
     - 4.08
     - 4.94
     - 6.05 (Isometry3d)
     - 1.2x
   * - Inverse SE3 product
     - ``ksl_product_dinvd``
     - 4.85
     - 3.87
     - 6.62 (Isometry3d)
     - 0.8x
   * - Transform a point
     - ``ksl_product_dv``
     - 1.12
     - 1.41
     - 1.61 (Isometry3d)
     - 1.3x
   * - Rotation about z
     - ``ksl_product_ddrz``
     - 2.68
     - 3.44
     - 3.93 (R * Rz)
     - 1.3x
   * - Adjoint of a screw
     - ``ksl_product_Ads``
     - 3.05
     - 2.56
     - 3.64 (6x6)
     - 0.8x
   * - CoAdjoint of a coscrew
     - ``ksl_product_CoAdc``
     - 3.05
     - 2.57
     - 3.14 (6x6)
     - 0.8x
   * - Quaternion product
     - ``ksl_product_qq``
     - 1.48
     -
     - 1.48 (Quaterniond)
     - 1.0x
   * - Inertia transform
     - ``ksl_inertia_transformed``
     - 7.67
     - 25.78
     - 37.41 (6x6)
     - 3.4x
   * - Kinematic chain (latency)
     - ``ksl_product_dd``
     - 5.98
     - 4.95
     - 6.75 (Isometry3d)
     - 0.8x

Native build (``-O3 -march=native``)
************************************

.. list-table::
   :header-rows: 1
   :widths: 30 25 10 10 15 10

   * - Operation
     - KSL function
     - KSL
     - Eigen R, t
     - Eigen generic
     - Speedup
   * - SE3 product
     - ``ksl_product_dd``
     - 4.49
     - 6.32
     - 13.37 (Isometry3d)
     - 1.4x
   * - Inverse SE3 product
     - ``ksl_product_dinvd``
     - 4.65
     - 6.46
     - 24.89 (Isometry3d)
     - 1.4x
   * - Transform a point
     - ``ksl_product_dv``
     - 0.97
     - 4.62
     - 9.54 (Isometry3d)
     - 4.8x
   * - Rotation about z
     - ``ksl_product_ddrz``
     - 2.34
     - 3.25
     - 4.07 (R * Rz)
     - 1.4x
   * - Adjoint of a screw
     - ``ksl_product_Ads``
     - 3.18
     - 9.71
     - 3.48 (6x6)
     - 1.1x
   * - CoAdjoint of a coscrew
     - ``ksl_product_CoAdc``
     - 2.66
     - 9.81
     - 3.11 (6x6)
     - 1.2x
   * - Quaternion product
     - ``ksl_product_qq``
     - 0.90
     -
     - 0.81 (Quaterniond)
     - 0.9x
   * - Inertia transform
     - ``ksl_inertia_transformed``
     - 6.18
     - 36.70
     - 31.59 (6x6)
     - 5.1x
   * - Kinematic chain (latency)
     - ``ksl_product_dd``
     - 6.65
     - 8.97
     - 15.24 (Isometry3d)
     - 1.3x

Observations
------------

* **KSL matches or beats Eigen's general-purpose types.** Against
  ``Isometry3d`` and 6x6 matrices, every *KSL* kernel is as fast or faster.
  The quaternion product ties ``Quaterniond`` in the portable build, and
  ``Quaterniond`` is about 10% faster with ``-march=native``.
* **The largest gain is the inertia transform:** 3.4x in the portable build
  and 5.1x with ``-march=native``. *KSL* transforms the 10 independent mass
  and inertia terms directly instead of forming :math:`R I R^T` or a 6x6
  product.
* **With** ``-march=native``, **KSL is faster on every kernel except the
  quaternion product.** The gains range from 1.1x (adjoint) to 5.1x
  (inertia transform).
* **In the portable build, hand-written Eigen code is faster on four
  kernels.** Eigen code written directly on ``R`` and ``t`` takes about
  15-20% less time for the inverse product, the adjoint, the coadjoint and the dependent
  kinematic chain. *KSL* is faster for the SE3 product (1.2x), point transform
  (1.3x), axis rotation (1.3x) and inertia transform.
* **The quaternion product matches Eigen.** The general quaternion products
  are hand-vectorized with SSE2, using SSE3's ``addsub`` when available, as
  Eigen's are. They tie Eigen in the portable build and are within 10% with
  ``-march=native``. Define ``KSL_NO_SIMD`` to use the portable scalar code
  instead.
* **Eigen's fixed-size code does not always benefit from** ``-march=native``.
  With AVX enabled, the ``Isometry3d`` products, the point transform and the
  hand-written adjoint became roughly 2-6x slower than in the portable build.
  The *KSL* kernels changed by about 10% or less, or became faster.
* **Data size.** ``ksl_SE3_t`` is 96 bytes, against 128 bytes for
  ``Isometry3d``. ``ksl_inertia_t`` is 80 bytes, against 288 bytes for a 6x6
  spatial inertia matrix.

Method
------

All results were measured on 2026-10-31 on an Intel Core i9-14900K with GCC
16.2.1 and Eigen 5.0.1, using double precision.

* The *KSL* kernels are ``static inline`` functions in its headers, so both
  libraries are compiled in the same translation unit with the same flags.
* Every operation is applied to an array of 512 independent inputs, a working
  set that fits in cache, so the timings measure throughput. Each timing is the
  minimum of 9 samples of 4000 passes over the array.
* The kinematic chain row instead multiplies 512 transforms in sequence, with
  each product depending on the previous result, so it measures latency.
* The benchmark checks *KSL* against Eigen before timing. Results agree to
  within :math:`2 \times 10^{-15}`.
* Each configuration was run 7 times, pinned to a single core of an otherwise
  idle machine. The tables show the median of those runs, which agreed within
  a few percent apart from occasional single-run outliers. Measurements taken
  while the machine was busy varied by 10-20% and are not reliable for
  comparisons at this scale.

The benchmark is ``bench/bench_eigen.cpp`` in the *KSL* repository. To
reproduce the results, install Eigen and run:

.. code::

   meson setup build-bench --buildtype=release -Db_ndebug=true -Dbench=enabled \
       -Dc_args=-march=native -Dcpp_args=-march=native
   meson compile -C build-bench
   ./build-bench/bench/bench_eigen

``-Db_ndebug=true`` matters: without it, a meson release build keeps Eigen's
assertions and libstdc++'s bounds checks enabled.
