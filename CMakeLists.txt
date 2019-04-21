cmake_minimum_required(VERSION 2.8.11)
project(ksl)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

set(VERSION_MAJOR 1 CACHE STRING "Project major version number.")
set(VERSION_MINOR 0 CACHE STRING "Project minor version number.")
set(VERSION_PATCH 0 CACHE STRING "Project patch version number.")
mark_as_advanced(VERSION_MAJOR VERSION_MINOR VERSION_PATCH)

list(INSERT CMAKE_MODULE_PATH 0 "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

if(CMAKE_BUILD_TYPE MATCHES Release)
  add_compile_options(-g3)
  add_compile_options(-msse)
  add_compile_options(-msse2)
  add_compile_options(-msse3)
  add_compile_options(-ffast-math)
  add_compile_options(-fassociative-math)
  add_definitions(-O3)
else(CMAKE_BUILD_TYPE MATCHES Release)
  add_compile_options(-ggdb)
  add_compile_options(-ftree-vectorizer-verbose=7)
  add_compile_options(-fopt-info)
  add_compile_options(-Wextra)
endif()

add_compile_options(-std=c11)
add_compile_options(-Wall)
add_compile_options(-D_GNU_SOURCE=1)
add_compile_options(-pipe)
add_compile_options(-fPIC)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# build ksl static library
add_library(ksl STATIC
  ${CMAKE_CURRENT_SOURCE_DIR}/src/axis.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/array.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/coscrew.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/inertia.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/linalg.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/mat3x3.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/mat4x4.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/matrix.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/memory.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/print.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/quaternion.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/screw.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/SE3.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/trig.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/vec3.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/vec4.c
)

get_target_property(KSL_COMPILE_OPTIONS ksl COMPILE_OPTIONS)

message(STATUS "Build type: " ${CMAKE_BUILD_TYPE})
message(STATUS "Compile options: " "${KSL_COMPILE_OPTIONS}")


find_library(M_LIB m REQUIRED)

if(DEFINED WITH_BLAS)
  find_package(cblas REQUIRED)
endif()

set(LIBS
  ${M_LIB}
  ${CBLAS_LIBRARIES})

if(${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_SOURCE_DIR} AND
   CMAKE_BUILD_TYPE MATCHES Debug)

  find_package(Check)
  if(CHECK_FOUND)
    message(STATUS "Check library found. Building test suite. Run all tests by  issuing `make test`")
    include(CheckCSourceCompiles)
    include(CheckCSourceRuns)
    include(CheckFunctionExists)
    include(CheckIncludeFile)
    include(CheckIncludeFiles)
    include(CheckLibraryExists)
    include(CheckSymbolExists)
    include(CheckTypeSize)

    check_type_size(intmax_t INTMAX_T)
    check_type_size(uintmax_t UINTMAX_T)
    check_type_size(pid_t PID_T)
    if(NOT HAVE_PID_T)
      if(WIN32)
        set(pid_t "int")
      else(WIN32)
        MESSAGE(FATAL_ERROR "pid_t doesn't exist on this platform?")
      endif(WIN32)
    endif(NOT HAVE_PID_T)

    configure_file(
      ${CMAKE_CURRENT_SOURCE_DIR}/cmake/config.h.in
      ${CMAKE_CURRENT_BINARY_DIR}/config.h)
    include_directories(BEFORE ${CMAKE_CURRENT_BINARY_DIR})
    add_definitions(-DHAVE_CONFIG_H)
    set(CONFIG_HEADER ${CMAKE_CURRENT_BINARY_DIR}/config.h)

    include_directories(${CHECK_INCLUDE_DIRS})
    link_directories(${CHECK_LIBRARY_DIRS})

    include(CodeCoverage)
    append_coverage_compiler_flags()

    add_subdirectory(test)

    enable_testing()
    add_test(NAME check_axis COMMAND check_axis)
    add_test(NAME check_coscrew COMMAND check_coscrew)
    add_test(NAME check_inertia COMMAND check_inertia)
    add_test(NAME check_linalg COMMAND check_linalg)
    add_test(NAME check_matrix COMMAND check_matrix)
    add_test(NAME check_quaternion COMMAND check_quaternion)
    add_test(NAME check_screw COMMAND check_screw)
    add_test(NAME check_util COMMAND check_util)
    add_test(NAME check_vector COMMAND check_vector)
    add_test(NAME check_print COMMAND check_print)

    setup_target_for_coverage_gcovr_xml(
      NAME coverage
      EXECUTABLE ctest -j ${n_cores}
      DEPENDENCIES
        check_axis
        check_coscrew
        check_inertia
        check_linalg
        check_matrix
        check_quaternion
        check_screw
        check_util
        check_vector
        check_print
    )

  else()

    message(STATUS "WARNING. Check library not found. Test suite will not be  built.")

  endif()

  add_subdirectory(doc)

else()
  message(STATUS "Not building test suite or documenation for the KSL submodule.")

endif()
