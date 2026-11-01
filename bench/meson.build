add_languages('cpp', native: false, required: true)
eigen_dep = dependency('eigen3', required: true)

executable(
  'bench_eigen',
  'bench_eigen.cpp',
  dependencies: [ksl_dep, eigen_dep],
  cpp_args: ['-std=c++17'],
  build_by_default: true,
)
