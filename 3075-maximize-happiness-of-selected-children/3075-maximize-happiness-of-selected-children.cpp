// https://leetcode.com/problems/maximize-happiness-of-selected-children

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long res=0;
        partial_sort(happiness.begin(),happiness.begin()+k,happiness.end(),greater<int>());
        for(int i=0;i<k;i++)res+=happiness[i]>i?happiness[i]-i:0;
        return res;
    }
};