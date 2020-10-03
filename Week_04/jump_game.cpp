class Solution {
public:
    int max_R = 0;
    bool toNext(vector<int>& nums, int curr){
        if (nums[curr] + curr >= nums.size() - 1) {
            return true;
        }
        if (nums[curr] == 0 || nums[curr] + curr <= max_R) {
            return false;
        }
        max_R = nums[curr] + curr;
        bool reach = false;
        for (int i = nums[curr]; i > 0; i--) {
            int next = i + curr;
            reach = toNext(nums,next);
            if (reach) {
                break;
            }
        }
        return reach;
    }
    bool canJump(vector<int>& nums) {
        return toNext(nums,0);
    }
};
