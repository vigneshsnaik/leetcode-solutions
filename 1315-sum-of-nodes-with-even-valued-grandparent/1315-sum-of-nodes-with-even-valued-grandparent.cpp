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
    int res = 0;
    void solve(TreeNode* root, int decide) {
        if (!root) {
            return;
        }
        if (root->val % 2 == 0) {
            decide |= 1;
        }
        if (decide & 0b100) {
            res += root->val;
        }
        int newDecide = decide << 1;
        solve(root->left, newDecide);
        solve(root->right, newDecide);
    }
    int sumEvenGrandparent(TreeNode* root) {
        solve(root, root->val % 2 == 0 ? 1 : 0);
        return res;
    }
};