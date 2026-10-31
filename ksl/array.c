#include <ksl/array.h>

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

