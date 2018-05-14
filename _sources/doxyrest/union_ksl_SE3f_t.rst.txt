.. index:: pair: union; ksl_SE3f_t
.. _doxid-unionksl___s_e3f__t:
.. _cid-ksl_se3f_t:

union ksl_SE3f_t
================

.. toctree::
	:hidden:

.. code-block:: cpp
	:class: overview-code-block

	#include <matrix.h>


Overview
~~~~~~~~

Single precision member of 3 Dimensional Special Euclidian group (SE3) consisting of a single precision SO3 (othonormalized 3x3 rotation matrix) and single precision translation vector pair. :ref:`More...<details-doxid-unionksl___s_e3f__t>`

.. _doxid-unionksl___s_e3f__t_1a4d583b6cbf1401749e727ec2c4d66c2c:
.. _cid-ksl_se3f_t::at:
.. _doxid-unionksl___s_e3f__t_1aaee32e0d5158cf399822c4c2c7398b87:
.. _cid-ksl_se3f_t::as_array:
.. _doxid-unionksl___s_e3f__t_1a134189e68331e79e46493933aafb1c3a:
.. _cid-ksl_se3f_t::r:
.. _doxid-unionksl___s_e3f__t_1a3197ad64b57690cbf7b99d35f69fb1ed:
.. _cid-ksl_se3f_t::t:
.. _doxid-unionksl___s_e3f__t_1ad8b275e7d57f74518c4890f099043add:
.. _cid-ksl_se3f_t::@31:
.. ref-code-block:: cpp
	:class: overview-code-block

	// fields

	float at [12]
	float as_array [4][3]
	:ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>` R
	:ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>` t

.. _details-doxid-unionksl___s_e3f__t:

Detailed Documentation
~~~~~~~~~~~~~~~~~~~~~~

Single precision member of 3 Dimensional Special Euclidian group (SE3) consisting of a single precision SO3 (othonormalized 3x3 rotation matrix) and single precision translation vector pair.

if using the at/as_array operators, quantities are accessed in column major order with Rotation matrix quantities coming first, followed by translation vector

