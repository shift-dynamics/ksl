.. index:: pair: union; ksl_inertiaf_t
.. _doxid-unionksl__inertiaf__t:
.. _cid-ksl_inertiaf_t:

union ksl_inertiaf_t
====================

.. toctree::
	:hidden:

.. code-block:: cpp
	:class: overview-code-block

	#include <inertia.h>


Overview
~~~~~~~~

single precision mass and inertia properties :ref:`More...<details-doxid-unionksl__inertiaf__t>`

.. _doxid-unionksl__inertiaf__t_1ac8b1f3d007c055681edab90f3296de9f:
.. _cid-ksl_inertiaf_t::at:
.. _doxid-unionksl__inertiaf__t_1ad555149301b2a53ef97ba6a6b5084b87:
.. _cid-ksl_inertiaf_t::@11:
.. ref-code-block:: cpp
	:class: overview-code-block

	// fields

	float at [10]
	float :ref:`m<doxid-unionksl__inertiaf__t_1a531450fe0f798aabeb0bf2f462d2f1d6>`
	:ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>` :ref:`mt<doxid-unionksl__inertiaf__t_1a655bab49abb224308a73f020c6f1d430>`
	float :ref:`Ixx<doxid-unionksl__inertiaf__t_1a38355270d1633949a289664d1133e896>`
	float :ref:`Iyy<doxid-unionksl__inertiaf__t_1ada7effe4365292c26afbac4daaed6bf0>`
	float :ref:`Izz<doxid-unionksl__inertiaf__t_1a32b7ff4d285a103d34f1e07319b0a604>`
	float :ref:`Ixy<doxid-unionksl__inertiaf__t_1a754af6d2c8a9d7072fde26dfe2aa7470>`
	float :ref:`Iyz<doxid-unionksl__inertiaf__t_1a90c45886158ce8485ddbc4820fae76a0>`
	float :ref:`Izx<doxid-unionksl__inertiaf__t_1a7f3550d75ec16feaa2db6ede933a0ef1>`

.. _details-doxid-unionksl__inertiaf__t:

Detailed Documentation
~~~~~~~~~~~~~~~~~~~~~~

single precision mass and inertia properties

Fields
------

.. _doxid-unionksl__inertiaf__t_1a531450fe0f798aabeb0bf2f462d2f1d6:
.. _cid-ksl_inertiaf_t::m:
.. ref-code-block:: cpp
	:class: title-code-block

	float m

mass

.. _doxid-unionksl__inertiaf__t_1a655bab49abb224308a73f020c6f1d430:
.. _cid-ksl_inertiaf_t::mt:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>` mt

mass times a vector, t, from reference frame to body centroid

.. _doxid-unionksl__inertiaf__t_1a38355270d1633949a289664d1133e896:
.. _cid-ksl_inertiaf_t::ixx:
.. ref-code-block:: cpp
	:class: title-code-block

	float Ixx

Ixx centroidal inertia term, expressed in reference frame coordinates

.. _doxid-unionksl__inertiaf__t_1ada7effe4365292c26afbac4daaed6bf0:
.. _cid-ksl_inertiaf_t::iyy:
.. ref-code-block:: cpp
	:class: title-code-block

	float Iyy

Ixy centroidal inertia term, expressed in reference frame coordinates

.. _doxid-unionksl__inertiaf__t_1a32b7ff4d285a103d34f1e07319b0a604:
.. _cid-ksl_inertiaf_t::izz:
.. ref-code-block:: cpp
	:class: title-code-block

	float Izz

Izz centroidal inertia term, expressed in reference frame coordinates

.. _doxid-unionksl__inertiaf__t_1a754af6d2c8a9d7072fde26dfe2aa7470:
.. _cid-ksl_inertiaf_t::ixy:
.. ref-code-block:: cpp
	:class: title-code-block

	float Ixy

Ixy centroidal inertia term, expressed in reference frame coordinates

.. _doxid-unionksl__inertiaf__t_1a90c45886158ce8485ddbc4820fae76a0:
.. _cid-ksl_inertiaf_t::iyz:
.. ref-code-block:: cpp
	:class: title-code-block

	float Iyz

Iyz centroidal inertia term, expressed in reference frame coordinates

.. _doxid-unionksl__inertiaf__t_1a7f3550d75ec16feaa2db6ede933a0ef1:
.. _cid-ksl_inertiaf_t::izx:
.. ref-code-block:: cpp
	:class: title-code-block

	float Izx

Izx centroidal inertia term, expressed in reference frame coordinates

