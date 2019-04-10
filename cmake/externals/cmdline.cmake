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