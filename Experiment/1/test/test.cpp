//
// Created by 86133 on 2024/4/15.
//

#include "testArray.cpp"
#include "testNode.cpp"

bool Flag= false;

int main(){

    if(Flag){
        testArray::doTest();
        testArray::experiment();
    }
    else{
        testNode::doTest();
        testNode::experiment();
    }

    return 0;
}