class Solution {
public:
    int move_i[8] = {0, 1, 0, -1, 1, 1, -1, -1};
    int move_j[8] = {1, 0, -1, 0, 1, -1, 1, -1};

    void revealBlank(vector<vector<char>>& board, int i, int j) {
        if (board[i][j] == 'M') {
            board[i][j] = 'X';
            return;
        }
        int numM = 0;
        for (int pos = 0; pos < 8; pos++) {
            int i_m = i + move_i[pos];
            int j_m = j + move_j[pos];
            if (i_m < 0 || i_m >= board.size() || j_m < 0 || j_m >= board[0].size()) {
                continue;
            }
            if (board[i_m][j_m] == 'M') {
                numM ++;
            }
        }
        if (numM > 0) {
            board[i][j] = numM + '0';
        } 
        else {
            board[i][j] = 'B';
            for (int pos = 0; pos < 8; pos++) {
                int i_m = i + move_i[pos];
                int j_m = j + move_j[pos];
                if (i_m < 0 || i_m >= board.size() || j_m < 0 || j_m >= board[0].size()) {
                    continue;
                }
                if (board[i_m][j_m] == 'E') {
                    revealBlank(board, i_m, j_m);
                }
            }
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        revealBlank(board,click[0],click[1]);
        return board;
    }
};
