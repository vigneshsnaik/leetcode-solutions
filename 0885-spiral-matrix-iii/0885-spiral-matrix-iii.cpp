class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int m, int n, int x, int y) {
        vector<vector<int>> res;
        int len = 1;
        res.push_back({x, y});
        while (res.size() < m * n) {
            for (int j = 1; j <= len; j++)
                if (isValid(x, y + j, m, n))
                    res.push_back({x, y + j});
            y += len;
            for (int i = 1; i <= len; i++)
                if (isValid(x + i, y, m, n))
                    res.push_back({x + i, y});
            x += len;
            len++;
            for (int j = 1; j <= len; j++)
                if (isValid(x, y - j, m, n))
                    res.push_back({x, y - j});
            y -= len;
            for (int i = 1; i <= len; i++)
                if (isValid(x - i, y, m, n))
                    res.push_back({x - i, y});
            x -= len;
            len++;
        }
        return res;
    }

    bool isValid(int i, int j, int m, int n) {
        return (i >= 0 and j >= 0 and i < m and j < n);
    }
};