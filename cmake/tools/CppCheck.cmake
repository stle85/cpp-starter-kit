find_program(CPPCHECK cppcheck)

add_custom_target(
        cppcheck
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
        COMMAND ${CPPCHECK}
                --enable=warning,performance,portability
                --std=c++11
                --template="[{severity}][{id}] {message} {callstack} \(On {file}:{line}\)"
                --verbose
                --force
                --quiet
                sources/
)