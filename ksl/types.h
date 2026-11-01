/**
@file
@author Kristopher Wehage, Roger Wehage
@brief KSL datastructures
@copyright Kristopher Wehage 2018-2026
*/
#ifndef _KSL_TYPES_H_
#define _KSL_TYPES_H_

/*!
@brief Expands to the C99 restrict qualifier, or to __restrict when compiled
as C++, which has no restrict keyword.
*/
#ifdef __cplusplus
#define KSL_RESTRICT __restrict
#else
#define KSL_RESTRICT restrict
#endif

/*!
@brief 3 dimensional double precision vector
*/
typedef union ksl_vec3_t {
  struct {
    double at[3];
  }; /*!< anonymous union allows accessing vector quantities at specified index
      */
  struct {
    double x;
    double y;
    double z;
  }; /*!< anonymous union allows accessing vector quantities by descriptive name
      */
} ksl_vec3_t;

/*!
@brief 3 dimensional single precision vector
*/
typedef union ksl_vec3f_t {
  struct {
    float at[3];
  }; /*!< anonymous union allows accessing vector quantities at specified index
      */
  struct {
    float x;
    float y;
    float z;
  }; /*!< anonymous union allows accessing vector quantities by descriptive name
      */
} ksl_vec3f_t;

/*!
@brief 3 dimensional integer vector
*/
typedef union ksl_vec3i_t {
  struct {
    int at[3];
  }; /*!< anonymous union allows accessing vector quantities at specified index
      */
  struct {
    int x;
    int y;
    int z;
  }; /*!< anonymous union allows accessing vector quantities by descriptive name
      */
} ksl_vec3i_t;

/*!
@brief double precision 4x1 vector representing a 3x1 vector
with a homogeneous coordinate (w) appended.

Typically used for nonlinear transformations such as camera projections.
*/
typedef union ksl_vec4_t {
  struct {
    double at[4];
  }; /*!< anonymous union allows accessing vector quantities at specified index
      */
  struct {
    union {
      struct {
        ksl_vec3_t r;
      }; /*!< anonymous union allows accessing 3d vector component of 4d vector
          */
      struct {
        double x;
        double y;
        double z;
      }; /*!< anonymous union allows x, y, z vector component of 4d vector by
            descriptive name*/
    };
    double w; /*!< homogeneous coordinate of 4d vector */
  }; /*!< anonymous union allows x, y, z, w vector components of 4d vector by
        descriptive name or 3d vector component */
} ksl_vec4_t;

/*!
@brief single precision 4x1 vector representing a 3x1 vector
with a homogeneous coordinate (w) appended.

Typically used for nonlinear transformations such as camera projections.
*/
typedef union ksl_vec4f_t {
  struct {
    float at[4];
  }; /*!< anonymous union allows accessing vector quantities at specified index
      */
  struct {
    union {
      struct {
        ksl_vec3f_t r;
      }; /*!< anonymous union allows accessing 3d vector component of 4d vector
          */
      struct {
        float x;
        float y;
        float z;
      }; /*!< anonymous union allows x, y, z vector component of 4d vector by
           descriptive name*/
    };
    float w; /*!< homogeneous coordinate of 4d vector */
  }; /*!< anonymous union allows x, y, z, w vector components of 4d vector by
        descriptive name or 3d vector component */
} ksl_vec4f_t;

/*!
@brief A 4 element integer vector.
*/
typedef union ksl_vec4i_t {
  struct {
    int at[4];
  }; /*!< anonymous union allows accessing vector quantities at specified index
      */
  struct {
    union {
      struct {
        ksl_vec3i_t r;
      }; /*!< anonymous union allows accessing 3d vector component of 4d vector
          */
      struct {
        int x;
        int y;
        int z;
      }; /*!< anonymous union allows x, y, z vector component of 4d vector by
           descriptive name*/
    };
    int w; /*!< homogeneous coordinate of 4d vector */
  }; /*!< anonymous union allows x, y, z, w vector components of 4d vector by
        descriptive name or 3d vector component */
} ksl_vec4i_t;

/*! @brief A general 3x3 double precision matrix

This union allows accessing double precision mat3x3 quantities by field name, as
a singly dimensioned array, as a doubly dimensioned array, or by accessing a
specific column.  If using the `at` or `as_array` operators, quantities are
accessed in column major order.

The following examples illustrate how to access row 2, column 1 (using 0 based
indexing) of matrix `R`. The following access methods are equivalent.

\verbatim embed:rst
.. code-block:: c

  R.as_array[2 + 1 * 3];
  R.at[1][2];
  R.m21;
  R.v1.z;
  R.v1.at[2];
  R.v[1].z;
  R.v[1].at[2];

\endverbatim

See also the `ksl_mat3x3_get` and `ksl_mat3x3_set` functions. */
typedef union ksl_mat3x3_t {
  struct {
    double as_array[9];
  }; /*!< anonymous union allows accessing quantities at specified index in
          linear array, where entities are specified in column
          major order */
  struct {
    double at[3][3];
  }; /*!< anonymous union allows accessing quantities at specified index
        in a doubly dimensioned array, where entities are specified in column
        major order */
  struct {
    double m00, m10, m20;
    double m01, m11, m21;
    double m02, m12, m22;
  }; /*!< anonymous union allows accessing rotation matrix quantities by field
        name */
  struct {
    ksl_vec3_t v0, v1, v2;
  }; /*!< anonymous union allows accessing columns of rotation matrix quantities
        by field name */
  struct {
    ksl_vec3_t v[3];
  }; /*!< anonymous union allows accessing columns of rotation
          matrix quantities at specified index */
} ksl_mat3x3_t;

/*!
@brief A general 3x3 single precision matrix.

This union allows accessing single precision mat3x3 quantities by field name, as
a singly dimensioned array, as a doubly dimensioned array, or by accessing a
specific column.  If using the `at` or `as_array` operators, quantities are
accessed in column major order.

The following examples illustrate how to access row 2, column 1 (using 0 based
indexing) of matrix `R`. The following access methods are equivalent.

\verbatim embed:rst
.. code-block:: c

  R.as_array[2 + 1 * 3];
  R.at[1][2];
  R.m21;
  R.v1.z;
  R.v1.at[2];
  R.v[1].z;
  R.v[1].at[2];

\endverbatim

See also the `ksl_mat3x3f_get` and `ksl_mat3x3f_set` functions.
*/
typedef union ksl_mat3x3f_t {
  struct {
    float as_array[9];
  }; /*!< anonymous union allows accessing quantities at specified index in
                           linear array, where entities are specified in column
                           major order */
  struct {
    float at[3][3];
  }; /*!< anonymous union allows accessing mat3x3 quantities at specified index
       in a doubly dimensioned array, where entities are specified in column
       major order */
  struct {
    float m00, m10, m20;
    float m01, m11, m21;
    float m02, m12, m22;
  }; /*!< anonymous union allows accessing rotation matrix quantities by field
        name */
  struct {
    ksl_vec3f_t v0, v1, v2;
  }; /*!< anonymous union allows accessing columns of rotation matrix quantities
        by field name */
  struct {
    ksl_vec3f_t v[3];
  }; /*!< anonymous union allows accessing columns of rotation by index
          matrix quantities at specified index */
} ksl_mat3x3f_t;

/*! @brief A general double precision 4x4 matrix.

This union allows accessing double precision mat4x4 quantities by field name, as
a singly dimensioned array, as a doubly dimensioned array, or by accessing a
specific column.  If using the `at` or `as_array` operators, quantities are
accessed in column major order.

The following examples illustrate how to access row 3, column 2 (using 0 based
indexing) of matrix `M`. The following access methods are equivalent.

\verbatim embed:rst
.. code-block:: c

  M.as_array[3 + 2 * 4];
  M.at[2][3];
  M.m32;
  M.v2.w;
  M.v2.at[3];
  M.v[2].w;
  M.v[2].at[3];

\endverbatim


See also the `ksl_mat4x4_get` and `ksl_mat4x4_set` functions.

*/
typedef union ksl_mat4x4_t {
  struct {
    double as_array[16];
  }; /*!< anonymous union allows accessing quantities at specified index in
          linear array, where entities are specified in column
          major order */
  struct {
    double at[4][4];
  }; /*!< anonymous union allows accessing mat3x3 quantities at specified index
        in a doubly dimensioned array, where entities are specified in column
        major order */
  struct {
    double m00, m10, m20, m30;
    double m01, m11, m21, m31;
    double m02, m12, m22, m32;
    double m03, m13, m23, m33;
  }; /*!< anonymous union allows accessing rotation matrix quantities by field
        name */
  struct {
    ksl_vec4_t v0, v1, v2, v3;
  }; /*!< anonymous union allows accessing columns of rotation matrix quantities
        by field name */
  struct {
    ksl_vec4_t v[4];
  }; /*!< anonymous union allows accessing columns of rotation
          matrix quantities at specified index */
} ksl_mat4x4_t;

/*!
@brief A general single precision 4x4 matrix.

This union allows accessing single precision mat4x4 quantities by field name, as
a singly dimensioned array, as a doubly dimensioned array, or by accessing a
specific column.  If using the `at` or `as_array` operators, quantities are
accessed in column major order.

The following examples illustrate how to access row 3, column 2 (using 0 based
indexing) of matrix `M`. The following access methods are equivalent.

\verbatim embed:rst
.. code-block:: c

  M.as_array[3 + 2 * 4];
  M.at[2][3];
  M.m32;
  M.v2.w;
  M.v2.at[3];
  M.v[2].w;
  M.v[2].at[3];

\endverbatim

See also the `ksl_mat4x4f_get` and `ksl_mat4x4f_set` functions.
*/
typedef union ksl_mat4x4f_t {
  struct {
    float as_array[16];
  }; /*!< allows accessing quantities at specified index in
          linear array, where entities are specified in column
          major order */
  struct {
    float at[4][4];
  }; /*!< allows accessing mat3x3 quantities at specified index in
          a doubly dimensioned array, where entities are specified
          in column major order */
  struct {
    float m00, m10, m20, m30;
    float m01, m11, m21, m31;
    float m02, m12, m22, m32;
    float m03, m13, m23, m33;
  }; /*!< anonymous union allows accessing rotation matrix quantities by field
        name */
  struct {
    ksl_vec4f_t v0, v1, v2, v3;
  }; /*!< anonymous union allows accessing columns of rotation matrix quantities
        by field name */
  struct {
    ksl_vec4f_t v[4];
  }; /*!< anonymous union allows accessing columns of rotation
          matrix quantities at specified index */
} ksl_mat4x4f_t;

/*!
@brief Double precision member of 3 Dimensional Special Euclidian group (SE3)
consisting of a double precision SO3 (othonormalized 3x3 rotation matrix) and
double precision translation vector pair.

This union allows accessing double precision SE3 quantities by field name, as
a singly dimensioned array, as a doubly dimensioned array, or by accessing a
specific column.  If using the `at` or `as_array` operators, quantities are
accessed in column major order.

The following examples illustrate how to access row 2, column 1 (using 0 based
indexing) of SE3 matrix `D`. The following access methods are equivalent.

\verbatim embed:rst
.. code-block:: c

  D.as_array[2 + 1 * 3];
  D.at[1][2];
  D.m21;
  D.v1.z;
  D.v1.at[2];
  D.v[1].z;
  D.v[1].at[2];
  D.R.m21;
  D.R.v1.z;
  D.R.v1.at[2];
  D.R.v[1].z;
  D.R.v[1].at[2];

\endverbatim

The following examples illustrate how to access row 1, column 3 (using 0 based
indexing) of SE3 matrix `D`. The following access methods are equivalent.

\verbatim embed:rst
.. code-block:: c

  D.as_array[1 + 3 * 3];
  D.at[3][1];
  D.m13;
  D.v3.y;
  D.v3.at[1];
  D.v[3].y;
  D.v[3].at[1];
  D.t.y;
  D.t.at[1];

\endverbatim

See also the `ksl_SE3_get` and `ksl_SE3_set` functions.
*/
typedef union ksl_SE3_t {
  struct {
    double as_array[12];
  }; /*!< anonymous union allows accessing quantities at specified index in
          linear array, where entities are specified in column
          major order */
  struct {
    double at[4][3];
  }; /*!< anonymous union allows accessing SE3 quantities at specified index in
          a doubly dimensioned array, where entities are specified
          in column major order */
  struct {
    ksl_mat3x3_t R; /*!< rotation component of SE3 transformation */
    ksl_vec3_t t;   /*!< translation component of SE3 transformation */
  }; /*!< anonymous union allows accessing rotation matrix and translation
       vector quantities by field name */
  struct {
    double m00, m10, m20;
    double m01, m11, m21;
    double m02, m12, m22;
    double m03, m13, m23;
  }; /*!< anonymous union allows accessing rotation matrix quantities by field
       name */
  struct {
    ksl_vec3_t v0, v1, v2, v3;
  }; /*!< anonymous union allows accessing columns of rotation matrix quantities
        by field name */
  struct {
    ksl_vec3_t v[4];
  }; /*!< anonymous union allows accessing columns of rotation
          matrix quantities at specified index */
} ksl_SE3_t;

/*!
@brief Single precision member of 3 Dimensional Special Euclidian group (SE3)
consisting of a single precision SO3 (othonormalized 3x3 rotation matrix) and
single precision translation vector pair.

This union allows accessing single precision SE3 quantities by field name, as
a singly dimensioned array, as a doubly dimensioned array, or by accessing a
specific column.  If using the `at` or `as_array` operators, quantities are
accessed in column major order.

The following examples illustrate how to access row 2, column 1 (using 0 based
indexing) of SE3 matrix `D`. The following access methods are equivalent.

\verbatim embed:rst
.. code-block:: c

  D.as_array[2 + 1 * 3];
  D.at[1][2];
  D.m21;
  D.v1.z;
  D.v1.at[2];
  D.v[1].z;
  D.v[1].at[2];
  D.R.m21;
  D.R.v1.z;
  D.R.v1.at[2];
  D.R.v[1].z;
  D.R.v[1].at[2];

\endverbatim

The following examples illustrate how to access row 1, column 3 (using 0 based
indexing) of SE3 matrix `D`. The following access methods are equivalent.

\verbatim embed:rst
.. code-block:: c

  D.as_array[1 + 3 * 3];
  D.at[3][1];
  D.m13;
  D.v3.y;
  D.v3.at[1];
  D.v[3].y;
  D.v[3].at[1];
  D.t.y;
  D.t.at[1];

\endverbatim

See also the `ksl_SE3f_get` and `ksl_SE3f_set` functions.
*/
typedef union ksl_SE3f_t {
  struct {
    float as_array[12];
  }; /*!< anonymous union allows accessing quantities at specified index in
          linear array, with entities specified in column major order */
  struct {
    float at[4][3];
  }; /*!< anonymous union allows accessing SE3 quantities at specified index in
          a doubly dimensioned array, with entities specified
          in column major order */
  struct {
    ksl_mat3x3f_t R; /*!< rotation component of SE3 transformation */
    ksl_vec3f_t t;   /*!< translation component of SE3 transformation */
  }; /*!< anonymous union allows accessing rotation matrix and translation
       vector quantities by field name */
  struct {
    float m00, m10, m20;
    float m01, m11, m21;
    float m02, m12, m22;
    float m03, m13, m23;
  }; /*!< anonymous union allows accessing rotation matrix quantities by field
       name */
  struct {
    ksl_vec3f_t v0, v1, v2, v3;
  }; /*!< anonymous union allows accessing columns of rotation matrix quantities
        by field name */
  struct {
    ksl_vec3f_t v[4];
  }; /*!< anonymous union allows accessing columns of rotation
      matrix quantities at specified index */
} ksl_SE3f_t;

/*!
@brief double precision screw consisting of a linear and angular vector pair in
configuration space
*/
typedef union ksl_screw_t {
  struct {
    double at[6];
  }; /*!< anonymous union allows accessing screw quantities at specified index
      */
  struct {
    ksl_vec3_t lin; /*!< free linear vector, e.g. linear velocity or
                            acceleration */
    ksl_vec3_t ang; /*!< bound angular vector, e.g. angular velocity or
                             angular acceleration */
  }; /*!< anonymous union allows accessing screw quantities by linear or angular
        vector components */
  struct {
    double m0, m1, m2, m3, m4, m5;
  }; /*!< anonymous union allows accessing screw quantities by field name  */
} ksl_screw_t;

/*!
@brief single precision screw consisting of a linear and angular vector
pair in configuration space
*/
typedef union ksl_screwf_t {
  struct {
    float at[6]; /*!< allows accessing screw quantities at specified index */
  }; /*!< anonymous union allows accessing screw quantities at specified index
      */
  struct {
    ksl_vec3f_t lin; /*!< free linear vector, e.g. linear velocity or
                            acceleration */
    ksl_vec3f_t ang; /*!< bound angular vector, e.g. angular velocity or
                             angular acceleration */
  }; /*!< anonymous union allows accessing screw quantities by linear or angular
        vector components */
  struct {
    float m0, m1, m2, m3, m4, m5;
  }; /*!< anonymous union allows accessing screw quantities by field name */
} ksl_screwf_t;

/*!
@brief double precision coscrew (i.e. a linear operator on a screw), consisting
of a linear and angular vector pair in function space.
*/
typedef union ksl_coscrew_t {
  struct {
    double at[6];
  }; /*!< anyonymous union allows accessing coscrew quantities at specified
        index */
  struct {
    ksl_vec3_t lin; /*!< bound linear vector, e.g. force or linear
                         momentum */
    ksl_vec3_t ang; /*!< free angular vector, e.g. moment/torque
                         or angular momentum*/
  }; /*!< anyonymous union allows accessing coscrew quantities by its linear and
        angular vector components */
  struct {
    double m0, m1, m2, m3, m4, m5;
  }; /*!< anonymous union allows accessing coscrew quantities by field name */
} ksl_coscrew_t;

/*!
@brief single precision coscrew (i.e. a linear operator on a screw), consisting
of a linear and angular vector pair in function space.
*/
typedef union ksl_coscrewf_t {
  struct {
    float at[6];
  }; /*!< anonymous union allows accessing coscrew quantities at specified index
      */
  struct {
    ksl_vec3f_t lin; /*!< bound linear vector, e.g. force or linear
                         momentum */
    ksl_vec3f_t ang; /*!< free angular vector, e.g. moment/torque
                         or angular momentum*/
  }; /*!< anyonymous union allows accessing coscrew quantities by its linear and
        angular vector components */
  struct {
    float m0, m1, m2, m3, m4, m5;
  }; /*!< anonymous union allows accessing coscrew quantities by field name */
} ksl_coscrewf_t;

/*!
@brief double precision quaternion data structure
*/
typedef union ksl_quaternion_t {
  double at[4];
  struct {
    union {
      ksl_vec3_t r;
      struct {
        double x;
        double y;
        double z;
      };
    };
    double w;
  };
} ksl_quaternion_t;

/*!
@brief single precision quaternion data structure
*/
typedef union ksl_quaternionf_t {
  float at[4];
  struct {
    union {
      ksl_vec3f_t r;
      struct {
        float x;
        float y;
        float z;
      };
    };
    float w;
  };
} ksl_quaternionf_t;

/*!
@brief double precision mass and inertia properties
*/
typedef union ksl_inertia_t {
  struct {
    double at[10];
  }; /*!< anonymous union allows accessing by index */
  struct {
    double m;      /*!< mass */
    ksl_vec3_t mt; /*!< mass times a vector, t, from reference
                        frame to body centroid */
    double Ixx;    /*!< Ixx centroidal inertia term, expressed in reference
                        frame coordinates */
    double Iyy;    /*!< Ixy centroidal inertia term, expressed in reference
                        frame coordinates */
    double Izz;    /*!< Izz centroidal inertia term, expressed in reference
                        frame coordinates */
    double Ixy;    /*!< Ixy centroidal inertia term, expressed in reference
                        frame coordinates */
    double Iyz;    /*!< Iyz centroidal inertia term, expressed in reference
                        frame coordinates */
    double Izx;    /*!< Izx centroidal inertia term, expressed in reference
                        frame coordinates */
  }; /*!< anonymous union allows accessing by field names */
  struct {
    double mass;   /*!< mass */
    ksl_vec3_t mr; /*!< mass times a vector, r, from reference
                        frame to body centroid */
    double _Ixx;   /*!< Ixx centroidal inertia term, expressed in reference
                       frame coordinates */
    double _Iyy;   /*!< Ixy centroidal inertia term, expressed in reference
                       frame coordinates */
    double _Izz;   /*!< Izz centroidal inertia term, expressed in reference
                       frame coordinates */
    double Iyx;    /*!< Ixy centroidal inertia term, expressed in reference
                        frame coordinates */
    double Izy;    /*!< Iyz centroidal inertia term, expressed in reference
                        frame coordinates */
    double Ixz;    /*!< Izx centroidal inertia term, expressed in reference
                        frame coordinates */
  }; /*!< anonymous union allows accessing by alternative field names
      */
} ksl_inertia_t;

/*!
@brief single precision mass and inertia properties
*/
typedef union ksl_inertiaf_t {
  struct {
    float at[10];
  }; /*!< anonymous union allows accessing by index */
  struct {
    float m;        /*!< mass */
    ksl_vec3f_t mt; /*!< mass times a vector, t, from reference
                        frame to body centroid */
    float Ixx;      /*!< Ixx centroidal inertia term, expressed in reference
                         frame coordinates */
    float Iyy;      /*!< Ixy centroidal inertia term, expressed in reference
                         frame coordinates */
    float Izz;      /*!< Izz centroidal inertia term, expressed in reference
                         frame coordinates */
    float Ixy;      /*!< Ixy centroidal inertia term, expressed in reference
                         frame coordinates */
    float Iyz;      /*!< Iyz centroidal inertia term, expressed in reference
                         frame coordinates */
    float Izx;      /*!< Izx centroidal inertia term, expressed in reference
                         frame coordinates */
  }; /*!< anonymous union allows accessing inertial quantities by field name */
  struct {
    float mass;     /*!< mass */
    ksl_vec3f_t mr; /*!< mass times a vector, r, from reference
                        frame to body centroid */
    float _Ixx;     /*!< Ixx centroidal inertia term, expressed in reference
                         frame coordinates */
    float _Iyy;     /*!< Ixy centroidal inertia term, expressed in reference
                         frame coordinates */
    float _Izz;     /*!< Izz centroidal inertia term, expressed in reference
                         frame coordinates */
    float Iyx;      /*!< Ixy centroidal inertia term, expressed in reference
                          frame coordinates */
    float Izy;      /*!< Iyz centroidal inertia term, expressed in reference
                          frame coordinates */
    float Ixz;      /*!< Izx centroidal inertia term, expressed in reference
                          frame coordinates */
  }; /*!< anonymous union allows accessing inertial quantities by alternative
        field name */
} ksl_inertiaf_t;

#endif
