class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res = 0;
        for (string word : words) {
            if (pref == word.substr(0, pref.size())) {
                res++;
            }
        }
        return res;
    }
};