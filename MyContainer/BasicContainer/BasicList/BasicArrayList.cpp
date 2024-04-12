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
[[maybe_unused]] BasicArrayList<T>::BasicArrayList(unsigned long long inputSize) {
    size=inputSize;
    length=0;
    bottom=new T[size];
}

template<typename T>
[[maybe_unused]] BasicArrayList<T>::BasicArrayList(const T* array, unsigned long long arraySize) {
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
[[nodiscard]] unsigned long long BasicArrayList<T>::getSize() const {
    return size;
}

template<typename T>
[[nodiscard]] unsigned long long BasicArrayList<T>::getLength() const {
    return length;
}

    //Main
        //Maintain

template<typename T>
bool BasicArrayList<T>::isEmpty() const {
    return (length==0);
}

template<typename T>
T &BasicArrayList<T>::get(unsigned long long index) const {
    checkData();
    if(index>=length||index<0){
        throw "BasicArrayList : function get() receive a invalid index!";
    }

    return *(bottom+index+1);
}

template<typename T>
unsigned long long BasicArrayList<T>::getIndex(T& t) const {
    T* comparator=bottom;
    for(int i=0;i<length;++i){
        comparator++;
        if(&t==comparator){
            return i;
        }
    }

    return 18446744073709551615ULL;
}

template<typename T>
unsigned long long BasicArrayList<T>::find(const T &t) const {
    return 0;
}

template<typename T>
BasicArrayList<T> &BasicArrayList<T>::subList(const unsigned long long beginIndex, const unsigned long long endIndex) const {
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
void BasicArrayList<T>::addAll(const T *array, unsigned long long arraySize) {

}

template<typename T>
void BasicArrayList<T>::insert(const unsigned long long index, const T &t) {

}

template<typename T>
void BasicArrayList<T>::insert(const unsigned long long index, const T &t, const unsigned long long amount) {

}

template<typename T>
void BasicArrayList<T>::insert(const unsigned long long index, const BasicArrayList &basicArrayList) {

}

template<typename T>
void BasicArrayList<T>::insert(const unsigned long long index, const T *array, unsigned long long arraySize) {

}

template<typename T>
void BasicArrayList<T>::erase(unsigned long long index) {

}

template<typename T>
void BasicArrayList<T>::remove(T &t) {

}

template<typename T>
void BasicArrayList<T>::reSize(unsigned long long inputSize) {

}

//private
    //Functions
        //Data Getter & Setter

template<typename T>
[[nodiscard]] unsigned long long BasicArrayList<T>::getBottom() const {
    return bottom;
}

template<typename T>
void BasicArrayList<T>::setSize(unsigned long long inputSize) {
    size=inputSize;
}

template<typename T>
void BasicArrayList<T>::setLength(unsigned long long inputLength) {
    length=inputLength;
}

template<typename T>
void BasicArrayList<T>::setBottom(T* inputBottom) {
    bottom=inputBottom;
}

    //Main
        //Maintain

template<typename T>
void BasicArrayList<T>::checkData() {
    if(bottom== nullptr){
        throw "BasicArrayList : bottom can't be nullptr!";
    }
    if(size<length){
        throw "BasicArrayList : length is bigger than size!";
    }
}

template<typename T>
bool BasicArrayList<T>::isFull() {
    return (length==size);
}

        //Modify