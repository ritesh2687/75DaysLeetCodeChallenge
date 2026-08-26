class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int maxi = candies[0];
        for (int num : candies) {
            maxi = max(num, maxi);
            
        }
        for (int num1 : candies) {
            if (num1 + extraCandies >=maxi) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }

};