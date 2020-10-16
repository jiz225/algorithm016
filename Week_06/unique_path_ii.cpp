class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<int> num(obstacleGrid[0].size(),0);
        num[0] = 1;
        for (int i = 0; i < obstacleGrid.size(); i++) {
            num[0] *= (1-obstacleGrid[i][0]);
            for (int j = 1; j < obstacleGrid[0].size(); j++) {
                num[j] = (1-obstacleGrid[i][j]) * (num[j-1] + num[j]);
            }
        }
        return num.back();
    }
};
