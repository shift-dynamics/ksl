/**
@file
@author Kristopher Wehage
@date 2019
@copyright Kristopher Wehage 2019
@section DESCRIPTION
This file includes utility routines to dynamically allocate and free memory for
two dimensional arrays

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

#ifndef _KSL_MEMORY_H_
#define _KSL_MEMORY_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*!
@brief Allocates memory for a two dimensional double array

@param int rows in two dimensional array to allocate
@param int columns in two dimensional array to allocate
@return two dimensional double array
*/
double** ksl_array2D_alloc(int rows, int columns);

/*!
@brief Frees memory for a two dimensional double array

*/
void ksl_array2D_free(double** x);

/*!
@brief Allocates memory for a two dimensional single precision array

@param int rows in two dimensional array to allocate
@param int columns in two dimensional array to allocate
@return two dimensional double array
*/
float** ksl_array2Df_alloc(int rows, int columns);

/*!
@brief Frees memory for a two dimensional float array

*/
void ksl_array2Df_free(float** x);

/*!
@brief Allocates memory for a two dimensional integer array

@param int rows in two dimensional array to allocate
@param int columns in two dimensional array to allocate
@return two dimensional integer array
*/
int** ksl_array2Di_alloc(int rows, int columns);

/*!
@brief Free memory for a two dimensional integer array

*/
void ksl_array2Di_free(int** x);

/*!
@brief Allocates memory for a two dimensional integer array

@param int rows in two dimensional array to allocate
@param int columns in two dimensional array to allocate
@return two dimensional integer array
*/
unsigned int** ksl_array2Dui_alloc(int rows, int columns);

/*!
@brief Free memory for a one dimensional unsigned integer array

*/
void ksl_array2Dui_free(unsigned int** x);

/*!
@brief Allocates memory for a two dimensional char array

@param int rows in two dimensional array to allocate
@param int columns in two dimensional array to allocate
@return two dimensional char array
*/
char** ksl_array2Dc_alloc(int rows, int columns);

/*!
@brief Frees memory for a two dimensional double array

*/
void ksl_array2Dc_free(char** x);

/*!
@brief Allocates memory for a two dimensional array of booleans

@param int rows in two dimensional array to allocate
@param int columns in two dimensional array to allocate
@return two dimensional char array
*/
bool** ksl_array2Db_alloc(int rows, int columns);

/*!
@brief Frees memory for a two dimensional array of booleans

*/
void ksl_array2Db_free(bool** x);

/*!
@brief Free memory for a one dimensional double array

*/
void ksl_array_free(double* x);

/*!
@brief Free memory for a one dimensional float array

*/
void ksl_arrayf_free(float* x);

/*!
@brief Free memory for a one dimensional integer array

*/
void ksl_arrayi_free(int* x);

/*!
@brief Free memory for a one dimensional unsigned integer array

*/
void ksl_arrayui_free(unsigned int* x);

/*!
@brief Free memory for a one dimensional boolean array

*/
void ksl_arrayc_free(char* x);

/*!
@brief Free memory for a one dimensional boolean array

*/
void ksl_arrayb_free(bool* x);

#ifdef __cplusplus
}
#endif

#endif
