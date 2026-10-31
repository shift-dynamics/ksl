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

# Doxygen XML only; the HTML site is built by sphinx + breathe from it
doxygen_xml = custom_target(
  'doxygen',
  input: doxyfile,
  output: 'xml',
  command: [doxygen, '@INPUT@'],
  build_always_stale: true,
  build_by_default: false,
)

sphinx_build = find_program('sphinx-build', required: false)
if sphinx_build.found()
  # `meson compile -C build docs` -> build/doc/html/index.html
  run_target(
    'docs',
    command: [
      sphinx_build, '-b', 'html', '-q',
      meson.current_source_dir() / 'sphinx',
      meson.current_build_dir() / 'html',
    ],
    depends: doxygen_xml,
    env: {'KSL_DOXYGEN_XML': meson.current_build_dir() / 'xml'},
  )
endif
