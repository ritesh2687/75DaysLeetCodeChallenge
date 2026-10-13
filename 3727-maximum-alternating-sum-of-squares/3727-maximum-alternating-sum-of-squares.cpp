class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            long long val = nums[i];
            a[i] = val * val;
        }
        sort(a.begin(), a.end());
        long long ans = 0;
        int mid = n / 2;
        for (int i = 0; i < mid; ++i) {
            ans -= a[i];
        }
        for (int i = mid; i < n; ++i) {
            ans += a[i];
        }
        return ans;
    }
};