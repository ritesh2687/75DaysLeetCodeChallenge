class Solution {
public:
    bool isGood(vector<int>& nums) {
        int s = nums.size();
        int count = 0;
        sort(nums.begin(), nums.end());
        if (s > 2) {
            for (int i = 1; i <= s - 2; i++) {
                if (nums[i]-nums[i-1] == 1) {
                    count = 1;
                    continue;
                } else
                    count = 0;
                break;
            }
            if (count == 1 && nums[s - 1] == nums[s - 2]) {
                count = 1;
            } else {
                count = 0;
            }
        } else if ( s==2 && nums[s - 2] == nums[s - 1] && nums[1]<s) {
            return true;
        } else
            count = 0;
        return count;
    }
};