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
private:
    void preorder(TreeNode* root, vector<int>& nodes) {
            if (root == nullptr) {
                return;
            }
            nodes.push_back(root->val);
            preorder(root->left, nodes);
            preorder(root->right, nodes);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // iteration: stack
        vector<int> nodes;
        vector<TreeNode*> nstack;
        while (root != nullptr || !nstack.empty()) {
            if (root != nullptr) {
                nodes.push_back(root->val);
                nstack.push_back(root);
                root = root->left;
            }
            else {
                root = nstack.back();
                nstack.pop_back();
                root = root->right;
            }   
        }
        return nodes;

    /** 
        // recursion
        vector<int> nodes;
        preorder(root,nodes);
        return nodes;
    **/
    }
};
