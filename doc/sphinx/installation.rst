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

*   `Cblas <http://www.netlib.org/blas/>`_


Linux
*****

On most Linux distributions the above packages can be installed using the distribution's package manager.

Arch Linux:
^^^^^^^^^^^

.. code::

   pacman -S meson ninja check cblas


Ubuntu / Debian-based Linux Distributions:
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. code::

   apt-get install meson ninja-build check libopenblas-dev


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

   meson setup build --buildtype=release


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
