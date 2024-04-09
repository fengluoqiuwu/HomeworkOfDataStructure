//
// Created by 86133 on 2024/4/9.
//

#include <algorithm>
#include <iostream>
#include "BasicStack.h"

//private
template<typename T>
bool BasicStack<T>::isFull() {
    return (stackSize==(top-button+1));
}

//public
template <typename T>
BasicStack<T>::BasicStack() {
    stackSize=STACK_INIT_SIZE;
    button=new T[stackSize];
    top=button-1;
}

template<typename T>
BasicStack<T>::BasicStack(unsigned int size) {
    stackSize=size;
    button=new T[stackSize];
    top=button-1;
}

template<typename T>
BasicStack<T>::BasicStack(BasicStack &basicStack) {
    stackSize=basicStack.stackSize;
    button=new T[stackSize];
    std::copy(basicStack.button, basicStack.top+1, button);
    top=button+(basicStack.top-basicStack.button);
}

template <typename T>
BasicStack<T>::~BasicStack() {
    delete[] button;
    button=nullptr;
    top=nullptr;
    stackSize=-1;
}

template<typename T>
T BasicStack<T>::pop() {
    if(isEmpty()){
        std::cerr << "Could not pop an 0 length Stack!" << std::endl;
        exit(-1);
    }
    T t=*top;
    top--;
    return t;
}

template<typename T>
void BasicStack<T>::push(T t) {
    if(isFull()){
        stackSize=stackSize*1.2;
        T* newButton=new T[stackSize];

        std::copy(button,top+1,newButton);
        delete[] button;
        top=newButton+(top-button);
        button=newButton;
    }

    top++;
    *top=t;
}

template<typename T>
T BasicStack<T>::getTop() {
    return *top;
}

template<typename T>
unsigned int BasicStack<T>::getSize() {
    return stackSize;
}

template<typename T>
unsigned int BasicStack<T>::getLength() {
    return 1+(top-button);
}

template<typename T>
bool BasicStack<T>::isEmpty() {
    return (top==(button-1));
}

template<typename T>
void BasicStack<T>::clear() {
    top=button-1;
}