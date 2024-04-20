//
// Created by 86133 on 2024/4/17.
//

#include <iostream>
#include "testBinaryTree.h"


void testBinaryTree::doTest() {

}

void testBinaryTree::experiment() {
    std::cout<<"###Experient###"<<std::endl<<std::endl;
    std::string s="ABDF##G##E#H##C";

    BinaryTree<char> tree=BinaryTreeTools::initCharBinaryTree(s);
    BinaryTreeTools::show(tree);
    std::cout<<"Node Amount:"<<tree.getNodeAmount()<<std::endl;
    std::cout<<"Leave Amount:"<<tree.getLeaveAmount()<<std::endl;
    std::cout<<"Height:"<<tree.getHeight()<<std::endl;

    std::cout<<std::endl;
}
