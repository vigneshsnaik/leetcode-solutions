// https://leetcode.com/problems/find-if-path-exists-in-graph

class Solution {
public:
    bool dfs(vector<vector<int>>& mat, int src, int des, vector<int>& visited) {
        if (src == des)
            return true;
        if (visited[src])
            return false;
        visited[src] = true;
        for (int i : mat[src])
            if (dfs(mat, i, des, visited))
                return true;
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        vector<vector<int>> graph(n);
        for (auto const& v : edges){
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        vector<int> visited(n);
        return dfs(graph, source, destination, visited);
    }
};