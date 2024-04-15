//
// Created by 86133 on 2024/4/15.
//

#include <iostream>
#include "Polynomial_Node.h"

Node::Node(double number) : coefficient(number) {
    exp=0;
}

Node::Node(double coefficient, unsigned long long int exp) : coefficient(coefficient), exp(exp) {}

void Node::xPower(unsigned long long int n) {
    exp+=n;
}

Node &Node::operator=(double num) {
    exp=0;
    coefficient=num;
    
    return *this;
}

Node &Node::operator=(const Node &other) = default;

Node &Node::operator+=(const Node &other) {
    if(exp!=other.exp){
        std::cerr<<"Polynomial_Node.cpp Node::operator += receive a different exp Node!";
        throw std::exception();
    }
    coefficient+=other.coefficient;
    
    return *this;
}

Node &Node::operator-=(const Node &other) {
    if(exp!=other.exp){
        std::cerr<<"Polynomial_Node.cpp Node::operator -= receive a different exp Node!";
        throw std::exception();
    }
    coefficient-=other.coefficient;

    return *this;
}

Node &Node::operator*=(const Node &other) {
    coefficient*=other.coefficient;
    exp+=other.exp;
    
    return *this;
}

Node &Node::operator/=(const Node &other) {
    if(other.exp==0){
        std::cerr<<"Polynomial_Node.cpp Node::operator /= receive 0!";
        throw std::exception();
    }
    if(exp<other.exp){
        std::cerr<<"Polynomial_Node.cpp Node::operator /= receive a too large exp Node!";
        throw std::exception();
    }
    coefficient/=other.coefficient;
    exp-=other.exp;
    
    return *this;
}

Node Node::operator+(const Node &other) const {
    Node copy=*this;
    if(copy.exp!=other.exp){
        std::cerr<<"Polynomial_Node.cpp Node::operator + receive a different exp Node!";
        throw std::exception();
    }
    copy.coefficient+=other.coefficient;

    return copy;
}

Node Node::operator-(const Node &other) const {
    Node copy=*this;
    if(copy.exp!=other.exp){
        std::cerr<<"Polynomial_Node.cpp Node::operator - receive a different exp Node!";
        throw std::exception();
    }
    copy.coefficient-=other.coefficient;

    return copy;
}

Node Node::operator*(const Node &other) const {
    Node copy=*this;
    copy*=other;
    return copy;
}

Node Node::operator/(const Node &other) const {
    Node copy=*this;
    if(other.exp==0){
        std::cerr<<"Polynomial_Node.cpp Node::operator / receive 0!";
        throw std::exception();
    }
    if(copy.exp<other.exp){
        std::cerr<<"Polynomial_Node.cpp Node::operator / receive a too large exp Node!";
        throw std::exception();
    }
    copy.coefficient/=other.coefficient;
    copy.exp-=other.exp;

    return copy;
}

bool Node::operator==(double num) const {
    if(coefficient==0&&num==0){
        return true;
    }
    
    if(exp==0&&coefficient==num){
        return true;
    }

    return false;
}

bool Node::operator==(const Node &other) const {
    if(coefficient==0&&other.coefficient==0){
        return true;
    }
    return (coefficient==other.coefficient&&exp==other.exp);
}

bool Node::operator>(const Node &other) const {
    return (exp>other.exp);
}

bool Node::operator<(const Node &other) const {
    return (exp<other.exp);
}

bool Node::operator>=(const Node &other) const {
    return (exp>=other.exp);
}

bool Node::operator<=(const Node &other) const {
    return (exp<=other.exp);
}


Polynomial_Node::Polynomial_Node() {
    coefficientList.add(Node(0));
}

Polynomial_Node::Polynomial_Node(BasicArrayList<Node> &basicArrayList) {
    coefficientList=basicArrayList;

    coefficientList.sort();
}

Polynomial_Node::Polynomial_Node(Node *array, unsigned long long int arraySize) {

}

Polynomial_Node::~Polynomial_Node() {

}

std::string Polynomial_Node::toString() const {
    return std::string();
}

void Polynomial_Node::show() const {

}

int Polynomial_Node::deg() const {
    return 0;
}

double Polynomial_Node::getValue(double x) const {
    return 0;
}

Polynomial_Node Polynomial_Node::differentiate() const {
    return Polynomial_Node();
}

double Polynomial_Node::valDifferentiate(double x) const {
    return 0;
}

Polynomial_Node Polynomial_Node::integrate() const {
    return Polynomial_Node();
}

double Polynomial_Node::valIntegrate(double x1, double x2) const {
    return 0;
}

Polynomial_Node &Polynomial_Node::operator=(const Polynomial_Node &other) {
    return *this;
}

Polynomial_Node &Polynomial_Node::operator=(double num) {
    return *this;
}

Polynomial_Node &Polynomial_Node::operator+=(const Polynomial_Node &other) {
    return *this;
}

Polynomial_Node &Polynomial_Node::operator+=(double num) {
    return *this;
}

Polynomial_Node &Polynomial_Node::operator-=(const Polynomial_Node &other) {
    return *this;
}

Polynomial_Node &Polynomial_Node::operator-=(double num) {
    return *this;
}

Polynomial_Node &Polynomial_Node::operator*=(const Polynomial_Node &other) {
    return *this;
}

Polynomial_Node &Polynomial_Node::operator*=(double num) {
    return *this;
}

Polynomial_Node &Polynomial_Node::operator/=(const Polynomial_Node &other) {
    return *this;
}

Polynomial_Node &Polynomial_Node::operator/=(double num) {
    return *this;
}

Polynomial_Node &Polynomial_Node::operator%=(const Polynomial_Node &other) {
    return *this;
}

Polynomial_Node Polynomial_Node::operator+(const Polynomial_Node &other) const {
    return Polynomial_Node();
}

Polynomial_Node Polynomial_Node::operator+(double num) const {
    return Polynomial_Node();
}

Polynomial_Node Polynomial_Node::operator-(const Polynomial_Node &other) const {
    return Polynomial_Node();
}

Polynomial_Node Polynomial_Node::operator-(double num) const {
    return Polynomial_Node();
}

Polynomial_Node Polynomial_Node::operator*(const Polynomial_Node &other) const {
    return Polynomial_Node();
}

Polynomial_Node Polynomial_Node::operator*(double num) const {
    return Polynomial_Node();
}

Polynomial_Node Polynomial_Node::operator/(const Polynomial_Node &other) const {
    return Polynomial_Node();
}

Polynomial_Node Polynomial_Node::operator/(double num) const {
    return Polynomial_Node();
}

Polynomial_Node Polynomial_Node::operator%(const Polynomial_Node &other) const {
    return Polynomial_Node();
}

bool Polynomial_Node::operator==(const Polynomial_Node &other) const {
    return false;
}

bool Polynomial_Node::operator==(double num) const {
    return false;
}

void Polynomial_Node::format() {

}

const BasicArrayList<Node> &Polynomial_Node::getCoefficientList() const {
    return coefficientList;
}

Node Polynomial_Node::getFirst() const {
    return Node(0);
}

Polynomial_Node Polynomial_Node::xPower(unsigned long long int n) const {
    return Polynomial_Node();
}
