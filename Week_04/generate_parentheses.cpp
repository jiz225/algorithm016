class Solution {
    struct Node {
        string s;
        int left;
        int right;
        Node(string s, int left, int right) : s(s), left(left), right(right) {}
    };
public:
    vector<string> comb;  
    vector<string> generateParenthesis(int n) {
        if (n <= 0) {
            return comb;
        }
        Node* curr = new Node("(",1,0);
        //string path;
        queue<Node*> q;
        q.push(curr);
        while (!q.empty()) {
            curr = q.front();
            q.pop();
            if (curr->s.length() == n*2) {
                comb.push_back(curr->s);
            }
            else {
                string news = curr->s;
                int left = curr->left;
                int right = curr->right;
                if (left < n) {
                    curr = new Node(news+"(", left+1, right);
                    q.push(curr);
                }
                if (right < left) {
                    curr = new Node(news+")", left, right+1);
                    q.push(curr);
                }
            }
        }
        return comb;
    }
};
