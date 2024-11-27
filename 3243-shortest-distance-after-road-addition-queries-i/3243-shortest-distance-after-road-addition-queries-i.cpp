class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>>& queries) {
        vector<vector<pair<int, int>>> graph(n);
        for (int i = 0; i < n - 1; ++i) {
            graph[i].emplace_back(i + 1, 1);
        }
        vector<int> answer;
        for (const auto& query : queries) {
            int u = query[0];
            int v = query[1];
            graph[u].emplace_back(v, 1);
            answer.push_back(dijkstra(graph, n));
        }

        return answer;
    }

private:
    int dijkstra(const vector<vector<pair<int, int>>>& graph, int n) {
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        dist[0] = 0;
        pq.emplace(0, 0);

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u])
                continue;

            for (const auto& edge : graph[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.emplace(dist[v], v);
                }
            }
        }
        return dist[n - 1];
    }
};