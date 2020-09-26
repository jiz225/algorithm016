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
    TreeNode* lca;
    bool isAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return false;
        }
        bool isleft = isAncestor(root->left,p,q);
        bool isright = isAncestor(root->right,p,q);
        if (((root->val == p->val || root->val == q->val) && (isleft||isright)) || (isright && isleft)) {
            lca = root;
        }
        if (root->val == p->val || root->val == q->val) {
            return true;
        }
        else {
            return (isleft || isright);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // recursion I: check if p,q in subtree
        if (root == nullptr || root->val == q->val || root->val == p->val) {
            return root;
        }
        /// left, right subtree
        TreeNode* leftA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightA = lowestCommonAncestor(root->right, p, q);
        if (leftA == nullptr) { /// p,q in right subtree
            return rightA;
        }
        else if (rightA == nullptr) { /// p,q in left subtree
            return leftA;
        }
        else {
            return root; /// one in left, one in right
        }


        /**
        // recursion II: one of p,q is ancestor || root of p,q
        if (root == nullptr) {
            return root;
        }
        isAncestor(root, p, q);
        return lca;
        **/
    }
};
