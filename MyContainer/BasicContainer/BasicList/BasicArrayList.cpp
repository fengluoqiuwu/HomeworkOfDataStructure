//
// Created by 86133 on 2024/4/10.
//

#include <algorithm>
#include "BasicArrayList.h"



//public
    //Functions
        //Constructor & Destructor

template<typename T>
BasicArrayList<T>::BasicArrayList() {
    size=LIST_INIT_SIZE;
    length=0;
    bottom=new T[size];
}

template<typename T>
[[maybe_unused]] BasicArrayList<T>::BasicArrayList(unsigned long long int inputSize) {
    size=inputSize;
    length=0;
    bottom=new T[size];
}

template<typename T>
[[maybe_unused]] BasicArrayList<T>::BasicArrayList(const T* array, unsigned long long int arraySize) {
    size=arraySize;
    length=0;
    bottom=new T[size];

    std::copy(array,array+size-1,bottom);
}

template<typename T>
[[maybe_unused]] BasicArrayList<T>::BasicArrayList(const BasicArrayList &basicArrayList) {
    size=basicArrayList.getSize();
    length=0;
    bottom=new T[size];

    std::copy(basicArrayList.getBottom()+1,
              basicArrayList.getBottom()+basicArrayList.getSize(),
              bottom
              );
}

template<typename T>
BasicArrayList<T>::~BasicArrayList() {
    delete[] bottom;
    bottom = nullptr;
}

        //Data Getter & Setter

template<typename T>
[[nodiscard]] unsigned long long int BasicArrayList<T>::getSize() const {
    return size;
}

template<typename T>
[[nodiscard]] unsigned long long int BasicArrayList<T>::getLength() const {
    return length;
}

    //Main
        //Maintain

template<typename T>
bool BasicArrayList<T>::isEmpty() const {
    return false;
}

template<typename T>
T &BasicArrayList<T>::get() const {
    return nullptr;
}

template<typename T>
unsigned long long int BasicArrayList<T>::getIndex() const {
    return 0;
}

template<typename T>
unsigned long long int BasicArrayList<T>::find(const T &t) const {
    return 0;
}

template<typename T>
BasicArrayList<T> &BasicArrayList<T>::subList(const long long int beginIndex, const long long int endIndex) const {
    return nullptr;
}

        //Modify

template<typename T>
void BasicArrayList<T>::clear() {

}

template<typename T>
void BasicArrayList<T>::add(const T &t) {

}

template<typename T>
void BasicArrayList<T>::addAll(const T *array, unsigned long long int arraySize) {

}

template<typename T>
void BasicArrayList<T>::insert(const long long int index, const T &t) {

}

template<typename T>
void BasicArrayList<T>::insert(const long long int index, const T &t, const long long int amount) {

}

template<typename T>
void BasicArrayList<T>::insert(const long long int index, const BasicArrayList &basicArrayList) {

}

template<typename T>
void BasicArrayList<T>::insert(const long long int index, const T *array, unsigned long long int arraySize) {

}

template<typename T>
void BasicArrayList<T>::erase(unsigned long long int index) {

}

template<typename T>
void BasicArrayList<T>::remove(T &t) {

}

template<typename T>
void BasicArrayList<T>::reSize(unsigned long long int inputSize) {

}

//private
    //Functions
        //Data Getter & Setter

template<typename T>
[[nodiscard]] unsigned long long int BasicArrayList<T>::getBottom() const {
    return bottom;
}

template<typename T>
void BasicArrayList<T>::setSize(unsigned long long int inputSize) {
    size=inputSize;
}

template<typename T>
void BasicArrayList<T>::setLength(unsigned long long int inputLength) {
    length=inputLength;
}

template<typename T>
void BasicArrayList<T>::setButton(T* inputBottom) {
    bottom=inputBottom;
}

    //Main
        //Maintain

template<typename T>
void BasicArrayList<T>::checkData() {

}

template<typename T>
void BasicArrayList<T>::isFull() {

}

        //Modify