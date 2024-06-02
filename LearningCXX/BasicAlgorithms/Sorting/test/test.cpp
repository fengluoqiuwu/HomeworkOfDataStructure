//
// Created by 86133 on 2024/5/30.
//

#include <iostream>
#include "../sort.h"

int test[]={5, 4, 3, 2, 1};
int length=5;

void testSelectionSort();

void show(){
    std::cout<<'{';
    for(int i=0;i<length;++i){
        std::cout<<test[i];
        if(i!=length-1){
            std::cout<<',';
        }
    }
    std::cout<<'}'<<std::endl;
}

int main(){
    show();
    sort::counting_sort(test,length);
    show();
    return 0;
}

