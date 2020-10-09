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
#ifndef _KSL_VEC4_H_
#define _KSL_VEC4_H_

#include "vec3.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
@brief double precision 4x1 vector representing a 3x1 vector
with a homogeneous coordinate (w) appended.

Typically used for nonlinear transformations such as camera projections.
*/
typedef union ksl_vec4_t {
  struct {
    double at[4];
  }; /*!< anonymous union allows accessing vector quantities at specified index
      */
  struct {
    union {
      struct {
        ksl_vec3_t r;
      }; /*!< anonymous union allows accessing 3d vector component of 4d vector
          */
      struct {
        double x;
        double y;
        double z;
      }; /*!< anonymous union allows x, y, z vector component of 4d vector by
            descriptive name*/
    };
    double w; /*!< homogeneous coordinate of 4d vector */
  }; /*!< anonymous union allows x, y, z, w vector components of 4d vector by
        descriptive name or 3d vector component */
} ksl_vec4_t;

/*!
@brief single precision 4x1 vector representing a 3x1 vector
with a homogeneous coordinate (w) appended.

Typically used for nonlinear transformations such as camera projections.
*/
typedef union ksl_vec4f_t {
  struct {
    float at[4];
  }; /*!< anonymous union allows accessing vector quantities at specified index
      */
  struct {
    union {
      struct {
        ksl_vec3f_t r;
      }; /*!< anonymous union allows accessing 3d vector component of 4d vector
          */
      struct {
        float x;
        float y;
        float z;
      }; /*!< anonymous union allows x, y, z vector component of 4d vector by
           descriptive name*/
    };
    float w; /*!< homogeneous coordinate of 4d vector */
  }; /*!< anonymous union allows x, y, z, w vector components of 4d vector by
        descriptive name or 3d vector component */
} ksl_vec4f_t;

typedef union ksl_vec4i_t {
  struct {
    int at[4];
  }; /*!< anonymous union allows accessing vector quantities at specified index
      */
  struct {
    union {
      struct {
        ksl_vec3i_t r;
      }; /*!< anonymous union allows accessing 3d vector component of 4d vector
          */
      struct {
        int x;
        int y;
        int z;
      }; /*!< anonymous union allows x, y, z vector component of 4d vector by
           descriptive name*/
    };
    int w; /*!< homogeneous coordinate of 4d vector */
  }; /*!< anonymous union allows x, y, z, w vector components of 4d vector by
        descriptive name or 3d vector component */
} ksl_vec4i_t;

ksl_vec4i_t ksl_vec4i(const int x, const int y, const int z, const int w);

ksl_vec4_t ksl_vec4(const double x, const double y, const double z,
                    const double w);

ksl_vec4f_t ksl_vec4f(const float x, const float y, const float z,
                      const float w);

ksl_vec4_t* ksl_vec4_alloc(int);

ksl_vec4f_t* ksl_vec4f_alloc(int);

ksl_vec4i_t* ksl_vec4i_alloc(int);

double ksl_vec4_l2norm(const ksl_vec4_t* v);

float ksl_vec4f_l2norm(const ksl_vec4f_t* v);

void ksl_vec4_normalize(ksl_vec4_t* v);

void ksl_vec4f_normalize(ksl_vec4f_t* v);

void ksl_vec4_normalized(const ksl_vec4_t* v, ksl_vec4_t* vo);

void ksl_vec4f_normalized(const ksl_vec4f_t* v, ksl_vec4f_t* vo);

void ksl_vec4_scale(ksl_vec4_t* v, const double);

void ksl_vec4f_scale(ksl_vec4f_t* v, const float);

void ksl_vec4_scaled(const ksl_vec4_t* v, const double, ksl_vec4_t* vo);

void ksl_vec4f_scaled(const ksl_vec4f_t* v, const float, ksl_vec4f_t* vo);

void ksl_vec4_copy(const ksl_vec4_t* vi, ksl_vec4_t* vo);

void ksl_vec4f_copy(const ksl_vec4f_t* vi, ksl_vec4f_t* vo);

void ksl_vec4_swap(ksl_vec4_t* v1, ksl_vec4_t* v2);

void ksl_vec4f_swap(ksl_vec4f_t* v1, ksl_vec4f_t* v2);

void ksl_vec4_inverted(const ksl_vec4_t* vi, ksl_vec4_t* vo);

void ksl_vec4_invert(ksl_vec4_t* vi);

void ksl_vec4f_inverted(const ksl_vec4f_t* vi, ksl_vec4f_t* vo);

void ksl_vec4f_invert(ksl_vec4f_t* vi);

#ifdef __cplusplus
}
#endif

#endif
