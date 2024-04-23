//
// Created by 86133 on 2024/4/17.
//

#ifndef DATA_STRUCTURE_TEST_BINARY_TREE_H
#define DATA_STRUCTURE_TEST_BINARY_TREE_H


#include "../BinaryTree.h"
#include "../BinaryTreeTools.h"

class testBinaryTree {
public:
    static void doTest();
    static void experiment();
private:
    //Test Node
    static void testNodeConstructorAndDestructor();
    static void testNodeData();
    static void testNodeChildren();
    static void testNodeCount();
    static void testNodeTraversal();
    static void testNodeSearch();
    static void testNodeModify();
    static void testNodeJudgment();
    //Test Binary Tree
    static void testBinaryTreeConstructorAndDestructor();
    static void testBinaryTreeRoot();
    static void testBinaryTreeCount();
    static void testBinaryTreeTraversal();
    static void testBinaryTreeSearch();
    static void testBinaryTreeJudgment();
    //Test Binary Tree Tools
    static void testBinaryTreeToolsInit();
    static void testBinaryTreeToolsGetString();
    static void testBinaryTreeToolsShow();
};


#endif //DATA_STRUCTURE_TEST_BINARY_TREE_H
