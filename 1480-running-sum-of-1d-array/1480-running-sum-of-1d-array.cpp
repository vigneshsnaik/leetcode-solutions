// https://leetcode.com/problems/running-sum-of-1d-array

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        if(nums.size()<2)
            return nums;
        for(auto i=nums.begin()+1;i!=nums.end();i++)
            *i+=*(i-1);
        return nums;
    }
};