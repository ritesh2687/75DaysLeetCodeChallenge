class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        vector<pair<long long,int>> stack;
        stack.push_back({0,-1});
        long long prefix = 0;
        int ans = INT_MAX, n = nums.size();
        for (int i = 0;i<n;i++) {
            prefix += nums[i];
            while (stack.size() > 0 && stack.back().first > prefix) {
                stack.pop_back();
            }
            long long target = prefix - k;
            int id = binarySearch(stack,target);
            if (id != -1 ) {
                ans = min(ans,i - stack[id].second);
            }
            stack.push_back({prefix,i});
        }
        return ans == INT_MAX ? -1 : ans;
    }
    int binarySearch(vector<pair<long long,int>>& nums,long long target) {
        int l =0, r = nums.size() - 1, ans = -1;
        while (l <= r) {
            int mid = l+(r-l) / 2;
            if (nums[mid].first <= target) {
                ans = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return ans;
    }
};