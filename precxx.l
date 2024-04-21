%option noyywrap
%option nounput
%option noinput

%{

#include <cstdlib>
#include <string>

%}

WhiteSpace    [ \t\n\r]*
/* LineComment   "//".* */

Identifier    [a-zA-Z_][a-zA-Z0-9_]*

Binary        0b[01]+
Octal         0[0-7]*
Decimal       [1-9][0-9]*
Hexadecimal   0[xX][0-9a-fA-F]+

%%

{WhiteSpace} { /**/ }

"var" { return VAR_DEF; }
"fun" { return FUN_DEF; }
"return" { return RETURN; }

{Identifier} {
  yylval.str_val = new std::string(yytext);
  return IDENT;
}

{Binary} {
  yylval.int_val = std::strtol(yytext + 2, nullptr, 2);
  return INT_LITERAL;
}
{Octal} {
  yylval.int_val = std::strtol(yytext + 2, nullptr, 8);
  return INT_LITERAL;
}
{Decimal} {
  yylval.int_val = std::strtol(yytext, nullptr, 10);
  return INT_LITERAL;
}
{Hexadecimal} {
  yylval.int_val = std::strtol(yytext + 2, nullptr, 16);
  return INT_LITERAL;
}

. { return yytext[0]; }

%%