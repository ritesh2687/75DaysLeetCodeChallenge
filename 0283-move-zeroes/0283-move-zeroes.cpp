class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        
        int l=0;
        int r=1;
        while(r<nums.size()){
            if(nums[l]==0 && nums[r]!=0){
                nums[l]=nums[r];
                nums[r]=0;
                l++;
                r++;

            }
            else if(nums[l]==0 && nums[r]==0)
            {
                r++;
            }
            else {
                r++;
                l++;
            }
        }
    }
};