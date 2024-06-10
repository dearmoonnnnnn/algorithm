#include <iostream>
#include <string>

int main()
{
    const char * str = "Hello World!";
    for( const char * p = str; *p; ++p ){
        std::cout << *p << " ";
    }

    return 0;
}