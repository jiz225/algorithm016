class Solution {
public:
    // Greedy
    vector<int> steps;
    int jump(vector<int>& nums) {
        steps.resize(nums.size(),nums.size());
        steps[0] = 0;
        int reach = 0;
        for (int i = 0; i < nums.size()-1; i++) {
            if (i <= reach) {
                reach = max(reach,i+nums[i]);
                if (reach >= nums.size()-1) {
                    reach = nums.size()-1;
                }
                steps[reach] = min(steps[reach],steps[i]+1);
            }
        }
        return steps[nums.size()-1];
    }
};
