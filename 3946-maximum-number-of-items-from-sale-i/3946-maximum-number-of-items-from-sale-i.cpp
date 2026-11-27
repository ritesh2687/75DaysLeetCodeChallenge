class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int max_factor = 0;
        for (const auto& item : items) {
            max_factor = max(max_factor, item[0]);
        }

        vector<int> freq(max_factor + 1, 0);
        for (const auto& item : items) {
            freq[item[0]]++;
        }

        vector<int> free_gain(max_factor + 1, 0);
        for (int f = 1; f <= max_factor; ++f) {
            if (freq[f] == 0) continue;
            int total_divisible = 0;
            for (int m = f; m <= max_factor; m += f) {
                total_divisible += freq[m];
            }
            free_gain[f] = total_divisible - 1;
        }

        vector<int> dp(budget + 1, 0);
        for (const auto& item : items) {
            int f = item[0];
            int p = item[1];
            if (p > budget) continue;

            int first_copy_value = 1 + free_gain[f];
            vector<int> next_dp = dp;

            for (int b = p; b <= budget; ++b) {
                next_dp[b] = max(next_dp[b], dp[b - p] + first_copy_value);
            }

            for (int b = 2 * p; b <= budget; ++b) {
                next_dp[b] = max(next_dp[b], next_dp[b - p] + 1);
            }

            dp = move(next_dp);
        }

        return *max_element(dp.begin(), dp.end());
    }
};