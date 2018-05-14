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

*   `Cblas <http://www.netlib.org/blas/>`_

Optional dependencies
---------------------

*   `Cblas <http://www.netlib.org/blas/>`_


Linux
*****

On most Linux distributions the above packages can be installed using the distribution's package manager.

Arch Linux:
^^^^^^^^^^^

.. code::

   pacman -S cmake cblas


Ubuntu / Debian-based Linux Distributions:
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. code::

   apt-get install cmake cblas


Macintosh
*********

On a Macintosh, the dependencies can be installed using the *brew* package manager:

.. code::

  brew install cmake


The cblas package is already available on a Macintosh using the *accelerate* framework, the CMakeLists.txt file may need to be modified to bring in this dependency correctly.


Windows
*******

*KSL* has not been tested on Windows machines.


Building KSL
--------------

To build the KSL library, from within the top directory of the repository, issue the following commands:

.. code::

   mkdir build
   cd build
   cmake ..
   make


To enable BLAS, change the cmake argument above as:

.. code::

   cmake .. -DWITH_BLAS


To build in release mode (disables asserts and debug output)

.. code::

   cmake .. -DCMAKE_BUILD_TYPE=Release


Building documentation
----------------------

Documentation can be built by issuing the command in the build directory:

.. code::

   make doc


Optional - documentation can be copied to your /share/doc folder by issuing the command:

.. code::

   make install
