class Solution {
public:
    // B[i] = B[i/2] + (i % 2)
    vector<int> countBits(int num) {
        vector<int> nums(num+1);
        for (int i = 1; i <= num; i++) {
            nums[i] = nums[(int)(i/2)] + (i % 2);
        }
        return nums;
    }
};
