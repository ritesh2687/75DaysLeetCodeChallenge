#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        int odd_count = 0;
        char mid_char = 0;
        for (int i = 0; i < 26; ++i) {
            if (count[i] % 2 != 0) {
                odd_count++;
                mid_char = 'a' + i;
            }
        }

        if ((n % 2 == 0 && odd_count != 0) || (n % 2 != 0 && odd_count != 1)) {
            return "";
        }

        vector<int> half_count(26, 0);
        for (int i = 0; i < 26; ++i) {
            half_count[i] = count[i] / 2;
        }

        int m = n / 2;

        auto build_palindrome = [&](const string& half) {
            string full = half;
            if (n % 2 != 0) {
                full += mid_char;
            }
            string rev = half;
            reverse(rev.begin(), rev.end());
            full += rev;
            return full;
        };

        vector<int> cur_half = half_count;
        int match_len = 0;
        for (int i = 0; i < m; ++i) {
            int t_char = target[i] - 'a';
            if (cur_half[t_char] > 0) {
                cur_half[t_char]--;
                match_len++;
            } else {
                break;
            }
        }

        if (match_len == m) {
            string candidate = build_palindrome(target.substr(0, m));
            if (candidate > target) {
                return candidate;
            }
        }

        for (int i = match_len; i >= 0; --i) {
            vector<int> rem_half = half_count;
            for (int j = 0; j < i; ++j) {
                rem_half[target[j] - 'a']--;
            }

            int start_char = (i < m) ? (target[i] - 'a' + 1) : 0;
            if (i == m) continue;

            for (int c = start_char; c < 26; ++c) {
                if (rem_half[c] > 0) {
                    rem_half[c]--;
                    string res_half = target.substr(0, i);
                    res_half += (char)('a' + c);
                    for (int k = 0; k < 26; ++k) {
                        res_half.append(rem_half[k], 'a' + k);
                    }
                    return build_palindrome(res_half);
                }
            }
        }

        return "";
    }
};