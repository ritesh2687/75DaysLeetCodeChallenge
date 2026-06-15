class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
     return generate(nums.size(),nums);
    }

    vector<vector<int>> generate(int n, vector<int>& nums){

        if(n==0){
            return{{}};
        }
        int num =nums[n-1];
        vector<vector<int>> faith=generate(n-1,nums);
        vector<vector<int>> answer=faith;
        for(vector<int> temp : faith){
            temp.push_back(num);
            answer.push_back(temp);
        }
        return answer;
    }
};