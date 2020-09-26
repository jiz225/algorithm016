class Solution {
public:
    vector<vector<int>> sets;
    vector<int> set;
    void findSets(vector<int>& nums, int level) {
        sets.push_back(set);
        for (int i = level; i < nums.size(); i++) {
            set.push_back(nums[i]);
            findSets(nums,i+1);
            set.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        findSets(nums, 0);
        return sets;
    }
};
