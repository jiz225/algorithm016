class Solution {
public:
    int countOnes(int n) {
        int one = 0;
        while (n > 0) {
            one ++;
            n &= (n-1);
        }
        return one;
    }
    vector<int> countBits(int num) {
        vector<int> nums;
        for (int n = 0; n <= num; n++) {
            nums.push_back(countOnes(n));
        }
        return nums;
    }
};
