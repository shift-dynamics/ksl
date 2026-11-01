project(
  'ksl',
  'c',
  version: '0.0.1',
  license: 'see LICENSE.md',
  meson_version: '>=1.1',
  default_options: ['c_std=c11', 'warning_level=1', 'buildtype=debug'],
)

cc = meson.get_compiler('c')

# headers are included as "ksl/<name>.h" relative to the project root (and
# the build root, for the generated ksl/version.h)
ksl_inc = include_directories('.')

subdir('ksl')

ksl_args = ['-D_GNU_SOURCE=1', '-pipe']
if get_option('buildtype') == 'release'
  ksl_args += cc.get_supported_arguments(
    '-g3',
    '-msse',
    '-msse2',
    '-msse3',
    '-ffast-math',
    '-fassociative-math',
  )
elif get_option('debug')
  ksl_args += cc.get_supported_arguments('-ggdb', '-Wextra')
endif

ksl_deps = [cc.find_library('m', required: false)]
blas_dep = dependency('cblas', required: get_option('blas'))
if blas_dep.found()
  ksl_deps += blas_dep
  ksl_args += '-DKSL_WITH_BLAS_'
endif

ksl_src = files(
  'ksl/SE3.c',
  'ksl/array.c',
  'ksl/axis.c',
  'ksl/coscrew.c',
  'ksl/inertia.c',
  'ksl/linalg.c',
  'ksl/mat3x3.c',
  'ksl/mat4x4.c',
  'ksl/memory.c',
  'ksl/print.c',
  'ksl/quaternion.c',
  'ksl/screw.c',
  'ksl/trig.c',
  'ksl/vec3.c',
  'ksl/vec4.c',
)

ksl_lib = static_library(
  'ksl',
  ksl_src,
  ksl_version_h,
  include_directories: ksl_inc,
  implicit_include_directories: false,
  c_args: ksl_args,
  dependencies: ksl_deps,
  pic: true,
)

ksl_dep = declare_dependency(
  link_with: ksl_lib,
  include_directories: ksl_inc,
  dependencies: ksl_deps,
  sources: ksl_version_h,
)
meson.override_dependency('ksl', ksl_dep)

summary(
  {
    'build type': get_option('buildtype'),
    'compile args': ksl_args,
    'cblas': blas_dep.found(),
  },
  section: 'ksl',
)

if not meson.is_subproject()
  if get_option('tests').allowed()
    subdir('test')
  endif
  subdir('doc')
  if get_option('bench').enabled()
    subdir('bench')
  endif
endif
