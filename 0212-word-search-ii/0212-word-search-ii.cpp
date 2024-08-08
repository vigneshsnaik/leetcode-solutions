class Solution {
public:
    vector<pair<int, int>> neighbours = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int X, Y;
    bool search(vector<vector<char>>& board, int x, int y, string& word,
                int curr, bool visited[12][12]) {
        if (word[curr] == '\0')
            return true;
        if (x < 0 or y < 0 or x == X or y == Y or visited[y][x] or
            (word[curr] and word[curr] != board[y][x]))
            return false;
        for (auto& [dx, dy] : neighbours) {
            visited[y][x] = true;
            if (search(board, x + dx, y + dy, word, curr + 1, visited))
                return true;
            visited[y][x] = false;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        Y = board.size(), X = board[0].size();
        bool visited[12][12];
        for (int y = 0; y < Y; y++) {
            for (int x = 0; x < X; x++) {
                if (board[y][x] == word[0]) {
                    if (search(board, x, y, word, 0, visited)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        vector<string> res;
        for (string& word : words) 
            if (exist(board, word))
                res.push_back(word);
        return res;
    }
};