class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int MOD = 1e9 + 7;

        vector<vector<pair<int, int>>> rightTarget(m, vector<pair<int, int>>(n));
        vector<vector<pair<int, int>>> downTarget(m, vector<pair<int, int>>(n));

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (j + 1 < n) {
                    if (grid[i][j + 1] == 0) {
                        rightTarget[i][j] = {i, j + 1};
                    } else {
                        rightTarget[i][j] = downTarget[i][j + 1];
                    }
                } else {
                    rightTarget[i][j] = {-1, -1};
                }

                if (i + 1 < m) {
                    if (grid[i + 1][j] == 0) {
                        downTarget[i][j] = {i + 1, j};
                    } else {
                        downTarget[i][j] = rightTarget[i + 1][j];
                    }
                } else {
                    downTarget[i][j] = {-1, -1};
                }
            }
        }

        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] == 0) continue;

                auto [r_next_i, r_next_j] = rightTarget[i][j];
                if (r_next_i != -1) {
                    dp[r_next_i][r_next_j] = (dp[r_next_i][r_next_j] + dp[i][j]) % MOD;
                }

                auto [d_next_i, d_next_j] = downTarget[i][j];
                if (d_next_i != -1) {
                    dp[d_next_i][d_next_j] = (dp[d_next_i][d_next_j] + dp[i][j]) % MOD;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};