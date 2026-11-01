.. _arrays:
.. title:: Arrays and Memory

Arrays and Memory
=================

Overview
--------

These are utilities for plain C arrays of numbers: swapping, finding the
largest entry, scaled addition (``axpy``, :math:`\underline{y} \leftarrow a
\underline{x} + \underline{y}`), linear interpolation, and comparing two arrays
within a tolerance (``allclose``, useful in tests). They are in
``ksl/array.h``, which ``ksl/ksl.h`` includes.

**Two-dimensional arrays.** ``ksl/memory.h``, which must be included
separately, allocates matrices whose entries can be written ``A[i][j]``. Each
array is an array of row pointers into **one contiguous block** of
``rows * columns`` values stored row by row:

.. code-block:: c

   double** A = ksl_array2D_alloc(3, 4);  /* 3 rows, 4 columns, zeroed */
   A[1][2] = 5.0;
   /* A[0] is the whole matrix in row major order, so it can be passed to
      the _rmo linear algebra functions: A[0][1 * 4 + 2] == 5.0 */
   ksl_array2D_free(A);

Free each array with the ``free`` function for its type, which releases both
the row pointers and the data block.

Array utilities
---------------

.. doxygenfunction:: ksl_swap


.. doxygenfunction:: ksl_swapf


.. doxygenfunction:: ksl_swapi


.. doxygenfunction:: ksl_swapArray


.. doxygenfunction:: ksl_maxIndex


.. doxygenfunction:: ksl_axpy


.. doxygenfunction:: ksl_axpyf


.. doxygenfunction:: ksl_allclose


.. doxygenfunction:: ksl_allclosef


.. doxygenfunction:: ksl_allclosei


.. doxygenfunction:: ksl_arraylerp


.. doxygenfunction:: ksl_arraylerpf


Two-dimensional arrays
----------------------

The ``alloc`` functions return an array of row pointers, so that elements can
be accessed as ``A[i][j]``. Free each array with the matching ``free``
function.

.. doxygenfunction:: ksl_array2D_alloc


.. doxygenfunction:: ksl_array2D_free


.. doxygenfunction:: ksl_array2Df_alloc


.. doxygenfunction:: ksl_array2Df_free


.. doxygenfunction:: ksl_array2Di_alloc


.. doxygenfunction:: ksl_array2Di_free


.. doxygenfunction:: ksl_array2Dui_alloc


.. doxygenfunction:: ksl_array2Dui_free


.. doxygenfunction:: ksl_array2Dc_alloc


.. doxygenfunction:: ksl_array2Dc_free


.. doxygenfunction:: ksl_array2Db_alloc


.. doxygenfunction:: ksl_array2Db_free


One-dimensional arrays
----------------------

.. doxygenfunction:: ksl_array_free


.. doxygenfunction:: ksl_arrayf_free


.. doxygenfunction:: ksl_arrayi_free


.. doxygenfunction:: ksl_arrayui_free


.. doxygenfunction:: ksl_arrayc_free


.. doxygenfunction:: ksl_arrayb_free
