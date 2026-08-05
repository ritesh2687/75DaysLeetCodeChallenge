class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, unordered_set<int>& suspicious) {
        suspicious.insert(u);
        for (int v : adj[u]) {
            if (suspicious.find(v) == suspicious.end()) {
                dfs(v, adj, suspicious);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (const auto& inv : invocations) {
            adj[inv[0]].push_back(inv[1]);
        }

        unordered_set<int> suspicious;
        dfs(k, adj, suspicious);

        for (const auto& inv : invocations) {
            int u = inv[0];
            int v = inv[1];
            if (suspicious.find(u) == suspicious.end() && suspicious.find(v) != suspicious.end()) {
                vector<int> allMethods(n);
                for (int i = 0; i < n; i++) allMethods[i] = i;
                return allMethods;
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (suspicious.find(i) == suspicious.end()) {
                result.push_back(i);
            }
        }

        return result;
    }
};