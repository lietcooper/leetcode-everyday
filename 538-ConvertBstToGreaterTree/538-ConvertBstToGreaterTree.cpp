// Last updated: 12/8/2025, 11:28:23 PM
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
    TreeNode* convertBST(TreeNode* root) {
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
                    suc->left = nullptr;
                    int temp = cur->val;
                    cur->val += sum;
                    sum += temp;
                    cur = cur->left;
                }
            } else {
                int temp = cur->val;
                cur->val += sum;
                sum += temp;
                cur = cur->left;
                
            }
        }

        return root;
    }
};