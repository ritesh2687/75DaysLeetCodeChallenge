class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
    vector<int> ans=nums;
    for(int n:nums){
        ans.push_back(n);
    }
     
    return ans;
    }
};