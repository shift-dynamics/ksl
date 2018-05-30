#include "coscrew.h"
#include "matrix.h"
#include "screw.h"
#include <print.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*!
@}
@name Functions to set print options
@{
*/

static ksl_print_options_t __ksl_print_options = {
  ", ",         "%0.6g", "%d", "true", "false",
  "[",          "]",     "[",  "]",    KSL_BREAK_BETWEEN_LINES,
  KSL_ROW_MAJOR};

/*!
@brief used to set delimiter used in display of matrices, vectors, etc.
@param delimiter [in] a
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL, the options are set in the global print
options. This second argument is required in this function.
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

/*!
@brief used to set format for display of float and double values
@param fmt [in]
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL, the options are set in the global print
options. This second argument is required in this function.
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

/*!
@brief used to set inner brackets in dispay of matrices
@param left [in] left bracket
@param right [in] right bracket
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL, the options are set in the global print
options. This second argument is required in this function.
*/
void ksl_print_setInnerBracketsOption(const char* left, const char* right,
                                      ...) {
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

/*!
@brief used to set outer brackets in dispay of matrices
@param left [in] left bracket
@param right [in] right bracket
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL, the options are set in the global print
options. This second argument is required in this function.
*/
void ksl_print_setOuterBracketsOption(const char* left, const char* right,
                                      ...) {
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

/*!
@brief used to set "BreakBetweenLinesInMatrix" option for dispay of matrices
@param val [in] valid inputs are KSL_BREAK_BETWEEN_LINES or
KSL_NO_BREAK_BETWEEN_LINES
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL, the options are set in the global print
options. This second argument is required in this function.
*/
void ksl_print_setBreakBetweenLinesInMatrixOption(
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

/*!
@brief used to set "RowColumnMajorPrinting" option for dispay of matrices
@param val [in] valid inputs are KSL_ROW_MAJOR or KSL_COLUMN_MAJOR
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL, the options are set in the global print
options. This second argument is required in this function.
*/
void ksl_print_setRowColumnMajorPrintingOption(
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
freed by user.
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

/*!
@brief print a ksl_vec3_t data structure with user defined label and options.
This function intended to be called by the helper macros ksl_vec3_debug and
ksl_vec3_print macros. In this function the label and options arguments are
required.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_vec3_t datastructure
@param label [in] pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL, the options are set in the global
print options. To pass an options struct with no label, call
ksl_vec3_print(f, v, NULL, options); or ksl_vec3_print(f, v, "", options);
*/
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

/*!
@brief print a ksl_vec3f_t data structure with user defined label and options.
This function intended to be called by the helper macros ksl_vec3f_debug and
ksl_vec3f_print macros. In this function the label and options arguments are
required.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_vec3f_t datastructure
@param label [in] pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct containing print
options. If the pointer is NULL, the options are set in the global
print options. To pass an options struct with no label, call
ksl_vec3f_print(f, v, NULL, options); or ksl_vec3f_print(f, v, "", options);
*/
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

/*!
@brief print a ksl_mat3x3_t data structure. This function is intended to be
called by the helper macros ksl_mat3x3_debug and
ksl_mat3x3_print macros. In this function the label and options arguments are
required.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_mat3x3_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] an optional pointer to a ksl_print_options_t struct
containing print options. If the pointer is NULL or not present, the options
are set in the global print options.
*/
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
    fprintf(f, "%s", options->inner_right_bracket);
    if(i != 2) {
      fprintf(f, "%s", options->delimiter);
    }
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

/*!
@brief print a ksl_mat3x3f_t data structure with user defined label and options.
This function is intended to be called by the helper macros ksl_mat3x3f_debug
and ksl_mat3x3f_print macros. In this function the label and options arguments
are required.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_mat3x3f_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] an optional pointer to a ksl_print_options_t struct
containing print options. If the pointer is NULL or not present, the options
are set in the global print options.
*/
void ksl_mat3x3f_printWithOptions(FILE* f, const ksl_mat3x3f_t* restrict r,
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
    fprintf(f, "%s", options->inner_right_bracket);
    if(i != 2) {
      fprintf(f, "%s", options->delimiter);
    }
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

/*!
@brief print a ksl_quaternion_t data structure with user defined label and
options. This function is intended to be called by the ksl_quaternion_debug and
ksl_quaternion_print macros. In this function the label and options arguments
are required.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_quaternion_t datastructure
@param label [in] optional pointer to a const char* label
@param options [in] an optional pointer to a ksl_print_options_t struct
containing print options. If the pointer is NULL or not present, the options
are set in the global print options.
*/
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

/*!
@brief print a ksl_quaternionf_t data structure with user defined label and
options. This function is intended to be called by the ksl_quaternionf_debug and
ksl_quaternionf_print macros. In this function the label and options arguments
are required.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_quaternionf_t datastructure
@param label [in] pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct
containing print options. If the pointer is NULL, the options
are set in the global print options.
*/
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

/*!
@brief print a ksl_screw_t data structure with user defined label and options.
This function is intended to be called by the ksl_screw_debug and
ksl_screw_print macros. In this function the label and options arguments are
required.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_screw_t datastructure
@param label [in] pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct
containing print options. If the pointer is NULL, the options
are set in the global print options.
*/
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

/*!
@brief print a ksl_screwf_t data structure with user defined label and options.
This function is intended to be called by the ksl_screwf_debug and
ksl_screwf_print macros. In this function the label and options arguments are
required.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_screwf_t datastructure
@param label [in] pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct
containing print options. If the pointer is NULL, the options
are set in the global print options.
*/
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

/*!
@brief print a ksl_coscrew_t data structure with user defined label and options.
This function is intended to be called by the ksl_coscrew_debug and
ksl_coscrewf_print macros. In this function the label and options arguments are
required.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_coscrew_t datastructure
@param label [in] pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct
containing print options. If the pointer is NULL, the options
are set in the global print options.
*/
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

/*!
@brief print a ksl_coscrewf_t data structure with user defined label and
options. This function is intended to be called by the ksl_coscrewf_debug and
ksl_coscrewf_print macros. In this function the label and options arguments are
required.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_coscrew_t datastructure
@param label [in] pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct
containing print options. If the pointer is NULL, the options
are set in the global print options.
*/
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

/*!
@brief print a ksl_SE3_t data structure with user defined label and options.
This function is intended to be called by the ksl_SE3_debug and
ksl_SE3_print macros. In this function the label and options arguments are
required.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_SE3_t datastructure
@param label [in] pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct
containing print options. If the pointer is NULL, the options
are set globally.
*/
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

/*!
@brief print a ksl_SE3f_t data structure with user defined label and options.
This function is intended to be called by the ksl_SE3f_debug and
ksl_SE3f_print macros. In this function the label and options arguments are
required.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_SE3f_t datastructure
@param label [in] pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct
containing print options. If the pointer is NULL, the options
are set globally.
*/
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

/*!
@brief print a ksl_mat4x4_t data structure with user defined label and options.
This function is intended to be called by the ksl_mat4x4_debug and
ksl_mat4x4_print macros. In this function the label and options arguments are
required.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_mat4x4_t datastructure
@param label [in] pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct
containing print options. If the pointer is NULL, the options
are set globally.
*/
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

/*!
@brief print a ksl_mat4x4f_t data structure with user defined label and options.
This function is intended to be called by the ksl_mat4x4f_debug and
ksl_mat4x4f_print macros. In this function the label and options arguments are
required.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param v [in] a pointer to a ksl_mat4x4f_t datastructure
@param label [in] pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct
containing print options. If the pointer is NULL, the options
are set are set globally.
*/
void ksl_mat4x4f_printWithOptions(FILE* f, const ksl_mat4x4f_t* restrict r,
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

/*!
@brief print a double precision array user defined label and options.
This function is intended to be called by the ksl_array_debug and
ksl_array_print macros. In this function the label and options arguments are
required.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param n [in] number of values to print
@param a [in] a double precision poiinter
@param label [in] pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct
containing print options. If the pointer is NULL, the options
are set globally.
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

/*!
@brief print a double precision 2D array user defined label and options.
This function is intended to be called by the ksl_array2D_debug and
ksl_array2D_print macros. In this function the label and options arguments are
required.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param rowDim [in] row dimension
@param colDim [in] column dimension
@param A [in] a double precision poiinter
@param label [in] pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct
containing print options. If the pointer is NULL, the options
are set globally.
*/
void ksl_array2D_printWithOptions(FILE* f, const int rowDim, const int colDim,
                                  const double* restrict A, ...) {

  va_list arguments;
  va_start(arguments, A);
  const char* label = va_arg(arguments, const char*);
  const ksl_print_options_t* options = va_arg(arguments, ksl_print_options_t*);
  va_end(arguments);
  if(!options) {
    // printf("  using global print options\n");
    options = &__ksl_print_options;
  }
  int label_length = 0;
  if(label) {
    fprintf(f, "%s", label);
    label_length = strlen(label);
  }
  int lead_in_length = label_length + strlen(options->outer_left_bracket);
  switch(options->print_row_column_major) {
    case KSL_ROW_MAJOR: {
      fprintf(f, "%s", options->outer_left_bracket);
      for(int i = 0; i < rowDim; i++) {
        fprintf(f, "%s", options->inner_left_bracket);
        for(int j = 0; j < colDim; j++) {
          fprintf(f, options->real_fmt, A[i * colDim + j]);
          if(j != colDim - 1) {
            fprintf(f, "%s", options->delimiter);
          }
        }
        fprintf(f, "%s", options->inner_right_bracket);
        if(i != rowDim - 1) {
          fprintf(f, "%s", options->delimiter);

          if(options->line_breaks_in_matrices) {
            fprintf(f, "\n");
            for(int j = 0; j < lead_in_length; j++) {
              fprintf(f, " ");
            }
          }
        }
      }
      fprintf(f, "%s", options->outer_right_bracket);
      fprintf(f, "\n");
      break;
    }
    case KSL_COLUMN_MAJOR: {
      fprintf(f, "%s", options->outer_left_bracket);
      for(int i = 0; i < rowDim; i++) {
        fprintf(f, "%s", options->inner_left_bracket);
        for(int j = 0; j < colDim; j++) {
          fprintf(f, options->real_fmt, A[i + j * rowDim]);
          if(j != colDim - 1) {
            fprintf(f, "%s", options->delimiter);
          }
        }
        fprintf(f, "%s", options->inner_right_bracket);
        if(i != rowDim - 1) {
          fprintf(f, "%s", options->delimiter);

          if(options->line_breaks_in_matrices) {
            fprintf(f, "\n");
            for(int j = 0; j < lead_in_length; j++) {
              fprintf(f, " ");
            }
          }
        }
      }
      fprintf(f, "%s", options->outer_right_bracket);
      fprintf(f, "\n");
      break;
    }
  }
}

/*!
@brief print an array of integers with user defined label and options.
This function is intended to be called by the ksl_arrayi_debug and
ksl_arrayi_print macros. In this function the label and options arguments are
required.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param n [in] number of values to print
@param a [in] array of integers
@param label [in] pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct
containing print options. If the pointer is NULL, the options
are set globally.
*/
void ksl_arrayi_printWithOptions(FILE* f, const int n, const int* restrict a,
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

  for(int i = 0; i < n - 1; i++) {
    fprintf(f, options->int_fmt, a[i]);
    fprintf(f, "%s", options->delimiter);
  }
  fprintf(f, options->int_fmt, a[n - 1]);
  fprintf(f, "\n");
}

/*!
@brief print a lower triangular double precision matrix stored in contiguous
memory with user defined label and options.
This function is intended to be called by the ksl_triang_debug and
ksl_triang_print macros. In this function the label and options arguments are
required.
@param f [in] a file pointer (e.g. stdout, stderr, etc.)
@param n [in] row/column dimension of nxn matrix
@param a [in] array of double precision values
@param label [in] pointer to a const char* label
@param options [in] a pointer to a ksl_print_options_t struct
containing print options. If the pointer is NULL, the options
are set globally.
*/
void ksl_triang_printWithOptions(FILE* f, const int n, const double* restrict a,
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
    fprintf(f, "%s\n", label);
  }

  for(int i = 0; i < n; i++) {
    int i_s = (i * (i + 1) / 2);
    for(int j = 0; j < i + 1; j++) {
      fprintf(f, options->real_fmt, a[i_s + j]);
      if(j != i) {
        fprintf(f, "%s", options->delimiter);
      }
    }
    fprintf(f, "\n");
  }
}

/*!
@brief utility to print a lower triangular matrix
of integers stored in a linear array
*/
void ksl_triangi_printWithOptions(FILE* f, const int n, const int* restrict a,
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
    fprintf(f, "%s\n", label);
  }

  for(int i = 0; i < n; i++) {
    int i_s = (i * (i + 1) / 2);
    for(int j = 0; j < i + 1; j++) {
      fprintf(f, options->int_fmt, a[i_s + j]);
      if(i != j) {
        fprintf(f, "%s", options->delimiter);
      }
    }
    fprintf(f, "\n");
  }
}

/*!
@brief utility to print a lower triangular matrix
of integers stored in a linear array
*/
void ksl_triangb_printWithOptions(FILE* f, const int n, const bool* restrict a,
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
    fprintf(f, "%s\n", label);
  }

  for(int i = 0; i < n; i++) {
    int i_s = (i * (i + 1) / 2);
    for(int j = 0; j < i + 1; j++) {
      fprintf(f, "%s", a[i_s + j] ? options->true_fmt : options->false_fmt);
    }
    fprintf(f, "\n");
  }
}

/*!
@brief print a full 6x6 spatial inertia matrix
*/
void ksl_inertia_printWithOptions(FILE* f, const ksl_inertia_t* inertia, ...) {
  va_list arguments;
  va_start(arguments, inertia);
  const char* label = va_arg(arguments, const char*);
  const ksl_print_options_t* options = va_arg(arguments, ksl_print_options_t*);
  va_end(arguments);
  if(!options) {
    options = &__ksl_print_options;
  }
  int label_length = 0;
  if(label) {
    fprintf(f, "%s", label);
    label_length = strlen(label);
  }
  int lead_in_length = label_length + strlen(options->outer_left_bracket);
  fprintf(f, "%s", options->outer_left_bracket);

  /* [ m  0  0]  [ 0 -z  y]
     [ 0  m  0]  [ z  0 -x]
     [ 0  0  m]  [-y  x  0] */

  /* first row */
  fprintf(f, "%s", options->inner_left_bracket);
  fprintf(f, options->real_fmt, inertia->m);
  fprintf(f, "%s", options->delimiter);
  fprintf(f, options->real_fmt, 0.0);
  fprintf(f, "%s", options->delimiter);
  fprintf(f, options->real_fmt, 0.0);
  fprintf(f, "%s", options->delimiter);

  fprintf(f, options->real_fmt, 0.0);
  fprintf(f, "%s", options->delimiter);
  fprintf(f, options->real_fmt, -inertia->mt.z);
  fprintf(f, "%s", options->delimiter);
  fprintf(f, options->real_fmt, inertia->mt.y);
  fprintf(f, "%s", options->inner_right_bracket);
  fprintf(f, "%s", options->delimiter);
  if(options->line_breaks_in_matrices == KSL_BREAK_BETWEEN_LINES) {
    fprintf(f, "\n");
    for(int j = 0; j < lead_in_length; j++) {
      fprintf(f, " ");
    }
  }

  /* second row */
  fprintf(f, "%s", options->inner_left_bracket);
  fprintf(f, options->real_fmt, 0.0);
  fprintf(f, "%s", options->delimiter);
  fprintf(f, options->real_fmt, inertia->m);
  fprintf(f, "%s", options->delimiter);
  fprintf(f, options->real_fmt, 0.0);
  fprintf(f, "%s", options->delimiter);

  fprintf(f, options->real_fmt, inertia->mt.z);
  fprintf(f, "%s", options->delimiter);
  fprintf(f, options->real_fmt, 0.0);
  fprintf(f, "%s", options->delimiter);
  fprintf(f, options->real_fmt, -inertia->mt.x);
  fprintf(f, "%s", options->inner_right_bracket);
  fprintf(f, "%s", options->delimiter);

  if(options->line_breaks_in_matrices == KSL_BREAK_BETWEEN_LINES) {
    fprintf(f, "\n");
    for(int j = 0; j < lead_in_length; j++) {
      fprintf(f, " ");
    }
  }

  /* third row */
  fprintf(f, "%s", options->inner_left_bracket);
  fprintf(f, options->real_fmt, 0.0);
  fprintf(f, "%s", options->delimiter);
  fprintf(f, options->real_fmt, 0.0);
  fprintf(f, "%s", options->delimiter);
  fprintf(f, options->real_fmt, inertia->m);
  fprintf(f, "%s", options->delimiter);

  fprintf(f, options->real_fmt, -inertia->mt.y);
  fprintf(f, "%s", options->delimiter);
  fprintf(f, options->real_fmt, inertia->mt.x);
  fprintf(f, "%s", options->delimiter);
  fprintf(f, options->real_fmt, 0.0);
  fprintf(f, "%s", options->inner_right_bracket);
  fprintf(f, "%s", options->delimiter);

  if(options->line_breaks_in_matrices == KSL_BREAK_BETWEEN_LINES) {
    fprintf(f, "\n");
    for(int j = 0; j < lead_in_length; j++) {
      fprintf(f, " ");
    }
  }

  /* [ 0  z -y]  [Ixx Ixy Ixz]
     [-z  0  x]  [Iyx Iyy Iyz]
     [ y -x  0]  [Izx Izy Izz]*/

  /* fourth row */
  fprintf(f, "%s", options->inner_left_bracket);
  fprintf(f, options->real_fmt, 0.0);
  fprintf(f, "%s", options->delimiter);
  fprintf(f, options->real_fmt, inertia->mt.z);
  fprintf(f, "%s", options->delimiter);
  fprintf(f, options->real_fmt, -inertia->mt.y);
  fprintf(f, "%s", options->delimiter);
  fprintf(f, options->real_fmt, inertia->Ixx);
  fprintf(f, "%s", options->delimiter);
  fprintf(f, options->real_fmt, inertia->Ixy);
  fprintf(f, "%s", options->delimiter);
  fprintf(f, options->real_fmt, inertia->Ixz);
  fprintf(f, "%s", options->inner_right_bracket);
  fprintf(f, "%s", options->delimiter);
  if(options->line_breaks_in_matrices == KSL_BREAK_BETWEEN_LINES) {
    fprintf(f, "\n");
    for(int j = 0; j < lead_in_length; j++) {
      fprintf(f, " ");
    }
  }

  /* fifth row */
  fprintf(f, "%s", options->inner_left_bracket);
  fprintf(f, options->real_fmt, -inertia->mt.z);
  fprintf(f, "%s", options->delimiter);
  fprintf(f, options->real_fmt, 0.0);
  fprintf(f, "%s", options->delimiter);
  fprintf(f, options->real_fmt, inertia->mt.x);
  fprintf(f, "%s", options->delimiter);
  fprintf(f, options->real_fmt, inertia->Iyx);
  fprintf(f, "%s", options->delimiter);
  fprintf(f, options->real_fmt, inertia->Iyy);
  fprintf(f, "%s", options->delimiter);
  fprintf(f, options->real_fmt, inertia->Iyz);
  fprintf(f, "%s", options->inner_right_bracket);
  fprintf(f, "%s", options->delimiter);
  if(options->line_breaks_in_matrices == KSL_BREAK_BETWEEN_LINES) {
    fprintf(f, "\n");
    for(int j = 0; j < lead_in_length; j++) {
      fprintf(f, " ");
    }
  }

  /* sixth row */
  fprintf(f, "%s", options->inner_left_bracket);
  fprintf(f, options->real_fmt, inertia->mt.y);
  fprintf(f, "%s", options->delimiter);
  fprintf(f, options->real_fmt, -inertia->mt.x);
  fprintf(f, "%s", options->delimiter);
  fprintf(f, options->real_fmt, 0.0);
  fprintf(f, "%s", options->delimiter);
  fprintf(f, options->real_fmt, inertia->Izx);
  fprintf(f, "%s", options->delimiter);
  fprintf(f, options->real_fmt, inertia->Izy);
  fprintf(f, "%s", options->delimiter);
  fprintf(f, options->real_fmt, inertia->Izz);
  fprintf(f, "%s", options->inner_right_bracket);
  fprintf(f, "%s", options->outer_right_bracket);
  fprintf(f, "\n");
}

/*!
@}
*/
