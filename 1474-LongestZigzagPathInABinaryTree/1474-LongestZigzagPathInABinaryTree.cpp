// Last updated: 12/8/2025, 11:26:10 PM
// // /**
// //  * Definition for a binary tree node.
// //  * struct TreeNode {
// //  *     int val;
// //  *     TreeNode *left;
// //  *     TreeNode *right;
// //  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
// //  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// //  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// //  * };
// //  */
// // class Solution {
// // public:
// //     int longestZigZag(TreeNode* root) {
// //         int maxLen = 0;
// //         helper(root, maxLen);
// //         return maxLen;
// //     }

// //     void helper(TreeNode* root, int& maxLen) {
// //         if (!root) return;
// //         int left = dfs(root, 0, 0);
// //         int right = dfs(root, 1, 0);
// //         maxLen = max(maxLen, max(left, right));
// //         helper(root->left, maxLen);
// //         helper(root->right, maxLen);
// //     }

// //     // 0 = left, 1 = right;
// //     int dfs(TreeNode* node, int direction, int length) {
// //         if (!node) return length - 1;
// //         if (direction == 0) {
// //             return dfs(node->right, 1, length + 1);
// //         } else {
// //             return dfs(node->left, 0, length + 1);
// //         }
// //     }
// // };

// class Solution {
// private:
//     int longest = 0;
//     unordered_map<TreeNode*, int[2]> sums;  // 0 is left, 1 is right
//     void dfs(TreeNode* node) {
//         if (node == nullptr) {
//             return;
//         }
        
//         dfs(node->left);
//         dfs(node->right);

//         if (node->left == nullptr) sums[node][0] = 1;
//         else sums[node][0] = sums[node->left][1] + 1;

//         if (node->right == nullptr) sums[node][1] = 1;
//         else sums[node][1] = sums[node->right][0] + 1;
        
//         longest = max({longest, sums[node][0], sums[node][1]});
//     }

// public:
//     int longestZigZag(TreeNode* root) {
//         dfs(root);
//         return longest - 1;
//     }
// };

class Solution {
public:
    int pathLength = 0;
    void dfs(TreeNode* node, int left, int right) {
        if (node == nullptr) {
            return;
        }
        pathLength = max({pathLength, left, right});
        if (node->left) dfs(node->left, right + 1, 0);
        if (node->right) dfs(node->right, 0, left + 1);
    }

    int longestZigZag(TreeNode* root) {
        dfs(root, 0, 0);
        return pathLength;
    }
};