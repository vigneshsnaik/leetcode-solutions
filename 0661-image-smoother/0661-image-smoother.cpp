class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0, count = 0;
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        if (0 <= x and x < m and 0 <= y and y < n) {
                            sum += img[x][y];
                            count += 1;
                        }
                    }
                }
                res[i][j] = sum / count;
            }
        }
        return res;
    }
};