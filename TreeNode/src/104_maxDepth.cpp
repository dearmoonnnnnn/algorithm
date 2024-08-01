#include <iostream>
#include <cmath>
#include <queue>

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;    
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right){}
};


// DFS, 深度优先搜索
class Solution{
public:
    int maxDepth(TreeNode* root){
        if(root == nullptr) return 0;

        int res;
        res = std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    
        return res;
    }
};

// BFS, 广度优先搜索
class Solution{
public:
    int maxDepth(TreeNode* root){
        std::queue<TreeNode*> q;
        int res = 0;

        if(root == nullptr) return 0;

        TreeNode *cur = root;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            while(size > 0){
                cur = q.front();
                q.pop();
                if(cur->left != nullptr) q.push(cur->left);
                if(cur->right != nullptr) q.push(cur->right);

                size--;
            }

            res++;
        
        }
        
        return res;
    }
};

