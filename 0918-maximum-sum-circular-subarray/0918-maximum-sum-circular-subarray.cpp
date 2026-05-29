class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
    int n=nums.size(),curr=0,maxi=INT_MIN;
    int mini=INT_MAX,currM=0,total=0;
    for (int i=0;i<n;i++){
        curr=max(curr+nums[i],nums[i]);
        maxi=max(maxi,curr);

        total+=nums[i];
        currM=min(currM+nums[i],nums[i]);
        mini=min(mini,currM);

    }  
    return maxi < 0 ? maxi : max(maxi,total-mini); 
   }
};