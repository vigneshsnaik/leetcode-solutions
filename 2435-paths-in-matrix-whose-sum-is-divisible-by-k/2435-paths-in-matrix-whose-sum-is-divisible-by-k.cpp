class Solution {
public:
    int mod = 1e9 + 7, X, Y, K;
    vector<vector<vector<int>>> dp;
    int solve(vector<vector<int>>& grid, int x, int y, int numpath) {
        if (x == X or y == Y)
            return 0;
        if (y == Y - 1 && x == X - 1)
            return ((numpath + grid[y][x]) % K) == 0;
        return dp[y][x][numpath] == -1
                   ? (dp[y][x][numpath] =
                          (solve(grid, x + 1, y, (numpath + grid[y][x]) % K) +
                           solve(grid, x, y + 1, (numpath + grid[y][x]) % K)) %
                          mod)
                   : dp[y][x][numpath];
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        Y = grid.size(), X = grid[0].size(), K = k;
        dp.resize(Y, vector<vector<int>>(X, vector<int>(K, -1)));
        return solve(grid, 0, 0, 0);
    }
};