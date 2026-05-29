class Solution {
public:
    int maxProduct(vector<int>& nums) {
    int maxp=INT_MIN;
    int curr=1;
    int n=nums.size();

    for(int i=0;i<n;i++)
    {
        curr*=nums[i];
        maxp=max(curr,maxp);
        if(curr==0){curr=1;}

    }   
    curr=1;
    for(int i=n-1;i>=0;i--)
    {
        curr*=nums[i];
        maxp=max(maxp,curr);
        if(curr==0){curr=1;}
    }  
    return maxp;
   }
};