//
// Created by 86133 on 2024/4/9.
//
#include <iostream>
#include <sstream>
#include "BasicStack.cpp"
#include "BasicQueue.cpp"

void testOfBasicStack();

void testOfBasicQueue();

void homework3_7();

void homework3_8();

void homework3_9();

void homework3_10();

void homework3_11();

int main() {
    //testOfBasicStack();
    //testOfBasicQueue();
    homework3_7();
    homework3_8();
    homework3_9();
    //homework3_10();
    //homework3_11();
    return 0;
}

void testOfBasicStack() {
    BasicStack<int> stack;
    std::cout << "isEmpty:\t" << stack.isEmpty() << std::endl;
    std::cout << "getLength:\t" << stack.getLength() << std::endl;
    std::cout << "getSize:\t" << stack.getSize() << std::endl;
    std::cout << "getTop:\t" << stack.getTop() << std::endl;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "isEmpty:\t" << stack.isEmpty() << std::endl;
    std::cout << "getLength:\t" << stack.getLength() << std::endl;
    std::cout << "getSize:\t" << stack.getSize() << std::endl;
    std::cout << "getTop:\t" << stack.getTop() << std::endl;
    std::cout << "pop:\t" << stack.pop() << std::endl;
    std::cout << "pop:\t" << stack.pop() << std::endl;

    stack.clear();
    std::cout << "isEmpty:\t" << stack.isEmpty() << std::endl;
    std::cout << "getSize:\t" << stack.getSize() << std::endl;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "isEmpty:\t" << stack.isEmpty() << std::endl;
    std::cout << "getLength:\t" << stack.getLength() << std::endl;
    std::cout << "getSize:\t" << stack.getSize() << std::endl;
    std::cout << "getTop:\t" << stack.getTop() << std::endl;

    BasicStack<int> copyStack(stack);

    std::cout << "isEmpty:\t" << copyStack.isEmpty() << std::endl;
    std::cout << "getLength:\t" << copyStack.getLength() << std::endl;
    std::cout << "getSize:\t" << copyStack.getSize() << std::endl;
    std::cout << "getTop:\t" << copyStack.getTop() << std::endl;
    std::cout << "pop:\t" << copyStack.pop() << std::endl;
    std::cout << "pop:\t" << copyStack.pop() << std::endl;
}

void testOfBasicQueue() {
    BasicQueue<int> queue;
    std::cout << "isEmpty:\t" << queue.isEmpty() << std::endl;
    std::cout << "getLength:\t" << queue.getLength() << std::endl;
    std::cout << "getSize:\t" << queue.getSize() << std::endl;
    std::cout << "getHead:\t" << queue.getHead() << std::endl;

    queue.push(1);
    queue.push(2);
    queue.push(3);

    std::cout << "isEmpty:\t" << queue.isEmpty() << std::endl;
    std::cout << "getLength:\t" << queue.getLength() << std::endl;
    std::cout << "getSize:\t" << queue.getSize() << std::endl;
    std::cout << "getHead:\t" << queue.getHead() << std::endl;
    std::cout << "pop:\t" << queue.pop() << std::endl;
    std::cout << "pop:\t" << queue.pop() << std::endl;

    queue.clear();
    std::cout << "isEmpty:\t" << queue.isEmpty() << std::endl;
    std::cout << "getSize:\t" << queue.getSize() << std::endl;

    queue.push(1);
    queue.push(2);
    queue.push(3);

    std::cout << "isEmpty:\t" << queue.isEmpty() << std::endl;
    std::cout << "getLength:\t" << queue.getLength() << std::endl;
    std::cout << "getSize:\t" << queue.getSize() << std::endl;
    std::cout << "getHead:\t" << queue.getHead() << std::endl;

    BasicQueue<int> copyQueue(queue);

    std::cout << "isEmpty:\t" << copyQueue.isEmpty() << std::endl;
    std::cout << "getLength:\t" << copyQueue.getLength() << std::endl;
    std::cout << "getSize:\t" << copyQueue.getSize() << std::endl;
    std::cout << "getHead:\t" << copyQueue.getHead() << std::endl;
    std::cout << "pop:\t" << copyQueue.pop() << std::endl;
    std::cout << "pop:\t" << copyQueue.pop() << std::endl;
}

//homework3_7
bool isMatch(const std::string& s){
    enum Parentheses{
        Round=0,
        Square=1,
        Curly=2
    };
    BasicStack<Parentheses> stack;
    for(char item:s){
        switch(item){
            case '(':
                stack.push(Round);
                break;
            case '[':
                stack.push(Square);
                break;
            case '{':
                stack.push(Curly);
                break;
            case ')':
                if(stack.isEmpty()||stack.getTop()!=Round) {
                    return false;
                }
                stack.pop();
                break;
            case ']':
                if(stack.isEmpty()||stack.getTop()!=Square) {
                    return false;
                }
                stack.pop();
                break;
            case '}':
                if(stack.isEmpty()||stack.getTop()!=Curly) {
                    return false;
                }
                stack.pop();
                break;
            default:
                return false;
                break;
        }
    }
    if(stack.isEmpty()){
        return true;
    }
    else{
        return false;
    }
}
void homework3_7(){
    std::cout<<"Homework3_7!!!!"<<std::endl;
    const std::string testString1="{(){()}[][{()}]([])}";//True
    const std::string testString2="{(){()[}][{()}]([])}";//False
    const std::string testString3="{(){()}[(][{()}]([])}";//False
    std::cout<<"String1:"<<isMatch(testString1)<<std::endl;
    std::cout<<"String2:"<<isMatch(testString2)<<std::endl;
    std::cout<<"String3:"<<isMatch(testString3)<<std::endl;
}
//homework3_8
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}
std::string infixToRPN(const std::string& infix) {
    std::stringstream rpn;
    BasicStack<char> operators;

    for (char c : infix) {
        if (std::isdigit(c)||std::isalpha(c)) {
            rpn << c << ' ';
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.isEmpty() && operators.getTop() != '(') {
                rpn << operators.getTop() << ' ';
                operators.pop();
            }
            operators.pop(); // 弹出左括号
        } else {
            while (!operators.isEmpty() && precedence(operators.getTop()) >= precedence(c)) {
                rpn << operators.getTop() << ' ';
                operators.pop();
            }
            operators.push(c);
        }
    }

    // 弹出剩余的操作符
    while (!operators.isEmpty()) {
        rpn << operators.getTop() << ' ';
        operators.pop();
    }

    return rpn.str();
}
void homework3_8(){
    std::cout<<"Homework3_8!!!!"<<std::endl;
    const std::string testString1="(3+4*5+6)/7*8";
    const std::string testString2="1+2+3+(4*(5+6*7))";
    const std::string testString3="(a*(b+c)-d)/e";
    std::cout<<"String1:"<<infixToRPN(testString1)<<std::endl;
    std::cout<<"String2:"<<infixToRPN(testString2)<<std::endl;
    std::cout<<"String3:"<<infixToRPN(testString3)<<std::endl;
}
//homework3_9
int calculate(int op1, int op2, char op) {
    switch (op) {
        case '+':
            return op1 + op2;
        case '-':
            return op1 - op2;
        case '*':
            return op1 * op2;
        case '/':
            return op1 / op2;
        default:
            throw std::invalid_argument("Invalid operator");
    }
}
int evaluateRPN(const std::string& rpn) {
    BasicStack<int> operands;

    std::stringstream ss(rpn);
    std::string token;
    while (ss >> token) {
        if (std::isdigit(token[0])) {
            // 操作数，压入栈中
            operands.push(std::stoi(token));
        } else {
            // 操作符，从栈中弹出操作数进行计算，结果压入栈中
            int op2 = operands.getTop();
            operands.pop();
            int op1 = operands.getTop();
            operands.pop();
            operands.push(calculate(op1, op2, token[0]));
        }
    }

    // 栈顶元素即为表达式的求值结果
    return operands.getTop();
}
void homework3_9(){
    std::cout<<"Homework3_9!!!!"<<std::endl;
    const std::string testString1="(2+4*5+6)/7*8";
    const std::string testString2="1+2+3+(4*(5+6*7))";
    const std::string testString3="(1*(2+3)-4)*2";
    const std::string testString4="3+4*7";
    std::cout<<"String1:"<<evaluateRPN(infixToRPN(testString1))<<std::endl;
    std::cout<<"String2:"<<evaluateRPN(infixToRPN(testString2))<<std::endl;
    std::cout<<"String3:"<<evaluateRPN(infixToRPN(testString3))<<std::endl;
    std::cout<<"String4:"<<evaluateRPN(infixToRPN(testString4))<<std::endl;
}
//homework3_10
template <typename T>
class QueueNode{
public:
    T* elem=new T;
    QueueNode<T>* next= nullptr;
    ~QueueNode(){
        free(elem);
    }
};
template <typename T>
class LinkedQueue{
private:
    QueueNode<T>* rear= nullptr;
public:
    ~LinkedQueue(){
        if(rear== nullptr){
            return;
        }
        QueueNode<T>* item1=rear;
        QueueNode<T>* item2=rear->next;
        while(item2!=rear){
            free(item1);
            item1=item2;
            item2=item2->next;
        }
    }
    void push(T t){
        if(rear== nullptr){
            rear=new QueueNode<T>;
            rear->elem=new T;
            rear->next=rear;
            *(rear->elem)=t;
        }
        else{
            QueueNode<T>* newNode = new QueueNode<T>;

            newNode->next=rear->next;
            rear->next=newNode;
            rear=newNode;
            rear->elem=new T;
            *(rear->elem)=t;
        }
    }
    T pop(){
        if(rear== nullptr){
            std::cerr << "Could not pop an 0 length Queue!" << std::endl;
            exit(-1);
        }

        T t=*(rear->elem);

        if(rear->next==rear){
            free(rear);
            rear= nullptr;
            return t;
        }

        QueueNode<T>* newRear=rear;

        while(newRear->next!=rear){
            newRear=newRear->next;
        }

        newRear->next=rear->next;
        free(rear);
        rear=newRear;

        return t;
    }
    void show(){
        QueueNode<T>* pointer =rear;
        do{
            std::cout<<*(pointer->elem)<<std::endl;
            pointer=pointer->next;
        }while(pointer!=rear);
    }
};
void homework3_10(){
    std::cout<<"Homework3_10!!!!"<<std::endl;
    LinkedQueue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.show();
    std::cout<<queue.pop()<<':'<<queue.pop()<<':'<<queue.pop()<<std::endl;
}
//homework3_11
void homework3_11(){
//见BasicQueue文件
}