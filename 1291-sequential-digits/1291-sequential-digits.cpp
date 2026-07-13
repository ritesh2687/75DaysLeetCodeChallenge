class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        string digits = "123456789";
        
        int min_len = to_string(low).length();
        int max_len = to_string(high).length();
        
        for (int len = min_len; len <= max_len; ++len) {
            for (int i = 0; i <= 9 - len; ++i) {
                int num = stoi(digits.substr(i, len));
                if (num >= low && num <= high) {
                    result.push_back(num);
                }
            }
        }
        
        return result;
    }
};