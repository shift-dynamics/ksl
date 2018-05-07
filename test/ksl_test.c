#include "ksl.h"
#include <stdio.h>

int main() {

  /* examples of accessing quantities in various data structues */
  ksl_quaternion_t q = {{1.0, 2.0, 3.0, 4.0}};
  printf("%g, %g, %g, %g\n", q.x, q.y, q.z, q.w);
  printf("%g, %g, %g, %g\n", q.r.x, q.r.y, q.r.z, q.w);
  printf("%g, %g, %g, %g\n", q.r.at[0], q.r.at[1], q.r.at[2], q.w);
  printf("%g, %g, %g, %g\n", q.at[0], q.at[1], q.at[2], q.at[3]);
  printf("\n");

  ksl_screw_t s = {{1.0, 2.0, 3.0, 4.0, 5.0, 6.0}};
  printf("%g, %g, %g, %g, %g, %g\n", s.lin.x, s.lin.y, s.lin.z, s.ang.x,
         s.ang.y, s.ang.z);
  printf("%g, %g, %g, %g, %g, %g\n", s.lin.at[0], s.lin.at[1], s.lin.at[2],
         s.ang.at[0], s.ang.at[1], s.ang.at[2]);
  printf("%g, %g, %g, %g, %g, %g\n", s.at[0], s.at[1], s.at[2], s.at[3],
         s.at[4], s.at[5]);
  printf("\n");

  /* SE3/SE4 matrices are specified in column major order */
  ksl_SE3_t D = {
    {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0}};
  for(int i = 0; i < 3; i++) {   /* row index */
    for(int j = 0; j < 4; j++) { /* column index */
      printf("%g ", D.at[i + j * 3]);
    }
    printf("\n");
  }
  printf("\n");

  for(int i = 0; i < 3; i++) {   /* row index */
    for(int j = 0; j < 4; j++) { /* column index */
      printf("%g ", D.as_array[j][i]);
    }
    printf("\n");
  }

  /* example of using level 1 matrix vector ksl functions */
  ksl_mat3x3_t r = {{1, 2, 3, 4, 5, 6, 7, 8, 9}};
  ksl_vec3_t v = {{1, 2, 3}};
  ksl_vec3_t vo;
  ksl_product_drinvv(&r, &v, &vo);
  ksl_mat3x3_print(stdout, &r);
  ksl_vec3_print(stdout, &v);
  ksl_vec3_print(stdout, &vo);

  ksl_product_drvtx(&r, 0.5, &vo);
  ksl_vec3_print(stdout, &vo);
}
