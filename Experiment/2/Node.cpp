//
// Created by 86133 on 2024/4/16.
//

#include <algorithm>
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
Node<T> *Node<T>::takeLeft() {
    Node<T>* node=left;
    left= nullptr;
    return node;
}

template<typename T>
Node<T> *Node<T>::takeRight() {
    Node<T>* node=right;
    right= nullptr;
    return node;
}

template<typename T>
unsigned long long Node<T>::getNodeAmount() const {
    unsigned long long result=1;

    if(hasLeft()){
        result+=left->getNodeAmount();
    }
    if(hasRight()){
        result+=right->getNodeAmount();
    }

    return result;
}

template<typename T>
unsigned long long Node<T>::getLeaveAmount() const {
    if(!hasLeft()&&!hasRight()){
        return 1;
    }
    unsigned long long result=0;

    if(hasLeft()){
        result+=left->getLeaveAmount();
    }
    if(hasRight()){
        result+=right->getLeaveAmount();
    }

    return result;
}

template<typename T>
unsigned long long Node<T>::getHeight() const {
    if(hasLeft()){
        if(hasRight()){
            return (1+std::max(left->getHeight(),right->getHeight()));
        }
        else{
            return (1+left->getHeight());
        }
    }
    else{
        if(hasRight()){
            return (1+right->getHeight());
        }
        else{
            return 1;
        }
    }
}

template<typename T>
std::list<T *> Node<T>::PreorderTraversal() const {
    std::list<T *>result;

    result.push_back(&data);
    if(hasLeft()){
        result.splice(result.end(),left->PreorderTraversal());
    }
    if(hasRight()){
        result.splice(result.end(),right->PreorderTraversal());
    }

    return result;
}

template<typename T>
std::list<T *> Node<T>::InorderTraversal() const {
    std::list<T *>result;

    if(hasLeft()){
        result.splice(result.end(),left->InorderTraversal());
    }
    result.push_back(&data);
    if(hasRight()){
        result.splice(result.end(),right->InorderTraversal());
    }

    return result;
}

template<typename T>
std::list<T *> Node<T>::PostorderTraversal() const {
    std::list<T *>result;

    if(hasLeft()){
        result.splice(result.end(),left->PostorderTraversal());
    }
    if(hasRight()){
        result.splice(result.end(),right->PostorderTraversal());
    }
    result.push_back(&data);

    return result;
}

template<typename T>
std::list<std::list<T *>> Node<T>::LevelOrderTraversal() const {
    std::list<T*> root ={&data};
    std::list<std::list<T *>> rootList={root};
    std::list<std::list<T *>> leftList;
    std::list<std::list<T *>> rightList;

    if(hasLeft()){
        leftList=left->LevelOrderTraversal();
    }
    if(hasRight()){
        rightList=right->LevelOrderTraversal();
    }

    unsigned long long count=std::max(leftList.size(),rightList.size());

    rootList.insert(rootList.end(),std::list<T *>(),count);

    std::iterator rootIt=rootList.begin()+1;
    std::iterator leftIt=leftList.begin();
    std::iterator rightIt=rightList.begin();

    for(int i=1;i<=leftList.size();++i){
        (*rootIt).splice((*rootIt).end(),(*leftIt));
        rootIt++;
        leftIt++;
    }

    rootIt=rootList.begin()+1;

    for(int i=1;i<=rightList.size();++i){
        (*rootIt).splice((*rootIt).end(),(*rightList));
        rootIt++;
        rightList++;
    }

    return rootList;
}

template<typename T>
Node<T>* Node<T>::search(T &t) {
    if(data==t){
        return this;
    }

    Node<T>* result= nullptr;
    if(hasLeft()){
        result=left->search();
        if(result!= nullptr){
            return result;
        }
    }
    if(hasRight()){
        result=right->search();
        if(result!= nullptr){
            return result;
        }
    }

    return nullptr;
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
