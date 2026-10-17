class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l=0;
      
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                int temp = nums[l];
                nums[l]=nums[i];
                nums[i]=temp;
                l++;

            }  
        }
    }
};