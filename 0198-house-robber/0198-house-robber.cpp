// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1=0,prev2=0;
        for(int num:nums){
            int tmp=prev1;
            prev1=max(prev2+num,prev1);
            prev2=tmp;
        }
        return prev1;
    }
};