#include <vector>
#include <string>
#include <unordered_map>

/*
 * 字母异位词分组
 */

using namespace std;
class Solution{
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs){

            int count = 0;
            vector<vector<string>> result;

            for(int i = 0; i < strs.size(); i++){
                vector<string> temp;
                unordered_map<char, int> map;

                temp.push_back(strs[i]);

                for(char c : strs[i]){
                    map[c]++;
                }  

                for(int j = i + 1; j < strs.size(); j++){

                    // 如果字符串i和字符串j长度不一样，直接跳过
                    if(strs[i] != strs[j]){
                        continue;
                    }

                    for(char c : strs[j]){
                        map[c]--;

                        if(map[c] < 0){
                            break;
                        }
                    }

                    temp.push_back(strs[j]);
                    strs.erase(strs.begin() + j);
                }

                strs.erase(strs.begin() + i);


            }

            return result;
            
        }
};