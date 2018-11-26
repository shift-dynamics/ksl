/**
@file
@author Kristopher Wehage, Roger Wehage
@brief Utilities related to axes to support KSL datastructures
@date 2018
@copyright Kristopher Wehage 2018

@remark
THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
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

#include "vector.h"

#ifdef __cplusplus
extern "C" {
#endif

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

ksl_axis_enum_t ksl_axis_enumFromChar(const char*);

#ifdef __cplusplus
}
#endif

#endif
