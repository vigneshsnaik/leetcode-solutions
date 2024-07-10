// https://leetcode.com/problems/find-bottom-left-tree-value

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
    int maxDepth=0,res;
    int findBottomLeftValue(TreeNode* root,int depth=0) {
        if(!root->left&&!root->right&&depth>=maxDepth){
            res=root->val;
            maxDepth=depth;
        }
        if(root->right)findBottomLeftValue(root->right,depth+1);
        if(root->left)findBottomLeftValue(root->left,depth+1);
        return res;
    }
};