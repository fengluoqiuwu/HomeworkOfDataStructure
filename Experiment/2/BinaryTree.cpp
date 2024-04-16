//
// Created by 86133 on 2024/4/16.
//

#include "BinaryTree.h"

template<typename T>
BinaryTree<T>::BinaryTree() {

}

template<typename T>
BinaryTree<T>::BinaryTree(std::string preorderTraversalString) {

}

template<typename T>
BinaryTree<T>::~BinaryTree() {

}

template<typename T>
bool BinaryTree<T>::hasRoot() const {
    return false;
}

template<typename T>
Node<T> &BinaryTree<T>::getRoot() {
    return <#initializer#>;
}

template<typename T>
unsigned long long BinaryTree<T>::getNodeAmount() const {
    return 0;
}

template<typename T>
unsigned long long BinaryTree<T>::getLeaveAmount() const {
    return 0;
}

template<typename T>
unsigned long long BinaryTree<T>::getHeight() const {
    return 0;
}

template<typename T>
std::list<T *> BinaryTree<T>::PreorderTraversal() const {
    return std::list<T *>();
}

template<typename T>
std::list<T *> BinaryTree<T>::InorderTraversal() const {
    return std::list<T *>();
}

template<typename T>
std::list<T *> BinaryTree<T>::PostorderTraversal() const {
    return std::list<T *>();
}

template<typename T>
std::list<std::list<T *>> BinaryTree<T>::LevelorderTraversal() const {
    return std::list<std::list<T *>>();
}

template<typename T>
Node<T> &BinaryTree<T>::search(T &t) {
    return <#initializer#>;
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
