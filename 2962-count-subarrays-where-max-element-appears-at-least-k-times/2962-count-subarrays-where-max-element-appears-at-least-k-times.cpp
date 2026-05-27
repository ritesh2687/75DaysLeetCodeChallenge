class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
    int maxi=0;
    for(int x:nums) maxi=max(maxi,x);
    int left=0,right=0,count=0,n=nums.size();
    long long ans=0;
    while(right<n){
        if(nums[right]==maxi)count++;
        while(count>=k){
            ans+=(n-right);
            if(nums[left]==maxi) count--;
            left++;
        }
        right++;
    }
    return ans;
    }
};