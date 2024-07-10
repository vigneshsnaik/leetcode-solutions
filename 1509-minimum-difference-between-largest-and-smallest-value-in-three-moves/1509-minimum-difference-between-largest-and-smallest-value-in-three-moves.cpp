// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves

class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() <= 4)
            return 0;
        sort(nums.begin(), nums.end());
        int res = INT_MAX;
        int n = nums.size();
        for (int i = 0; i < 4; i++) {
            res = min(nums[n - 4 + i] - nums[i], res);
        }
        return res;
    }
};