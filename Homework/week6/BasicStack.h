//
// Created by 86133 on 2024/4/9.
//

#ifndef HOMEWORK_OF_DATA_STRUCTURE_BASIC_STACK_H
#define HOMEWORK_OF_DATA_STRUCTURE_BASIC_STACK_H

#define STACK_INIT_SIZE 100 //栈的初始大小

template <typename T>
class BasicStack {
private:
    unsigned int stackSize;
    T * button;                 //指向第一个元素
    T * top;                    //指向当前栈顶元素

    //Function
    bool isFull();              //栈是否是满的
public:
    //Constructor & Destructor
    BasicStack();
    explicit BasicStack(unsigned int size);
    BasicStack(BasicStack &basicStack);

    ~BasicStack();
    //Function
    void clear();               //清空栈
    bool isEmpty();             //返回是否为空
    unsigned int getLength();   //返回栈的长度
    unsigned int getSize();     //返回栈的大小
    T getTop();                 //返回栈顶元素
    void push(T t);            //新增元素
    T pop();                    //取出元素
};
//假设等号赋值已被重载


#endif //HOMEWORK_OF_DATA_STRUCTURE_BASIC_STACK_H
