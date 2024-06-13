#include <iostream>
#include <vector>

using namespace std;

// 使用数组的方法
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {}; // 返回空 vector 以防找不到满足条件的两个数
    }
};

// 帮助函数，用于格式化输出 vector<int>
ostream& operator<<(ostream& os, const vector<int>& vec) {
    os << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        os << vec[i];
        if (i < vec.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

int main() {
    vector<int> arr = {1, 2, 3, 5};
    int target = 7;

    vector<int> result = Solution().twoSum(arr, target);

    cout << result << std::endl;

    return 0;
}
