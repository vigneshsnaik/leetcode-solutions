// https://leetcode.com/problems/find-triangular-sum-of-an-array

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if(nums.size()==1)return *(nums.begin());
        for(auto i=nums.begin();i!=nums.end()-1;i++)*i=(*i+*(i+1))%10;
        nums.pop_back();
        return triangularSum(nums);
    }
};