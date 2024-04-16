//
// Created by 86133 on 2024/4/15.
//

#include "testArray.h"
#include "testNode.h"

bool Flag= true;

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