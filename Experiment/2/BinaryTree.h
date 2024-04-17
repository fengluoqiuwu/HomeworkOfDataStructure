//
// Created by 86133 on 2024/4/16.
//

#ifndef DATA_STRUCTURE_BINARY_TREE_H
#define DATA_STRUCTURE_BINARY_TREE_H


#include <string>
#include <list>
#include "Node.h"

template<typename T>
class BinaryTree {
public:
    //Constructor & Destructor
    BinaryTree();
    ~BinaryTree();
    //Root
    [[nodiscard]] bool hasRoot() const;
    Node<T>& getRoot();
    void setRoot(Node<T>& inputRoot);//会释放原来的树
    //Count
    [[nodiscard]] unsigned long long getNodeAmount() const;
    [[nodiscard]] unsigned long long getLeaveAmount() const;
    [[nodiscard]] unsigned long long getHeight() const;
    //Traversal
    std::list<T*> PreorderTraversal() const;
    std::list<T*> InorderTraversal() const;
    std::list<T*> PostorderTraversal() const;
    std::list<std::list<T*>> LevelOrderTraversal() const;
    //Search
    Node<T>* search(T& t);
    //Judgment
    [[nodiscard]] bool isBinarySearchTree() const;
    [[nodiscard]] bool isCompleteBinaryTree() const;
    [[nodiscard]] bool isBalancedBinaryTree() const;
private:
    Node<T>* root;//如果是空的就指向null
};


#endif //DATA_STRUCTURE_BINARY_TREE_H
