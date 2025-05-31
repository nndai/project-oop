cmake_minimum_required(VERSION 3.10)
project(simple_gtest_demo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Thêm GoogleTest (giả sử bạn đã clone về external/googletest)
add_subdirectory(external/googletest)

add_executable(test_add
    test/test_main.cpp
)

target_link_libraries(test_add PRIVATE gtest_main)

enable_testing()
add_test(NAME test_add COMMAND test_add)