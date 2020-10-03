/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> maxVals;
        if (root == nullptr) {
            return maxVals;
        }
        queue<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            int size = nodes.size();
            int maxV = numeric_limits<int>::min();
            while(size > 0) {
                root = nodes.front();
                nodes.pop();
                size --;
                if (root->val > maxV) {
                    maxV = root->val;
                }
                if (root->left != nullptr) {
                    nodes.push(root->left);
                }
                if (root->right != nullptr) {
                    nodes.push(root->right);
                }
            }
            maxVals.push_back(maxV);
        }
        return maxVals;
    }
};
