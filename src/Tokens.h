#include <cstdint>
#include <string>
#include <string_view>

#include "Accessor.hpp"

enum class TokenType {
  keyword,
};

class Token {
 public:
  Accessor<Token, TokenType> type;
  Accessor<Token, std::string> content;

  Token(const TokenType _type, const std::string_view _content = {}):
    type(_type), content(_content) {}
};

enum class TokenCharType: uint8_t {
  nulltype = 0,
  space = 0x01,
  end   = 0x02,
  value_beg,
  string,
  ident,
  ident_beg = ident | (ident << 1),
};

// nulltype
// non-null
//   space
//   end
//
//   literal
//     value
//     string
//   ident
//     ident_beg
//
//   punct

//   layer

constexpr TokenCharType operator~(TokenCharType _obj) {
  return (TokenCharType)~(int8_t)_obj;
}
constexpr TokenCharType operator&(
  TokenCharType _lhs, TokenCharType _rhs
) {
  return (TokenCharType)((uint8_t)_lhs & (uint8_t)_rhs);
}
constexpr TokenCharType operator|(
  TokenCharType _lhs, TokenCharType _rhs
) {
  return (TokenCharType)((uint8_t)_lhs | (uint8_t)_rhs);
}
constexpr TokenCharType& operator&=(
  TokenCharType& _obj, TokenCharType _rhs
) {
  return _obj = _obj & _rhs;
}
constexpr TokenCharType& operator|=(
  TokenCharType& _obj, TokenCharType _rhs
) {
  return _obj = _obj | _rhs;
}

std::string GetToken(std::istream& _in);

constexpr bool IsTokenCharType(TokenCharType _mask, char c);