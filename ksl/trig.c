#include "ksl/trig.h"

inline void ksl_dc(const double thetai, double dc[2]) {
#ifdef _GNU_SOURCE

#ifdef __APPLE__
  __sincos(thetai, &dc[0], &dc[1]);
#else
  sincos(thetai, &dc[0], &dc[1]);
#endif

#else
  dc[0] = sin(thetai);
  dc[1] = cos(thetai);
#endif
}

inline void ksl_dcf(const float thetai, float dc[2]) {
#ifdef _GNU_SOURCE

#ifdef __APPLE__
  __sincosf(thetai, &dc[0], &dc[1]);
#else
  sincosf(thetai, &dc[0], &dc[1]);
#endif

#else
  dc[0] = sin(thetai);
  dc[1] = cos(thetai);
#endif
}

/*!
@brief Normalize double precision angle in degrees

@param angle [in] angle in degrees
@return the angle wrapped to the range [0, 360)
*/
inline double ksl_normalizeDegrees(double angle) {
  return (angle - floor(angle / 360.0) * 360.0);
}

/*!
@brief Normalize single precision angle in degrees

@param angle [in] angle in degrees
@return the angle wrapped to the range [0, 360)
*/
inline float ksl_normalizeDegreesf(float angle) {
  return (angle - floor(angle / 360.0) * 360.0);
}

/*!
@brief Normalize angle in radians

@param angle [in] angle in radians
@return the angle wrapped to the range [0, 2 pi)
*/
double ksl_normalizeRadians(double angle) {
  const double twopi = 2.0 * M_PI;
  return (angle - floor(angle / twopi) * twopi);
}

/*!
@brief Normalize angle in radians

@param angle [in] angle in radians
@return the angle wrapped to the range [0, 2 pi)
*/
float ksl_normalizeRadiansf(float angle) {
  const float twopi = 2.0 * M_PI;
  return (angle - floor(angle / twopi) * twopi);
}

/*!
@brief returns a continuous double precision angle obtained from atan2(y, x)

Returns the angle with sine y and cosine x (up to a common positive factor)
that is nearest to the reference angle theta, typically the value returned
by the previous call. The result is atan2(y, x) shifted by a multiple of
2 pi:

\f[ \theta_{new} = \theta + \operatorname{remainder}(\operatorname{atan2}(y, x)
- \theta,\ 2\pi) \f]

so it lies within pi of theta and is continuous in time as long as the
angle changes by less than pi between calls, in either direction. theta may
be any multiple of a full turn.

Both x and y must have their correct signs. If they are known only up to a
common sign, the angle is known only to within pi; use ksl_catan1pi.

@param y [in] sine of the angle, or a positive multiple of it
@param x [in] cosine of the angle, the same multiple
@param theta [in] reference angle in radians
@return the angle nearest to theta
*/
double ksl_catan2pi(const double y, const double x, double theta) {
  return theta + remainder(atan2(y, x) - theta, 2.0 * M_PI);
}

/*!
@brief Single precision version of ksl_catan2pi().
*/
float ksl_catan2pif(const float y, const float x, float theta) {
  return theta + remainderf(atan2f(y, x) - theta, (float)(2.0 * M_PI));
}

/*!
@brief returns a continuous double precision angle from atan2(y, x) when x
and y are known only up to a common sign

If x and y may both have the wrong sign, atan2(y, x) gives the angle only to
within pi. This function returns the angle in that family nearest to the
reference angle theta, typically the value returned by the previous call:

\f[ \theta_{new} = \theta + \operatorname{remainder}(\operatorname{atan2}(y, x)
- \theta,\ \pi) \f]

so it lies within pi/2 of theta and is continuous in time as long as the
angle changes by less than pi/2 between calls, in either direction. When the
signs of x and y are known, ksl_catan2pi determines the angle to within 2 pi.

@param y [in] sine of the angle, or a nonzero multiple of it
@param x [in] cosine of the angle, the same multiple
@param theta [in] reference angle in radians
@return the angle nearest to theta
*/
double ksl_catan1pi(const double y, const double x, double theta) {
  return theta + remainder(atan2(y, x) - theta, M_PI);
}

/*!
@brief Single precision version of ksl_catan1pi().
*/
float ksl_catan1pif(const float y, const float x, float theta) {
  return theta + remainderf(atan2f(y, x) - theta, (float)M_PI);
}
