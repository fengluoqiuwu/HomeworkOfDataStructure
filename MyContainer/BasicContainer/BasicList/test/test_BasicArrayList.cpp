//
// Created by 86133 on 2024/4/10.
//

#include "../BasicArrayList.cpp"
#include "../BasicLinkedList.cpp"


void testOperator();

void testShow();

void testToString();

void testResize();

void testRemove();

void testErase();

void testInsert();

void testAddAll();

void testAdd();

void testClear();

void testSubList();

void testFind();

void testGetIndex();

void testGet();

void testIsEmpty();

void testPrivateFunction();

void testGetterAndSetter();

void testConstructorAndDestructor();

void testSort();

int main() {
    testConstructorAndDestructor();
//    testGetterAndSetter();
//    testPrivateFunction();
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
    testToString();
    testShow();
    testOperator();
    testSort();
    return 0;
}

void testConstructorAndDestructor() {
    std::cout<<"###Test Constructor And Destructor###"<<std::endl;

    BasicArrayList<int> a;
    a.show();
    std::cout<<std::endl;

    BasicArrayList<int> b(200);
    b.show();
    std::cout<<std::endl;

    int arr[]={1,2,3,4};
    BasicArrayList<int> c(arr,4);
    c.show();
    std::cout<<std::endl;

    const BasicArrayList<int>&d(c);
    d.show();
    std::cout<<std::endl;
}

//void testGetterAndSetter() {
//    std::cout<<"###Test Getter And Setter###"<<std::endl;
//    BasicArrayList<int>a;
//
//    a.add(1);
//    a.add(2);
//    a.add(3);
//
//    a.show();
//    std::cout<<std::endl;
//
//    std::cout<<"bottom:"<<a.getBottom()<<std::endl;
//    std::cout<<"size:"<<a.getSize()<<std::endl;
//    std::cout<<"length:"<<a.getLength()<<std::endl;
//    std::cout<<std::endl;
//
////    a.setBottom(nullptr);
//    a.setLength(200);
//    a.setSize(114514);
//
//    std::cout<<"bottom:"<<a.getBottom()<<std::endl;
//    std::cout<<"size:"<<a.getSize()<<std::endl;
//    std::cout<<"length:"<<a.getLength()<<std::endl;
//    std::cout<<std::endl;
//}
//
//void testPrivateFunction() {
//    std::cout<<"###Test Private Function###"<<std::endl;
//    BasicArrayList<int>a;
//
//    a.add(1);
//    a.add(2);
//    a.add(3);
//
//    a.show();
//    std::cout<<std::endl;
//
//    std::cout<<"check data:"<<std::endl;
//    std::cout<<"isFull:"<<a.isFull()<<std::endl;
//    a.reSize(3);
//    std::cout<<"isFull:"<<a.isFull()<<std::endl;
//    std::cout<<std::endl;
//
//    a.show();
//    std::cout<<std::endl;
//
//    a.expand();
//    a.show();
//    std::cout<<std::endl;
//}

void testIsEmpty() {
    std::cout<<"###Test Is Empty###"<<std::endl;
    BasicArrayList<int>a;

    a.add(1);
    a.add(2);
    a.add(3);
    a.show();
    std::cout<<std::endl;

    std::cout<<"IsEmpty:"<<a.isEmpty()<<std::endl;
    a.clear();
    std::cout<<"IsEmpty:"<<a.isEmpty()<<std::endl;
}

void testGet() {
    std::cout<<"###Test Get###"<<std::endl;
    BasicArrayList<int>a;

    a.add(1);
    a.add(2);
    a.add(3);
    a.show();
    std::cout<<std::endl;

    std::cout<<"Get:"<<a.get(1)<<std::endl;
    std::cout<<"Get:"<<a.get(2)<<std::endl;
//    std::cout<<"Get:"<<a.get(3)<<std::endl;

    std::cout<<std::endl;
}

void testGetIndex() {
    std::cout<<"###Test Get Index###"<<std::endl;
    BasicArrayList<int>a;

    a.add(1);
    a.add(2);
    a.add(3);
    a.show();
    std::cout<<std::endl;

    std::cout<<"GetIndex:"<<a.getIndex(a.get(1))<<std::endl;

    std::cout<<std::endl;
}

void testFind() {
    std::cout<<"###Test Find###"<<std::endl;
    BasicArrayList<int>a;

    a.add(1);
    a.add(2);
    a.add(3);
    a.show();
    std::cout<<std::endl;

    std::cout<<"GetIndex:"<<a.find(a.get(1))<<std::endl;

    std::cout<<std::endl;
}

void testSubList() {
    std::cout<<"###Test SubList###"<<std::endl;
    BasicArrayList<int>a;

    a.add(1);
    a.add(2);
    a.add(3);
    a.show();
    std::cout<<std::endl;

    BasicArrayList<int> a1=a.subList(0,3);
    a1.show();
    std::cout<<std::endl;
}

void testClear() {
    std::cout<<"###Test Clear###"<<std::endl;
    BasicArrayList<int>a;

    a.add(1);
    a.add(2);
    a.add(3);
    a.show();
    std::cout<<std::endl;

    a.clear();
    a.show();
    std::cout<<std::endl;
}

void testAdd() {
    std::cout<<"###Test Add###"<<std::endl;
    BasicArrayList<int>a;

    a.add(1);
    a.add(2);
    a.add(3);
    a.show();
    std::cout<<std::endl;
}

void testAddAll() {
    std::cout<<"###Test AddAll###"<<std::endl;
    BasicArrayList<int>a;

    a.add(1);
    a.add(2);
    a.add(3);
    a.show();
    std::cout<<std::endl;

    int arr[]={1,2,3};
    a.addAll(arr,3);

    a.show();
    std::cout<<std::endl;
}

void testInsert() {
    std::cout<<"###Test Insert###"<<std::endl;
    BasicArrayList<int>a;

    a.add(1);
    a.add(2);
    a.add(3);
    a.show();
    std::cout<<std::endl;

    a.insert(0,1);
    a.show();
    std::cout<<std::endl;

    a.insert(0,1,10);
    a.show();
    std::cout<<std::endl;

    BasicArrayList<int>a1=a;
    a.insert(0,a1);
    a.show();
    std::cout<<std::endl;

    int arr[]={1,2,3};
    a.insert(1,3,arr);
    a.show();
    std::cout<<std::endl;
}

void testErase() {
    std::cout<<"###Test Erase###"<<std::endl;
    BasicArrayList<int>a;

    a.add(1);
    a.add(2);
    a.add(3);
    a.show();
    std::cout<<std::endl;

    a.erase(1);
    a.show();
    std::cout<<std::endl;
}

void testRemove() {
    std::cout<<"###Test Remove###"<<std::endl;
    BasicArrayList<int>a;

    a.add(1);
    a.add(2);
    a.add(3);
    a.show();
    std::cout<<std::endl;

    a.remove(a.get(1));
    a.show();
    std::cout<<std::endl;
}

void testResize() {
    std::cout<<"###Test ReSize###"<<std::endl;
    BasicArrayList<int>a;

    a.add(1);
    a.add(2);
    a.add(3);
    a.show();
    std::cout<<std::endl;

    a.reSize(1);
    a.show();
    std::cout<<std::endl;
}

void testToString() {
    std::cout<<"###Test ToString###"<<std::endl;
    BasicArrayList<int>a;

    a.add(1);
    a.add(2);
    a.add(3);
    std::cout<<a.toString()<<std::endl;
    std::cout<<std::endl;
}

void testShow() {
    std::cout<<"###Test Show###"<<std::endl;
    BasicArrayList<int>a;

    a.add(1);
    a.add(2);
    a.add(3);
    a.show();
    std::cout<<std::endl;
}

void testOperator(){
    std::cout<<"###Test Operator###"<<std::endl;
    BasicArrayList<int>a;

    a.add(1);
    a.add(2);
    a.add(3);
    a.show();
    std::cout<<std::endl;

    BasicArrayList<int>a1=a;
    a1.show();
    std::cout<<std::endl;
}

void testSort() {
    std::cout<<"###Test Sort###"<<std::endl;
    BasicArrayList<int>a;

    a.add(3);
    a.add(2);
    a.add(2);
    a.add(1);
    a.show();
    std::cout<<std::endl;

    a.sort();
    a.show();
    std::cout<<std::endl;
}