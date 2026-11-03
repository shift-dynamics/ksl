#include <config.h>
#include <stdlib.h>

#include <assert.h>
#include <check.h>
#include <float.h>
#include <stdio.h>
#include <time.h>

#include <math.h>

#include "ksl/matrix.h"
#include "ksl/quaternion.h"

static ksl_quaternion_t make_test_quaternion(double ax, double ay, double az,
                                             double angle) {
  ksl_vec3_t axis = ksl_vec3(ax, ay, az);
  ksl_vec3_normalize(&axis);
  double s = sin(0.5 * angle);
  return ksl_quaternion(axis.x * s, axis.y * s, axis.z * s, cos(0.5 * angle));
}

static ksl_quaternion_t quaternion_conj(const ksl_quaternion_t* q) {
  return ksl_quaternion(-q->x, -q->y, -q->z, q->w);
}

START_TEST(test_quaternion_create) {
  ksl_quaternion_t q = {{1.0, 2.0, 3.0, 4.0}};
  ck_assert(q.x == q.at[0]);
  ck_assert(q.y == q.at[1]);
  ck_assert(q.z == q.at[2]);
  ck_assert(q.w == q.at[3]);
}
END_TEST

START_TEST(test_quaternion_product_qq) {
  /* R(q1 * q2) == R(q1) * R(q2) */
  ksl_quaternion_t q1 = make_test_quaternion(1.0, 2.0, 3.0, 0.7);
  ksl_quaternion_t q2 = make_test_quaternion(-0.5, 0.3, 0.9, 1.9);
  ksl_quaternion_t q3;
  ksl_product_qq(&q1, &q2, &q3);

  ksl_mat3x3_t r1, r2, r3, expected;
  ksl_quaternion_toMat3x3(&q1, &r1);
  ksl_quaternion_toMat3x3(&q2, &r2);
  ksl_quaternion_toMat3x3(&q3, &r3);
  ksl_product_drdr(&r1, &r2, &expected);

  for(int i = 0; i < 9; i++) {
    ck_assert_double_eq_tol(r3.as_array[i], expected.as_array[i], 1e-9);
  }
}
END_TEST

START_TEST(test_quaternion_product_qconjq) {
  ksl_quaternion_t q1 = make_test_quaternion(1.0, 2.0, 3.0, 0.7);
  ksl_quaternion_t q2 = make_test_quaternion(-0.5, 0.3, 0.9, 1.9);
  ksl_quaternion_t q1c = quaternion_conj(&q1);
  ksl_quaternion_t expected;
  ksl_product_qq(&q1c, &q2, &expected);

  ksl_quaternion_t q3;
  ksl_product_qconjq(&q1, &q2, &q3);

  for(int i = 0; i < 4; i++) {
    ck_assert_double_eq_tol(q3.at[i], expected.at[i], 1e-12);
  }
}
END_TEST

START_TEST(test_quaternion_product_qqconj) {
  ksl_quaternion_t q1 = make_test_quaternion(1.0, 2.0, 3.0, 0.7);
  ksl_quaternion_t q2 = make_test_quaternion(-0.5, 0.3, 0.9, 1.9);
  ksl_quaternion_t q2c = quaternion_conj(&q2);
  ksl_quaternion_t expected;
  ksl_product_qq(&q1, &q2c, &expected);

  ksl_quaternion_t q3;
  ksl_product_qqconj(&q1, &q2, &q3);

  for(int i = 0; i < 4; i++) {
    ck_assert_double_eq_tol(q3.at[i], expected.at[i], 1e-12);
  }
}
END_TEST

START_TEST(test_quaternion_product_qconjqconj) {
  ksl_quaternion_t q1 = make_test_quaternion(1.0, 2.0, 3.0, 0.7);
  ksl_quaternion_t q2 = make_test_quaternion(-0.5, 0.3, 0.9, 1.9);
  ksl_quaternion_t q1c = quaternion_conj(&q1);
  ksl_quaternion_t q2c = quaternion_conj(&q2);
  ksl_quaternion_t expected;
  ksl_product_qq(&q1c, &q2c, &expected);

  ksl_quaternion_t q3;
  ksl_product_qconjqconj(&q1, &q2, &q3);

  for(int i = 0; i < 4; i++) {
    ck_assert_double_eq_tol(q3.at[i], expected.at[i], 1e-12);
  }
}
END_TEST

/* Hamilton product written out component by component, independent of the
library, as the reference for the SIMD and scalar implementations */
static void reference_qq(const double a[4], const double b[4], double o[4]) {
  o[0] = a[3] * b[0] + a[0] * b[3] + a[1] * b[2] - a[2] * b[1];
  o[1] = a[3] * b[1] - a[0] * b[2] + a[1] * b[3] + a[2] * b[0];
  o[2] = a[3] * b[2] + a[0] * b[1] - a[1] * b[0] + a[2] * b[3];
  o[3] = a[3] * b[3] - a[0] * b[0] - a[1] * b[1] - a[2] * b[2];
}

START_TEST(test_quaternion_product_reference) {
  /* non-unit quaternions with distinct components, so a wrong sign or lane
  in any of the products shows up */
  const double a[4] = {0.3, -1.7, 2.9, 0.45};
  const double b[4] = {-2.2, 0.8, 1.3, -0.6};
  for(int conj1 = 0; conj1 < 2; conj1++) {
    for(int conj2 = 0; conj2 < 2; conj2++) {
      double ac[4], bc[4], expected[4];
      for(int i = 0; i < 4; i++) {
        ac[i] = (conj1 && i < 3) ? -a[i] : a[i];
        bc[i] = (conj2 && i < 3) ? -b[i] : b[i];
      }
      reference_qq(ac, bc, expected);

      ksl_quaternion_t q1 = {{a[0], a[1], a[2], a[3]}};
      ksl_quaternion_t q2 = {{b[0], b[1], b[2], b[3]}};
      ksl_quaternionf_t q1f = {{a[0], a[1], a[2], a[3]}};
      ksl_quaternionf_t q2f = {{b[0], b[1], b[2], b[3]}};
      ksl_quaternion_t qo;
      ksl_quaternionf_t qof;
      if(!conj1 && !conj2) {
        ksl_product_qq(&q1, &q2, &qo);
        ksl_product_qqf(&q1f, &q2f, &qof);
      } else if(conj1 && !conj2) {
        ksl_product_qconjq(&q1, &q2, &qo);
        ksl_product_qconjqf(&q1f, &q2f, &qof);
      } else if(!conj1 && conj2) {
        ksl_product_qqconj(&q1, &q2, &qo);
        ksl_product_qqconjf(&q1f, &q2f, &qof);
      } else {
        ksl_product_qconjqconj(&q1, &q2, &qo);
        ksl_product_qconjqconjf(&q1f, &q2f, &qof);
      }
      for(int i = 0; i < 4; i++) {
        ck_assert_msg(fabs(qo.at[i] - expected[i]) < 1e-12,
                      "conj1 %d conj2 %d: component %d", conj1, conj2, i);
        ck_assert_msg(fabs(qof.at[i] - expected[i]) < 1e-5,
                      "float conj1 %d conj2 %d: component %d", conj1, conj2, i);
      }
    }
  }
}
END_TEST

START_TEST(test_quaternion_product_vector) {
  /* products of a quaternion with a vector v, treated as the quaternion
  {v, 0}, checked against the reference Hamilton product */
  const double a[4] = {0.3, -1.7, 2.9, 0.45};
  const double v[3] = {-2.2, 0.8, 1.3};
  const double vq[4] = {v[0], v[1], v[2], 0.0};
  const double ac[4] = {-a[0], -a[1], -a[2], a[3]};
  double expected[4][4];
  reference_qq(a, vq, expected[0]);  /* q v */
  reference_qq(ac, vq, expected[1]); /* q* v */
  reference_qq(vq, a, expected[2]);  /* v q */
  reference_qq(vq, ac, expected[3]); /* v q* */

  ksl_quaternion_t q = {{a[0], a[1], a[2], a[3]}};
  ksl_quaternionf_t qf = {{a[0], a[1], a[2], a[3]}};
  ksl_vec3_t vi = ksl_vec3(v[0], v[1], v[2]);
  ksl_vec3f_t vif = ksl_vec3f(v[0], v[1], v[2]);
  ksl_quaternion_t qo[4];
  ksl_quaternionf_t qof[4];
  ksl_product_qv(&q, &vi, &qo[0]);
  ksl_product_qconjv(&q, &vi, &qo[1]);
  ksl_product_vq(&vi, &q, &qo[2]);
  ksl_product_vqconj(&vi, &q, &qo[3]);
  ksl_product_qvf(&qf, &vif, &qof[0]);
  ksl_product_qconjvf(&qf, &vif, &qof[1]);
  ksl_product_vqf(&vif, &qf, &qof[2]);
  ksl_product_vqconjf(&vif, &qf, &qof[3]);
  for(int k = 0; k < 4; k++) {
    for(int i = 0; i < 4; i++) {
      ck_assert_msg(fabs(qo[k].at[i] - expected[k][i]) < 1e-12,
                    "product %d: component %d", k, i);
      ck_assert_msg(fabs(qof[k].at[i] - expected[k][i]) < 1e-5,
                    "float product %d: component %d", k, i);
    }
  }
}
END_TEST

/* largest component difference between a and b, or a and -b, whichever is
smaller: a quaternion and its negative are the same rotation */
static double rotation_difference(const double a[4], const double b[4]) {
  double plus = 0, minus = 0;
  for(int i = 0; i < 4; i++) {
    plus = fmax(plus, fabs(a[i] - b[i]));
    minus = fmax(minus, fabs(a[i] + b[i]));
  }
  return fmin(plus, minus);
}

START_TEST(test_quaternion_slerp) {
  /* rotations about z by 0.3 and 1.3 radians. q2 is negated, so the dot
  product is negative: slerp must still take the shorter path, through the
  rotations about z by 0.3 + t, at a constant rate. The second pair differs
  by 1e-4 radians, which takes the linear branch. */
  const double start[2] = {0.3, 0.3};
  const double span[2] = {1.0, 1e-4};
  for(int pair = 0; pair < 2; pair++) {
    ksl_quaternion_t q1 = make_test_quaternion(0, 0, 1, start[pair]);
    ksl_quaternion_t q2 =
      make_test_quaternion(0, 0, 1, start[pair] + span[pair]);
    for(int i = 0; i < 4; i++) {
      q2.at[i] = -q2.at[i];
    }
    ksl_quaternionf_t q1f = {{q1.x, q1.y, q1.z, q1.w}};
    ksl_quaternionf_t q2f = {{q2.x, q2.y, q2.z, q2.w}};
    for(int k = 0; k <= 4; k++) {
      double t = 0.25 * k;
      float tf = t;
      ksl_quaternion_t qo;
      ksl_quaternionf_t qof;
      ksl_quaternion_slerp(&q1, &q2, &t, &qo);
      ksl_quaternionf_slerp(&q1f, &q2f, &tf, &qof);
      ksl_quaternion_t expected =
        make_test_quaternion(0, 0, 1, start[pair] + t * span[pair]);
      double of[4] = {qof.x, qof.y, qof.z, qof.w};
      ck_assert_msg(rotation_difference(qo.at, expected.at) < 1e-12,
                    "pair %d, t = %g", pair, t);
      ck_assert_msg(rotation_difference(of, expected.at) < 1e-6,
                    "float pair %d, t = %g", pair, t);
    }
  }
}
END_TEST

START_TEST(test_quaternion_log_exp) {
  /* log of a rotation by theta about e is e theta / 2, and exp inverts it,
  including at small angles, where the series are used */
  const double angles[4] = {2.5, 0.7, 1e-3, 1e-8};
  for(int k = 0; k < 4; k++) {
    ksl_quaternion_t q = make_test_quaternion(1.0, -2.0, 0.5, angles[k]);
    ksl_vec3_t e = ksl_vec3(1.0, -2.0, 0.5);
    ksl_vec3_normalize(&e);
    ksl_vec3_t v;
    ksl_quaternion_log(&q, &v);
    for(int i = 0; i < 3; i++) {
      ck_assert_double_eq_tol(v.at[i], 0.5 * angles[k] * e.at[i],
                              1e-12 * angles[k]);
    }
    ksl_quaternion_t qe;
    ksl_quaternion_exp(&v, &qe);
    for(int i = 0; i < 4; i++) {
      ck_assert_double_eq_tol(qe.at[i], q.at[i], 1e-14);
    }

    ksl_quaternionf_t qf = {{q.x, q.y, q.z, q.w}};
    ksl_vec3f_t vf;
    ksl_quaternionf_log(&qf, &vf);
    ksl_quaternionf_t qef;
    ksl_quaternionf_exp(&vf, &qef);
    for(int i = 0; i < 3; i++) {
      ck_assert_double_eq_tol(vf.at[i], v.at[i], 1e-6);
    }
    for(int i = 0; i < 4; i++) {
      ck_assert_double_eq_tol(qef.at[i], q.at[i], 1e-6);
    }
  }
}
END_TEST

/* angular velocity of the squad curve through keys, in the moving frame, by
a one-sided difference of width dt to the right (dt > 0) or left (dt < 0)
of t */
static ksl_vec3_t squad_rate(const int n, const ksl_quaternion_t* keys,
                             const double t, const double dt) {
  double t1 = t, t2 = t + dt;
  ksl_quaternion_t q1, q2, d;
  ksl_quaternion_squad_keys(n, keys, &t1, &q1);
  ksl_quaternion_squad_keys(n, keys, &t2, &q2);
  ksl_product_qconjq(&q1, &q2, &d);
  if(d.w < 0) {
    for(int i = 0; i < 4; i++) {
      d.at[i] = -d.at[i];
    }
  }
  ksl_vec3_t v;
  ksl_quaternion_log(&d, &v);
  return ksl_vec3(2 * v.x / dt, 2 * v.y / dt, 2 * v.z / dt);
}

START_TEST(test_quaternion_squad_keys) {
  /* keys at rotations about z by 0.4 k, with every other key negated: the
  control points equal the keys, and squad reduces to rotation about z at a
  constant rate, 0.4 t */
  ksl_quaternion_t keys[5];
  ksl_quaternionf_t keysf[5];
  for(int k = 0; k < 5; k++) {
    keys[k] = make_test_quaternion(0, 0, 1, 0.4 * k);
    if(k % 2) {
      for(int i = 0; i < 4; i++) {
        keys[k].at[i] = -keys[k].at[i];
      }
    }
    keysf[k] = ksl_quaternionf(keys[k].x, keys[k].y, keys[k].z, keys[k].w);
  }
  for(int j = -2; j <= 18; j++) {
    double t = 0.25 * j;
    float tf = t;
    ksl_quaternion_t qo;
    ksl_quaternionf_t qof;
    ksl_quaternion_squad_keys(5, keys, &t, &qo);
    ksl_quaternionf_squad_keys(5, keysf, &tf, &qof);
    double tc = fmin(fmax(t, 0.0), 4.0);
    ksl_quaternion_t expected = make_test_quaternion(0, 0, 1, 0.4 * tc);
    double of[4] = {qof.x, qof.y, qof.z, qof.w};
    ck_assert_msg(rotation_difference(qo.at, expected.at) < 1e-12, "t = %g", t);
    ck_assert_msg(rotation_difference(of, expected.at) < 1e-6, "float t = %g",
                  t);
  }
}
END_TEST

START_TEST(test_quaternion_squad_smooth) {
  /* keys about different axes: the squad curve passes through every key,
  and its angular velocity is continuous at the interior keys, where slerp's
  jumps */
  const double axes[5][3] = {
    {0, 0, 1}, {1, 0, 0}, {0, 1, 1}, {1, -1, 0.5}, {-0.3, 1, 0}};
  const double angles[5] = {0.2, 0.9, -0.6, 1.4, 0.5};
  ksl_quaternion_t keys[5];
  ksl_quaternionf_t keysf[5];
  for(int k = 0; k < 5; k++) {
    keys[k] =
      make_test_quaternion(axes[k][0], axes[k][1], axes[k][2], angles[k]);
    keysf[k] = ksl_quaternionf(keys[k].x, keys[k].y, keys[k].z, keys[k].w);
  }

  for(int k = 0; k < 5; k++) {
    double t = k;
    ksl_quaternion_t qo;
    ksl_quaternion_squad_keys(5, keys, &t, &qo);
    ck_assert_msg(rotation_difference(qo.at, keys[k].at) < 1e-14, "key %d", k);
    /* the key reached from the left */
    t = k - 1e-12;
    if(k > 0) {
      ksl_quaternion_squad_keys(5, keys, &t, &qo);
      ck_assert_msg(rotation_difference(qo.at, keys[k].at) < 1e-10,
                    "key %d from the left", k);
    }
  }

  const double dt = 1e-6;
  for(int k = 1; k < 4; k++) {
    ksl_vec3_t left = squad_rate(5, keys, k, -dt);
    ksl_vec3_t right = squad_rate(5, keys, k, dt);
    for(int i = 0; i < 3; i++) {
      ck_assert_msg(fabs(left.at[i] - right.at[i]) < 1e-4,
                    "key %d: angular velocity %g from the left, %g from the "
                    "right",
                    k, left.at[i], right.at[i]);
    }
  }

  /* single precision follows the double precision curve */
  for(int j = 0; j <= 40; j++) {
    double t = 0.1 * j;
    float tf = t;
    ksl_quaternion_t qo;
    ksl_quaternionf_t qof;
    ksl_quaternion_squad_keys(5, keys, &t, &qo);
    ksl_quaternionf_squad_keys(5, keysf, &tf, &qof);
    double of[4] = {qof.x, qof.y, qof.z, qof.w};
    ck_assert_msg(rotation_difference(of, qo.at) < 1e-5, "float t = %g", t);
  }
}
END_TEST

START_TEST(test_quaternion_product_qxq) {
  /* dci = {sin(theta/2), cos(theta/2)} as computed by ksl_dc, i.e.
  qx = {dci[0], 0, 0, dci[1]} */
  double theta = 0.8;
  double dc[2];
  ksl_dc(0.5 * theta, dc);
  ksl_quaternion_t qx = make_test_quaternion(1.0, 0.0, 0.0, theta);
  ksl_quaternion_t q = make_test_quaternion(-0.5, 0.3, 0.9, 1.9);
  ksl_quaternion_t expected;
  ksl_product_qq(&qx, &q, &expected);

  ksl_quaternion_t q3;
  ksl_product_qxq(dc, &q, &q3);

  for(int i = 0; i < 4; i++) {
    ck_assert_double_eq_tol(q3.at[i], expected.at[i], 1e-12);
  }
}
END_TEST

/* every axial product ksl_product_q{x,y,z}... against the general product
with the axial quaternion written out, including the conjugate variants */
typedef void (*axial_first_fn)(const double[2], const ksl_quaternion_t*,
                               ksl_quaternion_t*);
typedef void (*axial_second_fn)(const ksl_quaternion_t*, const double[2],
                                ksl_quaternion_t*);
typedef void (*axial_first_fnf)(const float[2], const ksl_quaternionf_t*,
                                ksl_quaternionf_t*);
typedef void (*axial_second_fnf)(const ksl_quaternionf_t*, const float[2],
                                 ksl_quaternionf_t*);

static void check_axial(int axis, int axial_first, int axial_conj, int q_conj,
                        axial_first_fn f1, axial_second_fn f2,
                        axial_first_fnf f1f, axial_second_fnf f2f) {
  double theta = 0.8;
  double dc[2];
  ksl_dc(0.5 * theta, dc);
  float dcf[2];
  ksl_dcf(0.5f * (float)theta, dcf);
  ksl_quaternion_t qa = ksl_quaternion(0.0, 0.0, 0.0, dc[1]);
  qa.at[axis] = dc[0];
  ksl_quaternion_t q = make_test_quaternion(-0.5, 0.3, 0.9, 1.9);
  if(axial_conj)
    qa = quaternion_conj(&qa);
  ksl_quaternion_t qc = q_conj ? quaternion_conj(&q) : q;
  ksl_quaternion_t expected;
  if(axial_first) {
    ksl_product_qq(&qa, &qc, &expected);
  } else {
    ksl_product_qq(&qc, &qa, &expected);
  }

  ksl_quaternion_t out;
  ksl_quaternionf_t qf, outf;
  for(int i = 0; i < 4; i++)
    qf.at[i] = q.at[i];
  if(axial_first) {
    f1(dc, &q, &out);
    f1f(dcf, &qf, &outf);
  } else {
    f2(&q, dc, &out);
    f2f(&qf, dcf, &outf);
  }
  for(int i = 0; i < 4; i++) {
    ck_assert_msg(fabs(out.at[i] - expected.at[i]) < 1e-12,
                  "axis %d first %d aconj %d qconj %d: component %d", axis,
                  axial_first, axial_conj, q_conj, i);
    ck_assert_msg(fabs(outf.at[i] - expected.at[i]) < 1e-6,
                  "float axis %d first %d aconj %d qconj %d: component %d",
                  axis, axial_first, axial_conj, q_conj, i);
  }
}

#define AXIAL_FIRST(axis, ac, qc, name)                                        \
  check_axial(axis, 1, ac, qc, name, NULL, name##f, NULL)
#define AXIAL_SECOND(axis, ac, qc, name)                                       \
  check_axial(axis, 0, ac, qc, NULL, name, NULL, name##f)
#define AXIAL_ALL(axis, a)                                                     \
  AXIAL_FIRST(axis, 0, 0, ksl_product_q##a##q);                                \
  AXIAL_SECOND(axis, 0, 0, ksl_product_qq##a);                                 \
  AXIAL_FIRST(axis, 1, 0, ksl_product_q##a##conjq);                            \
  AXIAL_SECOND(axis, 1, 0, ksl_product_qq##a##conj);                           \
  AXIAL_FIRST(axis, 0, 1, ksl_product_q##a##qconj);                            \
  AXIAL_SECOND(axis, 0, 1, ksl_product_qconjq##a);                             \
  AXIAL_FIRST(axis, 1, 1, ksl_product_q##a##conjqconj);                        \
  AXIAL_SECOND(axis, 1, 1, ksl_product_qconjq##a##conj)

START_TEST(test_quaternion_product_axial) {
  AXIAL_ALL(0, x);
  AXIAL_ALL(1, y);
  AXIAL_ALL(2, z);
}
END_TEST

START_TEST(test_quaternion_mat3x3_toQuaternion) {
  /* round trip R -> q -> R, including rotations near pi which exercise each
  branch of the conversion */
  ksl_vec3_t axes[5] = {ksl_vec3(1.0, 2.0, 3.0), ksl_vec3(1.0, 0.0, 0.0),
                        ksl_vec3(0.0, 1.0, 0.0), ksl_vec3(0.0, 0.0, 1.0),
                        ksl_vec3(1.0, 1.0, 1.0)};
  double angles[4] = {0.3, 2.0, M_PI - 1e-3, M_PI};
  for(int k = 0; k < 5; k++) {
    for(int j = 0; j < 4; j++) {
      ksl_mat3x3_t r;
      ksl_mat3x3_setFromAxisAngle(&r, &axes[k], angles[j]);
      ksl_quaternion_t q;
      ksl_mat3x3_toQuaternion(&r, &q);
      ksl_mat3x3_t r_test;
      ksl_quaternion_toMat3x3(&q, &r_test);
      for(int i = 0; i < 9; i++) {
        ck_assert_msg(fabs(r.as_array[i] - r_test.as_array[i]) < 1e-9,
                      "failed for axis %d, angle %f\n", k, angles[j]);
      }
    }
  }
}
END_TEST

Suite* quaternion_suite(void) {
  Suite* s = suite_create("quaternion");

  /* Core test case */
  TCase* tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_quaternion_create);
  tcase_add_test(tc_core, test_quaternion_product_qq);
  tcase_add_test(tc_core, test_quaternion_product_qconjq);
  tcase_add_test(tc_core, test_quaternion_product_qqconj);
  tcase_add_test(tc_core, test_quaternion_product_qconjqconj);
  tcase_add_test(tc_core, test_quaternion_product_reference);
  tcase_add_test(tc_core, test_quaternion_product_vector);
  tcase_add_test(tc_core, test_quaternion_slerp);
  tcase_add_test(tc_core, test_quaternion_log_exp);
  tcase_add_test(tc_core, test_quaternion_squad_keys);
  tcase_add_test(tc_core, test_quaternion_squad_smooth);
  tcase_add_test(tc_core, test_quaternion_product_qxq);
  tcase_add_test(tc_core, test_quaternion_product_axial);
  tcase_add_test(tc_core, test_quaternion_mat3x3_toQuaternion);
  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
  int number_failed;
  Suite* s = quaternion_suite();
  SRunner* sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
