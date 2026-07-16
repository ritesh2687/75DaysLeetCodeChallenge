class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen = 0 , count = 0, left = 0, n = nums.size();
        for (int right = 0;right<n;right++) {
            if (nums[right] == 0) count++;
            while (count > k) {
                if (nums[left] == 0) count--;
                left++;
            }
            maxLen = max(maxLen,right-left+1);
        }
        return maxLen;
    }
};