#include "coscrew.h"
#include "matrix.h"
#include "screw.h"
#include <print.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/* macros for obtaining the length of arguments in a variadic function */
#define VA_COMMA(...) GET_6TH_ARG(, ##__VA_ARGS__, COMMA, COMMA, COMMA, COMMA, )
#define GET_6TH_ARG(a1, a2, a3, a4, a5, a6, ...) a6
#define COMMA ,

/*!
@}
@name Functions to set print options
@{
*/

/*! @brief print formatting options*/
typedef struct ksl_print_options_t {
  char delimiter[100]; /*!< default delimiter */
  char real_fmt[100];  /*!< formatting for doubles and floats */
  char int_fmt[100];   /*!< formatting for ints */
  char true_fmt[100];  /*!< formatting for display of true boolean */
  char false_fmt[100]; /*!< formatting for display of false boolean */
  char inner_left_bracket[100];
  char inner_right_bracket[100];
  char outer_left_bracket[100];
  char outer_right_bracket[100];
  ksl_print_breakBetweenLines_enum_t line_breaks_in_matrices;
  ksl_matrix_enum_t print_row_column_major;
} ksl_print_options_t;

static ksl_print_options_t __ksl_print_options = {
  ", ",         "%0.6g", "%d", "true", "false",
  "[",          "]",     "[",  "]",    KSL_BREAK_BETWEEN_LINES,
  KSL_ROW_MAJOR};

#define ksl_print_setDelimiter(fmt, ...)                                       \
  { ksl_print_setDelimiterOption(fmt, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL); }

/*!
@brief used to set delimiter used in display of matrices and vectors
@param delimiter [in] a
@param options [in] optionally pass in a pointer containing print options.
*/
void ksl_print_setDelimiterOption(const char* delimiter, ...) {
  va_list arguments;
  va_start(arguments, delimiter);
  ksl_print_options_t* options = va_arg(arguments, ksl_print_options_t*);
  va_end(arguments);
  if(!options) {
    options = &__ksl_print_options;
  }
  sprintf(options->delimiter, "%s", delimiter);
}

#define ksl_print_setRealFormat(fmt, ...)                                      \
  {                                                                            \
    ksl_print_setRealFormatOption(fmt,                                         \
                                  __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL);     \
  }

/*!
@brief used to set formatting for display of floats and doubles
@param fmt [in] number formatting used by printf
@param options [in] optionally pass in a pointer containing print options.
*/
void ksl_print_setRealFormatOption(const char* fmt, ...) {
  va_list arguments;
  va_start(arguments, fmt);
  ksl_print_options_t* options = va_arg(arguments, ksl_print_options_t*);
  va_end(arguments);
  if(!options) {
    options = &__ksl_print_options;
  }
  sprintf(options->real_fmt, "%s", fmt);
}

#define ksl_print_setInnerBrackets(left, right, ...)                           \
  {                                                                            \
    ksl_print_setInnerBracketsOption(left, right,                              \
                                     __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL);  \
  }

void ksl_setInnerBracketsOption(const char* left, const char* right, ...) {
  va_list arguments;
  va_start(arguments, right);
  ksl_print_options_t* options = va_arg(arguments, ksl_print_options_t*);
  va_end(arguments);
  if(!options) {
    options = &__ksl_print_options;
  }
  sprintf(options->inner_left_bracket, "%s", left);
  sprintf(options->inner_right_bracket, "%s", right);
}

#define ksl_print_setOuterBrackets(left, right, ...)                           \
  {                                                                            \
    ksl_print_setOuterBracketsOption(left, right,                              \
                                     __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL);  \
  }

void ksl_setOuterBracketsOption(const char* left, const char* right, ...) {
  va_list arguments;
  va_start(arguments, right);
  ksl_print_options_t* options = va_arg(arguments, ksl_print_options_t*);
  va_end(arguments);
  if(!options) {
    options = &__ksl_print_options;
  }
  sprintf(options->outer_left_bracket, "%s", left);
  sprintf(options->outer_right_bracket, "%s", right);
}

#define ksl_print_setBreakBetweenLinesInMatrix(val, ...)                       \
  {                                                                            \
    ksl_print_setBreakBetweenLinesInMatrixOption(                              \
      val, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL);                            \
  }

void ksl_setBreakBetweenLinesInMatrixOption(
  ksl_print_breakBetweenLines_enum_t val, ...) {
  va_list arguments;
  va_start(arguments, val);
  ksl_print_options_t* options = va_arg(arguments, ksl_print_options_t*);
  va_end(arguments);
  if(!options) {
    options = &__ksl_print_options;
  }
  options->line_breaks_in_matrices = val;
}

#define ksl_print_setRowColumnMajorPrinting(val, ...)                          \
  {                                                                            \
    ksl_print_setRowColumnMajorPrintingOption(                                 \
      val, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL);                            \
  }
void ksl_setRowColumnMajorPrintingOption(
  ksl_matrix_enum_t print_row_column_major, ...) {

  va_list arguments;
  va_start(arguments, print_row_column_major);
  ksl_print_options_t* options = va_arg(arguments, ksl_print_options_t*);
  va_end(arguments);
  if(!options) {
    options = &__ksl_print_options;
  }
  options->print_row_column_major = print_row_column_major;
}

/*!
@brief constructor used to create a default print options on the heap. must be
freed by user when
*/
ksl_print_options_t* ksl_print_options() {
  ksl_print_options_t* options = calloc(1, sizeof(ksl_print_options_t));
  sprintf(options->delimiter, ", ");
  sprintf(options->real_fmt, "%%0.6g");
  sprintf(options->int_fmt, "%%d");
  sprintf(options->true_fmt, "true");
  sprintf(options->false_fmt, "false");
  sprintf(options->outer_left_bracket, "[");
  sprintf(options->outer_right_bracket, "]");
  sprintf(options->inner_left_bracket, "[");
  sprintf(options->inner_right_bracket, "]");
  options->line_breaks_in_matrices = true;
  options->print_row_column_major = KSL_ROW_MAJOR;
  return options;
}

/*!
@}
@name Printing utilities
Utilities to print vectors, screws, rotation matrices and SE3 transformations
@{
*/
#ifndef NDEBUG
#define ksl_vec3_debug(f, v, ...)                                              \
  do {                                                                         \
    ksl_vec3_printWithOptions(f, v, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL,    \
                              NULL);                                           \
  } while(0)
#else
#define ksl_vec3_debug(f, v, ...)                                              \
  do {                                                                         \
  } while(0)
#endif

#define ksl_vec3_print(f, v, ...)                                              \
  {                                                                            \
    ksl_vec3_printWithOptions(f, v, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL,    \
                              NULL);                                           \
  }

void ksl_vec3_printWithOptions(FILE* f, const ksl_vec3_t* restrict v, ...) {

  va_list arguments;
  va_start(arguments, v);
  const char* label = va_arg(arguments, const char*);
  const ksl_print_options_t* options = va_arg(arguments, ksl_print_options_t*);
  va_end(arguments);
  if(!options) {
    // printf("  using global print options\n");
    options = &__ksl_print_options;
  }
  // else {
  // printf("  using user specified print
  // options\n");
  // }
  if(label) {
    // printf("  using user specified label\n");
    fprintf(f, "%s", label);
  }
  // else {
  // printf("  no label specified\n");
  // }
  fprintf(f, "%s", options->outer_left_bracket);
  for(int i = 0; i < 2; i++) {
    fprintf(f, options->real_fmt, v->at[i]);
    fprintf(f, options->delimiter, v->at[i]);
  }
  fprintf(f, options->real_fmt, v->at[2]);
  fprintf(f, "%s", options->outer_right_bracket);
  fprintf(f, "\n");
}

#ifndef NDEBUG
#define ksl_vec3f_debug(f, v, ...)                                             \
  do {                                                                         \
    ksl_vec3f_printWithOptions(f, v, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL,   \
                               NULL);                                          \
  } while(0)
#else
#define ksl_vec3f_debug(f, v, ...)                                             \
  do {                                                                         \
  } while(0)
#endif

#define ksl_vec3f_print(f, v, ...)                                             \
  {                                                                            \
    ksl_vec3f_printWithOptions(f, v, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL,   \
                               NULL);                                          \
  }

void ksl_vec3f_printWithOptions(FILE* f, const ksl_vec3f_t* restrict v, ...) {

  va_list arguments;
  va_start(arguments, v);
  const char* label = va_arg(arguments, const char*);
  const ksl_print_options_t* options = va_arg(arguments, ksl_print_options_t*);
  va_end(arguments);
  if(!options) {
    // printf("  using global print options\n");
    options = &__ksl_print_options;
  }
  // else {
  // printf("  using user specified print
  // options\n");
  // }
  if(label) {
    // printf("  using user specified label\n");
    fprintf(f, "%s", label);
  }
  // else {
  // printf("  no label specified\n");
  // }
  fprintf(f, "%s", options->outer_left_bracket);
  for(int i = 0; i < 2; i++) {
    fprintf(f, options->real_fmt, v->at[i]);
    fprintf(f, options->delimiter, v->at[i]);
  }
  fprintf(f, options->real_fmt, v->at[2]);
  fprintf(f, "%s", options->outer_right_bracket);
  fprintf(f, "\n");
}

#ifndef NDEBUG
#define ksl_mat3x3_debug(f, m, ...)                                            \
  do {                                                                         \
    ksl_mat3x3_printWithOptions(f, m, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL,  \
                                NULL);                                         \
  } while(0)
#else
#define ksl_mat3x3_debug(f, m, ...)                                            \
  do {                                                                         \
  } while(0)
#endif

#define ksl_mat3x3_print(f, m, ...)                                            \
  {                                                                            \
    ksl_mat3x3_printWithOptions(f, m, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL,  \
                                NULL);                                         \
  }

void ksl_mat3x3_printWithOptions(FILE* f, const ksl_mat3x3_t* restrict r, ...) {
  va_list arguments;
  va_start(arguments, r);
  const char* label = va_arg(arguments, const char*);
  const ksl_print_options_t* options = va_arg(arguments, ksl_print_options_t*);
  va_end(arguments);
  if(!options) {
    // printf("  using global print options\n");
    options = &__ksl_print_options;
  }
  // else {
  // printf("  using user specified print
  // options\n");
  // }
  int label_length = 0;
  if(label) {
    fprintf(f, "%s", label);
    label_length = strlen(label);
  }
  int lead_in_length = label_length + strlen(options->outer_left_bracket);
  fprintf(f, "%s", options->outer_left_bracket);
  for(int i = 0; i < 3; i++) {
    fprintf(f, "%s", options->inner_left_bracket);
    for(int j = 0; j < 2; j++) {
      switch(options->print_row_column_major) {
        case KSL_ROW_MAJOR: {
          fprintf(f, options->real_fmt, r->as_array[j][i]);
          fprintf(f, "%s", options->delimiter);
          break;
        }
        case KSL_COLUMN_MAJOR: {
          fprintf(f, options->real_fmt, r->as_array[i][j]);
          fprintf(f, "%s", options->delimiter);
          break;
        }
      }
      switch(options->print_row_column_major) {
        case KSL_ROW_MAJOR: {
          fprintf(f, options->real_fmt, r->as_array[2][i]);
          break;
        }
        case KSL_COLUMN_MAJOR: {
          fprintf(f, options->real_fmt, r->as_array[i][2]);
          break;
        }
      }
    }
    fprintf(f, "%s%s", options->inner_right_bracket, options->delimiter);
    if(options->line_breaks_in_matrices && i < 2) {
      fprintf(f, "\n");
      for(int j = 0; j < lead_in_length; j++) {
        fprintf(f, " ");
      }
    }
  }
  fprintf(f, "%s", options->outer_right_bracket);
  fprintf(f, "\n");
}

#ifndef NDEBUG
#define ksl_mat3x3f_debug(f, m, ...)                                           \
  do {                                                                         \
    ksl_mat3x3f_printWithOptions(f, m, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL, \
                                 NULL);                                        \
  } while(0)
#else
#define ksl_mat3x3f_debug(f, m, ...)                                           \
  do {                                                                         \
  } while(0)
#endif

#define ksl_mat3x3f_print(f, m, ...)                                           \
  {                                                                            \
    ksl_mat3x3f_printWithOptions(f, m, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL, \
                                 NULL);                                        \
  }

void ksl_mat3x3f_printWithOptions(FILE* f, const ksl_mat3x3_t* restrict r,
                                  ...) {
  va_list arguments;
  va_start(arguments, r);
  const char* label = va_arg(arguments, const char*);
  const ksl_print_options_t* options = va_arg(arguments, ksl_print_options_t*);
  va_end(arguments);
  if(!options) {
    // printf("  using global print options\n");
    options = &__ksl_print_options;
  }
  // else {
  // printf("  using user specified print
  // options\n");
  // }
  int label_length = 0;
  if(label) {
    fprintf(f, "%s", label);
    label_length = strlen(label);
  }
  int lead_in_length = label_length + strlen(options->outer_left_bracket);
  fprintf(f, "%s", options->outer_left_bracket);
  for(int i = 0; i < 3; i++) {
    fprintf(f, "%s", options->inner_left_bracket);
    for(int j = 0; j < 2; j++) {
      switch(options->print_row_column_major) {
        case KSL_ROW_MAJOR: {
          fprintf(f, options->real_fmt, r->as_array[j][i]);
          fprintf(f, "%s", options->delimiter);
          break;
        }
        case KSL_COLUMN_MAJOR: {
          fprintf(f, options->real_fmt, r->as_array[i][j]);
          fprintf(f, "%s", options->delimiter);
          break;
        }
      }
      switch(options->print_row_column_major) {
        case KSL_ROW_MAJOR: {
          fprintf(f, options->real_fmt, r->as_array[2][i]);
          break;
        }
        case KSL_COLUMN_MAJOR: {
          fprintf(f, options->real_fmt, r->as_array[i][2]);
          break;
        }
      }
    }
    fprintf(f, "%s%s", options->inner_right_bracket, options->delimiter);
    if(options->line_breaks_in_matrices && i < 2) {
      fprintf(f, "\n");
      for(int j = 0; j < lead_in_length; j++) {
        fprintf(f, " ");
      }
    }
  }
  fprintf(f, "%s", options->outer_right_bracket);
  fprintf(f, "\n");
}

#ifndef NDEBUG
#define ksl_quaternion_debug(f, v, ...)                                        \
  do {                                                                         \
    ksl_quaternion_printWithOptions(                                           \
      f, v, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL, NULL);                     \
  } while(0)
#else
#define ksl_quaternion_debug(f, v, ...)                                        \
  do {                                                                         \
  } while(0)
#endif

#define ksl_quaternion_print(f, v, ...)                                        \
  {                                                                            \
    ksl_quaternion_printWithOptions(                                           \
      f, v, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL, NULL);                     \
  }

void ksl_quaternion_printWithOptions(FILE* f,
                                     const ksl_quaternion_t* restrict v, ...) {

  va_list arguments;
  va_start(arguments, v);
  const char* label = va_arg(arguments, const char*);
  const ksl_print_options_t* options = va_arg(arguments, ksl_print_options_t*);
  va_end(arguments);
  if(!options) {
    // printf("  using global print options\n");
    options = &__ksl_print_options;
  }
  // else {
  // printf("  using user specified print
  // options\n");
  // }
  if(label) {
    // printf("  using user specified label\n");
    fprintf(f, "%s", label);
  }
  // else {
  // printf("  no label specified\n");
  // }
  fprintf(f, "%s", options->outer_left_bracket);
  for(int i = 0; i < 3; i++) {
    fprintf(f, options->real_fmt, v->at[i]);
    fprintf(f, options->delimiter, v->at[i]);
  }
  fprintf(f, options->real_fmt, v->at[3]);
  fprintf(f, "%s", options->outer_right_bracket);
  fprintf(f, "\n");
}

#ifndef NDEBUG
#define ksl_quaternionf_debug(f, v, ...)                                       \
  do {                                                                         \
    ksl_quaternionf_printWithOptions(                                          \
      f, v, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL, NULL);                     \
  } while(0)
#else
#define ksl_quaternionf_debug(f, v, ...)                                       \
  do {                                                                         \
  } while(0)
#endif

#define ksl_quaternionf_print(f, v, ...)                                       \
  {                                                                            \
    ksl_quaternionf_printWithOptions(                                          \
      f, v, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL, NULL);                     \
  }

void ksl_quaternionf_printWithOptions(FILE* f,
                                      const ksl_quaternionf_t* restrict v,
                                      ...) {

  va_list arguments;
  va_start(arguments, v);
  const char* label = va_arg(arguments, const char*);
  const ksl_print_options_t* options = va_arg(arguments, ksl_print_options_t*);
  va_end(arguments);
  if(!options) {
    // printf("  using global print options\n");
    options = &__ksl_print_options;
  }
  // else {
  // printf("  using user specified print
  // options\n");
  // }
  if(label) {
    // printf("  using user specified label\n");
    fprintf(f, "%s", label);
  }
  // else {
  // printf("  no label specified\n");
  // }
  fprintf(f, "%s", options->outer_left_bracket);
  for(int i = 0; i < 3; i++) {
    fprintf(f, options->real_fmt, v->at[i]);
    fprintf(f, options->delimiter, v->at[i]);
  }
  fprintf(f, options->real_fmt, v->at[3]);
  fprintf(f, "%s", options->outer_right_bracket);
  fprintf(f, "\n");
}

#ifndef NDEBUG
#define ksl_screw_debug(f, v, ...)                                             \
  do {                                                                         \
    ksl_screw_printWithOptions(f, v, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL,   \
                               NULL);                                          \
  } while(0)
#else
#define ksl_screw_debug(f, v, ...)                                             \
  do {                                                                         \
  } while(0)
#endif

#define ksl_screw_print(f, v, ...)                                             \
  {                                                                            \
    ksl_screw_printWithOptions(f, v, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL,   \
                               NULL);                                          \
  }

void ksl_screw_printWithOptions(FILE* f, const ksl_screw_t* restrict v, ...) {

  va_list arguments;
  va_start(arguments, v);
  const char* label = va_arg(arguments, const char*);
  const ksl_print_options_t* options = va_arg(arguments, ksl_print_options_t*);
  va_end(arguments);
  if(!options) {
    // printf("  using global print options\n");
    options = &__ksl_print_options;
  }
  // else {
  // printf("  using user specified print
  // options\n");
  // }
  if(label) {
    // printf("  using user specified label\n");
    fprintf(f, "%s", label);
  }
  // else {
  // printf("  no label specified\n");
  // }
  fprintf(f, "%s", options->outer_left_bracket);
  for(int i = 0; i < 5; i++) {
    fprintf(f, options->real_fmt, v->at[i]);
    fprintf(f, options->delimiter, v->at[i]);
  }
  fprintf(f, options->real_fmt, v->at[5]);
  fprintf(f, "%s", options->outer_right_bracket);
  fprintf(f, "\n");
}

#ifndef NDEBUG
#define ksl_screwf_debug(f, v, ...)                                            \
  do {                                                                         \
    ksl_screwf_printWithOptions(f, v, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL,  \
                                NULL);                                         \
  } while(0)
#else
#define ksl_screwf_debug(f, v, ...)                                            \
  do {                                                                         \
  } while(0)
#endif

#define ksl_screwf_print(f, v, ...)                                            \
  {                                                                            \
    ksl_screwf_printWithOptions(f, v, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL,  \
                                NULL);                                         \
  }

void ksl_screwf_printWithOptions(FILE* f, const ksl_screwf_t* restrict v, ...) {

  va_list arguments;
  va_start(arguments, v);
  const char* label = va_arg(arguments, const char*);
  const ksl_print_options_t* options = va_arg(arguments, ksl_print_options_t*);
  va_end(arguments);
  if(!options) {
    // printf("  using global print options\n");
    options = &__ksl_print_options;
  }
  // else {
  // printf("  using user specified print
  // options\n");
  // }
  if(label) {
    // printf("  using user specified label\n");
    fprintf(f, "%s", label);
  }
  // else {
  // printf("  no label specified\n");
  // }
  fprintf(f, "%s", options->outer_left_bracket);
  for(int i = 0; i < 5; i++) {
    fprintf(f, options->real_fmt, v->at[i]);
    fprintf(f, options->delimiter, v->at[i]);
  }
  fprintf(f, options->real_fmt, v->at[5]);
  fprintf(f, "%s", options->outer_right_bracket);
  fprintf(f, "\n");
}

#ifndef NDEBUG
#define ksl_coscrew_debug(f, v, ...)                                           \
  do {                                                                         \
    ksl_coscrew_printWithOptions(f, v, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL, \
                                 NULL);                                        \
  } while(0)
#else
#define ksl_coscrew_debug(f, v, ...)                                           \
  do {                                                                         \
  } while(0)
#endif

#define ksl_coscrew_print(f, v, ...)                                           \
  {                                                                            \
    ksl_coscrew_printWithOptions(f, v, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL, \
                                 NULL);                                        \
  }

void ksl_coscrew_printWithOptions(FILE* f, const ksl_coscrew_t* restrict v,
                                  ...) {

  va_list arguments;
  va_start(arguments, v);
  const char* label = va_arg(arguments, const char*);
  const ksl_print_options_t* options = va_arg(arguments, ksl_print_options_t*);
  va_end(arguments);
  if(!options) {
    // printf("  using global print options\n");
    options = &__ksl_print_options;
  }
  // else {
  // printf("  using user specified print
  // options\n");
  // }
  if(label) {
    // printf("  using user specified label\n");
    fprintf(f, "%s", label);
  }
  // else {
  // printf("  no label specified\n");
  // }
  fprintf(f, "%s", options->outer_left_bracket);
  for(int i = 0; i < 5; i++) {
    fprintf(f, options->real_fmt, v->at[i]);
    fprintf(f, options->delimiter, v->at[i]);
  }
  fprintf(f, options->real_fmt, v->at[5]);
  fprintf(f, "%s", options->outer_right_bracket);
  fprintf(f, "\n");
}

#ifndef NDEBUG
#define ksl_coscrewf_debug(f, v, ...)                                          \
  do {                                                                         \
    ksl_coscrewf_printWithOptions(                                             \
      f, v, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL, NULL);                     \
  } while(0)
#else
#define ksl_coscrewf_debug(f, v, ...)                                          \
  do {                                                                         \
  } while(0)
#endif

#define ksl_coscrewf_print(f, v, ...)                                          \
  {                                                                            \
    ksl_coscrewf_printWithOptions(                                             \
      f, v, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL, NULL);                     \
  }

void ksl_coscrewf_printWithOptions(FILE* f, const ksl_coscrewf_t* restrict v,
                                   ...) {

  va_list arguments;
  va_start(arguments, v);
  const char* label = va_arg(arguments, const char*);
  const ksl_print_options_t* options = va_arg(arguments, ksl_print_options_t*);
  va_end(arguments);
  if(!options) {
    // printf("  using global print options\n");
    options = &__ksl_print_options;
  }
  // else {
  // printf("  using user specified print
  // options\n");
  // }
  if(label) {
    // printf("  using user specified label\n");
    fprintf(f, "%s", label);
  }
  // else {
  // printf("  no label specified\n");
  // }
  fprintf(f, "%s", options->outer_left_bracket);
  for(int i = 0; i < 5; i++) {
    fprintf(f, options->real_fmt, v->at[i]);
    fprintf(f, options->delimiter, v->at[i]);
  }
  fprintf(f, options->real_fmt, v->at[5]);
  fprintf(f, "%s", options->outer_right_bracket);
  fprintf(f, "\n");
}

#ifndef NDEBUG
#define ksl_SE3_debug(f, m, ...)                                               \
  do {                                                                         \
    ksl_SE3_printWithOptions(f, m, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL,     \
                             NULL);                                            \
  } while(0)
#else
#define ksl_SE3_debug(f, m, ...)                                               \
  do {                                                                         \
  } while(0)
#endif

#define ksl_SE3_print(f, m, ...)                                               \
  {                                                                            \
    ksl_SE3_printWithOptions(f, m, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL,     \
                             NULL);                                            \
  }

void ksl_SE3_printWithOptions(FILE* f, const ksl_SE3_t* restrict m, ...) {
  va_list arguments;
  va_start(arguments, m);
  const char* label = va_arg(arguments, const char*);
  const ksl_print_options_t* options = va_arg(arguments, ksl_print_options_t*);
  va_end(arguments);
  if(!options) {
    // printf("  using global print options\n");
    options = &__ksl_print_options;
  }
  // else {
  // printf("  using user specified print
  // options\n");
  // }
  int label_length = 0;
  if(label) {
    fprintf(f, "%s", label);
    label_length = strlen(label);
  }
  int lead_in_length = label_length + strlen(options->outer_left_bracket);
  fprintf(f, "%s", options->outer_left_bracket);
  switch(options->print_row_column_major) {
    case KSL_ROW_MAJOR: {
      fprintf(f, "%s", options->inner_left_bracket);
      for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
          fprintf(f, options->real_fmt, m->as_array[j][i]);
          fprintf(f, "%s", options->delimiter);
        }
        fprintf(f, options->real_fmt, m->t.at[i]);
        fprintf(f, "%s%s", options->inner_right_bracket, options->delimiter);
        if(options->line_breaks_in_matrices) {
          fprintf(f, "\n");
          for(int j = 0; j < lead_in_length; j++) {
            fprintf(f, " ");
          }
        }
      }
      fprintf(f, "%s", options->inner_left_bracket);
      double vec[4] = {0.0, 0.0, 0.0, 1.0};
      for(int i = 0; i < 3; i++) {
        fprintf(f, options->real_fmt, vec[i]);
        fprintf(f, "%s", options->delimiter);
      }
      fprintf(f, options->real_fmt, vec[3]);
      fprintf(f, "%s", options->inner_right_bracket);
      fprintf(f, "%s", options->outer_right_bracket);
      break;
    }
    case KSL_COLUMN_MAJOR: {
      double vec[4] = {0.0, 0.0, 0.0, 1.0};
      fprintf(f, "%s", options->inner_left_bracket);
      for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 3; j++) {
          fprintf(f, options->real_fmt, m->as_array[i][j]);
          fprintf(f, "%s", options->delimiter);
        }
        fprintf(f, options->real_fmt, vec[i]);
        fprintf(f, "%s%s", options->inner_right_bracket, options->delimiter);
        if(options->line_breaks_in_matrices && i < 3) {
          fprintf(f, "\n");
          for(int j = 0; j < lead_in_length; j++) {
            fprintf(f, " ");
          }
        }
      }
      fprintf(f, "%s", options->outer_right_bracket);
      break;
    }
  }
  fprintf(f, "\n");
}

#ifndef NDEBUG
#define ksl_SE3f_debug(f, m, ...)                                              \
  do {                                                                         \
    ksl_SE3f_printWithOptions(f, m, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL,    \
                              NULL);                                           \
  } while(0)
#else
#define ksl_SE3f_debug(f, m, ...)                                              \
  do {                                                                         \
  } while(0)
#endif

#define ksl_SE3f_print(f, m, ...)                                              \
  {                                                                            \
    ksl_SE3f_printWithOptions(f, m, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL,    \
                              NULL);                                           \
  }

void ksl_SE3f_printWithOptions(FILE* f, const ksl_SE3f_t* restrict r, ...) {
  va_list arguments;
  va_start(arguments, r);
  const char* label = va_arg(arguments, const char*);
  const ksl_print_options_t* options = va_arg(arguments, ksl_print_options_t*);
  va_end(arguments);
  if(!options) {
    // printf("  using global print options\n");
    options = &__ksl_print_options;
  }
  // else {
  // printf("  using user specified print
  // options\n");
  // }
  int label_length = 0;
  if(label) {
    fprintf(f, "%s", label);
    label_length = strlen(label);
  }
  int lead_in_length = label_length + strlen(options->outer_left_bracket);
  fprintf(f, "%s", options->outer_left_bracket);
  for(int i = 0; i < 3; i++) {
    fprintf(f, "%s", options->inner_left_bracket);
    for(int j = 0; j < 2; j++) {
      switch(options->print_row_column_major) {
        case KSL_ROW_MAJOR: {
          fprintf(f, options->real_fmt, r->as_array[j][i]);
          fprintf(f, "%s", options->delimiter);
          break;
        }
        case KSL_COLUMN_MAJOR: {
          fprintf(f, options->real_fmt, r->as_array[i][j]);
          fprintf(f, "%s", options->delimiter);
          break;
        }
      }
      switch(options->print_row_column_major) {
        case KSL_ROW_MAJOR: {
          fprintf(f, options->real_fmt, r->as_array[2][i]);
          break;
        }
        case KSL_COLUMN_MAJOR: {
          fprintf(f, options->real_fmt, r->as_array[i][2]);
          break;
        }
      }
    }
    fprintf(f, "%s%s", options->inner_right_bracket, options->delimiter);
    if(options->line_breaks_in_matrices && i < 2) {
      fprintf(f, "\n");
      for(int j = 0; j < lead_in_length; j++) {
        fprintf(f, " ");
      }
    }
  }
  fprintf(f, "%s", options->outer_right_bracket);
  fprintf(f, "\n");
}

#ifndef NDEBUG
#define ksl_mat4x4_debug(f, m, ...)                                            \
  do {                                                                         \
    ksl_mat4x4_printWithOptions(f, m, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL,  \
                                NULL);                                         \
  } while(0)
#else
#define ksl_mat4x4_debug(f, m, ...)                                            \
  do {                                                                         \
  } while(0)
#endif

#define ksl_mat4x4_print(f, m, ...)                                            \
  {                                                                            \
    ksl_mat4x4_printWithOptions(f, m, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL,  \
                                NULL);                                         \
  }

void ksl_mat4x4_printWithOptions(FILE* f, const ksl_mat4x4_t* restrict r, ...) {
  va_list arguments;
  va_start(arguments, r);
  const char* label = va_arg(arguments, const char*);
  const ksl_print_options_t* options = va_arg(arguments, ksl_print_options_t*);
  va_end(arguments);
  if(!options) {
    // printf("  using global print options\n");
    options = &__ksl_print_options;
  }
  // else {
  // printf("  using user specified print
  // options\n");
  // }
  int label_length = 0;
  if(label) {
    fprintf(f, "%s", label);
    label_length = strlen(label);
  }
  int lead_in_length = label_length + strlen(options->outer_left_bracket);
  fprintf(f, "%s", options->outer_left_bracket);
  for(int i = 0; i < 4; i++) {
    fprintf(f, "%s", options->inner_left_bracket);
    for(int j = 0; j < 3; j++) {
      switch(options->print_row_column_major) {
        case KSL_ROW_MAJOR: {
          fprintf(f, options->real_fmt, r->as_array[j][i]);
          fprintf(f, "%s", options->delimiter);
          break;
        }
        case KSL_COLUMN_MAJOR: {
          fprintf(f, options->real_fmt, r->as_array[i][j]);
          fprintf(f, "%s", options->delimiter);
          break;
        }
      }
      switch(options->print_row_column_major) {
        case KSL_ROW_MAJOR: {
          fprintf(f, options->real_fmt, r->as_array[3][i]);
          break;
        }
        case KSL_COLUMN_MAJOR: {
          fprintf(f, options->real_fmt, r->as_array[i][3]);
          break;
        }
      }
    }
    fprintf(f, "%s%s", options->inner_right_bracket, options->delimiter);
    if(options->line_breaks_in_matrices && i < 2) {
      fprintf(f, "\n");
      for(int j = 0; j < lead_in_length; j++) {
        fprintf(f, " ");
      }
    }
  }
  fprintf(f, "%s", options->outer_right_bracket);
  fprintf(f, "\n");
}

#ifndef NDEBUG
#define ksl_mat4x4f_debug(f, m, ...)                                           \
  do {                                                                         \
    ksl_mat4x4f_printWithOptions(f, m, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL, \
                                 NULL);                                        \
  } while(0)
#else
#define ksl_mat4x4f_debug(f, m, ...)                                           \
  do {                                                                         \
  } while(0)
#endif

#define ksl_mat4x4f_print(f, m, ...)                                           \
  {                                                                            \
    ksl_mat4x4f_printWithOptions(f, m, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL, \
                                 NULL);                                        \
  }

void ksl_mat4x4f_printWithOptions(FILE* f, const ksl_mat4x4_t* restrict r,
                                  ...) {
  va_list arguments;
  va_start(arguments, r);
  const char* label = va_arg(arguments, const char*);
  const ksl_print_options_t* options = va_arg(arguments, ksl_print_options_t*);
  va_end(arguments);
  if(!options) {
    // printf("  using global print options\n");
    options = &__ksl_print_options;
  }
  // else {
  // printf("  using user specified print
  // options\n");
  // }
  int label_length = 0;
  if(label) {
    fprintf(f, "%s", label);
    label_length = strlen(label);
  }
  int lead_in_length = label_length + strlen(options->outer_left_bracket);
  fprintf(f, "%s", options->outer_left_bracket);
  for(int i = 0; i < 4; i++) {
    fprintf(f, "%s", options->inner_left_bracket);
    for(int j = 0; j < 3; j++) {
      switch(options->print_row_column_major) {
        case KSL_ROW_MAJOR: {
          fprintf(f, options->real_fmt, r->as_array[j][i]);
          fprintf(f, "%s", options->delimiter);
          break;
        }
        case KSL_COLUMN_MAJOR: {
          fprintf(f, options->real_fmt, r->as_array[i][j]);
          fprintf(f, "%s", options->delimiter);
          break;
        }
      }
      switch(options->print_row_column_major) {
        case KSL_ROW_MAJOR: {
          fprintf(f, options->real_fmt, r->as_array[3][i]);
          break;
        }
        case KSL_COLUMN_MAJOR: {
          fprintf(f, options->real_fmt, r->as_array[i][3]);
          break;
        }
      }
    }
    fprintf(f, "%s%s", options->inner_right_bracket, options->delimiter);
    if(options->line_breaks_in_matrices && i < 2) {
      fprintf(f, "\n");
      for(int j = 0; j < lead_in_length; j++) {
        fprintf(f, " ");
      }
    }
  }
  fprintf(f, "%s", options->outer_right_bracket);
  fprintf(f, "\n");
}

#ifndef NDEBUG
#define ksl_array_debug(f, n, a, ...)                                          \
  do {                                                                         \
    ksl_array_printWithOptions(f, n, a,                                        \
                               __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL, NULL);  \
  } while(0)
#else
#define ksl_array_debug(f, n, a, ...)                                          \
  do {                                                                         \
  } while(0)
#endif

#define ksl_array_print(f, n, a, ...)                                          \
  {                                                                            \
    ksl_array_printWithOptions(f, n, a,                                        \
                               __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL, NULL);  \
  }

/*!
@brief utility to print a general array of double
of length n on one line
*/
void ksl_array_printWithOptions(FILE* f, const int n, const double* restrict a,
                                ...) {
  va_list arguments;
  va_start(arguments, a);
  const char* label = va_arg(arguments, const char*);
  const ksl_print_options_t* options = va_arg(arguments, ksl_print_options_t*);
  va_end(arguments);
  if(!options) {
    // printf("  using global print options\n");
    options = &__ksl_print_options;
  }
  if(label) {
    fprintf(f, "%s", label);
  }
  fprintf(f, "%s", options->inner_left_bracket);
  for(int i = 0; i < n - 1; i++) {
    fprintf(f, options->real_fmt, a[i]);
    fprintf(f, "%s", options->delimiter);
  }
  fprintf(f, options->real_fmt, a[n - 1]);
  fprintf(f, "%s", options->inner_right_bracket);
  fprintf(f, "\n");
}

#ifndef NDEBUG
#define ksl_array2D_debug(f, n, m, a, ...)                                     \
  do {                                                                         \
    ksl_array2D_printWithOptions(                                              \
      f, n, m, a, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL, NULL);               \
  } while(0)
#else
#define ksl_array2D_debug(f, n, m, a, ...)                                     \
  do {                                                                         \
  } while(0)
#endif

#define ksl_array2D_print(f, n, m, a, ...)                                     \
  {                                                                            \
    ksl_array2D_printWithOptions(                                              \
      f, n, m, a, __VA_ARGS__ VA_COMMA(__VA_ARGS__) NULL, NULL);               \
  }

/*!
@brief utility to print a 2D array stored in a
single pointer with dimension rowDim * colDim
*/
void ksl_array2D_printWithOptions(FILE* f, const int rowDim, const int colDim,
                                  double* restrict A, ...) {

  va_list arguments;
  va_start(arguments, A);
  const char* label = va_arg(arguments, const char*);
  const ksl_print_options_t* options = va_arg(arguments, ksl_print_options_t*);
  va_end(arguments);
  if(!options) {
    // printf("  using global print options\n");
    options = &__ksl_print_options;
  }
  if(label) {
    fprintf(f, "%s", label);
  }
  switch(options->print_row_column_major) {
    case KSL_ROW_MAJOR: {
      for(int i = 0; i < rowDim; i++) {
        fprintf(f, "  [");
        for(int j = 0; j < colDim; j++) {
          fprintf(f, "% 0.10f", A[i * colDim + j]);
          if(j != colDim - 1) {
            fprintf(f, ", ");
          }
        }
        fprintf(f, "]\n");
      }
    } break;

    case KSL_COLUMN_MAJOR: {
      for(int i = 0; i < rowDim; i++) {
        fprintf(f, "  ");
        for(int j = 0; j < colDim; j++) {
          fprintf(f, "% 0.10f ", A[i + j * rowDim]);
        }
        fprintf(f, "\n");
      }
    } break;
  }
}

/*!
@brief utility to print a general array of
uint32_ts of length n on one line
*/
void ksl_arrayi_print(FILE* f, const int n, const int* restrict a) {

  for(int i = 0; i < n; i++) {
    fprintf(f, "%d ", a[i]);
  }
  fprintf(f, "\n");
}

/*!
@brief utility to print a lower triangular matrix
of doubles stored in a linear array
*/
void ksl_triang_print(FILE* f, const int n, const double* restrict A) {

  for(int i = 0; i < n; i++) {
    int i_s = (i * (i + 1) / 2);
    for(int j = 0; j < i + 1; j++) {
      fprintf(f, "% 9.4f ", A[i_s + j]);
    }
    fprintf(f, "\n");
  }
}

/*!
@brief utility to print a lower triangular matrix
of integers stored in a linear array
*/
void ksl_triangi_print(FILE* f, const int n, const int* restrict A) {

  for(int i = 0; i < n; i++) {
    int i_s = (i * (i + 1) / 2);
    for(int j = 0; j < i + 1; j++) {
      fprintf(f, "% d ", A[i_s + j]);
    }
    fprintf(f, "\n");
  }
}

/*!
@brief utility to print a lower triangular matrix
of uint32_tegers stored in a linear array
*/
void ksl_triangb_print(FILE* f, const int n, const bool* restrict A) {

  for(int i = 0; i < n; i++) {
    int i_s = (i * (i + 1) / 2);
    for(int j = 0; j < i + 1; j++) {
      fprintf(f, "%s ", A[i_s + j] ? "1" : "0");
    }
    fprintf(f, "\n");
  }
}
