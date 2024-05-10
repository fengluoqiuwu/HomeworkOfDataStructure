//
// Created by 86133 on 2024/4/10.
//

#ifndef MY_CONTAINER_BASIC_LINKED_LIST_H
#define MY_CONTAINER_BASIC_LINKED_LIST_H

//Read me before using it!!!
//Typename T's = operator must be reloaded
//Typename T's == operator should be reloaded if you want to use function find
//Typename T's > & < operator should be reloaded if you want to use function sort
template<typename T>
class BasicLinkedList {
public:
    //Operator
    BasicLinkedList<T>& operator=(const BasicLinkedList<T>& BasicLinkedList);
    //Functions
    //Constructor & Destructor
    BasicLinkedList();

    [[maybe_unused]] explicit BasicLinkedList(unsigned long long inputSize);

    [[maybe_unused]] BasicLinkedList(const T *array, unsigned long long arraySize);

    [[maybe_unused]] BasicLinkedList(BasicLinkedList const &BasicLinkedList);

    ~BasicLinkedList();

    //Data Getter & Setter
    [[nodiscard]] unsigned long long getSize();

    [[nodiscard]] unsigned long long getLength();

    //Main
    //Maintain
    [[nodiscard]] bool isEmpty();

    T &get(unsigned long long index);

    unsigned long long getIndex(T &t);

    unsigned long long find(const T &t);//Please reload the == operator before using the function
    BasicLinkedList<T> subList(
            unsigned long long beginIndex,
            unsigned long long endIndex
    ) const;//[beginIndex,endIndex)

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
            const BasicLinkedList &BasicLinkedList
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
};


#endif //MY_CONTAINER_BASIC_LINKED_LIST_H
