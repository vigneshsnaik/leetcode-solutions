// https://leetcode.com/problems/binary-tree-level-order-traversal

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
    vector<vector<int>>res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return{};
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        vector<int>nodes;
        while(!q.empty()){
            auto tmp=q.front().first;
            int level=q.front().second;
            if(level!=res.size()){
                res.push_back(nodes);
                nodes.clear();
            }
            nodes.push_back(tmp->val);
            q.pop();
            if(tmp->left)q.push({tmp->left,level+1});
            if(tmp->right)q.push({tmp->right,level+1});
        }
        res.push_back(nodes);
        return res;
    }
};