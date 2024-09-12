class Solution {
public:
    int countConsistentStrings(string& allowed, vector<string>& words) {
        bool isAllowed[26] = {false};
        for (char c : allowed) {
            isAllowed[c - 'a'] = true;
        }
        return count_if(words.begin(), words.end(), [&isAllowed](string s) {
            for (char c : s) {
                if (!isAllowed[c - 'a']) {
                    return false;
                }
            }
            return true;
        });
    }
};