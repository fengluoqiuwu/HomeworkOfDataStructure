//
// Created by 86133 on 2024/5/9.
//

#ifndef WEEK9_WORK_H
#define WEEK9_WORK_H

#include "BinaryTree.h"

class work {
public:
    static void doHomework6();
private:
    work()=default;

    static void homework6_1();
    static void homework6_2();
    static void homework6_3();
    static void homework6_4();
    static void homework6_8();
    static void homework6_9();
    static void homework6_11();
    static void homework6_13();
    static void homework6_14();
    static void homework6_16();
    static void homework6_22();
    static void homework6_23();

    static void doSwap(Node<int> &root);
    static unsigned long long getDepth(Node<int> &root);
    static unsigned long long getK_thLevelNodeCount(Node<int> &root,unsigned long long k);
};


#endif //WEEK9_WORK_H
