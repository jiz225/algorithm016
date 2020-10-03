class Solution {
public:
    set<pair<int, int>> obs;
    // forward, down, backward, up
    int move_y[4] = {1, 0, -1, 0};
    int move_x[4] = {0, 1, 0, -1};
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int maxD = 0;
        for (int i = 0; i < obstacles.size(); i++) {
            obs.emplace(make_pair(obstacles[i][0],obstacles[i][1]));
        }
        int x = 0;
        int y = 0;
        int currdir = 0;
        for (int i = 0; i < commands.size(); i++) {
            if (commands[i] == -1) {
                currdir = (currdir + 1)%4;
            }
            else if (commands[i] == -2) {
                currdir = (currdir + 3)%4;
            }
            else {
                for (int j = 1; j <= commands[i]; j++) { // move step by step
                    if (obs.find(make_pair(x+move_x[currdir],y+move_y[currdir])) != obs.end()) {
                        break;
                    }
                    else {
                        x += move_x[currdir];
                        y += move_y[currdir];
                    }
                    maxD = max(maxD, x*x+y*y);
                }
                
            }
        }
        return maxD;
    }
};
