// Last updated: 12/8/2025, 11:26:31 PM
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        i = 0;
        return build(preorder, INT_MIN, INT_MAX);
    }

    int i = 0;
    TreeNode* build(const vector<int>& preorder, int low, int high) {
        if (i >= preorder.size()) return nullptr;
        int cur = preorder[i];
        
        if (cur <= low || cur >= high) return nullptr;

        TreeNode* root = new TreeNode(cur);
        i++;
        root->left = build(preorder, low, cur);
        root->right = build(preorder, cur, high);

        return root;
    }
};