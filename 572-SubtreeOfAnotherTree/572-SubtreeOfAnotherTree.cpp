// Last updated: 12/8/2025, 11:28:18 PM
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
    string deserialize(TreeNode* root) {
        if (!root) return ",#";
        return ',' + to_string(root->val) + deserialize(root->left) + deserialize(root->right);
        
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string s = deserialize(root);
        string t = deserialize(subRoot);
        cout << s << " and " << t << endl;
        return kmp(s, t);
    }

    bool kmp(string& s, string& t) {
        int n = t.length();
        vector<int> next(n, 0);
        int j = -1;
        next[0] = -1;
        for (int i = 1; i < n; ++i) {
            while (j >= 0 && t[i] != t[j + 1]) {
                j = next[j];
            }
            if (t[i] == t[j + 1]) {
                j++;
            }
            next[i] = j;
        }

        j = - 1;
        for (int i = 0; i < s.length(); ++i) {
            while (j >= 0 && s[i] != t[j + 1]) {
                j = next[j];
            }
            if (s[i] == t[j + 1]) {
                j++;
            }
            if (j == n - 1) return true;
        }
        return false;
    }
};