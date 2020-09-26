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
    TreeNode* invertTree(TreeNode* root) {
        // recursion: preorder
        if (root == nullptr) {
            return root;
        }
        TreeNode* left = invertTree(root->right);
        TreeNode* right = invertTree(root->left);
        root->left = left;
        root->right = right;
        return root;

        /**
        // iteration: slow
        vector<TreeNode*> stack;
        if (root == nullptr) {
            return root;
        }
        TreeNode* curr = root;
        stack.push_back(curr);
        while (!stack.empty()) {
            curr = stack.back();
            stack.pop_back();
            TreeNode* right = curr->left;
            TreeNode* left = curr->right;
            curr->left = left;
            curr->right = right;
            if (curr->left != nullptr) {              
                stack.push_back(curr->left);
            }
            if (curr->right != nullptr) {
                stack.push_back(curr->right);
            }
        }
        return root;
        **/
    }
};
