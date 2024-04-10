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
    [[maybe_unused]] explicit BasicArrayList(unsigned long long int inputSize);
    [[maybe_unused]] BasicArrayList(const T* array,unsigned long long int arraySize);
    [[maybe_unused]] BasicArrayList(BasicArrayList const &basicArrayList);
    ~BasicArrayList();
    //Data Getter & Setter
    [[nodiscard]] unsigned long long int getSize() const;
    [[nodiscard]] unsigned long long int getLength() const;
    //Main
        //Maintain
    bool isEmpty() const;//TODO
    T& get() const;//TODO
    unsigned long long int getIndex() const;//TODO
    unsigned long long int find(const T& t) const;//TODO Please reload the == operator before using the function
    BasicArrayList<T>& subList(
            const long long int beginIndex,
            const long long int endIndex
            ) const;//TODO [beginIndex,endIndex)
        //Modify
    void clear();//TODO
    void add(const T& t);//TODO
    void addAll(const T* array,unsigned long long int arraySize);//TODO
    void insert(const long long int index,const T& t);//TODO
    void insert(const long long int index,const T& t,const long long int amount);
    void insert(
            const long long int index,
            BasicArrayList const &basicArrayList
            );//TODO
    void insert(
            const long long int index,
            const T* array,
            unsigned long long int arraySize
    );//TODO
    void erase(unsigned long long int index);//TODO
    void remove(T& t);//TODO
    void reSize(unsigned long long int inputSize);//TODO
private:
    //Data
    T* bottom;//指向索引-1
    unsigned long long int size;
    unsigned long long int length;
    //Functions
        //Data Getter & Setter
    [[nodiscard]] unsigned long long int getBottom() const;
    void setSize(unsigned long long int inputSize);
    void setLength(unsigned long long int inputLength);
    void setButton(T* inputBottom);//A very dangerous function!!!
    //Main
        //Maintain
    void checkData();//TODO
    void isFull();//TODO
        //Modify
};


#endif //MY_CONTAINER_BASIC_ARRAY_LIST_H
