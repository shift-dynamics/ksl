doxygen = find_program('doxygen', required: get_option('docs'))
if not doxygen.found()
  subdir_done()
endif

version = meson.project_version().split('.')
doxyfile = configure_file(
  input: 'Doxyfile.in',
  output: 'Doxyfile',
  configuration: {
    'CMAKE_PROJECT_NAME': meson.project_name(),
    'PROJECT_SOURCE_DIR': meson.project_source_root(),
    'ksl_SOURCE_DIR': meson.project_source_root(),
    'PROJECT_BINARY_DIR': meson.project_build_root(),
    'VERSION_MAJOR': version[0],
    'VERSION_MINOR': version[1],
    'VERSION_PATCH': version[2],
    'doxy_main_page': meson.project_source_root() / 'README.md',
  },
)

# `ninja -C build doxygen`, then `make html` in doc/ for the sphinx pages
run_target('doxygen', command: [doxygen, doxyfile])
