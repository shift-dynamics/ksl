.. _coscrews:
.. title:: Coscrews

Coscrews
==========

Overview
--------

Just as the linear and angular velocities can be combined in to a single :math:`6 \times 1` column vector, forces and moments can be combined in a single quantity called a *wrench*.  A wrench is *dual* to a screw, i.e., it is a linear operator on a screw. In older literature, a wrench is often referred to as another kind of screw. In modern literature, a wrenches are referred to as a *coscrews* :cite:`selig2005geometric`. A superscript :math:`^*` is used to distinguish a coscrew from a screw. A wrench, :math:`\underline{\mathbf{f}}^*`, is defined as

.. math::
    :label: eq:wrench

    \underline{\mathbf{f}}^*=\begin{Bmatrix}\underline{f}\\ \underline{\tau}\end{Bmatrix}=
    \begin{Bmatrix}
    f_x\\
    f_y\\
    f_z\\
    \tau_x\\
    \tau_y\\
    \tau_z
    \end{Bmatrix}


Coadjoint Matrix :math:`[Ad]^*`
*******************************

As coscrews are dual to screws, they are transformed differently than screws. The following simple example illustrates how coscrews are transformed.  The power imparted by a linear combination of a wrench and screw is invariant, regardless of the coordinate system in which it is expressed. The power imparted by a given wrench and screw, the scalar quantity :math:`p`, is given as

.. math::
    :label: eq:power

    p = \underline{f}\cdot \underline{v} + \underline{\tau} \cdot \underline{\omega}=
    \underline{\mathbf{f}}^* \cdot \underline{\mathbf{v}} = \underline{\mathbf{f}}^{*T}\underline{\mathbf{v}}


Recall that the operator for transforming screw quantities is

.. math::
    :label: eq:adjoint_matrix2

    [Ad]=\begin{bmatrix}
    R & \tilde{r}R\\
    0 & R
    \end{bmatrix}


Therefore

.. math::
    :label: eq:transform_power

    p = \underline{\mathbf{f}}^{*T}\underline{\mathbf{v}}=
    \underline{\mathbf{f}}^{*T}
    [Ad]^{-1}[Ad]\underline{\mathbf{v}}=
    \underline{\mathbf{f}}^{*T}
    \begin{bmatrix}
    R^T & \tilde{r}R^T\\
    0 & R^T
    \end{bmatrix}
    \begin{bmatrix}
    R & \tilde{r}R\\
    0 & R
    \end{bmatrix}
    \underline{\mathbf{v}}=
    \underline{\mathbf{f}^*}' \cdot \underline{\mathbf{v}}'


And

.. math::
    :label: eq:transform_power2

    \underline{\mathbf{f}^*}'=
    [Ad]^{-T}\underline{\mathbf{f}}^*=[Ad]^*\underline{\mathbf{f}}^* =
    \begin{bmatrix}
    R & 0\\
    \tilde{r}R & R
    \end{bmatrix}
    \underline{\mathbf{f}}^*


Therefore, the :math:`6\times6` *coadjoint* transformation matrix for transforming coscrews is [#]_ :

.. math::
    :label: eq:coadjoint_matrix

    [Ad]^* =
    \begin{bmatrix}
    R & 0\\
    \tilde{r}R & R
    \end{bmatrix}


.. [#]

    Note that the linear components of force and velocity are found in the top position of the velocity screw and wrenches; the angular components are found in the lower position. This convention allows power to be computed using the linear algebra dot product operator. Many authors swap the angular and linear terms in screw and wrench quantities, in which case the dot product does not yield power, and a special "reciprocal product" operator, denoted as :math:`\odot` is used. For example, if angular terms are placed above the velocity screws, a reciprocal product is used to combine screw and coscrew quantities as:

    :math:`p = \underline{f}\cdot{\underline{v}} + \underline{\tau} \cdot \underline{\omega}=\mathscr{\underline{W}} \odot \underline{\$} = \begin{Bmatrix}\underline{f}\\ \underline{\tau}
    \end{Bmatrix}^T \begin{bmatrix}
    0 & I\\
    I & 0
    \end{bmatrix}
    \begin{Bmatrix}
    \underline{\omega}\\ \underline{v}
    \end{Bmatrix}`


    Certainly, no convention is *more correct* than another, however keeping linear and angular components in the same position in screws and coscrews does have its advantages: (1) it obviates the need to introduce an additional reciprocal product operator, and (2) when formulating the equations of motion, the generalized mass matrix is symmetric, allowing the equations to be solved more efficiently using standard numerical methods.


Constraint Forces
*****************

Consider two bodies pinned together by a revolute joint aligned with the :math:`z` axis of its local coordinate frame, :math:`a`. If the joint is modeled without friction, then no torques about the joint axis can be transmitted from the first body to the second body. The only forces that can be imparted from one joint to the next are those orthogonal to the joint's axis. If a spatial wrench :math:`\underline{\mathbf{f}}^*_a` is applied to the joint, the non--working joint reaction forces are given by

.. math::
    :label: eq:joint_reaction_forces

    \bar{H}^*_a\underline{\mathbf{f}}^*_a=
    \begin{bmatrix}
    1 & 0 & 0 & 0 & 0 & 0\\
    0 & 1 & 0 & 0 & 0 & 0\\
    0 & 0 & 1 & 0 & 0 & 0\\
    0 & 0 & 0 & 1 & 0 & 0\\
    0 & 0 & 0 & 0 & 1 & 0\\
    0 & 0 & 0 & 0 & 0 & 0\\
    \end{bmatrix}\underline{\mathbf{f}}^*_a


The coadjoint transformation matrix, :math:`[Ad]^*`, from Eq. :eq:`eq:coadjoint_matrix` provides a convenient and compact method to express constraint forces in other coordinate systems.


.. math::
    :label: eq:h_bar_star

    \bar{H}^*_0=[Ad]^*_{0a}\begin{bmatrix}
    1 & 0 & 0 & 0 & 0 & 0\\
    0 & 1 & 0 & 0 & 0 & 0\\
    0 & 0 & 1 & 0 & 0 & 0\\
    0 & 0 & 0 & 1 & 0 & 0\\
    0 & 0 & 0 & 0 & 1 & 0\\
    0 & 0 & 0 & 0 & 0 & 0\\
    \end{bmatrix}=
    \begin{bmatrix}
    R_{0a} & 0\\
    \tilde{r}_{0a}R_{0a} & R_{0a}
    \end{bmatrix}
    \begin{bmatrix}
    1 & 0 & 0 & 0 & 0 & 0\\
    0 & 1 & 0 & 0 & 0 & 0\\
    0 & 0 & 1 & 0 & 0 & 0\\
    0 & 0 & 0 & 1 & 0 & 0\\
    0 & 0 & 0 & 0 & 1 & 0\\
    0 & 0 & 0 & 0 & 0 & 0\\
    \end{bmatrix}


Second, consider the case where working forces may be applied in a joint, such as in a robotic actuator. The torque provided by the motor required to resist the applied wrench :math:`\underline{f}_a^*` is given by

.. math::
    :label: eq:h_star

    \bar{h}^*_0\underline{\mathbf{f}}_a^*=[Ad]^*\begin{bmatrix}
    0 & 0 & 0 & 0 & 0 & 0\\
    0 & 0 & 0 & 0 & 0 & 0\\
    0 & 0 & 0 & 0 & 0 & 0\\
    0 & 0 & 0 & 0 & 0 & 0\\
    0 & 0 & 0 & 0 & 0 & 0\\
    0 & 0 & 0 & 0 & 0 & 1\\
    \end{bmatrix}\underline{\mathbf{f}}_a^*=
    \begin{bmatrix}
    R_{0a} & 0\\
    \tilde{r}_{0a}R_{0a} & R_{0a}
    \end{bmatrix}
    \begin{bmatrix}
    0 & 0 & 0 & 0 & 0 & 0\\
    0 & 0 & 0 & 0 & 0 & 0\\
    0 & 0 & 0 & 0 & 0 & 0\\
    0 & 0 & 0 & 0 & 0 & 0\\
    0 & 0 & 0 & 0 & 0 & 0\\
    0 & 0 & 0 & 0 & 0 & 1\\
    \end{bmatrix}\underline{\mathbf{f}}_a^*


From Eqs. :eq:`eq:h_bar_star` and :eq:`eq:h_star` it follows that

.. math::
    :label: eq:H_union_h_star

    [Ad]^*=[\bar{H}^* \cup \underline{\mathbf{h}}^*]


and additionally that

.. math::
    :label: eq:HT_times_h_star

    \bar{H}^{T} \underline{\mathbf{h}}^* = 0


as each of the columns of :math:`\bar{H}^*` are orthogonal to :math:`\underline{\mathbf{h}}^*`.

In the present example, :math:`[\bar{H}^* \cup \underline{\mathbf{h}}^*]=[\bar{H}^* \underline{\mathbf{h}}^*]`, as :math:`\underline{\mathbf{h}}^*` occurs in the last column of :math:`[Ad]^*`, however in the general case, :math:`\underline{\mathbf{h}}^*` may occur in a different column of :math:`[Ad]^*`, corresponding to the type of primitive joint. In the following discussion, the :math:`\cup` symbol is dropped with the understanding that the matrix :math:`\underline{\mathbf{h}}^*` occurs in its respective column, interspersed within the columns of :math:`\bar{H}^*`.


Derivative operator matrices: :math:`[ad]^*`
********************************************

The left derivative operator for :math:`[Ad]^*` matrices is:

.. math::
    :label: eq:adjoint_dual_rep

    [ad]^* = \dot{[Ad]^*}[Ad]^{*-1} =
    \begin{bmatrix}
    0 & -\omega_z & \omega_{y} & 0 & 0 & 0\\
    \omega_z & 0 & -\omega_x & 0 & 0 & 0\\
    -\omega_y & \omega_x & 0 & 0 & 0 & 0\\
    0 & -v_z & v_y & 0 & -\omega_z & \omega_{y} \\
    v_z & 0 & -v_x &   \omega_z & 0 & -\omega_x\\
    -v_y & v_x & 0 & -\omega_y & \omega_x & 0
    \end{bmatrix}=
    \begin{bmatrix}
    \tilde{\omega} & 0\\
    \tilde{v} & \tilde{\omega}
    \end{bmatrix}


Double precision
----------------

.. doxygenunion:: ksl_coscrew_t


.. doxygenfunction:: ksl_coscrew


.. doxygenfunction:: ksl_coscrew_alloc


.. doxygenfunction:: ksl_coscrew_copy


.. doxygenfunction:: ksl_coscrew_scale


.. doxygenfunction:: ksl_coscrew_inverted


.. doxygenfunction:: ksl_coscrew_invert


.. doxygenfunction:: ksl_axpy_cc


.. doxygenfunction:: ksl_xpy_cc


.. doxygenfunction:: ksl_nxpy_cc


.. doxygenfunction:: ksl_product_ac


.. doxygenfunction:: ksl_add_cc


.. doxygenfunction:: ksl_subtract_cc


.. doxygenfunction:: ksl_cross_sc


.. doxygenfunction:: ksl_product_CoAdtc


.. doxygenfunction:: ksl_product_CoAdtcinv


.. doxygenfunction:: ksl_product_CoAdrc


.. doxygenfunction:: ksl_product_CoAdrinvc


.. doxygenfunction:: ksl_product_CoAdc


.. doxygenfunction:: ksl_product_CoAdinvc



Single precision
----------------

.. doxygenunion:: ksl_coscrewf_t


.. doxygenfunction:: ksl_coscrewf


.. doxygenfunction:: ksl_coscrewf_alloc


.. doxygenfunction:: ksl_coscrewf_copy


.. doxygenfunction:: ksl_coscrewf_scale


.. doxygenfunction:: ksl_coscrewf_inverted


.. doxygenfunction:: ksl_coscrewf_invert


.. doxygenfunction:: ksl_axpy_ccf


.. doxygenfunction:: ksl_xpy_ccf


.. doxygenfunction:: ksl_nxpy_ccf


.. doxygenfunction:: ksl_product_acf


.. doxygenfunction:: ksl_add_ccf


.. doxygenfunction:: ksl_subtract_ccf


.. doxygenfunction:: ksl_cross_scf


.. doxygenfunction:: ksl_product_CoAdtcf


.. doxygenfunction:: ksl_product_CoAdtcinvf


.. doxygenfunction:: ksl_product_CoAdrcf


.. doxygenfunction:: ksl_product_CoAdrinvcf


.. doxygenfunction:: ksl_product_CoAdrcf


.. doxygenfunction:: ksl_product_CoAdinvcf
