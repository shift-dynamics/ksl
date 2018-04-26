/**
@file
@author Kristopher Wehage, Roger Wehage
@brief Utilities to initialize and operate on vectors
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

#ifndef _KSL_VECTOR_H_
#define _KSL_VECTOR_H_

/*!
@brief 3 dimensional double precision vector
*/
typedef union ksl_vec3_t {
  double at[3];
  struct {
    double x;
    double y;
    double z;
  };
} ksl_vec3_t;

/*!
@brief 3 dimensional single precision vector
*/
typedef union ksl_vec3f_t {
  float at[3];
  struct {
    float x;
    float y;
    float z;
  };
} ksl_vec3f_t;

/*!
@brief double precision 4x1 vector representing a 3x1 vector
with a homogeneous coordinate (w) appended.

Typically used for nonlinear transformations such as camera projections.
*/
typedef union ksl_vec4_t {
  double at[4];
  struct {
    union {
      ksl_vec3_t r;
      struct {
        double x;
        double y;
        double z;
      };
    };
    double w;
  };
} ksl_vec4_t;

/*!
@brief single precision 4x1 vector representing a 3x1 vector
with a homogeneous coordinate (w) appended.

Typically used for nonlinear transformations such as camera projections.
*/
typedef union ksl_vec4f_t {
  float at[4];
  struct {
    union {
      ksl_vec3f_t r;
      struct {
        float x;
        float y;
        float z;
      };
    };
    float w;
  };
} ksl_vec4f_t;

#endif
