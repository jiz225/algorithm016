class Solution {
public:
    vector<vector<int>> comb;
    vector<int> path;
    void collectPath(int s, int n, int k) {
        if (path.size() == k) {
            //cout << " " << s;
            comb.push_back(path);
            return;
        }
        // if the number of int i+1...n is less than k-i, do not permute
        for (int i = s; i <= n - k + path.size() + 1; i++) {
            path.push_back(i);
            collectPath(i+1, n, k);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        collectPath(1,n,k);
        return comb;
    }
};
