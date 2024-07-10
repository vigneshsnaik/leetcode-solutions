// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,len=0;
        vector<int>map(128,-1);
        while(r<s.size()){
            if(map[s[r]]!=-1)l=max(map[s[r]]+1,l);
            map[s[r]]=r;
            len=max(len,r-l+1);     
            r++;
        }
        return len;
    }
};