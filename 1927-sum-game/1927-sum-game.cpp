class Solution {
public:
    bool sumGame(string num) {
        double sum_diff = 0;
        double q_diff = 0;
        int n = num.size();
        
        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') {
                q_diff -= 1.0;
            } else {
                sum_diff += (num[i] - '0');
            }
        }
        
        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') {
                q_diff += 1.0;
            } else {
                sum_diff -= (num[i] - '0');
            }
        }
        
        return sum_diff != q_diff * 4.5;
    }
};