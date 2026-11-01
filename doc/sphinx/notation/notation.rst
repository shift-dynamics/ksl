.. _notation:
.. title:: Notation

Notation
--------

Conventions
***********

===================================== =============================== =========================
example                               description                     reserved for
===================================== =============================== =========================
:math:`A`                             capital symbols                 Matrices
:math:`a`                             lowercase symbols               Scalar quantities
:math:`\underline{a}`                 underlined symbols              Vector quantities, or a column matrix of stacked vector quantities
:math:`\dot{v}`                       overhead dot                    First time derivative
:math:`\ddot{v}`                      overhead double dot             Second time derivative
:math:`\begin{bmatrix} \end{bmatrix}` square brackets                 :math:`m \times n` matrices where :math:`m` and :math:`n` are typically greater than 1
:math:`\begin{Bmatrix} \end{Bmatrix}` *curly* brackets or braces      :math:`m \times 1` column matrix
:math:`\mathbf{\underline{v}}`        bold face/underlined            :math:`6 \times 1` *screw* quantities, such as velocities and accelerations
:math:`\mathbf{\underline{f}}^*`      bold face, underlined, asterisk :math:`6 \times 1` *coscrew* quantities, such as forces.
===================================== =============================== =========================

Transformations
***************

========================== =============================================================================== ======
symbol                     operation                                                                       description
========================== =============================================================================== ======
:math:`R`                                                                                                  :math:`R \in \mathbb{R}^{3x3}`, an SO(3) rotation matrix
:math:`R^{-1}`             :math:`R^T`
:math:`\underline{r}`                                                                                      :math:`r \in \mathbb{R}^{3}`, a translation vector
:math:`\underline{r}^{-1}` :math:`- \underline{r}`
:math:`\tilde{r}`          :math:`\begin{bmatrix}0&-r_z&r_y&\\r_z&0&-r_x\\-r_y&r_x&0\end{bmatrix}`         :math:`\tilde{r} \in \mathbb{R}^{3x3}`, a skew-symmetric matrix
:math:`\Phi`                  :math:`\begin{bmatrix}R&\underline{r}\\0 & 1\end{bmatrix}`                      :math:`\Phi(R,r) \in SE(3)`, a general rigid body displacement consisting of rotation (:math:`R`) and translation (:math:`r`).
:math:`\Phi^{-1}`             :math:`\begin{bmatrix}R^T&-R^T\underline{r}\\0&1\end{bmatrix}`
:math:`[Ad]`               :math:`\begin{bmatrix}R & \tilde{r}R\\0&R\end{bmatrix}`                         adjoint operator for transforming screws
:math:`[Ad]^{-1}`          :math:`\begin{bmatrix}R^T&-R^T\tilde{r}\\0&R^T\end{bmatrix}`                         inverse of adjoint operator for transforming screws
:math:`[Ad]^*`             :math:`\begin{bmatrix}R & 0\\\tilde{r}R&R\end{bmatrix}`                         coadjoint operator for transforming coscrews
:math:`[ad]`               :math:`\begin{bmatrix}\tilde{\omega}&\tilde{v}\\0&\tilde{\omega}\end{bmatrix}`  time derivative of :math:`[Ad]`
:math:`[ad]^*`             :math:`\begin{bmatrix}\tilde{\omega}&0\\\tilde{v}&\tilde{\omega}\end{bmatrix}`  time derivative of :math:`[Ad]^*`
========================== =============================================================================== ======
