//
// Created by 86133 on 2024/5/30.
//

#ifndef HOMEWORK_OF_DATA_STRUCTURE_SORT_H
#define HOMEWORK_OF_DATA_STRUCTURE_SORT_H


class sort {
public:
    static void bubble_sort(int * array,int length);
    static void bucket_sort(int * array,int length);
    static void counting_sort(int * array,int length);
    static void heap_sort(int * array,int length);
    static void insertion_sort(int * array,int length);
    static void merge_sort(int * array,int length);
    static void quick_sort(int * array,int length);
    static void radix_sort(int * array,int length);
    static void selection_sort(int * array,int length);
    static void shell_sort(int * array,int length);
    static void tim_sort(int * array,int length);
    static void tournament_sort(int * array,int length);
private:
    sort()= default;
};


#endif //HOMEWORK_OF_DATA_STRUCTURE_SORT_H
