class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> count(10, 0);
        for (int d : digits) {
            count[d]++;
        }
        
        int ans = 0;
        for (int i = 100; i <= 998; i += 2) {
            int c0 = i % 10;
            int c1 = (i / 10) % 10;
            int c2 = i / 100;
            
            count[c0]--;
            count[c1]--;
            count[c2]--;
            
            if (count[c0] >= 0 && count[c1] >= 0 && count[c2] >= 0) {
                ans++;
            }
            
            count[c0]++;
            count[c1]++;
            count[c2]++;
        }
        
        return ans;
    }
};