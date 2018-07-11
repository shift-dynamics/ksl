.. index:: pair: union; ksl_screw_t
.. _doxid-unionksl__screw__t:
.. _cid-ksl_screw_t:

union ksl_screw_t
=================

.. toctree::
	:hidden:

.. code-block:: cpp
	:class: overview-code-block

	#include <screw.h>


Overview
~~~~~~~~

double precision screw consisting of a linear and angular vector pair in configuration space :ref:`More...<details-doxid-unionksl__screw__t>`

.. _doxid-unionksl__screw__t_1ada5c023f9bd09a888176eebfac47dcba:
.. _cid-ksl_screw_t::at:
.. _doxid-unionksl__screw__t_1a9e6c40f46851fd02a65e2a9839871ba4:
.. _cid-ksl_screw_t::m0:
.. _doxid-unionksl__screw__t_1a1966593d0013d38fa281b2976b095d70:
.. _cid-ksl_screw_t::m1:
.. _doxid-unionksl__screw__t_1a97aa3e2b96af7a7097f2a767a6da2dc2:
.. _cid-ksl_screw_t::m2:
.. _doxid-unionksl__screw__t_1ae589d0193e0deb1ba18df5f320e562f7:
.. _cid-ksl_screw_t::m3:
.. _doxid-unionksl__screw__t_1a36264ce6e0f7f69fcd30e59b709d2fd6:
.. _cid-ksl_screw_t::m4:
.. _doxid-unionksl__screw__t_1a5bb2b8380475be5eb8acc7b3e582fe40:
.. _cid-ksl_screw_t::m5:
.. ref-code-block:: cpp
	:class: overview-code-block

	// fields

	double at [6]
	:ref:`ksl_vec3_t<doxid-unionksl__vec3__t>` :ref:`lin<doxid-unionksl__screw__t_1ae874feb8d45111b747ab609800bccba0>`
	:ref:`ksl_vec3_t<doxid-unionksl__vec3__t>` :ref:`ang<doxid-unionksl__screw__t_1a1f38cba5a2fc17b3850b51fded2a7094>`
	double m0
	double m1
	double m2
	double m3
	double m4
	double m5

.. _details-doxid-unionksl__screw__t:

Detailed Documentation
~~~~~~~~~~~~~~~~~~~~~~

double precision screw consisting of a linear and angular vector pair in configuration space

Fields
------

.. _doxid-unionksl__screw__t_1ae874feb8d45111b747ab609800bccba0:
.. _cid-ksl_screw_t::lin:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_vec3_t<doxid-unionksl__vec3__t>` lin

free linear vector, e.g. linear velocity or acceleration

.. _doxid-unionksl__screw__t_1a1f38cba5a2fc17b3850b51fded2a7094:
.. _cid-ksl_screw_t::ang:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_vec3_t<doxid-unionksl__vec3__t>` ang

bound angular vector, e.g. angular velocity or angular acceleration

