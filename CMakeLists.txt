# --------------------------------------------------------------------------------- #

cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(template)

# --------------------------------------------------------------------------------- #

# 3rdparty libs version
set(CMDLINE_VERSION "master")

# --------------------------------------------------------------------------------- #

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)

set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -s")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -s")

include(ExternalProject)

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

include(cmake/cpack.cmake)

# --------------------------------------------------------------------------------- #

set(HEADERS )
set(SOURCES )
set(DEFINITIONS )
set(LIBRARIES )
set(DEPENDENCIES )

# --------------------------------------------------------------------------------- #

include(cmake/externals/cmdline.cmake)

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