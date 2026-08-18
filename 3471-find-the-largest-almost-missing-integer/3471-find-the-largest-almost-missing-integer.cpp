class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> count;
        
        for (int i = 0; i <= n - k; ++i) {
            unordered_set<int> unique_elements;
            for (int j = i; j < i + k; ++j) {
                unique_elements.insert(nums[j]);
            }
            for (int x : unique_elements) {
                count[x]++;
            }
        }
        
        int ans = -1;
        for (auto const& [val, freq] : count) {
            if (freq == 1) {
                ans = max(ans, val);
            }
        }
        
        return ans;
    }
};