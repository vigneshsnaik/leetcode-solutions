// https://leetcode.com/problems/append-characters-to-string-to-make-subsequence

class Solution {
public:
    int appendCharacters(string s, string t) {
        int si=0,ti=0;
        while(si<s.length()){
            if(s[si]==t[ti])ti++;
            si++;
        }
        return t.length()-ti;
    }
};