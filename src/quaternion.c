#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "quaternion.h"
#include "util.h"

/*!
@brief allocate memory for n quaternions and set to identity
*/
ksl_quaternion_t* ksl_quaternion_alloc(const int n) {
  ksl_quaternion_t* q = calloc(n, sizeof(ksl_quaternion_t));
  for(int i = 0; i < n; i++) {
    q[i].w = 1.0;
  }
  return q;
}

/*!
@brief allocate memory for n quaternions and set to identity
*/
ksl_quaternionf_t* ksl_quaternionf_alloc(const int n) {
  ksl_quaternionf_t* q = calloc(n, sizeof(ksl_quaternionf_t));
  for(int i = 0; i < n; i++) {
    q[i].w = 1.0;
  }
  return q;
}

/*!
@brief Return double precision dot product between two double precision
quaternions

Return the dot product between two quaternions.

@param qi and q2i quaternions to form dot product.
*/

inline double ksl_dot_qq(const ksl_quaternion_t* restrict q1i,
                         const ksl_quaternion_t* restrict q2i) {
  register double qdotq = 0.0;
  for(int i = 0; i < 4; i++) {
    qdotq += q1i->at[i] * q2i->at[i];
  }
  return qdotq;
}

/*!
@brief Return float dot product between two float
quaternions

Return the dot product between two quaternions.

@param q1i and q2i quaternions to form dot product.
*/
inline float ksl_dot_qqf(const ksl_quaternionf_t* restrict q1i,
                         const ksl_quaternionf_t* restrict q2i) {
  register float qdotq = 0.0;
  for(int i = 0; i < 4; i++) {
    qdotq += q1i->at[i] * q2i->at[i];
  }
  return qdotq;
}

/*!
@brief Normalize a double precision quaternion

Normalize a quaternion and overwrite.
Add assert(norm) > unit roundoff to avoid division by zero.

@param qi quaternion to normalize.
*/
inline void ksl_normalize(ksl_quaternion_t* restrict qi) {
  register double norm = sqrt(ksl_quaternion_dot_qq(qi, qi));
  for(int i = 0; i < 4; i++) {
    qi->at[i] /= norm;
  }
}

/*!
@brief Normalize float quaternion

Normalize a quaternion and overwrite.
Add assert(norm) > unit roundoff to avoid division by zero.

@param qi euler parameters to normalize
*/
inline void ksl_normalizef(ksl_quaternionf_t* restrict qi) {
  register float norm = sqrt(ksl_dot_qqf(qi, qi));
  for(int i = 0; i < 4; i++) {
    qi->at[i] /= norm;
  }
}

/*!
@brief Multiply double precision quaternion x by double precison scalar a and
add to double precision quaternion y.

Scale quaternion x by a and add to quaternion y

@param y += a*x
*/
inline void ksl_axpy_qq(const double a, const ksl_quaternion_t* restrict x,
                        ksl_quaternion_t* restrict y) {
  for(int i = 0; i < 4; i++) {
    y->at[i] += a * x->at[i];
  }
}

/*!
@brief Multiply float quaternion x by float scalar a and
add to float quaternion y.

Scale quaternion x by a and add to quaternion y

@param y += a*x
*/
inline void ksl_axpy_qqf(const float a, const ksl_quaternionf_t* restrict x,
                         ksl_quaternionf_t* restrict y) {
  for(int i = 0; i < 4; i++) {
    y->at[i] += a * x->at[i];
  }
}

/*!
@todo: add ksl_xpy_qq/qqf, ksl_nxpy_qq/qqf, variants of axpy where a is +/-1
*/

/*!
@brief Double precision function to convert ksl_mat3x3_t rotation matrix to
quaternion representation

\f$R = \begin{bmatrix}
q3q3+q0q0 - q1q1-q2q2 & q0q1+q0q1 - q3q2+q3q2 & q2q0+q2q0 + q3q1+q3q1 \\
q0q1+q0q1 + q3q2+q3q2 & q3q3-q0q0 + q1q1-q2q2 & q1q2+q1q2 - q3q0-q3q0 \\
q2q0+q2q0 - q3q1-q3q1 & q1q2+q1q2 + q3q0+q3q0 & q3q3-q0q0 - q1q1+q2q2 \\
\end{bmatrix}\f$

@todo Supply qr, a reference quaternion. If necessary, flip the sign of
qo so that each qo[i] is the closest match to qr[i]. For this algorithm to
work, qo must be a close follow-on to qr. This function would then prove more
useful when continuous quaternions are desired for interpolation purposes.
Matrix ri is quadratic in qo so qo and -qo give the same ri.

@param ri a rotation matrix in a 9x1 column format
@param qo the resulting euler parameters are stored in the 4x1 array, qo
*/
void ksl_mat3x3_toQuaternion(const ksl_mat3x3_t* restrict ri,
                             ksl_quaternion_t* restrict qo) {

  if(fabs(ri->m00) > 1e-9 || fabs(ri->m11) > 1e-9 || fabs(ri->m22) > 1e-9) {
    double p;
    if((p = ri->m00 + ri->m11 + ri->m22) > 0) {
      // p = 4q3q3-1 > 0 or q3q3 > 1/4 or |q3| > 1/2

      p = sqrt(p + 1); // Now p = 2|q3| > 1

      // If (2|q3| - 2q3) > 1, then p = 2|q3| has the wrong sign.
      // if ( p - qr[3] - qr[3] > 1 ) p = -p; // 2q3
      qo->w = p / 2; // q3
      p = p + p;     // 4q3

      qo->x = (ri->as_array[2 + 1 * 3] - ri->as_array[1 + 2 * 3]) /
              p; // q0 = 4q3q0/4q3
      qo->y = (ri->as_array[0 + 2 * 3] - ri->as_array[2 + 0 * 3]) /
              p; // q1 = 4q3q1/4q3
      qo->z = (ri->as_array[1 + 0 * 3] - ri->as_array[0 + 1 * 3]) /
              p; // q2 = 4q3q2/4q3
    } else if((p = ri->m00 - ri->m11 - ri->m22) > 0) {
      // 4q0q0-1 > 0 or q0q0 > 1/4 or |q0| > 1/2

      p = sqrt(p + 1); // Now p = 2|q0| > 1

      // If (2|q0| - 2q0) > 1, then p = 2|q0| has the wrong sign.
      // if ( p - qr[0] - qr[0] > 1 ) p = -p; // 2q0
      qo->x = p / 2; // q0
      p = p + p;     // 4q0

      qo->w = (ri->as_array[2 + 1 * 3] - ri->as_array[1 + 2 * 3]) /
              p; // q3 = 4q3q0/4q0
      qo->y = (ri->as_array[1 + 0 * 3] + ri->as_array[0 + 1 * 3]) /
              p; // q1 = 4q0q1/4q0
      qo->z = (ri->as_array[2 + 0 * 3] + ri->as_array[0 + 2 * 3]) /
              p; // q2 = 4q2q0/4q0
    } else if((p = ri->m11 - ri->m00 - ri->m22) > 0) {
      // 4q1q1-1 > 0 or q1q1 > 1/4 or |q1| > 1/2

      p = sqrt(p + 1); // Now p = 2|q1| > 1

      // If (2|q1| - 2eq1) > 1, then p = 2|q1| has the wrong sign.
      // if ( p - qr[1] - qr[1] > 1 ) p = -p; // 2q1

      qo->y = p / 2; // q1
      p = p + p;     // 4q1

      qo->w = (ri->as_array[0 + 2 * 3] - ri->as_array[2 + 0 * 3]) /
              p; // q3 = 4q3q1/4q1
      qo->x = (ri->as_array[0 + 1 * 3] + ri->as_array[1 + 0 * 3]) /
              p; // q0 = 4q0q1/4q1
      qo->z = (ri->as_array[1 + 2 * 3] + ri->as_array[2 + 1 * 3]) /
              p; // q2 = 4q1q2/4q1
    } else {
      // 4q2q2-1 > 0 or q2q2 > 1/4 or |q2| > 1/2
      p = ri->m22 - ri->m00 - ri->m11;

      p = sqrt(p + 1); // Now p = 2|q2| > 1

      // If (2|q2| - 2q2) > 1, then p = 2|q2| has the wrong sign.
      // if ( p - qr[2] - qr[2] > 1 ) p = -p; // 2q2

      qo->z = p / 2; // q2
      p = p + p;     // 4q2

      qo->w = (ri->as_array[1 + 0 * 3] - ri->as_array[0 + 1 * 3]) /
              p; // q3 = 4q3q2/4q2
      qo->x = (ri->as_array[0 + 2 * 3] + ri->as_array[2 + 0 * 3]) /
              p; // q0 = 4q2q0/4q2
      qo->y = (ri->as_array[2 + 1 * 3] + ri->as_array[1 + 2 * 3]) /
              p; // q1 = 4q1q2/4q2
    }
  } else {
    qo->w = 0.5;
    qo->x = copysign(0.5, ri->as_array[2 + 1 * 3] - ri->as_array[1 + 2 * 3]);
    qo->y = copysign(0.5, ri->as_array[0 + 2 * 3] - ri->as_array[2 + 0 * 3]);
    qo->z = copysign(0.5, ri->as_array[1 + 0 * 3] - ri->as_array[0 + 1 * 3]);
  }
  return;
}

/*!
@brief single precision function to convert ksl_mat3x3_t rotation matrix to
single precision quaternion representation

\f$R = \begin{bmatrix}
q3q3+q0q0 - q1q1-q2q2 & q0q1+q0q1 - q3q2+q3q2 & q2q0+q2q0 + q3q1+q3q1 \\
q0q1+q0q1 + q3q2+q3q2 & q3q3-q0q0 + q1q1-q2q2 & q1q2+q1q2 - q3q0-q3q0 \\
q2q0+q2q0 - q3q1-q3q1 & q1q2+q1q2 + q3q0+q3q0 & q3q3-q0q0 - q1q1+q2q2 \\
\end{bmatrix}\f$

@todo Supply qr, a reference quaterniohn. If necessary, flip the sign of
qo so that each qo[i] is the closest match to qr[i]. For this algorithm to
work, qo must be a close follow-on to qr. This function would then prove more
useful when continuous quaternions are desired for interpolation purposes.
Matrix ri is quadratic in qo so qo and -qo give the same ri.

@param ri [in] a rotation matrix in a 9x1 column format
@param qo [out] resulting euler parameters
*/
inline void ksl_mat3x3f_toQuaternion(const ksl_mat3x3f_t* restrict ri,
                                     ksl_quaternionf_t* restrict qo) {

  if(fabs(ri->m00) > 1e-9 || fabs(ri->m11) > 1e-9 || fabs(ri->m22) > 1e-9) {
    double p;
    // p = 4q3q3-1 > 0 or q3q3 > 1/4 or |q3| > 1/2
    if((p = ri->m00 + ri->m11 + ri->m22) > 0) {

      p = sqrt(p + 1); // Now p = 2|q3| > 1

      // If (2|q3| - 2q3) > 1, then p = 2|q3| has the wrong sign.
      // if ( p - qr[3] - qr[3] > 1 ) p = -p; // 2q3

      qo->w = p / 2; // q3
      p = p + p;     // 4q3

      qo->x = (ri->as_array[2 + 1 * 3] - ri->as_array[1 + 2 * 3]) /
              p; // q0 = 4q3q0/4q3
      qo->y = (ri->as_array[0 + 2 * 3] - ri->as_array[2 + 0 * 3]) /
              p; // q1 = 4q3q1/4q3
      qo->z = (ri->as_array[1 + 0 * 3] - ri->as_array[0 + 1 * 3]) /
              p; // q2 = 4q3q2/4q3
    } else if((p = ri->m00 - ri->m11 - ri->m22) > 0) {
      // 4q0q0-1 > 0 or q0q0 > 1/4 or |q0| > 1/2

      p = sqrt(p + 1); // Now p = 2|q0| > 1

      // If (2|q0| - 2q0) > 1, then p = 2|q0| has the wrong sign.
      // if ( p - qr[0] - qr[0] > 1 ) p = -p; // 2q0
      qo->x = p / 2; // q0
      p = p + p;     // 4q0
      qo->w = (ri->as_array[2 + 1 * 3] - ri->as_array[1 + 2 * 3]) /
              p; // q3 = 4q3q0/4q0
      qo->y = (ri->as_array[1 + 0 * 3] + ri->as_array[0 + 1 * 3]) /
              p; // q1 = 4q0q1/4q0
      qo->z = (ri->as_array[2 + 0 * 3] + ri->as_array[0 + 2 * 3]) /
              p; // q2 = 4q2q0/4q0
    } else if((p = ri->m11 - ri->m00 - ri->m22) > 0) {
      // 4q1q1-1 > 0 or q1q1 > 1/4 or |q1| > 1/2

      p = sqrt(p + 1); // Now p = 2|q1| > 1

      // If (2|q1| - 2q1) > 1, then p = 2|q1| has the wrong sign.
      // if ( p - qr[1] - qr[1] > 1 ) p = -p; // 2q1

      qo->y = p / 2; // q1
      p = p + p;     // 4q1

      qo->w = (ri->as_array[0 + 2 * 3] - ri->as_array[2 + 0 * 3]) /
              p; // q3 = 4q3q1/4q1
      qo->x = (ri->as_array[0 + 1 * 3] + ri->as_array[1 + 0 * 3]) /
              p; // q0 = 4q0q1/4q1
      qo->z = (ri->as_array[1 + 2 * 3] + ri->as_array[2 + 1 * 3]) /
              p; // q2 = 4q1q2/4q1
    } else {
      // 4q2q2-1 > 0 or q2q2 > 1/4 or |q2| > 1/2
      p = ri->m22 - ri->m00 - ri->m11;

      p = sqrt(p + 1); // Now p = 2|q2| > 1

      // If (2|q2| - 2q2) > 1, then p = 2|q2| has the wrong sign.
      // if ( p - qr[2] - qr[2] > 1 ) p = -p; // 2q2

      qo->z = p / 2; // q2
      p = p + p;     // 4q2

      qo->w = (ri->as_array[1 + 0 * 3] - ri->as_array[0 + 1 * 3]) /
              p; // q3 = 4q3q2/4q2
      qo->x = (ri->as_array[0 + 2 * 3] + ri->as_array[2 + 0 * 3]) /
              p; // q0 = 4q2q0/4q2
      qo->y = (ri->as_array[2 + 1 * 3] + ri->as_array[1 + 2 * 3]) /
              p; // q1 = 4q1q2/4q2
    }
  } else {
    qo->w = 0.5;
    qo->x = copysign(0.5, ri->as_array[2 + 1 * 3] - ri->as_array[1 + 2 * 3]);
    qo->y = copysign(0.5, ri->as_array[0 + 2 * 3] - ri->as_array[2 + 0 * 3]);
    qo->z = copysign(0.5, ri->as_array[1 + 0 * 3] - ri->as_array[0 + 1 * 3]);
  }
  return;
}

/*!
@brief Double precision function to convert quaternion to rotation
matrix representation

The following formula is used to perform conversion:

\f$R = \begin{bmatrix}
q3q3+q0q0 - q1q1-q2q2 & q0q1+q0q1 - q3q2+q3q2 & q2q0+q2q0 + q3q1+q3q1 \\
q0q1+q0q1 + q3q2+q3q2 & q3q3-q0q0 + q1q1-q2q2 & q1q2+q1q2 - q3q0-q3q0 \\
q2q0+q2q0 - q3q1-q3q1 & q1q2+q1q2 + q3q0+q3q0 & q3q3-q0q0 - q1q1+q2q2 \\
\end{bmatrix}\f$

The Quaternion will be normalized during conversion.

@param qi [in] euler parameters to convert in a 4x1 array, in the form [x,y,z,w]
@param ro [out] the resulting rotation matrix is stored in ro
*/
inline void ksl_quaternion_toMat3x3(ksl_quaternion_t* restrict qi,
                                    ksl_mat3x3_t* restrict ro) {

  ksl_normalize(qi);

  double w2 = qi->w * qi->w;
  double x2 = qi->x * qi->x;
  double y2 = qi->y * qi->y;
  double z2 = qi->z * qi->z;

  ro->m00 = (x2 - y2 - z2 + w2);
  ro->m11 = (-x2 + y2 - z2 + w2);
  ro->m22 = (-x2 - y2 + z2 + w2);

  double tmp1 = qi->x * qi->y;
  double tmp2 = qi->z * qi->w;
  ro->m10 = 2.0 * (tmp1 + tmp2);
  ro->m01 = 2.0 * (tmp1 - tmp2);

  tmp1 = qi->x * qi->z;
  tmp2 = qi->y * qi->w;
  ro->m20 = 2.0 * (tmp1 - tmp2);
  ro->m02 = 2.0 * (tmp1 + tmp2);

  tmp1 = qi->y * qi->z;
  tmp2 = qi->x * qi->w;
  ro->m21 = 2.0 * (tmp1 + tmp2);
  ro->m12 = 2.0 * (tmp1 - tmp2);
}

/*!
@brief single precision function to convert Quaternionf to rotation
matrix (ksl_mat3x3f_t) representation

The following formula is used to perform conversion:

\f$R = \begin{bmatrix}
q3q3+q0q0 - q1q1-q2q2 & q0q1+q0q1 - q3q2+q3q2 & q2q0+q2q0 + q3q1+q3q1 \\
q0q1+q0q1 + q3q2+q3q2 & q3q3-q0q0 + q1q1-q2q2 & q1q2+q1q2 - q3q0-q3q0 \\
q2q0+q2q0 - q3q1-q3q1 & q1q2+q1q2 + q3q0+q3q0 & q3q3-q0q0 - q1q1+q2q2 \\
\end{bmatrix}\f$

The Quaternion will be normalized during conversion.

@param qi euler parameters to convert in a 4x1 array, in the form [x,y,z,w]
@param ro the resulting rotation matrix is stored in ro
*/
inline void ksl_quaternionf_toMat3x3f(ksl_quaternionf_t* restrict qi,
                                      ksl_mat3x3f_t* restrict ro) {
  ksl_normalizef(qi);

  float w2 = qi->w * qi->w;
  float x2 = qi->x * qi->x;
  float y2 = qi->y * qi->y;
  float z2 = qi->z * qi->z;

  ro->m00 = (x2 - y2 - z2 + w2);
  ro->m11 = (-x2 + y2 - z2 + w2);
  ro->m22 = (-x2 - y2 + z2 + w2);

  float tmp1 = qi->x * qi->y;
  float tmp2 = qi->z * qi->y;
  ro->m10 = 2.0 * (tmp1 + tmp2);
  ro->m01 = 2.0 * (tmp1 - tmp2);

  tmp1 = qi->x * qi->z;
  tmp2 = qi->y * qi->w;
  ro->m20 = 2.0 * (tmp1 - tmp2);
  ro->m02 = 2.0 * (tmp1 + tmp2);

  tmp1 = qi->y * qi->z;
  tmp2 = qi->x * qi->w;
  ro->m21 = 2.0 * (tmp1 + tmp2);
  ro->m12 = 2.0 * (tmp1 - tmp2);
}

/*!
@brief Double precision version of Shoemake's Spherical
Linear Interpolation algorithm

[Shoemake, Animating rotation with Quaternion Curves, SIGGRAPH, vol 19,
No. 3, 1985] (http://run.usc.edu/cs520-s12/assign2/p245-shoemake.pdf)

@param q1i a first quaternion in the form [x,y,z,w] to interpolate from
@param q2i a second quaternion in the form [x,y,z,w] to interpolate to
@param t fraction from q1i to q2i (0<t<1)
@param qo the resulting quaternion is returned in qo
*/
inline void ksl_slerp(const ksl_quaternion_t* restrict q1i,
                      const ksl_quaternion_t* restrict q2i, double* restrict t,
                      ksl_quaternion_t* restrict qo) {

  double cosHalfTheta = 0.0;
  for(int i = 0; i < 4; i++) {
    cosHalfTheta += q1i->at[i] * q2i->at[i];
  }

  /*
    if q1i=q2i or q1i=-q2i then theta = 0 and we can return q1i
  */
  if(fabs(cosHalfTheta) >= 1.0) {
    memcpy(qo, q1i, sizeof(ksl_quaternion_t));
    return;
  }

  double halfTheta = acos(cosHalfTheta);
  double sinHalfTheta = sqrt(1.0 - cosHalfTheta * cosHalfTheta);

  /* if theta = 180 degrees then result is not defined
    we could rotate around any axis normal to q1i or q2i
  */
  memset(qo, 0, sizeof(ksl_quaternion_t));
  if(fabs(sinHalfTheta) < 0.001) {
    ksl_axpy_qq(0.5, q1i, qo);
    ksl_axpy_qq(0.5, q2i, qo);
    return;
  }
  double ratioA = sin((1 - *t) * halfTheta) / sinHalfTheta;
  double ratioB = sin(*t * halfTheta) / sinHalfTheta;

  /* calculate quaternion. */
  ksl_axpy_qq(ratioA, q1i, qo);
  ksl_axpy_qq(ratioB, q2i, qo);
}

/*!
@brief single precision version of Shoemake's Spherical
Linear Interpolation algorithm

[Shoemake, Animating rotation with Quaternion Curves, SIGGRAPH, vol 19,
No. 3, 1985] (http://run.usc.edu/cs520-s12/assign2/p245-shoemake.pdf)

@param q1i a first quaternion in the form [x,y,z,w] to interpolate from
@param q2i a second quaternion in the form [x,y,z,w] to interpolate to
@param t fraction from q1i to q2i (0<t<1)
@param qo the resulting quaternion is returned in qo
*/
inline void ksl_quaternionf_slerp(const ksl_quaternionf_t* restrict q1i,
                                  const ksl_quaternionf_t* restrict q2i,
                                  float* restrict t,
                                  ksl_quaternionf_t* restrict qo) {

  float cosHalfTheta = 0.0;
  for(int i = 0; i < 4; i++) {
    cosHalfTheta += q1i->at[i] * q2i->at[i];
  }

  /* if q1i=q2i or q1i=-q2i then theta = 0 and we can return q1i */
  if(fabs(cosHalfTheta) >= 1.0) {
    memcpy(qo, q1i, sizeof(ksl_quaternionf_t));
    return;
  }
  float halfTheta = acos(cosHalfTheta);
  float sinHalfTheta = sqrt(1.0 - cosHalfTheta * cosHalfTheta);

  /*
    if theta = 180 degrees then result is not defined
    we could rotate around any axis normal to q1i or q2i
  */
  memset(qo, 0, 4 * sizeof(double));
  if(fabs(sinHalfTheta) < 0.001) { // fabs is floating point absolute
    ksl_axpy_qqf(0.5, q1i, qo);
    ksl_axpy_qqf(0.5, q2i, qo);
    return;
  }
  float ratioA = sin((1 - *t) * halfTheta) / sinHalfTheta;
  float ratioB = sin(*t * halfTheta) / sinHalfTheta;

  /* calculate quaternion. */
  ksl_axpy_qqf(ratioA, q1i, qo);
  ksl_axpy_qqf(ratioB, q2i, qo);
}

/*!
@brief Vectorized version of quaternion Linear Interpolation (Lerp)

Less expensive numerically than Shoemake's Slerp algorithm (ksl_slerp)
but does not interpolate with constant velocity

@param q1i a first quaternion in the form [x,y,z,w] to interpolate from
@param q2i a second quaternion in the form [x,y,z,w] to interpolate to
@param t fraction from q1i to q2i (0<t<1)
@param qo the resulting quaternion is returned in qo
*/
inline void ksl_quaternion_nlerp(const ksl_quaternion_t* restrict q1i,
                                 const ksl_quaternion_t* restrict q2i,
                                 const double* restrict t,
                                 ksl_quaternion_t* restrict qo) {

  if((*t) < 1e-9) {
    memcpy(qo, q1i, sizeof(ksl_quaternion_t));
    return;
  }
  if((*t) >= 1.0) {
    memcpy(qo, q2i, sizeof(ksl_quaternion_t));
    return;
  }
  double alpha = 1.0f - *t;
  double omega = *t;

  double dot = 0.0;
  for(int i = 0; i < 4; i++) {
    dot += q1i->at[i] * q2i->at[i];
  }
  if(dot < 0) {
    omega = -omega;
  }

  memset(qo, 0, sizeof(ksl_quaternion_t));
  ksl_axpy_qq(alpha, q1i, qo);
  ksl_axpy_qq(omega, q2i, qo);

  /* linear interpolation doesn't yield quaternions with unit norm,
  so normalize before returning to user */
  ksl_quaternion_normalize(qo);
}

/*!
@brief Vectorized version of quaternion Linear Interpolation (Lerp)

Less expensive numerically than Shoemake's Slerp algorithm (ksl_Slerp)
but does not interpolate with constant velocity

@param q1i a first quaternion in the form [x,y,z,w] to interpolate from
@param q2i a second quaternion in the form [x,y,z,w] to interpolate to
@param t fraction from q1i to q2i (0<t<1)
@param qo the resulting quaternion is returned in qo
*/
inline void ksl_quaternionf_nlerp(const ksl_quaternionf_t* restrict q1i,
                                  const ksl_quaternionf_t* restrict q2i,
                                  const float* restrict t,
                                  ksl_quaternionf_t* restrict qo) {

  if((*t) < 1e-9) {
    memcpy(qo, q1i, sizeof(ksl_quaternionf_t));
    return;
  }
  if((*t) >= 1.0) {
    memcpy(qo, q2i, sizeof(ksl_quaternionf_t));
    return;
  }
  float alpha = 1.0f - *t;
  float omega = *t;

  float dot = 0.0;
  for(int i = 0; i < 4; i++) {
    dot += q1i->at[i] * q2i->at[i];
  }
  if(dot < 0) {
    omega = -omega;
  }

  memset(qo, 0, sizeof(ksl_quaternionf_t));
  ksl_axpy_qqf(alpha, q1i, qo);
  ksl_axpy_qqf(omega, q2i, qo);

  /* linear interpolation doesn't yield quaternions with unit norm,
  so normalize before returning to user */
  ksl_quaternionf_normalize(qo);
}

/*!
@brief utility to convert dpi, an array of length 3, to deltaq (an incremental
change in quaternion), add incremental change to an input quaternion
q^{ij} += 1/2 * L_c(q^{ij}) d\underline{\pi}_{ij}^j)

       | qw -qz  qy : qx|                    | qw  qz -qy : qx|
L(q) = | qz  qw -qx : qy| = |Lc(q):q| R(q) = |-qz  qw  qx : qy| = |Rc(q):q|
       |-qy  qx  qw : qz|                    | qy -qx  qw : qz|
       |-qx -qy -qz : qw|                    |-qx -qy -qz : qw|

                               | qw -qz  qy| |dpijx|
qij += 1/2*Lc(qij)*dpij += 1/2 | qz  qw -qx| |dpijy|
                               |-qy  qx  qw| |dpijz|
                               |-qx -qy -qz|

*/
inline void kls_add_dpiToq(const ksl_vec3_t* restrict dpi,
                           ksl_quaternion_t* restrict qi) {
  register ksl_quaternion_t dq;
  dq.x = qi->w * dpi->x - qi->z * dpi->y + qi->y * dpi->z;
  dq.y = qi->z * dpi->x + qi->w * dpi->y - qi->x * dpi->z;
  dq.z = -qi->y * dpi->x + qi->x * dpi->y + qi->w * dpi->z;
  dq.w = -qi->x * dpi->x - qi->y * dpi->y - qi->z * dpi->z;
  qi->x += 0.5 * dq.x;
  qi->y += 0.5 * dq.y;
  qi->z += 0.5 * dq.z;
  qi->w += 0.5 * dq.w;
}

/*!
@brief utility to convert dpi, an array of length 3, to deltaq (an incremental
change in quaternion), subtract incremental change from an input quaternion
*/
inline void ksl_subtract_dpiFromq(const ksl_vec3_t* restrict dpi,
                                  ksl_quaternion_t* restrict qi) {

  /*
  q^{ij} -= 1/2 * L_c(q^{ij}) d\underline{\pi}_{ij}^j)

         | qw -qz  qy : qx|                    | qw  qz -qy : qx|
  L(q) = | qz  qw -qx : qy| = |Lc(q):q| R(q) = |-qz  qw  qx : qy| = |Rc(q):q|
         |-qy  qx  qw : qz|                    | qy -qx  qw : qz|
         |-qx -qy -qz : qw|                    |-qx -qy -qz : qw|

                            | qw -qz  qy| |dpijx|
  qij -= 1/2*Lc(qij)*dpij = | qz  qw -qx| |dpijy|
                            |-qy  qx  qw| |dpijz|
                            |-qx -qy -qz|

  */

  /* dq \leftarrow L_c(e^{ij} d\underline{\pi}_{ij}^j) */
  register ksl_quaternion_t dq;
  dq.x = qi->w * dpi->x - qi->z * dpi->y + qi->y * dpi->z;
  dq.y = qi->z * dpi->x + qi->w * dpi->y - qi->x * dpi->z;
  dq.z = -qi->y * dpi->x + qi->x * dpi->y + qi->w * dpi->z;
  dq.w = -qi->x * dpi->x - qi->y * dpi->y - qi->z * dpi->z;

  /* qi -= 1/2 * dq */
  qi->x -= 0.5 * dq.x;
  qi->y -= 0.5 * dq.y;
  qi->z -= 0.5 * dq.z;
  qi->w -= 0.5 * dq.w;
}

/*!
@brief utility to convert angular velocity to time derivative of quaternion

\f$ \underline{\dot{e}}^{ij} \leftarrow 1/2 \mathscr{R}(\underline{e})
\underline{\omega}_{ij}^i\f$

The result is then normalized by adding a feedback term

       | qw -qz  qy : qx|                    | qw  qz -qy : qx|
L(q) = | qz  qw -qx : qy| = |Lc(q):q| R(q) = |-qz  qw  qx : qy| = |Rc(q):q|
       |-qy  qx  qw : qz|                    | qy -qx  qw : qz|
       |-qx -qy -qz : qw|                    |-qx -qy -qz : qw|


\f$ \underline{\dot{e}}^{ij} - \frac{0.5}{\tau}(1 - \underline{e}^{ijT}
\underline{e}^{ij})\underline{e}^{ij} \f$

where \f$\tau=0.5\f$ is hard coded

@param w [in] omega, angular velocity
@param qi [in] reference quaternion
@param dqo [out] output quaternion time derivative
*/
inline void ksl_omega_to_dquaternion(const ksl_vec3_t* restrict w,
                                     const ksl_quaternion_t* restrict qi,
                                     ksl_quaternion_t* restrict dqo) {

  /*
          | qw  qz -qy : qx|
   R(q) = |-qz  qw  qx : qy| = |Rc(q):q|
          | qy -qx  qw : qz|
          |-qx -qy -qz : qw|
    1/2 * [ qi->w  qi->z -qi->y] * {w->x}
          [-qi->z  qi->w  qi->x]   {w->y}
          [ qi->y -qi->x  qi->w]   {w->z}
          [-qi->x -qi->y -qi->z]
  */
  dqo->x = qi->w * w->x + qi->z * w->y - qi->y * w->z;
  dqo->y = -qi->z * w->x + qi->w * w->y + qi->x * w->z;
  dqo->z = qi->y * w->x - qi->x * w->y + qi->w * w->z;
  dqo->w = -qi->x * w->x - qi->y * w->y - qi->z * w->z;

  dqo->x *= 0.5;
  dqo->y *= 0.5;
  dqo->z *= 0.5;
  dqo->w *= 0.5;

  /* add feedback term to normalize quaternion */

  /* if tau is 0.5 */
  double alpha = 1.0 - ksl_dot_qq(qi, qi);

  /*
    if tau is not 0.5

    let coeff = 0.5 / tau
  */
  // double alpha =
  //   coeff * (1 - cblas_ddot(4, (double*)qi, 1, (double*)qi, 1));

  ksl_axpy_qq(alpha, qi, dqo);
}

/*!
@brief Double precision function to multiply double precision quaternion q1i
with double precision quaternion q2i and return results in double precision
quaternion qo.

       | qw -qz  qy  qx|         | qw  qz -qy  qx|
L(q) = | qz  qw -qx  qy|  R(q) = |-qz  qw  qx  qy|
       |-qy  qx  qw  qz|         | qy -qx  qw  qz|
       |-qx -qy -qz  qw|         |-qx -qy -qz  qw|

 @param q1i a first quaternion in the form [x,y,z,w]
 @param q2i a second quaternion in the form [x,y,z,w]
 @param qo the returned quaternion in the form [x,y,z,w]
*/
inline void ksl_product_qq(const ksl_quaternion_t* restrict q1i,
                           const ksl_quaternion_t* restrict q2i,
                           ksl_quaternion_t* restrict qo) {
  /*
                    | q1iw -q1iz  q1iy  q1ix| |q2ix|
  qo = L(q1i)*q2i = | q1iz  q1iw -q1ix  q1iy| |q2iy| = R(q2i)*q1i
                    |-q1iy  q1ix  q1iw  q1iz| |q2iz|
                    |-q1ix -q1iy -q1iz  q1iw| |q2iw|
  */
  qo->x = q1i->w * q2i->x - q1i->z * q2i->y + q1i->y * q2i->z + q1i->x * q2i->w;
  qo->y = q1i->z * q2i->x + q1i->w * q2i->y - q1i->x * q2i->z + q1i->y * q2i->w;
  qo->z =
    -q1i->y * q2i->x + q1i->x * q2i->y + q1i->w * q2i->z + q1i->z * q2i->w;
  qo->w =
    -q1i->x * q2i->x - q1i->y * q2i->y - q1i->z * q2i->z + q1i->w * q2i->w;
}

/*!
@brief Single precision function to multiply single precision quaternion q1i
with single precision quaternion q2i and return results in single precision
quaternion qo.

       | qw -qz  qy  qx|         | qw  qz -qy  qx|
L(q) = | qz  qw -qx  qy|  R(q) = |-qz  qw  qx  qy|
       |-qy  qx  qw  qz|         | qy -qx  qw  qz|
       |-qx -qy -qz  qw|         |-qx -qy -qz  qw|

@param q1i a first quaternion in the form [x,y,z,w]
@param q2i a second quaternion in the form [x,y,z,w]
@param qo the returned quaternion in the form [x,y,z,w]
*/
inline void ksl_product_qqf(const ksl_quaternionf_t* restrict q1i,
                            const ksl_quaternionf_t* restrict q2i,
                            ksl_quaternionf_t* restrict qo) {
  /*
                    | q1iw -q1iz  q1iy  q1ix| |q2ix|
  qo = L(q1i)*q2i = | q1iz  q1iw -q1ix  q1iy| |q2iy| = R(q2i)*q1i
                    |-q1iy  q1ix  q1iw  q1iz| |q2iz|
                    |-q1ix -q1iy -q1iz  q1iw| |q2iw|
  */

  qo->x = q1i->w * q2i->x - q1i->z * q2i->y + q1i->y * q2i->z + q1i->x * q2i->w;
  qo->y = q1i->z * q2i->x + q1i->w * q2i->y - q1i->x * q2i->z + q1i->y * q2i->w;
  qo->z =
    -q1i->y * q2i->x + q1i->x * q2i->y + q1i->w * q2i->z + q1i->z * q2i->w;
  qo->w =
    -q1i->x * q2i->x - q1i->y * q2i->y - q1i->z * q2i->z + q1i->w * q2i->w;
}

/*!
@brief Double precision function to multiply the conjugate of double precision
quaternion q1i with double precision quaternion q2i and return results in double
precision quaternion qo.

       | qw -qz  qy  qx|         | qw  qz -qy  qx|
L(q) = | qz  qw -qx  qy|  R(q) = |-qz  qw  qx  qy|
       |-qy  qx  qw  qz|         | qy -qx  qw  qz|
       |-qx -qy -qz  qw|         |-qx -qy -qz  qw|

@param q1i a first quaternion in the form [x,y,z,w]
@param q2i a second quaternion in the form [x,y,z,w]
@param qo the returned quaternion in the form [x,y,z,w]
*/
inline void ksl_product_qconjq(const ksl_quaternion_t* restrict q1i,
                               const ksl_quaternion_t* restrict q2i,
                               ksl_quaternion_t* restrict qo) {
  /*
                      | q1iw  q1iz -q1iy -q1ix| |q2ix|
  qo = L(q1i)^T*q2i = |-q1iz  q1iw  q1ix -q1iy| |q2iy|
                      | q1iy -q1ix  q1iw -q1iz| |q2iz|
                      | q1ix  q1iy  q1iz  q1iw| |q2iw|
  */

  qo->x = q1i->w * q2i->x + q1i->z * q2i->y - q1i->y * q2i->z - q1i->x * q2i->w;
  qo->y =
    -q1i->z * q2i->x + q1i->w * q2i->y + q1i->x * q2i->z - q1i->y * q2i->w;
  qo->z = q1i->y * q2i->x - q1i->x * q2i->y + q1i->w * q2i->z - q1i->z * q2i->w;
  qo->w = q1i->x * q2i->x + q1i->y * q2i->y + q1i->z * q2i->z + q1i->w * q2i->w;
}

/*!
@brief Single precision function to multiply the conjugate of single precision
quaternion q1i with single precision quaternion q2i and return results in single
precision quaternion qo.

       | qw -qz  qy  qx|         | qw  qz -qy  qx|
L(q) = | qz  qw -qx  qy|  R(q) = |-qz  qw  qx  qy|
       |-qy  qx  qw  qz|         | qy -qx  qw  qz|
       |-qx -qy -qz  qw|         |-qx -qy -qz  qw|

@param q1i a first quaternion in the form [x,y,z,w]
@param q2i a second quaternion in the form [x,y,z,w]
@param qo the returned quaternion in the form [x,y,z,w]
*/
inline void ksl_product_qconjqf(const ksl_quaternionf_t* restrict q1i,
                                const ksl_quaternionf_t* restrict q2i,
                                ksl_quaternionf_t* restrict qo) {
  /*
                      | q1iw  q1iz -q1iy -q1ix| |q2ix|
  qo = L(q1i)^T*q2i = |-q1iz  q1iw  q1ix -q1iy| |q2iy|
                      | q1iy -q1ix  q1iw -q1iz| |q2iz|
                      | q1ix  q1iy  q1iz  q1iw| |q2iw|
  */

  qo->x = q1i->w * q2i->x + q1i->z * q2i->y - q1i->y * q2i->z - q1i->x * q2i->w;
  qo->y =
    -q1i->z * q2i->x + q1i->w * q2i->y + q1i->x * q2i->z - q1i->y * q2i->w;
  qo->z = q1i->y * q2i->x - q1i->x * q2i->y + q1i->w * q2i->z - q1i->z * q2i->w;
  qo->w = q1i->x * q2i->x + q1i->y * q2i->y + q1i->z * q2i->z + q1i->w * q2i->w;
}

/*!
@brief Double precision function to multiply double precision quaternion q1i
with the conjugate of double precision quaternion q2i and return results in
double precision quaternion qo.

       | qw -qz  qy  qx|         | qw  qz -qy  qx|
L(q) = | qz  qw -qx  qy|  R(q) = |-qz  qw  qx  qy|
       |-qy  qx  qw  qz|         | qy -qx  qw  qz|
       |-qx -qy -qz  qw|         |-qx -qy -qz  qw|

@param q1i a first quaternion in the form [x,y,z,w]
@param q2i a second quaternion in the form [x,y,z,w]
@param qo the returned quaternion in the form [x,y,z,w]
*/
inline void ksl_product_qqconj(const ksl_quaternion_t* restrict q1i,
                               const ksl_quaternion_t* restrict q2i,
                               ksl_quaternion_t* restrict qo) {
  /*
                      | q2iw -q2iz  q2iy -q2ix| |q1ix|
  qo = R(q2i)^T*q1i = | q2iz  q2iw -q2ix -q2iy| |q1iy|
                      |-q2iy  q2ix  q2iw -q2iz| |q1iz|
                      | q2ix  q2iy  q2iz  q2iw| |q1iw|
  */

  qo->x = q2i->w * q1i->x - q2i->z * q1i->y + q2i->y * q1i->z - q2i->x * q1i->w;
  qo->y = q2i->z * q1i->x + q2i->w * q1i->y - q2i->x * q1i->z - q2i->y * q1i->w;
  qo->z =
    -q2i->y * q1i->x + q2i->x * q1i->y + q2i->w * q1i->z - q2i->z * q1i->w;
  qo->w = q2i->x * q1i->x + q2i->y * q1i->y + q2i->z * q1i->z + q2i->w * q1i->w;
}

/*!
@brief Single precision function to multiply single precision quaternion q1i
with the conjugate of single precision quaternion q2i and return results in
single precision quaternion qo.

       | qw -qz  qy  qx|         | qw  qz -qy  qx|
L(q) = | qz  qw -qx  qy|  R(q) = |-qz  qw  qx  qy|
       |-qy  qx  qw  qz|         | qy -qx  qw  qz|
       |-qx -qy -qz  qw|         |-qx -qy -qz  qw|

@param q1i a first quaternion in the form [x,y,z,w]
@param q2i a second quaternion in the form [x,y,z,w]
@param qo the returned quaternion in the form [x,y,z,w]
*/
inline void ksl_product_qqconjf(const ksl_quaternionf_t* restrict q1i,
                                const ksl_quaternionf_t* restrict q2i,
                                ksl_quaternionf_t* restrict qo) {
  /*
                      | q2iw -q2iz  q2iy -q2ix| |q1ix|
  qo = R(q2i)^T*q1i = | q2iz  q2iw -q2ix -q2iy| |q1iy|
                      |-q2iy  q2ix  q2iw -q2iz| |q1iz|
                      | q2ix  q2iy  q2iz  q2iw| |q1iw|
  */

  qo->x = q2i->w * q1i->x - q2i->z * q1i->y + q2i->y * q1i->z - q2i->x * q1i->w;
  qo->y = q2i->z * q1i->x + q2i->w * q1i->y - q2i->x * q1i->z - q2i->y * q1i->w;
  qo->z =
    -q2i->y * q1i->x + q2i->x * q1i->y + q2i->w * q1i->z - q2i->z * q1i->w;
  qo->w = q2i->x * q1i->x + q2i->y * q1i->y + q2i->z * q1i->z + q2i->w * q1i->w;
}

/*!
@brief Double precision function to multiply the conjugate of double precision
quaternion q1i with the conjugate of double precision quaternion q2i and return
results in double precision quaternion qo.

       | qw -qz  qy  qx|         | qw  qz -qy  qx|
L(q) = | qz  qw -qx  qy|  R(q) = |-qz  qw  qx  qy|
       |-qy  qx  qw  qz|         | qy -qx  qw  qz|
       |-qx -qy -qz  qw|         |-qx -qy -qz  qw|

@param q1i a first quaternion in the form [x,y,z,w]
@param q2i a second quaternion in the form [x,y,z,w]
@param qo the returned quaternion in the form [x,y,z,w]
*/
void ksl_product_qconjqconj(const ksl_quaternion_t* restrict q1i,
                            const ksl_quaternion_t* restrict q2i,
                            ksl_quaternion_t* restrict qo) {
  /*
                          | q1iw  q1iz -q1iy -q1ix| | q2ix|
  qo = L(q1i)^T*q2iconj = |-q1iz  q1iw  q1ix -q1iy| |-q2iy|
                          | q1iy -q1ix  q1iw -q1iz| |-q2iz|
                          | q1ix  q1iy  q1iz  q1iw| |-q2iw|

                          | q1iw -q1iz  q1iy  q1ix| |q2ix|
                        = |-q1iz -q1iw -q1ix  q1iy| |q2iy|
                          | q1iy  q1ix -q1iw  q1iz| |q2iz|
                          | q1ix -q1iy -q1iz -q1iw| |q2iw|
  */
  qo->x = q1i->w * q2i->x - q1i->z * q2i->y + q1i->y * q2i->z + q1i->x * q2i->w;
  qo->y =
    -q1i->z * q2i->x - q1i->w * q2i->y - q1i->x * q2i->z + q1i->y * q2i->w;
  qo->z = q1i->y * q2i->x + q1i->x * q2i->y - q1i->w * q2i->z + q1i->z * q2i->w;
  qo->w = q1i->x * q2i->x - q1i->y * q2i->y - q1i->z * q2i->z - q1i->w * q2i->w;
}

/*!
@brief Single precision function to multiply the conjugate of single precision
quaternion q1i with the conjugate of single precision quaternion q2i and return
results in single precision quaternion qo.

       | qw -qz  qy  qx|         | qw  qz -qy  qx|
L(q) = | qz  qw -qx  qy|  R(q) = |-qz  qw  qx  qy|
       |-qy  qx  qw  qz|         | qy -qx  qw  qz|
       |-qx -qy -qz  qw|         |-qx -qy -qz  qw|

@param q1i a first quaternion in the form [x,y,z,w]
@param q2i a second quaternion in the form [x,y,z,w]
@param qo the returned quaternion in the form [x,y,z,w]
*/
void ksl_product_qconjqconjf(const ksl_quaternionf_t* restrict q1i,
                             const ksl_quaternionf_t* restrict q2i,
                             ksl_quaternionf_t* restrict qo) {
  /*
                          | q1iw  q1iz -q1iy -q1ix| | q2ix|
  qo = L(q1i)^T*q2iconj = |-q1iz  q1iw  q1ix -q1iy| |-q2iy|
                          | q1iy -q1ix  q1iw -q1iz| |-q2iz|
                          | q1ix  q1iy  q1iz  q1iw| |-q2iw|

                          | q1iw -q1iz  q1iy  q1ix| |q2ix|
                        = |-q1iz -q1iw -q1ix  q1iy| |q2iy|
                          | q1iy  q1ix -q1iw  q1iz| |q2iz|
                          | q1ix -q1iy -q1iz -q1iw| |q2iw|
  */
  qo->x = q1i->w * q2i->x - q1i->z * q2i->y + q1i->y * q2i->z + q1i->x * q2i->w;
  qo->y =
    -q1i->z * q2i->x - q1i->w * q2i->y - q1i->x * q2i->z + q1i->y * q2i->w;
  qo->z = q1i->y * q2i->x + q1i->x * q2i->y - q1i->w * q2i->z + q1i->z * q2i->w;
  qo->w = q1i->x * q2i->x - q1i->y * q2i->y - q1i->z * q2i->z - q1i->w * q2i->w;
}

/*!
@brief Double precision function to multiply double precision quaternion dci
with double precision quaternion qi and return results in double precision
quaternion qo.

       | qw  qz -qy  qx|
R(q) = |-qz  qw  qx  qy|
       | qy -qx  qw  qz|
       |-qx -qy -qz  qw|

@param dci[2] a quaternion in the form [w,x,0,0]
@param qi a quaternion in the form [x,y,z,w]
@param qo the returned quaternion in the form [x,y,z,w]
*/
void ksl_product_qxq(const double dci[2], const ksl_quaternion_t* restrict qi,
                     ksl_quaternion_t* restrict qo) {
  /*
       | qiw  qiz -qiy  qix| |dci[1]|
  qo = |-qiz  qiw  qix  qiy| |  0   |
       | qiy -qix  qiw  qiz| |  0   |
       |-qix -qiy -qiz  qiw| |dci[0]|
  */
  qo->x = qi->x * dci[0] + qi->w * dci[1];
  qo->y = qi->y * dci[0] - qi->z * dci[1];
  qo->z = qi->z * dci[0] + qi->y * dci[1];
  qo->w = qi->w * dci[0] - qi->x * dci[1];
}

/*!
@brief Single precision function to multiply single precision quaternion dci
with single precision quaternion qi and return results in single precision
quaternion qo.

         | dci[0]    0       0     dci[1]|
L(dci) = |   0     dci[0] -dci[1]    0   |
         |   0     dci[1]  dci[0]    0   |
         |-dci[1]    0       0     dci[0]|

 @param dci[2] a quaternion in the form [w,x,0,0]
 @param qi a quaternion in the form [x,y,z,w]
 @param qo the returned quaternion in the form [x,y,z,w]
*/
void ksl_product_qxqf(const float dci[2], const ksl_quaternionf_t* restrict qi,
                      ksl_quaternionf_t* restrict qo) {
  /*
                 | dci[0]    0       0     dci[1]| |qix|
qo = L(dci) qi = |   0     dci[0] -dci[1]    0   | |qiy|
                 |   0     dci[1]  dci[0]    0   | |qiz|
                 |-dci[1]    0       0     dci[0]| |qiw|
  */
  qo->x = dci[0] * qi->x + dci[1] * qi->w;
  qo->y = dci[0] * qi->y - dci[1] * qi->z;
  qo->z = dci[0] * qi->z + dci[1] * qi->y;
  qo->w = dci[0] * qi->w - dci[1] * qi->x;
}

void ksl_product_qqx(const ksl_quaternion_t* restrict qi, const double dci[2],
                     ksl_quaternion_t* restrict qo) {
  //
}

void ksl_product_qqxf(const ksl_quaternionf_t* restrict qi, const float dci[2],
                      ksl_quaternionf_t* restrict qo) {
  //
}

void ksl_product_qxconjq(const double dci[2],
                         const ksl_quaternion_t* restrict qi,
                         ksl_quaternion_t* restrict qo) {
  //
}

void ksl_product_qxconjqf(const float dci[2],
                          const ksl_quaternionf_t* restrict qi,
                          ksl_quaternionf_t* restrict qo) {
  //
}

void ksl_product_qconjqx(const ksl_quaternion_t* restrict qi,
                         const double dci[2], ksl_quaternion_t* restrict qo) {
  //
}

void ksl_product_qconjqxf(const ksl_quaternionf_t* restrict qi,
                          const float dci[2], ksl_quaternionf_t* restrict qo) {
  //
}

void ksl_product_qxqconj(const double dci[2],
                         const ksl_quaternion_t* restrict qi,
                         ksl_quaternion_t* restrict qo) {
  //
}

void ksl_product_qxqconjf(const float dci[2],
                          const ksl_quaternionf_t* restrict qi,
                          ksl_quaternionf_t* restrict qo) {
  //
}

void ksl_product_qqxconj(const ksl_quaternion_t* restrict qi,
                         const double dci[2], ksl_quaternion_t* restrict qo) {
  //
}

void ksl_product_qqxconjf(const ksl_quaternionf_t* restrict qi,
                          const float dci[2], ksl_quaternionf_t* restrict qo) {
  //
}

void ksl_product_qxconjqconj(const double dci[2],
                             const ksl_quaternion_t* restrict qi,
                             ksl_quaternion_t* restrict qo) {
  //
}

void ksl_product_qxconjqconjf(const float dci[2],
                              const ksl_quaternionf_t* restrict qi,
                              ksl_quaternionf_t* restrict qo) {
  //
}

void ksl_product_qconjqxconj(const ksl_quaternion_t* restrict qi,
                             const double dci[2],
                             ksl_quaternion_t* restrict qo) {
  //
}

void ksl_product_qconjqxconjf(const ksl_quaternionf_t* restrict qi,
                              const float dci[2],
                              ksl_quaternionf_t* restrict qo) {
  //
}

void ksl_product_qyq(const double dci[2], const ksl_quaternion_t* restrict qi,
                     ksl_quaternion_t* restrict qo) {
  //
}

void ksl_product_qyqf(const float dci[2], const ksl_quaternionf_t* restrict qi,
                      ksl_quaternionf_t* restrict qo) {
  //
}

void ksl_product_qqy(const ksl_quaternion_t* restrict qi, const double dci[2],
                     ksl_quaternion_t* restrict qo) {
  //
}

void ksl_product_qqyf(const ksl_quaternionf_t* restrict qi, const float dci[2],
                      ksl_quaternionf_t* restrict qo) {
  //
}

void ksl_product_qyconjq(const double dci[2],
                         const ksl_quaternion_t* restrict qi,
                         ksl_quaternion_t* restrict qo) {
  //
}

void ksl_product_qyconjqf(const float dci[2],
                          const ksl_quaternionf_t* restrict qi,
                          ksl_quaternionf_t* restrict qo) {
  //
}

void ksl_product_qconjqy(const ksl_quaternion_t* restrict qi,
                         const double dci[2], ksl_quaternion_t* restrict qo) {
  //
}

void ksl_product_qconjqyf(const ksl_quaternionf_t* restrict qi,
                          const float dci[2], ksl_quaternionf_t* restrict qo) {
  //
}

void ksl_product_qyqconj(const double dci[2],
                         const ksl_quaternion_t* restrict qi,
                         ksl_quaternion_t* restrict qo) {
  //
}

void ksl_product_qyqconjf(const float dci[2],
                          const ksl_quaternionf_t* restrict qi,
                          ksl_quaternionf_t* restrict qo) {
  //
}

void ksl_product_qqyconj(const ksl_quaternion_t* restrict qi,
                         const double dci[2], ksl_quaternion_t* restrict qo) {
  //
}

void ksl_product_qqyconjf(const ksl_quaternionf_t* restrict qi,
                          const float dci[2], ksl_quaternionf_t* restrict qo) {
  //
}

void ksl_product_qyconjqconj(const double dci[2],
                             const ksl_quaternion_t* restrict qi,
                             ksl_quaternion_t* restrict qo) {
  //
}

void ksl_product_qyconjqconjf(const float dci[2],
                              const ksl_quaternionf_t* restrict qi,
                              ksl_quaternionf_t* restrict qo) {
  //
}

void ksl_product_qconjqyconj(const ksl_quaternion_t* restrict qi,
                             const double dci[2],
                             ksl_quaternion_t* restrict qo) {
  //
}

void ksl_product_qconjqyconjf(const ksl_quaternionf_t* restrict qi,
                              const float dci[2],
                              ksl_quaternionf_t* restrict qo) {
  //
}

void ksl_product_qzq(const double dci[2], const ksl_quaternion_t* restrict qi,
                     ksl_quaternion_t* restrict qo) {
  //
}

void ksl_product_qzqf(const float dci[2], const ksl_quaternionf_t* restrict qi,
                      ksl_quaternionf_t* restrict qo) {
  //
}

void ksl_product_qqz(const ksl_quaternion_t* restrict qi, const double dci[2],
                     ksl_quaternion_t* restrict qo) {
  //
}

void ksl_product_qqzf(const ksl_quaternionf_t* restrict qi, const float dci[2],
                      ksl_quaternionf_t* restrict qo) {
  //
}

void ksl_product_qzconjq(const double dci[2],
                         const ksl_quaternion_t* restrict qi,
                         ksl_quaternion_t* restrict qo) {
  //
}

void ksl_product_qzconjqf(const float dci[2],
                          const ksl_quaternionf_t* restrict qi,
                          ksl_quaternionf_t* restrict qo) {
  //
}

void ksl_product_qconjqz(const ksl_quaternion_t* restrict qi,
                         const double dci[2], ksl_quaternion_t* restrict qo) {
  //
}

void ksl_product_qconjqzf(const ksl_quaternionf_t* restrict qi,
                          const float dci[2], ksl_quaternionf_t* restrict qo) {
  //
}

void ksl_product_qzqconj(const double dci[2],
                         const ksl_quaternion_t* restrict qi,
                         ksl_quaternion_t* restrict qo) {
  //
}

void ksl_product_qzqconjf(const float dci[2],
                          const ksl_quaternionf_t* restrict qi,
                          ksl_quaternionf_t* restrict qo) {
  //
}

void ksl_product_qqzconj(const ksl_quaternion_t* restrict qi,
                         const double dci[2], ksl_quaternion_t* restrict qo) {
  //
}

void ksl_product_qqzconjf(const ksl_quaternionf_t* restrict qi,
                          const float dci[2], ksl_quaternionf_t* restrict qo) {
  //
}

void ksl_product_qzconjqconj(const double dci[2],
                             const ksl_quaternion_t* restrict qi,
                             ksl_quaternion_t* restrict qo) {
  //
}

void ksl_product_qzconjqconjf(const float dci[2],
                              const ksl_quaternionf_t* restrict qi,
                              ksl_quaternionf_t* restrict qo) {
  //
}

void ksl_product_qconjqzconj(const ksl_quaternion_t* restrict qi,
                             const double dci[2],
                             ksl_quaternion_t* restrict qo) {
  //
}

void ksl_product_qconjqzconjf(const ksl_quaternionf_t* restrict qi,
                              const float dci[2],
                              ksl_quaternionf_t* restrict qo) {
  //
}

/*!
@brief Double precision function to multiply double precision quaternion qi
with double precision vector vi and return results in double precision
quaternion qo.

       | qw -qz  qy  qx|         | qw  qz -qy  qx|
L(q) = | qz  qw -qx  qy|  R(q) = |-qz  qw  qx  qy|
       |-qy  qx  qw  qz|         | qy -qx  qw  qz|
       |-qx -qy -qz  qw|         |-qx -qy -qz  qw|

 @param qi a quaternion in the form [x,y,z,w]
 @param vi a vector in the form [x,y,z]
 @param qo the returned quaternion in the form [x,y,z,w]
*/

void ksl_product_qv(const ksl_quaternion_t* restrict qi,
                    const ksl_vec3_t* restrict vi,
                    ksl_quaternion_t* restrict qo) {
  /*
                  | qiw -qiz  qiy  qix| |vix|
  qo = L(qi)*vi = | qiz  qiw -qix  qiy| |viy|
                  |-qiy  qix  qiw  qiz| |viz|
                  |-qix -qiy -qiz  qiw| | 0 |
*/

  qo->x = qi->w * vi->x - qi->z * vi->y + qi->y * vi->z;
  qo->y = qi->z * vi->x + qi->w * vi->y - qi->x * vi->z;
  qo->z = -qi->y * vi->x + qi->x * vi->y + qi->w * vi->z;
  qo->w = -qi->x * vi->x - qi->y * vi->y - qi->z * vi->z;
}

/*!
@brief Single precision function to multiply single precision quaternion qi
with single precision quaternion q2i and return results in single precision
quaternion qo.

       | qw -qz  qy  qx|         | qw  qz -qy  qx|
L(q) = | qz  qw -qx  qy|  R(q) = |-qz  qw  qx  qy|
       |-qy  qx  qw  qz|         | qy -qx  qw  qz|
       |-qx -qy -qz  qw|         |-qx -qy -qz  qw|

@param qi a quaternion in the form [x,y,z,w]
@param vi a vector in the form [x,y,z]
@param qo the returned quaternion in the form [x,y,z,w]
*/
void ksl_product_qvf(const ksl_quaternionf_t* restrict qi,
                     const ksl_vec3f_t* restrict vi,
                     ksl_quaternionf_t* restrict qo) {
  /*
                  | qiw -qiz  qiy  qix| |vix|
  qo = L(qi)*vi = | qiz  qiw -qix  qiy| |viy|
                  |-qiy  qix  qiw  qiz| |viz|
                  |-qix -qiy -qiz  qiw| | 0 |
*/

  qo->x = qi->w * vi->x - qi->z * vi->y + qi->y * vi->z;
  qo->y = qi->z * vi->x + qi->w * vi->y - qi->x * vi->z;
  qo->z = -qi->y * vi->x + qi->x * vi->y + qi->w * vi->z;
  qo->w = -qi->x * vi->x - qi->y * vi->y - qi->z * vi->z;
}

/*!
@brief Double precision function to multiply conjugate of double precision
quaternion qi with double precision vector vi and return results in double
precision quaternion qo.

       | qw -qz  qy  qx|         | qw  qz -qy  qx|
L(q) = | qz  qw -qx  qy|  R(q) = |-qz  qw  qx  qy|
       |-qy  qx  qw  qz|         | qy -qx  qw  qz|
       |-qx -qy -qz  qw|         |-qx -qy -qz  qw|

 @param qi a quaternion in the form [x,y,z,w]
 @param vi a vector in the form [x,y,z]
 @param qo the returned quaternion in the form [x,y,z,w]
*/

void ksl_product_qconjv(const ksl_quaternion_t* restrict qi,
                        const ksl_vec3_t* restrict vi,
                        ksl_quaternion_t* restrict qo) {
  /*
                    | qiw  qiz -qiy -qix| |vix|
  qo = L(qi)^T*vi = |-qiz  qiw  qix -qiy| |viy|
                    | qiy -qix  qiw -qiz| |viz|
                    | qix  qiy  qiz  qiw| | 0 |
  */

  qo->x = qi->w * vi->x + qi->z * vi->y - qi->y * vi->z;
  qo->y = -qi->z * vi->x + qi->w * vi->y + qi->x * vi->z;
  qo->z = qi->y * vi->x - qi->x * vi->y + qi->w * vi->z;
  qo->w = qi->x * vi->x + qi->y * vi->y + qi->z * vi->z;
}

/*!
@brief Single precision function to multiply conjugate of single precision
quaternion qi with single precision quaternion q2i and return results in single
precision quaternion qo.

       | qw -qz  qy  qx|         | qw  qz -qy  qx|
L(q) = | qz  qw -qx  qy|  R(q) = |-qz  qw  qx  qy|
       |-qy  qx  qw  qz|         | qy -qx  qw  qz|
       |-qx -qy -qz  qw|         |-qx -qy -qz  qw|

@param qi a quaternion in the form [x,y,z,w]
@param vi a vector in the form [x,y,z]
@param qo the returned quaternion in the form [x,y,z,w]
*/
void ksl_product_qconjvf(const ksl_quaternionf_t* restrict qi,
                         const ksl_vec3f_t* restrict vi,
                         ksl_quaternionf_t* restrict qo) {
  /*
                  | qiw  qiz -qiy -qix| |vix|
  qo = L(qi)*vi = |-qiz  qiw  qix -qiy| |viy|
                  | qiy -qix  qiw -qiz| |viz|
                  | qix  qiy  qiz  qiw| | 0 |
  */

  qo->x = qi->w * vi->x - qi->z * vi->y + qi->y * vi->z;
  qo->y = qi->z * vi->x + qi->w * vi->y - qi->x * vi->z;
  qo->z = -qi->y * vi->x + qi->x * vi->y + qi->w * vi->z;
  qo->w = -qi->x * vi->x - qi->y * vi->y - qi->z * vi->z;
}

/*!
@brief Double precision function to multiply double precision vector vi
with double precision quaternion qi and return results in double precision
quaternion qo.

       | qw -qz  qy  qx|         | qw  qz -qy  qx|
L(q) = | qz  qw -qx  qy|  R(q) = |-qz  qw  qx  qy|
       |-qy  qx  qw  qz|         | qy -qx  qw  qz|
       |-qx -qy -qz  qw|         |-qx -qy -qz  qw|

@param vi a vector in the form [x,y,z]
@param qi a quaternion in the form [x,y,z,w]
@param qo the returned quaternion in the form [x,y,z,w]
*/
void ksl_product_vq(const ksl_vec3_t* restrict vi,
                    const ksl_quaternion_t* restrict qi,
                    ksl_quaternion_t* restrict qo) {
  /*
                 | qiw  qiz -qiy  qix| |vix|
  qo =R(qi)*vi = |-qiz  qiw  qix  qiy| |viy|
                 | qiy -qix  qiw  qiz| |viz|
                 |-qix -qiy -qiz  qiw| | 0 |
  */
  qo->x = qi->w * vi->x + qi->z * vi->y - qi->y * vi->z;
  qo->y = -qi->z * vi->x + qi->w * vi->y + qi->x * vi->z;
  qo->z = qi->y * vi->x - qi->x * vi->y + qi->w * vi->z;
  qo->w = -qi->x * vi->x - qi->y * vi->y - qi->z * vi->z;
}

/*!
@brief Single precision function to multiply single precision vector vi
with single precision quaternion qi and return results in single precision
quaternion qo.

       | qw -qz  qy  qx|         | qw  qz -qy  qx|
L(q) = | qz  qw -qx  qy|  R(q) = |-qz  qw  qx  qy|
       |-qy  qx  qw  qz|         | qy -qx  qw  qz|
       |-qx -qy -qz  qw|         |-qx -qy -qz  qw|

@param vi a vector in the form [x,y,z]
@param qi a quaternion in the form [x,y,z,w]
@param qo the returned quaternion in the form [x,y,z,w]
*/
void ksl_product_vqf(const ksl_vec3f_t* restrict vi,
                     const ksl_quaternionf_t* restrict qi,
                     ksl_quaternionf_t* restrict qo) {
  /*
                 | qiw  qiz -qiy  qix| |vix|
  qo =R(qi)*vi = |-qiz  qiw  qix  qiy| |viy|
                 | qiy -qix  qiw  qiz| |viz|
                 |-qix -qiy -qiz  qiw| | 0 |
  */
  qo->x = qi->w * vi->x + qi->z * vi->y - qi->y * vi->z;
  qo->y = -qi->z * vi->x + qi->w * vi->y + qi->x * vi->z;
  qo->z = qi->y * vi->x - qi->x * vi->y + qi->w * vi->z;
  qo->w = -qi->x * vi->x - qi->y * vi->y - qi->z * vi->z;
}

/*!
@brief Double precision function to multiply double precision vector vi
with double precision conjugate quaternion qi and return results in double
precision quaternion qo.

       | qw -qz  qy  qx|         | qw  qz -qy  qx|
L(q) = | qz  qw -qx  qy|  R(q) = |-qz  qw  qx  qy|
       |-qy  qx  qw  qz|         | qy -qx  qw  qz|
       |-qx -qy -qz  qw|         |-qx -qy -qz  qw|

@param vi a vector in the form [x,y,z]
@param qi a quaternion in the form [x,y,z,w]
@param qo the returned quaternion in the form [x,y,z,w]
*/
void ksl_product_vqconj(const ksl_vec3_t* restrict vi,
                        const ksl_quaternion_t* restrict qi,
                        ksl_quaternion_t* restrict qo) {
  /*
                    | qiw -qiz  qiy -qix| |vix|
  qo = R(qi)^T*vi = | qiz  qiw -qix -qiy| |viy|
                    |-qiy  qix  qiw -qiz| |viz|
                    | qix  qiy  qiz  qiw| | 0 |
  */

  qo->x = qi->w * vi->x - qi->z * vi->y + qi->y * vi->z;
  qo->y = qi->z * vi->x + qi->w * vi->y - qi->x * vi->z;
  qo->z = -qi->y * vi->x + qi->x * vi->y + qi->w * vi->z;
  qo->w = qi->x * vi->x + qi->y * vi->y + qi->z * vi->z;
}

/*!
@brief Single precision function to multiply single precision vector vi
with single precision conjugate quaternion qi and return results in single
precision quaternion qo.

       | qw -qz  qy  qx|         | qw  qz -qy  qx|
L(q) = | qz  qw -qx  qy|  R(q) = |-qz  qw  qx  qy|
       |-qy  qx  qw  qz|         | qy -qx  qw  qz|
       |-qx -qy -qz  qw|         |-qx -qy -qz  qw|

@param vi a vector in the form [x,y,z]
@param qi a quaternion in the form [x,y,z,w]
@param qo the returned quaternion in the form [x,y,z,w]
*/
void ksl_product_vqconjf(const ksl_vec3f_t* restrict vi,
                         const ksl_quaternionf_t* restrict qi,
                         ksl_quaternionf_t* restrict qo) {
  /*
                    | qiw -qiz  qiy -qix| |vix|
  qo = R(qi)^T*vi = | qiz  qiw -qix -qiy| |viy|
                    |-qiy  qix  qiw -qiz| |viz|
                    | qix  qiy  qiz  qiw| | 0 |
  */

  qo->x = qi->w * vi->x - qi->z * vi->y + qi->y * vi->z;
  qo->y = qi->z * vi->x + qi->w * vi->y - qi->x * vi->z;
  qo->z = -qi->y * vi->x + qi->x * vi->y + qi->w * vi->z;
  qo->w = qi->x * vi->x + qi->y * vi->y + qi->z * vi->z;
}
