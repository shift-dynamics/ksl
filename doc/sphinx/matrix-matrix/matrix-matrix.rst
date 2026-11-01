.. _matrix-matrix:
.. title:: Matrix-matrix operations

Matrix-matrix operations
========================

Overview
--------

These functions compose rotations and rigid body transformations. If
:math:`D^{ab}` gives the pose of frame :math:`b` in frame :math:`a`, and
:math:`D^{bc}` the pose of frame :math:`c` in frame :math:`b`, the pose of
:math:`c` in :math:`a` is the product

.. math::

   D^{ac} = D^{ab} D^{bc}, \qquad
   R^{ac} = R^{ab} R^{bc}, \qquad
   \underline{t}^a_{ac} = R^{ab}\, \underline{t}^b_{bc} + \underline{t}^a_{ab}

(``ksl_product_dd``). In a robot arm or any other kinematic chain, the pose of
each link is found by multiplying the transformations of the joints and links
leading to it, from the base outward.

**Specialized products.** Most of the factors in such a chain are simple: a
rotation about one coordinate axis (a revolute joint) or a translation along
one axis (a prismatic joint or a link offset). The classic Denavit-Hartenberg
convention, for example, writes each link transformation as
:math:`R_z(\theta)\, T_z(d)\, T_x(a)\, R_x(\alpha)`
:cite:`hartenberg1964kinematic`. *KSL* has a function for each such factor,
which updates only the terms that change:

* ``ksl_product_ddrz(D, dc)`` computes :math:`D\, R_z(\theta)`. Only the first
  two columns of :math:`R` change, at a cost of 12 multiplications and 6
  additions, compared with 27 multiplications and 18 additions for a general
  3x3 product.
* ``ksl_product_ddtz(D, t)`` computes :math:`D\, T_z(t)`. Only the translation
  changes: :math:`\underline{t} \leftarrow \underline{t} + t\, R\,
  \underline{e}_z`, 3 multiplications and 3 additions.

The axis rotations take the angle as its ``{sin, cos}`` pair (see
:ref:`trig`). The ``inv`` variants multiply by an inverse without forming it,
for example ``ksl_product_dinvd`` computes :math:`(D^{ab})^{-1} D^{ac} =
D^{bc}`, which gives the pose of one frame relative to another when both are
known in a common frame. The ``dr`` functions do the same for rotation
matrices alone.

Double precision
----------------

.. doxygenfunction:: ksl_product_drdrx


.. doxygenfunction:: ksl_product_drdrxinv


.. doxygenfunction:: ksl_product_drdry


.. doxygenfunction:: ksl_product_drdryinv


.. doxygenfunction:: ksl_product_drdrz


.. doxygenfunction:: ksl_product_drdrzinv


.. doxygenfunction:: ksl_product_drdr


.. doxygenfunction:: ksl_product_drdrinv


.. doxygenfunction:: ksl_product_drinvdr


.. doxygenfunction:: ksl_product_ddrx


.. doxygenfunction:: ksl_product_ddrxinv


.. doxygenfunction:: ksl_product_ddry


.. doxygenfunction:: ksl_product_ddryinv


.. doxygenfunction:: ksl_product_ddrz


.. doxygenfunction:: ksl_product_ddrzinv


.. doxygenfunction:: ksl_product_ddt


.. doxygenfunction:: ksl_product_ddtinv


.. doxygenfunction:: ksl_product_dinvdt


.. doxygenfunction:: ksl_product_ddtx


.. doxygenfunction:: ksl_product_ddtxinv


.. doxygenfunction:: ksl_product_ddty


.. doxygenfunction:: ksl_product_ddtyinv


.. doxygenfunction:: ksl_product_ddtz


.. doxygenfunction:: ksl_product_ddtzinv


.. doxygenfunction:: ksl_product_ddr


.. doxygenfunction:: ksl_product_ddrinv


.. doxygenfunction:: ksl_product_dd


.. doxygenfunction:: ksl_product_ddinv


.. doxygenfunction:: ksl_product_dinvd



Single precision
----------------

.. doxygenfunction:: ksl_product_drdrxf


.. doxygenfunction:: ksl_product_drdrxinvf


.. doxygenfunction:: ksl_product_drdryf


.. doxygenfunction:: ksl_product_drdryinvf


.. doxygenfunction:: ksl_product_drdrzf


.. doxygenfunction:: ksl_product_drdrzinvf


.. doxygenfunction:: ksl_product_drdrf


.. doxygenfunction:: ksl_product_drdrinvf


.. doxygenfunction:: ksl_product_drinvdrf


.. doxygenfunction:: ksl_product_ddrxf


.. doxygenfunction:: ksl_product_ddrxinvf


.. doxygenfunction:: ksl_product_ddryf


.. doxygenfunction:: ksl_product_ddryinvf


.. doxygenfunction:: ksl_product_ddrzf


.. doxygenfunction:: ksl_product_ddrzinvf


.. doxygenfunction:: ksl_product_ddtf


.. doxygenfunction:: ksl_product_ddtinvf


.. doxygenfunction:: ksl_product_dinvdtf


.. doxygenfunction:: ksl_product_ddtxf


.. doxygenfunction:: ksl_product_ddtxinvf


.. doxygenfunction:: ksl_product_ddtyf


.. doxygenfunction:: ksl_product_ddtyinvf


.. doxygenfunction:: ksl_product_ddtzf


.. doxygenfunction:: ksl_product_ddtzinvf


.. doxygenfunction:: ksl_product_ddrf


.. doxygenfunction:: ksl_product_ddrinvf


.. doxygenfunction:: ksl_product_ddf


.. doxygenfunction:: ksl_product_ddinvf


.. doxygenfunction:: ksl_product_dinvdf
