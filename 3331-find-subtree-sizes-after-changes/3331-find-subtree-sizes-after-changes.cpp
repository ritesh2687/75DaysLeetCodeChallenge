class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; ++i) {
            adj[parent[i]].push_back(i);
        }

        vector<int> newParent = parent;
        vector<int> lastSeen(26, -1);

        auto dfs1 = [&](auto& self, int u) -> void {
            int c = s[u] - 'a';
            int prev = lastSeen[c];
            if (prev != -1) {
                newParent[u] = prev;
            }
            lastSeen[c] = u;
            for (int v : adj[u]) {
                self(self, v);
            }
            lastSeen[c] = prev;
        };

        dfs1(dfs1, 0);

        vector<vector<int>> newAdj(n);
        for (int i = 1; i < n; ++i) {
            newAdj[newParent[i]].push_back(i);
        }

        vector<int> ans(n, 1);
        auto dfs2 = [&](auto& self, int u) -> void {
            for (int v : newAdj[u]) {
                self(self, v);
                ans[u] += ans[v];
            }
        };

        dfs2(dfs2, 0);
        return ans;
    }
};