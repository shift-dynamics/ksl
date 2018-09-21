cmake_minimum_required(VERSION 2.8.11)
project(ksl)

set(VERSION_MAJOR 1 CACHE STRING "Project major version number.")
set(VERSION_MINOR 0 CACHE STRING "Project minor version number.")
set(VERSION_PATCH 0 CACHE STRING "Project patch version number.")
mark_as_advanced(VERSION_MAJOR VERSION_MINOR VERSION_PATCH)

list(INSERT CMAKE_MODULE_PATH 0 "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

add_definitions(-g3)
add_definitions(-ggdb)
add_definitions(-std=c11)
add_definitions(-O3)
add_definitions(-Wall)
add_definitions(-D_GNU_SOURCE=1)
add_definitions(-pipe)
add_definitions(-fPIC)
add_definitions(-msse)
add_definitions(-msse2)
add_definitions(-msse3)
add_definitions(-ffast-math)
add_definitions(-fassociative-math)
add_definitions(-ftree-vectorizer-verbose=7)
add_definitions(-fopt-info)
add_definitions(-Wextra)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

# build ksl static library
add_library(ksl STATIC
  ${CMAKE_CURRENT_SOURCE_DIR}/src/ksl_axis.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/ksl_coscrew.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/ksl_inertia.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/ksl_linalg.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/ksl_matrix.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/ksl_print.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/ksl_quaternion.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/ksl_screw.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/ksl_util.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/ksl_vector.c
)

find_library(M_LIB m REQUIRED)

if(DEFINED WITH_BLAS)
  find_package(cblas REQUIRED)
endif()

set(LIBS
  ${M_LIB}
  ${CBLAS_LIBRARIES})

if(${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_SOURCE_DIR})

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

  else()

    message(STATUS "WARNING. Check library not found. Test suite will not be  built.")

  endif()

  add_subdirectory(doc)

else()
  message(STATUS "Not building test suite or documenation for the KSL submodule.")

endif()
