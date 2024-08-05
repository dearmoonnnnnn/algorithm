/* 将东八区时间转为 UTC 时间 
 * 输入：第一行为时间的个数，后面几行为时间
 *  如 ： 2
 *       20:00
 *       18:00   
 * 
 * 输出：
 *       12:00
 *       10:00
 */
 

#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int main(){
    int n;
    cin >> n;

    std::tm tm;

    for(int i = 0; i++; i < n){
        while(cin >> std::get_time(&tm, "%H-%M")){

            std::time_t time = mktime(&tm);
            time = time - 8*60*60;

            tm = gmtime(&time, "%H-M");

        }
    }
}
