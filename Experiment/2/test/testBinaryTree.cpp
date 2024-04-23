//
// Created by 86133 on 2024/4/17.
//

#include <iostream>
#include <vector>
#include "testBinaryTree.h"


void testBinaryTree::doTest() {
    testNodeConstructorAndDestructor();
    testNodeData();
    testNodeChildren();
    testNodeCount();
    testNodeTraversal();
    testNodeSearch();
    testNodeModify();
    testNodeJudgment();
    testBinaryTreeConstructorAndDestructor();
    testBinaryTreeRoot();
    testBinaryTreeCount();
    testBinaryTreeTraversal();
    testBinaryTreeSearch();
    testBinaryTreeJudgment();
    testBinaryTreeToolsInit();
    testBinaryTreeToolsGetString();
    testBinaryTreeToolsShow();
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

void testBinaryTree::testNodeConstructorAndDestructor() {
    std::cout<<"###Node Constructor And Destructor###"<<std::endl<<std::endl;
    bool Flag=true;

    int x=10;
    Node<int> node1(x);
    if((node1.getData()!=10)||(node1.takeLeft()!= nullptr)||(node1.takeRight()!= nullptr)){
        Flag=false;
        std::cout<<"explicit Node(T& inputData);"<<std::endl;
        std::cout<<"data:"<<node1.getData()<<std::endl;
        std::cout<<"left:"<<node1.takeLeft()<<std::endl;
        std::cout<<"right:"<<node1.takeRight()<<std::endl;
        std::cout<<std::endl;
    }

    Node<int> node2(x,&node1, nullptr);
    if((node1.getData()!=10)&&(node1.takeLeft()!= &node1)&&(node1.takeRight()!= nullptr)){
        Flag=false;
        std::cout<<"Node(T& inputData,Node<T>* inputLeft,Node<T>* inputRight);"<<std::endl;
        std::cout<<"data:"<<node1.getData()<<std::endl;
        std::cout<<"left:"<<node1.takeLeft()<<std::endl;
        std::cout<<"right:"<<node1.takeRight()<<std::endl;
        std::cout<<std::endl;
    }

    if(Flag){
        std::cout<<"test all correct!"<<std::endl<<std::endl;
    }
}

void testBinaryTree::testNodeData() {
    std::cout<<"###Node Data###"<<std::endl<<std::endl;
    bool Flag=true;

    std::vector<int> vector1;
    vector1.push_back(1);
    Node<std::vector<int>> node1(vector1);
    node1.getData().push_back(2);
    if(node1.getData()[1]!=2){
        Flag=false;
        std::cout<<"T& getData();"<<std::endl;
        std::cout<<"data:"<<node1.getData()[1]<<std::endl;
        std::cout<<std::endl;
    }

    if(Flag){
        std::cout<<"test all correct!"<<std::endl<<std::endl;
    }
}

void testBinaryTree::testNodeChildren() {
    std::cout<<"###Node Children###"<<std::endl<<std::endl;
    bool Flag=true;

    if(Flag){
        std::cout<<"test all correct!"<<std::endl<<std::endl;
    }
}//TODO

void testBinaryTree::testNodeCount() {
    std::cout<<"###Node Count###"<<std::endl<<std::endl;
    bool Flag=true;

    if(Flag){
        std::cout<<"test all correct!"<<std::endl<<std::endl;
    }
}//TODO

void testBinaryTree::testNodeTraversal() {
    std::cout<<"###Node Traversal###"<<std::endl<<std::endl;
    bool Flag=true;

    if(Flag){
        std::cout<<"test all correct!"<<std::endl<<std::endl;
    }
}//TODO

void testBinaryTree::testNodeSearch() {
    std::cout<<"###Node Search###"<<std::endl<<std::endl;
    bool Flag=true;

    if(Flag){
        std::cout<<"test all correct!"<<std::endl<<std::endl;
    }
}//TODO

void testBinaryTree::testNodeModify() {
    std::cout<<"###Node Modify###"<<std::endl<<std::endl;
    bool Flag=true;

    if(Flag){
        std::cout<<"test all correct!"<<std::endl<<std::endl;
    }
}//TODO

void testBinaryTree::testNodeJudgment() {
    std::cout<<"###Node Judgment###"<<std::endl<<std::endl;
    bool Flag=true;

    if(Flag){
        std::cout<<"test all correct!"<<std::endl<<std::endl;
    }
}//TODO

void testBinaryTree::testBinaryTreeConstructorAndDestructor() {
    std::cout<<"###Binary Tree Constructor And Destructor###"<<std::endl<<std::endl;
    bool Flag=true;

    if(Flag){
        std::cout<<"test all correct!"<<std::endl<<std::endl;
    }
}//TODO

void testBinaryTree::testBinaryTreeRoot() {
    std::cout<<"###Binary Tree Root###"<<std::endl<<std::endl;
    bool Flag=true;

    if(Flag){
        std::cout<<"test all correct!"<<std::endl<<std::endl;
    }
}//TODO

void testBinaryTree::testBinaryTreeCount() {
    std::cout<<"###Binary Tree Count###"<<std::endl<<std::endl;
    bool Flag=true;

    if(Flag){
        std::cout<<"test all correct!"<<std::endl<<std::endl;
    }
}//TODO

void testBinaryTree::testBinaryTreeTraversal() {
    std::cout<<"###Binary Tree Traversal###"<<std::endl<<std::endl;
    bool Flag=true;

    if(Flag){
        std::cout<<"test all correct!"<<std::endl<<std::endl;
    }
}//TODO

void testBinaryTree::testBinaryTreeSearch() {
    std::cout<<"###Binary Tree Search###"<<std::endl<<std::endl;
    bool Flag=true;

    if(Flag){
        std::cout<<"test all correct!"<<std::endl<<std::endl;
    }
}//TODO

void testBinaryTree::testBinaryTreeJudgment() {
    std::cout<<"###Binary Tree Judgment###"<<std::endl<<std::endl;
    bool Flag=true;

    if(Flag){
        std::cout<<"test all correct!"<<std::endl<<std::endl;
    }
}//TODO

void testBinaryTree::testBinaryTreeToolsInit() {
    std::cout<<"###Binary Tree Tools Init###"<<std::endl<<std::endl;
    bool Flag=true;

    if(Flag){
        std::cout<<"test all correct!"<<std::endl<<std::endl;
    }
}//TODO

void testBinaryTree::testBinaryTreeToolsGetString() {
    std::cout<<"###Binary Tree Tools Get String###"<<std::endl<<std::endl;
    bool Flag=true;

    if(Flag){
        std::cout<<"test all correct!"<<std::endl<<std::endl;
    }
}//TODO

void testBinaryTree::testBinaryTreeToolsShow() {
    std::cout<<"###Binary Tree Tools Show###"<<std::endl<<std::endl;
    bool Flag=true;

    if(Flag){
        std::cout<<"test all correct!"<<std::endl<<std::endl;
    }
}//TODO
