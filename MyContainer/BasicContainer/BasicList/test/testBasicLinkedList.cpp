//
// Created by 86133 on 2024/5/1.
//

#include <iostream>
#include "testBasicLinkedList.h"
#include "BasicLinkedList.h"

void testBasicLinkedList::test() {
    testConstructorAndDestructor();
    testIsEmpty();
    testGet();
    testGetIndex();
    testFind();
    testSubList();
    testClear();
    testAdd();
    testAddAll();
    testInsert();
    testErase();
    testRemove();
    testResize();
    testOperator();
    testSort();
}

void testBasicLinkedList::testConstructorAndDestructor() {
    std::cout<<"###Test Constructor And Destructor###"<<std::endl;

    BasicLinkedList<int> a;
    std::cout<<std::endl;

    BasicLinkedList<int> b(200);
    std::cout<<std::endl;

    int arr[]={1,2,3,4};
    BasicLinkedList<int> c(arr,4);
    std::cout<<std::endl;

    const BasicLinkedList<int>&d(c);
    std::cout<<std::endl;
}

void testBasicLinkedList::testIsEmpty() {
    std::cout<<"###Test Is Empty###"<<std::endl;
    BasicLinkedList<int>a;

    a.add(1);
    a.add(2);
    a.add(3);
    std::cout<<std::endl;

    std::cout<<"IsEmpty:"<<a.isEmpty()<<std::endl;
    a.clear();
    std::cout<<"IsEmpty:"<<a.isEmpty()<<std::endl;
}

void testBasicLinkedList::testGet() {
    std::cout<<"###Test Get###"<<std::endl;
    BasicLinkedList<int>a;

    a.add(1);
    a.add(2);
    a.add(3);
    std::cout<<std::endl;

    std::cout<<"Get:"<<a.get(1)<<std::endl;
    std::cout<<"Get:"<<a.get(2)<<std::endl;
//    std::cout<<"Get:"<<a.get(3)<<std::endl;

    std::cout<<std::endl;
}

void testBasicLinkedList::testGetIndex() {
    std::cout<<"###Test Get Index###"<<std::endl;
    BasicLinkedList<int>a;

    a.add(1);
    a.add(2);
    a.add(3);
    std::cout<<std::endl;

    std::cout<<"GetIndex:"<<a.getIndex(a.get(1))<<std::endl;

    std::cout<<std::endl;
}

void testBasicLinkedList::testFind() {
    std::cout<<"###Test Find###"<<std::endl;
    BasicLinkedList<int>a;

    a.add(1);
    a.add(2);
    a.add(3);
    std::cout<<std::endl;

    std::cout<<"GetIndex:"<<a.find(a.get(1))<<std::endl;

    std::cout<<std::endl;
}

void testBasicLinkedList::testSubList() {
    std::cout<<"###Test SubList###"<<std::endl;
    BasicLinkedList<int>a;

    a.add(1);
    a.add(2);
    a.add(3);
    std::cout<<std::endl;

    BasicLinkedList<int> a1=a.subList(0,3);
    std::cout<<std::endl;
}

void testBasicLinkedList::testClear() {
    std::cout<<"###Test Clear###"<<std::endl;
    BasicLinkedList<int>a;

    a.add(1);
    a.add(2);
    a.add(3);
    std::cout<<std::endl;

    a.clear();
    std::cout<<std::endl;
}

void testBasicLinkedList::testAdd() {
    std::cout<<"###Test Add###"<<std::endl;
    BasicLinkedList<int>a;

    a.add(1);
    a.add(2);
    a.add(3);
    std::cout<<std::endl;
}

void testBasicLinkedList::testAddAll() {
    std::cout<<"###Test AddAll###"<<std::endl;
    BasicLinkedList<int>a;

    a.add(1);
    a.add(2);
    a.add(3);
    std::cout<<std::endl;

    int arr[]={1,2,3};
    a.addAll(arr,3);

    std::cout<<std::endl;
}

void testBasicLinkedList::testInsert() {
    std::cout<<"###Test Insert###"<<std::endl;
    BasicLinkedList<int>a;

    a.add(1);
    a.add(2);
    a.add(3);
    std::cout<<std::endl;

    a.insert(0,1);
    std::cout<<std::endl;

    a.insert(0,1,10);
    std::cout<<std::endl;

    BasicLinkedList<int>a1=a;
    a.insert(0,a1);
    std::cout<<std::endl;

    int arr[]={1,2,3};
    a.insert(1,3,arr);
    std::cout<<std::endl;
}

void testBasicLinkedList::testErase() {
    std::cout<<"###Test Erase###"<<std::endl;
    BasicLinkedList<int>a;

    a.add(1);
    a.add(2);
    a.add(3);
    std::cout<<std::endl;

    a.erase(1);
    std::cout<<std::endl;
}

void testBasicLinkedList::testRemove() {
    std::cout<<"###Test Remove###"<<std::endl;
    BasicLinkedList<int>a;

    a.add(1);
    a.add(2);
    a.add(3);
    std::cout<<std::endl;

    a.remove(a.get(1));
    std::cout<<std::endl;
}

void testBasicLinkedList::testResize() {
    std::cout<<"###Test ReSize###"<<std::endl;
    BasicLinkedList<int>a;

    a.add(1);
    a.add(2);
    a.add(3);
    std::cout<<std::endl;

    a.reSize(1);
    std::cout<<std::endl;
}

void testBasicLinkedList::testOperator() {
    std::cout<<"###Test Operator###"<<std::endl;
    BasicLinkedList<int>a;

    a.add(1);
    a.add(2);
    a.add(3);
    std::cout<<std::endl;

    BasicLinkedList<int>a1=a;
    std::cout<<std::endl;
}

void testBasicLinkedList::testSort() {
    std::cout<<"###Test Sort###"<<std::endl;
    BasicLinkedList<int>a;

    a.add(3);
    a.add(2);
    a.add(2);
    a.add(1);
    std::cout<<std::endl;

    a.ascendingSort();
    std::cout<<std::endl;

    a.descendingSort();
    std::cout<<std::endl;
}