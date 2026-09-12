class Solution {
public:
    int pivotIndex(vector<int>& nums) {

    int total=accumulate(nums.begin(),nums.end(),0);
    int l=0;
    for(int i=0;i<nums.size();i++){
        if(l== total-nums[i]-l){
            return i;
        }
        l+=nums[i];
    }
    return -1;
    }
};