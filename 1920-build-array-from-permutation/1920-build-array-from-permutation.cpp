class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;

        for(int i=0;i<n;i++){
            int a=nums[i];
            ans.push_back(nums[a]);
        }

        return ans;
        
    }
};