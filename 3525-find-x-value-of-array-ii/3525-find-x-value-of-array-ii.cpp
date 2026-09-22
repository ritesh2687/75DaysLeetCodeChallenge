class Solution {
    vector<int> cnt;
    vector<int> total_prod;

    void build(int node, int l, int r, const vector<int>& nums, int k) {
        if (l == r) {
            total_prod[node] = nums[l] % k;
            cnt[node * k + (nums[l] % k)] = 1;
            return;
        }
        int mid = l + (r - l) / 2;
        int left_node = 2 * node;
        int right_node = 2 * node + 1;
        
        build(left_node, l, mid, nums, k);
        build(right_node, mid + 1, r, nums, k);
        
        total_prod[node] = (total_prod[left_node] * total_prod[right_node]) % k;
        
        int base = node * k;
        int l_base = left_node * k;
        int r_base = right_node * k;
        
        for (int i = 0; i < k; ++i) {
            cnt[base + i] = cnt[l_base + i];
        }
        for (int i = 0; i < k; ++i) {
            if (cnt[r_base + i] > 0) {
                cnt[base + (total_prod[left_node] * i) % k] += cnt[r_base + i];
            }
        }
    }

    void update(int node, int l, int r, int idx, int val, int k) {
        if (l == r) {
            total_prod[node] = val % k;
            int base = node * k;
            fill(cnt.begin() + base, cnt.begin() + base + k, 0);
            cnt[base + (val % k)] = 1;
            return;
        }
        int mid = l + (r - l) / 2;
        int left_node = 2 * node;
        int right_node = 2 * node + 1;
        
        if (idx <= mid) {
            update(left_node, l, mid, idx, val, k);
        } else {
            update(right_node, mid + 1, r, idx, val, k);
        }
        
        total_prod[node] = (total_prod[left_node] * total_prod[right_node]) % k;
        
        int base = node * k;
        int l_base = left_node * k;
        int r_base = right_node * k;
        
        fill(cnt.begin() + base, cnt.begin() + base + k, 0);
        for (int i = 0; i < k; ++i) {
            cnt[base + i] += cnt[l_base + i];
            if (cnt[r_base + i] > 0) {
                cnt[base + (total_prod[left_node] * i) % k] += cnt[r_base + i];
            }
        }
    }

    int query(int node, int l, int r, int ql, int qr, int k, int& current_prod, int x) {
        if (ql <= l && r <= qr) {
            int count = 0;
            int base = node * k;
            for (int i = 0; i < k; ++i) {
                if ((current_prod * i) % k == x) {
                    count += cnt[base + i];
                }
            }
            current_prod = (current_prod * total_prod[node]) % k;
            return count;
        }
        
        int mid = l + (r - l) / 2;
        int ans = 0;
        
        if (ql <= mid) {
            ans += query(2 * node, l, mid, ql, qr, k, current_prod, x);
        }
        if (qr > mid) {
            ans += query(2 * node + 1, mid + 1, r, ql, qr, k, current_prod, x);
        }
        
        return ans;
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        cnt.assign(4 * n * k, 0);
        total_prod.assign(4 * n, 1);
        
        build(1, 0, n - 1, nums, k);
        
        vector<int> result;
        result.reserve(queries.size());
        
        for (const auto& q : queries) {
            int idx = q[0], val = q[1], start = q[2], x = q[3];
            update(1, 0, n - 1, idx, val, k);
            int current_prod = 1;
            result.push_back(query(1, 0, n - 1, start, n - 1, k, current_prod, x));
        }
        
        return result;
    }
};