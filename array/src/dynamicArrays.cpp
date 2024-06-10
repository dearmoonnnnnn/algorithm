#include <iostream>

using namespace std;
int main(){
    cout << " enter the size of the array :" ;
    int size;
    cin >> size ;

    // 填充
    int *array = new int[size]; 
    for( int i = 0; i < size ; i++){
        array[i] = i;
    }

    // 输出
    for( int i = 0; i < size; i++){
        cout << "array[" << i << "]: " << array[i] << endl;
    }
    delete[] array;

}