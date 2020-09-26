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
    bool checkNode(TreeNode* root, long long lower, long long upper) {
        if (root == nullptr) {
            return true;
        }
        if (root->val >= upper || root->val <= lower) {
            return false;
        }
        return (checkNode(root->left, lower, root->val) && checkNode(root->right, root->val, upper));
    }
    bool isValidBST(TreeNode* root) {
        // iteration: 
        vector<TreeNode*> stack;
        if (root == nullptr) {
            return true;
        }
        long long prev = LONG_MIN;
        while (!stack.empty() || root != nullptr) {
            if (root != nullptr) {
                stack.push_back(root);
                root = root->left;
            }
            else {
                root = stack.back();
                stack.pop_back();
                //cout << " " << root->val;
                if (root->val <= prev) {
                    return false;
                }
                prev = root->val;
                root = root->right;
            }
            
        }
        return true;
    /**
        // recursion: upper,lower bound
        return checkNode(root, LONG_MIN, LONG_MAX);
    **/
    }
};
