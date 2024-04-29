#include <string>
#include <fstream>
#include <iostream>
#include <vector>

#include "Accessor.hpp"
#include "Tokens.h"

class A {
 public:
  Accessor<A, std::vector<int>> val;

  A(): val({13255, 45568, 46468}) {}
};

int main(int argc, const char* argv[]) {
  std::ifstream file(
    "C:/Users/OMEN/Documents/Lib/Projects/CppPrecompiler/test/tester.pccxx"
  );
  // std::string fileData((std::stringstream() << file.rdbuf()).str());
  // file.close();

  // std::cout << fileData << std::endl;
  // std::cout << fileData.size() << std::endl;

  std::string str;

  while (file.tellg() != std::ifstream::pos_type(-1)) {
    str = GetToken(file);
    std::cout << str << ' ';
  }

  Token t(TokenType::keyword);
}