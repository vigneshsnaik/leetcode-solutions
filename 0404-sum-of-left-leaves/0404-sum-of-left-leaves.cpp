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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root)if(root->left)return (!root->left->left&&!root->left->right?root->left->val:0)+sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
        else return sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
        return 0;
    }
};