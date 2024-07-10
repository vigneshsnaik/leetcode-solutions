// https://leetcode.com/problems/rotate-array

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        std::rotate(nums.begin(),nums.begin()+nums.size()-k%nums.size(),nums.end());
    }
};