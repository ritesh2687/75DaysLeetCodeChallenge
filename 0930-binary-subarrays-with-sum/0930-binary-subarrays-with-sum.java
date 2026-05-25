class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        return find(nums,goal)-find(nums,goal-1);
    }

    int find(int[] nums,int goal){
        int count=0,sum=0;
        int left=0,right=0;
        while(right<nums.length){
            sum+=nums[right];
            while(left<=right && sum>goal){
                sum-= nums[left];left++;

            }
            count+=(right-left+1);
            right++;
        }
        return count;
    }
}