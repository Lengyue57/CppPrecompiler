cmake_minimum_required(VERSION 3.28)

project(CppPrecompiler)

message(STATUS "CMAKE_EXPORT_COMPILE_COMMANDS: ${CMAKE_EXPORT_COMPILE_COMMANDS}")

set(CMAKE_CXX_STANDARD 20)

message(STATUS "CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")

message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")

add_executable(${CMAKE_PROJECT_NAME})

target_sources(
  ${CMAKE_PROJECT_NAME}
  PRIVATE
  "main.cpp"
  "Tokens.cpp"
)

add_subdirectory("./TestModule")