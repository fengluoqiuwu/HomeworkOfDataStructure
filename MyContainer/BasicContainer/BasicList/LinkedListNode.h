//
// Created by 86133 on 2024/5/10.
//

#ifndef BASIC_LIST_TEST_LINKED_LIST_NODE_H
#define BASIC_LIST_TEST_LINKED_LIST_NODE_H

template<typename T>
class LinkedListNode {
public:
    LinkedListNode();
    explicit LinkedListNode(T data);
    LinkedListNode(T data,LinkedListNode<T>& next);
    T data;
    LinkedListNode* next;
};

template<typename T>
LinkedListNode<T>::LinkedListNode() {
    next= nullptr;
}

template<typename T>
LinkedListNode<T>::LinkedListNode(T data) {
    this->data = data;
    next = nullptr;
}

template<typename T>
LinkedListNode<T>::LinkedListNode(T data, LinkedListNode<T> &next) {
    this->data = data;
    this->next = &next;
}

#endif //BASIC_LIST_TEST_LINKED_LIST_NODE_H
