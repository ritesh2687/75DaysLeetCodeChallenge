class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        int left= 0;
        int count = 0 ;
        string ans = "";
        for (int right = 0; right < n; ++right) {
            if (s[right] == '1') {
                count++;
            }

            while (count == k) {
                if (s[left] == '0') {
                    left++;
                    continue;
                }
                string current = s.substr(left, right - left + 1);

                if (ans.empty() || current.length() < ans.length() ||
                    (current.length() == ans.length() && current < ans)) {
                    ans = current;
                }
            
            count--;
            left++;
        }}
         return ans;
    }
   
};