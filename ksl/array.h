/**
@file
@author Kristopher Wehage, Roger Wehage
@brief Additional math utilities for KSL library
@date 2018
@copyright Kristopher Wehage 2018-2026

@remark
THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
SUCH DAMAGE.
*/
#ifndef _KSL_ARRAY_H_
#define _KSL_ARRAY_H_

#include "ksl/types.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

static inline void ksl_swap(double* a, double* b);

static inline void ksl_swapf(float* a, float* b);

static inline void ksl_swapi(int* a, int* b);

static inline void ksl_axpy(const int, const double, const double*, double*);

static inline void ksl_axpyf(const int, const float, const float*, float*);

bool ksl_allclose(const int count, const double* a1, const double* a2);

bool ksl_allclosef(const int count, const float* a1, const float* a2);

static inline bool ksl_allclosei(const int count, const int* a1, const int* a2);

static inline void ksl_arraylerp(const int count, const double p,
                                 const double* y1i, const double* y2i,
                                 double* yo);

static inline void ksl_arraylerpf(const int count, const float p,
                                  const float* y1i, const float* y2i,
                                  float* yo);

/*!
@brief Return the index of the entry with the largest absolute value in an
array.

@param n [in] number of entries, at least 1
@param a [in] array of n entries
@return index of the first entry with the largest absolute value
*/
static inline int ksl_maxIndex(const int n, const double* a);

/*!
@brief Swap the entries of two strided arrays.

Swaps a[i * a_stride] with b[i * b_stride] for i = 0 to n-1, so it can swap rows
or columns of a matrix.

@param n [in] number of entries to swap
@param a [in,out] first array
@param a_stride [in] distance between consecutive entries of a
@param b [in,out] second array
@param b_stride [in] distance between consecutive entries of b
*/
static inline void ksl_swapArray(const int n, double* a, const int a_stride,
                                 double* b, const int b_stride);

#ifdef __cplusplus
}
#endif

/* -------- inline definitions -------- */

#include <assert.h>
#include <math.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

/*!
@brief swap two doubles
*/
static inline void ksl_swap(double* KSL_RESTRICT a, double* KSL_RESTRICT b) {
  double temp = *a;
  *a = *b;
  *b = temp;
}

/*!
@brief swap two integers
*/
static inline void ksl_swapi(int* KSL_RESTRICT a, int* KSL_RESTRICT b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

/*!
@brief swap two floats
*/
static inline void ksl_swapf(float* KSL_RESTRICT a, float* KSL_RESTRICT b) {
  double temp = *a;
  *a = *b;
  *b = temp;
}

/*!
@brief y += a * x for double precision arrays with unit stride
*/
static inline void ksl_axpy(const int n, const double a,
                            const double* KSL_RESTRICT x,
                            double* KSL_RESTRICT y) {
  for(int i = 0; i < n; i++) {
    y[i] += a * x[i];
  }
}

/*!
@brief y += a * x for single precision arrays with unit stride
*/
static inline void ksl_axpyf(const int n, const float a,
                             const float* KSL_RESTRICT x,
                             float* KSL_RESTRICT y) {
  for(int i = 0; i < n; i++) {
    y[i] += a * x[i];
  }
}

/*!
@brief used to determine if two int arrays are equal to each other

@param count [in] number of entries in array
@param a1 [in] first int array
@param a2 [in] second int array
@returns true if all pairs are close, false at the first pair not close
*/
static inline bool ksl_allclosei(const int count, const int* KSL_RESTRICT a1,
                                 const int* KSL_RESTRICT a2) {

  for(int i = 0; i < count; i++) {
    if(a1[i] != a2[i]) {
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
static inline void ksl_arraylerp(const int count, const double p,
                                 const double* KSL_RESTRICT y1i,
                                 const double* KSL_RESTRICT y2i,
                                 double* KSL_RESTRICT yo) {

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
static inline void ksl_arraylerpf(const int count, const float p,
                                  const float* KSL_RESTRICT y1i,
                                  const float* KSL_RESTRICT y2i,
                                  float* KSL_RESTRICT yo) {

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
static inline void ksl_swapArray(const int n, double* KSL_RESTRICT a,
                                 const int a_stride, double* KSL_RESTRICT b,
                                 const int b_stride) {
  for(int i = 0; i < n; i++) {
    ksl_swap(a + i * a_stride, b + i * b_stride);
  }
}

/*
n: Number of entries in array a.
a: Array in which to locate index of absolutely largest entry.
Return index of absolutely largest entry in a.
*/
static inline int ksl_maxIndex(const int n, const double* KSL_RESTRICT a) {
  double max = fabs(a[0]);
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

#ifdef __cplusplus
}
#endif

#endif
