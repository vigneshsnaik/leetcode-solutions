// https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        for (int i = 0; i < strs[0].size(); i++)
            for (int j = 1; j < strs.size(); j++)
                if (strs[j][i] != strs[j - 1][i])
                    return strs[j].substr(0,i);
        return strs[0];
    }
};