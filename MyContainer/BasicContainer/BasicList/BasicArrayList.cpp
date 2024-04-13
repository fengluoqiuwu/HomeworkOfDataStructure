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

    std::copy(array,array+size,bottom);
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
    checkData();
    T* comparator=bottom;
    for(unsigned long long i=0;i<length;++i){
        comparator++;
        if(&t==comparator){
            return i;
        }
    }

    return 18446744073709551615ULL;
}

template<typename T>
unsigned long long BasicArrayList<T>::find(const T &t) const {
    checkData();

    T* comparator=bottom;
    for(unsigned long long i=0;i<length;++i){
        comparator++;
        if(t==(*comparator)){
            return i;
        }
    }

    return 18446744073709551615ULL;
}

template<typename T>
BasicArrayList<T> &BasicArrayList<T>::subList(
        const unsigned long long beginIndex,
        const unsigned long long endIndex
        ) const {
    if(endIndex>length){
        throw "BasicArrayList : function subList receive a too large endIndex!";
    }
    if(beginIndex>=endIndex){
        return BasicArrayList<T>();
    }

    T * subArray=new T[endIndex-beginIndex];
    std::copy(bottom+beginIndex+1,bottom+endIndex+1,subArray);
    auto* subArrayList=new BasicArrayList<T>(size);
    subArrayList->setBottom(subArray-1);
    subArrayList->setLength(endIndex-beginIndex);

    return *subArrayList;
}

        //Modify

template<typename T>
void BasicArrayList<T>::clear() {
    length=0;
}

template<typename T>
void BasicArrayList<T>::add(const T &t) {
    checkData();

    if(isFull()){
        expand();
    }

    length++;
    *(bottom+length)=t;
}

template<typename T>
void BasicArrayList<T>::addAll(const T *array, unsigned long long arraySize) {
    checkData();

    if(length+arraySize>size){
        reSize(length+arraySize);
    }

    std::copy(array,array+arraySize,bottom+length+1);
    length+=arraySize;
}

template<typename T>
void BasicArrayList<T>::insert(const unsigned long long index, const T &t) {
    checkData();

    if(isFull()){
        expand();
    }

    T* pointer=bottom+index;
    for(unsigned long long i=index;i<=length;i++){
        pointer++;
        *(pointer+1)=*pointer;
    }
    *(bottom+index+1)=t;
    length++;
}

template<typename T>
void BasicArrayList<T>::insert(const unsigned long long index, const T &t, const unsigned long long amount) {
    checkData();

    if(length+amount>size){
        reSize(length+amount);
    }

    T* pointer=bottom+index;
    for(unsigned long long i=index;i<=length;i++){
        pointer++;
        *(pointer+amount)=*pointer;
    }
    for(unsigned long long i=1;i<=amount;i++){
        *(bottom+index+i)=t;
    }

    length+=amount;
}

template<typename T>
void BasicArrayList<T>::insert(const unsigned long long index, const BasicArrayList &basicArrayList) {
    insert(index,basicArrayList.getBottom()+1,basicArrayList.getLength());
}

template<typename T>
void BasicArrayList<T>::insert(const unsigned long long index, const T *array, unsigned long long arraySize) {
    checkData();

    if(length+arraySize>size){
        reSize(length+arraySize);
    }

    T* pointer=bottom+index;
    for(unsigned long long i=index;i<=length;i++){
        pointer++;
        *(pointer+arraySize)=*pointer;
    }
    std::copy(array,array+arraySize,bottom+index+1);

    length+=arraySize;
}

template<typename T>
void BasicArrayList<T>::erase(unsigned long long index) {
    checkData();

    if(index>=length){
        throw "BasicArrayList : function erase receive a too large index!";
    }

    T* pointer=bottom+index;
    for(unsigned long long i=index;i<=length;i++){
        *(pointer)=*(pointer+1);
        pointer++;
    }
    length--;
}

template<typename T>
void BasicArrayList<T>::remove(T &t) {
    T* pointer=bottom+1;
    T* end=bottom+length;
    while(true){
        if(pointer==end){
            break;
        }

        if(*(pointer)==t){
            erase(pointer-bottom);
            continue;
        }

        pointer++;
    }
}

template<typename T>
void BasicArrayList<T>::reSize(unsigned long long inputSize) {
    size=inputSize;
    if(length>size){
        length=size;
    }
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

template<typename T>
void BasicArrayList<T>::expand() {
    if(size>=15372286728091293012ULL){
        throw "BasicArrayList : function expand couldn't work!The length is larger than 2^64-1;";
    }
}

        //Modify