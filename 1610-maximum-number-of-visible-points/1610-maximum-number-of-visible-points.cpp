class Solution {
public:
    double diff(double a1, double a2) { return a1 - a2; }

    int visiblePoints(vector<vector<int>>& points, int angle,
                      vector<int>& location) {
        vector<double> angles;
        int originPoints = 0;
        for (auto& v : points) {
            if (v == location) {
                originPoints++;
                continue;
            }
            double angleDeg =
                atan2(v[1] - location[1], v[0] - location[0]) * (180.0 / M_PI);
            if (angleDeg < 0)
                angleDeg += 360;
            angles.push_back(angleDeg);
        }
        sort(angles.begin(), angles.end());
        if (angles.empty())
            return originPoints;
        int n = points.size();
        int maxPoints = 0;
        int i = 0, j = 0;
        while (i < n) {
            while (j < n + i) {
                angles.push_back(angles[j] + 360);
                j++;
            }
            int count = 0;
            int start = i, end = i + n;
            for (int k = start; k < end; k++) {
                if (angles[k] - angles[start] <= angle) {
                    count++;
                }
            }
            maxPoints = max(maxPoints, count);
            i++;
        }
        return maxPoints + originPoints;
    }
};
