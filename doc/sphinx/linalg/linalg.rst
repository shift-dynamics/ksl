.. _linalg:
.. title:: Linear Algebra

Linear Algebra
==============

Overview
--------

These functions solve the linear systems that arise in multibody kinematics
and dynamics.

**LU factorization with full pivoting.** The constraint equations of a
mechanism with closed loops give a Jacobian matrix that is often rectangular
and rank deficient, because some constraints are redundant. LU factorization
with complete row and column pivoting (``ksl_linalg_lu_full_rmo()``) handles
such matrices: it finds the rank, and the column permutation it chooses splits
the generalized coordinates into a set of independent coordinates and a set
of dependent coordinates that can be computed from them. This is the basis of
generalized coordinate partitioning :cite:`wehage1982`. The
``setBMatrix`` functions then compute
:math:`B = U_r^{-1} U_R`, which expresses the dependent coordinates in terms of
the independent ones, and the ``specified`` variants keep chosen coordinates,
such as driven joints, in the independent set. The largest entry of :math:`B`
(``ksl_linalg_lu_infinityNormB_rmo()``) grows as the partition becomes poorly
conditioned, which signals that a new partition should be chosen.

**Cholesky and LDLT factorization.** Mass matrices are symmetric and positive
definite. The Cholesky factorization :math:`A = L L^T` and the closely related
:math:`A = L D L^T` solve such systems with about half the work of an LU
factorization and without pivoting. Each comes with forward elimination, back
substitution and solve functions, and ``symmetricMatrixInverse`` computes the
inverse of a symmetric positive definite matrix.

**Gram-Schmidt orthonormalization** (``ksl_linalg_gramSchmidt()``) makes the
columns of a matrix orthonormal.

**Storage order.** The matrices are plain ``double`` arrays. Functions ending
in ``_rmo`` expect **row major order**, where element :math:`(i, j)` of a matrix
with ``n`` columns is ``A[i * n + j]``. Functions ending in ``_cmo`` expect
**column major order**, where element :math:`(i, j)` of a matrix with ``m``
rows is ``A[j * m + i]``. The two-dimensional arrays from
``ksl_array2D_alloc()`` store their rows in one contiguous block, so
``A[0]`` can be passed to the ``_rmo`` functions (see :ref:`arrays`).
:cite:`golub1996matrix` is the standard reference for these algorithms.

The array utilities ``ksl_swapArray()`` and ``ksl_maxIndex()`` used by these
functions are described in :ref:`arrays`.

Gram Schmidt Decomposition
--------------------------

.. doxygenfunction:: ksl_linalg_gramSchmidt


.. doxygenfunction:: ksl_linalg_gramSchmidtf


LU Decomposition
----------------

row major order
***************

.. doxygenfunction:: ksl_linalg_lu_full_rmo


.. doxygenfunction:: ksl_linalg_lu_full_specified_rmo


.. doxygenfunction:: ksl_linalg_lu_rmo


.. doxygenfunction:: ksl_linalg_lu_setBMatrix_rmo


.. doxygenfunction:: ksl_linalg_lu_setCMatrix_rmo


.. doxygenfunction:: ksl_linalg_lu_full_multiSpecified_rmo


.. doxygenfunction:: ksl_linalg_lu_infinityNormB_rmo



column major order
******************

.. doxygenfunction:: ksl_linalg_lu_full_cmo


.. doxygenfunction:: ksl_linalg_lu_full_specified_cmo


.. doxygenfunction:: ksl_linalg_lu_cmo


.. doxygenfunction:: ksl_linalg_lu_setBMatrix_cmo


.. doxygenfunction:: ksl_linalg_lu_setCMatrix_cmo



Cholesky Decomposition
----------------------

row major order
***************

.. doxygenfunction:: ksl_linalg_cholesky_rmo


.. doxygenfunction:: ksl_linalg_cholesky_forwardElimination_rmo


.. doxygenfunction:: ksl_linalg_cholesky_backwardSubstitution_rmo


.. doxygenfunction:: ksl_linalg_cholesky_solve_rmo


column major order
******************

.. doxygenfunction:: ksl_linalg_cholesky_cmo


.. doxygenfunction:: ksl_linalg_cholesky_forwardElimination_cmo


.. doxygenfunction:: ksl_linalg_cholesky_backwardSubstitution_cmo


.. doxygenfunction:: ksl_linalg_cholesky_solve_cmo



LDLT Decomposition
------------------

row major order
***************
.. doxygenfunction:: ksl_linalg_ldlt_rmo


.. doxygenfunction:: ksl_linalg_ldlt_forwardElimination_rmo


.. doxygenfunction:: ksl_linalg_ldlt_backwardSubstitution_rmo


.. doxygenfunction:: ksl_linalg_ldlt_solve_rmo


column major order
******************

.. doxygenfunction:: ksl_linalg_ldlt_cmo


.. doxygenfunction:: ksl_linalg_ldlt_forwardElimination_cmo


.. doxygenfunction:: ksl_linalg_ldlt_backwardSubstitution_cmo


.. doxygenfunction:: ksl_linalg_ldlt_solve_cmo


Symmetric Matrix Inverse
------------------------

row major order
***************

.. doxygenfunction:: ksl_linalg_symmetricMatrixInverse_rmo


column major order
******************

.. doxygenfunction:: ksl_linalg_symmetricMatrixInverse_cmo
