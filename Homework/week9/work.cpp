//
// Created by 86133 on 2024/5/9.
//

#include <iostream>
#include "work.h"

void work::doHomework6() {
    std::cout<<"Sorry!I'm not good at English,but I have to use English in my homework "
               "because in Windows system GBK code is supported but in "
               "CLion IDE there is some bug in GBK so I use the UTF-8 code."<<std::endl;
    homework6_1();
    homework6_2();
    homework6_3();
    homework6_4();
    homework6_8();
    homework6_9();
    homework6_11();
    homework6_13();
    homework6_14();
    homework6_16();
    homework6_22();
    homework6_23();
}

void work::homework6_1() {
    std::cout<<"###Homework 6.1###"<<std::endl;

    std::cout<<"#(root)-#-#"<<std::endl;
    std::cout<<"#-#(root)-#"<<std::endl;

    std::cout<<"Maybe it will be a bit abstract. "<<std::endl;

    std::cout<<std::endl;
}

void work::homework6_2() {
    std::cout<<"###Homework 6.2###"<<std::endl;

    std::cout<<"If x is root node of a binary tree,then is has one subtree."<<std::endl;
    std::cout<<"Else,it has no subtree."<<std::endl;

    std::cout<<std::endl;
}

void work::homework6_3() {
    std::cout<<"###Homework 6.3###"<<std::endl;

    std::cout<<"Right Skewed Binary Tree,where each node has only a right child, except for the leaf nodes."<<std::endl;
    std::cout<<"Left Skewed Binary Tree,where each node has only a left child, except for the leaf nodes. "<<std::endl;
    std::cout<<"Single-node Binary Tree,which consists of only one node."<<std::endl;

    std::cout<<std::endl;
}

void work::homework6_4() {
    std::cout<<"###Homework 6.4###"<<std::endl;

    std::cout<<"(1) How many nodes are there on each level?\n"
               "\n"
               "The first level has 1 node.\n"
               "The second level has k nodes.\n"
               "The third level has k^2 nodes.\n"
               "The fourth level has k^3 nodes.\n"
               "...\n"
               "The (H-1)th level has k^(H-2) nodes.\n"
               "The Hth level has k^(H-1) nodes\n"<<std::endl;
    std::cout<<"(2) What is the number of the parent node (if exists) of node i?\n"
               "\n"
               "The number of the parent node is [ (i - 2) / k ] + 1.\n"<<std::endl;
    std::cout<<"(3) What is the number of the j-th child node (if exists) of node i?\n"
               "\n"
               "The number of the j-th child node is (k * (i - 1)) + j + 1.\n"<<std::endl;
    std::cout<<"(4) What is the condition for node i to have a right sibling? What is the number of its right sibling?\n"
               "\n"
               "Node i has a right sibling if i is not the last node on its level.\n"
               "If i is the last node on its level, then its number is congruent to 1 modulo k.\n"
               "The number of its right sibling is i + 1."<<std::endl;

    std::cout<<std::endl;
}

void work::homework6_8() {
    std::cout<<"###Homework 6.8###"<<std::endl;

    std::cout<<"tree:AB#CEI#J##F#GK##H##D###"<<std::endl;
    std::cout<<"preorder traversal:ABCEIJFGKHD"<<std::endl;
    std::cout<<"postorder traversal:JIKHGFEDCBA"<<std::endl;

    std::cout<<std::endl;
}

void work::homework6_9() {
    std::cout<<"###Homework 6.9###"<<std::endl;

    std::cout<<"tree:ABC#D#EFH##G###IJ##K#LM#NO####"<<std::endl;

    std::cout<<std::endl;
}

void work::homework6_11() {
    std::cout<<"###Homework 6.11###"<<std::endl;

    std::cout<<"          A\n"
               "         / \\\n"
               "        /   \\\n"
               "       /     \\\n"
               "      B       I\n"
               "     / \\     / \\\n"
               "    C   G   H   J\n"
               "   /     \\   \\   \\\n"
               "  D       E   F   K\n"<<std::endl;

    std::cout<<std::endl;
}

void work::homework6_13() {
    std::cout<<"###Homework 6.13###"<<std::endl;

    std::cout<<"     A         H\n"
               "    / \\       / \\\n"
               "   / | \\     / | \\\n"
               "  B  D  G   I  K  L\n"
               " /  / \\    /\n"
               "C  E   F  J\n"<<std::endl;

    std::cout<<std::endl;
}

void work::homework6_14() {
    std::cout<<"###Homework 6.14###"<<std::endl;

    std::cout<<"Huffman Tree:\n"<<std::endl;
    std::cout<<"      #\n"
               "     / \\\n"
               "    /   \\\n"
               "   #     #\n"
               "  / \\   / \\\n"
               " b   g #   e\n"
               "      / \\\n"
               "     /   \\\n"
               "    #     #\n"
               "   / \\   / \\\n"
               "  #   d a   h\n"
               " / \\\n"
               "c   f\n"<<std::endl;

    std::cout<<"Huffman Code:\n"<<std::endl;
    std::cout<<"b:00\n"
               "g:01\n"
               "c:10000\n"
               "f:10001\n"
               "d:1001\n"
               "a:1010\n"
               "h:1011\n"
               "e:11\n"<<std::endl;

    std::cout<<"File length:225"<<std::endl;

    std::cout<<std::endl;
}

void work::homework6_16() {
    std::cout<<"###Homework 6.16###"<<std::endl;

    Node<int> node(1);
    BinaryTree<int> binaryTree;
    binaryTree.setRoot(&node);
    doSwap(*binaryTree.getRoot());

    std::cout<<std::endl;
}

void work::homework6_22() {
    std::cout<<"###Homework 6.22###"<<std::endl;

    Node<int> node(1);
    BinaryTree<int> binaryTree;
    binaryTree.setRoot(&node);
    getDepth(*binaryTree.getRoot());

    std::cout<<std::endl;
}

void work::homework6_23() {
    std::cout<<"###Homework 6.23###"<<std::endl;

    Node<int> node(1);
    BinaryTree<int> binaryTree;
    binaryTree.setRoot(&node);
    getK_thLevelNodeCount(*binaryTree.getRoot(),10);

    std::cout<<std::endl;
}

void work::doSwap(Node<int> &root) {
    if(root.hasLeft()){
        doSwap(root.getLeft());
    }
    else{
        if(root.hasRight()){
            doSwap(root.getRight());
        }
        else{
            return;
        }
    }

    root.swap();
}

unsigned long long work::getDepth(Node<int> &root) {
    unsigned long long LDepth=0,RDepth=0;

    if(root.hasLeft()){
        LDepth= getDepth(root.getLeft())+1;
    }

    if(root.hasRight()){
        RDepth= getDepth(root.getRight());
    }

    return (LDepth>RDepth?LDepth:RDepth);
}

unsigned long long work::getK_thLevelNodeCount(Node<int> &root,unsigned long long k) {
    if(k<=1){
        return 1;
    }

    unsigned long long count=0;

    if(root.hasLeft()){
        count+= getK_thLevelNodeCount(root.getLeft(),k-1);
    }

    if(root.hasRight()){
        count+= getK_thLevelNodeCount(root.getRight(),k-1);
    }

    return count;
}
