class Solution {
public:
    double myPow(double x, long long n) {
        if (n == 0) {
            return 1.0;
        } 
        if (n < 0) {
            return 1/myPow(x, -n);
        }
        if (n % 2 == 0) {
            double divide = myPow(x, n/2);
            return divide * divide;
        }
        else {
            double divide = myPow(x, n/2);
            return divide * divide * x;
        }
    }
};
