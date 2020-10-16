class Solution {
public:
    int num;
    int half_num;
    void collectPath(vector<int>& diag_f, vector<int>& diag_b, vector<int>& cols, int row, int n) {
        if (row == n) {
            num ++;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (row == 0 && i == n/2) {
                half_num = num;
            }
            if (row == 0 && i == (n+1)/2) {
                break;
            }
            if (!cols[i] && !diag_f[row - i + n] && !diag_b[row + i]) {
                cols[i] = 1, diag_f[row - i + n] = 1, diag_b[row + i] = 1;
                collectPath(diag_f, diag_b, cols, row + 1, n);
                cols[i] = 0, diag_f[row - i + n] = 0, diag_b[row + i] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        num = 0;
        vector<int> cols(n, 0);
        vector<int> diag_f(2 * n, 0);
        vector<int> diag_b(2 * n, 0);
        collectPath(diag_f, diag_b, cols, 0, n);
        if (n % 2 == 0) {
            num = half_num * 2; 
        }
        else {
            num = half_num * 2 + num - half_num; 
        }
        return num;
    }
};
