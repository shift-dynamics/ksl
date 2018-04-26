cmake_minimum_required(VERSION 2.8.11)
project(ksl)

set(VERSION_MAJOR 1 CACHE STRING "Project major version number.")
set(VERSION_MINOR 0 CACHE STRING "Project minor version number.")
set(VERSION_PATCH 0 CACHE STRING "Project patch version number.")
mark_as_advanced(VERSION_MAJOR VERSION_MINOR VERSION_PATCH)

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

# build static library
add_library(ksl STATIC
  ${CMAKE_CURRENT_SOURCE_DIR}/src/vector.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/quaternion.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/matrix.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/screw.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/linalg.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/print.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/util.c
)

# build command line test application
add_executable(ksl_test ${CMAKE_CURRENT_SOURCE_DIR}/test/ksl_test.c)
target_link_libraries(ksl_test ksl)
