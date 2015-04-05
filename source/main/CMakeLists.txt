#

set(tgt ${maintarget})

file(GLOB_RECURSE FILES_CPP
    ${CMAKE_CURRENT_SOURCE_DIR}/cpp/*.cpp)
file(GLOB_RECURSE FILES_INCLUDES
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.tpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

add_library(${tgt} ${FILES_CPP} ${FILES_INCLUDES})

set_target_properties(${tgt} PROPERTIES
    COMPILE_FLAGS -std=c++1y)

include_directories(include)
include_directories(cpp)
