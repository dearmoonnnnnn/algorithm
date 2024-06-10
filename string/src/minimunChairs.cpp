#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumChairs(const string& s) {
        int result = 0;
        int temp = 0;
        for_each(s.begin(), s.end(), [&temp, &result](char c){
            if (c == 'E') {
                temp++;
                if (temp > result) {
                    result = temp;
                }
            } else if (c == 'L') {
                temp--;
            }
        });

        return result;
    }
};

int main() {
    string str = "EEELLEEE";

    cout << Solution().minimumChairs(str) << endl;

    return 0;
}
