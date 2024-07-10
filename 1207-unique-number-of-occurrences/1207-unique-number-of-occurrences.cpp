// https://leetcode.com/problems/unique-number-of-occurrences

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int>cnt(2001);
        for(int num:arr)
            cnt[num+1000]++;
        sort(cnt.rbegin(),cnt.rend());
        for(int i=0;i<2000;i++)
            if(cnt[i]&&cnt[i]==cnt[i+1])return 0;
        return true;
    }
};