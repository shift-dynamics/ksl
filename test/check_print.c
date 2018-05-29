#include "ksl.h"

#include <stdlib.h>
#include <stdio.h>

int main() {

  ksl_print_options_t* options = ksl_print_options();

  ksl_vec3_t v = {{1.0, 2.0, 3.0}};
  ksl_vec3_print(stdout, &v);

}
