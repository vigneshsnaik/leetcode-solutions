class Solution {
public:
    int maxScore(string s) {
        int cnt1 = count(s.begin(), s.end(), '1'), res = 0, cnt0 = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '1') {
                cnt1--;
            } else {
                cnt0++;
            }
            res = max(res, cnt0 + cnt1);
        }
        return res;
    }
};