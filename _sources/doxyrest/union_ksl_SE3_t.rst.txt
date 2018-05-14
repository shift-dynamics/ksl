.. index:: pair: union; ksl_SE3_t
.. _doxid-unionksl___s_e3__t:
.. _cid-ksl_se3_t:

union ksl_SE3_t
===============

.. toctree::
	:hidden:

.. code-block:: cpp
	:class: overview-code-block

	#include <matrix.h>


Overview
~~~~~~~~

SE3 (3 Dimensional Special Euclidian group) consists of a SO3 (othonormalized 3x3 rotation matrix) and translation vector pair. :ref:`More...<details-doxid-unionksl___s_e3__t>`

.. _doxid-unionksl___s_e3__t_1a67b2300e952c625fbee11474530984e5:
.. _cid-ksl_se3_t::at:
.. _doxid-unionksl___s_e3__t_1a02db45167f2d2ba43fa1a07c6d46a5e0:
.. _cid-ksl_se3_t::as_array:
.. _doxid-unionksl___s_e3__t_1a531593b2501a91295f9b43ed5ad66247:
.. _cid-ksl_se3_t::r:
.. _doxid-unionksl___s_e3__t_1a47054a5fe5bab25744238bd3e75a818c:
.. _cid-ksl_se3_t::t:
.. _doxid-unionksl___s_e3__t_1a57eb9405eac686d22bf1e8378ec57697:
.. _cid-ksl_se3_t::@29:
.. ref-code-block:: cpp
	:class: overview-code-block

	// fields

	double at [12]
	double as_array [4][3]
	:ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>` R
	:ref:`ksl_vec3_t<doxid-unionksl__vec3__t>` t

.. _details-doxid-unionksl___s_e3__t:

Detailed Documentation
~~~~~~~~~~~~~~~~~~~~~~

SE3 (3 Dimensional Special Euclidian group) consists of a SO3 (othonormalized 3x3 rotation matrix) and translation vector pair.

if using the at/as_array operators, quantities are accessed in column major order with Rotation matrix quantities coming first, followed by translation vector

