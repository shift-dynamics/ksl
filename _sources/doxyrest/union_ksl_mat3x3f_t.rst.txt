.. index:: pair: union; ksl_mat3x3f_t
.. _doxid-unionksl__mat3x3f__t:
.. _cid-ksl_mat3x3f_t:

union ksl_mat3x3f_t
===================

.. toctree::
	:hidden:

.. code-block:: cpp
	:class: overview-code-block

	#include <matrix.h>


Overview
~~~~~~~~

general 3x3 double precision matrix :ref:`More...<details-doxid-unionksl__mat3x3f__t>`

.. _doxid-unionksl__mat3x3f__t_1a1006a7449667905708e4c8eca844103e:
.. _cid-ksl_mat3x3f_t::m00:
.. _doxid-unionksl__mat3x3f__t_1ad81b40b6fa61fcd79110dd0660ce1c52:
.. _cid-ksl_mat3x3f_t::m10:
.. _doxid-unionksl__mat3x3f__t_1a00919ee9f5fdb6cc6d865237129cddf6:
.. _cid-ksl_mat3x3f_t::m20:
.. _doxid-unionksl__mat3x3f__t_1adba89925fd0b73ac2a95b5ef03dee9d2:
.. _cid-ksl_mat3x3f_t::m01:
.. _doxid-unionksl__mat3x3f__t_1ae7af2a52c4c7b5be2e95e5182ee4878a:
.. _cid-ksl_mat3x3f_t::m11:
.. _doxid-unionksl__mat3x3f__t_1a23ec053c7fb796dbaf1027e84069adf3:
.. _cid-ksl_mat3x3f_t::m21:
.. _doxid-unionksl__mat3x3f__t_1a979fc73175cd085e0cec1fe5a1d39f06:
.. _cid-ksl_mat3x3f_t::m02:
.. _doxid-unionksl__mat3x3f__t_1add15116857bf84a0cfe4e658161d857d:
.. _cid-ksl_mat3x3f_t::m12:
.. _doxid-unionksl__mat3x3f__t_1a6c20498998604e5d3b46db8f37d52230:
.. _cid-ksl_mat3x3f_t::m22:
.. _doxid-unionksl__mat3x3f__t_1a142c24ac07a4d3ae9dc2bd05fef74a31:
.. _cid-ksl_mat3x3f_t::v0:
.. _doxid-unionksl__mat3x3f__t_1a3b7c8385e68ce89e70f4064057506390:
.. _cid-ksl_mat3x3f_t::v1:
.. _doxid-unionksl__mat3x3f__t_1ae1878c1ae11efeefd6c27dd7d0d52b18:
.. _cid-ksl_mat3x3f_t::v2:
.. ref-code-block:: cpp
	:class: overview-code-block

	// fields

	float :ref:`as_array<doxid-unionksl__mat3x3f__t_1a233431ba494406a5eaa05e21cb0c61d8>` [9]
	float :ref:`at<doxid-unionksl__mat3x3f__t_1a53027ce9683d9d0b59b0464f9e3f0487>` [3][3]
	float m00
	float m10
	float m20
	float m01
	float m11
	float m21
	float m02
	float m12
	float m22
	:ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>` v0
	:ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>` v1
	:ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>` v2
	:ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>` :ref:`v<doxid-unionksl__mat3x3f__t_1ace1667287f6ab22d7f1027be1f82942f>` [3]

.. _details-doxid-unionksl__mat3x3f__t:

Detailed Documentation
~~~~~~~~~~~~~~~~~~~~~~

general 3x3 double precision matrix

allow accessing mat3x3 quantities by field name or by using at / as_array operators. if using the at or as_array operators, quantities are accessed in column major order

Fields
------

.. _doxid-unionksl__mat3x3f__t_1a233431ba494406a5eaa05e21cb0c61d8:
.. _cid-ksl_mat3x3f_t::as_array:
.. ref-code-block:: cpp
	:class: title-code-block

	float as_array [9]

allows accessing quantities at specified index in linear array, where entities are specified in column major order

.. _doxid-unionksl__mat3x3f__t_1a53027ce9683d9d0b59b0464f9e3f0487:
.. _cid-ksl_mat3x3f_t::at:
.. ref-code-block:: cpp
	:class: title-code-block

	float at [3][3]

allows accessing mat3x3 quantities at specified index in a doubly dimensioned array, where entities are specified in column major order

.. _doxid-unionksl__mat3x3f__t_1ace1667287f6ab22d7f1027be1f82942f:
.. _cid-ksl_mat3x3f_t::v:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>` v [3]

anonymous union allows accessing columns of rotation matrix quantities at specified index

