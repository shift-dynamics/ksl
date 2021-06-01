#include "ksl/trig.h"

inline void ksl_dc(const double thetai, double dc[2]) {
#ifdef _GNU_SOURCE
  sincos(thetai, &dc[0], &dc[1]);
#else
  dc[0] = sin(thetai);
  dc[1] = cos(thetai);
#endif
}

inline void ksl_dcf(const float thetai, float dc[2]) {
#ifdef _GNU_SOURCE
  sincosf(thetai, &dc[0], &dc[1]);
#else
  dc[0] = sin(thetai);
  dc[1] = cos(thetai);
#endif
}

/*!
@brief Normalize double precision angle in degrees

@param normalizes degrees to be between 0 and 360 degrees
*/
inline double ksl_normalizeDegrees(double angle) {
  return (angle - floor(angle / 360.0) * 360.0);
}

/*!
@brief Normalize single precision angle in degrees

@param normalizes degrees to be between 0 and 360 degrees
*/
inline float ksl_normalizeDegreesf(float angle) {
  return (angle - floor(angle / 360.0) * 360.0);
}

/*!
@brief Normalize angle in radians

@param normalizes double precision radians to be between 0 and 2 * PI radians
*/
double ksl_normalizeRadians(double angle) {
  const double twopi = 2.0 * M_PI;
  return (angle - floor(angle / twopi) * twopi);
}

/*!
@brief Normalize angle in radians

@param normalizes single precision radians to be between 0 and 2 * PI radians
*/
float ksl_normalizeRadiansf(float angle) {
  const float twopi = 2.0 * M_PI;
  return (angle - floor(angle / twopi) * twopi);
}

/*!
@brief returns a continuous double precision angle obtained from atan2(y, x)

Caution: atan2(y,x) will return an angle with +-2m*pi accuracy only if the
sign on x and y are both correct. If x and y are both off by (-1) then
atan2 will return an angle with accuracy of only +-m*pi. If the sign of
x and y are uncertain, use the alternate function, catan1pi.

This function returns a continuous angle obtained from the standard math
atan2(y,x) function. On input, the argument theta contains the
previous value associated with the angle that is being computed.
catan2() adjusts the value returned from atan2(), so it will be as close to
theta as possible. The assumption is that the current value to be returned
by catan2() is not more than (+-)pi/4 from the previous value. This should
be a valid assumption, because angles generally don't change very fast over
the course of a simulation. Both input arguments x and y must have the
correct sign for catan2pi to work correctly.

*/
double catan2pi(const double y, const double x, double theta) {

  double temp;
  double a;

  /* temp holds the exact current angle, but it may be off by multiples of 2*pi.
  so it is brought closer to theta by adding multiples of 2*pi obtained from
  theta. */
  const double twopi = 2.0 * M_PI;
  temp = atan2(y, x) + twopi * floor(theta / twopi);

  /* temp might still be a 2*pi increment above the desired angle.
  a is the upper limit for the current angle. Add QUARTER_PI to bracket the
  current angle. */
  a = theta + M_PI_4;

  /* Decrement the angle until it is below this upper limit if necessary. */
  while(temp > a) {
    temp -= twopi;
  }

  /* Or temp may be a 2*pi increment below the desired angle.
  Now a is the lower limit for the current angle. Subtract QUARTER_PI
  to bracket the current angle. */
  a = theta - M_PI_4;

  /* Increment the angle until it is above this lower limit if necessary. */
  while(temp < a) {
    temp += twopi;
  }

  /* Now the true angle is bracketed by theta - pi/4 and theta + pi/4. */
  return temp;
}

/*!
@brief returns a continuous single precision angle obtained from atan2(y, x)

Caution: atan2(y,x) will return an angle with +-2m*pi accuracy only if the
sign on x and y are both correct. If x and y are both off by (-1) then
atan2 will return an angle with accuracy of only +-m*pi. If the sign of
x and y are uncertain, use the alternate function, catan1pi.

This function returns a continuous angle obtained from the standard math
atan2(y,x) function. On input, the argument theta contains the
previous value associated with the angle that is being computed.
catan2() adjusts the value returned from atan2(), so it will be as close to
theta as possible. The assumption is that the current value to be returned
by catan2() is not more than (+-)pi/4 from the previous value. This should
be a valid assumption, because angles generally don't change very fast over
the course of a simulation. Both input arguments x and y must have the
correct sign for catan2pi to work correctly.

*/
float catan2pif(const float y, const float x, float theta) {
  float temp;
  float a;

  /* temp holds the exact current angle, but it may be off by multiples of 2*pi.
  so it is brought closer to theta by adding multiples of 2*pi obtained from
  theta. */
  const float twopi = 2.0 * M_PI;
  temp = atan2(y, x) + twopi * floor(theta / twopi);

  /* temp might still be a 2*pi increment above the desired angle.
  a is the upper limit for the current angle. Add QUARTER_PI to bracket the
  current angle. */
  a = theta + M_PI_4;

  /* Decrement the angle until it is below this upper limit if necessary. */
  while(temp > a) {
    temp -= twopi;
  }

  /* Or temp may be a 2*pi increment below the desired angle.
  Now a is the lower limit for the current angle. Subtract QUARTER_PI
  to bracket the current angle. */
  a = theta - M_PI_4;

  /* Increment the angle until it is above this lower limit if necessary. */
  while(temp < a) {
    temp += twopi;
  }

  /* Now the true angle is bracketed by theta - pi/4 and theta + pi/4. */
  return temp;
}

/*!
@brief returns a continuous double precision angle from the atan2(y, x) function

Caution: atan2(y,x) will return an angle with +-2m*pi accuracy only if the
sign on x and y are both correct. If x and y are both off by (-1) then
atan2 will return an angle with accuracy of only +-m*pi. If the sign of
x and y are certain, this or the alternate function, catan2pi will work.
If the sign of x and y are uncertain, do not use catan2pi.
This function returns a continuous angle from the standard
math atan2(y,x) function. On input, the argument theta contains
the previous value associated with the angle that is being computed.
catan2() adjusts the value returned from atan2(), so it will be as close to
theta as possible. The assumption is that the current value to be returned
by catan2() is not more than (+-)pi/4 from the previous value. This should
be a valid assumption, because angles generally don't change very fast over
the course of a simulation. Both input arguments x and y must either
have the correct sign or be off by the same sign for catan1pia() to work
correctly.
*/
double catan1pi(const double y, const double x, double theta) {

  double temp;
  double a;

  /* temp holds the exact current angle, but it may be off by multiples of pi.
  so it is brought closer to theta by adding multiples of pi obtained from
  theta. */
  temp = atan2(y, x) + M_PI * floor(theta / M_PI);

  /* temp might still be one or more pi increments above the desired angle.
  a is the upper limit for the current angle. Add QUARTER_PI to bracket
  the current angle. */
  a = theta + M_PI_4;

  /* Decrement the angle until it is below this upper limit if necessary. */
  while(temp > a) {
    temp -= M_PI;
  }

  /* Or temp may be one or more pi increments below the desired angle.
  Now a is the lower limit for the current angle. Subtract QUARTER_PI
  to bracket the current angle. */
  a = theta - M_PI_4;

  /* Increment the angle until it is above this lower limit if necessary. */
  while(temp < a) {
    temp += M_PI;
  }

  /* Now the true angle is bracketed by theta - pi/4 and theta + pi/4. */
  return temp;
}

/*!
@brief returns a continuous single precision angle from the atan2(y, x) function

Caution: atan2(y,x) will return an angle with +-2m*pi accuracy only if the
sign on x and y are both correct. If x and y are both off by (-1) then
atan2 will return an angle with accuracy of only +-m*pi. If the sign of
x and y are certain, this or the alternate function, catan2pi will work.
If the sign of x and y are uncertain, do not use catan2pi.
This function returns a continuous angle from the standard
math atan2(y,x) function. On input, the argument theta contains
the previous value associated with the angle that is being computed.
catan2() adjusts the value returned from atan2(), so it will be as close to
theta as possible. The assumption is that the current value to be returned
by catan2() is not more than (+-)pi/4 from the previous value. This should
be a valid assumption, because angles generally don't change very fast over
the course of a simulation. Both input arguments x and y must either
have the correct sign or be off by the same sign for catan1pia() to work
correctly.
*/
float catan1pif(const float y, const float x, float theta) {

  float temp;
  float a;

  /* temp holds the exact current angle, but it may be off by multiples of pi.
  so it is brought closer to theta by adding multiples of pi obtained from
  theta. */
  temp = atan2(y, x) + M_PI * floor(theta / M_PI);

  /* temp might still be one or more pi increments above the desired angle.
  a is the upper limit for the current angle. Add QUARTER_PI to bracket
  the current angle. */
  a = theta + M_PI_4;

  /* Decrement the angle until it is below this upper limit if necessary. */
  while(temp > a) {
    temp -= M_PI;
  }

  /* Or temp may be one or more pi increments below the desired angle.
  Now a is the lower limit for the current angle. Subtract QUARTER_PI
  to bracket the current angle. */
  a = theta - M_PI_4;

  /* Increment the angle until it is above this lower limit if necessary. */
  while(temp < a) {
    temp += M_PI;
  }

  /* Now the true angle is bracketed by theta - pi/4 and theta + pi/4. */
  return temp;
}
