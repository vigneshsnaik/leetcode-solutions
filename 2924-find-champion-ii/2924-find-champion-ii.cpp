class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<bool> inward(n, false);
        for (vector<int>& edge : edges) {
            inward[edge[1]] = true;
        }
        int champion = -1;
        for (int i = 0; i < n; i++) {
            if (!inward[i]) {
                if (champion != -1) {
                    return -1;
                }
                champion = i;
            }
        }
        return champion;
    }
};