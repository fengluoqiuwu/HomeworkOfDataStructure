//
// Created by 86133 on 2024/4/17.
//

#ifndef DATA_STRUCTURE_TEST_BINARY_TREE_H
#define DATA_STRUCTURE_TEST_BINARY_TREE_H


#include "../../../MyContainer/Tree/BasicBinaryTree/BinaryTree.h"
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
    static void testNodeTraversal();//test in elsewhere
    static void testNodeSearch();
    static void testNodeModify();
    static void testNodeJudgment();
    //Test Binary Tree
    static void testBinaryTreeConstructorAndDestructor();
    static void testBinaryTreeRoot();
    static void testBinaryTreeCount();//test in elsewhere
    static void testBinaryTreeTraversal();//test in elsewhere
    static void testBinaryTreeSearch();//test in elsewhere
    static void testBinaryTreeJudgment();//test in elsewhere
    //Test Binary Tree Tools
    static void testBinaryTreeToolsInit();//test in elsewhere
    static void testBinaryTreeToolsGetString();//test in elsewhere
    static void testBinaryTreeToolsShow();//test in elsewhere
};


#endif //DATA_STRUCTURE_TEST_BINARY_TREE_H
