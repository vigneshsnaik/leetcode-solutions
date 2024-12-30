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
    TreeNode* solve(vector<int>& nums, int l, int h) {
        if (l == h) {
            return NULL;
        }
        int pivot = max(nums, l, h);
        TreeNode* root = new TreeNode(nums[pivot]);
        root->left = solve(nums, l, pivot);
        root->right = solve(nums, pivot + 1, h);
        return root;
    }
    int max(vector<int> nums, int l, int h) {
        int pivot = l;
        for (int i = l; i < h; i++) {
            if (nums[pivot] < nums[i]) {
                pivot = i;
            }
        }
        return pivot;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return solve(nums, 0, nums.size());
    }
};