class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int l = nums.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int min_i = 0;
        int max_i = 0;

        for (int i = 0; i < l; i++) {
            if (nums[i] < mini) {
                mini = nums[i];
                min_i = i;
            }
            if (nums[i] > maxi) {
                maxi = nums[i];
                max_i = i;
            }
        }

        int left = min(min_i, max_i);
        int right = max(min_i, max_i);

        int front = right + 1;
        int back = l - left;
        int both = (left + 1) + (l - right);

        return min({front, back, both});
    }
};