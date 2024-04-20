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
    Node<T>* getRoot();
    void setRoot(Node<T>* inputRoot);//会释放原来的树
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

template<typename T>
BinaryTree<T>::BinaryTree() {
    root= nullptr;
}

template<typename T>
BinaryTree<T>::~BinaryTree() = default;

template<typename T>
bool BinaryTree<T>::hasRoot() const {
    return (root!= nullptr);
}

template<typename T>
Node<T> *BinaryTree<T>::getRoot() {
    return root;
}

template<typename T>
void BinaryTree<T>::setRoot(Node<T> *inputRoot) {
    if(hasRoot()){
        root->~Node();
    }

    root=inputRoot;
}

template<typename T>
unsigned long long BinaryTree<T>::getNodeAmount() const {
    if(!hasRoot()){
        return 0;
    }

    return root->getNodeAmount();
}

template<typename T>
unsigned long long BinaryTree<T>::getLeaveAmount() const {
    if(!hasRoot()){
        return 0;
    }

    return root->getLeaveAmount();
}

template<typename T>
unsigned long long BinaryTree<T>::getHeight() const {
    if(!hasRoot()){
        return 0;
    }

    return root->getHeight();
}

template<typename T>
std::list<T *> BinaryTree<T>::PreorderTraversal() const {
    if(root== nullptr){
        return std::list<T *>();
    }
    return root->PreorderTraversal();
}

template<typename T>
std::list<T *> BinaryTree<T>::InorderTraversal() const {
    if(root== nullptr){
        return std::list<T *>();
    }
    return root->InorderTraversal();
}

template<typename T>
std::list<T *> BinaryTree<T>::PostorderTraversal() const {
    if(root== nullptr){
        return std::list<T *>();
    }
    return root->PostorderTraversal();
}

template<typename T>
std::list<std::list<T *>> BinaryTree<T>::LevelOrderTraversal() const {
    if(root== nullptr){
        return std::list<std::list<T *>>();
    }
    return root->LevelOrderTraversal();
}

template<typename T>
Node<T> *BinaryTree<T>::search(T &t) {
    if(root== nullptr){
        return nullptr;
    }

    return root->search();
}

template<typename T>
bool BinaryTree<T>::isBinarySearchTree() const {
    if(root== nullptr){
        return true;
    }
    return root->isBinarySearchTree();
}

template<typename T>
bool BinaryTree<T>::isCompleteBinaryTree() const {
    if(root== nullptr){
        return true;
    }
    return root->isCompleteBinaryTree();
}

template<typename T>
bool BinaryTree<T>::isBalancedBinaryTree() const {
    if(root== nullptr){
        return true;
    }
    return root->isBalancedBinaryTree();
}


#endif //DATA_STRUCTURE_BINARY_TREE_H
