class Solution {
public:
    long long gcdSum(vector<int>& nums) {
            int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1;i<n;i++) prefix[i] = max(prefix[i-1],nums[i]);
        for (int i = 0;i<n;i++) {
            prefix[i] = __gcd(prefix[i],nums[i]);
        }
        sort(prefix.begin(),prefix.end());
        long long ans = 0;
        int l = 0 , r = n-1;
        while (l<r) {
            ans += __gcd(prefix[l],prefix[r]);
            l++; r--;
        }
        return ans;
    }
};