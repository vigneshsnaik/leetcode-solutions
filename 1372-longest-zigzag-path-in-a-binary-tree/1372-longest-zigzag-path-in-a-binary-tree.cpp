// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree

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
    int maxStep = 0;
    int longestZigZag(TreeNode* root) {
        dfs(root,true,0);
        dfs(root,false,0);
        return maxStep;
    }
    void dfs(TreeNode* root, bool isLeft, int step) {
        if (!root) return;
        maxStep = max(maxStep, step);
        dfs(root->left,false,isLeft?step+1:1);
        dfs(root->right,true,isLeft?1:step+1);
    }
};