class Solution {
public:
    vector<vector<bool>> col;
    vector<vector<bool>> row;
    vector<vector<bool>> box;
    bool done;
    vector<int> fill;
    void collectPath(vector<vector<char>>& board, int f) {
        if (f >= fill.size()) {
            done = true;
            return;
        }
        int i = fill[f]/9;
        int j = fill[f] - i*9;
        for (int num = 0; num < 9; num++) {
            if (!done && !row[i][num] && !col[j][num] && !box[((int)i/3)*3+((int)j/3)][num]) {
                board[i][j] = '1' + num;
                //update row,col,box
                row[i][num] = true;
                col[j][num] = true;
                box[((int)i/3) * 3 + ((int)j/3)][num] = true;

                collectPath(board, f+1);
                //change row,col,box back
                row[i][num] = false;
                col[j][num] = false;
                box[((int)i/3) * 3 + ((int)j/3)][num] = false;
            }

        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<bool> nine(9);
        for (int i = 0; i < 9; i++) {
            row.push_back(nine);
            col.push_back(nine);      
            box.push_back(nine);
        }
        done = false;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    row[i][board[i][j] - '1'] = true;
                    col[j][board[i][j] - '1'] = true;
                    box[((int)i/3) * 3 + ((int)j/3)][board[i][j] - '1'] = true;
                }
                else {
                    fill.push_back(i*9+j);
                }
            }
        }
        collectPath(board, 0);
    }
};
