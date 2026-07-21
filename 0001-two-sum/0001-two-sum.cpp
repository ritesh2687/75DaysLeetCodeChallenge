class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        int i = 0;
        while (i < len) {
            int j = i+1;
            while (j < len) {
                if (nums[i] + nums[j] == target) {
                   return {i,j};
                }
                j++;
            }
            i++;
        }
    return {};
    }
};