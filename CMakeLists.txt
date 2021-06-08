cmake_minimum_required(VERSION 3.1)
cmake_policy(SET CMP0048 NEW)
project(ksl
    VERSION 0.0.1
    DESCRIPTION "Kinematics Subroutine Library"
    LANGUAGES C CXX
)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Debug)
endif(NOT CMAKE_BUILD_TYPE)

list(INSERT CMAKE_MODULE_PATH 0 "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
file(GLOB_RECURSE ksl_includes RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/src *.h)
foreach(include ${ksl_includes})
  configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/src/${include}"
    "${CMAKE_BINARY_DIR}/include/ksl/${include}"
    COPYONLY
  )
endforeach()

execute_process(
  COMMAND git rev-parse --abbrev-ref HEAD
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  OUTPUT_VARIABLE KSL_GIT_BRANCH
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

execute_process(
  COMMAND git log -1 --format=%h
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  OUTPUT_VARIABLE KSL_GIT_COMMIT
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

configure_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/src/version.h.in"
  "${CMAKE_BINARY_DIR}/include/ksl/version.h"
)

include_directories(${CMAKE_BINARY_DIR}/include)

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

if(CMAKE_BUILD_TYPE MATCHES Release)
  target_compile_options(
    ksl
    PRIVATE
    -g3
    -msse
    -msse2
    -msse3
    -ffast-math
    -fassociative-math
    -O3
  )
else()
  target_compile_options(
    ksl
    PRIVATE
    -ggdb
    -Wextra
  )
  if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(
      ksl
      PRIVATE
      -ftree-vectorizer-verbose=7
      -fopt-info
    )
  endif()
endif()

target_compile_options(
  ksl
  PRIVATE
  -std=c11
  -Wall
  -D_GNU_SOURCE=1
  -pipe
  -fPIC
)

get_target_property(KSL_COMPILE_OPTIONS ksl COMPILE_OPTIONS)

message(STATUS "ksl build type: " ${CMAKE_BUILD_TYPE})
message(STATUS "ksl compile options: " "${KSL_COMPILE_OPTIONS}")

find_library(M_LIB m REQUIRED)

if(DEFINED WITH_BLAS)
  find_package(cblas REQUIRED)
endif()

target_link_libraries(
  ksl
  PUBLIC
  ${M_LIB}
  ${CBLAS_LIBRARIES}
)

option(KSL_BUILD_TESTS "Build KSL test suite" OFF)

if(${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_SOURCE_DIR} AND KSL_BUILD_TESTS)

  find_package(Check REQUIRED)
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

    # get_cmake_property(_variableNames VARIABLES)
    # list (SORT _variableNames)
    # foreach (_variableName ${_variableNames})
    #     message(STATUS "${_variableName}=${${_variableName}}")
    # endforeach()
    message(STATUS "Check include directories: ${CHECK_INCLUDE_DIR}")
    message(STATUS "Check library directories: ${CHECK_LIBRARIES}")
    include_directories(${CHECK_INCLUDE_DIR})

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

    find_program(GCOVR_BIN gcovr)
    if(GCOVR_BIN)
      message(STATUS "Adding code coverage target using gcovr")
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
    endif()

  else()

    message(STATUS "WARNING. Check library not found. Test suite will not be  built.")

  endif()

  add_subdirectory(doc)

else()
  message(STATUS "Not building test suite or documenation for the KSL submodule.")

endif()
