#include <iostream>

/*
 * 错误示范：填充时改变了array指向的内存，导致delete时产生未定义行为
 */

using namespace std;
int main(){
    cout << " enter the size of the array :" ;
    int size;
    cin >> size ;

    // 填充
    int *array = new int[size]; 
    for( int i = 0; i < size ; i++){
        *array = i;
        array++;
    }

    // 输出
    for( int i = 0; i < size; i++){
        cout << "array[" << i << "]: " << array[i] << endl;
    }
    delete[] array;

}