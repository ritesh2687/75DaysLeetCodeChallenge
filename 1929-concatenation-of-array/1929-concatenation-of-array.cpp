class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
    vector<int> ans;
    for(int n:nums){
        ans.push_back(n);
    }
      for(int n:nums){
        ans.push_back(n);
    }
    return ans;
    }
};