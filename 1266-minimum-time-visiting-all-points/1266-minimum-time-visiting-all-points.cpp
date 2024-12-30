class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int prevX = points[0][0], prevY = points[0][1], res = 0;
        for (auto p : points) {
            int x = p[0], y = p[1];
            res += max(abs(prevX - x), abs(prevY - y));
            prevX = x, prevY = y;
        }
        return res;
    }
};