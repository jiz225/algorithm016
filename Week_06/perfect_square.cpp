class Solution {
public:
    // S[i] = min(S[i - j^2] + 1, S[i])
    int numSquares(int n) {
        vector<int> nums(n+1);

        for (int i = 1; i <= n; i++) {
            nums[i] = i;
            if (i*i == n) {
                return 1;
            }
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 1; i + j*j <= n; j++) {
                nums[i + j*j] = min(nums[i] + 1, nums[i + j*j]);
            }
        }
        return nums[n];
    }
};
