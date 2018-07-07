.. index:: pair: union; ksl_mat3x3_t
.. _doxid-unionksl__mat3x3__t:
.. _cid-ksl_mat3x3_t:

union ksl_mat3x3_t
==================

.. toctree::
	:hidden:

.. code-block:: cpp
	:class: overview-code-block

	#include <matrix.h>


Overview
~~~~~~~~

general 3x3 double precision matrix :ref:`More...<details-doxid-unionksl__mat3x3__t>`

.. _doxid-unionksl__mat3x3__t_1a162a0190fa2a2340c23a54299ba1501b:
.. _cid-ksl_mat3x3_t::m00:
.. _doxid-unionksl__mat3x3__t_1a91cd59c9da0690418147081584906959:
.. _cid-ksl_mat3x3_t::m10:
.. _doxid-unionksl__mat3x3__t_1acb3e71790ce566891039e7dbdf5f31fc:
.. _cid-ksl_mat3x3_t::m20:
.. _doxid-unionksl__mat3x3__t_1ab8068d20d7f2371dcd39d20ad890ae03:
.. _cid-ksl_mat3x3_t::m01:
.. _doxid-unionksl__mat3x3__t_1a6d83ae2504ae905fb65fbd03a460ba3a:
.. _cid-ksl_mat3x3_t::m11:
.. _doxid-unionksl__mat3x3__t_1a1c08cee73f76531cfec45ac253b09dba:
.. _cid-ksl_mat3x3_t::m21:
.. _doxid-unionksl__mat3x3__t_1ae495158cba0849f8ef59b226e6aed111:
.. _cid-ksl_mat3x3_t::m02:
.. _doxid-unionksl__mat3x3__t_1ad7716f45ff7235162695407abe155db7:
.. _cid-ksl_mat3x3_t::m12:
.. _doxid-unionksl__mat3x3__t_1a807e5473906d9c261cf5800a773d5230:
.. _cid-ksl_mat3x3_t::m22:
.. _doxid-unionksl__mat3x3__t_1a252afd31c4f921ab2bafe0707c59df50:
.. _cid-ksl_mat3x3_t::v0:
.. _doxid-unionksl__mat3x3__t_1aa385567df3e4b48528c42e251a2b93bb:
.. _cid-ksl_mat3x3_t::v1:
.. _doxid-unionksl__mat3x3__t_1aed4d36a602440a5ac5c573d77bf46fcb:
.. _cid-ksl_mat3x3_t::v2:
.. ref-code-block:: cpp
	:class: overview-code-block

	// fields

	double :ref:`as_array<doxid-unionksl__mat3x3__t_1af8a0577428c1f106f77e2d490f2045d7>` [9]
	double :ref:`at<doxid-unionksl__mat3x3__t_1a6ce045febd1d090b69e3d90e75d3bb48>` [3][3]
	double m00
	double m10
	double m20
	double m01
	double m11
	double m21
	double m02
	double m12
	double m22
	:ref:`ksl_vec3_t<doxid-unionksl__vec3__t>` v0
	:ref:`ksl_vec3_t<doxid-unionksl__vec3__t>` v1
	:ref:`ksl_vec3_t<doxid-unionksl__vec3__t>` v2
	:ref:`ksl_vec3_t<doxid-unionksl__vec3__t>` :ref:`v<doxid-unionksl__mat3x3__t_1a08c00340cd3bcae96d6edf4479603a27>` [3]

.. _details-doxid-unionksl__mat3x3__t:

Detailed Documentation
~~~~~~~~~~~~~~~~~~~~~~

general 3x3 double precision matrix

allow accessing mat3x3 quantities by field name or by using at / as_array operators. if using the at or as_array operators, quantities are accessed in column major order

Fields
------

.. _doxid-unionksl__mat3x3__t_1af8a0577428c1f106f77e2d490f2045d7:
.. _cid-ksl_mat3x3_t::as_array:
.. ref-code-block:: cpp
	:class: title-code-block

	double as_array [9]

allows accessing quantities at specified index in linear array, where entities are specified in column major order

.. _doxid-unionksl__mat3x3__t_1a6ce045febd1d090b69e3d90e75d3bb48:
.. _cid-ksl_mat3x3_t::at:
.. ref-code-block:: cpp
	:class: title-code-block

	double at [3][3]

allows accessing mat3x3 quantities at specified index in a doubly dimensioned array, where entities are specified in column major order

.. _doxid-unionksl__mat3x3__t_1a08c00340cd3bcae96d6edf4479603a27:
.. _cid-ksl_mat3x3_t::v:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_vec3_t<doxid-unionksl__vec3__t>` v [3]

anonymous union allows accessing columns of rotation matrix quantities at specified index

