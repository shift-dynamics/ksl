.. index:: pair: union; ksl_inertia_t
.. _doxid-unionksl__inertia__t:
.. _cid-ksl_inertia_t:

union ksl_inertia_t
===================

.. toctree::
	:hidden:

.. code-block:: cpp
	:class: overview-code-block

	#include <inertia.h>


Overview
~~~~~~~~

double precision mass and inertia properties :ref:`More...<details-doxid-unionksl__inertia__t>`

.. _doxid-unionksl__inertia__t_1a7e473f4d334f16258e711b99162b77b3:
.. _cid-ksl_inertia_t::at:
.. ref-code-block:: cpp
	:class: overview-code-block

	// fields

	double at [10]
	double :ref:`m<doxid-unionksl__inertia__t_1a3b0b12ce02a3b9008173b74e26acee1e>`
	:ref:`ksl_vec3_t<doxid-unionksl__vec3__t>` :ref:`mt<doxid-unionksl__inertia__t_1a01f08a63b6f7fec66f999a1e310dfee2>`
	double :ref:`Ixx<doxid-unionksl__inertia__t_1a2eb8d915d9bc40c5e2c17774155ba1d2>`
	double :ref:`Iyy<doxid-unionksl__inertia__t_1a6c0a1c56da613ca19cd99e80de6ea134>`
	double :ref:`Izz<doxid-unionksl__inertia__t_1aeaec6e980056613046172dcc63286874>`
	double :ref:`Ixy<doxid-unionksl__inertia__t_1a1e6573bc60662216e73675bf2076a11b>`
	double :ref:`Iyz<doxid-unionksl__inertia__t_1a0944254e6ea2d48340c112a5e59dd6ea>`
	double :ref:`Izx<doxid-unionksl__inertia__t_1aafcb32737673b966298d44998d4649a0>`
	double :ref:`mass<doxid-unionksl__inertia__t_1a3f8156d0486574f6b810d393d553a501>`
	:ref:`ksl_vec3_t<doxid-unionksl__vec3__t>` :ref:`mr<doxid-unionksl__inertia__t_1afab97679e93c0c3f7283fa760655a71d>`
	double :ref:`_Ixx<doxid-unionksl__inertia__t_1a84125375ee133ad0d92c1ba31cfa1c74>`
	double :ref:`_Iyy<doxid-unionksl__inertia__t_1a26e90ef5a5d27004ef98812388e82d34>`
	double :ref:`_Izz<doxid-unionksl__inertia__t_1a3077f4f2ba55b4cd95667e5d1fac9b07>`
	double :ref:`Iyx<doxid-unionksl__inertia__t_1ad902ca677203432d4a25b6d7928af981>`
	double :ref:`Izy<doxid-unionksl__inertia__t_1af3382f7297d21c91524ab1e5a7f211a7>`
	double :ref:`Ixz<doxid-unionksl__inertia__t_1a33f55406e42b2af43c5e903dd3f9bc0a>`

.. _details-doxid-unionksl__inertia__t:

Detailed Documentation
~~~~~~~~~~~~~~~~~~~~~~

double precision mass and inertia properties

Fields
------

.. _doxid-unionksl__inertia__t_1a3b0b12ce02a3b9008173b74e26acee1e:
.. _cid-ksl_inertia_t::m:
.. ref-code-block:: cpp
	:class: title-code-block

	double m

mass

.. _doxid-unionksl__inertia__t_1a01f08a63b6f7fec66f999a1e310dfee2:
.. _cid-ksl_inertia_t::mt:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_vec3_t<doxid-unionksl__vec3__t>` mt

mass times a vector, t, from reference frame to body centroid

.. _doxid-unionksl__inertia__t_1a2eb8d915d9bc40c5e2c17774155ba1d2:
.. _cid-ksl_inertia_t::ixx:
.. ref-code-block:: cpp
	:class: title-code-block

	double Ixx

Ixx centroidal inertia term, expressed in reference frame coordinates

.. _doxid-unionksl__inertia__t_1a6c0a1c56da613ca19cd99e80de6ea134:
.. _cid-ksl_inertia_t::iyy:
.. ref-code-block:: cpp
	:class: title-code-block

	double Iyy

Ixy centroidal inertia term, expressed in reference frame coordinates

.. _doxid-unionksl__inertia__t_1aeaec6e980056613046172dcc63286874:
.. _cid-ksl_inertia_t::izz:
.. ref-code-block:: cpp
	:class: title-code-block

	double Izz

Izz centroidal inertia term, expressed in reference frame coordinates

.. _doxid-unionksl__inertia__t_1a1e6573bc60662216e73675bf2076a11b:
.. _cid-ksl_inertia_t::ixy:
.. ref-code-block:: cpp
	:class: title-code-block

	double Ixy

Ixy centroidal inertia term, expressed in reference frame coordinates

.. _doxid-unionksl__inertia__t_1a0944254e6ea2d48340c112a5e59dd6ea:
.. _cid-ksl_inertia_t::iyz:
.. ref-code-block:: cpp
	:class: title-code-block

	double Iyz

Iyz centroidal inertia term, expressed in reference frame coordinates

.. _doxid-unionksl__inertia__t_1aafcb32737673b966298d44998d4649a0:
.. _cid-ksl_inertia_t::izx:
.. ref-code-block:: cpp
	:class: title-code-block

	double Izx

Izx centroidal inertia term, expressed in reference frame coordinates

.. _doxid-unionksl__inertia__t_1a3f8156d0486574f6b810d393d553a501:
.. _cid-ksl_inertia_t::mass:
.. ref-code-block:: cpp
	:class: title-code-block

	double mass

mass

.. _doxid-unionksl__inertia__t_1afab97679e93c0c3f7283fa760655a71d:
.. _cid-ksl_inertia_t::mr:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_vec3_t<doxid-unionksl__vec3__t>` mr

mass times a vector, r, from reference frame to body centroid

.. _doxid-unionksl__inertia__t_1a84125375ee133ad0d92c1ba31cfa1c74:
.. _cid-ksl_inertia_t::_ixx:
.. ref-code-block:: cpp
	:class: title-code-block

	double _Ixx

Ixx centroidal inertia term, expressed in reference frame coordinates

.. _doxid-unionksl__inertia__t_1a26e90ef5a5d27004ef98812388e82d34:
.. _cid-ksl_inertia_t::_iyy:
.. ref-code-block:: cpp
	:class: title-code-block

	double _Iyy

Ixy centroidal inertia term, expressed in reference frame coordinates

.. _doxid-unionksl__inertia__t_1a3077f4f2ba55b4cd95667e5d1fac9b07:
.. _cid-ksl_inertia_t::_izz:
.. ref-code-block:: cpp
	:class: title-code-block

	double _Izz

Izz centroidal inertia term, expressed in reference frame coordinates

.. _doxid-unionksl__inertia__t_1ad902ca677203432d4a25b6d7928af981:
.. _cid-ksl_inertia_t::iyx:
.. ref-code-block:: cpp
	:class: title-code-block

	double Iyx

Ixy centroidal inertia term, expressed in reference frame coordinates

.. _doxid-unionksl__inertia__t_1af3382f7297d21c91524ab1e5a7f211a7:
.. _cid-ksl_inertia_t::izy:
.. ref-code-block:: cpp
	:class: title-code-block

	double Izy

Iyz centroidal inertia term, expressed in reference frame coordinates

.. _doxid-unionksl__inertia__t_1a33f55406e42b2af43c5e903dd3f9bc0a:
.. _cid-ksl_inertia_t::ixz:
.. ref-code-block:: cpp
	:class: title-code-block

	double Ixz

Izx centroidal inertia term, expressed in reference frame coordinates

