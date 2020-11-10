class Solution {
public:
    int num;
    void collectPath(int diag_f, int diag_b, int cols, int row, int n) {
        if (row == n) {
            num ++;
            return;
        }
        int bit = ~(cols | diag_f | diag_b) & ((1 << n) - 1);
        while (bit > 0) {
            int pick = bit & -bit;
            collectPath((diag_f|pick) << 1, (diag_b|pick) >> 1, cols|pick, row+1, n);
            bit &= bit - 1;
        }
    }
    int totalNQueens(int n) {
        collectPath(0, 0, 0, 0, n);
        return num;
    }
};
