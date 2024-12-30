class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int Y = grid.size(), y = 0, x = grid[0].size() - 1, count = 0;
        while (y < Y && x >= 0) {
            if (grid[y][x] >= 0) {
                y++;
            } else {
                count += Y - y;
                x--;
            }
        }
        return count;
    }
};