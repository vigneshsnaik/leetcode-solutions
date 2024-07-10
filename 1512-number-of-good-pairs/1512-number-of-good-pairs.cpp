// https://leetcode.com/problems/number-of-good-pairs

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> cnt;
        for(int c:nums)
            cnt[c]++;
        return accumulate(cnt.begin(), cnt.end(), 0,[](int sum,const pair<int, int>& pair) {
            return sum+(pair.second*pair.second-pair.second)/2;
        });
    }
};