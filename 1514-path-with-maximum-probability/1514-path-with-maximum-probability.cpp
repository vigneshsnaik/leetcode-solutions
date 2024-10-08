class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> g(n);
        for (int i = 0; i < edges.size(); i++) {
            g[edges[i][0]].push_back({edges[i][1], succProb[i]});
            g[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<int> seen(n, 0);
        priority_queue<pair<double, int>> q;
        q.push({(double)1.0, start_node});
        vector<double> mx(n, (double)0.0);
        mx[start_node] = 1.0;
        while (!q.empty()) {
            auto top = q.top();
            q.pop();
            double proba = top.first;
            int node = top.second;
            if (!seen[node]) {
                seen[node]++;
                for (auto& to : g[node]) {
                    if (mx[to.first] < to.second * proba) {
                        mx[to.first] = to.second * proba;
                        q.push({mx[to.first], to.first});
                    }
                }
            }
        }
        return mx[end_node];
    }
};