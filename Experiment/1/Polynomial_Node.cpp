//
// Created by 86133 on 2024/4/15.
//

#include <iostream>
#include <sstream>
#include <valarray>
#include "Polynomial_Node.h"

Node::Node() {
    coefficient=0;
    exp=0;
}

Node::Node(double number) : coefficient(number) {
    exp=0;
}

Node::Node(double coefficient, unsigned long long int exp) : coefficient(coefficient), exp(exp) {}

void Node::xPower(unsigned long long int n) {
    exp+=n;
}

double Node::getValue(double x) const {
    return coefficient*std::pow(x,static_cast<double>(exp));
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
    if(std::abs(coefficient)<=1e-10&&std::abs(num)<=1e-10){
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

bool Node::operator!=(double num) const {
    return !((*this)==num);
}

bool Node::operator!=(const Node &other) const {
    return !((*this)==other);
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

    format();
}

Polynomial_Node::Polynomial_Node(Node *array, unsigned long long int arraySize) {
    coefficientList.addAll(array,arraySize);

    format();
}

Polynomial_Node::~Polynomial_Node()=default;

std::string Polynomial_Node::toString() const {
    std::stringstream ss;
    ss<<"p(x)=";

    bool isFirst=true;
    for(int i=0;i<coefficientList.getLength()-1;i++){
        Node node=coefficientList.get(i);
        if(!isFirst){
            if(node.coefficient>0){
                ss<<"+";
            }
            else{
                ss<<"-";
            }
        }
        else{
            isFirst=false;
        }

        if(std::abs(node.coefficient)!=1){
            ss<<std::abs(node.coefficient);
        }

        if(node.exp!=1){
            ss<<"x^"<<node.exp;
        }
        else{
            ss<<"x";
        }
    }//处理系数

    //处理常数项
    Node node=getLast();
    if(isFirst){
        ss<<node.coefficient;
    }
    else if(node.coefficient!=0){
        if(node.coefficient>0){
            ss<<"+";
        }
        else{
            ss<<"-";
        }
        ss<<std::abs(node.coefficient);
    }

    return ss.str();
}

void Polynomial_Node::show() const {
    std::cout<<toString()<<std::endl;
}

int Polynomial_Node::deg() const {
    return (static_cast<int>(getFirst().exp));
}

double Polynomial_Node::getValue(double x) const {
    double result=0;

    for(int i=0;i<coefficientList.getLength();++i){
        result+=coefficientList.get(i).getValue(x);
    }

    return result;
}

Polynomial_Node Polynomial_Node::differentiate() const {
    BasicArrayList<Node> coeList;

    for(int i=0;i<coefficientList.getLength()-1;++i){
        Node node=coefficientList.get(i);
        coeList.add(Node(static_cast<double>(node.exp)*node.coefficient,node.exp-1));
    }

    return Polynomial_Node(coeList);
}

double Polynomial_Node::valDifferentiate(double x) const {
    return differentiate().getValue(x);
}

Polynomial_Node Polynomial_Node::integrate() const {
    BasicArrayList<Node> coeList;
    coeList.add(Node(0));

    for(int i=0;i<coefficientList.getLength();++i){
        Node node=coefficientList.get(i);
        coeList.add(Node(node.coefficient/static_cast<double>(node.exp+1),node.exp+1));
    }

    return Polynomial_Node(coeList);
}

double Polynomial_Node::valIntegrate(double x1, double x2) const {
    Polynomial_Node integratePolynomial=integrate();
    return (integratePolynomial.getValue(x2)-integratePolynomial.getValue(x1));
}

Polynomial_Node &Polynomial_Node::operator=(const Polynomial_Node &other) = default;

Polynomial_Node &Polynomial_Node::operator=(double num) {
    coefficientList.clear();
    coefficientList.add(Node(num));

    return *this;
}

Polynomial_Node &Polynomial_Node::operator+=(const Polynomial_Node &other) {
    *this=*this+other;
    return *this;
}

Polynomial_Node &Polynomial_Node::operator+=(double num) {
    coefficientList.get(coefficientList.getLength()-1).coefficient+=num;
    return *this;
}

Polynomial_Node &Polynomial_Node::operator-=(const Polynomial_Node &other) {
    *this=*this-other;
    return *this;
}

Polynomial_Node &Polynomial_Node::operator-=(double num) {
    coefficientList.get(coefficientList.getLength()-1).coefficient-=num;
    return *this;
}

Polynomial_Node &Polynomial_Node::operator*=(const Polynomial_Node &other) {
    *this=*this*other;
    return *this;
}

Polynomial_Node &Polynomial_Node::operator*=(double num) {
    if(num==0){
        *this=0;
    }
    else {
        for (int i = 0; i < coefficientList.getLength(); ++i) {
            coefficientList.get(i).coefficient *= num;
        }
    }

    return *this;
}

Polynomial_Node &Polynomial_Node::operator/=(const Polynomial_Node &other) {
    if(other.deg()==0){
        std::cerr<<"Polynomial_Node.cpp PolynomialNode::operator /= receive a number!"<<std::endl;
        throw std::exception();
    }
    else{
        *this=(*this)/other;
    }
    return *this;
}

Polynomial_Node &Polynomial_Node::operator/=(double num) {
    if(num==0){
        std::cerr<<"Polynomial_Node.cpp PolynomialNode::operator /= receive a 0!"<<std::endl;
        throw std::exception();
    }
    else {
        for (int i = 0; i < coefficientList.getLength(); ++i) {
            coefficientList.get(i).coefficient /= num;
        }
    }

    return *this;
}

Polynomial_Node &Polynomial_Node::operator%=(const Polynomial_Node &other) {
    if(other.deg()==0){
        std::cerr<<"Polynomial_Node.cpp PolynomialNode::operator %= receive a number!"<<std::endl;
        throw std::exception();
    }
    else{
        *this=(*this)%other;
    }

    return *this;
}

Polynomial_Node Polynomial_Node::operator+(const Polynomial_Node &other) const {
    Polynomial_Node result;
    result.coefficientList.clear();

    unsigned long long thisIndex=0;
    unsigned long long otherIndex=0;

    while(thisIndex!=((*this).coefficientList.getLength())&&
          otherIndex!=(other.coefficientList.getLength())
            ){
        if((*this).coefficientList.get(thisIndex)>
        other.coefficientList.get(otherIndex)){
            result.coefficientList.add((*this).coefficientList.get(thisIndex));
            thisIndex++;
        }
        else if((*this).coefficientList.get(thisIndex)<
                other.coefficientList.get(otherIndex)){
            result.coefficientList.add(other.coefficientList.get(otherIndex));
            otherIndex++;
        }
        else{
            result.coefficientList.add((*this).coefficientList.get(thisIndex)+
                                       other.coefficientList.get(otherIndex));
            thisIndex++;
            otherIndex++;
        }
    }

    result.format();

    return result;
}

Polynomial_Node Polynomial_Node::operator+(double num) const {
    Polynomial_Node copy=*this;
    copy.coefficientList.get(copy.coefficientList.getLength()-1).coefficient+=num;
    return copy;
}

Polynomial_Node Polynomial_Node::operator-(const Polynomial_Node &other) const {
    Polynomial_Node result;
    result.coefficientList.clear();

    unsigned long long thisIndex=0;
    unsigned long long otherIndex=0;

    while(thisIndex!=((*this).coefficientList.getLength())&&
          otherIndex!=(other.coefficientList.getLength())
            ){
        if((*this).coefficientList.get(thisIndex)>
           other.coefficientList.get(otherIndex)){
            result.coefficientList.add((*this).coefficientList.get(thisIndex));
            thisIndex++;
        }
        else if((*this).coefficientList.get(thisIndex)<
                other.coefficientList.get(otherIndex)){
            Node node=other.coefficientList.get(otherIndex);
            node.coefficient=-node.coefficient;
            result.coefficientList.add(node);
            otherIndex++;
        }
        else{
            result.coefficientList.add((*this).coefficientList.get(thisIndex)-
                                       other.coefficientList.get(otherIndex));
            thisIndex++;
            otherIndex++;
        }
    }

    result.format();

    return result;
}

Polynomial_Node Polynomial_Node::operator-(double num) const {
    Polynomial_Node copy=*this;
    copy.coefficientList.get(copy.coefficientList.getLength()-1).coefficient-=num;
    return copy;
}

Polynomial_Node Polynomial_Node::operator*(const Polynomial_Node &other) const {
    Polynomial_Node result;
    result=0;

    if((*this!=0)&&other!=0) {
        for (int i = 0; i <other.coefficientList.getLength();++i){
            Node node=other.coefficientList.get(i);
            result+=((*this).xPower(node.exp)*node.coefficient);
        }
    }

    result.format();

    return result;
}

Polynomial_Node Polynomial_Node::operator*(double num) const {
    Polynomial_Node copy=*this;

    if(num==0){
        copy=0;
    }
    else {
        for (int i = 0; i < copy.coefficientList.getLength(); ++i) {
            copy.coefficientList.get(i).coefficient *= num;
        }
    }

    return copy;
}

Polynomial_Node Polynomial_Node::operator/(const Polynomial_Node &other) const {
    if(other.deg()==0){
        std::cerr<<"Polynomial_Node.cpp Polynomial_Node::operator/ receive number!"<<std::endl;
        throw std::exception();
    }

    Polynomial_Node copy=*this;
    Polynomial_Node result;
    result=0;

    while(copy.deg()>=other.deg()){
        Node node(0);
        node.coefficient=copy.getFirst().coefficient/other.getFirst().coefficient;
        node.exp=copy.deg()-other.deg();

        result.coefficientList.add(node);
        copy-=(other.xPower(node.exp)*(node.coefficient));
    }

    result.format();

    return result;
}

Polynomial_Node Polynomial_Node::operator/(double num) const {
    Polynomial_Node copy=*this;
    if(num==0){
        std::cerr<<"Polynomial_Node.cpp PolynomialNode::operator / receive a 0!"<<std::endl;
        throw std::exception();
    }
    else {
        for (int i = 0; i < copy.coefficientList.getLength(); ++i) {
            copy.coefficientList.get(i).coefficient /= num;
        }
    }

    return copy;
}

Polynomial_Node Polynomial_Node::operator%(const Polynomial_Node &other) const {
    if(other.deg()==0){
        std::cerr<<"Polynomial_Node.cpp Polynomial_Node::operator% receive number!"<<std::endl;
        throw std::exception();
    }

    Polynomial_Node copy=*this;

    while(copy.deg()>=other.deg()){
        copy-=(other.xPower(copy.deg()-other.deg())*(copy.getFirst().coefficient/other.getFirst().coefficient));
    }

    copy.format();

    return copy;
}

bool Polynomial_Node::operator==(const Polynomial_Node &other) const {
    if(coefficientList.getLength()!=other.coefficientList.getLength()){
        return false;
    }

    for(int i=0;i<coefficientList.getLength();i++){
        if(coefficientList.get(i)!=other.coefficientList.get(i)){
            return false;
        }
    }
    return true;
}

bool Polynomial_Node::operator==(double num) const {
    return (deg()==0&&getLast().coefficient==num);
}

bool Polynomial_Node::operator!=(const Polynomial_Node &other) const {
    return !((*this)==other);
}

bool Polynomial_Node::operator!=(double num) const {
    return !((*this)==num);
}

void Polynomial_Node::format() {
    for(int i=0;i<coefficientList.getLength();i++){
        if(coefficientList.get(i)==0){
            coefficientList.erase(i);
            i--;
        }
    }

    coefficientList.descendingSort(0,coefficientList.getLength());

    if(coefficientList.getLength()==0||getLast().exp!=0){
        coefficientList.add(Node(0));
    }
}

const BasicArrayList<Node> &Polynomial_Node::getCoefficientList() const {
    return coefficientList;
}

Node Polynomial_Node::getFirst() const{
    return coefficientList.get(0);
}

Node Polynomial_Node::getLast() const{
    return coefficientList.get(coefficientList.getLength()-1);
}

Polynomial_Node Polynomial_Node::xPower(unsigned long long int n) const {
    Polynomial_Node copy=*this;
    for(int i=0;i<copy.coefficientList.getLength();i++){
        copy.coefficientList.get(i).xPower(n);
    }

    copy.format();

    return copy;
}
