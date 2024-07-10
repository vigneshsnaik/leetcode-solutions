// https://leetcode.com/problems/projection-area-of-3d-shapes

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int xy = 0, yz = 0, zx = 0;
        int n = grid.size();
        for (int x = 0; x < n; x++) {
            int tmpxy = 0;
            int tmpyz = 0;
            for (int y = 0; y < n; y++) {
                if (grid[x][y])
                    xy++;
                tmpxy = max(grid[x][y], tmpxy);
                tmpyz = max(grid[y][x], tmpyz);
            }
            xy += tmpxy;
            zx += tmpyz;
        }
        return xy + yz + zx;
    }
};