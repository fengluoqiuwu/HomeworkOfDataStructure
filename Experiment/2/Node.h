//
// Created by 86133 on 2024/4/16.
//

#ifndef DATA_STRUCTURE_NODE_H
#define DATA_STRUCTURE_NODE_H

#include <list>

template<typename T>
class Node {
public:
    //Constructor & Destructor
    explicit Node(T& inputData);
    Node(T& inputData,Node<T>* inputLeft,Node<T>* inputRight);
    ~Node();
    //Data
    T& getData();
    //Children
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
    Node<T>* search(T& t);
    //Modify
    void swap();
    void deleteLeft();
    void deleteRight();
    void setLeft(Node& node);//注意，不是拷贝!!!
    void setRight(Node& node);//注意，不是拷贝!!!
    Node<T>* copy() const;
private:
    T data;
    Node<T>* left;
    Node<T>* right;
};


#endif //DATA_STRUCTURE_NODE_H
