class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq; 
        int ones = 0;
        long long mx = 0;
        
        for (int x : nums) {
            freq[x]++;
            mx = max(mx, (long long)x);
            if (x == 1) ones++;
        }
        int res = (ones > 0 ? (ones % 2 ? ones : ones - 1) : 1);
        
        for (auto [x, cnt] : freq) {
            if (x != 1 && cnt > 1) {
                int len = 0;
                long long cur = x;

                while (cur <= mx && freq.count(cur) && freq[cur] > 1) {
                    len++;
                    cur *= cur; 
                }
                
                
                if (freq.count(cur) && freq[cur] == 1) {
                    res = max(res, 2 * len + 1);
                } else {
                    res = max(res, 2 * len - 1);
                }
            }
        }
        
        return res;
    }
};