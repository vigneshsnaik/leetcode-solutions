class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<pair<int, int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                       {0, 1},   {1, -1}, {1, 0},  {1, 1}};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0;
                for (const auto& dir : dirs) {
                    int x = i + dir.first;
                    int y = j + dir.second;
                    if (x >= 0 && x < m && y >= 0 && y < n &&
                        (board[x][y] & 1)) {
                        ++sum;
                    }
                }
                if (sum < 2 || sum > 3)
                    board[i][j] |= 0;
                else if (sum == 3)
                    board[i][j] |= 2;
                else if (board[i][j])
                    board[i][j] |= 2;
            }
        }
        for (auto& row : board) {
            for (auto& cell : row) {
                cell = cell >> 1;
            }
        }
    }
};