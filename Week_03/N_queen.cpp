class Solution {
public:
    vector<vector<string>> combs;
    vector<string> path;
    string toStr(int i, int n) {
        string str(n, '.');
        str[i] = 'Q';
        return str;
    }
    void collectPath(vector<int>& diag_f, vector<int>& diag_b, vector<int>& cols, int row, int n) {
        if (path.size() == n) {
            combs.push_back(path);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!cols[i] && !diag_f[row - i + n] && !diag_b[row + i]) {
                string str = toStr(i, n);
                //cout << " " << str;
                cols[i] = 1, diag_f[row - i + n] = 1, diag_b[row + i] = 1;
                path.push_back(str);
                collectPath(diag_f, diag_b, cols, row + 1, n);
                path.pop_back();
                cols[i] = 0, diag_f[row - i + n] = 0, diag_b[row + i] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        if (n == 0) {
            return combs;
        }
        vector<int> cols(n, 0);
        vector<int> diag_f(2 * n, 0);
        vector<int> diag_b(2 * n, 0);
        collectPath(diag_f, diag_b, cols, 0, n);
        return combs;
    }
};
