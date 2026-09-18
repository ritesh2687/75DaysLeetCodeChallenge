class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
     int n = s.length();
        vector<int> first(26, -1), last(26, -1);
        
        for (int i = 0; i < n; ++i) {
            if (first[s[i] - 'a'] == -1) {
                first[s[i] - 'a'] = i;
            }
            last[s[i] - 'a'] = i;
        }
        
        vector<pair<int, int>> intervals;
        
        for (int i = 0; i < 26; ++i) {
            if (first[i] != -1) {
                int L = first[i];
                int R = last[i];
                bool valid = true;
                
                for (int j = L; j <= R; ++j) {
                    if (first[s[j] - 'a'] < L) {
                        valid = false;
                        break;
                    }
                    R = max(R, last[s[j] - 'a']);
                }
                
                if (valid) {
                    intervals.push_back({R, L});
                }
            }
        }
        
        sort(intervals.begin(), intervals.end());
        
        vector<string> res;
        int prevEnd = -1;
        
        for (auto p : intervals) {
            if (p.second > prevEnd) {
                res.push_back(s.substr(p.second, p.first - p.second + 1));
                prevEnd = p.first;
            }
        }
        
        return res;
    }
};