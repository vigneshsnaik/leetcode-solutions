// https://leetcode.com/problems/concatenation-of-array

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        if (nums.size()==0) return{};
        vector<int> ans={};
        for (auto i=nums.begin();i!=nums.end();i++)
            ans.push_back(*i);
        for (auto i=nums.begin();i!=nums.end();i++)
            ans.push_back(*i);
        return ans;
    }
};