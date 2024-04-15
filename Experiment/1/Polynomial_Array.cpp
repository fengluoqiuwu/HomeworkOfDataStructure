//
// Created by 86133 on 2024/4/14.
//

#include <iostream>
#include <sstream>
#include "Polynomial_Array.h"

//public
    //Functions
        //Constructor & Destructor

Polynomial_Array::Polynomial_Array(){
    coefficientList.add(0);
}

Polynomial_Array::Polynomial_Array(BasicArrayList<double>& basicArrayList) {
    coefficientList=basicArrayList;
}

Polynomial_Array::Polynomial_Array(double *array, unsigned long long int arraySize) {
    coefficientList=BasicArrayList<double>(array,arraySize);
}

Polynomial_Array::~Polynomial_Array() = default;

        //String & Print

std::string Polynomial_Array::toString() const {
    std::stringstream ss;
    ss<<"p(x)=";

    if(coefficientList.getLength()==1){
        ss<<coefficientList.get(0);
    }
    else {
        bool isFirst=true;
        for (unsigned long long i = coefficientList.getLength() - 1; i >= 1; --i) {
            if (coefficientList.get(i) != 0) {
                if(!isFirst){
                    if(coefficientList.get(i)>0){
                        ss<<"+";
                    }
                    else{
                        ss<<"-";
                    }
                } else{
                    isFirst= false;
                }

                if(i!=1) {
                    if (coefficientList.get(i) == 1 || coefficientList.get(i) == -1) {
                        ss << "x^" << i;
                    } else {
                        ss << std::abs(coefficientList.get(i)) << "x^" << i;
                    }
                }
                else{
                    if (coefficientList.get(1) == 1 || coefficientList.get(1) == -1) {
                        ss << "x";
                    } else {
                        ss << std::abs(coefficientList.get(i)) << "x";
                    }
                }
            }
        }

        if(coefficientList.get(0)!=0){
            if(!isFirst){
                if(coefficientList.get(0)>0){
                    ss<<"+";
                }
                else{
                    ss<<"-";
                }
            }
            ss << std::abs(coefficientList.get(0));
        }
    }

    return ss.str();
}

void Polynomial_Array::show() const {
    std::cout<<toString()<<std::endl;
}

        //Calculate

int Polynomial_Array::deg() const {
    return (static_cast<int>(coefficientList.getLength())-1);
}

double Polynomial_Array::getValue(double x) const {
    double result=0;
    double power=1;

    for(int i=0;i<coefficientList.getLength();i++){
        double coefficient=coefficientList.get(i);
        if(coefficient!=0){
            result+=coefficient*power;
        }
        power*=x;
    }

    return result;
}

Polynomial_Array Polynomial_Array::differentiate() const {
    Polynomial_Array p;

    for(int i=1;i<coefficientList.getLength();i++){
        double coefficient=coefficientList.get(i);
        if(coefficient!=0){
            p.coefficientList.add(coefficient*i);
        }
        else{
            p.coefficientList.add(0);
        }
    }

    return p;
}

double Polynomial_Array::valDifferentiate(double x) const {
    return differentiate().getValue(x);
}

Polynomial_Array Polynomial_Array::integrate() const {
    Polynomial_Array p;

    p.coefficientList.add(0);
    for(int i=0;i<coefficientList.getLength()-1;i++){
        double coefficient=coefficientList.get(i);
        if(coefficient!=0){
            p.coefficientList.add(coefficient/(i+1));
        }
        else{
            p.coefficientList.add(0);
        }
    }

    return p;
}

double Polynomial_Array::valIntegrate(double x1, double x2) const {
    Polynomial_Array p=integrate();
    return (p.getValue(x2)-p.getValue(x1));
}

        //Operator

Polynomial_Array &Polynomial_Array::operator=(const Polynomial_Array &other) = default;

Polynomial_Array &Polynomial_Array::operator=(double num) {
    coefficientList.clear();
    coefficientList.add(num);
    return *this;
}

Polynomial_Array &Polynomial_Array::operator+=(const Polynomial_Array &other) {

    for(int i=0;i<other.coefficientList.getLength();i++){
        if(i==coefficientList.getLength()){
            coefficientList.add(other.coefficientList.get(i));
        }
        else{
            coefficientList.get(i)+=other.coefficientList.get(i);
        }
    }

    return *this;
}

Polynomial_Array &Polynomial_Array::operator+=(double num) {
    coefficientList.get(0)+=num;
    return *this;
}

Polynomial_Array &Polynomial_Array::operator-=(const Polynomial_Array &other) {

    for(int i=0;i<other.coefficientList.getLength();i++){
        if(i==coefficientList.getLength()){
            coefficientList.add(-other.coefficientList.get(i));
        }
        else{
            coefficientList.get(i)-=other.coefficientList.get(i);
        }
    }

    return *this;
}

Polynomial_Array &Polynomial_Array::operator-=(double num) {
    coefficientList.get(0)-=num;
    return *this;
}

Polynomial_Array &Polynomial_Array::operator*=(const Polynomial_Array &other) {
    *this=(*this)*other;
    return *this;
}

Polynomial_Array &Polynomial_Array::operator*=(double num) {
    if(num==0){
        coefficientList.clear();
        coefficientList.add(0);
    }
    else{
        for(int i=0;i<coefficientList.getLength();i++){
            if(coefficientList.get(i)!=0) {
                coefficientList.get(i) *= num;
            }
        }
    }
    return *this;
}

Polynomial_Array &Polynomial_Array::operator/=(const Polynomial_Array &other) {
    if(other.deg()==0){
        std::cerr<<"Polynomial_Array : operator/= receive number!"<<std::endl;
        throw std::exception();
    }
    *this=(*this)/other;
    return *this;
}

Polynomial_Array &Polynomial_Array::operator/=(double num) {
    if(num==0){
        std::cerr<<"Polynomial_Array : operator/= receive 0!"<<std::endl;
        throw std::exception();
    }

    for(int i=0;i<coefficientList.getLength();i++){
        if(coefficientList.get(i)!=0) {
            coefficientList.get(i) /= num;
        }
    }

    return *this;
}

Polynomial_Array &Polynomial_Array::operator%=(const Polynomial_Array &other) {
    if(other.deg()==0){
        std::cerr<<"Polynomial_Array : operator%= receive number!"<<std::endl;
        throw std::exception();
    }

    while(deg()!=0&&deg()>=other.deg()){
        for(unsigned long long i=0;i<other.getCoefficientList().getLength();++i){
            coefficientList.get(coefficientList.getLength()-other.getCoefficientList().getLength()+i)-=
                    (getFirst()/other.getFirst()*other.getCoefficientList().get(i));
        }

        format();
    }

    return *this;
}

Polynomial_Array Polynomial_Array::operator+(const Polynomial_Array &other) const {
    Polynomial_Array result=*this;
    const BasicArrayList<double>& otherList=other.getCoefficientList();

    for(int i=0;i<otherList.getLength();i++){
        if(i==result.coefficientList.getLength()){
            result.coefficientList.add(otherList.get(i));
        }
        else{
            result.coefficientList.get(i)+=otherList.get(i);
        }
    }

    return result;
}

Polynomial_Array Polynomial_Array::operator+(double num) const {
    Polynomial_Array result=*this;
    result.coefficientList.get(0)+=num;
    return result;
}

Polynomial_Array Polynomial_Array::operator-(const Polynomial_Array &other) const {
    Polynomial_Array result=*this;
    const BasicArrayList<double>& otherList=other.getCoefficientList();

    for(int i=0;i<otherList.getLength();i++){
        if(i==result.coefficientList.getLength()){
            result.coefficientList.add(-otherList.get(i));
        }
        else{
            result.coefficientList.get(i)-=otherList.get(i);
        }
    }

    return result;
}

Polynomial_Array Polynomial_Array::operator-(double num) const {
    Polynomial_Array result=*this;
    result.coefficientList.get(0)-=num;
    return result;
}

Polynomial_Array Polynomial_Array::operator*(const Polynomial_Array &other) const {
    Polynomial_Array result;
    result=0;

    if((*this!=0)&&(other!=0)){
        for(int i=0;i<=deg();++i){
            if(coefficientList.get(i)!=0){
                result+=(other.xPower(i)*coefficientList.get(i));
            }
        }
    }

    return result;
}

Polynomial_Array Polynomial_Array::operator*(double num) const {
    Polynomial_Array result=*this;
    if(num==0){
        result.coefficientList.clear();
        result.coefficientList.add(0);
    }
    else{
        for(int i=0;i<result.coefficientList.getLength();i++){
            if(result.coefficientList.get(i)!=0) {
                result.coefficientList.get(i) *= num;
            }
        }
    }
    return result;
}

Polynomial_Array Polynomial_Array::operator/(const Polynomial_Array &other) const {
    Polynomial_Array result;
    Polynomial_Array copy=*this;

    result.coefficientList.clear();

    if(other.deg()==0){
        std::cerr<<"Polynomial_Array : operator/ receive number!"<<std::endl;
        throw std::exception();
    }

    while(copy.deg()!=0&&copy.deg()>=other.deg()){
        double coefficient=copy.getFirst()/other.getFirst();
        for(unsigned long long i=0;i<other.getCoefficientList().getLength();++i){
            copy.coefficientList.get(copy.coefficientList.getLength()-other.getCoefficientList().getLength()+i)-=
                    (coefficient*other.getCoefficientList().get(i));
        }
        result.coefficientList.insert(0,coefficient);

        copy.format();
    }

    return result;
}

Polynomial_Array Polynomial_Array::operator/(double num) const {
    Polynomial_Array result=*this;
    if(num==0){
        std::cerr<<"Polynomial_Array : operator/ receive 0!"<<std::endl;
        throw std::exception();
    }

    for(int i=0;i<result.coefficientList.getLength();i++){
        if(result.coefficientList.get(i)!=0) {
            result.coefficientList.get(i) /= num;
        }
    }

    return result;
}

Polynomial_Array Polynomial_Array::operator%(const Polynomial_Array &other) const {
    Polynomial_Array result=*this;
    if(other.deg()==0){
        std::cerr<<"Polynomial_Array : operator% receive number!"<<std::endl;
        throw std::exception();
    }

    while(result.deg()!=0&&result.deg()>=other.deg()){
        for(unsigned long long i=0;i<other.getCoefficientList().getLength();++i){
            result.coefficientList.get(result.coefficientList.getLength()-other.getCoefficientList().getLength()+i)-=
                    (result.getFirst()/other.getFirst()*other.getCoefficientList().get(i));
        }

        result.format();
    }

    return result;
}

bool Polynomial_Array::operator==(const Polynomial_Array &other) const {
    if(coefficientList.getLength()!=other.getCoefficientList().getLength()){
        return false;
    }

    for(int i=0;i<coefficientList.getLength();++i){
        if(coefficientList.get(i)!=other.getCoefficientList().get(i)){
            return false;
        }
    }

    return true;
}

bool Polynomial_Array::operator==(double num) const {
    return (coefficientList.getLength()==1&&coefficientList.get(0)==num);
}

bool Polynomial_Array::operator!=(const Polynomial_Array &other) const {
    return !(*this==other);
}

bool Polynomial_Array::operator!=(double num) const {
    return !(*this==num);
}

//private
    //Functions

void Polynomial_Array::format() {
    while(coefficientList.getLength()!=1&&
    coefficientList.get(coefficientList.getLength()-1)==0){
        coefficientList.erase(coefficientList.getLength()-1);
    }
}

const BasicArrayList<double> &Polynomial_Array::getCoefficientList() const{
    return coefficientList;
}

double Polynomial_Array::getFirst() const {
    return coefficientList.get(coefficientList.getLength()-1);
}

Polynomial_Array Polynomial_Array::xPower(unsigned long long int n) const {
    Polynomial_Array result=*this;
    result.coefficientList.insert(0,0,n);
    return result;
}
