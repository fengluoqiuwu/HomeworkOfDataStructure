//
// Created by 86133 on 2024/4/16.
//

#ifndef DATA_STRUCTURE_BINARY_TREE_TOOLS_H
#define DATA_STRUCTURE_BINARY_TREE_TOOLS_H


#include <string>
#include "BinaryTree.h"

template<typename T>
class BinaryTreeTools {
    static BinaryTree<char> initCharBinaryTree(const std::string& preorderTraversalString);//TODO
    static std::string getPreorderString(const BinaryTree<T>& tree);//TODO
    static std::string getInorderString(const BinaryTree<T>& tree);//TODO
    static std::string getPostorderString(const BinaryTree<T>& tree);//TODO
    static std::string getLevelorderString(const BinaryTree<T>& tree);//TODO
    static void show(const BinaryTree<T>& tree);//TODO
};


#endif //DATA_STRUCTURE_BINARY_TREE_TOOLS_H
