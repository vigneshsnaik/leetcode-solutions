// https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph

class Solution {
public:
    void dfs(int node,vector<vector<int>> &revAdjList, vector<int> &curr, vector<bool> &visited){
        visited[node]=true;
        for(int tmp:revAdjList[node]){
            if(!visited[tmp]){
                curr.push_back(tmp);
                dfs(tmp,revAdjList, curr, visited);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>revAdjList(n);   
        for(auto edge:edges)
            revAdjList[edge[1]].push_back(edge[0]);
        vector<vector<int>>res(n);
        for(int i=0; i<n; ++i){
            vector<bool>visited(n);
            vector<int>curr;
            dfs(i,revAdjList,curr,visited);
            sort(curr.begin(),curr.end());
            res[i]=curr;
        }
        return res;
    }
};