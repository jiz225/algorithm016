class UnionFind {
private:
    vector<int> parent;
public:
    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }
    void unite(int i, int j) {
        int pi = find(i);
        int pj = find(j);
        if (pj != pi) {
            parent[pi] = pj;
        }
    }
    UnionFind(int num) {
        for (int i = 0; i < num; i++) {
            parent.push_back(i);
        }
    }
};
class Solution {
public: 
    int mi[4] = {0, 1, 0, -1};
    int mj[4] = {1, 0, -1, 0};
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) {
            return;
        }
        
        int border = board.size() * board[0].size();
        UnionFind* region = new UnionFind(border + 1);
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'O') {
                    if (i == 0 || i == board.size()-1 || j == 0 || j == board[0].size()-1) {
                        region->unite(i * board[0].size() + j, border);
                    }
                    else {
                        for (int x = 0; x < 4; x++) {
                            int ni = i + mi[x];
                            int nj = j + mj[x];
                            if (board[ni][nj] == 'O') {
                                region->unite(i * board[0].size() + j, ni * board[0].size() + nj);
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'O' && region->find(i * board[0].size() + j) != region->find(border)) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
