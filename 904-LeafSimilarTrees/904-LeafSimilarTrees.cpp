// Last updated: 12/8/2025, 11:26:49 PM
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        return getLeaves(root1) == getLeaves(root2);
    }

    vector<int> getLeaves(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> leaves;
        dfs(root, leaves);
        return leaves;
    }

    void dfs(TreeNode* root, vector<int>& leaves) {
        if (!root->left && !root->right) {
            leaves.push_back(root->val);
            return;
        }
        if (root->left) dfs(root->left, leaves);
        if (root->right) dfs(root->right, leaves);
    }
};