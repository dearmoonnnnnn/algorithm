#include <iostream>

/*
 * 数组大小为3*4
 * array[0] 和 &array[0][0] 表示同一个地址
 */
int main(){
    int array[3][4];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            array[i][j] = i*10 + j;
        }
    }

    for(int i = 0; i < 3 ; i++){
        std::cout << "array[" << i << "] : " << array[i] << std::endl;
        std::cout << "&array[" << i << "][0] : " << &array[i][0] << std::endl;
        std::cout << "array[" << i << "][0] : " << array[i][0] << std::endl;
        std::cout << "*array[" << i << "][0] : "<< *array[i] << std::endl;
    }
   
}