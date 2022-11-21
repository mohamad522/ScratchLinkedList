cmake_minimum_required(VERSION 3.10)
project(LinkedList)
add_executable(LinkedList main.cpp)
add_subdirectory(scriptFiles)
target_link_libraries(LinkedList PUBLIC scriptFiles)
target_include_directories(LinkedList PUBLIC
"${PROJECT_BINARY_DIR}"
"${PROJECT_SOURCE_DIR}/scriptFiles")