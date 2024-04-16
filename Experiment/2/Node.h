//
// Created by 86133 on 2024/4/16.
//

#ifndef DATA_STRUCTURE_NODE_H
#define DATA_STRUCTURE_NODE_H

template<typename T>
class Node {
public:
    //Constructor & Destructor
    explicit Node(T& inputData);
    Node(T& inputData,Node<T>* inputLeft,Node<T>* inputRight);
    ~Node();
    T& getData();
    [[nodiscard]] bool hasLeft() const;
    [[nodiscard]] bool hasRight() const;
    Node<T>& getLeft();
    Node<T>& getRight();
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
