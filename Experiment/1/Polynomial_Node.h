//
// Created by 86133 on 2024/4/15.
//

#ifndef DATA_STRUCTURE_POLYNOMIAL_NODE_H
#define DATA_STRUCTURE_POLYNOMIAL_NODE_H


#include "BasicArrayList.h"

class Node{
public:
    double coefficient;
    unsigned long long exp;

    explicit Node(double number);
    Node(double coefficient, unsigned long long int exp);
    void xPower(unsigned long long n);
    [[nodiscard]] double getValue(double x)const;

    Node& operator=(double num);
    Node& operator=(const Node& other);
    Node& operator+=(const Node& other);
    Node& operator-=(const Node& other);
    Node& operator*=(const Node& other);
    Node& operator/=(const Node& other);

    Node operator+(const Node& other) const;
    Node operator-(const Node& other) const;
    Node operator*(const Node& other) const;
    Node operator/(const Node& other) const;

    bool operator==(double num) const;//任何为0的都相等
    bool operator==(const Node& other) const;//任何为0的都相等
    bool operator!=(double num) const;//任何为0的都相等
    bool operator!=(const Node& other) const;//任何为0的都相等
    bool operator>(const Node& other) const;//比较的是exp
    bool operator<(const Node& other) const;//比较的是exp
    bool operator>=(const Node& other) const;//比较的是exp
    bool operator<=(const Node& other) const;//比较的是exp
};//注意防止不规范的0_Node出现

//没有用大浮点数，用的是double，如果幂次过大求值肯定会出现问题
class Polynomial_Node {
public:
    //Functions
    //Constructor & Destructor
    Polynomial_Node();
    explicit Polynomial_Node(BasicArrayList<Node>& basicArrayList);
    Polynomial_Node(Node * array, unsigned long long arraySize);
    ~Polynomial_Node();
    //String & Print
    [[nodiscard]] std::string toString() const;
    void show() const;
    //Calculate
    [[nodiscard]] int deg() const;
    [[nodiscard]] double getValue(double x) const;
    [[nodiscard]] Polynomial_Node differentiate() const;
    [[nodiscard]] double valDifferentiate(double x) const;
    [[nodiscard]] Polynomial_Node integrate() const;
    [[nodiscard]] double valIntegrate(double x1,double x2) const;
    //Operator
    Polynomial_Node& operator=(const Polynomial_Node& other) ;
    Polynomial_Node& operator=(double num) ;
    Polynomial_Node& operator+=(const Polynomial_Node& other) ;
    Polynomial_Node& operator+=(double num) ;
    Polynomial_Node& operator-=(const Polynomial_Node& other) ;
    Polynomial_Node& operator-=(double num) ;
    Polynomial_Node& operator*=(const Polynomial_Node& other) ;
    Polynomial_Node& operator*=(double num) ;
    Polynomial_Node& operator/=(const Polynomial_Node& other) ;
    Polynomial_Node& operator/=(double num) ;
    Polynomial_Node& operator%=(const Polynomial_Node& other) ;

    Polynomial_Node operator+(const Polynomial_Node& other) const;
    Polynomial_Node operator+(double num) const;
    Polynomial_Node operator-(const Polynomial_Node& other) const;
    Polynomial_Node operator-(double num) const;
    Polynomial_Node operator*(const Polynomial_Node& other) const;
    Polynomial_Node operator*(double num) const;
    Polynomial_Node operator/(const Polynomial_Node& other) const;
    Polynomial_Node operator/(double num) const;
    Polynomial_Node operator%(const Polynomial_Node& other) const;

    bool operator==(const Polynomial_Node& other) const ;
    bool operator==(double num) const ;
    bool operator!=(const Polynomial_Node& other) const ;
    bool operator!=(double num) const ;

public:
    //Data
    BasicArrayList<Node> coefficientList;//降序排序,最后一项必然是常数项，0也要有
    //Functions
    void format();//去除0，保留常数,排序
    [[nodiscard]] const BasicArrayList<Node> &getCoefficientList() const;
    [[nodiscard]] Node getFirst() const;//最高位
    [[nodiscard]] Node getLast() const;//常数位
    [[nodiscard]] Polynomial_Node xPower(unsigned long long n) const;
};


#endif //DATA_STRUCTURE_POLYNOMIAL_NODE_H
