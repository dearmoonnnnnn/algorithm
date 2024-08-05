#include <iostream>
#include <queue>


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(nullptr), right(nullptr){}

};


// 深度优先搜索 dfs
class Solution{
public:
    bool isSameTree(TreeNode* p, TreeNode* q){
        if(p == nullptr &&  q == nullptr) return true;

        if(p->val != q->val) return false;

        if(p == nullptr && q != nullptr) return false;

        if(p != nullptr && q == nullptr) return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};


// 广度优先搜索 BFS

class Solution{
public:
    bool isSameTree(TreeNode* p, TreeNode* q){
        std::queue<TreeNode*> que_p;
        std::queue<TreeNode*> que_q;

        // if(p == nullptr && q == nullptr) return true;

        que_p.push(p);
        que_q.push(q);

        while(!que_p.empty() & !que_q.empty()){
            
            TreeNode *cur_p = que_p.front();
            TreeNode *cur_q = que_q.front();

            if(que_p.front()->val != que_q.front()->val ) return false;

            if(que_p.front() == nullptr && que_q.front() == nullptr){
                que_p.pop();
                que_q.pop();
                continue;
            }

            else if(que_p.front() == nullptr || que_q.front() == nullptr){
                return false;
            }

            else{
                que_p.push(cur_p->left);
                que_p.push(cur_p->right);

                que_q.push(cur_q->left);
                que_q.push(cur_q->right);
            }
        }

        return true;
    }
};