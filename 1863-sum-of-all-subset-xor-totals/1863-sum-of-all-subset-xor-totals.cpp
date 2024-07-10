// https://leetcode.com/problems/sum-of-all-subset-xor-totals

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans=0;
        for(auto it:nums)ans|=it;
        return ans<<(nums.size()-1);
    }
};