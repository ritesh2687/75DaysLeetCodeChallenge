class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());
        int min =0;

        for(int num:nums){
        if(num==k && min==0){min++; continue;}

        if(num/k>=1 && min==0){
                return k;
        }
        if(num%k==0 && num==(min+1) *k && min>0){
            min++;
            continue;

        }
        if(num%k!=0 && min==0 && num>k)return k;
        }

        return (min+1)*k; 






    //     sort(nums.begin(), nums.end());
    //     int target = k;
        
    //     for (int num : nums) {
    //         if (num == target) {
    //             target += k;
    //         }
    //     }
        
    //     return target;

      
    }







};