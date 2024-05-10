//
// Created by 86133 on 2024/5/10.
//

#include <iostream>
#include "testLinkedListNode.h"

void testLinkedListNode::test() {
    std::cout<<"###Linked List Node###"<<std::endl<<std::endl;
    if(testAll()){
        std::cout<<"test all pass!"<<std::endl<<std::endl;
    }
}

bool testLinkedListNode::testAll() {
    bool Flag=true;

    LinkedListNode<int> node1;
    if(node1.next!= nullptr){
        Flag=false;
        std::cout<<"test LinkedListNode();"<<std::endl;
        std::cout<<"next:"<<node1.next<<std::endl<<std::endl;
    }

    LinkedListNode<int> node2(1);
    if(node2.next!= nullptr||node2.data!=1){
        Flag=false;
        std::cout<<"test explicit LinkedListNode(T data);"<<std::endl;
        std::cout<<"data:"<<node2.data<<std::endl<<std::endl;
        std::cout<<"next:"<<node2.next<<std::endl<<std::endl;
    }

    LinkedListNode<int> node3(2,node1);
    if(node3.next!= &node1||node3.data!=2){
        Flag=false;
        std::cout<<"test LinkedListNode(T data,LinkedListNode<T>& next);"<<std::endl;
        std::cout<<"data:"<<node3.data<<std::endl<<std::endl;
        std::cout<<"next:"<<node3.next<<std::endl<<std::endl;
    }

    return Flag;
}
