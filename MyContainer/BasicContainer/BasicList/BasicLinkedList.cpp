//
// Created by 86133 on 2024/4/10.
//

#include "BasicLinkedList.h"

template<typename T>
BasicLinkedList<T> &BasicLinkedList<T>::operator=(const BasicLinkedList<T> &BasicLinkedList) {
    this->clear();

    if(BasicLinkedList.head= nullptr){
        return *this;
    }

    head=new LinkedListNode<T>;
    *head=*BasicLinkedList.head;

    LinkedListNode<T> *pointer=head;
    LinkedListNode<T> *otherPointer=BasicLinkedList.head->next;

    while(otherPointer!= nullptr){
        auto *nextNode=new LinkedListNode<T>(otherPointer->data);
        pointer->next=nextNode;

        pointer=pointer->next;
        otherPointer=otherPointer->next;
    }

    return *this;
}

template<typename T>
BasicLinkedList<T>::BasicLinkedList() {
    head= nullptr;
}

template<typename T>
BasicLinkedList<T>::BasicLinkedList(const T *array, unsigned long long int arraySize) {
    if(arraySize==0){
        head= nullptr;
        return;
    }

    unsigned long long index=0;
    head=new LinkedListNode<T>(array[index]);
    index++;

    LinkedListNode<T> pointer=head;
    for(;index<arraySize;++index){
        pointer->next=new LinkedListNode<T>(array[index]);
        pointer=pointer.next;
    }
}

template<typename T>
BasicLinkedList<T>::BasicLinkedList(const BasicLinkedList &BasicLinkedList) {
    *this=BasicLinkedList;
}

template<typename T>
BasicLinkedList<T>::~BasicLinkedList() {
    clear();
}

template<typename T>
unsigned long long BasicLinkedList<T>::getSize() {
    unsigned long long size=0;
    LinkedListNode<T>* pointer=head;

    while(pointer!= nullptr){
        size++;
        pointer=pointer->next;
    }

    return size;
}

template<typename T>
bool BasicLinkedList<T>::isEmpty() {
    return (head == nullptr);
}

template<typename T>
T &BasicLinkedList<T>::get(unsigned long long int index) {
    LinkedListNode<T> pointer=head;
    for(unsigned long long i=0;i<index;++i){
        if(pointer== nullptr){
            throw BasicLinkedListError((std::string &) "BasicLinkedList : function get() receive a invalid index!", 1);
        }
        pointer=pointer.next;
    }

    if(pointer== nullptr){
        throw BasicLinkedListError((std::string &) "BasicLinkedList : function get() receive a invalid index!", 1);
    }

    return pointer.data;
}

template<typename T>
unsigned long long BasicLinkedList<T>::getIndex(T &t) {
    return 0;
}//TODO

template<typename T>
unsigned long long BasicLinkedList<T>::find(const T &t) {
    return 0;
}

template<typename T>
BasicLinkedList<T>
BasicLinkedList<T>::subList(unsigned long long int beginIndex, unsigned long long int endIndex) const {
    return BasicLinkedList<T>();
}

template<typename T>
void BasicLinkedList<T>::clear() {

}

template<typename T>
void BasicLinkedList<T>::add(const T &t) {

}

template<typename T>
void BasicLinkedList<T>::addAll(const T *array, unsigned long long int arraySize) {

}

template<typename T>
void BasicLinkedList<T>::insert(unsigned long long int index, const T &t) {

}

template<typename T>
void BasicLinkedList<T>::insert(unsigned long long int index, const T &t, unsigned long long int amount) {

}

template<typename T>
void BasicLinkedList<T>::insert(unsigned long long int index, const BasicLinkedList &BasicLinkedList) {

}

template<typename T>
void BasicLinkedList<T>::insert(unsigned long long int index, unsigned long long int arraySize, const T *array) {

}

template<typename T>
void BasicLinkedList<T>::erase(unsigned long long int index) {

}

template<typename T>
void BasicLinkedList<T>::remove(T t) {

}

template<typename T>
void BasicLinkedList<T>::reSize(unsigned long long int inputSize) {

}

template<typename T>
void BasicLinkedList<T>::ascendingSort() {

}

template<typename T>
void BasicLinkedList<T>::ascendingSort(unsigned long long int beginIndex, unsigned long long int endIndex) {

}

template<typename T>
void BasicLinkedList<T>::descendingSort() {

}

template<typename T>
void BasicLinkedList<T>::descendingSort(unsigned long long int beginIndex, unsigned long long int endIndex) {

}
