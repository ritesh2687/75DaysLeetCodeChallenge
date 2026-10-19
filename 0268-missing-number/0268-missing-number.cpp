class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int xor1 = 0, xor2 = 0;
        // int M = nums.size();
        // int n = nums.size();
        // for (int i = 0; i < n; i++) {
        //     xor2 = xor2 ^ nums[i];
        //     xor1 = xor1 ^ (i + 1);
        // }
        // //xor1 = xor1 ^ N;
        // return xor1 ^ xor2;

        int n=nums.size();
        int s=n*(n+1)/2;
        for(int i=n-1;i>=0;i--){
            s=s-nums[i];
        }

        return s;









    }
};