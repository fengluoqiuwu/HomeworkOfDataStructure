//
// Created by 86133 on 2024/4/10.
//

#ifndef MY_CONTAINER_BASIC_ARRAY_LIST_H
#define MY_CONTAINER_BASIC_ARRAY_LIST_H

#include <string>
#include <algorithm>
#include <sstream>
#include <iostream>
#include "../AbstractClass/BasicError.h"

const unsigned int LIST_INIT_SIZE = 100;

//Read me before using it!!!
//Typename T's = operator must be reloaded
//Typename T's == operator should be reloaded if you want to use function find
//Typename T's > & < operator should be reloaded if you want to use function sort
template<typename T>
class BasicArrayList {
public:
    //Operator
    BasicArrayList<T>& operator=(const BasicArrayList<T>& basicArrayList);
    //Functions
    //Constructor & Destructor
    BasicArrayList();

    [[maybe_unused]] explicit BasicArrayList(unsigned long long inputSize);

    [[maybe_unused]] BasicArrayList(const T *array, unsigned long long arraySize);

    [[maybe_unused]] BasicArrayList(BasicArrayList const &basicArrayList);

    ~BasicArrayList();

    //Data Getter & Setter
    [[nodiscard]] unsigned long long getSize() const;

    [[nodiscard]] unsigned long long getLength() const;

    //Main
    //Maintain
    [[nodiscard]] bool isEmpty() const;

    T &get(unsigned long long index) const;

    unsigned long long getIndex(T &t) const;

    unsigned long long find(const T &t) const;//Please reload the == operator before using the function
    BasicArrayList<T> subList(
            unsigned long long beginIndex,
            unsigned long long endIndex
    ) const;//[beginIndex,endIndex)
    [[nodiscard]] std::string toString() const;

    void show() const;

    //Modify
    void clear();

    void add(const T &t);

    void addAll(const T *array, unsigned long long arraySize);

    void insert(unsigned long long index, const T &t);

    void insert(
            unsigned long long index,
            const T &t,
            unsigned long long amount
    );

    void insert(
            unsigned long long index,
            const BasicArrayList &basicArrayList
    );

     void insert(
            unsigned long long index,
            unsigned long long arraySize,
            const T *array
    );

    void erase(unsigned long long index);

    void remove(T t);

    void reSize(unsigned long long inputSize);

    void ascendingSort();//Ascending sorting,Please reload the > & < operator before using the function
    void ascendingSort(unsigned long long beginIndex,unsigned long long endIndex);

    void descendingSort();//Descending sorting,Please reload the > & < operator before using the function
    void descendingSort(unsigned long long beginIndex,unsigned long long endIndex);
private:
    //Data
    T *bottom;//指向索引0
    unsigned long long size;
    unsigned long long length;

    //Functions
    //Data Getter & Setter
    [[nodiscard]] T *getBottom() const;

    void setSize(unsigned long long inputSize);

    void setLength(unsigned long long inputLength);

    void setBottom(T *inputBottom);//A very dangerous function!!!
    //Main
    //Maintain
    void checkData() const;

    [[nodiscard]] bool isFull() const;

    //Modify
    void expand();
};

class BasicArrayListError : public BasicError {
public:
    BasicArrayListError(std::string &msg, unsigned int code) : BasicError(msg) {
        errorCode = code;
        std::cerr<<msg<<std::endl;
    }

    [[nodiscard]] unsigned int getErrorCode() const {
        return errorCode;
    }

private:
    unsigned int errorCode;
};

//public
//Operator

template<typename T>
BasicArrayList<T> &BasicArrayList<T>::operator=(const BasicArrayList<T> &basicArrayList) {
    if(this!=&basicArrayList){
        size = basicArrayList.getSize();
        length = basicArrayList.getLength();
        bottom = new T[size];

        std::copy(basicArrayList.getBottom(),
                  basicArrayList.getBottom() + basicArrayList.getSize(),
                  bottom
        );
    }
    return *this;
}

//Functions
//Constructor & Destructor

template<typename T>
BasicArrayList<T>::BasicArrayList() {
    size = LIST_INIT_SIZE;
    length = 0;
    bottom = new T[size];
}

template<typename T>
[[maybe_unused]] BasicArrayList<T>::BasicArrayList(unsigned long long inputSize) {
    size = inputSize;
    length = 0;
    bottom = new T[size];
}

template<typename T>
[[maybe_unused]] BasicArrayList<T>::BasicArrayList(const T *array, unsigned long long arraySize) {
    size = arraySize;
    length = arraySize;
    bottom = new T[size];

    std::copy(array, array + size, bottom);
}

template<typename T>
[[maybe_unused]] BasicArrayList<T>::BasicArrayList(const BasicArrayList &basicArrayList) {
    size = basicArrayList.getSize();
    length = basicArrayList.getLength();
    bottom = new T[size];

    std::copy(basicArrayList.getBottom(),
              basicArrayList.getBottom() + basicArrayList.getSize(),
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
    return (length == 0);
}

template<typename T>
T &BasicArrayList<T>::get(unsigned long long index) const {
    checkData();
    if (index >= length) {
        throw BasicArrayListError((std::string &) "BasicArrayList : function get() receive a invalid index!", 1);
    }

    return *(bottom + index);
}

template<typename T>
unsigned long long BasicArrayList<T>::getIndex(T &t) const {
    checkData();
    T *comparator = bottom;
    for (unsigned long long i = 0; i < length; ++i) {
        if (&t == comparator) {
            return i;
        }
        comparator++;
    }

    return 18446744073709551615ULL;
}

template<typename T>
unsigned long long BasicArrayList<T>::find(const T &t) const {
    checkData();

    T *comparator = bottom;
    for (unsigned long long i = 0; i < length; ++i) {
        if (t == (*comparator)) {
            return i;
        }
        comparator++;
    }

    return 18446744073709551615ULL;
}

template<typename T>
BasicArrayList<T> BasicArrayList<T>::subList(
        unsigned long long beginIndex,
        unsigned long long endIndex
) const {
    if (endIndex > length) {
        throw BasicArrayListError((std::string &) "BasicArrayList : function subList receive a too large endIndex!", 2);
    }
    if (beginIndex >= endIndex) {
        return BasicArrayList<T>();
    }

    T *subArray = new T[endIndex - beginIndex];
    std::copy(bottom + beginIndex, bottom + endIndex, subArray);
    auto *subArrayList = new BasicArrayList<T>(size);
    subArrayList->setBottom(subArray);
    subArrayList->setLength(endIndex - beginIndex);

    return *subArrayList;
}

template<typename T>
std::string BasicArrayList<T>::toString() const {
    std::stringstream ss;
    ss << '[';
    for (int i = 0; i < length; i++) {
        //ss << *(bottom + i);
        if (i != length - 1) {
            ss << ',';
        }
    }
    ss << ']';

    return ss.str();
}

template<typename T>
void BasicArrayList<T>::show() const {
    std::cout << "BasicArrayList" << std::endl;
    std::cout << toString() << std::endl;
    std::cout << "bottom:" << bottom << std::endl;
    std::cout << "size:" << size << std::endl;
    std::cout << "length:" << length << std::endl;
}

//Modify

template<typename T>
void BasicArrayList<T>::clear() {
    length = 0;
}

template<typename T>
void BasicArrayList<T>::add(const T &t) {
    checkData();

    if (isFull()) {
        expand();
    }

    *(bottom + length) = t;
    length++;
}

template<typename T>
void BasicArrayList<T>::addAll(const T *array, unsigned long long arraySize) {
    checkData();

    if (length + arraySize > size) {
        reSize(length + arraySize);
    }

    std::copy(array, array + arraySize, bottom + length);
    length += arraySize;
}

template<typename T>
void BasicArrayList<T>::insert(unsigned long long index, const T &t) {
    checkData();

    if (isFull()) {
        expand();
    }

    T *pointer = bottom + length;
    for (unsigned long long i = index; i <= length; i++) {
        pointer--;
        *(pointer + 1) = *pointer;
    }
    *(bottom + index) = t;
    length++;
}

template<typename T>
void BasicArrayList<T>::insert(unsigned long long index, const T &t, unsigned long long amount) {
    checkData();

    if (length + amount > size) {
        reSize(length + amount);
    }

    T *pointer = bottom + length;
    for (unsigned long long i = index; i <= length; i++) {
        pointer--;
        *(pointer + amount) = *pointer;
    }

    for (unsigned long long i = 0; i < amount; i++) {
        *(bottom + index + i) = t;
    }

    length += amount;
}

template<typename T>
void BasicArrayList<T>::insert(unsigned long long index, const BasicArrayList &basicArrayList) {
    insert(index, basicArrayList.getLength(), basicArrayList.getBottom());
}

template<typename T>
void BasicArrayList<T>::insert(unsigned long long index, unsigned long long arraySize, const T *array) {
    checkData();

    if (length + arraySize > size) {
        reSize(length + arraySize);
    }

    T *pointer = bottom + length;
    for (unsigned long long i = index; i <= length; i++) {
        pointer--;
        *(pointer + arraySize) = *pointer;
    }

    std::copy(array, array + arraySize, bottom + index);

    length += arraySize;
}

template<typename T>
void BasicArrayList<T>::erase(unsigned long long index) {
    checkData();

    if (index >= length) {
        throw BasicArrayListError((std::string &) "BasicArrayList : function erase receive a too large index!", 3);
    }

    T *pointer = bottom + index;
    for (unsigned long long i = index; i < length - 1; i++) {
        *(pointer) = *(pointer + 1);
        pointer++;
    }
    length--;
}

template<typename T>
void BasicArrayList<T>::remove(T t) {
    T *pointer = bottom;
    T *end = bottom + length;
    while (true) {
        if (pointer == end) {
            break;
        }

        if (*(pointer) == t) {
            erase(pointer - bottom);
            end--;
            continue;
        }

        pointer++;
    }
}

template<typename T>
void BasicArrayList<T>::reSize(unsigned long long inputSize) {
    T *newBottom = new T[inputSize];
    if (length > inputSize) {
        length = inputSize;
    }

    std::copy(bottom, bottom + length, newBottom);

    delete[] bottom;
    size = inputSize;
    bottom = newBottom;

}

template<typename T>
void BasicArrayList<T>::ascendingSort() {
    std::sort(bottom,bottom+length);
}

template<typename T>
void BasicArrayList<T>::ascendingSort(unsigned long long int beginIndex, unsigned long long int endIndex) {
    std::sort(bottom+beginIndex,bottom+endIndex);
}

template<typename T>
void BasicArrayList<T>::descendingSort() {
    std::sort(bottom,bottom+length);
    std::reverse(bottom,bottom+length);
}

template<typename T>
void BasicArrayList<T>::descendingSort(unsigned long long int beginIndex, unsigned long long int endIndex) {

    std::sort(bottom+beginIndex,bottom+endIndex);
    std::reverse(bottom+beginIndex,bottom+endIndex);
}

//private
//Functions
//Data Getter & Setter

template<typename T>
[[nodiscard]] T *BasicArrayList<T>::getBottom() const {
    return bottom;
}

template<typename T>
void BasicArrayList<T>::setSize(unsigned long long inputSize) {
    size = inputSize;
}

template<typename T>
void BasicArrayList<T>::setLength(unsigned long long inputLength) {
    length = inputLength;
}

template<typename T>
void BasicArrayList<T>::setBottom(T *inputBottom) {
    bottom = inputBottom;
}

//Main
//Maintain

template<typename T>
void BasicArrayList<T>::checkData() const {
    if (bottom == nullptr) {
        throw BasicArrayListError((std::string &) "BasicArrayList : bottom can't be nullptr!", 4);
    }
    if (size < length) {
        throw BasicArrayListError((std::string &) "BasicArrayList : length is bigger than size!", 5);
    }
}

template<typename T>
bool BasicArrayList<T>::isFull() const {
    return (length == size);
}

//Modify

template<typename T>
void BasicArrayList<T>::expand() {
    if (size >= 15372286728091293012ULL) {
        throw BasicArrayListError(
                (std::string &) "BasicArrayList : function expand couldn't work!The length is larger than 2^64-1;", 6
        );
    }

    reSize(size * 1.2 + 10);
}

#endif //MY_CONTAINER_BASIC_ARRAY_LIST_H
