#include <iostream>

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution{
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        ListNode* result_head = nullptr;
        ListNode* result_index = result_head;

        int flag = 0;   // 进位标志
        int val;

        while(1){
            if(l1 == nullptr){
                result_index = l2;
            }

            if(l2 == nullptr){
                result_index = l1;
            }

            val = l1->val + l2->val + flag;

            if((l1->val + l2->val + flag) > 9){
              val = val -10 ;
              flag = 1;  
            }

            else{
                flag = 0;
            }

            ListNode* newNode = new ListNode(val);

            if(result_head == nullptr){
                result_head = newNode;
                result_index = newNode;
            }

            else{
                result_index->next = newNode;
                result_index = result_index->next;
            }

            l1 = l1->next;
            l2 = l2->next;
        }
    }


    ListNode* addTwoNumbers_dummy(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(0);  // 哑节点
        ListNode* tail = dummy->next;

        int carry = 0;
        int val1;
        int val2;
        int sum;

        while(l1 != nullptr || l2 != nullptr ){
            val1 = (l1 == nullptr) ? 0 : l1->val;
            val2 = (l2 == nullptr) ? 0 : l2->val;
            sum = val1 + val2 + carry;

            sum = sum % 10;
            carry = sum/10;

            ListNode* new_node = new ListNode(sum);

            tail = new_node;
            tail = tail->next;

            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;

        }

        return dummy->next;

    }

};



int main(){

}