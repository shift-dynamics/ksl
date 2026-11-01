.. _installation:
.. title:: Installation

Installation
============

Acquiring KSL
---------------

KSL can be obtained by cloning the repository from the GitHub site:

.. code::

   git clone git@github.com:shift-dynamics/ksl.git


Required tools
---------------------

*   `meson <https://mesonbuild.com>`_ and `ninja <https://ninja-build.org>`_
*   `check <https://libcheck.github.io/check/>`_ (for the test suite)

Optional dependencies
---------------------

*   `CBLAS <http://www.netlib.org/blas/>`_, used by the functions that
    copy screws into larger matrices when the ``blas`` option is enabled (off
    by default)
*   `Eigen <https://eigen.tuxfamily.org>`_ and a C++ compiler, for the
    benchmark in :ref:`performance`
*   doxygen, sphinx, breathe and sphinxcontrib-bibtex, to build this
    documentation


Linux
*****

On most Linux distributions the above packages can be installed using the distribution's package manager.

Arch Linux:
^^^^^^^^^^^

.. code::

   pacman -S meson ninja check
   # optional: CBLAS, Eigen, and the documentation tools
   pacman -S cblas eigen doxygen python-sphinx python-breathe python-sphinxcontrib-bibtex


Ubuntu / Debian-based Linux Distributions:
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. code::

   apt-get install meson ninja-build check
   # optional: CBLAS, Eigen, and the documentation tools
   apt-get install libopenblas-dev libeigen3-dev doxygen
   pip install sphinx breathe sphinxcontrib-bibtex


Macintosh
*********

On a Macintosh, the dependencies can be installed using the *brew* package manager:

.. code::

  brew install meson ninja check


The cblas package is already available on a Macintosh using the *accelerate* framework, the meson.build file may need to be modified to bring in this dependency correctly.


Windows
*******

*KSL* has not been tested on Windows machines.


Building KSL
--------------

To build the KSL library, from within the top directory of the repository, issue the following commands:

.. code::

   meson setup build
   meson compile -C build


To enable BLAS, configure with:

.. code::

   meson setup build -Dblas=enabled


To build in release mode (disables asserts and debug output)

.. code::

   meson setup build --buildtype=release -Db_ndebug=true

Build options
*************

Options are passed to ``meson setup`` or changed later with
``meson configure build -D<option>=<value>``:

========= ========== ==========================================================
option    default    purpose
========= ========== ==========================================================
tests     auto       build the test suite (needs check)
blas      disabled   link against a CBLAS implementation
docs      auto       add the ``doxygen`` and ``docs`` documentation targets
bench     disabled   build the comparison with Eigen described in
                     :ref:`performance`
========= ========== ==========================================================

The quaternion products use SSE2 and SSE3 processor instructions on x86-64
processors, which handle two double precision numbers at once. To use the
plain C versions instead, for example to compare results, define
``KSL_NO_SIMD``:

.. code::

   meson setup build -Dc_args=-DKSL_NO_SIMD

Functions are compiled for the processor family that the compiler targets by
default. To let the compiler use every instruction available on the build
machine, add ``-Dc_args=-march=native``. The resulting program may not run on
older processors.


Using KSL from another project
------------------------------

See :ref:`getting-started` for adding *KSL* to a meson project or linking it
directly.

Running Tests
-------------

After building as described above, then issue the command:

.. code::

    meson test -C build


Building documentation
----------------------

The documentation is built with doxygen, sphinx, breathe and
sphinxcontrib-bibtex. Doxygen extracts the API as XML, and sphinx renders it
with breathe:

.. code::

   meson compile -C build docs

The HTML pages are written to ``build/doc/html``. The site is published to
GitHub Pages from ``master`` by the CI workflow.
