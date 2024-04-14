//
// Created by 86133 on 2024/4/10.
//

#include "../BasicArrayList.cpp"
#include "../BasicLinkedList.cpp"


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

int main(int argc, char* argv[]) {
    testConstructorAndDestructor();
    testGetterAndSetter();
//    testPrivateFunction();
//    testIsEmpty();
//    testGet();
//    testGetIndex();
//    testFind();
//    testSubList();
//    testClear();
//    testAdd();
//    testAddAll();
//    testInsert();
//    testErase();
//    testRemove();
//    testResize();
//    testToString();
//    testShow();
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

    BasicArrayList<int>d(c);
    d.show();
    std::cout<<std::endl;
}

void testGetterAndSetter() {
    std::cout<<"###Test Getter And Setter###"<<std::endl;
    BasicArrayList<int>a;

    a.add(1);
    a.add(2);
    a.add(3);

    a.show();
    std::cout<<std::endl;

    std::cout<<"bottom:"<<a.getBottom()<<std::endl;
    std::cout<<"size:"<<a.getSize()<<std::endl;
    std::cout<<"length:"<<a.getLength()<<std::endl;
    std::cout<<std::endl;

//    a.setBottom(nullptr);
    a.setLength(200);
    a.setSize(114514);

    std::cout<<"bottom:"<<a.getBottom()<<std::endl;
    std::cout<<"size:"<<a.getSize()<<std::endl;
    std::cout<<"length:"<<a.getLength()<<std::endl;
    std::cout<<std::endl;
}

void testPrivateFunction() {

}

void testIsEmpty() {

}

void testGet() {

}

void testGetIndex() {

}

void testFind() {

}

void testSubList() {

}

void testClear() {

}

void testAdd() {

}

void testAddAll() {

}

void testInsert() {

}

void testErase() {

}

void testRemove() {

}

void testResize() {

}

void testToString() {

}

void testShow() {

}
