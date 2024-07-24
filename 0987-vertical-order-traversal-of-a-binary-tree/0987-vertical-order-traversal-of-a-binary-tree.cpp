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
    vector<vector<int>> res;
    vector<vector<int>> c;
    void dfs(TreeNode* root, int x, int y) {
        if (!root)
            return;
        c.push_back({root->val, x, y});
        dfs(root->left, x - 1, y + 1);
        dfs(root->right, x + 1, y + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        sort(c.begin(), c.end(), [](auto v1, auto v2) {
            if (v1[1] == v2[1]) {
                if (v1[2] == v2[2]) {
                    return v1[0] < v2[0];
                }
                return v1[2] < v2[2];
            }
            return v1[1] < v2[1];
        });
        int x, xPrev = INT_MIN;
        for (auto v : c) {
            if (v[1] != xPrev) {
                res.push_back({v[0]});
                xPrev=v[1];
            }
            else res.back().push_back(v[0]);
        }
        return res;
    }
};