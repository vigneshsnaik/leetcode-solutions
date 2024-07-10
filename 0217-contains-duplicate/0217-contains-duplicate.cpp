// https://leetcode.com/problems/contains-duplicate

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> num(nums.begin(),nums.end());   
        return !(nums.size()==num.size());     
    }
};