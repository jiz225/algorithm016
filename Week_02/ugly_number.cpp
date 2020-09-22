class Solution {
public:
    int nthUglyNumber(int n) {
        // DP x_(i) = min(x_a*2, x_b*3, x_c*5), (a,b,c) in 0...i-1
        vector<int> nums (n, 1);
        int a2 = 0, a3 = 0, a5 = 0;
        for (int i = 1; i < n; i++) {
            nums[i] = min(nums[a2]*2,min(nums[a3]*3,nums[a5]*5));
            if (nums[i] == nums[a2]*2) {
                a2 += 1;
            }
            if (nums[i] == nums[a3]*3) {
                a3 += 1;
            }
            if (nums[i] == nums[a5]*5) {
                a5 += 1;
            }
        }
        return nums.back();
    }
};
