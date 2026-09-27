class Solution {
public:
    string reverseParentheses(string s) {

        while (s.find('(') != string::npos) {


            int close = s.find(')');


            int open = close - 1;

            while (s[open] != '(') {
                open--;
            }


            reverse(s.begin() + open + 1, s.begin() + close);

            s.erase(close, 1);

     
            s.erase(open, 1);
        }

        return s;
    }
};