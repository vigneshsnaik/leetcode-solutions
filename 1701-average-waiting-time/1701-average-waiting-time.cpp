// https://leetcode.com/problems/average-waiting-time

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double time = customers[0][0], totalWT = 0;
        for (auto& times : customers) {
            if (time < times[0])
                time = times[0];
            time += times[1];
            totalWT += time - times[0];
        }
        return (double)totalWT / customers.size();
    }
};