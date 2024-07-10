// https://leetcode.com/problems/maximum-subarray

class Solution {    
public:
    int maxSubArray(vector<int>& nums) {
        int curr=0,max=*(nums.begin());
        for(int x:nums){
            curr=std::max(x,x+curr);
            max=std::max(max,curr);
        }
        return max;
    }
};