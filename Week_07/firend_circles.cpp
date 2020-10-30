class UnionFind {
private:
    vector<int> parent;
    int groups;
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
            groups --;
        }
    }
    int getGroups() {
        return groups;
    }
    UnionFind(int num) {
        groups = num;
        for (int i = 0; i < num; i++) {
            parent.push_back(i);
        }
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if (M.empty() || M[0].empty() || M.size() != M[0].size()) {
            return 0;
        }
        UnionFind* friends = new UnionFind(M.size());
        for (int i = 0; i < M.size(); i++) {
            for (int j = i + 1; j < M.size(); j++) {
                if (M[i][j] == 1) {
                    friends->unite(i, j);
                }
            }
        }
        return friends->getGroups();
    }
};
