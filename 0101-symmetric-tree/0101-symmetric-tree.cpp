// https://leetcode.com/problems/symmetric-tree

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
    bool compare(TreeNode* p,TreeNode* q){
        if(p&&q) return (p->val==q->val)&&compare(p->right,q->left)&&compare(p->left,q->right);
        else return(p==q);
    }
    bool isSymmetric(TreeNode* root) {
        return compare(root->right,root->left);
    }
};