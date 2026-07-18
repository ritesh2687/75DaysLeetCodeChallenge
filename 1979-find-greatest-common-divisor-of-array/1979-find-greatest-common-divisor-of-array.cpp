class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int ans =1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }
        

        while(maxi!=0){
            int temp=maxi;
            maxi=mini%maxi;
            mini=temp;
        }
        return mini;

    }
};