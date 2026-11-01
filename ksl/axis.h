/**
@file
@author Kristopher Wehage, Roger Wehage
@brief Utilities related to axes to support KSL datastructures
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
#ifndef _KSL_AXIS_H_
#define _KSL_AXIS_H_

#include "ksl/types.h"

#include "vec3.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
@brief Order of the three rotation axes in an Euler angle sequence. The
comment after each value gives the axis indices (0 = x, 1 = y, 2 = z).
*/
typedef enum {
  KSL_AXIS_XYZ = 0, // 012
  KSL_AXIS_YZX,     // 120
  KSL_AXIS_ZXY,     // 201
  KSL_AXIS_XZY,     // 021
  KSL_AXIS_YXZ,     // 102
  KSL_AXIS_ZYX,     // 210
  KSL_AXIS_XYX,     // 010
  KSL_AXIS_XZX,     // 020
  KSL_AXIS_YXY,     // 101
  KSL_AXIS_YZY,     // 121
  KSL_AXIS_ZXZ,     // 202
  KSL_AXIS_ZYZ,     // 212
  KSL_AXIS_INVALID
} ksl_axis_enum_t;

ksl_vec3i_t ksl_axis_getVector(ksl_axis_enum_t axisType);

/*!
@brief Look up the Euler angle sequence for a triple of axis indices.

@param angles [in] the axes of the three rotations, 0 = x, 1 = y, 2 = z; for
example {2, 1, 0} for z-y-x
@return the matching ksl_axis_enum_t value, or KSL_AXIS_INVALID if the triple is
not one of the 12 valid sequences
*/
ksl_axis_enum_t ksl_axis_getEulerAngles(ksl_vec3i_t angles);

#ifdef __cplusplus
}
#endif

#endif
