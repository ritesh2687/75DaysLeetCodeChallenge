class Solution {
public:
    bool checkValidString(string s) {
        int cmin = 0;
        int cmax = 0;

        for (char c : s) {
            if (c == '(') {
                cmin++;
                cmax++;
            } else if (c == ')') {
                cmin--;
                cmax--;
            } else {
                cmin--;
                cmax++;
            }

            if (cmin < 0) {
                cmin = 0;
            }

            if (cmax < 0) {
                return false;
            }
        }

        return cmin == 0;
    }
};