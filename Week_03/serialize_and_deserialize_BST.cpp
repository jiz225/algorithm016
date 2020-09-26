/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    queue<TreeNode*> nodes;
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string seq = "";
        if (root == nullptr) {
            return seq;
        }
        nodes.push(root);
        while (!nodes.empty()) {
            int size = nodes.size();
            while (size > 0) {
                auto curr = nodes.front();
                nodes.pop();
                size --;
                if (curr != nullptr) {
                    seq += to_string(curr->val);
                    nodes.push(curr->left);
                    nodes.push(curr->right);
                }
                else {
                    seq.push_back('n');
                }
                seq.push_back(',');
            }
        }
        //cout << "" << seq;
        return seq;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") {
            return nullptr;
        }
        vector<string> svals;
        string sval = "";
        int idx = 0;
        while (idx < data.size()) {
            if (data[idx] != ',') {
                sval.push_back(data[idx]);
            }
            else {
                svals.push_back(sval);
                //cout << " " << sval;
                sval = "";
            }
            idx ++;
        }
        TreeNode* root = new TreeNode(stoi(svals[0]));
        idx = 1;
        nodes.push(root);
        while (!nodes.empty()) { 
            TreeNode* curr = nodes.front();
            nodes.pop();
            if (svals[idx] != "n"){
                curr->left = new TreeNode(stoi(svals[idx]));
                nodes.push(curr->left);
            }
            idx ++; 
            if (svals[idx] != "n") {
                curr->right = new TreeNode(stoi(svals[idx]));
                nodes.push(curr->right);
            }
            idx ++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
