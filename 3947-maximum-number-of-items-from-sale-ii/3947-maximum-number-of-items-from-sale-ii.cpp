class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int maxFactor = 0;
        for (const auto& item : items) {
            maxFactor = max(maxFactor, item[0]);
        }

        vector<int> freq(maxFactor + 1, 0);
        for (const auto& item : items) {
            freq[item[0]]++;
        }

        vector<int> multCount(maxFactor + 1, 0);
        for (int d = 1; d <= maxFactor; ++d) {
            for (int m = d; m <= maxFactor; m += d) {
                multCount[d] += freq[m];
            }
        }

        vector<vector<int>> sortedItems = items;
        sort(sortedItems.begin(), sortedItems.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        long long totalItems = 0;
        long long remBudget = budget;
        long long cheapestPrice = sortedItems.empty() ? 0 : sortedItems[0][1];

        for (const auto& item : sortedItems) {
            long long f = item[0];
            long long p = item[1];
            long long gain = multCount[f] - 1;

            if (gain > 0 && p < 2 * cheapestPrice && remBudget >= p) {
                long long buyCount = min(gain, remBudget / p);
                totalItems += buyCount * 2;
                remBudget -= buyCount * p;
            }
        }

        if (remBudget > 0 && cheapestPrice > 0) {
            totalItems += remBudget / cheapestPrice;
        }

        return static_cast<int>(totalItems);
    }
};