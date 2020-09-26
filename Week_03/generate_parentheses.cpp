class Solution {
public:
    vector<string> comb;  
    string path;
    void collectPath(int numl,int numr,int n) {
        if (path.length() == n*2) {
            comb.push_back(path);
            return;
        }
        if (numl < n) {
            path.push_back('(');
            collectPath(numl+1,numr,n);
            path.pop_back();
        }
        if (numr < numl) {
            path.push_back(')');
            collectPath(numl,numr+1,n);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        collectPath(0,0,n);
        return comb;
    }
};
