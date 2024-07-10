// https://leetcode.com/problems/binary-tree-right-side-view

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return{};
        vector<int>res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            TreeNode* tmp; 
            for(int i=0;i<size;i++){
                tmp=q.front();
                q.pop();
                if(tmp->left)q.push(tmp->left);
                if(tmp->right)q.push(tmp->right);
            }
            res.push_back(tmp->val);
        }
        return res;
    }
};