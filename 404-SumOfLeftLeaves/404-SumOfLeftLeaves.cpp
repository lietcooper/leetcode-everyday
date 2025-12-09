// Last updated: 12/8/2025, 11:28:54 PM
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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root->left && !root->right) return 0;
        TreeNode* cur = root;
        int sum = 0;
        // preorder
        while (cur) {
            if (!cur->left) {
                cur = cur->right;
            } else {
                TreeNode* prev = cur->left;
                // if (!prev->left && !prev->right) sum += prev->val;
                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                }
                if (!prev->right) {
                    prev->right = cur;
                    cur = cur->left;
                    if (!cur->left && cur->right == prev->right) sum += cur->val;
                } else {
                    prev->right = nullptr;
                    cur = cur->right;
                }
            }
        }
        return sum;
    }
};