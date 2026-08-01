class Solution {
    int memo[21][21];
    
    int maxDiff(vector<int>& nums, int i, int j) {
        if (i == j) return nums[i];
        if (memo[i][j] != -1) return memo[i][j];
        
        int takeLeft = nums[i] - maxDiff(nums, i + 1, j);
        int takeRight = nums[j] - maxDiff(nums, i, j - 1);
        
        return memo[i][j] = max(takeLeft, takeRight);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
    memset(memo, -1, sizeof(memo));
    return maxDiff(nums, 0, nums.size() - 1) >= 0;
    }
};