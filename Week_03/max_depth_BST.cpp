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
    int maxDepth(TreeNode* root) {
        // iteration: BFS
        queue<TreeNode*> nodes;
        int level = 0;
        if (root == nullptr) {
            return level;
        }
        nodes.push(root);
        while (!nodes.empty()) {
            int size = nodes.size();
            while (size > 0) {
                root = nodes.front();
                nodes.pop();
                // add children
                if (root->left != nullptr) {
                    nodes.push(root->left);
                }
                if (root->right != nullptr) {
                    nodes.push(root->right);
                }
                size -= 1;
            }
            level += 1;
        }
        return level;

    /**
        // recursion: DFS
        if (root == nullptr) {
            return 0;
        }
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    **/
    }
};
