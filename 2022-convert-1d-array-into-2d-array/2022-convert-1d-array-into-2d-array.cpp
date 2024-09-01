class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> res;
        if (m * n != original.size())
            return res;
        for (int i = 0; i < m; i++)
            res.push_back(vector<int>(original.begin() + i * n, original.begin() + (i + 1) * n));
        return res;
    }
};