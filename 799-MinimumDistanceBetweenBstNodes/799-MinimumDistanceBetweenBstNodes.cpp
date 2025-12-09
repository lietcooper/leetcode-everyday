// Last updated: 12/8/2025, 11:27:08 PM
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
    TreeNode* prev;
    int minDiffInBST(TreeNode* root) {
        int left = INT_MAX;
        int right = INT_MAX;

        if (root->left) {
            left = minDiffInBST(root->left);
        }
        if (prev != nullptr) {
            left = min(left, root->val - prev->val);
        }
        
        prev = root;
        if (root->right) {
            right = minDiffInBST(root->right);
        }

        return min(left, right);
    }
};