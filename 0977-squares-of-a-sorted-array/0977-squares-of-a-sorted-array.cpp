// https://leetcode.com/problems/squares-of-a-sorted-array

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        auto i=nums.begin();
        auto j=nums.rbegin();
        vector<int> res(n);
        for(auto k=res.rbegin();k!=res.rend();k++)*k=pow(abs(*i)>abs(*j)?*i++:*j++,2);
        return res;
    }
};
