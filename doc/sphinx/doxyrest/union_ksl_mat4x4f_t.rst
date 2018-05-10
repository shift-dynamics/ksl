.. index:: pair: union; ksl_mat4x4f_t
.. _doxid-unionksl__mat4x4f__t:
.. _cid-ksl_mat4x4f_t:

union ksl_mat4x4f_t
===================

.. toctree::
	:hidden:

.. code-block:: cpp
	:class: overview-code-block

	#include <matrix.h>


Overview
~~~~~~~~

general 4x4 double precision matrix :ref:`More...<details-doxid-unionksl__mat4x4f__t>`

.. _doxid-unionksl__mat4x4f__t_1ae83f1f0f33d146ca5bfafc8f86627a97:
.. _cid-ksl_mat4x4f_t::at:
.. _doxid-unionksl__mat4x4f__t_1acfdd4e3db1b8d3653de361c1788a6287:
.. _cid-ksl_mat4x4f_t::as_array:
.. _doxid-unionksl__mat4x4f__t_1a1b80be6ee04a121a84be8d01b1f414be:
.. _cid-ksl_mat4x4f_t::m00:
.. _doxid-unionksl__mat4x4f__t_1a3480a16b80a015b2f39aea73d03716aa:
.. _cid-ksl_mat4x4f_t::m10:
.. _doxid-unionksl__mat4x4f__t_1add6fe4b2211411e2bf3b6bc794cb2d14:
.. _cid-ksl_mat4x4f_t::m20:
.. _doxid-unionksl__mat4x4f__t_1a6f6ba5de5592946cfdcc95d3544b7f1a:
.. _cid-ksl_mat4x4f_t::m30:
.. _doxid-unionksl__mat4x4f__t_1a3c487577deebc79b10b692e697a82c17:
.. _cid-ksl_mat4x4f_t::m01:
.. _doxid-unionksl__mat4x4f__t_1a8d417f88460f24519ea86bfd7a20f34b:
.. _cid-ksl_mat4x4f_t::m11:
.. _doxid-unionksl__mat4x4f__t_1a7d4917b1fb4c6741e13d7903007e4544:
.. _cid-ksl_mat4x4f_t::m21:
.. _doxid-unionksl__mat4x4f__t_1a52b55e80b7754bbbd590ff7647c6b603:
.. _cid-ksl_mat4x4f_t::m31:
.. _doxid-unionksl__mat4x4f__t_1a86017c4f109427c627a7d07ecdc6e347:
.. _cid-ksl_mat4x4f_t::m02:
.. _doxid-unionksl__mat4x4f__t_1a98417848d988202cdffbf30ef6f82979:
.. _cid-ksl_mat4x4f_t::m12:
.. _doxid-unionksl__mat4x4f__t_1a28e66f2836e5c8bb9b2ded1047818cd2:
.. _cid-ksl_mat4x4f_t::m22:
.. _doxid-unionksl__mat4x4f__t_1a06900bf341e6a6fdbca8c9bfa653f30b:
.. _cid-ksl_mat4x4f_t::m32:
.. _doxid-unionksl__mat4x4f__t_1a380cf98fafd4f8ead78cf571918d4042:
.. _cid-ksl_mat4x4f_t::m03:
.. _doxid-unionksl__mat4x4f__t_1aaaf796f48a4426acd2e5be52cb82b951:
.. _cid-ksl_mat4x4f_t::m13:
.. _doxid-unionksl__mat4x4f__t_1ad3fb6bed3d94516742c01a47d78070c5:
.. _cid-ksl_mat4x4f_t::m23:
.. _doxid-unionksl__mat4x4f__t_1aaefc7878f7cf51f1b666a4de676e2bfa:
.. _cid-ksl_mat4x4f_t::m33:
.. _doxid-unionksl__mat4x4f__t_1aca56bda474e80c10f9401b7422507181:
.. _cid-ksl_mat4x4f_t::@25:
.. _doxid-unionksl__mat4x4f__t_1ac56cdc2a4620f31744a8c09f1ce5252d:
.. _cid-ksl_mat4x4f_t::v0:
.. _doxid-unionksl__mat4x4f__t_1afdf48082cc2bc42c0cf4ee98b1c032d1:
.. _cid-ksl_mat4x4f_t::v1:
.. _doxid-unionksl__mat4x4f__t_1abc9af91ffb920e2d5cb8ddccf82467db:
.. _cid-ksl_mat4x4f_t::v2:
.. _doxid-unionksl__mat4x4f__t_1a15f701e68e4fbfb107104227f943e967:
.. _cid-ksl_mat4x4f_t::v3:
.. _doxid-unionksl__mat4x4f__t_1a4af4f02a661acbc41d30b3e934114d58:
.. _cid-ksl_mat4x4f_t::@27:
.. ref-code-block:: cpp
	:class: overview-code-block

	// fields

	float at [16]
	float as_array [4][4]
	float m00
	float m10
	float m20
	float m30
	float m01
	float m11
	float m21
	float m31
	float m02
	float m12
	float m22
	float m32
	float m03
	float m13
	float m23
	float m33
	:ref:`ksl_vec4f_t<doxid-unionksl__vec4f__t>` v0
	:ref:`ksl_vec4f_t<doxid-unionksl__vec4f__t>` v1
	:ref:`ksl_vec4f_t<doxid-unionksl__vec4f__t>` v2
	:ref:`ksl_vec4f_t<doxid-unionksl__vec4f__t>` v3

.. _details-doxid-unionksl__mat4x4f__t:

Detailed Documentation
~~~~~~~~~~~~~~~~~~~~~~

general 4x4 double precision matrix

allow accessing mat4x4 quantities by field name or using at / as_array operators. if using the at / as_array operators, quantities are accessed in column major order

