class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.length();
        vector<vector<int>> cost(n, vector<int>(n, 1e9));
        
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len <= n; ++i) {
                int j = i + len - 1;
                for (int d = 1; d < len; ++d) {
                    if (len % d == 0) {
                        int curr_changes = 0;
                        for (int rem = 0; rem < d; ++rem) {
                            int l = i + rem;
                            int r = j - (d - 1 - rem);
                            while (l < r) {
                                if (s[l] != s[r]) {
                                    curr_changes++;
                                }
                                l += d;
                                r -= d;
                            }
                        }
                        cost[i][j] = min(cost[i][j], curr_changes);
                    }
                }
            }
        }
        
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1e9));
        dp[0][0] = 0;
        
        for (int i = 1; i <= n; ++i) {
            for (int parts = 1; parts <= k; ++parts) {
                for (int prev = 0; prev < i - 1; ++prev) {
                    if (dp[prev][parts - 1] != 1e9) {
                        dp[i][parts] = min(dp[i][parts], dp[prev][parts - 1] + cost[prev][i - 1]);
                    }
                }
            }
        }
        
        return dp[n][k];
    }
};