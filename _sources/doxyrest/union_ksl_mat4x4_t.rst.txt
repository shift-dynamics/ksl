.. index:: pair: union; ksl_mat4x4_t
.. _doxid-unionksl__mat4x4__t:
.. _cid-ksl_mat4x4_t:

union ksl_mat4x4_t
==================

.. toctree::
	:hidden:

.. code-block:: cpp
	:class: overview-code-block

	#include <matrix.h>


Overview
~~~~~~~~

general 4x4 double precision matrix :ref:`More...<details-doxid-unionksl__mat4x4__t>`

.. _doxid-unionksl__mat4x4__t_1a6bdede3ec2682ed43dd9c3b4f0f70111:
.. _cid-ksl_mat4x4_t::at:
.. _doxid-unionksl__mat4x4__t_1a118e9e1947836c9e8a09b171f7fe0a4d:
.. _cid-ksl_mat4x4_t::as_array:
.. _doxid-unionksl__mat4x4__t_1aaa6f86ad444a4cc69c51c14786f9269b:
.. _cid-ksl_mat4x4_t::m00:
.. _doxid-unionksl__mat4x4__t_1a8e8afc7688310155483c3c9e5f5380c6:
.. _cid-ksl_mat4x4_t::m10:
.. _doxid-unionksl__mat4x4__t_1ab1c099a2c160338a69a77daf0b0b53e6:
.. _cid-ksl_mat4x4_t::m20:
.. _doxid-unionksl__mat4x4__t_1a12016bb418969f7616e48cb931a8d847:
.. _cid-ksl_mat4x4_t::m30:
.. _doxid-unionksl__mat4x4__t_1a69b9748a3bb0ecdb6b3ce7c661c1c8ff:
.. _cid-ksl_mat4x4_t::m01:
.. _doxid-unionksl__mat4x4__t_1ad117cb0707b9cfd13358902aa9c05610:
.. _cid-ksl_mat4x4_t::m11:
.. _doxid-unionksl__mat4x4__t_1a9d0fa8f5410d2c59b70ff55ee1f94f05:
.. _cid-ksl_mat4x4_t::m21:
.. _doxid-unionksl__mat4x4__t_1a37e102cb3745e527511667c35bdcd3aa:
.. _cid-ksl_mat4x4_t::m31:
.. _doxid-unionksl__mat4x4__t_1a1510fa969f934d6c1cd8149f48a48f2a:
.. _cid-ksl_mat4x4_t::m02:
.. _doxid-unionksl__mat4x4__t_1acb960fe71180a3ab7f125ebe7b6ada1c:
.. _cid-ksl_mat4x4_t::m12:
.. _doxid-unionksl__mat4x4__t_1aa7b089f5ca3bcc77e2d4f1eae1bc52ab:
.. _cid-ksl_mat4x4_t::m22:
.. _doxid-unionksl__mat4x4__t_1aa1ed0515112e4b548c287c1d5e752751:
.. _cid-ksl_mat4x4_t::m32:
.. _doxid-unionksl__mat4x4__t_1ad2503c720dca9d142206917d3f19a725:
.. _cid-ksl_mat4x4_t::m03:
.. _doxid-unionksl__mat4x4__t_1a22a655278a32f92214f37cbf7e7228b5:
.. _cid-ksl_mat4x4_t::m13:
.. _doxid-unionksl__mat4x4__t_1a1290f7b29005c6bb03a36733af17c7b0:
.. _cid-ksl_mat4x4_t::m23:
.. _doxid-unionksl__mat4x4__t_1a5af9cd475cc771ff8e6332dbb581f350:
.. _cid-ksl_mat4x4_t::m33:
.. _doxid-unionksl__mat4x4__t_1a7186939d46d3265dc53f5877a82cfc7b:
.. _cid-ksl_mat4x4_t::@21:
.. _doxid-unionksl__mat4x4__t_1ada7c5c1b80c8bf03d88b7eb93b9c4220:
.. _cid-ksl_mat4x4_t::v0:
.. _doxid-unionksl__mat4x4__t_1a05b1b3778a7f270ea2a50735d36b1dcc:
.. _cid-ksl_mat4x4_t::v1:
.. _doxid-unionksl__mat4x4__t_1ac13bac37de762a17149ea6f98add9d52:
.. _cid-ksl_mat4x4_t::v2:
.. _doxid-unionksl__mat4x4__t_1ad6de37665a6d582b7a78a6e85ae8040e:
.. _cid-ksl_mat4x4_t::v3:
.. _doxid-unionksl__mat4x4__t_1a9816a3f18af4659f57cae555a6edc59b:
.. _cid-ksl_mat4x4_t::@23:
.. ref-code-block:: cpp
	:class: overview-code-block

	// fields

	double at [16]
	double as_array [4][4]
	double m00
	double m10
	double m20
	double m30
	double m01
	double m11
	double m21
	double m31
	double m02
	double m12
	double m22
	double m32
	double m03
	double m13
	double m23
	double m33
	:ref:`ksl_vec4_t<doxid-unionksl__vec4__t>` v0
	:ref:`ksl_vec4_t<doxid-unionksl__vec4__t>` v1
	:ref:`ksl_vec4_t<doxid-unionksl__vec4__t>` v2
	:ref:`ksl_vec4_t<doxid-unionksl__vec4__t>` v3

.. _details-doxid-unionksl__mat4x4__t:

Detailed Documentation
~~~~~~~~~~~~~~~~~~~~~~

general 4x4 double precision matrix

allow accessing mat4x4 quantities by field name or using at / as_array operators. if using the at / as_array operators, quantities are accessed in column major order

