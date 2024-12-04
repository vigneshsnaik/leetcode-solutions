class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int idx = 0;
        int len = str2.length();
        for (char curr : str1) {
            if (idx < len && (str2[idx] - curr + 26) % 26 <= 1) {
                idx++;
            }
        }
        return idx == len;
    }
};