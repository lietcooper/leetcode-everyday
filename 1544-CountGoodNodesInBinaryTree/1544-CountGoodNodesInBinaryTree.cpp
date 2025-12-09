// Last updated: 12/8/2025, 11:26:09 PM
// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     int goodNodes(TreeNode* root) {
//         int mx = root->val;
//         int count = 1;  // root 
//         TreeNode* cur = root;
//         bool visited = false;

//         // Morris traversal
//         while (cur) {
//             if (cur->left) {
//                 TreeNode* prev = cur->left;
//                 while (prev->right && prev->right != cur) {
//                     prev = prev->right;
//                 }
//                 if (!prev->right) {
//                     // build thread and go left
//                     prev->right = cur;
//                     cur = cur->left;
//                 } else {
//                     // cut thread and go right
//                     prev->right = nullptr;
//                     mx = cur->val;  // reset max as the value of starting node of a new path
//                     visited = isPredecessor(cur); // when going right each time we need to check if this node is a predecessor (since it can move to a previously visited node or to the unvisited right subtree)
//                     cur = cur->right;
//                 }
//             } else {
//                 visited = isPredecessor(cur);// when going right each time we need to check if this node is a predecessor (since it can move to a previously visited node or to the unvisited right subtree)
//                 cur = cur->right;
//             }

//             // for each move, if not empty node and not visited, do comparison
//             if (cur && !visited) {
//                 if (cur->val < mx) {
//                     cur->val = mx; // set node value to max, so each time when we get back to this node from Morris traversal, we know the max value of the previous path ending at this node.
//                 } else {
//                     mx = cur->val;
//                     count++;
//                 }
//             }
//             visited = false;
//         }
//         return count;
//     }

//     // Part of Morris traversal
//     bool isPredecessor(TreeNode* root) {
//         TreeNode* cur = root->right;
//         if (cur) {
//             if (cur->left) {
//                 TreeNode* prev = cur->left;
//                 while (prev->right && prev->right != cur) {
//                     prev = prev->right;
//                 }
//                 return prev == root;
//             }
//         }
//         return false;
//     }
// };

class Solution {
public:
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        int good = 0;
        int currMax = INT_MIN;
        TreeNode* curr = root;

        while (curr) {
            if (!curr->left) {
                // 直接访问 curr（前序）
                int v = curr->val;              // 原始值
                if (v >= currMax) ++good;       // 判断是否 good

                int pm = currMax;
                if (v > pm) pm = v;             // pm = 从根到 curr 的最大值
                curr->val = pm;                 // 覆盖 val 为路径最大值
                currMax = pm;                   // 更新当前路径最大值

                curr = curr->right;             // 没有左子树，直接去右边
            } else {
                // 找到左子树中的前驱节点（Morris）
                TreeNode* pre = curr->left;
                while (pre->right && pre->right != curr) {
                    pre = pre->right;
                }

                if (!pre->right) {
                    // 第一次到达 curr：处理 curr（前序），然后建立线索，转向左子树
                    int v = curr->val;          // 原始值
                    if (v >= currMax) ++good;   // 判断是否 good

                    int pm = currMax;
                    if (v > pm) pm = v;         // 从根到 curr 的最大值
                    curr->val = pm;             // 覆盖 val
                    currMax = pm;               // 路径最大值更新

                    pre->right = curr;          // 建立线索
                    curr = curr->left;          // 下潜到左子树
                } else {
                    // 第二次回到 curr：左子树已经访问完，断开线索
                    pre->right = nullptr;

                    // 恢复当前路径最大值：curr->val 里就存着从根到 curr 的最大值
                    currMax = curr->val;

                    curr = curr->right;         // 去右子树
                }
            }
        }
        return good;
    }
};