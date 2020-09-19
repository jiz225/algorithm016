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
    vector<int> postorder(Node* root) {
        vector<int> nodes;
        vector<Node*> nstack;
        if (root == nullptr) {
            return nodes;
        }
        nstack.push_back(root);
        while (!nstack.empty()) {
            root = nstack.back();
            nodes.insert(nodes.begin(),root->val);
            nstack.pop_back();
            int n = (root->children).size();
            for (int i = 0; i < n; i++) {
                if (root->children[i]) {
                    nstack.push_back(root->children[i]);
                }
            }
        }
        return nodes;
    }
};
