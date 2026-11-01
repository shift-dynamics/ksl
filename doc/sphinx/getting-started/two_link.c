/* Position and velocity of the tip of a planar two-link arm.

Joint 1 rotates link 1 about the base z axis. Joint 2 is at the end of link 1,
a distance L1 along its x axis, and rotates link 2 about z. The tip is a
distance L2 along the x axis of link 2.

The program prints the tip position and velocity computed with KSL and with
the closed-form expressions, and returns 0 if they agree. */

#include <math.h>
#include <stdio.h>

#include "ksl/ksl.h"
#include "ksl/trig.h"

int main(void) {
  const double L1 = 0.5, L2 = 0.3;          /* link lengths, m */
  const double q1 = 0.4, q2 = -1.1;         /* joint angles, rad */
  const double q1dot = 0.7, q2dot = 1.5;    /* joint rates, rad/s */

  /* Each axis rotation takes the {sin, cos} pair of its angle. */
  double dc1[2], dc2[2];
  ksl_dc(q1, dc1);
  ksl_dc(q2, dc2);

  /* Pose of link 1 in the base frame: D1 = drz(q1). */
  const ksl_SE3_t I = ksl_SE3_identity();
  ksl_SE3_t D1;
  ksl_product_ddrz(&I, dc1, &D1);

  /* Pose of link 2: D2 = D1 * dtx(L1) * drz(q2). The specialized products
     update only the terms that a translation or an axis rotation changes. */
  ksl_SE3_t D1t, D2;
  ksl_product_ddtx(&D1, L1, &D1t);
  ksl_product_ddrz(&D1t, dc2, &D2);

  /* Tip position: p = D2 * {L2, 0, 0}. */
  const ksl_vec3_t tip_local = {.x = L2, .y = 0.0, .z = 0.0};
  ksl_vec3_t p;
  ksl_product_dv(&D2, &tip_local, &p);

  /* Joint axis screws in the base frame, hs = Ad(D) * {0, z}. Their linear
     part is the velocity of the point at the base origin for a unit joint
     rate. */
  ksl_screw_t h1, h2;
  ksl_hsrz(&D1, &h1);
  ksl_hsrz(&D2, &h2);

  /* Velocity screw of link 2: V = h1 * q1dot + h2 * q2dot. */
  ksl_screw_t V;
  ksl_product_as(q1dot, &h1, &V);
  ksl_axpy_ss(q2dot, &h2, &V);

  /* Velocity of the tip: v = V.lin + V.ang x p. */
  ksl_vec3_t w_x_p, v;
  ksl_cross_vv(&V.ang, &p, &w_x_p);
  ksl_add_vv(&V.lin, &w_x_p, &v);

  /* Closed-form results for comparison. */
  const double q12 = q1 + q2, q12dot = q1dot + q2dot;
  const double px = L1 * cos(q1) + L2 * cos(q12);
  const double py = L1 * sin(q1) + L2 * sin(q12);
  const double vx = -L1 * sin(q1) * q1dot - L2 * sin(q12) * q12dot;
  const double vy = L1 * cos(q1) * q1dot + L2 * cos(q12) * q12dot;

  printf("tip position  ksl: % .6f % .6f % .6f\n", p.x, p.y, p.z);
  printf("        closed form: % .6f % .6f % .6f\n", px, py, 0.0);
  printf("tip velocity  ksl: % .6f % .6f % .6f\n", v.x, v.y, v.z);
  printf("        closed form: % .6f % .6f % .6f\n", vx, vy, 0.0);

  const double tol = 1e-12;
  const int ok = fabs(p.x - px) < tol && fabs(p.y - py) < tol &&
                 fabs(p.z) < tol && fabs(v.x - vx) < tol &&
                 fabs(v.y - vy) < tol && fabs(v.z) < tol;
  return ok ? 0 : 1;
}
