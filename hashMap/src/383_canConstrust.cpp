#include <iostream>
#include <unordered_map>

using namespace std;

/*
 * 383.赎金信
 */

class solution{
    public:
        bool canConstruct(string ransomNote, string magazine){
            unordered_map<char, int> hashMap;

            for(char c : magazine){
                hashMap[c]++;
            }

            for(char c : ransomNote){
                hashMap[c]--;

                if(hashMap[c] < 0){
                    return false;
                }
            }

            return true;
        }
};