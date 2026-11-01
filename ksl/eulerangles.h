/**
@file
@author Kristopher Wehage, Roger Wehage
@brief Utilities to support orientation as a sequence of three angles
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
#ifndef _KSL_EULERANGLES_H_
#define _KSL_EULERANGLES_H_

#include "ksl/types.h"

#include "axis.h"
#include "vec3.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
@brief A sequence of three double precision Euler angles and the axis order
they are applied in.
*/
typedef struct {
  ksl_vec3_t angles;    /*!< the three angles, in radians */
  ksl_axis_enum_t axis; /*!< rotation sequence, e.g. KSL_AXIS_ZYX */
} ksl_eulerangles_t;

/*!
@brief Single precision version of ksl_eulerangles_t.
*/
typedef struct {
  ksl_vec3f_t angles;   /*!< the three angles, in radians */
  ksl_axis_enum_t axis; /*!< rotation sequence, e.g. KSL_AXIS_ZYX */
} ksl_euleranglesf_t;

#ifdef __cplusplus
}
#endif

#endif
