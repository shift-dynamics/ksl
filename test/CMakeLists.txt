add_executable(check_axis ${CMAKE_CURRENT_LIST_DIR}/check_axis.c)
target_link_libraries(check_axis ksl ${LIBS} ${CHECK_LIBRARIES})

add_executable(check_coscrew ${CMAKE_CURRENT_LIST_DIR}/check_coscrew.c)
target_link_libraries(check_coscrew ksl ${LIBS} ${CHECK_LIBRARIES})

add_executable(check_inertia ${CMAKE_CURRENT_LIST_DIR}/check_inertia.c)
target_link_libraries(check_inertia ksl ${LIBS} ${CHECK_LIBRARIES})

add_executable(check_linalg ${CMAKE_CURRENT_LIST_DIR}/check_linalg.c)
target_link_libraries(check_linalg ksl ${LIBS} ${CHECK_LIBRARIES})

add_executable(check_matrix ${CMAKE_CURRENT_LIST_DIR}/check_matrix.c)
target_link_libraries(check_matrix ksl ${LIBS} ${CHECK_LIBRARIES})

add_executable(check_quaternion ${CMAKE_CURRENT_LIST_DIR}/check_quaternion.c)
target_link_libraries(check_quaternion ksl ${LIBS} ${CHECK_LIBRARIES})

add_executable(check_screw ${CMAKE_CURRENT_LIST_DIR}/check_screw.c)
target_link_libraries(check_screw ksl ${LIBS} ${CHECK_LIBRARIES})

add_executable(check_util ${CMAKE_CURRENT_LIST_DIR}/check_util.c)
target_link_libraries(check_util ksl ${LIBS} ${CHECK_LIBRARIES})

add_executable(check_vector ${CMAKE_CURRENT_LIST_DIR}/check_vector.c)
target_link_libraries(check_vector ksl ${LIBS} ${CHECK_LIBRARIES})
