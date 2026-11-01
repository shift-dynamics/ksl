.. _arrays:
.. title:: Arrays and Memory

Arrays and Memory
=================

Utilities for plain C arrays, and for allocating two-dimensional arrays.
The array utilities are in ``ksl/array.h``, which ``ksl/ksl.h`` includes. The
allocation functions are in ``ksl/memory.h``, which must be included
separately.

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
