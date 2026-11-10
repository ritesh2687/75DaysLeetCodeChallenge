class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n + 1, 1e18);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int k = 1; k <= 3; ++k) {
                if (i - k >= 0) {
                    dp[i] = min(dp[i], dp[i - k] + costs[i - 1] + 1LL * k * k);
                }
            }
        }

        return dp[n];
    }
};