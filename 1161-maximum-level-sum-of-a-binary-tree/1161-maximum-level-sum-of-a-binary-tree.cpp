// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree

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
    int maxLevelSum(TreeNode* root) {
        int maxSum=INT_MIN;
        int res=0;
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            level++;
            int size=q.size();
            int levelSum=0;
            for(int i=0;i<size;i++){
                auto tmp=q.front();
                q.pop();
                levelSum+=tmp->val;
                if(tmp->left)q.push(tmp->left);
                if(tmp->right)q.push(tmp->right);
            }
            res=levelSum>maxSum?level:res;
            maxSum=max(maxSum,levelSum);
        }
        return res;
    }
};