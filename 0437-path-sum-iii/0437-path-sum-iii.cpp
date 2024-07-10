// https://leetcode.com/problems/path-sum-iii

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
    int pathSumOfSelfandChildren(TreeNode* root, long targetSum){
        if(!root)return 0;
        return 
            (root->val==targetSum?1:0)+
            pathSumOfSelfandChildren(root->left,targetSum-root->val)+
            pathSumOfSelfandChildren(root->right,targetSum-root->val);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)return 0;
        return pathSumOfSelfandChildren(root,targetSum)+pathSum(root->left,targetSum)+pathSum(root->right,targetSum);
    }
};