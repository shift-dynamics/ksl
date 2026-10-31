#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "ksl/quaternion.h"

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

#if 0

#endif

