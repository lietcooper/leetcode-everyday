// Last updated: 12/8/2025, 11:26:39 PM
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
    int result;
    int minCameraCover(TreeNode* root) {
        /**
                 n
                / \
               o   o
              / \ / \
             n  n n  n
        */
        result = 0;

        // extra check for root.
        if (visit(root) == 0) {
            result++;
        }
        return result;
    }


    /**
    0: uncovered
    1: has camera
    2: covered
    */
    int visit(TreeNode* root) {
        // if empty, return 2
        if (!root) return 2;

        int left = visit(root->left);
        int right = visit(root->right);

        // if both are uncovered, return 0 
        if (left == 2 && right == 2) return 0;
        // if at least one is uncovered, return 1, result++(should put camera)
        else if (left == 0 || right == 0) {
            result++;
            return 1;
        }
        else return 2;
    //     // if at least one camera, return 2,
    //     if (left == 1 || right == 1) return 2;
    //    return 0;
    }
};