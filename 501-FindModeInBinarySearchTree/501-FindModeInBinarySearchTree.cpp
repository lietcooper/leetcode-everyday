// Last updated: 12/8/2025, 11:28:33 PM
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
    vector<int> findMode(TreeNode* root) {
        int curStreak = 0, maxStreak = 0;
        int curNum = root->val;
        vector<int> res;
        TreeNode* cur = root;
        while (cur) {
            if (!cur->left) {
                if (cur->val == curNum) {
                    curStreak++;
                } else {
                    curStreak = 1;
                    curNum = cur->val;
                }
                if (curStreak == maxStreak) {
                    res.push_back(curNum);
                }

                if (curStreak > maxStreak) {
                    maxStreak = curStreak;
                    res.clear();
                    res.push_back(curNum);
                }

                cur = cur->right;
            } else {
                TreeNode* prev = cur->left;
                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                }
                if (!prev->right) {
                    prev->right = cur;
                    cur = cur->left;
                } else {
                    if (cur->val == curNum) {
                    curStreak++;
                    } else {
                        curStreak = 1;
                        curNum = cur->val;
                    }

                    if (curStreak == maxStreak) {
                        res.push_back(curNum);
                    }

                    if (curStreak > maxStreak) {
                        maxStreak = curStreak;
                        res.clear();
                        res.push_back(curNum);
                    }
                    prev->right = nullptr;
                    cur = cur->right;
                }
            }
        }
        return res;
    }
};