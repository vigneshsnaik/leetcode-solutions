// https://leetcode.com/problems/minimum-size-subarray-sum

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int j = 0, res = INT_MAX, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum +=nums[i];
            while (sum >= target) {
                res = min(res, i - j + 1);
                sum -= nums[j++];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};