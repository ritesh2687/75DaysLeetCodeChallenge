class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
   vector<pair<int, int>> sorted_nodes(n);
        for (int i = 0; i < n; ++i) {
            sorted_nodes[i] = {nums[i], i};
        }
        sort(sorted_nodes.begin(), sorted_nodes.end());

        vector<int> pos_in_sorted(n);
        for (int i = 0; i < n; ++i) {
            pos_in_sorted[sorted_nodes[i].second] = i;
        }

        int max_levels = log2(n) + 2;
        vector<vector<int>> dp(n, vector<int>(max_levels));

        for (int i = 0; i < n; ++i) {
            auto it = upper_bound(sorted_nodes.begin(), sorted_nodes.end(), 
                                  make_pair(sorted_nodes[i].first + maxDiff, n + 1));
            int target_idx = distance(sorted_nodes.begin(), it) - 1;
            dp[i][0] = max(i, target_idx);
        }

        for (int k = 1; k < max_levels; ++k) {
            for (int i = 0; i < n; ++i) {
                dp[i][k] = dp[dp[i][k-1]][k-1];
            }
        }

        vector<int> ans;
        for (auto& q : queries) {
            int u = pos_in_sorted[q[0]];
            int v = pos_in_sorted[q[1]];

            if (u == v) {
                ans.push_back(0);
                continue;
            }
            if (u > v) swap(u, v);

            int steps = 0;
            for (int k = max_levels - 1; k >= 0; --k) {
                if (dp[u][k] < v && dp[u][k] > u) {
                    steps += (1 << k);
                    u = dp[u][k];
                }
            }

            if (dp[u][0] >= v) {
                ans.push_back(steps + 1);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};