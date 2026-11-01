// KSL vs Eigen micro-benchmark.
//
// Each kernel is timed over an array of N independent operations (throughput),
// and a forward-kinematics chain of dependent SE3 products measures latency.
// Every result is the minimum over SAMPLES runs, reported in ns per operation.
// KSL's kernels are static inline in its headers, so both libraries are
// compiled in this translation unit with identical flags.
//
// Build with
//   meson setup build-bench --buildtype=release -Db_ndebug=true -Dbench=enabled
// and run build-bench/bench/bench_eigen. Results are in doc/sphinx/performance.
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <random>
#include <vector>

#include "ksl/SE3.h"
#include "ksl/coscrew.h"
#include "ksl/inertia.h"
#include "ksl/mat3x3.h"
#include "ksl/matrix.h"
#include "ksl/quaternion.h"
#include "ksl/screw.h"
#include "ksl/vec3.h"

using Eigen::Isometry3d;
using Eigen::Matrix3d;
using Eigen::Quaterniond;
using Eigen::Vector3d;
using Vector6d = Eigen::Matrix<double, 6, 1>;
using Matrix6d = Eigen::Matrix<double, 6, 6>;

struct Rt {  // compact SE3 in Eigen: 12 doubles, same footprint as ksl_SE3_t
  Matrix3d R;
  Vector3d t;
};
struct EInertia {
  double m;
  Vector3d mc;
  Matrix3d I;
};

static constexpr int N = 512;      // working set fits in L1/L2
static constexpr int REPS = 4000;  // inner repetitions per sample
static constexpr int SAMPLES = 9;  // take min

template <class F>
__attribute__((noinline)) static double TimeNs(F f) {
  double best = 1e30;
  for(int s = 0; s < SAMPLES; s++) {
    auto t0 = std::chrono::steady_clock::now();
    for(int r = 0; r < REPS; r++) {
      f();
      asm volatile("" ::: "memory");
    }
    auto t1 = std::chrono::steady_clock::now();
    double ns = std::chrono::duration<double, std::nano>(t1 - t0).count() /
                (double(REPS) * N);
    if(ns < best) best = ns;
  }
  return best;
}

static Matrix3d Skew(const Vector3d& v) {
  Matrix3d S;
  S << 0, -v.z(), v.y(), v.z(), 0, -v.x(), -v.y(), v.x(), 0;
  return S;
}

static void ToKsl(const Matrix3d& R, const Vector3d& t, ksl_SE3_t* d) {
  for(int c = 0; c < 3; c++)
    for(int r = 0; r < 3; r++) d->at[c][r] = R(r, c);
  for(int r = 0; r < 3; r++) d->at[3][r] = t(r);
}

static void Row(const char* name, double ksl, const char* e1n, double e1,
                const char* e2n = nullptr, double e2 = 0) {
  std::printf("%-26s ksl %6.2f ns | %-18s %6.2f ns", name, ksl, e1n, e1);
  if(e2n) std::printf(" | %-18s %6.2f ns", e2n, e2);
  std::printf("\n");
}

int main() {
  std::mt19937_64 rng(42);
  std::uniform_real_distribution<double> U(-1, 1);

  std::vector<ksl_SE3_t> kd1(N), kd2(N), kdo(N);
  std::vector<Rt> ed1(N), ed2(N), edo(N);
  std::vector<Isometry3d> id1(N), id2(N), ido(N);
  std::vector<ksl_vec3_t> kv(N), kvo(N);
  std::vector<Vector3d> ev(N), evo(N);
  std::vector<ksl_screw_t> ks(N), kso(N);
  std::vector<ksl_coscrew_t> kc(N), kco(N);
  std::vector<Vector6d> es(N), eso(N);
  std::vector<Matrix6d> eAd(N);
  std::vector<ksl_quaternion_t> kq1(N), kq2(N), kqo(N);
  std::vector<Quaterniond> eq1(N), eq2(N), eqo(N);
  std::vector<ksl_inertia_t> ki(N), kio(N);
  std::vector<EInertia> ei(N), eio(N);
  std::vector<Matrix6d> eM(N), eMo(N);
  std::vector<double> dc(2 * N);
  std::vector<Matrix3d> eRz(N);

  for(int i = 0; i < N; i++) {
    Quaterniond q1(U(rng), U(rng), U(rng), U(rng)), q2(U(rng), U(rng), U(rng), U(rng));
    q1.normalize();
    q2.normalize();
    Vector3d t1(U(rng), U(rng), U(rng)), t2(U(rng), U(rng), U(rng));
    ed1[i] = {q1.toRotationMatrix(), t1};
    ed2[i] = {q2.toRotationMatrix(), t2};
    id1[i].setIdentity(); id1[i].linear() = ed1[i].R; id1[i].translation() = t1;
    id2[i].setIdentity(); id2[i].linear() = ed2[i].R; id2[i].translation() = t2;
    ToKsl(ed1[i].R, t1, &kd1[i]);
    ToKsl(ed2[i].R, t2, &kd2[i]);
    ev[i] = Vector3d(U(rng), U(rng), U(rng));
    for(int k = 0; k < 3; k++) kv[i].at[k] = ev[i](k);
    for(int k = 0; k < 6; k++) es[i](k) = U(rng);
    for(int k = 0; k < 6; k++) ks[i].at[k] = kc[i].at[k] = es[i](k);
    Matrix6d Ad = Matrix6d::Zero();  // [v;w] ordering: [R tx*R; 0 R]
    Ad.topLeftCorner<3, 3>() = ed1[i].R;
    Ad.topRightCorner<3, 3>() = Skew(t1) * ed1[i].R;
    Ad.bottomRightCorner<3, 3>() = ed1[i].R;
    eAd[i] = Ad;
    eq1[i] = q1; eq2[i] = q2;
    for(int k = 0; k < 4; k++) { kq1[i].at[k] = q1.coeffs()(k); kq2[i].at[k] = q2.coeffs()(k); }
    // centroidal inertia, mt = 0 (the convention ksl_inertia_transformed assumes)
    double m = 1.0 + std::abs(U(rng));
    Matrix3d A = Matrix3d::Random();
    Matrix3d Ic = A * A.transpose() + Matrix3d::Identity();
    ei[i] = {m, Vector3d::Zero(), Ic};
    ki[i].m = m; ki[i].mt = ksl_vec3(0, 0, 0);
    ki[i].Ixx = Ic(0, 0); ki[i].Iyy = Ic(1, 1); ki[i].Izz = Ic(2, 2);
    ki[i].Ixy = Ic(0, 1); ki[i].Iyz = Ic(1, 2); ki[i].Izx = Ic(2, 0);
    Matrix6d M = Matrix6d::Zero();
    M.topLeftCorner<3, 3>() = m * Matrix3d::Identity();
    M.bottomRightCorner<3, 3>() = Ic;
    eM[i] = M;
    double th = U(rng) * M_PI;
    dc[2 * i] = std::sin(th); dc[2 * i + 1] = std::cos(th);
    eRz[i] = Eigen::AngleAxisd(th, Vector3d::UnitZ()).toRotationMatrix();
  }

  // ---------------- correctness cross-check ----------------
  double err = 0;
  for(int i = 0; i < N; i++) {
    ksl_product_dd(&kd1[i], &kd2[i], &kdo[i]);
    Rt e{ed1[i].R * ed2[i].R, ed1[i].R * ed2[i].t + ed1[i].t};
    for(int c = 0; c < 3; c++) for(int r = 0; r < 3; r++) err = std::max(err, std::abs(kdo[i].at[c][r] - e.R(r, c)));
    for(int r = 0; r < 3; r++) err = std::max(err, std::abs(kdo[i].at[3][r] - e.t(r)));
    ksl_product_Ads(&kd1[i], &ks[i], &kso[i]);
    Vector6d s = eAd[i] * es[i];
    for(int k = 0; k < 6; k++) err = std::max(err, std::abs(kso[i].at[k] - s(k)));
    ksl_product_qq(&kq1[i], &kq2[i], &kqo[i]);
    Quaterniond q = eq1[i] * eq2[i];
    for(int k = 0; k < 4; k++) err = std::max(err, std::abs(kqo[i].at[k] - q.coeffs()(k)));
    ksl_inertia_transformed(&ki[i], &kd1[i], &kio[i]);
    Vector3d c = ed1[i].t;  // new centroid location (centroidal input)
    Matrix3d I = ed1[i].R * ei[i].I * ed1[i].R.transpose() +
                 ei[i].m * (c.squaredNorm() * Matrix3d::Identity() - c * c.transpose());
    err = std::max({err, std::abs(kio[i].Ixx - I(0, 0)), std::abs(kio[i].Iyy - I(1, 1)),
                    std::abs(kio[i].Izz - I(2, 2)), std::abs(kio[i].Ixy - I(0, 1)),
                    std::abs(kio[i].Iyz - I(1, 2)), std::abs(kio[i].Izx - I(2, 0))});
    ksl_product_ddrz(&kd1[i], &dc[2 * i], &kdo[i]);
    Matrix3d Rz = ed1[i].R * eRz[i];
    for(int cc = 0; cc < 3; cc++) for(int r = 0; r < 3; r++) err = std::max(err, std::abs(kdo[i].at[cc][r] - Rz(r, cc)));
  }
  std::printf("max |ksl - eigen| over checks: %.3g\n\n", err);

  // ---------------- throughput ----------------
  double a, b, c;

  a = TimeNs([&] { for(int i = 0; i < N; i++) ksl_product_dd(&kd1[i], &kd2[i], &kdo[i]); });
  b = TimeNs([&] { for(int i = 0; i < N; i++) { edo[i].R.noalias() = ed1[i].R * ed2[i].R; edo[i].t.noalias() = ed1[i].R * ed2[i].t; edo[i].t += ed1[i].t; } });
  c = TimeNs([&] { for(int i = 0; i < N; i++) ido[i] = id1[i] * id2[i]; });
  Row("SE3*SE3 (dd)", a, "Eigen R,t", b, "Eigen Isometry3d", c);

  a = TimeNs([&] { for(int i = 0; i < N; i++) ksl_product_dinvd(&kd1[i], &kd2[i], &kdo[i]); });
  b = TimeNs([&] { for(int i = 0; i < N; i++) { edo[i].R.noalias() = ed1[i].R.transpose() * ed2[i].R; edo[i].t.noalias() = ed1[i].R.transpose() * (ed2[i].t - ed1[i].t); } });
  c = TimeNs([&] { for(int i = 0; i < N; i++) ido[i] = id1[i].inverse(Eigen::Isometry) * id2[i]; });
  Row("inv(SE3)*SE3 (dinvd)", a, "Eigen R,t", b, "Eigen Isometry3d", c);

  a = TimeNs([&] { for(int i = 0; i < N; i++) ksl_product_dv(&kd1[i], &kv[i], &kvo[i]); });
  b = TimeNs([&] { for(int i = 0; i < N; i++) evo[i].noalias() = ed1[i].R * ev[i] + ed1[i].t; });
  c = TimeNs([&] { for(int i = 0; i < N; i++) evo[i] = id1[i] * ev[i]; });
  Row("SE3*point (dv)", a, "Eigen R,t", b, "Eigen Isometry3d", c);

  a = TimeNs([&] { for(int i = 0; i < N; i++) ksl_product_ddrz(&kd1[i], &dc[2 * i], &kdo[i]); });
  b = TimeNs([&] { for(int i = 0; i < N; i++) { double s = dc[2 * i], co = dc[2 * i + 1];
      edo[i].R.col(0) = co * ed1[i].R.col(0) + s * ed1[i].R.col(1);
      edo[i].R.col(1) = co * ed1[i].R.col(1) - s * ed1[i].R.col(0);
      edo[i].R.col(2) = ed1[i].R.col(2); edo[i].t = ed1[i].t; } });
  c = TimeNs([&] { for(int i = 0; i < N; i++) { edo[i].R.noalias() = ed1[i].R * eRz[i]; edo[i].t = ed1[i].t; } });
  Row("SE3*Rz(dc) (ddrz)", a, "Eigen cols", b, "Eigen R*Rz full", c);

  a = TimeNs([&] { for(int i = 0; i < N; i++) ksl_product_Ads(&kd1[i], &ks[i], &kso[i]); });
  b = TimeNs([&] { for(int i = 0; i < N; i++) { Vector3d w = ed1[i].R * es[i].tail<3>();
      eso[i].head<3>() = ed1[i].R * es[i].head<3>() + ed1[i].t.cross(w); eso[i].tail<3>() = w; } });
  c = TimeNs([&] { for(int i = 0; i < N; i++) eso[i].noalias() = eAd[i] * es[i]; });
  Row("Ad*screw (Ads)", a, "Eigen R,t", b, "Eigen 6x6 Ad", c);

  a = TimeNs([&] { for(int i = 0; i < N; i++) ksl_product_CoAdc(&kd1[i], &kc[i], &kco[i]); });
  b = TimeNs([&] { for(int i = 0; i < N; i++) { Vector3d f = ed1[i].R * es[i].head<3>();
      eso[i].tail<3>() = ed1[i].R * es[i].tail<3>() + ed1[i].t.cross(f); eso[i].head<3>() = f; } });
  c = TimeNs([&] { for(int i = 0; i < N; i++) eso[i].noalias() = eAd[i].transpose() * es[i]; });
  Row("CoAd*coscrew (CoAdc)", a, "Eigen R,t", b, "Eigen 6x6 (AdT)", c);

  a = TimeNs([&] { for(int i = 0; i < N; i++) ksl_product_qq(&kq1[i], &kq2[i], &kqo[i]); });
  b = TimeNs([&] { for(int i = 0; i < N; i++) eqo[i] = eq1[i] * eq2[i]; });
  Row("quat*quat (qq)", a, "Eigen Quaterniond", b);

  a = TimeNs([&] { for(int i = 0; i < N; i++) ksl_inertia_transformed(&ki[i], &kd1[i], &kio[i]); });
  b = TimeNs([&] { for(int i = 0; i < N; i++) { const Rt& d = ed1[i]; const EInertia& in = ei[i];
      Vector3d mc = d.R * in.mc + in.m * d.t; Vector3d cc = mc / in.m;
      eio[i].m = in.m; eio[i].mc = mc;
      eio[i].I.noalias() = d.R * in.I.selfadjointView<Eigen::Upper>() * d.R.transpose();
      eio[i].I += in.m * (cc.squaredNorm() * Matrix3d::Identity() - cc * cc.transpose()); } });
  c = TimeNs([&] { for(int i = 0; i < N; i++) eMo[i].noalias() = eAd[i].transpose() * eM[i] * eAd[i]; });
  Row("inertia transform", a, "Eigen 3x3", b, "Eigen 6x6 XtMX", c);

  // ---------------- latency: dependent FK chain ----------------
  auto chain = [&](auto step) { return TimeNs(step); };
  a = chain([&] { for(int i = 1; i < N; i++) ksl_product_dd(&kdo[i - 1], &kd2[i], &kdo[i]); });
  b = chain([&] { for(int i = 1; i < N; i++) { edo[i].R.noalias() = edo[i - 1].R * ed2[i].R; edo[i].t.noalias() = edo[i - 1].R * ed2[i].t; edo[i].t += edo[i - 1].t; } });
  c = chain([&] { for(int i = 1; i < N; i++) ido[i] = ido[i - 1] * id2[i]; });
  Row("FK chain (dependent dd)", a, "Eigen R,t", b, "Eigen Isometry3d", c);

  double sink = 0;
  for(int i = 0; i < N; i++) sink += kdo[i].at[3][0] + edo[i].t(0) + ido[i](0, 3) + kso[i].m0 + eso[i](0) + kqo[i].w + eqo[i].w() + kio[i].Ixx + eio[i].I(0, 0) + eMo[i](3, 3) + kvo[i].x + evo[i](0) + kco[i].m0;
  std::printf("\n(sink %g)\n", sink);
  std::printf("sizeof: ksl_SE3_t %zu, Rt %zu, Isometry3d %zu, ksl_inertia_t %zu, EInertia %zu, Matrix6d %zu\n",
              sizeof(ksl_SE3_t), sizeof(Rt), sizeof(Isometry3d), sizeof(ksl_inertia_t), sizeof(EInertia), sizeof(Matrix6d));
}
