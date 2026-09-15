#include<cmath>
class Solution {
public:
    int largestInteger(int n, int s) {
        int t=pow(10,n)-1;
        for (int i = t; i >= 0; i--) {
            int sum = 0;
            int  temp=i;
            while (temp > 0) {
                int r = temp % 10;
                sum = sum + r;
                temp /= 10;
            }
            if (sum == s) {
                return i;
            }
        }
        return -1;
    }
};