class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        for (int i = 1; i < n; ++i) {
            stones[i] += stones[i - 1];
        }
        
        int res = stones.back();
        for (int i = n - 2; i > 0; --i) {
            res = max(res, stones[i] - res);
        }
        
        return res;
    }
};