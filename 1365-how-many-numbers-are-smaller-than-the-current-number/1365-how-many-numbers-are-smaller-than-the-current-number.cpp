class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(101, 0);
        for (int x : nums) {
            count[x]++;
        }
        for (int i = 1; i <= 100; i++) {
            count[i] += count[i - 1];
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                ans[i] = 0;
            } else {
                ans[i] = count[nums[i] - 1];
            }
        }
        return ans;
    }
};