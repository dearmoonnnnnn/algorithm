/* 给定一个数，判断从2进制到36进制，1最多是多少个*/
#include <iostream>

int main(){
    int num;
    std::cin >> num;

    int res = 0;
    int res_temp =  0;
    int num_backup;
    for(int i = 2; i < 37; i++){
        num_backup = num;
        res_temp = 0;
        while(num_backup !=0 ){
            if(num_backup % i == 1) res_temp++;

            num_backup = num_backup / i;
        }

        res = res > res_temp ? res : res_temp;
    }

    std::cout << num  << std::endl;
    return res;
}

