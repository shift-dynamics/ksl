.. _coscrews:
.. title:: Coscrews

Coscrews
==========

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
----------------------------------

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


Influence Coefficient Matrices
------------------------------

An important tool in the analysis of mechanisms and multibody systems is a map of a particular joint's velocity to the body velocity. From Eqs. :eq:`eq:omega_z` and :eq:`eq:screw`, it is possible to find the velocity screw associated with a revolute joint. The joint is aligned with :math:`z` axis of reference frame :math:`a`.

.. math::
    :label: eq:unit_velocity

    \underline{\mathbf{v}}_a=
    \begin{Bmatrix}
    0\\0\\ 0\\ 0\\ 0\\\dot{q}
    \end{Bmatrix}=
    \begin{Bmatrix}
    0\\0\\ 0 \\0 \\0 \\1
    \end{Bmatrix}\dot{q}=\underline{\mathbf{h}}_a\dot{q}


Here :math:`\underline{h}_a` is the *influence coefficient matrix* :cite:`tsai1999robot` associated with the joint. Note that the influence coefficient matrix taken at the joint's origin is simply a unit twist, :math:`\omega_z`, about the :math:`z` axis.

Usually it is desirable to express the influence coefficient matrix with respect to other coordinate systems, such as the inertial reference frame. Using the :math:`[Ad]` operator in Eq. :eq:`eq:screw` yields:

.. math::
    :label: eq:influence_coefficient_matrix

    \underline{\mathbf{v}}_0=
    \underline{\mathbf{h}}_0\dot{q}=
    [Ad]_{0a} \underline{\mathbf{h}}_a\dot{q}=
    \begin{bmatrix}
    R_{0a} &\tilde{r}_{0a}R_{0a}\\
    0 & R_{0a}
    \end{bmatrix}
    \begin{Bmatrix}
    0\\0\\ 0 \\0 \\0 \\1
    \end{Bmatrix}\dot{q}


These influence coefficient matrices taken with respect to the inertial reference frame form elements of the Jacobian matrix of a mechanism. As a mechanism moves through varying configurations, :math:`\underline{h}_0` changes, and may require updating many millions of times in the course of a simulation. Equation :eq:`eq:influence_coefficient_matrix` reveals important insight that allows one to reduce the number of floating point operations (FLOPs) required to update the influence coefficient matrix of primitive joints.

.. math::
    :label: eq:screw_basis

    \underline{\mathbf{h}}_0=
    \begin{Bmatrix}
    r_yR_{33}-r_zR_{23}\\
    r_zR_{13}-r_xR_{33}\\
    r_xR_{23}-r_yR_{13}\\
    R_{13}\\
    R_{23}\\
    R_{33}\\
    \end{Bmatrix}=
    \begin{bmatrix}
    R_{11} & R_{12} & R_{13} & r_yR_{31}-r_zR_{21} & r_yR_{32}-r_zR_{22} & r_yR_{33}-r_zR_{23}\\
    R_{21} & R_{22} & R_{11} & r_zR_{11}-r_xR_{31} & r_zR_{12}-r_xR_{32} & r_zR_{13}-r_xR_{33}\\
    R_{31} & R_{32} & R_{33} & r_xR_{21}-r_yR_{11} & r_xR_{22}-r_yR_{12} & r_xR_{23}-r_yR_{13}\\
    0 & 0 & 0 & R_{11} & R_{12} & R_{13}\\
    0 & 0 & 0 & R_{21} & R_{22} & R_{23}\\
    0 & 0 & 0 & R_{31} & R_{32} & R_{33}\\
    \end{bmatrix}
    \begin{Bmatrix}
    0\\0\\ 0 \\0 \\0 \\1
    \end{Bmatrix}


Once the position and orientation of each joint in a mechanism has been computed, the influence coefficient matrix can be computed simply by forming the corresponding column of :math:`[Ad]`, which requires only 9 additional FLOPs for revolute joints and no additional FLOPs for prismatic joints. Additionally, if SE(3) displacements and the Jacobian matrix are stored in column-major order, updating the influence coefficient matrices and elements Jacobian matrix can be vectorized with a stride of 1, which is optimal in terms of memory access.


Constraint Forces
-----------------

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


Inertia
-------------------------------

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


..
    #   [R          0] [mI         -m\tilde{t2}] [R^T   -R^T\tilde{t1}]
    #   [\tilde{t1}R R] [m\tilde{t2} M_2        ] [0       R^T        ]
    #
    #  [I          0]  [R 0] [mI         -m\tilde{t2}] [R^T 0  ] [I  -\tilde{t1}]
    #  [\tilde{t1} I]  [0 R] [m\tilde{t2} M_2        ] [0   R^T] [0  I         ]
    #
    # step 1: multiply middle part (rotations)
    # R * mI * R^T = mI <-- does nothing
    # -mR*\tilde{t2}R^T <-- applying similarity transformation converts to fixed
    #                       inertial reference frame
    # m\tilde{t2}^{fixed} = R * m\tilde{t2}^{body} * R^T <-- this is equivalent to:
    # m{t2}^{fixed} = R * m{t2}^{body}
    # R * M2 * R^T
    #
    # step 2: multiple outer part (translations)
    # left multiplication
    # [mI            -m\tilde{t2}      ] * [I  -\tilde{t1}]
    # [m * (t1 + t2) M2-m\tilde1\tilde2]   [0  I          ]
    #
    # [mI                         -m(\tilde{t1} + \tilde{t2})]
    # [m(\tilde{t1} + \tilde{t2}) M2 - m * (\tilde{t1}\tilde{t2} + \tilde{t1}**2
    # + \tilde{t2}\tilde{t1})]
    #
    # Don't do it the way above, assume we are storing the inertia matrix at
    # the center of mass and we have a vector from the body reference frame to the
    # center of mass, then the number of operations is reduced
    #
    #   D^{-T} * M * D^{-1}
    #   M2^{ff}_{cc} = R^{fb} * M2^{bb}_{cc} * R^{fb}^T
    #   t^{f}_{fc} = t^{f}_{fb} + R^{fb} * t^{b}_{bc}
    #   temp = m * t^{f}_{fc}
    #
    #   [mI           -\tilde{temp}                                   ]
    #   [\tilde{temp} M2^{ff}_{cc} - \tilde{temp} * \tilde{t^{f}_{fc}}]
    #
    #  use the following identity to simplify \tilde{temp} * \tilde{t^{f}_{fc}}
    # \tilde{a} * \tilde{b} = b * a^T - (a^T * b) * I
    # result = [b0 b1 b2]^T * [a0 a1 a2]
    # result -= trace(result) * I
    #
    # M2^{ff}_{ff} = M2^{ff}_{cc} - \tilde{temp} * \tilde{t^{f}_{fc}}
    # M2^{ff}_{ff} = M2^{ff}_{cc} - result



More derivative operator matrices: :math:`[ad]` and :math:`[ad]^*`
------------------------------------------------------------------

In Eq. :eq:`eq:spatial_velocity2`, the derivative operator of the SE(3) group was found. Similarly, the derivative operator matrices for the :math:`6 \times 6` transformation matrices, :math:`[Ad]` and :math:`[Ad]^*` can be found as follows:

..
  The :math:`6\times 6` :math:`[Ad]` matrices themselves fulfill all the necessary requirements of a Lie group :cite:`selig2005geometric`. The requirements of a general mathematical group are as follows:

..
  * The group is closed under a binary operation
  * Operations are associative
  * The group must have a unique identity element
  * Every element of the group must have a unique inverseSimilarly, the (left) derivative operator for :math:`[Ad]` matrices is found as:

..
  Lie groups must satisfy the additional axioms:

..
  * The set of group elements, :math:`G`, form a differential manifold
  * A group operation must be a differentiable map.


.. math::
  :label: eq:adjoint_representation

  [ad] = \dot{[Ad]}[Ad]^{-1} =
  \begin{bmatrix}
  0 & -\omega_z & \omega_{y} & 0 & -v_z & v_y\\
  \omega_z & 0 & -\omega_x & v_z & 0 & -v_x\\
  -\omega_y & \omega_x & 0 & -v_y & v_x & 0\\
  0 & 0 & 0 & 0 & -\omega_z & \omega_{y} \\
  0 & 0 & 0 &   \omega_z & 0 & -\omega_x\\
  0 & 0 & 0 & -\omega_y & \omega_x & 0
  \end{bmatrix}=
  \begin{bmatrix}
  \tilde{\omega} & \tilde{v}\\
  0 & \tilde{\omega}
  \end{bmatrix}

Similarly, the left derivative operator for :math:`[Ad]^*` matrices is:

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


Previously, it was discussed how the derivative operators form the Lie algebra of the SE(3) group. Similarly, the :math:`6\times6` :math:`[Ad]` matrices themselves fulfill the necessary requirements of a Lie group :cite:`selig2005geometric`. The :math:`[ad]` and :math:`[ad]^*` matrices comprise their respective Lie algebras.
