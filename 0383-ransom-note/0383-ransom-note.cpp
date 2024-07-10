// https://leetcode.com/problems/ransom-note

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count[26];
        for (char c : magazine)
            count[c - 'a']++;
        for (char c : ransomNote)
            if (count[c - 'a'])
                count[c - 'a']--;
            else
                return false;
        return true;
    }
};