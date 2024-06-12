#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> orderedMap;
    orderedMap[1] = "one";
    orderedMap[2] = "two";
    // orderedMap[3] = "three";
    orderedMap[4] = "four";
    orderedMap[5] = "five";

    int lower = 2;
    int upper = 4;

    // 使用 lower_bound 和 upper_bound 进行范围查询
    auto itLower = orderedMap.lower_bound(lower); // 第一个不小于 2 的元素
    auto itUpper = orderedMap.upper_bound(upper); // 第一个大于 4 的元素

    std::cout << "Range [" << lower << ", " << upper << "):" << std::endl;
    for (auto it = itLower; it != itUpper; ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    return 0;
}
