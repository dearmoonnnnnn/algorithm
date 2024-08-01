#include<iostream>
#include<unordered_map>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode* next): val(x), next(next){}
};

class Solution{

public:
    ListNode* reverseBetween(ListNode* head, int left, int right ){
        std::unordered_map<int, ListNode*> cachedNode;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* left_ptr = dummy;     // left_ptr 指向 left 左边一个位置
        ListNode* right_ptr = dummy;    // right_ptr 指向 right 右边一个位置

        for(int i = 0; i < left -1; i++){
            left_ptr = left_ptr->next;
        }

        for( int i = 0 ; i < right + 1; i++){
            right_ptr = right_ptr->next;
        }

        ListNode* cur = left_ptr; 
        for(int i = 0; i < right - left + 1; i++){
            cur = cur->next;
            cachedNode[i] = cur;
        }

        cur = left_ptr;
        for(int i = right - left; i >= 0 ; i--){
            cur->next = cachedNode[i];
            cur = cur->next;
        }
        cur->next = right_ptr;

        return dummy->next;
    }

};

// 头插法，遍历到的节点放在最前面
class Solution_2{
public:
    ListNode* reverseBetween(ListNode* head, int left, int right ){
        if(left == right || head == nullptr){
            return head;
        }

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* pre = dummy;
        ListNode* suc = dummy;

        for(int i = 0; i < left - 1; i++){
            pre = pre->next;
        }

        for(int i = 0; i < right + 1; i++){
            suc = suc->next;
        }

        ListNode* cur = pre->next->next;    // 从第二个待反转节点开始
        ListNode* tail_sub = pre->next;
        ListNode* head_sub = pre->next;
        ListNode* cur_suc = cur->next;      // 头插法，尾部与原链表断开，需要记录当前节点的下一个节点

        while(cur != suc){
            pre->next = cur;
            cur->next = head_sub;
            head_sub = pre->next;

            cur = cur_suc;
            if(cur_suc->next != nullptr)  cur_suc = cur_suc->next;
        }

        tail_sub->next = suc;

        return head;
    }

};