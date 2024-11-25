class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int Y = box.size(), X = box[0].size();
        vector<vector<char>> res(X, vector<char>(Y, '.'));
        for (int i = 0; i < Y; i++) {
            int bottom = X - 1;
            for (int j = X - 1; j >= 0; j--) {
                if (box[i][j] == '#') {
                    res[bottom][Y - 1 - i] = '#';
                    bottom--;
                } else if (box[i][j] == '*') {
                    res[j][Y - 1 - i] = '*';
                    bottom = j - 1;
                }
            }
        }
        return res;
    }
};