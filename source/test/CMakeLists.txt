
include_directories(../main/include)

add_executable(test1 test1.cpp)



set_target_properties(test1 PROPERTIES
    COMPILE_FLAGS -std=c++1y)