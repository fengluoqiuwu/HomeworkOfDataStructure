//
// Created by 86133 on 2024/4/16.
//

#include <iostream>
#include "testNode.h"
#include "../Polynomial_Node.h"

void testNode::doTest() {
    testPrivateFunctions();
    testConstructorAndDestructor();
    testStringAndPrint();
    testCalculate();
    testOperator();
}

void testNode::experiment() {
    std::cout<<"###Experient###"<<std::endl<<std::endl;
    std::cout<<"懒得写了，自己看上面的程序！！！"<<std::endl;
}

void testNode::testPrivateFunctions() {
//        std::cout<<"###Test Private Functions###"<<std::endl<<std::endl;
//
//        std::cout<<"Test format()"<<std::endl;
//        Node arr1[]={Node(0,0),Node(0,1),Node(0,2)};
//        Polynomial_Node p1(arr1, 3);
//        p1.format();
//        p1.show();
//        std::cout<<std::endl;
//
//        std::cout<<"Test getCoefficientList"<<std::endl;
//        Polynomial_Node p2(arr1, 3);
//        p2.getCoefficientList().show();
//        std::cout<<std::endl;
//
//        std::cout<<"Test getFirst"<<std::endl;
//        Node arr2[]={Node(1,0),Node(1.2,3),Node(23,4),Node(3.4,5)};
//        Polynomial_Node p3(arr2, 4);
//        std::cout<<"getFirst():"<<p3.getFirst().coefficient<<std::endl;
//        std::cout<<std::endl;
//
//        std::cout<<"Test getLast"<<std::endl;
//        std::cout<<"getLast():"<<p3.getLast().coefficient<<std::endl;
//        std::cout<<std::endl;
//
//        std::cout<<"Test xPower"<<std::endl;
//        Polynomial_Node p4(arr2, 4);
//        p4.xPower(3).show();
//        std::cout<<std::endl;
}

void testNode::testConstructorAndDestructor() {
    std::cout<<"###Test Constructor And Destructor###"<<std::endl<<std::endl;

    Polynomial_Node p1;
    p1.show();
    std::cout<<std::endl;

    Node arr[]={Node(1,0),Node(2,1),Node(3,2),Node(4,3),Node(5,4)};
    BasicArrayList<Node> arrayList(arr,5);

    Polynomial_Node p2(arrayList);
    p2.show();
    std::cout<<std::endl;

    Polynomial_Node p3(arr, 5);
    p3.show();
    std::cout<<std::endl;
}

void testNode::testStringAndPrint() {
    std::cout<<"###Test String And Print###"<<std::endl<<std::endl;

    Node arr[]={Node(1,0),Node(-2,1),Node(-4,3),Node(1,4)};

    std::cout<<"Test toString()"<<std::endl;
    Polynomial_Node p1(arr, 5);
    std::cout<<"toString() : "<<p1.toString()<<std::endl;
    std::cout<<std::endl;

    std::cout<<"Test Show()"<<std::endl;
    Polynomial_Node p2(arr, 5);
    p2.show();
    std::cout<<std::endl;
}

void testNode::testCalculate() {
    std::cout<<"###Test Calculate###"<<std::endl<<std::endl;

    Node arr[]={Node(1,0),Node(2,1),Node(3,2),Node(4,3),Node(5,4)};

    std::cout<<"Test deg()"<<std::endl;
    Polynomial_Node p1(arr, 5);
    std::cout<<"deg() : "<<p1.deg()<<std::endl;
    p1.show();
    std::cout<<std::endl;

    std::cout<<"Test getValue()"<<std::endl;
    Polynomial_Node p2(arr, 5);
    std::cout<<"getValue() : "<<p2.getValue(-1)<<std::endl;
    std::cout<<std::endl;

    std::cout<<"Test differentiate()"<<std::endl;
    Polynomial_Node p3(arr, 5);
    p3.differentiate().show();
    std::cout<<std::endl;

    std::cout<<"Test valDifferentiate()"<<std::endl;
    Polynomial_Node p4(arr, 5);
    std::cout<<"valDifferentiate() : "<<p4.valDifferentiate(1)<<std::endl;
    std::cout<<std::endl;

    std::cout<<"Test integrate()"<<std::endl;
    Polynomial_Node p5(arr, 5);
    p5.integrate().show();
    std::cout<<std::endl;

    std::cout<<"Test valIntegrate()"<<std::endl;
    Polynomial_Node p6(arr, 5);
    std::cout<<"valIntegrate() : "<<p6.valIntegrate(0,1)<<std::endl;
    std::cout<<std::endl;
}

void testNode::testOperator() {
    std::cout<<"###Test Operator###"<<std::endl<<std::endl;

    Node arr1[]={Node(1,0),Node(2,1),Node(3,2),Node(4,3),Node(5,4)};
    Node arr2[]={Node(1,0),Node(1,1),Node(1,2)};

    Polynomial_Node p1(arr1, 5);
    Polynomial_Node p2(arr2, 3);

    std::cout<<"Test ="<<std::endl;
    Polynomial_Node p3;
    p3=p1;p3.show();
    p3=1;p3.show();
    std::cout<<std::endl;

    std::cout<<"Test +="<<std::endl;
    Polynomial_Node p4;
    p4=p1;
    p4+=p2;
    p4.show();
    p4+=1;
    p4.show();
    std::cout<<std::endl;

    std::cout<<"Test -="<<std::endl;
    Polynomial_Node p5;
    p5=p1;
    p5-=p2;
    p5.show();
    p5-=1;
    p5.show();
    std::cout<<std::endl;

    std::cout<<"Test *="<<std::endl;
    Polynomial_Node p6;
    p6=p1;
    p6*=p2;
    p6.show();
    p6*=2;
    p6.show();
    std::cout<<std::endl;

    std::cout<<"Test /="<<std::endl;
    Polynomial_Node p7;
    p7=p1;
    p7/=p2;
    p7.show();
    p7/=2;
    p7.show();
    std::cout<<std::endl;

    std::cout<<"Test %="<<std::endl;
    Polynomial_Node p8;
    p8=p1;
    p8%=p2;
    p8.show();
    std::cout<<std::endl;

    std::cout<<"Test +"<<std::endl;
    (p1+p2).show();
    (p1+1).show();
    std::cout<<std::endl;

    std::cout<<"Test -"<<std::endl;
    (p1-p2).show();
    (p1-1).show();
    std::cout<<std::endl;

    std::cout<<"Test *"<<std::endl;
    (p1*p2).show();
    (p1*2).show();
    std::cout<<std::endl;

    std::cout<<"Test /"<<std::endl;
    (p1/p2).show();
    (p1/2).show();
    std::cout<<std::endl;

    std::cout<<"Test %"<<std::endl;
    (p1%p2).show();
    std::cout<<std::endl;

    std::cout<<"Test =="<<std::endl;
    std::cout<<"== : "<<(p1==p1)<<std::endl;
    std::cout<<"== : "<<(p1==1)<<std::endl;
    std::cout<<std::endl;

    std::cout<<"Test !="<<std::endl;
    std::cout<<"!= : "<<(p1!=p1)<<std::endl;
    std::cout<<"!= : "<<(p1!=1)<<std::endl;
    std::cout<<std::endl;
}
