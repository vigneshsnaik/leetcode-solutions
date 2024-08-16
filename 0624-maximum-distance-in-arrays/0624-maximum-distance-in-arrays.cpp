class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int smallest = arrays[0][0], biggest = arrays[0].back(), max_distance = 0;
        for (int i = 1; i < arrays.size(); ++i) {
            max_distance = max({abs(arrays[i].back() - smallest), abs(biggest - arrays[i][0]), max_distance});
            smallest = min(smallest, arrays[i][0]);
            biggest = max(biggest, arrays[i].back());
        }
        return max_distance;
    }
};