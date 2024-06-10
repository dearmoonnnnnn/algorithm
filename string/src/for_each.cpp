#include <iostream>
#include <algorithm>

void print(char x){
	std::cout << x << " ";
}

int main(){
    std::string str = "Hello, World";
    std::for_each(str.begin(), str.end(), print);
    
    std::cout << std::endl;
    return 0;
}