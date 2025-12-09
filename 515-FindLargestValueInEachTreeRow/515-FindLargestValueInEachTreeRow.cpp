// Last updated: 12/8/2025, 11:28:30 PM
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
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        queue<TreeNode*> q;
        q.emplace(root);
        while (!q.empty()) {
            int num = INT_MIN;
            int sz = q.size();
            while (sz--) {
                TreeNode* cur = q.front();
                q.pop();
                num = max(cur->val, num);
                if (cur->left) q.emplace(cur->left);
                if (cur->right) q.emplace(cur->right);
            }
            res.push_back(num);
        }
        return res;
    }
};