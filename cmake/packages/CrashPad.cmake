hunter_add_package(crashpad)
find_package(crashpad CONFIG REQUIRED)
list(APPEND DEPENDENCIES cmcrashpad)
list(APPEND LIBRARIES crashpad::crashpad_client)
