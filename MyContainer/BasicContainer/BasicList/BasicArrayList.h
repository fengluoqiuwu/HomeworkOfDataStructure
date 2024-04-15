//
// Created by 86133 on 2024/4/10.
//

#ifndef MY_CONTAINER_BASIC_ARRAY_LIST_H
#define MY_CONTAINER_BASIC_ARRAY_LIST_H

#include <string>
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

    void sort();//Ascending sorting,Please reload the > & < operator before using the function

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
    }

    [[nodiscard]] unsigned int getErrorCode() const {
        return errorCode;
    }

private:
    unsigned int errorCode;
};

#endif //MY_CONTAINER_BASIC_ARRAY_LIST_H
