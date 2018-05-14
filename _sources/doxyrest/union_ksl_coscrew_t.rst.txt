.. index:: pair: union; ksl_coscrew_t
.. _doxid-unionksl__coscrew__t:
.. _cid-ksl_coscrew_t:

union ksl_coscrew_t
===================

.. toctree::
	:hidden:

.. code-block:: cpp
	:class: overview-code-block

	#include <coscrew.h>


Overview
~~~~~~~~

double precision coscrew (i.e. a linear operator on a screw), consisting of a linear and angular vector pair in function space. :ref:`More...<details-doxid-unionksl__coscrew__t>`

.. _doxid-unionksl__coscrew__t_1afad4d4c7f661a9abac72cda156022e2d:
.. _cid-ksl_coscrew_t::at:
.. _doxid-unionksl__coscrew__t_1afb2a1d1f2021df90a16968ae9eecf605:
.. _cid-ksl_coscrew_t::@1:
.. _doxid-unionksl__coscrew__t_1ab42fd4ef9267ef487aabdb1a487c239c:
.. _cid-ksl_coscrew_t::m0:
.. _doxid-unionksl__coscrew__t_1ac2b8e770c7a82e5fa18c2352c45207a5:
.. _cid-ksl_coscrew_t::m1:
.. _doxid-unionksl__coscrew__t_1ad292f7bff046cb4fff3bd9b88b23f959:
.. _cid-ksl_coscrew_t::m2:
.. _doxid-unionksl__coscrew__t_1a61bf03e105cb659c4b81c57524d1924c:
.. _cid-ksl_coscrew_t::m3:
.. _doxid-unionksl__coscrew__t_1a7d5f67ff86445b9f034eeff0988b7e14:
.. _cid-ksl_coscrew_t::m4:
.. _doxid-unionksl__coscrew__t_1a4e248ae481f1512c5a7981f304936221:
.. _cid-ksl_coscrew_t::m5:
.. _doxid-unionksl__coscrew__t_1ad56964f52df770fd16da1842c0688803:
.. _cid-ksl_coscrew_t::m6:
.. _doxid-unionksl__coscrew__t_1a1294a73fa6ed2042f76ccd9593f7c66c:
.. _cid-ksl_coscrew_t::@3:
.. ref-code-block:: cpp
	:class: overview-code-block

	// fields

	double at [6]
	:ref:`ksl_vec3_t<doxid-unionksl__vec3__t>` :ref:`lin<doxid-unionksl__coscrew__t_1ab57fd5fdc42e837a08d695852c055386>`
	:ref:`ksl_vec3_t<doxid-unionksl__vec3__t>` :ref:`ang<doxid-unionksl__coscrew__t_1a8d29d9b0e7c76cec6f11dc77ed4e2eed>`
	double m0
	double m1
	double m2
	double m3
	double m4
	double m5
	double m6

.. _details-doxid-unionksl__coscrew__t:

Detailed Documentation
~~~~~~~~~~~~~~~~~~~~~~

double precision coscrew (i.e. a linear operator on a screw), consisting of a linear and angular vector pair in function space.

Fields
------

.. _doxid-unionksl__coscrew__t_1ab57fd5fdc42e837a08d695852c055386:
.. _cid-ksl_coscrew_t::lin:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_vec3_t<doxid-unionksl__vec3__t>` lin

free linear vector, e.g. force or linear momentum

.. _doxid-unionksl__coscrew__t_1a8d29d9b0e7c76cec6f11dc77ed4e2eed:
.. _cid-ksl_coscrew_t::ang:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_vec3_t<doxid-unionksl__vec3__t>` ang

bound angular vector, e.g. moment/torque or angular momentum

