class Solution {
public:
    int maxi=0;
    int count=0;
    int curr=0;
    int jump(vector<int>& nums) {
      for(int i=0;i<nums.size()-1;i++){
         maxi=max(maxi,i+nums[i]);
        if(i==curr){
            count++;
            curr=maxi;
        }
      }  
      return count;
    }
};