class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int l_min = 0;
        int count=0;
        for (char ch : s) {
            if (ch != 32) {
                len++;
                count=0;
            } else {
                if(count==0) l_min = len;
                len = 0;
                count++;
            }
        }
        if (len == 0)
            return l_min;
        else {
            return len;
        }
    }
};