check_dep = dependency('check', required: get_option('tests'))
if not check_dep.found()
  subdir_done()
endif

test_conf = configuration_data()
test_conf.set('HAVE_INTMAX_T', cc.has_type('intmax_t', prefix: '#include <stdint.h>'))
test_conf.set('HAVE_UINTMAX_T', cc.has_type('uintmax_t', prefix: '#include <stdint.h>'))
configure_file(input: 'config.h.in', output: 'config.h', configuration: test_conf)

tests = {
  'check_axis': 'check_axis.c',
  'check_coscrew': 'check_coscrew.c',
  'check_inertia': 'check_inertia.c',
  'check_linalg': 'check_linalg.c',
  'check_matrix': 'check_matrix.c',
  'check_quaternion': 'check_quaternion.c',
  'check_screw': 'check_screw.c',
  'check_util': 'check_array.c',
  'check_vector': 'check_vector.c',
  'check_print': 'check_print.c',
}

foreach name, src : tests
  exe = executable(
    name,
    src,
    c_args: ['-DHAVE_CONFIG_H', '-D_GNU_SOURCE=1'],
    dependencies: [ksl_dep, check_dep],
    include_directories: include_directories('.'), # generated config.h
    implicit_include_directories: false,
  )
  test(name, exe)
endforeach
