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
    /**
    // recursion
    unordered_map <int,int> in_map;
    TreeNode* buildRoot(vector<int>& preorder, vector<int>& inorder, int pre_l, int pre_r, int in_l, int in_r) {
        if (pre_l > pre_r) {
            return nullptr;
        }
        int val = preorder[pre_l];
        int in_root = in_map[val];
        TreeNode* root = new TreeNode(val);
        int left_size = in_root - in_l;
        root->left = buildRoot(preorder, inorder, pre_l+1,pre_l+left_size,in_l,in_root-1);
        root->right = buildRoot(preorder, inorder,pre_l+1+left_size, pre_r,in_root+1,in_r);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (inorder.empty() || inorder.size() != preorder.size()) {
            return nullptr;
        }
        for (int i = 0; i < inorder.size(); i++) {
            in_map[inorder[i]] = i;
        }
        return buildRoot(preorder, inorder, 0, preorder.size()-1, 0, inorder.size());
    }**/

    // iteration: stack find parent for right
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (inorder.empty() || inorder.size() != preorder.size()) {
            return nullptr;
        }
        vector<TreeNode*> parents;
        TreeNode* root = new TreeNode(preorder[0]);
        parents.push_back(root);
        int index = 0;
        for (int i = 1; i < preorder.size(); i++) {
            TreeNode* prev = parents.back();
            if (prev->val != inorder[index]) {
                prev->left = new TreeNode(preorder[i]);
                parents.push_back(prev->left);
            }
            else {
                while (!parents.empty() && parents.back()->val == inorder[index]) {
                    prev = parents.back();
                    parents.pop_back();
                    index++;
                }
                prev->right = new TreeNode(preorder[i]);
                parents.push_back(prev->right);
            }
        }
        return root;
    }
};
