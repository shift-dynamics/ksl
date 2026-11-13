#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "ksl/vec3.h"

/*!
@brief initialize n ksl_vec3_t double precision vectors datastructures on the
heap
*/
inline ksl_vec3_t* ksl_vec3_alloc(int n) {
  return calloc(n, sizeof(ksl_vec3_t));
}

/*!
@brief initialize n ksl_vec3f_t single precision vectors datastructures on the
heap
*/
inline ksl_vec3f_t* ksl_vec3f_alloc(int n) {
  return calloc(n, sizeof(ksl_vec3f_t));
}

/*!
@brief initialize n ksl_vec3i_t vectors of integers on the heap
*/
inline ksl_vec3i_t* ksl_vec3i_alloc(int n) {
  return calloc(n, sizeof(ksl_vec3i_t));
}

/*!
@brief Computes the single precision product of a vector and 1/scalar

Note: this function does not check for divide by zero.

\f$V_i * 1 / k_i \rightarrow V_o\f$

@param vi [in] A 3x1 input vector
@param ki [in] a double precision scalar
@param vo [out] the results are returned in vo
*/
void ksl_product_ainvvf(const ksl_vec3f_t* restrict vi, const float ki,
                        ksl_vec3f_t* restrict vo) {
  register float inv = 1.0 / ki;
  vo->x = inv * vi->x;
  vo->y = inv * vi->y;
  vo->z = inv * vi->z;
}


/* -------- cubic splines through key points -------- */

/* Both splines solve a symmetric tridiagonal system with ones beside the
diagonal by its LDL^T factors: pivots d_0 = a_0, d_i = a_i - 1 / d_i-1, forward
substitution with l_i = 1 / d_i-1, division by the pivots, and back
substitution with the same l_i. */

void ksl_vec3_spline_natural(const int n, const ksl_vec3_t* restrict keys,
                             ksl_vec3_t* restrict m, double* restrict work) {
  m[0] = ksl_vec3(0.0, 0.0, 0.0);
  m[n - 1] = m[0];
  if(n < 3) {
    return;
  }
  /* unknowns m_1, ..., m_n-2, with the right sides first stored in their
  place; the pivots go in work[0..n-3] */
  for(int k = 1; k < n - 1; k++) {
    for(int c = 0; c < 3; c++) {
      m[k].at[c] =
        6.0 * (keys[k + 1].at[c] - 2.0 * keys[k].at[c] + keys[k - 1].at[c]);
    }
  }
  const int u = n - 2;
  /* pivots of the constant diagonal 4: d_0 = 4, d_i = 4 - 1 / d_i-1 */
  work[0] = 4.0;
  for(int i = 1; i < u; i++) {
    work[i] = 4.0 - 1.0 / work[i - 1];
  }
  ksl_vec3_t* x = m + 1;
  for(int i = 1; i < u; i++) {
    const double l = 1.0 / work[i - 1];
    for(int c = 0; c < 3; c++) {
      x[i].at[c] -= l * x[i - 1].at[c];
    }
  }
  for(int i = 0; i < u; i++) {
    for(int c = 0; c < 3; c++) {
      x[i].at[c] /= work[i];
    }
  }
  for(int i = u - 2; i >= 0; i--) {
    const double l = 1.0 / work[i];
    for(int c = 0; c < 3; c++) {
      x[i].at[c] -= l * x[i + 1].at[c];
    }
  }
}

void ksl_vec3_spline_clamped(const int n, const ksl_vec3_t* restrict keys,
                             const ksl_vec3_t* restrict v0,
                             const ksl_vec3_t* restrict vn,
                             ksl_vec3_t* restrict m, double* restrict work) {
  /* unknowns m_0, ..., m_n-1; diagonal 2, 4, ..., 4, 2 */
  for(int c = 0; c < 3; c++) {
    m[0].at[c] = 6.0 * (keys[1].at[c] - keys[0].at[c] - v0->at[c]);
    m[n - 1].at[c] =
      6.0 * (vn->at[c] - keys[n - 1].at[c] + keys[n - 2].at[c]);
  }
  for(int k = 1; k < n - 1; k++) {
    for(int c = 0; c < 3; c++) {
      m[k].at[c] =
        6.0 * (keys[k + 1].at[c] - 2.0 * keys[k].at[c] + keys[k - 1].at[c]);
    }
  }
  /* the diagonal is written into work and replaced by the pivots */
  for(int i = 0; i < n; i++) {
    work[i] = (i == 0 || i == n - 1) ? 2.0 : 4.0;
  }
  for(int i = 1; i < n; i++) {
    const double l = 1.0 / work[i - 1];
    work[i] -= l;
    for(int c = 0; c < 3; c++) {
      m[i].at[c] -= l * m[i - 1].at[c];
    }
  }
  for(int i = 0; i < n; i++) {
    for(int c = 0; c < 3; c++) {
      m[i].at[c] /= work[i];
    }
  }
  for(int i = n - 2; i >= 0; i--) {
    const double l = 1.0 / work[i];
    for(int c = 0; c < 3; c++) {
      m[i].at[c] -= l * m[i + 1].at[c];
    }
  }
}

void ksl_vec3_spline(const int n, const ksl_vec3_t* restrict keys,
                     const ksl_vec3_t* restrict m, const double* restrict t,
                     ksl_vec3_t* restrict po, ksl_vec3_t* restrict dpo,
                     ksl_vec3_t* restrict ddpo) {
  double tc = *t;
  if(!(tc > 0.0)) {
    tc = 0.0;
  }
  if(tc > n - 1) {
    tc = n - 1;
  }
  int k = (int)floor(tc);
  if(k > n - 2) {
    k = n - 2;
  }
  const double u = tc - k, v = 1.0 - u;
  const double a = (v * v * v - v) / 6.0, b = (u * u * u - u) / 6.0;
  const double da = -(3.0 * v * v - 1.0) / 6.0, db = (3.0 * u * u - 1.0) / 6.0;
  for(int c = 0; c < 3; c++) {
    const double p0 = keys[k].at[c], p1 = keys[k + 1].at[c];
    const double m0 = m[k].at[c], m1 = m[k + 1].at[c];
    po->at[c] = v * p0 + u * p1 + a * m0 + b * m1;
    if(dpo) {
      dpo->at[c] = p1 - p0 + da * m0 + db * m1;
    }
    if(ddpo) {
      ddpo->at[c] = v * m0 + u * m1;
    }
  }
}
