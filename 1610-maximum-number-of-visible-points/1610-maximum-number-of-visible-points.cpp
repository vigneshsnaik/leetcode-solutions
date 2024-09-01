class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> angles;
        int originPoints = 0;
        for (auto& point : points) {
            if (point == location) {
                originPoints++;
                continue;
            }
            double angleDeg =
                atan2(point[1] - location[1], point[0] - location[0]) *
                (180.0 / M_PI);
            if (angleDeg < 0)
                angleDeg += 360;
            angles.push_back(angleDeg);
        }
        sort(angles.begin(), angles.end());
        int n = angles.size();
        for (int i = 0; i < n; i++) {
            angles.push_back(angles[i] + 360);
        }
        int maxPoints = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < angles.size() && angles[j] - angles[i] <= angle) {
                j++;
            }
            maxPoints = max(maxPoints, j - i);
        }
        return maxPoints + originPoints;
    }
};
