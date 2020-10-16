class Solution {
public:
    // P[i][j] = P[i-1][j] + P[i][j-1]
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) {
            return 1;
        }
        vector<int> num(m,1);
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                num[j] = num[j] + num[j-1];
            }
        }
        return num[m-1];
    }
};
