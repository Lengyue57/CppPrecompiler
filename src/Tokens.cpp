#include <fstream>
#include <sstream>

#include "Tokens.h"

namespace {

TokenCharType TokenCharTypeOf(char c) {
  using enum TokenCharType;
  TokenCharType ret = nulltype;

  return ret;
}

extern TokenCharType tokenCharTypeTable[];

}

std::string GetToken(std::istream& _in) {
  class CharType: public std::ctype<char> {
  public:
    CharType(size_t refs = 0):
      ctype<char>(classic_table(), false, refs) {}
  } charType;

  std::stringstream buf;
  char ch;

  while (_in.get(ch)) {
    if (!charType.is(CharType::blank, ch))
      break;
  }

  if (_in.tellg() == std::ifstream::pos_type(-1))
    return std::string();

  buf << ch;

  if (charType.is(CharType::punct, ch))
    return buf.str();

  while(_in.get(ch)) {
    if (charType.is(CharType::blank, ch)) {
      _in.unget();
      break;
    }

    if (charType.is(CharType::punct, ch)) {
      _in.unget();
      break;
    }
    buf << ch;
  }

  return buf.str();
}

// constexpr bool TokenCharTypeOf(TokenCharType _mask, char c) {
//   return MakeTable(c) & _mask;
// }
