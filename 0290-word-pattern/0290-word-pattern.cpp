// https://leetcode.com/problems/word-pattern

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string p2s[26];
        map<string, char> s2p;
        istringstream iss(s);
        string word;
        int i = 0;
        while (iss >> word) {
            if (!pattern[i])
                return false;
            if (!p2s[pattern[i] - 'a'].empty() and p2s[pattern[i] - 'a'] != word)
                return false;
            if (s2p[word]!='\0' and s2p[word] != pattern[i])
                return false;
            s2p[word] = pattern[i];
            p2s[pattern[i] - 'a'] = word;
            i++;
        }
        if (pattern[i])
            return false;
        return true;
    }
};