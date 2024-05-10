//
// Created by 86133 on 2024/5/1.
//

#ifndef DATA_STRUCTURE_STACK_H
#define DATA_STRUCTURE_STACK_H

#include "BasicArrayList.h"

template <typename T>
class stack : private BasicArrayList<T>{
public:
    //Constructor & Destructor
    stack();
    stack(stack<T> &inputStack);
    ~stack();
    //Operator
    stack<T>& operator=(stack<T> other);
    //Method
    bool empty{};
    unsigned long long size();
    T& top();
    void push(const T& inputT);
    T pop();
    void swap(stack& other);
};

template<typename T>
stack<T>::stack() = default;

template<typename T>
stack<T>::stack(stack<T> &inputStack) {
    *this=inputStack;
}

template<typename T>
stack<T>::~stack() = default;

template<typename T>
stack<T> &stack<T>::operator=(const stack<T> other) {
    BasicArrayList<T>::operator=(other);
    return *this;
}

template<typename T>
unsigned long long stack<T>::size() {
    return BasicArrayList<T>::getLength();
}

template<typename T>
T &stack<T>::top() {
    return BasicArrayList<T>::get(size()-1);
}

template<typename T>
void stack<T>::push(const T &inputT) {
    return BasicArrayList<T>::add(inputT);
}

template<typename T>
T stack<T>::pop() {
    T result=top();
    result.erase(size()-1);
    return result;
}

template<typename T>
void stack<T>::swap(stack<T> &other) {
    stack<T> helper(other);
    other=*this;
    *this=helper;
}

#endif //DATA_STRUCTURE_STACK_H
