#include <iostream>
#include <string>
#include <algorithm>

int main(){
    std::string str = "Hello, World";
    std::for_each(str.begin(), str.end(), [](char x){
        std::cout << x << " ";
    });
    
    std::cout << std::endl;
    return 0;
}


