class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> count(30, 0);
        for (int x : nums) {
            for (int i = 0; i < 30; ++i) {
                if ((x >> i) & 1) {
                    count[i]++;
                }
            }
        }
        
        long long ans = 0;
        long long mod = 1e9 + 7;
        
        for (int step = 0; step < k; ++step) {
            long long curr = 0;
            for (int i = 0; i < 30; ++i) {
                if (count[i] > 0) {
                    curr |= (1 << i);
                    count[i]--;
                }
            }
            ans = (ans + curr * curr) % mod;
        }
        
        return ans;
    }
};