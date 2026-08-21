#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
    long long lcm(long long a, long long b) {
        return (a / std::gcd(a, b)) * b;
    }

    long long countMultiples(long long target, const vector<int>& coins) {
        int n = coins.size();
        long long total = 0;

        for (int mask = 1; mask < (1 << n); ++mask) {
            long long cur_lcm = 1;
            int bits = 0;
            
            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) {
                    bits++;
                    cur_lcm = lcm(cur_lcm, coins[i]);
                }
            }

            if (bits % 2 == 1) {
                total += target / cur_lcm;
            } else {
                total -= target / cur_lcm;
            }
        }

        return total;
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 1;
        long long min_coin = *min_element(coins.begin(), coins.end());
        long long high = min_coin * k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (countMultiples(mid, coins) >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};