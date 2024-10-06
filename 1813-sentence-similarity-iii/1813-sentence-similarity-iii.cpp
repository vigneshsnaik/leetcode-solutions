class Solution {
public:
    vector<string> split(string sentence) {
        vector<string> s;
        stringstream ss(sentence);
        string str;
        while (ss >> str) {
            s.push_back(str);
        }
        return s;
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> s1 = split(sentence1);
        vector<string> s2 = split(sentence2);
        int len1 = s1.size(), len2 = s2.size();
        if (len1 > len2) {
            swap(len1, len2), swap(s1, s2);
        }
        int l = 0, r2 = len2 - 1, r1 = len1 - 1;
        while (l < len1 and s1[l] == s2[l])
            l++;
        while (r1 > 0 and s1[r1--] == s2[r2--])
            ;
        return r1 < l;
    }
};