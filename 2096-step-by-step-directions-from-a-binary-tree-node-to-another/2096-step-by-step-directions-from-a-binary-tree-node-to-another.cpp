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
    string S, D;

public:
    void solve(TreeNode* root, string &path, int s, int d) {
        if (!root) {
            return;
        }
        if (root->val == s) {
            S = path;
        }
        if (root->val == d) {
            D = path;
        }
        if (S.empty() || D.empty()) {
            path.push_back('L');
            solve(root->left, path, s, d);
            path.pop_back();
            path.push_back('R');
            solve(root->right, path, s, d);
            path.pop_back();
        }
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string path;
        solve(root, path, startValue, destValue);
        int i;
        for (i = 0; S[i] and D[i] and S[i] == D[i]; i++)
            ;
        return string(S.size() - i, 'U') + D.substr(i);
    }
};