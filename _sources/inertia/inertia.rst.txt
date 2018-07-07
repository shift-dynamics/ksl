.. _inertia:
.. title:: Inertia

Inertia
==========

In the body center of mass frame, the :math:`6 \times 6` Inertia matrix, :math:`M`, can be expressed as:

.. math::
  :label: eq:inertia_matrix

  M_{11} = \begin{bmatrix}
  mI & 0\\
  0 & \bar{I}
  \end{bmatrix}


Where :math:`m` is the body mass, :math:`I` is a :math:`3 \times 3` identity matrix and :math:`\bar{I}` is the :math:`3 \times 3` rotational inertia matrix. The body center of mass frame is denoted with a subscript :math:`c`. When solving the equations of motion in a fixed inertial reference frame, it is necessary to transform these local inertia matrices to the origin of the fixed inertial reference frame, which is denoted with a subscript :math:`f`. To understand how the inertia matrix is transformed to other coordinate systems, consider the equation for momentum, :math:`\underline{\mathbf{p}}^*`. Note that the asterisk indicates the :math:`\underline{\mathbf{p}}^*` is a *coscrew* quantity.

.. math::
  :label: eq:transform_1

  \underline{\mathbf{p}}^*_f = M_{cc} \underline{\mathbf{v}}_c


As noted above, coscrew quantities are transformed by left multiplication with the coadjoint operator, :math:`[Ad]^*`.

.. math::
  :label: eq:transform_2

  [Ad]^*_{cf}\underline{\mathbf{p}}_f = M_{cc}[Ad]_{fc}^{-1}[Ad]_{fc}\underline{\mathbf{v}}_c


.. math::
  :label: eq:transform_3

  \underline{\mathbf{p}}_f = [Ad]^{*-1}_{10}M_{11}[Ad]^{-1}_{fc}{\underline{\mathbf{v}}}_f=
  [Ad]^*_{fc}M_{cc}[Ad]_{cf}\underline{\mathbf{v}}_f


yielding:

.. math::
  :label: eq:transform_4

  M_{ff} = [Ad]^*_{fc}M_{cc}[Ad]_{cf}


Again the :math:`6 \times 6` Adjoint and Coadjoint matrices provides a convenient and compact notation to describe transformations, but full dense matrix algebra need not be applied to carry out transformation of the inertia matrix, noting that:

.. math::
  :label: eq:minimum_operations

  M_{ff} = [Ad]^*_{fc}M_{cc}[Ad]_{cf} =
  \begin{bmatrix}
  R_{fc}m_cIR_{cf} & R_{fc}m_cI\tilde{r}_{cf}R_{cf}\\
  \tilde{r}_{cf}R_{cf}m_1IR_{cf}&
  \tilde{r}_{cf}R_{cf}m_cI\tilde{r}_{cf}R_{cf} + R_{fc}\bar{I}_{cc}R_{cf}
  \end{bmatrix}


which can be further simplified as:

.. math::
  :label: eq:further_simplified

  M_{ff} = \begin{bmatrix}
  m_cI &  m_cR_{fc}\tilde{r}_{cf}R_{cf}\\
  -m_cR_{fc}\tilde{r}_{cf}R_{cf}     & \bar{I}_{cc} -m_c\tilde{r}_{cf}^2
  \end{bmatrix}


and:

.. math::
  :label: eq:further_simplified2

  M_{ff} = \begin{bmatrix}
  m_cI &  m_c\tilde{r}_{cf}\\
  -m_c\tilde{r}_{cf}     & \bar{I}_{cc} -m_c\tilde{r}_{cf}^2
  \end{bmatrix}


Based on Eq. :eq:`eq:further_simplified2`, it is only necessary to store ten terms to reconstruct the inertia matrix: :math:`m_c, m_c\underline{r}`, and the terms on and below the diagonal of :math:`\bar{I}` (i.e. :math:`I_{xx}`, :math:`I_{yy}`, :math:`I_{zz}`, :math:`I_{xy}`, :math:`I_{yz}` and :math:`I_{zx}`). Storing only these 10 terms requires approximately 70% less storage than the full :math:`6\times6` inertia matrix. In order to take advantage of SIMD for various algorithms which access the quantities in the inertia matrix, additional memory is used to store the quantity :math:`-m_c\underline{r}`, which still results in a 64% reduction in storage compared to the full :math:`6 \times 6` representation.

If the reference frame for the body is not taken as the center of mass, then in addition to the inertia matrix stored in the center of mass coordinate system, a vector from the body's reference frame to the center of mass frame, :math:`\underline{r}^{bc}_b`, is stored. Here, the subscript :math:`b` denotes the body reference frame and the :math:`c` denotes the center of mass frame.

.. math::
  :label: eq:not_com_frame

  M_{ff} = [Ad]^{*}_{fb}[Ad]^{*}_{bc} M_{cc} [Ad]_{cb}[Ad]_{bf}


.. math::
  :label: eq:not_com_frame2

  M_{ff} = R_{fb} \bar{I}_{bb}^{cc} R_{bf}


.. math::
  :label: eq:not_com_frame3

  \underline{r}_{f}^{fc} = \underline{r}_{f}^{fb} + R_{fb} \underline{r}_{b}^{bc}


.. math::
  :label: eq:not_com_frame4

  \underline{t}_{temp} = m_c \underline{r}_{f}^{fc}


.. math::
  :label: eq:not_com_frame5

  M_{ff} = \begin{bmatrix} mI &  -\tilde{t}_{temp}\\
  \tilde{t}_{temp} & \bar{I}^{ff}_{cc} - \tilde{t}_{temp} \tilde{t}^{f}_{fc}\end{bmatrix}


Then use the following identity to simplify the matrix product :math:`\tilde{t}_{temp} \tilde{t}^{f}_{fc}`:

.. math::
  :label: eq:identity_simplify

  \tilde{a} \tilde{b} = b a^T - (a^T b) I


Therefore, :math:`\tilde{a} \tilde{b}` is found as:

.. math::
  :label: eq:identity_simplify2

  \begin{array} \text{result} \leftarrow \begin{Bmatrix}b_0 \\ b_1 \\ b_2\end{Bmatrix} \begin{Bmatrix}a_0&a_1&a_2\end{Bmatrix}\\
  result -= trace(result) * I
  \end{array}


.. math::
  :label: eq:result

  \bar{I}^{ff}_{ff} = \bar{I}^{ff}_{cc} - \tilde{t}_{temp} \tilde{r}^{f}_{fc}


.. math::
  :label: eq:result2

  \bar{I}^{ff}_{ff} = \bar{I}^{ff}_{cc} - result


KSL double precision inertia matrices
-------------------------------------

.. doxygenunion:: ksl_inertia_t


.. doxygenfunction:: ksl_inertia


.. doxygenfunction:: ksl_inertia_alloc


.. doxygenfunction:: ksl_inertia_rotated


.. doxygenfunction:: ksl_inertia_rotate


.. doxygenfunction:: ksl_inertia_translated


.. doxygenfunction:: ksl_inertia_translate


.. doxygenfunction:: ksl_inertia_transformed


.. doxygenfunction:: ksl_inertia_transform


.. doxygenfunction:: ksl_inertia_merge


.. doxygenfunction:: ksl_inertia_factor


KSL single precision inertia matrices
-------------------------------------

.. doxygenunion:: ksl_inertiaf_t


.. doxygenfunction:: ksl_inertiaf


.. doxygenfunction:: ksl_inertiaf_alloc


.. doxygenfunction:: ksl_inertiaf_rotated


.. doxygenfunction:: ksl_inertiaf_rotate


.. doxygenfunction:: ksl_inertiaf_translated


.. doxygenfunction:: ksl_inertiaf_translate


.. doxygenfunction:: ksl_inertiaf_transformed


.. doxygenfunction:: ksl_inertiaf_transform


.. doxygenfunction:: ksl_inertiaf_merge


.. doxygenfunction:: ksl_inertiaf_factor
