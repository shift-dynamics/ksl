#include <ksl/array.h>

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

/*
n: Number of entries in two arrays to swap.
a: First array to swap.
a_stride: Stride in array a for swap.
b: Second array to swap.
b_stride: Stride in array b for swap.
*/

inline void ksl_swapArray(const int n, double* restrict a, const int a_stride,
                          double* restrict b, const int b_stride) {
  for(int i = 0; i < n; i++) {
    ksl_swap(a + i * a_stride, b + i * b_stride);
  }
}

/*
n: Number of entries in array a.
a: Array in which to locate index of absolutely largest entry.
Return index of absolutely largest entry in a.
*/
inline int ksl_maxIndex(const int n, const double* restrict a) {
  register double max = fabs(a[0]);
  int max_index = 0;
  for(int i = 1; i < n; i++) {
    double a_abs = fabs(a[i]);
    if(a_abs > max) {
      max_index = i;
      max = a_abs;
    }
  }
  return max_index;
}
