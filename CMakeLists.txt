# --------------------------------------------------------------------------------- #

cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(template)

# --------------------------------------------------------------------------------- #

# 3rdparty libs version
set(CMDLINE_VERSION "master")

# --------------------------------------------------------------------------------- #

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -s")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -s")
include(ExternalProject)

set(CPACK_GENERATOR TBZ2)
set(CPACK_PACKAGE_VENDOR "unknown")
set(CPACK_PACKAGE_VERSION_MAJOR 0)
set(CPACK_PACKAGE_VERSION_MINOR 0)
set(CPACK_PACKAGE_VERSION_PATCH 1)
set(CPACK_PACKAGE_FILE_NAME ${PROJECT_NAME})
set(CPACK_SOURCE_STRIP_FILES TRUE)
include(CPack)

if (NOT TARGET ALL_PROJECT_FILES)
    set(SCAN_GLOB_EXPR * CACHE STRING "Setup file system scanning pattern to display all needed files, default: *")
    set(SCAN_DUMMY_PROG "true" CACHE STRING "Dummy prog for dummy target, default: true")
    file(GLOB_RECURSE ALL_RPOJECT_FILES_LIST LIST_DIRECTORIES false RELATIVE ${CMAKE_SOURCE_DIR} ${SCAN_GLOB_EXPR})
    add_custom_target(ALL_PROJECT_FILES ${SCAN_DUMMY_PROG} SOURCES ${ALL_RPOJECT_FILES_LIST})
endif()

# Forward real toolchain file
if (CMAKE_TOOLCHAIN_FILE_FORWARD)
    include(${CMAKE_TOOLCHAIN_FILE_FORWARD})
endif()

# --------------------------------------------------------------------------------- #

set(HEADERS )
set(SOURCES )
set(DEFINITIONS )
set(LIBRARIES )
set(DEPENDENCIES )

# --------------------------------------------------------------------------------- #

# cmdline lib from github: command line args parser
ExternalProject_Add(cmdline
        URL https://raw.githubusercontent.com/tanakh/cmdline/${CMDLINE_VERSION}/cmdline.h
        DOWNLOAD_NO_EXTRACT 1
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        UPDATE_COMMAND ""
        INSTALL_COMMAND ${CMAKE_COMMAND}
        -E copy_if_different
        <SOURCE_DIR>/../cmdline.h
        ${CMAKE_BINARY_DIR}/include/cmdline.h)
include_directories(${PROJECT_BINARY_DIR}/include)
list(APPEND DEPENDENCIES cmdline)

# --------------------------------------------------------------------------------- #

aux_source_directory(sources SOURCES)

# --------------------------------------------------------------------------------- #

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
if(DEPENDENCIES)
    add_dependencies(${PROJECT_NAME} ${DEPENDENCIES})
endif()
if(DEFINITIONS)
    target_compile_definitions(${PROJECT_NAME} PRIVATE ${DEFINITIONS})
endif()
if(LIBRARIES)
    target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBRARIES})
endif()

# --------------------------------------------------------------------------------- #

install(TARGETS ${PROJECT_NAME}
        RUNTIME
        DESTINATION .
        COMPONENT applications)

# --------------------------------------------------------------------------------- #