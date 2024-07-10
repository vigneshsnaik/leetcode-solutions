// https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable

class SetUnionFind {
    vector<int> components;
    int distinct;

public:
    SetUnionFind(int n) {
        distinct=n;
        components.resize(n + 1);
        iota(components.begin(), components.end(), 0);
    }
    int findcomponents(int a) {
        if (components[a] != a) {
            components[a] = findcomponents(components[a]);
        }
        return components[a];
    }
    bool unite(int c1, int c2) {
        if (findcomponents(c2) == findcomponents(c1))
            return false;
        components[findcomponents(c1)] = c2;
        distinct--;
        return true;
    }
    bool united() { return distinct == 1; }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(),
             [](auto& a, auto& b) { return a[0] > b[0]; });
        int edgesAdded = 0;
        SetUnionFind b(n), a(n);
        for (auto& edge : edges) {
            int type = edge[0], src = edge[1], des = edge[2];
            if (type == 3)
                edgesAdded += (b.unite(src, des) | a.unite(src, des)) ? 1 : 0;
            else if (type == 2)
                edgesAdded += b.unite(src, des) ? 1 : 0;    
            else if (type == 1)
                edgesAdded += a.unite(src, des) ? 1 : 0;
        }
        return (b.united() && a.united()) ? (edges.size() - edgesAdded) : -1;
    }
};