class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> s = nums;
        sort(s.begin(), s.end());
        long long totalSum = 0;

        for (int k = 1; k * k <= n; ++k) {
            if (n % k == 0) {
                totalSum += check(nums, s, k);
                if (k * k != n) {
                    totalSum += check(nums, s, n / k);
                }
            }
        }
        return totalSum;
    }

private:
    long long check(const vector<int>& nums, const vector<int>& s, int k) {
        int n = nums.size();
        for (int i = 0; i < n; i += k) {
            int drops = 0;
            int drop_idx = -1;
            
            for (int j = 0; j < k - 1; ++j) {
                if (nums[i + j] > nums[i + j + 1]) {
                    drops++;
                    drop_idx = j;
                }
            }

            if (drops > 1) return 0;
            if (drops == 1 && nums[i + k - 1] > nums[i]) return 0;

            int min_idx = (drops == 0) ? 0 : (drop_idx + 1);

            for (int j = 0; j < k; ++j) {
                if (nums[i + (min_idx + j) % k] != s[i + j]) {
                    return 0;
                }
            }
        }
        return k;
    }
};