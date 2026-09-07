class Solution {
public:
    int distinctSubseqII(string s) {
        int mod = 1e9 + 7;
        vector<int> ends(26, 0);
        int sum = 0;
        
        for (char c : s) {
            int add = (sum + 1) % mod;
            int diff = (add - ends[c - 'a'] + mod) % mod;
            sum = (sum + diff) % mod;
            ends[c - 'a'] = add;
        }
        
        return sum;
    }
};