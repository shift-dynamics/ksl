#include "axis.h"
#include "vector.h"

/*!
@brief convert ksl_axis_enum_t to a vector of ints
*/
ksl_vec3i_t ksl_axis_getVector(ksl_axis_enum_t axisType) {

  switch(axisType) {
    case KSL_AXIS_XYZ: {
      ksl_vec3i_t axis = {{0, 1, 2}};
      return axis;
    }
    case KSL_AXIS_YZX: {
      ksl_vec3i_t axis = {{1, 2, 0}};
      return axis;
    }
    case KSL_AXIS_ZXY: {
      ksl_vec3i_t axis = {{2, 1, 2}};
      return axis;
    }
    case KSL_AXIS_XZY: {
      ksl_vec3i_t axis = {{0, 2, 1}};
      return axis;
    }
    case KSL_AXIS_YXZ: {
      ksl_vec3i_t axis = {{1, 0, 2}};
      return axis;
    }
    case KSL_AXIS_ZYX: {
      ksl_vec3i_t axis = {{2, 1, 0}};
      return axis;
    }
    case KSL_AXIS_XYX: {
      ksl_vec3i_t axis = {{0, 1, 0}};
      return axis;
    }
    case KSL_AXIS_XZX: {
      ksl_vec3i_t axis = {{0, 2, 0}};
      return axis;
    }
    case KSL_AXIS_YXY: {
      ksl_vec3i_t axis = {{1, 0, 1}};
      return axis;
    }
    case KSL_AXIS_YZY: {
      ksl_vec3i_t axis = {{1, 2, 1}};
      return axis;
    }
    case KSL_AXIS_ZXZ: {
      ksl_vec3i_t axis = {{2, 0, 2}};
      return axis;
    }
    case KSL_AXIS_ZYZ: {
      ksl_vec3i_t axis = {{2, 1, 2}};
      return axis;
    }
    default: {
      ksl_vec3i_t axis = {{0, 1, 2}};
      return axis;
    }
  }
}
