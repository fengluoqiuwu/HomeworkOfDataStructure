//
// Created by 86133 on 2024/5/1.
//

#ifndef DATA_STRUCTURE_QUEUE_H
#define DATA_STRUCTURE_QUEUE_H

template <typename T>
class queue : private BasicLinckedList<T>{
public:
    //Constructor & Destructor
    queue();
    queue(queue<T> &inputQueue);
    ~queue();
    //Method
    bool empty{};
    unsigned long long size();
    T& front();
    T& back();
    void push(const T& inputT);
    T pop();
    void swap(queue& other);
};

#endif //DATA_STRUCTURE_QUEUE_H
