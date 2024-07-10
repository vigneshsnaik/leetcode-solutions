// https://leetcode.com/problems/average-of-levels-in-binary-tree

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            level++;
            int size = q.size();
            double levelSum = 0.0;
            for (int i = 0; i < size; i++) {
                auto tmp = q.front();
                q.pop();
                levelSum += tmp->val;
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);
            }
            res.push_back((double)levelSum / size);
        }
        return res;
    }
};
