class Solution {
public:
    // DFS: grid[i][j] == 0; steps --
    int collectPath(vector<vector<int>>& grid, int i, int j, int steps) {
        if (i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0 || grid[i][j] == -1) {
            return 0;
        }
        if (grid[i][j] == 2) {
            if (steps == 1) {
                return 1;
            }
            return 0;
        }
        int num = 0;
        grid[i][j] = -1;
        steps --;
        num += collectPath(grid, i + 1, j, steps);
        num += collectPath(grid, i, j + 1, steps);
        num += collectPath(grid, i - 1, j, steps);
        num += collectPath(grid, i, j - 1, steps);
        grid[i][j] = 0;
        return num;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int steps = 0, s_i = 0, s_j = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] != -1) {
                    steps ++;
                }
                if (grid[i][j] == 1) {
                    s_i = i;
                    s_j = j;
                }
            }
        }
        return collectPath(grid, s_i, s_j, steps);
    }
};
