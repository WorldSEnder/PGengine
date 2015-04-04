
add_subdirectory(main)

if(OPTION_TESTS)
    add_subdirectory(test tests)
endif()