class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> dp(k, 0);
        
        for (int num : nums) {
            vector<long long> next_dp(k, 0);
            long long current = num % k;
            
            next_dp[current] += 1;
            
            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    next_dp[(r * current) % k] += dp[r];
                }
            }
            
            for (int r = 0; r < k; ++r) {
                result[r] += next_dp[r];
                dp[r] = next_dp[r];
            }
        }
        
        return result;
    }
};