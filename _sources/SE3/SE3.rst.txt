.. _SE3:
.. title:: SE3

SE3
===

4x4 matrices matrices are commonly used to describe rigid body displacements :cite:`uicker2013`. In group theory, these 4x4 matrices are identified as the Special Euclidian group, SE(3). Another important group is the Special Orthogonal group, SO(3), the set of 3x3 orthogonal matrices for rigid body rotation. Note that screws can be formalized in terms of group theory and Lie algebra. A detailed discussion of group theory and Lie algebra is beyond the scope of the present work, but some of symbols for groups and operators are used to be consistent with the literature. The interested reader is referred to :cite:`hawkins2012emergence,selig2005geometric` for more information.


.. doxygenunion:: ksl_SE3_t
   :members:
   :undoc-members:
   :outline:
