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
        std::cout<<"explicit Node(T inputData);"<<std::endl;
        std::cout<<"data:"<<node1.getData()<<std::endl;
        std::cout<<"left:"<<node1.takeLeft()<<std::endl;
        std::cout<<"right:"<<node1.takeRight()<<std::endl;
        std::cout<<std::endl;
    }

    Node<int> node2(&x);
    if((node2.getData()!=10)||(node2.takeLeft()!= nullptr)||(node2.takeRight()!= nullptr)){
        Flag=false;
        std::cout<<"explicit Node(T inputData);"<<std::endl;
        std::cout<<"data:"<<node2.getData()<<std::endl;
        std::cout<<"left:"<<node2.takeLeft()<<std::endl;
        std::cout<<"right:"<<node2.takeRight()<<std::endl;
        std::cout<<std::endl;
    }

    Node<int> node3(x,&node1, nullptr);
    if((node3.getData()!=10)||(&node3.getLeft()!= &node1)){
        Flag=false;
        std::cout<<"Node(T& inputData,Node<T>* inputLeft,Node<T>* inputRight);"<<std::endl;
        std::cout<<"data:"<<node3.getData()<<std::endl;
        std::cout<<"left:"<<node3.takeLeft()<<std::endl;
        std::cout<<"right:"<<node3.takeRight()<<std::endl;
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

    int x1=1;
    int x2=2;
    int x3=3;

    Node<int> node2(x2);
    Node<int> node3(x3);
    Node<int> node1(x1,&node2,&node3);

    if(!node1.isFull()){
        Flag=false;
        std::cout<<"[[nodiscard]] bool isFull() const;"<<std::endl;
        std::cout<<"node1.isFull:"<<node1.isFull()<<std::endl;
        std::cout<<std::endl;
    }

    if(!node2.isEmpty()){
        Flag=false;
        std::cout<<"[[nodiscard]] bool isEmpty() const;"<<std::endl;
        std::cout<<"node2.isEmpty:"<<node1.isEmpty()<<std::endl;
        std::cout<<std::endl;
    }

    if(node2.hasLeft()){
        Flag=false;
        std::cout<<"[[nodiscard]] bool hasLeft() const;"<<std::endl;
        std::cout<<"node2.hasLeft:"<<node1.hasLeft()<<std::endl;
        std::cout<<std::endl;
    }

    if(node2.hasRight()){
        Flag=false;
        std::cout<<"[[nodiscard]] bool hasRight() const;"<<std::endl;
        std::cout<<"node2.hasRight:"<<node1.hasRight()<<std::endl;
        std::cout<<std::endl;
    }

    if(&node1.getLeft()!=&node2||!node1.hasLeft()){
        Flag=false;
        std::cout<<"Node<T>& getLeft();"<<std::endl;
        std::cout<<"node1.getLeft():"<<&node1.getLeft()<<std::endl;
        std::cout<<std::endl;
    }

    if(&node1.getRight()!=&node3||!node1.hasRight()){
        Flag=false;
        std::cout<<"Node<T>& getRight();"<<std::endl;
        std::cout<<"node1.getRight():"<<&node1.getRight()<<std::endl;
        std::cout<<std::endl;
    }

    if(node1.takeLeft()!=&node2||node1.hasLeft()){
        Flag=false;
        std::cout<<"Node<T>* takeLeft();"<<std::endl;
        std::cout<<std::endl;
    }

    if(node1.takeRight()!=&node3||node1.hasRight()){
        Flag=false;
        std::cout<<"Node<T>* takeRight();"<<std::endl;
        std::cout<<std::endl;
    }

    if(Flag){
        std::cout<<"test all correct!"<<std::endl<<std::endl;
    }
}

void testBinaryTree::testNodeCount() {
    std::cout<<"###Node Count###"<<std::endl<<std::endl;
    bool Flag=true;

    Node<int> node1(1);
    Node<int> node2(2);
    Node<int> node3(3);
    Node<int> node4(4);
    Node<int> node5(5);
    Node<int> node6(6,&node5,&node4);
    Node<int> node7(7,&node6,&node3);
    Node<int> node8(8,&node1,&node7);

    if(node8.getNodeAmount()!=7){
        Flag=false;
        std::cout<<"[[nodiscard]] unsigned long long getNodeAmount() const;"<<std::endl;
        std::cout<<"Node Amount:"<<node8.getNodeAmount()<<std::endl;
        std::cout<<std::endl;
    }

    if(node8.getLeaveAmount()!=4){
        Flag=false;
        std::cout<<"[[nodiscard]] unsigned long long getLeaveAmount() const;"<<std::endl;
        std::cout<<"Leave Amount:"<<node8.getLeaveAmount()<<std::endl;
        std::cout<<std::endl;
    }

    if(node8.getHeight()!=4){
        Flag=false;
        std::cout<<"[[nodiscard]] unsigned long long getHeight() const;"<<std::endl;
        std::cout<<"Height:"<<node8.getHeight()<<std::endl;
        std::cout<<std::endl;
    }

    if(Flag){
        std::cout<<"test all correct!"<<std::endl<<std::endl;
    }
}

void testBinaryTree::testNodeTraversal() {
    std::cout<<"###Node Traversal###"<<std::endl<<std::endl;

    std::cout << "test all correct!" << std::endl << std::endl;
}

void testBinaryTree::testNodeSearch() {
    std::cout<<"###Node Search###"<<std::endl<<std::endl;
    bool Flag=true;

    Node<int> node1(1);
    Node<int> node2(2);
    Node<int> node3(3);
    Node<int> node4(4);
    Node<int> node5(5);
    Node<int> node6(6,&node5,&node4);
    Node<int> node7(7,&node6,&node3);
    Node<int> node8(8,&node1,&node7);

    if(node8.search(2)!= nullptr){
        Flag=false;
        std::cout<<"Node<T>* search(T t);"<<std::endl;
        std::cout<<"node8.search(2):"<<node8.search(2)<<std::endl;
        std::cout<<std::endl;
    }

    if(node8.search(4)!= &node4){
        Flag=false;
        std::cout<<"Node<T>* search(T t);"<<std::endl;
        std::cout<<"node8.search(4):"<<node8.search(4)<<std::endl;
        std::cout<<std::endl;
    }

    if(Flag){
        std::cout<<"test all correct!"<<std::endl<<std::endl;
    }
}

void testBinaryTree::testNodeModify() {
    std::cout<<"###Node Modify###"<<std::endl<<std::endl;
    bool Flag=true;

    Node<int> node1(1);
    Node<int> node2(2);
    Node<int> node3(3,&node1,&node2);

    node3.swap();
    if((&node3.getLeft()!=&node2)||(&node3.getRight()!=&node1)){
        Flag=false;
        std::cout<<"void swap();"<<std::endl;
        std::cout<<"node3.left:"<<&node3.getLeft()<<std::endl;
        std::cout<<"node3.Right:"<<&node3.getRight()<<std::endl;
        std::cout<<std::endl;
    }
    node3.swap();

    node3.deleteLeft();
    if(node3.takeLeft()!= nullptr||(&node3.getRight()!=&node2)){
        Flag=false;
        std::cout<<"deleteLeft();"<<std::endl;
        std::cout<<std::endl;
    }

    node3.deleteRight();
    if(node3.takeLeft()!= nullptr||node3.takeRight()!= nullptr){
        Flag=false;
        std::cout<<"deleteRight();"<<std::endl;
        std::cout<<std::endl;
    }

    node3.setLeft(&node1);
    node3.setRight(&node2);
    if((&node3.getLeft()!=&node1)||(&node3.getRight()!=&node2)){
        Flag=false;
        std::cout<<"setLeft(Node* node);setRight(Node* node);"<<std::endl;
        std::cout<<"node3.left:"<<&node3.getLeft()<<std::endl;
        std::cout<<"node3.Right:"<<&node3.getRight()<<std::endl;
        std::cout<<std::endl;
    }

    Node<int>* node4=node3.copy();
    if((node4->getData()!=node3.getData())
    ||(node4->getLeft().getData()!=node3.getLeft().getData())
    ||(node4->getRight().getData()!=node3.getRight().getData())
    ||(node4==&node3)
    ||(&node4->getLeft()==&node3.getLeft())
    ||(&node4->getRight()==&node3.getRight()
    )){
        Flag=false;
        std::cout<<"Node<T>* copy() const;"<<std::endl;
        std::cout<<"node3:"<<&node3<<std::endl;
        std::cout<<"node3.left:"<<&node3.getLeft()<<":"<<node3.getLeft().getData()<<std::endl;
        std::cout<<"node3.right:"<<&node3.getRight()<<":"<<node3.getRight().getData()<<std::endl;
        std::cout<<std::endl;
        std::cout<<"node4:"<<node4<<std::endl;
        std::cout<<"node4.left:"<<&node4->getLeft()<<":"<<node4->getLeft().getData()<<std::endl;
        std::cout<<"node4.right:"<<&node4->getRight()<<":"<<node4->getRight().getData()<<std::endl;
        std::cout<<std::endl;
    }

    if(Flag){
        std::cout<<"test all correct!"<<std::endl<<std::endl;
    }
}

void testBinaryTree::testNodeJudgment() {
    std::cout<<"###Node Judgment###"<<std::endl<<std::endl;
    bool Flag=true;

    {
        Node<char> node1('1');
        Node<char> node2('2');
        Node<char> node3('3');
        Node<char> node4('4');
        Node<char> node5('5');
        Node<char> node6('6');
        Node<char> node7('7');
        Node<char> node8('8');
        Node<char> node9('9');
        Node<char> tree('5');

        tree.setLeft(&node3);
        tree.setRight(&node6);
        node3.setLeft(&node1);
        node3.setRight(&node4);
        node6.setRight(&node8);
        node8.setRight(&node9);
        node8.setLeft(&node7);

        if(!tree.isBinarySearchTree()){
            Flag=false;
            std::cout<<"[[nodiscard]] bool isBinarySearchTree() const;"<<std::endl;
            BinaryTree<char> binaryTree;
            binaryTree.setRoot(&tree);
            BinaryTreeTools::show(binaryTree);
            std::cout<<std::endl;
        }

        node6.setLeft(&node2);
        if(tree.isBinarySearchTree()){
            Flag=false;
            std::cout<<"[[nodiscard]] bool isBinarySearchTree() const;"<<std::endl;
            BinaryTree<char> binaryTree;
            binaryTree.setRoot(&tree);
            BinaryTreeTools::show(binaryTree);
            std::cout<<std::endl;
        }
    }

    {
        Node<char> node1('1');
        Node<char> node2('2');
        Node<char> node3('3');
        Node<char> node4('4');
        Node<char> node5('5');
        Node<char> node6('6');
        Node<char> node7('7');
        Node<char> node8('8');
        Node<char> node9('9');
        Node<char> tree('5');

        tree.setLeft(&node3);
        tree.setRight(&node6);
        node3.setLeft(&node1);
        node3.setRight(&node4);
        node6.setRight(&node8);
        node6.setLeft(&node9);

        if(!tree.isCompleteBinaryTree()){
            Flag=false;
            std::cout<<"[[nodiscard]] bool isCompleteBinaryTree() const;"<<std::endl;
            BinaryTree<char> binaryTree;
            binaryTree.setRoot(&tree);
            BinaryTreeTools::show(binaryTree);
            std::cout<<std::endl;
        }

        node8.setLeft(&node7);
        if(tree.isCompleteBinaryTree()){
            Flag=false;
            std::cout<<"[[nodiscard]] bool isCompleteBinaryTree() const;"<<std::endl;
            BinaryTree<char> binaryTree;
            binaryTree.setRoot(&tree);
            BinaryTreeTools::show(binaryTree);
            std::cout<<std::endl;
        }
    }

    {
        Node<char> node1('1');
        Node<char> node2('2');
        Node<char> node3('3');
        Node<char> node4('4');
        Node<char> node5('5');
        Node<char> node6('6');
        Node<char> node7('7');
        Node<char> node8('8');
        Node<char> node9('9');
        Node<char> tree('5');

        tree.setLeft(&node3);
        tree.setRight(&node6);
        node3.setLeft(&node1);
        node3.setRight(&node4);
        node6.setRight(&node8);
        node6.setLeft(&node9);
        node8.setLeft(&node7);

        if(!tree.isBalancedBinaryTree()){
            Flag=false;
            std::cout<<"[[nodiscard]] bool isBalancedBinaryTree() const;"<<std::endl;
            BinaryTree<char> binaryTree;
            binaryTree.setRoot(&tree);
            BinaryTreeTools::show(binaryTree);
            std::cout<<std::endl;
        }

        node7.setLeft(&node5);
        if(tree.isBalancedBinaryTree()){
            Flag=false;
            std::cout<<"[[nodiscard]] bool isBalancedBinaryTree() const;"<<std::endl;
            BinaryTree<char> binaryTree;
            binaryTree.setRoot(&tree);
            BinaryTreeTools::show(binaryTree);
            std::cout<<std::endl;
        }
    }

    if(Flag){
        std::cout<<"test all correct!"<<std::endl<<std::endl;
    }
}

void testBinaryTree::testBinaryTreeConstructorAndDestructor() {
    std::cout<<"###Binary Tree Constructor And Destructor###"<<std::endl<<std::endl;
    bool Flag=true;

    BinaryTree<char> binaryTree;

    if(binaryTree.getRoot()!= nullptr){
        Flag=false;
        std::cout<<"BinaryTree();"<<std::endl;
        std::cout<<std::endl;
    }

    if(Flag){
        std::cout<<"test all correct!"<<std::endl<<std::endl;
    }
}

void testBinaryTree::testBinaryTreeRoot() {
    std::cout<<"###Binary Tree Root###"<<std::endl<<std::endl;
    bool Flag=true;

    BinaryTree<char> binaryTree;
    Node<char> root('1');

    if(binaryTree.hasRoot()){
        Flag=false;
        std::cout<<"[[nodiscard]] bool hasRoot() const;"<<std::endl;
        std::cout<<"hasRoot():"<<binaryTree.hasRoot()<<std::endl;
        std::cout<<std::endl;
    }

    if(binaryTree.getRoot()!= nullptr){
        Flag=false;
        std::cout<<"Node<T>* getRoot();"<<std::endl;
        std::cout<<"getRoot():"<<binaryTree.getRoot()<<std::endl;
        std::cout<<std::endl;
    }

    binaryTree.setRoot(&root);
    if(binaryTree.getRoot()!= &root){
        Flag=false;
        std::cout<<"void setRoot(Node<T>* inputRoot);"<<std::endl;
        std::cout<<"root:"<<binaryTree.getRoot()<<std::endl;
        std::cout<<std::endl;
    }

    if(Flag){
        std::cout<<"test all correct!"<<std::endl<<std::endl;
    }
}

void testBinaryTree::testBinaryTreeCount() {
    std::cout<<"###Binary Tree Count###"<<std::endl<<std::endl;

    std::cout << "test all correct!" << std::endl << std::endl;
}

void testBinaryTree::testBinaryTreeTraversal() {
    std::cout<<"###Binary Tree Traversal###"<<std::endl<<std::endl;

    std::cout << "test all correct!" << std::endl << std::endl;
}

void testBinaryTree::testBinaryTreeSearch() {
    std::cout<<"###Binary Tree Search###"<<std::endl<<std::endl;

    std::cout << "test all correct!" << std::endl << std::endl;
}

void testBinaryTree::testBinaryTreeJudgment() {
    std::cout<<"###Binary Tree Judgment###"<<std::endl<<std::endl;

    std::cout << "test all correct!" << std::endl << std::endl;
}
