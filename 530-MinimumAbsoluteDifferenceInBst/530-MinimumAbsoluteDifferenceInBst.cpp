// Last updated: 12/8/2025, 11:28:25 PM
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
    int getMinimumDifference(TreeNode* root) {
        TreeNode* cur = root;
        int dif = INT_MAX;
        int prev_val = INT_MAX;
        while (cur) {
            if (!cur->left) {
                dif = min(dif, abs(cur->val - prev_val));
                prev_val = cur->val;
                cur = cur->right;
            } else {
                TreeNode* pre = cur->left;
                while (pre->right && pre->right != cur)
                    pre = pre->right;

                // stopped: empty or back to current ?
                if (!pre->right) {
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    // pre->right = cur, cut thread, visit, then go right
                    pre->right = nullptr;
                    dif = min(dif, abs(cur->val - prev_val));
                    prev_val = cur->val;
                    cur = cur->right;
                }
            }
        }
        return dif;
    }
};