//
// Created by 86133 on 2024/4/16.
//

#ifndef DATA_STRUCTURE_BIT_TREE_H
#define DATA_STRUCTURE_BIT_TREE_H


#include <string>
#include <list>
#include "Node.h"

template<typename T>
class BinaryTree {
public:
    //Constructor & Destructor
    BinaryTree();
    BinaryTree(std::string preorderTraversalString);
    ~BinaryTree();
    //Root
    bool hasRoot() const;
    Node<T>& getRoot();
    //Count
    unsigned long long getNodeAmount() const;
    unsigned long long getLeaveAmount() const;
    unsigned long long getHeight() const;
    //Traversal
    std::list<T*> PreorderTraversal() const;
    std::list<T*> InorderTraversal() const;
    std::list<T*> PostorderTraversal() const;
    std::list<std::list<T*>> LevelOrderTraversal() const;
    //Search
    Node<T>& search(T& t);
    //Judgment
    bool isBinarySearchTree() const;
    bool isCompleteBinaryTree() const;
    bool isBalancedBinaryTree() const;
private:
    Node<T>* root;//如果是空的就指向null
};//TODO


#endif //DATA_STRUCTURE_BIT_TREE_H
