.. _print:
.. title:: Printing and debugging

Printing and debugging
======================

Overview
--------

Every *KSL* type can be printed to a ``FILE*`` such as ``stdout`` or a log
file. Each type has three forms:

* ``ksl_<type>_print(f, x)`` always prints.
* ``ksl_<type>_debug(f, x)`` prints like ``print`` in a debug build, and
  compiles to nothing when ``NDEBUG`` is defined, as in a release build. It
  can be left in code that runs every time step at no cost to the release
  build.
* ``ksl_<type>_printWithOptions(f, x, label, options)`` is the function that
  the two macros above call.

The macros take two optional arguments after the value: a label printed before
it, and a pointer to a ``ksl_print_options_t`` that controls the format:

.. code-block:: c

   ksl_SE3_print(stdout, &D);                  /* default format */
   ksl_SE3_print(stdout, &D, "D");             /* with a label */
   ksl_SE3_print(stdout, &D, "D", &options);   /* with custom options */

The options set the number format (a ``printf`` format such as ``"%0.6g"``),
the delimiter between values, the brackets, whether each matrix row starts on
a new line, and whether matrices print row by row or column by column. The
``ksl_print_set...`` functions change the global defaults when no options
pointer is given, or the fields of an options struct when one is.

Setting print options
---------------------


.. doxygenenum:: ksl_print_breakBetweenLines_enum_t


.. doxygenstruct:: ksl_print_options_t


.. doxygenfunction:: ksl_print_setDefaultOptions


.. doxygendefine:: ksl_print_setDelimiter


.. doxygenfunction:: ksl_print_setDelimiterOption


.. doxygendefine:: ksl_print_setRealFormat


.. doxygenfunction:: ksl_print_setRealFormatOption


.. doxygendefine:: ksl_print_setInnerBrackets


.. doxygenfunction:: ksl_print_setInnerBracketsOption


.. doxygendefine:: ksl_print_setOuterBrackets


.. doxygenfunction:: ksl_print_setOuterBracketsOption


.. doxygendefine:: ksl_print_setBreakBetweenLinesInMatrix


.. doxygenfunction:: ksl_print_setBreakBetweenLinesInMatrixOption


.. doxygendefine:: ksl_print_setBoolean


.. doxygenfunction:: ksl_print_setBooleanOption


.. doxygendefine:: ksl_print_setRowColumnMajorPrinting


.. doxygenfunction:: ksl_print_setRowColumnMajorPrintingOption


.. doxygenfunction:: ksl_print_options



Double precision
----------------

.. doxygendefine:: ksl_vec3_debug


.. doxygendefine:: ksl_vec3_print


.. doxygenfunction:: ksl_vec3_printWithOptions


.. doxygendefine:: ksl_mat3x3_debug


.. doxygendefine:: ksl_mat3x3_print


.. doxygenfunction:: ksl_mat3x3_printWithOptions


.. doxygendefine:: ksl_mat4x4_debug


.. doxygendefine:: ksl_mat4x4_print


.. doxygenfunction:: ksl_mat4x4_printWithOptions


.. doxygendefine:: ksl_quaternion_debug


.. doxygendefine:: ksl_quaternion_print


.. doxygenfunction:: ksl_quaternion_printWithOptions


.. doxygendefine:: ksl_screw_debug


.. doxygendefine:: ksl_screw_print


.. doxygenfunction:: ksl_screw_printWithOptions


.. doxygendefine:: ksl_coscrew_debug


.. doxygendefine:: ksl_coscrew_print


.. doxygenfunction:: ksl_coscrew_printWithOptions


.. doxygendefine:: ksl_SE3_debug


.. doxygendefine:: ksl_SE3_print


.. doxygenfunction:: ksl_SE3_printWithOptions


.. doxygendefine:: ksl_inertia_debug


.. doxygendefine:: ksl_inertia_print


.. doxygenfunction:: ksl_inertia_printWithOptions


.. doxygendefine:: ksl_array_debug


.. doxygendefine:: ksl_array_print


.. doxygenfunction:: ksl_array_printWithOptions


.. doxygendefine:: ksl_array2D_debug


.. doxygendefine:: ksl_array2D_print


.. doxygenfunction:: ksl_array2D_printWithOptions


.. doxygendefine:: ksl_triang_debug


.. doxygendefine:: ksl_triang_print


.. doxygenfunction:: ksl_triang_printWithOptions


.. doxygendefine:: ksl_vec4_debug


.. doxygendefine:: ksl_vec4_print


.. doxygenfunction:: ksl_vec4_printWithOptions


.. doxygendefine:: ksl_eulerangles_debug


.. doxygendefine:: ksl_eulerangles_print


.. doxygenfunction:: ksl_eulerangles_printWithOptions



Single precision
----------------

.. doxygendefine:: ksl_vec3f_debug


.. doxygendefine:: ksl_vec3f_print


.. doxygenfunction:: ksl_vec3f_printWithOptions


.. doxygendefine:: ksl_mat3x3f_debug


.. doxygendefine:: ksl_mat3x3f_print


.. doxygenfunction:: ksl_mat3x3f_printWithOptions


.. doxygendefine:: ksl_mat4x4f_debug


.. doxygendefine:: ksl_mat4x4f_print


.. doxygenfunction:: ksl_mat4x4f_printWithOptions


.. doxygendefine:: ksl_quaternionf_debug


.. doxygendefine:: ksl_quaternionf_print


.. doxygenfunction:: ksl_quaternionf_printWithOptions


.. doxygendefine:: ksl_screwf_debug


.. doxygendefine:: ksl_screwf_print


.. doxygenfunction:: ksl_screwf_printWithOptions


.. doxygendefine:: ksl_coscrewf_debug


.. doxygendefine:: ksl_coscrewf_print


.. doxygenfunction:: ksl_coscrewf_printWithOptions


.. doxygendefine:: ksl_SE3f_debug


.. doxygendefine:: ksl_SE3f_print


.. doxygenfunction:: ksl_SE3f_printWithOptions


.. .. doxygendefine:: ksl_inertiaf_debug


.. .. doxygendefine:: ksl_inertiaf_print


.. .. doxygenfunction:: ksl_inertiaf_printWithOptions


.. doxygendefine:: ksl_vec4f_debug


.. doxygendefine:: ksl_vec4f_print


.. doxygenfunction:: ksl_vec4f_printWithOptions


.. doxygendefine:: ksl_euleranglesf_debug


.. doxygendefine:: ksl_euleranglesf_print


.. doxygenfunction:: ksl_euleranglesf_printWithOptions



Integers
--------

.. doxygendefine:: ksl_arrayi_debug


.. doxygendefine:: ksl_arrayi_print


.. doxygenfunction:: ksl_arrayi_printWithOptions


.. doxygendefine:: ksl_triangi_debug


.. doxygendefine:: ksl_triangi_print


.. doxygenfunction:: ksl_triangi_printWithOptions



Booleans
--------

.. doxygendefine:: ksl_triangb_debug


.. doxygendefine:: ksl_triangb_print


.. doxygenfunction:: ksl_triangb_printWithOptions
