class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        for (int i = 0; i < k; i++)
            sum += cardPoints[i];
        int res = INT_MIN;
        for (int i = k - 1; i >= 0; i--) {
            sum += cardPoints[cardPoints.size() - k + i] - cardPoints[i];
            res = max(res, sum);
        }
        return res;
    }
};