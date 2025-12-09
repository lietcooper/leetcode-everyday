// Last updated: 12/8/2025, 11:28:29 PM
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
    int findBottomLeftValue(TreeNode* root) {
        if (!root) return 0;
        int depth = -1;
        int val = 0;
        dfs(root, 0, depth, val);
        return val;
    }

    void dfs(TreeNode* root, int level, int& depth, int& val) {
        if (level > depth) {
            depth = level;
            val = root->val;
        }
        if (root->left) dfs(root->left, level + 1, depth, val);
        if (root->right) dfs(root->right, level + 1, depth, val);

    }
};