class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<long long> windowCost(n - x + 1, 0);

        multiset<long long> low, high;
        long long sumLow = 0, sumHigh = 0;

        auto balance = [&]() {
            while (low.size() > high.size() + 1) {
                auto it = prev(low.end());
                sumLow -= *it;
                sumHigh += *it;
                high.insert(*it);
                low.erase(it);
            }
            while (low.size() < high.size()) {
                auto it = high.begin();
                sumHigh -= *it;
                sumLow += *it;
                low.insert(*it);
                high.erase(it);
            }
        };

        auto add = [&](long long val) {
            if (low.empty() || val <= *low.rbegin()) {
                low.insert(val);
                sumLow += val;
            } else {
                high.insert(val);
                sumHigh += val;
            }
            balance();
        };

        auto remove = [&](long long val) {
            auto itLow = low.find(val);
            if (itLow != low.end()) {
                sumLow -= val;
                low.erase(itLow);
            } else {
                auto itHigh = high.find(val);
                if (itHigh != high.end()) {
                    sumHigh -= val;
                    high.erase(itHigh);
                }
            }
            balance();
        };

        for (int i = 0; i < x; ++i) {
            add(nums[i]);
        }
        long long median = *low.rbegin();
        windowCost[0] = (low.size() * median - sumLow) + (sumHigh - high.size() * median);

        for (int i = 1; i <= n - x; ++i) {
            remove(nums[i - 1]);
            add(nums[i + x - 1]);
            median = *low.rbegin();
            windowCost[i] = (low.size() * median - sumLow) + (sumHigh - high.size() * median);
        }

        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 1e18));

        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 0;
        }

        for (int j = 1; j <= k; ++j) {
            for (int i = j * x; i <= n; ++i) {
                dp[i][j] = dp[i - 1][j];
                long long cost = windowCost[i - x];
                dp[i][j] = min(dp[i][j], dp[i - x][j - 1] + cost);
            }
        }

        return dp[n][k];
    }
};