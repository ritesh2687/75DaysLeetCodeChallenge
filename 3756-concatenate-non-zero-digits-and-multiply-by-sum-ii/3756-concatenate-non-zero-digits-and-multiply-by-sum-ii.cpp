class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        long long MOD = 1e9 + 7;
        
        // 1. Extract non-zero digits and their original indices
        vector<int> digit;
        vector<int> pos;
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                digit.push_back(s[i] - '0');
                pos.push_back(i);
            }
        }
        
        int m = digit.size();
        if (m == 0) {
            return vector<int>(queries.size(), 0);
        }
        
        // 2. Precompute powers of 10 modulo 10^9 + 7
        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }
        
        // 3. Compute prefix values for the number and prefix sums for the digits
        vector<long long> prefNum(m + 1, 0);
        vector<long long> prefSum(m + 1, 0);
        for (int i = 0; i < m; i++) {
            prefNum[i + 1] = (prefNum[i] * 10 + digit[i]) % MOD;
            prefSum[i + 1] = prefSum[i] + digit[i];
        }
        
        // 4. Map original string indices to compressed digit indices
        vector<int> firstRight(n, -1);
        int p = 0;
        for (int i = 0; i < n; i++) {
            while (p < m && pos[p] < i) {
                p++;
            }
            if (p < m) {
                firstRight[i] = p;
            }
        }
        
        vector<int> lastLeft(n, -1);
        p = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (p >= 0 && pos[p] > i) {
                p--;
            }
            if (p >= 0) {
                lastLeft[i] = p;
            }
        }
        
        // 5. Process queries
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            int L = firstRight[l];
            int R = lastLeft[r];
            
            // If no non-zero digits lie within [l, r]
            if (L == -1 || R == -1 || L > R) {
                ans.push_back(0);
                continue;
            }
            
            int len = R - L + 1;
            // Extract substring number value modulo MOD
            long long x = (prefNum[R + 1] - (prefNum[L] * pow10[len]) % MOD + MOD) % MOD;
            // Sum of digits does not need modulo because max sum is 9 * 10^5 (fits in long long easily)
            long long sum = prefSum[R + 1] - prefSum[L];
            
            ans.push_back((x * (sum % MOD)) % MOD);
        }
        
        return ans;
    }
};