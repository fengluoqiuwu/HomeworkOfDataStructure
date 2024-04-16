//
// Created by 86133 on 2024/4/9.
//

#ifndef HOMEWORK_OF_DATA_STRUCTURE_BASIC_QUEUE_H
#define HOMEWORK_OF_DATA_STRUCTURE_BASIC_QUEUE_H

#define QUEUE_INIT_SIZE 100

template <typename T>
class BasicQueue {
private:
    unsigned int queueSize; //队列容量
    T * front;              //队头指针
    T * rear;               //队尾指针
    T * begin;              //连续空间中第一个的指针
    bool isFull();          //是否已满
public:
    //Constructor & Destructor
    BasicQueue();
    explicit BasicQueue(unsigned int size);
    BasicQueue(BasicQueue& basicQueue);
    ~BasicQueue();
    //Functions
    void clear();
    bool isEmpty();
    unsigned int getSize();
    unsigned int getLength();
    void push(T t);
    T pop();
    T getHead();
};//假设已经完成重载,-1为空，-2为满,其中front是队尾，rear是队头


#endif //HOMEWORK_OF_DATA_STRUCTURE_BASIC_QUEUE_H
