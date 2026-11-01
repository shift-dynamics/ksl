.. _matrix-vector:
.. title:: Matrix-vector operations

Matrix-vector operations
========================

Overview
--------

These functions apply a rotation or a rigid body transformation to a vector.
The operand abbreviations are explained in :ref:`getting-started`: ``dr`` is a
rotation matrix, ``d`` a full transformation :math:`D = (R, \underline{t})`,
and ``inv`` after either one means its inverse.

**Points and free vectors transform differently.** A *point*, such as the
location of a marker on a body, changes frame with both the rotation and the
translation:

.. math::

   \underline{p}^a = R^{ab}\, \underline{p}^b + \underline{t}^a_{ab}
   \qquad \text{(}\texttt{ksl\_product\_dv}\text{)}

A *free vector*, such as a velocity, a force or the direction of an axis, has
no location, so it is only rotated:

.. math::

   \underline{v}^a = R^{ab}\, \underline{v}^b
   \qquad \text{(}\texttt{ksl\_product\_drv}\text{)}

Using the wrong one is a common source of errors.

**Inverse transformations** go the other way, from frame :math:`a` to frame
:math:`b`. They are applied directly from :math:`R` and :math:`\underline{t}`,
without computing and storing the inverse:

.. math::

   \underline{p}^b = (R^{ab})^T (\underline{p}^a - \underline{t}^a_{ab})
   \qquad \text{(}\texttt{ksl\_product\_dinvv}\text{)}

**Translations along an axis.** The ``drvtx``, ``drvty`` and ``drvtz``
functions rotate a vector that lies along a coordinate axis,
:math:`R\,(t\,\underline{e}_x)`. That is just :math:`t` times the first column
of :math:`R`, so it costs 3 multiplications instead of the 9 multiplications
and 6 additions of a general matrix-vector product.

Double precision
----------------

.. doxygenfunction:: ksl_product_drv


.. doxygenfunction:: ksl_product_drvinv


.. doxygenfunction:: ksl_product_drinvv


.. doxygenfunction:: ksl_product_drinvvinv


.. doxygenfunction:: ksl_product_drvtx


.. doxygenfunction:: ksl_product_drvtxinv


.. doxygenfunction:: ksl_product_drvty


.. doxygenfunction:: ksl_product_drvtyinv


.. doxygenfunction:: ksl_product_drvtz


.. doxygenfunction:: ksl_product_drvtzinv


.. doxygenfunction:: ksl_product_dv


.. doxygenfunction:: ksl_product_dinvv


Single precision
----------------

.. doxygenfunction:: ksl_product_drvf


.. doxygenfunction:: ksl_product_drvinvf


.. doxygenfunction:: ksl_product_drinvvf


.. doxygenfunction:: ksl_product_drinvvinvf


.. doxygenfunction:: ksl_product_drvtxf


.. doxygenfunction:: ksl_product_drvtxinvf


.. doxygenfunction:: ksl_product_drvtyf


.. doxygenfunction:: ksl_product_drvtyinvf


.. doxygenfunction:: ksl_product_drvtzf


.. doxygenfunction:: ksl_product_drvtzinvf


.. doxygenfunction:: ksl_product_dvf


.. doxygenfunction:: ksl_product_dinvvf
