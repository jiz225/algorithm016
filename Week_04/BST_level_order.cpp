/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levels;
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> nodes;
        if (root == nullptr) {
            return levels;
        }
        nodes.push(root);
        while (!nodes.empty()) {
            int size = nodes.size();
            levels.push_back(vector<int> ());
            while (size > 0) {
                root = nodes.front();
                levels.back().push_back(root->val);
                nodes.pop();
                size --;
                if (root->left != nullptr) {
                    nodes.push(root->left);
                }
                if (root->right != nullptr) {
                    nodes.push(root->right);
                }
            }
        }

        return levels;
    }
};
