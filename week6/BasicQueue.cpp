//
// Created by 86133 on 2024/4/9.
//

#include <algorithm>
#include <iostream>
#include "BasicQueue.h"


//private

template<typename T>
bool BasicQueue<T>::isFull() {
    return (((front-rear+2)%queueSize)==0);
}

//public

template<typename T>
BasicQueue<T>::~BasicQueue() {
    delete[] begin;
    begin=nullptr;
    rear= nullptr;
    front= nullptr;
    queueSize=0;
}

template<typename T>
BasicQueue<T>::BasicQueue(BasicQueue &basicQueue) {
    queueSize=basicQueue.queueSize;
    begin=new T[queueSize];
    front=begin+(basicQueue.front-basicQueue.begin);
    rear=begin+(basicQueue.rear-basicQueue.begin);
    std::copy(basicQueue.begin,basicQueue.begin+queueSize,begin);
}

template<typename T>
BasicQueue<T>::BasicQueue(unsigned int size) {
    queueSize=size;
    begin=new T[queueSize];
    front=begin+queueSize-1;
    rear=begin;
}

template<typename T>
BasicQueue<T>::BasicQueue() {
    queueSize=QUEUE_INIT_SIZE;
    begin=new T[queueSize];
    front=begin+queueSize-1;
    rear=begin;
}

template<typename T>
T BasicQueue<T>::pop() {
    if(isEmpty()){
        std::cerr << "Could not pop an 0 length Queue!" << std::endl;
        exit(-1);
    }

    T t=*rear;

    rear++;
    if(rear>=begin+queueSize){
        rear-=queueSize;
    }

    return t;
}

template<typename T>
void BasicQueue<T>::push(T t) {
    if(isFull()){
        unsigned int newQueueSize=queueSize*1.2;
        T * newBegin=new T[newQueueSize];
        front=begin+(front-begin);
        rear=begin+(rear-begin);
        std::copy(begin,begin+queueSize,newBegin);
        queueSize=newQueueSize;
        begin=newBegin;
    }

    front++;
    if(front>=begin+queueSize){
        front-=queueSize;
    }

    *front=t;
}

template<typename T>
unsigned int BasicQueue<T>::getLength() {
    return ((front-rear+1)%queueSize);
}

template<typename T>
unsigned int BasicQueue<T>::getSize() {
    return queueSize;
}

template<typename T>
bool BasicQueue<T>::isEmpty() {
    return (((front-rear+1)%queueSize)==0);
}

template<typename T>
void BasicQueue<T>::clear() {
    front=begin+queueSize-1;
    rear=begin;
}

template<typename T>
T BasicQueue<T>::getHead() {
    return *rear;
}

