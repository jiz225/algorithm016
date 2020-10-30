class TrieNode{
public:
    string word = "";
    vector<TrieNode*> children;
    TrieNode():children(26, 0){}
};
class Solution {
public: 
    int move_i[4] = {0, 1, 0, -1};
    int move_j[4] = {1, 0, -1, 0};
    TrieNode* root;
    vector<string> strs;
    void expandChar(vector<vector<char>>& board, int i, int j, TrieNode* curr) {
        if (i >= board.size() || j >= board[0].size() || i < 0 || j < 0 || board[i][j] == '-') {
            return;
        }
        char c = board[i][j];
        if (curr->children[c-97] == 0) {
            return;
        }
        curr = curr->children[c-97];
        if (curr->word.size() > 0) {
            strs.push_back(curr->word);
            curr->word = "";
        }
        board[i][j] = '-';
        for (int x = 0; x < 4; x++) {
            expandChar(board,i + move_i[x], j + move_j[x], curr);
        }
        board[i][j] = c;
    }         
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        TrieNode* curr = root;
        for (string word: words) {
            for (char c: word) {
                if (curr->children[c-97] == 0) {
                    curr->children[c-97] = new TrieNode();
                }
                curr = curr->children[c-97];
            }
            curr->word = word;
            curr = root;
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                expandChar(board, i, j, curr);
                curr = root;
            }
        }
        return strs;
    }
};
