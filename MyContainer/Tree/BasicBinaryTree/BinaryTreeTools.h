//
// Created by 86133 on 2024/4/16.
//

#ifndef DATA_STRUCTURE_BINARY_TREE_TOOLS_H
#define DATA_STRUCTURE_BINARY_TREE_TOOLS_H


#include <string>
#include "../../MyContainer/Tree/BasicBinaryTree/BinaryTree.h"

class BinaryTreeTools {
public:
    static BinaryTree<char> initCharBinaryTree(const std::string& preorderTraversalString);
    static std::string getPreorderString(const BinaryTree<char>& tree);
    static std::string getInorderString(const BinaryTree<char>& tree);
    static std::string getPostorderString(const BinaryTree<char>& tree);
    static std::string getLevelOrderString(const BinaryTree<char>& tree);
    static void show(const BinaryTree<char>& tree);
};


#endif //DATA_STRUCTURE_BINARY_TREE_TOOLS_H
