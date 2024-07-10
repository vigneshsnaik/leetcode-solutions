// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero

class Solution {
public:
    int change;
    vector<vector<pair<int,int>>> adj;
    vector<bool>visited;
    void dfs(int curr,int from){
        visited[curr]=true;
        for(auto &[to,real]:adj[curr])
            if(!visited[to]){
                change+=real?1:0;
                dfs(to,curr);
            }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        adj.resize(n);
        visited.resize(n,false);
        change=0;
        for (auto& connection : connections) {
            adj[connection[0]].push_back({connection[1],true});
            adj[connection[1]].push_back({connection[0],false});
        }
        dfs(0,-1);
        return change;
    }
};