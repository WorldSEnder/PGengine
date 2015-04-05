
include_directories(../main/include)

add_executable(test1 test1.cpp)
add_unit_test(test1 NAME "Test1" COMMAND test1)



set_target_properties(test1 PROPERTIES
    COMPILE_FLAGS -std=c++1y)
target_link_libraries(test1 ${maintarget})
