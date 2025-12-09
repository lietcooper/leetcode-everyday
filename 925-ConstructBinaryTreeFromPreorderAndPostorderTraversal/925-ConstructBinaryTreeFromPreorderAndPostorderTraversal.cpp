// Last updated: 12/8/2025, 11:26:47 PM
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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int i = 0, j = 0;
        return build(preorder, postorder, i, j);
    }

    TreeNode* build(auto& preorder, auto& postorder, int& i, int& j) {
        TreeNode* node = new TreeNode(preorder[i]);
        i++;
        if (node->val != postorder[j]) {
            node->left = build(preorder, postorder, i, j);
        }
        if (node->val != postorder[j]) {
            node->right = build(preorder, postorder, i, j);
        }
        j++;
        return node;
    }
};