.. index:: pair: union; ksl_vec4_t
.. _doxid-unionksl__vec4__t:
.. _cid-ksl_vec4_t:

union ksl_vec4_t
================

.. toctree::
	:hidden:

.. code-block:: cpp
	:class: overview-code-block

	#include <vector.h>


Overview
~~~~~~~~

double precision 4x1 vector representing a 3x1 vector with a homogeneous coordinate (w) appended. :ref:`More...<details-doxid-unionksl__vec4__t>`

.. _doxid-unionksl__vec4__t_1a812f1b71f83255f3c8dc9c1a6b65fb4d:
.. _cid-ksl_vec4_t::at:
.. _doxid-unionksl__vec4__t_1a6e16be0f64f6cf39a4366ec1c1370ea0:
.. _cid-ksl_vec4_t::r:
.. _doxid-unionksl__vec4__t_1a3bdea62edd67a5ae3f7a1910c220ce03:
.. _cid-ksl_vec4_t::x:
.. _doxid-unionksl__vec4__t_1ac468a99515c0ae0d1c34779a3c537f46:
.. _cid-ksl_vec4_t::y:
.. _doxid-unionksl__vec4__t_1a8cb6cb1e0ca6c3b30b8a7e279afc4458:
.. _cid-ksl_vec4_t::z:
.. ref-code-block:: cpp
	:class: overview-code-block

	// fields

	double at [4]
	:ref:`ksl_vec3_t<doxid-unionksl__vec3__t>` r
	double x
	double y
	double z
	double :ref:`w<doxid-unionksl__vec4__t_1ad616f057a4113c468fb0b07d8f22148e>`

.. _details-doxid-unionksl__vec4__t:

Detailed Documentation
~~~~~~~~~~~~~~~~~~~~~~

double precision 4x1 vector representing a 3x1 vector with a homogeneous coordinate (w) appended.

Typically used for nonlinear transformations such as camera projections.

Fields
------

.. _doxid-unionksl__vec4__t_1ad616f057a4113c468fb0b07d8f22148e:
.. _cid-ksl_vec4_t::w:
.. ref-code-block:: cpp
	:class: title-code-block

	double w

homogeneous coordinate of 4d vector

