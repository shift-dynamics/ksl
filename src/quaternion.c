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

@param qi1 and qi2 quaternions to form dot product.
*/

inline double ksl_quaternion_dot_qq(const ksl_quaternion_t* restrict qi1,
                                    const ksl_quaternion_t* restrict qi2) {
  register double qdotq = 0.0;
  for(int i = 0; i < 4; i++) {
    qdotq += qi1->at[i] * qi2->at[i];
  }
  return qdotq;
}

/*!
@brief Return float dot product between two float
quaternions

Return the dot product between two quaternions.

@param qi1 and qi2 quaternions to form dot product.
*/
inline float ksl_quaternionf_dot_qq(const ksl_quaternionf_t* restrict qi1,
                                    const ksl_quaternionf_t* restrict qi2) {
  register float qdotq = 0.0;
  for(int i = 0; i < 4; i++) {
    qdotq += qi1->at[i] * qi2->at[i];
  }
  return qdotq;
}

/*!
@brief Normalize a double precision quaternion

Normalize a quaternion and overwrite.
Add assert(norm) > unit roundoff to avoid division by zero.

@param qi quaternion to normalize.
*/
inline void ksl_quaternion_normalize(ksl_quaternion_t* restrict qi) {
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
inline void ksl_quaternionf_normalize(ksl_quaternionf_t* restrict qi) {
  register float norm = sqrt(ksl_quaternionf_dot_qq(qi, qi));
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

      qo->x = (ri->at[2 + 1 * 3] - ri->at[1 + 2 * 3]) / p; // q0 = 4q3q0/4q3
      qo->y = (ri->at[0 + 2 * 3] - ri->at[2 + 0 * 3]) / p; // q1 = 4q3q1/4q3
      qo->z = (ri->at[1 + 0 * 3] - ri->at[0 + 1 * 3]) / p; // q2 = 4q3q2/4q3
    } else if((p = ri->m00 - ri->m11 - ri->m22) > 0) {
      // 4q0q0-1 > 0 or q0q0 > 1/4 or |q0| > 1/2

      p = sqrt(p + 1); // Now p = 2|q0| > 1

      // If (2|q0| - 2q0) > 1, then p = 2|q0| has the wrong sign.
      // if ( p - qr[0] - qr[0] > 1 ) p = -p; // 2q0
      qo->x = p / 2; // q0
      p = p + p;     // 4q0

      qo->w = (ri->at[2 + 1 * 3] - ri->at[1 + 2 * 3]) / p; // q3 = 4q3q0/4q0
      qo->y = (ri->at[1 + 0 * 3] + ri->at[0 + 1 * 3]) / p; // q1 = 4q0q1/4q0
      qo->z = (ri->at[2 + 0 * 3] + ri->at[0 + 2 * 3]) / p; // q2 = 4q2q0/4q0
    } else if((p = ri->m11 - ri->m00 - ri->m22) > 0) {
      // 4q1q1-1 > 0 or q1q1 > 1/4 or |q1| > 1/2

      p = sqrt(p + 1); // Now p = 2|q1| > 1

      // If (2|q1| - 2eq1) > 1, then p = 2|q1| has the wrong sign.
      // if ( p - qr[1] - qr[1] > 1 ) p = -p; // 2q1

      qo->y = p / 2; // q1
      p = p + p;     // 4q1

      qo->w = (ri->at[0 + 2 * 3] - ri->at[2 + 0 * 3]) / p; // q3 = 4q3q1/4q1
      qo->x = (ri->at[0 + 1 * 3] + ri->at[1 + 0 * 3]) / p; // q0 = 4q0q1/4q1
      qo->z = (ri->at[1 + 2 * 3] + ri->at[2 + 1 * 3]) / p; // q2 = 4q1q2/4q1
    } else {
      // 4q2q2-1 > 0 or q2q2 > 1/4 or |q2| > 1/2
      p = ri->m22 - ri->m00 - ri->m11;

      p = sqrt(p + 1); // Now p = 2|q2| > 1

      // If (2|q2| - 2q2) > 1, then p = 2|q2| has the wrong sign.
      // if ( p - qr[2] - qr[2] > 1 ) p = -p; // 2q2

      qo->z = p / 2; // q2
      p = p + p;     // 4q2

      qo->w = (ri->at[1 + 0 * 3] - ri->at[0 + 1 * 3]) / p; // q3 = 4q3q2/4q2
      qo->x = (ri->at[0 + 2 * 3] + ri->at[2 + 0 * 3]) / p; // q0 = 4q2q0/4q2
      qo->y = (ri->at[2 + 1 * 3] + ri->at[1 + 2 * 3]) / p; // q1 = 4q1q2/4q2
    }
  } else {
    qo->w = 0.5;
    qo->x = copysign(0.5, ri->at[2 + 1 * 3] - ri->at[1 + 2 * 3]);
    qo->y = copysign(0.5, ri->at[0 + 2 * 3] - ri->at[2 + 0 * 3]);
    qo->z = copysign(0.5, ri->at[1 + 0 * 3] - ri->at[0 + 1 * 3]);
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

      qo->x = (ri->at[2 + 1 * 3] - ri->at[1 + 2 * 3]) / p; // q0 = 4q3q0/4q3
      qo->y = (ri->at[0 + 2 * 3] - ri->at[2 + 0 * 3]) / p; // q1 = 4q3q1/4q3
      qo->z = (ri->at[1 + 0 * 3] - ri->at[0 + 1 * 3]) / p; // q2 = 4q3q2/4q3
    } else if((p = ri->m00 - ri->m11 - ri->m22) > 0) {
      // 4q0q0-1 > 0 or q0q0 > 1/4 or |q0| > 1/2

      p = sqrt(p + 1); // Now p = 2|q0| > 1

      // If (2|q0| - 2q0) > 1, then p = 2|q0| has the wrong sign.
      // if ( p - qr[0] - qr[0] > 1 ) p = -p; // 2q0
      qo->x = p / 2;                                       // q0
      p = p + p;                                           // 4q0
      qo->w = (ri->at[2 + 1 * 3] - ri->at[1 + 2 * 3]) / p; // q3 = 4q3q0/4q0
      qo->y = (ri->at[1 + 0 * 3] + ri->at[0 + 1 * 3]) / p; // q1 = 4q0q1/4q0
      qo->z = (ri->at[2 + 0 * 3] + ri->at[0 + 2 * 3]) / p; // q2 = 4q2q0/4q0
    } else if((p = ri->m11 - ri->m00 - ri->m22) > 0) {
      // 4q1q1-1 > 0 or q1q1 > 1/4 or |q1| > 1/2

      p = sqrt(p + 1); // Now p = 2|q1| > 1

      // If (2|q1| - 2q1) > 1, then p = 2|q1| has the wrong sign.
      // if ( p - qr[1] - qr[1] > 1 ) p = -p; // 2q1

      qo->y = p / 2; // q1
      p = p + p;     // 4q1

      qo->w = (ri->at[0 + 2 * 3] - ri->at[2 + 0 * 3]) / p; // q3 = 4q3q1/4q1
      qo->x = (ri->at[0 + 1 * 3] + ri->at[1 + 0 * 3]) / p; // q0 = 4q0q1/4q1
      qo->z = (ri->at[1 + 2 * 3] + ri->at[2 + 1 * 3]) / p; // q2 = 4q1q2/4q1
    } else {
      // 4q2q2-1 > 0 or q2q2 > 1/4 or |q2| > 1/2
      p = ri->m22 - ri->m00 - ri->m11;

      p = sqrt(p + 1); // Now p = 2|q2| > 1

      // If (2|q2| - 2q2) > 1, then p = 2|q2| has the wrong sign.
      // if ( p - qr[2] - qr[2] > 1 ) p = -p; // 2q2

      qo->z = p / 2; // q2
      p = p + p;     // 4q2

      qo->w = (ri->at[1 + 0 * 3] - ri->at[0 + 1 * 3]) / p; // q3 = 4q3q2/4q2
      qo->x = (ri->at[0 + 2 * 3] + ri->at[2 + 0 * 3]) / p; // q0 = 4q2q0/4q2
      qo->y = (ri->at[2 + 1 * 3] + ri->at[1 + 2 * 3]) / p; // q1 = 4q1q2/4q2
    }
  } else {
    qo->w = 0.5;
    qo->x = copysign(0.5, ri->at[2 + 1 * 3] - ri->at[1 + 2 * 3]);
    qo->y = copysign(0.5, ri->at[0 + 2 * 3] - ri->at[2 + 0 * 3]);
    qo->z = copysign(0.5, ri->at[1 + 0 * 3] - ri->at[0 + 1 * 3]);
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

@param qi [in] euler parameters to convert in a 4x1 array, in the form [w,x,y,z]
@param ro [out] the resulting rotation matrix is stored in ro
*/
inline void ksl_quaternion_toMat3x3(ksl_quaternion_t* restrict qi,
                                    ksl_mat3x3_t* restrict ro) {

  ksl_quaternion_normalize(qi);

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

@param qi euler parameters to convert in a 4x1 array, in the form [w,x,y,z]
@param ro the resulting rotation matrix is stored in ro
*/
inline void ksl_quaternionf_toMat3x3f(ksl_quaternionf_t* restrict qi,
                                      ksl_mat3x3f_t* restrict ro) {
  ksl_quaternionf_normalize(qi);

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

@param q1i a first quaternion in the form [w,x,y,z] to interpolate from
@param q2i a second quaternion in the form [w,x,y,z] to interpolate to
@param t fraction from q1i to q2i (0<t<1)
@param qo the resulting quaternion is returned in qo
*/
inline void ksl_quaternion_slerp(const ksl_quaternion_t* restrict q1i,
                                 const ksl_quaternion_t* restrict q2i,
                                 double* restrict t,
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

@param q1i a first quaternion in the form [w,x,y,z] to interpolate from
@param q2i a second quaternion in the form [w,x,y,z] to interpolate to
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

@param q1i a first quaternion in the form [w,x,y,z] to interpolate from
@param q2i a second quaternion in the form [w,x,y,z] to interpolate to
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

@param q1i a first quaternion in the form [w,x,y,z] to interpolate from
@param q2i a second quaternion in the form [w,x,y,z] to interpolate to
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
  double alpha = 1.0 - ksl_quaternion_dot_qq(qi, qi);

  /*
    if tau is not 0.5

    let coeff = 0.5 / tau
  */
  // double alpha =
  //   coeff * (1 - cblas_ddot(4, (double*)qi, 1, (double*)qi, 1));

  ksl_axpy_qq(alpha, qi, dqo);
}

/*!
@brief Double precision function to multiply double precision quaternion qi1
with double precision quaternion qi2 and return results in double precision
quaternion qo.

       | qw -qz  qy  qx|         | qw  qz -qy  qx|
L(q) = | qz  qw -qx  qy|  R(q) = |-qz  qw  qx  qy|
       |-qy  qx  qw  qz|         | qy -qx  qw  qz|
       |-qx -qy -qz  qw|         |-qx -qy -qz  qw|

 @param q1i a first quaternion in the form [w,x,y,z]
 @param q2i a second quaternion in the form [w,x,y,z]
 @param qo the returned quaternion in the form [w,x,y,z]
*/

inline void ksl_quaternion_product_qq(const ksl_quaternion_t* restrict q1i,
                                      const ksl_quaternion_t* restrict q2i,
                                      ksl_quaternion_t* restrict qo) {
  /*
                    | qi1w -qi1z  qi1y  qi1x| |qi2x|
  qo = L(qi1)*qi2 = | qi1z  qi1w -qi1x  qi1y| |qi2y| = R(qi2)*qi1
                    |-qi1y  qi1x  qi1w  qi1z| |qi2z|
                    |-qi1x -qi1y -qi1z  qi1w| |qi2w|
  */

  qo->x = q1i->w * q2i->x - q1i->z * q2i->y + q1i->y * q2i->z + q1i->x * q2i->w;
  qo->y = q1i->z * q2i->x + q1i->w * q2i->y - q1i->x * q2i->z + q1i->y * q2i->w;
  qo->z =
    -q1i->y * q2i->x + q1i->x * q2i->y + q1i->w * q2i->z + q1i->z * q2i->w;
  qo->w =
    -q1i->x * q2i->x - q1i->y * q2i->y - q1i->z * q2i->z + q1i->w * q2i->w;
}

/*!
@brief Single precision function to multiply single precision quaternion qi1
with single precision quaternion qi2 and return results in single precision
quaternion qo.

       | qw -qz  qy  qx|         | qw  qz -qy  qx|
L(q) = | qz  qw -qx  qy|  R(q) = |-qz  qw  qx  qy|
       |-qy  qx  qw  qz|         | qy -qx  qw  qz|
       |-qx -qy -qz  qw|         |-qx -qy -qz  qw|

@param q1i a first quaternion in the form [w,x,y,z]
@param q2i a second quaternion in the form [w,x,y,z]
@param qo the returned quaternion in the form [w,x,y,z]
*/

inline void ksl_quaternionf_product_qq(const ksl_quaternionf_t* restrict q1i,
                                       const ksl_quaternionf_t* restrict q2i,
                                       ksl_quaternionf_t* restrict qo) {
  /*
                    | qi1w -qi1z  qi1y  qi1x| |qi2x|
  qo = L(qi1)*qi2 = | qi1z  qi1w -qi1x  qi1y| |qi2y| = R(qi2)*qi1
                    |-qi1y  qi1x  qi1w  qi1z| |qi2z|
                    |-qi1x -qi1y -qi1z  qi1w| |qi2w|
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
quaternion qi1 with double precision quaternion qi2 and return results in double
precision quaternion qo.

       | qw -qz  qy  qx|         | qw  qz -qy  qx|
L(q) = | qz  qw -qx  qy|  R(q) = |-qz  qw  qx  qy|
       |-qy  qx  qw  qz|         | qy -qx  qw  qz|
       |-qx -qy -qz  qw|         |-qx -qy -qz  qw|

@param q1i a first quaternion in the form [w,x,y,z]
@param q2i a second quaternion in the form [w,x,y,z]
@param qo the returned quaternion in the form [w,x,y,z]
*/

inline void ksl_quaternion_product_qconjq(const ksl_quaternion_t* restrict q1i,
                                          const ksl_quaternion_t* restrict q2i,
                                          ksl_quaternion_t* restrict qo) {
  /*
                      | qi1w  qi1z -qi1y -qi1x| |qi2x|
  qo = L(qi1)^T*qi2 = |-qi1z  qi1w  qi1x -qi1y| |qi2y|
                      | qi1y -qi1x  qi1w -qi1z| |qi2z|
                      | qi1x  qi1y  qi1z  qi1w| |qi2w|
  */

  qo->x = q1i->w * q2i->x + q1i->z * q2i->y - q1i->y * q2i->z - q1i->x * q2i->w;
  qo->y =
    -q1i->z * q2i->x + q1i->w * q2i->y + q1i->x * q2i->z - q1i->y * q2i->w;
  qo->z = q1i->y * q2i->x - q1i->x * q2i->y + q1i->w * q2i->z - q1i->z * q2i->w;
  qo->w = q1i->x * q2i->x + q1i->y * q2i->y + q1i->z * q2i->z + q1i->w * q2i->w;
}

/*!
@brief Single precision function to multiply the conjugate of single precision
quaternion qi1 with single precision quaternion qi2 and return results in single
precision quaternion qo.

       | qw -qz  qy  qx|         | qw  qz -qy  qx|
L(q) = | qz  qw -qx  qy|  R(q) = |-qz  qw  qx  qy|
       |-qy  qx  qw  qz|         | qy -qx  qw  qz|
       |-qx -qy -qz  qw|         |-qx -qy -qz  qw|

@param q1i a first quaternion in the form [w,x,y,z]
@param q2i a second quaternion in the form [w,x,y,z]
@param qo the returned quaternion in the form [w,x,y,z]
*/

inline void
ksl_quaternionf_product_qconjq(const ksl_quaternionf_t* restrict q1i,
                               const ksl_quaternionf_t* restrict q2i,
                               ksl_quaternionf_t* restrict qo) {
  /*
                      | qi1w  qi1z -qi1y -qi1x| |qi2x|
  qo = L(qi1)^T*qi2 = |-qi1z  qi1w  qi1x -qi1y| |qi2y|
                      | qi1y -qi1x  qi1w -qi1z| |qi2z|
                      | qi1x  qi1y  qi1z  qi1w| |qi2w|
  */

  qo->x = q1i->w * q2i->x + q1i->z * q2i->y - q1i->y * q2i->z - q1i->x * q2i->w;
  qo->y =
    -q1i->z * q2i->x + q1i->w * q2i->y + q1i->x * q2i->z - q1i->y * q2i->w;
  qo->z = q1i->y * q2i->x - q1i->x * q2i->y + q1i->w * q2i->z - q1i->z * q2i->w;
  qo->w = q1i->x * q2i->x + q1i->y * q2i->y + q1i->z * q2i->z + q1i->w * q2i->w;
}

/*!
@brief Double precision function to multiply double precision quaternion qi1
with the conjugate of double precision quaternion qi2 and return results in
double precision quaternion qo.

       | qw -qz  qy  qx|         | qw  qz -qy  qx|
L(q) = | qz  qw -qx  qy|  R(q) = |-qz  qw  qx  qy|
       |-qy  qx  qw  qz|         | qy -qx  qw  qz|
       |-qx -qy -qz  qw|         |-qx -qy -qz  qw|

@param q1i a first quaternion in the form [w,x,y,z]
@param q2i a second quaternion in the form [w,x,y,z]
@param qo the returned quaternion in the form [w,x,y,z]
*/

inline void ksl_quaternion_product_qqconj(const ksl_quaternion_t* restrict q1i,
                                          const ksl_quaternion_t* restrict q2i,
                                          ksl_quaternion_t* restrict qo) {
  /*
                      | qi2w -qi2z  qi2y -qi2x| |qi1x|
  qo = R(qi2)^T*qi1 = | qi2z  qi2w -qi2x -qi2y| |qi1y|
                      |-qi2y  qi2x  qi2w -qi2z| |qi1z|
                      | qi2x  qi2y  qi2z  qi2w| |qi1w|
  */

  qo->x = q2i->w * q1i->x - q2i->z * q1i->y + q2i->y * q1i->z - q2i->x * q1i->w;
  qo->y = q2i->z * q1i->x + q2i->w * q1i->y - q2i->x * q1i->z - q2i->y * q1i->w;
  qo->z =
    -q2i->y * q1i->x + q2i->x * q1i->y + q2i->w * q1i->z - q2i->z * q1i->w;
  qo->w = q2i->x * q1i->x + q2i->y * q1i->y + q2i->z * q1i->z + q2i->w * q1i->w;
}

/*!
@brief Single precision function to multiply single precision quaternion qi1
with the conjugate of single precision quaternion qi2 and return results in
single precision quaternion qo.

       | qw -qz  qy  qx|         | qw  qz -qy  qx|
L(q) = | qz  qw -qx  qy|  R(q) = |-qz  qw  qx  qy|
       |-qy  qx  qw  qz|         | qy -qx  qw  qz|
       |-qx -qy -qz  qw|         |-qx -qy -qz  qw|

@param q1i a first quaternion in the form [w,x,y,z]
@param q2i a second quaternion in the form [w,x,y,z]
@param qo the returned quaternion in the form [w,x,y,z]
*/

inline void
ksl_quaternionf_product_qqconj(const ksl_quaternionf_t* restrict q1i,
                               const ksl_quaternionf_t* restrict q2i,
                               ksl_quaternionf_t* restrict qo) {
  /*
                      | qi2w -qi2z  qi2y -qi2x| |qi1x|
  qo = R(qi2)^T*qi1 = | qi2z  qi2w -qi2x -qi2y| |qi1y|
                      |-qi2y  qi2x  qi2w -qi2z| |qi1z|
                      | qi2x  qi2y  qi2z  qi2w| |qi1w|
  */

  qo->x = q2i->w * q1i->x - q2i->z * q1i->y + q2i->y * q1i->z - q2i->x * q1i->w;
  qo->y = q2i->z * q1i->x + q2i->w * q1i->y - q2i->x * q1i->z - q2i->y * q1i->w;
  qo->z =
    -q2i->y * q1i->x + q2i->x * q1i->y + q2i->w * q1i->z - q2i->z * q1i->w;
  qo->w = q2i->x * q1i->x + q2i->y * q1i->y + q2i->z * q1i->z + q2i->w * q1i->w;
}

/*!
@brief Double precision function to multiply the conjugate of double precision
quaternion qi1 with the conjugate of double precision quaternion qi2 and return
results in double precision quaternion qo.

       | qw -qz  qy  qx|         | qw  qz -qy  qx|
L(q) = | qz  qw -qx  qy|  R(q) = |-qz  qw  qx  qy|
       |-qy  qx  qw  qz|         | qy -qx  qw  qz|
       |-qx -qy -qz  qw|         |-qx -qy -qz  qw|

@param q1i a first quaternion in the form [w,x,y,z]
@param q2i a second quaternion in the form [w,x,y,z]
@param qo the returned quaternion in the form [w,x,y,z]
*/
void ksl_quaternion_product_qconjqconj(const ksl_quaternion_t* restrict q1i,
                                       const ksl_quaternion_t* restrict q2i,
                                       ksl_quaternion_t* restrict qo) {
  /*
                          | qi1w  qi1z -qi1y -qi1x| | qi2x|
  qo = L(qi1)^T*qi2conj = |-qi1z  qi1w  qi1x -qi1y| |-qi2y|
                          | qi1y -qi1x  qi1w -qi1z| |-qi2z|
                          | qi1x  qi1y  qi1z  qi1w| |-qi2w|

                          | qi1w -qi1z  qi1y  qi1x| |qi2x|
                        = |-qi1z -qi1w -qi1x  qi1y| |qi2y|
                          | qi1y  qi1x -qi1w  qi1z| |qi2z|
                          | qi1x -qi1y -qi1z -qi1w| |qi2w|
  */
  qo->x = q1i->w * q2i->x - q1i->z * q2i->y + q1i->y * q2i->z + q1i->x * q2i->w;
  qo->y =
    -q1i->z * q2i->x - q1i->w * q2i->y - q1i->x * q2i->z + q1i->y * q2i->w;
  qo->z = q1i->y * q2i->x + q1i->x * q2i->y - q1i->w * q2i->z + q1i->z * q2i->w;
  qo->w = q1i->x * q2i->x - q1i->y * q2i->y - q1i->z * q2i->z - q1i->w * q2i->w;
}

/*!
@brief Single precision function to multiply the conjugate of single precision
quaternion qi1 with the conjugate of single precision quaternion qi2 and return
results in single precision quaternion qo.

       | qw -qz  qy  qx|         | qw  qz -qy  qx|
L(q) = | qz  qw -qx  qy|  R(q) = |-qz  qw  qx  qy|
       |-qy  qx  qw  qz|         | qy -qx  qw  qz|
       |-qx -qy -qz  qw|         |-qx -qy -qz  qw|

@param q1i a first quaternion in the form [w,x,y,z]
@param q2i a second quaternion in the form [w,x,y,z]
@param qo the returned quaternion in the form [w,x,y,z]
*/

void ksl_quaternionf_product_qconjqconj(const ksl_quaternionf_t* restrict q1i,
                                        const ksl_quaternionf_t* restrict q2i,
                                        ksl_quaternionf_t* restrict qo) {
  /*
                          | qi1w  qi1z -qi1y -qi1x| | qi2x|
  qo = L(qi1)^T*qi2conj = |-qi1z  qi1w  qi1x -qi1y| |-qi2y|
                          | qi1y -qi1x  qi1w -qi1z| |-qi2z|
                          | qi1x  qi1y  qi1z  qi1w| |-qi2w|

                          | qi1w -qi1z  qi1y  qi1x| |qi2x|
                        = |-qi1z -qi1w -qi1x  qi1y| |qi2y|
                          | qi1y  qi1x -qi1w  qi1z| |qi2z|
                          | qi1x -qi1y -qi1z -qi1w| |qi2w|
  */
  qo->x = q1i->w * q2i->x - q1i->z * q2i->y + q1i->y * q2i->z + q1i->x * q2i->w;
  qo->y =
    -q1i->z * q2i->x - q1i->w * q2i->y - q1i->x * q2i->z + q1i->y * q2i->w;
  qo->z = q1i->y * q2i->x + q1i->x * q2i->y - q1i->w * q2i->z + q1i->z * q2i->w;
  qo->w = q1i->x * q2i->x - q1i->y * q2i->y - q1i->z * q2i->z - q1i->w * q2i->w;
}

/*!
@brief Double precision function to multiply double precision quaternion qi1
with double precision vector vi and return results in double precision
quaternion qo.

       | qw -qz  qy  qx|         | qw  qz -qy  qx|
L(q) = | qz  qw -qx  qy|  R(q) = |-qz  qw  qx  qy|
       |-qy  qx  qw  qz|         | qy -qx  qw  qz|
       |-qx -qy -qz  qw|         |-qx -qy -qz  qw|

 @param q1i a first quaternion in the form [w,x,y,z]
 @param q2i a second quaternion in the form [w,x,y,z]
 @param qo the returned quaternion in the form [w,x,y,z]
*/

void ksl_quaternion_product_qv(const ksl_quaternion_t* restrict q1i,
                               const ksl_vec3_t* restrict vi,
                               ksl_quaternion_t* restrict qo) {
  /*
                   | qi1w -qi1z  qi1y  qi1x| |vix|
  qo = L(qi1)*vi = | qi1z  qi1w -qi1x  qi1y| |viy|
                   |-qi1y  qi1x  qi1w  qi1z| |viz|
                   |-qi1x -qi1y -qi1z  qi1w| | 0 |
*/

  qo->x = q1i->w * vi->x - q1i->z * vi->y + q1i->y * vi->z;
  qo->y = q1i->z * vi->x + q1i->w * vi->y - q1i->x * vi->z;
  qo->z = -q1i->y * vi->x + q1i->x * vi->y + q1i->w * vi->z;
  qo->w = -q1i->x * vi->x - q1i->y * vi->y - q1i->z * vi->z;
}
/*!
@brief Single precision function to multiply single precision quaternion qi1
with single precision quaternion qi2 and return results in single precision
quaternion qo.

       | qw -qz  qy  qx|         | qw  qz -qy  qx|
L(q) = | qz  qw -qx  qy|  R(q) = |-qz  qw  qx  qy|
       |-qy  qx  qw  qz|         | qy -qx  qw  qz|
       |-qx -qy -qz  qw|         |-qx -qy -qz  qw|

@param q1i a first quaternion in the form [w,x,y,z]
@param q2i a second quaternion in the form [w,x,y,z]
@param qo the returned quaternion in the form [w,x,y,z]
*/

void ksl_quaternionf_product_qv(const ksl_quaternionf_t* restrict q1i,
                                const ksl_vec3f_t* restrict vi,
                                ksl_quaternionf_t* restrict qo) {
  /*
                   | qi1w -qi1z  qi1y  qi1x| |vix|
  qo = L(qi1)*vi = | qi1z  qi1w -qi1x  qi1y| |viy|
                   |-qi1y  qi1x  qi1w  qi1z| |viz|
                   |-qi1x -qi1y -qi1z  qi1w| | 0 |
*/

  qo->x = q1i->w * vi->x - q1i->z * vi->y + q1i->y * vi->z;
  qo->y = q1i->z * vi->x + q1i->w * vi->y - q1i->x * vi->z;
  qo->z = -q1i->y * vi->x + q1i->x * vi->y + q1i->w * vi->z;
  qo->w = -q1i->x * vi->x - q1i->y * vi->y - q1i->z * vi->z;
}
