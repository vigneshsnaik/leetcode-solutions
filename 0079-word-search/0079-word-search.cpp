class Solution {
public:
    vector<pair<int, int>> neighbours = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int X, Y;
    bool visited[6][6];
    bool search(vector<vector<char>>& board, int x, int y, string& word,
                int curr) {
        if (x < 0 or y < 0 or x == X or y == Y or visited[y][x] or
            (word[curr] and word[curr] != board[y][x]))
            return false;
        printf("%d %d %d %c\n", x, y, curr, word[curr]);
        if (word[curr] == '\0') {
            return true;
        }
        for (auto& [dx, dy] : neighbours) {
            visited[y][x] = true;
            if (search(board, x + dx, y + dy, word, curr + 1))
                return true;
            visited[y][x] = false;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        Y = board.size(), X = board[0].size();
        for (int y = 0; y < Y; y++) {
            for (int x = 0; x < X; x++) {
                if (board[y][x] == word[0]) {
                    if (search(board, x, y, word, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
