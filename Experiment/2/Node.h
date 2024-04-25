//
// Created by 86133 on 2024/4/16.
//

#ifndef DATA_STRUCTURE_NODE_H
#define DATA_STRUCTURE_NODE_H

#include <list>
#include <algorithm>


template<typename T>
class Node {
public:
    //Constructor & Destructor
    explicit Node(T inputData);
    explicit Node(T* inputData);
    Node(T inputData,Node<T>* inputLeft,Node<T>* inputRight);
    ~Node();
    //Data
    T& getData();
    //Children
    [[nodiscard]] bool isFull() const;
    [[nodiscard]] bool isEmpty() const;
    [[nodiscard]] bool hasLeft() const;
    [[nodiscard]] bool hasRight() const;
    Node<T>& getLeft();
    Node<T>& getRight();
    Node<T>* takeLeft();
    Node<T>* takeRight();
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
    Node<T>* search(T t);
    //Modify
    void swap();
    void deleteLeft();
    void deleteRight();
    void setLeft(Node* node);//注意，不是拷贝!!!
    void setRight(Node* node);//注意，不是拷贝!!!
    Node<T>* copy() const;
    //Judgment
    [[nodiscard]] bool isBinarySearchTree() const;
    [[nodiscard]] bool isCompleteBinaryTree() const;
    [[nodiscard]] bool isBalancedBinaryTree() const;
private:
    T* data;
    Node<T>* left;
    Node<T>* right;
};

template<typename T>
Node<T>::Node(T inputData) {
    data=new T;
    *data=inputData;
    left= nullptr;
    right= nullptr;
}

template<typename T>
Node<T>::Node(T* inputData) {
    data=new T;
    *data=*inputData;
    left= nullptr;
    right= nullptr;
}

template<typename T>
Node<T>::Node(T inputData, Node<T> *inputLeft, Node<T> *inputRight) {
    data=new T;
    *data=inputData;
    left=inputLeft;
    right=inputRight;
}

template<typename T>
Node<T>::~Node() =default;

template<typename T>
T &Node<T>::getData() {
    return *data;
}

template<typename T>
bool Node<T>::isFull() const {
    return (left!= nullptr&&right!= nullptr);
}

template<typename T>
bool Node<T>::isEmpty() const {
    return (left== nullptr&&right== nullptr);
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

    result.push_back(data);
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
    result.push_back(data);
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
    result.push_back(data);

    return result;
}

template<typename T>
std::list<std::list<T *>> Node<T>::LevelOrderTraversal() const {
    std::list<T*> root ={data};
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

    for(int i=1;i<=count;++i){
        rootList.push_back(std::list<T *>());
    }

    typename std::list<std::list<T *>>::iterator rootIt=rootList.begin();
    rootIt++;
    typename std::list<std::list<T *>>::iterator leftIt=leftList.begin();
    typename std::list<std::list<T *>>::iterator rightIt=rightList.begin();

    for(int i=1;i<=leftList.size();++i){
        (*rootIt).splice((*rootIt).end(),(*leftIt));
        rootIt++;
        leftIt++;
    }

    rootIt=rootList.begin();
    rootIt++;

    for(int i=1;i<=rightList.size();++i){
        (*rootIt).splice((*rootIt).end(),(*rightIt));
        rootIt++;
        rightIt++;
    }

    return rootList;
}

template<typename T>
Node<T>* Node<T>::search(T t) {
    if(*data==t){
        return this;
    }

    Node<T>* result= nullptr;
    if(hasLeft()){
        result=left->search(t);
        if(result!= nullptr){
            return result;
        }
    }
    if(hasRight()){
        result=right->search(t);
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
void Node<T>::setLeft(Node *node) {
    deleteLeft();
    left=node;
}

template<typename T>
void Node<T>::setRight(Node *node) {
    deleteRight();
    right=node;
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

    return new Node(*data,newLeft,newRight);
}

template<typename T>
bool Node<T>::isBinarySearchTree() const {
    std::list<char*> inorderList=InorderTraversal();

    auto it=inorderList.begin();
    for(unsigned long long i=1;i<inorderList.size();i++){
        char c1=**it;
        it++;
        if(c1>=**it){
            return false;
        }
    }

    return true;
}

template<typename T>
bool Node<T>::isCompleteBinaryTree() const {
    std::list<std::list<char*>> levelOrderList=LevelOrderTraversal();

    unsigned long long height=LevelOrderTraversal();
    unsigned long long count=1;
    auto it=levelOrderList.begin();
    for(int i=1;i<height;++i){
        if(count!=(*it).size()){
            return false;
        }

        it++;
        count*=2;
    }

    return true;
}

template<typename T>
bool Node<T>::isBalancedBinaryTree() const {
    if(left!=nullptr){
        if(right!= nullptr){
            return (left->isBalancedBinaryTree()
                    &&right->isBalancedBinaryTree()
                    &&std::abs((long long)left->getHeight()-(long long)right->getHeight())<=1);
        }
        else{
            return right->isEmpty();
        }
    } else{
        if(right!= nullptr){
            return left->isEmpty();
        }
        else{
            return true;
        }
    }
}


#endif //DATA_STRUCTURE_NODE_H
