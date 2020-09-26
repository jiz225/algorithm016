class Solution {
public:
    vector<vector<int>> comb;
    vector<int> path;
    void collectPath(queue<int>& q, int k) {
        if (path.size() == k) {
            comb.push_back(path);
            return;
        }
        int prev;
        for (int i = 0; i < q.size(); i++) {
            if (i == 0 || (i > 0 && q.front() != prev)) {
                prev = q.front();
                path.push_back(prev);
                q.pop();
                collectPath(q, k);
                q.push(prev);
                path.pop_back();
            }
            else {
                prev = q.front();
                q.pop();
                q.push(prev);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        queue<int> q;
        sort(nums.begin(), nums.end());
        for (int num: nums) {
            q.push(num);
        }
        collectPath(q, nums.size());
        return comb;
    }
};
