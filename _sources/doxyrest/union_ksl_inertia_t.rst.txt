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
.. _doxid-unionksl__inertia__t_1afd5c4854ed9a438c33126299e6c2e752:
.. _cid-ksl_inertia_t::@9:
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

