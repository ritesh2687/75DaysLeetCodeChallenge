class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        bool check = true;

        for (int bill : bills) {
            if (bill == 5) {
                five++;
                check = true;
            }
            else if (bill == 10) {
                if (five == 0) {
                    check = false;
                    break;
                }
                five--;
                ten++;
                check = true;
            }
            else if (bill == 20) {
                if (ten >= 1 && five >= 1) {
                    ten--;
                    five--;
                    check = true;
                }
                else if (five >= 3) {
                    five -= 3;
                    check = true;
                }
                else {
                    check = false;
                    break;
                }
            }
        }

        return check;
    }
};