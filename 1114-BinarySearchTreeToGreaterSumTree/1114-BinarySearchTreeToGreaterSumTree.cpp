// Last updated: 12/8/2025, 11:26:25 PM
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
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        TreeNode* cur = root;
        while (cur) {
            if (cur->right) {
                TreeNode* suc = cur->right;
                while (suc->left && suc->left != cur)
                    suc = suc->left;
                if (!suc->left) {
                    suc->left = cur;
                    cur = cur->right;
                } else {
                    // add greater sum
                    int temp = cur->val;
                    cur->val += sum;
                    sum += temp;

                    // move
                    suc->left = nullptr;
                    cur = cur->left;
                }
            } else {
                // add greater sum
                int temp = cur->val;
                cur->val += sum;
                sum += temp;

                // move
                cur = cur->left;
                
            }
        }

        return root;
    }
};