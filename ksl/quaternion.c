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

/* TODO: add ksl_xpy_qq/qqf and ksl_nxpy_qq/qqf, variants of axpy where a is
+/-1 */

/*!
@brief Convert a rotation matrix to a quaternion.

The inverse of ksl_quaternion_toMat3x3(). A rotation matrix determines its
quaternion only up to sign, since q and -q give the same matrix. When the
trace of the matrix is positive, the returned quaternion has w > 0.

@param ri [in] rotation matrix
@param qo [out] quaternion
*/
/* TODO: accept a reference quaternion qr and flip the sign of qo so that it
is the closer of qo and -qo to qr, to give continuous quaternions for
interpolation. */
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
@brief Single precision version of ksl_mat3x3_toQuaternion().
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
@brief Logarithm of a unit quaternion.

For the unit quaternion \f$q = \{\underline{e}\sin\phi, \cos\phi\}\f$, with
\f$0 \le \phi \le \pi\f$, the logarithm is the pure quaternion
\f$\log q = \{\underline{e}\,\phi, 0\}\f$; its vector part, half the rotation
vector, is returned. If qi is a rotation of more than \f$\pi\f$ (w < 0), so is
the result, \f$|\log q| > \pi/2\f$; negate qi first for the shorter rotation.
The inverse of ksl_quaternion_exp().

@param qi [in] unit quaternion
@param vo [out] vector part of log(qi)
*/
void ksl_quaternion_log(const ksl_quaternion_t* restrict qi,
                        ksl_vec3_t* restrict vo) {
  const double n = sqrt(qi->x * qi->x + qi->y * qi->y + qi->z * qi->z);
  double f;
  if(n < 1e-6 && qi->w > 0.0) {
    /* atan(n / w) / n, to within (n / w)^4 / 5 */
    const double r = n / qi->w;
    f = (1.0 - r * r / 3.0) / qi->w;
  } else if(n == 0.0) {
    f = 0.0; /* w = -1: a rotation by 2 pi, about no particular axis */
  } else {
    f = atan2(n, qi->w) / n;
  }
  vo->x = f * qi->x;
  vo->y = f * qi->y;
  vo->z = f * qi->z;
}

/*!
@brief Exponential of a pure quaternion.

For the pure quaternion \f$\{\underline{v}, 0\}\f$ with
\f$\phi = |\underline{v}|\f$,
\f$\exp\{\underline{v}, 0\} = \{\underline{v}\sin(\phi)/\phi, \cos\phi\}\f$,
the rotation by \f$2\phi\f$ about \f$\underline{v}\f$. The inverse of
ksl_quaternion_log().

@param vi [in] vector part of a pure quaternion
@param qo [out] unit quaternion exp(vi)
*/
void ksl_quaternion_exp(const ksl_vec3_t* restrict vi,
                        ksl_quaternion_t* restrict qo) {
  const double phi2 = vi->x * vi->x + vi->y * vi->y + vi->z * vi->z;
  const double phi = sqrt(phi2);
  /* sin(phi) / phi, to within phi^4 / 120 */
  const double f = phi < 1e-4 ? 1.0 - phi2 / 6.0 : sin(phi) / phi;
  qo->x = f * vi->x;
  qo->y = f * vi->y;
  qo->z = f * vi->z;
  qo->w = cos(phi);
}

/* log(q1i^* q2i) for the shorter of the two rotations q1i^* q2i and
-q1i^* q2i, so the result does not depend on the signs of q1i and q2i */
static void ksl_quaternion_log_difference(const ksl_quaternion_t* q1i,
                                          const ksl_quaternion_t* q2i,
                                          ksl_vec3_t* vo) {
  ksl_quaternion_t d;
  ksl_product_qconjq(q1i, q2i, &d);
  if(d.w < 0.0) {
    for(int i = 0; i < 4; i++) {
      d.at[i] = -d.at[i];
    }
  }
  ksl_quaternion_log(&d, vo);
}

/*!
@brief Control point of a key quaternion for ksl_quaternion_squad().

Given the key \f$q_i\f$ and its neighbors \f$q_{i-1}\f$ and \f$q_{i+1}\f$,
computes (Shoemake, 1987; see the References)

\f[
s_i = q_i \exp\left(-\frac{\log(q_i^* q_{i+1}) + \log(q_i^* q_{i-1})}{4}
\right)
\f]

which makes the squad curve through the keys continuous in angular velocity
at \f$q_i\f$. The differences \f$q_i^* q_{i\pm1}\f$ are taken as the shorter
rotation, so the signs of the keys do not matter, and \f$s_i\f$ has the sign
of \f$q_i\f$. At the first and last key there is only one neighbor; use the
key itself as its control point, as ksl_quaternion_squad_keys() does.

@param qprevi [in] previous key, \f$q_{i-1}\f$
@param qi [in] key, \f$q_i\f$
@param qnexti [in] next key, \f$q_{i+1}\f$
@param so [out] control point, \f$s_i\f$
*/
void ksl_quaternion_squad_control(const ksl_quaternion_t* restrict qprevi,
                                  const ksl_quaternion_t* restrict qi,
                                  const ksl_quaternion_t* restrict qnexti,
                                  ksl_quaternion_t* restrict so) {
  ksl_vec3_t lnext, lprev;
  ksl_quaternion_log_difference(qi, qnexti, &lnext);
  ksl_quaternion_log_difference(qi, qprevi, &lprev);
  ksl_vec3_t v =
    ksl_vec3(-0.25 * (lnext.x + lprev.x), -0.25 * (lnext.y + lprev.y),
             -0.25 * (lnext.z + lprev.z));
  ksl_quaternion_t e;
  ksl_quaternion_exp(&v, &e);
  ksl_product_qq(qi, &e, so);
}

/*!
@brief Spherical quadrangle interpolation (squad) between two key quaternions.

Interpolates from the key \f$q_1\f$ to the next key \f$q_2\f$ along a smooth
curve shaped by their control points \f$s_1\f$ and \f$s_2\f$ from
ksl_quaternion_squad_control() (Shoemake, 1987; see the References):

\f[
\mathrm{squad}(q_1, q_2, s_1, s_2, t) = \mathrm{slerp}\big(
\mathrm{slerp}(q_1, q_2, t), \mathrm{slerp}(s_1, s_2, t), 2t(1 - t)\big)
\f]

Joining the curves between successive keys gives an orientation path through
all the keys that is continuous in angular velocity, unlike slerp between
successive keys, whose angular velocity jumps at every key. The slerps take
the shorter path, so the signs of the keys do not matter. To interpolate an
array of keys, see ksl_quaternion_squad_keys().

@param q1i [in] key at t = 0
@param q2i [in] key at t = 1
@param s1i [in] control point of q1i
@param s2i [in] control point of q2i
@param t [in] interpolation parameter, from 0 to 1
@param qo [out] interpolated quaternion
*/
void ksl_quaternion_squad(const ksl_quaternion_t* restrict q1i,
                          const ksl_quaternion_t* restrict q2i,
                          const ksl_quaternion_t* restrict s1i,
                          const ksl_quaternion_t* restrict s2i,
                          const double* restrict t,
                          ksl_quaternion_t* restrict qo) {
  double h = *t;
  double u = 2.0 * h * (1.0 - h);
  ksl_quaternion_t a, b;
  ksl_quaternion_slerp(q1i, q2i, &h, &a);
  ksl_quaternion_slerp(s1i, s2i, &h, &b);
  ksl_quaternion_slerp(&a, &b, &u, qo);
}

/*!
@brief Interpolate an array of key quaternions with squad.

Evaluates the squad curve through the n keys at the parameter t, which runs
from 0 at keys[0] to n - 1 at keys[n - 1]: key k is reached at t = k, so the
keys are taken as equally spaced in time. Between keys k and k + 1 it calls
ksl_quaternion_squad() with t - k, computing the two control points with
ksl_quaternion_squad_control(); the first and last keys are their own control
points. t outside [0, n - 1] is clamped. The signs of the keys do not matter.

To evaluate many points, it is cheaper to compute the control points of all
the keys once with ksl_quaternion_squad_control() and call
ksl_quaternion_squad() directly.

@param n [in] number of keys, at least 1
@param keys [in] key quaternions
@param t [in] key parameter, from 0 to n - 1
@param qo [out] interpolated quaternion
*/
void ksl_quaternion_squad_keys(const int n,
                               const ksl_quaternion_t* restrict keys,
                               const double* restrict t,
                               ksl_quaternion_t* restrict qo) {
  if(n < 2 || !(*t > 0.0)) {
    *qo = keys[0];
    return;
  }
  if(*t >= n - 1) {
    *qo = keys[n - 1];
    return;
  }
  const int k = (int)floor(*t);
  const double h = *t - k;
  ksl_quaternion_t s1 = keys[k], s2 = keys[k + 1];
  if(k > 0) {
    ksl_quaternion_squad_control(&keys[k - 1], &keys[k], &keys[k + 1], &s1);
  }
  if(k + 2 < n) {
    ksl_quaternion_squad_control(&keys[k], &keys[k + 1], &keys[k + 2], &s2);
  }
  ksl_quaternion_squad(&keys[k], &keys[k + 1], &s1, &s2, &h, qo);
}

/*!
@brief Single precision version of ksl_quaternion_log().
*/
void ksl_quaternionf_log(const ksl_quaternionf_t* restrict qi,
                         ksl_vec3f_t* restrict vo) {
  const float n = sqrtf(qi->x * qi->x + qi->y * qi->y + qi->z * qi->z);
  float f;
  if(n < 1e-3f && qi->w > 0.0f) {
    /* atan(n / w) / n, to within (n / w)^4 / 5 */
    const float r = n / qi->w;
    f = (1.0f - r * r / 3.0f) / qi->w;
  } else if(n == 0.0f) {
    f = 0.0f; /* w = -1: a rotation by 2 pi, about no particular axis */
  } else {
    f = atan2f(n, qi->w) / n;
  }
  vo->x = f * qi->x;
  vo->y = f * qi->y;
  vo->z = f * qi->z;
}

/*!
@brief Single precision version of ksl_quaternion_exp().
*/
void ksl_quaternionf_exp(const ksl_vec3f_t* restrict vi,
                         ksl_quaternionf_t* restrict qo) {
  const float phi2 = vi->x * vi->x + vi->y * vi->y + vi->z * vi->z;
  const float phi = sqrtf(phi2);
  /* sin(phi) / phi, to within phi^4 / 120 */
  const float f = phi < 1e-2f ? 1.0f - phi2 / 6.0f : sinf(phi) / phi;
  qo->x = f * vi->x;
  qo->y = f * vi->y;
  qo->z = f * vi->z;
  qo->w = cosf(phi);
}

/* log(q1i^* q2i) for the shorter of the two rotations q1i^* q2i and
-q1i^* q2i, so the result does not depend on the signs of q1i and q2i */
static void ksl_quaternionf_log_difference(const ksl_quaternionf_t* q1i,
                                           const ksl_quaternionf_t* q2i,
                                           ksl_vec3f_t* vo) {
  ksl_quaternionf_t d;
  ksl_product_qconjqf(q1i, q2i, &d);
  if(d.w < 0.0f) {
    for(int i = 0; i < 4; i++) {
      d.at[i] = -d.at[i];
    }
  }
  ksl_quaternionf_log(&d, vo);
}

/*!
@brief Single precision version of ksl_quaternion_squad_control().
*/
void ksl_quaternionf_squad_control(const ksl_quaternionf_t* restrict qprevi,
                                   const ksl_quaternionf_t* restrict qi,
                                   const ksl_quaternionf_t* restrict qnexti,
                                   ksl_quaternionf_t* restrict so) {
  ksl_vec3f_t lnext, lprev;
  ksl_quaternionf_log_difference(qi, qnexti, &lnext);
  ksl_quaternionf_log_difference(qi, qprevi, &lprev);
  ksl_vec3f_t v =
    ksl_vec3f(-0.25f * (lnext.x + lprev.x), -0.25f * (lnext.y + lprev.y),
              -0.25f * (lnext.z + lprev.z));
  ksl_quaternionf_t e;
  ksl_quaternionf_exp(&v, &e);
  ksl_product_qqf(qi, &e, so);
}

/*!
@brief Single precision version of ksl_quaternion_squad().
*/
void ksl_quaternionf_squad(const ksl_quaternionf_t* restrict q1i,
                           const ksl_quaternionf_t* restrict q2i,
                           const ksl_quaternionf_t* restrict s1i,
                           const ksl_quaternionf_t* restrict s2i,
                           const float* restrict t,
                           ksl_quaternionf_t* restrict qo) {
  float h = *t;
  float u = 2.0f * h * (1.0f - h);
  ksl_quaternionf_t a, b;
  ksl_quaternionf_slerp(q1i, q2i, &h, &a);
  ksl_quaternionf_slerp(s1i, s2i, &h, &b);
  ksl_quaternionf_slerp(&a, &b, &u, qo);
}

/*!
@brief Single precision version of ksl_quaternion_squad_keys().
*/
void ksl_quaternionf_squad_keys(const int n,
                                const ksl_quaternionf_t* restrict keys,
                                const float* restrict t,
                                ksl_quaternionf_t* restrict qo) {
  if(n < 2 || !(*t > 0.0f)) {
    *qo = keys[0];
    return;
  }
  if(*t >= n - 1) {
    *qo = keys[n - 1];
    return;
  }
  const int k = (int)floorf(*t);
  const float h = *t - k;
  ksl_quaternionf_t s1 = keys[k], s2 = keys[k + 1];
  if(k > 0) {
    ksl_quaternionf_squad_control(&keys[k - 1], &keys[k], &keys[k + 1], &s1);
  }
  if(k + 2 < n) {
    ksl_quaternionf_squad_control(&keys[k], &keys[k + 1], &keys[k + 2], &s2);
  }
  ksl_quaternionf_squad(&keys[k], &keys[k + 1], &s1, &s2, &h, qo);
}
