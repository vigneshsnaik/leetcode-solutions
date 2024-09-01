class Solution {
public:
    vector<vector<vector<int>>> dp;
    int m, n;
    bool dfs(vector<vector<char>>& grid, int i, int j, int st) {
        if (i < 0 || j < 0)
            return false;
        if (dp[i][j][st] != -1)
            return dp[i][j][st];
        int tmp=st;
        if (grid[i][j] == ')')
            st++;
        else
            st--;
        if (j == 0 && i == 0)
            return !st;
        if (st < 0)
            return false;
        return dp[i][j][tmp] =
                   (dfs(grid, i - 1, j, st) or dfs(grid, i, j - 1, st));
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        dp.resize(m, vector<vector<int>>(n, vector<int>(m + n, -1)));
        return dfs(grid, m - 1, n - 1, 0);
    }
};