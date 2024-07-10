// https://leetcode.com/problems/teemo-attacking

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res=0;
        for(int i=0;i<timeSeries.size()-1;i++)
            res+=(timeSeries[i]+duration<=timeSeries[i+1])?duration:(timeSeries[i+1]-timeSeries[i]);
        return res+duration;
    }
};