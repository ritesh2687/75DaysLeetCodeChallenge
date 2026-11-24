class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int ans = 0;

        int maxVal = 0;
        long long totalLcm = 1;
        for (int x : nums) {
            maxVal = max(maxVal, x);
            totalLcm = lcm(totalLcm, static_cast<long long>(x));
        }
        long long maxProdBound = totalLcm * maxVal;

        for (int i = 0; i < n; ++i) {
            long long prod = 1;
            long long curGcd = 0;
            long long curLcm = 1;

            for (int j = i; j < n; ++j) {
                long long val = nums[j];
                prod *= val;
                curGcd = gcd(curGcd, val);
                curLcm = lcm(curLcm, val);

                if (prod == curGcd * curLcm) {
                    ans = max(ans, j - i + 1);
                }

                if (prod > maxProdBound) {
                    break;
                }
            }
        }

        return ans;
    }
};