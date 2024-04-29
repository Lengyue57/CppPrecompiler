#ifndef _CPPPRECOMPILER_COMPILEUNIT_H
#define _CPPPRECOMPILER_COMPILEUNIT_H

#include <string_view>

class CompUnit {
  // name
  // structure;
  // identifierPool
  // exportIdentifiers
  // importIdentifiers

  CompUnit(std::string_view);
};

#endif  // !_CPPPRECOMPILER_COMPILEUNIT_H