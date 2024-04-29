add_executable(${CMAKE_PROJECT_NAME})

add_subdirectory("lexer")

target_sources(
  ${CMAKE_PROJECT_NAME}
  PRIVATE
  "main.cpp"
  "Tokens.cpp"
)

target_include_directories(
  ${CMAKE_PROJECT_NAME}
  PRIVATE
  "${CMAKE_SOURCE_DIR}/lib"
)