cmake_minimum_required(VERSION 3.20)

add_subdirectory(./lib/googletest-1.8.x)
set(gtest_SOURCE_DIR, ./lib/googletest-1.8.x/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(SOURCE_TEST_FILES runAllTests.cpp ItemTest.cpp)
add_executable(runAllTests ${SOURCE_TEST_FILES})
target_link_libraries(runAllTests gtest gtest_main core)