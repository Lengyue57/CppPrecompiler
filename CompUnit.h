#ifndef _CPPPRECOMPILER_COMPILEUNIT_H
#define _CPPPRECOMPILER_COMPILEUNIT_H

#include <string_view>
#include "StructTree.h"

class CompUnit {
  // name
  StructTree structure;
  // identifierPool
  // exportIdentifiers
  // importIdentifiers

  CompUnit(std::string_view);
};

#endif  // !_CPPPRECOMPILER_COMPILEUNIT_H