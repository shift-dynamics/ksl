.. _contributing:

.. title:: Contributing

Contributing
============

Contributions are welcome. Refer to the
`GitHub issues page <https://github.com/shift-dynamics/ksl/issues>`_ for
possible development tasks, or contact the authors with other development or
research ideas.

Building and testing
--------------------

Build and run the tests as described in :ref:`installation`:

.. code::

   meson setup build
   meson compile -C build
   meson test -C build

Every change should pass the test suite. New functions need a test in
``test/``, ideally one that checks the result against an independent
calculation rather than against another *KSL* function. ``test/check_conventions.c``
shows this style.

The continuous integration workflow on GitHub builds with GCC and Clang in
debug and release mode, with SSE3 enabled and with ``KSL_NO_SIMD``, and
builds this documentation. Pull requests need to pass all of these jobs.

Code conventions
----------------

* Follow the naming conventions in :ref:`getting-started`. Every double
  precision function should have a single precision version with an ``f``
  suffix.
* Arguments are inputs first, then outputs. Outputs are written through
  pointers provided by the caller; functions do not allocate memory.
* Small functions are ``static inline`` and defined in their header. Declare
  each function near the top of the header with its documentation comment,
  and define it further down.
* Document every function with a Doxygen comment: a ``@brief`` line, and a
  ``@param`` line for each argument marked ``[in]``, ``[out]`` or ``[in,out]``.
  The documentation build reports missing or mismatched parameters as
  warnings.

Formatting with clang-format
----------------------------

The repository contains a
`clang-format <https://clang.llvm.org/docs/ClangFormat.html>`_ configuration
file. Format your changes before committing; ``git clang-format`` formats only
the lines that you changed:

.. code::

   git add -u
   git clang-format

Most editors can also run clang-format when a file is saved.

Pull requests
-------------

Fork the repository, make your changes on a branch, and open a pull request
against ``master``. Describe what the change does and how it was tested.
