.. _screws:
.. title:: Screws

Screws
==========

In the early 1800s, Chasles proved that any change in the configuration of a rigid body can be parameterized in terms of a helical motion along a fixed axis :cite:`chasles1830note`. Poinsot is credited with the discovery that a system of forces acting on a rigid body can be resolved as a force acting along a line combined with a torque acting about the same line :cite:`poinsot1806composition`. Chasles' and Poinsot's work was later developed by Sir Robert Ball into the theory of screws :cite:`ball1998treatise`. Screws represent angular and translational quantities in a single 6x1 vector quantity. Not only do screws provide a systematic framework for kinematics and dynamics of mechanisms, their compact representation is well-suited for compact computer storage and facilitates vectorization.

Linear and angular velocity can be combined into a single 6x1 quantity as:

.. math::
    :label: eq:screw_1

    \underline{\mathbf{v}} = \begin{Bmatrix}\underline{v}\\ \underline{\omega}\end{Bmatrix}


In 1873, Clifford coined the word *motor* to refer to this screw quantity (i.e. a combination of *motion* and *vector*) :cite:`davidson2004robots`. Later, Ball referred to this screw quantity as a *twist* :cite:`ball1998treatise`. The term *twist* is used more frequently in modern literature, and therefore is used in the present work.

Adjoint Matrix :math:`[Ad]`
----------------------------

The :math:`6 \times 6` adjoint transformation matrix, :math:`[Ad]`, for transforming twists from one coordinate system to another can be formed from :math:`SE(3)` matrices. The derivation is briefly summarized below:

Consider a displacement about the :math:`z` axis given by the Special Orthogonal :math:`SO(3)` matrix:

.. math::
    :label: eq:SO3_matrix

    \underline{a}=R_{ab}\underline{b}=
    \begin{bmatrix}
    cos\theta_z & -sin\theta_z & 0\\
    sin \theta_z & cos\theta_z & 0\\
    0 & 0 & 1
    \end{bmatrix}\underline{b}


Then

.. math::
    :label: eq:velocity_transformation

    \dot{a}=\dot{R}_{ab}=\left[ \dot{R_{ab}}R^T_{ab} \right] R_{ab}b


.. math::
    :label: eq:omega_z

    \dot{R}^T=
    \begin{bmatrix}
    -\dot{\theta_z} sin \theta_z & -\dot{\theta_z} cos \theta_z & 0\\
    \dot{\theta_z} cos \theta_z & -\dot{\theta_z} sin \theta_z & 0\\
    0 & 0 & 0
    \end{bmatrix}
    \begin{bmatrix}
    cos \theta_z & sin \theta_z & 0\\
    -sin \theta_z & cos \theta_z & 0\\
    0 & 0 & 1
    \end{bmatrix}=
    \begin{bmatrix}
    0 & -\dot{\theta_z} & 0\\
    \dot{\theta_z} & 0 & 0 \\
    0 & 0 & 0
    \end{bmatrix}=\tilde{\omega}_z


Where :math:`\tilde{\omega}_z` is a skew symmetric matrix and the spatial velocity is given by


.. math::
    :label: eq:spatial_velocity

    \underline{\omega}=\begin{Bmatrix}
    0\\
    0\\
    \dot{\theta_z}
    \end{Bmatrix}=
    \begin{Bmatrix}
    0\\0\\ \omega_z
    \end{Bmatrix}


The derivation can be extended to :math:`SE(3)` matrices for rigid body transformations:

.. math::
    :label: eq:SE3_matrix

    \underline{a}=\Phi_{ab}\underline{b}=
    \begin{bmatrix}
    R_{ab} & \underline{r}_{ab}\\
    0 & 1
    \end{bmatrix}\underline{b}


and

.. math::
    :label: eq:SE3_velocity_transformation

    \dot{a}=\left[\dot{\Phi}_{ab}\Phi_{ab}^{-1}\right] q_{ab}\underline{b}=
    \begin{bmatrix}
    \dot{R}_{ab} & \dot{\underline{r}}_{ab}\\
    0 & 0
    \end{bmatrix}
    \begin{bmatrix}
    R^T_{ab} & -R^T_{ab}\underline{r}_{ab}\\
    0 & 1
    \end{bmatrix}
    \begin{bmatrix}
    R_{ab} & \underline{r}_{ab}\\
    0 & 1
    \end{bmatrix}\underline{b}


simplifying yields:

.. math::
    :label: eq:spatial_velocity2

    \dot{\Phi}_{ab}\Phi_{ab}^{-1}=
    \begin{bmatrix}
    \dot{R}_{ab}R^T_{ab} & -\dot{R}_{ab}R^T_{ab}
    \underline{r}_{ab}+\dot{\underline{r}}_{ab}\\
    0 & 0
    \end{bmatrix}=
    \begin{bmatrix}
    0 & -\omega_z & \omega_y & v_x\\
    \omega_z & 0 & -\omega_x & v_y\\
    -\omega_y & \omega_x & 0 & v_z\\
    0 & 0 & 0 & 0
    \end{bmatrix}=
    \begin{bmatrix}
    \tilde{\omega} & \underline{v}\\
    0 & 0
    \end{bmatrix}


Which yields a :math:`6\times 1` velocity screw, also known as a *twist*, :math:`\underline{\mathbf{v}}`, where

.. math::
    :label: eq:screw

    \underline{\mathbf{v}}=\begin{Bmatrix}
    v_x\\
    v_y\\
    v_z\\
    \omega_x\\
    \omega_y\\
    \omega_z
    \end{Bmatrix}=
    \begin{Bmatrix}
    \underline{v}\\
    \underline{\omega}
    \end{Bmatrix}


In the language of modern differential geometry, velocity screws are known as the *Lie algebra* of the SE(3) group; their group is designated as :math:`se(3)` :cite:`park1995lie`. The quantity in Eq. :eq:`eq:spatial_velocity` can be expressed in other coordinate systems by a similarity transformation.

.. math::
    :label: eq:similarity_transformation

    \begin{bmatrix}
    \Omega' & \underline{v}' \\
    0 & 0
    \end{bmatrix}=
    \begin{bmatrix}
    R & \underline{r} \\
    0 & 1
    \end{bmatrix}
    \begin{bmatrix}
    \Omega & \underline{v} \\
    0 & 0
    \end{bmatrix}
    \begin{bmatrix}
    R^T & -R^T\underline{r} \\
    0 & 1
    \end{bmatrix}=
    \begin{bmatrix}
    R\Omega R^T & R\underline{v}-R\Omega R^T \underline{r} \\
    0 & 0
    \end{bmatrix}


In computer implementation of the spatial velocity transformation, it is not necessary to perform the entire sequence of :math:`4\times4` matrix operations. Not only can one exploit the matrix sparsity, but it is also possible to take advantage of the following identity to reduce the number of operations required. As the quantity :math:`R\Omega R^T` is skew symmetric, it is only necessary to compute the :math:`\omega'` terms as


.. math::
    :label: eq:identity1

    \omega'_x= (R_{22}R_{33}- R_{23}R_{32})\omega_x + (R_{23}R_{31} - R_{21}R_{32})\omega_y + (R_{21}R_{32} - R_{22}R_{31})\omega_z


.. math::
    :label: eq:identity2

    \omega'_y= (R_{13}R_{32}- R_{12}R_{33})\omega_x + (R_{11}R_{33} - R_{13}R_{31})\omega_y + (R_{12}R_{31} - R_{11}R_{32})\omega_z


.. math::
    :label: eq:identity3

    \omega'_z=(R_{12}R_{23} - R_{13}R_{22})\omega_x + (R_{13}R_{21} - R_{11}R_{23})\omega_y + (R_{12}R_{21} - R_{11}R_{22})\omega_z


R is orthonormal and therefore the second row of R crossed with the third row yields the first row, and the following is true:

.. math::
    :label: eq:identity4

    R_{22}R_{33} - R_{23}R_{32} = R_{11}


.. math::
    :label: eq:identity5

    R_{23}R_{31} - R_{21}R_{32} = R_{12}


.. math::
    :label: eq:identity6

    R_{21}R_{32} - R_{22}R_{31} = R_{13}


and therefore:

.. math::
    :label: eq:identity7

    \omega'_x= R_{11}\omega_x + R_{12}\omega_y + R_{13}\omega_z


.. math::
    :label: eq:identity8

    \omega'_y= R_{21}\omega_x + R_{22}\omega_y + R_{23}\omega_z


.. math::
    :label: eq:identity9

    \omega'_z=R_{31}\omega_x + R_{32}\omega_y + R_{33}\omega_z


.. math::
    :label: eq:identity10

    \underline{\omega}'=R\underline{\omega}


and

.. math::
    :label: eq:identity11

    \begin{bmatrix}
    \Omega' & \underline{v}' \\
    0 & 0
    \end{bmatrix}=
    \begin{bmatrix}
    \widetilde{[R\underline\omega]} & R\underline{v}-\widetilde{[R\underline\omega]} \underline{r}\\
    0 & 0
    \end{bmatrix}=
    \begin{bmatrix}
    \widetilde{[R\underline\omega]} & R\underline{v}+\tilde{r} R\underline\omega\\
    0 & 0
    \end{bmatrix}


Using this information, a :math:`6\times6` adjoint transformation matrix can be generated to transform twists as

.. math::
    :label: eq:adjoint_matrix

    \begin{Bmatrix}
    \underline{v}'\\\underline{\omega}'
    \end{Bmatrix}
    =\begin{bmatrix}
    R & \tilde{r}R\\
    0 & R
    \end{bmatrix}
    \begin{Bmatrix}
    \underline{v}\\ \underline{\omega}
    \end{Bmatrix}=[Ad]\begin{Bmatrix}
    \underline{v}\\ \underline{\omega}
    \end{Bmatrix}


The matrix :math:`[Ad]` forms a :math:`6\times6` screw *basis*. A similar matrix operator for transforming spatial velocities was introduced by Yuan and Freudenstein in 1970 :cite:`yuan1970kinematic`. Some authors put :math:`\underline\omega` above :math:`\underline v` as Yuan did. The form of spatial velocity specified in Eq. :eq:`eq:adjoint_matrix` was chosen in this work as it is the original order specified in Clifford's Algebra :cite:`clifford1882mathematical` and is commonly used in flexible multibody dynamics formulations :cite:`shabana2010computational`.

In the language of differential geometry, :math:`[Ad]` is known as the *adjoint representation* and provides a linear mapping of elements of a Lie algebra.

The :math:`6\times6` screw *basis*, :math:`[Ad]`, provides a convenient and compact notation for transforming screws, and therefore in computer implementation of the transformation, it is tempting to carry out full :math:`6\times6` matrix algebra to transform twists. However, it is strongly emphasized that the full :math:`6\times6` matrix algebra should *never* be carried out in computer code, and additionally that the full :math:`6\times6 [Ad]` adjoint transformation matrix need not be stored or created in computer memory. In the present work, rigid body displacements are stored as a 12x1 array with the entries of a SO(3) rotation matrix stored in column-major order in the first 9 entries of the array, followed by a translation vector in the last 3 entries of the array. When computing :math:`v'` and :math:`\omega'` in Eq. :eq:`eq:adjoint_matrix`, it is only necessary to multiply the non-zero terms of the various quantities as:

.. math::
    :label: eq:twist_end_result

    \begin{Bmatrix}\underline{v}'\\ \underline{\omega}'\end{Bmatrix} =
    \begin{Bmatrix}R\underline{v} +\tilde{r}R\underline{\omega}\\ R\underline{\omega}\end{Bmatrix}


The number of floating point operations required to compute the Eq. :eq:`eq:twist_end_result` are shown below:

.. _table1:

======================================================= ========== ====== =====
Operation                                               Multiplies Adds   Notes
======================================================= ========== ====== =====
:math:`R\underline{\omega}`                             9          6
:math:`\tilde{r}R\underline{\omega}`                    6          3      :math:`R\underline{\omega}` computed above
:math:`R\underline{v}`                                  9          6
:math:`\tilde{r}R{\underline{\omega}} + R\underline{v}` 0          3
------------------------------------------------------- ---------- ------ -----
**total**                                               **24**     **18**
======================================================= ========== ====== =====

On the other hand, carrying out full, dense matrix algebra requires the following operations:


.. _table2:

======================================== ============ ====== ======
Operation                                Multiplies   Adds   Notes
======================================== ============ ====== ======
:math:`\tilde{r}R`                       27           18     Counts refers to the full, dense version.
Full, dense Eq. :eq:`eq:adjoint_matrix`  36           30
---------------------------------------- ------------ ------ ------
**total**                                **63**       **48**
======================================== ============ ====== ======

Carrying out the minimal required operations to transform screw quantities requires 62% fewer operations, 66% less memory and many of the matrix-matrix and matrix-vector operations benefit from vectorization. The above example illustrates that although the notational convention of Lie algebra provides a convenient and compact representation of kinematic and dynamic quantities, care should be taken in the computer implementation of the operations described here. KSL consists of a custom, sparse, vectorized kinematics library consisting of over 200 functions for processing screw quantities and SE(3) displacements that uses the minimal set of operations as described above.


Derivative operator matrices: :math:`[ad]`
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
