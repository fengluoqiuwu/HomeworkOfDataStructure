//
// Created by 86133 on 2024/4/10.
//

#ifndef MY_CONTAINER_BASIC_ARRAY_LIST_H
#define MY_CONTAINER_BASIC_ARRAY_LIST_H

const unsigned int LIST_INIT_SIZE=100;

//Read me before using it!!!
//Typename T's = operator must be reloaded
//Typename T's == operator should be reloaded if you want to use function find
template<typename T>
class BasicArrayList {
public:
    //Functions
    //Constructor & Destructor
    BasicArrayList();
    [[maybe_unused]] explicit BasicArrayList(unsigned long long inputSize);
    [[maybe_unused]] BasicArrayList(const T* array,unsigned long long arraySize);
    [[maybe_unused]] BasicArrayList(BasicArrayList const &basicArrayList);
    ~BasicArrayList();
    //Data Getter & Setter
    [[nodiscard]] unsigned long long getSize() const;
    [[nodiscard]] unsigned long long getLength() const;
    //Main
        //Maintain
    bool isEmpty() const;
    T& get(unsigned long long index) const;
    unsigned long long getIndex(T& t) const;
    unsigned long long find(const T& t) const;//TODO Please reload the == operator before using the function
    BasicArrayList<T>& subList(
            const unsigned long long beginIndex,
            const unsigned long long endIndex
            ) const;//TODO [beginIndex,endIndex)
        //Modify
    void clear();//TODO
    void add(const T& t);//TODO
    void addAll(const T* array,unsigned long long arraySize);//TODO
    void insert(const unsigned long long index,const T& t);//TODO
    void insert(const unsigned long long index,const T& t,const unsigned long long amount);
    void insert(
            const unsigned long long index,
            BasicArrayList const &basicArrayList
            );//TODO
    void insert(
            const unsigned long long index,
            const T* array,
            unsigned long long arraySize
    );//TODO
    void erase(unsigned long long index);//TODO
    void remove(T& t);//TODO
    void reSize(unsigned long long inputSize);//TODO
private:
    //Data
    T* bottom;//指向索引-1
    unsigned long long size;
    unsigned long long length;
    //Functions
        //Data Getter & Setter
    [[nodiscard]] unsigned long long getBottom() const;
    void setSize(unsigned long long inputSize);
    void setLength(unsigned long long inputLength);
    void setBottom(T* inputBottom);//A very dangerous function!!!
    //Main
        //Maintain
    void checkData();
    bool isFull();
        //Modify
};


#endif //MY_CONTAINER_BASIC_ARRAY_LIST_H
