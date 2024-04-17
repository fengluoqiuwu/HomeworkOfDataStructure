//
// Created by 86133 on 2024/4/16.
//

#include <stack>
#include "BinaryTree.h"

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
Node<T> &BinaryTree<T>::getRoot() {
    return *root;
}

template<typename T>
void BinaryTree<T>::setRoot(Node<T> &inputRoot) {
    if(hasRoot()){
        root->~Node();
    }

    root=&inputRoot;
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
    return false;
}

template<typename T>
bool BinaryTree<T>::isCompleteBinaryTree() const {
    return false;
}

template<typename T>
bool BinaryTree<T>::isBalancedBinaryTree() const {
    return false;
}
