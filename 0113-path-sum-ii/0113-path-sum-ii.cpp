// https://leetcode.com/problems/path-sum-ii

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
    void pathSum(TreeNode* root, int targetSum,vector<int>path) {
        if(!root)return;
        path.push_back(root->val);
        targetSum-=root->val;
        if(!root->left&&!root->right&&!targetSum){
            res.push_back(path);
            return;
        }
        pathSum(root->right,targetSum,path);
        pathSum(root->left,targetSum,path);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        pathSum(root,targetSum,{});
        return res;
    }
};

