.. _notation:
.. title:: linalg

Linear Algebra
==============

Utilities
---------

.. doxygenfunction:: ksl_swapArray


.. doxygenfunction:: ksl_maxIndex


Gram Schmidt Decomposition
--------------------------

.. doxygenfunction:: ksl_linalg_gramSchmidt


Principal Component Analysis
----------------------------

.. doxygenfunction:: ksl_linalg_pca


LU Decomposition
----------------

row major order
***************

.. doxygenfunction:: ksl_linalg_lu_full_rmo


.. doxygenfunction:: ksl_linalg_lu_full_specified_rmo


.. doxygenfunction:: ksl_linalg_lu_rmo


.. doxygenfunction:: ksl_linalg_lu_setBMatrix_rmo


.. doxygenfunction:: ksl_linalg_lu_setCMatrix_rmo


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

.. doxygenfunction:: ksl_linalg_ldlt_cmo


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
