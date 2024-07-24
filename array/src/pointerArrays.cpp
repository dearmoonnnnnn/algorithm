#include <iostream>


int main(){


    // 存放指针的大小为10的数组
    int* a[10];


    //指向大小为10的数组的指针
    int array[10];
    int (*ptr)[10] = &array;
}