class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        int ogColor = image[sr][sc];
        if (color == ogColor)
            return image;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        vector<pair<int, int>> neighbours = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!q.empty()) {
            auto [x, y] = q.front();
            for (auto [dx, dy] : neighbours) {
                int X = x + dx;
                int Y = y + dy;
                if (X >= 0 && X < m && Y >= 0 && Y < n && image[X][Y] == ogColor) {
                    q.push({X, Y});
                    image[X][Y] = color;
                }
            }
            q.pop();
        }
        return image;
    }
};
