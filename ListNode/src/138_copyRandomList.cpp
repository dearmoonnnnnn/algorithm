#include <iostream>
#include <unordered_map>
// 传统链表节点
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){}
};

// 定义随机链表节点

class Node{
public:
    int val;
    Node* next;
    Node* random;

    Node(int x) : val(x), next(nullptr), random(nullptr){}
};

// 双迭代 + 哈希表
class solution{
public:
    Node* copyRandomList(Node* head){
        std::unordered_map<Node*, Node*> map;

        Node* dummy = new Node(-1);
        Node* tail = dummy;

        if(head == nullptr) return nullptr;

        while(head != nullptr){

            // 按照 next 拷贝
            Node* new_node = new Node(head->val);
            tail->next = new_node;
            tail = tail->next;
            map[new_node] = head;
        }

        Node* cur = dummy->next;
        while(cur != nullptr){
            cur->random = map[cur]->random;
            cur = cur->next;
        }

        return dummy->next;

    }
};

int main(){
    
}




