# --------------------------------------------------------------------------------- #

cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

# Change cmake policy
cmake_policy(SET CMP0054 OLD)
cmake_policy(SET CMP0045 OLD)

# Include package manager
set (HUNTER_ROOT build/hunter)
set (HUNTER_BUILD_SHARED_LIBS OFF)

include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.23.152.tar.gz"
    SHA1 "0c9801f60a8149c3105db04501bbcfb155581b7d"
    )

# Define project name and version
project(app)
set(PROJECT_VERSION "0.0.1")

# --------------------------------------------------------------------------------- #
# Configure CPP flags

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)

set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -s")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -s")

include(ExternalProject)

# --------------------------------------------------------------------------------- #
# Include cotire for speed up compilation

include(cmake/Cotire.cmake)

# --------------------------------------------------------------------------------- #
# Define base variables

set(HEADERS )
set(SOURCES )
set(DEFINITIONS )
set(LIBRARIES )
set(DEPENDENCIES )

# --------------------------------------------------------------------------------- #
# Packages

#include(cmake/packages/CmdLine.cmake)
include(cmake/packages/Boost.cmake)

# --------------------------------------------------------------------------------- #
# Tools

include(cmake/tools/CPack.cmake)
include(cmake/tools/CppCheck.cmake)
include(cmake/tools/CLangFormat.cmake)

# --------------------------------------------------------------------------------- #
# Find sources

aux_source_directory(sources SOURCES)

# --------------------------------------------------------------------------------- #
# Build configuration

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

cotire(${PROJECT_NAME})

# --------------------------------------------------------------------------------- #
# Install configuration

install(TARGETS ${PROJECT_NAME}
    RUNTIME
    DESTINATION .
    COMPONENT applications
    )

# --------------------------------------------------------------------------------- #
