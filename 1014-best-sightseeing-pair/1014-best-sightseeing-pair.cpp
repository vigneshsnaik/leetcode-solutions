class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        vector<int> maxLeftScore(values.size());
        maxLeftScore[0] = values[0];
        int maxScore = 0;
        for (int i = 1; i < values.size(); i++) {
            int currentRightScore = values[i] - i;
            maxScore = max(maxScore, maxLeftScore[i - 1] + currentRightScore);
            int currentLeftScore = values[i] + i;
            maxLeftScore[i] = max(maxLeftScore[i - 1], currentLeftScore);
        }
        return maxScore;
    }
};