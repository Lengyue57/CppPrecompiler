project(Lexer)

add_custom_command(
  OUTPUT  lexer.lex.cpp
  COMMAND flex -+ -olexer.lex.cpp ${PROJECT_SOURCE_DIR}/lexer.l
  DEPENDS "./lexer.l"
  VERBATIM
)

# add_custom_target(
#   Lexer_lex_cpp
#   DEPENDS lexer.lex.cpp
# )

add_library(${PROJECT_NAME} STATIC)

target_sources(
  ${PROJECT_NAME}
  PRIVATE
  "lexer.lex.cpp"
)

target_include_directories(
  ${PROJECT_NAME}
  PRIVATE
  "C:/Program Files (x86)/GnuWin32/include"
)