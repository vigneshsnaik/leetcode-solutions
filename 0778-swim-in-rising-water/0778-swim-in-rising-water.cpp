class Solution {
public:
    vector<vector<vector<int>>> dp;
    vector<vector<bool>> visited;
    int n;
    int solve(vector<vector<int>>& grid, int x, int y, int t) {
        if (x < 0 or y < 0 or x == n or y == n or visited[x][y])
            return INT_MAX;
        if (x == n - 1 and y == n - 1)
            return max(t, grid[x][y]);
        if (dp[x][y][t] != -1)
            return dp[x][y][t];
        visited[x][y] = true;
        dp[x][y][t] = min({
            solve(grid, x - 1, y, max(t, grid[x][y])),
            solve(grid, x + 1, y, max(t, grid[x][y])),
            solve(grid, x, y + 1, max(t, grid[x][y])),
            solve(grid, x, y - 1, max(t, grid[x][y])),
        });
        visited[x][y] = false;
        return dp[x][y][t];
    }
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        dp.resize(n, vector<vector<int>>(n, vector<int>(n * n, -1)));
        visited.resize(n, vector<bool>(n, false));
        return solve(grid, 0, 0, 0);
    }
};