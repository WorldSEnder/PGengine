
include(CMakeParseArguments)

set(UNIT_TEST "unit_tests")

add_custom_target(${UNIT_TEST} ALL VERBATIM)

function(add_unit_test dependency)
    cmake_parse_arguments(UT_ "" "NAME" "" ${ARGN})
    if(NOT ${UT_NAME})
        set(${UT_NAME} ${ARG0})
    endif()

    add_test(${ARGN})
    add_dependencies(${UNIT_TEST} ${dependency})
    #add_custom_command(TARGET ${UNIT_TEST}
    #               COMMENT "Run test ${UT_NAME}"
    #               POST_BUILD COMMAND ctest
    #               ARGS -R ${UT_NAME} --output-on-failures
    #               WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    #               VERBATIM)
endfunction(add_unit_test)

