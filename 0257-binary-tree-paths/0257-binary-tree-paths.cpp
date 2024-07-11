/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<string> res;
    void solve(TreeNode* root, string s) {
        if (!root)
            return;
        if (!root->left and !root->right) {
            s += to_string(root->val);
            res.push_back(s);
        }
        s += to_string(root->val) + "->";
        solve(root->right, s);
        solve(root->left, s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        solve(root, "");
        return res;
    }
};