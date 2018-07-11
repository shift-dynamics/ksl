.. index:: pair: union; ksl_coscrewf_t
.. _doxid-unionksl__coscrewf__t:
.. _cid-ksl_coscrewf_t:

union ksl_coscrewf_t
====================

.. toctree::
	:hidden:

.. code-block:: cpp
	:class: overview-code-block

	#include <coscrew.h>


Overview
~~~~~~~~

single precision coscrew (i.e. a linear operator on a screw), consisting of a linear and angular vector pair in function space. :ref:`More...<details-doxid-unionksl__coscrewf__t>`

.. _doxid-unionksl__coscrewf__t_1a031608610b216c8a41371a1b4dd93ffc:
.. _cid-ksl_coscrewf_t::at:
.. _doxid-unionksl__coscrewf__t_1a7f1df0ce12dbbbf9e517e23773fe2254:
.. _cid-ksl_coscrewf_t::m0:
.. _doxid-unionksl__coscrewf__t_1a4483b31d8f6bd391cd8b9191bcd0c84c:
.. _cid-ksl_coscrewf_t::m1:
.. _doxid-unionksl__coscrewf__t_1a9838fe6dcf7931f15a1730cfaa2201a1:
.. _cid-ksl_coscrewf_t::m2:
.. _doxid-unionksl__coscrewf__t_1ac33572f5dc35ccb879775263076724ac:
.. _cid-ksl_coscrewf_t::m3:
.. _doxid-unionksl__coscrewf__t_1aa23200c77fc9a5a545d427171845cf08:
.. _cid-ksl_coscrewf_t::m4:
.. _doxid-unionksl__coscrewf__t_1acedebe8e105ac41303816c69d37ceefd:
.. _cid-ksl_coscrewf_t::m5:
.. ref-code-block:: cpp
	:class: overview-code-block

	// fields

	float at [6]
	:ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>` :ref:`lin<doxid-unionksl__coscrewf__t_1aeb248395e0060c9febdc6a702d89313b>`
	:ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>` :ref:`ang<doxid-unionksl__coscrewf__t_1a8a5d53fe8630263f4fa6cd73518baff0>`
	float m0
	float m1
	float m2
	float m3
	float m4
	float m5

.. _details-doxid-unionksl__coscrewf__t:

Detailed Documentation
~~~~~~~~~~~~~~~~~~~~~~

single precision coscrew (i.e. a linear operator on a screw), consisting of a linear and angular vector pair in function space.

Fields
------

.. _doxid-unionksl__coscrewf__t_1aeb248395e0060c9febdc6a702d89313b:
.. _cid-ksl_coscrewf_t::lin:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>` lin

bound linear vector, e.g. force or linear momentum

.. _doxid-unionksl__coscrewf__t_1a8a5d53fe8630263f4fa6cd73518baff0:
.. _cid-ksl_coscrewf_t::ang:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>` ang

free angular vector, e.g. moment/torque or angular momentum

