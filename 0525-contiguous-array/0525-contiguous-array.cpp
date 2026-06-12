class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int inc = 0, n = nums.size(), ans = 0;
        unordered_map<int, int> map;
        map[0] = -1;
        for (int i = 0; i < n; i++) {
            int x = nums[i] ;
                if (x == 1)
                    inc++;
                else
                    inc--;
                if (map.count(inc)) {
                    ans = max(ans, i - map[inc]);
                } else {
                    map[inc] = i;
                }
            
            }
            return ans;
        }
    
};