class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
        int right = 1e6;
        int ans = -1;
        while(left<=right){
            int mid = (left+right) /2;
            if (valid(nums , mid, threshold)){
                ans = mid;
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return ans;

        }
        bool valid(vector<int>& nums,int div, int threshold){
            int total = 0, n = nums.size();
            for(int i = 0;i<n;i++){
                total += (nums[i] /div);
                if (nums[i]%div != 0) total++;
                if(total > threshold) return false;
            }
            return total = threshold;
        
    }
};