cmake_minimum_required(VERSION 2.8.9)

include(cmake/testing.cmake)

option(BUILD_TESTING "Set to build tests" ON)
option(BUILD_SHARED_LIBS "Build Shared Libraries" ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(BUILD_TESTING)
    enable_testing()
endif(BUILD_TESTING)

add_subdirectory(source)
