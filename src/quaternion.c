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
@brief Normalize a double precision quaternion

Normalize a quaternion and overwrite.
Add assert(norm) > unit roundoff to avoid division by zero.

@param qi euler parameters to normalize
*/
inline void ksl_quaternion_normalize(ksl_quaternion_t* restrict qi) {
  register double norm = 0;
  for(int i = 0; i < 4; i++) {
    norm += qi->at[i] * qi->at[i];
  }
  norm = sqrt(norm);
  for(int i = 0; i < 4; i++) {
    qi->at[i] /= norm;
  }
}

/*!
@brief Normalize single precision quaternion

Normalize a quaternion and overwrite.
Add assert(norm) > unit roundoff to avoid division by zero.

@param qi euler parameters to normalize
*/
inline void ksl_quaternionf_normalize(ksl_quaternionf_t* restrict qi) {
  register float norm = 0;
  for(int i = 0; i < 4; i++) {
    norm += qi->at[i] * qi->at[i];
  }
  norm = sqrt(norm);
  for(int i = 0; i < 4; i++) {
    qi->at[i] /= norm;
  }
}

inline void ksl_axpy_qq(const double a, const ksl_quaternion_t* restrict x,
                        ksl_quaternion_t* restrict y) {
  for(int i = 0; i < 4; i++) {
    y->at[i] += a * x->at[i];
  }
}

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
q3q3 + q0q0 - q1q1 - q2q2 & q0q1 + q0q1 - q3q2 + q3q2 &
q2q0 + q2q0 + q3q1 + q3q1 \\
q0q1 + q0q1 + q3q2 + q3q2 & q3q3 - q0q0 + q1q1 - q2q2 & q1q2 +
q1q2 - q3q0 - q3q0 \\
q2q0 + q2q0 - q3q1 - q3q1 & q1q2 + q1q2 + q3q0 + q3q0 &
q3q3 - q0q0 - q1q1 + q2q2 \\ \end{bmatrix}\f$

@todo Supply qr, a reference quaterniohn. If necessary, flip the sign of
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
      // Now p = 2|q3| > 1
      p = sqrt(p + 1);

      // If (2|q3| - 2q3) > 1, then p = 2|q3| has the wrong sign.
      // if ( p - qr[3] - qr[3] > 1 ) p = -p; // 2q3
      qo->w = p / 2; // q3
      p = p + p;     // 4q3

      qo->x = (ri->at[2 + 1 * 3] - ri->at[1 + 2 * 3]) / p; // q0 = 4q3q0/4q3
      qo->y = (ri->at[0 + 2 * 3] - ri->at[2 + 0 * 3]) / p; // q1 = 4q3q1/4q3
      qo->z = (ri->at[1 + 0 * 3] - ri->at[0 + 1 * 3]) / p; // q2 = 4q3q2/4q3
    } else if((p = ri->m00 - ri->m11 - ri->m22) > 0) {
      // 4q0q0-1 > 0 or q0q0 > 1/4 or |q0| > 1/2
      // Now p = 2|q0| > 1
      p = sqrt(p + 1);

      // If (2|q0| - 2q0) > 1, then p = 2|q0| has the wrong sign.
      // if ( p - qr[0] - qr[0] > 1 ) p = -p; // 2q0
      qo->x = p / 2; // q0
      p = p + p;     // 4q0

      qo->w = (ri->at[2 + 1 * 3] - ri->at[1 + 2 * 3]) / p; // q3 = 4q3q0/4q0
      qo->y = (ri->at[1 + 0 * 3] + ri->at[0 + 1 * 3]) / p; // q1 = 4q0q1/4q0
      qo->z = (ri->at[2 + 0 * 3] + ri->at[0 + 2 * 3]) / p; // q2 = 4q2q0/4q0
    } else if((p = ri->m11 - ri->m00 - ri->m22) > 0) {
      // 4q1q1-1 > 0 or q1q1 > 1/4 or |q1| > 1/2
      // Now p = 2|q1| > 1
      p = sqrt(p + 1);

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

      // Now p = 2|q2| > 1
      p = sqrt(p + 1);

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
q3q3 + q0q0 - q1q1 - q2q2 & q0q1 + q0q1 - q3q2 + q3q2 &
q2q0 + q2q0 + q3q1 + q3q1 \\
q0q1 + q0q1 + q3q2 + q3q2 & q3q3 - q0q0 + q1q1 - q2q2 & q1q2 +
q1q2 - q3q0 - q3q0 \\
q2q0 + q2q0 - q3q1 - q3q1 & q1q2 + q1q2 + q3q0 + q3q0 &
q3q3 - q0q0 - q1q1 + q2q2 \\ \end{bmatrix}\f$

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

      // Now p = 2|q3| > 1
      p = sqrt(p + 1);

      // If (2|q3| - 2q3) > 1, then p = 2|q3| has the wrong sign.
      // if ( p - qr[3] - qr[3] > 1 ) p = -p; // 2q3

      qo->w = p / 2; // q3
      p = p + p;     // 4q3

      qo->x = (ri->at[2 + 1 * 3] - ri->at[1 + 2 * 3]) / p; // q0 = 4q3q0/4q3
      qo->y = (ri->at[0 + 2 * 3] - ri->at[2 + 0 * 3]) / p; // q1 = 4q3q1/4q3
      qo->z = (ri->at[1 + 0 * 3] - ri->at[0 + 1 * 3]) / p; // q2 = 4q3q2/4q3
    } else if((p = ri->m00 - ri->m11 - ri->m22) > 0) {
      // 4q0q0-1 > 0 or q0q0 > 1/4 or |q0| > 1/2
      // Now p = 2|q0| > 1
      p = sqrt(p + 1);

      // If (2|q0| - 2q0) > 1, then p = 2|q0| has the wrong sign.
      // if ( p - qr[0] - qr[0] > 1 ) p = -p; // 2q0
      qo->x = p / 2;                                       // q0
      p = p + p;                                           // 4q0
      qo->w = (ri->at[2 + 1 * 3] - ri->at[1 + 2 * 3]) / p; // q3 = 4q3q0/4q0
      qo->y = (ri->at[1 + 0 * 3] + ri->at[0 + 1 * 3]) / p; // q1 = 4q0q1/4q0
      qo->z = (ri->at[2 + 0 * 3] + ri->at[0 + 2 * 3]) / p; // q2 = 4q2q0/4q0
    } else if((p = ri->m11 - ri->m00 - ri->m22) > 0) {
      // 4q1q1-1 > 0 or q1q1 > 1/4 or |q1| > 1/2
      // Now p = 2|q1| > 1
      p = sqrt(p + 1);

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

      // Now p = 2|q2| > 1
      p = sqrt(p + 1);

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
q3q3 + q0q0 - q1q1 - q2q2 & q0q1 + q0q1 - q3q2 + q3q2 &
q2q0 + q2q0 + q3q1 + q3q1 \\
q0q1 + q0q1 + q3q2 + q3q2 & q3q3 - q0q0 + q1q1 - q2q2 & q1q2 +
q1q2 - q3q0 - q3q0 \\
q2q0 + q2q0 - q3q1 - q3q1 & q1q2 + q1q2 + q3q0 + q3q0 &
q3q3 - q0q0 - q1q1 + q2q2 \\ \end{bmatrix}\f$

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
q3q3 + q0q0 - q1q1 - q2q2 & q0q1 + q0q1 - q3q2 + q3q2 &
q2q0 + q2q0 + q3q1 + q3q1 \\
q0q1 + q0q1 + q3q2 + q3q2 & q3q3 - q0q0 + q1q1 - q2q2 & q1q2 +
q1q2 - q3q0 - q3q0 \\
q2q0 + q2q0 - q3q1 - q3q1 & q1q2 + q1q2 + q3q0 + q3q0 &
q3q3 - q0q0 - q1q1 + q2q2 \\ \end{bmatrix}\f$

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
