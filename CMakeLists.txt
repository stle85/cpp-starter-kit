# --------------------------------------------------------------------------------- #

cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

include("cmake/HunterGate.cmake")
HunterGate(
        URL "https://github.com/ruslo/hunter/archive/v0.23.152.tar.gz"
        SHA1 "0c9801f60a8149c3105db04501bbcfb155581b7d"
)
project(template)
set(version "0.0.1")

# --------------------------------------------------------------------------------- #

# 3rdparty libs version
set(CMDLINE_VERSION "master")

# --------------------------------------------------------------------------------- #

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)

set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -s")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -s")

include(ExternalProject)

# --------------------------------------------------------------------------------- #

include(cmake/CPack.cmake)

# --------------------------------------------------------------------------------- #

set(HEADERS )
set(SOURCES )
set(DEFINITIONS )
set(LIBRARIES )
set(DEPENDENCIES )

# --------------------------------------------------------------------------------- #

#include(cmake/packages/CmdLine.cmake)
#include(cmake/packages/CrashPad.cmake)

# --------------------------------------------------------------------------------- #

include(cmake/tools/CppCheck.cmake)
include(cmake/tools/CLangFormat.cmake)

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