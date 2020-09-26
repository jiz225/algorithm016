class Solution {
public:
    vector<vector<int>> comb;
    vector<int> path;
    void collectPath(queue<int>& q, int k) {
        if (path.size() == k) {
            comb.push_back(path);
            return;
        }
        for (int i = 0; i < q.size(); i++) {
            path.push_back(q.front());
            q.pop();
            collectPath(q, k);
            q.push(path.back());
            path.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        queue<int> q;
        for (int num: nums) {
            q.push(num);
        }
        collectPath(q, nums.size());
        return comb;
    }
};
