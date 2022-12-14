cmake_minimum_required(VERSION 3.10)
project(LinkedList)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()
add_executable(LinkedList main.cpp)
add_subdirectory(scriptFiles)
target_link_libraries(LinkedList PUBLIC scriptFiles GTest::gtest_main)
target_include_directories(LinkedList PUBLIC
 "${PROJECT_BINARY_DIR}"
 "${PROJECT_SOURCE_DIR}/scriptFiles" )
include(GoogleTest)
gtest_discover_tests(LinkedList)