// https://leetcode.com/problems/missing-number

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        for (int i=0;i!=nums.size();i++)
        {
            sum+=nums[i];
            sum-=i+1;
        }
        return -sum;
    }
};