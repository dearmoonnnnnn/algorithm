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

        Node* p = head;
        while(p != nullptr){
            // 按照 next 拷贝
            Node* new_node = new Node(p->val);
            tail->next = new_node;
            tail = tail->next;
            map[p] = new_node;

            p = p->next;
        }
        
        while(head != nullptr){
            map[head]->random = map[head->random];
            head = head->next;
        }

        return dummy->next;
    }
};

// 方法2：递归 + 哈希表
class Solution2{
public:
    std::unordered_map<Node*, Node*> cachedNode;
    Node* copyRandomList(Node* head){
        if(head == nullptr) return nullptr;

        if(cachedNode.count(head) == 1){
            return cachedNode[head]; 
        }


        Node* new_node = new Node(head->val);
        cachedNode[head] = new_node;

        new_node->next = copyRandomList(head->next);
        new_node->random = copyRandomList(head->random);

        return new_node;
    }

};

// A-B-C  -> A-A'-B-B'-C-C'
class Solution3{
public:
    Node* copyRandomList(Node* head){
        if(head == nullptr) return nullptr;

        // next
        Node* cur = head;
        while(cur != nullptr){
            Node* newNode = new Node(cur->val);

            newNode->next = cur->next;
            cur->next = newNode;

            cur = cur->next->next;
        }

         // random
        cur = head;
        while(cur != nullptr){
            if(cur->random == nullptr){
                cur->next->random =nullptr;
            }

            else{
                cur->next->random = cur->random->next;
            }
            
            cur = cur->next->next;
        }

        // 拆分链表
        Node* cur_bef = head;
        Node* cur_aft = head->next;
        Node* res = head->next;

        while(cur_aft != nullptr){
            if(cur_aft->next == nullptr){
                cur_bef->next = nullptr;
            }

            else{
                cur_bef->next = cur_aft->next;
                cur_aft->next = cur_aft->next->next;
            }

            cur_bef = cur_bef->next;
            cur_aft = cur_aft->next;
        }

        return res; 

    }
};

int main(){
    
}




