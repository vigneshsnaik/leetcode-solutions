class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            if (count(grid[i].begin(), grid[i].end(), 0) == 1) {
                return i;
            }
        }
        return -1;
    }
};