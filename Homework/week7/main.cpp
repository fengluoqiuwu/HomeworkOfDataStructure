//
// Created by 86133 on 2024/4/16.
//

#include <iostream>

void homework5_1();
void homework5_2();
void homework5_3();
void homework5_4();
void homework5_5();

int main(){
    homework5_1();
    homework5_2();
    homework5_3();
    homework5_4();
    homework5_5();
    return 0;
}

void homework5_1(){
    std::cout<<"###HOMEWORK 5-1###"<<std::endl;
//    0,0,0,0
//    0,0,0,1
//    0,0,0,2
//    0,0,1,0
//    0,0,1,1
//    0,0,1,2
//    0,0,2,0
//    0,0,2,1
//    0,0,2,2
//    0,1,0,0
//    0,1,0,1
//    0,1,0,2
//    0,1,1,0
//    0,1,1,1
//    0,1,1,2
//    0,1,2,0
//    0,1,2,1
//    0,1,2,2
//    1,0,0,0
//    1,0,0,1
//    1,0,0,2
//    1,0,1,0
//    1,0,1,1
//    1,0,1,2
//    1,0,2,0
//    1,0,2,1
//    1,0,2,2
//    1,1,0,0
//    1,1,0,1
//    1,1,0,2
//    1,1,1,0
//    1,1,1,1
//    1,1,1,2
//    1,1,2,0
//    1,1,2,1
//    1,1,2,2
    for(int i1=0;i1<2;++i1){
        for(int i2=0;i2<2;++i2){
            for(int i3=0;i3<3;++i3){
                for(int i4=0;i4<3;++i4){
                    std::cout<<i1<<','<<i2<<','<<i3<<','<<i4<<std::endl;
                }
            }
        }
    }
    std::cout<<"What does it mean? I couldn't understand!"<<std::endl;
    std::cout<<std::endl;
}

void homework5_2(){
    std::cout<<"###HOMEWORK 5-2###"<<std::endl;
    std::cout<<"Question1:288 bytes"<<std::endl;//288字节
    std::cout<<"Question2:1282"<<std::endl;
    std::cout<<"Question3:1120"<<std::endl;
    std::cout<<"Question4:1300"<<std::endl;
    std::cout<<std::endl;
}

void homework5_3(){
    std::cout<<"###HOMEWORK 5-3###"<<std::endl;
    std::cout<<"f1(i)=(2n+2-i)*(i-1)/2-i"<<std::endl;
    std::cout<<"f2(j)=j"<<std::endl;
    std::cout<<"c=0"<<std::endl;
    std::cout<<std::endl;
}

void homework5_4(){
    std::cout<<"###HOMEWORK 5-4###"<<std::endl;
    std::cout<<" a[i][j]"<<std::endl;
    std::cout<<"=([(i-1)/2])*4+2*((i-1)%2)+((j-1)%2)"<<std::endl;
    std::cout<<std::endl;
}

void homework5_5(){
    std::cout<<"###HOMEWORK 5-5###"<<std::endl;
    std::cout<<"triplet form:"<<std::endl;
    std::cout<<"(0, 1, 1)\n"
               "(0, 4, 5)\n"
               "(1, 0, 2)\n"
               "(1, 1, 3)\n"
               "(1, 3, 6)\n"
               "(3, 1, 4)\n"
               "(3, 4, 7)\n";
    std::cout<<std::endl;
    std::cout<<"cross-linked list form:"<<std::endl;
    std::cout<<"  |    0       1       2       3       4\n"
               "-------------------------------------------\n"
               "0 |         (0,1,1)                 (0,4,5)\n"
               "1 | (1,0,2) (1,1,3)         (1,3,6)\n"
               "2 |\n"
               "3 |         (3,1,4)                 (3,4,7)\n";
    std::cout<<"Please imagine the right and down pointer!"<<std::endl;
    std::cout<<std::endl;
}