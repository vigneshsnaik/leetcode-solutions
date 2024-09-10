class Solution {
public:
    vector<int> path = {0};
    vector<vector<int>> res;
    void dfs(vector<vector<int>>& graph, int curr, int n) {
        if (curr == n) {
            res.push_back(path);
            return;
        }
        for (int node : graph[curr]) {
            path.push_back(node);
            dfs(graph, node, n);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph, 0, graph.size() - 1);
        return res;
    }
};