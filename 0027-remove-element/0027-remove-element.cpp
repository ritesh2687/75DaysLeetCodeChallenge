class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    int s=nums.size();
    vector<int> ans;
    for(int n:nums){
        if(val!=n) ans.push_back(n); 
    }
    nums=ans;
    return nums.size();
    }

};