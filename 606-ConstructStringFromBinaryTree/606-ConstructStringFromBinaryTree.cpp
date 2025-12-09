// Last updated: 12/8/2025, 11:28:12 PM
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

/**
 1(2
 1(2(4
 1(2(4()()
 1(2(4
 1(2(4))
 1(2(4))(3)

 root:
    to left: +(
            + left->val
            recur(left)
    +)
    to right: +(
            +right->val
            reur(right)
    +)
    if (right is null) pop()
    if (left is null) pop()
 */
class Solution {
public:
    string tree2str(TreeNode* root) {
        string str = "";
        if (root != nullptr) {
            str += to_string(root->val);
            if (root->left) {
                str += '(';
                str += tree2str(root->left);
                str += ')';

            } else if (root->right) {
                str += "()";
            }

            if (root->right) {
                str += '(';
                str += tree2str(root->right);
                str += ')';
            }
        }

        return str;
    }
};