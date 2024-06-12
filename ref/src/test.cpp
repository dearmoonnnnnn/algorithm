#include <iostream>
#include <string>

class MyObject {
private:
    std::string data;
public:
    MyObject(const std::string& str) : data(str) {
        std::cout << "Constructor called. Data: " << data << std::endl;
    }
    // 移动构造函数
    MyObject(MyObject&& other) noexcept : data(other.data) {
        std::cout << "Move constructor called. Data: " << data << std::endl;
    }
    // 移动赋值运算符
    MyObject& operator=(MyObject&& other) noexcept {
        std::cout << "Move assignment operator called. Data: " << data << std::endl;
        return *this;
    }
};

int main() {
    std::string str = "Hello";
    MyObject obj1(str); // 调用构造函数
    MyObject obj2 = std::move(obj1); // 调用移动构造函数
    MyObject obj3("World"); // 调用构造函数
    obj2 = std::move(obj3); // 调用移动赋值运算符
    return 0;
}
