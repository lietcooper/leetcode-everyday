// Last updated: 12/8/2025, 11:28:24 PM
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
    int i = 0;
    TreeNode* str2tree(string s) {
        if (s.empty()) return nullptr;
        i = 0;
        return build(s);
    }

    

    TreeNode* build(const string& s) {
        if (i >= s.length()) return nullptr;
        int val = parseNumber(s);
        TreeNode* root = new TreeNode(val);

        // go left
        if (s[i] == '(') {
            i++;  // skip opening
            root->left = build(s);
            i++;  // skip closing when get back
        }

        // go right
        if (s[i] == '(') {
            i++;
            root->right = build(s);
            i++;
        }

        return root;  
    }

    // parse number
    int parseNumber(const string& s) {
        int start = i;
        if (s[i] == '-') i++;
        while (i < s.length() && isdigit(s[i])) i++;
        return stoi(s.substr(start, i - start));
    } 
};