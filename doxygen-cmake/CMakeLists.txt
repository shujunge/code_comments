cmake_minimum_required(VERSION 3.5)
project(project)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_DOCS_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/docs)

set(CMAKE_CXX_STANDARD 11)


FIND_PACKAGE(Doxygen)
OPTION(BUILD_DOCUMENTATION "Create and install the HTML based API documentation (requires Doxygen)" ${DOXYGEN_FOUND})
 
IF(BUILD_DOCUMENTATION)
    IF(NOT DOXYGEN_FOUND)
        MESSAGE(FATAL_ERROR "Doxygen is needed to build the documentation.")
    ENDIF()
 
    SET(doxyfile_in ${CMAKE_CURRENT_SOURCE_DIR}/doxygen/Doxyfile.in)
    SET(doxyfile ${CMAKE_CURRENT_BINARY_DIR}/doxygen/Doxyfile)
    SET(srcsfile ${CMAKE_CURRENT_BINARY_DIR}/srcs)
    CONFIGURE_FILE(${doxyfile_in} ${doxyfile} @ONLY)
 
    ADD_CUSTOM_TARGET(doc
        COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile}
        WORKING_DIRECTORY ${CMAKE_DOCS_OUTPUT_DIRECTORY}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)
 
    #INSTALL(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/html DESTINATION share/doc)
ENDIF()
