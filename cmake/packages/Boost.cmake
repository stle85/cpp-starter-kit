set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

hunter_add_package(Boost COMPONENTS
    filesystem
    stacktrace
    system
    )

find_package(Boost REQUIRED COMPONENTS
    filesystem
    stacktrace_backtrace
    system
    )

list(APPEND LIBRARIES
    Boost::boost
    Boost::filesystem
    Boost::stacktrace_backtrace
    Boost::system
    -ldl
    )
