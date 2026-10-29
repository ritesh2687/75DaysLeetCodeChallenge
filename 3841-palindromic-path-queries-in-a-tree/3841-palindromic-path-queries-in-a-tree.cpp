class Solution {
    int n;
    vector<vector<int>> adj;
    vector<int> tin, tout, tour;
    int timer;
    vector<int> head, heavy, parent, depth, pos;
    vector<int> tree;
    string str;

    int dfs_sz(int u, int p, int d) {
        int sz = 1, max_c_sz = 0;
        parent[u] = p;
        depth[u] = d;
        for (int v : adj[u]) {
            if (v != p) {
                int c_sz = dfs_sz(v, u, d + 1);
                sz += c_sz;
                if (c_sz > max_c_sz) {
                    max_c_sz = c_sz;
                    heavy[u] = v;
                }
            }
        }
        return sz;
    }

    void dfs_hld(int u, int h) {
        head[u] = h;
        pos[u] = ++timer;
        tour[timer] = u;
        if (heavy[u] != -1) {
            dfs_hld(heavy[u], h);
        }
        for (int v : adj[u]) {
            if (v != parent[u] && v != heavy[u]) {
                dfs_hld(v, v);
            }
        }
    }

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = (1 << (str[tour[start]] - 'a'));
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] ^ tree[2 * node + 1];
    }

    void update_tree(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) {
            update_tree(2 * node, start, mid, idx, val);
        } else {
            update_tree(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = tree[2 * node] ^ tree[2 * node + 1];
    }

    int query_tree(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return query_tree(2 * node, start, mid, l, r) ^ query_tree(2 * node + 1, mid + 1, end, l, r);
    }

    int query_path(int u, int v) {
        int res = 0;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) {
                res ^= query_tree(1, 1, n, pos[head[u]], pos[u]);
                u = parent[head[u]];
            } else {
                res ^= query_tree(1, 1, n, pos[head[v]], pos[v]);
                v = parent[head[v]];
            }
        }
        if (depth[u] > depth[v]) {
            res ^= query_tree(1, 1, n, pos[v], pos[u]);
        } else {
            res ^= query_tree(1, 1, n, pos[u], pos[v]);
        }
        return res;
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->n = n;
        this->str = s;
        adj.assign(n, vector<int>());
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        parent.assign(n, 0);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        tour.assign(n + 1, 0);
        tree.assign(4 * (n + 1), 0);

        timer = 0;
        dfs_sz(0, -1, 0);
        dfs_hld(0, 0);
        build(1, 1, n);

        vector<bool> answer;
        for (auto& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;
            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;
                str[u] = c;
                update_tree(1, 1, n, pos[u], (1 << (c - 'a')));
            } else {
                int u, v;
                ss >> u >> v;
                int mask = query_path(u, v);
                if ((mask & (mask - 1)) == 0) {
                    answer.push_back(true);
                } else {
                    answer.push_back(false);
                }
            }
        }
        return answer;
    }
};