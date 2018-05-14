.. _influence_coefficient_matrices:
.. title:: Influence Coefficient Matrices


Influence Coefficient Matrices
===============================

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
