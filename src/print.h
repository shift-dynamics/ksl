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

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>

#include "SE3.h"
#include "eulerangles.h"
#include "inertia.h"
#include "mat3x3.h"
#include "mat4x4.h"
#include "quaternion.h"
#include "screw.h"
#include "vec3.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum ksl_print_breakBetweenLines_enum_t {
  KSL_NO_BREAK_BETWEEN_LINES = 0,
  KSL_BREAK_BETWEEN_LINES
} ksl_print_breakBetweenLines_enum_t;

/*! @brief print formatting options*/
typedef struct ksl_print_options_t {
  char delimiter[100]; /*!< default delimiter, default: ", " */
  char
    real_fmt[100]; /*!< formatting for doubles and floats, default: "%0.6g"  */
  char int_fmt[100];   /*!< formatting for ints: default: "%d" */
  char true_fmt[100];  /*!< formatting for display of true boolean, default:
                          "true" */
  char false_fmt[100]; /*!< formatting for display of false boolean, default:
                          "false" */
  char inner_left_bracket[100];  /*!< default: "[" */
  char inner_right_bracket[100]; /*!< default: "]" */
  char outer_left_bracket[100];  /*!< default: "[" */
  char outer_right_bracket[100]; /*!< default: "]" */
  ksl_print_breakBetweenLines_enum_t line_breaks_in_matrices;
  /*!< default: KSL_BREAK_BETWEEN_LINES */
  ksl_matrix_enum_t print_row_column_major; /*!< default: KSL_ROW_MAJOR */
} ksl_print_options_t;

void ksl_print_setDefaultOptions();

/*!
@brief used to set delimiter used in display of matrices, vectors, screws, etc.
@param delimiter [in]
@param options [in] a pointer to a user-defined ksl_print_options_t struct
containing print options. If this value is NULL or is not present, the option
will be set in the global print settings.
*/
#define ksl_print_setDelimiter(fmt, ...)                                       \
  { ksl_print_setDelimiterOption(fmt, ##__VA_ARGS__, NULL); }

void ksl_print_setDelimiterOption(const char* delimiter, ...);

/*!
@brief used to set format for display of float and double values
@param fmt [in]
@param options [in] a pointer to a user-defined ksl_print_options_t struct
containing print options. If this value is NULL or is not present, the option
will be set in the global print settings.
*/
#define ksl_print_setRealFormat(fmt, ...)                                      \
  { ksl_print_setRealFormatOption(fmt, ##__VA_ARGS__, NULL); }

void ksl_print_setRealFormatOption(const char* fmt, ...);

/*!
@brief used to set inner brackets in dispay of matrices
@param left [in] left bracket
@param right [in] right bracket
@param options [in] a pointer to a user-defined ksl_print_options_t struct
containing print options. If this value is NULL or is not present, the option
will be set in the global print settings.
*/
#define ksl_print_setInnerBrackets(left, right, ...)                           \
  { ksl_print_setInnerBracketsOption(left, right, ##__VA_ARGS__, NULL); }

void ksl_print_setInnerBracketsOption(const char* left, const char* right, ...);

/*!
@brief used to set outer brackets in dispay of matrices
@param left [in] left bracket
@param right [in] right bracket
@param options [in] a pointer to a user-defined ksl_print_options_t struct
containing print options. If this value is NULL or is not present, the option
will be set in the global print settings.
*/
#define ksl_print_setOuterBrackets(left, right, ...)                           \
  { ksl_print_setOuterBracketsOption(left, right, ##__VA_ARGS__, NULL); }

void ksl_print_setOuterBracketsOption(const char* left, const char* right, ...);

/*!
@brief used to set "BreakBetweenLinesInMatrix" option for dispay of matrices
@param val [in] valid inputs are KSL_BREAK_BETWEEN_LINES or
KSL_NO_BREAK_BETWEEN_LINES
@param options [in] a pointer to a user-defined ksl_print_options_t struct
containing print options. If this value is NULL or is not present, the option
will be set in the global print settings.
*/
#define ksl_print_setBreakBetweenLinesInMatrix(val, ...)                       \
  { ksl_print_setBreakBetweenLinesInMatrixOption(val, ##__VA_ARGS__, NULL); }

void ksl_print_setBreakBetweenLinesInMatrixOption(
  ksl_print_breakBetweenLines_enum_t val, ...);

/*!
@brief used to set "BreakBetweenLinesInMatrix" option for dispay of matrices
@param val [in] valid inputs are KSL_BREAK_BETWEEN_LINES or
KSL_NO_BREAK_BETWEEN_LINES
@param options [in] a pointer to a user-defined ksl_print_options_t struct
containing print options. If this value is NULL or is not present, the option
will be set in the global print settings.
*/
#define ksl_print_setBoolean(True, False, ...)                                 \
  { ksl_print_setBooleanOption(True, False, ##__VA_ARGS__, NULL); }
void ksl_print_setBooleanOption(const char* True, const char* False, ...);

/*!
@brief used to set "RowColumnMajorPrinting" option for dispay of matrices
@param val [in] valid inputs are KSL_ROW_MAJOR or KSL_COLUMN_MAJOR
@param options [in] a pointer to a user-defined ksl_print_options_t struct
containing print options. If this value is NULL or is not present, the option
will be set in the global print settings.
*/
#define ksl_print_setRowColumnMajorPrinting(val, ...)                          \
  { ksl_print_setRowColumnMajorPrintingOption(val, ##__VA_ARGS__, NULL); }

void ksl_print_setRowColumnMajorPrintingOption(
  ksl_matrix_enum_t print_row_column_major, ...);

ksl_print_options_t* ksl_print_options();

/*!
@brief "debug" print a ksl_vec3_t data structure. If NDEBUG is defined, this
function is converted to a no-op and nothing will be output. If it is desired
to print a ksl_vec3_t in release mode, use the ksl_vec3_print function.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_vec3_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#ifdef NDEBUG
#define ksl_vec3_debug(f, v, ...)                                              \
  do {                                                                         \
  } while(0)
#else
#define ksl_vec3_debug(f, v, ...)                                              \
  { ksl_vec3_printWithOptions(f, v, ##__VA_ARGS__, NULL, NULL); }
#endif

/*!
@brief print a ksl_vec3_t data structure.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_vec3_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options. To pass an options struct with no label, call
ksl_vec3_print(f, v, NULL, options); or ksl_vec3_print(f, v, "", options);
*/
#define ksl_vec3_print(f, v, ...)                                              \
  { ksl_vec3_printWithOptions(f, v, ##__VA_ARGS__, NULL, NULL); }

void ksl_vec3_printWithOptions(FILE* f, const ksl_vec3_t* v, ...);

/*!
@brief "debug" print a ksl_vec3f_t data structure. If NDEBUG is defined, this
function is converted to a no-op and nothing will be output. If it is desired
to print a ksl_vec3f_t in release mode, use the ksl_vec3f_print function.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_vec3f_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#ifdef NDEBUG
#define ksl_vec3f_debug(f, v, ...)                                             \
  do {                                                                         \
  } while(0)
#else
#define ksl_vec3f_debug(f, v, ...)                                             \
  { ksl_vec3f_printWithOptions(f, v, ##__VA_ARGS__, NULL, NULL); }
#endif

/*!
@brief print a ksl_vec3f_t data structure.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_vec3f_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options. To pass an options struct with no label, call
ksl_vec3f_print(f, v, NULL, options); or ksl_vec3f_print(f, v, "", options);
*/
#define ksl_vec3f_print(f, v, ...)                                             \
  { ksl_vec3f_printWithOptions(f, v, ##__VA_ARGS__, NULL, NULL); }

void ksl_vec3f_printWithOptions(FILE* f, const ksl_vec3f_t* vi, ...);

/*!
@brief "debug" print a ksl_vec4_t data structure. If NDEBUG is defined, this
function is converted to a no-op and nothing will be output. If it is desired
to print a ksl_vec4_t in release mode, use the ksl_vec4_print function.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_vec4_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#ifdef NDEBUG
#define ksl_vec4_debug(f, v, ...)                                              \
  do {                                                                         \
  } while(0)
#else
#define ksl_vec4_debug(f, v, ...)                                              \
  { ksl_vec4_printWithOptions(f, v, ##__VA_ARGS__, NULL, NULL); }
#endif

/*!
@brief print a ksl_vec4_t data structure.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_vec4_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options. To pass an options struct with no label, call
ksl_vec4_print(f, v, NULL, options); or ksl_vec4_print(f, v, "", options);
*/
#define ksl_vec4_print(f, v, ...)                                              \
  { ksl_vec4_printWithOptions(f, v, ##__VA_ARGS__, NULL, NULL); }

void ksl_vec4_printWithOptions(FILE* f, const ksl_vec4_t* v, ...);

/*!
@brief "debug" print a ksl_vec4f_t data structure. If NDEBUG is defined, this
function is converted to a no-op and nothing will be output. If it is desired
to print a ksl_vec4f_t in release mode, use the ksl_vec4f_print function.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_vec4f_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#ifdef NDEBUG
#define ksl_vec4f_debug(f, v, ...)                                             \
  do {                                                                         \
  } while(0)
#else
#define ksl_vec4f_debug(f, v, ...)                                             \
  { ksl_vec4f_printWithOptions(f, v, ##__VA_ARGS__, NULL, NULL); }
#endif

/*!
@brief print a ksl_vec4f_t data structure.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_vec4f_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options. To pass an options struct with no label, call
ksl_vec4f_print(f, v, NULL, options); or ksl_vec4f_print(f, v, "", options);
*/
#define ksl_vec4f_print(f, v, ...)                                             \
  { ksl_vec4f_printWithOptions(f, v, ##__VA_ARGS__, NULL, NULL); }

void ksl_vec4f_printWithOptions(FILE* f, const ksl_vec4f_t* vi, ...);

/*!
@brief "debug" print a ksl_eulerangles_t data structure. If NDEBUG is defined,
this function is converted to a no-op and nothing will be output. If it is
desired to print a ksl_eulerangles_t in release mode, use the
ksl_eulerangles_print function.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_eulerangles_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#ifdef NDEBUG
#define ksl_eulerangles_debug(f, v, ...)                                       \
  do {                                                                         \
  } while(0)
#else
#define ksl_eulerangles_debug(f, v, ...)                                       \
  { ksl_eulerangles_printWithOptions(f, v, ##__VA_ARGS__, NULL, NULL); }
#endif

/*!
@brief print a ksl_eulerangles_t data structure.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_eulerangles_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options. To pass an options struct with no label, call
ksl_eulerangles_print(f, v, NULL, options); or ksl_eulerangles_print(f, v, "",
options);
*/
#define ksl_eulerangles_print(f, v, ...)                                       \
  { ksl_eulerangles_printWithOptions(f, v, ##__VA_ARGS__, NULL, NULL); }

void ksl_eulerangles_printWithOptions(FILE* f, const ksl_eulerangles_t* v, ...);

/*!
@brief "debug" print a ksl_euleranglesf_t data structure. If NDEBUG is defined,
this function is converted to a no-op and nothing will be output. If it is
desired to print a ksl_euleranglesf_t in release mode, use the
ksl_euleranglesf_print function.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_euleranglesf_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#ifdef NDEBUG
#define ksl_euleranglesf_debug(f, v, ...)                                      \
  do {                                                                         \
  } while(0)
#else
#define ksl_euleranglesf_debug(f, v, ...)                                      \
  { ksl_euleranglesf_printWithOptions(f, v, ##__VA_ARGS__, NULL, NULL); }
#endif

/*!
@brief print a ksl_vec3f_t data structure.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_vec3f_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options. To pass an options struct with no label, call
ksl_vec3f_print(f, v, NULL, options); or ksl_vec3f_print(f, v, "", options);
*/
#define ksl_euleranglesf_print(f, v, ...)                                      \
  { ksl_euleranglesf_printWithOptions(f, v, ##__VA_ARGS__, NULL, NULL); }

void ksl_euleranglesf_printWithOptions(FILE* f, const ksl_euleranglesf_t* vi,
                                       ...);

/*!
@brief "debug" print a ksl_mat3x3_t data structure. If NDEBUG is defined, this
function is converted to a no-op and nothing will be output. If it is desired
to print a ksl_mat3x3_t in release mode, use the ksl_mat3x3_print function.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_mat3x3_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#ifdef NDEBUG
#define ksl_mat3x3_debug(f, m, ...)                                            \
  do {                                                                         \
  } while(0)
#else
#define ksl_mat3x3_debug(f, m, ...)                                            \
  { ksl_mat3x3_printWithOptions(f, m, ##__VA_ARGS__, NULL, NULL); }
#endif

/*!
@brief print a ksl_mat3x3_t data structure.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_mat3x3_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] an optional pointer to a ksl_print_options_t struct
containing print options. If the pointer is NULL or not present, the options
are set in the global print options.
*/
#define ksl_mat3x3_print(f, m, ...)                                            \
  { ksl_mat3x3_printWithOptions(f, m, ##__VA_ARGS__, NULL, NULL); }

void ksl_mat3x3_printWithOptions(FILE* f, const ksl_mat3x3_t* m, ...);

/*!
@brief "debug" print a ksl_mat3x3f_t data structure. If NDEBUG is defined, this
function is converted to a no-op and nothing will be output. If it is desired
to print a ksl_mat3x3f_t in release mode, use the ksl_mat3x3f_print function.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_mat3x3_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#ifdef NDEBUG
#define ksl_mat3x3f_debug(f, m, ...)                                           \
  do {                                                                         \
  } while(0)
#else
#define ksl_mat3x3f_debug(f, m, ...)                                           \
  { ksl_mat3x3f_printWithOptions(f, m, ##__VA_ARGS__, NULL, NULL); }
#endif

/*!
@brief print a ksl_mat3x3f_t data structure.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_mat3x3f_t datastructure
@param label [in] an optional pointer to a const char* label
@param options [in] an optional pointer to a ksl_print_options_t struct
containing print options. If the pointer is NULL or not present, the options
are set in the global print options.
*/
#define ksl_mat3x3f_print(f, m, ...)                                           \
  { ksl_mat3x3f_printWithOptions(f, m, ##__VA_ARGS__, NULL, NULL); }

void ksl_mat3x3f_printWithOptions(FILE* f, const ksl_mat3x3f_t* m, ...);

/*!
@brief "debug" print a ksl_quaternion_t data structure. If NDEBUG is defined,
this function is converted to a no-op and nothing will be output. If it is
desired to print a ksl_quaternion_t in release mode, use the
ksl_quaternion_print function.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_quaternion_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#ifdef NDEBUG
#define ksl_quaternion_debug(f, v, ...)                                        \
  do {                                                                         \
  } while(0)
#else
#define ksl_quaternion_debug(f, v, ...)                                        \
  { ksl_quaternion_printWithOptions(f, v, ##__VA_ARGS__, NULL, NULL); }
#endif

/*!
@brief print a ksl_quaternion_t data structure.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_quaternion_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#define ksl_quaternion_print(f, v, ...)                                        \
  { ksl_quaternion_printWithOptions(f, v, ##__VA_ARGS__, NULL, NULL); }

void ksl_quaternion_printWithOptions(FILE* f, const ksl_quaternion_t* q, ...);

/*!
@brief "debug" print a ksl_quaternionf_t data structure. If NDEBUG is defined,
this function is converted to a no-op and nothing will be output. If it is
desired to print a ksl_quaternionf_t in release mode, use the
ksl_quaternionf_print function.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_quaternionf_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#ifdef NDEBUG
#define ksl_quaternionf_debug(f, v, ...)                                       \
  do {                                                                         \
  } while(0)
#else
#define ksl_quaternionf_debug(f, v, ...)                                       \
  { ksl_quaternionf_printWithOptions(f, v, ##__VA_ARGS__, NULL, NULL); }
#endif

/*!
@brief print a ksl_quaternionf_t data structure.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_quaternionf_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#define ksl_quaternionf_print(f, v, ...)                                       \
  { ksl_quaternionf_printWithOptions(f, v, ##__VA_ARGS__, NULL, NULL); }

void ksl_quaternionf_printWithOptions(FILE* f, const ksl_quaternionf_t* q, ...);

/*!
@brief "debug" print a ksl_screw_t data structure. If NDEBUG is defined, this
function is converted to a no-op and nothing will be output. If it is desired
to print a ksl_screw_t in release mode, use the ksl_screw_print function.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_screw_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#ifdef NDEBUG
#define ksl_screw_debug(f, v, ...)                                             \
  do {                                                                         \
  } while(0)
#else
#define ksl_screw_debug(f, v, ...)                                             \
  { ksl_screw_printWithOptions(f, v, ##__VA_ARGS__, NULL, NULL); }
#endif

/*!
@brief print a ksl_screw_t data structure.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_screw_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#define ksl_screw_print(f, v, ...)                                             \
  { ksl_screw_printWithOptions(f, v, ##__VA_ARGS__, NULL, NULL); }

void ksl_screw_printWithOptions(FILE* f, const ksl_screw_t* s, ...);

/*!
@brief "debug" print a ksl_screwf_t data structure. If NDEBUG is defined, this
function is converted to a no-op and nothing will be output. If it is desired
to print a ksl_screwf_t in release mode, use the ksl_screwf_print function.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_screwf_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#ifdef NDEBUG
#define ksl_screwf_debug(f, v, ...)                                            \
  do {                                                                         \
  } while(0)
#else
#define ksl_screwf_debug(f, v, ...)                                            \
  { ksl_screwf_printWithOptions(f, v, ##__VA_ARGS__, NULL, NULL); }
#endif

/*!
@brief print a ksl_screwf_t data structure.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_screwf_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#define ksl_screwf_print(f, v, ...)                                            \
  { ksl_screwf_printWithOptions(f, v, ##__VA_ARGS__, NULL, NULL); }

void ksl_screwf_printWithOptions(FILE* f, const ksl_screwf_t* s, ...);

/*!
@brief "debug" print a ksl_coscrew_t data structure. If NDEBUG is defined, this
function is converted to a no-op and nothing will be output. If it is desired
to print a ksl_coscrew_t in release mode, use the ksl_coscrew_print function.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_coscrew_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#ifdef NDEBUG
#define ksl_coscrew_debug(f, v, ...)                                           \
  do {                                                                         \
  } while(0)
#else
#define ksl_coscrew_debug(f, v, ...)                                           \
  { ksl_coscrew_printWithOptions(f, v, ##__VA_ARGS__, NULL, NULL); }
#endif

/*!
@brief print a ksl_coscrew_t data structure.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_coscrew_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#define ksl_coscrew_print(f, v, ...)                                           \
  { ksl_coscrew_printWithOptions(f, v, ##__VA_ARGS__, NULL, NULL); }

void ksl_coscrew_printWithOptions(FILE* f, const ksl_coscrew_t* s, ...);

/*!
@brief "debug" print a ksl_coscrewf_t data structure. If NDEBUG is defined, this
function is converted to a no-op and nothing will be output. If it is desired
to print a ksl_coscrewf_t in release mode, use the ksl_coscrewf_print function.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_coscrewf_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#ifdef NDEBUG
#define ksl_coscrewf_debug(f, v, ...)                                          \
  do {                                                                         \
  } while(0)
#else
#define ksl_coscrewf_debug(f, v, ...)                                          \
  { ksl_coscrewf_printWithOptions(f, v, ##__VA_ARGS__, NULL, NULL); }
#endif

/*!
@brief print a ksl_coscrewf_t data structure.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_coscrewf_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#define ksl_coscrewf_print(f, v, ...)                                          \
  { ksl_coscrewf_printWithOptions(f, v, ##__VA_ARGS__, NULL, NULL); }

void ksl_coscrewf_printWithOptions(FILE* f, const ksl_coscrewf_t* s, ...);

/*!
@brief "debug" print a ksl_SE3_t data structure. If NDEBUG is defined, this
function is converted to a no-op and nothing will be output. If it is desired
to print a ksl_SE3_t in release mode, use the ksl_SE3_print function.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_SE3_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#ifdef NDEBUG
#define ksl_SE3_debug(f, m, ...)                                               \
  do {                                                                         \
  } while(0)
#else
#define ksl_SE3_debug(f, m, ...)                                               \
  { ksl_SE3_printWithOptions(f, m, ##__VA_ARGS__, NULL, NULL); }
#endif

/*!
@brief print a ksl_SE3_t data structure.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_SE3_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#define ksl_SE3_print(f, m, ...)                                               \
  { ksl_SE3_printWithOptions(f, m, ##__VA_ARGS__, NULL, NULL); }

void ksl_SE3_printWithOptions(FILE* f, const ksl_SE3_t* d, ...);

/*!
@brief "debug" print a ksl_SE3f_t data structure. If NDEBUG is defined, this
function is converted to a no-op and nothing will be output. If it is desired
to print a ksl_SE3f_t in release mode, use the ksl_SE3f_print function.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_SE3f_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#ifdef NDEBUG
#define ksl_SE3f_debug(f, m, ...)                                              \
  do {                                                                         \
  } while(0)
#else
#define ksl_SE3f_debug(f, m, ...)                                              \
  { ksl_SE3f_printWithOptions(f, m, ##__VA_ARGS__, NULL, NULL); }
#endif

/*!
@brief print a ksl_SE3f_t data structure.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_SE3f_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#define ksl_SE3f_print(f, m, ...)                                              \
  { ksl_SE3f_printWithOptions(f, m, ##__VA_ARGS__, NULL, NULL); }

void ksl_SE3f_printWithOptions(FILE* f, const ksl_SE3f_t* r, ...);

/*!
@brief "debug" print a ksl_mat4x4_t data structure. If NDEBUG is defined, this
function is converted to a no-op and nothing will be output. If it is desired
to print a ksl_mat4x4_t in release mode, use the ksl_mat4x4_print function.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_mat3x3_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#ifdef NDEBUG
#define ksl_mat4x4_debug(f, m, ...)                                            \
  do {                                                                         \
  } while(0)
#else
#define ksl_mat4x4_debug(f, m, ...)                                            \
  { ksl_mat4x4_printWithOptions(f, m, ##__VA_ARGS__, NULL, NULL); }
#endif

/*!
@brief print a ksl_mat4x4_t data structure.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_mat4x4_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#define ksl_mat4x4_print(f, m, ...)                                            \
  { ksl_mat4x4_printWithOptions(f, m, ##__VA_ARGS__, NULL, NULL); }

void ksl_mat4x4_printWithOptions(FILE* f, const ksl_mat4x4_t* d, ...);

/*!
@brief "debug" print a ksl_mat4x4f_t data structure. If NDEBUG is defined, this
function is converted to a no-op and nothing will be output. If it is desired
to print a ksl_mat4x4_t in release mode, use the ksl_mat4x4_print function.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_mat3x3_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#ifdef NDEBUG
#define ksl_mat4x4f_debug(f, m, ...)                                           \
  do {                                                                         \
  } while(0)
#else
#define ksl_mat4x4f_debug(f, m, ...)                                           \
  { ksl_mat4x4f_printWithOptions(f, m, ##__VA_ARGS__, NULL, NULL); }
#endif

/*!
@brief print a ksl_mat4x4f_t data structure.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_mat4x4f_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#define ksl_mat4x4f_print(f, m, ...)                                           \
  { ksl_mat4x4f_printWithOptions(f, m, ##__VA_ARGS__, NULL, NULL); }

void ksl_mat4x4f_printWithOptions(FILE* f, const ksl_mat4x4f_t* d, ...);

/*!
@brief "debug" print a double precision array. If NDEBUG is defined, this
function is converted to a no-op and nothing will be output. If it is desired
to print an array in release mode, use the ksl_array_print function.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param n [in] number of values to print
@param a [in] a pointer to a double*
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#ifdef NDEBUG
#define ksl_array_debug(f, n, a, ...)                                          \
  do {                                                                         \
  } while(0)
#else
#define ksl_array_debug(f, n, a, ...)                                          \
  { ksl_array_printWithOptions(f, n, a, ##__VA_ARGS__, NULL, NULL); }
#endif

/*!
@brief print a double precision array.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param n [in] number of values to print
@param a [in] a pointer to a double*
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#define ksl_array_print(f, n, a, ...)                                          \
  { ksl_array_printWithOptions(f, n, a, ##__VA_ARGS__, NULL, NULL); }

void ksl_array_printWithOptions(FILE* f, const int n, const double* a, ...);

/*!
@brief "debug" print a double precision 2D array. If NDEBUG is defined, this
function is converted to a no-op and nothing will be output. If it is desired
to print an array in release mode, use the ksl_array_print function.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param m [in] array row dimension
@param n [in] array column dimension
@param a [in] a pointer to a double*
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#ifdef NDEBUG
#define ksl_array2D_debug(f, m, n, a, ...)                                     \
  do {                                                                         \
  } while(0)
#else
#define ksl_array2D_debug(f, m, n, a, ...)                                     \
  { ksl_array2D_printWithOptions(f, m, n, a, ##__VA_ARGS__, NULL, NULL); }
#endif

/*!
@brief print a double precision 2D array.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param m [in] row dimension
@param n [in] column dimension
@param a [in] a pointer to a double*
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#define ksl_array2D_print(f, m, n, a, ...)                                     \
  { ksl_array2D_printWithOptions(f, m, n, a, ##__VA_ARGS__, NULL, NULL); }

void ksl_array2D_printWithOptions(FILE* f, const int rowDim, const int colDim,
                                  const double* a, ...);

/*!
@brief "debug" print an array of integers. If NDEBUG is defined, this
function is converted to a no-op and nothing will be output. If it is desired
to print an array in release mode, use the ksl_arrayi_print function.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param n [in] number of values to print
@param a [in] a pointer to a double*
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#ifdef NDEBUG
#define ksl_arrayi_debug(f, n, a, ...)                                         \
  do {                                                                         \
  } while(0)
#else
#define ksl_arrayi_debug(f, n, a, ...)                                         \
  { ksl_arrayi_printWithOptions(f, n, a, ##__VA_ARGS__, NULL, NULL); }
#endif

/*!
@brief print an array of integers.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param n [in] number of values to print
@param a [in] a pointer to a int*
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#define ksl_arrayi_print(f, n, a, ...)                                         \
  { ksl_arrayi_printWithOptions(f, n, a, ##__VA_ARGS__, NULL, NULL); }

void ksl_arrayi_printWithOptions(FILE* f, const int n, const int* a, ...);

/*!
@brief "debug" print a triangular array of double precision values. If
NDEBUG is defined, this function is converted to a no-op and nothing will be
output. If it is desired to print an array in release mode, use the
ksl_triang_print function.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param n [in] row/column dimension of nxn matrix
@param a [in] a pointer to a double*
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#ifdef NDEBUG
#define ksl_triang_debug(f, n, a, ...)                                         \
  do {                                                                         \
  } while(0)
#else
#define ksl_triang_debug(f, n, a, ...)                                         \
  { ksl_triang_printWithOptions(f, n, a, ##__VA_ARGS__, NULL, NULL); }
#endif

/*!
@brief print a lower triangular array of double precision values.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param n [in] row/column dimension of nxn matrix
@param a [in] a pointer to a int*
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#define ksl_triang_print(f, n, a, ...)                                         \
  { ksl_triang_printWithOptions(f, n, a, ##__VA_ARGS__, NULL, NULL); }

void ksl_triang_printWithOptions(FILE* f, const int n, const double* a, ...);

/*!
@brief "debug" print a triangular array of integer values. If
NDEBUG is defined, this function is converted to a no-op and nothing will be
output. If it is desired to print an array in release mode, use the
ksl_triangi_print function.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param n [in] row/column dimension of nxn matrix
@param a [in] a pointer to a int*
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#ifdef NDEBUG
#define ksl_triangi_debug(f, n, a, ...)                                        \
  do {                                                                         \
  } while(0)
#else
#define ksl_triangi_debug(f, n, a, ...)                                        \
  { ksl_triangi_printWithOptions(f, n, a, ##__VA_ARGS__, NULL, NULL); }
#endif

/*!
@brief print a lower triangular array of integers.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param n [in] row/column dimension of nxn matrix
@param a [in] a pointer to a int*
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#define ksl_triangi_print(f, n, a, ...)                                        \
  { ksl_triangi_printWithOptions(f, n, a, ##__VA_ARGS__, NULL, NULL); }

void ksl_triangi_printWithOptions(FILE* f, const int n, const int* a, ...);

/*!
@brief "debug" print a triangular array of boolean values. If
NDEBUG is defined, this function is converted to a no-op and nothing will be
output. If it is desired to print an array in release mode, use the
ksl_triangb_print function.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param n [in] row/column dimension of nxn matrix
@param a [in] a pointer to a boolean array
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#ifdef NDEBUG
#define ksl_triangb_debug(f, n, a, ...)                                        \
  do {                                                                         \
  } while(0)
#else
#define ksl_triangb_debug(f, n, a, ...)                                        \
  { ksl_triangb_printWithOptions(f, n, a, ##__VA_ARGS__, NULL, NULL); }
#endif

/*!
@brief print a lower triangular array of booleans.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param n [in] row/column dimension of nxn matrix
@param a [in] a pointer to a boolean array
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#define ksl_triangb_print(f, n, a, ...)                                        \
  { ksl_triangb_printWithOptions(f, n, a, ##__VA_ARGS__, NULL, NULL); }

void ksl_triangb_printWithOptions(FILE* f, const int n, const bool* a, ...);

/*!
@brief "debug" print a triangular array of boolean values. If
NDEBUG is defined, this function is converted to a no-op and nothing will be
output. If it is desired to print an array in release mode, use the
ksl_triangb_print function.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param n [in] row/column dimension of nxn matrix
@param a [in] a pointer to a boolean array
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#ifdef NDEBUG
#define ksl_inertia_debug(f, m, ...)                                           \
  do {                                                                         \
  } while(0)
#else
#define ksl_inertia_debug(f, m, ...)                                           \
  { ksl_inertia_printWithOptions(f, m, ##__VA_ARGS__, NULL, NULL); }
#endif

/*!
@brief print a lower triangular array of booleans.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param n [in] row/column dimension of nxn matrix
@param a [in] a pointer to a boolean array
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the
global print options.
*/
#define ksl_inertia_print(f, m, ...)                                           \
  { ksl_inertia_printWithOptions(f, m, ##__VA_ARGS__, NULL, NULL); }

void ksl_inertia_printWithOptions(FILE* f, const ksl_inertia_t* m, ...);

#ifdef __cplusplus
}
#endif

#endif
