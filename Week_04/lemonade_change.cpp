class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int num_5 = 0;
        int num_10 = 0;
        for (int bill: bills) {
            if (bill == 5) {
                num_5 ++;
            }
            else if (bill == 10) {
                num_10 ++;
                num_5 --;
            }
            else {
                num_5 --;
                if (num_10 > 0) {
                    num_10 --;
                }
                else {
                    num_5 -= 2;
                }
            }
            if (num_5 < 0) {
                return false;
            }
        }
        return true;
    }
};
