// https://leetcode.com/problems/sum-game

class Solution {
public:
    bool sumGame(string num) {
        double res = 0, n = num.length();
        for (int i = 0; i < n; ++i)
            res += (i < n / 2 ? 1 : -1) * (num[i] == '?' ? 4.5 : num[i] - '0');
        return res != 0.0;
    }
};