class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<vector<int>> revAdj(n);
        for (auto edge : edges) {
            revAdj[edge[1]].push_back(edge[0]);
        }
        int emptyIndex = -1;
        int emptyCount = 0;
        for (int i = 0; i < revAdj.size(); ++i) {
            if (revAdj[i].empty()) {
                emptyCount++;
                if (emptyCount == 1) {
                    emptyIndex = i;
                } else {
                    return -1;
                }
            }
        }
        return emptyIndex;
    }
};