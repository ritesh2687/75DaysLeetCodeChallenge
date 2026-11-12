class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        if(nums.empty())return 0;
        int i_p=1;
        int d_p=1;
        int m_p=1;
        int l=nums.size()-1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                i_p++;
                d_p=1;
            }
            else if(nums[i-1]>nums[i]){
                d_p++;
                i_p=1;
            }

            else{
                d_p=1;
                i_p=1;
            }
            m_p=max({m_p,i_p,d_p});
        }
        return m_p;
    }
};