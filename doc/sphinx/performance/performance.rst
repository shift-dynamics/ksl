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
     - 6.2
     - 8.9
     - 8.1 (Isometry3d)
     - 1.3x
   * - Inverse SE3 product
     - ``ksl_product_dinvd``
     - 7.5
     - 8.0
     - 9.4 (Isometry3d)
     - 1.1x
   * - Transform a point
     - ``ksl_product_dv``
     - 1.7
     - 2.1
     - 2.2 (Isometry3d)
     - 1.2x
   * - Rotation about z
     - ``ksl_product_ddrz``
     - 3.2
     - 4.8
     - 5.4 (R * Rz)
     - 1.5x
   * - Adjoint of a screw
     - ``ksl_product_Ads``
     - 4.5
     - 4.3
     - 5.3 (6x6)
     - 1.0x
   * - CoAdjoint of a coscrew
     - ``ksl_product_CoAdc``
     - 4.5
     - 4.0
     - 4.7 (6x6)
     - 0.9x
   * - Quaternion product
     - ``ksl_product_qq``
     - 2.7
     -
     - 2.2 (Quaterniond)
     - 0.8x
   * - Inertia transform
     - ``ksl_inertia_transformed``
     - 11.9
     - 44.1
     - 55.2 (6x6)
     - 3.7x
   * - Kinematic chain (latency)
     - ``ksl_product_dd``
     - 6.9
     - 7.5
     - 7.4 (Isometry3d)
     - 1.1x

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
     - 5.5
     - 9.2
     - 14.9 (Isometry3d)
     - 1.7x
   * - Inverse SE3 product
     - ``ksl_product_dinvd``
     - 6.1
     - 8.4
     - 27.1 (Isometry3d)
     - 1.4x
   * - Transform a point
     - ``ksl_product_dv``
     - 1.4
     - 5.3
     - 10.7 (Isometry3d)
     - 3.8x
   * - Rotation about z
     - ``ksl_product_ddrz``
     - 3.3
     - 5.4
     - 5.7 (R * Rz)
     - 1.6x
   * - Adjoint of a screw
     - ``ksl_product_Ads``
     - 3.7
     - 11.3
     - 4.9 (6x6)
     - 1.3x
   * - CoAdjoint of a coscrew
     - ``ksl_product_CoAdc``
     - 3.4
     - 11.1
     - 4.5 (6x6)
     - 1.3x
   * - Quaternion product
     - ``ksl_product_qq``
     - 2.7
     -
     - 1.1 (Quaterniond)
     - 0.4x
   * - Inertia transform
     - ``ksl_inertia_transformed``
     - 7.5
     - 57.7
     - 50.6 (6x6)
     - 6.7x
   * - Kinematic chain (latency)
     - ``ksl_product_dd``
     - 7.6
     - 10.6
     - 17.0 (Isometry3d)
     - 1.4x

Observations
------------

* **Most kernels are faster in KSL.** The largest gain is the inertia
  transform, 3.7-6.7x, because *KSL* transforms the 10 independent mass and
  inertia terms directly instead of forming :math:`R I R^T` or a 6x6 product.
  Axis rotations (``ddrz``) touch only the two columns that change, a 1.5x
  gain over the equivalent Eigen column code.
* **Eigen wins the quaternion product.** Eigen has a hand-vectorized
  quaternion product that works on pairs of doubles with SSE2, and it gains
  further from the newer instructions enabled by ``-march=native``.
  ``ksl_product_qq`` is scalar code.
* **The adjoint and coadjoint tie in the portable build.** There, they are
  within run-to-run noise of hand-written Eigen code on ``R`` and ``t``.
  With ``-march=native``, *KSL* is 1.3x faster than the best Eigen variant.
* **Eigen's fixed-size code does not always benefit from** ``-march=native``.
  With AVX enabled, several Eigen variants became roughly 2-5x slower than
  in the portable build (``Isometry3d`` products, the point transform, and
  the hand-written adjoint). The *KSL* kernels changed by less than 10% or
  became faster.
* **Data size.** ``ksl_SE3_t`` is 96 bytes, against 128 bytes for
  ``Isometry3d``. ``ksl_inertia_t`` is 80 bytes, against 288 bytes for a 6x6
  spatial inertia matrix.
* **Results are noisy at this scale.** The tables report medians; individual
  runs varied by 10-20% for some kernels, so differences under about 15%
  should be read as a tie.

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
* Each configuration was run 7 times, pinned to a single core. The tables show
  the median of those runs.

The benchmark is ``bench/bench_eigen.cpp`` in the *KSL* repository. To
reproduce the results, install Eigen and run:

.. code::

   meson setup build-bench --buildtype=release -Db_ndebug=true -Dbench=enabled \
       -Dc_args=-march=native -Dcpp_args=-march=native
   meson compile -C build-bench
   ./build-bench/bench/bench_eigen

``-Db_ndebug=true`` matters: without it, a meson release build keeps Eigen's
assertions and libstdc++'s bounds checks enabled.
