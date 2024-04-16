//
// Created by 86133 on 2024/4/16.
//

#include "Node.h"

template<typename T>
Node<T>::Node(T &inputData) {
    data=inputData;
    left= nullptr;
    right= nullptr;
}

template<typename T>
Node<T>::Node(T &inputData, Node<T> *inputLeft, Node<T> *inputRight) {
    data=inputData;
    left=inputLeft;
    right=inputRight;
}

template<typename T>
Node<T>::~Node() {
    if(left!= nullptr){
        left->~Node();
    }
    if(right!= nullptr){
        right->~Node();
    }
}

template<typename T>
T &Node<T>::getData() {
    return data;
}

template<typename T>
bool Node<T>::hasLeft() const {
    return (left!= nullptr);
}

template<typename T>
Node<T> &Node<T>::getLeft() {
    return *left;
}

template<typename T>
bool Node<T>::hasRight() const {
    return (right!= nullptr);
}

template<typename T>
Node<T> &Node<T>::getRight() {
    return *right;
}

template<typename T>
void Node<T>::swap() {
    Node<T>* swapper=left;
    left=right;
    right=swapper;
}

template<typename T>
void Node<T>::deleteLeft() {
    left->~Node();
    left= nullptr;
}

template<typename T>
void Node<T>::deleteRight() {
    right->~Node();
    right= nullptr;
}

template<typename T>
void Node<T>::setLeft(Node &node) {
    deleteLeft();
    left=&node;
}

template<typename T>
void Node<T>::setRight(Node &node) {
    deleteRight();
    right=&node;
}

template<typename T>
Node<T>* Node<T>::copy() const {
    Node<T>* newLeft= nullptr;
    Node<T>* newRight= nullptr;

    if(left!= nullptr){
        newLeft=left->copy();
    }
    if(right!= nullptr){
        newRight=right->copy();
    }

    return new Node(data,newLeft,newRight);
}
