class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        const unsigned long long B1 = 1315423911ULL;
        const unsigned long long B2 = 1000003ULL;
        const unsigned long long MOD2 = 1000000007ULL;

        vector<unsigned long long> p1(n + 1, 1ULL), p2(n + 1, 1ULL);
        vector<unsigned long long> h1(n + 1, 0ULL), h2(n + 1, 0ULL);

        for (int i = 0; i < n; ++i) {
            unsigned long long val = static_cast<unsigned long long>(nums[i]) + 1ULL;
            p1[i + 1] = p1[i] * B1;
            p2[i + 1] = (p2[i] * B2) % MOD2;
            h1[i + 1] = h1[i] * B1 + val;
            h2[i + 1] = (h2[i] * B2 + val) % MOD2;
        }

        auto getHash = [&](int l, int r) -> unsigned long long {
            unsigned long long x1 = h1[r + 1] - h1[l] * p1[r - l + 1];
            unsigned long long x2 = (h2[r + 1] + MOD2 - (h2[l] * p2[r - l + 1]) % MOD2) % MOD2;
            return (x1 << 32) ^ x2;
        };

        auto hasUnique = [&](int len) -> bool {
            unordered_map<unsigned long long, int> freq;
            freq.reserve(static_cast<size_t>(n - len + 1) * 2);
            for (int i = 0; i + len <= n; ++i) {
                unsigned long long key = getHash(i, i + len - 1);
                ++freq[key];
            }
            for (const auto& kv : freq) {
                if (kv.second == 1) return true;
            }
            return false;
        };

        int lo = 1, hi = n, ans = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (hasUnique(mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};