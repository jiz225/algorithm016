class Solution {
public:
    // M[i][1] = M[i-1][0] + nums[i]
    // M[i][0] = max(M[i-1][1], M[i-1][0])
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int rob = 0, skip = 0;
        for (int i = 1; i < nums.size(); i++) {
            int prev = rob;
            rob = skip + nums[i];
            skip = max(skip, prev);
        }
        int maxR = max(nums[0],max(rob,skip));
        rob = 0, skip = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            int prev = rob;
            rob = skip + nums[i];
            skip = max(skip, prev);
        }
        return max(max(rob,skip), maxR);
    }
};
