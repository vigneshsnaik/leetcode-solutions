// https://leetcode.com/problems/most-frequent-even-element

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int>count;
        for(int num:nums)
            if(num%2==0)count[num]++;
        if(count.empty())return -1;
        pair<int,int>res={INT_MAX,0};
        for (auto [element, cnt] : count) 
            res=(cnt>res.second||(cnt==res.second&&element<res.first))?make_pair(element,cnt):res;
        return res.first;
    }
};