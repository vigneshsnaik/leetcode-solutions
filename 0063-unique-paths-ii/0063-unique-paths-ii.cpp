// https://leetcode.com/problems/unique-paths-ii

class Solution {
public:
    vector<vector<int>> dp;
    int m, n;
    int solve(vector<vector<int>>& obstacleGrid, int x, int y) {
        if (x == m || y == n)
            return 0;
        if (obstacleGrid[x][y])
            return 0;
        if (dp[x][y])
            return dp[x][y];
        return dp[x][y] = solve(obstacleGrid, x + 1, y) +
                          solve(obstacleGrid, x, y + 1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size(), n = obstacleGrid[0].size();
        dp.resize(m, vector<int>(n));
        dp[m - 1][n - 1] = 1;
        return solve(obstacleGrid, 0, 0);
    }
};