// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())return false;
        int map[26];
        for(int i=0;i<s.length();i++){
            map[s[i]-'a']++;
            map[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(map[i])return false;
        }
        return true;
    }
};