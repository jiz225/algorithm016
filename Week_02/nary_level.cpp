/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> levels;
        queue<Node*> parents;
        
        if (root == nullptr) {
            return levels;
        }
        parents.push(root);
        while (!parents.empty()) {
            int num = parents.size();
            vector<int> level; //level means parent level
            while (num > 0) {
                root = parents.front();
                parents.pop();
                level.push_back(root->val);
                num -= 1;
                // add children of each parent node
                int n = root->children.size();
                for (int i = 0; i < n; i++) {
                    if (root->children[i]) {
                        parents.push(root->children[i]);
                    }
                }
            }
            levels.push_back(level);
        }
        return levels;
    }
};
