#include <iostream>

int main(){

    int** array = new int*[3];
    for( int i = 0; i < 3; i++){
        array[i] = new int[4];
    }

    for( int i = 0; i < 4; i++){
        delete[] array[i];
    }

    delete[] array;
}