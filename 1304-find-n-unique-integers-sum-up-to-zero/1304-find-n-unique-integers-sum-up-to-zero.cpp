class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res(n);
        for (int i = 1; i <= n / 2; i++) {
            res[2 * i - 2] = i;
            res[2 * i - 1] = -i;
        }
        return res;
    }
};