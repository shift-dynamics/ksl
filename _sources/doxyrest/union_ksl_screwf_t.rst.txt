.. index:: pair: union; ksl_screwf_t
.. _doxid-unionksl__screwf__t:
.. _cid-ksl_screwf_t:

union ksl_screwf_t
==================

.. toctree::
	:hidden:

.. code-block:: cpp
	:class: overview-code-block

	#include <screw.h>


Overview
~~~~~~~~

single precision screw consisting of a linear and angular vector pair in configuration space :ref:`More...<details-doxid-unionksl__screwf__t>`

.. _doxid-unionksl__screwf__t_1ac5570c4616705a58573950813e84b82f:
.. _cid-ksl_screwf_t::m0:
.. _doxid-unionksl__screwf__t_1aa91e8cfe0e4aab0dcccbe5e7e7f2a3cb:
.. _cid-ksl_screwf_t::m1:
.. _doxid-unionksl__screwf__t_1a1369fa68e2b9d328b01427b2778d94fa:
.. _cid-ksl_screwf_t::m2:
.. _doxid-unionksl__screwf__t_1aaf4a94057162a07d927e74cf00026bdd:
.. _cid-ksl_screwf_t::m3:
.. _doxid-unionksl__screwf__t_1a8917fae33553d3abe455848ac1c4deb2:
.. _cid-ksl_screwf_t::m4:
.. _doxid-unionksl__screwf__t_1a8f4c3e9594ce783cf4773e214aa255da:
.. _cid-ksl_screwf_t::m5:
.. ref-code-block:: cpp
	:class: overview-code-block

	// fields

	float :ref:`at<doxid-unionksl__screwf__t_1a9de51f2c5f979d88482339fe26ea9c58>` [6]
	:ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>` :ref:`lin<doxid-unionksl__screwf__t_1a021a5251d03bc384509ed69c6a78d8ed>`
	float m0
	float m1
	float m2
	float m3
	float m4
	float m5

.. _details-doxid-unionksl__screwf__t:

Detailed Documentation
~~~~~~~~~~~~~~~~~~~~~~

single precision screw consisting of a linear and angular vector pair in configuration space

Fields
------

.. _doxid-unionksl__screwf__t_1a9de51f2c5f979d88482339fe26ea9c58:
.. _cid-ksl_screwf_t::at:
.. ref-code-block:: cpp
	:class: title-code-block

	float at [6]

allows accessing screw quantities at specified index

.. _doxid-unionksl__screwf__t_1a021a5251d03bc384509ed69c6a78d8ed:
.. _cid-ksl_screwf_t::lin:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>` lin

free linear vector, e.g. linear velocity or acceleration

