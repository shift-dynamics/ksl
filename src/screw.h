/**
@file
@author Kristopher Wehage, Roger Wehage
@brief Utilities to initialize and operate on quaternions
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

#ifndef _KSL_SCREW_H_
#define _KSL_SCREW_H_

#include "vector.h"

/*!
@brief screw quantities consist of a linear and angular vector pair in
configuration space
*/
typedef union ksl_screw_t {
  double at[6];
  struct {
    ksl_vec3_t lin; /*!< bound linear vector, e.g. linear velocity or
                            acceleration */
    ksl_vec3_t ang; /*!< free angular vector, e.g. angular velocity or
                             angular acceleration (\omega, or \dot{\omega}) */
  };
} ksl_screw_t;

/*!
@brief Coscrews are linear operators on screws. Coscrews consist of a linear and
angular vector pair in function space.
*/
typedef union ksl_coscrew_t {
  double at[6];
  struct {
    ksl_vec3_t lin; /*!< free linear vector, e.g. force or linear
                         momentum */
    ksl_vec3_t ang; /*!< bound angular vector, e.g. moment/torque
                         or angular momentum*/
  };
} ksl_coscrew_t;

#endif
