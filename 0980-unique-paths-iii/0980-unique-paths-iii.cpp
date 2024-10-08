class Solution {
public:
    int X, Y;
    int solve(vector<vector<int>>& grid, pair<int, int> curr, int empty) {
        auto& [x, y] = curr;
        if (x >= X or x < 0 or y >= Y or y < 0 or grid[y][x] == -1) {
            return 0;
        }
        if (grid[y][x] == 2) {
            return empty == 0;
        }
        grid[y][x] = -1;
        int res = solve(grid, {x + 1, y}, empty - 1) +
                  solve(grid, {x - 1, y}, empty - 1) +
                  solve(grid, {x, y + 1}, empty - 1) +
                  solve(grid, {x, y - 1}, empty - 1);
        grid[y][x] = 0;
        return res;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        pair<int, int> start;
        Y = grid.size(), X = grid[0].size();
        int empty = X * Y;
        for (int y = 0; y < Y; y++) {
            for (int x = 0; x < X; x++) {
                if (grid[y][x] == 1) {
                    start = {x, y};
                    empty--;
                } else if (grid[y][x] == -1) {
                    empty--;
                }
            }
        }
        return solve(grid, start, empty);
    }
};