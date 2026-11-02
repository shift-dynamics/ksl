.. _performance:
.. title:: Performance

Performance compared to Eigen
=============================

`Eigen <https://eigen.tuxfamily.org>`_ is the most widely used C++ library for
small fixed-size linear algebra, and its ``Isometry3d``, ``Quaterniond`` and
fixed-size matrix types are a common way to write kinematics code. This page
compares *KSL* functions with the equivalent Eigen code.

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

Results are given for two builds:

* The **portable build** (``-march=x86-64``) runs on any 64-bit x86 processor,
  so the compiler can only use instructions that every such processor has.
  This is the default for most compilers and Linux distributions.
* The **native build** (``-march=native``) lets the compiler use every
  instruction the test machine supports, including AVX, which can operate on
  four double precision numbers at once. The program may then not run on older
  processors.

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
     - 3.50
     - 4.83
     - 5.85 (Isometry3d)
     - 1.4x
   * - Inverse SE3 product
     - ``ksl_product_dinvd``
     - 3.86
     - 3.77
     - 7.19 (Isometry3d)
     - 1.0x
   * - Transform a point
     - ``ksl_product_dv``
     - 1.10
     - 1.41
     - 1.50 (Isometry3d)
     - 1.3x
   * - Rotation about z
     - ``ksl_product_ddrz``
     - 2.72
     - 2.79
     - 3.67 (R * Rz)
     - 1.0x
   * - Adjoint of a screw
     - ``ksl_product_Ads``
     - 2.41
     - 2.55
     - 3.62 (6x6)
     - 1.1x
   * - CoAdjoint of a coscrew
     - ``ksl_product_CoAdc``
     - 2.42
     - 2.54
     - 3.12 (6x6)
     - 1.0x
   * - Quaternion product
     - ``ksl_product_qq``
     - 1.45
     -
     - 1.47 (Quaterniond)
     - 1.0x
   * - Inertia transform
     - ``ksl_inertia_transformed``
     - 7.63
     - 25.56
     - 37.38 (6x6)
     - 3.3x
   * - Kinematic chain
     - ``ksl_product_dd``
     - 3.58
     - 4.86
     - 6.76 (Isometry3d)
     - 1.4x

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
     - 2.79
     - 6.18
     - 12.23 (Isometry3d)
     - 2.2x
   * - Inverse SE3 product
     - ``ksl_product_dinvd``
     - 2.94
     - 6.81
     - 23.69 (Isometry3d)
     - 2.3x
   * - Transform a point
     - ``ksl_product_dv``
     - 0.96
     - 4.63
     - 9.52 (Isometry3d)
     - 4.8x
   * - Rotation about z
     - ``ksl_product_ddrz``
     - 2.72
     - 3.05
     - 3.94 (R * Rz)
     - 1.1x
   * - Adjoint of a screw
     - ``ksl_product_Ads``
     - 1.79
     - 9.70
     - 3.47 (6x6)
     - 1.9x
   * - CoAdjoint of a coscrew
     - ``ksl_product_CoAdc``
     - 1.83
     - 9.75
     - 3.07 (6x6)
     - 1.7x
   * - Quaternion product
     - ``ksl_product_qq``
     - 0.80
     -
     - 0.80 (Quaterniond)
     - 1.0x
   * - Inertia transform
     - ``ksl_inertia_transformed``
     - 6.15
     - 36.75
     - 31.97 (6x6)
     - 5.2x
   * - Kinematic chain
     - ``ksl_product_dd``
     - 3.12
     - 8.98
     - 16.38 (Isometry3d)
     - 2.9x

Observations
------------

* **With** ``-march=native``, **KSL is faster on every operation except the
  quaternion product, which ties** ``Quaterniond``. The gains range from 1.1x
  (rotation about z) to 5.2x (inertia transform).
* **In the portable build, KSL is faster or ties on every operation except
  the inverse SE3 product,** where hand-written Eigen code takes 2% less
  time. The gains range from 1.0x to 3.3x (inertia transform).
* **The largest gain is the inertia transform:** 3.3x in the portable build
  and 5.2x with ``-march=native``. *KSL* transforms the 10 independent mass
  and inertia terms directly instead of forming :math:`R I R^T` or a 6x6
  product.
* **The SE3 products, adjoint, coadjoint and quaternion products are written
  with SSE2 instructions,** which operate on two double precision numbers at
  once and are available on every 64-bit x86 processor. Each 3-element column
  is handled as one pair plus one single number, and results are written to
  memory in the same pieces, so a following operation, such as the next
  product in a kinematic chain, can read them as soon as they are written.
  From plain C code, the compiler forms the pairs itself, and because a
  column has three numbers its pairs straddle columns, which takes extra
  instructions to rearrange values. On other processors, or when
  ``KSL_NO_SIMD`` is defined, these functions use plain C code instead.
* **How results are stored matters in a loop.** The SSE functions that store
  a register to memory are allowed to write to memory of any type, so after
  one the compiler has to assume that any pointer held in memory, such as the
  data pointer of a ``std::vector``, may have changed, and it reloads those
  pointers on every pass through the loop. In a loop as short as a quaternion
  product, that costs about 10%. With GCC, *KSL* stores through a
  vector-of-doubles type instead, which the compiler knows can only write
  doubles, so the pointers are loaded once before the loop. Clang treats both
  kinds of store the same way, so there *KSL* uses the SSE store functions.
* **Eigen's fixed-size code does not always benefit from** ``-march=native``.
  With AVX instructions enabled, the ``Isometry3d`` products, the point
  transform and the hand-written adjoint are roughly 2-6x slower than in the
  portable build. The *KSL* functions are faster with ``-march=native``,
  apart from the rotation about z, which takes the same time in both builds.
* **Data size.** ``ksl_SE3_t`` is 96 bytes, against 128 bytes for
  ``Isometry3d``. ``ksl_inertia_t`` is 80 bytes, against 288 bytes for a 6x6
  spatial inertia matrix.

Method
------

All results were measured on 2026-11-02 on an Intel Core i9-14900K with GCC
16.2.1 and Eigen 5.0.1, using double precision.

* Like Eigen, *KSL* defines its functions in its header files, so the
  benchmark compiles the code of both libraries together with the same
  compiler settings.
* Every operation is applied to an array of 2048 independent inputs, for
  example 192 KB of ``ksl_SE3_t`` per array. Like the data of most
  simulations, that is larger than the processor's fastest cache (L1, 48 KB
  per core on this processor), so the timings include moving data to and from
  the next cache (L2, 2 MB per core), where every operation's inputs and
  outputs fit. Because the inputs are independent, the processor can overlap
  consecutive operations, so these timings measure how many operations it can
  complete per second (throughput). Each timing is the minimum of 50 samples
  of 1000 passes over the array, about 0.4 seconds per operation.
* The kinematic chain row instead multiplies 2048 transforms in sequence. Each
  product needs the previous result, so the operations cannot overlap, and the
  timing measures how long one operation takes from start to finish
  (latency).
* The benchmark checks *KSL* against Eigen before timing. Results agree to
  within :math:`2 \times 10^{-15}`.
* Each configuration was run 21 times, pinned to a single core of an
  otherwise idle machine, and the tables show the median of those runs. Apart
  from occasional single-run outliers, the runs agreed within about 1%.
  Measurements taken while the machine was busy varied by 10-20% and are not
  reliable for comparisons at this scale.
* On this processor, writes to memory that is not already in the L1 cache
  complete at one of two rates, and a newly started program can take from a
  few milliseconds to a few seconds to reach the faster one. Until it does,
  the SE3 products, which write the most data per operation, take 20-40%
  longer, for both *KSL* and Eigen. Timing each operation for about 0.4
  seconds and keeping the fastest sample measures the rate a long simulation
  runs at.

The benchmark is ``bench/bench_eigen.cpp`` in the *KSL* repository. To
reproduce the results, install Eigen and run:

.. code::

   meson setup build-bench --buildtype=release -Db_ndebug=true -Dbench=enabled \
       -Dc_args=-march=native -Dcpp_args=-march=native
   meson compile -C build-bench
   ./build-bench/bench/bench_eigen

``-Db_ndebug=true`` matters: without it, a meson release build keeps Eigen's
assertions and libstdc++'s bounds checks enabled.
