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

#include <stdbool.h>
#include <stdio.h>
#include <stdarg.h>

#include "inertia.h"
#include "matrix.h"
#include "quaternion.h"
#include "screw.h"
#include "vector.h"

/* macros for obtaining the length of arguments in a variadic function */
#define VA_COMMA(...) GET_6TH_ARG(, ##__VA_ARGS__, COMMA, COMMA, COMMA, COMMA, )
#define GET_6TH_ARG(a1, a2, a3, a4, a5, a6, ...) a6
#define COMMA ,

typedef enum ksl_print_breakBetweenLines_enum_t {
  KSL_BREAK_BETWEEN_LINES,
  KSL_NO_BREAK_BETWEEN_LINES
} ksl_print_breakBetweenLines_enum_t;

/*! @brief print formatting options*/
typedef struct ksl_print_options_t {
  char delimiter[100]; /*!< default delimiter, default: ", " */
  char real_fmt[100];  /*!< formatting for doubles and floats, default: "%0.6g"  */
  char int_fmt[100];   /*!< formatting for ints: default: "%d" */
  char true_fmt[100];  /*!< formatting for display of true boolean, default: "true" */
  char false_fmt[100]; /*!< formatting for display of false boolean, default: "false" */
  char inner_left_bracket[100];  /*!< default: "[" */
  char inner_right_bracket[100]; /*!< default: "]" */
  char outer_left_bracket[100];  /*!< default: "[" */
  char outer_right_bracket[100]; /*!< default: "]" */
  ksl_print_breakBetweenLines_enum_t line_breaks_in_matrices;
    /*!< default: KSL_BREAK_BETWEEN_LINES */
  ksl_matrix_enum_t print_row_column_major; /*!< default: KSL_ROW_MAJOR */
} ksl_print_options_t;

/*!
@brief used to set delimiter used in display of matrices, vectors, screws, etc.
@param delimiter [in]
@param options [in] a pointer to a user-defined ksl_print_options_t struct containing print options. If this value is NULL or is not present, the option will be set in the global print settings.
*/
#define ksl_print_setDelimiter(fmt, ...)                                       \
  { ksl_print_setDelimiterOption(fmt, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL); }

void ksl_print_setDelimiterOption(const char* delimiter, ...);

/*!
@brief used to set format for display of float and double values
@param fmt [in]
@param options [in] a pointer to a user-defined ksl_print_options_t struct containing print options. If this value is NULL or is not present, the option will be set in the global print settings.
*/
#define ksl_print_setRealFormat(fmt, ...)                                      \
  {                                                                            \
    ksl_print_setRealFormatOption(fmt,                                         \
                                  __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL);     \
  }

void ksl_print_setRealFormatOption(const char* fmt, ...);

/*!
@brief used to set inner brackets in dispay of matrices
@param left [in] left bracket
@param right [in] right bracket
@param options [in] a pointer to a user-defined ksl_print_options_t struct containing print options. If this value is NULL or is not present, the option will be set in the global print settings.
*/
#define ksl_print_setInnerBrackets(left, right, ...)                           \
  {                                                                            \
    ksl_print_setInnerBracketsOption(left, right,                              \
                                     __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL);  \
  }

void ksl_setInnerBracketsOption(const char* left, const char* right, ...);

/*!
@brief used to set outer brackets in dispay of matrices
@param left [in] left bracket
@param right [in] right bracket
@param options [in] a pointer to a user-defined ksl_print_options_t struct containing print options. If this value is NULL or is not present, the option will be set in the global print settings.
*/
#define ksl_print_setOuterBrackets(left, right, ...)                           \
  {                                                                            \
    ksl_print_setOuterBracketsOption(left, right,                              \
                                     __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL);  \
  }

void ksl_setOuterBracketsOption(const char* left, const char* right, ...);

/*!
@brief used to set "BreakBetweenLinesInMatrix" option for dispay of matrices
@param val [in] valid inputs are KSL_BREAK_BETWEEN_LINES or KSL_NO_BREAK_BETWEEN_LINES
@param options [in] a pointer to a user-defined ksl_print_options_t struct containing print options. If this value is NULL or is not present, the option will be set in the global print settings.
*/
#define ksl_print_setBreakBetweenLinesInMatrix(val, ...)                       \
  {                                                                            \
    ksl_print_setBreakBetweenLinesInMatrixOption(                              \
      val, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL);                            \
  }

void ksl_setBreakBetweenLinesInMatrixOption(
  ksl_print_breakBetweenLines_enum_t val, ...);

/*!
@brief used to set "RowColumnMajorPrinting" option for dispay of matrices
@param val [in] valid inputs are KSL_ROW_MAJOR or KSL_COLUMN_MAJOR
@param options [in] a pointer to a user-defined ksl_print_options_t struct containing print options. If this value is NULL or is not present, the option will be set in the global print settings.
*/
#define ksl_print_setRowColumnMajorPrinting(val, ...)                          \
  {                                                                            \
    ksl_print_setRowColumnMajorPrintingOption(                                 \
      val, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL);                            \
  }

void ksl_setRowColumnMajorPrintingOption(
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
options. If the pointer is NULL or not present, the options are set in the global
print options.
*/
#ifdef NDEBUG
#define ksl_vec3_debug(f, v, ...)                                              \
  do {                                                                         \
  } while(0)
#else
#define ksl_vec3_debug(f, v, ...)                                              \
  {                                                                         \
    ksl_vec3_printWithOptions(f, v, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL,    \
                              NULL);                                           \
  }
#endif

/*!
@brief print a ksl_vec3_t data structure.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_vec3_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the global
print options. To pass an options struct with no label, call
ksl_vec3_print(f, v, NULL, options); or ksl_vec3_print(f, v, "", options);
*/
#define ksl_vec3_print(f, v, ...)                                              \
  {                                                                            \
    ksl_vec3_printWithOptions(f, v, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL,    \
                              NULL);                                           \
  }

void ksl_vec3_printWithOptions(FILE* f, const ksl_vec3_t* v, ...);

/*!
@brief "debug" print a ksl_vec3f_t data structure. If NDEBUG is defined, this
function is converted to a no-op and nothing will be output. If it is desired
to print a ksl_vec3f_t in release mode, use the ksl_vec3f_print function.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_vec3f_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the global
print options.
*/
#ifdef NDEBUG
#define ksl_vec3f_debug(f, v, ...)                                             \
  do {                                                                         \
  } while(0)
#else
#define ksl_vec3f_debug(f, v, ...)                                             \
  {                                                                         \
    ksl_vec3f_printWithOptions(f, v, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL,   \
                               NULL);                                          \
  }
#endif

/*!
@brief print a ksl_vec3f_t data structure.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_vec3f_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the global
print options. To pass an options struct with no label, call
ksl_vec3f_print(f, v, NULL, options); or ksl_vec3f_print(f, v, "", options);
*/
#define ksl_vec3f_print(f, v, ...)                                             \
  {                                                                            \
    ksl_vec3f_printWithOptions(f, v, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL,   \
                               NULL);                                          \
  }

void ksl_vec3f_printWithOptions(FILE* f, const ksl_vec3f_t* vi, ...);

/*!
@brief "debug" print a ksl_mat3x3_t data structure. If NDEBUG is defined, this
function is converted to a no-op and nothing will be output. If it is desired
to print a ksl_mat3x3_t in release mode, use the ksl_mat3x3_print function.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_mat3x3_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the global
print options.
*/
#ifdef NDEBUG
#define ksl_mat3x3_debug(f, m, ...)                                            \
  do {                                                                         \
  } while(0)
#else
#define ksl_mat3x3_debug(f, m, ...)                                            \
  {                                                                         \
    ksl_mat3x3_printWithOptions(f, m, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL,  \
                                NULL);                                         \
  }
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
  {                                                                            \
    ksl_mat3x3_printWithOptions(f, m, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL,  \
                                NULL);                                         \
  }

void ksl_mat3x3_printWithOptions(FILE* f, const ksl_mat3x3_t* m, ...);

/*!
@brief "debug" print a ksl_mat3x3f_t data structure. If NDEBUG is defined, this
function is converted to a no-op and nothing will be output. If it is desired
to print a ksl_mat3x3f_t in release mode, use the ksl_mat3x3f_print function.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_mat3x3_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the global
print options.
*/
#ifdef NDEBUG
#define ksl_mat3x3f_debug(f, m, ...)                                           \
  do {                                                                         \
  } while(0)
#else
#define ksl_mat3x3f_debug(f, m, ...)                                           \
  {                                                                            \
    ksl_mat3x3f_printWithOptions(f, m, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL, \
                                 NULL);                                        \
  }
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
  {                                                                            \
    ksl_mat3x3f_printWithOptions(f, m, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL, \
                                 NULL);                                        \
  }

void ksl_mat3x3f_printWithOptions(FILE* f, const ksl_mat3x3f_t* m, ...);

/*!
@brief "debug" print a ksl_quaternion_t data structure. If NDEBUG is defined, this
function is converted to a no-op and nothing will be output. If it is desired
to print a ksl_quaternion_t in release mode, use the ksl_quaternion_print function.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_quaternion_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the global
print options.
*/
#ifdef NDEBUG
#define ksl_quaternion_debug(f, v, ...)                                        \
  do {                                                                         \
  } while(0)
#else
#define ksl_quaternion_debug(f, v, ...)                                        \
  {                                                                         \
    ksl_quaternion_printWithOptions(                                           \
      f, v, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL, NULL);                     \
  }
#endif

/*!
@brief print a ksl_quaternion_t data structure.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_quaternion_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the global
print options.
*/
#define ksl_quaternion_print(f, v, ...)                                        \
  {                                                                            \
    ksl_quaternion_printWithOptions(                                           \
      f, v, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL, NULL);                     \
  }

void ksl_quaternion_printWithOptions(FILE* f, const ksl_quaternion_t* q, ...);

/*!
@brief "debug" print a ksl_quaternionf_t data structure. If NDEBUG is defined, this
function is converted to a no-op and nothing will be output. If it is desired
to print a ksl_quaternionf_t in release mode, use the ksl_quaternionf_print function.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_quaternionf_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the global
print options.
*/
#ifdef NDEBUG
#define ksl_quaternionf_debug(f, v, ...)                                       \
  do {                                                                         \
  } while(0)
#else
#define ksl_quaternionf_debug(f, v, ...)                                       \
  {                                                                            \
    ksl_quaternionf_printWithOptions(                                          \
      f, v, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL, NULL);                     \
  }
#endif

/*!
@brief print a ksl_quaternionf_t data structure.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_quaternionf_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the global
print options.
*/
#define ksl_quaternionf_print(f, v, ...)                                       \
  {                                                                            \
    ksl_quaternionf_printWithOptions(                                          \
      f, v, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL, NULL);                     \
  }

void ksl_quaternionf_printWithOptions(FILE* f, const ksl_quaternionf_t* q, ...);

/*!
@brief "debug" print a ksl_screw_t data structure. If NDEBUG is defined, this
function is converted to a no-op and nothing will be output. If it is desired
to print a ksl_screw_t in release mode, use the ksl_screw_print function.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_screw_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the global
print options.
*/
#ifdef NDEBUG
#define ksl_screw_debug(f, v, ...)                                             \
  do {                                                                         \
  } while(0)
#else
#define ksl_screw_debug(f, v, ...)                                             \
  {                                                                         \
    ksl_screw_printWithOptions(f, v, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL,   \
                               NULL);                                          \
  }
#endif

/*!
@brief print a ksl_screw_t data structure.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_screw_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the global
print options.
*/
#define ksl_screw_print(f, v, ...)                                             \
  {                                                                            \
    ksl_screw_printWithOptions(f, v, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL,   \
                               NULL);                                          \
  }

void ksl_screw_printWithOptions(FILE* f, const ksl_screw_t* s, ...);

/*!
@brief "debug" print a ksl_screwf_t data structure. If NDEBUG is defined, this
function is converted to a no-op and nothing will be output. If it is desired
to print a ksl_screwf_t in release mode, use the ksl_screwf_print function.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_screwf_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the global
print options.
*/
#ifdef NDEBUG
#define ksl_screwf_debug(f, v, ...)                                            \
  do {                                                                         \
  } while(0)
#else
#define ksl_screwf_debug(f, v, ...)                                            \
  {                                                                         \
    ksl_screwf_printWithOptions(f, v, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL,  \
                                NULL);                                         \
  }
#endif

/*!
@brief print a ksl_screwf_t data structure.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_screwf_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the global
print options.
*/
#define ksl_screwf_print(f, v, ...)                                            \
  {                                                                            \
    ksl_screwf_printWithOptions(f, v, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL,  \
                                NULL);                                         \
  }

void ksl_screwf_printWithOptions(FILE* f, const ksl_screw_t* s, ...);

/*!
@brief "debug" print a ksl_coscrew_t data structure. If NDEBUG is defined, this
function is converted to a no-op and nothing will be output. If it is desired
to print a ksl_coscrew_t in release mode, use the ksl_coscrew_print function.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_coscrew_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the global
print options.
*/
#ifdef NDEBUG
#define ksl_coscrew_debug(f, v, ...)                                           \
  do {                                                                         \
  } while(0)
#else
#define ksl_coscrew_debug(f, v, ...)                                           \
  {                                                                         \
    ksl_coscrew_printWithOptions(f, v, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL, \
                                 NULL);                                        \
  }
#endif

/*!
@brief print a ksl_coscrew_t data structure.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_coscrew_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the global
print options.
*/
#define ksl_coscrew_print(f, v, ...)                                           \
  {                                                                            \
    ksl_coscrew_printWithOptions(f, v, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL, \
                                 NULL);                                        \
  }

void ksl_coscrew_printWithOptions(FILE* f, const ksl_coscrew_t* s, ...);

/*!
@brief "debug" print a ksl_coscrewf_t data structure. If NDEBUG is defined, this
function is converted to a no-op and nothing will be output. If it is desired
to print a ksl_coscrewf_t in release mode, use the ksl_coscrewf_print function.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_coscrewf_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the global
print options.
*/
#ifdef NDEBUG
#define ksl_coscrewf_debug(f, v, ...)                                          \
  do {                                                                         \
  } while(0)
#else
#define ksl_coscrewf_debug(f, v, ...)                                          \
  {                                                                         \
    ksl_coscrewf_printWithOptions(                                             \
      f, v, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL, NULL);                     \
  }
#endif

/*!
@brief print a ksl_coscrewf_t data structure.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_coscrewf_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the global
print options.
*/
#define ksl_coscrewf_print(f, v, ...)                                          \
  {                                                                            \
    ksl_coscrewf_printWithOptions(                                             \
      f, v, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL, NULL);                     \
  }

void ksl_coscrewf_printWithOptions(FILE* f, const ksl_coscrewf_t* s, ...);

/*!
@brief "debug" print a ksl_SE3_t data structure. If NDEBUG is defined, this
function is converted to a no-op and nothing will be output. If it is desired
to print a ksl_SE3_t in release mode, use the ksl_SE3_print function.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_SE3_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the global
print options.
*/
#ifdef NDEBUG
#define ksl_SE3_debug(f, m, ...)                                               \
  do {                                                                         \
  } while(0)
#else
#define ksl_SE3_debug(f, m, ...)                                               \
  {                                                                         \
    ksl_SE3_printWithOptions(f, m, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL,     \
                             NULL);                                            \
  }
#endif

/*!
@brief print a ksl_SE3_t data structure.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_SE3_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL or not present, the options are set in the global
print options.
*/
#define ksl_SE3_print(f, m, ...)                                               \
  {                                                                            \
    ksl_SE3_printWithOptions(f, m, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL,     \
                             NULL);                                            \
  }

void ksl_SE3_printWithOptions(FILE* f, const ksl_SE3_t* d, ...);

void ksl_mat4x4_printWithOptions(FILE* f, const ksl_mat4x4_t* d, ...);

void ksl_mat4x4f_printWithOptions(FILE* f, const ksl_mat4x4f_t* d, ...);

void ksl_array_printWithOptions(FILE* f, const int n, const double* a, ...);

void ksl_array2D_printWithOptions(FILE* f, const int rowDim, const int colDim,
                       const double* a, ...);

void ksl_arrayi_printWithOptions(FILE* f, const int n, const int* a, ...);

void ksl_triang_printWithOptions(FILE* f, const int n, const double* a, ...);

void ksl_triangi_printWithOptions(FILE* f, const int n, const int* a, ...);

void ksl_triangb_printWithOptions(FILE* f, const int n, const bool* a, ...);

void ksl_inertia_printWithOptions(FILE* f, const ksl_inertia_t* inertia, ...);

#endif
