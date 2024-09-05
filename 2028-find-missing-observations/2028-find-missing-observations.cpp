class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = accumulate(rolls.begin(), rolls.end(), 0);
        int miss = mean * (n + rolls.size()) - sum;
        if (miss < n || miss > 6 * n) {
            return {};
        }
        int extra = miss % n;
        vector<int> res(n, miss / n);
        for (int i = 0; i < extra; ++i) {
            res[i]++;
        }
        return res;
    }
};
