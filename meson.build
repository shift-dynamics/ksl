project(
  'ksl',
  'c',
  version: '0.0.1',
  license: 'see LICENSE.md',
  meson_version: '>=1.1',
  default_options: ['c_std=c11', 'warning_level=1', 'buildtype=debug'],
)

cc = meson.get_compiler('c')

# headers are included as "ksl/<name>.h"; include/ksl is a symlink to src/
ksl_inc = include_directories('include', 'generated')

subdir('generated/ksl')

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
endif

ksl_src = files(
  'src/SE3.c',
  'src/array.c',
  'src/axis.c',
  'src/coscrew.c',
  'src/inertia.c',
  'src/linalg.c',
  'src/mat3x3.c',
  'src/mat4x4.c',
  'src/matrix.c',
  'src/memory.c',
  'src/print.c',
  'src/quaternion.c',
  'src/screw.c',
  'src/trig.c',
  'src/vec3.c',
  'src/vec4.c',
)

ksl_lib = static_library(
  'ksl',
  ksl_src,
  ksl_version_h,
  include_directories: ksl_inc,
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
endif
