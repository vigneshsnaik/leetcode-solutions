// https://leetcode.com/problems/jump-game

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        for (int res = 0; i < nums.size() and i <= res; i++)
            res = max(nums[i] + i, res);
        return i == nums.size();
    }
};