class Solution {
public:
    // T[i][j] = min(T[i-1][j-1],T[i-1][j]) + triangle[i][j]
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty() || triangle[0].empty()) {
            return 0;
        }
        // only compare path total at the bottom of triangle
        vector<int> total(triangle.size(),triangle[0][0]);
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = i; j >= 0; j--) {
                total[j] = min(total[min(j,i-1)], total[max(j-1,0)]) + triangle[i][j];
            }
        }
        int minT = total[0];
        for (int j = 1; j < total.size(); j++) {
            minT = min(minT,total[j]);
        }
        return minT;
    }
};
