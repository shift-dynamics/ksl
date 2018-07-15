find_package(Doxygen)
option(BUILD_DOCUMENTATION
  "Create and install the HTML based API documentation (requires Doxygen, Breathe and Sphinx)"
  ${DOXYGEN_FOUND})

if(BUILD_DOCUMENTATION)
  if(NOT DOXYGEN_FOUND)
    message(FATAL_ERROR "Doxygen is required to build documentation.")
  endif()

  set(doxyfile_in ${CMAKE_CURRENT_LIST_DIR}/Doxyfile.in)
  set(doxyfile ${CMAKE_CURRENT_BINARY_DIR}/doc/Doxyfile)

  configure_file(${doxyfile_in} ${doxyfile} @ONLY)

  # generate doxygen documentation
  add_custom_target(
    doxygen
    COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Generating API documentation with Doxygen"
    VERBATIM)

  set (DOC_NAME "ksl documentation")

  set (ksl_VERSION_MAJOR 0)
  set (ksl_VERSION_MINOR 1)
  set (ksl_VERSION_REVISION 0)

  set (ksl_VERSION_COMPANY "Kristopher Wehage, Roger Wehage")
  set (ksl_VERSION_YEARS   "2018")

  set (STATIC_RST_DIR ${CMAKE_CURRENT_LIST_DIR}/sphinx/doxyrest)
  set (XML_DIR  ${CMAKE_CURRENT_BINARY_DIR}/doc/xml)
  set (RST_DIR  ${CMAKE_CURRENT_LIST_DIR}/sphinx/doxyrest)
  set (TMP_DIR  ${CMAKE_CURRENT_BINARY_DIR}/tmp)
  set (HTML_DIR ${CMAKE_CURRENT_LIST_DIR}/html)
  # set (DOXYREST_FRAME_DIR ${CMAKE_CURRENT_LIST_DIR}/doxyrest/frame)

  # message(${DOXYREST_FRAME_DIR})

  # set (
  # 	DOXYREST_CMD_LINE
  # 	${XML_DIR}/index.xml
  # 	-D g_hasNewLineAfterReturnType
  # 	-D g_nameDelimiter=::
  # 	-D g_escapeAsterisks
  # 	-D g_verbatimToCodeBlock
  # 	-o ${RST_DIR}/page_index.rst
  # 	-F ${DOXYREST_FRAME_DIR}
  # 	-f c_index.rst.in
  # 	)

  # running doxyrest to convert doxygen to rst format
  # add_custom_target(doxyrest
  #   COMMAND doxyrest ${DOXYREST_CMD_LINE}
  #   WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
  #   COMMENT "Generating .rst from Doxygen .xml listing using Doxyrest"
  #   VERBATIM)
  #
  # add_dependencies(doxyrest doxygen)

  # generate sphinx documentation
  add_custom_target(doc
    COMMAND make html
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
    COMMENT "Generating API documentation with Sphinx"
    VERBATIM)

  add_dependencies(doc doxygen)

  # optionally install doxygen documentation to /share/doc
  install(
    DIRECTORY
    ${CMAKE_CURRENT_SOURCE_DIR}/html
    DESTINATION
    /share/doc)

endif()
