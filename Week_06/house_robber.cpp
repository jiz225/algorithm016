class Solution {
public:
    // M[i][1] = M[i-1][0] + nums[i]
    // M[i][0] = max(M[i-1][1], M[i-1][0])
    int rob(vector<int>& nums) {
        int rob = 0, skip = 0;
        for (int i = 0; i < nums.size(); i++) {
            int prev = rob;
            rob = skip + nums[i];
            skip = max(skip, prev);
        }
        return max(rob,skip);
    }
};
