class Solution {
public:
    // Greedy
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        //cout << " " << g.back();
        int content = 0;
        while (g.size() > 0 && s.size() > 0 ) {
            if (s.back() >= g.back()) {
                s.pop_back();
                g.pop_back();
                content ++;
            }
            else {
                g.pop_back();
            }
        }
        return content;
    }
};
