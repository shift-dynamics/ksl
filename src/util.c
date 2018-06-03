#include <util.h>

/*!
@brief swap two doubles
*/
inline void ksl_swap(double* restrict a, double* restrict b) {
  double temp = *a;
  *a = *b;
  *b = temp;
}

/*!
@brief swap two integers
*/
inline void ksl_swapi(int* restrict a, int* restrict b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

/*!
@brief swap two floats
*/
inline void ksl_swapf(float* restrict a, float* restrict b) {
  double temp = *a;
  *a = *b;
  *b = temp;
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

/*!
@brief a non-blas implementation of daxpy for unit stride only
*/
inline void ksl_axpy(const int n, const double a, const double* restrict x,
                     double* restrict y) {
  for(int i = 0; i < n; i++) {
    y[i] += a * x[i];
  }
}

/*!
@brief a non-blas implementation of saxpy for unit stride only
*/
inline void ksl_axpyf(const int n, const float a, const float* restrict x,
                      float* restrict y) {
  for(int i = 0; i < n; i++) {
    y[i] += a * x[i];
  }
}

/*!
@brief used to determine if two double arrays are close to each other
within an error tolerance of 1e-6

@param count [in] number of entries in array
@param a1 [in] first double array
@param a2 [in] second double array
@returns true if all pairs are close, false at the first pair not close
*/
bool ksl_allclose(const int count, const double* restrict a1,
                  const double* restrict a2) {

  for(int i = 0; i < count; i++) {
    double scaleFactor = fmax(fabs(a1[i]), 1.0);
    if(fabs(a1[i] - a2[i]) / scaleFactor > 1e-6) {
      fprintf(stdout, "match failed at index: %d\n", i);
      return false;
    }
  }
  return true;
}

/*!
@brief used to determine if two single precision arrays are close to each other
within an error tolerance of 1e-6

@param count [in] number of entries in array
@param a1 [in] first float array
@param a2 [in] second float array
@returns true if all pairs are close, false at the first pair not close
*/
bool ksl_allclosef(const int count, const float* restrict a1,
                   const float* restrict a2) {

  for(int i = 0; i < count; i++) {
    double scaleFactor = fmax(fabs(a1[i]), 1.0);
    if(fabs(a1[i] - a2[i]) / scaleFactor > 1e-6) {
      fprintf(stdout, "match failed at index: %d\n", i);
      return false;
    }
  }
  return true;
}

/*!
@brief used to determine if two int arrays are equal to each other

@param count [in] number of entries in array
@param a1 [in] first int array
@param a2 [in] second int array
@returns true if all pairs are close, false at the first pair not close
*/
bool ksl_allclosei(const int count, const int* restrict a1,
                   const int* restrict a2) {

  for(int i = 0; i < count; i++) {
    if(a1[i] != a2[i]) {
      fprintf(stdout, "match failed at index: %d\n", i);
      return false;
    }
  }
  return true;
}

/*!
@brief linear interpolation

@param count [in] number of entries to interpolate
@param p [in] interpolant value, ranges from 0 to 1
@param y1i [in] value of function at p = 0
@param y2i [in] value of function at p = 1
@param yo [out] interpolated data returned in yo

*/
void ksl_arraylerp(const int count, const double p, const double* restrict y1i,
                   const double* restrict y2i, double* restrict yo) {

  if(p < 1e-9) {
    memcpy(yo, y1i, count * sizeof(double));
    return;
  } else if(p >= 1.0) {
    memcpy(yo, y2i, count * sizeof(double));
    return;
  }

  for(int i = 0; i < count; i++) {
    yo[i] = y1i[i] + p * (y2i[i] - y1i[i]);
  }
  return;
}

/*!
@brief linear interpolation

@param count [in] number of entries to interpolate
@param p [in] interpolant value, ranges from 0 to 1
@param y1i [in] value of function at p = 0
@param y2i [in] value of function at p = 1
@param yo [out] interpolated data returned in yo

*/
void ksl_arraylerpf(const int count, const float p, const float* restrict y1i,
                    const float* restrict y2i, float* restrict yo) {

  if(p < 1e-9) {
    memcpy(yo, y1i, count * sizeof(float));
    return;
  } else if(p >= 1.0) {
    memcpy(yo, y2i, count * sizeof(float));
    return;
  }

  for(int i = 0; i < count; i++) {
    yo[i] = y1i[i] + p * (y2i[i] - y1i[i]);
  }
  return;
}
