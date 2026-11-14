#include <math.h>
#include <stdbool.h>

#include "ksl/array.h"
#include "ksl/axis.h"
#include "ksl/mat3x3.h"
#include "ksl/matrix.h"

/*!
@brief convert ksl_axis_enum_t to a vector of ints
*/
ksl_vec3i_t ksl_axis_getVector(ksl_axis_enum_t axisType) {

  switch(axisType) {
    case KSL_AXIS_XYZ: {
      return ksl_vec3i(0, 1, 2);
    }
    case KSL_AXIS_YZX: {
      return ksl_vec3i(1, 2, 0);
    }
    case KSL_AXIS_ZXY: {
      return ksl_vec3i(2, 0, 1);
    }
    case KSL_AXIS_XZY: {
      return ksl_vec3i(0, 2, 1);
    }
    case KSL_AXIS_YXZ: {
      return ksl_vec3i(1, 0, 2);
    }
    case KSL_AXIS_ZYX: {
      return ksl_vec3i(2, 1, 0);
    }
    case KSL_AXIS_XYX: {
      return ksl_vec3i(0, 1, 0);
    }
    case KSL_AXIS_XZX: {
      return ksl_vec3i(0, 2, 0);
    }
    case KSL_AXIS_YXY: {
      return ksl_vec3i(1, 0, 1);
    }
    case KSL_AXIS_YZY: {
      return ksl_vec3i(1, 2, 1);
    }
    case KSL_AXIS_ZXZ: {
      return ksl_vec3i(2, 0, 2);
    }
    case KSL_AXIS_ZYZ: {
      return ksl_vec3i(2, 1, 2);
    }
    default: { return ksl_vec3i(0, 1, 2); }
  }
}

ksl_axis_enum_t ksl_axis_getEulerAngles(ksl_vec3i_t angles) {
  ksl_vec3i_t valid_angles[12] = {

    {{{0, 1, 2}}}, {{{1, 2, 0}}}, {{{2, 0, 1}}}, {{{0, 2, 1}}},
    {{{1, 0, 2}}}, {{{2, 1, 0}}}, {{{0, 1, 0}}}, {{{0, 2, 0}}},
    {{{1, 0, 1}}}, {{{1, 2, 1}}}, {{{2, 0, 2}}}, {{{2, 1, 2}}}};
  int match = -1;
  for(int i = 0; i < 12; i++) {
    if(ksl_vec3i_isEqual(&angles, valid_angles + i)) {
      match = i;
      break;
    }
  }
  if(match > -1) {
    return match;
  } else {
    return KSL_AXIS_INVALID;
  }
}

void ksl_axis_getEulerRateMatrix(const ksl_axis_enum_t axisType,
                                 const ksl_vec3_t* restrict angles,
                                 ksl_mat3x3_t* restrict E) {
  const ksl_vec3i_t axes = ksl_axis_getVector(axisType);
  ksl_vec3_t ui = ksl_vec3(0.0, 0.0, 0.0), uj = ui, uk = ui;
  ui.at[axes.at[0]] = 1.0;
  uj.at[axes.at[1]] = 1.0;
  uk.at[axes.at[2]] = 1.0;
  ksl_mat3x3_t ri, rj;
  ksl_mat3x3_setFromAxisAngle(&ri, &ui, angles->at[0]);
  ksl_mat3x3_setFromAxisAngle(&rj, &uj, angles->at[1]);
  ksl_vec3_t c1, t, c2;
  ksl_product_drv(&ri, &uj, &c1);
  ksl_product_drv(&rj, &uk, &t);
  ksl_product_drv(&ri, &t, &c2);
  for(int r = 0; r < 3; r++) {
    E->at[0][r] = ui.at[r];
    E->at[1][r] = c1.at[r];
    E->at[2][r] = c2.at[r];
  }
}

void ksl_axis_eulerRatesToOmega(const ksl_axis_enum_t axisType,
                                const ksl_vec3_t* restrict angles,
                                const ksl_vec3_t* restrict rates,
                                ksl_vec3_t* restrict omega) {
  ksl_mat3x3_t E;
  ksl_axis_getEulerRateMatrix(axisType, angles, &E);
  ksl_product_drv(&E, rates, omega);
}

int ksl_axis_omegaToEulerRates(const ksl_axis_enum_t axisType,
                               const ksl_vec3_t* restrict angles,
                               const ksl_vec3_t* restrict omega,
                               ksl_vec3_t* restrict rates) {
  /* with the columns e0, e1, e2 of E and d = e0 . (e1 x e2), the rows of
  E^-1 are (e1 x e2) / d, (e2 x e0) / d and (e0 x e1) / d */
  ksl_mat3x3_t E;
  ksl_axis_getEulerRateMatrix(axisType, angles, &E);
  ksl_vec3_t c12, c20, c01;
  ksl_cross_vv(&E.v1, &E.v2, &c12);
  ksl_cross_vv(&E.v2, &E.v0, &c20);
  ksl_cross_vv(&E.v0, &E.v1, &c01);
  const double d = ksl_dot_vv(&E.v0, &c12);
  if(fabs(d) < 1e-12) {
    return 1;
  }
  rates->at[0] = ksl_dot_vv(&c12, omega) / d;
  rates->at[1] = ksl_dot_vv(&c20, omega) / d;
  rates->at[2] = ksl_dot_vv(&c01, omega) / d;
  return 0;
}
