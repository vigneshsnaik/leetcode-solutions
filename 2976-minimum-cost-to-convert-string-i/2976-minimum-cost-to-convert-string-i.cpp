class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> d(26, vector<int>(26, INT_MAX));
        int N = source.size();
        for (int i = 0; i < cost.size(); i++) {
            d[original[i] - 'a'][changed[i] - 'a'] =
                min(cost[i], d[original[i] - 'a'][changed[i] - 'a']);
        }
        for (int i = 0; i < 26; ++i) {
            d[i][i] = 0;
        }
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    if (d[i][k] != INT_MAX && d[k][j] != INT_MAX) {
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                    }
                }
            }
        }
        long long res = 0;
        for (int i = 0; i < N; i++) {
            if (source[i] != target[i]) {
                if (d[source[i] - 'a'][target[i] - 'a'] == INT_MAX) {
                    return -1;
                }
                res += d[source[i] - 'a'][target[i] - 'a'];
            }
        }
        return res;
    }
};