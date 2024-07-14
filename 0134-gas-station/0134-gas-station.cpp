class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), totalGas = 0, remainingGas = 0, start = 0;
        for (int i = 0; i < n; i++) {
            totalGas += gas[i] - cost[i];
            remainingGas += gas[i] - cost[i];
            if (remainingGas < 0) {
                remainingGas = 0;
                start = i + 1;
            }
        }
        return (totalGas < 0) ? -1 : start;
    }
};