find_program(CLANG_FORMAT clang-format)

add_custom_target(
    format
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    COMMAND ${CLANG_FORMAT}
        -style=file
        -i
        sources/*
    )
