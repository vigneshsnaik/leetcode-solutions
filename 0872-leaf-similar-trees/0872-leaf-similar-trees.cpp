// https://leetcode.com/problems/leaf-similar-trees

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
    vector<int>leaves1;
    vector<int>leaves2;
    void inorder(TreeNode* root,vector<int>&res){
        if(root==NULL)return;
        inorder(root->left,res);
        if(!root->left&&!root->right)res.push_back(root->val);
        inorder(root->right,res);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        inorder(root1,leaves1);
        inorder(root2,leaves2);
        return leaves1==leaves2;
    }
};