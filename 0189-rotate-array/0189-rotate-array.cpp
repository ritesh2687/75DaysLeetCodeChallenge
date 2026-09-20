class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      int n=nums.size();
      int t=k%n;

    reverse(nums.begin(),nums.end());
    reverse(nums.begin(),nums.begin()+t);
    reverse(nums.begin()+t,nums.end());

        
        
    }
};