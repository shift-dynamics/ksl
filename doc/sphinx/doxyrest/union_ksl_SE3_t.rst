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

.. _doxid-unionksl___s_e3__t_1aab410906175d3f9597bdd71ce02a1b5c:
.. _cid-ksl_se3_t::m00:
.. _doxid-unionksl___s_e3__t_1a4b0d6c04e34f2ebe77331013d1e964cb:
.. _cid-ksl_se3_t::m10:
.. _doxid-unionksl___s_e3__t_1a9633350ec2746322e4fe738d99267c00:
.. _cid-ksl_se3_t::m20:
.. _doxid-unionksl___s_e3__t_1a7ee80a6c9e21799f4c71f8bfef961187:
.. _cid-ksl_se3_t::m01:
.. _doxid-unionksl___s_e3__t_1a4166faba989a483fe23413c14c04050b:
.. _cid-ksl_se3_t::m11:
.. _doxid-unionksl___s_e3__t_1afd07d0bcbe89167c1e29415bab7ceb6d:
.. _cid-ksl_se3_t::m21:
.. _doxid-unionksl___s_e3__t_1a9fe61a09d564a6c8b7a4be307b30b9b9:
.. _cid-ksl_se3_t::m02:
.. _doxid-unionksl___s_e3__t_1af7e19e7cf3ca11b3fe3bffaa34182364:
.. _cid-ksl_se3_t::m12:
.. _doxid-unionksl___s_e3__t_1ad8a52aedc6159dc9c5bb91f7a74c8db5:
.. _cid-ksl_se3_t::m22:
.. _doxid-unionksl___s_e3__t_1a6f1347ef0795c74810cb210775960677:
.. _cid-ksl_se3_t::m03:
.. _doxid-unionksl___s_e3__t_1acb2b6458245e2cc5fd5b7c4b0c9beaf0:
.. _cid-ksl_se3_t::m13:
.. _doxid-unionksl___s_e3__t_1a874498cb8555c7d7467ee33a2123ec2d:
.. _cid-ksl_se3_t::m23:
.. _doxid-unionksl___s_e3__t_1af95364902063366372f24bf6b5cc6271:
.. _cid-ksl_se3_t::v0:
.. _doxid-unionksl___s_e3__t_1ac3ed5357b4ded71e6ec228792f08197d:
.. _cid-ksl_se3_t::v1:
.. _doxid-unionksl___s_e3__t_1aceaf0fa14236dc6b5c49ee5cc2379006:
.. _cid-ksl_se3_t::v2:
.. _doxid-unionksl___s_e3__t_1a6084a9642906e98d1ead47d8202fc67f:
.. _cid-ksl_se3_t::v3:
.. ref-code-block:: cpp
	:class: overview-code-block

	// fields

	double :ref:`as_array<doxid-unionksl___s_e3__t_1a5d6cd994a201ab7abe82456af34c28e1>` [12]
	double :ref:`at<doxid-unionksl___s_e3__t_1aed3eb72a50870d02410f259e74917d3b>` [4][3]
	:ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>` :ref:`R<doxid-unionksl___s_e3__t_1a531593b2501a91295f9b43ed5ad66247>`
	:ref:`ksl_vec3_t<doxid-unionksl__vec3__t>` :ref:`t<doxid-unionksl___s_e3__t_1a47054a5fe5bab25744238bd3e75a818c>`
	double m00
	double m10
	double m20
	double m01
	double m11
	double m21
	double m02
	double m12
	double m22
	double m03
	double m13
	double m23
	:ref:`ksl_vec3_t<doxid-unionksl__vec3__t>` v0
	:ref:`ksl_vec3_t<doxid-unionksl__vec3__t>` v1
	:ref:`ksl_vec3_t<doxid-unionksl__vec3__t>` v2
	:ref:`ksl_vec3_t<doxid-unionksl__vec3__t>` v3
	:ref:`ksl_vec3_t<doxid-unionksl__vec3__t>` :ref:`v<doxid-unionksl___s_e3__t_1a87b08ce43c441cc408ede7d20d5c7c27>` [4]

.. _details-doxid-unionksl___s_e3__t:

Detailed Documentation
~~~~~~~~~~~~~~~~~~~~~~

SE3 (3 Dimensional Special Euclidian group) consists of a SO3 (othonormalized 3x3 rotation matrix) and translation vector pair.

if using the at/as_array operators, quantities are accessed in column major order with Rotation matrix quantities coming first, followed by translation vector

Fields
------

.. _doxid-unionksl___s_e3__t_1a5d6cd994a201ab7abe82456af34c28e1:
.. _cid-ksl_se3_t::as_array:
.. ref-code-block:: cpp
	:class: title-code-block

	double as_array [12]

allows accessing quantities at specified index in linear array, where entities are specified in column major order

.. _doxid-unionksl___s_e3__t_1aed3eb72a50870d02410f259e74917d3b:
.. _cid-ksl_se3_t::at:
.. ref-code-block:: cpp
	:class: title-code-block

	double at [4][3]

allows accessing SE3 quantities at specified index in a doubly dimensioned array, where entities are specified in column major order

.. _doxid-unionksl___s_e3__t_1a531593b2501a91295f9b43ed5ad66247:
.. _cid-ksl_se3_t::r:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>` R

rotation component of SE3 transformation

.. _doxid-unionksl___s_e3__t_1a47054a5fe5bab25744238bd3e75a818c:
.. _cid-ksl_se3_t::t:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_vec3_t<doxid-unionksl__vec3__t>` t

translation component of SE3 transformation

.. _doxid-unionksl___s_e3__t_1a87b08ce43c441cc408ede7d20d5c7c27:
.. _cid-ksl_se3_t::v:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_vec3_t<doxid-unionksl__vec3__t>` v [4]

anonymous union allows accessing columns of rotation matrix quantities at specified index

