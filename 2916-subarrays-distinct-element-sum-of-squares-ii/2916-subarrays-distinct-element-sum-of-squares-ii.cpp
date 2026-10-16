#include <vector>
#include <unordered_map>

class Solution {
    int n;
    std::vector<long long> tree;
    std::vector<long long> sum_tree;
    std::vector<long long> lazy;
    const int MOD = 1000000007;

    void push(int node, int l, int r) {
        if (lazy[node] != 0) {
            int mid = (l + r) / 2;
            long long v = lazy[node];

            // Left child
            long long lenL = (mid - l + 1);
            tree[2 * node] = (tree[2 * node] + 2 * v * sum_tree[2 * node] % MOD + lenL * (v * v % MOD) % MOD) % MOD;
            sum_tree[2 * node] = (sum_tree[2 * node] + lenL * v % MOD) % MOD;
            lazy[2 * node] = (lazy[2 * node] + v) % MOD;

            // Right child
            long long lenR = (r - mid);
            tree[2 * node + 1] = (tree[2 * node + 1] + 2 * v * sum_tree[2 * node + 1] % MOD + lenR * (v * v % MOD) % MOD) % MOD;
            sum_tree[2 * node + 1] = (sum_tree[2 * node + 1] + lenR * v % MOD) % MOD;
            lazy[2 * node + 1] = (lazy[2 * node + 1] + v) % MOD;

            lazy[node] = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr, long long v) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            long long len = (r - l + 1);
            tree[node] = (tree[node] + 2 * v * sum_tree[node] % MOD + len * (v * v % MOD) % MOD) % MOD;
            sum_tree[node] = (sum_tree[node] + len * v % MOD) % MOD;
            lazy[node] = (lazy[node] + v) % MOD;
            return;
        }
        push(node, l, r);
        int mid = (l + r) / 2;
        update(2 * node, l, mid, ql, qr, v);
        update(2 * node + 1, mid + 1, r, ql, qr, v);
        
        tree[node] = (tree[2 * node] + tree[2 * node + 1]) % MOD;
        sum_tree[node] = (sum_tree[2 * node] + sum_tree[2 * node + 1]) % MOD;
    }

    long long query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return tree[node];
        push(node, l, r);
        int mid = (l + r) / 2;
        return (query(2 * node, l, mid, ql, qr) + query(2 * node + 1, mid + 1, r, ql, qr)) % MOD;
    }

public:
    int sumCounts(std::vector<int>& arr) {
        n = arr.size();
        tree.assign(4 * n, 0);
        sum_tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        
        std::unordered_map<int, int> last_pos;
        long long total_sum = 0;
        long long current_sum = 0;

        for (int j = 0; j < n; ++j) {
            int prev = last_pos.count(arr[j]) ? last_pos[arr[j]] + 1 : 0;
            last_pos[arr[j]] = j;

            update(1, 0, n - 1, prev, j, 1);
            current_sum = query(1, 0, n - 1, 0, j);
            total_sum = (total_sum + current_sum) % MOD;
        }

        return total_sum;
    }
};