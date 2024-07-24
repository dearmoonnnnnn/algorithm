#include <iostream>
#include <vector>

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){};
};


class Solution{
public:
    // 使用快慢指针
    bool hasCycle(ListNode *head){
        if(head->next == nullptr){
            return false;
        }

        ListNode* fast_ptr = head->next;
        ListNode* slow_ptr = head;

        while(fast_ptr != nullptr){
            if(fast_ptr == slow_ptr){
                return true;
            }

            if(fast_ptr->next != nullptr && fast_ptr->next->next != nullptr){
                fast_ptr = fast_ptr->next->next;
                slow_ptr = slow_ptr->next;
            }
            
        } 

        return false;
    }
};



int main() {
    // 创建一个无环链表：1 -> 2 -> 3 -> 4 -> 5
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);

    // 创建一个有环链表：1 -> 2 -> 3 -> 4 -> 5 -> 2 (成环)
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);
    head2->next->next->next->next->next = head2->next; // 成环

    Solution solution;
    
    // 测试无环链表
    if (solution.hasCycle(head1)) {
        std::cout << "head1 has a cycle." << std::endl;
    } else {
        std::cout << "head1 does not have a cycle." << std::endl;
    }

    // 测试有环链表
    if (solution.hasCycle(head2)) {
        std::cout << "head2 has a cycle." << std::endl;
    } else {
        std::cout << "head2 does not have a cycle." << std::endl;
    }

    // 清理内存
    // 注意：有环链表的清理需要特别处理，这里仅简单演示无环链表的清理
    ListNode* current = head1;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

    // 对于有环链表，这里就不演示如何清理了，因为需要额外的步骤来打破环
    // 否则会导致无限循环或者访问非法内存

    return 0;
}

