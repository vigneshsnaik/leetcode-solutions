// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};
        bool rev = true;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            rev = !rev;
            int size = q.size();
            vector<int> nodes;
            for (int i = 0; i < size; i++) {
                auto tmp = q.front();
                q.pop();
                nodes.push_back(tmp->val);
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);
            }
            if (rev)
                reverse(nodes.begin(), nodes.end());
            res.push_back(nodes);
        }
        return res;
    }
};