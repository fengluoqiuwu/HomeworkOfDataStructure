//
// Created by 86133 on 2024/4/10.
//

#include "BasicLinkedList.h"

template<typename T>
BasicLinkedList<T> &BasicLinkedList<T>::operator=(const BasicLinkedList<T> &BasicLinkedList) {


    return *this;
}

template<typename T>
BasicLinkedList<T>::BasicLinkedList() {

}

template<typename T>
BasicLinkedList<T>::BasicLinkedList(unsigned long long int inputSize) {

}

template<typename T>
BasicLinkedList<T>::BasicLinkedList(const T *array, unsigned long long int arraySize) {

}

template<typename T>
BasicLinkedList<T>::BasicLinkedList(const BasicLinkedList &BasicLinkedList) {

}

template<typename T>
BasicLinkedList<T>::~BasicLinkedList() {

}

template<typename T>
unsigned long long BasicLinkedList<T>::getSize() {
    return 0;
}

template<typename T>
unsigned long long BasicLinkedList<T>::getLength() {
    return 0;
}

template<typename T>
bool BasicLinkedList<T>::isEmpty() {
    return false;
}

template<typename T>
T &BasicLinkedList<T>::get(unsigned long long int index) {
    return nullptr;
}

template<typename T>
unsigned long long BasicLinkedList<T>::getIndex(T &t) {
    return 0;
}

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
