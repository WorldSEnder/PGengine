
macro(add_unit_test trgt)
    add_dependencies(unit_tests ${UNIT_TEST_TARGETS})
    add_test(${ARGN})
endmacro(add_unit_test)

add_custom_target(unit_tests ALL VERBATIM)

add_custom_command(TARGET unit_tests
                   COMMENT "Run tests"
                   POST_BUILD COMMAND ctest
                   ARGS --output-on-failures
                   WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
                   VERBATIM)