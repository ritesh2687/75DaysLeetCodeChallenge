class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
        vector<vector<long long>> dist(n, vector<long long>(k + 1, LLONG_MAX));

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, count] = pq.top();
            pq.pop();

            if (d > dist[u][count]) continue;
            if (u == n - 1) return d;

            for (const auto& [v, weight] : adj[u]) {
                int next_count = (labels[u] == labels[v]) ? count + 1 : 1;
                if (next_count <= k) {
                    if (d + weight < dist[v][next_count]) {
                        dist[v][next_count] = d + weight;
                        pq.push({dist[v][next_count], v, next_count});
                    }
                }
            }
        }

        return -1;
    }
};