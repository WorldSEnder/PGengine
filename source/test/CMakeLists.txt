
# TODO: change this to the exported headers only
include_directories(../main/include)

#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests/lib)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests/lib)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests/bin)

add_executable(test1 test1.cpp)
add_test(NAME "SimpleTest" COMMAND test1)

add_executable(polyget polyget.cpp)
add_test(NAME "PolymorphicGet" COMMAND polyget)


set_target_properties(test1 polyget PROPERTIES
    COMPILE_FLAGS -std=c++1y)
target_link_libraries(test1 ${maintarget})
target_link_libraries(polyget ${maintarget})
