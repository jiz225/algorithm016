class Solution {
public:
    int climbStairs(int n) {
        int sum = 1, l = 0, r = 0;
        for (int i = 1; i <= n; i++) {
            l = r;
            r = sum;
            sum = l + r;
        }
        return sum;
    }
};
