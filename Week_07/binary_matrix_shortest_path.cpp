class Solution {
public:
    // BFS
    int mi[8] = {0,1,0,-1,1,-1,1,-1};
    int mj[8] = {1,0,-1,0,1,1,-1,-1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid.size() != grid[0].size() || grid[0][0] != 0 || grid[grid.size()-1].back() != 0) {
            return -1;
        }
        if (grid.size() == 1) {
            return 1;
        }
        int num = 1;
        int k = grid.size();
        queue<int> q;
        q.push(0);
        //pos.erase(0);
        while (!q.empty()) {
            int size = q.size();
            num ++;
            while(size > 0) {
                int parent = q.front();
                q.pop();
                size --;
                int i = parent/k;
                int j = parent - i*k;
                for (int x = 0; x < 8; x++) {
                    int ci = i + mi[x];
                    int cj = j + mj[x];
                    if (ci >= 0 && cj >= 0 && ci < k && cj < k && !grid[ci][cj]) {
                        if (ci == k-1 && cj == k-1) {
                            return num;
                        }
                        int child = ci*k+cj;
                        grid[ci][cj] = 1;
                        q.push(child);
                    }
                }
                //cout << " " << q.size() << "-" << num; 
            }

        }
        return -1;
    }
};
