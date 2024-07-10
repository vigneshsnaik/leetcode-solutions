// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char s_to_t[256]{0};
        char t_to_s[256]{0};
        for (int i = 0; i < s.length(); ++i)
            if (s_to_t[s[i]]==0&&t_to_s[t[i]]==0) {
                s_to_t[s[i]]=t[i];
                t_to_s[t[i]]=s[i];
            } 
            else if(s_to_t[s[i]]!=t[i]||t_to_s[t[i]]!=s[i])
                return false;
        return true;
    }
};