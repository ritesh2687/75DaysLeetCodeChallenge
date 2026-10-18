class Solution {
    long long mod = 1000000007;
    vector<vector<long long>> table;

    long long comb(int n, int k) {
        if (k == 0 || k == n) return 1;
        if (table[n][k] != -1) return table[n][k];
        return table[n][k] = (comb(n - 1, k - 1) + comb(n - 1, k)) % mod;
    }

    long long dfs(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 1;
        
        vector<int> left, right;
        int root = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] < root) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
        
        long long leftWays = dfs(left);
        long long rightWays = dfs(right);
        
        long long ways = comb(n - 1, left.size());
        ways = (ways * leftWays) % mod;
        ways = (ways * rightWays) % mod;
        return ways;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        table = vector<vector<long long>>(n + 1, vector<long long>(n + 1, -1));
        return (dfs(nums) - 1 + mod) % mod;
    }
};