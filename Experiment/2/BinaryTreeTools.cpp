//
// Created by 86133 on 2024/4/16.
//

#include <sstream>
#include <iostream>
#include <stack>
#include "BinaryTreeTools.h"

BinaryTree<char> BinaryTreeTools::initCharBinaryTree(const std::string &preorderTraversalString) {
    BinaryTree<char> result;
    std::stack<Node<char>*> helperStack;
    bool isFirst=true;
    bool isOccupied=false;

    //保证加入字符时位置结点可用
    for(auto c:preorderTraversalString){
        if(c!='#'){
            if(isFirst){
                isFirst=false;

                auto* head=new Node<char>(c);
                helperStack.push(head);
                result.setRoot(head);
            }
            else{
                auto* node=new Node<char>(c);

                if(helperStack.top()->hasLeft() || isOccupied){
                    isOccupied= false;
                    helperStack.top()->setRight(node);
                }
                else{
                    helperStack.top()->setLeft(node);
                }

                helperStack.push(node);
            }
        }
        else{
            if(isFirst){
                isFirst=false;

                return result;
            }

            if(helperStack.top()->hasLeft()||isOccupied){
                isOccupied= false;

                bool isFull=true;
                while(isFull){
                    Node<char>* node1=helperStack.top();
                    helperStack.pop();
                    isFull=(node1==&helperStack.top()->getRight());
                    if(helperStack.empty()){
                        return result;
                    }
                }
            }
            else{
                isOccupied=true;
            }
        }
    }

    return result;
}

std::string BinaryTreeTools::getPreorderString(const BinaryTree<char> &tree) {
    std::list<char*> preorderList=tree.PreorderTraversal();
    std::stringstream ss;

    for(auto & it : preorderList){
        ss<<*it;
    }

    return ss.str();
}

std::string BinaryTreeTools::getInorderString(const BinaryTree<char> &tree) {
    std::list<char*> inorderList=tree.InorderTraversal();
    std::stringstream ss;

    for(auto & it : inorderList){
        ss<<*it;
    }

    return ss.str();
}

std::string BinaryTreeTools::getPostorderString(const BinaryTree<char> &tree) {
    std::list<char*> postorderTraversal=tree.PostorderTraversal();
    std::stringstream ss;

    for(auto & it : postorderTraversal){
        ss<<*it;
    }

    return ss.str();
}

std::string BinaryTreeTools::getLevelOrderString(const BinaryTree<char> &tree) {
    std::list<std::list<char*>> levelOrderList=tree.LevelOrderTraversal();
    std::stringstream ss;

    for(auto & it1 : levelOrderList){
        for(auto & it2 : it1){
            ss<<*it2;
        }
        ss<<'\n';
    }

    return ss.str();
}

void BinaryTreeTools::show(const BinaryTree<char> &tree) {
    std::cout<<"BinaryTreeShow:"<<std::endl;

    std::cout<<"PreorderTraversal:"<<getPreorderString(tree)<<std::endl;
    std::cout<<"InorderTraversal:"<<getInorderString(tree)<<std::endl;
    std::cout<<"PostorderTraversal:"<<getPostorderString(tree)<<std::endl;
    std::cout<<"LevelOrderTraversal:"<<getLevelOrderString(tree)<<std::endl;
}
