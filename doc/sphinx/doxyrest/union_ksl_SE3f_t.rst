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

.. _doxid-unionksl___s_e3f__t_1a8787de28772319c3962c8ad2407aa834:
.. _cid-ksl_se3f_t::m00:
.. _doxid-unionksl___s_e3f__t_1a7ebf36f6f4c2f73edcf5c35149a211c9:
.. _cid-ksl_se3f_t::m10:
.. _doxid-unionksl___s_e3f__t_1a587bd8889335742e51070960d0ad9a93:
.. _cid-ksl_se3f_t::m20:
.. _doxid-unionksl___s_e3f__t_1a981cdfa6df08af5cb083e0cc5ba47897:
.. _cid-ksl_se3f_t::m01:
.. _doxid-unionksl___s_e3f__t_1ad79160839eb3660ee0d9e002153a7556:
.. _cid-ksl_se3f_t::m11:
.. _doxid-unionksl___s_e3f__t_1ac47a0a98d977705f866d2d9f00cd7fa6:
.. _cid-ksl_se3f_t::m21:
.. _doxid-unionksl___s_e3f__t_1a0794bb7c23b9af6dd2b2aa1a56737567:
.. _cid-ksl_se3f_t::m02:
.. _doxid-unionksl___s_e3f__t_1aded4e6c199ee0c7b53a555df2405e7a4:
.. _cid-ksl_se3f_t::m12:
.. _doxid-unionksl___s_e3f__t_1aa736c8acd7606253c5fdd8d3a4de844d:
.. _cid-ksl_se3f_t::m22:
.. _doxid-unionksl___s_e3f__t_1a62c5ee660eea0db7522dc3cd8f3549c9:
.. _cid-ksl_se3f_t::m03:
.. _doxid-unionksl___s_e3f__t_1abf9dfb0ebeb89c0808a7c17b8b10c06f:
.. _cid-ksl_se3f_t::m13:
.. _doxid-unionksl___s_e3f__t_1a8e3e4b73cb01e558d7cc25009c5d74fa:
.. _cid-ksl_se3f_t::m23:
.. _doxid-unionksl___s_e3f__t_1a80d52e8348bcbe9940254a472fe6c76d:
.. _cid-ksl_se3f_t::v0:
.. _doxid-unionksl___s_e3f__t_1a05c81847e8378fa0617bfb185986481d:
.. _cid-ksl_se3f_t::v1:
.. _doxid-unionksl___s_e3f__t_1abd62bb364ac50ad0448c831d000b77c4:
.. _cid-ksl_se3f_t::v2:
.. _doxid-unionksl___s_e3f__t_1afedda2df9ac230f740909666298b983b:
.. _cid-ksl_se3f_t::v3:
.. ref-code-block:: cpp
	:class: overview-code-block

	// fields

	float :ref:`as_array<doxid-unionksl___s_e3f__t_1aafad3204f63ca0be4168422f6718db02>` [12]
	float :ref:`at<doxid-unionksl___s_e3f__t_1a48feafdac5471ea54ccd03ee5e4d7833>` [4][3]
	:ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>` :ref:`R<doxid-unionksl___s_e3f__t_1a134189e68331e79e46493933aafb1c3a>`
	:ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>` :ref:`t<doxid-unionksl___s_e3f__t_1a3197ad64b57690cbf7b99d35f69fb1ed>`
	float m00
	float m10
	float m20
	float m01
	float m11
	float m21
	float m02
	float m12
	float m22
	float m03
	float m13
	float m23
	:ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>` v0
	:ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>` v1
	:ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>` v2
	:ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>` v3
	:ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>` :ref:`v<doxid-unionksl___s_e3f__t_1a25b357f06c92064dac04792d3e088568>` [4]

.. _details-doxid-unionksl___s_e3f__t:

Detailed Documentation
~~~~~~~~~~~~~~~~~~~~~~

Single precision member of 3 Dimensional Special Euclidian group (SE3) consisting of a single precision SO3 (othonormalized 3x3 rotation matrix) and single precision translation vector pair.

if using the at/as_array operators, quantities are accessed in column major order with Rotation matrix quantities coming first, followed by translation vector

Fields
------

.. _doxid-unionksl___s_e3f__t_1aafad3204f63ca0be4168422f6718db02:
.. _cid-ksl_se3f_t::as_array:
.. ref-code-block:: cpp
	:class: title-code-block

	float as_array [12]

allows accessing quantities at specified index in linear array, with entities specified in column major order

.. _doxid-unionksl___s_e3f__t_1a48feafdac5471ea54ccd03ee5e4d7833:
.. _cid-ksl_se3f_t::at:
.. ref-code-block:: cpp
	:class: title-code-block

	float at [4][3]

allows accessing SE3 quantities at specified index in a doubly dimensioned array, with entities specified in column major order

.. _doxid-unionksl___s_e3f__t_1a134189e68331e79e46493933aafb1c3a:
.. _cid-ksl_se3f_t::r:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>` R

rotation component of SE3 transformation

.. _doxid-unionksl___s_e3f__t_1a3197ad64b57690cbf7b99d35f69fb1ed:
.. _cid-ksl_se3f_t::t:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>` t

translation component of SE3 transformation

.. _doxid-unionksl___s_e3f__t_1a25b357f06c92064dac04792d3e088568:
.. _cid-ksl_se3f_t::v:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>` v [4]

anonymous union allows accessing columns of rotation matrix quantities at specified index

