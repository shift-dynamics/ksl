/**
@file
@author Kristopher Wehage, Roger Wehage
@brief Utilities to print KSL datastructures
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

#ifndef _KSL_PRINT_H_
#define _KSL_PRINT_H_

#include <stdio.h>

#include "inertia.h"
#include "matrix.h"
#include "quaternion.h"
#include "screw.h"
#include "vector.h"

void ksl_vec3_print(FILE* f, const ksl_vec3_t* vi);

void ksl_vec3f_print(FILE* f, const ksl_vec3f_t* vi);

void ksl_quaternion_print(FILE* f, const ksl_quaternion_t* qi);

void ksl_quaternionf_print(FILE* f, const ksl_quaternionf_t* qi);

void ksl_screw_print(FILE* f, const ksl_screw_t* si);

void ksl_screwf_print(FILE* f, const ksl_screw_t* si);

void ksl_mat3x3_print(FILE* f, ksl_mat3x3_t* r);

void ksl_mat3x3f_print(FILE* f, ksl_mat3x3f_t* r);

void ksl_displacement_print(FILE* f, ksl_SE3_t* d);

void ksl_mat4x4_print(FILE* f, ksl_mat4x4_t* d);

void ksl_mat4x4f_print(FILE* f, ksl_mat4x4f_t* d);

void ksl_array_print(FILE* f, int n, double* a);

void ksl_array_print2D(FILE* f, int rowDim, int colDim, bool isRowMajor,
                       double* a);

void ksl_arrayi_print(FILE* f, int n, int* a);

void ksl_triang_print(FILE* f, int n, double* a);

void ksl_triangi_print(FILE* f, int n, int* a);

void ksl_triangb_print(FILE* f, int n, bool* a);

void ksl_inertia_print(FILE* f, ksl_inertia_t* inertia);

#endif
