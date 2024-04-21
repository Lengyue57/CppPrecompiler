#ifndef _CPPPRECOMPILER_STRUCTTREE_H
#define _CPPPRECOMPILER_STRUCTTREE_H

#include <cstdint>
#include <string_view>
#include <vector>

class Identifier {
  const std::string_view name;
  std::string_view* type;
};

class StructTree {
  class Node;
  class VarNode;
  class FuncNode;
};

class StructTree::Node {
  Identifier identifier;
  // defineType
  //   line
  //   block
 public:
  enum class NodeType: int8_t {
    define_var         = 0b0001,
    define_func        = 0b0010,
    command            = 0b0100,
    access_restriction = 0b1000,
  };

  friend NodeType operator| (
    const NodeType& _lhs, const NodeType& _rhs
  ) {
    return (NodeType)((int8_t)_lhs | (int8_t)_rhs);
  }

  virtual NodeType GetNodeType() = 0;
};

class StructTree::VarNode: public Node {
 public:
  NodeType GetNodeType() {
    return (NodeType)0;
  }
};

class StructTree::FuncNode: public Node {
  std::vector<Node*> contents;

 public:
  NodeType GetNodeType() {
    return NodeType::define_var |
           NodeType::command;
  }
};

#endif  // !_CPPPRECOMPILER_STRUCTTREE_H