class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> sklX(n), sklY(n);
        for (int i = 0; i < n; i++) {
            int maxX = 0, maxY = 0;
            for (int j = 0; j < n; j++) {
                maxX = max(maxX, grid[j][i]), maxY = max(maxY, grid[i][j]);
            }
            sklX[i] = maxX, sklY[i] = maxY;
        }
        int res = 0;
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                res += min(sklX[x], sklY[y]) - grid[y][x];
            }
        }
        return res;
    }
};