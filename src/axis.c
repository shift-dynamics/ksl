#include "ksl/axis.h"

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
