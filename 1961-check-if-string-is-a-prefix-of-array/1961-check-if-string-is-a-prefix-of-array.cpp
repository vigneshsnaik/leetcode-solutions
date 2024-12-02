class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string w;
        for (string word : words) {
            w += word;
            if (w == s) {
                return true;
            }
        }
        return false;
    }
};