class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<bool> inward(n, false);
        for (auto edge : edges) {
            inward[edge[1]] = true;
        }
        return count(inward.begin(), inward.end(), false) == 1
                   ? distance(inward.begin(),
                               find(inward.begin(), inward.end(), false))
            : -1;
    }
};