//
// Created by 86133 on 2024/5/30.
//

#include "sort.h"

void sort::bubble_sort(int *array, int length) {
    bool flag=true;
    while(flag){
        flag=false;
        for(int i=0;i<length-1;++i){
            if(*(array+i)>*(array+i+1)){
                flag=true;
                int helper=*(array+i);
                *(array+i)=*(array+i+1);
                *(array+i+1)=helper;
            }
        }
    }
}

void sort::bucket_sort(int *array, int length) {

}

void sort::counting_sort(int *array, int length) {
    int count[5]={0};
    for(int i=0;i<length;++i){
        count[*(array+i)-1]++;
    }

    int* pointer=array;
    for(int i=0;i<length;++i){
        for(int j=0;j<count[i];++j){
            *pointer=i+1;
            pointer++;
        }
    }
}

void sort::heap_sort(int *array, int length) {

}

void sort::insertion_sort(int *array, int length) {
    for(int i=1;i<length;++i){
        int key=*(array+i);
        int j=i-1;
        while(j>=0&&*(array+j)>key){
            *(array+j+1)=*(array+j);
            j--;
        }
        *(array+j+1)=key;
    }
}

void sort::merge_sort(int *array, int length) {

}

void sort::quick_sort(int *array, int length) {

}

void sort::radix_sort(int *array, int length) {

}

void sort::selection_sort(int *array, int length) {
    int index=0;

    for(int i=0;i<length;++i){
        int min=*(array+i);
        index=i;
        for(int j=i;j<length;j++){
            if(*(array+j)<min){
                min=*(array+j);
                index=j;
            }
        }

        if(index!=i){
            int helper=*(array+i);
            *(array+i)=*(array+index);
            *(array+index)=helper;
        }
    }
}

void sort::shell_sort(int *array, int length) {

}

void sort::tim_sort(int *array, int length) {

}

void sort::tournament_sort(int *array, int length) {

}
