class Solution {
public:
    bool check(vector<int>& nums) {
        int s = nums.size();
        int count = 1;
        bool ans=1;
        for (int i = 0; i < s - 1; i++) {
            if (nums[i] <= nums[i + 1]) {
                continue;
            } else {
                count--;
            }
        }
        if (count == 0) {
            if (nums[s - 1] <= nums[0]) {
                ans=1;
            }
            else ans=0;
        } else if (count > 0)
            {ans=1;}
        else {
            {ans=0;}
        }
        return ans;
    }
};