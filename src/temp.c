#include <print.h>

int lead_in_length = label_length + strlen(options->outer_left_bracket);
fprintf(f, "%s", options->outer_left_bracket);

switch(options->print_row_column_major) {
  case KSL_PRINT_ROW_MAJOR: {
    for(int i = 0; i < 3; i++) {
      fprintf(f, "%s", options->inner_left_bracket);
    }
    break;
  }
  case KSL_PRINT_COLUMN_MAJOR: {
    for(int i = 0; i < 3; i++) {
      fprintf(f, "%s", options->inner_left_bracket);
    }
    break;
  }
}

for(int i = 0; i < 4; i++) {
  fprintf(f, "%s", options->inner_left_bracket);
  if(i < 3) {
    for(int j = 0; j < 3; j++) {
      switch(options->print_row_column_major) {
        case KSL_PRINT_ROW_MAJOR: {
          if(j < 2) {
            fprintf(f, options->real_fmt, di->as_array[j][i]);
            fprintf(f, "%s", options->delimiter);
          } else {
            fprintf(f, options->real_fmt, di->as_array[j][i]);
          }
          break;
        }
        case KSL_PRINT_COLUMN_MAJOR: {
          if(j < 2) {
            fprintf(f, options->real_fmt, di->as_array[i][j]);
            fprintf(f, "%s", options->delimiter);
          } else {
            fprintf(f, options->real_fmt, di->as_array[i][j]);
          }
          break;
        }
      }
    }
  } else {
    for(int j = 0; j < 3; j++) {
      fprintf(f, options->real_fmt, 0.0);
      fprintf(f, "%s", options->delimiter);
    }
    fprintf(f, options->real_fmt, 1.0);
  }
  fprintf(f, "%s%s", options->inner_right_bracket, options->delimiter);
  if(options->line_breaks_in_matrices && i < 3) {
    fprintf(f, "\n");
    for(int j = 0; j < lead_in_length; j++) {
      fprintf(f, " ");
    }
  }
}
for(int i = 0; i < strlen(options->delimiter); i++) {
  fprintf(f, "\b \b");
}
fprintf(f, "%s", options->outer_right_bracket);
fprintf(f, "\n");
