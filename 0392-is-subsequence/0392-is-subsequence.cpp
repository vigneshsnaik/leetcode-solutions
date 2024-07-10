// https://leetcode.com/problems/is-subsequence

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(t.length()<s.length())return false;
        int i=0;
        for(char ch:t)if(s[i]==ch)++i;
        return i>=s.length()?true:false;
    }
};