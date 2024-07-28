class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> d1(n + 1, INT_MAX);
        vector<int> d2(n + 1, INT_MAX);
        queue<pair<int, int>> q;
        q.push({1, 1});
        d1[1] = 0;
        while (!q.empty()) {
            auto [node, freq] = q.front();
            q.pop();
            int timePassed = (freq == 1) ? d1[node] : d2[node];
            if (d2[n] != INT_MAX && node == n) {
                return d2[n];
            }
            int mult = timePassed / change;
            if (mult % 2 == 1) {
                timePassed = change * (mult + 1);
            }
            for (auto& nbr : adj[node]) {
                if (d1[nbr] == INT_MAX) {
                    d1[nbr] = timePassed + time;
                    q.push({nbr, 1});
                } else if (d2[nbr] == INT_MAX && d1[nbr] != timePassed + time) {
                    d2[nbr] = timePassed + time;
                    q.push({nbr, 2});
                }
            }
        }
        return -1;
    }
};
