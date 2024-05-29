//
// Created by 86133 on 2024/4/14.
//

#ifndef DATA_STRUCTURE_POLYNOMIAL_ARRAY_H
#define DATA_STRUCTURE_POLYNOMIAL_ARRAY_H

#include "BasicArrayList.h"

class Polynomial_Array {
public:
    //Functions
        //Constructor & Destructor
    Polynomial_Array();
    explicit Polynomial_Array(BasicArrayList<double>& basicArrayList);
    Polynomial_Array(double * array, unsigned long long arraySize);
    ~Polynomial_Array();
        //String & Print
    [[nodiscard]] std::string toString() const;
    void show() const;
        //Calculate
    [[nodiscard]] int deg() const;
    [[nodiscard]] double getValue(double x) const;
    [[nodiscard]] Polynomial_Array differentiate() const;
    [[nodiscard]] double valDifferentiate(double x) const;
    [[nodiscard]] Polynomial_Array integrate() const;
    [[nodiscard]] double valIntegrate(double x1,double x2) const;
    //Operator
    Polynomial_Array& operator=(const Polynomial_Array& other) ;
    Polynomial_Array& operator=(double num) ;
    Polynomial_Array& operator+=(const Polynomial_Array& other) ;
    Polynomial_Array& operator+=(double num) ;
    Polynomial_Array& operator-=(const Polynomial_Array& other) ;
    Polynomial_Array& operator-=(double num) ;
    Polynomial_Array& operator*=(const Polynomial_Array& other) ;
    Polynomial_Array& operator*=(double num) ;
    Polynomial_Array& operator/=(const Polynomial_Array& other) ;
    Polynomial_Array& operator/=(double num) ;
    Polynomial_Array& operator%=(const Polynomial_Array& other) ;

    Polynomial_Array operator+(const Polynomial_Array& other) const;
    Polynomial_Array operator+(double num) const;
    Polynomial_Array operator-(const Polynomial_Array& other) const;
    Polynomial_Array operator-(double num) const;
    Polynomial_Array operator*(const Polynomial_Array& other) const;
    Polynomial_Array operator*(double num) const;
    Polynomial_Array operator/(const Polynomial_Array& other) const;
    Polynomial_Array operator/(double num) const;
    Polynomial_Array operator%(const Polynomial_Array& other) const;

    bool operator==(const Polynomial_Array& other) const ;
    bool operator==(double num) const ;
    bool operator!=(const Polynomial_Array& other) const ;
    bool operator!=(double num) const ;

private:
    //Data
    BasicArrayList<double> coefficientList;
    //Functions
    void format();
    [[nodiscard]] const BasicArrayList<double> &getCoefficientList() const;
    [[nodiscard]] double getFirst() const;//最高位
    [[nodiscard]] Polynomial_Array xPower(unsigned long long n) const;
};


#endif //DATA_STRUCTURE_POLYNOMIAL_ARRAY_H
