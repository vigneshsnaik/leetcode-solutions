class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int res = 0;
        for (string word : words) {
            if (word == s.substr(0, word.size())) {
                res++;
            }
        }
        return res;
    }
};