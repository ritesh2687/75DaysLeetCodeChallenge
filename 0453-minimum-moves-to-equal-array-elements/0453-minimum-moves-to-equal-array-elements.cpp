class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minNum = nums[0];
        long long sum = 0;
        
        for (int num : nums) {
            minNum = min(minNum, num);
            sum += num;
        }
        
        return sum - (long long)minNum * nums.size();
    }
};